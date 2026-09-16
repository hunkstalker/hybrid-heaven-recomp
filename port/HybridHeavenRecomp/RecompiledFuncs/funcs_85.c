#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M9_FUN_801f2c7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F2C7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F2C80: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801F2C84: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801F2C88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F2C8C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801F2C90: beq         $t6, $zero, L_801F2E9C
    if (ctx->r14 == 0) {
        // 0x801F2C94: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_801F2E9C;
    }
    // 0x801F2C94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F2C98: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801F2C9C: jal         0x80005E44
    // 0x801F2CA0: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801F2CA0: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x801F2CA4: jal         0x80006214
    // 0x801F2CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801F2CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801F2CAC: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x801F2CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F2CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F2CB8: ori         $t8, $t7, 0xC20
    ctx->r24 = ctx->r15 | 0XC20;
    // 0x801F2CBC: jal         0x8012636C
    // 0x801F2CC0: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_2;
    // 0x801F2CC0: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    after_2:
    // 0x801F2CC4: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x801F2CC8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F2CCC: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801F2CD0: lh          $t9, 0x8($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X8);
    // 0x801F2CD4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F2CD8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F2CDC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801F2CE0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F2CE4: lw          $t1, 0x10($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X10);
    // 0x801F2CE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F2CEC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801F2CF0: srl         $t2, $t1, 16
    ctx->r10 = S32(U32(ctx->r9) >> 16);
    // 0x801F2CF4: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x801F2CF8: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x801F2CFC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x801F2D00: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801F2D04: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F2D08: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x801F2D0C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801F2D10: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801F2D14: add.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f6.d + ctx->f2.d;
    // 0x801F2D18: add.d       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f16.d + ctx->f2.d;
    // 0x801F2D1C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F2D20: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F2D24: sub.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f8.d - ctx->f0.d;
    // 0x801F2D28: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x801F2D2C: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x801F2D30: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x801F2D34: nop

    // 0x801F2D38: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801F2D3C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801F2D40: bgez        $v0, L_801F2D50
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801F2D44: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_801F2D50;
    }
    // 0x801F2D44: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x801F2D48: b           L_801F2D50
    // 0x801F2D4C: negu        $t0, $v0
    ctx->r8 = SUB32(0, ctx->r2);
        goto L_801F2D50;
    // 0x801F2D4C: negu        $t0, $v0
    ctx->r8 = SUB32(0, ctx->r2);
L_801F2D50:
    // 0x801F2D50: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x801F2D54: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801F2D58: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801F2D5C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x801F2D60: swc1        $f12, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f12.u32l;
    // 0x801F2D64: swc1        $f12, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f12.u32l;
    // 0x801F2D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F2D6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F2D70: add.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f8.d + ctx->f0.d;
    // 0x801F2D74: trunc.w.d   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x801F2D78: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x801F2D7C: nop

    // 0x801F2D80: sh          $t7, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r15;
    // 0x801F2D84: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x801F2D88: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801F2D8C: srl         $t9, $t8, 16
    ctx->r25 = S32(U32(ctx->r24) >> 16);
    // 0x801F2D90: sll         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25 << 16);
    // 0x801F2D94: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x801F2D98: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x801F2D9C: nop

    // 0x801F2DA0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801F2DA4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801F2DA8: add.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f6.d + ctx->f2.d;
    // 0x801F2DAC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F2DB0: swc1        $f10, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f10.u32l;
    // 0x801F2DB4: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x801F2DB8: lw          $v0, 0x18($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X18);
    // 0x801F2DBC: srl         $a3, $v0, 16
    ctx->r7 = S32(U32(ctx->r2) >> 16);
    // 0x801F2DC0: andi        $a3, $a3, 0xF
    ctx->r7 = ctx->r7 & 0XF;
    // 0x801F2DC4: jal         0x8012C89C
    // 0x801F2DC8: srl         $a2, $v0, 20
    ctx->r6 = S32(U32(ctx->r2) >> 20);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x801F2DC8: srl         $a2, $v0, 20
    ctx->r6 = S32(U32(ctx->r2) >> 20);
    after_3:
    // 0x801F2DCC: lhu         $t6, 0x36($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X36);
    // 0x801F2DD0: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x801F2DD4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801F2DD8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801F2DDC: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801F2DE0: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x801F2DE4: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x801F2DE8: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x801F2DEC: srl         $t3, $t2, 16
    ctx->r11 = S32(U32(ctx->r10) >> 16);
    // 0x801F2DF0: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x801F2DF4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801F2DF8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801F2DFC: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x801F2E00: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x801F2E04: jal         0x8000522C
    // 0x801F2E08: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_4;
    // 0x801F2E08: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    after_4:
    // 0x801F2E0C: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x801F2E10: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801F2E14: ori         $a1, $a1, 0xC00
    ctx->r5 = ctx->r5 | 0XC00;
    // 0x801F2E18: jal         0x800062F8
    // 0x801F2E1C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_5;
    // 0x801F2E1C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x801F2E20: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801F2E24: addiu       $t7, $zero, 0x13
    ctx->r15 = ADD32(0, 0X13);
    // 0x801F2E28: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x801F2E2C: sw          $t7, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r15;
    // 0x801F2E30: jal         0x8000C3B0
    // 0x801F2E34: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_6;
    // 0x801F2E34: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_6:
    // 0x801F2E38: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801F2E3C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801F2E40: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801F2E44: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F2E48: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F2E4C: addiu       $a1, $a1, 0x2EB0
    ctx->r5 = ADD32(ctx->r5, 0X2EB0);
    // 0x801F2E50: sw          $v0, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r2;
    // 0x801F2E54: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801F2E58: lbu         $t4, 0xF32($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF32);
    // 0x801F2E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F2E60: lw          $t5, 0x30($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X30);
    // 0x801F2E64: sb          $t4, 0x4C($t5)
    MEM_B(0X4C, ctx->r13) = ctx->r12;
    // 0x801F2E68: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801F2E6C: lbu         $t6, 0xF33($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF33);
    // 0x801F2E70: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x801F2E74: sb          $t6, 0x4D($t7)
    MEM_B(0X4D, ctx->r15) = ctx->r14;
    // 0x801F2E78: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801F2E7C: lbu         $t1, 0xF34($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XF34);
    // 0x801F2E80: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801F2E84: sb          $t1, 0x4E($t3)
    MEM_B(0X4E, ctx->r11) = ctx->r9;
    // 0x801F2E88: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801F2E8C: lbu         $t9, 0xF35($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF35);
    // 0x801F2E90: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F2E94: jal         0x800058DC
    // 0x801F2E98: sb          $t9, 0x4F($t5)
    MEM_B(0X4F, ctx->r13) = ctx->r25;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801F2E98: sb          $t9, 0x4F($t5)
    MEM_B(0X4F, ctx->r13) = ctx->r25;
    after_7:
L_801F2E9C:
    // 0x801F2E9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F2EA0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801F2EA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801F2EA8: jr          $ra
    // 0x801F2EAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801F2EAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f2eb0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f2eb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F2EB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F2EB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F2EB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F2EBC: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x801F2EC0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801F2EC4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801F2EC8: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x801F2ECC: lbu         $t6, 0x28($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X28);
    // 0x801F2ED0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F2ED4: srl         $t9, $t8, 16
    ctx->r25 = S32(U32(ctx->r24) >> 16);
    // 0x801F2ED8: srl         $t1, $t9, 12
    ctx->r9 = S32(U32(ctx->r25) >> 12);
    // 0x801F2EDC: nor         $t2, $t1, $zero
    ctx->r10 = ~(ctx->r9 | 0);
    // 0x801F2EE0: and         $t3, $t6, $t2
    ctx->r11 = ctx->r14 & ctx->r10;
    // 0x801F2EE4: sb          $t3, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r11;
    // 0x801F2EE8: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x801F2EEC: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801F2EF0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F2EF4: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x801F2EF8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F2EFC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F2F00: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x801F2F04: lw          $t4, 0x24($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X24);
    // 0x801F2F08: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801F2F0C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801F2F10: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F2F14: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801F2F18: lwc1        $f4, 0x8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X8);
    // 0x801F2F1C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801F2F20: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x801F2F24: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x801F2F28: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x801F2F2C: c.eq.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d == ctx->f4.d;
    // 0x801F2F30: nop

    // 0x801F2F34: bc1fl       L_801F2F78
    if (!c1cs) {
        // 0x801F2F38: lw          $t9, 0x10($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X10);
            goto L_801F2F78;
    }
    goto skip_0;
    // 0x801F2F38: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x801F2F3C: lhu         $t8, 0x4($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X4);
    // 0x801F2F40: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801F2F44: addiu       $a0, $zero, 0x1FA
    ctx->r4 = ADD32(0, 0X1FA);
    // 0x801F2F48: beq         $t8, $at, L_801F2F5C
    if (ctx->r24 == ctx->r1) {
        // 0x801F2F4C: nop
    
            goto L_801F2F5C;
    }
    // 0x801F2F4C: nop

    // 0x801F2F50: jal         0x80020718
    // 0x801F2F54: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801F2F54: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801F2F58: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_801F2F5C:
    // 0x801F2F5C: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F2F60: addiu       $a1, $a1, 0x3610
    ctx->r5 = ADD32(ctx->r5, 0X3610);
    // 0x801F2F64: jal         0x800058DC
    // 0x801F2F68: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801F2F68: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x801F2F6C: b           L_801F2FE4
    // 0x801F2F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801F2FE4;
    // 0x801F2F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F2F74: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
L_801F2F78:
    // 0x801F2F78: srl         $t0, $t9, 16
    ctx->r8 = S32(U32(ctx->r25) >> 16);
    // 0x801F2F7C: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x801F2F80: sra         $t6, $t1, 16
    ctx->r14 = S32(SIGNED(ctx->r9) >> 16);
    // 0x801F2F84: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x801F2F88: nop

    // 0x801F2F8C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801F2F90: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801F2F94: add.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d + ctx->f2.d;
    // 0x801F2F98: c.eq.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d == ctx->f16.d;
    // 0x801F2F9C: nop

    // 0x801F2FA0: bc1fl       L_801F2FE4
    if (!c1cs) {
        // 0x801F2FA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F2FE4;
    }
    goto skip_1;
    // 0x801F2FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801F2FA8: lw          $t2, 0x24($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X24);
    // 0x801F2FAC: addiu       $a0, $zero, 0x1FA
    ctx->r4 = ADD32(0, 0X1FA);
    // 0x801F2FB0: bnel        $a3, $t2, L_801F2FE4
    if (ctx->r7 != ctx->r10) {
        // 0x801F2FB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F2FE4;
    }
    goto skip_2;
    // 0x801F2FB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x801F2FB8: jal         0x80020718
    // 0x801F2FBC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_2;
    // 0x801F2FBC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x801F2FC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F2FC4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x801F2FC8: jal         0x801518D4
    // 0x801F2FCC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x801518D4)(rdram, ctx);
        goto after_3;
    // 0x801F2FCC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_3:
    // 0x801F2FD0: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F2FD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801F2FD8: jal         0x800058DC
    // 0x801F2FDC: addiu       $a1, $a1, 0x2FF0
    ctx->r5 = ADD32(ctx->r5, 0X2FF0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801F2FDC: addiu       $a1, $a1, 0x2FF0
    ctx->r5 = ADD32(ctx->r5, 0X2FF0);
    after_4:
    // 0x801F2FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801F2FE4:
    // 0x801F2FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F2FE8: jr          $ra
    // 0x801F2FEC: nop

    return;
    // 0x801F2FEC: nop

;}
RECOMP_FUNC void M9_FUN_801f2ff0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F2FF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F2FF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F2FF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F2FFC: lwc1        $f4, 0xA4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XA4);
    // 0x801F3000: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801F3004: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F3008: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x801F300C: c.eq.d      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.d == ctx->f2.d;
    // 0x801F3010: nop

    // 0x801F3014: bc1fl       L_801F3134
    if (!c1cs) {
        // 0x801F3018: lw          $v1, 0x38($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X38);
            goto L_801F3134;
    }
    goto skip_0;
    // 0x801F3018: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    skip_0:
    // 0x801F301C: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x801F3020: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801F3024: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801F3028: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x801F302C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F3030: lwc1        $f2, 0xA0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x801F3034: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x801F3038: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801F303C: bgez        $t7, L_801F3050
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801F3040: cvt.s.w     $f12, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801F3050;
    }
    // 0x801F3040: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801F3044: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F3048: nop

    // 0x801F304C: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
L_801F3050:
    // 0x801F3050: div.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    // 0x801F3054: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801F3058: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801F305C: nop

    // 0x801F3060: bc1fl       L_801F3084
    if (!c1cs) {
        // 0x801F3064: swc1        $f0, 0xA0($a0)
        MEM_W(0XA0, ctx->r4) = ctx->f0.u32l;
            goto L_801F3084;
    }
    goto skip_1;
    // 0x801F3064: swc1        $f0, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f0.u32l;
    skip_1:
    // 0x801F3068: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F306C: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x801F3070: div.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f12.fl, ctx->f16.fl);
    // 0x801F3074: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x801F3078: b           L_801F30F8
    // 0x801F307C: swc1        $f4, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f4.u32l;
        goto L_801F30F8;
    // 0x801F307C: swc1        $f4, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f4.u32l;
    // 0x801F3080: swc1        $f0, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f0.u32l;
L_801F3084:
    // 0x801F3084: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x801F3088: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x801F308C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F3090: srl         $t8, $v0, 16
    ctx->r24 = S32(U32(ctx->r2) >> 16);
    // 0x801F3094: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x801F3098: sra         $t3, $t9, 16
    ctx->r11 = S32(SIGNED(ctx->r25) >> 16);
    // 0x801F309C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x801F30A0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F30A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F30A8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801F30AC: lw          $t4, 0x30($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X30);
    // 0x801F30B0: andi        $t5, $v0, 0xFFFF
    ctx->r13 = ctx->r2 & 0XFFFF;
    // 0x801F30B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F30B8: lwc1        $f4, 0x8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X8);
    // 0x801F30BC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801F30C0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801F30C4: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801F30C8: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x801F30CC: sub.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d - ctx->f6.d;
    // 0x801F30D0: bgez        $t5, L_801F30E4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801F30D4: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801F30E4;
    }
    // 0x801F30D4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801F30D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F30DC: nop

    // 0x801F30E0: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_801F30E4:
    // 0x801F30E4: div.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f14.fl);
    // 0x801F30E8: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x801F30EC: sub.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d - ctx->f6.d;
    // 0x801F30F0: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801F30F4: swc1        $f4, 0xA4($a0)
    MEM_W(0XA4, ctx->r4) = ctx->f4.u32l;
L_801F30F8:
    // 0x801F30F8: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
    // 0x801F30FC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F3100: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F3104: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x801F3108: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F310C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F3110: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801F3114: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F3118: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F311C: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    // 0x801F3120: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x801F3124: div.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f6.d);
    // 0x801F3128: b           L_801F321C
    // 0x801F312C: add.d       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f10.d + ctx->f4.d;
        goto L_801F321C;
    // 0x801F312C: add.d       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f10.d + ctx->f4.d;
    // 0x801F3130: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
