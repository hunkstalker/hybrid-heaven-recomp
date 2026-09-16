#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801c8ab8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8AB8: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801C8ABC: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801C8AC0: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x801C8AC4: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x801C8AC8: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x801C8ACC: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x801C8AD0: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x801C8AD4: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801C8AD8: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801C8ADC: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x801C8AE0: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801C8AE4: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x801C8AE8: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x801C8AEC: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x801C8AF0: lwc1        $f14, 0x8($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X8);
    // 0x801C8AF4: sub.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x801C8AF8: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x801C8AFC: add.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x801C8B00: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x801C8B04: lwc1        $f8, 0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC);
    // 0x801C8B08: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x801C8B0C: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x801C8B10: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x801C8B14: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801C8B18: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x801C8B1C: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x801C8B20: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x801C8B24: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x801C8B28: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x801C8B2C: add.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x801C8B30: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x801C8B34: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x801C8B38: lwc1        $f2, 0x14($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X14);
    // 0x801C8B3C: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x801C8B40: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x801C8B44: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x801C8B48: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x801C8B4C: lwc1        $f18, 0x18($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X18);
    // 0x801C8B50: lwc1        $f14, 0x18($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X18);
    // 0x801C8B54: sub.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x801C8B58: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801C8B5C: add.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x801C8B60: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x801C8B64: lwc1        $f10, 0x1C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x801C8B68: lwc1        $f16, 0x1C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x801C8B6C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801C8B70: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x801C8B74: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801C8B78: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x801C8B7C: lwc1        $f8, 0x20($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X20);
    // 0x801C8B80: lwc1        $f0, 0x20($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X20);
    // 0x801C8B84: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x801C8B88: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x801C8B8C: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x801C8B90: jr          $ra
    // 0x801C8B94: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x801C8B94: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c8b98(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c8b98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8B98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C8B9C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C8BA0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C8BA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C8BA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C8BAC: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801C8BB0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C8BB4: jal         0x80005E44
    // 0x801C8BB8: addiu       $a1, $a1, -0x2764
    ctx->r5 = ADD32(ctx->r5, -0X2764);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C8BB8: addiu       $a1, $a1, -0x2764
    ctx->r5 = ADD32(ctx->r5, -0X2764);
    after_0:
    // 0x801C8BBC: bne         $v0, $zero, L_801C8BD4
    if (ctx->r2 != 0) {
        // 0x801C8BC0: nop
    
            goto L_801C8BD4;
    }
    // 0x801C8BC0: nop

    // 0x801C8BC4: jal         0x80005700
    // 0x801C8BC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801C8BC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C8BCC: b           L_801C8D18
    // 0x801C8BD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x801C8D18)(rdram, ctx);
    return;
    // 0x801C8BD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C8BD4:
    // 0x801C8BD4: jal         0x80006214
    // 0x801C8BD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801C8BD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801C8BDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C8BE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C8BE4: addiu       $a2, $zero, 0xA7
    ctx->r6 = ADD32(0, 0XA7);
    // 0x801C8BE8: jal         0x8012C89C
    // 0x801C8BEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x801C8BEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x801C8BF0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C8BF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C8BF8: addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    // 0x801C8BFC: lw          $a1, 0x30($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X30);
    // 0x801C8C00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C8C04: jal         0x8012CF8C
    // 0x801C8C08: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_4;
    // 0x801C8C08: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_4:
    // 0x801C8C0C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C8C10: addiu       $v0, $v0, 0x4C0
    ctx->r2 = ADD32(ctx->r2, 0X4C0);
    // 0x801C8C14: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801C8C18: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801C8C1C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801C8C20: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C8C24: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c8c28(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c8c28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8C28: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801C8C2C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C8C30: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C8C34: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C8C38: addiu       $a1, $a1, -0x72D8
    ctx->r5 = ADD32(ctx->r5, -0X72D8);
    // 0x801C8C3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C8C40: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801C8C44: swc1        $f16, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f16.u32l;
    // 0x801C8C48: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C8C4C: lwc1        $f18, 0x94($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801C8C50: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C8C54: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    // 0x801C8C58: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801C8C5C: lwc1        $f4, 0x98($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801C8C60: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801C8C64: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C8C68: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801C8C6C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C8C70: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x801C8C74: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801C8C78: swc1        $f16, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f16.u32l;
    // 0x801C8C7C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C8C80: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C8C84: sh          $zero, 0x12($t4)
    MEM_H(0X12, ctx->r12) = 0;
    // 0x801C8C88: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C8C8C: addiu       $t4, $zero, 0x100
    ctx->r12 = ADD32(0, 0X100);
    // 0x801C8C90: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C8C94: sb          $v1, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r3;
    // 0x801C8C98: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C8C9C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C8CA0: sb          $v1, 0x49($t8)
    MEM_B(0X49, ctx->r24) = ctx->r3;
    // 0x801C8CA4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C8CA8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C8CAC: sb          $v1, 0x4A($t0)
    MEM_B(0X4A, ctx->r8) = ctx->r3;
    // 0x801C8CB0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C8CB4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C8CB8: sb          $t1, 0x4B($t3)
    MEM_B(0X4B, ctx->r11) = ctx->r9;
    // 0x801C8CBC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C8CC0: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801C8CC4: addiu       $t3, $t3, -0x71A0
    ctx->r11 = ADD32(ctx->r11, -0X71A0);
    // 0x801C8CC8: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C8CCC: or          $t5, $t3, $at
    ctx->r13 = ctx->r11 | ctx->r1;
    // 0x801C8CD0: sw          $t4, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r12;
    // 0x801C8CD4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C8CD8: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x801C8CDC: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C8CE0: swc1        $f18, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f18.u32l;
    // 0x801C8CE4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C8CE8: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x801C8CEC: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C8CF0: swc1        $f4, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f4.u32l;
    // 0x801C8CF4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C8CF8: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x801C8CFC: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x801C8D00: swc1        $f6, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f6.u32l;
    // 0x801C8D04: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C8D08: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801C8D0C: jal         0x800058DC
    // 0x801C8D10: sw          $t5, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r13;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C8D10: sw          $t5, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r13;
    after_0:
    // 0x801C8D14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C8D18: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C8D1C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C8D20: jr          $ra
    // 0x801C8D24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C8D24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c8d28(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c8d28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8D28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C8D2C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801C8D30: lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // 0x801C8D34: addiu       $s2, $s2, 0x4C0
    ctx->r18 = ADD32(ctx->r18, 0X4C0);
    // 0x801C8D38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801C8D3C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801C8D40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C8D44: lwc1        $f4, 0x90($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801C8D48: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801C8D4C: lwc1        $f10, 0x0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801C8D50: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801C8D54: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801C8D58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C8D5C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C8D60: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801C8D64: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801C8D68: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801C8D6C: swc1        $f16, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f16.u32l;
    // 0x801C8D70: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801C8D74: lwc1        $f18, 0x98($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X98);
    // 0x801C8D78: lwc1        $f8, 0x8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801C8D7C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x801C8D80: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801C8D84: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C8D88: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801C8D8C: swc1        $f10, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f10.u32l;
    // 0x801C8D90: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x801C8D94: lwc1        $f16, 0x14($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X14);
    // 0x801C8D98: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C8D9C: swc1        $f16, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f16.u32l;
    // 0x801C8DA0: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x801C8DA4: lwc1        $f18, 0x14($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X14);
    // 0x801C8DA8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C8DAC: swc1        $f18, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f18.u32l;
    // 0x801C8DB0: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x801C8DB4: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x801C8DB8: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C8DBC: swc1        $f4, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f4.u32l;
    // 0x801C8DC0: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x801C8DC4: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C8DC8: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C8DCC: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801C8DD0: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C8DD4: lwc1        $f16, 0x38($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801C8DD8: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801C8DDC: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801C8DE0: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x801C8DE4: jal         0x8001EF38
    // 0x801C8DE8: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x801C8DE8: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x801C8DEC: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C8DF0: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C8DF4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801C8DF8: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C8DFC: addiu       $t9, $v0, 0x1000
    ctx->r25 = ADD32(ctx->r2, 0X1000);
    // 0x801C8E00: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C8E04: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C8E08: andi        $t0, $t9, 0x1FFF
    ctx->r8 = ctx->r25 & 0X1FFF;
    // 0x801C8E0C: sh          $t0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r8;
    // 0x801C8E10: jal         0x8002FC20
    // 0x801C8E14: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x801C8E14: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_1:
    // 0x801C8E18: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801C8E1C: lw          $t3, -0x4328($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4328);
    // 0x801C8E20: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801C8E24: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801C8E28: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801C8E2C: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801C8E30: jal         0x8001EF38
    // 0x801C8E34: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x801C8E34: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_2:
    // 0x801C8E38: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801C8E3C: andi        $t4, $v0, 0x1FFF
    ctx->r12 = ctx->r2 & 0X1FFF;
    // 0x801C8E40: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C8E44: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C8E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C8E4C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C8E50: sh          $t4, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r12;
    // 0x801C8E54: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C8E58: lwc1        $f16, -0x2D30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2D30);
    // 0x801C8E5C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C8E60: lwc1        $f10, 0x8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801C8E64: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x801C8E68: nop

    // 0x801C8E6C: bc1f        L_801C8E84
    if (!c1cs) {
        // 0x801C8E70: nop
    
            goto L_801C8E84;
    }
    // 0x801C8E70: nop

    // 0x801C8E74: jal         0x800058DC
    // 0x801C8E78: addiu       $a1, $a1, -0x7064
    ctx->r5 = ADD32(ctx->r5, -0X7064);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C8E78: addiu       $a1, $a1, -0x7064
    ctx->r5 = ADD32(ctx->r5, -0X7064);
    after_3:
    // 0x801C8E7C: b           L_801C8F88
    // 0x801C8E80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801C8F88;
    // 0x801C8E80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C8E84:
    // 0x801C8E84: jal         0x801C78F8
    // 0x801C8E88: nop

    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_4;
    // 0x801C8E88: nop

    after_4:
    // 0x801C8E8C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801C8E90: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C8E94: nop

    // 0x801C8E98: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x801C8E9C: nop

    // 0x801C8EA0: bc1fl       L_801C8F24
    if (!c1cs) {
        // 0x801C8EA4: lhu         $t3, 0xA4($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0XA4);
            goto L_801C8F24;
    }
    goto skip_0;
    // 0x801C8EA4: lhu         $t3, 0xA4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XA4);
    skip_0:
    // 0x801C8EA8: lhu         $t9, 0xA4($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XA4);
    // 0x801C8EAC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C8EB0: bnel        $t9, $zero, L_801C8F24
    if (ctx->r25 != 0) {
        // 0x801C8EB4: lhu         $t3, 0xA4($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0XA4);
            goto L_801C8F24;
    }
    goto skip_1;
    // 0x801C8EB4: lhu         $t3, 0xA4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XA4);
    skip_1:
    // 0x801C8EB8: sh          $t1, 0xA4($s0)
    MEM_H(0XA4, ctx->r16) = ctx->r9;
    // 0x801C8EBC: jal         0x801C78F8
    // 0x801C8EC0: sh          $zero, 0xA8($s0)
    MEM_H(0XA8, ctx->r16) = 0;
    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_5;
    // 0x801C8EC0: sh          $zero, 0xA8($s0)
    MEM_H(0XA8, ctx->r16) = 0;
    after_5:
    // 0x801C8EC4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801C8EC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C8ECC: nop

    // 0x801C8ED0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801C8ED4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C8ED8: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x801C8EDC: jal         0x801C78F8
    // 0x801C8EE0: sh          $t2, 0xAA($s0)
    MEM_H(0XAA, ctx->r16) = ctx->r10;
    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_6;
    // 0x801C8EE0: sh          $t2, 0xAA($s0)
    MEM_H(0XAA, ctx->r16) = ctx->r10;
    after_6:
    // 0x801C8EE4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801C8EE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C8EEC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C8EF0: lwc1        $f18, -0x2D2C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2D2C);
    // 0x801C8EF4: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x801C8EF8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801C8EFC: jal         0x801C78F8
    // 0x801C8F00: swc1        $f4, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_7;
    // 0x801C8F00: swc1        $f4, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f4.u32l;
    after_7:
    // 0x801C8F04: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801C8F08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C8F0C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C8F10: lwc1        $f10, -0x2D28($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2D28);
    // 0x801C8F14: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x801C8F18: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801C8F1C: swc1        $f16, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f16.u32l;
    // 0x801C8F20: lhu         $t3, 0xA4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XA4);
L_801C8F24:
    // 0x801C8F24: beql        $t3, $zero, L_801C8F70
    if (ctx->r11 == 0) {
        // 0x801C8F28: lw          $t8, 0x0($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X0);
            goto L_801C8F70;
    }
    goto skip_2;
    // 0x801C8F28: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x801C8F2C: lwc1        $f18, 0x90($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801C8F30: lwc1        $f4, 0xAC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x801C8F34: lwc1        $f8, 0x98($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801C8F38: lwc1        $f10, 0xB0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x801C8F3C: lhu         $t5, 0xA8($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XA8);
    // 0x801C8F40: lhu         $t6, 0xAA($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XAA);
    // 0x801C8F44: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801C8F48: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x801C8F4C: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x801C8F50: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801C8F54: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x801C8F58: swc1        $f6, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f6.u32l;
    // 0x801C8F5C: sh          $t4, 0xA8($s0)
    MEM_H(0XA8, ctx->r16) = ctx->r12;
    // 0x801C8F60: beq         $at, $zero, L_801C8F6C
    if (ctx->r1 == 0) {
        // 0x801C8F64: swc1        $f16, 0x98($s0)
        MEM_W(0X98, ctx->r16) = ctx->f16.u32l;
            goto L_801C8F6C;
    }
    // 0x801C8F64: swc1        $f16, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f16.u32l;
    // 0x801C8F68: sh          $zero, 0xA4($s0)
    MEM_H(0XA4, ctx->r16) = 0;
L_801C8F6C:
    // 0x801C8F6C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
L_801C8F70:
    // 0x801C8F70: lwc1        $f4, 0x18($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X18);
    // 0x801C8F74: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801C8F78: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801C8F7C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801C8F80: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x801C8F84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801C8F88:
    // 0x801C8F88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C8F8C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801C8F90: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801C8F94: jr          $ra
    // 0x801C8F98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C8F98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c8f9c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c8f9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C8F9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C8FA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C8FA4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801C8FA8: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x801C8FAC: lbu         $v0, 0x4B($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4B);
    // 0x801C8FB0: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x801C8FB4: bgezl       $v0, L_801C8FFC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801C8FB8: sb          $v0, 0x4B($v1)
        MEM_B(0X4B, ctx->r3) = ctx->r2;
            goto L_801C8FFC;
    }
    goto skip_0;
    // 0x801C8FB8: sb          $v0, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r2;
    skip_0:
    // 0x801C8FBC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C8FC0: addiu       $v0, $v0, 0x4C0
    ctx->r2 = ADD32(ctx->r2, 0X4C0);
    // 0x801C8FC4: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801C8FC8: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801C8FCC: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801C8FD0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801C8FD4: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x801C8FD8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x801C8FDC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C8FE0: addiu       $a1, $a1, -0x72D8
    ctx->r5 = ADD32(ctx->r5, -0X72D8);
    // 0x801C8FE4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C8FE8: jal         0x800058DC
    // 0x801C8FEC: sb          $t7, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C8FEC: sb          $t7, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r15;
    after_0:
    // 0x801C8FF0: b           L_801C9000
    // 0x801C8FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C9000;
    // 0x801C8FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C8FF8: sb          $v0, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r2;
L_801C8FFC:
    // 0x801C8FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C9000:
    // 0x801C9000: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C9004: jr          $ra
    // 0x801C9008: nop

    return;
    // 0x801C9008: nop

;}
RECOMP_FUNC void M24_FUN_801c900c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C900C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C9010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C9014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C9018: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C901C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C9020: jal         0x80005E44
    // 0x801C9024: addiu       $a1, $a1, -0x5888
    ctx->r5 = ADD32(ctx->r5, -0X5888);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C9024: addiu       $a1, $a1, -0x5888
    ctx->r5 = ADD32(ctx->r5, -0X5888);
    after_0:
    // 0x801C9028: beq         $v0, $zero, L_801C903C
    if (ctx->r2 == 0) {
        // 0x801C902C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801C903C;
    }
    // 0x801C902C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C9030: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C9034: jal         0x800058DC
    // 0x801C9038: addiu       $a1, $a1, -0x6FB4
    ctx->r5 = ADD32(ctx->r5, -0X6FB4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C9038: addiu       $a1, $a1, -0x6FB4
    ctx->r5 = ADD32(ctx->r5, -0X6FB4);
    after_1:
L_801C903C:
    // 0x801C903C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C9040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C9044: jr          $ra
    // 0x801C9048: nop

    return;
    // 0x801C9048: nop

;}
RECOMP_FUNC void M24_FUN_801c904c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C904C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C9050: lw          $t6, -0x59EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X59EC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c9054(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c9054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C9058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C905C: bne         $t6, $zero, L_801C906C
    if (ctx->r14 != 0) {
        // 0x801C9060: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801C906C;
    }
    // 0x801C9060: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C9064: jal         0x80005700
    // 0x801C9068: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801C9068: nop

    after_0:
L_801C906C:
    // 0x801C906C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C9070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C9074: jr          $ra
    // 0x801C9078: nop

    return;
    // 0x801C9078: nop

;}
RECOMP_FUNC void M24_FUN_801c907c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C907C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C9080: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C9084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C9088: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C908C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C9090: jal         0x80005E44
    // 0x801C9094: addiu       $a1, $a1, -0x5878
    ctx->r5 = ADD32(ctx->r5, -0X5878);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C9094: addiu       $a1, $a1, -0x5878
    ctx->r5 = ADD32(ctx->r5, -0X5878);
    after_0:
    // 0x801C9098: jal         0x80006214
    // 0x801C909C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C909C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801C90A0: jal         0x80001060
    // 0x801C90A4: nop

    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_2;
    // 0x801C90A4: nop

    after_2:
    // 0x801C90A8: beq         $v0, $zero, L_801C9104
    if (ctx->r2 == 0) {
        // 0x801C90AC: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_801C9104;
    }
    // 0x801C90AC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x801C90B0: jal         0x801302CC
    // 0x801C90B4: nop

    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_3;
    // 0x801C90B4: nop

    after_3:
    // 0x801C90B8: beq         $v0, $zero, L_801C90E4
    if (ctx->r2 == 0) {
        // 0x801C90BC: lw          $t3, 0x1C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X1C);
            goto L_801C90E4;
    }
    // 0x801C90BC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x801C90C0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x801C90C4: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C90C8: addiu       $t6, $t6, -0x6A58
    ctx->r14 = ADD32(ctx->r14, -0X6A58);
    // 0x801C90CC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801C90D0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C90D4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801C90D8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C90DC: b           L_801C9120
    // 0x801C90E0: sw          $t7, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r15;
        goto L_801C9120;
    // 0x801C90E0: sw          $t7, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r15;
L_801C90E4:
    // 0x801C90E4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801C90E8: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801C90EC: addiu       $t1, $t1, -0x6AD8
    ctx->r9 = ADD32(ctx->r9, -0X6AD8);
    // 0x801C90F0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C90F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C90F8: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x801C90FC: b           L_801C9120
    // 0x801C9100: sw          $t2, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r10;
        goto L_801C9120;
    // 0x801C9100: sw          $t2, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r10;
L_801C9104:
    // 0x801C9104: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x801C9108: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C910C: addiu       $t6, $t6, -0x6B58
    ctx->r14 = ADD32(ctx->r14, -0X6B58);
    // 0x801C9110: lw          $t0, 0x30($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X30);
    // 0x801C9114: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C9118: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x801C911C: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
L_801C9120:
    // 0x801C9120: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C9124: addiu       $a1, $a1, -0x6EC0
    ctx->r5 = ADD32(ctx->r5, -0X6EC0);
    // 0x801C9128: jal         0x800058DC
    // 0x801C912C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C912C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x801C9130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C9134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C9138: jr          $ra
    // 0x801C913C: nop

    return;
    // 0x801C913C: nop

