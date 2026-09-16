#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FUN_80008b9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008B9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80008BA0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80008BA4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80008BA8: jal         0x8000671C
    // 0x80008BAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    LOOKUP_FUNC(0x8000671C)(rdram, ctx);
        goto after_0;
    // 0x80008BAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80008BB0: jal         0x8000671C
    // 0x80008BB4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8000671C)(rdram, ctx);
        goto after_1;
    // 0x80008BB4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x80008BB8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80008BBC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80008BC0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80008BC4: addiu       $t1, $t1, -0x2A44
    ctx->r9 = ADD32(ctx->r9, -0X2A44);
    // 0x80008BC8: sw          $a0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r4;
    // 0x80008BCC: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008BD0: lui         $ra, 0x8009
    ctx->r31 = S32(0X8009 << 16);
    // 0x80008BD4: addiu       $ra, $ra, -0x6D50
    ctx->r31 = ADD32(ctx->r31, -0X6D50);
    // 0x80008BD8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80008BDC: sw          $s0, 0x1B0($ra)
    MEM_W(0X1B0, ctx->r31) = ctx->r16;
    // 0x80008BE0: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80008BE4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80008BE8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80008BEC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80008BF0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008BF4: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
    // 0x80008BF8: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x80008BFC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80008C00: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80008C04: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80008C08: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x80008C0C: lui         $t9, 0xD9C0
    ctx->r25 = S32(0XD9C0 << 16);
    // 0x80008C10: ori         $t9, $t9, 0xF9FA
    ctx->r25 = ctx->r25 | 0XF9FA;
    // 0x80008C14: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80008C18: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80008C1C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008C20: lui         $t7, 0xD700
    ctx->r15 = S32(0XD700 << 16);
    // 0x80008C24: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80008C28: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80008C2C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80008C30: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80008C34: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008C38: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80008C3C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80008C40: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80008C44: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80008C48: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x80008C4C: lwc1        $f4, 0x24($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X24);
    // 0x80008C50: lw          $a1, 0x18($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X18);
    // 0x80008C54: lw          $a2, 0x1C($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X1C);
    // 0x80008C58: lw          $a3, 0x20($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X20);
    // 0x80008C5C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80008C60: lwc1        $f6, 0x28($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X28);
    // 0x80008C64: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80008C68: lwc1        $f8, 0x2C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x80008C6C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80008C70: lwc1        $f10, 0x30($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X30);
    // 0x80008C74: jal         0x80031F84
    // 0x80008C78: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80031F84)(rdram, ctx);
        goto after_2;
    // 0x80008C78: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80008C7C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80008C80: addiu       $t1, $t1, -0x2A44
    ctx->r9 = ADD32(ctx->r9, -0X2A44);
    // 0x80008C84: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008C88: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x80008C8C: ori         $t9, $t9, 0x7
    ctx->r25 = ctx->r25 | 0X7;
    // 0x80008C90: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80008C94: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80008C98: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80008C9C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80008CA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80008CA4: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80008CA8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80008CAC: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x80008CB0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80008CB4: lh          $t8, 0x40($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X40);
    // 0x80008CB8: lwc1        $f16, 0x34($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X34);
    // 0x80008CBC: lwc1        $f4, 0x38($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X38);
    // 0x80008CC0: lwc1        $f8, 0x3C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x80008CC4: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80008CC8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80008CCC: lh          $t6, 0x42($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X42);
    // 0x80008CD0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80008CD4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80008CD8: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80008CDC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80008CE0: lh          $t8, 0x44($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X44);
    // 0x80008CE4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80008CE8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80008CEC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80008CF0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80008CF4: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80008CF8: jal         0x80014B2C
    // 0x80008CFC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80014B2C)(rdram, ctx);
        goto after_3;
    // 0x80008CFC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_3:
    // 0x80008D00: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80008D04: addiu       $t1, $t1, -0x2A44
    ctx->r9 = ADD32(ctx->r9, -0X2A44);
    // 0x80008D08: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008D0C: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x80008D10: ori         $t7, $t7, 0x5
    ctx->r15 = ctx->r15 | 0X5;
    // 0x80008D14: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80008D18: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80008D1C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80008D20: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80008D24: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80008D28: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80008D2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80008D30: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80008D34: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80008D38: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008D3C: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80008D40: lui         $ra, 0x8009
    ctx->r31 = S32(0X8009 << 16);
    // 0x80008D44: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80008D48: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80008D4C: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x80008D50: addiu       $ra, $ra, -0x6D50
    ctx->r31 = ADD32(ctx->r31, -0X6D50);
    // 0x80008D54: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x80008D58: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80008D5C: nop

    // 0x80008D60: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80008D64: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80008D68: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80008D6C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80008D70: nop

    // 0x80008D74: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80008D78: lh          $t9, 0x2($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X2);
    // 0x80008D7C: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80008D80: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80008D84: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80008D88: nop

    // 0x80008D8C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80008D90: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80008D94: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80008D98: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80008D9C: nop

    // 0x80008DA0: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80008DA4: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80008DA8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80008DAC: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x80008DB0: lh          $t7, 0x4($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X4);
    // 0x80008DB4: lh          $t8, 0x6($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X6);
    // 0x80008DB8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80008DBC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80008DC0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80008DC4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80008DC8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80008DCC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80008DD0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80008DD4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80008DD8: nop

    // 0x80008DDC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80008DE0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80008DE4: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80008DE8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80008DEC: nop

    // 0x80008DF0: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80008DF4: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80008DF8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80008DFC: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x80008E00: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008E04: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80008E08: sh          $t7, 0x1B4($ra)
    MEM_H(0X1B4, ctx->r31) = ctx->r15;
    // 0x80008E0C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80008E10: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80008E14: sh          $t9, 0x1B6($ra)
    MEM_H(0X1B6, ctx->r31) = ctx->r25;
    // 0x80008E18: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x80008E1C: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x80008E20: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80008E24: sh          $t7, 0x1B8($ra)
    MEM_H(0X1B8, ctx->r31) = ctx->r15;
    // 0x80008E28: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80008E2C: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80008E30: lh          $t9, 0x6($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6);
    // 0x80008E34: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80008E38: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80008E3C: sh          $t9, 0x1BA($ra)
    MEM_H(0X1BA, ctx->r31) = ctx->r25;
    // 0x80008E40: addiu       $t8, $t8, 0x33E0
    ctx->r24 = ADD32(ctx->r24, 0X33E0);
    // 0x80008E44: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80008E48: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80008E4C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80008E50: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80008E54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80008E58: jr          $ra
    // 0x80008E5C: nop

    return;
    // 0x80008E5C: nop

;}
RECOMP_FUNC void FUN_80008e60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008E60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008E68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80008E6C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80008E70: sb          $t6, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r14;
    // 0x80008E74: jal         0x80001060
    // 0x80008E78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x80008E78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80008E7C: beq         $v0, $zero, L_80008EB8
    if (ctx->r2 == 0) {
        // 0x80008E80: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80008EB8;
    }
    // 0x80008E80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80008E84: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80008E88: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80008E8C: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80008E90: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x80008E94: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x80008E98: addiu       $t1, $zero, 0x260
    ctx->r9 = ADD32(0, 0X260);
    // 0x80008E9C: addiu       $t3, $zero, 0x1D0
    ctx->r11 = ADD32(0, 0X1D0);
    // 0x80008EA0: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x80008EA4: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80008EA8: sh          $t1, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r9;
    // 0x80008EAC: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80008EB0: b           L_80008EE8
    // 0x80008EB4: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
        goto L_80008EE8;
    // 0x80008EB4: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
L_80008EB8:
    // 0x80008EB8: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80008EBC: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x80008EC0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80008EC4: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x80008EC8: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80008ECC: addiu       $t9, $zero, 0x130
    ctx->r25 = ADD32(0, 0X130);
    // 0x80008ED0: addiu       $t1, $zero, 0xE8
    ctx->r9 = ADD32(0, 0XE8);
    // 0x80008ED4: sh          $t7, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r15;
    // 0x80008ED8: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x80008EDC: sh          $t9, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r25;
    // 0x80008EE0: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80008EE4: sh          $t1, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r9;
L_80008EE8:
    // 0x80008EE8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80008EEC: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x80008EF0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80008EF4: sw          $t4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r12;
    // 0x80008EF8: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80008EFC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80008F00: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80008F04: beq         $at, $zero, L_80008F20
    if (ctx->r1 == 0) {
        // 0x80008F08: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80008F20;
    }
    // 0x80008F08: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80008F0C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80008F10: addu        $at, $at, $t7
    gpr jr_addend_80008F18 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80008F14: lw          $t7, -0x3904($at)
    ctx->r15 = ADD32(ctx->r1, -0X3904);
    // 0x80008F18: jr          $t7
    // 0x80008F1C: nop

    switch (jr_addend_80008F18 >> 2) {
        case 0: goto L_80008F20; break;
        case 1: goto L_80008F20; break;
        case 2: goto L_80008F20; break;
        case 3: goto L_80008F20; break;
        case 4: goto L_80008F20; break;
        default: switch_error(__func__, 0x80008F18, 0x8004C6FC);
    }
    // 0x80008F1C: nop

L_80008F20:
    // 0x80008F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008F28: jr          $ra
    // 0x80008F2C: nop

    return;
    // 0x80008F2C: nop

;}
RECOMP_FUNC void FUN_80008f30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008F30: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80008F34: addiu       $a1, $a1, -0x2A44
    ctx->r5 = ADD32(ctx->r5, -0X2A44);
    // 0x80008F38: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80008F3C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80008F40: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x80008F44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008F48: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80008F4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008F50: sw          $a0, 0x1B0($t1)
    MEM_W(0X1B0, ctx->r9) = ctx->r4;
    // 0x80008F54: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80008F58: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80008F5C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80008F60: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80008F64: jal         0x80001060
    // 0x80008F68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x80008F68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80008F6C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80008F70: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80008F74: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x80008F78: addiu       $a1, $a1, -0x2A44
    ctx->r5 = ADD32(ctx->r5, -0X2A44);
    // 0x80008F7C: beq         $v0, $zero, L_80008FAC
    if (ctx->r2 == 0) {
        // 0x80008F80: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80008FAC;
    }
    // 0x80008F80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80008F84: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80008F88: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
    // 0x80008F8C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80008F90: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80008F94: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80008F98: addiu       $t2, $t2, 0x33C0
    ctx->r10 = ADD32(ctx->r10, 0X33C0);
    // 0x80008F9C: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x80008FA0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80008FA4: b           L_80008FD0
    // 0x80008FA8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
        goto L_80008FD0;
    // 0x80008FA8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
L_80008FAC:
    // 0x80008FAC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80008FB0: lui         $t4, 0xDC08
    ctx->r12 = S32(0XDC08 << 16);
    // 0x80008FB4: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x80008FB8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80008FBC: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80008FC0: addiu       $t5, $t5, 0x33A0
    ctx->r13 = ADD32(ctx->r13, 0X33A0);
    // 0x80008FC4: ori         $t4, $t4, 0x8
    ctx->r12 = ctx->r12 | 0X8;
    // 0x80008FC8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80008FCC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_80008FD0:
    // 0x80008FD0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80008FD4: lui         $t7, 0xD9C0
    ctx->r15 = S32(0XD9C0 << 16);
    // 0x80008FD8: ori         $t7, $t7, 0xF9FA
    ctx->r15 = ctx->r15 | 0XF9FA;
    // 0x80008FDC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80008FE0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80008FE4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80008FE8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80008FEC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80008FF0: lui         $t9, 0xD700
    ctx->r25 = S32(0XD700 << 16);
    // 0x80008FF4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80008FF8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80008FFC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80009000: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80009004: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80009008: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8000900C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80009010: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80009014: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80009018: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x8000901C: lw          $v1, 0x2C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X2C);
    // 0x80009020: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x80009024: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x80009028: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8000902C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80009030: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80009034: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80009038: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8000903C: nop

    // 0x80009040: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80009044: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80009048: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8000904C: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80009050: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80009054: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x80009058: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8000905C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80009060: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x80009064: or          $t5, $t8, $t4
    ctx->r13 = ctx->r24 | ctx->r12;
    // 0x80009068: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8000906C: lw          $v1, 0x2C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X2C);
    // 0x80009070: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
    // 0x80009074: lh          $t8, 0x6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X6);
    // 0x80009078: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8000907C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80009080: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80009084: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80009088: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8000908C: nop

    // 0x80009090: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80009094: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80009098: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000909C: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800090A0: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800090A4: andi        $t2, $t9, 0xFFF
    ctx->r10 = ctx->r25 & 0XFFF;
    // 0x800090A8: sll         $t3, $t2, 12
    ctx->r11 = S32(ctx->r10 << 12);
    // 0x800090AC: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x800090B0: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800090B4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800090B8: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x800090BC: lh          $t2, 0x0($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X0);
    // 0x800090C0: sh          $t2, 0x1B4($t1)
    MEM_H(0X1B4, ctx->r9) = ctx->r10;
    // 0x800090C4: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x800090C8: lh          $t4, 0x2($t8)
    ctx->r12 = MEM_H(ctx->r24, 0X2);
    // 0x800090CC: sh          $t4, 0x1B6($t1)
    MEM_H(0X1B6, ctx->r9) = ctx->r12;
    // 0x800090D0: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x800090D4: lh          $t3, 0x4($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X4);
    // 0x800090D8: sh          $t3, 0x1B8($t1)
    MEM_H(0X1B8, ctx->r9) = ctx->r11;
    // 0x800090DC: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x800090E0: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x800090E4: sh          $t7, 0x1BA($t1)
    MEM_H(0X1BA, ctx->r9) = ctx->r15;
    // 0x800090E8: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x800090EC: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x800090F0: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x800090F4: beq         $at, $zero, L_80009178
    if (ctx->r1 == 0) {
        // 0x800090F8: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80009178;
    }
    // 0x800090F8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800090FC: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80009100: addu        $at, $at, $t2
    gpr jr_addend_80009108 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80009104: lw          $t2, -0x38F0($at)
    ctx->r10 = ADD32(ctx->r1, -0X38F0);
    // 0x80009108: jr          $t2
    // 0x8000910C: nop

    switch (jr_addend_80009108 >> 2) {
        case 0: goto L_80009110; break;
        case 1: goto L_80009134; break;
        case 2: goto L_80009158; break;
        case 3: goto L_80009134; break;
        case 4: goto L_80009110; break;
        default: switch_error(__func__, 0x80009108, 0x8004C710);
    }
    // 0x8000910C: nop

L_80009110:
    // 0x80009110: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80009114: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x80009118: addiu       $t5, $t5, 0x3430
    ctx->r13 = ADD32(ctx->r13, 0X3430);
    // 0x8000911C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80009120: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80009124: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x80009128: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8000912C: b           L_80009178
    // 0x80009130: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_80009178;
    // 0x80009130: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_80009134:
    // 0x80009134: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80009138: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8000913C: addiu       $t7, $t7, 0x3510
    ctx->r15 = ADD32(ctx->r15, 0X3510);
    // 0x80009140: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80009144: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80009148: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x8000914C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80009150: b           L_80009178
    // 0x80009154: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_80009178;
    // 0x80009154: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_80009158:
    // 0x80009158: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8000915C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80009160: addiu       $t8, $t8, 0x34A0
    ctx->r24 = ADD32(ctx->r24, 0X34A0);
    // 0x80009164: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80009168: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8000916C: lui         $t2, 0xDE00
    ctx->r10 = S32(0XDE00 << 16);
    // 0x80009170: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80009174: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_80009178:
    // 0x80009178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000917C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80009180: jr          $ra
    // 0x80009184: nop

    return;
    // 0x80009184: nop

    // 0x80009188: nop

    // 0x8000918C: nop

;}
RECOMP_FUNC void FUN_80009190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009190: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80009194: jr          $ra
    // 0x80009198: sb          $zero, 0x22($a0)
    MEM_B(0X22, ctx->r4) = 0;
    return;
    // 0x80009198: sb          $zero, 0x22($a0)
    MEM_B(0X22, ctx->r4) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000919c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000919c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000919C: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x800091A0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800091A4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800091A8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800091AC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800091B0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800091B4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800091B8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800091BC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800091C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800091C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800091C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800091CC: addiu       $t6, $t6, 0x3570
    ctx->r14 = ADD32(ctx->r14, 0X3570);
    // 0x800091D0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800091D4: addiu       $a3, $sp, 0xFC
    ctx->r7 = ADD32(ctx->r29, 0XFC);
    // 0x800091D8: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800091DC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800091E0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800091E4: addiu       $t9, $t9, 0x3578
    ctx->r25 = ADD32(ctx->r25, 0X3578);
    // 0x800091E8: addiu       $ra, $sp, 0xF0
    ctx->r31 = ADD32(ctx->r29, 0XF0);
    // 0x800091EC: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800091F0: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800091F4: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800091F8: addiu       $t8, $t8, 0x3584
    ctx->r24 = ADD32(ctx->r24, 0X3584);
    // 0x800091FC: sw          $t7, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r15;
    // 0x80009200: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x80009204: addiu       $s0, $sp, 0xE8
    ctx->r16 = ADD32(ctx->r29, 0XE8);
    // 0x80009208: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8000920C: sw          $t6, 0x4($ra)
    MEM_W(0X4, ctx->r31) = ctx->r14;
    // 0x80009210: lhu         $t7, 0x8($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X8);
    // 0x80009214: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80009218: addiu       $s2, $s2, -0x2A44
    ctx->r18 = ADD32(ctx->r18, -0X2A44);
    // 0x8000921C: sh          $t7, 0x8($ra)
    MEM_H(0X8, ctx->r31) = ctx->r15;
    // 0x80009220: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80009224: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80009228: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8000922C: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80009230: lbu         $t7, 0x22($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X22);
    // 0x80009234: beql        $t7, $zero, L_80009F60
    if (ctx->r15 == 0) {
        // 0x80009238: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80009F60;
    }
    goto skip_0;
    // 0x80009238: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8000923C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009240: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80009244: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80009248: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8000924C: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80009250: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80009254: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80009258: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8000925C: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x80009260: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80009264: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80009268: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8000926C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80009270: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80009274: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009278: ori         $t9, $t9, 0x800
    ctx->r25 = ctx->r25 | 0X800;
    // 0x8000927C: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80009280: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80009284: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80009288: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000928C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80009290: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009294: ori         $t7, $t7, 0xF00
    ctx->r15 = ctx->r15 | 0XF00;
    // 0x80009298: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x8000929C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800092A0: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800092A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800092A8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800092AC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800092B0: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x800092B4: ori         $t9, $t9, 0x1001
    ctx->r25 = ctx->r25 | 0X1001;
    // 0x800092B8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800092BC: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800092C0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800092C4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800092C8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800092CC: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800092D0: ori         $t8, $t8, 0xD01
    ctx->r24 = ctx->r24 | 0XD01;
    // 0x800092D4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800092D8: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800092DC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800092E0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800092E4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800092E8: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800092EC: ori         $t6, $t6, 0xC00
    ctx->r14 = ctx->r14 | 0XC00;
    // 0x800092F0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800092F4: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800092F8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800092FC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80009300: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009304: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80009308: ori         $t8, $t8, 0x1201
    ctx->r24 = ctx->r24 | 0X1201;
    // 0x8000930C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80009310: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80009314: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80009318: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000931C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009320: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80009324: ori         $t6, $t6, 0x1402
    ctx->r14 = ctx->r14 | 0X1402;
    // 0x80009328: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000932C: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80009330: addiu       $t7, $zero, 0xC00
    ctx->r15 = ADD32(0, 0XC00);
    // 0x80009334: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80009338: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000933C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009340: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80009344: ori         $t9, $t9, 0x1E01
    ctx->r25 = ctx->r25 | 0X1E01;
    // 0x80009348: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8000934C: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80009350: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80009354: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80009358: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x8000935C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80009360: lw          $t0, 0x14($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X14);
    // 0x80009364: lbu         $v1, 0x3($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X3);
    // 0x80009368: beql        $v1, $zero, L_80009600
    if (ctx->r3 == 0) {
        // 0x8000936C: lhu         $v0, 0x6($t0)
        ctx->r2 = MEM_HU(ctx->r8, 0X6);
            goto L_80009600;
    }
    goto skip_1;
    // 0x8000936C: lhu         $v0, 0x6($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X6);
    skip_1:
    // 0x80009370: beq         $v1, $at, L_80009388
    if (ctx->r3 == ctx->r1) {
        // 0x80009374: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80009388;
    }
    // 0x80009374: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80009378: beql        $v1, $at, L_80009568
    if (ctx->r3 == ctx->r1) {
        // 0x8000937C: lhu         $t8, 0x6($a1)
        ctx->r24 = MEM_HU(ctx->r5, 0X6);
            goto L_80009568;
    }
    goto skip_2;
    // 0x8000937C: lhu         $t8, 0x6($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6);
    skip_2:
    // 0x80009380: b           L_80009600
    // 0x80009384: lhu         $v0, 0x6($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X6);
        goto L_80009600;
    // 0x80009384: lhu         $v0, 0x6($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X6);
L_80009388:
    // 0x80009388: lhu         $t6, 0x6($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X6);
    // 0x8000938C: lhu         $t7, 0x4($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X4);
    // 0x80009390: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80009394: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80009398: sh          $t8, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r24;
    // 0x8000939C: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x800093A0: lhu         $t9, 0x6($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X6);
    // 0x800093A4: lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X4);
    // 0x800093A8: sra         $t6, $t9, 4
    ctx->r14 = S32(SIGNED(ctx->r25) >> 4);
    // 0x800093AC: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800093B0: beq         $at, $zero, L_8000955C
    if (ctx->r1 == 0) {
        // 0x800093B4: nop
    
            goto L_8000955C;
    }
    // 0x800093B4: nop

    // 0x800093B8: lbu         $t7, 0x2($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X2);
L_800093BC:
    // 0x800093BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800093C0: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800093C4: bnel        $at, $zero, L_80009438
    if (ctx->r1 != 0) {
        // 0x800093C8: lw          $a0, 0xC($a1)
        ctx->r4 = MEM_W(ctx->r5, 0XC);
            goto L_80009438;
    }
    goto skip_3;
    // 0x800093C8: lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XC);
    skip_3:
    // 0x800093CC: sb          $zero, 0x3($t0)
    MEM_B(0X3, ctx->r8) = 0;
    // 0x800093D0: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
    // 0x800093D4: lw          $t8, 0x2C($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X2C);
    // 0x800093D8: sb          $zero, 0x4($t8)
    MEM_B(0X4, ctx->r24) = 0;
    // 0x800093DC: lw          $t9, 0x2C($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X2C);
    // 0x800093E0: sh          $zero, 0x6($t9)
    MEM_H(0X6, ctx->r25) = 0;
    // 0x800093E4: lw          $t6, 0x2C($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X2C);
    // 0x800093E8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800093EC: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x800093F0: swl         $t9, 0x0($t7)
    do_swl(rdram, 0X0, ctx->r15, ctx->r25);
    // 0x800093F4: swr         $t9, 0x3($t7)
    do_swr(rdram, 0X3, ctx->r15, ctx->r25);
    // 0x800093F8: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800093FC: swl         $t8, 0x4($t7)
    do_swl(rdram, 0X4, ctx->r15, ctx->r24);
    // 0x80009400: swr         $t8, 0x7($t7)
    do_swr(rdram, 0X7, ctx->r15, ctx->r24);
    // 0x80009404: lw          $t6, 0x2C($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X2C);
    // 0x80009408: lw          $t9, 0x0($ra)
    ctx->r25 = MEM_W(ctx->r31, 0X0);
    // 0x8000940C: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80009410: swl         $t9, 0x0($t7)
    do_swl(rdram, 0X0, ctx->r15, ctx->r25);
    // 0x80009414: swr         $t9, 0x3($t7)
    do_swr(rdram, 0X3, ctx->r15, ctx->r25);
    // 0x80009418: lw          $t8, 0x4($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X4);
    // 0x8000941C: swl         $t8, 0x4($t7)
    do_swl(rdram, 0X4, ctx->r15, ctx->r24);
    // 0x80009420: swr         $t8, 0x7($t7)
    do_swr(rdram, 0X7, ctx->r15, ctx->r24);
    // 0x80009424: lhu         $t9, 0x8($ra)
    ctx->r25 = MEM_HU(ctx->r31, 0X8);
    // 0x80009428: sh          $t9, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r25;
    // 0x8000942C: b           L_8000955C
    // 0x80009430: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
        goto L_8000955C;
    // 0x80009430: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x80009434: lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XC);
L_80009438:
    // 0x80009438: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x8000943C: lbu         $t7, 0x4($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X4);
    // 0x80009440: sll         $t8, $t7, 7
    ctx->r24 = S32(ctx->r15 << 7);
    // 0x80009444: lbu         $t7, 0xB($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XB);
    // 0x80009448: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8000944C: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x80009450: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80009454: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80009458: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8000945C: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80009460: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80009464: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80009468: and         $t7, $t6, $t9
    ctx->r15 = ctx->r14 & ctx->r25;
    // 0x8000946C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80009470: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x80009474: lbu         $t6, 0x4($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X4);
    // 0x80009478: sll         $t9, $t6, 7
    ctx->r25 = S32(ctx->r14 << 7);
    // 0x8000947C: lbu         $t6, 0xB($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XB);
    // 0x80009480: addu        $t7, $a0, $t9
    ctx->r15 = ADD32(ctx->r4, ctx->r25);
    // 0x80009484: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x80009488: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8000948C: andi        $t7, $t9, 0x1
    ctx->r15 = ctx->r25 & 0X1;
    // 0x80009490: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80009494: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x80009498: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8000949C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800094A0: and         $t6, $t8, $t7
    ctx->r14 = ctx->r24 & ctx->r15;
    // 0x800094A4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800094A8: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x800094AC: lbu         $t8, 0x4($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X4);
    // 0x800094B0: sll         $t7, $t8, 7
    ctx->r15 = S32(ctx->r24 << 7);
    // 0x800094B4: lbu         $t8, 0xB($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XB);
    // 0x800094B8: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x800094BC: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x800094C0: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800094C4: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x800094C8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800094CC: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800094D0: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x800094D4: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x800094D8: and         $t8, $t9, $t6
    ctx->r24 = ctx->r25 & ctx->r14;
    // 0x800094DC: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x800094E0: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x800094E4: lbu         $t9, 0x4($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X4);
    // 0x800094E8: sll         $t6, $t9, 7
    ctx->r14 = S32(ctx->r25 << 7);
    // 0x800094EC: lbu         $t9, 0xB($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XB);
    // 0x800094F0: addu        $t8, $a0, $t6
    ctx->r24 = ADD32(ctx->r4, ctx->r14);
    // 0x800094F4: addu        $v0, $t8, $v1
    ctx->r2 = ADD32(ctx->r24, ctx->r3);
    // 0x800094F8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800094FC: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x80009500: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80009504: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x80009508: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8000950C: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x80009510: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80009514: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80009518: bne         $v1, $a2, L_80009438
    if (ctx->r3 != ctx->r6) {
        // 0x8000951C: sw          $t9, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r25;
            goto L_80009438;
    }
    // 0x8000951C: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x80009520: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x80009524: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x80009528: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000952C: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // 0x80009530: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x80009534: lbu         $t8, 0x4($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X4);
    // 0x80009538: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8000953C: sb          $t9, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r25;
    // 0x80009540: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x80009544: lhu         $t6, 0x6($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X6);
    // 0x80009548: lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X4);
    // 0x8000954C: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x80009550: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80009554: bnel        $at, $zero, L_800093BC
    if (ctx->r1 != 0) {
        // 0x80009558: lbu         $t7, 0x2($t0)
        ctx->r15 = MEM_BU(ctx->r8, 0X2);
            goto L_800093BC;
    }
    goto skip_4;
    // 0x80009558: lbu         $t7, 0x2($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X2);
    skip_4:
L_8000955C:
    // 0x8000955C: b           L_800095FC
    // 0x80009560: lw          $t0, 0x14($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X14);
        goto L_800095FC;
    // 0x80009560: lw          $t0, 0x14($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X14);
    // 0x80009564: lhu         $t8, 0x6($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6);
L_80009568:
    // 0x80009568: lhu         $t9, 0x4($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X4);
    // 0x8000956C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80009570: sh          $t6, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r14;
    // 0x80009574: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x80009578: lhu         $t7, 0x6($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X6);
    // 0x8000957C: lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X4);
    // 0x80009580: sra         $t8, $t7, 4
    ctx->r24 = S32(SIGNED(ctx->r15) >> 4);
    // 0x80009584: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80009588: beql        $at, $zero, L_800095FC
    if (ctx->r1 == 0) {
        // 0x8000958C: lw          $t0, 0x14($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X14);
            goto L_800095FC;
    }
    goto skip_5;
    // 0x8000958C: lw          $t0, 0x14($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X14);
    skip_5:
    // 0x80009590: lbu         $t9, 0x2($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X2);
L_80009594:
    // 0x80009594: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80009598: bnel        $at, $zero, L_800095C4
    if (ctx->r1 != 0) {
        // 0x8000959C: lh          $t8, 0x2($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X2);
            goto L_800095C4;
    }
    goto skip_6;
    // 0x8000959C: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    skip_6:
    // 0x800095A0: sb          $zero, 0x3($t0)
    MEM_B(0X3, ctx->r8) = 0;
    // 0x800095A4: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
    // 0x800095A8: lw          $t6, 0x2C($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X2C);
    // 0x800095AC: sb          $zero, 0x4($t6)
    MEM_B(0X4, ctx->r14) = 0;
    // 0x800095B0: lw          $t7, 0x2C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X2C);
    // 0x800095B4: sh          $zero, 0x6($t7)
    MEM_H(0X6, ctx->r15) = 0;
    // 0x800095B8: b           L_800095F8
    // 0x800095BC: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
        goto L_800095F8;
    // 0x800095BC: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x800095C0: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
L_800095C4:
    // 0x800095C4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800095C8: sh          $t9, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r25;
    // 0x800095CC: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x800095D0: lbu         $t6, 0x4($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X4);
    // 0x800095D4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800095D8: sb          $t7, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r15;
    // 0x800095DC: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x800095E0: lhu         $t8, 0x6($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6);
    // 0x800095E4: lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X4);
    // 0x800095E8: sra         $t9, $t8, 4
    ctx->r25 = S32(SIGNED(ctx->r24) >> 4);
    // 0x800095EC: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800095F0: bnel        $at, $zero, L_80009594
    if (ctx->r1 != 0) {
        // 0x800095F4: lbu         $t9, 0x2($t0)
        ctx->r25 = MEM_BU(ctx->r8, 0X2);
            goto L_80009594;
    }
    goto skip_7;
    // 0x800095F4: lbu         $t9, 0x2($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X2);
    skip_7:
L_800095F8:
    // 0x800095F8: lw          $t0, 0x14($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X14);
L_800095FC:
    // 0x800095FC: lhu         $v0, 0x6($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X6);
L_80009600:
    // 0x80009600: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80009604: addiu       $s0, $s0, -0x6D50
    ctx->r16 = ADD32(ctx->r16, -0X6D50);
    // 0x80009608: beq         $v0, $zero, L_80009620
    if (ctx->r2 == 0) {
        // 0x8000960C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80009620;
    }
    // 0x8000960C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80009610: sh          $t6, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r14;
    // 0x80009614: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x80009618: b           L_800096BC
    // 0x8000961C: sw          $t0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r8;
        goto L_800096BC;
    // 0x8000961C: sw          $t0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r8;
L_80009620:
    // 0x80009620: sw          $t0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r8;
    // 0x80009624: lhu         $t7, 0x8($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X8);
    // 0x80009628: beql        $t7, $zero, L_800096C0
    if (ctx->r15 == 0) {
        // 0x8000962C: lh          $t7, 0x9C($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X9C);
            goto L_800096C0;
    }
    goto skip_8;
    // 0x8000962C: lh          $t7, 0x9C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X9C);
    skip_8:
    // 0x80009630: lw          $s1, 0x18($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X18);
    // 0x80009634: sw          $t0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r8;
    // 0x80009638: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8000963C: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x80009640: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80009644: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80009648: beq         $t4, $t8, L_80009698
    if (ctx->r12 == ctx->r24) {
        // 0x8000964C: nop
    
            goto L_80009698;
    }
    // 0x8000964C: nop

    // 0x80009650: sw          $t0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r8;
    // 0x80009654: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80009658: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
L_8000965C:
    // 0x8000965C: lhu         $a0, 0x8($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X8);
    // 0x80009660: beq         $t4, $v0, L_8000966C
    if (ctx->r12 == ctx->r2) {
        // 0x80009664: addu        $v1, $v0, $a0
        ctx->r3 = ADD32(ctx->r2, ctx->r4);
            goto L_8000966C;
    }
    // 0x80009664: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x80009668: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8000966C:
    // 0x8000966C: slti        $at, $v1, 0xFF
    ctx->r1 = SIGNED(ctx->r3) < 0XFF ? 1 : 0;
    // 0x80009670: bnel        $at, $zero, L_80009684
    if (ctx->r1 != 0) {
        // 0x80009674: sb          $v1, 0x2($s1)
        MEM_B(0X2, ctx->r17) = ctx->r3;
            goto L_80009684;
    }
    goto skip_9;
    // 0x80009674: sb          $v1, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r3;
    skip_9:
    // 0x80009678: b           L_80009684
    // 0x8000967C: sb          $a1, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r5;
        goto L_80009684;
    // 0x8000967C: sb          $a1, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r5;
    // 0x80009680: sb          $v1, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r3;
L_80009684:
    // 0x80009684: lbu         $t9, 0x8($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X8);
    // 0x80009688: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000968C: bnel        $t4, $t9, L_8000965C
    if (ctx->r12 != ctx->r25) {
        // 0x80009690: lbu         $v0, 0x2($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X2);
            goto L_8000965C;
    }
    goto skip_10;
    // 0x80009690: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    skip_10:
    // 0x80009694: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
L_80009698:
    // 0x80009698: bne         $t5, $zero, L_800096BC
    if (ctx->r13 != 0) {
        // 0x8000969C: lw          $t0, 0x114($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X114);
            goto L_800096BC;
    }
    // 0x8000969C: lw          $t0, 0x114($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X114);
    // 0x800096A0: sw          $t0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r8;
    // 0x800096A4: lw          $t6, 0x18($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X18);
    // 0x800096A8: beql        $s1, $t6, L_800096C0
    if (ctx->r17 == ctx->r14) {
        // 0x800096AC: lh          $t7, 0x9C($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X9C);
            goto L_800096C0;
    }
    goto skip_11;
    // 0x800096AC: lh          $t7, 0x9C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X9C);
    skip_11:
    // 0x800096B0: sh          $zero, 0x8($t0)
    MEM_H(0X8, ctx->r8) = 0;
    // 0x800096B4: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x800096B8: sw          $t0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r8;
L_800096BC:
    // 0x800096BC: lh          $t7, 0x9C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X9C);
L_800096C0:
    // 0x800096C0: addiu       $s1, $zero, 0x700
    ctx->r17 = ADD32(0, 0X700);
    // 0x800096C4: lw          $ra, 0x10($a1)
    ctx->r31 = MEM_W(ctx->r5, 0X10);
    // 0x800096C8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800096CC: multu       $t8, $s1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800096D0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800096D4: lw          $t1, 0xC($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XC);
    // 0x800096D8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800096DC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800096E0: lw          $t3, 0x114($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X114);
    // 0x800096E4: mflo        $t9
    ctx->r25 = lo;
    // 0x800096E8: addu        $a0, $t9, $ra
    ctx->r4 = ADD32(ctx->r25, ctx->r31);
    // 0x800096EC: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
L_800096F0:
    // 0x800096F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800096F4: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_800096F8:
    // 0x800096F8: lw          $t7, 0x2C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X2C);
    // 0x800096FC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80009700: addu        $v0, $t0, $a2
    ctx->r2 = ADD32(ctx->r8, ctx->r6);
    // 0x80009704: lbu         $t8, 0xB($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XB);
    // 0x80009708: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8000970C: andi        $t7, $t9, 0x1
    ctx->r15 = ctx->r25 & 0X1;
    // 0x80009710: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80009714: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x80009718: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8000971C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80009720: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80009724: lbu         $t9, 0x0($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X0);
    // 0x80009728: addu        $t6, $t9, $s7
    ctx->r14 = ADD32(ctx->r25, ctx->r23);
    // 0x8000972C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80009730: slti        $at, $t7, 0xD
    ctx->r1 = SIGNED(ctx->r15) < 0XD ? 1 : 0;
    // 0x80009734: beql        $at, $zero, L_80009778
    if (ctx->r1 == 0) {
        // 0x80009738: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80009778;
    }
    goto skip_12;
    // 0x80009738: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_12:
    // 0x8000973C: lw          $t6, 0x2C($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X2C);
    // 0x80009740: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80009744: addu        $t8, $t1, $v0
    ctx->r24 = ADD32(ctx->r9, ctx->r2);
    // 0x80009748: lbu         $t7, 0xB($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XB);
    // 0x8000974C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80009750: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
    // 0x80009754: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80009758: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8000975C: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80009760: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80009764: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80009768: and         $t6, $t9, $t8
    ctx->r14 = ctx->r25 & ctx->r24;
    // 0x8000976C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80009770: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80009774: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80009778:
    // 0x80009778: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x8000977C: bne         $at, $zero, L_800096F8
    if (ctx->r1 != 0) {
        // 0x80009780: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800096F8;
    }
    // 0x80009780: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80009784: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80009788: slti        $at, $s7, 0xD
    ctx->r1 = SIGNED(ctx->r23) < 0XD ? 1 : 0;
    // 0x8000978C: addiu       $t0, $t0, 0x20
    ctx->r8 = ADD32(ctx->r8, 0X20);
    // 0x80009790: bne         $at, $zero, L_800096F0
    if (ctx->r1 != 0) {
        // 0x80009794: addiu       $t2, $t2, 0x80
        ctx->r10 = ADD32(ctx->r10, 0X80);
            goto L_800096F0;
    }
    // 0x80009794: addiu       $t2, $t2, 0x80
    ctx->r10 = ADD32(ctx->r10, 0X80);
    // 0x80009798: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000979C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800097A0: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_800097A4:
    // 0x800097A4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800097A8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800097AC: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800097B0: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800097B4: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800097B8: bne         $a2, $v0, L_800097A4
    if (ctx->r6 != ctx->r2) {
        // 0x800097BC: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800097A4;
    }
    // 0x800097BC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800097C0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800097C4: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x800097C8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800097CC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800097D0: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800097D4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800097D8: lh          $t6, 0x9C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X9C);
    // 0x800097DC: andi        $t9, $t6, 0x1
    ctx->r25 = ctx->r14 & 0X1;
    // 0x800097E0: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800097E4: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x800097E8: mflo        $t8
    ctx->r24 = lo;
    // 0x800097EC: addu        $t7, $t8, $ra
    ctx->r15 = ADD32(ctx->r24, ctx->r31);
    // 0x800097F0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800097F4: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800097F8: lui         $t8, 0x704
    ctx->r24 = S32(0X704 << 16);
    // 0x800097FC: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80009800: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80009804: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80009808: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x8000980C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80009810: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80009814: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x80009818: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8000981C: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x80009820: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80009824: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80009828: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8000982C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80009830: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x80009834: ori         $t7, $t7, 0xF080
    ctx->r15 = ctx->r15 | 0XF080;
    // 0x80009838: addiu       $t9, $t1, 0x8
    ctx->r25 = ADD32(ctx->r9, 0X8);
    // 0x8000983C: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80009840: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x80009844: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80009848: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8000984C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80009850: lui         $t7, 0xF540
    ctx->r15 = S32(0XF540 << 16);
    // 0x80009854: addiu       $t6, $t2, 0x8
    ctx->r14 = ADD32(ctx->r10, 0X8);
    // 0x80009858: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8000985C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80009860: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80009864: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80009868: lui         $t6, 0x4
    ctx->r14 = S32(0X4 << 16);
    // 0x8000986C: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80009870: addiu       $t8, $t3, 0x8
    ctx->r24 = ADD32(ctx->r11, 0X8);
    // 0x80009874: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80009878: ori         $t7, $t7, 0x2000
    ctx->r15 = ctx->r15 | 0X2000;
    // 0x8000987C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80009880: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80009884: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009888: lui         $t7, 0x3F
    ctx->r15 = S32(0X3F << 16);
    // 0x8000988C: ori         $t7, $t7, 0xC03C
    ctx->r15 = ctx->r15 | 0XC03C;
    // 0x80009890: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80009894: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80009898: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8000989C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800098A0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800098A4: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x800098A8: lui         $ra, 0xE400
    ctx->r31 = S32(0XE400 << 16);
    // 0x800098AC: lhu         $v1, 0x8($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X8);
    // 0x800098B0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800098B4: lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14);
L_800098B8:
    // 0x800098B8: lw          $s1, 0x18($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X18);
    // 0x800098BC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800098C0: sw          $t6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r14;
    // 0x800098C4: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x800098C8: lh          $s5, 0x0($a1)
    ctx->r21 = MEM_H(ctx->r5, 0X0);
    // 0x800098CC: lh          $fp, 0x2($a1)
    ctx->r30 = MEM_H(ctx->r5, 0X2);
    // 0x800098D0: beq         $t4, $t9, L_80009F30
    if (ctx->r12 == ctx->r25) {
        // 0x800098D4: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_80009F30;
    }
    // 0x800098D4: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800098D8: lbu         $t8, 0x4($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X4);
L_800098DC:
    // 0x800098DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800098E0: addu        $s3, $s5, $t8
    ctx->r19 = ADD32(ctx->r21, ctx->r24);
    // 0x800098E4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800098E8: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x800098EC: bne         $a2, $zero, L_8000990C
    if (ctx->r6 != 0) {
        // 0x800098F0: sra         $s3, $s3, 16
        ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
            goto L_8000990C;
    }
    // 0x800098F0: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800098F4: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x800098F8: beql        $v0, $zero, L_80009924
    if (ctx->r2 == 0) {
        // 0x800098FC: lbu         $v0, 0x6($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X6);
            goto L_80009924;
    }
    goto skip_13;
    // 0x800098FC: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    skip_13:
    // 0x80009900: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // 0x80009904: b           L_80009920
    // 0x80009908: sb          $zero, 0x5($s1)
    MEM_B(0X5, ctx->r17) = 0;
        goto L_80009920;
    // 0x80009908: sb          $zero, 0x5($s1)
    MEM_B(0X5, ctx->r17) = 0;
L_8000990C:
    // 0x8000990C: lbu         $t7, 0x5($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X5);
    // 0x80009910: beql        $t7, $zero, L_80009924
    if (ctx->r15 == 0) {
        // 0x80009914: lbu         $v0, 0x6($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X6);
            goto L_80009924;
    }
    goto skip_14;
    // 0x80009914: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    skip_14:
    // 0x80009918: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000991C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80009920:
    // 0x80009920: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
L_80009924:
    // 0x80009924: beql        $v0, $zero, L_80009974
    if (ctx->r2 == 0) {
        // 0x80009928: lbu         $v0, 0x7($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X7);
            goto L_80009974;
    }
    goto skip_15;
    // 0x80009928: lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7);
    skip_15:
    // 0x8000992C: lw          $t6, 0x2C($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X2C);
    // 0x80009930: lbu         $t9, 0xA($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0XA);
    // 0x80009934: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x80009938: mflo        $t8
    ctx->r24 = lo;
    // 0x8000993C: andi        $t7, $t8, 0x1
    ctx->r15 = ctx->r24 & 0X1;
    // 0x80009940: bne         $v0, $zero, L_8000994C
    if (ctx->r2 != 0) {
        // 0x80009944: nop
    
            goto L_8000994C;
    }
    // 0x80009944: nop

    // 0x80009948: break       7
    do_break(2147522888);
L_8000994C:
    // 0x8000994C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009950: bne         $v0, $at, L_80009964
    if (ctx->r2 != ctx->r1) {
        // 0x80009954: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80009964;
    }
    // 0x80009954: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80009958: bne         $t9, $at, L_80009964
    if (ctx->r25 != ctx->r1) {
        // 0x8000995C: nop
    
            goto L_80009964;
    }
    // 0x8000995C: nop

    // 0x80009960: break       6
    do_break(2147522912);
L_80009964:
    // 0x80009964: beql        $t7, $zero, L_80009974
    if (ctx->r15 == 0) {
        // 0x80009968: lbu         $v0, 0x7($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X7);
            goto L_80009974;
    }
    goto skip_16;
    // 0x80009968: lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7);
    skip_16:
    // 0x8000996C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80009970: lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7);
L_80009974:
    // 0x80009974: lw          $t9, 0x114($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X114);
    // 0x80009978: beql        $v0, $zero, L_80009A58
    if (ctx->r2 == 0) {
        // 0x8000997C: lbu         $t9, 0x3($s1)
        ctx->r25 = MEM_BU(ctx->r17, 0X3);
            goto L_80009A58;
    }
    goto skip_17;
    // 0x8000997C: lbu         $t9, 0x3($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X3);
    skip_17:
    // 0x80009980: lhu         $t8, 0x8($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X8);
    // 0x80009984: lw          $t6, 0x2C($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X2C);
    // 0x80009988: beq         $t8, $zero, L_80009994
    if (ctx->r24 == 0) {
        // 0x8000998C: lbu         $v1, 0xA($t6)
        ctx->r3 = MEM_BU(ctx->r14, 0XA);
            goto L_80009994;
    }
    // 0x8000998C: lbu         $v1, 0xA($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XA);
    // 0x80009990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80009994:
    // 0x80009994: div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // 0x80009998: mflo        $t7
    ctx->r15 = lo;
    // 0x8000999C: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x800099A0: bne         $v0, $zero, L_800099AC
    if (ctx->r2 != 0) {
        // 0x800099A4: nop
    
            goto L_800099AC;
    }
    // 0x800099A4: nop

    // 0x800099A8: break       7
    do_break(2147522984);
L_800099AC:
    // 0x800099AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800099B0: bne         $v0, $at, L_800099C4
    if (ctx->r2 != ctx->r1) {
        // 0x800099B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800099C4;
    }
    // 0x800099B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800099B8: bne         $v1, $at, L_800099C4
    if (ctx->r3 != ctx->r1) {
        // 0x800099BC: nop
    
            goto L_800099C4;
    }
    // 0x800099BC: nop

    // 0x800099C0: break       6
    do_break(2147523008);
L_800099C4:
    // 0x800099C4: beq         $t6, $zero, L_80009A10
    if (ctx->r14 == 0) {
        // 0x800099C8: nop
    
            goto L_80009A10;
    }
    // 0x800099C8: nop

    // 0x800099CC: div         $zero, $t4, $v0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r2)));
    // 0x800099D0: lbu         $t9, 0x2($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X2);
    // 0x800099D4: mflo        $t8
    ctx->r24 = lo;
    // 0x800099D8: bne         $v0, $zero, L_800099E4
    if (ctx->r2 != 0) {
        // 0x800099DC: nop
    
            goto L_800099E4;
    }
    // 0x800099DC: nop

    // 0x800099E0: break       7
    do_break(2147523040);
L_800099E4:
    // 0x800099E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800099E8: bne         $v0, $at, L_800099FC
    if (ctx->r2 != ctx->r1) {
        // 0x800099EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800099FC;
    }
    // 0x800099EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800099F0: bne         $t4, $at, L_800099FC
    if (ctx->r12 != ctx->r1) {
        // 0x800099F4: nop
    
            goto L_800099FC;
    }
    // 0x800099F4: nop

    // 0x800099F8: break       6
    do_break(2147523064);
L_800099FC:
    // 0x800099FC: subu        $v1, $t9, $t8
    ctx->r3 = SUB32(ctx->r25, ctx->r24);
    // 0x80009A00: bltzl       $v1, L_80009A58
    if (SIGNED(ctx->r3) < 0) {
        // 0x80009A04: lbu         $t9, 0x3($s1)
        ctx->r25 = MEM_BU(ctx->r17, 0X3);
            goto L_80009A58;
    }
    goto skip_18;
    // 0x80009A04: lbu         $t9, 0x3($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X3);
    skip_18:
    // 0x80009A08: b           L_80009A54
    // 0x80009A0C: sb          $v1, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r3;
        goto L_80009A54;
    // 0x80009A0C: sb          $v1, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r3;
L_80009A10:
    // 0x80009A10: div         $zero, $t4, $v0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r2)));
    // 0x80009A14: lbu         $t7, 0x2($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X2);
    // 0x80009A18: bne         $v0, $zero, L_80009A24
    if (ctx->r2 != 0) {
        // 0x80009A1C: nop
    
            goto L_80009A24;
    }
    // 0x80009A1C: nop

    // 0x80009A20: break       7
    do_break(2147523104);
L_80009A24:
    // 0x80009A24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009A28: bne         $v0, $at, L_80009A3C
    if (ctx->r2 != ctx->r1) {
        // 0x80009A2C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80009A3C;
    }
    // 0x80009A2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80009A30: bne         $t4, $at, L_80009A3C
    if (ctx->r12 != ctx->r1) {
        // 0x80009A34: nop
    
            goto L_80009A3C;
    }
    // 0x80009A34: nop

    // 0x80009A38: break       6
    do_break(2147523128);
L_80009A3C:
    // 0x80009A3C: mflo        $t6
    ctx->r14 = lo;
    // 0x80009A40: addu        $v1, $t7, $t6
    ctx->r3 = ADD32(ctx->r15, ctx->r14);
    // 0x80009A44: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80009A48: beql        $at, $zero, L_80009A58
    if (ctx->r1 == 0) {
        // 0x80009A4C: lbu         $t9, 0x3($s1)
        ctx->r25 = MEM_BU(ctx->r17, 0X3);
            goto L_80009A58;
    }
    goto skip_19;
    // 0x80009A4C: lbu         $t9, 0x3($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X3);
    skip_19:
    // 0x80009A50: sb          $v1, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r3;
L_80009A54:
    // 0x80009A54: lbu         $t9, 0x3($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X3);
L_80009A58:
    // 0x80009A58: beq         $s7, $t9, L_80009A64
    if (ctx->r23 == ctx->r25) {
        // 0x80009A5C: nop
    
            goto L_80009A64;
    }
    // 0x80009A5C: nop

    // 0x80009A60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80009A64:
    // 0x80009A64: bnel        $a0, $zero, L_80009EF4
    if (ctx->r4 != 0) {
        // 0x80009A68: lbu         $v0, 0x4($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X4);
            goto L_80009EF4;
    }
    goto skip_20;
    // 0x80009A68: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    skip_20:
    // 0x80009A6C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009A70: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80009A74: lui         $t6, 0xFF64
    ctx->r14 = S32(0XFF64 << 16);
    // 0x80009A78: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80009A7C: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80009A80: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80009A84: lbu         $t9, 0x2($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X2);
    // 0x80009A88: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x80009A8C: ori         $t7, $t7, 0xB3FF
    ctx->r15 = ctx->r15 | 0XB3FF;
    // 0x80009A90: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80009A94: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009A98: ori         $t6, $t6, 0xFE7F
    ctx->r14 = ctx->r14 | 0XFE7F;
    // 0x80009A9C: addiu       $s0, $fp, 0xD
    ctx->r16 = ADD32(ctx->r30, 0XD);
    // 0x80009AA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80009AA4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80009AA8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80009AAC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80009AB0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009AB4: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x80009AB8: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80009ABC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80009AC0: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80009AC4: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80009AC8: ori         $t7, $t7, 0x4240
    ctx->r15 = ctx->r15 | 0X4240;
    // 0x80009ACC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80009AD0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80009AD4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009AD8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80009ADC: lui         $t9, 0xF900
    ctx->r25 = S32(0XF900 << 16);
    // 0x80009AE0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80009AE4: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80009AE8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80009AEC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80009AF0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009AF4: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x80009AF8: sll         $t9, $s7, 1
    ctx->r25 = S32(ctx->r23 << 1);
    // 0x80009AFC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80009B00: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80009B04: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80009B08: lw          $t8, 0x2C($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X2C);
    // 0x80009B0C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80009B10: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80009B14: lbu         $t7, 0xB($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XB);
    // 0x80009B18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80009B1C: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80009B20: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80009B24: addiu       $t7, $t7, 0x2DF8
    ctx->r15 = ADD32(ctx->r15, 0X2DF8);
    // 0x80009B28: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x80009B2C: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x80009B30: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80009B34: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009B38: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x80009B3C: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x80009B40: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80009B44: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80009B48: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80009B4C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80009B50: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009B54: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x80009B58: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80009B5C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80009B60: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80009B64: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80009B68: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80009B6C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009B70: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80009B74: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x80009B78: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80009B7C: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80009B80: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80009B84: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80009B88: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009B8C: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x80009B90: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x80009B94: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80009B98: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80009B9C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80009BA0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80009BA4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009BA8: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80009BAC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80009BB0: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80009BB4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80009BB8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80009BBC: jal         0x80001060
    // 0x80009BC0: sb          $t5, 0x12E($sp)
    MEM_B(0X12E, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x80009BC0: sb          $t5, 0x12E($sp)
    MEM_B(0X12E, ctx->r29) = ctx->r13;
    after_0:
    // 0x80009BC4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80009BC8: lbu         $t5, 0x12E($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X12E);
    // 0x80009BCC: bne         $v0, $zero, L_80009D24
    if (ctx->r2 != 0) {
        // 0x80009BD0: lui         $ra, 0xE400
        ctx->r31 = S32(0XE400 << 16);
            goto L_80009D24;
    }
    // 0x80009BD0: lui         $ra, 0xE400
    ctx->r31 = S32(0XE400 << 16);
    // 0x80009BD4: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80009BD8: addiu       $v1, $s3, 0x1
    ctx->r3 = ADD32(ctx->r19, 0X1);
    // 0x80009BDC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80009BE0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80009BE4: sll         $t1, $fp, 2
    ctx->r9 = S32(ctx->r30 << 2);
    // 0x80009BE8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80009BEC: sll         $a1, $a1, 18
    ctx->r5 = S32(ctx->r5 << 18);
    // 0x80009BF0: sll         $t0, $t1, 16
    ctx->r8 = S32(ctx->r9 << 16);
    // 0x80009BF4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80009BF8: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x80009BFC: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80009C00: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80009C04: blez        $v1, L_80009C14
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80009C08: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_80009C14;
    }
    // 0x80009C08: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80009C0C: b           L_80009C18
    // 0x80009C10: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_80009C18;
    // 0x80009C10: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80009C14:
    // 0x80009C14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80009C18:
    // 0x80009C18: blez        $a1, L_80009C28
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80009C1C: andi        $t6, $a0, 0xFFF
        ctx->r14 = ctx->r4 & 0XFFF;
            goto L_80009C28;
    }
    // 0x80009C1C: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x80009C20: b           L_80009C2C
    // 0x80009C24: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
        goto L_80009C2C;
    // 0x80009C24: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80009C28:
    // 0x80009C28: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009C2C:
    // 0x80009C2C: andi        $t9, $v1, 0xFFF
    ctx->r25 = ctx->r3 & 0XFFF;
    // 0x80009C30: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80009C34: sll         $a1, $a1, 18
    ctx->r5 = S32(ctx->r5 << 18);
    // 0x80009C38: or          $t7, $t9, $ra
    ctx->r15 = ctx->r25 | ctx->r31;
    // 0x80009C3C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80009C40: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80009C44: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80009C48: blez        $a1, L_80009C58
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80009C4C: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_80009C58;
    }
    // 0x80009C4C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80009C50: b           L_80009C5C
    // 0x80009C54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
        goto L_80009C5C;
    // 0x80009C54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80009C58:
    // 0x80009C58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80009C5C:
    // 0x80009C5C: blez        $t0, L_80009C6C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80009C60: andi        $t7, $a0, 0xFFF
        ctx->r15 = ctx->r4 & 0XFFF;
            goto L_80009C6C;
    }
    // 0x80009C60: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x80009C64: b           L_80009C70
    // 0x80009C68: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_80009C70;
    // 0x80009C68: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80009C6C:
    // 0x80009C6C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009C70:
    // 0x80009C70: andi        $t6, $v1, 0xFFF
    ctx->r14 = ctx->r3 & 0XFFF;
    // 0x80009C74: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80009C78: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80009C7C: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80009C80: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80009C84: lui         $t6, 0xE100
    ctx->r14 = S32(0XE100 << 16);
    // 0x80009C88: sll         $v1, $a1, 10
    ctx->r3 = S32(ctx->r5 << 10);
    // 0x80009C8C: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x80009C90: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80009C94: bgez        $a1, L_80009CB8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80009C98: sw          $t6, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r14;
            goto L_80009CB8;
    }
    // 0x80009C98: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80009C9C: sra         $v1, $v1, 7
    ctx->r3 = S32(SIGNED(ctx->r3) >> 7);
    // 0x80009CA0: bgez        $v1, L_80009CB0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80009CA4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80009CB0;
    }
    // 0x80009CA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80009CA8: b           L_80009CBC
    // 0x80009CAC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_80009CBC;
    // 0x80009CAC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_80009CB0:
    // 0x80009CB0: b           L_80009CBC
    // 0x80009CB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80009CBC;
    // 0x80009CB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80009CB8:
    // 0x80009CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80009CBC:
    // 0x80009CBC: bgez        $t1, L_80009CE4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80009CC0: sll         $t7, $s6, 5
        ctx->r15 = S32(ctx->r22 << 5);
            goto L_80009CE4;
    }
    // 0x80009CC0: sll         $t7, $s6, 5
    ctx->r15 = S32(ctx->r22 << 5);
    // 0x80009CC4: sll         $v0, $t0, 10
    ctx->r2 = S32(ctx->r8 << 10);
    // 0x80009CC8: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80009CCC: bgez        $v0, L_80009CDC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80009CD0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80009CDC;
    }
    // 0x80009CD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009CD4: b           L_80009CE8
    // 0x80009CD8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80009CE8;
    // 0x80009CD8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80009CDC:
    // 0x80009CDC: b           L_80009CE8
    // 0x80009CE0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_80009CE8;
    // 0x80009CE0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80009CE4:
    // 0x80009CE4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009CE8:
    // 0x80009CE8: negu        $t8, $v1
    ctx->r24 = SUB32(0, ctx->r3);
    // 0x80009CEC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80009CF0: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x80009CF4: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80009CF8: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80009CFC: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x80009D00: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009D04: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80009D08: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80009D0C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80009D10: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80009D14: lui         $t9, 0xF100
    ctx->r25 = S32(0XF100 << 16);
    // 0x80009D18: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80009D1C: b           L_80009E70
    // 0x80009D20: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_80009E70;
    // 0x80009D20: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_80009D24:
    // 0x80009D24: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80009D28: addiu       $v1, $s3, 0x1
    ctx->r3 = ADD32(ctx->r19, 0X1);
    // 0x80009D2C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80009D30: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80009D34: sll         $t1, $fp, 3
    ctx->r9 = S32(ctx->r30 << 3);
    // 0x80009D38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80009D3C: sll         $a1, $a1, 19
    ctx->r5 = S32(ctx->r5 << 19);
    // 0x80009D40: sll         $t0, $t1, 16
    ctx->r8 = S32(ctx->r9 << 16);
    // 0x80009D44: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80009D48: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x80009D4C: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80009D50: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80009D54: blez        $v1, L_80009D64
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80009D58: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_80009D64;
    }
    // 0x80009D58: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80009D5C: b           L_80009D68
    // 0x80009D60: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_80009D68;
    // 0x80009D60: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80009D64:
    // 0x80009D64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80009D68:
    // 0x80009D68: blez        $a1, L_80009D78
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80009D6C: andi        $t7, $a0, 0xFFF
        ctx->r15 = ctx->r4 & 0XFFF;
            goto L_80009D78;
    }
    // 0x80009D6C: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x80009D70: b           L_80009D7C
    // 0x80009D74: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
        goto L_80009D7C;
    // 0x80009D74: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80009D78:
    // 0x80009D78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009D7C:
    // 0x80009D7C: andi        $t8, $v1, 0xFFF
    ctx->r24 = ctx->r3 & 0XFFF;
    // 0x80009D80: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80009D84: sll         $a1, $a1, 19
    ctx->r5 = S32(ctx->r5 << 19);
    // 0x80009D88: or          $t9, $t8, $ra
    ctx->r25 = ctx->r24 | ctx->r31;
    // 0x80009D8C: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x80009D90: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80009D94: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80009D98: blez        $a1, L_80009DA8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80009D9C: sw          $t8, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r24;
            goto L_80009DA8;
    }
    // 0x80009D9C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80009DA0: b           L_80009DAC
    // 0x80009DA4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
        goto L_80009DAC;
    // 0x80009DA4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80009DA8:
    // 0x80009DA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80009DAC:
    // 0x80009DAC: blez        $t0, L_80009DBC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80009DB0: andi        $t9, $a0, 0xFFF
        ctx->r25 = ctx->r4 & 0XFFF;
            goto L_80009DBC;
    }
    // 0x80009DB0: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x80009DB4: b           L_80009DC0
    // 0x80009DB8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_80009DC0;
    // 0x80009DB8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80009DBC:
    // 0x80009DBC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009DC0:
    // 0x80009DC0: andi        $t7, $v1, 0xFFF
    ctx->r15 = ctx->r3 & 0XFFF;
    // 0x80009DC4: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80009DC8: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80009DCC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x80009DD0: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80009DD4: lui         $t7, 0xE100
    ctx->r15 = S32(0XE100 << 16);
    // 0x80009DD8: sll         $v1, $a1, 9
    ctx->r3 = S32(ctx->r5 << 9);
    // 0x80009DDC: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x80009DE0: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80009DE4: bgez        $a1, L_80009E08
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80009DE8: sw          $t7, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r15;
            goto L_80009E08;
    }
    // 0x80009DE8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80009DEC: sra         $v1, $v1, 7
    ctx->r3 = S32(SIGNED(ctx->r3) >> 7);
    // 0x80009DF0: bgez        $v1, L_80009E00
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80009DF4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80009E00;
    }
    // 0x80009DF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80009DF8: b           L_80009E0C
    // 0x80009DFC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_80009E0C;
    // 0x80009DFC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_80009E00:
    // 0x80009E00: b           L_80009E0C
    // 0x80009E04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80009E0C;
    // 0x80009E04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80009E08:
    // 0x80009E08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80009E0C:
    // 0x80009E0C: bgez        $t1, L_80009E34
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80009E10: sll         $t9, $s6, 5
        ctx->r25 = S32(ctx->r22 << 5);
            goto L_80009E34;
    }
    // 0x80009E10: sll         $t9, $s6, 5
    ctx->r25 = S32(ctx->r22 << 5);
    // 0x80009E14: sll         $v0, $t0, 9
    ctx->r2 = S32(ctx->r8 << 9);
    // 0x80009E18: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80009E1C: bgez        $v0, L_80009E2C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80009E20: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80009E2C;
    }
    // 0x80009E20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009E24: b           L_80009E38
    // 0x80009E28: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80009E38;
    // 0x80009E28: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80009E2C:
    // 0x80009E2C: b           L_80009E38
    // 0x80009E30: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_80009E38;
    // 0x80009E30: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80009E34:
    // 0x80009E34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009E38:
    // 0x80009E38: negu        $t6, $v1
    ctx->r14 = SUB32(0, ctx->r3);
    // 0x80009E3C: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80009E40: subu        $t6, $t9, $a1
    ctx->r14 = SUB32(ctx->r25, ctx->r5);
    // 0x80009E44: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x80009E48: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x80009E4C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x80009E50: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80009E54: lui         $t9, 0x200
    ctx->r25 = S32(0X200 << 16);
    // 0x80009E58: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80009E5C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80009E60: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80009E64: lui         $t8, 0xF100
    ctx->r24 = S32(0XF100 << 16);
    // 0x80009E68: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80009E6C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80009E70:
    // 0x80009E70: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x80009E74: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80009E78: andi        $v1, $v0, 0xF
    ctx->r3 = ctx->r2 & 0XF;
    // 0x80009E7C: beql        $v1, $zero, L_80009E94
    if (ctx->r3 == 0) {
        // 0x80009E80: andi        $v1, $v0, 0x70
        ctx->r3 = ctx->r2 & 0X70;
            goto L_80009E94;
    }
    goto skip_21;
    // 0x80009E80: andi        $v1, $v0, 0x70
    ctx->r3 = ctx->r2 & 0X70;
    skip_21:
    // 0x80009E84: andi        $t7, $v0, 0xF0
    ctx->r15 = ctx->r2 & 0XF0;
    // 0x80009E88: sb          $t7, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r15;
    // 0x80009E8C: andi        $v0, $t7, 0xFF
    ctx->r2 = ctx->r15 & 0XFF;
    // 0x80009E90: andi        $v1, $v0, 0x70
    ctx->r3 = ctx->r2 & 0X70;
L_80009E94:
    // 0x80009E94: beql        $v1, $zero, L_80009EC0
    if (ctx->r3 == 0) {
        // 0x80009E98: andi        $t6, $v0, 0xF0
        ctx->r14 = ctx->r2 & 0XF0;
            goto L_80009EC0;
    }
    goto skip_22;
    // 0x80009E98: andi        $t6, $v0, 0xF0
    ctx->r14 = ctx->r2 & 0XF0;
    skip_22:
    // 0x80009E9C: sh          $v1, -0x40C0($at)
    MEM_H(-0X40C0, ctx->r1) = ctx->r3;
    // 0x80009EA0: lbu         $t6, 0x1($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X1);
    // 0x80009EA4: andi        $t8, $t6, 0xF
    ctx->r24 = ctx->r14 & 0XF;
    // 0x80009EA8: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80009EAC: ori         $t7, $t9, 0x80
    ctx->r15 = ctx->r25 | 0X80;
    // 0x80009EB0: sb          $t8, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r24;
    // 0x80009EB4: sb          $t7, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r15;
    // 0x80009EB8: andi        $v0, $t7, 0xFF
    ctx->r2 = ctx->r15 & 0XFF;
    // 0x80009EBC: andi        $t6, $v0, 0xF0
    ctx->r14 = ctx->r2 & 0XF0;
L_80009EC0:
    // 0x80009EC0: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80009EC4: bnel        $t6, $at, L_80009EF4
    if (ctx->r14 != ctx->r1) {
        // 0x80009EC8: lbu         $v0, 0x4($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X4);
            goto L_80009EF4;
    }
    goto skip_23;
    // 0x80009EC8: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    skip_23:
    // 0x80009ECC: lw          $t8, 0x2C($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X2C);
    // 0x80009ED0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80009ED4: lhu         $t9, 0x8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8);
    // 0x80009ED8: bnel        $t9, $zero, L_80009EF4
    if (ctx->r25 != 0) {
        // 0x80009EDC: lbu         $v0, 0x4($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X4);
            goto L_80009EF4;
    }
    goto skip_24;
    // 0x80009EDC: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    skip_24:
    // 0x80009EE0: sh          $zero, -0x40C0($at)
    MEM_H(-0X40C0, ctx->r1) = 0;
    // 0x80009EE4: lbu         $t7, 0x1($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1);
    // 0x80009EE8: andi        $t6, $t7, 0xF
    ctx->r14 = ctx->r15 & 0XF;
    // 0x80009EEC: sb          $t6, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r14;
    // 0x80009EF0: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
L_80009EF4:
    // 0x80009EF4: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
    // 0x80009EF8: lbu         $t8, 0x8($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X8);
    // 0x80009EFC: addu        $s6, $s6, $v0
    ctx->r22 = ADD32(ctx->r22, ctx->r2);
    // 0x80009F00: lhu         $v1, 0x8($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X8);
    // 0x80009F04: addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // 0x80009F08: sll         $s6, $s6, 16
    ctx->r22 = S32(ctx->r22 << 16);
    // 0x80009F0C: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x80009F10: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80009F14: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    // 0x80009F18: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80009F1C: beq         $t4, $t8, L_80009F30
    if (ctx->r12 == ctx->r24) {
        // 0x80009F20: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_80009F30;
    }
    // 0x80009F20: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80009F24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80009F28: bnel        $t5, $at, L_800098DC
    if (ctx->r13 != ctx->r1) {
        // 0x80009F2C: lbu         $t8, 0x4($s1)
        ctx->r24 = MEM_BU(ctx->r17, 0X4);
            goto L_800098DC;
    }
    goto skip_25;
    // 0x80009F2C: lbu         $t8, 0x4($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X4);
    skip_25:
L_80009F30:
    // 0x80009F30: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80009F34: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80009F38: bnel        $s7, $at, L_800098B8
    if (ctx->r23 != ctx->r1) {
        // 0x80009F3C: lw          $t6, 0x14($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X14);
            goto L_800098B8;
    }
    goto skip_26;
    // 0x80009F3C: lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14);
    skip_26:
    // 0x80009F40: beq         $a2, $zero, L_80009F50
    if (ctx->r6 == 0) {
        // 0x80009F44: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_80009F50;
    }
    // 0x80009F44: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80009F48: sh          $t9, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r25;
    // 0x80009F4C: lw          $a1, 0x2C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2C);
L_80009F50:
    // 0x80009F50: lbu         $t7, 0xA($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XA);
    // 0x80009F54: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x80009F58: sb          $t6, 0xA($a1)
    MEM_B(0XA, ctx->r5) = ctx->r14;
    // 0x80009F5C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80009F60:
    // 0x80009F60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80009F64: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80009F68: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80009F6C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80009F70: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80009F74: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80009F78: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80009F7C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80009F80: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80009F84: jr          $ra
    // 0x80009F88: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    return;
    // 0x80009F88: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80009f8c(rdram, ctx);
;}
RECOMP_FUNC void FUN_80009f8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009F8C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80009F90: sra         $v1, $v0, 8
    ctx->r3 = S32(SIGNED(ctx->r2) >> 8);
    // 0x80009F94: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80009F98: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80009F9C: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x80009FA0: beq         $v1, $at, L_80009FD4
    if (ctx->r3 == ctx->r1) {
        // 0x80009FA4: sw          $a0, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r4;
            goto L_80009FD4;
    }
    // 0x80009FA4: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x80009FA8: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x80009FAC: beq         $v1, $at, L_80009FEC
    if (ctx->r3 == ctx->r1) {
        // 0x80009FB0: andi        $t0, $v0, 0xFF
        ctx->r8 = ctx->r2 & 0XFF;
            goto L_80009FEC;
    }
    // 0x80009FB0: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x80009FB4: addiu       $at, $zero, 0xA4
    ctx->r1 = ADD32(0, 0XA4);
    // 0x80009FB8: beq         $v1, $at, L_8000A000
    if (ctx->r3 == ctx->r1) {
        // 0x80009FBC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8000A000;
    }
    // 0x80009FBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80009FC0: addiu       $at, $zero, 0xA5
    ctx->r1 = ADD32(0, 0XA5);
    // 0x80009FC4: beq         $v1, $at, L_8000A02C
    if (ctx->r3 == ctx->r1) {
        // 0x80009FC8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8000A02C;
    }
    // 0x80009FC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80009FCC: b           L_8000A054
    // 0x80009FD0: lhu         $v1, 0x4($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X4);
        goto L_8000A054;
    // 0x80009FD0: lhu         $v1, 0x4($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X4);
L_80009FD4:
    // 0x80009FD4: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80009FD8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80009FDC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80009FE0: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80009FE4: b           L_8000A054
    // 0x80009FE8: lhu         $v1, 0x347C($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X347C);
        goto L_8000A054;
    // 0x80009FE8: lhu         $v1, 0x347C($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X347C);
L_80009FEC:
    // 0x80009FEC: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80009FF0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80009FF4: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x80009FF8: b           L_8000A054
    // 0x80009FFC: lhu         $v1, 0x3504($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X3504);
        goto L_8000A054;
    // 0x80009FFC: lhu         $v1, 0x3504($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X3504);
L_8000A000:
    // 0x8000A000: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8000A004: slti        $at, $a0, 0xE1
    ctx->r1 = SIGNED(ctx->r4) < 0XE1 ? 1 : 0;
    // 0x8000A008: beq         $at, $zero, L_8000A01C
    if (ctx->r1 == 0) {
        // 0x8000A00C: sll         $t2, $a0, 1
        ctx->r10 = S32(ctx->r4 << 1);
            goto L_8000A01C;
    }
    // 0x8000A00C: sll         $t2, $a0, 1
    ctx->r10 = S32(ctx->r4 << 1);
    // 0x8000A010: addiu       $v1, $a0, -0xA1
    ctx->r3 = ADD32(ctx->r4, -0XA1);
    // 0x8000A014: b           L_8000A054
    // 0x8000A018: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
        goto L_8000A054;
    // 0x8000A018: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_8000A01C:
    // 0x8000A01C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8000A020: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8000A024: b           L_8000A054
    // 0x8000A028: lhu         $v1, 0x353A($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X353A);
        goto L_8000A054;
    // 0x8000A028: lhu         $v1, 0x353A($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X353A);
L_8000A02C:
    // 0x8000A02C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8000A030: slti        $at, $a0, 0xE1
    ctx->r1 = SIGNED(ctx->r4) < 0XE1 ? 1 : 0;
    // 0x8000A034: beq         $at, $zero, L_8000A048
    if (ctx->r1 == 0) {
        // 0x8000A038: sll         $t3, $a0, 1
        ctx->r11 = S32(ctx->r4 << 1);
            goto L_8000A048;
    }
    // 0x8000A038: sll         $t3, $a0, 1
    ctx->r11 = S32(ctx->r4 << 1);
    // 0x8000A03C: addiu       $v1, $a0, -0x61
    ctx->r3 = ADD32(ctx->r4, -0X61);
    // 0x8000A040: b           L_8000A054
    // 0x8000A044: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
        goto L_8000A054;
    // 0x8000A044: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_8000A048:
    // 0x8000A048: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8000A04C: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x8000A050: lhu         $v1, 0x3562($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X3562);
L_8000A054:
    // 0x8000A054: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000A058: jr          $ra
    // 0x8000A05C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000A05C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000a060(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000a060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A060: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000A064: jr          $ra
    // 0x8000A068: sb          $zero, 0x22($a0)
    MEM_B(0X22, ctx->r4) = 0;
    return;
    // 0x8000A068: sb          $zero, 0x22($a0)
    MEM_B(0X22, ctx->r4) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000a06c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000a06c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A06C: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x8000A070: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000A074: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8000A078: addiu       $s2, $s2, -0x2A44
    ctx->r18 = ADD32(ctx->r18, -0X2A44);
    // 0x8000A07C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A080: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000A084: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000A088: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000A08C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000A090: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000A094: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000A098: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000A09C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000A0A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000A0A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000A0A8: sw          $a0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r4;
    // 0x8000A0AC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8000A0B0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8000A0B4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000A0B8: jal         0x80001060
    // 0x8000A0BC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x8000A0BC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    after_0:
    // 0x8000A0C0: beq         $v0, $zero, L_8000A0EC
    if (ctx->r2 == 0) {
        // 0x8000A0C4: lui         $s0, 0xE300
        ctx->r16 = S32(0XE300 << 16);
            goto L_8000A0EC;
    }
    // 0x8000A0C4: lui         $s0, 0xE300
    ctx->r16 = S32(0XE300 << 16);
    // 0x8000A0C8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A0CC: lui         $t6, 0x9F
    ctx->r14 = S32(0X9F << 16);
    // 0x8000A0D0: ori         $t6, $t6, 0xC77C
    ctx->r14 = ctx->r14 | 0XC77C;
    // 0x8000A0D4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000A0D8: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8000A0DC: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x8000A0E0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000A0E4: b           L_8000A10C
    // 0x8000A0E8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
        goto L_8000A10C;
    // 0x8000A0E8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_8000A0EC:
    // 0x8000A0EC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A0F0: lui         $t9, 0x4F
    ctx->r25 = S32(0X4F << 16);
    // 0x8000A0F4: ori         $t9, $t9, 0xC3BC
    ctx->r25 = ctx->r25 | 0XC3BC;
    // 0x8000A0F8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000A0FC: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8000A100: lui         $t8, 0xED00
    ctx->r24 = S32(0XED00 << 16);
    // 0x8000A104: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000A108: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_8000A10C:
    // 0x8000A10C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A110: lw          $ra, 0x110($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X110);
    // 0x8000A114: ori         $s0, $s0, 0xA01
    ctx->r16 = ctx->r16 | 0XA01;
    // 0x8000A118: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000A11C: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8000A120: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A124: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x8000A128: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A12C: lui         $t8, 0xD9D0
    ctx->r24 = S32(0XD9D0 << 16);
    // 0x8000A130: ori         $t8, $t8, 0xF9FA
    ctx->r24 = ctx->r24 | 0XF9FA;
    // 0x8000A134: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000A138: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8000A13C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A140: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000A144: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A148: lui         $s1, 0xFCFF
    ctx->r17 = S32(0XFCFF << 16);
    // 0x8000A14C: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x8000A150: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000A154: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8000A158: ori         $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 | 0XFFFF;
    // 0x8000A15C: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8000A160: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000A164: sw          $s1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r17;
    // 0x8000A168: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A16C: lui         $s3, 0xE200
    ctx->r19 = S32(0XE200 << 16);
    // 0x8000A170: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8000A174: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000A178: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8000A17C: ori         $s3, $s3, 0x1C
    ctx->r19 = ctx->r19 | 0X1C;
    // 0x8000A180: ori         $t8, $t8, 0x4240
    ctx->r24 = ctx->r24 | 0X4240;
    // 0x8000A184: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000A188: sw          $s3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r19;
    // 0x8000A18C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A190: lui         $s4, 0xE700
    ctx->r20 = S32(0XE700 << 16);
    // 0x8000A194: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000A198: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000A19C: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8000A1A0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A1A4: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x8000A1A8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A1AC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8000A1B0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x8000A1B4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000A1B8: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8000A1BC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8000A1C0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000A1C4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A1C8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8000A1CC: lui         $fp, 0xE400
    ctx->r30 = S32(0XE400 << 16);
    // 0x8000A1D0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000A1D4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8000A1D8: lw          $v0, 0x2C($ra)
    ctx->r2 = MEM_W(ctx->r31, 0X2C);
    // 0x8000A1DC: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    // 0x8000A1E0: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8000A1E4: addiu       $t6, $t9, 0x100
    ctx->r14 = ADD32(ctx->r25, 0X100);
    // 0x8000A1E8: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x8000A1EC: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x8000A1F0: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x8000A1F4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8000A1F8: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x8000A1FC: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8000A200: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8000A204: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8000A208: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000A20C: lw          $v0, 0x2C($ra)
    ctx->r2 = MEM_W(ctx->r31, 0X2C);
    // 0x8000A210: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8000A214: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8000A218: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x8000A21C: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x8000A220: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8000A224: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000A228: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8000A22C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000A230: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A234: lui         $t9, 0x20
    ctx->r25 = S32(0X20 << 16);
    // 0x8000A238: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000A23C: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8000A240: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A244: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x8000A248: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A24C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8000A250: ori         $t8, $t8, 0x800
    ctx->r24 = ctx->r24 | 0X800;
    // 0x8000A254: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000A258: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8000A25C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000A260: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x8000A264: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A268: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x8000A26C: ori         $t9, $t9, 0xF00
    ctx->r25 = ctx->r25 | 0XF00;
    // 0x8000A270: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000A274: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8000A278: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A27C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000A280: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A284: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8000A288: ori         $t8, $t8, 0x1001
    ctx->r24 = ctx->r24 | 0X1001;
    // 0x8000A28C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000A290: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8000A294: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A298: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000A29C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A2A0: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8000A2A4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000A2A8: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8000A2AC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000A2B0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000A2B4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A2B8: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x8000A2BC: ori         $t7, $t7, 0xD01
    ctx->r15 = ctx->r15 | 0XD01;
    // 0x8000A2C0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000A2C4: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8000A2C8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A2CC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000A2D0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A2D4: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x8000A2D8: ori         $t6, $t6, 0xC00
    ctx->r14 = ctx->r14 | 0XC00;
    // 0x8000A2DC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000A2E0: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8000A2E4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A2E8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000A2EC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A2F0: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x8000A2F4: ori         $t7, $t7, 0x1201
    ctx->r15 = ctx->r15 | 0X1201;
    // 0x8000A2F8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000A2FC: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8000A300: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A304: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000A308: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A30C: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x8000A310: ori         $t6, $t6, 0x1402
    ctx->r14 = ctx->r14 | 0X1402;
    // 0x8000A314: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000A318: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8000A31C: addiu       $t9, $zero, 0xC00
    ctx->r25 = ADD32(0, 0XC00);
    // 0x8000A320: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000A324: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000A328: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A32C: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x8000A330: ori         $t8, $t8, 0x1E01
    ctx->r24 = ctx->r24 | 0X1E01;
    // 0x8000A334: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000A338: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8000A33C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8000A340: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000A344: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A348: lui         $t9, 0xFFFC
    ctx->r25 = S32(0XFFFC << 16);
    // 0x8000A34C: ori         $t9, $t9, 0xF279
    ctx->r25 = ctx->r25 | 0XF279;
    // 0x8000A350: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000A354: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8000A358: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000A35C: sw          $s1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r17;
    // 0x8000A360: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A364: lui         $t6, 0xF900
    ctx->r14 = S32(0XF900 << 16);
    // 0x8000A368: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000A36C: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8000A370: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A374: sw          $s3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r19;
    // 0x8000A378: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A37C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000A380: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8000A384: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8000A388: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000A38C: lbu         $t9, 0x22($ra)
    ctx->r25 = MEM_BU(ctx->r31, 0X22);
    // 0x8000A390: beql        $t9, $zero, L_8000A754
    if (ctx->r25 == 0) {
        // 0x8000A394: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8000A754;
    }
    goto skip_0;
    // 0x8000A394: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8000A398: sb          $zero, 0x10F($sp)
    MEM_B(0X10F, ctx->r29) = 0;
L_8000A39C:
    // 0x8000A39C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8000A3A0: addiu       $t6, $t6, 0x358C
    ctx->r14 = ADD32(ctx->r14, 0X358C);
    // 0x8000A3A4: sll         $t8, $s7, 3
    ctx->r24 = S32(ctx->r23 << 3);
    // 0x8000A3A8: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8000A3AC: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8000A3B0: sb          $zero, 0x10E($sp)
    MEM_B(0X10E, ctx->r29) = 0;
    // 0x8000A3B4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8000A3B8:
    // 0x8000A3B8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A3BC: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8000A3C0: andi        $a0, $s5, 0x1
    ctx->r4 = ctx->r21 & 0X1;
    // 0x8000A3C4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000A3C8: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8000A3CC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000A3D0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8000A3D4: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8000A3D8: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x8000A3DC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000A3E0: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8000A3E4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000A3E8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A3EC: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x8000A3F0: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8000A3F4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000A3F8: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8000A3FC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A400: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000A404: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A408: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8000A40C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000A410: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8000A414: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000A418: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000A41C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A420: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8000A424: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8000A428: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000A42C: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8000A430: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A434: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000A438: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A43C: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x8000A440: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8000A444: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000A448: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8000A44C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000A450: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000A454: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A458: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8000A45C: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x8000A460: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000A464: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8000A468: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A46C: bne         $a0, $zero, L_8000A550
    if (ctx->r4 != 0) {
        // 0x8000A470: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8000A550;
    }
    // 0x8000A470: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000A474: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A478: sra         $t7, $s5, 1
    ctx->r15 = S32(SIGNED(ctx->r21) >> 1);
    // 0x8000A47C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000A480: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000A484: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8000A488: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8000A48C: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8000A490: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000A494: lw          $t6, 0x35B4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X35B4);
    // 0x8000A498: lui         $t8, 0x704
    ctx->r24 = S32(0X704 << 16);
    // 0x8000A49C: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8000A4A0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000A4A4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A4A8: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x8000A4AC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000A4B0: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8000A4B4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000A4B8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000A4BC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A4C0: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8000A4C4: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8000A4C8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000A4CC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8000A4D0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A4D4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000A4D8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A4DC: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x8000A4E0: ori         $t6, $t6, 0xF100
    ctx->r14 = ctx->r14 | 0XF100;
    // 0x8000A4E4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000A4E8: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8000A4EC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000A4F0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000A4F4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A4F8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8000A4FC: lui         $t6, 0xF540
    ctx->r14 = S32(0XF540 << 16);
    // 0x8000A500: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000A504: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8000A508: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A50C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000A510: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A514: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x8000A518: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8000A51C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000A520: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8000A524: ori         $t6, $t6, 0x1000
    ctx->r14 = ctx->r14 | 0X1000;
    // 0x8000A528: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000A52C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000A530: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A534: lui         $t6, 0x1F
    ctx->r14 = S32(0X1F << 16);
    // 0x8000A538: ori         $t6, $t6, 0xC07C
    ctx->r14 = ctx->r14 | 0XC07C;
    // 0x8000A53C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000A540: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8000A544: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8000A548: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000A54C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_8000A550:
    // 0x8000A550: lw          $t9, 0x110($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X110);
    // 0x8000A554: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x8000A558: lw          $s3, 0x4($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X4);
    // 0x8000A55C: lh          $s1, 0x0($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X0);
    // 0x8000A560: lh          $s4, 0x2($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X2);
    // 0x8000A564: lhu         $a0, 0x0($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X0);
    // 0x8000A568: beql        $s6, $a0, L_8000A724
    if (ctx->r22 == ctx->r4) {
        // 0x8000A56C: lbu         $v0, 0x10E($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X10E);
            goto L_8000A724;
    }
    goto skip_1;
    // 0x8000A56C: lbu         $v0, 0x10E($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X10E);
    skip_1:
L_8000A570:
    // 0x8000A570: beq         $s7, $zero, L_8000A588
    if (ctx->r23 == 0) {
        // 0x8000A574: nop
    
            goto L_8000A588;
    }
    // 0x8000A574: nop

    // 0x8000A578: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000A57C: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x8000A580: b           L_8000A710
    // 0x8000A584: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
        goto L_8000A710;
    // 0x8000A584: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
L_8000A588:
    // 0x8000A588: jal         0x80009F8C
    // 0x8000A58C: sll         $s0, $s5, 6
    ctx->r16 = S32(ctx->r21 << 6);
    LOOKUP_FUNC(0x80009F8C)(rdram, ctx);
        goto after_1;
    // 0x8000A58C: sll         $s0, $s5, 6
    ctx->r16 = S32(ctx->r21 << 6);
    after_1:
    // 0x8000A590: andi        $t7, $v0, 0xC0
    ctx->r15 = ctx->r2 & 0XC0;
    // 0x8000A594: bne         $s0, $t7, L_8000A704
    if (ctx->r16 != ctx->r15) {
        // 0x8000A598: addiu       $a0, $s1, 0x7
        ctx->r4 = ADD32(ctx->r17, 0X7);
            goto L_8000A704;
    }
    // 0x8000A598: addiu       $a0, $s1, 0x7
    ctx->r4 = ADD32(ctx->r17, 0X7);
    // 0x8000A59C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8000A5A0: addiu       $a2, $s4, 0x7
    ctx->r6 = ADD32(ctx->r20, 0X7);
    // 0x8000A5A4: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8000A5A8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8000A5AC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8000A5B0: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8000A5B4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8000A5B8: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8000A5BC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8000A5C0: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x8000A5C4: sll         $t1, $t2, 16
    ctx->r9 = S32(ctx->r10 << 16);
    // 0x8000A5C8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8000A5CC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8000A5D0: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x8000A5D4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8000A5D8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8000A5DC: blez        $a0, L_8000A5EC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000A5E0: sra         $t1, $t1, 16
        ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
            goto L_8000A5EC;
    }
    // 0x8000A5E0: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8000A5E4: b           L_8000A5F0
    // 0x8000A5E8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
        goto L_8000A5F0;
    // 0x8000A5E8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_8000A5EC:
    // 0x8000A5EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8000A5F0:
    // 0x8000A5F0: blez        $a2, L_8000A600
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8000A5F4: andi        $t7, $a1, 0xFFF
        ctx->r15 = ctx->r5 & 0XFFF;
            goto L_8000A600;
    }
    // 0x8000A5F4: andi        $t7, $a1, 0xFFF
    ctx->r15 = ctx->r5 & 0XFFF;
    // 0x8000A5F8: b           L_8000A604
    // 0x8000A5FC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
        goto L_8000A604;
    // 0x8000A5FC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_8000A600:
    // 0x8000A600: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000A604:
    // 0x8000A604: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x8000A608: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8000A60C: sll         $a2, $a2, 18
    ctx->r6 = S32(ctx->r6 << 18);
    // 0x8000A610: or          $t9, $t6, $fp
    ctx->r25 = ctx->r14 | ctx->r30;
    // 0x8000A614: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8000A618: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8000A61C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8000A620: blez        $a2, L_8000A630
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8000A624: sw          $t6, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r14;
            goto L_8000A630;
    }
    // 0x8000A624: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8000A628: b           L_8000A634
    // 0x8000A62C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
        goto L_8000A634;
    // 0x8000A62C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
L_8000A630:
    // 0x8000A630: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8000A634:
    // 0x8000A634: blez        $t1, L_8000A644
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8000A638: andi        $t9, $a1, 0xFFF
        ctx->r25 = ctx->r5 & 0XFFF;
            goto L_8000A644;
    }
    // 0x8000A638: andi        $t9, $a1, 0xFFF
    ctx->r25 = ctx->r5 & 0XFFF;
    // 0x8000A63C: b           L_8000A648
    // 0x8000A640: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
        goto L_8000A648;
    // 0x8000A640: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
L_8000A644:
    // 0x8000A644: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000A648:
    // 0x8000A648: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8000A64C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8000A650: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8000A654: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x8000A658: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8000A65C: lui         $t7, 0xE100
    ctx->r15 = S32(0XE100 << 16);
    // 0x8000A660: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000A664: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x8000A668: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8000A66C: bgez        $a2, L_8000A694
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8000A670: sw          $t7, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r15;
            goto L_8000A694;
    }
    // 0x8000A670: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8000A674: sll         $v1, $a2, 12
    ctx->r3 = S32(ctx->r6 << 12);
    // 0x8000A678: sra         $v1, $v1, 7
    ctx->r3 = S32(SIGNED(ctx->r3) >> 7);
    // 0x8000A67C: bgez        $v1, L_8000A68C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000A680: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000A68C;
    }
    // 0x8000A680: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000A684: b           L_8000A694
    // 0x8000A688: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_8000A694;
    // 0x8000A688: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_8000A68C:
    // 0x8000A68C: b           L_8000A694
    // 0x8000A690: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
        goto L_8000A694;
    // 0x8000A690: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_8000A694:
    // 0x8000A694: bgez        $t2, L_8000A6BC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8000A698: andi        $t9, $v0, 0x30
        ctx->r25 = ctx->r2 & 0X30;
            goto L_8000A6BC;
    }
    // 0x8000A698: andi        $t9, $v0, 0x30
    ctx->r25 = ctx->r2 & 0X30;
    // 0x8000A69C: sll         $v1, $t1, 10
    ctx->r3 = S32(ctx->r9 << 10);
    // 0x8000A6A0: sra         $v1, $v1, 7
    ctx->r3 = S32(SIGNED(ctx->r3) >> 7);
    // 0x8000A6A4: bgez        $v1, L_8000A6B4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000A6A8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8000A6B4;
    }
    // 0x8000A6A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000A6AC: b           L_8000A6C0
    // 0x8000A6B0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_8000A6C0;
    // 0x8000A6B0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_8000A6B4:
    // 0x8000A6B4: b           L_8000A6C0
    // 0x8000A6B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
        goto L_8000A6C0;
    // 0x8000A6B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8000A6BC:
    // 0x8000A6BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000A6C0:
    // 0x8000A6C0: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x8000A6C4: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x8000A6C8: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8000A6CC: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x8000A6D0: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8000A6D4: subu        $t8, $t9, $a3
    ctx->r24 = SUB32(ctx->r25, ctx->r7);
    // 0x8000A6D8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8000A6DC: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8000A6E0: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8000A6E4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000A6E8: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x8000A6EC: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x8000A6F0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000A6F4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8000A6F8: lui         $t6, 0xF100
    ctx->r14 = S32(0XF100 << 16);
    // 0x8000A6FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000A700: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_8000A704:
    // 0x8000A704: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000A708: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x8000A70C: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
L_8000A710:
    // 0x8000A710: lhu         $a0, 0x2($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X2);
    // 0x8000A714: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x8000A718: bne         $s6, $a0, L_8000A570
    if (ctx->r22 != ctx->r4) {
        // 0x8000A71C: nop
    
            goto L_8000A570;
    }
    // 0x8000A71C: nop

    // 0x8000A720: lbu         $v0, 0x10E($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X10E);
L_8000A724:
    // 0x8000A724: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000A728: andi        $s5, $v0, 0xFF
    ctx->r21 = ctx->r2 & 0XFF;
    // 0x8000A72C: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x8000A730: bne         $at, $zero, L_8000A3B8
    if (ctx->r1 != 0) {
        // 0x8000A734: sb          $s5, 0x10E($sp)
        MEM_B(0X10E, ctx->r29) = ctx->r21;
            goto L_8000A3B8;
    }
    // 0x8000A734: sb          $s5, 0x10E($sp)
    MEM_B(0X10E, ctx->r29) = ctx->r21;
    // 0x8000A738: lbu         $t7, 0x10F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X10F);
    // 0x8000A73C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000A740: andi        $s7, $t8, 0xFF
    ctx->r23 = ctx->r24 & 0XFF;
    // 0x8000A744: slti        $at, $s7, 0x4
    ctx->r1 = SIGNED(ctx->r23) < 0X4 ? 1 : 0;
    // 0x8000A748: bne         $at, $zero, L_8000A39C
    if (ctx->r1 != 0) {
        // 0x8000A74C: sb          $t8, 0x10F($sp)
        MEM_B(0X10F, ctx->r29) = ctx->r24;
            goto L_8000A39C;
    }
    // 0x8000A74C: sb          $t8, 0x10F($sp)
    MEM_B(0X10F, ctx->r29) = ctx->r24;
    // 0x8000A750: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8000A754:
    // 0x8000A754: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000A758: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A75C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000A760: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000A764: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000A768: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A76C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000A770: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8000A774: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000A778: jr          $ra
    // 0x8000A77C: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x8000A77C: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000a780(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000a780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A780: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000A784: sb          $t6, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r14;
    // 0x8000A788: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x8000A78C: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x8000A790: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x8000A794: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x8000A798: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    // 0x8000A79C: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x8000A7A0: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x8000A7A4: lbu         $t1, 0x4($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X4);
    // 0x8000A7A8: sb          $t1, 0x4($t2)
    MEM_B(0X4, ctx->r10) = ctx->r9;
    // 0x8000A7AC: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x8000A7B0: lbu         $t3, 0x5($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X5);
    // 0x8000A7B4: sb          $t3, 0x5($t4)
    MEM_B(0X5, ctx->r12) = ctx->r11;
    // 0x8000A7B8: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8000A7BC: lbu         $t5, 0x6($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X6);
    // 0x8000A7C0: sb          $t5, 0x6($t6)
    MEM_B(0X6, ctx->r14) = ctx->r13;
    // 0x8000A7C4: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x8000A7C8: lbu         $t7, 0x7($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X7);
    // 0x8000A7CC: sb          $t7, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r15;
    // 0x8000A7D0: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x8000A7D4: lbu         $t9, 0x8($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X8);
    // 0x8000A7D8: sb          $t9, 0x8($t0)
    MEM_B(0X8, ctx->r8) = ctx->r25;
    // 0x8000A7DC: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x8000A7E0: lbu         $t1, 0x9($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X9);
    // 0x8000A7E4: sb          $t1, 0x9($t2)
    MEM_B(0X9, ctx->r10) = ctx->r9;
    // 0x8000A7E8: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x8000A7EC: lbu         $t3, 0xA($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0XA);
    // 0x8000A7F0: sb          $t3, 0xA($t4)
    MEM_B(0XA, ctx->r12) = ctx->r11;
    // 0x8000A7F4: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8000A7F8: lbu         $t5, 0xB($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XB);
    // 0x8000A7FC: sb          $t5, 0xB($t6)
    MEM_B(0XB, ctx->r14) = ctx->r13;
    // 0x8000A800: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x8000A804: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x8000A808: sh          $t7, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r15;
    // 0x8000A80C: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x8000A810: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x8000A814: sh          $t9, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r25;
    // 0x8000A818: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x8000A81C: lhu         $t1, 0x10($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X10);
    // 0x8000A820: jr          $ra
    // 0x8000A824: sh          $t1, 0x10($t2)
    MEM_H(0X10, ctx->r10) = ctx->r9;
    return;
    // 0x8000A824: sh          $t1, 0x10($t2)
    MEM_H(0X10, ctx->r10) = ctx->r9;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000a828(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000a828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A828: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8000A82C: addiu       $a1, $a1, -0x2A44
    ctx->r5 = ADD32(ctx->r5, -0X2A44);
    // 0x8000A830: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000A834: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A83C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000A840: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8000A844: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8000A848: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8000A84C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A850: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000A854: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8000A858: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x8000A85C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000A860: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000A864: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A868: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000A86C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000A870: lui         $t5, 0xD9D0
    ctx->r13 = S32(0XD9D0 << 16);
    // 0x8000A874: ori         $t5, $t5, 0xF9FA
    ctx->r13 = ctx->r13 | 0XF9FA;
    // 0x8000A878: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000A87C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8000A880: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A884: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000A888: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000A88C: lui         $t8, 0xFFFD
    ctx->r24 = S32(0XFFFD << 16);
    // 0x8000A890: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x8000A894: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000A898: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8000A89C: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8000A8A0: ori         $t8, $t8, 0xF6FB
    ctx->r24 = ctx->r24 | 0XF6FB;
    // 0x8000A8A4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000A8A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000A8AC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000A8B0: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x8000A8B4: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x8000A8B8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000A8BC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8000A8C0: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8000A8C4: ori         $t6, $t6, 0x4240
    ctx->r14 = ctx->r14 | 0X4240;
    // 0x8000A8C8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000A8CC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000A8D0: jal         0x80001060
    // 0x8000A8D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x8000A8D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000A8D8: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8000A8DC: addiu       $a1, $a1, -0x2A44
    ctx->r5 = ADD32(ctx->r5, -0X2A44);
    // 0x8000A8E0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8000A8E4: bne         $v0, $zero, L_8000AC14
    if (ctx->r2 != 0) {
        // 0x8000A8E8: lui         $t4, 0xE700
        ctx->r12 = S32(0XE700 << 16);
            goto L_8000AC14;
    }
    // 0x8000A8E8: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8000A8EC: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000A8F0: lbu         $t7, 0x7($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X7);
    // 0x8000A8F4: beql        $t7, $zero, L_8000A9C8
    if (ctx->r15 == 0) {
        // 0x8000A8F8: lhu         $t6, 0x10($v0)
        ctx->r14 = MEM_HU(ctx->r2, 0X10);
            goto L_8000A9C8;
    }
    goto skip_0;
    // 0x8000A8F8: lhu         $t6, 0x10($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X10);
    skip_0:
    // 0x8000A8FC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000A900: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8000A904: lui         $t3, 0xF600
    ctx->r11 = S32(0XF600 << 16);
    // 0x8000A908: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000A90C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8000A910: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A914: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8000A918: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000A91C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000A920: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8000A924: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000A928: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000A92C: lbu         $t5, 0x5($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X5);
    // 0x8000A930: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x8000A934: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x8000A938: lbu         $t5, 0x6($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X6);
    // 0x8000A93C: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8000A940: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8000A944: sll         $t8, $t5, 8
    ctx->r24 = S32(ctx->r13 << 8);
    // 0x8000A948: lbu         $t5, 0x7($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X7);
    // 0x8000A94C: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8000A950: or          $t7, $t6, $t5
    ctx->r15 = ctx->r14 | ctx->r13;
    // 0x8000A954: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000A958: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000A95C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000A960: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8000A964: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000A968: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8000A96C: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x8000A970: addu        $t5, $t9, $t6
    ctx->r13 = ADD32(ctx->r25, ctx->r14);
    // 0x8000A974: andi        $t7, $t5, 0x3FF
    ctx->r15 = ctx->r13 & 0X3FF;
    // 0x8000A978: lhu         $t5, 0xE($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XE);
    // 0x8000A97C: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x8000A980: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x8000A984: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x8000A988: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x8000A98C: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8000A990: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8000A994: or          $t5, $t9, $t6
    ctx->r13 = ctx->r25 | ctx->r14;
    // 0x8000A998: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000A99C: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000A9A0: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8000A9A4: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x8000A9A8: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8000A9AC: andi        $t5, $t6, 0x3FF
    ctx->r13 = ctx->r14 & 0X3FF;
    // 0x8000A9B0: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8000A9B4: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8000A9B8: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8000A9BC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000A9C0: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000A9C4: lhu         $t6, 0x10($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X10);
L_8000A9C8:
    // 0x8000A9C8: lui         $t3, 0xF600
    ctx->r11 = S32(0XF600 << 16);
    // 0x8000A9CC: beql        $t6, $zero, L_8000AFCC
    if (ctx->r14 == 0) {
        // 0x8000A9D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000AFCC;
    }
    goto skip_1;
    // 0x8000A9D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8000A9D4: lbu         $t5, 0xB($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XB);
    // 0x8000A9D8: beql        $t5, $zero, L_8000AFCC
    if (ctx->r13 == 0) {
        // 0x8000A9DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000AFCC;
    }
    goto skip_2;
    // 0x8000A9DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8000A9E0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000A9E4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8000A9E8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000A9EC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8000A9F0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000A9F4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8000A9F8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000A9FC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000AA00: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000AA04: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000AA08: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AA0C: lbu         $t8, 0x9($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X9);
    // 0x8000AA10: lbu         $t5, 0x8($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X8);
    // 0x8000AA14: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x8000AA18: lbu         $t8, 0xA($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XA);
    // 0x8000AA1C: sll         $t9, $t5, 24
    ctx->r25 = S32(ctx->r13 << 24);
    // 0x8000AA20: or          $t5, $t9, $t6
    ctx->r13 = ctx->r25 | ctx->r14;
    // 0x8000AA24: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8000AA28: lbu         $t8, 0xB($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XB);
    // 0x8000AA2C: or          $t6, $t5, $t9
    ctx->r14 = ctx->r13 | ctx->r25;
    // 0x8000AA30: or          $t5, $t6, $t8
    ctx->r13 = ctx->r14 | ctx->r24;
    // 0x8000AA34: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8000AA38: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000AA3C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000AA40: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8000AA44: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AA48: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8000AA4C: lhu         $t6, 0xE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XE);
    // 0x8000AA50: lhu         $t5, 0x10($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X10);
    // 0x8000AA54: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8000AA58: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x8000AA5C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8000AA60: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x8000AA64: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8000AA68: andi        $t5, $t8, 0x3FF
    ctx->r13 = ctx->r24 & 0X3FF;
    // 0x8000AA6C: sll         $t9, $t5, 14
    ctx->r25 = S32(ctx->r13 << 14);
    // 0x8000AA70: or          $t7, $t9, $t3
    ctx->r15 = ctx->r25 | ctx->r11;
    // 0x8000AA74: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8000AA78: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000AA7C: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AA80: lhu         $a0, 0x10($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X10);
    // 0x8000AA84: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x8000AA88: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8000AA8C: subu        $t9, $t5, $a0
    ctx->r25 = SUB32(ctx->r13, ctx->r4);
    // 0x8000AA90: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x8000AA94: subu        $t5, $t8, $a0
    ctx->r13 = SUB32(ctx->r24, ctx->r4);
    // 0x8000AA98: andi        $t9, $t5, 0x3FF
    ctx->r25 = ctx->r13 & 0X3FF;
    // 0x8000AA9C: sll         $t6, $t7, 14
    ctx->r14 = S32(ctx->r15 << 14);
    // 0x8000AAA0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8000AAA4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8000AAA8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000AAAC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000AAB0: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8000AAB4: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8000AAB8: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AABC: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8000AAC0: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x8000AAC4: lhu         $a0, 0x10($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X10);
    // 0x8000AAC8: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8000AACC: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8000AAD0: andi        $t5, $t8, 0x3FF
    ctx->r13 = ctx->r24 & 0X3FF;
    // 0x8000AAD4: lhu         $t8, 0xE($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XE);
    // 0x8000AAD8: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8000AADC: sll         $t9, $t5, 14
    ctx->r25 = S32(ctx->r13 << 14);
    // 0x8000AAE0: or          $t6, $t9, $t3
    ctx->r14 = ctx->r25 | ctx->r11;
    // 0x8000AAE4: addu        $t5, $t7, $t8
    ctx->r13 = ADD32(ctx->r15, ctx->r24);
    // 0x8000AAE8: addu        $t9, $t5, $a0
    ctx->r25 = ADD32(ctx->r13, ctx->r4);
    // 0x8000AAEC: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x8000AAF0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000AAF4: or          $t5, $t6, $t8
    ctx->r13 = ctx->r14 | ctx->r24;
    // 0x8000AAF8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000AAFC: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AB00: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8000AB04: lhu         $t7, 0xC($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XC);
    // 0x8000AB08: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x8000AB0C: lhu         $t7, 0x10($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X10);
    // 0x8000AB10: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8000AB14: andi        $t8, $t6, 0x3FF
    ctx->r24 = ctx->r14 & 0X3FF;
    // 0x8000AB18: sll         $t5, $t8, 14
    ctx->r13 = S32(ctx->r24 << 14);
    // 0x8000AB1C: subu        $t6, $t9, $t7
    ctx->r14 = SUB32(ctx->r25, ctx->r15);
    // 0x8000AB20: andi        $t8, $t6, 0x3FF
    ctx->r24 = ctx->r14 & 0X3FF;
    // 0x8000AB24: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000AB28: or          $t7, $t5, $t9
    ctx->r15 = ctx->r13 | ctx->r25;
    // 0x8000AB2C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000AB30: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000AB34: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000AB38: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8000AB3C: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AB40: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8000AB44: lhu         $t5, 0xC($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XC);
    // 0x8000AB48: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x8000AB4C: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x8000AB50: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x8000AB54: sll         $t6, $t7, 14
    ctx->r14 = S32(ctx->r15 << 14);
    // 0x8000AB58: andi        $t9, $t5, 0x3FF
    ctx->r25 = ctx->r13 & 0X3FF;
    // 0x8000AB5C: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8000AB60: or          $t8, $t6, $t3
    ctx->r24 = ctx->r14 | ctx->r11;
    // 0x8000AB64: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x8000AB68: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000AB6C: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AB70: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x8000AB74: lhu         $t9, 0x10($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X10);
    // 0x8000AB78: subu        $t8, $t5, $t9
    ctx->r24 = SUB32(ctx->r13, ctx->r25);
    // 0x8000AB7C: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x8000AB80: andi        $t7, $t8, 0x3FF
    ctx->r15 = ctx->r24 & 0X3FF;
    // 0x8000AB84: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8000AB88: andi        $t9, $t5, 0x3FF
    ctx->r25 = ctx->r13 & 0X3FF;
    // 0x8000AB8C: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x8000AB90: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8000AB94: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000AB98: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000AB9C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8000ABA0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8000ABA4: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000ABA8: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8000ABAC: lhu         $t8, 0xC($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XC);
    // 0x8000ABB0: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x8000ABB4: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x8000ABB8: sll         $t5, $t7, 14
    ctx->r13 = S32(ctx->r15 << 14);
    // 0x8000ABBC: lhu         $t6, 0xE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XE);
    // 0x8000ABC0: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8000ABC4: or          $t9, $t5, $t3
    ctx->r25 = ctx->r13 | ctx->r11;
    // 0x8000ABC8: lhu         $t5, 0x10($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X10);
    // 0x8000ABCC: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8000ABD0: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x8000ABD4: andi        $t6, $t8, 0x3FF
    ctx->r14 = ctx->r24 & 0X3FF;
    // 0x8000ABD8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000ABDC: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x8000ABE0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000ABE4: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000ABE8: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8000ABEC: lhu         $t6, 0xE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XE);
    // 0x8000ABF0: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8000ABF4: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8000ABF8: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x8000ABFC: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8000AC00: andi        $t6, $t8, 0x3FF
    ctx->r14 = ctx->r24 & 0X3FF;
    // 0x8000AC04: sll         $t9, $t6, 14
    ctx->r25 = S32(ctx->r14 << 14);
    // 0x8000AC08: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x8000AC0C: b           L_8000AFC8
    // 0x8000AC10: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
        goto L_8000AFC8;
    // 0x8000AC10: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_8000AC14:
    // 0x8000AC14: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AC18: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x8000AC1C: beql        $t8, $zero, L_8000AD08
    if (ctx->r24 == 0) {
        // 0x8000AC20: lhu         $t8, 0x10($v0)
        ctx->r24 = MEM_HU(ctx->r2, 0X10);
            goto L_8000AD08;
    }
    goto skip_3;
    // 0x8000AC20: lhu         $t8, 0x10($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X10);
    skip_3:
    // 0x8000AC24: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000AC28: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8000AC2C: lui         $t3, 0xF600
    ctx->r11 = S32(0XF600 << 16);
    // 0x8000AC30: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000AC34: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8000AC38: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000AC3C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8000AC40: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000AC44: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000AC48: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8000AC4C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000AC50: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AC54: lbu         $t5, 0x5($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X5);
    // 0x8000AC58: lbu         $t8, 0x4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4);
    // 0x8000AC5C: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x8000AC60: lbu         $t5, 0x6($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X6);
    // 0x8000AC64: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x8000AC68: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8000AC6C: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x8000AC70: lbu         $t5, 0x7($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X7);
    // 0x8000AC74: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8000AC78: or          $t8, $t7, $t5
    ctx->r24 = ctx->r15 | ctx->r13;
    // 0x8000AC7C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000AC80: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000AC84: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000AC88: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8000AC8C: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AC90: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8000AC94: lhu         $t5, 0xC($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XC);
    // 0x8000AC98: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x8000AC9C: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x8000ACA0: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8000ACA4: andi        $t9, $t6, 0x3FF
    ctx->r25 = ctx->r14 & 0X3FF;
    // 0x8000ACA8: sll         $t5, $t9, 14
    ctx->r13 = S32(ctx->r25 << 14);
    // 0x8000ACAC: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x8000ACB0: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8000ACB4: or          $t7, $t5, $t3
    ctx->r15 = ctx->r13 | ctx->r11;
    // 0x8000ACB8: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8000ACBC: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x8000ACC0: addu        $t8, $t6, $t5
    ctx->r24 = ADD32(ctx->r14, ctx->r13);
    // 0x8000ACC4: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x8000ACC8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8000ACCC: or          $t5, $t7, $t6
    ctx->r13 = ctx->r15 | ctx->r14;
    // 0x8000ACD0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000ACD4: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000ACD8: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8000ACDC: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x8000ACE0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8000ACE4: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x8000ACE8: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x8000ACEC: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x8000ACF0: sll         $t6, $t7, 14
    ctx->r14 = S32(ctx->r15 << 14);
    // 0x8000ACF4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8000ACF8: or          $t5, $t6, $t7
    ctx->r13 = ctx->r14 | ctx->r15;
    // 0x8000ACFC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8000AD00: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AD04: lhu         $t8, 0x10($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X10);
L_8000AD08:
    // 0x8000AD08: lui         $t3, 0xF600
    ctx->r11 = S32(0XF600 << 16);
    // 0x8000AD0C: beql        $t8, $zero, L_8000AFCC
    if (ctx->r24 == 0) {
        // 0x8000AD10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000AFCC;
    }
    goto skip_4;
    // 0x8000AD10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8000AD14: lbu         $t9, 0xB($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XB);
    // 0x8000AD18: beql        $t9, $zero, L_8000AFCC
    if (ctx->r25 == 0) {
        // 0x8000AD1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000AFCC;
    }
    goto skip_5;
    // 0x8000AD1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8000AD20: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000AD24: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8000AD28: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000AD2C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8000AD30: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000AD34: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8000AD38: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000AD3C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000AD40: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000AD44: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000AD48: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AD4C: lbu         $t5, 0x9($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X9);
    // 0x8000AD50: lbu         $t9, 0x8($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X8);
    // 0x8000AD54: sll         $t8, $t5, 16
    ctx->r24 = S32(ctx->r13 << 16);
    // 0x8000AD58: lbu         $t5, 0xA($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XA);
    // 0x8000AD5C: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x8000AD60: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8000AD64: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x8000AD68: lbu         $t5, 0xB($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XB);
    // 0x8000AD6C: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8000AD70: or          $t9, $t8, $t5
    ctx->r25 = ctx->r24 | ctx->r13;
    // 0x8000AD74: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000AD78: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000AD7C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000AD80: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8000AD84: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AD88: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8000AD8C: lhu         $t5, 0xE($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XE);
    // 0x8000AD90: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8000AD94: lhu         $t7, 0x10($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X10);
    // 0x8000AD98: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x8000AD9C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8000ADA0: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x8000ADA4: addu        $t8, $t6, $t5
    ctx->r24 = ADD32(ctx->r14, ctx->r13);
    // 0x8000ADA8: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8000ADAC: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x8000ADB0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8000ADB4: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x8000ADB8: andi        $t8, $t5, 0x3FF
    ctx->r24 = ctx->r13 & 0X3FF;
    // 0x8000ADBC: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8000ADC0: or          $t6, $t9, $t3
    ctx->r14 = ctx->r25 | ctx->r11;
    // 0x8000ADC4: or          $t5, $t6, $t7
    ctx->r13 = ctx->r14 | ctx->r15;
    // 0x8000ADC8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000ADCC: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000ADD0: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8000ADD4: lhu         $a0, 0x10($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X10);
    // 0x8000ADD8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8000ADDC: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8000ADE0: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x8000ADE4: subu        $t6, $t9, $a0
    ctx->r14 = SUB32(ctx->r25, ctx->r4);
    // 0x8000ADE8: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x8000ADEC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8000ADF0: subu        $t6, $t9, $a0
    ctx->r14 = SUB32(ctx->r25, ctx->r4);
    // 0x8000ADF4: sll         $t5, $t7, 14
    ctx->r13 = S32(ctx->r15 << 14);
    // 0x8000ADF8: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x8000ADFC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000AE00: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x8000AE04: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000AE08: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000AE0C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000AE10: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8000AE14: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AE18: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8000AE1C: lhu         $t8, 0xC($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XC);
    // 0x8000AE20: lhu         $a0, 0x10($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X10);
    // 0x8000AE24: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x8000AE28: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8000AE2C: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x8000AE30: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x8000AE34: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8000AE38: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8000AE3C: sll         $t5, $t8, 14
    ctx->r13 = S32(ctx->r24 << 14);
    // 0x8000AE40: lhu         $t8, 0xE($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XE);
    // 0x8000AE44: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x8000AE48: or          $t9, $t5, $t3
    ctx->r25 = ctx->r13 | ctx->r11;
    // 0x8000AE4C: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x8000AE50: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8000AE54: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x8000AE58: addu        $t8, $t6, $a0
    ctx->r24 = ADD32(ctx->r14, ctx->r4);
    // 0x8000AE5C: andi        $t7, $t8, 0x3FF
    ctx->r15 = ctx->r24 & 0X3FF;
    // 0x8000AE60: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8000AE64: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x8000AE68: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000AE6C: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AE70: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8000AE74: lhu         $t9, 0xC($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XC);
    // 0x8000AE78: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8000AE7C: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8000AE80: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x8000AE84: andi        $t8, $t6, 0x3FF
    ctx->r24 = ctx->r14 & 0X3FF;
    // 0x8000AE88: lhu         $t6, 0x10($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X10);
    // 0x8000AE8C: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8000AE90: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8000AE94: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8000AE98: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x8000AE9C: subu        $t7, $t5, $t8
    ctx->r15 = SUB32(ctx->r13, ctx->r24);
    // 0x8000AEA0: andi        $t6, $t7, 0x3FF
    ctx->r14 = ctx->r15 & 0X3FF;
    // 0x8000AEA4: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8000AEA8: or          $t8, $t9, $t5
    ctx->r24 = ctx->r25 | ctx->r13;
    // 0x8000AEAC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000AEB0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000AEB4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000AEB8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000AEBC: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AEC0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8000AEC4: lhu         $t5, 0xC($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XC);
    // 0x8000AEC8: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x8000AECC: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x8000AED0: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8000AED4: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8000AED8: andi        $t6, $t7, 0x3FF
    ctx->r14 = ctx->r15 & 0X3FF;
    // 0x8000AEDC: sll         $t5, $t6, 14
    ctx->r13 = S32(ctx->r14 << 14);
    // 0x8000AEE0: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8000AEE4: andi        $t6, $t7, 0x3FF
    ctx->r14 = ctx->r15 & 0X3FF;
    // 0x8000AEE8: or          $t9, $t5, $t3
    ctx->r25 = ctx->r13 | ctx->r11;
    // 0x8000AEEC: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8000AEF0: or          $t8, $t9, $t5
    ctx->r24 = ctx->r25 | ctx->r13;
    // 0x8000AEF4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000AEF8: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AEFC: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8000AF00: lhu         $t9, 0x10($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X10);
    // 0x8000AF04: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8000AF08: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8000AF0C: subu        $t8, $t6, $t5
    ctx->r24 = SUB32(ctx->r14, ctx->r13);
    // 0x8000AF10: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8000AF14: andi        $t7, $t8, 0x3FF
    ctx->r15 = ctx->r24 & 0X3FF;
    // 0x8000AF18: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8000AF1C: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x8000AF20: andi        $t8, $t5, 0x3FF
    ctx->r24 = ctx->r13 & 0X3FF;
    // 0x8000AF24: sll         $t7, $t8, 14
    ctx->r15 = S32(ctx->r24 << 14);
    // 0x8000AF28: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8000AF2C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000AF30: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000AF34: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8000AF38: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8000AF3C: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AF40: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8000AF44: lhu         $t9, 0xC($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XC);
    // 0x8000AF48: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8000AF4C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8000AF50: addu        $t5, $t7, $t6
    ctx->r13 = ADD32(ctx->r15, ctx->r14);
    // 0x8000AF54: andi        $t8, $t5, 0x3FF
    ctx->r24 = ctx->r13 & 0X3FF;
    // 0x8000AF58: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8000AF5C: lhu         $t8, 0xE($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XE);
    // 0x8000AF60: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x8000AF64: or          $t7, $t9, $t3
    ctx->r15 = ctx->r25 | ctx->r11;
    // 0x8000AF68: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8000AF6C: lhu         $t8, 0x10($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X10);
    // 0x8000AF70: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x8000AF74: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x8000AF78: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x8000AF7C: addu        $t9, $t6, $t5
    ctx->r25 = ADD32(ctx->r14, ctx->r13);
    // 0x8000AF80: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x8000AF84: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8000AF88: or          $t5, $t7, $t6
    ctx->r13 = ctx->r15 | ctx->r14;
    // 0x8000AF8C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000AF90: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8000AF94: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8000AF98: lhu         $t7, 0xE($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XE);
    // 0x8000AF9C: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x8000AFA0: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8000AFA4: addu        $t5, $t8, $t6
    ctx->r13 = ADD32(ctx->r24, ctx->r14);
    // 0x8000AFA8: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8000AFAC: andi        $t9, $t5, 0x3FF
    ctx->r25 = ctx->r13 & 0X3FF;
    // 0x8000AFB0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8000AFB4: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x8000AFB8: andi        $t5, $t6, 0x3FF
    ctx->r13 = ctx->r14 & 0X3FF;
    // 0x8000AFBC: sll         $t9, $t5, 14
    ctx->r25 = S32(ctx->r13 << 14);
    // 0x8000AFC0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8000AFC4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_8000AFC8:
    // 0x8000AFC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000AFCC:
    // 0x8000AFCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000AFD0: jr          $ra
    // 0x8000AFD4: nop

    return;
    // 0x8000AFD4: nop

    // 0x8000AFD8: nop

    // 0x8000AFDC: nop

;}
RECOMP_FUNC void FUN_8000afe0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AFE0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000AFE4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000AFE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000AFEC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000AFF0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8000AFF4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000AFF8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8000AFFC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8000B000: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8000B004: jal         0x8001EAD0
    // 0x8000B008: lh          $a0, 0x5A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5A);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x8000B008: lh          $a0, 0x5A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5A);
    after_0:
    // 0x8000B00C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8000B010: jal         0x8001EB64
    // 0x8000B014: lh          $a0, 0x5A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5A);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x8000B014: lh          $a0, 0x5A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5A);
    after_1:
    // 0x8000B018: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8000B01C: jal         0x8001EAD0
    // 0x8000B020: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x8000B020: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    after_2:
    // 0x8000B024: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8000B028: jal         0x8001EB64
    // 0x8000B02C: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x8000B02C: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    after_3:
    // 0x8000B030: lh          $a0, 0x62($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X62);
    // 0x8000B034: jal         0x8001EAD0
    // 0x8000B038: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x8000B038: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8000B03C: lh          $a0, 0x62($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X62);
    // 0x8000B040: jal         0x8001EB64
    // 0x8000B044: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x8000B044: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8000B048: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000B04C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000B050: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000B054: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8000B058: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000B05C: neg.s       $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = -ctx->f16.fl;
    // 0x8000B060: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8000B064: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8000B068: mul.s       $f12, $f20, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8000B06C: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8000B070: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8000B074: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8000B078: nop

    // 0x8000B07C: mul.s       $f18, $f22, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8000B080: nop

    // 0x8000B084: mul.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8000B088: nop

    // 0x8000B08C: mul.s       $f8, $f22, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8000B090: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8000B094: mul.s       $f18, $f20, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x8000B098: nop

    // 0x8000B09C: mul.s       $f12, $f22, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x8000B0A0: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x8000B0A4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8000B0A8: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x8000B0AC: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x8000B0B0: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8000B0B4: nop

    // 0x8000B0B8: mul.s       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8000B0BC: nop

    // 0x8000B0C0: mul.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8000B0C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8000B0C8: mul.s       $f18, $f20, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8000B0CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000B0D0: mul.s       $f6, $f22, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8000B0D4: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x8000B0D8: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8000B0DC: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x8000B0E0: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x8000B0E4: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8000B0E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000B0EC: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x8000B0F0: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8000B0F4: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x8000B0F8: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8000B0FC: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x8000B100: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8000B104: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
    // 0x8000B108: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000B10C: swc1        $f12, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f12.u32l;
    // 0x8000B110: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8000B114: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x8000B118: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x8000B11C: bc1t        L_8000B150
    if (c1cs) {
        // 0x8000B120: nop
    
            goto L_8000B150;
    }
    // 0x8000B120: nop

    // 0x8000B124: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000B128: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000B12C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000B130: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8000B134: nop

    // 0x8000B138: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8000B13C: nop

    // 0x8000B140: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8000B144: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x8000B148: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8000B14C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_8000B150:
    // 0x8000B150: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000B154: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x8000B158: nop

    // 0x8000B15C: bc1tl       L_8000B194
    if (c1cs) {
        // 0x8000B160: lwc1        $f0, 0x6C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X6C);
            goto L_8000B194;
    }
    goto skip_0;
    // 0x8000B160: lwc1        $f0, 0x6C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X6C);
    skip_0:
    // 0x8000B164: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8000B168: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8000B16C: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8000B170: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8000B174: nop

    // 0x8000B178: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8000B17C: nop

    // 0x8000B180: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8000B184: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x8000B188: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8000B18C: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x8000B190: lwc1        $f0, 0x6C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X6C);
L_8000B194:
    // 0x8000B194: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x8000B198: nop

    // 0x8000B19C: bc1tl       L_8000B1D4
    if (c1cs) {
        // 0x8000B1A0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8000B1D4;
    }
    goto skip_1;
    // 0x8000B1A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8000B1A4: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8000B1A8: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8000B1AC: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8000B1B0: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8000B1B4: nop

    // 0x8000B1B8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000B1BC: nop

    // 0x8000B1C0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8000B1C4: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x8000B1C8: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x8000B1CC: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    // 0x8000B1D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000B1D4:
    // 0x8000B1D4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000B1D8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8000B1DC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000B1E0: jr          $ra
    // 0x8000B1E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8000B1E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000b1e8(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000b1e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B1E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000B1EC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000B1F0: lw          $v1, 0x2C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X2C);
    // 0x8000B1F4: beql        $v1, $zero, L_8000B208
    if (ctx->r3 == 0) {
        // 0x8000B1F8: lw          $v0, 0x30($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X30);
            goto L_8000B208;
    }
    goto skip_0;
    // 0x8000B1F8: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    skip_0:
    // 0x8000B1FC: b           L_8000B208
    // 0x8000B200: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8000B208;
    // 0x8000B200: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000B204: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
L_8000B208:
    // 0x8000B208: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x8000B20C: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x8000B210: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x8000B214: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x8000B218: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8000B21C: lh          $t7, 0x12($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X12);
    // 0x8000B220: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8000B224: lh          $t8, 0x14($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X14);
    // 0x8000B228: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8000B22C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8000B230: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8000B234: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000B238: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8000B23C: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8000B240: jal         0x8000AFE0
    // 0x8000B244: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8000AFE0)(rdram, ctx);
        goto after_0;
    // 0x8000B244: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8000B248: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B24C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8000B250: jr          $ra
    // 0x8000B254: nop

    return;
    // 0x8000B254: nop

;}
RECOMP_FUNC void FUN_8000b258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B258: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000B25C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000B260: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8000B264: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8000B268: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000B26C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000B270: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000B274: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000B278: lwc1        $f10, 0x20($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8000B27C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000B280: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000B284: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8000B288: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8000B28C: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8000B290: swc1        $f8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f8.u32l;
    // 0x8000B294: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000B298: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000B29C: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8000B2A0: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8000B2A4: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8000B2A8: nop

    // 0x8000B2AC: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000B2B0: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8000B2B4: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000B2B8: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000B2BC: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000B2C0: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8000B2C4: swc1        $f18, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f18.u32l;
    // 0x8000B2C8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000B2CC: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000B2D0: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8000B2D4: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8000B2D8: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000B2DC: nop

    // 0x8000B2E0: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8000B2E4: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8000B2E8: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000B2EC: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8000B2F0: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8000B2F4: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000B2F8: swc1        $f16, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f16.u32l;
    // 0x8000B2FC: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000B300: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000B304: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8000B308: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8000B30C: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8000B310: nop

    // 0x8000B314: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8000B318: lwc1        $f16, 0x20($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8000B31C: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8000B320: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8000B324: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8000B328: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000B32C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8000B330: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000B334: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000B338: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8000B33C: lwc1        $f18, 0x14($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8000B340: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8000B344: nop

    // 0x8000B348: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8000B34C: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8000B350: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8000B354: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000B358: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8000B35C: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8000B360: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8000B364: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000B368: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000B36C: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8000B370: lwc1        $f16, 0x18($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8000B374: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8000B378: nop

    // 0x8000B37C: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000B380: lwc1        $f4, 0x28($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8000B384: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8000B388: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000B38C: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000B390: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8000B394: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8000B398: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8000B39C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000B3A0: lwc1        $f18, 0x24($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8000B3A4: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8000B3A8: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000B3AC: nop

    // 0x8000B3B0: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8000B3B4: lwc1        $f18, 0x20($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8000B3B8: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8000B3BC: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8000B3C0: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8000B3C4: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000B3C8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8000B3CC: lwc1        $f18, 0x20($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8000B3D0: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000B3D4: lwc1        $f16, 0x24($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8000B3D8: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8000B3DC: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8000B3E0: nop

    // 0x8000B3E4: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8000B3E8: lwc1        $f16, 0x24($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8000B3EC: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8000B3F0: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8000B3F4: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8000B3F8: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000B3FC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8000B400: lwc1        $f16, 0x20($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8000B404: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000B408: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8000B40C: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8000B410: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8000B414: nop

    // 0x8000B418: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8000B41C: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8000B420: lwc1        $f18, 0x28($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8000B424: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000B428: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8000B42C: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8000B430: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8000B434: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8000B438: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000B43C: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8000B440: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8000B444: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8000B448: nop

    // 0x8000B44C: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000B450: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8000B454: lwc1        $f16, 0x20($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8000B458: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000B45C: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000B460: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x8000B464: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8000B468: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8000B46C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000B470: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8000B474: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8000B478: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8000B47C: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000B480: lwc1        $f10, 0x34($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8000B484: lwc1        $f18, 0x14($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8000B488: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000B48C: nop

    // 0x8000B490: mul.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8000B494: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8000B498: lwc1        $f18, 0x24($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8000B49C: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8000B4A0: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8000B4A4: lwc1        $f10, 0x34($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8000B4A8: lwc1        $f18, 0x3C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8000B4AC: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000B4B0: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8000B4B4: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8000B4B8: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8000B4BC: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8000B4C0: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000B4C4: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8000B4C8: lwc1        $f16, 0x18($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8000B4CC: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8000B4D0: nop

    // 0x8000B4D4: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8000B4D8: lwc1        $f6, 0x38($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8000B4DC: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8000B4E0: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8000B4E4: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8000B4E8: lwc1        $f6, 0x38($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8000B4EC: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8000B4F0: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000B4F4: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8000B4F8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000B4FC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8000B500: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8000B504: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8000B508: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x8000B50C: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8000B510: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x8000B514: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8000B518: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x8000B51C: lwc1        $f18, 0x14($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8000B520: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x8000B524: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8000B528: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x8000B52C: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8000B530: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x8000B534: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000B538: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000B53C: swc1        $f16, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f16.u32l;
    // 0x8000B540: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8000B544: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x8000B548: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000B54C: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x8000B550: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000B554: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x8000B558: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000B55C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000B560: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x8000B564: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8000B568: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x8000B56C: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x8000B570: jr          $ra
    // 0x8000B574: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8000B574: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000b578(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000b578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B578: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8000B57C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B580: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8000B584: lw          $a0, 0x1C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1C);
    // 0x8000B588: jal         0x8000B67C
    // 0x8000B58C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    LOOKUP_FUNC(0x8000B67C)(rdram, ctx);
        goto after_0;
    // 0x8000B58C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8000B590: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8000B594: jal         0x8000B258
    // 0x8000B598: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    LOOKUP_FUNC(0x8000B258)(rdram, ctx);
        goto after_1;
    // 0x8000B598: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8000B59C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B5A0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8000B5A4: jr          $ra
    // 0x8000B5A8: nop

    return;
    // 0x8000B5A8: nop

;}
RECOMP_FUNC void FUN_8000b5ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B5AC: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8000B5B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000B5B4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8000B5B8: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x8000B5BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000B5C0: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8000B5C4: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x8000B5C8: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
L_8000B5CC:
    // 0x8000B5CC: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8000B5D0: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8000B5D4: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8000B5D8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000B5DC: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8000B5E0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8000B5E4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8000B5E8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8000B5EC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8000B5F0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8000B5F4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8000B5F8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8000B5FC: and         $t8, $a0, $a2
    ctx->r24 = ctx->r4 & ctx->r6;
    // 0x8000B600: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x8000B604: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8000B608: andi        $t2, $t9, 0xFFFF
    ctx->r10 = ctx->r25 & 0XFFFF;
    // 0x8000B60C: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x8000B610: and         $t5, $t4, $a2
    ctx->r13 = ctx->r12 & ctx->r6;
    // 0x8000B614: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x8000B618: sw          $t3, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r11;
    // 0x8000B61C: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8000B620: sw          $t7, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r15;
    // 0x8000B624: lwc1        $f4, -0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, -0X8);
    // 0x8000B628: lwc1        $f10, -0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, -0X4);
    // 0x8000B62C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000B630: nop

    // 0x8000B634: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8000B638: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8000B63C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8000B640: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8000B644: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8000B648: and         $t2, $a0, $a2
    ctx->r10 = ctx->r4 & ctx->r6;
    // 0x8000B64C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8000B650: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8000B654: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8000B658: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8000B65C: and         $t7, $t6, $a2
    ctx->r15 = ctx->r14 & ctx->r6;
    // 0x8000B660: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x8000B664: sw          $t5, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r13;
    // 0x8000B668: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8000B66C: bne         $a3, $t1, L_8000B5CC
    if (ctx->r7 != ctx->r9) {
        // 0x8000B670: sw          $t8, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r24;
            goto L_8000B5CC;
    }
    // 0x8000B670: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x8000B674: jr          $ra
    // 0x8000B678: nop

    return;
    // 0x8000B678: nop

;}
RECOMP_FUNC void FUN_8000b67c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B67C: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x8000B680: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000B684: addiu       $v1, $a0, 0x20
    ctx->r3 = ADD32(ctx->r4, 0X20);
    // 0x8000B688: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8000B68C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000B690: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8000B694: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8000B698: lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
    // 0x8000B69C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000B6A0:
    // 0x8000B6A0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8000B6A4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8000B6A8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8000B6AC: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x8000B6B0: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8000B6B4: and         $t0, $t9, $a0
    ctx->r8 = ctx->r25 & ctx->r4;
    // 0x8000B6B8: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x8000B6BC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8000B6C0: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8000B6C4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8000B6C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000B6CC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8000B6D0: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8000B6D4: and         $t6, $t5, $a0
    ctx->r14 = ctx->r13 & ctx->r4;
    // 0x8000B6D8: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8000B6DC: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x8000B6E0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8000B6E4: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8000B6E8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8000B6EC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8000B6F0: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x8000B6F4: swc1        $f8, -0x20($a3)
    MEM_W(-0X20, ctx->r7) = ctx->f8.u32l;
    // 0x8000B6F8: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8000B6FC: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8000B700: nop

    // 0x8000B704: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000B708: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8000B70C: swc1        $f18, -0x1C($a3)
    MEM_W(-0X1C, ctx->r7) = ctx->f18.u32l;
    // 0x8000B710: lw          $t0, -0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, -0XC);
    // 0x8000B714: lw          $t4, -0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, -0XC);
    // 0x8000B718: srl         $t1, $t0, 16
    ctx->r9 = S32(U32(ctx->r8) >> 16);
    // 0x8000B71C: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8000B720: and         $t5, $t4, $a0
    ctx->r13 = ctx->r12 & ctx->r4;
    // 0x8000B724: or          $t4, $t2, $t5
    ctx->r12 = ctx->r10 | ctx->r13;
    // 0x8000B728: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8000B72C: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8000B730: lw          $t9, -0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, -0XC);
    // 0x8000B734: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000B738: lw          $t6, -0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XC);
    // 0x8000B73C: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8000B740: and         $t0, $t8, $a0
    ctx->r8 = ctx->r24 & ctx->r4;
    // 0x8000B744: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8000B748: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x8000B74C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8000B750: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x8000B754: swc1        $f8, -0x18($a3)
    MEM_W(-0X18, ctx->r7) = ctx->f8.u32l;
    // 0x8000B758: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8000B75C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8000B760: nop

    // 0x8000B764: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000B768: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8000B76C: swc1        $f18, -0x14($a3)
    MEM_W(-0X14, ctx->r7) = ctx->f18.u32l;
    // 0x8000B770: lw          $t5, -0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X8);
    // 0x8000B774: lw          $t9, -0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X8);
    // 0x8000B778: srl         $t3, $t5, 16
    ctx->r11 = S32(U32(ctx->r13) >> 16);
    // 0x8000B77C: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x8000B780: and         $t8, $t9, $a0
    ctx->r24 = ctx->r25 & ctx->r4;
    // 0x8000B784: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8000B788: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8000B78C: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8000B790: lw          $t4, -0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X8);
    // 0x8000B794: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000B798: lw          $t0, -0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, -0X8);
    // 0x8000B79C: sll         $t2, $t4, 16
    ctx->r10 = S32(ctx->r12 << 16);
    // 0x8000B7A0: and         $t5, $t2, $a0
    ctx->r13 = ctx->r10 & ctx->r4;
    // 0x8000B7A4: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x8000B7A8: or          $t3, $t1, $t5
    ctx->r11 = ctx->r9 | ctx->r13;
    // 0x8000B7AC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8000B7B0: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
    // 0x8000B7B4: swc1        $f8, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->f8.u32l;
    // 0x8000B7B8: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8000B7BC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8000B7C0: nop

    // 0x8000B7C4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000B7C8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8000B7CC: swc1        $f18, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f18.u32l;
    // 0x8000B7D0: lw          $t8, -0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X4);
    // 0x8000B7D4: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x8000B7D8: srl         $t7, $t8, 16
    ctx->r15 = S32(U32(ctx->r24) >> 16);
    // 0x8000B7DC: andi        $t0, $t7, 0xFFFF
    ctx->r8 = ctx->r15 & 0XFFFF;
    // 0x8000B7E0: and         $t2, $t4, $a0
    ctx->r10 = ctx->r12 & ctx->r4;
    // 0x8000B7E4: or          $t4, $t0, $t2
    ctx->r12 = ctx->r8 | ctx->r10;
    // 0x8000B7E8: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8000B7EC: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8000B7F0: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x8000B7F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000B7F8: lw          $t5, -0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X4);
    // 0x8000B7FC: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8000B800: and         $t8, $t6, $a0
    ctx->r24 = ctx->r14 & ctx->r4;
    // 0x8000B804: andi        $t3, $t5, 0xFFFF
    ctx->r11 = ctx->r13 & 0XFFFF;
    // 0x8000B808: or          $t7, $t3, $t8
    ctx->r15 = ctx->r11 | ctx->r24;
    // 0x8000B80C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8000B810: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8000B814: swc1        $f8, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f8.u32l;
    // 0x8000B818: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8000B81C: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8000B820: nop

    // 0x8000B824: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000B828: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8000B82C: bne         $a2, $a1, L_8000B6A0
    if (ctx->r6 != ctx->r5) {
        // 0x8000B830: swc1        $f18, -0x4($a3)
        MEM_W(-0X4, ctx->r7) = ctx->f18.u32l;
            goto L_8000B6A0;
    }
    // 0x8000B830: swc1        $f18, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f18.u32l;
    // 0x8000B834: jr          $ra
    // 0x8000B838: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8000B838: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000b83c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000b83c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B83C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000B840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B844: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8000B848: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8000B84C: beql        $v0, $zero, L_8000B860
    if (ctx->r2 == 0) {
        // 0x8000B850: lw          $t6, 0x30($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X30);
            goto L_8000B860;
    }
    goto skip_0;
    // 0x8000B850: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    skip_0:
    // 0x8000B854: b           L_8000B864
    // 0x8000B858: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_8000B864;
    // 0x8000B858: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000B85C: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
L_8000B860:
    // 0x8000B860: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_8000B864:
    // 0x8000B864: lw          $t7, -0x6BA0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6BA0);
    // 0x8000B868: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x8000B86C: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8000B870: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8000B874: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8000B878: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8000B87C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000B880: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000B884: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x8000B888: jal         0x8001EF38
    // 0x8000B88C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x8000B88C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8000B890: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000B894: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8000B898: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B89C: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000B8A0: addiu       $t0, $v0, 0x1000
    ctx->r8 = ADD32(ctx->r2, 0X1000);
    // 0x8000B8A4: andi        $t1, $t0, 0x1FFF
    ctx->r9 = ctx->r8 & 0X1FFF;
    // 0x8000B8A8: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000B8AC: sh          $t1, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r9;
    // 0x8000B8B0: jal         0x8002FC20
    // 0x8000B8B4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x8000B8B4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_1:
    // 0x8000B8B8: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8000B8BC: lw          $t3, -0x6BA0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6BA0);
    // 0x8000B8C0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8000B8C4: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x8000B8C8: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8000B8CC: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8000B8D0: jal         0x8001EF38
    // 0x8000B8D4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x8000B8D4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_2:
    // 0x8000B8D8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B8DC: sh          $v0, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r2;
    // 0x8000B8E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B8E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000B8E8: jr          $ra
    // 0x8000B8EC: nop

    return;
    // 0x8000B8EC: nop

;}
RECOMP_FUNC void FUN_8000b8f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B8F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000B8F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B8F8: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8000B8FC: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8000B900: beql        $v0, $zero, L_8000B914
    if (ctx->r2 == 0) {
        // 0x8000B904: lw          $v1, 0x30($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X30);
            goto L_8000B914;
    }
    goto skip_0;
    // 0x8000B904: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
    skip_0:
    // 0x8000B908: b           L_8000B914
    // 0x8000B90C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8000B914;
    // 0x8000B90C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000B910: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
L_8000B914:
    // 0x8000B914: lw          $t6, -0x6BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6BA0);
    // 0x8000B918: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x8000B91C: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8000B920: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8000B924: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8000B928: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8000B92C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8000B930: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000B934: jal         0x8001EF38
    // 0x8000B938: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x8000B938: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x8000B93C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B940: addiu       $t9, $v0, 0x1000
    ctx->r25 = ADD32(ctx->r2, 0X1000);
    // 0x8000B944: andi        $t0, $t9, 0x1FFF
    ctx->r8 = ctx->r25 & 0X1FFF;
    // 0x8000B948: sh          $t0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r8;
    // 0x8000B94C: sh          $zero, 0x10($v1)
    MEM_H(0X10, ctx->r3) = 0;
    // 0x8000B950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B954: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000B958: jr          $ra
    // 0x8000B95C: nop

    return;
    // 0x8000B95C: nop

;}
RECOMP_FUNC void FUN_8000b960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B960: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B968: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000B96C: sb          $t6, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r14;
    // 0x8000B970: lw          $v1, 0x2C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X2C);
    // 0x8000B974: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000B978: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8000B97C: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000B980: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x8000B984: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000B988: swc1        $f8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
    // 0x8000B98C: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x8000B990: sh          $t7, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r15;
    // 0x8000B994: lh          $t8, 0xE($a1)
    ctx->r24 = MEM_H(ctx->r5, 0XE);
    // 0x8000B998: sh          $t8, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r24;
    // 0x8000B99C: lh          $t9, 0x10($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X10);
    // 0x8000B9A0: sh          $t9, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r25;
    // 0x8000B9A4: lw          $t0, 0x14($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X14);
    // 0x8000B9A8: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
    // 0x8000B9AC: lhu         $t1, 0x18($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X18);
    // 0x8000B9B0: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8000B9B4: lw          $t2, 0x1C($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X1C);
    // 0x8000B9B8: sw          $t2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r10;
    // 0x8000B9BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000B9C0: jal         0x8000C3B0
    // 0x8000B9C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_0;
    // 0x8000B9C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8000B9C8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B9CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8000B9D0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000B9D4: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
    // 0x8000B9D8: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x8000B9DC: sb          $zero, 0x3A($v1)
    MEM_B(0X3A, ctx->r3) = 0;
    // 0x8000B9E0: lhu         $t3, 0x20($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X20);
    // 0x8000B9E4: sh          $t3, 0x2C($v1)
    MEM_H(0X2C, ctx->r3) = ctx->r11;
    // 0x8000B9E8: lwc1        $f10, 0x34($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8000B9EC: c.eq.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl == ctx->f10.fl;
    // 0x8000B9F0: nop

    // 0x8000B9F4: bc1tl       L_8000BA1C
    if (c1cs) {
        // 0x8000B9F8: lwc1        $f12, 0x30($a1)
        ctx->f12.u32l = MEM_W(ctx->r5, 0X30);
            goto L_8000BA1C;
    }
    goto skip_0;
    // 0x8000B9F8: lwc1        $f12, 0x30($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X30);
    skip_0:
    // 0x8000B9FC: lwc1        $f16, 0x30($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X30);
    // 0x8000BA00: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
    // 0x8000BA04: lwc1        $f18, 0x34($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8000BA08: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x8000BA0C: lwc1        $f4, 0x38($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8000BA10: b           L_8000BA54
    // 0x8000BA14: swc1        $f4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f4.u32l;
        goto L_8000BA54;
    // 0x8000BA14: swc1        $f4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f4.u32l;
    // 0x8000BA18: lwc1        $f12, 0x30($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X30);
L_8000BA1C:
    // 0x8000BA1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000BA20: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x8000BA24: nop

    // 0x8000BA28: bc1tl       L_8000BA44
    if (c1cs) {
        // 0x8000BA2C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8000BA44;
    }
    goto skip_1;
    // 0x8000BA2C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_1:
    // 0x8000BA30: swc1        $f12, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f12.u32l;
    // 0x8000BA34: swc1        $f12, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f12.u32l;
    // 0x8000BA38: b           L_8000BA54
    // 0x8000BA3C: swc1        $f12, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f12.u32l;
        goto L_8000BA54;
    // 0x8000BA3C: swc1        $f12, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f12.u32l;
    // 0x8000BA40: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8000BA44:
    // 0x8000BA44: nop

    // 0x8000BA48: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x8000BA4C: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x8000BA50: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
L_8000BA54:
    // 0x8000BA54: swc1        $f2, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f2.u32l;
    // 0x8000BA58: sw          $zero, 0x54($v1)
    MEM_W(0X54, ctx->r3) = 0;
    // 0x8000BA5C: sh          $zero, 0x58($v1)
    MEM_H(0X58, ctx->r3) = 0;
    // 0x8000BA60: sw          $zero, 0x40($v1)
    MEM_W(0X40, ctx->r3) = 0;
    // 0x8000BA64: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x8000BA68: lw          $t5, 0x24($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X24);
    // 0x8000BA6C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8000BA70: sw          $t5, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r13;
    // 0x8000BA74: lw          $t4, 0x28($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X28);
    // 0x8000BA78: sw          $t4, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r12;
    // 0x8000BA7C: lw          $t5, 0x2C($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X2C);
    // 0x8000BA80: sw          $t5, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r13;
    // 0x8000BA84: lbu         $t6, 0x3C($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3C);
    // 0x8000BA88: sb          $t6, 0x68($v1)
    MEM_B(0X68, ctx->r3) = ctx->r14;
    // 0x8000BA8C: lbu         $t7, 0x3D($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X3D);
    // 0x8000BA90: sh          $zero, 0x6C($v1)
    MEM_H(0X6C, ctx->r3) = 0;
    // 0x8000BA94: swc1        $f2, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f2.u32l;
    // 0x8000BA98: sh          $zero, 0x74($v1)
    MEM_H(0X74, ctx->r3) = 0;
    // 0x8000BA9C: swc1        $f2, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f2.u32l;
    // 0x8000BAA0: swc1        $f2, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f2.u32l;
    // 0x8000BAA4: swc1        $f2, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f2.u32l;
    // 0x8000BAA8: swc1        $f2, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f2.u32l;
    // 0x8000BAAC: swc1        $f2, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->f2.u32l;
    // 0x8000BAB0: swc1        $f2, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = ctx->f2.u32l;
    // 0x8000BAB4: sb          $zero, 0x48($v1)
    MEM_B(0X48, ctx->r3) = 0;
    // 0x8000BAB8: sb          $zero, 0x49($v1)
    MEM_B(0X49, ctx->r3) = 0;
    // 0x8000BABC: sb          $zero, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = 0;
    // 0x8000BAC0: sb          $t8, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r24;
    // 0x8000BAC4: sb          $t7, 0x69($v1)
    MEM_B(0X69, ctx->r3) = ctx->r15;
    // 0x8000BAC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000BACC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000BAD0: jr          $ra
    // 0x8000BAD4: nop

    return;
    // 0x8000BAD4: nop

;}
RECOMP_FUNC void FUN_8000bad8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BAD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000BAE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000BAE4: sb          $t6, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r14;
    // 0x8000BAE8: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
    // 0x8000BAEC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000BAF0: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8000BAF4: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000BAF8: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x8000BAFC: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000BB00: swc1        $f8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
    // 0x8000BB04: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x8000BB08: sh          $t7, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r15;
    // 0x8000BB0C: lh          $t8, 0xE($a1)
    ctx->r24 = MEM_H(ctx->r5, 0XE);
    // 0x8000BB10: sh          $t8, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r24;
    // 0x8000BB14: lh          $t9, 0x10($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X10);
    // 0x8000BB18: sh          $t9, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r25;
    // 0x8000BB1C: lw          $t0, 0x14($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X14);
    // 0x8000BB20: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
    // 0x8000BB24: lhu         $t1, 0x18($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X18);
    // 0x8000BB28: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8000BB2C: lhu         $t2, 0x20($a1)
    ctx->r10 = MEM_HU(ctx->r5, 0X20);
    // 0x8000BB30: sh          $t2, 0x2C($v1)
    MEM_H(0X2C, ctx->r3) = ctx->r10;
    // 0x8000BB34: lw          $t3, 0x1C($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X1C);
    // 0x8000BB38: sw          $t3, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r11;
    // 0x8000BB3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000BB40: jal         0x8000C3B0
    // 0x8000BB44: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_0;
    // 0x8000BB44: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8000BB48: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BB4C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8000BB50: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000BB54: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
    // 0x8000BB58: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x8000BB5C: sb          $zero, 0x3A($v1)
    MEM_B(0X3A, ctx->r3) = 0;
    // 0x8000BB60: lwc1        $f10, 0x34($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8000BB64: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8000BB68: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x8000BB6C: nop

    // 0x8000BB70: bc1tl       L_8000BB98
    if (c1cs) {
        // 0x8000BB74: lwc1        $f2, 0x30($a1)
        ctx->f2.u32l = MEM_W(ctx->r5, 0X30);
            goto L_8000BB98;
    }
    goto skip_0;
    // 0x8000BB74: lwc1        $f2, 0x30($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X30);
    skip_0:
    // 0x8000BB78: lwc1        $f16, 0x30($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X30);
    // 0x8000BB7C: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
    // 0x8000BB80: lwc1        $f18, 0x34($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8000BB84: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x8000BB88: lwc1        $f4, 0x38($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8000BB8C: b           L_8000BBD0
    // 0x8000BB90: swc1        $f4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f4.u32l;
        goto L_8000BBD0;
    // 0x8000BB90: swc1        $f4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f4.u32l;
    // 0x8000BB94: lwc1        $f2, 0x30($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X30);
L_8000BB98:
    // 0x8000BB98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000BB9C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8000BBA0: nop

    // 0x8000BBA4: bc1tl       L_8000BBC0
    if (c1cs) {
        // 0x8000BBA8: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8000BBC0;
    }
    goto skip_1;
    // 0x8000BBA8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_1:
    // 0x8000BBAC: swc1        $f2, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f2.u32l;
    // 0x8000BBB0: swc1        $f2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
    // 0x8000BBB4: b           L_8000BBD0
    // 0x8000BBB8: swc1        $f2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f2.u32l;
        goto L_8000BBD0;
    // 0x8000BBB8: swc1        $f2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f2.u32l;
    // 0x8000BBBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8000BBC0:
    // 0x8000BBC0: nop

    // 0x8000BBC4: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x8000BBC8: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x8000BBCC: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
L_8000BBD0:
    // 0x8000BBD0: sw          $zero, 0x40($v1)
    MEM_W(0X40, ctx->r3) = 0;
    // 0x8000BBD4: sb          $zero, 0x48($v1)
    MEM_B(0X48, ctx->r3) = 0;
    // 0x8000BBD8: sb          $zero, 0x49($v1)
    MEM_B(0X49, ctx->r3) = 0;
    // 0x8000BBDC: sb          $zero, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = 0;
    // 0x8000BBE0: sb          $t4, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r12;
    // 0x8000BBE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000BBE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000BBEC: jr          $ra
    // 0x8000BBF0: nop

    return;
    // 0x8000BBF0: nop

;}
RECOMP_FUNC void FUN_8000bbf4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BBF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BBF8: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x8000BBFC: sll         $v0, $a1, 6
    ctx->r2 = S32(ctx->r5 << 6);
    // 0x8000BC00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000BC04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000BC08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000BC0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000BC10: jal         0x8001F290
    // 0x8000BC14: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_0;
    // 0x8000BC14: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x8000BC18: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BC1C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8000BC20: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x8000BC24: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8000BC28: sw          $v0, 0x4280($v1)
    MEM_W(0X4280, ctx->r3) = ctx->r2;
    // 0x8000BC2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000BC30: jal         0x8001F290
    // 0x8000BC34: sw          $t7, 0x4284($v1)
    MEM_W(0X4284, ctx->r3) = ctx->r15;
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_1;
    // 0x8000BC34: sw          $t7, 0x4284($v1)
    MEM_W(0X4284, ctx->r3) = ctx->r15;
    after_1:
    // 0x8000BC38: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BC3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000BC40: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8000BC44: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x8000BC48: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8000BC4C: sw          $v0, 0x4288($v1)
    MEM_W(0X4288, ctx->r3) = ctx->r2;
    // 0x8000BC50: sw          $t9, 0x428C($v1)
    MEM_W(0X428C, ctx->r3) = ctx->r25;
    // 0x8000BC54: jr          $ra
    // 0x8000BC58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000BC58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000bc5c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000bc5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BC5C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8000BC60: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x8000BC64: sb          $v0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r2;
    // 0x8000BC68: sb          $v0, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r2;
    // 0x8000BC6C: sb          $v0, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r2;
    // 0x8000BC70: jr          $ra
    // 0x8000BC74: sb          $v0, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r2;
    return;
    // 0x8000BC74: sb          $v0, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r2;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000bc78(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000bc78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BC78: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8000BC7C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000BC80: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000BC84: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000BC88: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000BC8C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000BC90: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000BC94: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000BC98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000BC9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000BCA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000BCA4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8000BCA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000BCAC: beql        $v0, $zero, L_8000BCD0
    if (ctx->r2 == 0) {
        // 0x8000BCB0: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_8000BCD0;
    }
    goto skip_0;
    // 0x8000BCB0: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_0:
    // 0x8000BCB4: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8000BCB8: jal         0x8000522C
    // 0x8000BCBC: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_0;
    // 0x8000BCBC: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
    after_0:
    // 0x8000BCC0: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x8000BCC4: b           L_8000BCE4
    // 0x8000BCC8: lw          $t2, 0x24($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X24);
        goto L_8000BCE4;
    // 0x8000BCC8: lw          $t2, 0x24($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X24);
    // 0x8000BCCC: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_8000BCD0:
    // 0x8000BCD0: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8000BCD4: jal         0x8000522C
    // 0x8000BCD8: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_1;
    // 0x8000BCD8: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
    after_1:
    // 0x8000BCDC: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x8000BCE0: lw          $t2, 0x24($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X24);
L_8000BCE4:
    // 0x8000BCE4: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8000BCE8: addiu       $s1, $s1, -0x2A44
    ctx->r17 = ADD32(ctx->r17, -0X2A44);
    // 0x8000BCEC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000BCF0: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8000BCF4: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x8000BCF8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000BCFC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000BD00: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000BD04: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000BD08: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000BD0C: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8000BD10: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x8000BD14: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000BD18: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8000BD1C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000BD20: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000BD24: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000BD28: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8000BD2C: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8000BD30: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000BD34: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8000BD38: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000BD3C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000BD40: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000BD44: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8000BD48: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8000BD4C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000BD50: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000BD54: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000BD58: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000BD5C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000BD60: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8000BD64: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8000BD68: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000BD6C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8000BD70: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000BD74: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000BD78: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000BD7C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8000BD80: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8000BD84: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000BD88: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8000BD8C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000BD90: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000BD94: lhu         $t3, 0x2($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X2);
    // 0x8000BD98: lbu         $t4, 0x4($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X4);
    // 0x8000BD9C: addiu       $s2, $v0, 0xC
    ctx->r18 = ADD32(ctx->r2, 0XC);
    // 0x8000BDA0: blez        $t3, L_8000C380
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8000BDA4: sh          $zero, 0xBE($sp)
        MEM_H(0XBE, ctx->r29) = 0;
            goto L_8000C380;
    }
    // 0x8000BDA4: sh          $zero, 0xBE($sp)
    MEM_H(0XBE, ctx->r29) = 0;
    // 0x8000BDA8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000BDAC: and         $t7, $t2, $at
    ctx->r15 = ctx->r10 & ctx->r1;
    // 0x8000BDB0: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x8000BDB4: and         $t8, $t2, $at
    ctx->r24 = ctx->r10 & ctx->r1;
    // 0x8000BDB8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8000BDBC: addiu       $s0, $s0, -0x6D50
    ctx->r16 = ADD32(ctx->r16, -0X6D50);
    // 0x8000BDC0: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8000BDC4: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8000BDC8: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8000BDCC: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
L_8000BDD0:
    // 0x8000BDD0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8000BDD4: lbu         $t0, 0x5($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X5);
    // 0x8000BDD8: lbu         $t3, 0x6($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X6);
    // 0x8000BDDC: beq         $t9, $zero, L_8000BE04
    if (ctx->r25 == 0) {
        // 0x8000BDE0: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_8000BE04;
    }
    // 0x8000BDE0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8000BDE4: lh          $v0, 0x8($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X8);
    // 0x8000BDE8: addu        $fp, $v0, $t0
    ctx->r30 = ADD32(ctx->r2, ctx->r8);
    // 0x8000BDEC: negu        $fp, $fp
    ctx->r30 = SUB32(0, ctx->r30);
    // 0x8000BDF0: sll         $fp, $fp, 16
    ctx->r30 = S32(ctx->r30 << 16);
    // 0x8000BDF4: negu        $t6, $v0
    ctx->r14 = SUB32(0, ctx->r2);
    // 0x8000BDF8: sra         $fp, $fp, 16
    ctx->r30 = S32(SIGNED(ctx->r30) >> 16);
    // 0x8000BDFC: b           L_8000BE18
    // 0x8000BE00: sh          $t6, 0xC8($sp)
    MEM_H(0XC8, ctx->r29) = ctx->r14;
        goto L_8000BE18;
    // 0x8000BE00: sh          $t6, 0xC8($sp)
    MEM_H(0XC8, ctx->r29) = ctx->r14;
L_8000BE04:
    // 0x8000BE04: lh          $v0, 0x8($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X8);
    // 0x8000BE08: sll         $fp, $v0, 16
    ctx->r30 = S32(ctx->r2 << 16);
    // 0x8000BE0C: addu        $t7, $v0, $t0
    ctx->r15 = ADD32(ctx->r2, ctx->r8);
    // 0x8000BE10: sra         $fp, $fp, 16
    ctx->r30 = S32(SIGNED(ctx->r30) >> 16);
    // 0x8000BE14: sh          $t7, 0xC8($sp)
    MEM_H(0XC8, ctx->r29) = ctx->r15;
L_8000BE18:
    // 0x8000BE18: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x8000BE1C: or          $s7, $t0, $zero
    ctx->r23 = ctx->r8 | 0;
    // 0x8000BE20: sll         $s7, $s7, 22
    ctx->r23 = S32(ctx->r23 << 22);
    // 0x8000BE24: beq         $v1, $zero, L_8000BE44
    if (ctx->r3 == 0) {
        // 0x8000BE28: sra         $s7, $s7, 16
        ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
            goto L_8000BE44;
    }
    // 0x8000BE28: sra         $s7, $s7, 16
    ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8000BE2C: lh          $v0, 0xA($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XA);
    // 0x8000BE30: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x8000BE34: addu        $t8, $v0, $t3
    ctx->r24 = ADD32(ctx->r2, ctx->r11);
    // 0x8000BE38: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8000BE3C: b           L_8000BE60
    // 0x8000BE40: sh          $t8, 0xC4($sp)
    MEM_H(0XC4, ctx->r29) = ctx->r24;
        goto L_8000BE60;
    // 0x8000BE40: sh          $t8, 0xC4($sp)
    MEM_H(0XC4, ctx->r29) = ctx->r24;
L_8000BE44:
    // 0x8000BE44: lh          $v0, 0xA($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XA);
    // 0x8000BE48: addu        $t5, $v0, $t3
    ctx->r13 = ADD32(ctx->r2, ctx->r11);
    // 0x8000BE4C: negu        $t5, $t5
    ctx->r13 = SUB32(0, ctx->r13);
    // 0x8000BE50: sll         $t5, $t5, 16
    ctx->r13 = S32(ctx->r13 << 16);
    // 0x8000BE54: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x8000BE58: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8000BE5C: sh          $t9, 0xC4($sp)
    MEM_H(0XC4, ctx->r29) = ctx->r25;
L_8000BE60:
    // 0x8000BE60: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8000BE64: lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X4);
    // 0x8000BE68: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
    // 0x8000BE6C: beq         $t6, $zero, L_8000BE7C
    if (ctx->r14 == 0) {
        // 0x8000BE70: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_8000BE7C;
    }
    // 0x8000BE70: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8000BE74: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8000BE78: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8000BE7C:
    // 0x8000BE7C: beq         $v1, $zero, L_8000BE8C
    if (ctx->r3 == 0) {
        // 0x8000BE80: sll         $s3, $s3, 22
        ctx->r19 = S32(ctx->r19 << 22);
            goto L_8000BE8C;
    }
    // 0x8000BE80: sll         $s3, $s3, 22
    ctx->r19 = S32(ctx->r19 << 22);
    // 0x8000BE84: xori        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 ^ 0X2;
    // 0x8000BE88: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8000BE8C:
    // 0x8000BE8C: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8000BE90: beq         $t7, $zero, L_8000BEAC
    if (ctx->r15 == 0) {
        // 0x8000BE94: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8000BEAC;
    }
    // 0x8000BE94: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000BE98: or          $s6, $t0, $zero
    ctx->r22 = ctx->r8 | 0;
    // 0x8000BE9C: sll         $s6, $s6, 22
    ctx->r22 = S32(ctx->r22 << 22);
    // 0x8000BEA0: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    // 0x8000BEA4: b           L_8000BEAC
    // 0x8000BEA8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
        goto L_8000BEAC;
    // 0x8000BEA8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_8000BEAC:
    // 0x8000BEAC: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x8000BEB0: beq         $t8, $zero, L_8000BECC
    if (ctx->r24 == 0) {
        // 0x8000BEB4: sra         $s3, $s3, 16
        ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
            goto L_8000BECC;
    }
    // 0x8000BEB4: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8000BEB8: or          $s4, $t3, $zero
    ctx->r20 = ctx->r11 | 0;
    // 0x8000BEBC: sll         $s4, $s4, 22
    ctx->r20 = S32(ctx->r20 << 22);
    // 0x8000BEC0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000BEC4: b           L_8000BED0
    // 0x8000BEC8: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
        goto L_8000BED0;
    // 0x8000BEC8: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
L_8000BECC:
    // 0x8000BECC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8000BED0:
    // 0x8000BED0: beq         $t9, $zero, L_8000BEEC
    if (ctx->r25 == 0) {
        // 0x8000BED4: srl         $v0, $t0, 4
        ctx->r2 = S32(U32(ctx->r8) >> 4);
            goto L_8000BEEC;
    }
    // 0x8000BED4: srl         $v0, $t0, 4
    ctx->r2 = S32(U32(ctx->r8) >> 4);
    // 0x8000BED8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000BEDC: beq         $t9, $at, L_8000C090
    if (ctx->r25 == ctx->r1) {
        // 0x8000BEE0: srl         $v0, $t0, 3
        ctx->r2 = S32(U32(ctx->r8) >> 3);
            goto L_8000C090;
    }
    // 0x8000BEE0: srl         $v0, $t0, 3
    ctx->r2 = S32(U32(ctx->r8) >> 3);
    // 0x8000BEE4: b           L_8000C218
    // 0x8000BEE8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
        goto L_8000C218;
    // 0x8000BEE8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_8000BEEC:
    // 0x8000BEEC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000BEF0: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x8000BEF4: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000BEF8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000BEFC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8000BF00: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000BF04: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8000BF08: lui         $t7, 0x70D
    ctx->r15 = S32(0X70D << 16);
    // 0x8000BF0C: ori         $t7, $t7, 0xC370
    ctx->r15 = ctx->r15 | 0XC370;
    // 0x8000BF10: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000BF14: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000BF18: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x8000BF1C: mflo        $a2
    ctx->r6 = lo;
    // 0x8000BF20: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000BF24: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8000BF28: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000BF2C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000BF30: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8000BF34: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000BF38: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8000BF3C: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8000BF40: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000BF44: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000BF48: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000BF4C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000BF50: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8000BF54: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000BF58: srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    // 0x8000BF5C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8000BF60: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000BF64: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8000BF68: sltiu       $at, $a2, 0x7FF
    ctx->r1 = ctx->r6 < 0X7FF ? 1 : 0;
    // 0x8000BF6C: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8000BF70: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000BF74: beq         $at, $zero, L_8000BF84
    if (ctx->r1 == 0) {
        // 0x8000BF78: or          $t2, $v1, $zero
        ctx->r10 = ctx->r3 | 0;
            goto L_8000BF84;
    }
    // 0x8000BF78: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x8000BF7C: b           L_8000BF88
    // 0x8000BF80: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
        goto L_8000BF88;
    // 0x8000BF80: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
L_8000BF84:
    // 0x8000BF84: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
L_8000BF88:
    // 0x8000BF88: bne         $v0, $zero, L_8000BF98
    if (ctx->r2 != 0) {
        // 0x8000BF8C: lui         $at, 0x700
        ctx->r1 = S32(0X700 << 16);
            goto L_8000BF98;
    }
    // 0x8000BF8C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8000BF90: b           L_8000BF9C
    // 0x8000BF94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8000BF9C;
    // 0x8000BF94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8000BF98:
    // 0x8000BF98: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8000BF9C:
    // 0x8000BF9C: bne         $v0, $zero, L_8000BFAC
    if (ctx->r2 != 0) {
        // 0x8000BFA0: addiu       $t8, $a3, 0x7FF
        ctx->r24 = ADD32(ctx->r7, 0X7FF);
            goto L_8000BFAC;
    }
    // 0x8000BFA0: addiu       $t8, $a3, 0x7FF
    ctx->r24 = ADD32(ctx->r7, 0X7FF);
    // 0x8000BFA4: b           L_8000BFB0
    // 0x8000BFA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8000BFB0;
    // 0x8000BFA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8000BFAC:
    // 0x8000BFAC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8000BFB0:
    // 0x8000BFB0: divu        $zero, $t8, $a2
    lo = S32(U32(ctx->r24) / U32(ctx->r6)); hi = S32(U32(ctx->r24) % U32(ctx->r6));
    // 0x8000BFB4: mflo        $t9
    ctx->r25 = lo;
    // 0x8000BFB8: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8000BFBC: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x8000BFC0: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8000BFC4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8000BFC8: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8000BFCC: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8000BFD0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000BFD4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8000BFD8: srl         $t6, $t0, 1
    ctx->r14 = S32(U32(ctx->r8) >> 1);
    // 0x8000BFDC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000BFE0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000BFE4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000BFE8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000BFEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000BFF0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000BFF4: addiu       $t8, $t6, 0x7
    ctx->r24 = ADD32(ctx->r14, 0X7);
    // 0x8000BFF8: srl         $t7, $t8, 3
    ctx->r15 = S32(U32(ctx->r24) >> 3);
    // 0x8000BFFC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000C000: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8000C004: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x8000C008: sll         $t6, $t9, 9
    ctx->r14 = S32(ctx->r25 << 9);
    // 0x8000C00C: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8000C010: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8000C014: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000C018: lbu         $t7, 0x7($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X7);
    // 0x8000C01C: lui         $at, 0xC
    ctx->r1 = S32(0XC << 16);
    // 0x8000C020: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8000C024: andi        $t9, $t7, 0xF
    ctx->r25 = ctx->r15 & 0XF;
    // 0x8000C028: sll         $t6, $t9, 20
    ctx->r14 = S32(ctx->r25 << 20);
    // 0x8000C02C: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8000C030: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8000C034: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8000C038: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8000C03C: ori         $t6, $t9, 0x370
    ctx->r14 = ctx->r25 | 0X370;
    // 0x8000C040: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000C044: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000C048: addiu       $t9, $t0, -0x1
    ctx->r25 = ADD32(ctx->r8, -0X1);
    // 0x8000C04C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8000C050: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000C054: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000C058: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8000C05C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8000C060: addiu       $t9, $t3, -0x1
    ctx->r25 = ADD32(ctx->r11, -0X1);
    // 0x8000C064: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000C068: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8000C06C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8000C070: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8000C074: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8000C078: bne         $a2, $zero, L_8000C084
    if (ctx->r6 != 0) {
        // 0x8000C07C: nop
    
            goto L_8000C084;
    }
    // 0x8000C07C: nop

    // 0x8000C080: break       7
    do_break(2147532928);
L_8000C084:
    // 0x8000C084: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000C088: b           L_8000C214
    // 0x8000C08C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8000C214;
    // 0x8000C08C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8000C090:
    // 0x8000C090: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000C094: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x8000C098: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000C09C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000C0A0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8000C0A4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000C0A8: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8000C0AC: lui         $t7, 0x70D
    ctx->r15 = S32(0X70D << 16);
    // 0x8000C0B0: ori         $t7, $t7, 0xC370
    ctx->r15 = ctx->r15 | 0XC370;
    // 0x8000C0B4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000C0B8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000C0BC: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x8000C0C0: mflo        $a2
    ctx->r6 = lo;
    // 0x8000C0C4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000C0C8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8000C0CC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000C0D0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000C0D4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8000C0D8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000C0DC: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8000C0E0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000C0E4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000C0E8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000C0EC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000C0F0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000C0F4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8000C0F8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000C0FC: srl         $a2, $a2, 1
    ctx->r6 = S32(U32(ctx->r6) >> 1);
    // 0x8000C100: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8000C104: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000C108: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8000C10C: sltiu       $at, $a2, 0x7FF
    ctx->r1 = ctx->r6 < 0X7FF ? 1 : 0;
    // 0x8000C110: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8000C114: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000C118: beq         $at, $zero, L_8000C128
    if (ctx->r1 == 0) {
        // 0x8000C11C: or          $t4, $v1, $zero
        ctx->r12 = ctx->r3 | 0;
            goto L_8000C128;
    }
    // 0x8000C11C: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x8000C120: b           L_8000C12C
    // 0x8000C124: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
        goto L_8000C12C;
    // 0x8000C124: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
L_8000C128:
    // 0x8000C128: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
L_8000C12C:
    // 0x8000C12C: bne         $v0, $zero, L_8000C13C
    if (ctx->r2 != 0) {
        // 0x8000C130: or          $t2, $t0, $zero
        ctx->r10 = ctx->r8 | 0;
            goto L_8000C13C;
    }
    // 0x8000C130: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x8000C134: b           L_8000C140
    // 0x8000C138: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8000C140;
    // 0x8000C138: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8000C13C:
    // 0x8000C13C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8000C140:
    // 0x8000C140: bne         $v0, $zero, L_8000C150
    if (ctx->r2 != 0) {
        // 0x8000C144: addiu       $t8, $a3, 0x7FF
        ctx->r24 = ADD32(ctx->r7, 0X7FF);
            goto L_8000C150;
    }
    // 0x8000C144: addiu       $t8, $a3, 0x7FF
    ctx->r24 = ADD32(ctx->r7, 0X7FF);
    // 0x8000C148: b           L_8000C154
    // 0x8000C14C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8000C154;
    // 0x8000C14C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8000C150:
    // 0x8000C150: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8000C154:
    // 0x8000C154: divu        $zero, $t8, $a2
    lo = S32(U32(ctx->r24) / U32(ctx->r6)); hi = S32(U32(ctx->r24) % U32(ctx->r6));
    // 0x8000C158: mflo        $t9
    ctx->r25 = lo;
    // 0x8000C15C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8000C160: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x8000C164: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8000C168: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8000C16C: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8000C170: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8000C174: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x8000C178: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000C17C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8000C180: addiu       $t6, $t2, 0x7
    ctx->r14 = ADD32(ctx->r10, 0X7);
    // 0x8000C184: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000C188: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000C18C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000C190: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000C194: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000C198: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000C19C: srl         $t8, $t6, 3
    ctx->r24 = S32(U32(ctx->r14) >> 3);
    // 0x8000C1A0: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x8000C1A4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000C1A8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8000C1AC: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x8000C1B0: lui         $t8, 0xD
    ctx->r24 = S32(0XD << 16);
    // 0x8000C1B4: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8000C1B8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8000C1BC: ori         $t8, $t8, 0xC370
    ctx->r24 = ctx->r24 | 0XC370;
    // 0x8000C1C0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000C1C4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000C1C8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8000C1CC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000C1D0: addiu       $t6, $t0, -0x1
    ctx->r14 = ADD32(ctx->r8, -0X1);
    // 0x8000C1D4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8000C1D8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000C1DC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8000C1E0: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8000C1E4: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8000C1E8: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x8000C1EC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000C1F0: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8000C1F4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8000C1F8: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8000C1FC: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8000C200: bne         $a2, $zero, L_8000C20C
    if (ctx->r6 != 0) {
        // 0x8000C204: nop
    
            goto L_8000C20C;
    }
    // 0x8000C204: nop

    // 0x8000C208: break       7
    do_break(2147533320);
L_8000C20C:
    // 0x8000C20C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000C210: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8000C214:
    // 0x8000C214: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_8000C218:
    // 0x8000C218: lui         $t9, 0x100
    ctx->r25 = S32(0X100 << 16);
    // 0x8000C21C: ori         $t9, $t9, 0x4008
    ctx->r25 = ctx->r25 | 0X4008;
    // 0x8000C220: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000C224: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000C228: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000C22C: lw          $t7, 0x4290($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C230: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000C234: lw          $t6, 0x4290($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C238: sh          $fp, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r30;
    // 0x8000C23C: lw          $t8, 0x4290($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C240: sh          $t5, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r13;
    // 0x8000C244: lw          $t9, 0x4290($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C248: sh          $s5, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r21;
    // 0x8000C24C: lw          $t7, 0x4290($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C250: sh          $s6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r22;
    // 0x8000C254: lw          $t6, 0x4290($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C258: sh          $s3, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r19;
    // 0x8000C25C: sh          $t5, 0xC6($sp)
    MEM_H(0XC6, ctx->r29) = ctx->r13;
    // 0x8000C260: jal         0x8000BC5C
    // 0x8000C264: lw          $a0, 0x4290($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4290);
    LOOKUP_FUNC(0x8000BC5C)(rdram, ctx);
        goto after_2;
    // 0x8000C264: lw          $a0, 0x4290($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4290);
    after_2:
    // 0x8000C268: lw          $t8, 0x4290($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C26C: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x8000C270: sw          $t9, 0x4290($s0)
    MEM_W(0X4290, ctx->r16) = ctx->r25;
    // 0x8000C274: sh          $fp, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r30;
    // 0x8000C278: lw          $t8, 0x4290($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C27C: lh          $t6, 0xC4($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XC4);
    // 0x8000C280: sh          $t6, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r14;
    // 0x8000C284: lw          $t9, 0x4290($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C288: sh          $s5, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r21;
    // 0x8000C28C: lw          $t7, 0x4290($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C290: sh          $s6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r22;
    // 0x8000C294: lw          $t6, 0x4290($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C298: sh          $s4, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r20;
    // 0x8000C29C: jal         0x8000BC5C
    // 0x8000C2A0: lw          $a0, 0x4290($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4290);
    LOOKUP_FUNC(0x8000BC5C)(rdram, ctx);
        goto after_3;
    // 0x8000C2A0: lw          $a0, 0x4290($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4290);
    after_3:
    // 0x8000C2A4: lw          $t8, 0x4290($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C2A8: lh          $t7, 0xC8($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XC8);
    // 0x8000C2AC: lh          $t5, 0xC6($sp)
    ctx->r13 = MEM_H(ctx->r29, 0XC6);
    // 0x8000C2B0: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x8000C2B4: sw          $t9, 0x4290($s0)
    MEM_W(0X4290, ctx->r16) = ctx->r25;
    // 0x8000C2B8: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x8000C2BC: lw          $t8, 0x4290($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C2C0: sh          $t5, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r13;
    // 0x8000C2C4: lw          $t9, 0x4290($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C2C8: sh          $s5, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r21;
    // 0x8000C2CC: lw          $t7, 0x4290($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C2D0: sh          $s7, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r23;
    // 0x8000C2D4: lw          $t6, 0x4290($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C2D8: sh          $s3, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r19;
    // 0x8000C2DC: jal         0x8000BC5C
    // 0x8000C2E0: lw          $a0, 0x4290($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4290);
    LOOKUP_FUNC(0x8000BC5C)(rdram, ctx);
        goto after_4;
    // 0x8000C2E0: lw          $a0, 0x4290($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4290);
    after_4:
    // 0x8000C2E4: lw          $t8, 0x4290($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C2E8: lh          $t7, 0xC8($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XC8);
    // 0x8000C2EC: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x8000C2F0: sw          $t9, 0x4290($s0)
    MEM_W(0X4290, ctx->r16) = ctx->r25;
    // 0x8000C2F4: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x8000C2F8: lw          $t9, 0x4290($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C2FC: lh          $t8, 0xC4($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XC4);
    // 0x8000C300: sh          $t8, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r24;
    // 0x8000C304: lw          $t7, 0x4290($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C308: sh          $s5, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r21;
    // 0x8000C30C: lw          $t6, 0x4290($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C310: sh          $s7, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r23;
    // 0x8000C314: lw          $t8, 0x4290($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C318: sh          $s4, 0xA($t8)
    MEM_H(0XA, ctx->r24) = ctx->r20;
    // 0x8000C31C: jal         0x8000BC5C
    // 0x8000C320: lw          $a0, 0x4290($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4290);
    LOOKUP_FUNC(0x8000BC5C)(rdram, ctx);
        goto after_5;
    // 0x8000C320: lw          $a0, 0x4290($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4290);
    after_5:
    // 0x8000C324: lw          $t9, 0x4290($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4290);
    // 0x8000C328: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000C32C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8000C330: addiu       $t7, $t9, 0x10
    ctx->r15 = ADD32(ctx->r25, 0X10);
    // 0x8000C334: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000C338: sw          $t7, 0x4290($s0)
    MEM_W(0X4290, ctx->r16) = ctx->r15;
    // 0x8000C33C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8000C340: lui         $t9, 0x6
    ctx->r25 = S32(0X6 << 16);
    // 0x8000C344: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x8000C348: ori         $t8, $t8, 0x206
    ctx->r24 = ctx->r24 | 0X206;
    // 0x8000C34C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000C350: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000C354: lhu         $t7, 0xBE($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0XBE);
    // 0x8000C358: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8000C35C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8000C360: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x8000C364: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x8000C368: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x8000C36C: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000C370: sh          $t6, 0xBE($sp)
    MEM_H(0XBE, ctx->r29) = ctx->r14;
    // 0x8000C374: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x8000C378: bne         $at, $zero, L_8000BDD0
    if (ctx->r1 != 0) {
        // 0x8000C37C: sra         $s5, $s5, 16
        ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
            goto L_8000BDD0;
    }
    // 0x8000C37C: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
L_8000C380:
    // 0x8000C380: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C384: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000C388: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C38C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000C390: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000C394: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000C398: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C39C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000C3A0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8000C3A4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000C3A8: jr          $ra
    // 0x8000C3AC: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x8000C3AC: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000c3b0(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000c3b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C3B0: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8000C3B4: beql        $v0, $zero, L_8000C3C8
    if (ctx->r2 == 0) {
        // 0x8000C3B8: lw          $v1, 0x30($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X30);
            goto L_8000C3C8;
    }
    goto skip_0;
    // 0x8000C3B8: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
    skip_0:
    // 0x8000C3BC: b           L_8000C3C8
    // 0x8000C3C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8000C3C8;
    // 0x8000C3C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000C3C4: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
L_8000C3C8:
    // 0x8000C3C8: lw          $a0, 0x24($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X24);
    // 0x8000C3CC: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8000C3D0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000C3D4: sltiu       $at, $t7, 0x15
    ctx->r1 = ctx->r15 < 0X15 ? 1 : 0;
    // 0x8000C3D8: beq         $at, $zero, L_8000C49C
    if (ctx->r1 == 0) {
        // 0x8000C3DC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8000C49C;
    }
    // 0x8000C3DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000C3E0: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000C3E4: addu        $at, $at, $t7
    gpr jr_addend_8000C3EC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8000C3E8: lw          $t7, -0x38D0($at)
    ctx->r15 = ADD32(ctx->r1, -0X38D0);
    // 0x8000C3EC: jr          $t7
    // 0x8000C3F0: nop

    switch (jr_addend_8000C3EC >> 2) {
        case 0: goto L_8000C400; break;
        case 1: goto L_8000C434; break;
        case 2: goto L_8000C49C; break;
        case 3: goto L_8000C49C; break;
        case 4: goto L_8000C49C; break;
        case 5: goto L_8000C49C; break;
        case 6: goto L_8000C49C; break;
        case 7: goto L_8000C494; break;
        case 8: goto L_8000C49C; break;
        case 9: goto L_8000C49C; break;
        case 10: goto L_8000C49C; break;
        case 11: goto L_8000C49C; break;
        case 12: goto L_8000C49C; break;
        case 13: goto L_8000C440; break;
        case 14: goto L_8000C45C; break;
        case 15: goto L_8000C49C; break;
        case 16: goto L_8000C49C; break;
        case 17: goto L_8000C478; break;
        case 18: goto L_8000C40C; break;
        case 19: goto L_8000C3F4; break;
        case 20: goto L_8000C420; break;
        default: switch_error(__func__, 0x8000C3EC, 0x8004C730);
    }
    // 0x8000C3F0: nop

L_8000C3F4:
    // 0x8000C3F4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8000C3F8: jr          $ra
    // 0x8000C3FC: addiu       $v0, $v0, -0x52D8
    ctx->r2 = ADD32(ctx->r2, -0X52D8);
    return;
    // 0x8000C3FC: addiu       $v0, $v0, -0x52D8
    ctx->r2 = ADD32(ctx->r2, -0X52D8);
L_8000C400:
    // 0x8000C400: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8000C404: jr          $ra
    // 0x8000C408: addiu       $v0, $v0, -0x5168
    ctx->r2 = ADD32(ctx->r2, -0X5168);
    return;
    // 0x8000C408: addiu       $v0, $v0, -0x5168
    ctx->r2 = ADD32(ctx->r2, -0X5168);
L_8000C40C:
    // 0x8000C40C: ori         $t8, $a0, 0x400
    ctx->r24 = ctx->r4 | 0X400;
    // 0x8000C410: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8000C414: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x8000C418: jr          $ra
    // 0x8000C41C: addiu       $v0, $v0, -0x50C8
    ctx->r2 = ADD32(ctx->r2, -0X50C8);
    return;
    // 0x8000C41C: addiu       $v0, $v0, -0x50C8
    ctx->r2 = ADD32(ctx->r2, -0X50C8);
L_8000C420:
    // 0x8000C420: ori         $t9, $a0, 0x400
    ctx->r25 = ctx->r4 | 0X400;
    // 0x8000C424: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8000C428: sw          $t9, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r25;
    // 0x8000C42C: jr          $ra
    // 0x8000C430: addiu       $v0, $v0, -0x5070
    ctx->r2 = ADD32(ctx->r2, -0X5070);
    return;
    // 0x8000C430: addiu       $v0, $v0, -0x5070
    ctx->r2 = ADD32(ctx->r2, -0X5070);
L_8000C434:
    // 0x8000C434: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8000C438: jr          $ra
    // 0x8000C43C: addiu       $v0, $v0, -0x51F0
    ctx->r2 = ADD32(ctx->r2, -0X51F0);
    return;
    // 0x8000C43C: addiu       $v0, $v0, -0x51F0
    ctx->r2 = ADD32(ctx->r2, -0X51F0);
L_8000C440:
    // 0x8000C440: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8000C444: ori         $t0, $a0, 0x100
    ctx->r8 = ctx->r4 | 0X100;
    // 0x8000C448: addiu       $v0, $v0, -0x4CD0
    ctx->r2 = ADD32(ctx->r2, -0X4CD0);
    // 0x8000C44C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000C450: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
    // 0x8000C454: jr          $ra
    // 0x8000C458: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    return;
    // 0x8000C458: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_8000C45C:
    // 0x8000C45C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8000C460: ori         $t1, $a0, 0x100
    ctx->r9 = ctx->r4 | 0X100;
    // 0x8000C464: addiu       $v0, $v0, -0x4C78
    ctx->r2 = ADD32(ctx->r2, -0X4C78);
    // 0x8000C468: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000C46C: sw          $t1, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r9;
    // 0x8000C470: jr          $ra
    // 0x8000C474: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    return;
    // 0x8000C474: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_8000C478:
    // 0x8000C478: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8000C47C: ori         $t2, $a0, 0x100
    ctx->r10 = ctx->r4 | 0X100;
    // 0x8000C480: addiu       $v0, $v0, -0x4B60
    ctx->r2 = ADD32(ctx->r2, -0X4B60);
    // 0x8000C484: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000C488: sw          $t2, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r10;
    // 0x8000C48C: jr          $ra
    // 0x8000C490: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    return;
    // 0x8000C490: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_8000C494:
    // 0x8000C494: jr          $ra
    // 0x8000C498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000C498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C49C:
    // 0x8000C49C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000C4A0: jr          $ra
    // 0x8000C4A4: nop

    return;
    // 0x8000C4A4: nop

;}
RECOMP_FUNC void FUN_8000c4a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C4A8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000C4AC: and         $v0, $a1, $at
    ctx->r2 = ctx->r5 & ctx->r1;
    // 0x8000C4B0: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8000C4B4: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8000C4B8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8000C4BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000C4C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000C4C4: sltu        $at, $v0, $at
    ctx->r1 = ctx->r2 < ctx->r1 ? 1 : 0;
    // 0x8000C4C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000C4CC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8000C4D0: bne         $at, $zero, L_8000C514
    if (ctx->r1 != 0) {
        // 0x8000C4D4: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8000C514;
    }
    // 0x8000C4D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000C4D8: lui         $at, 0x5
    ctx->r1 = S32(0X5 << 16);
    // 0x8000C4DC: beq         $v0, $at, L_8000C610
    if (ctx->r2 == ctx->r1) {
        // 0x8000C4E0: lui         $at, 0x6
        ctx->r1 = S32(0X6 << 16);
            goto L_8000C610;
    }
    // 0x8000C4E0: lui         $at, 0x6
    ctx->r1 = S32(0X6 << 16);
    // 0x8000C4E4: beq         $v0, $at, L_8000C6BC
    if (ctx->r2 == ctx->r1) {
        // 0x8000C4E8: lui         $a3, 0x8009
        ctx->r7 = S32(0X8009 << 16);
            goto L_8000C6BC;
    }
    // 0x8000C4E8: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8000C4EC: lui         $at, 0x7
    ctx->r1 = S32(0X7 << 16);
    // 0x8000C4F0: beq         $v0, $at, L_8000C6E4
    if (ctx->r2 == ctx->r1) {
        // 0x8000C4F4: lui         $at, 0x8
        ctx->r1 = S32(0X8 << 16);
            goto L_8000C6E4;
    }
    // 0x8000C4F4: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8000C4F8: beq         $v0, $at, L_8000C70C
    if (ctx->r2 == ctx->r1) {
        // 0x8000C4FC: lui         $a3, 0x8009
        ctx->r7 = S32(0X8009 << 16);
            goto L_8000C70C;
    }
    // 0x8000C4FC: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8000C500: lui         $at, 0x9
    ctx->r1 = S32(0X9 << 16);
    // 0x8000C504: beq         $v0, $at, L_8000C734
    if (ctx->r2 == ctx->r1) {
        // 0x8000C508: nop
    
            goto L_8000C734;
    }
    // 0x8000C508: nop

    // 0x8000C50C: b           L_8000C758
    // 0x8000C510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000C758;
    // 0x8000C510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000C514:
    // 0x8000C514: beq         $v0, $zero, L_8000C550
    if (ctx->r2 == 0) {
        // 0x8000C518: addiu       $a0, $sp, 0x88
        ctx->r4 = ADD32(ctx->r29, 0X88);
            goto L_8000C550;
    }
    // 0x8000C518: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8000C51C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8000C520: beq         $v0, $at, L_8000C57C
    if (ctx->r2 == ctx->r1) {
        // 0x8000C524: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8000C57C;
    }
    // 0x8000C524: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000C528: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8000C52C: beq         $v0, $at, L_8000C598
    if (ctx->r2 == ctx->r1) {
        // 0x8000C530: lui         $a3, 0x8009
        ctx->r7 = S32(0X8009 << 16);
            goto L_8000C598;
    }
    // 0x8000C530: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8000C534: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x8000C538: beq         $v0, $at, L_8000C5C0
    if (ctx->r2 == ctx->r1) {
        // 0x8000C53C: lui         $at, 0x4
        ctx->r1 = S32(0X4 << 16);
            goto L_8000C5C0;
    }
    // 0x8000C53C: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8000C540: beq         $v0, $at, L_8000C5E8
    if (ctx->r2 == ctx->r1) {
        // 0x8000C544: lui         $a3, 0x8009
        ctx->r7 = S32(0X8009 << 16);
            goto L_8000C5E8;
    }
    // 0x8000C544: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8000C548: b           L_8000C758
    // 0x8000C54C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000C758;
    // 0x8000C54C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000C550:
    // 0x8000C550: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8000C554: addiu       $a3, $a3, -0x2A44
    ctx->r7 = ADD32(ctx->r7, -0X2A44);
    // 0x8000C558: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000C55C: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8000C560: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x8000C564: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8000C568: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8000C56C: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x8000C570: addu        $t8, $s1, $t0
    ctx->r24 = ADD32(ctx->r17, ctx->r8);
    // 0x8000C574: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000C578: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8000C57C:
    // 0x8000C57C: jal         0x8000B1E8
    // 0x8000C580: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8000B1E8)(rdram, ctx);
        goto after_0;
    // 0x8000C580: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8000C584: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8000C588: jal         0x8000B5AC
    // 0x8000C58C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8000B5AC)(rdram, ctx);
        goto after_1;
    // 0x8000C58C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8000C590: b           L_8000C758
    // 0x8000C594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000C758;
    // 0x8000C594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000C598:
    // 0x8000C598: addiu       $a3, $a3, -0x2A44
    ctx->r7 = ADD32(ctx->r7, -0X2A44);
    // 0x8000C59C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000C5A0: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8000C5A4: lui         $t1, 0xDA38
    ctx->r9 = S32(0XDA38 << 16);
    // 0x8000C5A8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000C5AC: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8000C5B0: ori         $t1, $t1, 0x3
    ctx->r9 = ctx->r9 | 0X3;
    // 0x8000C5B4: addu        $t2, $s1, $t0
    ctx->r10 = ADD32(ctx->r17, ctx->r8);
    // 0x8000C5B8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8000C5BC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_8000C5C0:
    // 0x8000C5C0: jal         0x8000B1E8
    // 0x8000C5C4: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    LOOKUP_FUNC(0x8000B1E8)(rdram, ctx);
        goto after_2;
    // 0x8000C5C4: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_2:
    // 0x8000C5C8: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8000C5CC: jal         0x8000B578
    // 0x8000C5D0: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(0x8000B578)(rdram, ctx);
        goto after_3;
    // 0x8000C5D0: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    after_3:
    // 0x8000C5D4: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8000C5D8: jal         0x8000B5AC
    // 0x8000C5DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8000B5AC)(rdram, ctx);
        goto after_4;
    // 0x8000C5DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8000C5E0: b           L_8000C758
    // 0x8000C5E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000C758;
    // 0x8000C5E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000C5E8:
    // 0x8000C5E8: addiu       $a3, $a3, -0x2A44
    ctx->r7 = ADD32(ctx->r7, -0X2A44);
    // 0x8000C5EC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000C5F0: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8000C5F4: lui         $t4, 0xDA38
    ctx->r12 = S32(0XDA38 << 16);
    // 0x8000C5F8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8000C5FC: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8000C600: ori         $t4, $t4, 0x3
    ctx->r12 = ctx->r12 | 0X3;
    // 0x8000C604: addu        $t5, $s1, $t0
    ctx->r13 = ADD32(ctx->r17, ctx->r8);
    // 0x8000C608: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8000C60C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8000C610:
    // 0x8000C610: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8000C614: addiu       $a3, $a3, -0x2A44
    ctx->r7 = ADD32(ctx->r7, -0X2A44);
    // 0x8000C618: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000C61C: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8000C620: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x8000C624: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8000C628: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8000C62C: ori         $t7, $t7, 0x18
    ctx->r15 = ctx->r15 | 0X18;
    // 0x8000C630: addu        $t8, $s1, $t0
    ctx->r24 = ADD32(ctx->r17, ctx->r8);
    // 0x8000C634: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000C638: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000C63C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000C640: lui         $t1, 0xDB06
    ctx->r9 = S32(0XDB06 << 16);
    // 0x8000C644: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x8000C648: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000C64C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8000C650: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8000C654: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x8000C658: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8000C65C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000C660: lw          $t3, 0x1C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C);
    // 0x8000C664: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x8000C668: jal         0x8000B1E8
    // 0x8000C66C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    LOOKUP_FUNC(0x8000B1E8)(rdram, ctx);
        goto after_5;
    // 0x8000C66C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    after_5:
    // 0x8000C670: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8000C674: jal         0x8000B578
    // 0x8000C678: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(0x8000B578)(rdram, ctx);
        goto after_6;
    // 0x8000C678: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    after_6:
    // 0x8000C67C: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x8000C680: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8000C684: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8000C688: beq         $v0, $zero, L_8000C6AC
    if (ctx->r2 == 0) {
        // 0x8000C68C: nop
    
            goto L_8000C6AC;
    }
    // 0x8000C68C: nop

    // 0x8000C690: swc1        $f4, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f4.u32l;
    // 0x8000C694: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    // 0x8000C698: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8000C69C: swc1        $f6, 0x9C($t5)
    MEM_W(0X9C, ctx->r13) = ctx->f6.u32l;
    // 0x8000C6A0: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x8000C6A4: lwc1        $f8, 0xC0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8000C6A8: swc1        $f8, 0xA0($t6)
    MEM_W(0XA0, ctx->r14) = ctx->f8.u32l;
L_8000C6AC:
    // 0x8000C6AC: jal         0x8000B5AC
    // 0x8000C6B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8000B5AC)(rdram, ctx);
        goto after_7;
    // 0x8000C6B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x8000C6B4: b           L_8000C758
    // 0x8000C6B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000C758;
    // 0x8000C6B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000C6BC:
    // 0x8000C6BC: addiu       $a3, $a3, -0x2A44
    ctx->r7 = ADD32(ctx->r7, -0X2A44);
    // 0x8000C6C0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000C6C4: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8000C6C8: lui         $t8, 0xDA38
    ctx->r24 = S32(0XDA38 << 16);
    // 0x8000C6CC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8000C6D0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8000C6D4: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x8000C6D8: addu        $t9, $s1, $t0
    ctx->r25 = ADD32(ctx->r17, ctx->r8);
    // 0x8000C6DC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000C6E0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8000C6E4:
    // 0x8000C6E4: jal         0x8000B83C
    // 0x8000C6E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8000B83C)(rdram, ctx);
        goto after_8;
    // 0x8000C6E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8000C6EC: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8000C6F0: jal         0x8000B1E8
    // 0x8000C6F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8000B1E8)(rdram, ctx);
        goto after_9;
    // 0x8000C6F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x8000C6F8: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8000C6FC: jal         0x8000B5AC
    // 0x8000C700: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8000B5AC)(rdram, ctx);
        goto after_10;
    // 0x8000C700: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x8000C704: b           L_8000C758
    // 0x8000C708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000C758;
    // 0x8000C708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000C70C:
    // 0x8000C70C: addiu       $a3, $a3, -0x2A44
    ctx->r7 = ADD32(ctx->r7, -0X2A44);
    // 0x8000C710: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000C714: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8000C718: lui         $t2, 0xDA38
    ctx->r10 = S32(0XDA38 << 16);
    // 0x8000C71C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8000C720: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x8000C724: ori         $t2, $t2, 0x3
    ctx->r10 = ctx->r10 | 0X3;
    // 0x8000C728: addu        $t3, $s1, $t0
    ctx->r11 = ADD32(ctx->r17, ctx->r8);
    // 0x8000C72C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8000C730: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_8000C734:
    // 0x8000C734: jal         0x8000B8F0
    // 0x8000C738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8000B8F0)(rdram, ctx);
        goto after_11;
    // 0x8000C738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8000C73C: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8000C740: jal         0x8000B1E8
    // 0x8000C744: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8000B1E8)(rdram, ctx);
        goto after_12;
    // 0x8000C744: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x8000C748: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8000C74C: jal         0x8000B5AC
    // 0x8000C750: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x8000B5AC)(rdram, ctx);
        goto after_13;
    // 0x8000C750: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_13:
    // 0x8000C754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000C758:
    // 0x8000C758: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000C75C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000C760: jr          $ra
    // 0x8000C764: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x8000C764: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000c768(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000c768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C768: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8000C76C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8000C770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C774: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x8000C778: addiu       $t7, $t7, 0x3750
    ctx->r15 = ADD32(ctx->r15, 0X3750);
    // 0x8000C77C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8000C780: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8000C784: addiu       $t6, $sp, 0xB8
    ctx->r14 = ADD32(ctx->r29, 0XB8);
    // 0x8000C788: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8000C78C: addiu       $t7, $t7, 0x3758
    ctx->r15 = ADD32(ctx->r15, 0X3758);
    // 0x8000C790: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8000C794: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8000C798: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8000C79C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8000C7A0: addiu       $t6, $sp, 0xB0
    ctx->r14 = ADD32(ctx->r29, 0XB0);
    // 0x8000C7A4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8000C7A8: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8000C7AC: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
    // 0x8000C7B0: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x8000C7B4: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    // 0x8000C7B8: jal         0x8000671C
    // 0x8000C7BC: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    LOOKUP_FUNC(0x8000671C)(rdram, ctx);
        goto after_0;
    // 0x8000C7BC: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    after_0:
    // 0x8000C7C0: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x8000C7C4: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x8000C7C8: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x8000C7CC: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x8000C7D0: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x8000C7D4: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8000C7D8: beq         $v1, $zero, L_8000C7E8
    if (ctx->r3 == 0) {
        // 0x8000C7DC: sw          $v0, 0x1C($t2)
        MEM_W(0X1C, ctx->r10) = ctx->r2;
            goto L_8000C7E8;
    }
    // 0x8000C7DC: sw          $v0, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r2;
    // 0x8000C7E0: b           L_8000C7EC
    // 0x8000C7E4: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
        goto L_8000C7EC;
    // 0x8000C7E4: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
L_8000C7E8:
    // 0x8000C7E8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
L_8000C7EC:
    // 0x8000C7EC: beql        $v1, $zero, L_8000C8AC
    if (ctx->r3 == 0) {
        // 0x8000C7F0: lw          $t9, 0x40($t3)
        ctx->r25 = MEM_W(ctx->r11, 0X40);
            goto L_8000C8AC;
    }
    goto skip_0;
    // 0x8000C7F0: lw          $t9, 0x40($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X40);
    skip_0:
    // 0x8000C7F4: lhu         $t6, 0x58($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X58);
    // 0x8000C7F8: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8000C7FC: addiu       $a3, $a3, -0x2A44
    ctx->r7 = ADD32(ctx->r7, -0X2A44);
    // 0x8000C800: beql        $t6, $zero, L_8000C874
    if (ctx->r14 == 0) {
        // 0x8000C804: lw          $t8, 0x44($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X44);
            goto L_8000C874;
    }
    goto skip_1;
    // 0x8000C804: lw          $t8, 0x44($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X44);
    skip_1:
    // 0x8000C808: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000C80C: lui         $t8, 0xDB06
    ctx->r24 = S32(0XDB06 << 16);
    // 0x8000C810: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x8000C814: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000C818: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8000C81C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000C820: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    // 0x8000C824: lhu         $a0, 0x58($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X58);
    // 0x8000C828: sw          $t5, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r13;
    // 0x8000C82C: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
    // 0x8000C830: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    // 0x8000C834: sw          $t0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r8;
    // 0x8000C838: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8000C83C: jal         0x80005204
    // 0x8000C840: sw          $v1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_1;
    // 0x8000C840: sw          $v1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r3;
    after_1:
    // 0x8000C844: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x8000C848: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C84C: addu        $t6, $v0, $at
    ctx->r14 = ADD32(ctx->r2, ctx->r1);
    // 0x8000C850: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x8000C854: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x8000C858: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x8000C85C: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x8000C860: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8000C864: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8000C868: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x8000C86C: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x8000C870: lw          $t8, 0x44($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X44);
L_8000C874:
    // 0x8000C874: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8000C878: addiu       $a3, $a3, -0x2A44
    ctx->r7 = ADD32(ctx->r7, -0X2A44);
    // 0x8000C87C: beql        $t8, $zero, L_8000C8AC
    if (ctx->r24 == 0) {
        // 0x8000C880: lw          $t9, 0x40($t3)
        ctx->r25 = MEM_W(ctx->r11, 0X40);
            goto L_8000C8AC;
    }
    goto skip_2;
    // 0x8000C880: lw          $t9, 0x40($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X40);
    skip_2:
    // 0x8000C884: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000C888: lui         $t6, 0xDB06
    ctx->r14 = S32(0XDB06 << 16);
    // 0x8000C88C: ori         $t6, $t6, 0x28
    ctx->r14 = ctx->r14 | 0X28;
    // 0x8000C890: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000C894: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8000C898: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000C89C: lw          $t7, 0x2C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X2C);
    // 0x8000C8A0: lw          $t8, 0x44($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X44);
    // 0x8000C8A4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000C8A8: lw          $t9, 0x40($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X40);
L_8000C8AC:
    // 0x8000C8AC: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8000C8B0: addiu       $a3, $a3, -0x2A44
    ctx->r7 = ADD32(ctx->r7, -0X2A44);
    // 0x8000C8B4: beql        $t9, $zero, L_8000C8E0
    if (ctx->r25 == 0) {
        // 0x8000C8B8: lw          $v1, 0x0($a3)
        ctx->r3 = MEM_W(ctx->r7, 0X0);
            goto L_8000C8E0;
    }
    goto skip_3;
    // 0x8000C8B8: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    skip_3:
    // 0x8000C8BC: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000C8C0: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x8000C8C4: ori         $t7, $t7, 0x24
    ctx->r15 = ctx->r15 | 0X24;
    // 0x8000C8C8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000C8CC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8000C8D0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000C8D4: lw          $t8, 0x40($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X40);
    // 0x8000C8D8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000C8DC: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
L_8000C8E0:
    // 0x8000C8E0: lui         $t6, 0xDB06
    ctx->r14 = S32(0XDB06 << 16);
    // 0x8000C8E4: ori         $t6, $t6, 0xC
    ctx->r14 = ctx->r14 | 0XC;
    // 0x8000C8E8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000C8EC: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8000C8F0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000C8F4: lhu         $a0, 0x0($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X0);
    // 0x8000C8F8: sw          $t5, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r13;
    // 0x8000C8FC: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
    // 0x8000C900: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    // 0x8000C904: sw          $t0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r8;
    // 0x8000C908: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8000C90C: jal         0x80005204
    // 0x8000C910: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_2;
    // 0x8000C910: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8000C914: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8000C918: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C91C: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x8000C920: addu        $t7, $v0, $at
    ctx->r15 = ADD32(ctx->r2, ctx->r1);
    // 0x8000C924: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8000C928: addiu       $a3, $a3, -0x2A44
    ctx->r7 = ADD32(ctx->r7, -0X2A44);
    // 0x8000C92C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8000C930: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000C934: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x8000C938: ori         $t9, $t9, 0x34
    ctx->r25 = ctx->r25 | 0X34;
    // 0x8000C93C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000C940: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8000C944: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000C948: lhu         $a0, 0x2C($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X2C);
    // 0x8000C94C: jal         0x80005204
    // 0x8000C950: sw          $v1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_3;
    // 0x8000C950: sw          $v1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r3;
    after_3:
    // 0x8000C954: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8000C958: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x8000C95C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C960: addu        $t6, $v0, $at
    ctx->r14 = ADD32(ctx->r2, ctx->r1);
    // 0x8000C964: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x8000C968: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x8000C96C: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x8000C970: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8000C974: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8000C978: lw          $v1, 0x30($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X30);
    // 0x8000C97C: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8000C980: addiu       $a3, $a3, -0x2A44
    ctx->r7 = ADD32(ctx->r7, -0X2A44);
    // 0x8000C984: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8000C988: bltz        $t7, L_8000C9A8
    if (SIGNED(ctx->r15) < 0) {
        // 0x8000C98C: lui         $a1, 0x8009
        ctx->r5 = S32(0X8009 << 16);
            goto L_8000C9A8;
    }
    // 0x8000C98C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8000C990: addiu       $a1, $a1, -0x6D50
    ctx->r5 = ADD32(ctx->r5, -0X6D50);
    // 0x8000C994: lw          $t8, 0x4298($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4298);
    // 0x8000C998: lui         $at, 0x8FFF
    ctx->r1 = S32(0X8FFF << 16);
    // 0x8000C99C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000C9A0: and         $t9, $v1, $at
    ctx->r25 = ctx->r3 & ctx->r1;
    // 0x8000C9A4: beq         $t8, $t9, L_8000CB10
    if (ctx->r24 == ctx->r25) {
        // 0x8000C9A8: lui         $at, 0x8FFF
        ctx->r1 = S32(0X8FFF << 16);
            goto L_8000CB10;
    }
L_8000C9A8:
    // 0x8000C9A8: lui         $at, 0x8FFF
    ctx->r1 = S32(0X8FFF << 16);
    // 0x8000C9AC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000C9B0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8000C9B4: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8000C9B8: beq         $v0, $zero, L_8000CAF4
    if (ctx->r2 == 0) {
        // 0x8000C9BC: addiu       $a1, $a1, -0x6D50
        ctx->r5 = ADD32(ctx->r5, -0X6D50);
            goto L_8000CAF4;
    }
    // 0x8000C9BC: addiu       $a1, $a1, -0x6D50
    ctx->r5 = ADD32(ctx->r5, -0X6D50);
    // 0x8000C9C0: sw          $v0, 0x4298($a1)
    MEM_W(0X4298, ctx->r5) = ctx->r2;
    // 0x8000C9C4: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x8000C9C8: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x8000C9CC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000C9D0: bgezl       $t7, L_8000CAD8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8000C9D4: lw          $v1, 0x0($a3)
        ctx->r3 = MEM_W(ctx->r7, 0X0);
            goto L_8000CAD8;
    }
    goto skip_4;
    // 0x8000C9D4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    skip_4:
    // 0x8000C9D8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8000C9DC: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x8000C9E0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8000C9E4: bnel        $t8, $t6, L_8000C9F8
    if (ctx->r24 != ctx->r14) {
        // 0x8000C9E8: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8000C9F8;
    }
    goto skip_5;
    // 0x8000C9E8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    skip_5:
    // 0x8000C9EC: beql        $t9, $t7, L_8000CB2C
    if (ctx->r25 == ctx->r15) {
        // 0x8000C9F0: lw          $a0, 0x24($t3)
        ctx->r4 = MEM_W(ctx->r11, 0X24);
            goto L_8000CB2C;
    }
    goto skip_6;
    // 0x8000C9F0: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    skip_6:
    // 0x8000C9F4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8000C9F8:
    // 0x8000C9F8: lui         $t2, 0xDE01
    ctx->r10 = S32(0XDE01 << 16);
L_8000C9FC:
    // 0x8000C9FC: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
L_8000CA00:
    // 0x8000CA00: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8000CA04: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8000CA08: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8000CA0C: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8000CA10: lw          $v0, 0x4298($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4298);
    // 0x8000CA14: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8000CA18: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000CA1C: bne         $t7, $t8, L_8000CA30
    if (ctx->r15 != ctx->r24) {
        // 0x8000CA20: nop
    
            goto L_8000CA30;
    }
    // 0x8000CA20: nop

    // 0x8000CA24: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8000CA28: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x8000CA2C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
L_8000CA30:
    // 0x8000CA30: beq         $a2, $zero, L_8000CA58
    if (ctx->r6 == 0) {
        // 0x8000CA34: lw          $v1, 0x0($a3)
        ctx->r3 = MEM_W(ctx->r7, 0X0);
            goto L_8000CA58;
    }
    // 0x8000CA34: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CA38: bne         $a2, $v0, L_8000CA58
    if (ctx->r6 != ctx->r2) {
        // 0x8000CA3C: nop
    
            goto L_8000CA58;
    }
    // 0x8000CA3C: nop

    // 0x8000CA40: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8000CA44: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x8000CA48: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x8000CA4C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8000CA50: lw          $v0, 0x4298($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4298);
    // 0x8000CA54: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
L_8000CA58:
    // 0x8000CA58: beql        $t5, $zero, L_8000CAA0
    if (ctx->r13 == 0) {
        // 0x8000CA5C: addiu       $t6, $v1, 0x8
        ctx->r14 = ADD32(ctx->r3, 0X8);
            goto L_8000CAA0;
    }
    goto skip_7;
    // 0x8000CA5C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    skip_7:
    // 0x8000CA60: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8000CA64: bnel        $t4, $t6, L_8000CAA0
    if (ctx->r12 != ctx->r14) {
        // 0x8000CA68: addiu       $t6, $v1, 0x8
        ctx->r14 = ADD32(ctx->r3, 0X8);
            goto L_8000CAA0;
    }
    goto skip_8;
    // 0x8000CA68: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    skip_8:
    // 0x8000CA6C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8000CA70: sltu        $at, $a0, $t1
    ctx->r1 = ctx->r4 < ctx->r9 ? 1 : 0;
    // 0x8000CA74: bne         $at, $zero, L_8000CA9C
    if (ctx->r1 != 0) {
        // 0x8000CA78: sltu        $at, $a0, $a2
        ctx->r1 = ctx->r4 < ctx->r6 ? 1 : 0;
            goto L_8000CA9C;
    }
    // 0x8000CA78: sltu        $at, $a0, $a2
    ctx->r1 = ctx->r4 < ctx->r6 ? 1 : 0;
    // 0x8000CA7C: beql        $at, $zero, L_8000CAA0
    if (ctx->r1 == 0) {
        // 0x8000CA80: addiu       $t6, $v1, 0x8
        ctx->r14 = ADD32(ctx->r3, 0X8);
            goto L_8000CAA0;
    }
    goto skip_9;
    // 0x8000CA80: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    skip_9:
    // 0x8000CA84: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8000CA88: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x8000CA8C: subu        $t9, $t8, $t1
    ctx->r25 = SUB32(ctx->r24, ctx->r9);
    // 0x8000CA90: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000CA94: lw          $v0, 0x4298($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4298);
    // 0x8000CA98: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
L_8000CA9C:
    // 0x8000CA9C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
L_8000CAA0:
    // 0x8000CAA0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8000CAA4: sw          $t7, 0x4298($a1)
    MEM_W(0X4298, ctx->r5) = ctx->r15;
    // 0x8000CAA8: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8000CAAC: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8000CAB0: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x8000CAB4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8000CAB8: lw          $t7, 0x4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4);
    // 0x8000CABC: bne         $t8, $t6, L_8000C9FC
    if (ctx->r24 != ctx->r14) {
        // 0x8000CAC0: lw          $t9, 0xBC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XBC);
            goto L_8000C9FC;
    }
    // 0x8000CAC0: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x8000CAC4: bnel        $t9, $t7, L_8000CA00
    if (ctx->r25 != ctx->r15) {
        // 0x8000CAC8: lw          $t8, 0x0($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X0);
            goto L_8000CA00;
    }
    goto skip_10;
    // 0x8000CAC8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    skip_10:
    // 0x8000CACC: b           L_8000CB2C
    // 0x8000CAD0: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
        goto L_8000CB2C;
    // 0x8000CAD0: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x8000CAD4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
L_8000CAD8:
    // 0x8000CAD8: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x8000CADC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000CAE0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8000CAE4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000CAE8: lw          $t6, 0x4298($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4298);
    // 0x8000CAEC: b           L_8000CB28
    // 0x8000CAF0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
        goto L_8000CB28;
    // 0x8000CAF0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_8000CAF4:
    // 0x8000CAF4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CAF8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8000CAFC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000CB00: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8000CB04: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000CB08: b           L_8000CB28
    // 0x8000CB0C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_8000CB28;
    // 0x8000CB0C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8000CB10:
    // 0x8000CB10: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CB14: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8000CB18: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000CB1C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8000CB20: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000CB24: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_8000CB28:
    // 0x8000CB28: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
L_8000CB2C:
    // 0x8000CB2C: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x8000CB30: andi        $v0, $a0, 0x4600
    ctx->r2 = ctx->r4 & 0X4600;
    // 0x8000CB34: beq         $v0, $at, L_8000CB54
    if (ctx->r2 == ctx->r1) {
        // 0x8000CB38: addiu       $at, $zero, 0x400
        ctx->r1 = ADD32(0, 0X400);
            goto L_8000CB54;
    }
    // 0x8000CB38: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x8000CB3C: beq         $v0, $at, L_8000CBA0
    if (ctx->r2 == ctx->r1) {
        // 0x8000CB40: addiu       $at, $zero, 0x4000
        ctx->r1 = ADD32(0, 0X4000);
            goto L_8000CBA0;
    }
    // 0x8000CB40: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x8000CB44: beql        $v0, $at, L_8000CD64
    if (ctx->r2 == ctx->r1) {
        // 0x8000CB48: lw          $v1, 0x0($a3)
        ctx->r3 = MEM_W(ctx->r7, 0X0);
            goto L_8000CD64;
    }
    goto skip_11;
    // 0x8000CB48: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    skip_11:
    // 0x8000CB4C: b           L_8000CDA0
    // 0x8000CB50: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
        goto L_8000CDA0;
    // 0x8000CB50: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
L_8000CB54:
    // 0x8000CB54: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CB58: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x8000CB5C: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x8000CB60: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000CB64: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8000CB68: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000CB6C: lbu         $t8, 0x4C($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X4C);
    // 0x8000CB70: lbu         $t6, 0x4F($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X4F);
    // 0x8000CB74: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x8000CB78: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8000CB7C: lbu         $t6, 0x4D($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X4D);
    // 0x8000CB80: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x8000CB84: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8000CB88: lbu         $t7, 0x4E($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X4E);
    // 0x8000CB8C: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x8000CB90: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8000CB94: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000CB98: b           L_8000CDA0
    // 0x8000CB9C: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
        goto L_8000CDA0;
    // 0x8000CB9C: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
L_8000CBA0:
    // 0x8000CBA0: lbu         $t7, 0x4F($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X4F);
    // 0x8000CBA4: slti        $at, $t7, 0x64
    ctx->r1 = SIGNED(ctx->r15) < 0X64 ? 1 : 0;
    // 0x8000CBA8: bnel        $at, $zero, L_8000CC60
    if (ctx->r1 != 0) {
        // 0x8000CBAC: lw          $v1, 0x0($a3)
        ctx->r3 = MEM_W(ctx->r7, 0X0);
            goto L_8000CC60;
    }
    goto skip_12;
    // 0x8000CBAC: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    skip_12:
    // 0x8000CBB0: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CBB4: lui         $t9, 0xDB08
    ctx->r25 = S32(0XDB08 << 16);
    // 0x8000CBB8: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x8000CBBC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000CBC0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8000CBC4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000CBC8: lbu         $v0, 0x4F($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X4F);
    // 0x8000CBCC: lui         $t8, 0xFFFE
    ctx->r24 = S32(0XFFFE << 16);
    // 0x8000CBD0: ori         $t8, $t8, 0xD400
    ctx->r24 = ctx->r24 | 0XD400;
    // 0x8000CBD4: subu        $a1, $t6, $v0
    ctx->r5 = SUB32(ctx->r14, ctx->r2);
    // 0x8000CBD8: sll         $t7, $v0, 8
    ctx->r15 = S32(ctx->r2 << 8);
    // 0x8000CBDC: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x8000CBE0: div         $zero, $t9, $a1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r5)));
    // 0x8000CBE4: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8000CBE8: ori         $t7, $t7, 0xF400
    ctx->r15 = ctx->r15 | 0XF400;
    // 0x8000CBEC: mflo        $t6
    ctx->r14 = lo;
    // 0x8000CBF0: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x8000CBF4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8000CBF8: div         $zero, $t7, $a1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r5)));
    // 0x8000CBFC: bne         $a1, $zero, L_8000CC08
    if (ctx->r5 != 0) {
        // 0x8000CC00: nop
    
            goto L_8000CC08;
    }
    // 0x8000CC00: nop

    // 0x8000CC04: break       7
    do_break(2147535876);
L_8000CC08:
    // 0x8000CC08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CC0C: bne         $a1, $at, L_8000CC20
    if (ctx->r5 != ctx->r1) {
        // 0x8000CC10: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000CC20;
    }
    // 0x8000CC10: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000CC14: bne         $t9, $at, L_8000CC20
    if (ctx->r25 != ctx->r1) {
        // 0x8000CC18: nop
    
            goto L_8000CC20;
    }
    // 0x8000CC18: nop

    // 0x8000CC1C: break       6
    do_break(2147535900);
L_8000CC20:
    // 0x8000CC20: mflo        $t9
    ctx->r25 = lo;
    // 0x8000CC24: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8000CC28: bne         $a1, $zero, L_8000CC34
    if (ctx->r5 != 0) {
        // 0x8000CC2C: nop
    
            goto L_8000CC34;
    }
    // 0x8000CC2C: nop

    // 0x8000CC30: break       7
    do_break(2147535920);
L_8000CC34:
    // 0x8000CC34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CC38: bne         $a1, $at, L_8000CC4C
    if (ctx->r5 != ctx->r1) {
        // 0x8000CC3C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000CC4C;
    }
    // 0x8000CC3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000CC40: bne         $t7, $at, L_8000CC4C
    if (ctx->r15 != ctx->r1) {
        // 0x8000CC44: nop
    
            goto L_8000CC4C;
    }
    // 0x8000CC44: nop

    // 0x8000CC48: break       6
    do_break(2147535944);
L_8000CC4C:
    // 0x8000CC4C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8000CC50: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8000CC54: b           L_8000CD18
    // 0x8000CC58: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
        goto L_8000CD18;
    // 0x8000CC58: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8000CC5C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
L_8000CC60:
    // 0x8000CC60: lui         $t8, 0xDB08
    ctx->r24 = S32(0XDB08 << 16);
    // 0x8000CC64: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x8000CC68: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000CC6C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8000CC70: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000CC74: lbu         $a0, 0x4F($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X4F);
    // 0x8000CC78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000CC7C: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x8000CC80: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8000CC84: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x8000CC88: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x8000CC8C: subu        $a1, $t7, $a0
    ctx->r5 = SUB32(ctx->r15, ctx->r4);
    // 0x8000CC90: negu        $t9, $a0
    ctx->r25 = SUB32(0, ctx->r4);
    // 0x8000CC94: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8000CC98: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x8000CC9C: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x8000CCA0: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x8000CCA4: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x8000CCA8: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8000CCAC: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x8000CCB0: mflo        $t7
    ctx->r15 = lo;
    // 0x8000CCB4: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8000CCB8: bne         $a1, $zero, L_8000CCC4
    if (ctx->r5 != 0) {
        // 0x8000CCBC: nop
    
            goto L_8000CCC4;
    }
    // 0x8000CCBC: nop

    // 0x8000CCC0: break       7
    do_break(2147536064);
L_8000CCC4:
    // 0x8000CCC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CCC8: bne         $a1, $at, L_8000CCDC
    if (ctx->r5 != ctx->r1) {
        // 0x8000CCCC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000CCDC;
    }
    // 0x8000CCCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000CCD0: bne         $t8, $at, L_8000CCDC
    if (ctx->r24 != ctx->r1) {
        // 0x8000CCD4: nop
    
            goto L_8000CCDC;
    }
    // 0x8000CCD4: nop

    // 0x8000CCD8: break       6
    do_break(2147536088);
L_8000CCDC:
    // 0x8000CCDC: div         $zero, $t6, $a1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r5)));
    // 0x8000CCE0: mflo        $t8
    ctx->r24 = lo;
    // 0x8000CCE4: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x8000CCE8: bne         $a1, $zero, L_8000CCF4
    if (ctx->r5 != 0) {
        // 0x8000CCEC: nop
    
            goto L_8000CCF4;
    }
    // 0x8000CCEC: nop

    // 0x8000CCF0: break       7
    do_break(2147536112);
L_8000CCF4:
    // 0x8000CCF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CCF8: bne         $a1, $at, L_8000CD0C
    if (ctx->r5 != ctx->r1) {
        // 0x8000CCFC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000CD0C;
    }
    // 0x8000CCFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000CD00: bne         $t6, $at, L_8000CD0C
    if (ctx->r14 != ctx->r1) {
        // 0x8000CD04: nop
    
            goto L_8000CD0C;
    }
    // 0x8000CD04: nop

    // 0x8000CD08: break       6
    do_break(2147536136);
L_8000CD0C:
    // 0x8000CD0C: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8000CD10: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8000CD14: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8000CD18:
    // 0x8000CD18: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CD1C: lui         $t9, 0xF800
    ctx->r25 = S32(0XF800 << 16);
    // 0x8000CD20: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x8000CD24: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000CD28: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8000CD2C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000CD30: lbu         $t8, 0x4E($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X4E);
    // 0x8000CD34: lbu         $t6, 0x4C($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X4C);
    // 0x8000CD38: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x8000CD3C: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x8000CD40: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8000CD44: lbu         $t7, 0x4D($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X4D);
    // 0x8000CD48: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8000CD4C: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8000CD50: ori         $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 | 0XFF;
    // 0x8000CD54: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000CD58: b           L_8000CDA0
    // 0x8000CD5C: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
        goto L_8000CDA0;
    // 0x8000CD5C: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x8000CD60: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
L_8000CD64:
    // 0x8000CD64: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x8000CD68: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000CD6C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8000CD70: lbu         $t6, 0x4D($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X4D);
    // 0x8000CD74: lbu         $t8, 0x4C($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X4C);
    // 0x8000CD78: or          $t7, $t6, $t5
    ctx->r15 = ctx->r14 | ctx->r13;
    // 0x8000CD7C: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8000CD80: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8000CD84: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000CD88: lbu         $t9, 0x4E($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X4E);
    // 0x8000CD8C: lbu         $t7, 0x4F($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X4F);
    // 0x8000CD90: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8000CD94: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8000CD98: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000CD9C: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
L_8000CDA0:
    // 0x8000CDA0: andi        $t9, $a0, 0xB900
    ctx->r25 = ctx->r4 & 0XB900;
    // 0x8000CDA4: beq         $t9, $zero, L_8000D058
    if (ctx->r25 == 0) {
        // 0x8000CDA8: andi        $t7, $a0, 0x100
        ctx->r15 = ctx->r4 & 0X100;
            goto L_8000D058;
    }
    // 0x8000CDA8: andi        $t7, $a0, 0x100
    ctx->r15 = ctx->r4 & 0X100;
    // 0x8000CDAC: beq         $t7, $zero, L_8000CDF8
    if (ctx->r15 == 0) {
        // 0x8000CDB0: lui         $t4, 0x801C
        ctx->r12 = S32(0X801C << 16);
            goto L_8000CDF8;
    }
    // 0x8000CDB0: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8000CDB4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CDB8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8000CDBC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000CDC0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8000CDC4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000CDC8: lbu         $t6, 0x48($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X48);
    // 0x8000CDCC: lbu         $t7, 0x4B($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X4B);
    // 0x8000CDD0: sll         $t9, $t6, 24
    ctx->r25 = S32(ctx->r14 << 24);
    // 0x8000CDD4: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8000CDD8: lbu         $t7, 0x49($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X49);
    // 0x8000CDDC: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x8000CDE0: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8000CDE4: lbu         $t8, 0x4A($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X4A);
    // 0x8000CDE8: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8000CDEC: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8000CDF0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000CDF4: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
L_8000CDF8:
    // 0x8000CDF8: andi        $t8, $a0, 0x800
    ctx->r24 = ctx->r4 & 0X800;
    // 0x8000CDFC: beq         $t8, $zero, L_8000CF1C
    if (ctx->r24 == 0) {
        // 0x8000CE00: addiu       $t4, $t4, -0x32B8
        ctx->r12 = ADD32(ctx->r12, -0X32B8);
            goto L_8000CF1C;
    }
    // 0x8000CE00: addiu       $t4, $t4, -0x32B8
    ctx->r12 = ADD32(ctx->r12, -0X32B8);
    // 0x8000CE04: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x8000CE08: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8000CE0C: ori         $t6, $t6, 0x500
    ctx->r14 = ctx->r14 | 0X500;
    // 0x8000CE10: sw          $t6, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r14;
    // 0x8000CE14: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CE18: lui         $t8, 0xDC08
    ctx->r24 = S32(0XDC08 << 16);
    // 0x8000CE1C: ori         $t8, $t8, 0xA
    ctx->r24 = ctx->r24 | 0XA;
    // 0x8000CE20: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000CE24: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8000CE28: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000CE2C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8000CE30: lui         $t7, 0xDC08
    ctx->r15 = S32(0XDC08 << 16);
    // 0x8000CE34: ori         $t7, $t7, 0x30A
    ctx->r15 = ctx->r15 | 0X30A;
    // 0x8000CE38: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000CE3C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CE40: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8000CE44: addiu       $t2, $t2, -0x32B4
    ctx->r10 = ADD32(ctx->r10, -0X32B4);
    // 0x8000CE48: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000CE4C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8000CE50: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000CE54: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8000CE58: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8000CE5C: addiu       $t6, $t8, 0x10
    ctx->r14 = ADD32(ctx->r24, 0X10);
    // 0x8000CE60: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000CE64: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CE68: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8000CE6C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000CE70: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8000CE74: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000CE78: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8000CE7C: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8000CE80: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8000CE84: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x8000CE88: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8000CE8C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8000CE90: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000CE94: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8000CE98: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8000CE9C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8000CEA0: addiu       $t9, $t6, 0x7C
    ctx->r25 = ADD32(ctx->r14, 0X7C);
    // 0x8000CEA4: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8000CEA8: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8000CEAC: addiu       $t8, $t7, 0x7C
    ctx->r24 = ADD32(ctx->r15, 0X7C);
    // 0x8000CEB0: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8000CEB4: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8000CEB8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000CEBC: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CEC0: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8000CEC4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000CEC8: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8000CECC: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8000CED0: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8000CED4: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8000CED8: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8000CEDC: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8000CEE0: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8000CEE4: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8000CEE8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000CEEC: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8000CEF0: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8000CEF4: addiu       $t8, $t9, 0x7C
    ctx->r24 = ADD32(ctx->r25, 0X7C);
    // 0x8000CEF8: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8000CEFC: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x8000CF00: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8000CF04: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8000CF08: addiu       $t9, $t8, 0x7C
    ctx->r25 = ADD32(ctx->r24, 0X7C);
    // 0x8000CF0C: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8000CF10: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8000CF14: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000CF18: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
L_8000CF1C:
    // 0x8000CF1C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8000CF20: andi        $t9, $a0, 0x1000
    ctx->r25 = ctx->r4 & 0X1000;
    // 0x8000CF24: beq         $t9, $zero, L_8000CF74
    if (ctx->r25 == 0) {
        // 0x8000CF28: addiu       $t4, $t4, -0x32B8
        ctx->r12 = ADD32(ctx->r12, -0X32B8);
            goto L_8000CF74;
    }
    // 0x8000CF28: addiu       $t4, $t4, -0x32B8
    ctx->r12 = ADD32(ctx->r12, -0X32B8);
    // 0x8000CF2C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CF30: lui         $t8, 0xDC08
    ctx->r24 = S32(0XDC08 << 16);
    // 0x8000CF34: ori         $t8, $t8, 0xA
    ctx->r24 = ctx->r24 | 0XA;
    // 0x8000CF38: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000CF3C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8000CF40: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000CF44: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8000CF48: lui         $t6, 0xDC08
    ctx->r14 = S32(0XDC08 << 16);
    // 0x8000CF4C: ori         $t6, $t6, 0x30A
    ctx->r14 = ctx->r14 | 0X30A;
    // 0x8000CF50: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000CF54: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CF58: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000CF5C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8000CF60: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000CF64: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8000CF68: addiu       $t7, $t8, 0x10
    ctx->r15 = ADD32(ctx->r24, 0X10);
    // 0x8000CF6C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000CF70: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
L_8000CF74:
    // 0x8000CF74: andi        $t9, $a0, 0x2000
    ctx->r25 = ctx->r4 & 0X2000;
    // 0x8000CF78: beql        $t9, $zero, L_8000D010
    if (ctx->r25 == 0) {
        // 0x8000CF7C: andi        $t6, $a0, 0x8000
        ctx->r14 = ctx->r4 & 0X8000;
            goto L_8000D010;
    }
    goto skip_13;
    // 0x8000CF7C: andi        $t6, $a0, 0x8000
    ctx->r14 = ctx->r4 & 0X8000;
    skip_13:
    // 0x8000CF80: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CF84: lui         $t8, 0xDB02
    ctx->r24 = S32(0XDB02 << 16);
    // 0x8000CF88: addiu       $t7, $zero, 0x30
    ctx->r15 = ADD32(0, 0X30);
    // 0x8000CF8C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000CF90: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8000CF94: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000CF98: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000CF9C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CFA0: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8000CFA4: lui         $t6, 0xDC08
    ctx->r14 = S32(0XDC08 << 16);
    // 0x8000CFA8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000CFAC: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8000CFB0: ori         $t6, $t6, 0x60A
    ctx->r14 = ctx->r14 | 0X60A;
    // 0x8000CFB4: addiu       $t8, $t8, -0x32A0
    ctx->r24 = ADD32(ctx->r24, -0X32A0);
    // 0x8000CFB8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000CFBC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000CFC0: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CFC4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8000CFC8: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
    // 0x8000CFCC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000CFD0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8000CFD4: ori         $t9, $t9, 0x90A
    ctx->r25 = ctx->r25 | 0X90A;
    // 0x8000CFD8: addiu       $t6, $t6, -0x3290
    ctx->r14 = ADD32(ctx->r14, -0X3290);
    // 0x8000CFDC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000CFE0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000CFE4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000CFE8: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8000CFEC: lui         $t7, 0xDC08
    ctx->r15 = S32(0XDC08 << 16);
    // 0x8000CFF0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000CFF4: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8000CFF8: ori         $t7, $t7, 0xC0A
    ctx->r15 = ctx->r15 | 0XC0A;
    // 0x8000CFFC: addiu       $t9, $t9, -0x32A8
    ctx->r25 = ADD32(ctx->r25, -0X32A8);
    // 0x8000D000: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000D004: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000D008: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x8000D00C: andi        $t6, $a0, 0x8000
    ctx->r14 = ctx->r4 & 0X8000;
L_8000D010:
    // 0x8000D010: beql        $t6, $zero, L_8000D05C
    if (ctx->r14 == 0) {
        // 0x8000D014: lw          $t7, 0x28($t3)
        ctx->r15 = MEM_W(ctx->r11, 0X28);
            goto L_8000D05C;
    }
    goto skip_14;
    // 0x8000D014: lw          $t7, 0x28($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X28);
    skip_14:
    // 0x8000D018: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000D01C: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8000D020: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000D024: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8000D028: lbu         $t9, 0x49($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X49);
    // 0x8000D02C: lbu         $t7, 0x48($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X48);
    // 0x8000D030: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x8000D034: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8000D038: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8000D03C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000D040: lbu         $t6, 0x4B($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X4B);
    // 0x8000D044: lbu         $t7, 0x4A($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X4A);
    // 0x8000D048: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8000D04C: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8000D050: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8000D054: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_8000D058:
    // 0x8000D058: lw          $t7, 0x28($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X28);
L_8000D05C:
    // 0x8000D05C: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x8000D060: beql        $t7, $zero, L_8000D0E8
    if (ctx->r15 == 0) {
        // 0x8000D064: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000D0E8;
    }
    goto skip_15;
    // 0x8000D064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_15:
    // 0x8000D068: lw          $a1, 0x24($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X24);
    // 0x8000D06C: lw          $a2, 0x1C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1C);
    // 0x8000D070: jal         0x8000C4A8
    // 0x8000D074: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x8000C4A8)(rdram, ctx);
        goto after_4;
    // 0x8000D074: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
    after_4:
    // 0x8000D078: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x8000D07C: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8000D080: addiu       $a3, $a3, -0x2A44
    ctx->r7 = ADD32(ctx->r7, -0X2A44);
    // 0x8000D084: lw          $t6, 0x24($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X24);
    // 0x8000D088: sll         $t8, $t6, 0
    ctx->r24 = S32(ctx->r14 << 0);
    // 0x8000D08C: bltz        $t8, L_8000D0DC
    if (SIGNED(ctx->r24) < 0) {
        // 0x8000D090: nop
    
            goto L_8000D0DC;
    }
    // 0x8000D090: nop

    // 0x8000D094: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000D098: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x8000D09C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000D0A0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8000D0A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000D0A8: lw          $t6, 0x28($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X28);
    // 0x8000D0AC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000D0B0: lw          $t8, 0x34($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X34);
    // 0x8000D0B4: beql        $t8, $zero, L_8000D0E8
    if (ctx->r24 == 0) {
        // 0x8000D0B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000D0E8;
    }
    goto skip_16;
    // 0x8000D0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_16:
    // 0x8000D0BC: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000D0C0: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x8000D0C4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000D0C8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8000D0CC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000D0D0: lw          $t6, 0x34($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X34);
    // 0x8000D0D4: b           L_8000D0E4
    // 0x8000D0D8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
        goto L_8000D0E4;
    // 0x8000D0D8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_8000D0DC:
    // 0x8000D0DC: jal         0x8000BC78
    // 0x8000D0E0: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    LOOKUP_FUNC(0x8000BC78)(rdram, ctx);
        goto after_5;
    // 0x8000D0E0: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    after_5:
L_8000D0E4:
    // 0x8000D0E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000D0E8:
    // 0x8000D0E8: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    // 0x8000D0EC: jr          $ra
    // 0x8000D0F0: nop

    return;
    // 0x8000D0F0: nop

    // 0x8000D0F4: nop

    // 0x8000D0F8: nop

    // 0x8000D0FC: nop

;}
RECOMP_FUNC void FUN_8000d100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D100: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000D104: sb          $t6, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r14;
    // 0x8000D108: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000D10C: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D110: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000D114: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000D118: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x8000D11C: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D120: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000D124: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8000D128: swc1        $f6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f6.u32l;
    // 0x8000D12C: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D130: lhu         $t9, 0x8($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X8);
    // 0x8000D134: sh          $t9, 0x24($t0)
    MEM_H(0X24, ctx->r8) = ctx->r25;
    // 0x8000D138: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D13C: lhu         $t1, 0xA($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0XA);
    // 0x8000D140: sh          $t1, 0x26($t2)
    MEM_H(0X26, ctx->r10) = ctx->r9;
    // 0x8000D144: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D148: lw          $t3, 0xC($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XC);
    // 0x8000D14C: sw          $t3, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r11;
    // 0x8000D150: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D154: lw          $t5, 0x10($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X10);
    // 0x8000D158: ori         $t3, $zero, 0x8000
    ctx->r11 = 0 | 0X8000;
    // 0x8000D15C: sw          $t5, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r13;
    // 0x8000D160: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D164: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x8000D168: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D16C: swc1        $f0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f0.u32l;
    // 0x8000D170: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D174: sb          $v0, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r2;
    // 0x8000D178: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D17C: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8000D180: lw          $t1, 0x2C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D184: sb          $v0, 0x12($t1)
    MEM_B(0X12, ctx->r9) = ctx->r2;
    // 0x8000D188: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D18C: sb          $v0, 0x13($t2)
    MEM_B(0X13, ctx->r10) = ctx->r2;
    // 0x8000D190: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D194: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x8000D198: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D19C: sh          $zero, 0x16($t5)
    MEM_H(0X16, ctx->r13) = 0;
    // 0x8000D1A0: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D1A4: sb          $zero, 0x18($t6)
    MEM_B(0X18, ctx->r14) = 0;
    // 0x8000D1A8: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D1AC: sb          $zero, 0x19($t7)
    MEM_B(0X19, ctx->r15) = 0;
    // 0x8000D1B0: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D1B4: sb          $zero, 0x1A($t8)
    MEM_B(0X1A, ctx->r24) = 0;
    // 0x8000D1B8: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D1BC: sw          $zero, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = 0;
    // 0x8000D1C0: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D1C4: jr          $ra
    // 0x8000D1C8: sw          $zero, 0x20($t0)
    MEM_W(0X20, ctx->r8) = 0;
    return;
    // 0x8000D1C8: sw          $zero, 0x20($t0)
    MEM_W(0X20, ctx->r8) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000d1cc(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000d1cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D1CC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000D1D0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8000D1D4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8000D1D8: addiu       $s0, $s0, -0x2A44
    ctx->r16 = ADD32(ctx->r16, -0X2A44);
    // 0x8000D1DC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D1E0: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8000D1E4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000D1E8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000D1EC: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x8000D1F0: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x8000D1F4: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8000D1F8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8000D1FC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000D200: lui         $s2, 0xE700
    ctx->r18 = S32(0XE700 << 16);
    // 0x8000D204: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x8000D208: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000D20C: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D210: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8000D214: lhu         $t8, 0x24($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X24);
    // 0x8000D218: beql        $t8, $zero, L_8000D254
    if (ctx->r24 == 0) {
        // 0x8000D21C: lw          $s1, 0x0($s0)
        ctx->r17 = MEM_W(ctx->r16, 0X0);
            goto L_8000D254;
    }
    goto skip_0;
    // 0x8000D21C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8000D220: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8000D224: lui         $t4, 0xDB06
    ctx->r12 = S32(0XDB06 << 16);
    // 0x8000D228: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x8000D22C: addiu       $t9, $s1, 0x8
    ctx->r25 = ADD32(ctx->r17, 0X8);
    // 0x8000D230: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8000D234: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8000D238: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x8000D23C: jal         0x80005204
    // 0x8000D240: lhu         $a0, 0x24($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X24);
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_0;
    // 0x8000D240: lhu         $a0, 0x24($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X24);
    after_0:
    // 0x8000D244: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000D248: addu        $t6, $v0, $at
    ctx->r14 = ADD32(ctx->r2, ctx->r1);
    // 0x8000D24C: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x8000D250: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_8000D254:
    // 0x8000D254: lui         $t8, 0xDB06
    ctx->r24 = S32(0XDB06 << 16);
    // 0x8000D258: ori         $t8, $t8, 0xC
    ctx->r24 = ctx->r24 | 0XC;
    // 0x8000D25C: addiu       $t7, $s1, 0x8
    ctx->r15 = ADD32(ctx->r17, 0X8);
    // 0x8000D260: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000D264: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000D268: lw          $t9, 0x2C($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X2C);
    // 0x8000D26C: jal         0x80005204
    // 0x8000D270: lhu         $a0, 0x26($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X26);
    LOOKUP_FUNC(0x80005204)(rdram, ctx);
        goto after_1;
    // 0x8000D270: lhu         $a0, 0x26($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X26);
    after_1:
    // 0x8000D274: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000D278: addu        $t4, $v0, $at
    ctx->r12 = ADD32(ctx->r2, ctx->r1);
    // 0x8000D27C: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    // 0x8000D280: lw          $t5, 0x2C($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X2C);
    // 0x8000D284: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8000D288: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x8000D28C: lbu         $t6, 0x13($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X13);
    // 0x8000D290: lui         $t5, 0xDE00
    ctx->r13 = S32(0XDE00 << 16);
    // 0x8000D294: bnel        $t6, $at, L_8000D2C0
    if (ctx->r14 != ctx->r1) {
        // 0x8000D298: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_8000D2C0;
    }
    goto skip_1;
    // 0x8000D298: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x8000D29C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D2A0: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8000D2A4: addiu       $t9, $t9, 0x3760
    ctx->r25 = ADD32(ctx->r25, 0X3760);
    // 0x8000D2A8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000D2AC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000D2B0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000D2B4: b           L_8000D31C
    // 0x8000D2B8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_8000D31C;
    // 0x8000D2B8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000D2BC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8000D2C0:
    // 0x8000D2C0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8000D2C4: addiu       $t6, $t6, 0x3778
    ctx->r14 = ADD32(ctx->r14, 0X3778);
    // 0x8000D2C8: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8000D2CC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8000D2D0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000D2D4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000D2D8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D2DC: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8000D2E0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000D2E4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000D2E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000D2EC: lw          $v0, 0x2C($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X2C);
    // 0x8000D2F0: lbu         $t4, 0x10($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X10);
    // 0x8000D2F4: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x8000D2F8: lbu         $t6, 0x12($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X12);
    // 0x8000D2FC: sll         $t5, $t4, 24
    ctx->r13 = S32(ctx->r12 << 24);
    // 0x8000D300: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8000D304: lbu         $t4, 0x13($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X13);
    // 0x8000D308: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x8000D30C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8000D310: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x8000D314: or          $t6, $t5, $t4
    ctx->r14 = ctx->r13 | ctx->r12;
    // 0x8000D318: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_8000D31C:
    // 0x8000D31C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D320: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8000D324: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8000D328: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000D32C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8000D330: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000D334: lw          $t8, 0x2C($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X2C);
    // 0x8000D338: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8000D33C: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8000D340: lw          $t5, 0x28($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X28);
    // 0x8000D344: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x8000D348: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8000D34C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D350: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8000D354: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8000D358: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000D35C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000D360: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D364: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x8000D368: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000D36C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8000D370: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000D374: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000D378: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D37C: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x8000D380: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x8000D384: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8000D388: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8000D38C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000D390: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8000D394: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D398: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x8000D39C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000D3A0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000D3A4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000D3A8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000D3AC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D3B0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000D3B4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000D3B8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000D3BC: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x8000D3C0: lw          $v0, 0x2C($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X2C);
    // 0x8000D3C4: lhu         $a0, 0x26($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X26);
    // 0x8000D3C8: jal         0x8000522C
    // 0x8000D3CC: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_2;
    // 0x8000D3CC: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    after_2:
    // 0x8000D3D0: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x8000D3D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000D3D8: lbu         $s5, 0x4($v0)
    ctx->r21 = MEM_BU(ctx->r2, 0X4);
    // 0x8000D3DC: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x8000D3E0: beq         $s3, $zero, L_8000D614
    if (ctx->r19 == 0) {
        // 0x8000D3E4: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_8000D614;
    }
    // 0x8000D3E4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x8000D3E8: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8000D3EC: addiu       $s2, $s2, -0x6D50
    ctx->r18 = ADD32(ctx->r18, -0X6D50);
L_8000D3F0:
    // 0x8000D3F0: lw          $v0, 0x2C($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X2C);
    // 0x8000D3F4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8000D3F8: lh          $t3, 0x1B4($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X1B4);
    // 0x8000D3FC: lhu         $a0, 0x16($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X16);
    // 0x8000D400: lhu         $t1, 0x14($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X14);
    // 0x8000D404: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000D408: andi        $t5, $a0, 0x1
    ctx->r13 = ctx->r4 & 0X1;
    // 0x8000D40C: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000D410: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000D414: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000D418: andi        $a1, $a0, 0x2
    ctx->r5 = ctx->r4 & 0X2;
    // 0x8000D41C: beq         $t5, $zero, L_8000D480
    if (ctx->r13 == 0) {
        // 0x8000D420: andi        $t2, $t1, 0x8000
        ctx->r10 = ctx->r9 & 0X8000;
            goto L_8000D480;
    }
    // 0x8000D420: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x8000D424: lh          $v0, 0x8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8);
    // 0x8000D428: lbu         $v1, 0x5($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X5);
    // 0x8000D42C: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8000D430: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x8000D434: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8000D438: nop

    // 0x8000D43C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000D440: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000D444: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8000D448: nop

    // 0x8000D44C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8000D450: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8000D454: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8000D458: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8000D45C: mfc1        $s1, $f16
    ctx->r17 = (int32_t)ctx->f16.u32l;
    // 0x8000D460: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000D464: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x8000D468: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8000D46C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8000D470: nop

    // 0x8000D474: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8000D478: b           L_8000D4D4
    // 0x8000D47C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
        goto L_8000D4D4;
    // 0x8000D47C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_8000D480:
    // 0x8000D480: lh          $v0, 0x8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8);
    // 0x8000D484: lbu         $v1, 0x5($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X5);
    // 0x8000D488: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8000D48C: addu        $t8, $v0, $v1
    ctx->r24 = ADD32(ctx->r2, ctx->r3);
    // 0x8000D490: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8000D494: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000D498: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000D49C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8000D4A0: nop

    // 0x8000D4A4: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8000D4A8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8000D4AC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8000D4B0: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8000D4B4: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x8000D4B8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8000D4BC: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x8000D4C0: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8000D4C4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8000D4C8: nop

    // 0x8000D4CC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8000D4D0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_8000D4D4:
    // 0x8000D4D4: beql        $a1, $zero, L_8000D53C
    if (ctx->r5 == 0) {
        // 0x8000D4D8: lh          $v0, 0xA($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XA);
            goto L_8000D53C;
    }
    goto skip_2;
    // 0x8000D4D8: lh          $v0, 0xA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA);
    skip_2:
    // 0x8000D4DC: lh          $v0, 0xA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA);
    // 0x8000D4E0: lbu         $t0, 0x6($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X6);
    // 0x8000D4E4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8000D4E8: addu        $t4, $v0, $t0
    ctx->r12 = ADD32(ctx->r2, ctx->r8);
    // 0x8000D4EC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8000D4F0: nop

    // 0x8000D4F4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000D4F8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000D4FC: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8000D500: nop

    // 0x8000D504: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8000D508: sub.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x8000D50C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8000D510: sub.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x8000D514: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8000D518: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8000D51C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8000D520: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8000D524: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8000D528: nop

    // 0x8000D52C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8000D530: b           L_8000D58C
    // 0x8000D534: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
        goto L_8000D58C;
    // 0x8000D534: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8000D538: lh          $v0, 0xA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA);
L_8000D53C:
    // 0x8000D53C: lbu         $t0, 0x6($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X6);
    // 0x8000D540: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000D544: addu        $t8, $v0, $t0
    ctx->r24 = ADD32(ctx->r2, ctx->r8);
    // 0x8000D548: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8000D54C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000D550: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000D554: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8000D558: nop

    // 0x8000D55C: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8000D560: add.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x8000D564: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8000D568: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x8000D56C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8000D570: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000D574: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8000D578: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8000D57C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8000D580: nop

    // 0x8000D584: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8000D588: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
L_8000D58C:
    // 0x8000D58C: beq         $t2, $zero, L_8000D59C
    if (ctx->r10 == 0) {
        // 0x8000D590: andi        $v0, $t1, 0xFF
        ctx->r2 = ctx->r9 & 0XFF;
            goto L_8000D59C;
    }
    // 0x8000D590: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // 0x8000D594: b           L_8000D59C
    // 0x8000D598: lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7);
        goto L_8000D59C;
    // 0x8000D598: lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7);
L_8000D59C:
    // 0x8000D59C: lbu         $t4, 0x4($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X4);
    // 0x8000D5A0: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8000D5A4: xor         $t1, $a0, $t4
    ctx->r9 = ctx->r4 ^ ctx->r12;
    // 0x8000D5A8: bne         $at, $zero, L_8000D608
    if (ctx->r1 != 0) {
        // 0x8000D5AC: andi        $t1, $t1, 0xFF
        ctx->r9 = ctx->r9 & 0XFF;
            goto L_8000D608;
    }
    // 0x8000D5AC: andi        $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 & 0XFF;
    // 0x8000D5B0: lh          $t6, 0x1B8($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X1B8);
    // 0x8000D5B4: slt         $at, $t6, $s1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8000D5B8: bnel        $at, $zero, L_8000D60C
    if (ctx->r1 != 0) {
        // 0x8000D5BC: or          $v1, $s3, $zero
        ctx->r3 = ctx->r19 | 0;
            goto L_8000D60C;
    }
    goto skip_3;
    // 0x8000D5BC: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    skip_3:
    // 0x8000D5C0: lh          $t9, 0x1B6($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X1B6);
    // 0x8000D5C4: slt         $at, $a3, $t9
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000D5C8: bnel        $at, $zero, L_8000D60C
    if (ctx->r1 != 0) {
        // 0x8000D5CC: or          $v1, $s3, $zero
        ctx->r3 = ctx->r19 | 0;
            goto L_8000D60C;
    }
    goto skip_4;
    // 0x8000D5CC: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    skip_4:
    // 0x8000D5D0: lh          $t7, 0x1BA($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X1BA);
    // 0x8000D5D4: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8000D5D8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8000D5DC: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000D5E0: bnel        $at, $zero, L_8000D60C
    if (ctx->r1 != 0) {
        // 0x8000D5E4: or          $v1, $s3, $zero
        ctx->r3 = ctx->r19 | 0;
            goto L_8000D60C;
    }
    goto skip_5;
    // 0x8000D5E4: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    skip_5:
    // 0x8000D5E8: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8000D5EC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8000D5F0: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x8000D5F4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8000D5F8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8000D5FC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8000D600: jal         0x8000D638
    // 0x8000D604: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8000D638)(rdram, ctx);
        goto after_3;
    // 0x8000D604: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_3:
L_8000D608:
    // 0x8000D608: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
L_8000D60C:
    // 0x8000D60C: bne         $s3, $zero, L_8000D3F0
    if (ctx->r19 != 0) {
        // 0x8000D610: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_8000D3F0;
    }
    // 0x8000D610: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_8000D614:
    // 0x8000D614: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8000D618: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8000D61C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8000D620: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8000D624: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8000D628: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x8000D62C: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x8000D630: jr          $ra
    // 0x8000D634: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8000D634: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000d638(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000d638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D638: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8000D63C: lbu         $v0, 0x9B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X9B);
    // 0x8000D640: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8000D644: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8000D648: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x8000D64C: beq         $v0, $zero, L_8000D674
    if (ctx->r2 == 0) {
        // 0x8000D650: sw          $a3, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r7;
            goto L_8000D674;
    }
    // 0x8000D650: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x8000D654: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000D658: beq         $v0, $at, L_8000D820
    if (ctx->r2 == ctx->r1) {
        // 0x8000D65C: lui         $a0, 0x8009
        ctx->r4 = S32(0X8009 << 16);
            goto L_8000D820;
    }
    // 0x8000D65C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8000D660: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8000D664: addiu       $a0, $a0, -0x2A44
    ctx->r4 = ADD32(ctx->r4, -0X2A44);
    // 0x8000D668: lbu         $t2, 0x97($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X97);
    // 0x8000D66C: b           L_8000D9A8
    // 0x8000D670: lbu         $a3, 0x93($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X93);
        goto L_8000D9A8;
    // 0x8000D670: lbu         $a3, 0x93($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X93);
L_8000D674:
    // 0x8000D674: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8000D678: addiu       $a0, $a0, -0x2A44
    ctx->r4 = ADD32(ctx->r4, -0X2A44);
    // 0x8000D67C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D680: lbu         $a3, 0x93($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X93);
    // 0x8000D684: lbu         $t2, 0x97($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X97);
    // 0x8000D688: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8000D68C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000D690: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x8000D694: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000D698: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x8000D69C: multu       $a3, $t2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D6A0: lui         $t7, 0x705
    ctx->r15 = S32(0X705 << 16);
    // 0x8000D6A4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000D6A8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D6AC: ori         $t7, $t7, 0xC170
    ctx->r15 = ctx->r15 | 0XC170;
    // 0x8000D6B0: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x8000D6B4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000D6B8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8000D6BC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8000D6C0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000D6C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D6C8: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8000D6CC: mflo        $t1
    ctx->r9 = lo;
    // 0x8000D6D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8000D6D4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8000D6D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000D6DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8000D6E0: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8000D6E4: addiu       $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x8000D6E8: srl         $t1, $t1, 2
    ctx->r9 = S32(U32(ctx->r9) >> 2);
    // 0x8000D6EC: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8000D6F0: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x8000D6F4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000D6F8: sltiu       $at, $t1, 0x7FF
    ctx->r1 = ctx->r9 < 0X7FF ? 1 : 0;
    // 0x8000D6FC: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8000D700: beq         $at, $zero, L_8000D710
    if (ctx->r1 == 0) {
        // 0x8000D704: sw          $t7, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r15;
            goto L_8000D710;
    }
    // 0x8000D704: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8000D708: b           L_8000D714
    // 0x8000D70C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
        goto L_8000D714;
    // 0x8000D70C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
L_8000D710:
    // 0x8000D710: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
L_8000D714:
    // 0x8000D714: srl         $v0, $a3, 4
    ctx->r2 = S32(U32(ctx->r7) >> 4);
    // 0x8000D718: bne         $v0, $zero, L_8000D728
    if (ctx->r2 != 0) {
        // 0x8000D71C: lui         $at, 0x700
        ctx->r1 = S32(0X700 << 16);
            goto L_8000D728;
    }
    // 0x8000D71C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8000D720: b           L_8000D72C
    // 0x8000D724: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8000D72C;
    // 0x8000D724: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8000D728:
    // 0x8000D728: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8000D72C:
    // 0x8000D72C: bne         $v0, $zero, L_8000D73C
    if (ctx->r2 != 0) {
        // 0x8000D730: addiu       $t8, $a1, 0x7FF
        ctx->r24 = ADD32(ctx->r5, 0X7FF);
            goto L_8000D73C;
    }
    // 0x8000D730: addiu       $t8, $a1, 0x7FF
    ctx->r24 = ADD32(ctx->r5, 0X7FF);
    // 0x8000D734: b           L_8000D740
    // 0x8000D738: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8000D740;
    // 0x8000D738: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000D73C:
    // 0x8000D73C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8000D740:
    // 0x8000D740: divu        $zero, $t8, $v1
    lo = S32(U32(ctx->r24) / U32(ctx->r3)); hi = S32(U32(ctx->r24) % U32(ctx->r3));
    // 0x8000D744: mflo        $t9
    ctx->r25 = lo;
    // 0x8000D748: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8000D74C: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x8000D750: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8000D754: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8000D758: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8000D75C: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x8000D760: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D764: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8000D768: srl         $t6, $a3, 1
    ctx->r14 = S32(U32(ctx->r7) >> 1);
    // 0x8000D76C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8000D770: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8000D774: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000D778: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000D77C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8000D780: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D784: addiu       $t8, $t6, 0x7
    ctx->r24 = ADD32(ctx->r14, 0X7);
    // 0x8000D788: srl         $t7, $t8, 3
    ctx->r15 = S32(U32(ctx->r24) >> 3);
    // 0x8000D78C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000D790: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8000D794: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x8000D798: sll         $t6, $t9, 9
    ctx->r14 = S32(ctx->r25 << 9);
    // 0x8000D79C: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8000D7A0: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8000D7A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000D7A8: lbu         $t7, 0xA7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XA7);
    // 0x8000D7AC: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8000D7B0: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x8000D7B4: andi        $t9, $t7, 0xF
    ctx->r25 = ctx->r15 & 0XF;
    // 0x8000D7B8: sll         $t6, $t9, 20
    ctx->r14 = S32(ctx->r25 << 20);
    // 0x8000D7BC: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8000D7C0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8000D7C4: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8000D7C8: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8000D7CC: ori         $t6, $t9, 0x170
    ctx->r14 = ctx->r25 | 0X170;
    // 0x8000D7D0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000D7D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D7D8: addiu       $t9, $a3, -0x1
    ctx->r25 = ADD32(ctx->r7, -0X1);
    // 0x8000D7DC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8000D7E0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8000D7E4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8000D7E8: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8000D7EC: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8000D7F0: addiu       $t9, $t2, -0x1
    ctx->r25 = ADD32(ctx->r10, -0X1);
    // 0x8000D7F4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000D7F8: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8000D7FC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8000D800: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8000D804: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8000D808: bne         $v1, $zero, L_8000D814
    if (ctx->r3 != 0) {
        // 0x8000D80C: nop
    
            goto L_8000D814;
    }
    // 0x8000D80C: nop

    // 0x8000D810: break       7
    do_break(2147538960);
L_8000D814:
    // 0x8000D814: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000D818: b           L_8000D9A8
    // 0x8000D81C: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
        goto L_8000D9A8;
    // 0x8000D81C: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_8000D820:
    // 0x8000D820: addiu       $a0, $a0, -0x2A44
    ctx->r4 = ADD32(ctx->r4, -0X2A44);
    // 0x8000D824: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D828: lbu         $a3, 0x93($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X93);
    // 0x8000D82C: lbu         $t2, 0x97($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X97);
    // 0x8000D830: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8000D834: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000D838: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x8000D83C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000D840: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x8000D844: multu       $a3, $t2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D848: lui         $t7, 0x705
    ctx->r15 = S32(0X705 << 16);
    // 0x8000D84C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000D850: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D854: ori         $t7, $t7, 0xC170
    ctx->r15 = ctx->r15 | 0XC170;
    // 0x8000D858: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x8000D85C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000D860: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8000D864: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8000D868: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000D86C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D870: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8000D874: mflo        $t1
    ctx->r9 = lo;
    // 0x8000D878: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8000D87C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8000D880: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000D884: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8000D888: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8000D88C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8000D890: srl         $t1, $t1, 1
    ctx->r9 = S32(U32(ctx->r9) >> 1);
    // 0x8000D894: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8000D898: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x8000D89C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000D8A0: sltiu       $at, $t1, 0x7FF
    ctx->r1 = ctx->r9 < 0X7FF ? 1 : 0;
    // 0x8000D8A4: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8000D8A8: beq         $at, $zero, L_8000D8B8
    if (ctx->r1 == 0) {
        // 0x8000D8AC: sw          $t7, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r15;
            goto L_8000D8B8;
    }
    // 0x8000D8AC: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8000D8B0: b           L_8000D8BC
    // 0x8000D8B4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
        goto L_8000D8BC;
    // 0x8000D8B4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
L_8000D8B8:
    // 0x8000D8B8: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
L_8000D8BC:
    // 0x8000D8BC: srl         $v0, $a3, 3
    ctx->r2 = S32(U32(ctx->r7) >> 3);
    // 0x8000D8C0: bne         $v0, $zero, L_8000D8D0
    if (ctx->r2 != 0) {
        // 0x8000D8C4: or          $t1, $a3, $zero
        ctx->r9 = ctx->r7 | 0;
            goto L_8000D8D0;
    }
    // 0x8000D8C4: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8000D8C8: b           L_8000D8D4
    // 0x8000D8CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8000D8D4;
    // 0x8000D8CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8000D8D0:
    // 0x8000D8D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8000D8D4:
    // 0x8000D8D4: bne         $v0, $zero, L_8000D8E4
    if (ctx->r2 != 0) {
        // 0x8000D8D8: addiu       $t8, $a1, 0x7FF
        ctx->r24 = ADD32(ctx->r5, 0X7FF);
            goto L_8000D8E4;
    }
    // 0x8000D8D8: addiu       $t8, $a1, 0x7FF
    ctx->r24 = ADD32(ctx->r5, 0X7FF);
    // 0x8000D8DC: b           L_8000D8E8
    // 0x8000D8E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8000D8E8;
    // 0x8000D8E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000D8E4:
    // 0x8000D8E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8000D8E8:
    // 0x8000D8E8: divu        $zero, $t8, $v1
    lo = S32(U32(ctx->r24) / U32(ctx->r3)); hi = S32(U32(ctx->r24) % U32(ctx->r3));
    // 0x8000D8EC: mflo        $t9
    ctx->r25 = lo;
    // 0x8000D8F0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8000D8F4: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x8000D8F8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8000D8FC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8000D900: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8000D904: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8000D908: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x8000D90C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D910: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8000D914: addiu       $t6, $t1, 0x7
    ctx->r14 = ADD32(ctx->r9, 0X7);
    // 0x8000D918: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8000D91C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8000D920: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000D924: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000D928: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x8000D92C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D930: srl         $t8, $t6, 3
    ctx->r24 = S32(U32(ctx->r14) >> 3);
    // 0x8000D934: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x8000D938: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000D93C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8000D940: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x8000D944: lui         $t8, 0x5
    ctx->r24 = S32(0X5 << 16);
    // 0x8000D948: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8000D94C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8000D950: ori         $t8, $t8, 0xC170
    ctx->r24 = ctx->r24 | 0XC170;
    // 0x8000D954: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000D958: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000D95C: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x8000D960: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000D964: addiu       $t6, $a3, -0x1
    ctx->r14 = ADD32(ctx->r7, -0X1);
    // 0x8000D968: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8000D96C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8000D970: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8000D974: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8000D978: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8000D97C: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x8000D980: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8000D984: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8000D988: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8000D98C: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8000D990: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8000D994: bne         $v1, $zero, L_8000D9A0
    if (ctx->r3 != 0) {
        // 0x8000D998: nop
    
            goto L_8000D9A0;
    }
    // 0x8000D998: nop

    // 0x8000D99C: break       7
    do_break(2147539356);
L_8000D9A0:
    // 0x8000D9A0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000D9A4: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
L_8000D9A8:
    // 0x8000D9A8: lh          $t8, 0x8A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8A);
    // 0x8000D9AC: lh          $t9, 0x82($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X82);
    // 0x8000D9B0: sll         $t6, $a3, 10
    ctx->r14 = S32(ctx->r7 << 10);
    // 0x8000D9B4: lbu         $t5, 0x9F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X9F);
    // 0x8000D9B8: subu        $t7, $t8, $t9
    ctx->r15 = SUB32(ctx->r24, ctx->r25);
    // 0x8000D9BC: div         $zero, $t6, $t7
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r15)));
    // 0x8000D9C0: lh          $t9, 0x86($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X86);
    // 0x8000D9C4: lh          $t8, 0x8E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8E);
    // 0x8000D9C8: mflo        $v1
    ctx->r3 = lo;
    // 0x8000D9CC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8000D9D0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8000D9D4: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8000D9D8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8000D9DC: bne         $t7, $zero, L_8000D9E8
    if (ctx->r15 != 0) {
        // 0x8000D9E0: nop
    
            goto L_8000D9E8;
    }
    // 0x8000D9E0: nop

    // 0x8000D9E4: break       7
    do_break(2147539428);
L_8000D9E8:
    // 0x8000D9E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D9EC: bne         $t7, $at, L_8000DA00
    if (ctx->r15 != ctx->r1) {
        // 0x8000D9F0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000DA00;
    }
    // 0x8000D9F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000D9F4: bne         $t6, $at, L_8000DA00
    if (ctx->r14 != ctx->r1) {
        // 0x8000D9F8: nop
    
            goto L_8000DA00;
    }
    // 0x8000D9F8: nop

    // 0x8000D9FC: break       6
    do_break(2147539452);
L_8000DA00:
    // 0x8000DA00: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x8000DA04: sll         $t7, $t2, 10
    ctx->r15 = S32(ctx->r10 << 10);
    // 0x8000DA08: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x8000DA0C: mflo        $a2
    ctx->r6 = lo;
    // 0x8000DA10: andi        $t8, $t5, 0x1
    ctx->r24 = ctx->r13 & 0X1;
    // 0x8000DA14: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x8000DA18: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8000DA1C: bne         $t6, $zero, L_8000DA28
    if (ctx->r14 != 0) {
        // 0x8000DA20: nop
    
            goto L_8000DA28;
    }
    // 0x8000DA20: nop

    // 0x8000DA24: break       7
    do_break(2147539492);
L_8000DA28:
    // 0x8000DA28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000DA2C: bne         $t6, $at, L_8000DA40
    if (ctx->r14 != ctx->r1) {
        // 0x8000DA30: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000DA40;
    }
    // 0x8000DA30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000DA34: bne         $t7, $at, L_8000DA40
    if (ctx->r15 != ctx->r1) {
        // 0x8000DA38: nop
    
            goto L_8000DA40;
    }
    // 0x8000DA38: nop

    // 0x8000DA3C: break       6
    do_break(2147539516);
L_8000DA40:
    // 0x8000DA40: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8000DA44: beq         $t8, $zero, L_8000DA58
    if (ctx->r24 == 0) {
        // 0x8000DA48: andi        $t9, $t5, 0x2
        ctx->r25 = ctx->r13 & 0X2;
            goto L_8000DA58;
    }
    // 0x8000DA48: andi        $t9, $t5, 0x2
    ctx->r25 = ctx->r13 & 0X2;
    // 0x8000DA4C: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8000DA50: negu        $t0, $v1
    ctx->r8 = SUB32(0, ctx->r3);
    // 0x8000DA54: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
L_8000DA58:
    // 0x8000DA58: beql        $t9, $zero, L_8000DA70
    if (ctx->r25 == 0) {
        // 0x8000DA5C: lh          $v1, 0x8A($sp)
        ctx->r3 = MEM_H(ctx->r29, 0X8A);
            goto L_8000DA70;
    }
    goto skip_0;
    // 0x8000DA5C: lh          $v1, 0x8A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X8A);
    skip_0:
    // 0x8000DA60: addiu       $t3, $a1, -0x1
    ctx->r11 = ADD32(ctx->r5, -0X1);
    // 0x8000DA64: negu        $t1, $a2
    ctx->r9 = SUB32(0, ctx->r6);
    // 0x8000DA68: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8000DA6C: lh          $v1, 0x8A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X8A);
L_8000DA70:
    // 0x8000DA70: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8000DA74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000DA78: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8000DA7C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8000DA80: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x8000DA84: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8000DA88: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000DA8C: blez        $v1, L_8000DA9C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000DA90: lh          $v0, 0x8E($sp)
        ctx->r2 = MEM_H(ctx->r29, 0X8E);
            goto L_8000DA9C;
    }
    // 0x8000DA90: lh          $v0, 0x8E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X8E);
    // 0x8000DA94: b           L_8000DA9C
    // 0x8000DA98: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8000DA9C;
    // 0x8000DA98: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8000DA9C:
    // 0x8000DA9C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000DAA0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000DAA4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000DAA8: blez        $v0, L_8000DAB8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000DAAC: andi        $t9, $a1, 0xFFF
        ctx->r25 = ctx->r5 & 0XFFF;
            goto L_8000DAB8;
    }
    // 0x8000DAAC: andi        $t9, $a1, 0xFFF
    ctx->r25 = ctx->r5 & 0XFFF;
    // 0x8000DAB0: b           L_8000DABC
    // 0x8000DAB4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8000DABC;
    // 0x8000DAB4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8000DAB8:
    // 0x8000DAB8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000DABC:
    // 0x8000DABC: andi        $t6, $v1, 0xFFF
    ctx->r14 = ctx->r3 & 0XFFF;
    // 0x8000DAC0: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8000DAC4: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8000DAC8: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x8000DACC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8000DAD0: lh          $t5, 0x82($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X82);
    // 0x8000DAD4: lh          $t9, 0x86($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X86);
    // 0x8000DAD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000DADC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8000DAE0: sll         $t5, $t5, 16
    ctx->r13 = S32(ctx->r13 << 16);
    // 0x8000DAE4: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8000DAE8: blez        $t5, L_8000DAF8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8000DAEC: sll         $t8, $t9, 2
        ctx->r24 = S32(ctx->r25 << 2);
            goto L_8000DAF8;
    }
    // 0x8000DAEC: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8000DAF0: b           L_8000DAF8
    // 0x8000DAF4: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
        goto L_8000DAF8;
    // 0x8000DAF4: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
L_8000DAF8:
    // 0x8000DAF8: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8000DAFC: lh          $a2, 0x6($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X6);
    // 0x8000DB00: andi        $t6, $a1, 0xFFF
    ctx->r14 = ctx->r5 & 0XFFF;
    // 0x8000DB04: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8000DB08: blez        $a2, L_8000DB18
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8000DB0C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000DB18;
    }
    // 0x8000DB0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000DB10: b           L_8000DB18
    // 0x8000DB14: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
        goto L_8000DB18;
    // 0x8000DB14: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_8000DB18:
    // 0x8000DB18: andi        $t7, $v1, 0xFFF
    ctx->r15 = ctx->r3 & 0XFFF;
    // 0x8000DB1C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8000DB20: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8000DB24: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8000DB28: lui         $t7, 0xE100
    ctx->r15 = S32(0XE100 << 16);
    // 0x8000DB2C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8000DB30: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8000DB34: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000DB38: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8000DB3C: bgez        $t5, L_8000DBA8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8000DB40: lw          $t9, 0x4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X4);
            goto L_8000DBA8;
    }
    // 0x8000DB40: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8000DB44: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x8000DB48: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000DB4C: bgez        $v0, L_8000DB7C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000DB50: nop
    
            goto L_8000DB7C;
    }
    // 0x8000DB50: nop

    // 0x8000DB54: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000DB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DB5C: mflo        $v1
    ctx->r3 = lo;
    // 0x8000DB60: sra         $v1, $v1, 7
    ctx->r3 = S32(SIGNED(ctx->r3) >> 7);
    // 0x8000DB64: blez        $v1, L_8000DB74
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000DB68: nop
    
            goto L_8000DB74;
    }
    // 0x8000DB68: nop

    // 0x8000DB6C: b           L_8000DBA8
    // 0x8000DB70: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
        goto L_8000DBA8;
    // 0x8000DB70: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
L_8000DB74:
    // 0x8000DB74: b           L_8000DBA8
    // 0x8000DB78: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
        goto L_8000DBA8;
    // 0x8000DB78: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_8000DB7C:
    // 0x8000DB7C: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000DB80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DB84: mflo        $v1
    ctx->r3 = lo;
    // 0x8000DB88: sra         $v1, $v1, 7
    ctx->r3 = S32(SIGNED(ctx->r3) >> 7);
    // 0x8000DB8C: bgez        $v1, L_8000DB9C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000DB90: nop
    
            goto L_8000DB9C;
    }
    // 0x8000DB90: nop

    // 0x8000DB94: b           L_8000DB9C
    // 0x8000DB98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8000DB9C;
    // 0x8000DB98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000DB9C:
    // 0x8000DB9C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000DBA0: b           L_8000DBA8
    // 0x8000DBA4: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
        goto L_8000DBA8;
    // 0x8000DBA4: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
L_8000DBA8:
    // 0x8000DBA8: bgez        $t9, L_8000DC14
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000DBAC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000DC14;
    }
    // 0x8000DBAC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000DBB0: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x8000DBB4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000DBB8: bgez        $v0, L_8000DBE8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000DBBC: nop
    
            goto L_8000DBE8;
    }
    // 0x8000DBBC: nop

    // 0x8000DBC0: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000DBC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000DBC8: mflo        $v1
    ctx->r3 = lo;
    // 0x8000DBCC: sra         $v1, $v1, 7
    ctx->r3 = S32(SIGNED(ctx->r3) >> 7);
    // 0x8000DBD0: blez        $v1, L_8000DBE0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000DBD4: nop
    
            goto L_8000DBE0;
    }
    // 0x8000DBD4: nop

    // 0x8000DBD8: b           L_8000DC18
    // 0x8000DBDC: subu        $t8, $t3, $v1
    ctx->r24 = SUB32(ctx->r11, ctx->r3);
        goto L_8000DC18;
    // 0x8000DBDC: subu        $t8, $t3, $v1
    ctx->r24 = SUB32(ctx->r11, ctx->r3);
L_8000DBE0:
    // 0x8000DBE0: b           L_8000DC14
    // 0x8000DBE4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
        goto L_8000DC14;
    // 0x8000DBE4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_8000DBE8:
    // 0x8000DBE8: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000DBEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DBF0: mflo        $v1
    ctx->r3 = lo;
    // 0x8000DBF4: sra         $v1, $v1, 7
    ctx->r3 = S32(SIGNED(ctx->r3) >> 7);
    // 0x8000DBF8: bgez        $v1, L_8000DC08
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000DBFC: nop
    
            goto L_8000DC08;
    }
    // 0x8000DBFC: nop

    // 0x8000DC00: b           L_8000DC08
    // 0x8000DC04: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8000DC08;
    // 0x8000DC04: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000DC08:
    // 0x8000DC08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000DC0C: b           L_8000DC14
    // 0x8000DC10: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
        goto L_8000DC14;
    // 0x8000DC10: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8000DC14:
    // 0x8000DC14: subu        $t8, $t3, $v1
    ctx->r24 = SUB32(ctx->r11, ctx->r3);
L_8000DC18:
    // 0x8000DC18: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8000DC1C: subu        $t9, $t4, $t2
    ctx->r25 = SUB32(ctx->r12, ctx->r10);
    // 0x8000DC20: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8000DC24: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8000DC28: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x8000DC2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000DC30: lui         $t6, 0xF100
    ctx->r14 = S32(0XF100 << 16);
    // 0x8000DC34: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x8000DC38: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000DC3C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8000DC40: andi        $t9, $t1, 0xFFFF
    ctx->r25 = ctx->r9 & 0XFFFF;
    // 0x8000DC44: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000DC48: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8000DC4C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8000DC50: jr          $ra
    // 0x8000DC54: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    return;
    // 0x8000DC54: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000DC58: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DC5C: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x8000DC60: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    // 0x8000DC64: beql        $v1, $a1, L_8000DC94
    if (ctx->r3 == ctx->r5) {
        // 0x8000DC68: lbu         $t9, 0x19($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X19);
            goto L_8000DC94;
    }
    goto skip_1;
    // 0x8000DC68: lbu         $t9, 0x19($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X19);
    skip_1:
    // 0x8000DC6C: sw          $v1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r3;
    // 0x8000DC70: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DC74: sb          $zero, 0x18($t6)
    MEM_B(0X18, ctx->r14) = 0;
    // 0x8000DC78: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DC7C: sb          $zero, 0x19($t7)
    MEM_B(0X19, ctx->r15) = 0;
    // 0x8000DC80: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DC84: sb          $zero, 0x1A($t8)
    MEM_B(0X1A, ctx->r24) = 0;
    // 0x8000DC88: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DC8C: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    // 0x8000DC90: lbu         $t9, 0x19($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X19);
L_8000DC94:
    // 0x8000DC94: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8000DC98: addu        $v1, $a1, $t0
    ctx->r3 = ADD32(ctx->r5, ctx->r8);
    // 0x8000DC9C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8000DCA0: sw          $t1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r9;
    // 0x8000DCA4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DCA8: lbu         $t2, 0x18($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X18);
    // 0x8000DCAC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8000DCB0: sb          $t3, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r11;
    // 0x8000DCB4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DCB8: lbu         $t5, 0x4($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X4);
    // 0x8000DCBC: lbu         $t4, 0x18($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X18);
    // 0x8000DCC0: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000DCC4: beql        $at, $zero, L_8000DCD8
    if (ctx->r1 == 0) {
        // 0x8000DCC8: sb          $zero, 0x18($v0)
        MEM_B(0X18, ctx->r2) = 0;
            goto L_8000DCD8;
    }
    goto skip_2;
    // 0x8000DCC8: sb          $zero, 0x18($v0)
    MEM_B(0X18, ctx->r2) = 0;
    skip_2:
    // 0x8000DCCC: jr          $ra
    // 0x8000DCD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000DCD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DCD4: sb          $zero, 0x18($v0)
    MEM_B(0X18, ctx->r2) = 0;
L_8000DCD8:
    // 0x8000DCD8: lbu         $a2, 0xC($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0XC);
    // 0x8000DCDC: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x8000DCE0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8000DCE4: beq         $a2, $at, L_8000DD78
    if (ctx->r6 == ctx->r1) {
        // 0x8000DCE8: addiu       $at, $zero, 0xFE
        ctx->r1 = ADD32(0, 0XFE);
            goto L_8000DD78;
    }
    // 0x8000DCE8: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x8000DCEC: beq         $a2, $at, L_8000DD1C
    if (ctx->r6 == ctx->r1) {
        // 0x8000DCF0: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_8000DD1C;
    }
    // 0x8000DCF0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8000DCF4: beq         $a2, $at, L_8000DD14
    if (ctx->r6 == ctx->r1) {
        // 0x8000DCF8: nop
    
            goto L_8000DD14;
    }
    // 0x8000DCF8: nop

    // 0x8000DCFC: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DD00: lbu         $t6, 0x19($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X19);
    // 0x8000DD04: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8000DD08: sb          $t7, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r15;
    // 0x8000DD0C: jr          $ra
    // 0x8000DD10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000DD10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DD14:
    // 0x8000DD14: jr          $ra
    // 0x8000DD18: addiu       $v0, $zero, 0x81
    ctx->r2 = ADD32(0, 0X81);
    return;
    // 0x8000DD18: addiu       $v0, $zero, 0x81
    ctx->r2 = ADD32(0, 0X81);
L_8000DD1C:
    // 0x8000DD1C: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DD20: lbu         $t8, 0x1A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1A);
    // 0x8000DD24: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8000DD28: sb          $t9, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r25;
    // 0x8000DD2C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8000DD30: beql        $a1, $zero, L_8000DD50
    if (ctx->r5 == 0) {
        // 0x8000DD34: lw          $t0, 0x2C($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X2C);
            goto L_8000DD50;
    }
    goto skip_3;
    // 0x8000DD34: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    skip_3:
    // 0x8000DD38: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DD3C: lbu         $v1, 0x1A($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1A);
    // 0x8000DD40: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8000DD44: beq         $at, $zero, L_8000DD60
    if (ctx->r1 == 0) {
        // 0x8000DD48: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_8000DD60;
    }
    // 0x8000DD48: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8000DD4C: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
L_8000DD50:
    // 0x8000DD50: sb          $zero, 0x19($t0)
    MEM_B(0X19, ctx->r8) = 0;
    // 0x8000DD54: lw          $t1, 0x2C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DD58: jr          $ra
    // 0x8000DD5C: lbu         $v0, 0x1A($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1A);
    return;
    // 0x8000DD5C: lbu         $v0, 0x1A($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1A);
L_8000DD60:
    // 0x8000DD60: ori         $a1, $a2, 0x80
    ctx->r5 = ctx->r6 | 0X80;
    // 0x8000DD64: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x8000DD68: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8000DD6C: sb          $t2, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r10;
    // 0x8000DD70: jr          $ra
    // 0x8000DD74: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x8000DD74: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8000DD78:
    // 0x8000DD78: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x8000DD7C: lw          $t3, 0x2C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DD80: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8000DD84: sw          $a2, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->r6;
    // 0x8000DD88: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DD8C: sw          $a2, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r6;
    // 0x8000DD90: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DD94: sb          $zero, 0x19($t5)
    MEM_B(0X19, ctx->r13) = 0;
    // 0x8000DD98: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8000DD9C: sb          $zero, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = 0;
    // 0x8000DDA0: jr          $ra
    // 0x8000DDA4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x8000DDA4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8000DDA8: nop

    // 0x8000DDAC: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000ddb0(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000ddb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DDB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000DDB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000DDB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000DDBC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000DDC0: jal         0x80001FE8
    // 0x8000DDC4: sb          $t6, -0x23E8($at)
    MEM_B(-0X23E8, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x80001FE8)(rdram, ctx);
        goto after_0;
    // 0x8000DDC4: sb          $t6, -0x23E8($at)
    MEM_B(-0X23E8, ctx->r1) = ctx->r14;
    after_0:
    // 0x8000DDC8: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8000DDCC: beq         $v1, $zero, L_8000DDE0
    if (ctx->r3 == 0) {
        // 0x8000DDD0: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_8000DDE0;
    }
    // 0x8000DDD0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_8000DDD4:
    // 0x8000DDD4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000DDD8: bne         $v0, $zero, L_8000DDD4
    if (ctx->r2 != 0) {
        // 0x8000DDDC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8000DDD4;
    }
    // 0x8000DDDC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8000DDE0:
    // 0x8000DDE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000DDE4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000DDE8: sb          $zero, -0x23E8($at)
    MEM_B(-0X23E8, ctx->r1) = 0;
    // 0x8000DDEC: jr          $ra
    // 0x8000DDF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000DDF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000ddf4(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000ddf4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DDF4: addiu       $sp, $sp, -0x1D0
    ctx->r29 = ADD32(ctx->r29, -0X1D0);
    // 0x8000DDF8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000DDFC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000DE00: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000DE04: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000DE08: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000DE0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000DE10: sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
    // 0x8000DE14: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000DE18: lhu         $s2, 0x0($a1)
    ctx->r18 = MEM_HU(ctx->r5, 0X0);
    // 0x8000DE1C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8000DE20: jal         0x80005E44
    // 0x8000DE24: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x8000DE24: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    after_0:
    // 0x8000DE28: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000DE2C: beq         $v0, $zero, L_8000DE9C
    if (ctx->r2 == 0) {
        // 0x8000DE30: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_8000DE9C;
    }
    // 0x8000DE30: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8000DE34: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x8000DE38: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8000DE3C: bne         $at, $zero, L_8000DEA4
    if (ctx->r1 != 0) {
        // 0x8000DE40: or          $s3, $s2, $zero
        ctx->r19 = ctx->r18 | 0;
            goto L_8000DEA4;
    }
    // 0x8000DE40: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x8000DE44: addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
L_8000DE48:
    // 0x8000DE48: lhu         $t6, 0x0($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X0);
    // 0x8000DE4C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000DE50: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x8000DE54: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000DE58: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x8000DE5C: jal         0x80005FAC
    // 0x8000DE60: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_1;
    // 0x8000DE60: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    after_1:
    // 0x8000DE64: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8000DE68: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x8000DE6C: bne         $v0, $zero, L_8000DE80
    if (ctx->r2 != 0) {
        // 0x8000DE70: sw          $v0, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r2;
            goto L_8000DE80;
    }
    // 0x8000DE70: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8000DE74: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000DE78: b           L_8000DEA4
    // 0x8000DE7C: sh          $t1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r9;
        goto L_8000DEA4;
    // 0x8000DE7C: sh          $t1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r9;
L_8000DE80:
    // 0x8000DE80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000DE84: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x8000DE88: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000DE8C: bne         $at, $zero, L_8000DE48
    if (ctx->r1 != 0) {
        // 0x8000DE90: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_8000DE48;
    }
    // 0x8000DE90: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000DE94: b           L_8000DEA8
    // 0x8000DE98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8000DEA8;
    // 0x8000DE98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000DE9C:
    // 0x8000DE9C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000DEA0: sh          $t2, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r10;
L_8000DEA4:
    // 0x8000DEA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000DEA8:
    // 0x8000DEA8: lhu         $v0, 0x3A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X3A);
    // 0x8000DEAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000DEB0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DEB4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000DEB8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000DEBC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000DEC0: jr          $ra
    // 0x8000DEC4: addiu       $sp, $sp, 0x1D0
    ctx->r29 = ADD32(ctx->r29, 0X1D0);
    return;
    // 0x8000DEC4: addiu       $sp, $sp, 0x1D0
    ctx->r29 = ADD32(ctx->r29, 0X1D0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000dec8(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000dec8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DEC8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000DECC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000DED0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000DED4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000DED8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8000DEDC: lhu         $a0, 0x2($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X2);
    // 0x8000DEE0: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    // 0x8000DEE4: jal         0x8000522C
    // 0x8000DEE8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_0;
    // 0x8000DEE8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000DEEC: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x8000DEF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000DEF4: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8000DEF8: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x8000DEFC: beql        $v0, $t6, L_8000DF1C
    if (ctx->r2 == ctx->r14) {
        // 0x8000DF00: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_8000DF1C;
    }
    goto skip_0;
    // 0x8000DF00: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8000DF04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000DF08: nop

    // 0x8000DF0C: swc1        $f4, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f4.u32l;
    // 0x8000DF10: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8000DF14: sw          $v0, 0x54($t7)
    MEM_W(0X54, ctx->r15) = ctx->r2;
    // 0x8000DF18: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_8000DF1C:
    // 0x8000DF1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000DF20: lhu         $v1, 0x0($t8)
    ctx->r3 = MEM_HU(ctx->r24, 0X0);
    // 0x8000DF24: andi        $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 & 0X7FFF;
    // 0x8000DF28: beql        $v1, $zero, L_8000DF40
    if (ctx->r3 == 0) {
        // 0x8000DF2C: lwc1        $f8, 0x0($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8000DF40;
    }
    goto skip_1;
    // 0x8000DF2C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x8000DF30: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8000DF34: b           L_8000DF4C
    // 0x8000DF38: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
        goto L_8000DF4C;
    // 0x8000DF38: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000DF3C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
L_8000DF40:
    // 0x8000DF40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000DF44: nop

    // 0x8000DF48: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
L_8000DF4C:
    // 0x8000DF4C: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8000DF50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000DF54: bc1tl       L_8000DFC4
    if (c1cs) {
        // 0x8000DF58: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8000DFC4;
    }
    goto skip_2;
    // 0x8000DF58: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_2:
    // 0x8000DF5C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000DF60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000DF64: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x8000DF68: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000DF6C: lwc1        $f4, 0x50($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X50);
    // 0x8000DF70: div.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8000DF74: mul.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8000DF78: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8000DF7C: nop

    // 0x8000DF80: bc1fl       L_8000DF90
    if (!c1cs) {
        // 0x8000DF84: trunc.w.s   $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_8000DF90;
    }
    goto skip_3;
    // 0x8000DF84: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_3:
    // 0x8000DF88: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8000DF8C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
L_8000DF90:
    // 0x8000DF90: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8000DF94: nop

    // 0x8000DF98: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x8000DF9C: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x8000DFA0: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x8000DFA4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000DFA8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8000DFAC: addu        $a2, $t1, $v0
    ctx->r6 = ADD32(ctx->r9, ctx->r2);
    // 0x8000DFB0: addiu       $v1, $a2, 0x4
    ctx->r3 = ADD32(ctx->r6, 0X4);
    // 0x8000DFB4: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8000DFB8: b           L_8000DFC8
    // 0x8000DFBC: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
        goto L_8000DFC8;
    // 0x8000DFBC: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8000DFC0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8000DFC4:
    // 0x8000DFC4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8000DFC8:
    // 0x8000DFC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000DFCC: nop

    // 0x8000DFD0: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x8000DFD4: nop

    // 0x8000DFD8: bc1tl       L_8000E15C
    if (c1cs) {
        // 0x8000DFDC: lwc1        $f6, 0x0($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
            goto L_8000E15C;
    }
    goto skip_4;
    // 0x8000DFDC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    skip_4:
    // 0x8000DFE0: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000DFE4: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000DFE8: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8000DFEC: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8000DFF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000DFF4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8000DFF8: jal         0x80015214
    // 0x8000DFFC: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    LOOKUP_FUNC(0x80015214)(rdram, ctx);
        goto after_1;
    // 0x8000DFFC: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_1:
    // 0x8000E000: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E004: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8000E008: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E00C: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8000E010: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000E014: ldc1        $f14, -0x3840($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X3840);
    // 0x8000E018: lw          $t4, 0x2C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X2C);
    // 0x8000E01C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E020: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000E024: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000E028: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000E02C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000E030: div.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f14.d);
    // 0x8000E034: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8000E038: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8000E03C: nop

    // 0x8000E040: sh          $t3, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r11;
    // 0x8000E044: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000E048: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000E04C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000E050: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8000E054: jal         0x80015214
    // 0x8000E058: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    LOOKUP_FUNC(0x80015214)(rdram, ctx);
        goto after_2;
    // 0x8000E058: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_2:
    // 0x8000E05C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E060: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8000E064: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E068: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8000E06C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000E070: ldc1        $f14, -0x3838($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X3838);
    // 0x8000E074: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8000E078: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E07C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000E080: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000E084: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000E088: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000E08C: div.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f14.d);
    // 0x8000E090: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8000E094: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8000E098: nop

    // 0x8000E09C: sh          $t6, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r14;
    // 0x8000E0A0: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000E0A4: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000E0A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000E0AC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8000E0B0: jal         0x80015214
    // 0x8000E0B4: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    LOOKUP_FUNC(0x80015214)(rdram, ctx);
        goto after_3;
    // 0x8000E0B4: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_3:
    // 0x8000E0B8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E0BC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8000E0C0: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E0C4: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8000E0C8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000E0CC: ldc1        $f14, -0x3830($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X3830);
    // 0x8000E0D0: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x8000E0D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E0D8: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000E0DC: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8000E0E0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000E0E4: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x8000E0E8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000E0EC: div.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f14.d);
    // 0x8000E0F0: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8000E0F4: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8000E0F8: nop

    // 0x8000E0FC: sh          $t9, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r25;
    // 0x8000E100: lwc1        $f2, -0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X8);
    // 0x8000E104: lwc1        $f6, -0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, -0X8);
    // 0x8000E108: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x8000E10C: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8000E110: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000E114: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8000E118: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x8000E11C: lwc1        $f2, -0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X4);
    // 0x8000E120: lwc1        $f6, -0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, -0X4);
    // 0x8000E124: lw          $t2, 0x2C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X2C);
    // 0x8000E128: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8000E12C: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000E130: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8000E134: swc1        $f4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f4.u32l;
    // 0x8000E138: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000E13C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000E140: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x8000E144: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8000E148: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000E14C: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8000E150: b           L_8000E1E4
    // 0x8000E154: swc1        $f4, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f4.u32l;
        goto L_8000E1E4;
    // 0x8000E154: swc1        $f4, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f4.u32l;
    // 0x8000E158: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
L_8000E15C:
    // 0x8000E15C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E160: ldc1        $f14, -0x3828($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X3828);
    // 0x8000E164: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000E168: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x8000E16C: div.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f14.d);
    // 0x8000E170: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8000E174: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8000E178: nop

    // 0x8000E17C: sh          $t5, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r13;
    // 0x8000E180: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8000E184: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x8000E188: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000E18C: div.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f14.d);
    // 0x8000E190: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8000E194: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8000E198: nop

    // 0x8000E19C: sh          $t8, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r24;
    // 0x8000E1A0: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8000E1A4: lw          $t2, 0x2C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X2C);
    // 0x8000E1A8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000E1AC: div.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f14.d);
    // 0x8000E1B0: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8000E1B4: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8000E1B8: nop

    // 0x8000E1BC: sh          $t1, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r9;
    // 0x8000E1C0: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x8000E1C4: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8000E1C8: swc1        $f6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f6.u32l;
    // 0x8000E1CC: lw          $t4, 0x2C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X2C);
    // 0x8000E1D0: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8000E1D4: swc1        $f8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f8.u32l;
    // 0x8000E1D8: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    // 0x8000E1DC: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8000E1E0: swc1        $f10, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f10.u32l;
L_8000E1E4:
    // 0x8000E1E4: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x8000E1E8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E1EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E1F0: lwc1        $f0, 0x50($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X50);
    // 0x8000E1F4: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x8000E1F8: nop

    // 0x8000E1FC: bc1fl       L_8000E244
    if (!c1cs) {
        // 0x8000E200: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8000E244;
    }
    goto skip_5;
    // 0x8000E200: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_5:
    // 0x8000E204: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8000E208: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000E20C: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8000E210: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8000E214: nop

    // 0x8000E218: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000E21C: c.eq.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl == ctx->f6.fl;
    // 0x8000E220: nop

    // 0x8000E224: bc1t        L_8000E238
    if (c1cs) {
        // 0x8000E228: nop
    
            goto L_8000E238;
    }
    // 0x8000E228: nop

    // 0x8000E22C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000E230: nop

    // 0x8000E234: swc1        $f8, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f8.u32l;
L_8000E238:
    // 0x8000E238: b           L_8000E250
    // 0x8000E23C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000E250;
    // 0x8000E23C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000E240: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8000E244:
    // 0x8000E244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000E248: add.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8000E24C: swc1        $f4, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f4.u32l;
L_8000E250:
    // 0x8000E250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E254: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000E258: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000E25C: jr          $ra
    // 0x8000E260: nop

    return;
    // 0x8000E260: nop

;}
RECOMP_FUNC void FUN_8000e264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E264: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000E268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E26C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8000E270: lhu         $a2, 0x2($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X2);
    // 0x8000E274: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000E278: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8000E27C: beq         $a2, $zero, L_8000E29C
    if (ctx->r6 == 0) {
        // 0x8000E280: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8000E29C;
    }
    // 0x8000E280: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8000E284: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    // 0x8000E288: jal         0x8000522C
    // 0x8000E28C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_0;
    // 0x8000E28C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000E290: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8000E294: b           L_8000E2A0
    // 0x8000E298: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8000E2A0;
    // 0x8000E298: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8000E29C:
    // 0x8000E29C: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
L_8000E2A0:
    // 0x8000E2A0: lw          $v1, 0x2C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X2C);
    // 0x8000E2A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8000E2A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E2AC: lw          $t8, 0x54($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X54);
    // 0x8000E2B0: addiu       $a0, $a1, 0x4
    ctx->r4 = ADD32(ctx->r5, 0X4);
    // 0x8000E2B4: beql        $a1, $t8, L_8000E2D4
    if (ctx->r5 == ctx->r24) {
        // 0x8000E2B8: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_8000E2D4;
    }
    goto skip_0;
    // 0x8000E2B8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8000E2BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000E2C0: nop

    // 0x8000E2C4: swc1        $f18, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f18.u32l;
    // 0x8000E2C8: lw          $t9, 0x2C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X2C);
    // 0x8000E2CC: sw          $a1, 0x54($t9)
    MEM_W(0X54, ctx->r25) = ctx->r5;
    // 0x8000E2D0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
L_8000E2D4:
    // 0x8000E2D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000E2D8: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x8000E2DC: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // 0x8000E2E0: beql        $v0, $zero, L_8000E2F8
    if (ctx->r2 == 0) {
        // 0x8000E2E4: lwc1        $f6, 0x0($a1)
        ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
            goto L_8000E2F8;
    }
    goto skip_1;
    // 0x8000E2E4: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    skip_1:
    // 0x8000E2E8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000E2EC: b           L_8000E304
    // 0x8000E2F0: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
        goto L_8000E304;
    // 0x8000E2F0: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000E2F4: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
L_8000E2F8:
    // 0x8000E2F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000E2FC: nop

    // 0x8000E300: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
L_8000E304:
    // 0x8000E304: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8000E308: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8000E30C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8000E310: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E314: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8000E318: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000E31C: bc1fl       L_8000E394
    if (!c1cs) {
        // 0x8000E320: mov.s       $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
            goto L_8000E394;
    }
    goto skip_2;
    // 0x8000E320: mov.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
    skip_2:
    // 0x8000E324: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000E328: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000E32C: lw          $t1, 0x2C($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X2C);
    // 0x8000E330: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000E334: lwc1        $f4, 0x50($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X50);
    // 0x8000E338: div.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8000E33C: mul.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8000E340: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000E344: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8000E348: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8000E34C: nop

    // 0x8000E350: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x8000E354: nop

    // 0x8000E358: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000E35C: bc1f        L_8000E374
    if (!c1cs) {
        // 0x8000E360: sub.s       $f14, $f0, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f10.fl;
            goto L_8000E374;
    }
    // 0x8000E360: sub.s       $f14, $f0, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8000E364: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8000E368: mov.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
    // 0x8000E36C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8000E370: nop

L_8000E374:
    // 0x8000E374: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x8000E378: subu        $t4, $t4, $a2
    ctx->r12 = SUB32(ctx->r12, ctx->r6);
    // 0x8000E37C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8000E380: addu        $v1, $t4, $a1
    ctx->r3 = ADD32(ctx->r12, ctx->r5);
    // 0x8000E384: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x8000E388: b           L_8000E394
    // 0x8000E38C: addiu       $a0, $v1, 0x10
    ctx->r4 = ADD32(ctx->r3, 0X10);
        goto L_8000E394;
    // 0x8000E38C: addiu       $a0, $v1, 0x10
    ctx->r4 = ADD32(ctx->r3, 0X10);
    // 0x8000E390: mov.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
L_8000E394:
    // 0x8000E394: c.eq.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl == ctx->f18.fl;
    // 0x8000E398: nop

    // 0x8000E39C: bc1tl       L_8000E4CC
    if (c1cs) {
        // 0x8000E3A0: lwc1        $f6, 0x0($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8000E4CC;
    }
    goto skip_3;
    // 0x8000E3A0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    skip_3:
    // 0x8000E3A4: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000E3A8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E3AC: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8000E3B0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8000E3B4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8000E3B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000E3BC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000E3C0: jal         0x80015214
    // 0x8000E3C4: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    LOOKUP_FUNC(0x80015214)(rdram, ctx);
        goto after_1;
    // 0x8000E3C4: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_1:
    // 0x8000E3C8: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E3CC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E3D0: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E3D4: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8000E3D8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E3DC: ldc1        $f2, -0x3820($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X3820);
    // 0x8000E3E0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8000E3E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000E3E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000E3EC: lw          $t7, 0x2C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X2C);
    // 0x8000E3F0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000E3F4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000E3F8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000E3FC: div.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f2.d);
    // 0x8000E400: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8000E404: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8000E408: nop

    // 0x8000E40C: sh          $t6, 0x10($t7)
    MEM_H(0X10, ctx->r15) = ctx->r14;
    // 0x8000E410: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E414: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000E418: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000E41C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000E420: jal         0x80015214
    // 0x8000E424: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    LOOKUP_FUNC(0x80015214)(rdram, ctx);
        goto after_2;
    // 0x8000E424: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_2:
    // 0x8000E428: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E42C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E430: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E434: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8000E438: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E43C: ldc1        $f2, -0x3818($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X3818);
    // 0x8000E440: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8000E444: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000E448: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000E44C: lw          $t0, 0x2C($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X2C);
    // 0x8000E450: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000E454: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000E458: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000E45C: div.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f2.d);
    // 0x8000E460: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8000E464: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8000E468: nop

    // 0x8000E46C: sh          $t9, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r25;
    // 0x8000E470: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E474: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000E478: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000E47C: jal         0x80015214
    // 0x8000E480: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    LOOKUP_FUNC(0x80015214)(rdram, ctx);
        goto after_3;
    // 0x8000E480: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_3:
    // 0x8000E484: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E488: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E48C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E490: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8000E494: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E498: ldc1        $f2, -0x3810($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X3810);
    // 0x8000E49C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8000E4A0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E4A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000E4A8: lw          $t3, 0x2C($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X2C);
    // 0x8000E4AC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000E4B0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000E4B4: div.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f2.d);
    // 0x8000E4B8: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8000E4BC: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8000E4C0: b           L_8000E530
    // 0x8000E4C4: sh          $t2, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r10;
        goto L_8000E530;
    // 0x8000E4C4: sh          $t2, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r10;
    // 0x8000E4C8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
L_8000E4CC:
    // 0x8000E4CC: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E4D0: ldc1        $f2, -0x3808($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X3808);
    // 0x8000E4D4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000E4D8: lw          $t6, 0x2C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X2C);
    // 0x8000E4DC: div.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f2.d);
    // 0x8000E4E0: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8000E4E4: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8000E4E8: nop

    // 0x8000E4EC: sh          $t5, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r13;
    // 0x8000E4F0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000E4F4: lw          $t9, 0x2C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X2C);
    // 0x8000E4F8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000E4FC: div.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f2.d);
    // 0x8000E500: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8000E504: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8000E508: nop

    // 0x8000E50C: sh          $t8, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r24;
    // 0x8000E510: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000E514: lw          $t2, 0x2C($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X2C);
    // 0x8000E518: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000E51C: div.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f2.d);
    // 0x8000E520: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8000E524: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8000E528: nop

    // 0x8000E52C: sh          $t1, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r9;
L_8000E530:
    // 0x8000E530: lw          $v1, 0x2C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X2C);
    // 0x8000E534: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8000E538: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E53C: lwc1        $f0, 0x50($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X50);
    // 0x8000E540: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x8000E544: nop

    // 0x8000E548: bc1fl       L_8000E570
    if (!c1cs) {
        // 0x8000E54C: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8000E570;
    }
    goto skip_4;
    // 0x8000E54C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_4:
    // 0x8000E550: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8000E554: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x8000E558: beq         $t5, $zero, L_8000E564
    if (ctx->r13 == 0) {
        // 0x8000E55C: nop
    
            goto L_8000E564;
    }
    // 0x8000E55C: nop

    // 0x8000E560: swc1        $f18, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f18.u32l;
L_8000E564:
    // 0x8000E564: b           L_8000E57C
    // 0x8000E568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000E57C;
    // 0x8000E568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000E56C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8000E570:
    // 0x8000E570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000E574: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8000E578: swc1        $f8, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f8.u32l;
L_8000E57C:
    // 0x8000E57C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E580: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8000E584: jr          $ra
    // 0x8000E588: nop

    return;
    // 0x8000E588: nop

;}
RECOMP_FUNC void FUN_8000e58c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E58C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8000E590: and         $t6, $a0, $at
    ctx->r14 = ctx->r4 & ctx->r1;
    // 0x8000E594: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x8000E598: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8000E59C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000E5A0: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8000E5A4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8000E5A8: lw          $t0, 0x1CEC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1CEC);
    // 0x8000E5AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E5B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E5B4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000E5B8: jal         0x8000511C
    // 0x8000E5BC: lhu         $a0, 0x0($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X0);
    LOOKUP_FUNC(0x8000511C)(rdram, ctx);
        goto after_0;
    // 0x8000E5BC: lhu         $a0, 0x0($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X0);
    after_0:
    // 0x8000E5C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E5C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000E5C8: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8000E5CC: jr          $ra
    // 0x8000E5D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000E5D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000e5d4(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000e5d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E5D4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8000E5D8: and         $t7, $a0, $at
    ctx->r15 = ctx->r4 & ctx->r1;
    // 0x8000E5DC: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x8000E5E0: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8000E5E4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8000E5E8: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8000E5EC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8000E5F0: lw          $t1, 0x1CEC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1CEC);
    // 0x8000E5F4: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x8000E5F8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8000E5FC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8000E600: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8000E604: addiu       $t6, $t6, 0x31E0
    ctx->r14 = ADD32(ctx->r14, 0X31E0);
    // 0x8000E608: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x8000E60C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000E610: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8000E614: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8000E618: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8000E61C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8000E620: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x8000E624: sw          $t0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r8;
    // 0x8000E628: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000E62C: jr          $ra
    // 0x8000E630: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    return;
    // 0x8000E630: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000e634(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000e634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E63C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000E640: jal         0x8000E5D4
    // 0x8000E644: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    LOOKUP_FUNC(0x8000E5D4)(rdram, ctx);
        goto after_0;
    // 0x8000E644: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8000E648: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8000E64C: lhu         $t7, 0x31EA($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X31EA);
    // 0x8000E650: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8000E654: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8000E658: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8000E65C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8000E660: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8000E664: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000E668: bgez        $t9, L_8000E680
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000E66C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8000E680;
    }
    // 0x8000E66C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000E670: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000E674: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000E678: nop

    // 0x8000E67C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8000E680:
    // 0x8000E680: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8000E684: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8000E688: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8000E68C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8000E690: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000E694: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000E698: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8000E69C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000E6A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000E6A4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8000E6A8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8000E6AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E6B0: mul.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8000E6B4: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8000E6B8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000E6BC: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8000E6C0: nop

    // 0x8000E6C4: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x8000E6C8: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8000E6CC: nop

    // 0x8000E6D0: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8000E6D4: beql        $v0, $zero, L_8000E728
    if (ctx->r2 == 0) {
        // 0x8000E6D8: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_8000E728;
    }
    goto skip_0;
    // 0x8000E6D8: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x8000E6DC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8000E6E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000E6E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000E6E8: sub.d       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f10.d - ctx->f16.d;
    // 0x8000E6EC: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8000E6F0: nop

    // 0x8000E6F4: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x8000E6F8: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8000E6FC: nop

    // 0x8000E700: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8000E704: bne         $v0, $zero, L_8000E71C
    if (ctx->r2 != 0) {
        // 0x8000E708: nop
    
            goto L_8000E71C;
    }
    // 0x8000E708: nop

    // 0x8000E70C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8000E710: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000E714: b           L_8000E734
    // 0x8000E718: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_8000E734;
    // 0x8000E718: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_8000E71C:
    // 0x8000E71C: b           L_8000E734
    // 0x8000E720: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000E734;
    // 0x8000E720: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000E724: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_8000E728:
    // 0x8000E728: nop

    // 0x8000E72C: bltz        $v0, L_8000E71C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000E730: nop
    
            goto L_8000E71C;
    }
    // 0x8000E730: nop

L_8000E734:
    // 0x8000E734: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000E738: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000E73C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000E740: jr          $ra
    // 0x8000E744: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000E744: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000e748(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000e748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E748: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E74C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E750: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000E754: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8000E758: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8000E75C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8000E760: jal         0x8000E5D4
    // 0x8000E764: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8000E5D4)(rdram, ctx);
        goto after_0;
    // 0x8000E764: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000E768: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x8000E76C: addiu       $a0, $a0, 0x31E0
    ctx->r4 = ADD32(ctx->r4, 0X31E0);
    // 0x8000E770: lhu         $t7, 0xA($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XA);
    // 0x8000E774: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8000E778: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8000E77C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8000E780: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8000E784: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8000E788: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8000E78C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E790: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8000E794: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8000E798: bgez        $t9, L_8000E7B0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000E79C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8000E7B0;
    }
    // 0x8000E79C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000E7A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000E7A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000E7A8: nop

    // 0x8000E7AC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8000E7B0:
    // 0x8000E7B0: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8000E7B4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8000E7B8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8000E7BC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8000E7C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000E7C4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000E7C8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8000E7CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000E7D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000E7D4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8000E7D8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8000E7DC: mul.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8000E7E0: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8000E7E4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8000E7E8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000E7EC: nop

    // 0x8000E7F0: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x8000E7F4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000E7F8: nop

    // 0x8000E7FC: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8000E800: beql        $t1, $zero, L_8000E854
    if (ctx->r9 == 0) {
        // 0x8000E804: mfc1        $t1, $f16
        ctx->r9 = (int32_t)ctx->f16.u32l;
            goto L_8000E854;
    }
    goto skip_0;
    // 0x8000E804: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x8000E808: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8000E80C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000E810: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000E814: sub.d       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f10.d - ctx->f16.d;
    // 0x8000E818: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000E81C: nop

    // 0x8000E820: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x8000E824: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000E828: nop

    // 0x8000E82C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8000E830: bne         $t1, $zero, L_8000E848
    if (ctx->r9 != 0) {
        // 0x8000E834: nop
    
            goto L_8000E848;
    }
    // 0x8000E834: nop

    // 0x8000E838: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x8000E83C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000E840: b           L_8000E860
    // 0x8000E844: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_8000E860;
    // 0x8000E844: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8000E848:
    // 0x8000E848: b           L_8000E860
    // 0x8000E84C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_8000E860;
    // 0x8000E84C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8000E850: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
L_8000E854:
    // 0x8000E854: nop

    // 0x8000E858: bltz        $t1, L_8000E848
    if (SIGNED(ctx->r9) < 0) {
        // 0x8000E85C: nop
    
            goto L_8000E848;
    }
    // 0x8000E85C: nop

L_8000E860:
    // 0x8000E860: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8000E864: lhu         $t3, 0xA($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0XA);
    // 0x8000E868: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8000E86C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8000E870: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x8000E874: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x8000E878: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x8000E87C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8000E880: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8000E884: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000E888: blez        $v0, L_8000E898
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000E88C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8000E898;
    }
    // 0x8000E88C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8000E890: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x8000E894: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
L_8000E898:
    // 0x8000E898: lhu         $t8, 0x8($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X8);
    // 0x8000E89C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8000E8A0: bgez        $t8, L_8000E8B4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8000E8A4: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8000E8B4;
    }
    // 0x8000E8A4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000E8A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000E8AC: nop

    // 0x8000E8B0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8000E8B4:
    // 0x8000E8B4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8000E8B8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8000E8BC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8000E8C0: sub.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d - ctx->f10.d;
    // 0x8000E8C4: beq         $v0, $zero, L_8000E95C
    if (ctx->r2 == 0) {
        // 0x8000E8C8: cvt.s.d     $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
            goto L_8000E95C;
    }
    // 0x8000E8C8: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x8000E8CC: lhu         $t9, 0x4($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X4);
    // 0x8000E8D0: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8000E8D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000E8D8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8000E8DC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000E8E0: bgez        $t9, L_8000E8F4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000E8E4: cvt.s.w     $f8, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8000E8F4;
    }
    // 0x8000E8E4: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000E8E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000E8EC: nop

    // 0x8000E8F0: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_8000E8F4:
    // 0x8000E8F4: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8000E8F8: bgez        $v0, L_8000E90C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000E8FC: lui         $at, 0x4F80
        ctx->r1 = S32(0X4F80 << 16);
            goto L_8000E90C;
    }
    // 0x8000E8FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000E900: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000E904: nop

    // 0x8000E908: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8000E90C:
    // 0x8000E90C: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8000E910: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8000E914: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000E918: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8000E91C: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8000E920: nop

    // 0x8000E924: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8000E928: nop

    // 0x8000E92C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000E930: sub.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8000E934: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x8000E938: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000E93C: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x8000E940: nop

    // 0x8000E944: bc1fl       L_8000E970
    if (!c1cs) {
        // 0x8000E948: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000E970;
    }
    goto skip_1;
    // 0x8000E948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8000E94C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000E950: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
    // 0x8000E954: b           L_8000E96C
    // 0x8000E958: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
        goto L_8000E96C;
    // 0x8000E958: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
L_8000E95C:
    // 0x8000E95C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000E960: nop

    // 0x8000E964: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8000E968: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
L_8000E96C:
    // 0x8000E96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E970:
    // 0x8000E970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000E974: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8000E978: jr          $ra
    // 0x8000E97C: nop

    return;
    // 0x8000E97C: nop

;}
RECOMP_FUNC void FUN_8000e980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E980: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000E984: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000E988: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8000E98C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8000E990: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8000E994: jal         0x8000E58C
    // 0x8000E998: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8000E58C)(rdram, ctx);
        goto after_0;
    // 0x8000E998: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000E99C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8000E9A0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8000E9A4: jal         0x8000E5D4
    // 0x8000E9A8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    LOOKUP_FUNC(0x8000E5D4)(rdram, ctx);
        goto after_1;
    // 0x8000E9A8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x8000E9AC: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8000E9B0: lbu         $t6, 0x31ED($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X31ED);
    // 0x8000E9B4: addiu       $t7, $sp, 0x32
    ctx->r15 = ADD32(ctx->r29, 0X32);
    // 0x8000E9B8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8000E9BC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8000E9C0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8000E9C4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8000E9C8: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x8000E9CC: jal         0x8000E748
    // 0x8000E9D0: sb          $t6, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8000E748)(rdram, ctx);
        goto after_2;
    // 0x8000E9D0: sb          $t6, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r14;
    after_2:
    // 0x8000E9D4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8000E9D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000E9DC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000E9E0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E9E4: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x8000E9E8: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x8000E9EC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000E9F0: addiu       $a1, $a1, 0x2D30
    ctx->r5 = ADD32(ctx->r5, 0X2D30);
    // 0x8000E9F4: addiu       $v0, $v0, 0x31E0
    ctx->r2 = ADD32(ctx->r2, 0X31E0);
    // 0x8000E9F8: lbu         $v1, 0x37($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X37);
    // 0x8000E9FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000EA00: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000EA04: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8000EA08: beql        $t9, $zero, L_8000EA58
    if (ctx->r25 == 0) {
        // 0x8000EA0C: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_8000EA58;
    }
    goto skip_0;
    // 0x8000EA0C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x8000EA10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000EA14: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000EA18: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000EA1C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000EA20: nop

    // 0x8000EA24: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8000EA28: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000EA2C: nop

    // 0x8000EA30: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8000EA34: bne         $t9, $zero, L_8000EA4C
    if (ctx->r25 != 0) {
        // 0x8000EA38: nop
    
            goto L_8000EA4C;
    }
    // 0x8000EA38: nop

    // 0x8000EA3C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8000EA40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000EA44: b           L_8000EA64
    // 0x8000EA48: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8000EA64;
    // 0x8000EA48: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8000EA4C:
    // 0x8000EA4C: b           L_8000EA64
    // 0x8000EA50: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8000EA64;
    // 0x8000EA50: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8000EA54: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_8000EA58:
    // 0x8000EA58: nop

    // 0x8000EA5C: bltz        $t9, L_8000EA4C
    if (SIGNED(ctx->r25) < 0) {
        // 0x8000EA60: nop
    
            goto L_8000EA4C;
    }
    // 0x8000EA60: nop

L_8000EA64:
    // 0x8000EA64: lbu         $t1, 0xC($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XC);
    // 0x8000EA68: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8000EA6C: lhu         $t3, 0x56($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X56);
    // 0x8000EA70: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EA74: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8000EA78: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000EA7C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000EA80: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000EA84: sll         $a2, $v1, 2
    ctx->r6 = S32(ctx->r3 << 2);
    // 0x8000EA88: subu        $a2, $a2, $v1
    ctx->r6 = SUB32(ctx->r6, ctx->r3);
    // 0x8000EA8C: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8000EA90: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8000EA94: mflo        $t2
    ctx->r10 = lo;
    // 0x8000EA98: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8000EA9C: nop

    // 0x8000EAA0: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EAA4: mflo        $t5
    ctx->r13 = lo;
    // 0x8000EAA8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8000EAAC: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8000EAB0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8000EAB4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EAB8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8000EABC: and         $t3, $t8, $at
    ctx->r11 = ctx->r24 & ctx->r1;
    // 0x8000EAC0: jal         0x8000DDB0
    // 0x8000EAC4: addu        $a0, $t3, $t5
    ctx->r4 = ADD32(ctx->r11, ctx->r13);
    LOOKUP_FUNC(0x8000DDB0)(rdram, ctx);
        goto after_3;
    // 0x8000EAC4: addu        $a0, $t3, $t5
    ctx->r4 = ADD32(ctx->r11, ctx->r13);
    after_3:
    // 0x8000EAC8: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x8000EACC: addiu       $a1, $a1, 0x2D30
    ctx->r5 = ADD32(ctx->r5, 0X2D30);
    // 0x8000EAD0: lwl         $t8, 0x0($a1)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r5, 0X0);
    // 0x8000EAD4: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x8000EAD8: lwr         $t8, 0x3($a1)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r5, 0X3);
    // 0x8000EADC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8000EAE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000EAE4: swl         $t8, 0x0($v0)
    do_swl(rdram, 0X0, ctx->r2, ctx->r24);
    // 0x8000EAE8: swr         $t8, 0x3($v0)
    do_swr(rdram, 0X3, ctx->r2, ctx->r24);
    // 0x8000EAEC: lhu         $t8, 0x4($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X4);
    // 0x8000EAF0: bne         $v1, $at, L_8000EB58
    if (ctx->r3 != ctx->r1) {
        // 0x8000EAF4: sh          $t8, 0x4($v0)
        MEM_H(0X4, ctx->r2) = ctx->r24;
            goto L_8000EB58;
    }
    // 0x8000EAF4: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x8000EAF8: lh          $t0, 0x6($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X6);
    // 0x8000EAFC: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x8000EB00: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8000EB04: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8000EB08: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000EB0C: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x8000EB10: mul.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8000EB14: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8000EB18: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x8000EB1C: lh          $t1, 0x8($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X8);
    // 0x8000EB20: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8000EB24: nop

    // 0x8000EB28: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000EB2C: mul.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8000EB30: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8000EB34: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8000EB38: lh          $t2, 0xA($a1)
    ctx->r10 = MEM_H(ctx->r5, 0XA);
    // 0x8000EB3C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8000EB40: nop

    // 0x8000EB44: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8000EB48: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8000EB4C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8000EB50: b           L_8000EB70
    // 0x8000EB54: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
        goto L_8000EB70;
    // 0x8000EB54: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
L_8000EB58:
    // 0x8000EB58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000EB5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000EB60: nop

    // 0x8000EB64: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x8000EB68: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x8000EB6C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
L_8000EB70:
    // 0x8000EB70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000EB74: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8000EB78: jr          $ra
    // 0x8000EB7C: nop

    return;
    // 0x8000EB7C: nop

;}
RECOMP_FUNC void FUN_8000eb80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EB80: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8000EB84: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8000EB88: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x8000EB8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000EB90: beq         $v0, $at, L_8000EBE0
    if (ctx->r2 == ctx->r1) {
        // 0x8000EB94: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8000EBE0;
    }
    // 0x8000EB94: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8000EB98: beql        $v0, $at, L_8000EC24
    if (ctx->r2 == ctx->r1) {
        // 0x8000EB9C: lh          $t2, 0x0($a0)
        ctx->r10 = MEM_H(ctx->r4, 0X0);
            goto L_8000EC24;
    }
    goto skip_0;
    // 0x8000EB9C: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    skip_0:
    // 0x8000EBA0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8000EBA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000EBA8: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EBAC: mflo        $t7
    ctx->r15 = lo;
    // 0x8000EBB0: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8000EBB4: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x8000EBB8: addiu       $t9, $t8, 0x2000
    ctx->r25 = ADD32(ctx->r24, 0X2000);
    // 0x8000EBBC: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x8000EBC0: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x8000EBC4: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EBC8: mflo        $t1
    ctx->r9 = lo;
    // 0x8000EBCC: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x8000EBD0: lh          $t2, 0x0($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X0);
    // 0x8000EBD4: addiu       $t3, $t2, 0x2000
    ctx->r11 = ADD32(ctx->r10, 0X2000);
    // 0x8000EBD8: jr          $ra
    // 0x8000EBDC: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    return;
    // 0x8000EBDC: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
L_8000EBE0:
    // 0x8000EBE0: lh          $t4, 0x0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X0);
    // 0x8000EBE4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000EBE8: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EBEC: mflo        $t5
    ctx->r13 = lo;
    // 0x8000EBF0: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    // 0x8000EBF4: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8000EBF8: addiu       $t7, $t6, 0x3000
    ctx->r15 = ADD32(ctx->r14, 0X3000);
    // 0x8000EBFC: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8000EC00: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x8000EC04: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EC08: mflo        $t9
    ctx->r25 = lo;
    // 0x8000EC0C: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x8000EC10: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x8000EC14: addiu       $t1, $t0, 0x3000
    ctx->r9 = ADD32(ctx->r8, 0X3000);
    // 0x8000EC18: jr          $ra
    // 0x8000EC1C: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
    return;
    // 0x8000EC1C: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
    // 0x8000EC20: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
L_8000EC24:
    // 0x8000EC24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000EC28: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EC2C: mflo        $t3
    ctx->r11 = lo;
    // 0x8000EC30: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
    // 0x8000EC34: lh          $t4, 0x0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X0);
    // 0x8000EC38: addiu       $t5, $t4, 0x200A
    ctx->r13 = ADD32(ctx->r12, 0X200A);
    // 0x8000EC3C: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    // 0x8000EC40: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8000EC44: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EC48: mflo        $t7
    ctx->r15 = lo;
    // 0x8000EC4C: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x8000EC50: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x8000EC54: addiu       $t9, $t8, 0x2000
    ctx->r25 = ADD32(ctx->r24, 0X2000);
    // 0x8000EC58: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x8000EC5C: jr          $ra
    // 0x8000EC60: nop

    return;
    // 0x8000EC60: nop

;}
RECOMP_FUNC void FUN_8000ec64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EC64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000EC68: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8000EC6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000EC70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000EC74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000EC78: andi        $a3, $a1, 0xFFFF
    ctx->r7 = ctx->r5 & 0XFFFF;
    // 0x8000EC7C: addiu       $a1, $t6, 0x12
    ctx->r5 = ADD32(ctx->r14, 0X12);
    // 0x8000EC80: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8000EC84: jal         0x8000EB80
    // 0x8000EC88: addiu       $a2, $t6, 0x14
    ctx->r6 = ADD32(ctx->r14, 0X14);
    LOOKUP_FUNC(0x8000EB80)(rdram, ctx);
        goto after_0;
    // 0x8000EC88: addiu       $a2, $t6, 0x14
    ctx->r6 = ADD32(ctx->r14, 0X14);
    after_0:
    // 0x8000EC8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000EC90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000EC94: jr          $ra
    // 0x8000EC98: nop

    return;
    // 0x8000EC98: nop

;}
RECOMP_FUNC void FUN_8000ec9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EC9C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8000ECA0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8000ECA4: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8000ECA8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000ECAC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8000ECB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000ECB4: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8000ECB8: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8000ECBC: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8000ECC0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8000ECC4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8000ECC8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8000ECCC: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x8000ECD0: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x8000ECD4: jal         0x8000E58C
    // 0x8000ECD8: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8000E58C)(rdram, ctx);
        goto after_0;
    // 0x8000ECD8: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000ECDC: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x8000ECE0: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // 0x8000ECE4: jal         0x8000E5D4
    // 0x8000ECE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8000E5D4)(rdram, ctx);
        goto after_1;
    // 0x8000ECE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000ECEC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8000ECF0: lui         $t0, 0x8006
    ctx->r8 = S32(0X8006 << 16);
    // 0x8000ECF4: addiu       $t0, $t0, 0x31E0
    ctx->r8 = ADD32(ctx->r8, 0X31E0);
    // 0x8000ECF8: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x8000ECFC: lbu         $v1, 0xD($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XD);
    // 0x8000ED00: lbu         $a3, 0xC($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0XC);
    // 0x8000ED04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000ED08: bc1t        L_8000ED18
    if (c1cs) {
        // 0x8000ED0C: lhu         $t6, 0xAE($sp)
        ctx->r14 = MEM_HU(ctx->r29, 0XAE);
            goto L_8000ED18;
    }
    // 0x8000ED0C: lhu         $t6, 0xAE($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XAE);
    // 0x8000ED10: b           L_8000ED18
    // 0x8000ED14: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8000ED18;
    // 0x8000ED14: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000ED18:
    // 0x8000ED18: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000ED1C: addiu       $s4, $zero, 0x6
    ctx->r20 = ADD32(0, 0X6);
    // 0x8000ED20: addiu       $s5, $zero, 0x6
    ctx->r21 = ADD32(0, 0X6);
    // 0x8000ED24: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8000ED28: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000ED2C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000ED30: lui         $s2, 0x8006
    ctx->r18 = S32(0X8006 << 16);
    // 0x8000ED34: addiu       $s2, $s2, 0x2D30
    ctx->r18 = ADD32(ctx->r18, 0X2D30);
    // 0x8000ED38: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x8000ED3C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8000ED40: mflo        $t7
    ctx->r15 = lo;
    // 0x8000ED44: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000ED48: nop

    // 0x8000ED4C: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000ED50: mflo        $t8
    ctx->r24 = lo;
    // 0x8000ED54: nop

    // 0x8000ED58: nop

    // 0x8000ED5C: multu       $t8, $s4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000ED60: mflo        $t9
    ctx->r25 = lo;
    // 0x8000ED64: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8000ED68: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8000ED6C: multu       $v1, $s5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000ED70: and         $t7, $t7, $at
    ctx->r15 = ctx->r15 & ctx->r1;
    // 0x8000ED74: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x8000ED78: mflo        $t8
    ctx->r24 = lo;
    // 0x8000ED7C: nop

    // 0x8000ED80: nop

    // 0x8000ED84: multu       $t8, $a3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000ED88: mflo        $t9
    ctx->r25 = lo;
    // 0x8000ED8C: nop

    // 0x8000ED90: nop

    // 0x8000ED94: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000ED98: mflo        $a2
    ctx->r6 = lo;
    // 0x8000ED9C: jal         0x8000DDB0
    // 0x8000EDA0: nop

    LOOKUP_FUNC(0x8000DDB0)(rdram, ctx);
        goto after_2;
    // 0x8000EDA0: nop

    after_2:
    // 0x8000EDA4: lhu         $t4, 0xB2($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XB2);
    // 0x8000EDA8: addiu       $v0, $s3, 0x1
    ctx->r2 = ADD32(ctx->r19, 0X1);
    // 0x8000EDAC: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8000EDB0: beql        $at, $zero, L_8000EDC4
    if (ctx->r1 == 0) {
        // 0x8000EDB4: slti        $at, $t4, 0x2
        ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
            goto L_8000EDC4;
    }
    goto skip_0;
    // 0x8000EDB4: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    skip_0:
    // 0x8000EDB8: sh          $v0, 0xB2($sp)
    MEM_H(0XB2, ctx->r29) = ctx->r2;
    // 0x8000EDBC: andi        $t4, $v0, 0xFFFF
    ctx->r12 = ctx->r2 & 0XFFFF;
    // 0x8000EDC0: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
L_8000EDC4:
    // 0x8000EDC4: bne         $at, $zero, L_8000F144
    if (ctx->r1 != 0) {
        // 0x8000EDC8: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8000F144;
    }
    // 0x8000EDC8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000EDCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000EDD0: lw          $t3, 0xB8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB8);
    // 0x8000EDD4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000EDD8: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x8000EDDC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8000EDE0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000EDE4: lhu         $t5, 0xBE($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0XBE);
    // 0x8000EDE8: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
L_8000EDEC:
    // 0x8000EDEC: lhu         $t6, 0x0($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X0);
    // 0x8000EDF0: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8000EDF4: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8000EDF8: bne         $t5, $t6, L_8000F138
    if (ctx->r13 != ctx->r14) {
        // 0x8000EDFC: addu        $t9, $t7, $t8
        ctx->r25 = ADD32(ctx->r15, ctx->r24);
            goto L_8000F138;
    }
    // 0x8000EDFC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8000EE00: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8000EE04: lhu         $a3, 0x9E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X9E);
    // 0x8000EE08: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x8000EE0C: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x8000EE10: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8000EE14: andi        $a3, $a3, 0x10
    ctx->r7 = ctx->r7 & 0X10;
    // 0x8000EE18: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    // 0x8000EE1C: beq         $t7, $zero, L_8000F138
    if (ctx->r15 == 0) {
        // 0x8000EE20: addu        $t8, $t8, $t2
        ctx->r24 = ADD32(ctx->r24, ctx->r10);
            goto L_8000F138;
    }
    // 0x8000EE20: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x8000EE24: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000EE28: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x8000EE2C: beq         $a3, $zero, L_8000EE3C
    if (ctx->r7 == 0) {
        // 0x8000EE30: addiu       $s0, $s0, -0x14
        ctx->r16 = ADD32(ctx->r16, -0X14);
            goto L_8000EE3C;
    }
    // 0x8000EE30: addiu       $s0, $s0, -0x14
    ctx->r16 = ADD32(ctx->r16, -0X14);
    // 0x8000EE34: b           L_8000EE40
    // 0x8000EE38: lbu         $t0, 0x69($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X69);
        goto L_8000EE40;
    // 0x8000EE38: lbu         $t0, 0x69($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X69);
L_8000EE3C:
    // 0x8000EE3C: lbu         $t0, 0x68($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X68);
L_8000EE40:
    // 0x8000EE40: multu       $s1, $t0
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EE44: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x8000EE48: mflo        $v0
    ctx->r2 = lo;
    // 0x8000EE4C: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x8000EE50: nop

    // 0x8000EE54: multu       $t1, $s5
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EE58: mflo        $t6
    ctx->r14 = lo;
    // 0x8000EE5C: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x8000EE60: lwl         $t9, 0x0($t7)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r15, 0X0);
    // 0x8000EE64: lwr         $t9, 0x3($t7)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r15, 0X3);
    // 0x8000EE68: swl         $t9, 0x0($s0)
    do_swl(rdram, 0X0, ctx->r16, ctx->r25);
    // 0x8000EE6C: swr         $t9, 0x3($s0)
    do_swr(rdram, 0X3, ctx->r16, ctx->r25);
    // 0x8000EE70: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x8000EE74: bc1t        L_8000EFA0
    if (c1cs) {
        // 0x8000EE78: sh          $t9, 0x4($s0)
        MEM_H(0X4, ctx->r16) = ctx->r25;
            goto L_8000EFA0;
    }
    // 0x8000EE78: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x8000EE7C: multu       $s1, $s3
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EE80: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8000EE84: mflo        $t6
    ctx->r14 = lo;
    // 0x8000EE88: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8000EE8C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000EE90: multu       $t1, $s4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EE94: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8000EE98: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8000EE9C: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x8000EEA0: mflo        $t6
    ctx->r14 = lo;
    // 0x8000EEA4: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x8000EEA8: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x8000EEAC: subu        $v1, $t7, $a0
    ctx->r3 = SUB32(ctx->r15, ctx->r4);
    // 0x8000EEB0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8000EEB4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000EEB8: andi        $t8, $v1, 0x1000
    ctx->r24 = ctx->r3 & 0X1000;
    // 0x8000EEBC: beq         $t8, $zero, L_8000EED0
    if (ctx->r24 == 0) {
        // 0x8000EEC0: andi        $v0, $v1, 0x1FFF
        ctx->r2 = ctx->r3 & 0X1FFF;
            goto L_8000EED0;
    }
    // 0x8000EEC0: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
    // 0x8000EEC4: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
    // 0x8000EEC8: b           L_8000EED0
    // 0x8000EECC: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
        goto L_8000EED0;
    // 0x8000EECC: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
L_8000EED0:
    // 0x8000EED0: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8000EED4: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8000EED8: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x8000EEDC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000EEE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000EEE4: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8000EEE8: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8000EEEC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000EEF0: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8000EEF4: nop

    // 0x8000EEF8: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x8000EEFC: lh          $t7, 0x2($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X2);
    // 0x8000EF00: subu        $v1, $t7, $a1
    ctx->r3 = SUB32(ctx->r15, ctx->r5);
    // 0x8000EF04: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8000EF08: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000EF0C: andi        $t8, $v1, 0x1000
    ctx->r24 = ctx->r3 & 0X1000;
    // 0x8000EF10: beq         $t8, $zero, L_8000EF24
    if (ctx->r24 == 0) {
        // 0x8000EF14: andi        $v0, $v1, 0x1FFF
        ctx->r2 = ctx->r3 & 0X1FFF;
            goto L_8000EF24;
    }
    // 0x8000EF14: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
    // 0x8000EF18: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
    // 0x8000EF1C: b           L_8000EF24
    // 0x8000EF20: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
        goto L_8000EF24;
    // 0x8000EF20: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
L_8000EF24:
    // 0x8000EF24: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8000EF28: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8000EF2C: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x8000EF30: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000EF34: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000EF38: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8000EF3C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000EF40: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000EF44: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8000EF48: nop

    // 0x8000EF4C: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
    // 0x8000EF50: lh          $t7, 0x4($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X4);
    // 0x8000EF54: subu        $v1, $t7, $a0
    ctx->r3 = SUB32(ctx->r15, ctx->r4);
    // 0x8000EF58: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8000EF5C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000EF60: andi        $t8, $v1, 0x1000
    ctx->r24 = ctx->r3 & 0X1000;
    // 0x8000EF64: beq         $t8, $zero, L_8000EF78
    if (ctx->r24 == 0) {
        // 0x8000EF68: andi        $v0, $v1, 0x1FFF
        ctx->r2 = ctx->r3 & 0X1FFF;
            goto L_8000EF78;
    }
    // 0x8000EF68: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
    // 0x8000EF6C: andi        $v0, $v1, 0x1FFF
    ctx->r2 = ctx->r3 & 0X1FFF;
    // 0x8000EF70: b           L_8000EF78
    // 0x8000EF74: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
        goto L_8000EF78;
    // 0x8000EF74: addiu       $v0, $v0, -0x2000
    ctx->r2 = ADD32(ctx->r2, -0X2000);
L_8000EF78:
    // 0x8000EF78: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8000EF7C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8000EF80: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000EF84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000EF88: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8000EF8C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8000EF90: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000EF94: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8000EF98: nop

    // 0x8000EF9C: sh          $t6, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r14;
L_8000EFA0:
    // 0x8000EFA0: beq         $a3, $zero, L_8000EFF4
    if (ctx->r7 == 0) {
        // 0x8000EFA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8000EFF4;
    }
    // 0x8000EFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000EFA8: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // 0x8000EFAC: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x8000EFB0: andi        $a3, $t0, 0xFFFF
    ctx->r7 = ctx->r8 & 0XFFFF;
    // 0x8000EFB4: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8000EFB8: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x8000EFBC: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x8000EFC0: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x8000EFC4: jal         0x8000EB80
    // 0x8000EFC8: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8000EB80)(rdram, ctx);
        goto after_3;
    // 0x8000EFC8: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    after_3:
    // 0x8000EFCC: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x8000EFD0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8000EFD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000EFD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000EFDC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000EFE0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8000EFE4: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8000EFE8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8000EFEC: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8000EFF0: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
L_8000EFF4:
    // 0x8000EFF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000EFF8: bne         $s1, $at, L_8000F12C
    if (ctx->r17 != ctx->r1) {
        // 0x8000EFFC: addiu       $v1, $t1, 0x1
        ctx->r3 = ADD32(ctx->r9, 0X1);
            goto L_8000F12C;
    }
    // 0x8000EFFC: addiu       $v1, $t1, 0x1
    ctx->r3 = ADD32(ctx->r9, 0X1);
    // 0x8000F000: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8000F004: multu       $v1, $s5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000F008: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x8000F00C: mflo        $t7
    ctx->r15 = lo;
    // 0x8000F010: addu        $v0, $s2, $t7
    ctx->r2 = ADD32(ctx->r18, ctx->r15);
    // 0x8000F014: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8000F018: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8000F01C: nop

    // 0x8000F020: cvt.d.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.d = CVT_D_W(ctx->f6.u32l);
    // 0x8000F024: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8000F028: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8000F02C: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8000F030: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8000F034: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8000F038: nop

    // 0x8000F03C: cvt.d.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.d = CVT_D_W(ctx->f6.u32l);
    // 0x8000F040: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8000F044: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8000F048: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8000F04C: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8000F050: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8000F054: nop

    // 0x8000F058: cvt.d.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.d = CVT_D_W(ctx->f6.u32l);
    // 0x8000F05C: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8000F060: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8000F064: bc1t        L_8000F138
    if (c1cs) {
        // 0x8000F068: swc1        $f10, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
            goto L_8000F138;
    }
    // 0x8000F068: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x8000F06C: multu       $s1, $s3
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000F070: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000F074: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x8000F078: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x8000F07C: mflo        $t7
    ctx->r15 = lo;
    // 0x8000F080: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8000F084: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000F088: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000F08C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8000F090: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8000F094: addu        $t6, $s2, $t9
    ctx->r14 = ADD32(ctx->r18, ctx->r25);
    // 0x8000F098: mflo        $t7
    ctx->r15 = lo;
    // 0x8000F09C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8000F0A0: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8000F0A4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8000F0A8: nop

    // 0x8000F0AC: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000F0B0: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8000F0B4: sub.d       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f10.d - ctx->f2.d;
    // 0x8000F0B8: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8000F0BC: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8000F0C0: cvt.d.s     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f12.d = CVT_D_S(ctx->f6.fl);
    // 0x8000F0C4: add.d       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f2.d + ctx->f4.d;
    // 0x8000F0C8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8000F0CC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8000F0D0: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8000F0D4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8000F0D8: nop

    // 0x8000F0DC: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000F0E0: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8000F0E4: sub.d       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f10.d - ctx->f12.d;
    // 0x8000F0E8: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8000F0EC: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8000F0F0: cvt.d.s     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f14.d = CVT_D_S(ctx->f6.fl);
    // 0x8000F0F4: add.d       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f12.d + ctx->f4.d;
    // 0x8000F0F8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8000F0FC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8000F100: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8000F104: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8000F108: nop

    // 0x8000F10C: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000F110: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8000F114: sub.d       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f10.d - ctx->f14.d;
    // 0x8000F118: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8000F11C: add.d       $f8, $f14, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f14.d + ctx->f4.d;
    // 0x8000F120: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8000F124: b           L_8000F138
    // 0x8000F128: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
        goto L_8000F138;
    // 0x8000F128: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
L_8000F12C:
    // 0x8000F12C: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8000F130: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8000F134: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_8000F138:
    // 0x8000F138: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8000F13C: bne         $t2, $t4, L_8000EDEC
    if (ctx->r10 != ctx->r12) {
        // 0x8000F140: addiu       $t3, $t3, 0x2
        ctx->r11 = ADD32(ctx->r11, 0X2);
            goto L_8000EDEC;
    }
    // 0x8000F140: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
L_8000F144:
    // 0x8000F144: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F148: lhu         $v0, 0xB2($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XB2);
    // 0x8000F14C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8000F150: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8000F154: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8000F158: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8000F15C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F160: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8000F164: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8000F168: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8000F16C: jr          $ra
    // 0x8000F170: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8000F170: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000f174(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000f174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F174: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000F178: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000F17C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000F180: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000F184: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8000F188: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8000F18C: addiu       $v0, $sp, 0x2C
    ctx->r2 = ADD32(ctx->r29, 0X2C);
    // 0x8000F190: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8000F194: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x8000F198: sw          $t9, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->r25;
    // 0x8000F19C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8000F1A0: sw          $t8, 0x60($t7)
    MEM_W(0X60, ctx->r15) = ctx->r24;
    // 0x8000F1A4: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8000F1A8: sw          $t9, 0x64($t7)
    MEM_W(0X64, ctx->r15) = ctx->r25;
    // 0x8000F1AC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000F1B0: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8000F1B4: beq         $t1, $zero, L_8000F1EC
    if (ctx->r9 == 0) {
        // 0x8000F1B8: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_8000F1EC;
    }
    // 0x8000F1B8: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8000F1BC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8000F1C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000F1C4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8000F1C8: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8000F1CC: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8000F1D0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8000F1D4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000F1D8: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8000F1DC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8000F1E0: jal         0x8000F174
    // 0x8000F1E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8000F174)(rdram, ctx);
        goto after_0;
    // 0x8000F1E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000F1E8: addiu       $v0, $sp, 0x2C
    ctx->r2 = ADD32(ctx->r29, 0X2C);
L_8000F1EC:
    // 0x8000F1EC: lbu         $t5, 0x3B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X3B);
    // 0x8000F1F0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000F1F4: beql        $t5, $zero, L_8000F234
    if (ctx->r13 == 0) {
        // 0x8000F1F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000F234;
    }
    goto skip_0;
    // 0x8000F1F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8000F1FC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8000F200: beql        $a0, $zero, L_8000F234
    if (ctx->r4 == 0) {
        // 0x8000F204: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000F234;
    }
    goto skip_1;
    // 0x8000F204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8000F208: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000F20C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000F210: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8000F214: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8000F218: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8000F21C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000F220: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8000F224: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8000F228: jal         0x8000F174
    // 0x8000F22C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8000F174)(rdram, ctx);
        goto after_1;
    // 0x8000F22C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x8000F230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000F234:
    // 0x8000F234: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000F238: jr          $ra
    // 0x8000F23C: nop

    return;
    // 0x8000F23C: nop

;}
RECOMP_FUNC void FUN_8000f240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F240: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000F244: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8000F248: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8000F24C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8000F250: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8000F254: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000F258: andi        $s1, $a2, 0xFF
    ctx->r17 = ctx->r6 & 0XFF;
    // 0x8000F25C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000F260: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
L_8000F264:
    // 0x8000F264: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x8000F268: swc1        $f20, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->f20.u32l;
    // 0x8000F26C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8000F270: beq         $a0, $zero, L_8000F284
    if (ctx->r4 == 0) {
        // 0x8000F274: nop
    
            goto L_8000F284;
    }
    // 0x8000F274: nop

    // 0x8000F278: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8000F27C: jal         0x8000F240
    // 0x8000F280: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8000F240)(rdram, ctx);
        goto after_0;
    // 0x8000F280: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
L_8000F284:
    // 0x8000F284: beql        $s1, $zero, L_8000F2A4
    if (ctx->r17 == 0) {
        // 0x8000F288: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000F2A4;
    }
    goto skip_0;
    // 0x8000F288: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8000F28C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000F290: beq         $v0, $zero, L_8000F2A0
    if (ctx->r2 == 0) {
        // 0x8000F294: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000F2A0;
    }
    // 0x8000F294: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000F298: b           L_8000F264
    // 0x8000F29C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8000F264;
    // 0x8000F29C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8000F2A0:
    // 0x8000F2A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000F2A4:
    // 0x8000F2A4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8000F2A8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F2AC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000F2B0: jr          $ra
    // 0x8000F2B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000F2B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000f2b8(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000f2b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F2B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000F2BC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000F2C0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000F2C4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000F2C8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000F2CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000F2D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000F2D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000F2D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000F2DC: andi        $s1, $a1, 0xFFFF
    ctx->r17 = ctx->r5 & 0XFFFF;
    // 0x8000F2E0: andi        $s2, $a2, 0xFF
    ctx->r18 = ctx->r6 & 0XFF;
    // 0x8000F2E4: andi        $s3, $a3, 0xFF
    ctx->r19 = ctx->r7 & 0XFF;
    // 0x8000F2E8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8000F2EC: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8000F2F0: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x8000F2F4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000F2F8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8000F2FC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8000F300: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
L_8000F304:
    // 0x8000F304: beq         $s2, $zero, L_8000F36C
    if (ctx->r18 == 0) {
        // 0x8000F308: or          $v0, $s2, $zero
        ctx->r2 = ctx->r18 | 0;
            goto L_8000F36C;
    }
    // 0x8000F308: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8000F30C: beql        $v0, $s4, L_8000F330
    if (ctx->r2 == ctx->r20) {
        // 0x8000F310: lw          $v0, 0x2C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X2C);
            goto L_8000F330;
    }
    goto skip_0;
    // 0x8000F310: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    skip_0:
    // 0x8000F314: beql        $v0, $s5, L_8000F344
    if (ctx->r2 == ctx->r21) {
        // 0x8000F318: lw          $v0, 0x2C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X2C);
            goto L_8000F344;
    }
    goto skip_1;
    // 0x8000F318: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    skip_1:
    // 0x8000F31C: beql        $v0, $s6, L_8000F35C
    if (ctx->r2 == ctx->r22) {
        // 0x8000F320: lw          $v0, 0x2C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X2C);
            goto L_8000F35C;
    }
    goto skip_2;
    // 0x8000F320: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    skip_2:
    // 0x8000F324: b           L_8000F370
    // 0x8000F328: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
        goto L_8000F370;
    // 0x8000F328: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x8000F32C: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
L_8000F330:
    // 0x8000F330: lhu         $t6, 0x62($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X62);
    // 0x8000F334: or          $t7, $t6, $s1
    ctx->r15 = ctx->r14 | ctx->r17;
    // 0x8000F338: b           L_8000F374
    // 0x8000F33C: sh          $t7, 0x62($v0)
    MEM_H(0X62, ctx->r2) = ctx->r15;
        goto L_8000F374;
    // 0x8000F33C: sh          $t7, 0x62($v0)
    MEM_H(0X62, ctx->r2) = ctx->r15;
    // 0x8000F340: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
L_8000F344:
    // 0x8000F344: nor         $t9, $s1, $zero
    ctx->r25 = ~(ctx->r17 | 0);
    // 0x8000F348: lhu         $t8, 0x62($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X62);
    // 0x8000F34C: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8000F350: b           L_8000F374
    // 0x8000F354: sh          $t0, 0x62($v0)
    MEM_H(0X62, ctx->r2) = ctx->r8;
        goto L_8000F374;
    // 0x8000F354: sh          $t0, 0x62($v0)
    MEM_H(0X62, ctx->r2) = ctx->r8;
    // 0x8000F358: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
L_8000F35C:
    // 0x8000F35C: lhu         $t1, 0x62($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X62);
    // 0x8000F360: xor         $t2, $t1, $s1
    ctx->r10 = ctx->r9 ^ ctx->r17;
    // 0x8000F364: b           L_8000F374
    // 0x8000F368: sh          $t2, 0x62($v0)
    MEM_H(0X62, ctx->r2) = ctx->r10;
        goto L_8000F374;
    // 0x8000F368: sh          $t2, 0x62($v0)
    MEM_H(0X62, ctx->r2) = ctx->r10;
L_8000F36C:
    // 0x8000F36C: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
L_8000F370:
    // 0x8000F370: sh          $s1, 0x62($t3)
    MEM_H(0X62, ctx->r11) = ctx->r17;
L_8000F374:
    // 0x8000F374: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8000F378: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8000F37C: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    // 0x8000F380: beq         $a0, $zero, L_8000F390
    if (ctx->r4 == 0) {
        // 0x8000F384: nop
    
            goto L_8000F390;
    }
    // 0x8000F384: nop

    // 0x8000F388: jal         0x8000F2B8
    // 0x8000F38C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8000F2B8)(rdram, ctx);
        goto after_0;
    // 0x8000F38C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
L_8000F390:
    // 0x8000F390: beq         $s3, $zero, L_8000F3B0
    if (ctx->r19 == 0) {
        // 0x8000F394: andi        $s1, $s1, 0xFFFF
        ctx->r17 = ctx->r17 & 0XFFFF;
            goto L_8000F3B0;
    }
    // 0x8000F394: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8000F398: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000F39C: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x8000F3A0: beq         $v0, $zero, L_8000F3B0
    if (ctx->r2 == 0) {
        // 0x8000F3A4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000F3B0;
    }
    // 0x8000F3A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000F3A8: b           L_8000F304
    // 0x8000F3AC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_8000F304;
    // 0x8000F3AC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8000F3B0:
    // 0x8000F3B0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000F3B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000F3B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F3BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000F3C0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000F3C4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000F3C8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F3CC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000F3D0: jr          $ra
    // 0x8000F3D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000F3D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000f3d8(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000f3d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F3D8: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8000F3DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000F3E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000F3E4: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8000F3E8: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8000F3EC: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x8000F3F0: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x8000F3F4: bc1fl       L_8000F414
    if (!c1cs) {
        // 0x8000F3F8: mtc1        $at, $f3
        ctx->f_odd[(3 - 1) * 2] = ctx->r1;
            goto L_8000F414;
    }
    goto skip_0;
    // 0x8000F3F8: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x8000F3FC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000F400: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8000F404: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000F408: b           L_8000F420
    // 0x8000F40C: add.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f8.d + ctx->f2.d;
        goto L_8000F420;
    // 0x8000F40C: add.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f8.d + ctx->f2.d;
    // 0x8000F410: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
L_8000F414:
    // 0x8000F414: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000F418: nop

    // 0x8000F41C: add.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f8.d + ctx->f2.d;
L_8000F420:
    // 0x8000F420: lui         $at, 0x3F50
    ctx->r1 = S32(0X3F50 << 16);
    // 0x8000F424: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8000F428: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000F42C: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x8000F430: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8000F434: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8000F438: nop

    // 0x8000F43C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8000F440: nop

    // 0x8000F444: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000F448: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x8000F44C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8000F450: jr          $ra
    // 0x8000F454: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    return;
    // 0x8000F454: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000f458(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000f458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F458: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8000F45C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000F460: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000F464: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000F468: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000F46C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000F470: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8000F474: lhu         $t8, 0x22($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X22);
    // 0x8000F478: lw          $s1, 0x2C($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X2C);
    // 0x8000F47C: lw          $s2, 0x2C($t7)
    ctx->r18 = MEM_W(ctx->r15, 0X2C);
    // 0x8000F480: sh          $t8, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r24;
    // 0x8000F484: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000F488: jal         0x8000E58C
    // 0x8000F48C: lw          $a0, 0x1C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1C);
    LOOKUP_FUNC(0x8000E58C)(rdram, ctx);
        goto after_0;
    // 0x8000F48C: lw          $a0, 0x1C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1C);
    after_0:
    // 0x8000F490: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8000F494: addiu       $t9, $sp, 0x5C
    ctx->r25 = ADD32(ctx->r29, 0X5C);
    // 0x8000F498: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x8000F49C: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // 0x8000F4A0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8000F4A4: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x8000F4A8: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8000F4AC: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x8000F4B0: jal         0x8000E748
    // 0x8000F4B4: addiu       $a3, $sp, 0x5A
    ctx->r7 = ADD32(ctx->r29, 0X5A);
    LOOKUP_FUNC(0x8000E748)(rdram, ctx);
        goto after_1;
    // 0x8000F4B4: addiu       $a3, $sp, 0x5A
    ctx->r7 = ADD32(ctx->r29, 0X5A);
    after_1:
    // 0x8000F4B8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8000F4BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000F4C0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000F4C4: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000F4C8: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x8000F4CC: addiu       $a1, $a1, 0x31B0
    ctx->r5 = ADD32(ctx->r5, 0X31B0);
    // 0x8000F4D0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000F4D4: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8000F4D8: lui         $t4, 0x8006
    ctx->r12 = S32(0X8006 << 16);
    // 0x8000F4DC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x8000F4E0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000F4E4: nop

    // 0x8000F4E8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8000F4EC: beq         $t1, $zero, L_8000F538
    if (ctx->r9 == 0) {
        // 0x8000F4F0: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_8000F538;
    }
    // 0x8000F4F0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000F4F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000F4F8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000F4FC: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000F500: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000F504: nop

    // 0x8000F508: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8000F50C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000F510: nop

    // 0x8000F514: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8000F518: bne         $t1, $zero, L_8000F530
    if (ctx->r9 != 0) {
        // 0x8000F51C: nop
    
            goto L_8000F530;
    }
    // 0x8000F51C: nop

    // 0x8000F520: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8000F524: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000F528: b           L_8000F548
    // 0x8000F52C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_8000F548;
    // 0x8000F52C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8000F530:
    // 0x8000F530: b           L_8000F548
    // 0x8000F534: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_8000F548;
    // 0x8000F534: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_8000F538:
    // 0x8000F538: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8000F53C: nop

    // 0x8000F540: bltz        $t1, L_8000F530
    if (SIGNED(ctx->r9) < 0) {
        // 0x8000F544: nop
    
            goto L_8000F530;
    }
    // 0x8000F544: nop

L_8000F548:
    // 0x8000F548: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8000F54C: lw          $t4, 0x31E4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X31E4);
    // 0x8000F550: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000F554: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8000F558: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8000F55C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000F560: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x8000F564: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000F568: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8000F56C: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x8000F570: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8000F574: jal         0x8000DDB0
    // 0x8000F578: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    LOOKUP_FUNC(0x8000DDB0)(rdram, ctx);
        goto after_2;
    // 0x8000F578: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    after_2:
    // 0x8000F57C: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x8000F580: addiu       $a1, $a1, 0x31B0
    ctx->r5 = ADD32(ctx->r5, 0X31B0);
    // 0x8000F584: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8000F588: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000F58C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8000F590: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x8000F594: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000F598: addiu       $a3, $a3, 0x31E0
    ctx->r7 = ADD32(ctx->r7, 0X31E0);
    // 0x8000F59C: swc1        $f16, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f16.u32l;
    // 0x8000F5A0: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000F5A4: lwc1        $f18, 0x14($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8000F5A8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8000F5AC: swc1        $f6, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f6.u32l;
    // 0x8000F5B0: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000F5B4: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000F5B8: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000F5BC: c.eq.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl == ctx->f14.fl;
    // 0x8000F5C0: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000F5C4: lwc1        $f12, 0x10($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8000F5C8: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x8000F5CC: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x8000F5D0: bc1t        L_8000F678
    if (c1cs) {
        // 0x8000F5D4: swc1        $f16, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
            goto L_8000F678;
    }
    // 0x8000F5D4: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    // 0x8000F5D8: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8000F5DC: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8000F5E0: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8000F5E4: lwc1        $f2, 0xC($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8000F5E8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000F5EC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8000F5F0: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8000F5F4: add.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8000F5F8: swc1        $f4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f4.u32l;
    // 0x8000F5FC: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8000F600: lwc1        $f6, 0x2C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8000F604: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000F608: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000F60C: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8000F610: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8000F614: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8000F618: swc1        $f6, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f6.u32l;
    // 0x8000F61C: lwc1        $f8, 0x28($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8000F620: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8000F624: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8000F628: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8000F62C: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000F630: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000F634: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8000F638: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8000F63C: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8000F640: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8000F644: add.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x8000F648: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8000F64C: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8000F650: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8000F654: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x8000F658: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8000F65C: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8000F660: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000F664: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000F668: swc1        $f16, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f16.u32l;
    // 0x8000F66C: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8000F670: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8000F674: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
L_8000F678:
    // 0x8000F678: lhu         $t4, 0x5A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X5A);
    // 0x8000F67C: lhu         $t6, 0x5E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X5E);
    // 0x8000F680: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x8000F684: beq         $t5, $zero, L_8000F9FC
    if (ctx->r13 == 0) {
        // 0x8000F688: andi        $t7, $t6, 0x2
        ctx->r15 = ctx->r14 & 0X2;
            goto L_8000F9FC;
    }
    // 0x8000F688: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8000F68C: beq         $t7, $zero, L_8000F8FC
    if (ctx->r15 == 0) {
        // 0x8000F690: lw          $t6, 0x3C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X3C);
            goto L_8000F8FC;
    }
    // 0x8000F690: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F694: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F698: lhu         $t8, 0x5C($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X5C);
    // 0x8000F69C: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000F6A0: lhu         $t0, 0x4($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X4);
    // 0x8000F6A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F6A8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8000F6AC: bnel        $t8, $t1, L_8000FA00
    if (ctx->r24 != ctx->r9) {
        // 0x8000F6B0: lbu         $t4, 0x76($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X76);
            goto L_8000FA00;
    }
    goto skip_0;
    // 0x8000F6B0: lbu         $t4, 0x76($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X76);
    skip_0:
    // 0x8000F6B4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8000F6B8: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8000F6BC: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8000F6C0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000F6C4: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000F6C8: addiu       $t6, $t6, 0x31C8
    ctx->r14 = ADD32(ctx->r14, 0X31C8);
    // 0x8000F6CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000F6D0: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8000F6D4: nop

    // 0x8000F6D8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8000F6DC: beql        $v0, $zero, L_8000F72C
    if (ctx->r2 == 0) {
        // 0x8000F6E0: mfc1        $v0, $f8
        ctx->r2 = (int32_t)ctx->f8.u32l;
            goto L_8000F72C;
    }
    goto skip_1;
    // 0x8000F6E0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x8000F6E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000F6E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F6EC: sub.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8000F6F0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8000F6F4: nop

    // 0x8000F6F8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000F6FC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8000F700: nop

    // 0x8000F704: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8000F708: bne         $v0, $zero, L_8000F720
    if (ctx->r2 != 0) {
        // 0x8000F70C: nop
    
            goto L_8000F720;
    }
    // 0x8000F70C: nop

    // 0x8000F710: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8000F714: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000F718: b           L_8000F738
    // 0x8000F71C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_8000F738;
    // 0x8000F71C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_8000F720:
    // 0x8000F720: b           L_8000F738
    // 0x8000F724: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000F738;
    // 0x8000F724: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000F728: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
L_8000F72C:
    // 0x8000F72C: nop

    // 0x8000F730: bltz        $v0, L_8000F720
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000F734: nop
    
            goto L_8000F720;
    }
    // 0x8000F734: nop

L_8000F738:
    // 0x8000F738: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000F73C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8000F740: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000F744: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000F748: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000F74C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000F750: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8000F754: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8000F758: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8000F75C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8000F760: nop

    // 0x8000F764: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8000F768: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8000F76C: nop

    // 0x8000F770: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8000F774: beql        $t4, $zero, L_8000F7C4
    if (ctx->r12 == 0) {
        // 0x8000F778: mfc1        $t4, $f16
        ctx->r12 = (int32_t)ctx->f16.u32l;
            goto L_8000F7C4;
    }
    goto skip_2;
    // 0x8000F778: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x8000F77C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000F780: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000F784: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8000F788: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8000F78C: nop

    // 0x8000F790: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000F794: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8000F798: nop

    // 0x8000F79C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8000F7A0: bne         $t4, $zero, L_8000F7B8
    if (ctx->r12 != 0) {
        // 0x8000F7A4: nop
    
            goto L_8000F7B8;
    }
    // 0x8000F7A4: nop

    // 0x8000F7A8: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x8000F7AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000F7B0: b           L_8000F7D0
    // 0x8000F7B4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8000F7D0;
    // 0x8000F7B4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8000F7B8:
    // 0x8000F7B8: b           L_8000F7D0
    // 0x8000F7BC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8000F7D0;
    // 0x8000F7BC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8000F7C0: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
L_8000F7C4:
    // 0x8000F7C4: nop

    // 0x8000F7C8: bltz        $t4, L_8000F7B8
    if (SIGNED(ctx->r12) < 0) {
        // 0x8000F7CC: nop
    
            goto L_8000F7B8;
    }
    // 0x8000F7CC: nop

L_8000F7D0:
    // 0x8000F7D0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8000F7D4: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x8000F7D8: bne         $t5, $v0, L_8000F7FC
    if (ctx->r13 != ctx->r2) {
        // 0x8000F7DC: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_8000F7FC;
    }
    // 0x8000F7DC: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000F7E0: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8000F7E4: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
    // 0x8000F7E8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8000F7EC: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    // 0x8000F7F0: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x8000F7F4: b           L_8000F9FC
    // 0x8000F7F8: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
        goto L_8000F9FC;
    // 0x8000F7F8: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
L_8000F7FC:
    // 0x8000F7FC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8000F800: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x8000F804: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000F808: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8000F80C: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000F810: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8000F814: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x8000F818: nop

    // 0x8000F81C: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x8000F820: beql        $v1, $zero, L_8000F870
    if (ctx->r3 == 0) {
        // 0x8000F824: mfc1        $v1, $f8
        ctx->r3 = (int32_t)ctx->f8.u32l;
            goto L_8000F870;
    }
    goto skip_3;
    // 0x8000F824: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    skip_3:
    // 0x8000F828: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000F82C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000F830: sub.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8000F834: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x8000F838: nop

    // 0x8000F83C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000F840: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x8000F844: nop

    // 0x8000F848: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x8000F84C: bne         $v1, $zero, L_8000F864
    if (ctx->r3 != 0) {
        // 0x8000F850: nop
    
            goto L_8000F864;
    }
    // 0x8000F850: nop

    // 0x8000F854: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8000F858: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000F85C: b           L_8000F87C
    // 0x8000F860: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_8000F87C;
    // 0x8000F860: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_8000F864:
    // 0x8000F864: b           L_8000F87C
    // 0x8000F868: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_8000F87C;
    // 0x8000F868: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8000F86C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
L_8000F870:
    // 0x8000F870: nop

    // 0x8000F874: bltz        $v1, L_8000F864
    if (SIGNED(ctx->r3) < 0) {
        // 0x8000F878: nop
    
            goto L_8000F864;
    }
    // 0x8000F878: nop

L_8000F87C:
    // 0x8000F87C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8000F880: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8000F884: bne         $v1, $v0, L_8000F8A8
    if (ctx->r3 != ctx->r2) {
        // 0x8000F888: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_8000F8A8;
    }
    // 0x8000F888: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8000F88C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8000F890: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
    // 0x8000F894: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8000F898: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    // 0x8000F89C: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x8000F8A0: b           L_8000F9FC
    // 0x8000F8A4: sw          $t1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r9;
        goto L_8000F9FC;
    // 0x8000F8A4: sw          $t1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r9;
L_8000F8A8:
    // 0x8000F8A8: lw          $t3, 0x4($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X4);
    // 0x8000F8AC: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x8000F8B0: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8000F8B4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000F8B8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000F8BC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8000F8C0: and         $t1, $t4, $at
    ctx->r9 = ctx->r12 & ctx->r1;
    // 0x8000F8C4: addu        $a0, $t1, $t9
    ctx->r4 = ADD32(ctx->r9, ctx->r25);
    // 0x8000F8C8: jal         0x8000DDB0
    // 0x8000F8CC: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    LOOKUP_FUNC(0x8000DDB0)(rdram, ctx);
        goto after_3;
    // 0x8000F8CC: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x8000F8D0: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x8000F8D4: addiu       $a1, $a1, 0x31B0
    ctx->r5 = ADD32(ctx->r5, 0X31B0);
    // 0x8000F8D8: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8000F8DC: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8000F8E0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8000F8E4: sw          $t4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r12;
    // 0x8000F8E8: lw          $t5, 0x4($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X4);
    // 0x8000F8EC: sw          $t5, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r13;
    // 0x8000F8F0: lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8);
    // 0x8000F8F4: b           L_8000F9FC
    // 0x8000F8F8: sw          $t4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r12;
        goto L_8000F9FC;
    // 0x8000F8F8: sw          $t4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r12;
L_8000F8FC:
    // 0x8000F8FC: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x8000F900: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000F904: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000F908: bne         $t7, $at, L_8000F9FC
    if (ctx->r15 != ctx->r1) {
        // 0x8000F90C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8000F9FC;
    }
    // 0x8000F90C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000F910: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8000F914: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000F918: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000F91C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8000F920: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8000F924: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000F928: nop

    // 0x8000F92C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8000F930: beql        $t1, $zero, L_8000F980
    if (ctx->r9 == 0) {
        // 0x8000F934: mfc1        $t1, $f6
        ctx->r9 = (int32_t)ctx->f6.u32l;
            goto L_8000F980;
    }
    goto skip_4;
    // 0x8000F934: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    skip_4:
    // 0x8000F938: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000F93C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000F940: sub.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8000F944: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000F948: nop

    // 0x8000F94C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8000F950: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000F954: nop

    // 0x8000F958: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8000F95C: bne         $t1, $zero, L_8000F974
    if (ctx->r9 != 0) {
        // 0x8000F960: nop
    
            goto L_8000F974;
    }
    // 0x8000F960: nop

    // 0x8000F964: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8000F968: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000F96C: b           L_8000F98C
    // 0x8000F970: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_8000F98C;
    // 0x8000F970: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8000F974:
    // 0x8000F974: b           L_8000F98C
    // 0x8000F978: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_8000F98C;
    // 0x8000F978: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8000F97C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
L_8000F980:
    // 0x8000F980: nop

    // 0x8000F984: bltz        $t1, L_8000F974
    if (SIGNED(ctx->r9) < 0) {
        // 0x8000F988: nop
    
            goto L_8000F974;
    }
    // 0x8000F988: nop

L_8000F98C:
    // 0x8000F98C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8000F990: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x8000F994: bne         $t8, $zero, L_8000F9B8
    if (ctx->r24 != 0) {
        // 0x8000F998: lui         $at, 0xFF
        ctx->r1 = S32(0XFF << 16);
            goto L_8000F9B8;
    }
    // 0x8000F998: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000F99C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8000F9A0: sw          $t2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r10;
    // 0x8000F9A4: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x8000F9A8: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x8000F9AC: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x8000F9B0: b           L_8000F9FC
    // 0x8000F9B4: sw          $t2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r10;
        goto L_8000F9FC;
    // 0x8000F9B4: sw          $t2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r10;
L_8000F9B8:
    // 0x8000F9B8: lw          $t3, 0x4($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X4);
    // 0x8000F9BC: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x8000F9C0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000F9C4: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x8000F9C8: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x8000F9CC: jal         0x8000DDB0
    // 0x8000F9D0: addu        $a0, $t7, $t1
    ctx->r4 = ADD32(ctx->r15, ctx->r9);
    LOOKUP_FUNC(0x8000DDB0)(rdram, ctx);
        goto after_4;
    // 0x8000F9D0: addu        $a0, $t7, $t1
    ctx->r4 = ADD32(ctx->r15, ctx->r9);
    after_4:
    // 0x8000F9D4: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x8000F9D8: addiu       $a1, $a1, 0x31B0
    ctx->r5 = ADD32(ctx->r5, 0X31B0);
    // 0x8000F9DC: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8000F9E0: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8000F9E4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8000F9E8: sw          $t3, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r11;
    // 0x8000F9EC: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x8000F9F0: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x8000F9F4: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x8000F9F8: sw          $t3, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r11;
L_8000F9FC:
    // 0x8000F9FC: lbu         $t4, 0x76($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X76);
L_8000FA00:
    // 0x8000FA00: lhu         $v0, 0x5E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X5E);
    // 0x8000FA04: addiu       $v1, $s0, 0x28
    ctx->r3 = ADD32(ctx->r16, 0X28);
    // 0x8000FA08: bne         $t4, $zero, L_8000FA54
    if (ctx->r12 != 0) {
        // 0x8000FA0C: addiu       $t9, $sp, 0x7C
        ctx->r25 = ADD32(ctx->r29, 0X7C);
            goto L_8000FA54;
    }
    // 0x8000FA0C: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x8000FA10: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8000FA14: bne         $t5, $zero, L_8000FA54
    if (ctx->r13 != 0) {
        // 0x8000FA18: andi        $t6, $v0, 0x2
        ctx->r14 = ctx->r2 & 0X2;
            goto L_8000FA54;
    }
    // 0x8000FA18: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x8000FA1C: beq         $t6, $zero, L_8000FA30
    if (ctx->r14 == 0) {
        // 0x8000FA20: lwc1        $f16, 0x6C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
            goto L_8000FA30;
    }
    // 0x8000FA20: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000FA24: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000FA28: b           L_8000FA3C
    // 0x8000FA2C: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
        goto L_8000FA3C;
    // 0x8000FA2C: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
L_8000FA30:
    // 0x8000FA30: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x8000FA34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000FA38: nop

L_8000FA3C:
    // 0x8000FA3C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8000FA40: addiu       $t7, $sp, 0x7C
    ctx->r15 = ADD32(ctx->r29, 0X7C);
    // 0x8000FA44: c.eq.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d == ctx->f4.d;
    // 0x8000FA48: nop

    // 0x8000FA4C: bc1fl       L_8000FA6C
    if (!c1cs) {
        // 0x8000FA50: lw          $t1, 0x0($t7)
        ctx->r9 = MEM_W(ctx->r15, 0X0);
            goto L_8000FA6C;
    }
    goto skip_5;
    // 0x8000FA50: lw          $t1, 0x0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X0);
    skip_5:
L_8000FA54:
    // 0x8000FA54: swc1        $f14, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f14.u32l;
    // 0x8000FA58: swc1        $f14, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f14.u32l;
    // 0x8000FA5C: swc1        $f14, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f14.u32l;
    // 0x8000FA60: b           L_8000FAB0
    // 0x8000FA64: sb          $zero, 0x76($s0)
    MEM_B(0X76, ctx->r16) = 0;
        goto L_8000FAB0;
    // 0x8000FA64: sb          $zero, 0x76($s0)
    MEM_B(0X76, ctx->r16) = 0;
    // 0x8000FA68: lw          $t1, 0x0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X0);
L_8000FA6C:
    // 0x8000FA6C: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8000FA70: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8000FA74: sw          $t1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r9;
    // 0x8000FA78: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8000FA7C: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8000FA80: sw          $t0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r8;
    // 0x8000FA84: lw          $t1, 0x8($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X8);
    // 0x8000FA88: sub.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8000FA8C: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8000FA90: sw          $t1, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r9;
    // 0x8000FA94: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8000FA98: lwc1        $f18, 0x30($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8000FA9C: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    // 0x8000FAA0: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8000FAA4: sub.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8000FAA8: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8000FAAC: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
L_8000FAB0:
    // 0x8000FAB0: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8000FAB4: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000FAB8: ldc1        $f8, -0x3800($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X3800);
    // 0x8000FABC: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8000FAC0: andi        $t8, $v0, 0x10
    ctx->r24 = ctx->r2 & 0X10;
    // 0x8000FAC4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8000FAC8: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8000FACC: div.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x8000FAD0: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8000FAD4: beq         $t8, $zero, L_8000FAF8
    if (ctx->r24 == 0) {
        // 0x8000FAD8: swc1        $f6, 0x8($s2)
        MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
            goto L_8000FAF8;
    }
    // 0x8000FAD8: swc1        $f6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
    // 0x8000FADC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000FAE0: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8000FAE4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8000FAE8: swc1        $f16, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f16.u32l;
    // 0x8000FAEC: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8000FAF0: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000FAF4: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
L_8000FAF8:
    // 0x8000FAF8: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x8000FAFC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8000FB00: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x8000FB04: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8000FB08: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x8000FB0C: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x8000FB10: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8000FB14: lwc1        $f6, 0x18($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8000FB18: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8000FB1C: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8000FB20: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8000FB24: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    // 0x8000FB28: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8000FB2C: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000FB30: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x8000FB34: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8000FB38: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8000FB3C: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    // 0x8000FB40: lh          $a0, 0x12($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X12);
    // 0x8000FB44: jal         0x8001EAD0
    // 0x8000FB48: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_5;
    // 0x8000FB48: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_5:
    // 0x8000FB4C: lh          $a0, 0x12($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X12);
    // 0x8000FB50: jal         0x8001EB64
    // 0x8000FB54: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_6;
    // 0x8000FB54: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8000FB58: lwc1        $f14, 0x74($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000FB5C: lwc1        $f12, 0x40($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8000FB60: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8000FB64: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8000FB68: mul.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8000FB6C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8000FB70: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x8000FB74: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8000FB78: andi        $t4, $v0, 0x1001
    ctx->r12 = ctx->r2 & 0X1001;
    // 0x8000FB7C: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8000FB80: nop

    // 0x8000FB84: mul.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8000FB88: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8000FB8C: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    // 0x8000FB90: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8000FB94: bne         $t4, $zero, L_8000FBD4
    if (ctx->r12 != 0) {
        // 0x8000FB98: swc1        $f16, 0x4C($s0)
        MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
            goto L_8000FBD4;
    }
    // 0x8000FB98: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
    // 0x8000FB9C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8000FBA0: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8000FBA4: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8000FBA8: andi        $t5, $v0, 0x2000
    ctx->r13 = ctx->r2 & 0X2000;
    // 0x8000FBAC: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8000FBB0: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8000FBB4: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8000FBB8: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8000FBBC: bne         $t5, $zero, L_8000FBD4
    if (ctx->r13 != 0) {
        // 0x8000FBC0: swc1        $f16, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->f16.u32l;
            goto L_8000FBD4;
    }
    // 0x8000FBC0: swc1        $f16, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f16.u32l;
    // 0x8000FBC4: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8000FBC8: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8000FBCC: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8000FBD0: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
L_8000FBD4:
    // 0x8000FBD4: jal         0x8000F3D8
    // 0x8000FBD8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    LOOKUP_FUNC(0x8000F3D8)(rdram, ctx);
        goto after_7;
    // 0x8000FBD8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    after_7:
    // 0x8000FBDC: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8000FBE0: jal         0x8000F3D8
    // 0x8000FBE4: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    LOOKUP_FUNC(0x8000F3D8)(rdram, ctx);
        goto after_8;
    // 0x8000FBE4: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    after_8:
    // 0x8000FBE8: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x8000FBEC: jal         0x8000F3D8
    // 0x8000FBF0: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    LOOKUP_FUNC(0x8000F3D8)(rdram, ctx);
        goto after_9;
    // 0x8000FBF0: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    after_9:
    // 0x8000FBF4: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x8000FBF8: lw          $t7, 0x5C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X5C);
    // 0x8000FBFC: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x8000FC00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000FC04: lw          $t6, 0x60($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X60);
    // 0x8000FC08: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8000FC0C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000FC10: lw          $t7, 0x64($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X64);
    // 0x8000FC14: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8000FC18: sw          $t1, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r9;
    // 0x8000FC1C: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8000FC20: sw          $t0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r8;
    // 0x8000FC24: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x8000FC28: sw          $t1, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->r9;
    // 0x8000FC2C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8000FC30: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8000FC34: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8000FC38: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8000FC3C: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8000FC40: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8000FC44: sw          $t2, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r10;
    // 0x8000FC48: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FC4C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000FC50: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000FC54: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000FC58: jr          $ra
    // 0x8000FC5C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8000FC5C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000fc60(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000fc60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FC60: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000FC64: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8000FC68: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8000FC6C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8000FC70: blez        $a1, L_8000FCC4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000FC74: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000FCC4;
    }
    // 0x8000FC74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000FC78: lhu         $a2, 0x4($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X4);
L_8000FC7C:
    // 0x8000FC7C: lhu         $t6, 0x4($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X4);
    // 0x8000FC80: bnel        $a2, $t6, L_8000FCB4
    if (ctx->r6 != ctx->r14) {
        // 0x8000FC84: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000FCB4;
    }
    goto skip_0;
    // 0x8000FC84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8000FC88: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8000FC8C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000FC90: bnel        $t7, $t8, L_8000FCB4
    if (ctx->r15 != ctx->r24) {
        // 0x8000FC94: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000FCB4;
    }
    goto skip_1;
    // 0x8000FC94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x8000FC98: lhu         $t9, 0x6($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X6);
    // 0x8000FC9C: lhu         $t0, 0x6($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X6);
    // 0x8000FCA0: bnel        $t9, $t0, L_8000FCB4
    if (ctx->r25 != ctx->r8) {
        // 0x8000FCA4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000FCB4;
    }
    goto skip_2;
    // 0x8000FCA4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x8000FCA8: jr          $ra
    // 0x8000FCAC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000FCAC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000FCB0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000FCB4:
    // 0x8000FCB4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8000FCB8: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8000FCBC: bne         $at, $zero, L_8000FC7C
    if (ctx->r1 != 0) {
        // 0x8000FCC0: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_8000FC7C;
    }
    // 0x8000FCC0: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_8000FCC4:
    // 0x8000FCC4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8000FCC8: jr          $ra
    // 0x8000FCCC: nop

    return;
    // 0x8000FCCC: nop

;}
RECOMP_FUNC void FUN_8000fcd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FCD0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8000FCD4: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x8000FCD8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000FCDC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8000FCE0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000FCE4: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x8000FCE8: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8000FCEC: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x8000FCF0: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8000FCF4: lw          $t0, 0x8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X8);
    // 0x8000FCF8: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    // 0x8000FCFC: lhu         $t1, 0x0($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X0);
    // 0x8000FD00: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8000FD04: jr          $ra
    // 0x8000FD08: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    return;
    // 0x8000FD08: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000fd0c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000fd0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FD0C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8000FD10: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000FD14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000FD18: andi        $s0, $a1, 0xFFFF
    ctx->r16 = ctx->r5 & 0XFFFF;
    // 0x8000FD1C: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8000FD20: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000FD24: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000FD28: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000FD2C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8000FD30: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8000FD34: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x8000FD38: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000FD3C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000FD40: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000FD44: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000FD48: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000FD4C: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
    // 0x8000FD50: addiu       $a1, $zero, 0x240
    ctx->r5 = ADD32(0, 0X240);
    // 0x8000FD54: jal         0x800279F0
    // 0x8000FD58: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800279F0)(rdram, ctx);
        goto after_0;
    // 0x8000FD58: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8000FD5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000FD60: or          $v1, $s7, $zero
    ctx->r3 = ctx->r23 | 0;
    // 0x8000FD64: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8000FD68: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8000FD6C:
    // 0x8000FD6C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000FD70: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x8000FD74: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x8000FD78: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    // 0x8000FD7C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8000FD80: bne         $a0, $a1, L_8000FD6C
    if (ctx->r4 != ctx->r5) {
        // 0x8000FD84: sh          $v0, -0x8($v1)
        MEM_H(-0X8, ctx->r3) = ctx->r2;
            goto L_8000FD6C;
    }
    // 0x8000FD84: sh          $v0, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r2;
    // 0x8000FD88: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8000FD8C: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8000FD90: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8000FD94: or          $s6, $s0, $zero
    ctx->r22 = ctx->r16 | 0;
    // 0x8000FD98: bne         $at, $zero, L_8000FE14
    if (ctx->r1 != 0) {
        // 0x8000FD9C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8000FE14;
    }
    // 0x8000FD9C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8000FDA0: beq         $v0, $zero, L_8000FE14
    if (ctx->r2 == 0) {
        // 0x8000FDA4: addiu       $s5, $sp, 0x5A
        ctx->r21 = ADD32(ctx->r29, 0X5A);
            goto L_8000FE14;
    }
    // 0x8000FDA4: addiu       $s5, $sp, 0x5A
    ctx->r21 = ADD32(ctx->r29, 0X5A);
    // 0x8000FDA8: andi        $t6, $s3, 0x1
    ctx->r14 = ctx->r19 & 0X1;
L_8000FDAC:
    // 0x8000FDAC: beq         $t6, $zero, L_8000FDFC
    if (ctx->r14 == 0) {
        // 0x8000FDB0: sll         $t7, $s2, 2
        ctx->r15 = S32(ctx->r18 << 2);
            goto L_8000FDFC;
    }
    // 0x8000FDB0: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8000FDB4: addu        $t8, $fp, $t7
    ctx->r24 = ADD32(ctx->r30, ctx->r15);
    // 0x8000FDB8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8000FDBC: sll         $t0, $s2, 1
    ctx->r8 = S32(ctx->r18 << 1);
    // 0x8000FDC0: addu        $s1, $s7, $t0
    ctx->r17 = ADD32(ctx->r23, ctx->r8);
    // 0x8000FDC4: lw          $s0, 0x2C($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X2C);
    // 0x8000FDC8: lhu         $a1, 0x5A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X5A);
    // 0x8000FDCC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8000FDD0: addiu       $s0, $s0, 0x5C
    ctx->r16 = ADD32(ctx->r16, 0X5C);
    // 0x8000FDD4: jal         0x8000FC60
    // 0x8000FDD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8000FC60)(rdram, ctx);
        goto after_1;
    // 0x8000FDD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000FDDC: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x8000FDE0: lhu         $t1, 0x5A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X5A);
    // 0x8000FDE4: andi        $t2, $v0, 0xFFFF
    ctx->r10 = ctx->r2 & 0XFFFF;
    // 0x8000FDE8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8000FDEC: bne         $t1, $t2, L_8000FDFC
    if (ctx->r9 != ctx->r10) {
        // 0x8000FDF0: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8000FDFC;
    }
    // 0x8000FDF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000FDF4: jal         0x8000FCD0
    // 0x8000FDF8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    LOOKUP_FUNC(0x8000FCD0)(rdram, ctx);
        goto after_2;
    // 0x8000FDF8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_2:
L_8000FDFC:
    // 0x8000FDFC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000FE00: slt         $at, $s2, $s6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8000FE04: beq         $at, $zero, L_8000FE14
    if (ctx->r1 == 0) {
        // 0x8000FE08: srl         $s3, $s3, 1
        ctx->r19 = S32(U32(ctx->r19) >> 1);
            goto L_8000FE14;
    }
    // 0x8000FE08: srl         $s3, $s3, 1
    ctx->r19 = S32(U32(ctx->r19) >> 1);
    // 0x8000FE0C: bnel        $s3, $zero, L_8000FDAC
    if (ctx->r19 != 0) {
        // 0x8000FE10: andi        $t6, $s3, 0x1
        ctx->r14 = ctx->r19 & 0X1;
            goto L_8000FDAC;
    }
    goto skip_0;
    // 0x8000FE10: andi        $t6, $s3, 0x1
    ctx->r14 = ctx->r19 & 0X1;
    skip_0:
L_8000FE14:
    // 0x8000FE14: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000FE18: lhu         $v0, 0x5A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X5A);
    // 0x8000FE1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000FE20: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FE24: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000FE28: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000FE2C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000FE30: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FE34: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000FE38: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8000FE3C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000FE40: jr          $ra
    // 0x8000FE44: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8000FE44: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000fe48(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000fe48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FE48: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8000FE4C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000FE50: andi        $s1, $a1, 0xFFFF
    ctx->r17 = ctx->r5 & 0XFFFF;
    // 0x8000FE54: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000FE58: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000FE5C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8000FE60: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8000FE64: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8000FE68: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000FE6C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000FE70: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000FE74: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000FE78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000FE7C: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8000FE80: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
    // 0x8000FE84: addiu       $a1, $zero, 0x240
    ctx->r5 = ADD32(0, 0X240);
    // 0x8000FE88: jal         0x800279F0
    // 0x8000FE8C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800279F0)(rdram, ctx);
        goto after_0;
    // 0x8000FE8C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8000FE90: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8000FE94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000FE98: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8000FE9C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8000FEA0: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_8000FEA4:
    // 0x8000FEA4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000FEA8: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x8000FEAC: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x8000FEB0: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    // 0x8000FEB4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8000FEB8: bne         $a0, $a1, L_8000FEA4
    if (ctx->r4 != ctx->r5) {
        // 0x8000FEBC: sh          $v0, -0x8($v1)
        MEM_H(-0X8, ctx->r3) = ctx->r2;
            goto L_8000FEA4;
    }
    // 0x8000FEBC: sh          $v0, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r2;
    // 0x8000FEC0: lhu         $t6, 0x52($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X52);
    // 0x8000FEC4: addiu       $s6, $sp, 0x52
    ctx->r22 = ADD32(ctx->r29, 0X52);
    // 0x8000FEC8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000FECC: sh          $t6, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r14;
    // 0x8000FED0: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8000FED4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8000FED8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8000FEDC: lw          $s0, 0x2C($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X2C);
    // 0x8000FEE0: jal         0x8000FCD0
    // 0x8000FEE4: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x8000FCD0)(rdram, ctx);
        goto after_1;
    // 0x8000FEE4: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    after_1:
    // 0x8000FEE8: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x8000FEEC: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x8000FEF0: bne         $at, $zero, L_8000FF54
    if (ctx->r1 != 0) {
        // 0x8000FEF4: or          $s5, $s1, $zero
        ctx->r21 = ctx->r17 | 0;
            goto L_8000FF54;
    }
    // 0x8000FEF4: or          $s5, $s1, $zero
    ctx->r21 = ctx->r17 | 0;
    // 0x8000FEF8: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x8000FEFC: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x8000FF00: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000FF04: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
L_8000FF08:
    // 0x8000FF08: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8000FF0C: lhu         $a1, 0x52($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X52);
    // 0x8000FF10: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8000FF14: lw          $s0, 0x2C($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X2C);
    // 0x8000FF18: addiu       $s0, $s0, 0x5C
    ctx->r16 = ADD32(ctx->r16, 0X5C);
    // 0x8000FF1C: jal         0x8000FC60
    // 0x8000FF20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8000FC60)(rdram, ctx);
        goto after_2;
    // 0x8000FF20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8000FF24: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x8000FF28: lhu         $t0, 0x52($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X52);
    // 0x8000FF2C: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x8000FF30: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000FF34: bne         $t0, $t1, L_8000FF44
    if (ctx->r8 != ctx->r9) {
        // 0x8000FF38: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8000FF44;
    }
    // 0x8000FF38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000FF3C: jal         0x8000FCD0
    // 0x8000FF40: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    LOOKUP_FUNC(0x8000FCD0)(rdram, ctx);
        goto after_3;
    // 0x8000FF40: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_3:
L_8000FF44:
    // 0x8000FF44: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000FF48: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8000FF4C: bne         $s2, $s5, L_8000FF08
    if (ctx->r18 != ctx->r21) {
        // 0x8000FF50: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_8000FF08;
    }
    // 0x8000FF50: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_8000FF54:
    // 0x8000FF54: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000FF58: lhu         $v0, 0x52($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X52);
    // 0x8000FF5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000FF60: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FF64: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000FF68: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000FF6C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000FF70: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FF74: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000FF78: jr          $ra
    // 0x8000FF7C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8000FF7C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000ff80(rdram, ctx);
;}