L_801F3134:
    // 0x801F3134: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F3138: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F313C: lh          $t8, 0x8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X8);
    // 0x801F3140: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F3144: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x801F3148: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x801F314C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F3150: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x801F3154: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801F3158: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F315C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F3160: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F3164: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x801F3168: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801F316C: div.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f6.d);
    // 0x801F3170: add.d       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f10.d + ctx->f4.d;
    // 0x801F3174: sub.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f18.d - ctx->f0.d;
    // 0x801F3178: c.lt.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d < ctx->f2.d;
    // 0x801F317C: nop

    // 0x801F3180: bc1fl       L_801F3220
    if (!c1cs) {
        // 0x801F3184: cvt.s.d     $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f10.fl = CVT_S_D(ctx->f0.d);
            goto L_801F3220;
    }
    goto skip_2;
    // 0x801F3184: cvt.s.d     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f10.fl = CVT_S_D(ctx->f0.d);
    skip_2:
    // 0x801F3188: lw          $t9, 0x10($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X10);
    // 0x801F318C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F3190: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x801F3194: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x801F3198: bgez        $t3, L_801F31AC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801F319C: cvt.s.w     $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801F31AC;
    }
    // 0x801F319C: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801F31A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F31A4: nop

    // 0x801F31A8: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
L_801F31AC:
    // 0x801F31AC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801F31B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F31B4: lwc1        $f2, 0xA0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x801F31B8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801F31BC: div.s       $f16, $f12, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x801F31C0: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x801F31C4: nop

    // 0x801F31C8: bc1fl       L_801F3220
    if (!c1cs) {
        // 0x801F31CC: cvt.s.d     $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f10.fl = CVT_S_D(ctx->f0.d);
            goto L_801F3220;
    }
    goto skip_3;
    // 0x801F31CC: cvt.s.d     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f10.fl = CVT_S_D(ctx->f0.d);
    skip_3:
    // 0x801F31D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F31D4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F31D8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F31DC: div.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f12.fl, ctx->f18.fl);
    // 0x801F31E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F31E4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F31E8: lw          $t4, 0x24($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X24);
    // 0x801F31EC: sub.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x801F31F0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F31F4: swc1        $f6, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f6.u32l;
    // 0x801F31F8: lh          $t5, 0x8($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X8);
    // 0x801F31FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F3200: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x801F3204: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x801F3208: nop

    // 0x801F320C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801F3210: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x801F3214: div.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x801F3218: add.d       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = ctx->f8.d + ctx->f6.d;
L_801F321C:
    // 0x801F321C: cvt.s.d     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f10.fl = CVT_S_D(ctx->f0.d);
L_801F3220:
    // 0x801F3220: lwc1        $f4, 0xA0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x801F3224: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x801F3228: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x801F322C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801F3230: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F3234: jal         0x8012AAE8
    // 0x801F3238: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8012AAE8)(rdram, ctx);
        goto after_0;
    // 0x801F3238: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801F323C: bne         $v0, $zero, L_801F32DC
    if (ctx->r2 != 0) {
        // 0x801F3240: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801F32DC;
    }
    // 0x801F3240: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801F3244: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801F3248: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F324C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F3250: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x801F3254: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F3258: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F325C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x801F3260: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F3264: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F3268: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801F326C: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x801F3270: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801F3274: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801F3278: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F327C: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F3280: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x801F3284: addiu       $a1, $a1, 0x3430
    ctx->r5 = ADD32(ctx->r5, 0X3430);
    // 0x801F3288: div.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f6.d);
    // 0x801F328C: add.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f10.d + ctx->f4.d;
    // 0x801F3290: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F3294: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F3298: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F329C: swc1        $f18, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f18.u32l;
    // 0x801F32A0: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x801F32A4: lw          $t5, -0x4330($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4330);
    // 0x801F32A8: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801F32AC: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801F32B0: lwc1        $f8, 0x8($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X8);
    // 0x801F32B4: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x801F32B8: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x801F32BC: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x801F32C0: swc1        $f16, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f16.u32l;
    // 0x801F32C4: jal         0x800058DC
    // 0x801F32C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801F32C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x801F32CC: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801F32D0: addiu       $t2, $t2, -0x4410
    ctx->r10 = ADD32(ctx->r10, -0X4410);
    // 0x801F32D4: b           L_801F331C
    // 0x801F32D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_801F331C;
    // 0x801F32D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_801F32DC:
    // 0x801F32DC: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x801F32E0: lwc1        $f8, 0xA0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x801F32E4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801F32E8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801F32EC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F32F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F32F4: lwc1        $f18, 0x8($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801F32F8: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801F32FC: addiu       $t2, $t2, -0x4410
    ctx->r10 = ADD32(ctx->r10, -0X4410);
    // 0x801F3300: sub.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x801F3304: lw          $t9, 0xE0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0XE0);
    // 0x801F3308: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x801F330C: lw          $t3, 0x2C($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X2C);
    // 0x801F3310: add.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f10.d + ctx->f4.d;
    // 0x801F3314: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F3318: swc1        $f18, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f18.u32l;
L_801F331C:
    // 0x801F331C: lw          $t4, 0x24($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X24);
    // 0x801F3320: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x801F3324: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F3328: lw          $t4, 0xE0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XE0);
    // 0x801F332C: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x801F3330: lh          $t6, 0x12($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X12);
    // 0x801F3334: lw          $a2, 0x2C($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X2C);
    // 0x801F3338: sll         $t3, $t9, 8
    ctx->r11 = S32(ctx->r25 << 8);
    // 0x801F333C: subu        $t1, $t6, $t3
    ctx->r9 = SUB32(ctx->r14, ctx->r11);
    // 0x801F3340: lh          $t0, 0x12($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X12);
    // 0x801F3344: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x801F3348: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x801F334C: subu        $v0, $t1, $t0
    ctx->r2 = SUB32(ctx->r9, ctx->r8);
    // 0x801F3350: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801F3354: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801F3358: andi        $a3, $v0, 0x1000
    ctx->r7 = ctx->r2 & 0X1000;
    // 0x801F335C: beq         $a3, $zero, L_801F3370
    if (ctx->r7 == 0) {
        // 0x801F3360: andi        $v1, $v0, 0x1FFF
        ctx->r3 = ctx->r2 & 0X1FFF;
            goto L_801F3370;
    }
    // 0x801F3360: andi        $v1, $v0, 0x1FFF
    ctx->r3 = ctx->r2 & 0X1FFF;
    // 0x801F3364: andi        $v1, $v0, 0x1FFF
    ctx->r3 = ctx->r2 & 0X1FFF;
    // 0x801F3368: b           L_801F3374
    // 0x801F336C: addiu       $a1, $v1, -0x2000
    ctx->r5 = ADD32(ctx->r3, -0X2000);
        goto L_801F3374;
    // 0x801F336C: addiu       $a1, $v1, -0x2000
    ctx->r5 = ADD32(ctx->r3, -0X2000);
L_801F3370:
    // 0x801F3370: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_801F3374:
    // 0x801F3374: bgez        $a1, L_801F3398
    if (SIGNED(ctx->r5) >= 0) {
        // 0x801F3378: nop
    
            goto L_801F3398;
    }
    // 0x801F3378: nop

    // 0x801F337C: beq         $a3, $zero, L_801F3390
    if (ctx->r7 == 0) {
        // 0x801F3380: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_801F3390;
    }
    // 0x801F3380: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x801F3384: addiu       $a1, $v1, -0x2000
    ctx->r5 = ADD32(ctx->r3, -0X2000);
    // 0x801F3388: b           L_801F33AC
    // 0x801F338C: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
        goto L_801F33AC;
    // 0x801F338C: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
L_801F3390:
    // 0x801F3390: b           L_801F33AC
    // 0x801F3394: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
        goto L_801F33AC;
    // 0x801F3394: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
L_801F3398:
    // 0x801F3398: beq         $a3, $zero, L_801F33A8
    if (ctx->r7 == 0) {
        // 0x801F339C: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_801F33A8;
    }
    // 0x801F339C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x801F33A0: b           L_801F33A8
    // 0x801F33A4: addiu       $a1, $v1, -0x2000
    ctx->r5 = ADD32(ctx->r3, -0X2000);
        goto L_801F33A8;
    // 0x801F33A4: addiu       $a1, $v1, -0x2000
    ctx->r5 = ADD32(ctx->r3, -0X2000);
L_801F33A8:
    // 0x801F33A8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_801F33AC:
    // 0x801F33AC: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x801F33B0: bnel        $at, $zero, L_801F3408
    if (ctx->r1 != 0) {
        // 0x801F33B4: sh          $t1, 0x12($a2)
        MEM_H(0X12, ctx->r6) = ctx->r9;
            goto L_801F3408;
    }
    goto skip_4;
    // 0x801F33B4: sh          $t1, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r9;
    skip_4:
    // 0x801F33B8: beq         $a3, $zero, L_801F33C8
    if (ctx->r7 == 0) {
        // 0x801F33BC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801F33C8;
    }
    // 0x801F33BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801F33C0: b           L_801F33C8
    // 0x801F33C4: addiu       $v0, $v1, -0x2000
    ctx->r2 = ADD32(ctx->r3, -0X2000);
        goto L_801F33C8;
    // 0x801F33C4: addiu       $v0, $v1, -0x2000
    ctx->r2 = ADD32(ctx->r3, -0X2000);
L_801F33C8:
    // 0x801F33C8: bgez        $v0, L_801F33DC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801F33CC: addiu       $t7, $t0, 0x40
        ctx->r15 = ADD32(ctx->r8, 0X40);
            goto L_801F33DC;
    }
    // 0x801F33CC: addiu       $t7, $t0, 0x40
    ctx->r15 = ADD32(ctx->r8, 0X40);
    // 0x801F33D0: addiu       $t5, $t0, -0x40
    ctx->r13 = ADD32(ctx->r8, -0X40);
    // 0x801F33D4: b           L_801F33E0
    // 0x801F33D8: sh          $t5, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r13;
        goto L_801F33E0;
    // 0x801F33D8: sh          $t5, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r13;
L_801F33DC:
    // 0x801F33DC: sh          $t7, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r15;
L_801F33E0:
    // 0x801F33E0: lw          $t8, 0xE0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XE0);
    // 0x801F33E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801F33E8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F33EC: lw          $a2, 0x2C($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X2C);
    // 0x801F33F0: lh          $t9, 0x12($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X12);
    // 0x801F33F4: andi        $t6, $t9, 0x1FFF
    ctx->r14 = ctx->r25 & 0X1FFF;
    // 0x801F33F8: sh          $t6, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r14;
    // 0x801F33FC: b           L_801F3410
    // 0x801F3400: sb          $t3, -0x5030($at)
    MEM_B(-0X5030, ctx->r1) = ctx->r11;
        goto L_801F3410;
    // 0x801F3400: sb          $t3, -0x5030($at)
    MEM_B(-0X5030, ctx->r1) = ctx->r11;
    // 0x801F3404: sh          $t1, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r9;
L_801F3408:
    // 0x801F3408: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F340C: sb          $zero, -0x5030($at)
    MEM_B(-0X5030, ctx->r1) = 0;
L_801F3410:
    // 0x801F3410: lw          $t4, 0x24($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X24);
    // 0x801F3414: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801F3418: jal         0x801F38B8
    // 0x801F341C: lwc1        $f12, 0x8($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X8);
    LOOKUP_FUNC(0x801F38B8)(rdram, ctx);
        goto after_2;
    // 0x801F341C: lwc1        $f12, 0x8($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X8);
    after_2:
    // 0x801F3420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F3424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F3428: jr          $ra
    // 0x801F342C: nop

    return;
    // 0x801F342C: nop

;}
RECOMP_FUNC void M9_FUN_801f3430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3430: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F3434: lhu         $t6, -0x440C($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X440C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f3438(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f3438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F343C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801F3440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F3444: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F3448: bne         $t6, $at, L_801F34C4
    if (ctx->r14 != ctx->r1) {
        // 0x801F344C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801F34C4;
    }
    // 0x801F344C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F3450: lw          $t0, 0x38($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X38);
    // 0x801F3454: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x801F3458: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F345C: lh          $t1, 0x8($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X8);
    // 0x801F3460: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801F3464: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F3468: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801F346C: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x801F3470: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F3474: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801F3478: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F347C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801F3480: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F3484: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801F3488: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801F348C: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x801F3490: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x801F3494: c.eq.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d == ctx->f10.d;
    // 0x801F3498: nop

    // 0x801F349C: bc1f        L_801F34DC
    if (!c1cs) {
        // 0x801F34A0: nop
    
            goto L_801F34DC;
    }
    // 0x801F34A0: nop

    // 0x801F34A4: jal         0x80020718
    // 0x801F34A8: addiu       $a0, $zero, 0x1FC
    ctx->r4 = ADD32(0, 0X1FC);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801F34A8: addiu       $a0, $zero, 0x1FC
    ctx->r4 = ADD32(0, 0X1FC);
    after_0:
    // 0x801F34AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F34B0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x801F34B4: jal         0x801518D4
    // 0x801F34B8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x801518D4)(rdram, ctx);
        goto after_1;
    // 0x801F34B8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x801F34BC: b           L_801F34DC
    // 0x801F34C0: nop

        goto L_801F34DC;
    // 0x801F34C0: nop

L_801F34C4:
    // 0x801F34C4: jal         0x80020718
    // 0x801F34C8: addiu       $a0, $zero, 0x1FC
    ctx->r4 = ADD32(0, 0X1FC);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_2;
    // 0x801F34C8: addiu       $a0, $zero, 0x1FC
    ctx->r4 = ADD32(0, 0X1FC);
    after_2:
    // 0x801F34CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F34D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x801F34D4: jal         0x801518D4
    // 0x801F34D8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x801518D4)(rdram, ctx);
        goto after_3;
    // 0x801F34D8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_3:
L_801F34DC:
    // 0x801F34DC: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F34E0: addiu       $a1, $a1, 0x34FC
    ctx->r5 = ADD32(ctx->r5, 0X34FC);
    // 0x801F34E4: jal         0x800058DC
    // 0x801F34E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801F34E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x801F34EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F34F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F34F4: jr          $ra
    // 0x801F34F8: nop

    return;
    // 0x801F34F8: nop

;}
RECOMP_FUNC void M9_FUN_801f34fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F34FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F3500: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801F3504: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x801F3508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F350C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F3510: sw          $zero, 0x24($a2)
    MEM_W(0X24, ctx->r6) = 0;
    // 0x801F3514: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x801F3518: lw          $t6, 0xE0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XE0);
    // 0x801F351C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F3520: lw          $v1, 0x14($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X14);
    // 0x801F3524: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801F3528: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801F352C: srl         $v1, $v1, 16
    ctx->r3 = S32(U32(ctx->r3) >> 16);
    // 0x801F3530: andi        $t8, $v1, 0xFFF
    ctx->r24 = ctx->r3 & 0XFFF;
    // 0x801F3534: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801F3538: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F353C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x801F3540: bgez        $t8, L_801F3558
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801F3544: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_801F3558;
    }
    // 0x801F3544: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x801F3548: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F354C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F3550: nop

    // 0x801F3554: add.d       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f8.d + ctx->f10.d;