;}
RECOMP_FUNC void M24_FUN_801c9140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9140: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C9144: lw          $t6, -0x59E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X59E8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c9148(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c9148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C914C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C9150: beq         $t6, $zero, L_801C9168
    if (ctx->r14 == 0) {
        // 0x801C9154: lui         $t0, 0x801E
        ctx->r8 = S32(0X801E << 16);
            goto L_801C9168;
    }
    // 0x801C9154: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C9158: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x801C915C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C9160: b           L_801C9170
    // 0x801C9164: sb          $t7, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r15;
        goto L_801C9170;
    // 0x801C9164: sb          $t7, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r15;
L_801C9168:
    // 0x801C9168: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801C916C: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
L_801C9170:
    // 0x801C9170: lw          $t0, -0x59EC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X59EC);
    // 0x801C9174: bnel        $t0, $zero, L_801C9188
    if (ctx->r8 != 0) {
        // 0x801C9178: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C9188;
    }
    goto skip_0;
    // 0x801C9178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801C917C: jal         0x80005700
    // 0x801C9180: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801C9180: nop

    after_0:
    // 0x801C9184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C9188:
    // 0x801C9188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C918C: jr          $ra
    // 0x801C9190: nop

    return;
    // 0x801C9190: nop

;}
RECOMP_FUNC void M24_FUN_801c9194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9194: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C9198: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C919C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C91A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C91A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C91A8: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C91AC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C91B0: jal         0x80005E44
    // 0x801C91B4: addiu       $a1, $a1, -0x5868
    ctx->r5 = ADD32(ctx->r5, -0X5868);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C91B4: addiu       $a1, $a1, -0x5868
    ctx->r5 = ADD32(ctx->r5, -0X5868);
    after_0:
    // 0x801C91B8: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C91BC: addiu       $a1, $a1, -0x5868
    ctx->r5 = ADD32(ctx->r5, -0X5868);
    // 0x801C91C0: jal         0x80005E44
    // 0x801C91C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_1;
    // 0x801C91C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C91C8: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C91CC: addiu       $a1, $a1, -0x5858
    ctx->r5 = ADD32(ctx->r5, -0X5858);
    // 0x801C91D0: jal         0x80005E44
    // 0x801C91D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x801C91D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801C91D8: jal         0x80006214
    // 0x801C91DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801C91DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x801C91E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C91E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C91E8: addiu       $a2, $zero, 0x447
    ctx->r6 = ADD32(0, 0X447);
    // 0x801C91EC: jal         0x8012C89C
    // 0x801C91F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_4;
    // 0x801C91F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x801C91F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C91F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801C91FC: addiu       $a2, $zero, 0x447
    ctx->r6 = ADD32(0, 0X447);
    // 0x801C9200: jal         0x8012C89C
    // 0x801C9204: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_5;
    // 0x801C9204: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x801C9208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C920C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801C9210: addiu       $a2, $zero, 0x447
    ctx->r6 = ADD32(0, 0X447);
    // 0x801C9214: jal         0x8012C89C
    // 0x801C9218: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_6;
    // 0x801C9218: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x801C921C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C9220: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801C9224: addiu       $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
    // 0x801C9228: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C922C: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x801C9230: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801C9234: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x801C9238: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C923C: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    // 0x801C9240: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x801C9244: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C9248: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C924C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C9250: swc1        $f0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f0.u32l;
    // 0x801C9254: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C9258: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C925C: addiu       $a0, $a0, -0x6018
    ctx->r4 = ADD32(ctx->r4, -0X6018);
    // 0x801C9260: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C9264: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C9268: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    // 0x801C926C: swc1        $f0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f0.u32l;
    // 0x801C9270: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C9274: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C9278: sh          $zero, 0x10($t4)
    MEM_H(0X10, ctx->r12) = 0;
    // 0x801C927C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C9280: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C9284: sh          $zero, 0x12($t6)
    MEM_H(0X12, ctx->r14) = 0;
    // 0x801C9288: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C928C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C9290: sh          $zero, 0x14($t8)
    MEM_H(0X14, ctx->r24) = 0;
    // 0x801C9294: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C9298: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C929C: sb          $t0, 0x48($t1)
    MEM_B(0X48, ctx->r9) = ctx->r8;
    // 0x801C92A0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C92A4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C92A8: sb          $zero, 0x49($t3)
    MEM_B(0X49, ctx->r11) = 0;
    // 0x801C92AC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C92B0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C92B4: sb          $zero, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = 0;
    // 0x801C92B8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C92BC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C92C0: sb          $v1, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = ctx->r3;
    // 0x801C92C4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C92C8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C92CC: sb          $a2, 0x4C($t9)
    MEM_B(0X4C, ctx->r25) = ctx->r6;
    // 0x801C92D0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C92D4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C92D8: sb          $a3, 0x4D($t2)
    MEM_B(0X4D, ctx->r10) = ctx->r7;
    // 0x801C92DC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C92E0: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C92E4: sb          $a1, 0x4E($t4)
    MEM_B(0X4E, ctx->r12) = ctx->r5;
    // 0x801C92E8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C92EC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C92F0: sb          $v1, 0x4F($t6)
    MEM_B(0X4F, ctx->r14) = ctx->r3;
    // 0x801C92F4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C92F8: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801C92FC: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x801C9300: ori         $t9, $t8, 0x300
    ctx->r25 = ctx->r24 | 0X300;
    // 0x801C9304: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x801C9308: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C930C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C9310: swc1        $f2, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f2.u32l;
    // 0x801C9314: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C9318: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C931C: swc1        $f2, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f2.u32l;
    // 0x801C9320: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C9324: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C9328: swc1        $f2, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f2.u32l;
    // 0x801C932C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C9330: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C9334: sw          $a0, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r4;
    // 0x801C9338: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x801C933C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C9340: swc1        $f0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f0.u32l;
    // 0x801C9344: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x801C9348: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C934C: swc1        $f0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f0.u32l;
    // 0x801C9350: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x801C9354: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C9358: swc1        $f0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f0.u32l;
    // 0x801C935C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x801C9360: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C9364: sh          $zero, 0x10($t7)
    MEM_H(0X10, ctx->r15) = 0;
    // 0x801C9368: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x801C936C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C9370: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x801C9374: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x801C9378: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C937C: sh          $zero, 0x14($t2)
    MEM_H(0X14, ctx->r10) = 0;
    // 0x801C9380: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x801C9384: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C9388: sb          $t0, 0x48($t4)
    MEM_B(0X48, ctx->r12) = ctx->r8;
    // 0x801C938C: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x801C9390: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C9394: sb          $zero, 0x49($t6)
    MEM_B(0X49, ctx->r14) = 0;
    // 0x801C9398: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x801C939C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C93A0: sb          $zero, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = 0;
    // 0x801C93A4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x801C93A8: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C93AC: sb          $v1, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r3;
    // 0x801C93B0: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x801C93B4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C93B8: sb          $a2, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = ctx->r6;
    // 0x801C93BC: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x801C93C0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C93C4: sb          $a3, 0x4D($t5)
    MEM_B(0X4D, ctx->r13) = ctx->r7;
    // 0x801C93C8: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x801C93CC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C93D0: sb          $a1, 0x4E($t7)
    MEM_B(0X4E, ctx->r15) = ctx->r5;
    // 0x801C93D4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x801C93D8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C93DC: sb          $v1, 0x4F($t9)
    MEM_B(0X4F, ctx->r25) = ctx->r3;
    // 0x801C93E0: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x801C93E4: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x801C93E8: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x801C93EC: ori         $t3, $t2, 0x300
    ctx->r11 = ctx->r10 | 0X300;
    // 0x801C93F0: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x801C93F4: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x801C93F8: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C93FC: swc1        $f2, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f2.u32l;
    // 0x801C9400: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x801C9404: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C9408: swc1        $f2, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f2.u32l;
    // 0x801C940C: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x801C9410: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C9414: swc1        $f2, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f2.u32l;
    // 0x801C9418: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x801C941C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C9420: sw          $a0, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r4;
    // 0x801C9424: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x801C9428: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C942C: swc1        $f0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f0.u32l;
    // 0x801C9430: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x801C9434: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C9438: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x801C943C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x801C9440: addiu       $t6, $zero, 0x48
    ctx->r14 = ADD32(0, 0X48);
    // 0x801C9444: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C9448: swc1        $f0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f0.u32l;
    // 0x801C944C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x801C9450: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C9454: sh          $zero, 0x10($t1)
    MEM_H(0X10, ctx->r9) = 0;
    // 0x801C9458: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x801C945C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C9460: sh          $zero, 0x12($t3)
    MEM_H(0X12, ctx->r11) = 0;
    // 0x801C9464: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x801C9468: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C946C: sh          $zero, 0x14($t5)
    MEM_H(0X14, ctx->r13) = 0;
    // 0x801C9470: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x801C9474: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C9478: sb          $t6, 0x48($t8)
    MEM_B(0X48, ctx->r24) = ctx->r14;
    // 0x801C947C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x801C9480: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C9484: sb          $a1, 0x49($t1)
    MEM_B(0X49, ctx->r9) = ctx->r5;
    // 0x801C9488: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x801C948C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C9490: sb          $zero, 0x4A($t3)
    MEM_B(0X4A, ctx->r11) = 0;
    // 0x801C9494: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x801C9498: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C949C: sb          $v1, 0x4B($t5)
    MEM_B(0X4B, ctx->r13) = ctx->r3;
    // 0x801C94A0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x801C94A4: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x801C94A8: sb          $a2, 0x4C($t6)
    MEM_B(0X4C, ctx->r14) = ctx->r6;
    // 0x801C94AC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x801C94B0: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C94B4: sb          $a3, 0x4D($t9)
    MEM_B(0X4D, ctx->r25) = ctx->r7;
    // 0x801C94B8: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x801C94BC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C94C0: sb          $a1, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = ctx->r5;
    // 0x801C94C4: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x801C94C8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C94CC: addiu       $a1, $a1, -0x6A54
    ctx->r5 = ADD32(ctx->r5, -0X6A54);
    // 0x801C94D0: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C94D4: sb          $v1, 0x4F($t4)
    MEM_B(0X4F, ctx->r12) = ctx->r3;
    // 0x801C94D8: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x801C94DC: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x801C94E0: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x801C94E4: ori         $t6, $t7, 0x300
    ctx->r14 = ctx->r15 | 0X300;
    // 0x801C94E8: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x801C94EC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x801C94F0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C94F4: addiu       $v0, $v0, 0x4E0
    ctx->r2 = ADD32(ctx->r2, 0X4E0);
    // 0x801C94F8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C94FC: swc1        $f2, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f2.u32l;
    // 0x801C9500: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x801C9504: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C9508: swc1        $f2, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f2.u32l;
    // 0x801C950C: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x801C9510: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C9514: swc1        $f2, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f2.u32l;
    // 0x801C9518: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x801C951C: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x801C9520: sw          $a0, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r4;
    // 0x801C9524: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C9528: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801C952C: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801C9530: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x801C9534: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x801C9538: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x801C953C: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x801C9540: swc1        $f0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f0.u32l;
    // 0x801C9544: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x801C9548: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x801C954C: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x801C9550: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x801C9554: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x801C9558: swc1        $f0, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f0.u32l;
    // 0x801C955C: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
    // 0x801C9560: swc1        $f0, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f0.u32l;
    // 0x801C9564: swc1        $f0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f0.u32l;
    // 0x801C9568: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x801C956C: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x801C9570: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x801C9574: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x801C9578: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x801C957C: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    // 0x801C9580: swc1        $f2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f2.u32l;
    // 0x801C9584: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
    // 0x801C9588: swc1        $f2, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f2.u32l;
    // 0x801C958C: swc1        $f2, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f2.u32l;
    // 0x801C9590: jal         0x800058DC
    // 0x801C9594: swc1        $f2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f2.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801C9594: swc1        $f2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f2.u32l;
    after_7:
    // 0x801C9598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C959C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C95A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C95A4: jr          $ra
    // 0x801C95A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C95A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c95ac(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c95ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C95AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C95B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C95B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C95B8: jal         0x80006214
    // 0x801C95BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801C95BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C95C0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C95C4: lw          $t6, -0x59B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X59B8);
    // 0x801C95C8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801C95CC: beql        $t6, $zero, L_801C95F8
    if (ctx->r14 == 0) {
        // 0x801C95D0: lw          $t0, 0x0($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X0);
            goto L_801C95F8;
    }
    goto skip_0;
    // 0x801C95D0: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x801C95D4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801C95D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C95DC: sb          $v0, 0x22($t7)
    MEM_B(0X22, ctx->r15) = ctx->r2;
    // 0x801C95E0: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x801C95E4: sb          $v0, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r2;
    // 0x801C95E8: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x801C95EC: b           L_801C960C
    // 0x801C95F0: sb          $v0, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r2;
        goto L_801C960C;
    // 0x801C95F0: sb          $v0, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r2;
    // 0x801C95F4: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
L_801C95F8:
    // 0x801C95F8: sb          $zero, 0x22($t0)
    MEM_B(0X22, ctx->r8) = 0;
    // 0x801C95FC: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x801C9600: sb          $zero, 0x22($t1)
    MEM_B(0X22, ctx->r9) = 0;
    // 0x801C9604: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x801C9608: sb          $zero, 0x22($t2)
    MEM_B(0X22, ctx->r10) = 0;
L_801C960C:
    // 0x801C960C: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x801C9610: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C9614: addiu       $v0, $v0, 0x4E0
    ctx->r2 = ADD32(ctx->r2, 0X4E0);
    // 0x801C9618: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x801C961C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C9620: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x801C9624: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C9628: swc1        $f4, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f4.u32l;
    // 0x801C962C: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x801C9630: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801C9634: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801C9638: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C963C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C9640: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x801C9644: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801C9648: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801C964C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C9650: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    // 0x801C9654: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801C9658: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x801C965C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C9660: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C9664: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801C9668: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801C966C: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x801C9670: nop

    // 0x801C9674: sh          $t0, 0x10($t2)
    MEM_H(0X10, ctx->r10) = ctx->r8;
    // 0x801C9678: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801C967C: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x801C9680: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801C9684: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C9688: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801C968C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801C9690: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x801C9694: nop

    // 0x801C9698: sh          $t4, 0x12($t6)
    MEM_H(0X12, ctx->r14) = ctx->r12;
    // 0x801C969C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x801C96A0: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801C96A4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C96A8: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C96AC: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C96B0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C96B4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x801C96B8: nop

    // 0x801C96BC: sh          $t8, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r24;
    // 0x801C96C0: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x801C96C4: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801C96C8: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x801C96CC: swc1        $f10, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f10.u32l;
    // 0x801C96D0: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x801C96D4: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801C96D8: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801C96DC: swc1        $f16, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f16.u32l;
    // 0x801C96E0: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x801C96E4: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801C96E8: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801C96EC: swc1        $f18, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f18.u32l;
    // 0x801C96F0: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x801C96F4: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C96F8: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C96FC: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801C9700: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x801C9704: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801C9708: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x801C970C: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x801C9710: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    // 0x801C9714: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C9718: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x801C971C: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x801C9720: lwc1        $f10, 0x30($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801C9724: lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4);
    // 0x801C9728: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C972C: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801C9730: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801C9734: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801C9738: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x801C973C: nop

    // 0x801C9740: sh          $t5, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r13;
    // 0x801C9744: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801C9748: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x801C974C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801C9750: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x801C9754: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801C9758: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801C975C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x801C9760: nop

    // 0x801C9764: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    // 0x801C9768: lwc1        $f18, 0x38($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801C976C: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x801C9770: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C9774: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C9778: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C977C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C9780: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x801C9784: nop

    // 0x801C9788: sh          $t2, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r10;
    // 0x801C978C: lw          $t5, 0x4($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X4);
    // 0x801C9790: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x801C9794: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C9798: swc1        $f10, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f10.u32l;
    // 0x801C979C: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x801C97A0: lwc1        $f16, 0x28($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X28);
    // 0x801C97A4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C97A8: swc1        $f16, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f16.u32l;
    // 0x801C97AC: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x801C97B0: lwc1        $f18, 0x2C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x801C97B4: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C97B8: swc1        $f18, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f18.u32l;
    // 0x801C97BC: lw          $t0, 0x8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X8);
    // 0x801C97C0: lwc1        $f4, 0x60($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X60);
    // 0x801C97C4: lw          $t3, 0x30($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X30);
    // 0x801C97C8: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
    // 0x801C97CC: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x801C97D0: lwc1        $f6, 0x64($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X64);
    // 0x801C97D4: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x801C97D8: swc1        $f6, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f6.u32l;
    // 0x801C97DC: lw          $t5, 0x8($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X8);
    // 0x801C97E0: lwc1        $f8, 0x68($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X68);
    // 0x801C97E4: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C97E8: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801C97EC: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x801C97F0: lwc1        $f10, 0x54($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X54);
    // 0x801C97F4: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x801C97F8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C97FC: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C9800: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801C9804: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801C9808: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x801C980C: nop

    // 0x801C9810: sh          $t8, 0x10($t1)
    MEM_H(0X10, ctx->r9) = ctx->r24;
    // 0x801C9814: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801C9818: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x801C981C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801C9820: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x801C9824: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801C9828: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801C982C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x801C9830: nop

    // 0x801C9834: sh          $t3, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r11;
    // 0x801C9838: lwc1        $f18, 0x5C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x801C983C: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x801C9840: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C9844: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C9848: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C984C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C9850: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x801C9854: nop

    // 0x801C9858: sh          $t6, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r14;
    // 0x801C985C: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x801C9860: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801C9864: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x801C9868: swc1        $f10, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f10.u32l;
    // 0x801C986C: lw          $t0, 0x8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X8);
    // 0x801C9870: lwc1        $f16, 0x4C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x801C9874: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x801C9878: swc1        $f16, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f16.u32l;
    // 0x801C987C: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x801C9880: lwc1        $f18, 0x50($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X50);
    // 0x801C9884: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C9888: swc1        $f18, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f18.u32l;
    // 0x801C988C: lw          $t5, -0x59BC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X59BC);
    // 0x801C9890: bnel        $t5, $zero, L_801C98A4
    if (ctx->r13 != 0) {
        // 0x801C9894: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C98A4;
    }
    goto skip_1;
    // 0x801C9894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801C9898: jal         0x80005700
    // 0x801C989C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801C989C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801C98A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C98A4:
    // 0x801C98A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C98A8: jr          $ra
    // 0x801C98AC: nop

    return;
    // 0x801C98AC: nop

;}
RECOMP_FUNC void M24_FUN_801c98b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C98B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C98B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C98B8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C98BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C98C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C98C4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C98C8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C98CC: jal         0x80005E44
    // 0x801C98D0: addiu       $a1, $a1, -0x5848
    ctx->r5 = ADD32(ctx->r5, -0X5848);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C98D0: addiu       $a1, $a1, -0x5848
    ctx->r5 = ADD32(ctx->r5, -0X5848);
    after_0:
    // 0x801C98D4: jal         0x80006214
    // 0x801C98D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C98D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C98DC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C98E0: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C98E4: addiu       $t8, $t8, -0x66F8
    ctx->r24 = ADD32(ctx->r24, -0X66F8);
    // 0x801C98E8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C98EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C98F0: addiu       $a2, $zero, 0x2DD
    ctx->r6 = ADD32(0, 0X2DD);
    // 0x801C98F4: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    // 0x801C98F8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C98FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C9900: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C9904: sw          $t8, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r24;
    // 0x801C9908: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C990C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C9910: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x801C9914: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C9918: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C991C: sh          $zero, 0x2C($t4)
    MEM_H(0X2C, ctx->r12) = 0;
    // 0x801C9920: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C9924: lw          $a1, 0x30($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X30);
    // 0x801C9928: jal         0x8012CF8C
    // 0x801C992C: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_2;
    // 0x801C992C: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_2:
    // 0x801C9930: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C9934: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801C9938: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x801C993C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C9940: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C9944: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801C9948: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801C994C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C9950: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801C9954: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C9958: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801C995C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C9960: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801C9964: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801C9968: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C996C: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801C9970: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C9974: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C9978: addiu       $a1, $a1, -0x6534
    ctx->r5 = ADD32(ctx->r5, -0X6534);
    // 0x801C997C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C9980: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x801C9984: lwc1        $f10, 0x9C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x801C9988: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C998C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C9990: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C9994: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801C9998: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801C999C: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x801C99A0: nop

    // 0x801C99A4: sh          $t3, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r11;
    // 0x801C99A8: lwc1        $f6, 0xA0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x801C99AC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C99B0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801C99B4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801C99B8: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801C99BC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801C99C0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x801C99C4: nop

    // 0x801C99C8: sh          $t7, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r15;
    // 0x801C99CC: lwc1        $f18, 0xA4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x801C99D0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C99D4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C99D8: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x801C99DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C99E0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C99E4: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C99E8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C99EC: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x801C99F0: nop

    // 0x801C99F4: sh          $t1, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r9;
    // 0x801C99F8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C99FC: lwc1        $f10, 0xA8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x801C9A00: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801C9A04: swc1        $f10, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f10.u32l;
    // 0x801C9A08: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C9A0C: lwc1        $f16, 0xAC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x801C9A10: lw          $t9, 0x30($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X30);
    // 0x801C9A14: swc1        $f16, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f16.u32l;
    // 0x801C9A18: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C9A1C: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x801C9A20: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C9A24: swc1        $f18, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f18.u32l;
    // 0x801C9A28: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C9A2C: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x801C9A30: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x801C9A34: ori         $t1, $t2, 0x300
    ctx->r9 = ctx->r10 | 0X300;
    // 0x801C9A38: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    // 0x801C9A3C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C9A40: addiu       $t1, $zero, 0xF4
    ctx->r9 = ADD32(0, 0XF4);
    // 0x801C9A44: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x801C9A48: sb          $v1, 0x48($t3)
    MEM_B(0X48, ctx->r11) = ctx->r3;
    // 0x801C9A4C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C9A50: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C9A54: sb          $v1, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r3;
    // 0x801C9A58: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C9A5C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C9A60: sb          $t9, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = ctx->r25;
    // 0x801C9A64: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C9A68: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x801C9A6C: sb          $v1, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r3;
    // 0x801C9A70: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C9A74: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x801C9A78: sb          $t1, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = ctx->r9;
    // 0x801C9A7C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C9A80: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C9A84: sb          $zero, 0x4D($t6)
    MEM_B(0X4D, ctx->r14) = 0;
    // 0x801C9A88: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C9A8C: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C9A90: sb          $zero, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = 0;
    // 0x801C9A94: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C9A98: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801C9A9C: sb          $v1, 0x4F($t0)
    MEM_B(0X4F, ctx->r8) = ctx->r3;
    // 0x801C9AA0: lwc1        $f4, -0x2D24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2D24);
    // 0x801C9AA4: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x801C9AA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C9AAC: swc1        $f4, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->f4.u32l;
    // 0x801C9AB0: jal         0x800058DC
    // 0x801C9AB4: swc1        $f6, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->f6.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C9AB4: swc1        $f6, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->f6.u32l;
    after_3:
    // 0x801C9AB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C9ABC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C9AC0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C9AC4: jr          $ra
    // 0x801C9AC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C9AC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c9acc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c9acc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9ACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C9AD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C9AD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C9AD8: lhu         $t6, 0xB0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XB0);
    // 0x801C9ADC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x801C9AE0: addiu       $a2, $zero, 0x2DD
    ctx->r6 = ADD32(0, 0X2DD);
    // 0x801C9AE4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C9AE8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C9AEC: bgez        $t6, L_801C9B04
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C9AF0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C9B04;
    }
    // 0x801C9AF0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C9AF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C9AF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C9AFC: nop

    // 0x801C9B00: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801C9B04:
    // 0x801C9B04: lhu         $t7, 0xB2($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XB2);
    // 0x801C9B08: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C9B0C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801C9B10: bgez        $t7, L_801C9B24
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C9B14: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C9B24;
    }
    // 0x801C9B14: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C9B18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C9B1C: nop

    // 0x801C9B20: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801C9B24:
    // 0x801C9B24: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801C9B28: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801C9B2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C9B30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C9B34: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C9B38: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801C9B3C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C9B40: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801C9B44: nop

    // 0x801C9B48: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C9B4C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801C9B50: nop

    // 0x801C9B54: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801C9B58: beql        $v0, $zero, L_801C9BA8
    if (ctx->r2 == 0) {
        // 0x801C9B5C: mfc1        $v0, $f18
        ctx->r2 = (int32_t)ctx->f18.u32l;
            goto L_801C9BA8;
    }
    goto skip_0;
    // 0x801C9B5C: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x801C9B60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C9B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C9B68: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801C9B6C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801C9B70: nop

    // 0x801C9B74: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801C9B78: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801C9B7C: nop

    // 0x801C9B80: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801C9B84: bne         $v0, $zero, L_801C9B9C
    if (ctx->r2 != 0) {
        // 0x801C9B88: nop
    
            goto L_801C9B9C;
    }
    // 0x801C9B88: nop

    // 0x801C9B8C: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x801C9B90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C9B94: b           L_801C9BB4
    // 0x801C9B98: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_801C9BB4;
    // 0x801C9B98: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_801C9B9C:
    // 0x801C9B9C: b           L_801C9BB4
    // 0x801C9BA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_801C9BB4;
    // 0x801C9BA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801C9BA4: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
L_801C9BA8:
    // 0x801C9BA8: nop

    // 0x801C9BAC: bltz        $v0, L_801C9B9C
    if (SIGNED(ctx->r2) < 0) {
        // 0x801C9BB0: nop
    
            goto L_801C9B9C;
    }
    // 0x801C9BB0: nop

L_801C9BB4:
    // 0x801C9BB4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x801C9BB8: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x801C9BBC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801C9BC0: mfhi        $v0
    ctx->r2 = hi;
    // 0x801C9BC4: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x801C9BC8: lw          $a1, 0x30($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X30);
    // 0x801C9BCC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C9BD0: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // 0x801C9BD4: lw          $a3, -0x5838($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5838);
    // 0x801C9BD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C9BDC: jal         0x8012CF8C
    // 0x801C9BE0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801C9BE0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x801C9BE4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x801C9BE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C9BEC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801C9BF0: lwc1        $f16, 0x90($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801C9BF4: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801C9BF8: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801C9BFC: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x801C9C00: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801C9C04: lwc1        $f8, 0x90($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801C9C08: lwc1        $f10, 0x94($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801C9C0C: lhu         $t4, 0xB0($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0XB0);
    // 0x801C9C10: lhu         $t7, 0xB2($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XB2);
    // 0x801C9C14: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801C9C18: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801C9C1C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x801C9C20: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x801C9C24: swc1        $f18, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f18.u32l;
    // 0x801C9C28: bne         $at, $zero, L_801C9C38
    if (ctx->r1 != 0) {
        // 0x801C9C2C: sh          $t5, 0xB0($a0)
        MEM_H(0XB0, ctx->r4) = ctx->r13;
            goto L_801C9C38;
    }
    // 0x801C9C2C: sh          $t5, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r13;
    // 0x801C9C30: jal         0x80005700
    // 0x801C9C34: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801C9C34: nop

    after_1:
L_801C9C38:
    // 0x801C9C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C9C3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C9C40: jr          $ra
    // 0x801C9C44: nop

    return;
    // 0x801C9C44: nop

;}
RECOMP_FUNC void M24_FUN_801c9c48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9C48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C9C4C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C9C50: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C9C54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C9C58: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C9C5C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C9C60: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C9C64: jal         0x80005E44
    // 0x801C9C68: addiu       $a1, $a1, -0x57E8
    ctx->r5 = ADD32(ctx->r5, -0X57E8);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C9C68: addiu       $a1, $a1, -0x57E8
    ctx->r5 = ADD32(ctx->r5, -0X57E8);
    after_0:
    // 0x801C9C6C: jal         0x80006214
    // 0x801C9C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C9C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C9C74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C9C78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C9C7C: addiu       $a2, $zero, 0xA7
    ctx->r6 = ADD32(0, 0XA7);
    // 0x801C9C80: jal         0x8012C89C
    // 0x801C9C84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801C9C84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801C9C88: lbu         $v0, 0xB2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB2);
    // 0x801C9C8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C9C90: beql        $v0, $zero, L_801C9CAC
    if (ctx->r2 == 0) {
        // 0x801C9C94: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_801C9CAC;
    }
    goto skip_0;
    // 0x801C9C94: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x801C9C98: beql        $v0, $at, L_801C9CD0
    if (ctx->r2 == ctx->r1) {
        // 0x801C9C9C: lw          $t7, 0x0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X0);
            goto L_801C9CD0;
    }
    goto skip_1;
    // 0x801C9C9C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x801C9CA0: b           L_801C9CEC
    // 0x801C9CA4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
        goto L_801C9CEC;
    // 0x801C9CA4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C9CA8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_801C9CAC:
    // 0x801C9CAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C9CB0: addiu       $a2, $zero, 0x43C
    ctx->r6 = ADD32(0, 0X43C);
    // 0x801C9CB4: lw          $a1, 0x30($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X30);
    // 0x801C9CB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C9CBC: jal         0x8012CF8C
    // 0x801C9CC0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x801C9CC0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x801C9CC4: b           L_801C9CEC
    // 0x801C9CC8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
        goto L_801C9CEC;
    // 0x801C9CC8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C9CCC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
L_801C9CD0:
    // 0x801C9CD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C9CD4: addiu       $a2, $zero, 0x43C
    ctx->r6 = ADD32(0, 0X43C);
    // 0x801C9CD8: lw          $a1, 0x30($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X30);
    // 0x801C9CDC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x801C9CE0: jal         0x8012CF8C
    // 0x801C9CE4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_4;
    // 0x801C9CE4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_4:
    // 0x801C9CE8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
L_801C9CEC:
    // 0x801C9CEC: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801C9CF0: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x801C9CF4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C9CF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C9CFC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801C9D00: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801C9D04: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C9D08: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801C9D0C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C9D10: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C9D14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C9D18: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801C9D1C: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x801C9D20: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C9D24: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801C9D28: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801C9D2C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C9D30: addiu       $a1, $a1, -0x6180
    ctx->r5 = ADD32(ctx->r5, -0X6180);
    // 0x801C9D34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C9D38: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x801C9D3C: lwc1        $f10, 0x9C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x801C9D40: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C9D44: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C9D48: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C9D4C: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801C9D50: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801C9D54: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x801C9D58: nop

    // 0x801C9D5C: sh          $t5, 0x10($t7)
    MEM_H(0X10, ctx->r15) = ctx->r13;
    // 0x801C9D60: lwc1        $f6, 0xA0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x801C9D64: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C9D68: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801C9D6C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C9D70: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801C9D74: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801C9D78: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x801C9D7C: nop

    // 0x801C9D80: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    // 0x801C9D84: lwc1        $f18, 0xA4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x801C9D88: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C9D8C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C9D90: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801C9D94: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C9D98: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C9D9C: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C9DA0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C9DA4: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x801C9DA8: nop

    // 0x801C9DAC: sh          $t3, 0x14($t6)
    MEM_H(0X14, ctx->r14) = ctx->r11;
    // 0x801C9DB0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C9DB4: lwc1        $f10, 0xA8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x801C9DB8: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x801C9DBC: swc1        $f10, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f10.u32l;
    // 0x801C9DC0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C9DC4: lwc1        $f16, 0xAC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x801C9DC8: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801C9DCC: swc1        $f16, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f16.u32l;
    // 0x801C9DD0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C9DD4: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C9DD8: swc1        $f18, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f18.u32l;
    // 0x801C9DDC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C9DE0: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x801C9DE4: lw          $t4, 0x24($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X24);
    // 0x801C9DE8: ori         $t3, $t4, 0x300
    ctx->r11 = ctx->r12 | 0X300;
    // 0x801C9DEC: sw          $t3, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r11;
    // 0x801C9DF0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C9DF4: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x801C9DF8: sb          $v0, 0x48($t5)
    MEM_B(0X48, ctx->r13) = ctx->r2;
    // 0x801C9DFC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C9E00: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C9E04: sb          $v0, 0x49($t8)
    MEM_B(0X49, ctx->r24) = ctx->r2;
    // 0x801C9E08: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C9E0C: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x801C9E10: sb          $v0, 0x4A($t9)
    MEM_B(0X4A, ctx->r25) = ctx->r2;
    // 0x801C9E14: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C9E18: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C9E1C: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801C9E20: addiu       $t1, $t1, -0x7060
    ctx->r9 = ADD32(ctx->r9, -0X7060);
    // 0x801C9E24: sb          $v0, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r2;
    // 0x801C9E28: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C9E2C: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x801C9E30: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x801C9E34: sb          $v0, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = ctx->r2;
    // 0x801C9E38: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C9E3C: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x801C9E40: sb          $v0, 0x4D($t5)
    MEM_B(0X4D, ctx->r13) = ctx->r2;
    // 0x801C9E44: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C9E48: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C9E4C: sb          $v0, 0x4E($t8)
    MEM_B(0X4E, ctx->r24) = ctx->r2;
    // 0x801C9E50: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C9E54: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x801C9E58: sb          $v0, 0x4F($t9)
    MEM_B(0X4F, ctx->r25) = ctx->r2;
    // 0x801C9E5C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C9E60: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x801C9E64: jal         0x800058DC
    // 0x801C9E68: sw          $t2, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801C9E68: sw          $t2, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r10;
    after_5:
    // 0x801C9E6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C9E70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C9E74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C9E78: jr          $ra
    // 0x801C9E7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C9E7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c9e80(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c9e80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9E80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C9E84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C9E88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C9E8C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C9E90: lbu         $v1, 0xB1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XB1);
    // 0x801C9E94: lbu         $a3, 0xB3($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0XB3);
    // 0x801C9E98: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C9E9C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x801C9EA0: addiu       $t6, $a3, 0x1
    ctx->r14 = ADD32(ctx->r7, 0X1);
    // 0x801C9EA4: sb          $t6, 0xB3($a0)
    MEM_B(0XB3, ctx->r4) = ctx->r14;
    // 0x801C9EA8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801C9EAC: lw          $t8, -0x598C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X598C);
    // 0x801C9EB0: lbu         $a2, 0xB2($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0XB2);
    // 0x801C9EB4: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x801C9EB8: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x801C9EBC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C9EC0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C9EC4: bne         $a2, $zero, L_801C9ED8
    if (ctx->r6 != 0) {
        // 0x801C9EC8: lw          $t0, 0x0($t1)
        ctx->r8 = MEM_W(ctx->r9, 0X0);
            goto L_801C9ED8;
    }
    // 0x801C9EC8: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x801C9ECC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C9ED0: b           L_801C9EE0
    // 0x801C9ED4: addiu       $v0, $v0, -0x57D8
    ctx->r2 = ADD32(ctx->r2, -0X57D8);
        goto L_801C9EE0;
    // 0x801C9ED4: addiu       $v0, $v0, -0x57D8
    ctx->r2 = ADD32(ctx->r2, -0X57D8);
L_801C9ED8:
    // 0x801C9ED8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C9EDC: addiu       $v0, $v0, -0x57CC
    ctx->r2 = ADD32(ctx->r2, -0X57CC);
L_801C9EE0:
    // 0x801C9EE0: sltiu       $at, $t0, 0x6
    ctx->r1 = ctx->r8 < 0X6 ? 1 : 0;
    // 0x801C9EE4: beq         $at, $zero, L_801C9FB8
    if (ctx->r1 == 0) {
        // 0x801C9EE8: sll         $t2, $t0, 2
        ctx->r10 = S32(ctx->r8 << 2);
            goto L_801C9FB8;
    }
    // 0x801C9EE8: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x801C9EEC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C9EF0: addu        $at, $at, $t2
    gpr jr_addend_801C9EF8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801C9EF4: lw          $t2, -0x2D20($at)
    ctx->r10 = ADD32(ctx->r1, -0X2D20);
    // 0x801C9EF8: jr          $t2
    // 0x801C9EFC: nop

    switch (jr_addend_801C9EF8 >> 2) {
        case 0: goto L_801C9F00; break;
        case 1: goto L_801C9F30; break;
        case 2: goto L_801C9F60; break;
        case 3: goto L_801C9F90; break;
        case 4: goto L_801C9F9C; break;
        case 5: goto L_801C9FB4; break;
        default: switch_error(__func__, 0x801C9EF8, 0x801DD2E0);
    }
    // 0x801C9EFC: nop

L_801C9F00:
    // 0x801C9F00: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C9F04: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C9F08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C9F0C: sb          $t3, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r11;
    // 0x801C9F10: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C9F14: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x801C9F18: addiu       $a2, $zero, 0x43C
    ctx->r6 = ADD32(0, 0X43C);
    // 0x801C9F1C: lw          $a1, 0x30($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X30);
    // 0x801C9F20: jal         0x8012CF8C
    // 0x801C9F24: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801C9F24: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x801C9F28: b           L_801C9FBC
    // 0x801C9F2C: lbu         $v0, 0xB0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB0);
        goto L_801C9FBC;
    // 0x801C9F2C: lbu         $v0, 0xB0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB0);
L_801C9F30:
    // 0x801C9F30: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C9F34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C9F38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C9F3C: sb          $t6, 0x22($t7)
    MEM_B(0X22, ctx->r15) = ctx->r14;
    // 0x801C9F40: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C9F44: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x801C9F48: addiu       $a2, $zero, 0x43C
    ctx->r6 = ADD32(0, 0X43C);
    // 0x801C9F4C: lw          $a1, 0x30($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X30);
    // 0x801C9F50: jal         0x8012CF8C
    // 0x801C9F54: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_1;
    // 0x801C9F54: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_1:
    // 0x801C9F58: b           L_801C9FBC
    // 0x801C9F5C: lbu         $v0, 0xB0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB0);
        goto L_801C9FBC;
    // 0x801C9F5C: lbu         $v0, 0xB0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB0);
L_801C9F60:
    // 0x801C9F60: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C9F64: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C9F68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C9F6C: sb          $t9, 0x22($t1)
    MEM_B(0X22, ctx->r9) = ctx->r25;
    // 0x801C9F70: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C9F74: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x801C9F78: addiu       $a2, $zero, 0x43C
    ctx->r6 = ADD32(0, 0X43C);
    // 0x801C9F7C: lw          $a1, 0x30($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X30);
    // 0x801C9F80: jal         0x8012CF8C
    // 0x801C9F84: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_2;
    // 0x801C9F84: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_2:
    // 0x801C9F88: b           L_801C9FBC
    // 0x801C9F8C: lbu         $v0, 0xB0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB0);
        goto L_801C9FBC;
    // 0x801C9F8C: lbu         $v0, 0xB0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB0);
L_801C9F90:
    // 0x801C9F90: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C9F94: b           L_801C9FB8
    // 0x801C9F98: sb          $zero, 0x22($t3)
    MEM_B(0X22, ctx->r11) = 0;
        goto L_801C9FB8;
    // 0x801C9F98: sb          $zero, 0x22($t3)
    MEM_B(0X22, ctx->r11) = 0;
L_801C9F9C:
    // 0x801C9F9C: lbu         $v0, 0xB0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB0);
    // 0x801C9FA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C9FA4: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x801C9FA8: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801C9FAC: b           L_801C9FB8
    // 0x801C9FB0: sw          $zero, 0x550($at)
    MEM_W(0X550, ctx->r1) = 0;
        goto L_801C9FB8;
    // 0x801C9FB0: sw          $zero, 0x550($at)
    MEM_W(0X550, ctx->r1) = 0;
L_801C9FB4:
    // 0x801C9FB4: sb          $zero, 0xB3($s1)
    MEM_B(0XB3, ctx->r17) = 0;
L_801C9FB8:
    // 0x801C9FB8: lbu         $v0, 0xB0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB0);