L_801F3558:
    // 0x801F3558: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801F355C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F3560: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x801F3564: mul.d       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f0.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x801F3568: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    // 0x801F356C: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801F3570: cvt.d.s     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f12.d = CVT_D_S(ctx->f18.fl);
    // 0x801F3574: add.d       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f0.d + ctx->f12.d;
    // 0x801F3578: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x801F357C: nop

    // 0x801F3580: bc1fl       L_801F35EC
    if (!c1cs) {
        // 0x801F3584: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_801F35EC;
    }
    goto skip_0;
    // 0x801F3584: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x801F3588: sub.d       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f12.d - ctx->f0.d;
    // 0x801F358C: c.lt.d      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.d < ctx->f2.d;
    // 0x801F3590: nop

    // 0x801F3594: bc1fl       L_801F35EC
    if (!c1cs) {
        // 0x801F3598: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_801F35EC;
    }
    goto skip_1;
    // 0x801F3598: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x801F359C: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x801F35A0: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801F35A4: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x801F35A8: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x801F35AC: add.d       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = ctx->f0.d + ctx->f12.d;
    // 0x801F35B0: c.lt.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d < ctx->f16.d;
    // 0x801F35B4: nop

    // 0x801F35B8: bc1fl       L_801F35EC
    if (!c1cs) {
        // 0x801F35BC: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_801F35EC;
    }
    goto skip_2;
    // 0x801F35BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_2:
    // 0x801F35C0: sub.d       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f12.d - ctx->f0.d;
    // 0x801F35C4: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x801F35C8: nop

    // 0x801F35CC: bc1fl       L_801F35EC
    if (!c1cs) {
        // 0x801F35D0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_801F35EC;
    }
    goto skip_3;
    // 0x801F35D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x801F35D4: lbu         $t0, 0x28($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X28);
    // 0x801F35D8: srl         $t2, $v1, 12
    ctx->r10 = S32(U32(ctx->r3) >> 12);
    // 0x801F35DC: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x801F35E0: b           L_801F3600
    // 0x801F35E4: sb          $t3, 0x28($a2)
    MEM_B(0X28, ctx->r6) = ctx->r11;
        goto L_801F3600;
    // 0x801F35E4: sb          $t3, 0x28($a2)
    MEM_B(0X28, ctx->r6) = ctx->r11;
    // 0x801F35E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_801F35EC:
    // 0x801F35EC: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F35F0: addiu       $a1, $a1, 0x2EB0
    ctx->r5 = ADD32(ctx->r5, 0X2EB0);
    // 0x801F35F4: swc1        $f0, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f0.u32l;
    // 0x801F35F8: jal         0x800058DC
    // 0x801F35FC: swc1        $f0, 0xA4($a0)
    MEM_W(0XA4, ctx->r4) = ctx->f0.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801F35FC: swc1        $f0, 0xA4($a0)
    MEM_W(0XA4, ctx->r4) = ctx->f0.u32l;
    after_0:
L_801F3600:
    // 0x801F3600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F3604: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F3608: jr          $ra
    // 0x801F360C: nop

    return;
    // 0x801F360C: nop

;}
RECOMP_FUNC void M9_FUN_801f3610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3610: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F3614: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F3618: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F361C: lwc1        $f4, 0xA4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XA4);
    // 0x801F3620: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801F3624: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F3628: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x801F362C: c.eq.d      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.d == ctx->f2.d;
    // 0x801F3630: nop

    // 0x801F3634: bc1fl       L_801F3758
    if (!c1cs) {
        // 0x801F3638: lw          $v1, 0x38($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X38);
            goto L_801F3758;
    }
    goto skip_0;
    // 0x801F3638: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    skip_0:
    // 0x801F363C: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x801F3640: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801F3644: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801F3648: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x801F364C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F3650: lwc1        $f2, 0xA0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x801F3654: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x801F3658: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801F365C: bgez        $t7, L_801F3670
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801F3660: cvt.s.w     $f12, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801F3670;
    }
    // 0x801F3660: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801F3664: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F3668: nop

    // 0x801F366C: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
L_801F3670:
    // 0x801F3670: div.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    // 0x801F3674: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801F3678: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801F367C: nop

    // 0x801F3680: bc1fl       L_801F36A4
    if (!c1cs) {
        // 0x801F3684: swc1        $f0, 0xA0($a0)
        MEM_W(0XA0, ctx->r4) = ctx->f0.u32l;
            goto L_801F36A4;
    }
    goto skip_1;
    // 0x801F3684: swc1        $f0, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f0.u32l;
    skip_1:
    // 0x801F3688: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F368C: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x801F3690: div.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f12.fl, ctx->f16.fl);
    // 0x801F3694: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x801F3698: b           L_801F3720
    // 0x801F369C: swc1        $f4, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f4.u32l;
        goto L_801F3720;
    // 0x801F369C: swc1        $f4, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f4.u32l;
    // 0x801F36A0: swc1        $f0, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f0.u32l;
L_801F36A4:
    // 0x801F36A4: lh          $t8, 0x8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X8);
    // 0x801F36A8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F36AC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F36B0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801F36B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F36B8: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x801F36BC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801F36C0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F36C4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F36C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F36CC: lw          $t9, 0x30($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X30);
    // 0x801F36D0: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x801F36D4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801F36D8: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x801F36DC: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x801F36E0: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x801F36E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F36E8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801F36EC: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F36F0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x801F36F4: sub.d       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f10.d - ctx->f6.d;
    // 0x801F36F8: bgez        $t1, L_801F370C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801F36FC: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801F370C;
    }
    // 0x801F36FC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801F3700: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F3704: nop

    // 0x801F3708: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_801F370C:
    // 0x801F370C: div.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
    // 0x801F3710: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x801F3714: sub.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f16.d - ctx->f6.d;
    // 0x801F3718: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x801F371C: swc1        $f8, 0xA4($a0)
    MEM_W(0XA4, ctx->r4) = ctx->f8.u32l;
L_801F3720:
    // 0x801F3720: lw          $t2, 0x10($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X10);
    // 0x801F3724: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F3728: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F372C: srl         $t3, $t2, 16
    ctx->r11 = S32(U32(ctx->r10) >> 16);
    // 0x801F3730: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x801F3734: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x801F3738: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801F373C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F3740: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    // 0x801F3744: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F3748: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801F374C: b           L_801F3834
    // 0x801F3750: add.d       $f0, $f16, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = ctx->f16.d + ctx->f6.d;
        goto L_801F3834;
    // 0x801F3750: add.d       $f0, $f16, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = ctx->f16.d + ctx->f6.d;
    // 0x801F3754: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
L_801F3758:
    // 0x801F3758: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x801F375C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F3760: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    // 0x801F3764: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801F3768: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F376C: srl         $t6, $a1, 16
    ctx->r14 = S32(U32(ctx->r5) >> 16);
    // 0x801F3770: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x801F3774: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x801F3778: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x801F377C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F3780: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F3784: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801F3788: andi        $t0, $a1, 0xFFFF
    ctx->r8 = ctx->r5 & 0XFFFF;
    // 0x801F378C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x801F3790: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x801F3794: add.d       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = ctx->f4.d + ctx->f10.d;
    // 0x801F3798: sub.d       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f0.d - ctx->f6.d;
    // 0x801F379C: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x801F37A0: nop

    // 0x801F37A4: bc1fl       L_801F3838
    if (!c1cs) {
        // 0x801F37A8: cvt.s.d     $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
            goto L_801F3838;
    }
    goto skip_2;
    // 0x801F37A8: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
    skip_2:
    // 0x801F37AC: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801F37B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F37B4: bgez        $t0, L_801F37C8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801F37B8: cvt.s.w     $f12, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801F37C8;
    }
    // 0x801F37B8: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801F37BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F37C0: nop

    // 0x801F37C4: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
L_801F37C8:
    // 0x801F37C8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801F37CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F37D0: lwc1        $f2, 0xA0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x801F37D4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801F37D8: div.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f12.fl, ctx->f10.fl);
    // 0x801F37DC: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x801F37E0: nop

    // 0x801F37E4: bc1fl       L_801F3838
    if (!c1cs) {
        // 0x801F37E8: cvt.s.d     $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
            goto L_801F3838;
    }
    goto skip_3;
    // 0x801F37E8: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
    skip_3:
    // 0x801F37EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F37F0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F37F4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F37F8: div.s       $f18, $f12, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f12.fl, ctx->f6.fl);
    // 0x801F37FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F3800: lw          $t1, 0x24($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X24);
    // 0x801F3804: sub.s       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x801F3808: swc1        $f8, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f8.u32l;
    // 0x801F380C: lw          $t2, 0x10($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X10);
    // 0x801F3810: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x801F3814: srl         $t3, $t2, 16
    ctx->r11 = S32(U32(ctx->r10) >> 16);
    // 0x801F3818: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x801F381C: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x801F3820: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801F3824: nop

    // 0x801F3828: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F382C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801F3830: add.d       $f0, $f16, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = ctx->f16.d + ctx->f6.d;
L_801F3834:
    // 0x801F3834: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
L_801F3838:
    // 0x801F3838: lwc1        $f8, 0xA0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x801F383C: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x801F3840: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x801F3844: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x801F3848: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F384C: jal         0x8012AAE8
    // 0x801F3850: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8012AAE8)(rdram, ctx);
        goto after_0;
    // 0x801F3850: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801F3854: bne         $v0, $zero, L_801F38A8
    if (ctx->r2 != 0) {
        // 0x801F3858: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801F38A8;
    }
    // 0x801F3858: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801F385C: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801F3860: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F3864: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F3868: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x801F386C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F3870: lw          $t1, 0x24($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X24);
    // 0x801F3874: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x801F3878: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x801F387C: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x801F3880: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x801F3884: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801F3888: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F388C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F3890: addiu       $a1, $a1, 0x3430
    ctx->r5 = ADD32(ctx->r5, 0X3430);
    // 0x801F3894: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801F3898: add.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f16.d + ctx->f6.d;
    // 0x801F389C: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x801F38A0: jal         0x800058DC
    // 0x801F38A4: swc1        $f8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f8.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801F38A4: swc1        $f8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f8.u32l;
    after_1:
L_801F38A8:
    // 0x801F38A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F38AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F38B0: jr          $ra
    // 0x801F38B4: nop

    return;
    // 0x801F38B4: nop

;}
RECOMP_FUNC void M9_FUN_801f38b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F38B8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801F38BC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801F38C0: lw          $t6, 0xDC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XDC);
    // 0x801F38C4: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x801F38C8: lw          $v0, 0x64($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X64);
    // 0x801F38CC: beq         $v0, $zero, L_801F38EC
    if (ctx->r2 == 0) {
        // 0x801F38D0: nop
    
            goto L_801F38EC;
    }
    // 0x801F38D0: nop

    // 0x801F38D4: lw          $t7, 0xE0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XE0);
    // 0x801F38D8: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x801F38DC: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801F38E0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801F38E4: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801F38E8: swc1        $f4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f4.u32l;
L_801F38EC:
    // 0x801F38EC: jr          $ra
    // 0x801F38F0: nop

    return;
    // 0x801F38F0: nop

;}
RECOMP_FUNC void M9_FUN_801f38f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F38F4: nop

    // 0x801F38F8: nop

    // 0x801F38FC: nop

;}
RECOMP_FUNC void M9_FUN_801f3900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3900: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F3904: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F3908: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F390C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801F3910: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801F3914: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F3918: jal         0x80005E44
    // 0x801F391C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801F391C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x801F3920: jal         0x80006214
    // 0x801F3924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801F3924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801F3928: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x801F392C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F3930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F3934: ori         $t7, $t6, 0x800
    ctx->r15 = ctx->r14 | 0X800;
    // 0x801F3938: jal         0x8012636C
    // 0x801F393C: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_2;
    // 0x801F393C: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    after_2:
    // 0x801F3940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F3944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F3948: jal         0x8012C784
    // 0x801F394C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_3;
    // 0x801F394C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x801F3950: lhu         $t8, 0x36($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X36);
    // 0x801F3954: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801F3958: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801F395C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x801F3960: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x801F3964: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801F3968: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801F396C: lhu         $a0, 0x0($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X0);
    // 0x801F3970: jal         0x8000522C
    // 0x801F3974: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_4;
    // 0x801F3974: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    after_4:
    // 0x801F3978: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F397C: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x801F3980: addiu       $a1, $a1, 0x39A0
    ctx->r5 = ADD32(ctx->r5, 0X39A0);
    // 0x801F3984: jal         0x800058DC
    // 0x801F3988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801F3988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801F398C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F3990: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801F3994: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F3998: jr          $ra
    // 0x801F399C: nop

    return;
    // 0x801F399C: nop

;}
RECOMP_FUNC void M9_FUN_801f39a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F39A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F39A4: jr          $ra
    // 0x801F39A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801F39A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f39ac(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f39ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F39AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F39B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F39B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F39B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801F39BC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801F39C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F39C4: jal         0x80005E44
    // 0x801F39C8: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801F39C8: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x801F39CC: jal         0x80006214
    // 0x801F39D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801F39D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801F39D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F39D8: jal         0x8012636C
    // 0x801F39DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_2;
    // 0x801F39DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x801F39E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F39E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F39E8: addiu       $a2, $zero, 0x86
    ctx->r6 = ADD32(0, 0X86);
    // 0x801F39EC: jal         0x8012C89C
    // 0x801F39F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x801F39F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x801F39F4: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F39F8: addiu       $a1, $a1, 0x3A18
    ctx->r5 = ADD32(ctx->r5, 0X3A18);
    // 0x801F39FC: jal         0x800058DC
    // 0x801F3A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801F3A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801F3A04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F3A08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801F3A0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F3A10: jr          $ra
    // 0x801F3A14: nop

    return;
    // 0x801F3A14: nop

;}
RECOMP_FUNC void M9_FUN_801f3a18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3A18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F3A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F3A20: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801F3A24: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F3A28: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x801F3A2C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801F3A30: jal         0x80133A24
    // 0x801F3A34: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801F3A34: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x801F3A38: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801F3A3C: beq         $v0, $zero, L_801F3A48
    if (ctx->r2 == 0) {
        // 0x801F3A40: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_801F3A48;
    }
    // 0x801F3A40: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x801F3A44: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801F3A48:
    // 0x801F3A48: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801F3A4C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x801F3A50: jal         0x80133A24
    // 0x801F3A54: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_1;
    // 0x801F3A54: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x801F3A58: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801F3A5C: beq         $v0, $zero, L_801F3A68
    if (ctx->r2 == 0) {
        // 0x801F3A60: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_801F3A68;
    }
    // 0x801F3A60: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x801F3A64: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
L_801F3A68:
    // 0x801F3A68: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x801F3A6C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x801F3A70: jal         0x80133A24
    // 0x801F3A74: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_2;
    // 0x801F3A74: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x801F3A78: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801F3A7C: beq         $v0, $zero, L_801F3A88
    if (ctx->r2 == 0) {
        // 0x801F3A80: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_801F3A88;
    }
    // 0x801F3A80: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x801F3A84: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