L_801C9FBC:
    // 0x801C9FBC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C9FC0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x801C9FC4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801C9FC8: lw          $t6, 0x550($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X550);
    // 0x801C9FCC: bnel        $t6, $zero, L_801C9FE0
    if (ctx->r14 != 0) {
        // 0x801C9FD0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801C9FE0;
    }
    goto skip_0;
    // 0x801C9FD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801C9FD4: jal         0x80005700
    // 0x801C9FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x801C9FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x801C9FDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C9FE0:
    // 0x801C9FE0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C9FE4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C9FE8: jr          $ra
    // 0x801C9FEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C9FEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c9ff0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c9ff0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C9FF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C9FF4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C9FF8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C9FFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CA000: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801CA004: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CA008: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CA00C: jal         0x80005E44
    // 0x801CA010: addiu       $a1, $a1, -0x57C0
    ctx->r5 = ADD32(ctx->r5, -0X57C0);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801CA010: addiu       $a1, $a1, -0x57C0
    ctx->r5 = ADD32(ctx->r5, -0X57C0);
    after_0:
    // 0x801CA014: jal         0x80006214
    // 0x801CA018: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801CA018: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801CA01C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CA020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CA024: addiu       $a2, $zero, 0xA7
    ctx->r6 = ADD32(0, 0XA7);
    // 0x801CA028: jal         0x8012C89C
    // 0x801CA02C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801CA02C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801CA030: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CA034: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CA038: addiu       $a2, $zero, 0x2DD
    ctx->r6 = ADD32(0, 0X2DD);
    // 0x801CA03C: lw          $a1, 0x30($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X30);
    // 0x801CA040: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CA044: jal         0x8012CF8C
    // 0x801CA048: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x801CA048: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x801CA04C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CA050: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801CA054: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x801CA058: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801CA05C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801CA060: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801CA064: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x801CA068: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CA06C: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801CA070: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801CA074: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CA078: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801CA07C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801CA080: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x801CA084: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CA088: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801CA08C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA090: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CA094: addiu       $a1, $a1, -0x5E14
    ctx->r5 = ADD32(ctx->r5, -0X5E14);
    // 0x801CA098: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CA09C: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x801CA0A0: lwc1        $f10, 0x9C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x801CA0A4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CA0A8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801CA0AC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CA0B0: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801CA0B4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801CA0B8: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x801CA0BC: nop

    // 0x801CA0C0: sh          $t4, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r12;
    // 0x801CA0C4: lwc1        $f6, 0xA0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x801CA0C8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CA0CC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801CA0D0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CA0D4: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801CA0D8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801CA0DC: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x801CA0E0: nop

    // 0x801CA0E4: sh          $t8, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r24;
    // 0x801CA0E8: lwc1        $f18, 0xA4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x801CA0EC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CA0F0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801CA0F4: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801CA0F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CA0FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801CA100: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801CA104: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801CA108: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x801CA10C: nop

    // 0x801CA110: sh          $t2, 0x14($t5)
    MEM_H(0X14, ctx->r13) = ctx->r10;
    // 0x801CA114: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CA118: lwc1        $f10, 0xA8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x801CA11C: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801CA120: swc1        $f10, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f10.u32l;
    // 0x801CA124: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CA128: lwc1        $f16, 0xAC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x801CA12C: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801CA130: swc1        $f16, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f16.u32l;
    // 0x801CA134: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CA138: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x801CA13C: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801CA140: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x801CA144: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CA148: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x801CA14C: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x801CA150: ori         $t2, $t3, 0x300
    ctx->r10 = ctx->r11 | 0X300;
    // 0x801CA154: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x801CA158: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CA15C: addiu       $t2, $zero, 0xF4
    ctx->r10 = ADD32(0, 0XF4);
    // 0x801CA160: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x801CA164: sb          $v1, 0x48($t4)
    MEM_B(0X48, ctx->r12) = ctx->r3;
    // 0x801CA168: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CA16C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CA170: sb          $v1, 0x49($t7)
    MEM_B(0X49, ctx->r15) = ctx->r3;
    // 0x801CA174: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CA178: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801CA17C: sb          $t9, 0x4A($t0)
    MEM_B(0X4A, ctx->r8) = ctx->r25;
    // 0x801CA180: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CA184: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801CA188: sb          $v1, 0x4B($t3)
    MEM_B(0X4B, ctx->r11) = ctx->r3;
    // 0x801CA18C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CA190: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801CA194: addiu       $t3, $t3, -0x7060
    ctx->r11 = ADD32(ctx->r11, -0X7060);
    // 0x801CA198: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x801CA19C: or          $t5, $t3, $at
    ctx->r13 = ctx->r11 | ctx->r1;
    // 0x801CA1A0: sb          $t2, 0x4C($t4)
    MEM_B(0X4C, ctx->r12) = ctx->r10;
    // 0x801CA1A4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CA1A8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CA1AC: sb          $zero, 0x4D($t7)
    MEM_B(0X4D, ctx->r15) = 0;
    // 0x801CA1B0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CA1B4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801CA1B8: sb          $zero, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = 0;
    // 0x801CA1BC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CA1C0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CA1C4: sb          $v1, 0x4F($t1)
    MEM_B(0X4F, ctx->r9) = ctx->r3;
    // 0x801CA1C8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CA1CC: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x801CA1D0: jal         0x800058DC
    // 0x801CA1D4: sw          $t5, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r13;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801CA1D4: sw          $t5, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r13;
    after_4:
    // 0x801CA1D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CA1DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801CA1E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801CA1E4: jr          $ra
    // 0x801CA1E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801CA1E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ca1ec(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ca1ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA1EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CA1F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CA1F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CA1F8: lbu         $v0, 0xB3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XB3);
    // 0x801CA1FC: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x801CA200: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CA204: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x801CA208: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801CA20C: sb          $t6, 0xB3($a0)
    MEM_B(0XB3, ctx->r4) = ctx->r14;
    // 0x801CA210: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801CA214: mfhi        $v1
    ctx->r3 = hi;
    // 0x801CA218: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x801CA21C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801CA220: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x801CA224: lw          $a3, -0x57B0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X57B0);
    // 0x801CA228: lw          $a1, 0x30($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X30);
    // 0x801CA22C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CA230: addiu       $a2, $zero, 0x2DD
    ctx->r6 = ADD32(0, 0X2DD);
    // 0x801CA234: jal         0x8012CF8C
    // 0x801CA238: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801CA238: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x801CA23C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801CA240: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801CA244: lbu         $v0, 0xB0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XB0);
    // 0x801CA248: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x801CA24C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801CA250: lw          $t1, 0x5D0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5D0);
    // 0x801CA254: bnel        $t1, $zero, L_801CA268
    if (ctx->r9 != 0) {
        // 0x801CA258: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CA268;
    }
    goto skip_0;
    // 0x801CA258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CA25C: jal         0x80005700
    // 0x801CA260: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801CA260: nop

    after_1:
    // 0x801CA264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CA268:
    // 0x801CA268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CA26C: jr          $ra
    // 0x801CA270: nop

    return;
    // 0x801CA270: nop

;}
RECOMP_FUNC void M24_FUN_801ca274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA274: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CA278: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801CA27C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801CA280: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CA284: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801CA288: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CA28C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CA290: jal         0x80005E44
    // 0x801CA294: addiu       $a1, $a1, -0x5710
    ctx->r5 = ADD32(ctx->r5, -0X5710);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801CA294: addiu       $a1, $a1, -0x5710
    ctx->r5 = ADD32(ctx->r5, -0X5710);
    after_0:
    // 0x801CA298: jal         0x80006214
    // 0x801CA29C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801CA29C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801CA2A0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CA2A4: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CA2A8: addiu       $t8, $t8, -0x66F8
    ctx->r24 = ADD32(ctx->r24, -0X66F8);
    // 0x801CA2AC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CA2B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CA2B4: addiu       $a2, $zero, 0x2DD
    ctx->r6 = ADD32(0, 0X2DD);
    // 0x801CA2B8: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    // 0x801CA2BC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CA2C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CA2C4: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CA2C8: sw          $t8, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r24;
    // 0x801CA2CC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CA2D0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CA2D4: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x801CA2D8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CA2DC: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CA2E0: sh          $zero, 0x2C($t4)
    MEM_H(0X2C, ctx->r12) = 0;
    // 0x801CA2E4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CA2E8: lw          $a1, 0x30($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X30);
    // 0x801CA2EC: jal         0x8012CF8C
    // 0x801CA2F0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_2;
    // 0x801CA2F0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_2:
    // 0x801CA2F4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CA2F8: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801CA2FC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801CA300: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CA304: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801CA308: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801CA30C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CA310: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801CA314: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801CA318: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801CA31C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CA320: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801CA324: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CA328: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CA32C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CA330: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x801CA334: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CA338: lwc1        $f10, 0x9C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x801CA33C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801CA340: swc1        $f10, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f10.u32l;
    // 0x801CA344: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CA348: lwc1        $f16, 0xA0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x801CA34C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801CA350: swc1        $f16, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f16.u32l;
    // 0x801CA354: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CA358: lwc1        $f18, 0xA4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x801CA35C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CA360: swc1        $f18, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f18.u32l;
    // 0x801CA364: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CA368: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801CA36C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CA370: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x801CA374: ori         $t0, $t8, 0x300
    ctx->r8 = ctx->r24 | 0X300;
    // 0x801CA378: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x801CA37C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CA380: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CA384: sb          $v1, 0x48($t2)
    MEM_B(0X48, ctx->r10) = ctx->r3;
    // 0x801CA388: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CA38C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CA390: sb          $v1, 0x49($t4)
    MEM_B(0X49, ctx->r12) = ctx->r3;
    // 0x801CA394: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CA398: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CA39C: sb          $v1, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r3;
    // 0x801CA3A0: lwc1        $f4, 0xA8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x801CA3A4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801CA3A8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801CA3AC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CA3B0: nop

    // 0x801CA3B4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801CA3B8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CA3BC: nop

    // 0x801CA3C0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CA3C4: beql        $t9, $zero, L_801CA414
    if (ctx->r25 == 0) {
        // 0x801CA3C8: mfc1        $t9, $f10
        ctx->r25 = (int32_t)ctx->f10.u32l;
            goto L_801CA414;
    }
    goto skip_0;
    // 0x801CA3C8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x801CA3CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CA3D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CA3D4: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801CA3D8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CA3DC: nop

    // 0x801CA3E0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801CA3E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CA3E8: nop

    // 0x801CA3EC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CA3F0: bne         $t9, $zero, L_801CA408
    if (ctx->r25 != 0) {
        // 0x801CA3F4: nop
    
            goto L_801CA408;
    }
    // 0x801CA3F4: nop

    // 0x801CA3F8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x801CA3FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CA400: b           L_801CA420
    // 0x801CA404: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801CA420;
    // 0x801CA404: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801CA408:
    // 0x801CA408: b           L_801CA420
    // 0x801CA40C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801CA420;
    // 0x801CA40C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801CA410: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
L_801CA414:
    // 0x801CA414: nop

    // 0x801CA418: bltz        $t9, L_801CA408
    if (SIGNED(ctx->r25) < 0) {
        // 0x801CA41C: nop
    
            goto L_801CA408;
    }
    // 0x801CA41C: nop

L_801CA420:
    // 0x801CA420: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CA424: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801CA428: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801CA42C: sb          $t9, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r25;
    // 0x801CA430: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CA434: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801CA438: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CA43C: sb          $zero, 0x4C($t2)
    MEM_B(0X4C, ctx->r10) = 0;
    // 0x801CA440: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CA444: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CA448: sb          $v1, 0x4D($t4)
    MEM_B(0X4D, ctx->r12) = ctx->r3;
    // 0x801CA44C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CA450: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CA454: sb          $v1, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r3;
    // 0x801CA458: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CA45C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801CA460: sb          $v1, 0x4F($t8)
    MEM_B(0X4F, ctx->r24) = ctx->r3;
    // 0x801CA464: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x801CA468: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x801CA46C: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801CA470: lwc1        $f18, 0x30($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801CA474: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801CA478: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801CA47C: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801CA480: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801CA484: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801CA488: jal         0x8001EF38
    // 0x801CA48C: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x801CA48C: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x801CA490: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801CA494: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801CA498: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CA49C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801CA4A0: addiu       $t2, $v0, 0x1000
    ctx->r10 = ADD32(ctx->r2, 0X1000);
    // 0x801CA4A4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801CA4A8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801CA4AC: andi        $t3, $t2, 0x1FFF
    ctx->r11 = ctx->r10 & 0X1FFF;
    // 0x801CA4B0: sh          $t3, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r11;
    // 0x801CA4B4: jal         0x8002FC20
    // 0x801CA4B8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_4;
    // 0x801CA4B8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_4:
    // 0x801CA4BC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801CA4C0: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x801CA4C4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801CA4C8: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801CA4CC: lwc1        $f16, 0x40($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801CA4D0: lwc1        $f18, 0x34($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801CA4D4: jal         0x8001EF38
    // 0x801CA4D8: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_5;
    // 0x801CA4D8: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    after_5:
    // 0x801CA4DC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CA4E0: andi        $t7, $v0, 0x1FFF
    ctx->r15 = ctx->r2 & 0X1FFF;
    // 0x801CA4E4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA4E8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801CA4EC: addiu       $a1, $a1, -0x5AF0
    ctx->r5 = ADD32(ctx->r5, -0X5AF0);
    // 0x801CA4F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CA4F4: jal         0x800058DC
    // 0x801CA4F8: sh          $t7, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801CA4F8: sh          $t7, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r15;
    after_6:
    // 0x801CA4FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CA500: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801CA504: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801CA508: jr          $ra
    // 0x801CA50C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801CA50C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ca510(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ca510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA510: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CA514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CA518: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CA51C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801CA520: lhu         $v0, 0xB0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XB0);
    // 0x801CA524: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x801CA528: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CA52C: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x801CA530: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801CA534: sh          $t6, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r14;
    // 0x801CA538: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x801CA53C: mfhi        $v1
    ctx->r3 = hi;
    // 0x801CA540: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x801CA544: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801CA548: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x801CA54C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CA550: lw          $a1, 0x30($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X30);
    // 0x801CA554: lw          $a3, -0x5700($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5700);
    // 0x801CA558: addiu       $a2, $zero, 0x2DD
    ctx->r6 = ADD32(0, 0X2DD);
    // 0x801CA55C: jal         0x8012CF8C
    // 0x801CA560: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801CA560: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x801CA564: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801CA568: lw          $t0, -0x4328($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4328);
    // 0x801CA56C: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x801CA570: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801CA574: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801CA578: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801CA57C: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801CA580: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801CA584: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801CA588: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801CA58C: jal         0x8001EF38
    // 0x801CA590: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x801CA590: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x801CA594: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801CA598: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801CA59C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x801CA5A0: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801CA5A4: addiu       $t3, $v0, 0x1000
    ctx->r11 = ADD32(ctx->r2, 0X1000);
    // 0x801CA5A8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801CA5AC: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801CA5B0: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x801CA5B4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CA5B8: sh          $t4, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r12;
    // 0x801CA5BC: jal         0x8002FC20
    // 0x801CA5C0: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x801CA5C0: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_2:
    // 0x801CA5C4: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801CA5C8: lw          $t8, -0x4328($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4328);
    // 0x801CA5CC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801CA5D0: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801CA5D4: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801CA5D8: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801CA5DC: jal         0x8001EF38
    // 0x801CA5E0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x801CA5E0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_3:
    // 0x801CA5E4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x801CA5E8: andi        $t9, $v0, 0x1FFF
    ctx->r25 = ctx->r2 & 0X1FFF;
    // 0x801CA5EC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801CA5F0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CA5F4: sh          $t9, 0x10($t2)
    MEM_H(0X10, ctx->r10) = ctx->r25;
    // 0x801CA5F8: lhu         $t5, 0xB0($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XB0);
    // 0x801CA5FC: lhu         $t3, 0xB2($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XB2);
    // 0x801CA600: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801CA604: beql        $at, $zero, L_801CA618
    if (ctx->r1 == 0) {
        // 0x801CA608: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801CA618;
    }
    goto skip_0;
    // 0x801CA608: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801CA60C: jal         0x80005700
    // 0x801CA610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x801CA610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801CA614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801CA618:
    // 0x801CA618: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CA61C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801CA620: jr          $ra
    // 0x801CA624: nop

    return;
    // 0x801CA624: nop

;}
RECOMP_FUNC void M24_FUN_801ca628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA628: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CA62C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801CA630: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801CA634: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CA638: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801CA63C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CA640: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CA644: jal         0x80005E44
    // 0x801CA648: addiu       $a1, $a1, -0x56B0
    ctx->r5 = ADD32(ctx->r5, -0X56B0);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801CA648: addiu       $a1, $a1, -0x56B0
    ctx->r5 = ADD32(ctx->r5, -0X56B0);
    after_0:
    // 0x801CA64C: jal         0x80006214
    // 0x801CA650: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801CA650: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801CA654: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CA658: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CA65C: addiu       $t8, $t8, -0x66F8
    ctx->r24 = ADD32(ctx->r24, -0X66F8);
    // 0x801CA660: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CA664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CA668: addiu       $a2, $zero, 0x2DD
    ctx->r6 = ADD32(0, 0X2DD);
    // 0x801CA66C: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    // 0x801CA670: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CA674: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CA678: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CA67C: sw          $t8, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r24;
    // 0x801CA680: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CA684: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CA688: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x801CA68C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CA690: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CA694: sh          $zero, 0x2C($t4)
    MEM_H(0X2C, ctx->r12) = 0;
    // 0x801CA698: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CA69C: lw          $a1, 0x30($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X30);
    // 0x801CA6A0: jal         0x8012CF8C
    // 0x801CA6A4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_2;
    // 0x801CA6A4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_2:
    // 0x801CA6A8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CA6AC: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801CA6B0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801CA6B4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CA6B8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801CA6BC: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801CA6C0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CA6C4: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801CA6C8: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801CA6CC: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801CA6D0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CA6D4: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801CA6D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801CA6DC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CA6E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CA6E4: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x801CA6E8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CA6EC: lwc1        $f10, 0x9C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x801CA6F0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801CA6F4: swc1        $f10, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f10.u32l;
    // 0x801CA6F8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CA6FC: lwc1        $f16, 0xA0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x801CA700: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801CA704: swc1        $f16, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f16.u32l;
    // 0x801CA708: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CA70C: lwc1        $f18, 0xA4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x801CA710: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CA714: swc1        $f18, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f18.u32l;
    // 0x801CA718: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CA71C: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801CA720: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CA724: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x801CA728: ori         $t0, $t8, 0x300
    ctx->r8 = ctx->r24 | 0X300;
    // 0x801CA72C: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x801CA730: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CA734: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CA738: sb          $v1, 0x48($t2)
    MEM_B(0X48, ctx->r10) = ctx->r3;
    // 0x801CA73C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CA740: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CA744: sb          $v1, 0x49($t4)
    MEM_B(0X49, ctx->r12) = ctx->r3;
    // 0x801CA748: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CA74C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CA750: sb          $v1, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r3;
    // 0x801CA754: lwc1        $f4, 0xA8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x801CA758: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801CA75C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801CA760: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CA764: nop

    // 0x801CA768: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801CA76C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CA770: nop

    // 0x801CA774: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CA778: beql        $t9, $zero, L_801CA7C8
    if (ctx->r25 == 0) {
        // 0x801CA77C: mfc1        $t9, $f10
        ctx->r25 = (int32_t)ctx->f10.u32l;
            goto L_801CA7C8;
    }
    goto skip_0;
    // 0x801CA77C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x801CA780: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CA784: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CA788: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801CA78C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CA790: nop

    // 0x801CA794: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801CA798: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CA79C: nop

    // 0x801CA7A0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CA7A4: bne         $t9, $zero, L_801CA7BC
    if (ctx->r25 != 0) {
        // 0x801CA7A8: nop
    
            goto L_801CA7BC;
    }
    // 0x801CA7A8: nop

    // 0x801CA7AC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x801CA7B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CA7B4: b           L_801CA7D4
    // 0x801CA7B8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801CA7D4;
    // 0x801CA7B8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801CA7BC:
    // 0x801CA7BC: b           L_801CA7D4
    // 0x801CA7C0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801CA7D4;
    // 0x801CA7C0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801CA7C4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
L_801CA7C8:
    // 0x801CA7C8: nop

    // 0x801CA7CC: bltz        $t9, L_801CA7BC
    if (SIGNED(ctx->r25) < 0) {
        // 0x801CA7D0: nop
    
            goto L_801CA7BC;
    }
    // 0x801CA7D0: nop