L_801F3A88:
    // 0x801F3A88: beq         $v1, $zero, L_801F3ABC
    if (ctx->r3 == 0) {
        // 0x801F3A8C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801F3ABC;
    }
    // 0x801F3A8C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801F3A90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F3A94: beq         $v1, $at, L_801F3AD0
    if (ctx->r3 == ctx->r1) {
        // 0x801F3A98: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801F3AD0;
    }
    // 0x801F3A98: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801F3A9C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801F3AA0: beq         $v1, $at, L_801F3AE4
    if (ctx->r3 == ctx->r1) {
        // 0x801F3AA4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801F3AE4;
    }
    // 0x801F3AA4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801F3AA8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801F3AAC: beq         $v1, $at, L_801F3AF8
    if (ctx->r3 == ctx->r1) {
        // 0x801F3AB0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801F3AF8;
    }
    // 0x801F3AB0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801F3AB4: b           L_801F3B0C
    // 0x801F3AB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
        goto L_801F3B0C;
    // 0x801F3AB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_801F3ABC:
    // 0x801F3ABC: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x801F3AC0: jal         0x8012D844
    // 0x801F3AC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801F3AC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801F3AC8: b           L_801F3B1C
    // 0x801F3ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801F3B1C;
    // 0x801F3ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801F3AD0:
    // 0x801F3AD0: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x801F3AD4: jal         0x8012D844
    // 0x801F3AD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x801F3AD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x801F3ADC: b           L_801F3B1C
    // 0x801F3AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801F3B1C;
    // 0x801F3AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801F3AE4:
    // 0x801F3AE4: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x801F3AE8: jal         0x8012D844
    // 0x801F3AEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_5;
    // 0x801F3AEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x801F3AF0: b           L_801F3B1C
    // 0x801F3AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801F3B1C;
    // 0x801F3AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801F3AF8:
    // 0x801F3AF8: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x801F3AFC: jal         0x8012D844
    // 0x801F3B00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_6;
    // 0x801F3B00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x801F3B04: b           L_801F3B1C
    // 0x801F3B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801F3B1C;
    // 0x801F3B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801F3B0C:
    // 0x801F3B0C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x801F3B10: jal         0x8012D844
    // 0x801F3B14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_7;
    // 0x801F3B14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x801F3B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801F3B1C:
    // 0x801F3B1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F3B20: jr          $ra
    // 0x801F3B24: nop

    return;
    // 0x801F3B24: nop

;}
RECOMP_FUNC void M9_FUN_801f3b28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3B28: nop

    // 0x801F3B2C: nop

    // 0x801F3B30: jr          $ra
    // 0x801F3B34: nop

    return;
    // 0x801F3B34: nop

;}
RECOMP_FUNC void M9_FUN_801f3b38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3B38: lui         $t6, 0x8021
    ctx->r14 = S32(0X8021 << 16);
    // 0x801F3B3C: lbu         $t6, 0x6F24($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X6F24);
    // 0x801F3B40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F3B44: beq         $t6, $zero, L_801F3B54
    if (ctx->r14 == 0) {
            // 0x801F3B48: nop

    LOOKUP_FUNC(0x801F3B54)(rdram, ctx);
    return;
    }
    // 0x801F3B48: nop

    // 0x801F3B4C: jr          $ra
    // 0x801F3B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801F3B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f3b54(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f3b54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3B54: jr          $ra
    // 0x801F3B58: nop

    return;
    // 0x801F3B58: nop

;}
RECOMP_FUNC void M9_FUN_801f3b5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3B5C: lui         $at, 0x8021
    ctx->r1 = S32(0X8021 << 16);
    // 0x801F3B60: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F3B64: jr          $ra
    // 0x801F3B68: sb          $a0, 0x6F24($at)
    MEM_B(0X6F24, ctx->r1) = ctx->r4;
    return;
    // 0x801F3B68: sb          $a0, 0x6F24($at)
    MEM_B(0X6F24, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f3b6c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f3b6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3B6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F3B70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F3B74: lw          $t0, 0x5C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X5C);
    // 0x801F3B78: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801F3B7C: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x801F3B80: lhu         $t6, 0x1A($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X1A);
    // 0x801F3B84: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801F3B88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F3B8C: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    // 0x801F3B90: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x801F3B94: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801F3B98: lw          $a1, 0x2C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X2C);
    // 0x801F3B9C: lwc1        $f12, 0x30($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801F3BA0: lwc1        $f14, 0x34($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801F3BA4: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x801F3BA8: lw          $a2, 0x38($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X38);
    // 0x801F3BAC: lw          $a3, 0x4($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X4);
    // 0x801F3BB0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F3BB4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801F3BB8: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x801F3BBC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801F3BC0: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
    // 0x801F3BC4: jal         0x8010843C
    // 0x801F3BC8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_0;
    // 0x801F3BC8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x801F3BCC: bne         $v0, $zero, L_801F3C80
    if (ctx->r2 != 0) {
        // 0x801F3BD0: lhu         $v1, 0x26($sp)
        ctx->r3 = MEM_HU(ctx->r29, 0X26);
            goto L_801F3C80;
    }
    // 0x801F3BD0: lhu         $v1, 0x26($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X26);
    // 0x801F3BD4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x801F3BD8: lhu         $t9, -0x2DB0($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2DB0);
    // 0x801F3BDC: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x801F3BE0: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x801F3BE4: beq         $t9, $zero, L_801F3C30
    if (ctx->r25 == 0) {
        // 0x801F3BE8: sll         $t1, $t1, 1
        ctx->r9 = S32(ctx->r9 << 1);
            goto L_801F3C30;
    }
    // 0x801F3BE8: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x801F3BEC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801F3BF0: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x801F3BF4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801F3BF8: addiu       $a1, $a1, -0x2DB0
    ctx->r5 = ADD32(ctx->r5, -0X2DB0);
    // 0x801F3BFC: lhu         $v0, -0x2DB0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2DB0);
    // 0x801F3C00: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    // 0x801F3C04: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_801F3C08:
    // 0x801F3C08: beql        $a0, $v0, L_801F3C34
    if (ctx->r4 == ctx->r2) {
        // 0x801F3C0C: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_801F3C34;
    }
    goto skip_0;
    // 0x801F3C0C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    skip_0:
    // 0x801F3C10: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801F3C14: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x801F3C18: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801F3C1C: mflo        $t2
    ctx->r10 = lo;
    // 0x801F3C20: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x801F3C24: lhu         $v0, 0x0($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X0);
    // 0x801F3C28: bne         $v0, $zero, L_801F3C08
    if (ctx->r2 != 0) {
        // 0x801F3C2C: nop
    
            goto L_801F3C08;
    }
    // 0x801F3C2C: nop

L_801F3C30:
    // 0x801F3C30: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_801F3C34:
    // 0x801F3C34: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801F3C38: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801F3C3C: addiu       $a1, $a1, -0x2DB0
    ctx->r5 = ADD32(ctx->r5, -0X2DB0);
    // 0x801F3C40: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x801F3C44: mflo        $t4
    ctx->r12 = lo;
    // 0x801F3C48: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x801F3C4C: lhu         $a3, 0x2($t5)
    ctx->r7 = MEM_HU(ctx->r13, 0X2);
    // 0x801F3C50: beql        $a3, $zero, L_801F3C84
    if (ctx->r7 == 0) {
        // 0x801F3C54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801F3C84;
    }
    goto skip_1;
    // 0x801F3C54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801F3C58: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801F3C5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F3C60: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F3C64: lw          $a1, 0x2C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X2C);
    // 0x801F3C68: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801F3C6C: lwc1        $f14, 0x8($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X8);
    // 0x801F3C70: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x801F3C74: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801F3C78: jal         0x80127430
    // 0x801F3C7C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80127430)(rdram, ctx);
        goto after_1;
    // 0x801F3C7C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
L_801F3C80:
    // 0x801F3C80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801F3C84:
    // 0x801F3C84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801F3C88: jr          $ra
    // 0x801F3C8C: nop

    return;
    // 0x801F3C8C: nop

;}
RECOMP_FUNC void M9_FUN_801f3c90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3C90: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x801F3C94: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801F3C98: lw          $t0, -0x4328($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4328);
    // 0x801F3C9C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801F3CA0: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x801F3CA4: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x801F3CA8: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x801F3CAC: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x801F3CB0: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801F3CB4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x801F3CB8: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801F3CBC: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x801F3CC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F3CC4: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x801F3CC8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801F3CCC: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F3CD0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801F3CD4: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x801F3CD8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801F3CDC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801F3CE0: addiu       $a0, $a0, -0x7790
    ctx->r4 = ADD32(ctx->r4, -0X7790);
    // 0x801F3CE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F3CE8: addiu       $a1, $zero, 0x1D5
    ctx->r5 = ADD32(0, 0X1D5);
    // 0x801F3CEC: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x801F3CF0: lwc1        $f2, 0x34($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801F3CF4: sub.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x801F3CF8: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x801F3CFC: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801F3D00: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
    // 0x801F3D04: lwc1        $f14, 0x38($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801F3D08: sub.s       $f4, $f6, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x801F3D0C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801F3D10: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x801F3D14: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x801F3D18: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801F3D1C: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x801F3D20: lwc1        $f10, 0xC8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x801F3D24: sub.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x801F3D28: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801F3D2C: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x801F3D30: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x801F3D34: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801F3D38: sub.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x801F3D3C: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801F3D40: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x801F3D44: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801F3D48: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x801F3D4C: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x801F3D50: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801F3D54: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x801F3D58: sub.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801F3D5C: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801F3D60: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x801F3D64: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x801F3D68: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801F3D6C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x801F3D70: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x801F3D74: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x801F3D78: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801F3D7C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801F3D80: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x801F3D84: lwc1        $f10, 0xD8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x801F3D88: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801F3D8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F3D90: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801F3D94: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801F3D98: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801F3D9C: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x801F3DA0: add.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x801F3DA4: add.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x801F3DA8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801F3DAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F3DB0: add.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x801F3DB4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801F3DB8: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801F3DBC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x801F3DC0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801F3DC4: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801F3DC8: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801F3DCC: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801F3DD0: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x801F3DD4: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801F3DD8: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x801F3DDC: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801F3DE0: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x801F3DE4: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801F3DE8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801F3DEC: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x801F3DF0: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801F3DF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F3DF8: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x801F3DFC: jal         0x8011AAF4
    // 0x801F3E00: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x801F3E00: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801F3E04: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801F3E08: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801F3E0C: lwc1        $f14, 0xB4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x801F3E10: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801F3E14: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x801F3E18: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x801F3E1C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801F3E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F3E24: bc1fl       L_801F3E38
    if (!c1cs) {
        // 0x801F3E28: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_801F3E38;
    }
    goto skip_0;
    // 0x801F3E28: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x801F3E2C: b           L_801F3E38
    // 0x801F3E30: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_801F3E38;
    // 0x801F3E30: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x801F3E34: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_801F3E38:
    // 0x801F3E38: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x801F3E3C: nop

    // 0x801F3E40: bc1f        L_801F3F58
    if (!c1cs) {
        // 0x801F3E44: nop
    
            goto L_801F3F58;
    }
    // 0x801F3E44: nop

    // 0x801F3E48: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x801F3E4C: nop

    // 0x801F3E50: bc1fl       L_801F3E64
    if (!c1cs) {
        // 0x801F3E54: mov.s       $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
            goto L_801F3E64;
    }
    goto skip_1;
    // 0x801F3E54: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    skip_1:
    // 0x801F3E58: b           L_801F3E64
    // 0x801F3E5C: neg.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = -ctx->f16.fl;
        goto L_801F3E64;
    // 0x801F3E5C: neg.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = -ctx->f16.fl;
    // 0x801F3E60: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_801F3E64:
    // 0x801F3E64: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x801F3E68: nop

    // 0x801F3E6C: bc1f        L_801F3F58
    if (!c1cs) {
        // 0x801F3E70: nop
    
            goto L_801F3F58;
    }
    // 0x801F3E70: nop

    // 0x801F3E74: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x801F3E78: lwc1        $f2, 0xA0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801F3E7C: bc1fl       L_801F3E90
    if (!c1cs) {
        // 0x801F3E80: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_801F3E90;
    }
    goto skip_2;
    // 0x801F3E80: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_2:
    // 0x801F3E84: b           L_801F3E90
    // 0x801F3E88: neg.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = -ctx->f18.fl;
        goto L_801F3E90;
    // 0x801F3E88: neg.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = -ctx->f18.fl;
    // 0x801F3E8C: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
L_801F3E90:
    // 0x801F3E90: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x801F3E94: nop

    // 0x801F3E98: bc1f        L_801F3F58
    if (!c1cs) {
        // 0x801F3E9C: nop
    
            goto L_801F3F58;
    }
    // 0x801F3E9C: nop

    // 0x801F3EA0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x801F3EA4: nop

    // 0x801F3EA8: bc1fl       L_801F3EBC
    if (!c1cs) {
        // 0x801F3EAC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_801F3EBC;
    }
    goto skip_3;
    // 0x801F3EAC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_3:
    // 0x801F3EB0: b           L_801F3EBC
    // 0x801F3EB4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_801F3EBC;
    // 0x801F3EB4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x801F3EB8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_801F3EBC:
    // 0x801F3EBC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x801F3EC0: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801F3EC4: bc1f        L_801F3F58
    if (!c1cs) {
        // 0x801F3EC8: nop
    
            goto L_801F3F58;
    }
    // 0x801F3EC8: nop

    // 0x801F3ECC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x801F3ED0: nop

    // 0x801F3ED4: bc1fl       L_801F3EE8
    if (!c1cs) {
        // 0x801F3ED8: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_801F3EE8;
    }
    goto skip_4;
    // 0x801F3ED8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_4:
    // 0x801F3EDC: b           L_801F3EE8
    // 0x801F3EE0: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_801F3EE8;
    // 0x801F3EE0: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x801F3EE4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_801F3EE8:
    // 0x801F3EE8: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x801F3EEC: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801F3EF0: bc1f        L_801F3F58
    if (!c1cs) {
        // 0x801F3EF4: nop
    
            goto L_801F3F58;
    }
    // 0x801F3EF4: nop

    // 0x801F3EF8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x801F3EFC: nop

    // 0x801F3F00: bc1fl       L_801F3F14
    if (!c1cs) {
        // 0x801F3F04: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_801F3F14;
    }
    goto skip_5;
    // 0x801F3F04: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_5:
    // 0x801F3F08: b           L_801F3F14
    // 0x801F3F0C: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_801F3F14;
    // 0x801F3F0C: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x801F3F10: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_801F3F14:
    // 0x801F3F14: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x801F3F18: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x801F3F1C: bc1f        L_801F3F58
    if (!c1cs) {
        // 0x801F3F20: nop
    
            goto L_801F3F58;
    }
    // 0x801F3F20: nop

    // 0x801F3F24: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x801F3F28: nop

    // 0x801F3F2C: bc1fl       L_801F3F40
    if (!c1cs) {
        // 0x801F3F30: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_801F3F40;
    }
    goto skip_6;
    // 0x801F3F30: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_6:
    // 0x801F3F34: b           L_801F3F40
    // 0x801F3F38: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_801F3F40;
    // 0x801F3F38: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x801F3F3C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_801F3F40:
    // 0x801F3F40: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x801F3F44: nop

    // 0x801F3F48: bc1f        L_801F3F58
    if (!c1cs) {
        // 0x801F3F4C: nop
    
            goto L_801F3F58;
    }
    // 0x801F3F4C: nop

    // 0x801F3F50: b           L_801F3F58
    // 0x801F3F54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F3F58;
    // 0x801F3F54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F3F58:
    // 0x801F3F58: jr          $ra
    // 0x801F3F5C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x801F3F5C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f3f60(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f3f60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3F60: jr          $ra
    // 0x801F3F64: nop

    return;
    // 0x801F3F64: nop

;}
RECOMP_FUNC void M9_FUN_801f3f68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3F68: jr          $ra
    // 0x801F3F6C: nop

    return;
    // 0x801F3F6C: nop

;}
RECOMP_FUNC void M9_FUN_801f3f70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3F70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F3F74: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801F3F78: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801F3F7C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801F3F80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F3F84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801F3F88: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
L_801F3F8C:
    // 0x801F3F8C: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x801F3F90: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801F3F94: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F3F98: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F3F9C: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F3FA0: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801F3FA4: sub.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x801F3FA8: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x801F3FAC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801F3FB0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801F3FB4: jal         0x8010843C
    // 0x801F3FB8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_0;
    // 0x801F3FB8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801F3FBC: bnel        $v0, $zero, L_801F3FE0
    if (ctx->r2 != 0) {
        // 0x801F3FC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801F3FE0;
    }
    goto skip_0;
    // 0x801F3FC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801F3FC4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x801F3FC8: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801F3FCC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801F3FD0: slti        $at, $s0, 0x1F4
    ctx->r1 = SIGNED(ctx->r16) < 0X1F4 ? 1 : 0;
    // 0x801F3FD4: bnel        $at, $zero, L_801F3F8C
    if (ctx->r1 != 0) {
        // 0x801F3FD8: lw          $t6, 0x24($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X24);
            goto L_801F3F8C;
    }
    goto skip_1;
    // 0x801F3FD8: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    skip_1:
    // 0x801F3FDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F3FE0:
    // 0x801F3FE0: addiu       $v0, $s0, -0x1
    ctx->r2 = ADD32(ctx->r16, -0X1);
    // 0x801F3FE4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801F3FE8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801F3FEC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801F3FF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F3FF4: jr          $ra
    // 0x801F3FF8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x801F3FF8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f3ffc(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f3ffc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F3FFC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F4000: lhu         $t6, -0x3520($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3520);
    // 0x801F4004: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f4008(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f4008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4008: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F400C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801F4010: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801F4014: andi        $t7, $t6, 0x200
    ctx->r15 = ctx->r14 & 0X200;
    // 0x801F4018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F401C: beq         $t7, $zero, L_801F4030
    if (ctx->r15 == 0) {
        // 0x801F4020: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_801F4030;
    }
    // 0x801F4020: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F4024: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801F4028: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801F402C: nop

L_801F4030:
    // 0x801F4030: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801F4034: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801F4038: jal         0x8012A564
    // 0x801F403C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8012A564)(rdram, ctx);
        goto after_0;
    // 0x801F403C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x801F4040: beq         $v0, $zero, L_801F40A8
    if (ctx->r2 == 0) {
        // 0x801F4044: lwc1        $f14, 0x1C($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_801F40A8;
    }
    // 0x801F4044: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801F4048: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x801F404C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801F4050: lw          $t8, -0x4330($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4330);
    // 0x801F4054: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801F4058: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F405C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801F4060: lwc1        $f0, 0x8($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X8);
    // 0x801F4064: lwc1        $f2, 0x8($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X8);
    // 0x801F4068: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801F406C: nop

    // 0x801F4070: bc1fl       L_801F4088
    if (!c1cs) {
        // 0x801F4074: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_801F4088;
    }
    goto skip_0;
    // 0x801F4074: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x801F4078: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x801F407C: b           L_801F4088
    // 0x801F4080: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_801F4088;
    // 0x801F4080: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x801F4084: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_801F4088:
    // 0x801F4088: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x801F408C: nop

    // 0x801F4090: bc1fl       L_801F40AC
    if (!c1cs) {
        // 0x801F4094: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801F40AC;
    }
    goto skip_1;
    // 0x801F4094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801F4098: jal         0x801F3B5C
    // 0x801F409C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801F3B5C)(rdram, ctx);
        goto after_1;
    // 0x801F409C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801F40A0: b           L_801F40AC
    // 0x801F40A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F40AC;
    // 0x801F40A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F40A8:
    // 0x801F40A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F40AC:
    // 0x801F40AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F40B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F40B4: jr          $ra
    // 0x801F40B8: nop

    return;
    // 0x801F40B8: nop

;}
RECOMP_FUNC void M9_FUN_801f40bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F40BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F40C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F40C4: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801F40C8: lw          $t8, -0x4330($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4330);
    // 0x801F40CC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801F40D0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801F40D4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F40D8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F40DC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801F40E0: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x801F40E4: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801F40E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F40EC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801F40F0: jal         0x8012A564
    // 0x801F40F4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8012A564)(rdram, ctx);
        goto after_0;
    // 0x801F40F4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x801F40F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801F40FC: beq         $v0, $zero, L_801F415C
    if (ctx->r2 == 0) {
        // 0x801F4100: lwc1        $f0, 0x1C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_801F415C;
    }
    // 0x801F4100: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801F4104: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F4108: nop

    // 0x801F410C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x801F4110: nop

    // 0x801F4114: bc1fl       L_801F4160
    if (!c1cs) {
        // 0x801F4118: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801F4160;
    }
    goto skip_0;
    // 0x801F4118: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801F411C: lh          $t0, 0x92($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X92);
    // 0x801F4120: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F4124: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F4128: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x801F412C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F4130: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801F4134: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x801F4138: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F413C: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x801F4140: nop

    // 0x801F4144: bc1fl       L_801F4160
    if (!c1cs) {
        // 0x801F4148: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801F4160;
    }
    goto skip_1;
    // 0x801F4148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801F414C: jal         0x801F3B5C
    // 0x801F4150: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801F3B5C)(rdram, ctx);
        goto after_1;
    // 0x801F4150: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801F4154: b           L_801F4160
    // 0x801F4158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F4160;
    // 0x801F4158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F415C:
    // 0x801F415C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F4160:
    // 0x801F4160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F4164: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F4168: jr          $ra
    // 0x801F416C: nop

    return;
    // 0x801F416C: nop

;}
RECOMP_FUNC void M9_FUN_801f4170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4170: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F4174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F4178: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801F417C: lw          $t8, -0x4330($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4330);
    // 0x801F4180: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801F4184: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801F4188: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F418C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F4190: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801F4194: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x801F4198: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801F419C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801F41A0: jal         0x8012A564
    // 0x801F41A4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8012A564)(rdram, ctx);
        goto after_0;
    // 0x801F41A4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x801F41A8: bne         $v0, $zero, L_801F41F4
    if (ctx->r2 != 0) {
        // 0x801F41AC: lwc1        $f0, 0x1C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_801F41F4;
    }
    // 0x801F41AC: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801F41B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F41B4: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x801F41B8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x801F41BC: nop

    // 0x801F41C0: bc1fl       L_801F41F8
    if (!c1cs) {
        // 0x801F41C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801F41F8;
    }
    goto skip_0;
    // 0x801F41C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801F41C8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F41CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F41D0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801F41D4: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x801F41D8: nop

    // 0x801F41DC: bc1fl       L_801F41F8
    if (!c1cs) {
        // 0x801F41E0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801F41F8;
    }
    goto skip_1;
    // 0x801F41E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801F41E4: jal         0x801F3B5C
    // 0x801F41E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801F3B5C)(rdram, ctx);
        goto after_1;
    // 0x801F41E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801F41EC: b           L_801F41F8
    // 0x801F41F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F41F8;
    // 0x801F41F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F41F4:
    // 0x801F41F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F41F8:
    // 0x801F41F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F41FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F4200: jr          $ra
    // 0x801F4204: nop

    return;
    // 0x801F4204: nop

;}
RECOMP_FUNC void M9_FUN_801f4208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4208: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801F420C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F4210: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801F4214: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x801F4218: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F421C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801F4220: nop

    // 0x801F4224: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F4228: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801F422C: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x801F4230: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801F4234: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x801F4238: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x801F423C: lh          $t9, 0x8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8);
    // 0x801F4240: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x801F4244: nop

    // 0x801F4248: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801F424C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801F4250: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801F4254: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801F4258: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x801F425C: lw          $t0, 0x38($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X38);
    // 0x801F4260: lh          $t1, 0xA($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XA);
    // 0x801F4264: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x801F4268: nop

    // 0x801F426C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801F4270: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801F4274: div.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x801F4278: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801F427C: jr          $ra
    // 0x801F4280: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    return;
    // 0x801F4280: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f4284(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f4284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4284: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x801F4288: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F428C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801F4290: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x801F4294: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F4298: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801F429C: nop

    // 0x801F42A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F42A4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801F42A8: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x801F42AC: trunc.w.d   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x801F42B0: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x801F42B4: nop

    // 0x801F42B8: sh          $t8, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r24;
    // 0x801F42BC: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
    // 0x801F42C0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x801F42C4: nop

    // 0x801F42C8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801F42CC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801F42D0: div.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x801F42D4: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x801F42D8: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x801F42DC: jr          $ra
    // 0x801F42E0: sh          $t1, 0x96($a0)
    MEM_H(0X96, ctx->r4) = ctx->r9;
    return;
    // 0x801F42E0: sh          $t1, 0x96($a0)
    MEM_H(0X96, ctx->r4) = ctx->r9;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f42e4(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f42e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F42E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F42E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F42EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801F42F0: lh          $t6, 0x98($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X98);
    // 0x801F42F4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801F42F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801F42FC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801F4300: sh          $t7, 0x98($a0)
    MEM_H(0X98, ctx->r4) = ctx->r15;
    // 0x801F4304: lh          $t8, 0x98($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X98);
    // 0x801F4308: lhu         $a0, 0x2E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2E);
    // 0x801F430C: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x801F4310: mfhi        $t9
    ctx->r25 = hi;
    // 0x801F4314: bnel        $t9, $zero, L_801F4420
    if (ctx->r25 != 0) {
        // 0x801F4318: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F4420;
    }
    goto skip_0;
    // 0x801F4318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801F431C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801F4320: jal         0x8012C6B4
    // 0x801F4324: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x801F4324: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x801F4328: lhu         $t0, 0x2E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2E);
    // 0x801F432C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F4330: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x801F4334: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x801F4338: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801F433C: bgez        $t0, L_801F4358
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801F4340: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_801F4358;
    }
    // 0x801F4340: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801F4344: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801F4348: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801F434C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F4350: nop

    // 0x801F4354: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_801F4358:
    // 0x801F4358: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F435C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F4360: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x801F4364: mul.d       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x801F4368: sub.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f18.d - ctx->f0.d;
    // 0x801F436C: sdc1        $f0, 0x18($sp)
    CHECK_FR(ctx, 0);
    SD(ctx->f0.u64, 0X18, ctx->r29);
    // 0x801F4370: trunc.w.d   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x801F4374: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x801F4378: jal         0x8012C6B4
    // 0x801F437C: sh          $t2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801F437C: sh          $t2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r10;
    after_1:
    // 0x801F4380: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801F4384: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F4388: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801F438C: lw          $v1, 0x38($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X38);
    // 0x801F4390: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801F4394: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x801F4398: lh          $t3, 0x6($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X6);
    // 0x801F439C: ldc1        $f0, 0x18($sp)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r29, 0X18);
    // 0x801F43A0: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x801F43A4: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x801F43A8: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x801F43AC: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x801F43B0: div.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f2.d);
    // 0x801F43B4: add.d       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f16.d + ctx->f4.d;
    // 0x801F43B8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801F43BC: trunc.w.d   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x801F43C0: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x801F43C4: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x801F43C8: nop

    // 0x801F43CC: sh          $t6, 0x94($a2)
    MEM_H(0X94, ctx->r6) = ctx->r14;
    // 0x801F43D0: lh          $t7, 0xA($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA);
    // 0x801F43D4: sub.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f8.d - ctx->f0.d;
    // 0x801F43D8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801F43DC: nop

    // 0x801F43E0: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x801F43E4: trunc.w.d   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x801F43E8: div.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = DIV_D(ctx->f18.d, ctx->f2.d);
    // 0x801F43EC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x801F43F0: nop

    // 0x801F43F4: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x801F43F8: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x801F43FC: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x801F4400: nop

    // 0x801F4404: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x801F4408: add.d       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f16.d + ctx->f4.d;
    // 0x801F440C: trunc.w.d   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x801F4410: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x801F4414: nop

    // 0x801F4418: sh          $t3, 0x96($a2)
    MEM_H(0X96, ctx->r6) = ctx->r11;
    // 0x801F441C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801F4420:
    // 0x801F4420: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F4424: jr          $ra
    // 0x801F4428: nop

    return;
    // 0x801F4428: nop

;}
RECOMP_FUNC void M9_FUN_801f442c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F442C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F4430: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x801F4434: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F4438: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F443C: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x801F4440: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F4444: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x801F4448: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801F444C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801F4450: lw          $t8, -0x4330($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4330);
    // 0x801F4454: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F4458: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801F445C: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801F4460: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x801F4464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F4468: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801F446C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F4470: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801F4474: div.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f18.d);
    // 0x801F4478: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801F447C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801F4480: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x801F4484: div.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f18.d);
    // 0x801F4488: sub.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x801F448C: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x801F4490: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801F4494: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x801F4498: sub.s       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x801F449C: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801F44A0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801F44A4: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x801F44A8: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x801F44AC: nop

    // 0x801F44B0: bc1f        L_801F450C
    if (!c1cs) {
            // 0x801F44B4: nop

    LOOKUP_FUNC(0x801F450C)(rdram, ctx);
    return;
    }
    // 0x801F44B4: nop

    // 0x801F44B8: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x801F44BC: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F44C0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F44C4: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F44C8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F44CC: lwc1        $f2, 0x8($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801F44D0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801F44D4: nop

    // 0x801F44D8: bc1fl       L_801F44F0
    if (!c1cs) {
        // 0x801F44DC: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_801F44F0;
    }
    goto skip_0;
    // 0x801F44DC: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x801F44E0: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x801F44E4: b           L_801F44F0
    // 0x801F44E8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_801F44F0;
    // 0x801F44E8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x801F44EC: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_801F44F0:
    // 0x801F44F0: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x801F44F4: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x801F44F8: nop

    // 0x801F44FC: bc1f        L_801F450C
    if (!c1cs) {
            // 0x801F4500: nop

    LOOKUP_FUNC(0x801F450C)(rdram, ctx);
    return;
    }
    // 0x801F4500: nop

    // 0x801F4504: jr          $ra
    // 0x801F4508: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801F4508: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f450c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f450c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F450C: jr          $ra
    // 0x801F4510: nop

    return;
    // 0x801F4510: nop

;}
RECOMP_FUNC void M9_FUN_801f4514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4514: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F4518: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x801F451C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801F4520: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x801F4524: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x801F4528: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x801F452C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801F4530: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801F4534: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x801F4538: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801F453C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F4540: lw          $t8, -0x4330($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4330);
    // 0x801F4544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F4548: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801F454C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801F4550: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801F4554: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801F4558: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801F455C: div.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f14.d);
    // 0x801F4560: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x801F4564: div.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f14.d);
    // 0x801F4568: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x801F456C: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x801F4570: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801F4574: nop

    // 0x801F4578: bc1f        L_801F458C
    if (!c1cs) {
        // 0x801F457C: cvt.s.d     $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
            goto L_801F458C;
    }
    // 0x801F457C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x801F4580: sub.s       $f14, $f12, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x801F4584: b           L_801F4590
    // 0x801F4588: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
        goto L_801F4590;
    // 0x801F4588: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_801F458C:
    // 0x801F458C: sub.s       $f14, $f12, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f0.fl;