L_801CA7D4:
    // 0x801CA7D4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CA7D8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801CA7DC: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801CA7E0: sb          $t9, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r25;
    // 0x801CA7E4: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CA7E8: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801CA7EC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CA7F0: sb          $v1, 0x4C($t2)
    MEM_B(0X4C, ctx->r10) = ctx->r3;
    // 0x801CA7F4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CA7F8: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CA7FC: sb          $v1, 0x4D($t4)
    MEM_B(0X4D, ctx->r12) = ctx->r3;
    // 0x801CA800: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CA804: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CA808: sb          $v1, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r3;
    // 0x801CA80C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CA810: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801CA814: sb          $v1, 0x4F($t8)
    MEM_B(0X4F, ctx->r24) = ctx->r3;
    // 0x801CA818: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x801CA81C: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x801CA820: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801CA824: lwc1        $f18, 0x30($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801CA828: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801CA82C: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801CA830: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801CA834: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801CA838: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801CA83C: jal         0x8001EF38
    // 0x801CA840: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x801CA840: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x801CA844: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801CA848: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801CA84C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CA850: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801CA854: addiu       $t2, $v0, 0x1000
    ctx->r10 = ADD32(ctx->r2, 0X1000);
    // 0x801CA858: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801CA85C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801CA860: andi        $t3, $t2, 0x1FFF
    ctx->r11 = ctx->r10 & 0X1FFF;
    // 0x801CA864: sh          $t3, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r11;
    // 0x801CA868: jal         0x8002FC20
    // 0x801CA86C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_4;
    // 0x801CA86C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_4:
    // 0x801CA870: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801CA874: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x801CA878: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801CA87C: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801CA880: lwc1        $f16, 0x40($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801CA884: lwc1        $f18, 0x34($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801CA888: jal         0x8001EF38
    // 0x801CA88C: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_5;
    // 0x801CA88C: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    after_5:
    // 0x801CA890: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CA894: andi        $t7, $v0, 0x1FFF
    ctx->r15 = ctx->r2 & 0X1FFF;
    // 0x801CA898: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CA89C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801CA8A0: addiu       $a1, $a1, -0x573C
    ctx->r5 = ADD32(ctx->r5, -0X573C);
    // 0x801CA8A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CA8A8: jal         0x800058DC
    // 0x801CA8AC: sh          $t7, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801CA8AC: sh          $t7, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r15;
    after_6:
    // 0x801CA8B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CA8B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801CA8B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801CA8BC: jr          $ra
    // 0x801CA8C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801CA8C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801ca8c4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801ca8c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA8C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CA8C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CA8CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CA8D0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801CA8D4: lhu         $v0, 0xB0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XB0);
    // 0x801CA8D8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x801CA8DC: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CA8E0: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x801CA8E4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801CA8E8: sh          $t6, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r14;
    // 0x801CA8EC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x801CA8F0: mfhi        $v1
    ctx->r3 = hi;
    // 0x801CA8F4: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x801CA8F8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801CA8FC: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x801CA900: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CA904: lw          $a1, 0x30($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X30);
    // 0x801CA908: lw          $a3, -0x56A0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X56A0);
    // 0x801CA90C: addiu       $a2, $zero, 0x2DD
    ctx->r6 = ADD32(0, 0X2DD);
    // 0x801CA910: jal         0x8012CF8C
    // 0x801CA914: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801CA914: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x801CA918: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801CA91C: lw          $t0, -0x4328($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4328);
    // 0x801CA920: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x801CA924: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801CA928: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801CA92C: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801CA930: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801CA934: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801CA938: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801CA93C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801CA940: jal         0x8001EF38
    // 0x801CA944: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x801CA944: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x801CA948: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801CA94C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801CA950: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x801CA954: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801CA958: addiu       $t3, $v0, 0x1000
    ctx->r11 = ADD32(ctx->r2, 0X1000);
    // 0x801CA95C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801CA960: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801CA964: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x801CA968: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CA96C: sh          $t4, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r12;
    // 0x801CA970: jal         0x8002FC20
    // 0x801CA974: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x801CA974: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_2:
    // 0x801CA978: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801CA97C: lw          $t8, -0x4328($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4328);
    // 0x801CA980: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801CA984: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801CA988: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801CA98C: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801CA990: jal         0x8001EF38
    // 0x801CA994: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x801CA994: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_3:
    // 0x801CA998: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x801CA99C: andi        $t9, $v0, 0x1FFF
    ctx->r25 = ctx->r2 & 0X1FFF;
    // 0x801CA9A0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801CA9A4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CA9A8: sh          $t9, 0x10($t2)
    MEM_H(0X10, ctx->r10) = ctx->r25;
    // 0x801CA9AC: lhu         $t5, 0xB0($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XB0);
    // 0x801CA9B0: lhu         $t3, 0xB2($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XB2);
    // 0x801CA9B4: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801CA9B8: beql        $at, $zero, L_801CA9CC
    if (ctx->r1 == 0) {
        // 0x801CA9BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801CA9CC;
    }
    goto skip_0;
    // 0x801CA9BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801CA9C0: jal         0x80005700
    // 0x801CA9C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x801CA9C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801CA9C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801CA9CC:
    // 0x801CA9CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CA9D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801CA9D4: jr          $ra
    // 0x801CA9D8: nop

    return;
    // 0x801CA9D8: nop

;}
RECOMP_FUNC void M24_FUN_801ca9dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CA9DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CA9E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801CA9E4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801CA9E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CA9EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801CA9F0: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CA9F4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CA9F8: jal         0x80005E44
    // 0x801CA9FC: addiu       $a1, $a1, -0x5650
    ctx->r5 = ADD32(ctx->r5, -0X5650);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801CA9FC: addiu       $a1, $a1, -0x5650
    ctx->r5 = ADD32(ctx->r5, -0X5650);
    after_0:
    // 0x801CAA00: jal         0x80006214
    // 0x801CAA04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801CAA04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801CAA08: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CAA0C: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CAA10: addiu       $t8, $t8, -0x64A0
    ctx->r24 = ADD32(ctx->r24, -0X64A0);
    // 0x801CAA14: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CAA18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CAA1C: addiu       $a2, $zero, 0x471
    ctx->r6 = ADD32(0, 0X471);
    // 0x801CAA20: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    // 0x801CAA24: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CAA28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CAA2C: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CAA30: sw          $t8, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r24;
    // 0x801CAA34: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CAA38: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CAA3C: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x801CAA40: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CAA44: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CAA48: sh          $zero, 0x2C($t4)
    MEM_H(0X2C, ctx->r12) = 0;
    // 0x801CAA4C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CAA50: lw          $a1, 0x30($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X30);
    // 0x801CAA54: jal         0x8012CF8C
    // 0x801CAA58: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_2;
    // 0x801CAA58: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_2:
    // 0x801CAA5C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CAA60: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801CAA64: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CAA68: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801CAA6C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CAA70: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801CAA74: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801CAA78: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801CAA7C: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801CAA80: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CAA84: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801CAA88: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CAA8C: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x801CAA90: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CAA94: lwc1        $f10, 0x9C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x801CAA98: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801CAA9C: swc1        $f10, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f10.u32l;
    // 0x801CAAA0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CAAA4: lwc1        $f16, 0xA0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x801CAAA8: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801CAAAC: swc1        $f16, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f16.u32l;
    // 0x801CAAB0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CAAB4: lwc1        $f18, 0xA4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x801CAAB8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CAABC: swc1        $f18, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f18.u32l;
    // 0x801CAAC0: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x801CAAC4: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x801CAAC8: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801CAACC: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801CAAD0: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801CAAD4: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801CAAD8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801CAADC: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801CAAE0: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801CAAE4: jal         0x8001EF38
    // 0x801CAAE8: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x801CAAE8: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x801CAAEC: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801CAAF0: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801CAAF4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CAAF8: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801CAAFC: addiu       $t1, $v0, 0x1000
    ctx->r9 = ADD32(ctx->r2, 0X1000);
    // 0x801CAB00: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CAB04: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801CAB08: andi        $t2, $t1, 0x1FFF
    ctx->r10 = ctx->r9 & 0X1FFF;
    // 0x801CAB0C: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    // 0x801CAB10: jal         0x8002FC20
    // 0x801CAB14: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_4;
    // 0x801CAB14: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_4:
    // 0x801CAB18: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801CAB1C: lw          $t5, -0x4328($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4328);
    // 0x801CAB20: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801CAB24: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x801CAB28: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801CAB2C: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801CAB30: jal         0x8001EF38
    // 0x801CAB34: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_5;
    // 0x801CAB34: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_5:
    // 0x801CAB38: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CAB3C: andi        $t6, $v0, 0x1FFF
    ctx->r14 = ctx->r2 & 0X1FFF;
    // 0x801CAB40: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801CAB44: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801CAB48: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801CAB4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CAB50: sh          $t6, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r14;
    // 0x801CAB54: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CAB58: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CAB5C: lw          $a2, 0x30($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X30);
    // 0x801CAB60: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801CAB64: lw          $t0, 0x24($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X24);
    // 0x801CAB68: ori         $t1, $t0, 0x300
    ctx->r9 = ctx->r8 | 0X300;
    // 0x801CAB6C: sw          $t1, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r9;
    // 0x801CAB70: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CAB74: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x801CAB78: sb          $v1, 0x48($t2)
    MEM_B(0X48, ctx->r10) = ctx->r3;
    // 0x801CAB7C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CAB80: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801CAB84: sb          $v1, 0x49($t5)
    MEM_B(0X49, ctx->r13) = ctx->r3;
    // 0x801CAB88: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CAB8C: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x801CAB90: sb          $v1, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r3;
    // 0x801CAB94: lwc1        $f8, 0xA8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x801CAB98: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801CAB9C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CABA0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801CABA4: nop

    // 0x801CABA8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801CABAC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801CABB0: nop

    // 0x801CABB4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801CABB8: beql        $t8, $zero, L_801CAC08
    if (ctx->r24 == 0) {
        // 0x801CABBC: mfc1        $t8, $f18
        ctx->r24 = (int32_t)ctx->f18.u32l;
            goto L_801CAC08;
    }
    goto skip_0;
    // 0x801CABBC: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x801CABC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CABC4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801CABC8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801CABCC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801CABD0: nop

    // 0x801CABD4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801CABD8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801CABDC: nop

    // 0x801CABE0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801CABE4: bne         $t8, $zero, L_801CABFC
    if (ctx->r24 != 0) {
        // 0x801CABE8: nop
    
            goto L_801CABFC;
    }
    // 0x801CABE8: nop

    // 0x801CABEC: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x801CABF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CABF4: b           L_801CAC14
    // 0x801CABF8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_801CAC14;
    // 0x801CABF8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_801CABFC:
    // 0x801CABFC: b           L_801CAC14
    // 0x801CAC00: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_801CAC14;
    // 0x801CAC00: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801CAC04: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
L_801CAC08:
    // 0x801CAC08: nop

    // 0x801CAC0C: bltz        $t8, L_801CABFC
    if (SIGNED(ctx->r24) < 0) {
        // 0x801CAC10: nop
    
            goto L_801CABFC;
    }
    // 0x801CAC10: nop

L_801CAC14:
    // 0x801CAC14: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CAC18: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CAC1C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CAC20: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CAC24: addiu       $a1, $a1, -0x5388
    ctx->r5 = ADD32(ctx->r5, -0X5388);
    // 0x801CAC28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CAC2C: sb          $t8, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r24;
    // 0x801CAC30: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CAC34: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x801CAC38: sb          $v1, 0x4C($t2)
    MEM_B(0X4C, ctx->r10) = ctx->r3;
    // 0x801CAC3C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CAC40: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801CAC44: sb          $v1, 0x4D($t5)
    MEM_B(0X4D, ctx->r13) = ctx->r3;
    // 0x801CAC48: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CAC4C: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x801CAC50: sb          $v1, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r3;
    // 0x801CAC54: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CAC58: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CAC5C: jal         0x800058DC
    // 0x801CAC60: sb          $v1, 0x4F($t0)
    MEM_B(0X4F, ctx->r8) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801CAC60: sb          $v1, 0x4F($t0)
    MEM_B(0X4F, ctx->r8) = ctx->r3;
    after_6:
    // 0x801CAC64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CAC68: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801CAC6C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801CAC70: jr          $ra
    // 0x801CAC74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801CAC74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cac78(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cac78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CAC78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CAC7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CAC80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CAC84: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801CAC88: lhu         $t6, 0xB0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XB0);
    // 0x801CAC8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CAC90: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CAC94: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801CAC98: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CAC9C: bgez        $t6, L_801CACB0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801CACA0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801CACB0;
    }
    // 0x801CACA0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CACA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CACA8: nop

    // 0x801CACAC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801CACB0:
    // 0x801CACB0: lhu         $t7, 0xB2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XB2);
    // 0x801CACB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CACB8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801CACBC: bgez        $t7, L_801CACD0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801CACC0: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801CACD0;
    }
    // 0x801CACC0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801CACC4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CACC8: nop

    // 0x801CACCC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801CACD0:
    // 0x801CACD0: div.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801CACD4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801CACD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CACDC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CACE0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x801CACE4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CACE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CACEC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801CACF0: addiu       $a2, $zero, 0x471
    ctx->r6 = ADD32(0, 0X471);
    // 0x801CACF4: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    // 0x801CACF8: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x801CACFC: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801CAD00: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801CAD04: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801CAD08: nop

    // 0x801CAD0C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801CAD10: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801CAD14: nop

    // 0x801CAD18: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801CAD1C: beql        $t1, $zero, L_801CAD6C
    if (ctx->r9 == 0) {
        // 0x801CAD20: mfc1        $t1, $f10
        ctx->r9 = (int32_t)ctx->f10.u32l;
            goto L_801CAD6C;
    }
    goto skip_0;
    // 0x801CAD20: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x801CAD24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CAD28: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CAD2C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801CAD30: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801CAD34: nop

    // 0x801CAD38: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801CAD3C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801CAD40: nop

    // 0x801CAD44: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801CAD48: bne         $t1, $zero, L_801CAD60
    if (ctx->r9 != 0) {
        // 0x801CAD4C: nop
    
            goto L_801CAD60;
    }
    // 0x801CAD4C: nop

    // 0x801CAD50: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x801CAD54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CAD58: b           L_801CAD78
    // 0x801CAD5C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_801CAD78;
    // 0x801CAD5C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_801CAD60:
    // 0x801CAD60: b           L_801CAD78
    // 0x801CAD64: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_801CAD78;
    // 0x801CAD64: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801CAD68: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
L_801CAD6C:
    // 0x801CAD6C: nop

    // 0x801CAD70: bltz        $t1, L_801CAD60
    if (SIGNED(ctx->r9) < 0) {
        // 0x801CAD74: nop
    
            goto L_801CAD60;
    }
    // 0x801CAD74: nop

L_801CAD78:
    // 0x801CAD78: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x801CAD7C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801CAD80: addu        $a3, $a3, $t3
    ctx->r7 = ADD32(ctx->r7, ctx->r11);
    // 0x801CAD84: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801CAD88: jal         0x8012CF8C
    // 0x801CAD8C: lw          $a3, -0x5640($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5640);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801CAD8C: lw          $a3, -0x5640($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5640);
    after_0:
    // 0x801CAD90: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801CAD94: lw          $t4, -0x4328($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4328);
    // 0x801CAD98: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x801CAD9C: lwc1        $f18, 0x3C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801CADA0: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801CADA4: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801CADA8: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801CADAC: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x801CADB0: sub.s       $f14, $f16, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x801CADB4: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x801CADB8: jal         0x8001EF38
    // 0x801CADBC: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x801CADBC: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x801CADC0: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801CADC4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801CADC8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801CADCC: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801CADD0: addiu       $t7, $v0, 0x1000
    ctx->r15 = ADD32(ctx->r2, 0X1000);
    // 0x801CADD4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801CADD8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801CADDC: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x801CADE0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CADE4: sh          $t8, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r24;
    // 0x801CADE8: jal         0x8002FC20
    // 0x801CADEC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x801CADEC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x801CADF0: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801CADF4: lw          $t2, -0x4328($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4328);
    // 0x801CADF8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801CADFC: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x801CAE00: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801CAE04: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801CAE08: jal         0x8001EF38
    // 0x801CAE0C: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x801CAE0C: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    after_3:
    // 0x801CAE10: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x801CAE14: andi        $t3, $v0, 0x1FFF
    ctx->r11 = ctx->r2 & 0X1FFF;
    // 0x801CAE18: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801CAE1C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CAE20: sh          $t3, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r11;
    // 0x801CAE24: lhu         $t7, 0xB0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XB0);
    // 0x801CAE28: lhu         $t8, 0xB2($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XB2);
    // 0x801CAE2C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x801CAE30: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x801CAE34: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801CAE38: bne         $at, $zero, L_801CAE48
    if (ctx->r1 != 0) {
        // 0x801CAE3C: sh          $t9, 0xB0($s0)
        MEM_H(0XB0, ctx->r16) = ctx->r25;
            goto L_801CAE48;
    }
    // 0x801CAE3C: sh          $t9, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r25;
    // 0x801CAE40: jal         0x80005700
    // 0x801CAE44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x801CAE44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_801CAE48:
    // 0x801CAE48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CAE4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CAE50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801CAE54: jr          $ra
    // 0x801CAE58: nop

    return;
    // 0x801CAE58: nop

;}
RECOMP_FUNC void M24_FUN_801cae5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CAE5C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CAE60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801CAE64: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801CAE68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CAE6C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801CAE70: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CAE74: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CAE78: jal         0x80005E44
    // 0x801CAE7C: addiu       $a1, $a1, -0x5620
    ctx->r5 = ADD32(ctx->r5, -0X5620);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801CAE7C: addiu       $a1, $a1, -0x5620
    ctx->r5 = ADD32(ctx->r5, -0X5620);
    after_0:
    // 0x801CAE80: jal         0x80006214
    // 0x801CAE84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801CAE84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801CAE88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CAE8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801CAE90: addiu       $a2, $zero, 0x373
    ctx->r6 = ADD32(0, 0X373);
    // 0x801CAE94: jal         0x8012C89C
    // 0x801CAE98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801CAE98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x801CAE9C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CAEA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CAEA4: lwc1        $f0, -0x2D08($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D08);
    // 0x801CAEA8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801CAEAC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801CAEB0: addiu       $t6, $t6, -0x6100
    ctx->r14 = ADD32(ctx->r14, -0X6100);
    // 0x801CAEB4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801CAEB8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801CAEBC: sw          $t7, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r15;
    // 0x801CAEC0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CAEC4: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801CAEC8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801CAECC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CAED0: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x801CAED4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CAED8: lwc1        $f6, 0xA0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x801CAEDC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801CAEE0: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801CAEE4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CAEE8: lwc1        $f8, 0x94($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801CAEEC: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801CAEF0: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
    // 0x801CAEF4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CAEF8: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801CAEFC: swc1        $f0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f0.u32l;
    // 0x801CAF00: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CAF04: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801CAF08: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x801CAF0C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CAF10: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x801CAF14: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CAF18: swc1        $f0, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f0.u32l;
    // 0x801CAF1C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CAF20: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x801CAF24: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x801CAF28: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x801CAF2C: ori         $t4, $t3, 0x300
    ctx->r12 = ctx->r11 | 0X300;
    // 0x801CAF30: sw          $t4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r12;
    // 0x801CAF34: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CAF38: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CAF3C: sb          $v1, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r3;
    // 0x801CAF40: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CAF44: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x801CAF48: addiu       $t8, $zero, 0x46
    ctx->r24 = ADD32(0, 0X46);
    // 0x801CAF4C: sb          $v1, 0x49($t7)
    MEM_B(0X49, ctx->r15) = ctx->r3;
    // 0x801CAF50: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CAF54: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CAF58: sb          $t9, 0x4A($t1)
    MEM_B(0X4A, ctx->r9) = ctx->r25;
    // 0x801CAF5C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CAF60: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CAF64: sb          $t2, 0x4B($t4)
    MEM_B(0X4B, ctx->r12) = ctx->r10;
    // 0x801CAF68: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CAF6C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801CAF70: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CAF74: sb          $v1, 0x4C($t6)
    MEM_B(0X4C, ctx->r14) = ctx->r3;
    // 0x801CAF78: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CAF7C: lw          $t0, 0x30($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X30);
    // 0x801CAF80: sb          $t8, 0x4D($t0)
    MEM_B(0X4D, ctx->r8) = ctx->r24;
    // 0x801CAF84: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CAF88: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801CAF8C: sb          $zero, 0x4E($t1)
    MEM_B(0X4E, ctx->r9) = 0;
    // 0x801CAF90: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CAF94: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x801CAF98: sb          $v1, 0x4F($t2)
    MEM_B(0X4F, ctx->r10) = ctx->r3;
    // 0x801CAF9C: lw          $t4, -0x4328($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4328);
    // 0x801CAFA0: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x801CAFA4: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801CAFA8: lwc1        $f16, 0x30($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801CAFAC: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801CAFB0: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801CAFB4: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801CAFB8: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801CAFBC: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801CAFC0: jal         0x8001EF38
    // 0x801CAFC4: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x801CAFC4: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x801CAFC8: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801CAFCC: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801CAFD0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CAFD4: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801CAFD8: addiu       $t7, $v0, 0x1000
    ctx->r15 = ADD32(ctx->r2, 0X1000);
    // 0x801CAFDC: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x801CAFE0: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801CAFE4: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x801CAFE8: sh          $t8, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r24;
    // 0x801CAFEC: jal         0x8002FC20
    // 0x801CAFF0: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_4;
    // 0x801CAFF0: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_4:
    // 0x801CAFF4: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801CAFF8: lw          $t1, -0x4328($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4328);
    // 0x801CAFFC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801CB000: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x801CB004: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801CB008: lwc1        $f16, 0x34($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801CB00C: jal         0x8001EF38
    // 0x801CB010: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_5;
    // 0x801CB010: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    after_5:
    // 0x801CB014: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CB018: andi        $t3, $v0, 0x1FFF
    ctx->r11 = ctx->r2 & 0X1FFF;
    // 0x801CB01C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CB020: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x801CB024: addiu       $a1, $a1, -0x4FB8
    ctx->r5 = ADD32(ctx->r5, -0X4FB8);
    // 0x801CB028: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CB02C: jal         0x800058DC
    // 0x801CB030: sh          $t3, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r11;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801CB030: sh          $t3, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r11;
    after_6:
    // 0x801CB034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CB038: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801CB03C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801CB040: jr          $ra
    // 0x801CB044: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801CB044: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cb048(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cb048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB048: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801CB04C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CB050: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CB054: lwc1        $f4, 0xA8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XA8);
    // 0x801CB058: lwc1        $f18, 0xA4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XA4);
    // 0x801CB05C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801CB060: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x801CB064: lhu         $v1, 0xB0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XB0);
    // 0x801CB068: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CB06C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x801CB070: bgez        $v1, L_801CB084
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801CB074: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801CB084;
    }
    // 0x801CB074: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801CB078: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CB07C: nop

    // 0x801CB080: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801CB084:
    // 0x801CB084: lhu         $t6, 0xB2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XB2);
    // 0x801CB088: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CB08C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801CB090: bgez        $t6, L_801CB0A4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801CB094: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801CB0A4;
    }
    // 0x801CB094: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CB098: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CB09C: nop

    // 0x801CB0A0: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_801CB0A4:
    // 0x801CB0A4: div.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801CB0A8: lwc1        $f2, 0x90($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801CB0AC: lwc1        $f14, 0x98($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X98);
    // 0x801CB0B0: lwc1        $f4, 0xA0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x801CB0B4: lwc1        $f12, 0x94($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801CB0B8: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x801CB0BC: lwc1        $f16, 0x9C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X9C);
    // 0x801CB0C0: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801CB0C4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CB0C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CB0CC: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801CB0D0: sub.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x801CB0D4: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801CB0D8: add.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x801CB0DC: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801CB0E0: swc1        $f6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f6.u32l;
    // 0x801CB0E4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CB0E8: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x801CB0EC: add.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x801CB0F0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CB0F4: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801CB0F8: bgez        $v1, L_801CB10C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801CB0FC: swc1        $f8, 0xC($t0)
        MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
            goto L_801CB10C;
    }
    // 0x801CB0FC: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x801CB100: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CB104: nop

    // 0x801CB108: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_801CB10C:
    // 0x801CB10C: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801CB110: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x801CB114: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801CB118: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801CB11C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CB120: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801CB124: mflo        $t1
    ctx->r9 = lo;
    // 0x801CB128: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801CB12C: bgez        $t1, L_801CB140
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801CB130: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801CB140;
    }
    // 0x801CB130: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801CB134: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CB138: nop

    // 0x801CB13C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801CB140:
    // 0x801CB140: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801CB144: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801CB148: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CB14C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CB150: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801CB154: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801CB158: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801CB15C: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x801CB160: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x801CB164: lw          $t4, -0x4328($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4328);
    // 0x801CB168: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x801CB16C: lwc1        $f8, 0x3C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801CB170: lwc1        $f10, 0x30($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801CB174: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801CB178: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801CB17C: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801CB180: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801CB184: sub.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x801CB188: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801CB18C: jal         0x8001EF38
    // 0x801CB190: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x801CB190: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x801CB194: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801CB198: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801CB19C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CB1A0: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801CB1A4: addiu       $t7, $v0, 0x1000
    ctx->r15 = ADD32(ctx->r2, 0X1000);
    // 0x801CB1A8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CB1AC: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801CB1B0: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x801CB1B4: sh          $t8, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r24;
    // 0x801CB1B8: jal         0x8002FC20
    // 0x801CB1BC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x801CB1BC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x801CB1C0: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801CB1C4: lw          $t1, -0x4328($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4328);
    // 0x801CB1C8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801CB1CC: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x801CB1D0: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801CB1D4: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801CB1D8: jal         0x8001EF38
    // 0x801CB1DC: sub.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f4.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x801CB1DC: sub.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f4.fl;
    after_2:
    // 0x801CB1E0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CB1E4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x801CB1E8: andi        $t2, $v0, 0x1FFF
    ctx->r10 = ctx->r2 & 0X1FFF;
    // 0x801CB1EC: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CB1F0: sh          $t2, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r10;
    // 0x801CB1F4: lhu         $t5, 0xB0($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0XB0);
    // 0x801CB1F8: lhu         $t7, 0xB2($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XB2);
    // 0x801CB1FC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x801CB200: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x801CB204: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x801CB208: beq         $at, $zero, L_801CB218
    if (ctx->r1 == 0) {
        // 0x801CB20C: sh          $t6, 0xB0($a0)
        MEM_H(0XB0, ctx->r4) = ctx->r14;
            goto L_801CB218;
    }
    // 0x801CB20C: sh          $t6, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r14;
    // 0x801CB210: jal         0x80005700
    // 0x801CB214: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x801CB214: nop

    after_3:
L_801CB218:
    // 0x801CB218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CB21C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CB220: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801CB224: jr          $ra
    // 0x801CB228: nop

    return;
    // 0x801CB228: nop

;}
RECOMP_FUNC void M24_FUN_801cb22c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB22C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CB230: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801CB234: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801CB238: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CB23C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801CB240: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CB244: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CB248: jal         0x80005E44
    // 0x801CB24C: addiu       $a1, $a1, -0x5610
    ctx->r5 = ADD32(ctx->r5, -0X5610);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801CB24C: addiu       $a1, $a1, -0x5610
    ctx->r5 = ADD32(ctx->r5, -0X5610);
    after_0:
    // 0x801CB250: jal         0x80006214
    // 0x801CB254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801CB254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801CB258: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CB25C: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CB260: addiu       $t8, $t8, -0x64A0
    ctx->r24 = ADD32(ctx->r24, -0X64A0);
    // 0x801CB264: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CB268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CB26C: addiu       $a2, $zero, 0x372
    ctx->r6 = ADD32(0, 0X372);
    // 0x801CB270: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    // 0x801CB274: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CB278: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CB27C: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CB280: sw          $t8, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r24;
    // 0x801CB284: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CB288: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CB28C: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x801CB290: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CB294: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CB298: sh          $zero, 0x2C($t4)
    MEM_H(0X2C, ctx->r12) = 0;
    // 0x801CB29C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CB2A0: lw          $a1, 0x30($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X30);
    // 0x801CB2A4: jal         0x8012CF8C
    // 0x801CB2A8: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_2;
    // 0x801CB2A8: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_2:
    // 0x801CB2AC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CB2B0: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801CB2B4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CB2B8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CB2BC: lwc1        $f0, -0x2D04($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2D04);
    // 0x801CB2C0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801CB2C4: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801CB2C8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CB2CC: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801CB2D0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801CB2D4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801CB2D8: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801CB2DC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CB2E0: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801CB2E4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CB2E8: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x801CB2EC: lwc1        $f10, 0x9C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x801CB2F0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CB2F4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801CB2F8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801CB2FC: swc1        $f16, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f16.u32l;
    // 0x801CB300: lwc1        $f18, 0xA0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x801CB304: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CB308: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801CB30C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801CB310: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801CB314: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CB318: swc1        $f4, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f4.u32l;
    // 0x801CB31C: lwc1        $f6, 0xA4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x801CB320: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CB324: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801CB328: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CB32C: swc1        $f8, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f8.u32l;
    // 0x801CB330: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CB334: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801CB338: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CB33C: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x801CB340: ori         $t0, $t8, 0x300
    ctx->r8 = ctx->r24 | 0X300;
    // 0x801CB344: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x801CB348: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CB34C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CB350: sb          $v1, 0x48($t2)
    MEM_B(0X48, ctx->r10) = ctx->r3;
    // 0x801CB354: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CB358: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CB35C: sb          $v1, 0x49($t4)
    MEM_B(0X49, ctx->r12) = ctx->r3;
    // 0x801CB360: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CB364: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CB368: sb          $v1, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r3;
    // 0x801CB36C: lwc1        $f10, 0xA8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x801CB370: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801CB374: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801CB378: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CB37C: nop

    // 0x801CB380: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801CB384: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CB388: nop

    // 0x801CB38C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CB390: beql        $t9, $zero, L_801CB3E0
    if (ctx->r25 == 0) {
        // 0x801CB394: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_801CB3E0;
    }
    goto skip_0;
    // 0x801CB394: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x801CB398: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CB39C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CB3A0: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801CB3A4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CB3A8: nop

    // 0x801CB3AC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CB3B0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CB3B4: nop

    // 0x801CB3B8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CB3BC: bne         $t9, $zero, L_801CB3D4
    if (ctx->r25 != 0) {
        // 0x801CB3C0: nop
    
            goto L_801CB3D4;
    }
    // 0x801CB3C0: nop

    // 0x801CB3C4: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x801CB3C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CB3CC: b           L_801CB3EC
    // 0x801CB3D0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801CB3EC;
    // 0x801CB3D0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801CB3D4:
    // 0x801CB3D4: b           L_801CB3EC
    // 0x801CB3D8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801CB3EC;
    // 0x801CB3D8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801CB3DC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_801CB3E0:
    // 0x801CB3E0: nop

    // 0x801CB3E4: bltz        $t9, L_801CB3D4
    if (SIGNED(ctx->r25) < 0) {
        // 0x801CB3E8: nop
    
            goto L_801CB3D4;
    }
    // 0x801CB3E8: nop

L_801CB3EC:
    // 0x801CB3EC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CB3F0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801CB3F4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CB3F8: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801CB3FC: addiu       $a1, $a1, -0x4BB0
    ctx->r5 = ADD32(ctx->r5, -0X4BB0);
    // 0x801CB400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CB404: sb          $t9, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r25;
    // 0x801CB408: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CB40C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CB410: sb          $v1, 0x4C($t2)
    MEM_B(0X4C, ctx->r10) = ctx->r3;
    // 0x801CB414: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CB418: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CB41C: sb          $v1, 0x4D($t4)
    MEM_B(0X4D, ctx->r12) = ctx->r3;
    // 0x801CB420: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CB424: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CB428: sb          $v1, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r3;
    // 0x801CB42C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CB430: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801CB434: jal         0x800058DC
    // 0x801CB438: sb          $v1, 0x4F($t8)
    MEM_B(0X4F, ctx->r24) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CB438: sb          $v1, 0x4F($t8)
    MEM_B(0X4F, ctx->r24) = ctx->r3;
    after_3:
    // 0x801CB43C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CB440: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801CB444: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801CB448: jr          $ra
    // 0x801CB44C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801CB44C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cb450(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cb450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CB454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CB458: lhu         $t6, 0xB0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XB0);
    // 0x801CB45C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CB460: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801CB464: bgez        $t6, L_801CB478
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801CB468: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801CB478;
    }
    // 0x801CB468: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CB46C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CB470: nop

    // 0x801CB474: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801CB478:
    // 0x801CB478: lhu         $t7, 0xB2($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XB2);
    // 0x801CB47C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CB480: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801CB484: bgez        $t7, L_801CB498
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801CB488: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801CB498;
    }
    // 0x801CB488: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801CB48C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CB490: nop

    // 0x801CB494: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801CB498:
    // 0x801CB498: div.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801CB49C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CB4A0: lwc1        $f4, -0x2D00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2D00);
    // 0x801CB4A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801CB4A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CB4AC: lwc1        $f6, 0xAC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x801CB4B0: lui         $at, 0xC37F
    ctx->r1 = S32(0XC37F << 16);
    // 0x801CB4B4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x801CB4B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CB4BC: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801CB4C0: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801CB4C4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801CB4C8: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801CB4CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CB4D0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801CB4D4: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x801CB4D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CB4DC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CB4E0: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801CB4E4: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x801CB4E8: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x801CB4EC: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x801CB4F0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CB4F4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801CB4F8: nop

    // 0x801CB4FC: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CB500: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801CB504: nop

    // 0x801CB508: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801CB50C: beql        $t0, $zero, L_801CB55C
    if (ctx->r8 == 0) {
        // 0x801CB510: mfc1        $t0, $f16
        ctx->r8 = (int32_t)ctx->f16.u32l;
            goto L_801CB55C;
    }
    goto skip_0;
    // 0x801CB510: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x801CB514: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801CB518: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801CB51C: sub.s       $f16, $f4, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x801CB520: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801CB524: nop

    // 0x801CB528: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801CB52C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801CB530: nop

    // 0x801CB534: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801CB538: bne         $t0, $zero, L_801CB550
    if (ctx->r8 != 0) {
        // 0x801CB53C: nop
    
            goto L_801CB550;
    }
    // 0x801CB53C: nop

    // 0x801CB540: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x801CB544: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CB548: b           L_801CB568
    // 0x801CB54C: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_801CB568;
    // 0x801CB54C: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_801CB550:
    // 0x801CB550: b           L_801CB568
    // 0x801CB554: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_801CB568;
    // 0x801CB554: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801CB558: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
L_801CB55C:
    // 0x801CB55C: nop

    // 0x801CB560: bltz        $t0, L_801CB550
    if (SIGNED(ctx->r8) < 0) {
        // 0x801CB564: nop
    
            goto L_801CB550;
    }
    // 0x801CB564: nop

L_801CB568:
    // 0x801CB568: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x801CB56C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CB570: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CB574: sb          $t0, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r8;
    // 0x801CB578: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x801CB57C: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801CB580: lh          $t4, 0x10($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X10);
    // 0x801CB584: addiu       $t5, $t4, 0x71
    ctx->r13 = ADD32(ctx->r12, 0X71);
    // 0x801CB588: sh          $t5, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r13;
    // 0x801CB58C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801CB590: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x801CB594: lh          $t7, 0x12($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X12);
    // 0x801CB598: addiu       $t8, $t7, 0x71
    ctx->r24 = ADD32(ctx->r15, 0X71);
    // 0x801CB59C: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
    // 0x801CB5A0: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801CB5A4: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801CB5A8: lh          $t1, 0x14($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X14);
    // 0x801CB5AC: addiu       $t0, $t1, 0x71
    ctx->r8 = ADD32(ctx->r9, 0X71);
    // 0x801CB5B0: sh          $t0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r8;
    // 0x801CB5B4: lhu         $v1, 0xB0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XB0);
    // 0x801CB5B8: lhu         $t2, 0xB2($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0XB2);
    // 0x801CB5BC: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x801CB5C0: slt         $a2, $t2, $v1
    ctx->r6 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801CB5C4: beq         $a2, $zero, L_801CB5D4
    if (ctx->r6 == 0) {
        // 0x801CB5C8: sh          $t3, 0xB0($a0)
        MEM_H(0XB0, ctx->r4) = ctx->r11;
            goto L_801CB5D4;
    }
    // 0x801CB5C8: sh          $t3, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r11;
    // 0x801CB5CC: jal         0x80005700
    // 0x801CB5D0: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801CB5D0: nop

    after_0:
L_801CB5D4:
    // 0x801CB5D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CB5D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CB5DC: jr          $ra
    // 0x801CB5E0: nop

    return;
    // 0x801CB5E0: nop

;}
RECOMP_FUNC void M24_FUN_801cb5e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB5E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CB5E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801CB5EC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801CB5F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CB5F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801CB5F8: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CB5FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CB600: jal         0x80005E44
    // 0x801CB604: addiu       $a1, $a1, -0x5600
    ctx->r5 = ADD32(ctx->r5, -0X5600);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801CB604: addiu       $a1, $a1, -0x5600
    ctx->r5 = ADD32(ctx->r5, -0X5600);
    after_0:
    // 0x801CB608: jal         0x80006214
    // 0x801CB60C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801CB60C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801CB610: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CB614: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CB618: addiu       $t8, $t8, -0x63F0
    ctx->r24 = ADD32(ctx->r24, -0X63F0);
    // 0x801CB61C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CB620: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CB624: addiu       $a2, $zero, 0x372
    ctx->r6 = ADD32(0, 0X372);
    // 0x801CB628: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    // 0x801CB62C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CB630: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CB634: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CB638: sw          $t8, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r24;
    // 0x801CB63C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CB640: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CB644: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x801CB648: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CB64C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CB650: sh          $zero, 0x2C($t4)
    MEM_H(0X2C, ctx->r12) = 0;
    // 0x801CB654: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CB658: lw          $a1, 0x30($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X30);
    // 0x801CB65C: jal         0x8012CF8C
    // 0x801CB660: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_2;
    // 0x801CB660: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_2:
    // 0x801CB664: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CB668: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801CB66C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CB670: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CB674: lwc1        $f0, -0x2CFC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2CFC);
    // 0x801CB678: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801CB67C: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801CB680: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CB684: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801CB688: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801CB68C: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801CB690: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801CB694: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CB698: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801CB69C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CB6A0: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x801CB6A4: lwc1        $f10, 0x9C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x801CB6A8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CB6AC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801CB6B0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801CB6B4: swc1        $f16, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f16.u32l;
    // 0x801CB6B8: lwc1        $f18, 0xA0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x801CB6BC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CB6C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801CB6C4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801CB6C8: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801CB6CC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CB6D0: swc1        $f4, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f4.u32l;
    // 0x801CB6D4: lwc1        $f6, 0xA4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x801CB6D8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CB6DC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801CB6E0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CB6E4: swc1        $f8, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f8.u32l;
    // 0x801CB6E8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CB6EC: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801CB6F0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CB6F4: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x801CB6F8: ori         $t0, $t8, 0x300
    ctx->r8 = ctx->r24 | 0X300;
    // 0x801CB6FC: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x801CB700: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CB704: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CB708: sb          $v1, 0x48($t2)
    MEM_B(0X48, ctx->r10) = ctx->r3;
    // 0x801CB70C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CB710: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CB714: sb          $v1, 0x49($t4)
    MEM_B(0X49, ctx->r12) = ctx->r3;
    // 0x801CB718: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cb71c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cb71c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB71C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CB720: sb          $v1, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r3;
    // 0x801CB724: lwc1        $f10, 0xA8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x801CB728: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801CB72C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801CB730: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CB734: nop

    // 0x801CB738: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801CB73C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CB740: nop

    // 0x801CB744: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CB748: beql        $t9, $zero, L_801CB798
    if (ctx->r25 == 0) {
        // 0x801CB74C: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_801CB798;
    }
    goto skip_0;
    // 0x801CB74C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x801CB750: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CB754: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CB758: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801CB75C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CB760: nop

    // 0x801CB764: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801CB768: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CB76C: nop

    // 0x801CB770: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CB774: bne         $t9, $zero, L_801CB78C
    if (ctx->r25 != 0) {
        // 0x801CB778: nop
    
            goto L_801CB78C;
    }
    // 0x801CB778: nop

    // 0x801CB77C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x801CB780: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CB784: b           L_801CB7A4
    // 0x801CB788: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801CB7A4;
    // 0x801CB788: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801CB78C:
    // 0x801CB78C: b           L_801CB7A4
    // 0x801CB790: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801CB7A4;
    // 0x801CB790: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801CB794: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_801CB798:
    // 0x801CB798: nop

    // 0x801CB79C: bltz        $t9, L_801CB78C
    if (SIGNED(ctx->r25) < 0) {
        // 0x801CB7A0: nop
    
            goto L_801CB78C;
    }
    // 0x801CB7A0: nop