L_801F4590:
    // 0x801F4590: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x801F4594: nop

    // 0x801F4598: bc1f        L_801F45DC
    if (!c1cs) {
            // 0x801F459C: nop

    LOOKUP_FUNC(0x801F45DC)(rdram, ctx);
    return;
    }
    // 0x801F459C: nop

    // 0x801F45A0: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801F45A4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801F45A8: nop

    // 0x801F45AC: bc1fl       L_801F45C4
    if (!c1cs) {
        // 0x801F45B0: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_801F45C4;
    }
    goto skip_0;
    // 0x801F45B0: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x801F45B4: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x801F45B8: b           L_801F45C4
    // 0x801F45BC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_801F45C4;
    // 0x801F45BC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x801F45C0: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_801F45C4:
    // 0x801F45C4: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x801F45C8: nop

    // 0x801F45CC: bc1f        L_801F45DC
    if (!c1cs) {
            // 0x801F45D0: nop

    LOOKUP_FUNC(0x801F45DC)(rdram, ctx);
    return;
    }
    // 0x801F45D0: nop

    // 0x801F45D4: jr          $ra
    // 0x801F45D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801F45D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f45dc(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f45dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F45DC: jr          $ra
    // 0x801F45E0: nop

    return;
    // 0x801F45E0: nop

;}
RECOMP_FUNC void M9_FUN_801f45e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F45E4: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801F45E8: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x801F45EC: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x801F45F0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F45F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F45F8: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x801F45FC: sub.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x801F4600: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x801F4604: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x801F4608: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F460C: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x801F4610: swc1        $f16, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f16.u32l;
    // 0x801F4614: sub.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x801F4618: jr          $ra
    // 0x801F461C: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    return;
    // 0x801F461C: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f4620(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f4620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4620: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801F4624: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x801F4628: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F462C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x801F4630: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x801F4634: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x801F4638: lwc1        $f8, 0x14($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14);
    // 0x801F463C: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x801F4640: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x801F4644: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x801F4648: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801F464C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801F4650: jr          $ra
    // 0x801F4654: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x801F4654: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f4658(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f4658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F465C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F4660: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801F4664: jal         0x8001EF38
    // 0x801F4668: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x801F4668: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x801F466C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F4670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F4674: jr          $ra
    // 0x801F4678: nop

    return;
    // 0x801F4678: nop

;}
RECOMP_FUNC void M9_FUN_801f467c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F467C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F4680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F4684: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F4688: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F468C: jal         0x8001EAD0
    // 0x801F4690: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x801F4690: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    after_0:
    // 0x801F4694: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801F4698: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F469C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x801F46A0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801F46A4: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x801F46A8: jal         0x8001EB64
    // 0x801F46AC: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x801F46AC: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    after_1:
    // 0x801F46B0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801F46B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F46B8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801F46BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F46C0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801F46C4: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x801F46C8: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x801F46CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F46D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F46D4: jr          $ra
    // 0x801F46D8: nop

    return;
    // 0x801F46D8: nop

;}
RECOMP_FUNC void M9_FUN_801f46dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F46DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F46E0: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x801F46E4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801F46E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F46EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801F46F0: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x801F46F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801F46F8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x801F46FC: jal         0x801F45E4
    // 0x801F4700: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x801F45E4)(rdram, ctx);
        goto after_0;
    // 0x801F4700: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x801F4704: jal         0x801F4658
    // 0x801F4708: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x801F4658)(rdram, ctx);
        goto after_1;
    // 0x801F4708: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x801F470C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801F4710: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x801F4714: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801F4718: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801F471C: lh          $t9, 0x12($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X12);
    // 0x801F4720: andi        $t0, $t9, 0x1FFF
    ctx->r8 = ctx->r25 & 0X1FFF;
    // 0x801F4724: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x801F4728: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x801F472C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x801F4730: subu        $t7, $v0, $t4
    ctx->r15 = SUB32(ctx->r2, ctx->r12);
    // 0x801F4734: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x801F4738: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x801F473C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F4740: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F4744: jr          $ra
    // 0x801F4748: nop

    return;
    // 0x801F4748: nop

;}
RECOMP_FUNC void M9_FUN_801f474c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F474C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801F4750: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x801F4754: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x801F4758: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F475C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801F4760: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x801F4764: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801F4768: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801F476C: addiu       $a2, $sp, 0x26
    ctx->r6 = ADD32(ctx->r29, 0X26);
    // 0x801F4770: jal         0x801F46DC
    // 0x801F4774: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x801F46DC)(rdram, ctx);
        goto after_0;
    // 0x801F4774: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x801F4778: lh          $v0, 0x26($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X26);
    // 0x801F477C: lh          $a0, 0x3E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3E);
    // 0x801F4780: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x801F4784: beql        $at, $zero, L_801F4798
    if (ctx->r1 == 0) {
        // 0x801F4788: slti        $at, $v0, 0x1001
        ctx->r1 = SIGNED(ctx->r2) < 0X1001 ? 1 : 0;
            goto L_801F4798;
    }
    goto skip_0;
    // 0x801F4788: slti        $at, $v0, 0x1001
    ctx->r1 = SIGNED(ctx->r2) < 0X1001 ? 1 : 0;
    skip_0:
    // 0x801F478C: b           L_801F47A8
    // 0x801F4790: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_801F47A8;
    // 0x801F4790: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801F4794: slti        $at, $v0, 0x1001
    ctx->r1 = SIGNED(ctx->r2) < 0X1001 ? 1 : 0;
L_801F4798:
    // 0x801F4798: bne         $at, $zero, L_801F47A8
    if (ctx->r1 != 0) {
        // 0x801F479C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_801F47A8;
    }
    // 0x801F479C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801F47A0: b           L_801F47A8
    // 0x801F47A4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_801F47A8;
    // 0x801F47A4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_801F47A8:
    // 0x801F47A8: jal         0x8012C6B4
    // 0x801F47AC: sb          $v1, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801F47AC: sb          $v1, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r3;
    after_1:
    // 0x801F47B0: lb          $v1, 0x2B($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X2B);
    // 0x801F47B4: lh          $t6, 0x28($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X28);
    // 0x801F47B8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x801F47BC: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801F47C0: mflo        $t7
    ctx->r15 = lo;
    // 0x801F47C4: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x801F47C8: sh          $t0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r8;
    // 0x801F47CC: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x801F47D0: andi        $t1, $t0, 0x1FFF
    ctx->r9 = ctx->r8 & 0X1FFF;
    // 0x801F47D4: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801F47D8: sh          $t1, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r9;
    // 0x801F47DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F47E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801F47E4: jr          $ra
    // 0x801F47E8: nop

    return;
    // 0x801F47E8: nop

;}
RECOMP_FUNC void M9_FUN_801f47ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F47EC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F47F0: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f47f4(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f47f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F47F4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801F47F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F47FC: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801F4800: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x801F4804: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801F4808: jal         0x801F45E4
    // 0x801F480C: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    LOOKUP_FUNC(0x801F45E4)(rdram, ctx);
        goto after_0;
    // 0x801F480C: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    after_0:
    // 0x801F4810: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x801F4814: jal         0x801477C4
    // 0x801F4818: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    LOOKUP_FUNC(0x801477C4)(rdram, ctx);
        goto after_1;
    // 0x801F4818: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    after_1:
    // 0x801F481C: jal         0x801F4658
    // 0x801F4820: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    LOOKUP_FUNC(0x801F4658)(rdram, ctx);
        goto after_2;
    // 0x801F4820: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x801F4824: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801F4828: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x801F482C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F4830: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801F4834: lh          $v1, 0x12($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X12);
    // 0x801F4838: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801F483C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x801F4840: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
    // 0x801F4844: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801F4848: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801F484C: andi        $a0, $a0, 0x1FFF
    ctx->r4 = ctx->r4 & 0X1FFF;
    // 0x801F4850: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801F4854: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801F4858: andi        $a1, $a0, 0x1000
    ctx->r5 = ctx->r4 & 0X1000;
    // 0x801F485C: beq         $a1, $zero, L_801F4870
    if (ctx->r5 == 0) {
        // 0x801F4860: andi        $v0, $a0, 0x1FFF
        ctx->r2 = ctx->r4 & 0X1FFF;
            goto L_801F4870;
    }
    // 0x801F4860: andi        $v0, $a0, 0x1FFF
    ctx->r2 = ctx->r4 & 0X1FFF;
    // 0x801F4864: andi        $v0, $a0, 0x1FFF
    ctx->r2 = ctx->r4 & 0X1FFF;
    // 0x801F4868: b           L_801F4874
    // 0x801F486C: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
        goto L_801F4874;
    // 0x801F486C: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
L_801F4870:
    // 0x801F4870: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801F4874:
    // 0x801F4874: bgez        $v1, L_801F4898
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801F4878: nop
    
            goto L_801F4898;
    }
    // 0x801F4878: nop

    // 0x801F487C: beq         $a1, $zero, L_801F4890
    if (ctx->r5 == 0) {
        // 0x801F4880: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801F4890;
    }
    // 0x801F4880: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801F4884: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
    // 0x801F4888: b           L_801F48AC
    // 0x801F488C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_801F48AC;
    // 0x801F488C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_801F4890:
    // 0x801F4890: b           L_801F48AC
    // 0x801F4894: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_801F48AC;
    // 0x801F4894: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_801F4898:
    // 0x801F4898: beq         $a1, $zero, L_801F48A8
    if (ctx->r5 == 0) {
        // 0x801F489C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801F48A8;
    }
    // 0x801F489C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801F48A0: b           L_801F48A8
    // 0x801F48A4: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
        goto L_801F48A8;
    // 0x801F48A4: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
L_801F48A8:
    // 0x801F48A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_801F48AC:
    // 0x801F48AC: slti        $at, $v0, 0x9C7
    ctx->r1 = SIGNED(ctx->r2) < 0X9C7 ? 1 : 0;
    // 0x801F48B0: beq         $at, $zero, L_801F48C0
    if (ctx->r1 == 0) {
        // 0x801F48B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801F48C0;
    }
    // 0x801F48B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801F48B8: b           L_801F48C0
    // 0x801F48BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F48C0;
    // 0x801F48BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F48C0:
    // 0x801F48C0: jr          $ra
    // 0x801F48C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801F48C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f48c8(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f48c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F48C8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801F48CC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F48D0: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x801F48D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F48D8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801F48DC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801F48E0: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801F48E4: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x801F48E8: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x801F48EC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801F48F0: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x801F48F4: jal         0x801F46DC
    // 0x801F48F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801F46DC)(rdram, ctx);
        goto after_0;
    // 0x801F48F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801F48FC: lh          $a1, 0x44($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X44);
    // 0x801F4900: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x801F4904: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F4908: andi        $a0, $a1, 0x1000
    ctx->r4 = ctx->r5 & 0X1000;
    // 0x801F490C: beq         $a0, $zero, L_801F4920
    if (ctx->r4 == 0) {
        // 0x801F4910: andi        $v0, $a1, 0x1FFF
        ctx->r2 = ctx->r5 & 0X1FFF;
            goto L_801F4920;
    }
    // 0x801F4910: andi        $v0, $a1, 0x1FFF
    ctx->r2 = ctx->r5 & 0X1FFF;
    // 0x801F4914: andi        $v0, $a1, 0x1FFF
    ctx->r2 = ctx->r5 & 0X1FFF;
    // 0x801F4918: b           L_801F4924
    // 0x801F491C: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
        goto L_801F4924;
    // 0x801F491C: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
L_801F4920:
    // 0x801F4920: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801F4924:
    // 0x801F4924: bgez        $v1, L_801F4948
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801F4928: lui         $t7, 0x801C
        ctx->r15 = S32(0X801C << 16);
            goto L_801F4948;
    }
    // 0x801F4928: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801F492C: beq         $a0, $zero, L_801F4940
    if (ctx->r4 == 0) {
        // 0x801F4930: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801F4940;
    }
    // 0x801F4930: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801F4934: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
    // 0x801F4938: b           L_801F495C
    // 0x801F493C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_801F495C;
    // 0x801F493C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_801F4940:
    // 0x801F4940: b           L_801F495C
    // 0x801F4944: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_801F495C;
    // 0x801F4944: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_801F4948:
    // 0x801F4948: beq         $a0, $zero, L_801F4958
    if (ctx->r4 == 0) {
        // 0x801F494C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801F4958;
    }
    // 0x801F494C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801F4950: b           L_801F4958
    // 0x801F4954: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
        goto L_801F4958;
    // 0x801F4954: addiu       $v1, $v0, -0x2000
    ctx->r3 = ADD32(ctx->r2, -0X2000);
L_801F4958:
    // 0x801F4958: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_801F495C:
    // 0x801F495C: slti        $at, $v0, 0x9C7
    ctx->r1 = SIGNED(ctx->r2) < 0X9C7 ? 1 : 0;
    // 0x801F4960: beq         $at, $zero, L_801F49D4
    if (ctx->r1 == 0) {
        // 0x801F4964: lbu         $t2, 0x4F($sp)
        ctx->r10 = MEM_BU(ctx->r29, 0X4F);
            goto L_801F49D4;
    }
    // 0x801F4964: lbu         $t2, 0x4F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4F);
    // 0x801F4968: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x801F496C: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801F4970: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x801F4974: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801F4978: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F497C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F4980: lwc1        $f0, 0x8($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801F4984: lwc1        $f2, 0x8($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801F4988: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801F498C: nop

    // 0x801F4990: bc1fl       L_801F49A8
    if (!c1cs) {
        // 0x801F4994: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_801F49A8;
    }
    goto skip_0;
    // 0x801F4994: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x801F4998: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x801F499C: b           L_801F49A8
    // 0x801F49A0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_801F49A8;
    // 0x801F49A0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x801F49A4: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_801F49A8:
    // 0x801F49A8: bgez        $t2, L_801F49BC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801F49AC: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801F49BC;
    }
    // 0x801F49AC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801F49B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F49B4: nop

    // 0x801F49B8: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801F49BC:
    // 0x801F49BC: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x801F49C0: nop

    // 0x801F49C4: bc1fl       L_801F49D8
    if (!c1cs) {
        // 0x801F49C8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801F49D8;
    }
    goto skip_1;
    // 0x801F49C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801F49CC: b           L_801F49D8
    // 0x801F49D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F49D8;
    // 0x801F49D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801F49D4:
    // 0x801F49D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F49D8:
    // 0x801F49D8: jr          $ra
    // 0x801F49DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801F49DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f49e0(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f49e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F49E0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F49E4: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f49e8(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f49e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F49E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F49EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F49F0: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801F49F4: addiu       $a1, $sp, 0x26
    ctx->r5 = ADD32(ctx->r29, 0X26);
    // 0x801F49F8: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x801F49FC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801F4A00: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x801F4A04: jal         0x801F46DC
    // 0x801F4A08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801F46DC)(rdram, ctx);
        goto after_0;
    // 0x801F4A08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801F4A0C: lh          $v1, 0x24($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X24);
    // 0x801F4A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F4A14: andi        $t7, $v1, 0x1000
    ctx->r15 = ctx->r3 & 0X1000;
    // 0x801F4A18: beq         $t7, $zero, L_801F4A2C
    if (ctx->r15 == 0) {
        // 0x801F4A1C: andi        $v0, $v1, 0x1FFF
        ctx->r2 = ctx->r3 & 0X1FFF;
            goto L_801F4A2C;
    }
    // 0x801F4A1C: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
    // 0x801F4A20: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
    // 0x801F4A24: b           L_801F4A2C
    // 0x801F4A28: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
        goto L_801F4A2C;
    // 0x801F4A28: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