L_801CB7A4:
    // 0x801CB7A4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CB7A8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801CB7AC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CB7B0: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801CB7B4: addiu       $v0, $v0, 0x650
    ctx->r2 = ADD32(ctx->r2, 0X650);
    // 0x801CB7B8: sb          $t9, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r25;
    // 0x801CB7BC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CB7C0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CB7C4: sb          $v1, 0x4C($t2)
    MEM_B(0X4C, ctx->r10) = ctx->r3;
    // 0x801CB7C8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CB7CC: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CB7D0: sb          $v1, 0x4D($t4)
    MEM_B(0X4D, ctx->r12) = ctx->r3;
    // 0x801CB7D4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CB7D8: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CB7DC: sb          $v1, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r3;
    // 0x801CB7E0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CB7E4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801CB7E8: sb          $v1, 0x4F($t8)
    MEM_B(0X4F, ctx->r24) = ctx->r3;
    // 0x801CB7EC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801CB7F0: lwc1        $f6, 0x90($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801CB7F4: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801CB7F8: lwc1        $f10, 0x94($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801CB7FC: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801CB800: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801CB804: lwc1        $f18, 0x98($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801CB808: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801CB80C: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801CB810: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801CB814: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801CB818: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801CB81C: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801CB820: jal         0x8002FC20
    // 0x801CB824: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x801CB824: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_0:
    // 0x801CB828: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CB82C: lwc1        $f18, -0x5914($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5914);
    // 0x801CB830: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CB834: addiu       $a1, $a1, -0x47A4
    ctx->r5 = ADD32(ctx->r5, -0X47A4);
    // 0x801CB838: div.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801CB83C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CB840: jal         0x800058DC
    // 0x801CB844: swc1        $f4, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f4.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801CB844: swc1        $f4, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f4.u32l;
    after_1:
    // 0x801CB848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CB84C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801CB850: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801CB854: jr          $ra
    // 0x801CB858: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801CB858: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cb85c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cb85c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CB85C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CB860: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CB864: lhu         $t6, 0xB0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XB0);
    // 0x801CB868: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801CB86C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CB870: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801CB874: bgez        $t6, L_801CB888
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801CB878: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801CB888;
    }
    // 0x801CB878: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CB87C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CB880: nop

    // 0x801CB884: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801CB888:
    // 0x801CB888: lhu         $t7, 0xB2($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XB2);
    // 0x801CB88C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CB890: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801CB894: bgez        $t7, L_801CB8A8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801CB898: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801CB8A8;
    }
    // 0x801CB898: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801CB89C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CB8A0: nop

    // 0x801CB8A4: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801CB8A8:
    // 0x801CB8A8: div.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801CB8AC: lwc1        $f4, 0xA8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XA8);
    // 0x801CB8B0: lui         $at, 0xC37F
    ctx->r1 = S32(0XC37F << 16);
    // 0x801CB8B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CB8B8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801CB8BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CB8C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CB8C4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CB8C8: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801CB8CC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801CB8D0: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801CB8D4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801CB8D8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CB8DC: nop

    // 0x801CB8E0: cvt.w.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801CB8E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CB8E8: nop

    // 0x801CB8EC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CB8F0: beql        $t9, $zero, L_801CB940
    if (ctx->r25 == 0) {
        // 0x801CB8F4: mfc1        $t9, $f16
        ctx->r25 = (int32_t)ctx->f16.u32l;
            goto L_801CB940;
    }
    goto skip_0;
    // 0x801CB8F4: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x801CB8F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801CB8FC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801CB900: sub.s       $f16, $f6, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x801CB904: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801CB908: nop

    // 0x801CB90C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801CB910: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801CB914: nop

    // 0x801CB918: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801CB91C: bne         $t9, $zero, L_801CB934
    if (ctx->r25 != 0) {
        // 0x801CB920: nop
    
            goto L_801CB934;
    }
    // 0x801CB920: nop

    // 0x801CB924: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x801CB928: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CB92C: b           L_801CB94C
    // 0x801CB930: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801CB94C;
    // 0x801CB930: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801CB934:
    // 0x801CB934: b           L_801CB94C
    // 0x801CB938: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801CB94C;
    // 0x801CB938: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801CB93C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
L_801CB940:
    // 0x801CB940: nop

    // 0x801CB944: bltz        $t9, L_801CB934
    if (SIGNED(ctx->r25) < 0) {
        // 0x801CB948: nop
    
            goto L_801CB934;
    }
    // 0x801CB948: nop

L_801CB94C:
    // 0x801CB94C: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x801CB950: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801CB954: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801CB958: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CB95C: sb          $t9, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r25;
    // 0x801CB960: lw          $t2, -0x4328($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4328);
    // 0x801CB964: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x801CB968: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801CB96C: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801CB970: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801CB974: lwc1        $f18, 0x38($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801CB978: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801CB97C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x801CB980: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801CB984: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801CB988: jal         0x8001EF38
    // 0x801CB98C: sub.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f18.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x801CB98C: sub.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f18.fl;
    after_0:
    // 0x801CB990: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801CB994: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801CB998: addiu       $t5, $v0, 0x1000
    ctx->r13 = ADD32(ctx->r2, 0X1000);
    // 0x801CB99C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x801CB9A0: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801CB9A4: andi        $t6, $t5, 0x1FFF
    ctx->r14 = ctx->r13 & 0X1FFF;
    // 0x801CB9A8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801CB9AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CB9B0: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    // 0x801CB9B4: lwc1        $f16, -0x2CF8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2CF8);
    // 0x801CB9B8: lwc1        $f6, 0xA0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x801CB9BC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801CB9C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CB9C4: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801CB9C8: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x801CB9CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CB9D0: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x801CB9D4: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801CB9D8: nop

    // 0x801CB9DC: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801CB9E0: swc1        $f18, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f18.u32l;
    // 0x801CB9E4: lhu         $t1, 0xB2($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0XB2);
    // 0x801CB9E8: lwc1        $f6, 0xA8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XA8);
    // 0x801CB9EC: lhu         $v1, 0xB0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XB0);
    // 0x801CB9F0: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x801CB9F4: bgez        $t1, L_801CBA08
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801CB9F8: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_801CBA08;
    }
    // 0x801CB9F8: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801CB9FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CBA00: nop

    // 0x801CBA04: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_801CBA08:
    // 0x801CBA08: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801CBA0C: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x801CBA10: sh          $t4, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r12;
    // 0x801CBA14: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801CBA18: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x801CBA1C: nop

    // 0x801CBA20: slt         $a1, $t3, $v1
    ctx->r5 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801CBA24: beql        $a1, $zero, L_801CBA38
    if (ctx->r5 == 0) {
        // 0x801CBA28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CBA38;
    }
    goto skip_1;
    // 0x801CBA28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801CBA2C: jal         0x80005700
    // 0x801CBA30: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801CBA30: nop

    after_1:
    // 0x801CBA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CBA38:
    // 0x801CBA38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801CBA3C: jr          $ra
    // 0x801CBA40: nop

    return;
    // 0x801CBA40: nop

;}
RECOMP_FUNC void M24_FUN_801cba44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBA44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CBA48: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801CBA4C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801CBA50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CBA54: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801CBA58: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CBA5C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CBA60: jal         0x80005E44
    // 0x801CBA64: addiu       $a1, $a1, -0x55F0
    ctx->r5 = ADD32(ctx->r5, -0X55F0);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801CBA64: addiu       $a1, $a1, -0x55F0
    ctx->r5 = ADD32(ctx->r5, -0X55F0);
    after_0:
    // 0x801CBA68: jal         0x80006214
    // 0x801CBA6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801CBA6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801CBA70: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CBA74: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CBA78: addiu       $t8, $t8, -0x66F8
    ctx->r24 = ADD32(ctx->r24, -0X66F8);
    // 0x801CBA7C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CBA80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CBA84: addiu       $a2, $zero, 0x472
    ctx->r6 = ADD32(0, 0X472);
    // 0x801CBA88: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    // 0x801CBA8C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CBA90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CBA94: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CBA98: sw          $t8, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r24;
    // 0x801CBA9C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CBAA0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CBAA4: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x801CBAA8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CBAAC: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CBAB0: sh          $zero, 0x2C($t4)
    MEM_H(0X2C, ctx->r12) = 0;
    // 0x801CBAB4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CBAB8: lw          $a1, 0x30($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X30);
    // 0x801CBABC: jal         0x8012CF8C
    // 0x801CBAC0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_2;
    // 0x801CBAC0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_2:
    // 0x801CBAC4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CBAC8: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801CBACC: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x801CBAD0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CBAD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801CBAD8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801CBADC: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801CBAE0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CBAE4: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801CBAE8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801CBAEC: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801CBAF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801CBAF4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801CBAF8: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801CBAFC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CBB00: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801CBB04: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CBB08: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CBB0C: addiu       $a1, $a1, -0x43B0
    ctx->r5 = ADD32(ctx->r5, -0X43B0);
    // 0x801CBB10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CBB14: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x801CBB18: lwc1        $f10, 0x9C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x801CBB1C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CBB20: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801CBB24: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801CBB28: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801CBB2C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801CBB30: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x801CBB34: nop

    // 0x801CBB38: sh          $t3, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r11;
    // 0x801CBB3C: lwc1        $f6, 0xA0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x801CBB40: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CBB44: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801CBB48: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801CBB4C: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801CBB50: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801CBB54: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x801CBB58: nop

    // 0x801CBB5C: sh          $t7, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r15;
    // 0x801CBB60: lwc1        $f18, 0xA4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x801CBB64: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CBB68: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801CBB6C: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x801CBB70: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CBB74: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801CBB78: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801CBB7C: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x801CBB80: nop

    // 0x801CBB84: sh          $t1, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r9;
    // 0x801CBB88: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CBB8C: lwc1        $f10, 0xA8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x801CBB90: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801CBB94: swc1        $f10, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f10.u32l;
    // 0x801CBB98: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CBB9C: lwc1        $f16, 0xAC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x801CBBA0: lw          $t9, 0x30($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X30);
    // 0x801CBBA4: swc1        $f16, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f16.u32l;
    // 0x801CBBA8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CBBAC: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801CBBB0: swc1        $f18, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f18.u32l;
    // 0x801CBBB4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CBBB8: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x801CBBBC: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x801CBBC0: ori         $t1, $t2, 0x300
    ctx->r9 = ctx->r10 | 0X300;
    // 0x801CBBC4: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    // 0x801CBBC8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CBBCC: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x801CBBD0: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x801CBBD4: sb          $v1, 0x48($t3)
    MEM_B(0X48, ctx->r11) = ctx->r3;
    // 0x801CBBD8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CBBDC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CBBE0: sb          $v1, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r3;
    // 0x801CBBE4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CBBE8: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x801CBBEC: sb          $v1, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r3;
    // 0x801CBBF0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CBBF4: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801CBBF8: sb          $v0, 0x4B($t0)
    MEM_B(0X4B, ctx->r8) = ctx->r2;
    // 0x801CBBFC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CBC00: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x801CBC04: sb          $v1, 0x4C($t1)
    MEM_B(0X4C, ctx->r9) = ctx->r3;
    // 0x801CBC08: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CBC0C: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x801CBC10: sb          $v1, 0x4D($t3)
    MEM_B(0X4D, ctx->r11) = ctx->r3;
    // 0x801CBC14: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CBC18: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CBC1C: sb          $v1, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r3;
    // 0x801CBC20: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CBC24: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x801CBC28: sb          $v0, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r2;
    // 0x801CBC2C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CBC30: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801CBC34: jal         0x800058DC
    // 0x801CBC38: sw          $zero, 0x30($t0)
    MEM_W(0X30, ctx->r8) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CBC38: sw          $zero, 0x30($t0)
    MEM_W(0X30, ctx->r8) = 0;
    after_3:
    // 0x801CBC3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CBC40: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801CBC44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801CBC48: jr          $ra
    // 0x801CBC4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801CBC4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cbc50(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cbc50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBC50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CBC54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CBC58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CBC5C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801CBC60: lhu         $t6, 0xB0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XB0);
    // 0x801CBC64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CBC68: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CBC6C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801CBC70: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CBC74: bgez        $t6, L_801CBC88
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801CBC78: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801CBC88;
    }
    // 0x801CBC78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CBC7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CBC80: nop

    // 0x801CBC84: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801CBC88:
    // 0x801CBC88: lhu         $t7, 0xB2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XB2);
    // 0x801CBC8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CBC90: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801CBC94: bgez        $t7, L_801CBCA8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801CBC98: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801CBCA8;
    }
    // 0x801CBC98: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801CBC9C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CBCA0: nop

    // 0x801CBCA4: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801CBCA8:
    // 0x801CBCA8: div.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801CBCAC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801CBCB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801CBCB4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CBCB8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x801CBCBC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CBCC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CBCC4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801CBCC8: addiu       $a2, $zero, 0x472
    ctx->r6 = ADD32(0, 0X472);
    // 0x801CBCCC: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    // 0x801CBCD0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x801CBCD4: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801CBCD8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801CBCDC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801CBCE0: nop

    // 0x801CBCE4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801CBCE8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801CBCEC: nop

    // 0x801CBCF0: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801CBCF4: beql        $t1, $zero, L_801CBD44
    if (ctx->r9 == 0) {
        // 0x801CBCF8: mfc1        $t1, $f10
        ctx->r9 = (int32_t)ctx->f10.u32l;
            goto L_801CBD44;
    }
    goto skip_0;
    // 0x801CBCF8: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x801CBCFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801CBD00: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801CBD04: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801CBD08: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801CBD0C: nop

    // 0x801CBD10: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801CBD14: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801CBD18: nop

    // 0x801CBD1C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801CBD20: bne         $t1, $zero, L_801CBD38
    if (ctx->r9 != 0) {
        // 0x801CBD24: nop
    
            goto L_801CBD38;
    }
    // 0x801CBD24: nop

    // 0x801CBD28: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x801CBD2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CBD30: b           L_801CBD50
    // 0x801CBD34: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_801CBD50;
    // 0x801CBD34: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_801CBD38:
    // 0x801CBD38: b           L_801CBD50
    // 0x801CBD3C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_801CBD50;
    // 0x801CBD3C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801CBD40: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
L_801CBD44:
    // 0x801CBD44: nop

    // 0x801CBD48: bltz        $t1, L_801CBD38
    if (SIGNED(ctx->r9) < 0) {
        // 0x801CBD4C: nop
    
            goto L_801CBD38;
    }
    // 0x801CBD4C: nop

L_801CBD50:
    // 0x801CBD50: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x801CBD54: divu        $zero, $t1, $at
    lo = S32(U32(ctx->r9) / U32(ctx->r1)); hi = S32(U32(ctx->r9) % U32(ctx->r1));
    // 0x801CBD58: mfhi        $t2
    ctx->r10 = hi;
    // 0x801CBD5C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801CBD60: addu        $a3, $a3, $t3
    ctx->r7 = ADD32(ctx->r7, ctx->r11);
    // 0x801CBD64: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801CBD68: jal         0x8012CF8C
    // 0x801CBD6C: lw          $a3, -0x55E0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X55E0);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801CBD6C: lw          $a3, -0x55E0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X55E0);
    after_0:
    // 0x801CBD70: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801CBD74: lw          $t4, -0x4328($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4328);
    // 0x801CBD78: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x801CBD7C: lwc1        $f18, 0x3C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801CBD80: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801CBD84: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801CBD88: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801CBD8C: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x801CBD90: sub.s       $f14, $f16, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x801CBD94: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x801CBD98: jal         0x8001EF38
    // 0x801CBD9C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x801CBD9C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x801CBDA0: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801CBDA4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801CBDA8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801CBDAC: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801CBDB0: addiu       $t7, $v0, 0x1000
    ctx->r15 = ADD32(ctx->r2, 0X1000);
    // 0x801CBDB4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801CBDB8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801CBDBC: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x801CBDC0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CBDC4: sh          $t8, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r24;
    // 0x801CBDC8: jal         0x8002FC20
    // 0x801CBDCC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x801CBDCC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x801CBDD0: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801CBDD4: lw          $t2, -0x4328($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4328);
    // 0x801CBDD8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801CBDDC: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x801CBDE0: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801CBDE4: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801CBDE8: jal         0x8001EF38
    // 0x801CBDEC: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x801CBDEC: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    after_3:
    // 0x801CBDF0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x801CBDF4: andi        $t3, $v0, 0x1FFF
    ctx->r11 = ctx->r2 & 0X1FFF;
    // 0x801CBDF8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801CBDFC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801CBE00: sh          $t3, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r11;
    // 0x801CBE04: lhu         $t7, 0xB0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XB0);
    // 0x801CBE08: lhu         $t8, 0xB2($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XB2);
    // 0x801CBE0C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x801CBE10: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x801CBE14: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801CBE18: bne         $at, $zero, L_801CBE28
    if (ctx->r1 != 0) {
        // 0x801CBE1C: sh          $t9, 0xB0($s0)
        MEM_H(0XB0, ctx->r16) = ctx->r25;
            goto L_801CBE28;
    }
    // 0x801CBE1C: sh          $t9, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r25;
    // 0x801CBE20: jal         0x80005700
    // 0x801CBE24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x801CBE24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_801CBE28:
    // 0x801CBE28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CBE2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CBE30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801CBE34: jr          $ra
    // 0x801CBE38: nop

    return;
    // 0x801CBE38: nop