L_801F4A2C:
    // 0x801F4A2C: bgezl       $v0, L_801F4A40
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801F4A30: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801F4A40;
    }
    goto skip_0;
    // 0x801F4A30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801F4A34: b           L_801F4A40
    // 0x801F4A38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801F4A40;
    // 0x801F4A38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801F4A3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801F4A40:
    // 0x801F4A40: jr          $ra
    // 0x801F4A44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801F4A44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f4a48(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f4a48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4A48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F4A4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F4A50: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F4A54: sb          $t6, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r14;
    // 0x801F4A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F4A5C: jal         0x801F48C8
    // 0x801F4A60: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x801F48C8)(rdram, ctx);
        goto after_0;
    // 0x801F4A60: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x801F4A64: beq         $v0, $zero, L_801F4A78
    if (ctx->r2 == 0) {
        // 0x801F4A68: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801F4A78;
    }
    // 0x801F4A68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801F4A6C: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x801F4A70: b           L_801F4A90
    // 0x801F4A74: sb          $t7, 0x92($a0)
    MEM_B(0X92, ctx->r4) = ctx->r15;
        goto L_801F4A90;
    // 0x801F4A74: sb          $t7, 0x92($a0)
    MEM_B(0X92, ctx->r4) = ctx->r15;
L_801F4A78:
    // 0x801F4A78: lbu         $v0, 0x92($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X92);
    // 0x801F4A7C: blez        $v0, L_801F4A8C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801F4A80: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_801F4A8C;
    }
    // 0x801F4A80: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x801F4A84: b           L_801F4A90
    // 0x801F4A88: sb          $t8, 0x92($a0)
    MEM_B(0X92, ctx->r4) = ctx->r24;
        goto L_801F4A90;
    // 0x801F4A88: sb          $t8, 0x92($a0)
    MEM_B(0X92, ctx->r4) = ctx->r24;
L_801F4A8C:
    // 0x801F4A8C: sb          $zero, 0x93($a0)
    MEM_B(0X93, ctx->r4) = 0;
L_801F4A90:
    // 0x801F4A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F4A94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F4A98: jr          $ra
    // 0x801F4A9C: nop

    return;
    // 0x801F4A9C: nop

;}
RECOMP_FUNC void M9_FUN_801f4aa0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4AA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F4AA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F4AA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F4AAC: jal         0x801DBE94
    // 0x801F4AB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801DBE94)(rdram, ctx);
        goto after_0;
    // 0x801F4AB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x801F4AB4: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x801F4AB8: addiu       $v1, $v1, 0x6EE8
    ctx->r3 = ADD32(ctx->r3, 0X6EE8);
    // 0x801F4ABC: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x801F4AC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801F4AC4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801F4AC8: addiu       $t6, $t6, -0x4FE8
    ctx->r14 = ADD32(ctx->r14, -0X4FE8);
    // 0x801F4ACC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x801F4AD0: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x801F4AD4: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x801F4AD8: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x801F4ADC: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x801F4AE0: lw          $t9, 0x38($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X38);
    // 0x801F4AE4: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x801F4AE8: sb          $t1, 0xAE($a0)
    MEM_B(0XAE, ctx->r4) = ctx->r9;
    // 0x801F4AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F4AF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F4AF4: jr          $ra
    // 0x801F4AF8: nop

    return;
    // 0x801F4AF8: nop

;}
RECOMP_FUNC void M9_FUN_801f4afc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4AFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801F4B00: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801F4B04: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801F4B08: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801F4B0C: lbu         $t6, 0xAE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XAE);
    // 0x801F4B10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F4B14: addiu       $t7, $zero, 0x23
    ctx->r15 = ADD32(0, 0X23);
    // 0x801F4B18: bne         $t6, $zero, L_801F4B24
    if (ctx->r14 != 0) {
        // 0x801F4B1C: lui         $t9, 0x801F
        ctx->r25 = S32(0X801F << 16);
            goto L_801F4B24;
    }
    // 0x801F4B1C: lui         $t9, 0x801F
    ctx->r25 = S32(0X801F << 16);
    // 0x801F4B20: sb          $t7, 0xAE($a0)
    MEM_B(0XAE, ctx->r4) = ctx->r15;
L_801F4B24:
    // 0x801F4B24: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x801F4B28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F4B2C: addiu       $t9, $t9, 0x7554
    ctx->r25 = ADD32(ctx->r25, 0X7554);
    // 0x801F4B30: lw          $v0, 0x18($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X18);
    // 0x801F4B34: srl         $v0, $v0, 16
    ctx->r2 = S32(U32(ctx->r2) >> 16);
    // 0x801F4B38: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801F4B3C: beq         $v0, $zero, L_801F4B60
    if (ctx->r2 == 0) {
        // 0x801F4B40: nop
    
            goto L_801F4B60;
    }
    // 0x801F4B40: nop

    // 0x801F4B44: beq         $v0, $at, L_801F4B68
    if (ctx->r2 == ctx->r1) {
        // 0x801F4B48: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F4B68;
    }
    // 0x801F4B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F4B4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801F4B50: beq         $v0, $at, L_801F4BBC
    if (ctx->r2 == ctx->r1) {
        // 0x801F4B54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F4BBC;
    }
    // 0x801F4B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F4B58: b           L_801F4C3C
    // 0x801F4B5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_801F4C3C;
    // 0x801F4B5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801F4B60:
    // 0x801F4B60: b           L_801F4C38
    // 0x801F4B64: sw          $t9, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r25;
        goto L_801F4C38;
    // 0x801F4B64: sw          $t9, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r25;
L_801F4B68:
    // 0x801F4B68: jal         0x801478D4
    // 0x801F4B6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801478D4)(rdram, ctx);
        goto after_0;
    // 0x801F4B6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x801F4B70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F4B74: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801F4B78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F4B7C: jal         0x80147AA8
    // 0x801F4B80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80147AA8)(rdram, ctx);
        goto after_1;
    // 0x801F4B80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x801F4B84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F4B88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F4B8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F4B90: jal         0x80147AF0
    // 0x801F4B94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80147AF0)(rdram, ctx);
        goto after_2;
    // 0x801F4B94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801F4B98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F4B9C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x801F4BA0: addiu       $a2, $zero, -0x64
    ctx->r6 = ADD32(0, -0X64);
    // 0x801F4BA4: jal         0x80147C28
    // 0x801F4BA8: addiu       $a3, $zero, -0x43
    ctx->r7 = ADD32(0, -0X43);
    LOOKUP_FUNC(0x80147C28)(rdram, ctx);
        goto after_3;
    // 0x801F4BA8: addiu       $a3, $zero, -0x43
    ctx->r7 = ADD32(0, -0X43);
    after_3:
    // 0x801F4BAC: lui         $t0, 0x801F
    ctx->r8 = S32(0X801F << 16);
    // 0x801F4BB0: addiu       $t0, $t0, 0x75B0
    ctx->r8 = ADD32(ctx->r8, 0X75B0);
    // 0x801F4BB4: b           L_801F4C38
    // 0x801F4BB8: sw          $t0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r8;
        goto L_801F4C38;
    // 0x801F4BB8: sw          $t0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r8;
L_801F4BBC:
    // 0x801F4BBC: jal         0x801478D4
    // 0x801F4BC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x801478D4)(rdram, ctx);
        goto after_4;
    // 0x801F4BC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x801F4BC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F4BC8: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x801F4BCC: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x801F4BD0: jal         0x80147AA8
    // 0x801F4BD4: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    LOOKUP_FUNC(0x80147AA8)(rdram, ctx);
        goto after_5;
    // 0x801F4BD4: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    after_5:
    // 0x801F4BD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F4BDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F4BE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F4BE4: jal         0x80147AF0
    // 0x801F4BE8: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    LOOKUP_FUNC(0x80147AF0)(rdram, ctx);
        goto after_6;
    // 0x801F4BE8: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_6:
    // 0x801F4BEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F4BF0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801F4BF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F4BF8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801F4BFC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801F4C00: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801F4C04: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x801F4C08: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801F4C0C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801F4C10: jal         0x801F4620
    // 0x801F4C14: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801F4620)(rdram, ctx);
        goto after_7;
    // 0x801F4C14: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x801F4C18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F4C1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801F4C20: addiu       $a2, $zero, -0x64
    ctx->r6 = ADD32(0, -0X64);
    // 0x801F4C24: jal         0x80147C28
    // 0x801F4C28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80147C28)(rdram, ctx);
        goto after_8;
    // 0x801F4C28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x801F4C2C: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x801F4C30: addiu       $t1, $t1, -0x7CD4
    ctx->r9 = ADD32(ctx->r9, -0X7CD4);
    // 0x801F4C34: sw          $t1, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r9;
L_801F4C38:
    // 0x801F4C38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801F4C3C:
    // 0x801F4C3C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801F4C40: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801F4C44: jr          $ra
    // 0x801F4C48: nop

    return;
    // 0x801F4C48: nop

;}
RECOMP_FUNC void M9_FUN_801f4c4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4C4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F4C50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F4C54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F4C58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F4C5C: jal         0x801F3F70
    // 0x801F4C60: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801F3F70)(rdram, ctx);
        goto after_0;
    // 0x801F4C60: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F4C64: sh          $v0, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r2;
    // 0x801F4C68: lh          $t6, 0x92($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X92);
    // 0x801F4C6C: addiu       $t9, $zero, 0x23
    ctx->r25 = ADD32(0, 0X23);
    // 0x801F4C70: slti        $at, $t6, 0xC9
    ctx->r1 = SIGNED(ctx->r14) < 0XC9 ? 1 : 0;
    // 0x801F4C74: bnel        $at, $zero, L_801F4C88
    if (ctx->r1 != 0) {
        // 0x801F4C78: lbu         $t8, 0xAE($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0XAE);
            goto L_801F4C88;
    }
    goto skip_0;
    // 0x801F4C78: lbu         $t8, 0xAE($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XAE);
    skip_0:
    // 0x801F4C7C: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801F4C80: sb          $zero, 0x22($t7)
    MEM_B(0X22, ctx->r15) = 0;
    // 0x801F4C84: lbu         $t8, 0xAE($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XAE);
L_801F4C88:
    // 0x801F4C88: bnel        $t8, $zero, L_801F4C98
    if (ctx->r24 != 0) {
        // 0x801F4C8C: lh          $t3, 0x92($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X92);
            goto L_801F4C98;
    }
    goto skip_1;
    // 0x801F4C8C: lh          $t3, 0x92($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X92);
    skip_1:
    // 0x801F4C90: sb          $t9, 0xAE($s0)
    MEM_B(0XAE, ctx->r16) = ctx->r25;
    // 0x801F4C94: lh          $t3, 0x92($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X92);
L_801F4C98:
    // 0x801F4C98: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x801F4C9C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x801F4CA0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x801F4CA4: sb          $t0, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r8;
    // 0x801F4CA8: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801F4CAC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801F4CB0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F4CB4: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x801F4CB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F4CBC: lui         $v0, 0x8021
    ctx->r2 = S32(0X8021 << 16);
    // 0x801F4CC0: addiu       $v0, $v0, 0x6ED0
    ctx->r2 = ADD32(ctx->r2, 0X6ED0);
    // 0x801F4CC4: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801F4CC8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801F4CCC: lui         $t7, 0x1F
    ctx->r15 = S32(0X1F << 16);
    // 0x801F4CD0: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x801F4CD4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F4CD8: swc1        $f18, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f18.u32l;
    // 0x801F4CDC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801F4CE0: sh          $t4, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r12;
    // 0x801F4CE4: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801F4CE8: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x801F4CEC: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x801F4CF0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801F4CF4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801F4CF8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801F4CFC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801F4D00: jal         0x8013A1B4
    // 0x801F4D04: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_1;
    // 0x801F4D04: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x801F4D08: lui         $t8, 0x8020
    ctx->r24 = S32(0X8020 << 16);
    // 0x801F4D0C: addiu       $t8, $t8, -0x668C
    ctx->r24 = ADD32(ctx->r24, -0X668C);
    // 0x801F4D10: sw          $t8, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r24;
    // 0x801F4D14: jal         0x801F3B5C
    // 0x801F4D18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801F3B5C)(rdram, ctx);
        goto after_2;
    // 0x801F4D18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801F4D1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801F4D20: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F4D24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F4D28: jr          $ra
    // 0x801F4D2C: nop

    return;
    // 0x801F4D2C: nop

;}
RECOMP_FUNC void M9_FUN_801f4d30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F4D30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F4D34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F4D38: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F4D3C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801F4D40: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801F4D44: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801F4D48: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801F4D4C: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x801F4D50: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x801F4D54: addiu       $t1, $zero, 0x12
    ctx->r9 = ADD32(0, 0X12);
    // 0x801F4D58: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    // 0x801F4D5C: sh          $t8, 0x78($a2)
    MEM_H(0X78, ctx->r6) = ctx->r24;
    // 0x801F4D60: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x801F4D64: lbu         $t4, 0xAE($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0XAE);
    // 0x801F4D68: addiu       $t2, $zero, 0xE0
    ctx->r10 = ADD32(0, 0XE0);
    // 0x801F4D6C: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x801F4D70: ori         $t0, $t9, 0xB00
    ctx->r8 = ctx->r25 | 0XB00;
    // 0x801F4D74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F4D78: sw          $t0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r8;
    // 0x801F4D7C: sb          $a3, 0x4C($a0)
    MEM_B(0X4C, ctx->r4) = ctx->r7;
    // 0x801F4D80: sb          $t1, 0x4D($a0)
    MEM_B(0X4D, ctx->r4) = ctx->r9;
    // 0x801F4D84: sb          $a3, 0x4E($a0)
    MEM_B(0X4E, ctx->r4) = ctx->r7;
    // 0x801F4D88: sb          $zero, 0x4F($a0)
    MEM_B(0X4F, ctx->r4) = 0;
    // 0x801F4D8C: sb          $zero, 0x50($a0)
    MEM_B(0X50, ctx->r4) = 0;
    // 0x801F4D90: sw          $t2, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r10;
    // 0x801F4D94: sh          $t3, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r11;
    // 0x801F4D98: sb          $zero, 0x92($a0)
    MEM_B(0X92, ctx->r4) = 0;
    // 0x801F4D9C: bne         $t4, $zero, L_801F4DAC
    if (ctx->r12 != 0) {
        // 0x801F4DA0: sh          $zero, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = 0;
            goto L_801F4DAC;
    }
    // 0x801F4DA0: sh          $zero, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = 0;
    // 0x801F4DA4: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x801F4DA8: sb          $t5, 0xAE($a0)
    MEM_B(0XAE, ctx->r4) = ctx->r13;
L_801F4DAC:
    // 0x801F4DAC: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x801F4DB0: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x801F4DB4: lui         $t9, 0x8021
    ctx->r25 = S32(0X8021 << 16);
    // 0x801F4DB8: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x801F4DBC: addiu       $t9, $t9, 0x6E88
    ctx->r25 = ADD32(ctx->r25, 0X6E88);
    // 0x801F4DC0: addiu       $t8, $t8, -0x5018
    ctx->r24 = ADD32(ctx->r24, -0X5018);
    // 0x801F4DC4: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x801F4DC8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801F4DCC: bne         $v0, $zero, L_801F4DE4
    if (ctx->r2 != 0) {
        // 0x801F4DD0: lui         $t2, 0x8022
        ctx->r10 = S32(0X8022 << 16);
            goto L_801F4DE4;
    }
    // 0x801F4DD0: lui         $t2, 0x8022
    ctx->r10 = S32(0X8022 << 16);
    // 0x801F4DD4: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x801F4DD8: sh          $t6, 0x9A($s0)
    MEM_H(0X9A, ctx->r16) = ctx->r14;
    // 0x801F4DDC: b           L_801F4DE8
    // 0x801F4DE0: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
        goto L_801F4DE8;
    // 0x801F4DE0: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