;}
RECOMP_FUNC void M24_FUN_801cbe3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBE3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801CBE40: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801CBE44: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801CBE48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CBE4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801CBE50: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801CBE54: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801CBE58: jal         0x80005E44
    // 0x801CBE5C: addiu       $a1, $a1, -0x55B0
    ctx->r5 = ADD32(ctx->r5, -0X55B0);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801CBE5C: addiu       $a1, $a1, -0x55B0
    ctx->r5 = ADD32(ctx->r5, -0X55B0);
    after_0:
    // 0x801CBE60: jal         0x80006214
    // 0x801CBE64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801CBE64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801CBE68: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CBE6C: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801CBE70: addiu       $t8, $t8, -0x66F8
    ctx->r24 = ADD32(ctx->r24, -0X66F8);
    // 0x801CBE74: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CBE78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CBE7C: addiu       $a2, $zero, 0x2DD
    ctx->r6 = ADD32(0, 0X2DD);
    // 0x801CBE80: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    // 0x801CBE84: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CBE88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801CBE8C: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801CBE90: sw          $t8, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r24;
    // 0x801CBE94: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801CBE98: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801CBE9C: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x801CBEA0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CBEA4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CBEA8: sh          $zero, 0x2C($t4)
    MEM_H(0X2C, ctx->r12) = 0;
    // 0x801CBEAC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801CBEB0: lw          $a1, 0x30($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X30);
    // 0x801CBEB4: jal         0x8012CF8C
    // 0x801CBEB8: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_2;
    // 0x801CBEB8: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_2:
    // 0x801CBEBC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CBEC0: lwc1        $f4, 0x94($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801CBEC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801CBEC8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CBECC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CBED0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801CBED4: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801CBED8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CBEDC: lwc1        $f6, 0x98($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801CBEE0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CBEE4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801CBEE8: addiu       $a1, $a1, -0x4018
    ctx->r5 = ADD32(ctx->r5, -0X4018);
    // 0x801CBEEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801CBEF0: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801CBEF4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CBEF8: lwc1        $f8, 0x9C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x801CBEFC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CBF00: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x801CBF04: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CBF08: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801CBF0C: sh          $zero, 0x10($t3)
    MEM_H(0X10, ctx->r11) = 0;
    // 0x801CBF10: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CBF14: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801CBF18: sh          $zero, 0x12($t5)
    MEM_H(0X12, ctx->r13) = 0;
    // 0x801CBF1C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801CBF20: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801CBF24: sh          $zero, 0x14($t7)
    MEM_H(0X14, ctx->r15) = 0;
    // 0x801CBF28: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801CBF2C: lwc1        $f10, 0xA0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x801CBF30: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801CBF34: swc1        $f10, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f10.u32l;
    // 0x801CBF38: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801CBF3C: lwc1        $f16, 0xA4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x801CBF40: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801CBF44: swc1        $f16, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f16.u32l;
    // 0x801CBF48: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CBF4C: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x801CBF50: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801CBF54: swc1        $f18, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f18.u32l;
    // 0x801CBF58: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CBF5C: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x801CBF60: lw          $t5, 0x24($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X24);
    // 0x801CBF64: ori         $t6, $t5, 0x300
    ctx->r14 = ctx->r13 | 0X300;
    // 0x801CBF68: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x801CBF6C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CBF70: addiu       $t6, $zero, 0xF4
    ctx->r14 = ADD32(0, 0XF4);
    // 0x801CBF74: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801CBF78: sb          $v1, 0x48($t9)
    MEM_B(0X48, ctx->r25) = ctx->r3;
    // 0x801CBF7C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CBF80: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801CBF84: sb          $v1, 0x49($t0)
    MEM_B(0X49, ctx->r8) = ctx->r3;
    // 0x801CBF88: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CBF8C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801CBF90: sb          $t1, 0x4A($t3)
    MEM_B(0X4A, ctx->r11) = ctx->r9;
    // 0x801CBF94: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801CBF98: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801CBF9C: sb          $v1, 0x4B($t5)
    MEM_B(0X4B, ctx->r13) = ctx->r3;
    // 0x801CBFA0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801CBFA4: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801CBFA8: sb          $t6, 0x4C($t9)
    MEM_B(0X4C, ctx->r25) = ctx->r14;
    // 0x801CBFAC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801CBFB0: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801CBFB4: sb          $zero, 0x4D($t0)
    MEM_B(0X4D, ctx->r8) = 0;
    // 0x801CBFB8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801CBFBC: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x801CBFC0: sb          $zero, 0x4E($t1)
    MEM_B(0X4E, ctx->r9) = 0;
    // 0x801CBFC4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801CBFC8: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CBFCC: jal         0x800058DC
    // 0x801CBFD0: sb          $v1, 0x4F($t4)
    MEM_B(0X4F, ctx->r12) = ctx->r3;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801CBFD0: sb          $v1, 0x4F($t4)
    MEM_B(0X4F, ctx->r12) = ctx->r3;
    after_3:
    // 0x801CBFD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801CBFD8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801CBFDC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801CBFE0: jr          $ra
    // 0x801CBFE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801CBFE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cbfe8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cbfe8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CBFE8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801CBFEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801CBFF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CBFF4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801CBFF8: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x801CBFFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801CC000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CC004: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801CC008: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801CC00C: bgez        $t6, L_801CC024
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801CC010: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801CC024;
    }
    // 0x801CC010: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801CC014: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CC018: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CC01C: nop

    // 0x801CC020: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801CC024:
    // 0x801CC024: lhu         $t7, 0xAA($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XAA);
    // 0x801CC028: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801CC02C: addiu       $a2, $zero, 0x2DD
    ctx->r6 = ADD32(0, 0X2DD);
    // 0x801CC030: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801CC034: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801CC038: bgez        $t7, L_801CC04C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801CC03C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801CC04C;
    }
    // 0x801CC03C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801CC040: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CC044: nop

    // 0x801CC048: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801CC04C:
    // 0x801CC04C: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801CC050: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801CC054: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801CC058: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801CC05C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801CC060: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801CC064: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801CC068: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801CC06C: nop

    // 0x801CC070: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801CC074: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801CC078: nop

    // 0x801CC07C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801CC080: beql        $v0, $zero, L_801CC0D0
    if (ctx->r2 == 0) {
        // 0x801CC084: mfc1        $v0, $f18
        ctx->r2 = (int32_t)ctx->f18.u32l;
            goto L_801CC0D0;
    }
    goto skip_0;
    // 0x801CC084: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x801CC088: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801CC08C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801CC090: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801CC094: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801CC098: nop

    // 0x801CC09C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801CC0A0: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801CC0A4: nop

    // 0x801CC0A8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801CC0AC: bne         $v0, $zero, L_801CC0C4
    if (ctx->r2 != 0) {
        // 0x801CC0B0: nop
    
            goto L_801CC0C4;
    }
    // 0x801CC0B0: nop

    // 0x801CC0B4: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x801CC0B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801CC0BC: b           L_801CC0DC
    // 0x801CC0C0: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_801CC0DC;
    // 0x801CC0C0: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_801CC0C4:
    // 0x801CC0C4: b           L_801CC0DC
    // 0x801CC0C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_801CC0DC;
    // 0x801CC0C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801CC0CC: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
L_801CC0D0:
    // 0x801CC0D0: nop

    // 0x801CC0D4: bltz        $v0, L_801CC0C4
    if (SIGNED(ctx->r2) < 0) {
        // 0x801CC0D8: nop
    
            goto L_801CC0C4;
    }
    // 0x801CC0D8: nop

L_801CC0DC:
    // 0x801CC0DC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x801CC0E0: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x801CC0E4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801CC0E8: mfhi        $v0
    ctx->r2 = hi;
    // 0x801CC0EC: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x801CC0F0: lw          $a1, 0x30($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X30);
    // 0x801CC0F4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801CC0F8: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // 0x801CC0FC: lw          $a3, -0x55A0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X55A0);
    // 0x801CC100: jal         0x8012CF8C
    // 0x801CC104: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801CC104: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x801CC108: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801CC10C: lw          $t2, -0x4328($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4328);
    // 0x801CC110: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x801CC114: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801CC118: lwc1        $f16, 0x30($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801CC11C: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801CC120: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801CC124: sub.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x801CC128: sub.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801CC12C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801CC130: jal         0x8001EF38
    // 0x801CC134: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x801CC134: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x801CC138: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801CC13C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801CC140: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x801CC144: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801CC148: addiu       $t5, $v0, 0x1000
    ctx->r13 = ADD32(ctx->r2, 0X1000);
    // 0x801CC14C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801CC150: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801CC154: andi        $t6, $t5, 0x1FFF
    ctx->r14 = ctx->r13 & 0X1FFF;
    // 0x801CC158: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801CC15C: sh          $t6, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r14;
    // 0x801CC160: jal         0x8002FC20
    // 0x801CC164: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x801CC164: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_2:
    // 0x801CC168: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801CC16C: lw          $t0, -0x4328($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4328);
    // 0x801CC170: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801CC174: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x801CC178: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801CC17C: lwc1        $f16, 0x34($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801CC180: jal         0x8001EF38
    // 0x801CC184: sub.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f16.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x801CC184: sub.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f16.fl;
    after_3:
    // 0x801CC188: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x801CC18C: andi        $t1, $v0, 0x1FFF
    ctx->r9 = ctx->r2 & 0X1FFF;
    // 0x801CC190: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801CC194: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801CC198: sh          $t1, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r9;
    // 0x801CC19C: lhu         $t5, 0xA8($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XA8);
    // 0x801CC1A0: lhu         $t6, 0xAA($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XAA);
    // 0x801CC1A4: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x801CC1A8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x801CC1AC: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801CC1B0: bne         $at, $zero, L_801CC1D8
    if (ctx->r1 != 0) {
        // 0x801CC1B4: sh          $t7, 0xA8($s0)
        MEM_H(0XA8, ctx->r16) = ctx->r15;
            goto L_801CC1D8;
    }
    // 0x801CC1B4: sh          $t7, 0xA8($s0)
    MEM_H(0XA8, ctx->r16) = ctx->r15;
    // 0x801CC1B8: lhu         $t9, 0x90($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X90);
    // 0x801CC1BC: beql        $t9, $zero, L_801CC1D8
    if (ctx->r25 == 0) {
        // 0x801CC1C0: sh          $zero, 0xA8($s0)
        MEM_H(0XA8, ctx->r16) = 0;
            goto L_801CC1D8;
    }
    goto skip_1;
    // 0x801CC1C0: sh          $zero, 0xA8($s0)
    MEM_H(0XA8, ctx->r16) = 0;
    skip_1:
    // 0x801CC1C4: jal         0x80005700
    // 0x801CC1C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x801CC1C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801CC1CC: b           L_801CC1D8
    // 0x801CC1D0: nop

        goto L_801CC1D8;
    // 0x801CC1D0: nop

    // 0x801CC1D4: sh          $zero, 0xA8($s0)
    MEM_H(0XA8, ctx->r16) = 0;
L_801CC1D8:
    // 0x801CC1D8: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801CC1DC: lw          $t0, -0x58E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X58E8);
    // 0x801CC1E0: beql        $t0, $zero, L_801CC1F4
    if (ctx->r8 == 0) {
        // 0x801CC1E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801CC1F4;
    }
    goto skip_2;
    // 0x801CC1E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x801CC1E8: jal         0x80005700
    // 0x801CC1EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_5;
    // 0x801CC1EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801CC1F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801CC1F4:
    // 0x801CC1F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CC1F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801CC1FC: jr          $ra
    // 0x801CC200: nop

    return;
    // 0x801CC200: nop

;}
RECOMP_FUNC void M24_FUN_801cc204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC204: nop

    // 0x801CC208: nop

    // 0x801CC20C: nop

;}
RECOMP_FUNC void M24_FUN_801cc210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC210: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC214: sw          $zero, -0x5544($at)
    MEM_W(-0X5544, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc218(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CC21C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC220: sw          $zero, -0x54EC($at)
    MEM_W(-0X54EC, ctx->r1) = 0;
    // 0x801CC224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC228: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CC22C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC230: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CC234: sw          $zero, -0x54E8($at)
    MEM_W(-0X54E8, ctx->r1) = 0;
    // 0x801CC238: jal         0x801BF6C4
    // 0x801CC23C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801BF6C4)(rdram, ctx);
        goto after_0;
    // 0x801CC23C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x801CC240: jal         0x801CC9FC
    // 0x801CC244: nop

    LOOKUP_FUNC(0x801CC9FC)(rdram, ctx);
        goto after_1;
    // 0x801CC244: nop

    after_1:
    // 0x801CC248: jal         0x801CCA44
    // 0x801CC24C: nop

    LOOKUP_FUNC(0x801CCA44)(rdram, ctx);
        goto after_2;
    // 0x801CC24C: nop

    after_2:
    // 0x801CC250: jal         0x801CCAB0
    // 0x801CC254: nop

    LOOKUP_FUNC(0x801CCAB0)(rdram, ctx);
        goto after_3;
    // 0x801CC254: nop

    after_3:
    // 0x801CC258: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC25C: addiu       $a1, $a1, -0x3D88
    ctx->r5 = ADD32(ctx->r5, -0X3D88);
    // 0x801CC260: jal         0x800058DC
    // 0x801CC264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801CC264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x801CC268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CC26C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CC270: jr          $ra
    // 0x801CC274: nop

    return;
    // 0x801CC274: nop

;}
RECOMP_FUNC void M24_FUN_801cc278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC278: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CC27C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC280: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801CC284: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC288: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801CC28C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CC290: jal         0x801BF968
    // 0x801CC294: sw          $t6, -0x5544($at)
    MEM_W(-0X5544, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x801BF968)(rdram, ctx);
        goto after_0;
    // 0x801CC294: sw          $t6, -0x5544($at)
    MEM_W(-0X5544, ctx->r1) = ctx->r14;
    after_0:
    // 0x801CC298: beql        $v0, $zero, L_801CC2BC
    if (ctx->r2 == 0) {
        // 0x801CC29C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801CC2BC;
    }
    goto skip_0;
    // 0x801CC29C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801CC2A0: jal         0x8013B130
    // 0x801CC2A4: nop

    LOOKUP_FUNC(0x8013B130)(rdram, ctx);
        goto after_1;
    // 0x801CC2A4: nop

    after_1:
    // 0x801CC2A8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801CC2AC: addiu       $a1, $a1, -0x3D38
    ctx->r5 = ADD32(ctx->r5, -0X3D38);
    // 0x801CC2B0: jal         0x800058DC
    // 0x801CC2B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801CC2B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801CC2B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801CC2BC:
    // 0x801CC2BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CC2C0: jr          $ra
    // 0x801CC2C4: nop

    return;
    // 0x801CC2C4: nop

;}
RECOMP_FUNC void M24_FUN_801cc2c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC2C8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc2cc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc2cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC2CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801CC2D0: sw          $a0, -0x54EC($at)
    MEM_W(-0X54EC, ctx->r1) = ctx->r4;
    // 0x801CC2D4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC2D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801CC2DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801CC2E0: sw          $a1, -0x54E8($at)
    MEM_W(-0X54E8, ctx->r1) = ctx->r5;
    // 0x801CC2E4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801CC2E8: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801CC2EC: addiu       $a2, $a2, 0xBB0
    ctx->r6 = ADD32(ctx->r6, 0XBB0);
    // 0x801CC2F0: addiu       $a0, $a0, -0x5550
    ctx->r4 = ADD32(ctx->r4, -0X5550);
    // 0x801CC2F4: jal         0x801BF850
    // 0x801CC2F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801BF850)(rdram, ctx);
        goto after_0;
    // 0x801CC2F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x801CC2FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801CC300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801CC304: jr          $ra
    // 0x801CC308: nop

    return;
    // 0x801CC308: nop

;}
RECOMP_FUNC void M24_FUN_801cc30c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC30C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801CC310: jr          $ra
    // 0x801CC314: lw          $v0, -0x5544($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5544);
    return;
    // 0x801CC314: lw          $v0, -0x5544($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5544);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc318(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC318: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CC31C: addiu       $v1, $v1, -0x5540
    ctx->r3 = ADD32(ctx->r3, -0X5540);
    // 0x801CC320: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801CC324: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801CC328: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801CC32C: jr          $ra
    // 0x801CC330: slti        $v0, $t7, 0xA
    ctx->r2 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    return;
    // 0x801CC330: slti        $v0, $t7, 0xA
    ctx->r2 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc334(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC334: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801CC338: addiu       $v1, $v1, -0x553C
    ctx->r3 = ADD32(ctx->r3, -0X553C);
    // 0x801CC33C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801CC340: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801CC344: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801CC348: jr          $ra
    // 0x801CC34C: slti        $v0, $t7, 0xA
    ctx->r2 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    return;
    // 0x801CC34C: slti        $v0, $t7, 0xA
    ctx->r2 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc350(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC350: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801CC354: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801CC358: lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // 0x801CC35C: addiu       $s2, $s2, -0x5540
    ctx->r18 = ADD32(ctx->r18, -0X5540);
    // 0x801CC360: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x801CC364: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801CC368: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801CC36C: beq         $v0, $zero, L_801CC3A8
    if (ctx->r2 == 0) {
        // 0x801CC370: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_801CC3A8;
    }
    // 0x801CC370: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801CC374: blez        $v0, L_801CC3A4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801CC378: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801CC3A4;
    }
    // 0x801CC378: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CC37C: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x801CC380: addiu       $s1, $s1, 0xA48
    ctx->r17 = ADD32(ctx->r17, 0XA48);
L_801CC384:
    // 0x801CC384: jal         0x801C250C
    // 0x801CC388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801C250C)(rdram, ctx);
        goto after_0;
    // 0x801CC388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x801CC38C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x801CC390: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CC394: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x801CC398: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801CC39C: bne         $at, $zero, L_801CC384
    if (ctx->r1 != 0) {
        // 0x801CC3A0: nop
    
            goto L_801CC384;
    }
    // 0x801CC3A0: nop

L_801CC3A4:
    // 0x801CC3A4: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_801CC3A8:
    // 0x801CC3A8: lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // 0x801CC3AC: addiu       $s2, $s2, -0x553C
    ctx->r18 = ADD32(ctx->r18, -0X553C);
    // 0x801CC3B0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x801CC3B4: beq         $v0, $zero, L_801CC3F0
    if (ctx->r2 == 0) {
        // 0x801CC3B8: nop
    
            goto L_801CC3F0;
    }
    // 0x801CC3B8: nop

    // 0x801CC3BC: blez        $v0, L_801CC3EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801CC3C0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801CC3EC;
    }
    // 0x801CC3C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801CC3C4: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x801CC3C8: addiu       $s1, $s1, 0xB38
    ctx->r17 = ADD32(ctx->r17, 0XB38);
L_801CC3CC:
    // 0x801CC3CC: jal         0x801C25B0
    // 0x801CC3D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x801C25B0)(rdram, ctx);
        goto after_1;
    // 0x801CC3D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801CC3D4: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x801CC3D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801CC3DC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x801CC3E0: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x801CC3E4: bne         $at, $zero, L_801CC3CC
    if (ctx->r1 != 0) {
        // 0x801CC3E8: nop
    
            goto L_801CC3CC;
    }
    // 0x801CC3E8: nop

L_801CC3EC:
    // 0x801CC3EC: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_801CC3F0:
    // 0x801CC3F0: jal         0x801CC9FC
    // 0x801CC3F4: nop

    LOOKUP_FUNC(0x801CC9FC)(rdram, ctx);
        goto after_2;
    // 0x801CC3F4: nop

    after_2:
    // 0x801CC3F8: jal         0x801CCA44
    // 0x801CC3FC: nop

    LOOKUP_FUNC(0x801CCA44)(rdram, ctx);
        goto after_3;
    // 0x801CC3FC: nop

    after_3:
    // 0x801CC400: jal         0x801CCAB0
    // 0x801CC404: nop

    LOOKUP_FUNC(0x801CCAB0)(rdram, ctx);
        goto after_4;
    // 0x801CC404: nop

    after_4:
    // 0x801CC408: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801CC40C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801CC410: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x801CC414: addiu       $s2, $s2, -0x1500
    ctx->r18 = ADD32(ctx->r18, -0X1500);
    // 0x801CC418: addiu       $s0, $s0, -0x2680
    ctx->r16 = ADD32(ctx->r16, -0X2680);
    // 0x801CC41C: addiu       $s1, $s1, -0x1500
    ctx->r17 = ADD32(ctx->r17, -0X1500);
L_801CC420:
    // 0x801CC420: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x801CC424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801CC428: jal         0x800279F0
    // 0x801CC42C: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    LOOKUP_FUNC(0x800279F0)(rdram, ctx);
        goto after_5;
    // 0x801CC42C: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    after_5:
    // 0x801CC430: addiu       $s0, $s0, 0xE0
    ctx->r16 = ADD32(ctx->r16, 0XE0);
    // 0x801CC434: bne         $s0, $s2, L_801CC420
    if (ctx->r16 != ctx->r18) {
        // 0x801CC438: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_801CC420;
    }
    // 0x801CC438: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801CC43C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801CC440: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801CC444: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801CC448: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801CC44C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801CC450: jr          $ra
    // 0x801CC454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801CC454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc458(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC458: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801CC45C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC460: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801CC464: sw          $a1, 0x6D8($at)
    MEM_W(0X6D8, ctx->r1) = ctx->r5;
    // 0x801CC468: jr          $ra
    // 0x801CC46C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801CC46C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc470(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC470: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801CC474: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801CC478: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CC47C: addiu       $t7, $t7, 0x660
    ctx->r15 = ADD32(ctx->r15, 0X660);
    // 0x801CC480: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801CC484: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x801CC488: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x801CC48C: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x801CC490: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801CC494: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x801CC498: sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
    // 0x801CC49C: sh          $a3, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r7;
    // 0x801CC4A0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801CC4A4: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x801CC4A8: lw          $t9, 0x6D8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D8);
    // 0x801CC4AC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CC4B0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801CC4B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801CC4B8: jr          $ra
    // 0x801CC4BC: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
    return;
    // 0x801CC4BC: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc4c0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc4c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC4C0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801CC4C4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801CC4C8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801CC4CC: sw          $a1, 0x778($at)
    MEM_W(0X778, ctx->r1) = ctx->r5;
    // 0x801CC4D0: jr          $ra
    // 0x801CC4D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801CC4D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc4d8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801cc4d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801CC4D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801CC4DC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801CC4E0: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801CC4E4: addiu       $t7, $t7, 0x700
    ctx->r15 = ADD32(ctx->r15, 0X700);
    // 0x801CC4E8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801CC4EC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x801CC4F0: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x801CC4F4: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x801CC4F8: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801CC4FC: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x801CC500: sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
    // 0x801CC504: sh          $a3, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r7;
    // 0x801CC508: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801CC50C: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x801CC510: lw          $t9, 0x778($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X778);
    // 0x801CC514: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801CC518: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801CC51C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801CC520: jr          $ra
    // 0x801CC524: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
    return;
    // 0x801CC524: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801cc528(rdram, ctx);
;}