L_801F4DE4:
    // 0x801F4DE4: sh          $v0, 0x9A($s0)
    MEM_H(0X9A, ctx->r16) = ctx->r2;
L_801F4DE8:
    // 0x801F4DE8: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x801F4DEC: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x801F4DF0: addiu       $t2, $t2, -0x5008
    ctx->r10 = ADD32(ctx->r10, -0X5008);
    // 0x801F4DF4: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x801F4DF8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801F4DFC: bnel        $v0, $zero, L_801F4E10
    if (ctx->r2 != 0) {
        // 0x801F4E00: sb          $v0, 0x9C($s0)
        MEM_B(0X9C, ctx->r16) = ctx->r2;
            goto L_801F4E10;
    }
    goto skip_0;
    // 0x801F4E00: sb          $v0, 0x9C($s0)
    MEM_B(0X9C, ctx->r16) = ctx->r2;
    skip_0:
    // 0x801F4E04: b           L_801F4E10
    // 0x801F4E08: sb          $t7, 0x9C($s0)
    MEM_B(0X9C, ctx->r16) = ctx->r15;
        goto L_801F4E10;
    // 0x801F4E08: sb          $t7, 0x9C($s0)
    MEM_B(0X9C, ctx->r16) = ctx->r15;
    // 0x801F4E0C: sb          $v0, 0x9C($s0)
    MEM_B(0X9C, ctx->r16) = ctx->r2;
L_801F4E10:
    // 0x801F4E10: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801F4E14: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801F4E18: lui         $t3, 0x8021
    ctx->r11 = S32(0X8021 << 16);
    // 0x801F4E1C: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x801F4E20: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801F4E24: addiu       $t3, $t3, 0x6EF4
    ctx->r11 = ADD32(ctx->r11, 0X6EF4);
    // 0x801F4E28: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x801F4E2C: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x801F4E30: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801F4E34: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801F4E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F4E3C: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801F4E40: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801F4E44: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801F4E48: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801F4E4C: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
    // 0x801F4E50: jal         0x801DBE94
    // 0x801F4E54: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DBE94)(rdram, ctx);
        goto after_0;
    // 0x801F4E54: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801F4E58: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F4E5C: sw          $v0, -0x5018($at)
    MEM_W(-0X5018, ctx->r1) = ctx->r2;
    // 0x801F4E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F4E64: jal         0x801DBE94
    // 0x801F4E68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801DBE94)(rdram, ctx);
        goto after_1;
    // 0x801F4E68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801F4E6C: lhu         $v1, 0x2A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2A);
    // 0x801F4E70: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F4E74: addiu       $a0, $a0, -0x5008
    ctx->r4 = ADD32(ctx->r4, -0X5008);
    // 0x801F4E78: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x801F4E7C: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x801F4E80: addiu       $a1, $a1, -0x5018
    ctx->r5 = ADD32(ctx->r5, -0X5018);
    // 0x801F4E84: beq         $v1, $at, L_801F4E9C
    if (ctx->r3 == ctx->r1) {
        // 0x801F4E88: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_801F4E9C;
    }
    // 0x801F4E88: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x801F4E8C: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x801F4E90: beq         $v1, $at, L_801F4E9C
    if (ctx->r3 == ctx->r1) {
        // 0x801F4E94: addiu       $at, $zero, 0x59
        ctx->r1 = ADD32(0, 0X59);
            goto L_801F4E9C;
    }
    // 0x801F4E94: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x801F4E98: bne         $v1, $at, L_801F4EC4
    if (ctx->r3 != ctx->r1) {
        // 0x801F4E9C: lui         $t7, 0x8021
        ctx->r15 = S32(0X8021 << 16);
            goto L_801F4EC4;
    }
L_801F4E9C:
    // 0x801F4E9C: lui         $t7, 0x8021
    ctx->r15 = S32(0X8021 << 16);
    // 0x801F4EA0: addiu       $t7, $t7, 0x6F00
    ctx->r15 = ADD32(ctx->r15, 0X6F00);
    // 0x801F4EA4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801F4EA8: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x801F4EAC: addiu       $t6, $t6, -0x4FE8
    ctx->r14 = ADD32(ctx->r14, -0X4FE8);
    // 0x801F4EB0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801F4EB4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801F4EB8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801F4EBC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801F4EC0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
L_801F4EC4:
    // 0x801F4EC4: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x801F4EC8: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x801F4ECC: srl         $t2, $t1, 16
    ctx->r10 = S32(U32(ctx->r9) >> 16);
    // 0x801F4ED0: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x801F4ED4: sltiu       $at, $t3, 0xC
    ctx->r1 = ctx->r11 < 0XC ? 1 : 0;
    // 0x801F4ED8: beq         $at, $zero, L_801F5058
    if (ctx->r1 == 0) {
        // 0x801F4EDC: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_801F5058;
    }
    // 0x801F4EDC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801F4EE0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F4EE4: addu        $at, $at, $t3
    gpr jr_addend_801F4EEC = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801F4EE8: lw          $t3, -0x739C($at)
    ctx->r11 = ADD32(ctx->r1, -0X739C);
    // 0x801F4EEC: jr          $t3
    // 0x801F4EF0: nop

    switch (jr_addend_801F4EEC >> 2) {
        case 0: goto L_801F4EF4; break;
        case 1: goto L_801F4EF4; break;
        case 2: goto L_801F4F04; break;
        case 3: goto L_801F4F28; break;
        case 4: goto L_801F5058; break;
        case 5: goto L_801F4F4C; break;
        case 6: goto L_801F4F68; break;
        case 7: goto L_801F4F84; break;
        case 8: goto L_801F4FDC; break;
        case 9: goto L_801F4FFC; break;
        case 10: goto L_801F5028; break;
        case 11: goto L_801F5040; break;
        default: switch_error(__func__, 0x801F4EEC, 0x80218C64);
    }
    // 0x801F4EF0: nop

L_801F4EF4:
    // 0x801F4EF4: lui         $t4, 0x801F
    ctx->r12 = S32(0X801F << 16);
    // 0x801F4EF8: addiu       $t4, $t4, 0x60D8
    ctx->r12 = ADD32(ctx->r12, 0X60D8);
    // 0x801F4EFC: b           L_801F5064
    // 0x801F4F00: sw          $t4, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r12;
        goto L_801F5064;
    // 0x801F4F00: sw          $t4, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r12;
L_801F4F04:
    // 0x801F4F04: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F4F08: lwc1        $f4, -0x736C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X736C);
    // 0x801F4F0C: lui         $t6, 0x801F
    ctx->r14 = S32(0X801F << 16);
    // 0x801F4F10: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
    // 0x801F4F14: addiu       $t6, $t6, 0x60D8
    ctx->r14 = ADD32(ctx->r14, 0X60D8);
    // 0x801F4F18: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x801F4F1C: sh          $t5, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r13;
    // 0x801F4F20: b           L_801F5064
    // 0x801F4F24: sw          $t6, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r14;
        goto L_801F5064;
    // 0x801F4F24: sw          $t6, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r14;
L_801F4F28:
    // 0x801F4F28: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F4F2C: lwc1        $f6, -0x7368($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7368);
    // 0x801F4F30: lui         $t8, 0x801F
    ctx->r24 = S32(0X801F << 16);
    // 0x801F4F34: addiu       $t7, $zero, 0x12C
    ctx->r15 = ADD32(0, 0X12C);
    // 0x801F4F38: addiu       $t8, $t8, 0x63E0
    ctx->r24 = ADD32(ctx->r24, 0X63E0);
    // 0x801F4F3C: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x801F4F40: sh          $t7, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r15;
    // 0x801F4F44: b           L_801F5064
    // 0x801F4F48: sw          $t8, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r24;
        goto L_801F5064;
    // 0x801F4F48: sw          $t8, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r24;
L_801F4F4C:
    // 0x801F4F4C: lui         $t0, 0x801F
    ctx->r8 = S32(0X801F << 16);
    // 0x801F4F50: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x801F4F54: addiu       $t0, $t0, 0x6C58
    ctx->r8 = ADD32(ctx->r8, 0X6C58);
    // 0x801F4F58: sb          $zero, 0x93($s0)
    MEM_B(0X93, ctx->r16) = 0;
    // 0x801F4F5C: sh          $t9, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r25;
    // 0x801F4F60: b           L_801F5064
    // 0x801F4F64: sw          $t0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r8;
        goto L_801F5064;
    // 0x801F4F64: sw          $t0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r8;
L_801F4F68:
    // 0x801F4F68: lui         $t2, 0x801F
    ctx->r10 = S32(0X801F << 16);
    // 0x801F4F6C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x801F4F70: addiu       $t2, $t2, 0x6C58
    ctx->r10 = ADD32(ctx->r10, 0X6C58);
    // 0x801F4F74: sh          $t1, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r9;
    // 0x801F4F78: sb          $zero, 0x93($s0)
    MEM_B(0X93, ctx->r16) = 0;
    // 0x801F4F7C: b           L_801F5064
    // 0x801F4F80: sw          $t2, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r10;
        goto L_801F5064;
    // 0x801F4F80: sw          $t2, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r10;
L_801F4F84:
    // 0x801F4F84: lui         $t3, 0x8021
    ctx->r11 = S32(0X8021 << 16);
    // 0x801F4F88: sb          $zero, 0x93($s0)
    MEM_B(0X93, ctx->r16) = 0;
    // 0x801F4F8C: addiu       $t3, $t3, 0x6E7C
    ctx->r11 = ADD32(ctx->r11, 0X6E7C);
    // 0x801F4F90: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801F4F94: lui         $t6, 0x1F
    ctx->r14 = S32(0X1F << 16);
    // 0x801F4F98: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x801F4F9C: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x801F4FA0: lw          $a2, 0x4($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X4);
    // 0x801F4FA4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801F4FA8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F4FAC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801F4FB0: lw          $a3, 0x8($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X8);
    // 0x801F4FB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801F4FB8: jal         0x8013A1B4
    // 0x801F4FBC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_2;
    // 0x801F4FBC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_2:
    // 0x801F4FC0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F4FC4: jal         0x80010550
    // 0x801F4FC8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_3;
    // 0x801F4FC8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x801F4FCC: lui         $t7, 0x801F
    ctx->r15 = S32(0X801F << 16);
    // 0x801F4FD0: addiu       $t7, $t7, 0x6008
    ctx->r15 = ADD32(ctx->r15, 0X6008);
    // 0x801F4FD4: b           L_801F5064
    // 0x801F4FD8: sw          $t7, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r15;
        goto L_801F5064;
    // 0x801F4FD8: sw          $t7, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r15;
L_801F4FDC:
    // 0x801F4FDC: jal         0x801F4284
    // 0x801F4FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F4284)(rdram, ctx);
        goto after_4;
    // 0x801F4FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801F4FE4: lui         $t9, 0x801F
    ctx->r25 = S32(0X801F << 16);
    // 0x801F4FE8: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x801F4FEC: addiu       $t9, $t9, 0x6534
    ctx->r25 = ADD32(ctx->r25, 0X6534);
    // 0x801F4FF0: sh          $t8, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r24;
    // 0x801F4FF4: b           L_801F5064
    // 0x801F4FF8: sw          $t9, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r25;
        goto L_801F5064;
    // 0x801F4FF8: sw          $t9, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r25;
L_801F4FFC:
    // 0x801F4FFC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F5000: lwc1        $f8, -0x7364($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7364);
    // 0x801F5004: addiu       $t0, $zero, 0x12C
    ctx->r8 = ADD32(0, 0X12C);
    // 0x801F5008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F500C: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x801F5010: jal         0x801F4284
    // 0x801F5014: sh          $t0, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r8;
    LOOKUP_FUNC(0x801F4284)(rdram, ctx);
        goto after_5;
    // 0x801F5014: sh          $t0, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r8;
    after_5:
    // 0x801F5018: lui         $t1, 0x801F
    ctx->r9 = S32(0X801F << 16);
    // 0x801F501C: addiu       $t1, $t1, 0x6534
    ctx->r9 = ADD32(ctx->r9, 0X6534);
    // 0x801F5020: b           L_801F5064
    // 0x801F5024: sw          $t1, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r9;
        goto L_801F5064;
    // 0x801F5024: sw          $t1, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r9;
L_801F5028:
    // 0x801F5028: jal         0x801F4284
    // 0x801F502C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F4284)(rdram, ctx);
        goto after_6;
    // 0x801F502C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801F5030: lui         $t2, 0x801F
    ctx->r10 = S32(0X801F << 16);
    // 0x801F5034: addiu       $t2, $t2, 0x6820
    ctx->r10 = ADD32(ctx->r10, 0X6820);
    // 0x801F5038: b           L_801F5064
    // 0x801F503C: sw          $t2, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r10;
        goto L_801F5064;
    // 0x801F503C: sw          $t2, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r10;
L_801F5040:
    // 0x801F5040: jal         0x801F4284
    // 0x801F5044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F4284)(rdram, ctx);
        goto after_7;
    // 0x801F5044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801F5048: lui         $t3, 0x801F
    ctx->r11 = S32(0X801F << 16);
    // 0x801F504C: addiu       $t3, $t3, 0x6A3C
    ctx->r11 = ADD32(ctx->r11, 0X6A3C);
    // 0x801F5050: b           L_801F5064
    // 0x801F5054: sw          $t3, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r11;
        goto L_801F5064;
    // 0x801F5054: sw          $t3, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r11;
L_801F5058:
    // 0x801F5058: lui         $t4, 0x801F
    ctx->r12 = S32(0X801F << 16);
    // 0x801F505C: addiu       $t4, $t4, 0x60D8
    ctx->r12 = ADD32(ctx->r12, 0X60D8);
    // 0x801F5060: sw          $t4, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r12;
L_801F5064:
    // 0x801F5064: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801F5068: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F506C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801F5070: jr          $ra
    // 0x801F5074: nop

    return;
    // 0x801F5074: nop

;}
RECOMP_FUNC void M9_FUN_801f5078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F5078: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F507C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F5080: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801F5084: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x801F5088: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F508C: lui         $t7, 0x8021
    ctx->r15 = S32(0X8021 << 16);
    // 0x801F5090: addiu       $t7, $t7, 0x7000
    ctx->r15 = ADD32(ctx->r15, 0X7000);
    // 0x801F5094: sh          $t6, 0x78($v0)
    MEM_H(0X78, ctx->r2) = ctx->r14;
    // 0x801F5098: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801F509C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801F50A0: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801F50A4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801F50A8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801F50AC: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x801F50B0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801F50B4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F50B8: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x801F50BC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801F50C0: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801F50C4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801F50C8: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x801F50CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801F50D0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801F50D4: jal         0x8012C4D0
    // 0x801F50D8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x801F50D8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x801F50DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801F50E0: lui         $t2, 0x8020
    ctx->r10 = S32(0X8020 << 16);
    // 0x801F50E4: addiu       $t2, $t2, -0x75BC
    ctx->r10 = ADD32(ctx->r10, -0X75BC);
    // 0x801F50E8: lhu         $t1, 0x72($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X72);
    // 0x801F50EC: sh          $t1, 0x72($v0)
    MEM_H(0X72, ctx->r2) = ctx->r9;
    // 0x801F50F0: sw          $t2, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r10;
    // 0x801F50F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801F50F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F50FC: jr          $ra
    // 0x801F5100: nop

    return;
    // 0x801F5100: nop

;}
