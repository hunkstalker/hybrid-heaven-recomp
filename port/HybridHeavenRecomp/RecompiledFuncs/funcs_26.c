#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_80136dd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136DD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136DDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136DE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80136DE4: swc1        $f4, 0x29C($v0)
    MEM_W(0X29C, ctx->r2) = ctx->f4.u32l;
    // 0x80136DE8: swc1        $f6, 0x2A0($v0)
    MEM_W(0X2A0, ctx->r2) = ctx->f6.u32l;
    // 0x80136DEC: jal         0x80005700
    // 0x80136DF0: sb          $t6, 0xF35($v0)
    MEM_B(0XF35, ctx->r2) = ctx->r14;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80136DF0: sb          $t6, 0xF35($v0)
    MEM_B(0XF35, ctx->r2) = ctx->r14;
    after_0:
    // 0x80136DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136DF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136DFC: jr          $ra
    // 0x80136E00: nop

    return;
    // 0x80136E00: nop

;}
RECOMP_FUNC void M7_FUN_80136e04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136E04: nop

    // 0x80136E08: nop

    // 0x80136E0C: nop

;}
RECOMP_FUNC void M7_FUN_80136e10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136E10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80136E14: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80136E18: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80136E1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80136E20: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80136E24: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80136E28: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80136E2C: jal         0x80005F6C
    // 0x80136E30: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_0;
    // 0x80136E30: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    after_0:
    // 0x80136E34: jal         0x80006214
    // 0x80136E38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80136E38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80136E3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80136E40: jal         0x8012636C
    // 0x80136E44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_2;
    // 0x80136E44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80136E48: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80136E4C: ori         $a1, $a1, 0xC00
    ctx->r5 = ctx->r5 | 0XC00;
    // 0x80136E50: jal         0x800062F8
    // 0x80136E54: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x800062F8)(rdram, ctx);
        goto after_3;
    // 0x80136E54: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80136E58: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80136E5C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80136E60: addiu       $t6, $t6, -0x50C8
    ctx->r14 = ADD32(ctx->r14, -0X50C8);
    // 0x80136E64: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80136E68: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x80136E6C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80136E70: sw          $t6, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r14;
    // 0x80136E74: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80136E78: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80136E7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80136E80: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80136E84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136E88: sw          $t9, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r25;
    // 0x80136E8C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80136E90: lbu         $t2, 0xF32($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XF32);
    // 0x80136E94: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80136E98: sb          $t2, 0x4C($t4)
    MEM_B(0X4C, ctx->r12) = ctx->r10;
    // 0x80136E9C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80136EA0: lbu         $t5, 0xF33($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XF33);
    // 0x80136EA4: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x80136EA8: sb          $t5, 0x4D($t6)
    MEM_B(0X4D, ctx->r14) = ctx->r13;
    // 0x80136EAC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80136EB0: lbu         $t8, 0xF34($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XF34);
    // 0x80136EB4: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x80136EB8: sb          $t8, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = ctx->r24;
    // 0x80136EBC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80136EC0: lbu         $t1, 0xF35($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XF35);
    // 0x80136EC4: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x80136EC8: sb          $t1, 0x4F($t2)
    MEM_B(0X4F, ctx->r10) = ctx->r9;
    // 0x80136ECC: lw          $t4, 0x38($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X38);
    // 0x80136ED0: lw          $a2, 0x10($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X10);
    // 0x80136ED4: jal         0x8012C784
    // 0x80136ED8: srl         $a2, $a2, 24
    ctx->r6 = S32(U32(ctx->r6) >> 24);
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_4;
    // 0x80136ED8: srl         $a2, $a2, 24
    ctx->r6 = S32(U32(ctx->r6) >> 24);
    after_4:
    // 0x80136EDC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80136EE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80136EE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136EE8: lw          $t5, 0x30($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X30);
    // 0x80136EEC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136EF0: addiu       $a1, $a1, 0x6F30
    ctx->r5 = ADD32(ctx->r5, 0X6F30);
    // 0x80136EF4: swc1        $f4, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f4.u32l;
    // 0x80136EF8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80136EFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80136F00: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80136F04: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80136F08: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80136F0C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80136F10: lw          $t8, 0x30($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X30);
    // 0x80136F14: jal         0x800058DC
    // 0x80136F18: swc1        $f0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f0.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80136F18: swc1        $f0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f0.u32l;
    after_5:
    // 0x80136F1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80136F20: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80136F24: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80136F28: jr          $ra
    // 0x80136F2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80136F2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80136f30(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80136f30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136F38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80136F3C: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x80136F40: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80136F44: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    // 0x80136F48: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80136F4C: jal         0x80133A24
    // 0x80136F50: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x80136F50: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_0:
    // 0x80136F54: beq         $v0, $zero, L_80136F80
    if (ctx->r2 == 0) {
        // 0x80136F58: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80136F80;
    }
    // 0x80136F58: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80136F5C: lw          $t7, 0x38($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X38);
    // 0x80136F60: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136F64: addiu       $a1, $a1, 0x6F90
    ctx->r5 = ADD32(ctx->r5, 0X6F90);
    // 0x80136F68: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80136F6C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80136F70: srl         $t9, $t8, 16
    ctx->r25 = S32(U32(ctx->r24) >> 16);
    // 0x80136F74: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80136F78: jal         0x800058DC
    // 0x80136F7C: sh          $t0, 0x90($a2)
    MEM_H(0X90, ctx->r6) = ctx->r8;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80136F7C: sh          $t0, 0x90($a2)
    MEM_H(0X90, ctx->r6) = ctx->r8;
    after_1:
L_80136F80:
    // 0x80136F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136F88: jr          $ra
    // 0x80136F8C: nop

    return;
    // 0x80136F8C: nop

;}
RECOMP_FUNC void M7_FUN_80136f90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136F90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80136F94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80136F98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80136F9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80136FA0: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x80136FA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80136FA8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80136FAC: srl         $t8, $t7, 8
    ctx->r24 = S32(U32(ctx->r15) >> 8);
    // 0x80136FB0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80136FB4: sltiu       $at, $t9, 0x80
    ctx->r1 = ctx->r25 < 0X80 ? 1 : 0;
    // 0x80136FB8: beql        $at, $zero, L_80137088
    if (ctx->r1 == 0) {
        // 0x80136FBC: lw          $t4, 0x24($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X24);
            goto L_80137088;
    }
    goto skip_0;
    // 0x80136FBC: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x80136FC0: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x80136FC4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80136FC8: jal         0x8001EB64
    // 0x80136FCC: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x80136FCC: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_0:
    // 0x80136FD0: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80136FD4: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80136FD8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80136FDC: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x80136FE0: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x80136FE4: srl         $t5, $t4, 8
    ctx->r13 = S32(U32(ctx->r12) >> 8);
    // 0x80136FE8: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80136FEC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80136FF0: bgez        $t6, L_80137004
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80136FF4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80137004;
    }
    // 0x80136FF4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80136FF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80136FFC: nop

    // 0x80137000: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80137004:
    // 0x80137004: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80137008: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013700C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80137010: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80137014: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80137018: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8013701C: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80137020: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80137024: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80137028: jal         0x8001EAD0
    // 0x8013702C: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x8013702C: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_1:
    // 0x80137030: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x80137034: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80137038: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8013703C: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80137040: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80137044: srl         $t2, $t1, 8
    ctx->r10 = S32(U32(ctx->r9) >> 8);
    // 0x80137048: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8013704C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80137050: bgez        $t3, L_80137064
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80137054: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80137064;
    }
    // 0x80137054: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80137058: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013705C: nop

    // 0x80137060: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80137064:
    // 0x80137064: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80137068: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013706C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80137070: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80137074: div.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80137078: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8013707C: b           L_8013714C
    // 0x80137080: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
        goto L_8013714C;
    // 0x80137080: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x80137084: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
L_80137088:
    // 0x80137088: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8013708C: jal         0x8001EB64
    // 0x80137090: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x80137090: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_2:
    // 0x80137094: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x80137098: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x8013709C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801370A0: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x801370A4: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x801370A8: srl         $t9, $t8, 8
    ctx->r25 = S32(U32(ctx->r24) >> 8);
    // 0x801370AC: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x801370B0: addiu       $t1, $t0, -0x80
    ctx->r9 = ADD32(ctx->r8, -0X80);
    // 0x801370B4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x801370B8: bgez        $t1, L_801370CC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801370BC: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801370CC;
    }
    // 0x801370BC: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801370C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801370C4: nop

    // 0x801370C8: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
L_801370CC:
    // 0x801370CC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801370D0: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x801370D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801370D8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801370DC: div.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801370E0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801370E4: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x801370E8: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801370EC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801370F0: jal         0x8001EAD0
    // 0x801370F4: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x801370F4: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_3:
    // 0x801370F8: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x801370FC: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x80137100: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80137104: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x80137108: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x8013710C: srl         $t7, $t6, 8
    ctx->r15 = S32(U32(ctx->r14) >> 8);
    // 0x80137110: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80137114: addiu       $t9, $t8, -0x80
    ctx->r25 = ADD32(ctx->r24, -0X80);
    // 0x80137118: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8013711C: bgez        $t9, L_80137130
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80137120: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80137130;
    }
    // 0x80137120: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80137124: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80137128: nop

    // 0x8013712C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80137130:
    // 0x80137130: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80137134: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80137138: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013713C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80137140: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80137144: sub.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80137148: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
L_8013714C:
    // 0x8013714C: lhu         $v0, 0x90($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X90);
    // 0x80137150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137154: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80137158: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8013715C: bne         $v0, $zero, L_8013716C
    if (ctx->r2 != 0) {
        // 0x80137160: sh          $t0, 0x90($s0)
        MEM_H(0X90, ctx->r16) = ctx->r8;
            goto L_8013716C;
    }
    // 0x80137160: sh          $t0, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r8;
    // 0x80137164: jal         0x800058DC
    // 0x80137168: addiu       $a1, $a1, 0x7180
    ctx->r5 = ADD32(ctx->r5, 0X7180);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80137168: addiu       $a1, $a1, 0x7180
    ctx->r5 = ADD32(ctx->r5, 0X7180);
    after_4:
L_8013716C:
    // 0x8013716C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80137170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80137174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80137178: jr          $ra
    // 0x8013717C: nop

    return;
    // 0x8013717C: nop

;}
RECOMP_FUNC void M7_FUN_80137180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137188: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8013718C: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x80137190: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80137194: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    // 0x80137198: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8013719C: jal         0x80133A24
    // 0x801371A0: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801371A0: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_0:
    // 0x801371A4: bne         $v0, $zero, L_801371D0
    if (ctx->r2 != 0) {
        // 0x801371A8: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_801371D0;
    }
    // 0x801371A8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801371AC: lw          $t7, 0x38($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X38);
    // 0x801371B0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801371B4: addiu       $a1, $a1, 0x71E0
    ctx->r5 = ADD32(ctx->r5, 0X71E0);
    // 0x801371B8: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x801371BC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801371C0: srl         $t9, $t8, 16
    ctx->r25 = S32(U32(ctx->r24) >> 16);
    // 0x801371C4: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x801371C8: jal         0x800058DC
    // 0x801371CC: sh          $t0, 0x90($a2)
    MEM_H(0X90, ctx->r6) = ctx->r8;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801371CC: sh          $t0, 0x90($a2)
    MEM_H(0X90, ctx->r6) = ctx->r8;
    after_1:
L_801371D0:
    // 0x801371D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801371D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801371D8: jr          $ra
    // 0x801371DC: nop

    return;
    // 0x801371DC: nop

;}
RECOMP_FUNC void M7_FUN_801371e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801371E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801371E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801371E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801371EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801371F0: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801371F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801371F8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x801371FC: srl         $t8, $t7, 8
    ctx->r24 = S32(U32(ctx->r15) >> 8);
    // 0x80137200: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80137204: sltiu       $at, $t9, 0x80
    ctx->r1 = ctx->r25 < 0X80 ? 1 : 0;
    // 0x80137208: beql        $at, $zero, L_801372D8
    if (ctx->r1 == 0) {
        // 0x8013720C: lw          $t4, 0x24($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X24);
            goto L_801372D8;
    }
    goto skip_0;
    // 0x8013720C: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x80137210: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x80137214: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80137218: jal         0x8001EB64
    // 0x8013721C: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x8013721C: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_0:
    // 0x80137220: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80137224: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80137228: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8013722C: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x80137230: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x80137234: srl         $t5, $t4, 8
    ctx->r13 = S32(U32(ctx->r12) >> 8);
    // 0x80137238: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8013723C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80137240: bgez        $t6, L_80137254
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80137244: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80137254;
    }
    // 0x80137244: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80137248: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013724C: nop

    // 0x80137250: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80137254:
    // 0x80137254: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80137258: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013725C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80137260: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80137264: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80137268: sub.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8013726C: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80137270: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80137274: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80137278: jal         0x8001EAD0
    // 0x8013727C: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x8013727C: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_1:
    // 0x80137280: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x80137284: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80137288: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8013728C: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80137290: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80137294: srl         $t2, $t1, 8
    ctx->r10 = S32(U32(ctx->r9) >> 8);
    // 0x80137298: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8013729C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x801372A0: bgez        $t3, L_801372B4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801372A4: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801372B4;
    }
    // 0x801372A4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801372A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801372AC: nop

    // 0x801372B0: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_801372B4:
    // 0x801372B4: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801372B8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801372BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801372C0: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801372C4: div.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x801372C8: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801372CC: b           L_8013739C
    // 0x801372D0: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
        goto L_8013739C;
    // 0x801372D0: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x801372D4: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
L_801372D8:
    // 0x801372D8: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801372DC: jal         0x8001EB64
    // 0x801372E0: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x801372E0: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_2:
    // 0x801372E4: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x801372E8: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801372EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801372F0: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x801372F4: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x801372F8: srl         $t9, $t8, 8
    ctx->r25 = S32(U32(ctx->r24) >> 8);
    // 0x801372FC: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80137300: addiu       $t1, $t0, -0x80
    ctx->r9 = ADD32(ctx->r8, -0X80);
    // 0x80137304: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80137308: bgez        $t1, L_8013731C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8013730C: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8013731C;
    }
    // 0x8013730C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80137310: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80137314: nop

    // 0x80137318: add.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f18.fl;
L_8013731C:
    // 0x8013731C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80137320: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80137324: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80137328: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8013732C: div.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80137330: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80137334: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80137338: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x8013733C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80137340: jal         0x8001EAD0
    // 0x80137344: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x80137344: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_3:
    // 0x80137348: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x8013734C: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x80137350: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80137354: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x80137358: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x8013735C: srl         $t7, $t6, 8
    ctx->r15 = S32(U32(ctx->r14) >> 8);
    // 0x80137360: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80137364: addiu       $t9, $t8, -0x80
    ctx->r25 = ADD32(ctx->r24, -0X80);
    // 0x80137368: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8013736C: bgez        $t9, L_80137380
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80137370: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80137380;
    }
    // 0x80137370: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80137374: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80137378: nop

    // 0x8013737C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80137380:
    // 0x80137380: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80137384: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80137388: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013738C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80137390: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80137394: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80137398: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
L_8013739C:
    // 0x8013739C: lhu         $v0, 0x90($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X90);
    // 0x801373A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801373A4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801373A8: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x801373AC: bne         $v0, $zero, L_801373BC
    if (ctx->r2 != 0) {
        // 0x801373B0: sh          $t0, 0x90($s0)
        MEM_H(0X90, ctx->r16) = ctx->r8;
            goto L_801373BC;
    }
    // 0x801373B0: sh          $t0, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r8;
    // 0x801373B4: jal         0x800058DC
    // 0x801373B8: addiu       $a1, $a1, 0x6F30
    ctx->r5 = ADD32(ctx->r5, 0X6F30);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801373B8: addiu       $a1, $a1, 0x6F30
    ctx->r5 = ADD32(ctx->r5, 0X6F30);
    after_4:
L_801373BC:
    // 0x801373BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801373C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801373C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801373C8: jr          $ra
    // 0x801373CC: nop

    return;
    // 0x801373CC: nop

;}
RECOMP_FUNC void M7_FUN_801373d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801373D0: jr          $ra
    // 0x801373D4: nop

    return;
    // 0x801373D4: nop

;}
RECOMP_FUNC void M7_FUN_801373d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801373D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801373DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801373E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801373E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801373E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801373EC: jal         0x80126CC0
    // 0x801373F0: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    LOOKUP_FUNC(0x80126CC0)(rdram, ctx);
        goto after_0;
    // 0x801373F0: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    after_0:
    // 0x801373F4: beq         $v0, $zero, L_80137408
    if (ctx->r2 == 0) {
        // 0x801373F8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80137408;
    }
    // 0x801373F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801373FC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80137400: jal         0x800058DC
    // 0x80137404: addiu       $a1, $a1, 0x7418
    ctx->r5 = ADD32(ctx->r5, 0X7418);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80137404: addiu       $a1, $a1, 0x7418
    ctx->r5 = ADD32(ctx->r5, 0X7418);
    after_1:
L_80137408:
    // 0x80137408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013740C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80137410: jr          $ra
    // 0x80137414: nop

    return;
    // 0x80137414: nop

;}
RECOMP_FUNC void M7_FUN_80137418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137418: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8013741C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80137420: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80137424: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80137428: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8013742C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80137430: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80137434: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80137438: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8013743C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80137440: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80137444: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80137448: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8013744C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80137450: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80137454: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80137458: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x8013745C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80137460: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x80137464: lw          $v0, 0x14($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X14);
    // 0x80137468: srl         $v0, $v0, 16
    ctx->r2 = S32(U32(ctx->r2) >> 16);
    // 0x8013746C: beq         $v0, $zero, L_80137480
    if (ctx->r2 == 0) {
        // 0x80137470: nop
    
            goto L_80137480;
    }
    // 0x80137470: nop

    // 0x80137474: jal         0x80133A24
    // 0x80137478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x80137478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_0:
    // 0x8013747C: beq         $v0, $zero, L_8013792C
    if (ctx->r2 == 0) {
        // 0x80137480: lui         $t7, 0x8016
        ctx->r15 = S32(0X8016 << 16);
            goto L_8013792C;
    }
L_80137480:
    // 0x80137480: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80137484: addiu       $t7, $t7, 0x4F40
    ctx->r15 = ADD32(ctx->r15, 0X4F40);
    // 0x80137488: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013748C: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x80137490: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80137494: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80137498: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8013749C: ori         $t0, $t0, 0x300
    ctx->r8 = ctx->r8 | 0X300;
    // 0x801374A0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801374A4: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x801374A8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801374AC: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
    // 0x801374B0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801374B4: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x801374B8: sw          $t0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r8;
    // 0x801374BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_801374C0:
    // 0x801374C0: jal         0x80005F6C
    // 0x801374C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_1;
    // 0x801374C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x801374C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801374CC: slti        $at, $s1, 0xE
    ctx->r1 = SIGNED(ctx->r17) < 0XE ? 1 : 0;
    // 0x801374D0: bnel        $at, $zero, L_801374C0
    if (ctx->r1 != 0) {
        // 0x801374D4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_801374C0;
    }
    goto skip_0;
    // 0x801374D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x801374D8: jal         0x80006214
    // 0x801374DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801374DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x801374E0: lui         $s4, 0x8018
    ctx->r20 = S32(0X8018 << 16);
    // 0x801374E4: addiu       $s4, $s4, -0x53A8
    ctx->r20 = ADD32(ctx->r20, -0X53A8);
    // 0x801374E8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801374EC: or          $s4, $s4, $at
    ctx->r20 = ctx->r20 | ctx->r1;
    // 0x801374F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801374F4: lui         $s5, 0x6
    ctx->r21 = S32(0X6 << 16);
    // 0x801374F8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801374FC: ori         $s5, $s5, 0x300
    ctx->r21 = ctx->r21 | 0X300;
    // 0x80137500: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80137504: or          $s0, $fp, $zero
    ctx->r16 = ctx->r30 | 0;
    // 0x80137508: addiu       $s7, $zero, 0xC8
    ctx->r23 = ADD32(0, 0XC8);
    // 0x8013750C: addiu       $s6, $zero, 0xE6
    ctx->r22 = ADD32(0, 0XE6);
    // 0x80137510: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
L_80137514:
    // 0x80137514: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80137518: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8013751C: addiu       $a2, $zero, 0x4B2
    ctx->r6 = ADD32(0, 0X4B2);
    // 0x80137520: jal         0x8012C89C
    // 0x80137524: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_3;
    // 0x80137524: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80137528: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8013752C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80137530: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80137534: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80137538: addiu       $a1, $zero, 0x4B2
    ctx->r5 = ADD32(0, 0X4B2);
    // 0x8013753C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80137540: jal         0x8012D8C8
    // 0x80137544: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x8012D8C8)(rdram, ctx);
        goto after_4;
    // 0x80137544: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_4:
    // 0x80137548: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8013754C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80137550: slti        $at, $s1, 0xE
    ctx->r1 = SIGNED(ctx->r17) < 0XE ? 1 : 0;
    // 0x80137554: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80137558: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8013755C: sw          $s5, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r21;
    // 0x80137560: lw          $t4, -0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, -0X4);
    // 0x80137564: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80137568: sw          $s4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r20;
    // 0x8013756C: lw          $t6, -0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, -0X4);
    // 0x80137570: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80137574: sb          $s2, 0x48($t7)
    MEM_B(0X48, ctx->r15) = ctx->r18;
    // 0x80137578: lw          $t8, -0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, -0X4);
    // 0x8013757C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80137580: sb          $s6, 0x49($t9)
    MEM_B(0X49, ctx->r25) = ctx->r22;
    // 0x80137584: lw          $t0, -0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, -0X4);
    // 0x80137588: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8013758C: sb          $zero, 0x4A($t1)
    MEM_B(0X4A, ctx->r9) = 0;
    // 0x80137590: lw          $t2, -0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, -0X4);
    // 0x80137594: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80137598: sb          $s7, 0x4B($t3)
    MEM_B(0X4B, ctx->r11) = ctx->r23;
    // 0x8013759C: lw          $t4, -0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, -0X4);
    // 0x801375A0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801375A4: sb          $s2, 0x4C($t5)
    MEM_B(0X4C, ctx->r13) = ctx->r18;
    // 0x801375A8: lw          $t6, -0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, -0X4);
    // 0x801375AC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801375B0: sb          $zero, 0x4D($t7)
    MEM_B(0X4D, ctx->r15) = 0;
    // 0x801375B4: lw          $t8, -0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, -0X4);
    // 0x801375B8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801375BC: bne         $at, $zero, L_80137514
    if (ctx->r1 != 0) {
        // 0x801375C0: sb          $zero, 0x4E($t9)
        MEM_B(0X4E, ctx->r25) = 0;
            goto L_80137514;
    }
    // 0x801375C0: sb          $zero, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = 0;
    // 0x801375C4: lw          $t0, 0x0($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X0);
    // 0x801375C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801375CC: lwc1        $f0, -0x2398($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2398);
    // 0x801375D0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801375D4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801375D8: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801375DC: swc1        $f0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f0.u32l;
    // 0x801375E0: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x801375E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801375E8: lwc1        $f4, -0x2394($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2394);
    // 0x801375EC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801375F0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801375F4: lui         $at, 0x4031
    ctx->r1 = S32(0X4031 << 16);
    // 0x801375F8: swc1        $f4, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f4.u32l;
    // 0x801375FC: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x80137600: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80137604: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80137608: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8013760C: addiu       $s0, $fp, 0x4
    ctx->r16 = ADD32(ctx->r30, 0X4);
    // 0x80137610: swc1        $f0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f0.u32l;
    // 0x80137614: lw          $t6, 0x38($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X38);
    // 0x80137618: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8013761C: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x80137620: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80137624: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80137628: nop

    // 0x8013762C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80137630: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80137634: div.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x80137638: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8013763C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80137640: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80137644: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80137648: swc1        $f18, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f18.u32l;
    // 0x8013764C: lw          $t0, 0x38($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X38);
    // 0x80137650: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x80137654: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x80137658: lh          $t1, 0x8($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X8);
    // 0x8013765C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80137660: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80137664: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80137668: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8013766C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137670: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80137674: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80137678: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x8013767C: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80137680: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80137684: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x80137688: lw          $t4, 0x38($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X38);
    // 0x8013768C: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80137690: lh          $t5, 0xA($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XA);
    // 0x80137694: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80137698: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8013769C: nop

    // 0x801376A0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801376A4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801376A8: div.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x801376AC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801376B0: swc1        $f18, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f18.u32l;
    // 0x801376B4: ldc1        $f24, -0x2390($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, -0X2390);
    // 0x801376B8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801376BC: ldc1        $f22, -0x2388($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, -0X2388);
L_801376C0:
    // 0x801376C0: jal         0x8012C6B4
    // 0x801376C4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x801376C4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_5:
    // 0x801376C8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801376CC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801376D0: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    // 0x801376D4: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801376D8: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801376DC: div.d       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f22.d);
    // 0x801376E0: add.d       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = ctx->f8.d + ctx->f24.d;
    // 0x801376E4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x801376E8: swc1        $f0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f0.u32l;
    // 0x801376EC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801376F0: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801376F4: swc1        $f0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
    // 0x801376F8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801376FC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80137700: jal         0x8012C6B4
    // 0x80137704: swc1        $f0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x80137704: swc1        $f0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f0.u32l;
    after_6:
    // 0x80137708: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013770C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80137710: andi        $s2, $v0, 0xFFFF
    ctx->r18 = ctx->r2 & 0XFFFF;
    // 0x80137714: jal         0x8001EAD0
    // 0x80137718: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_7;
    // 0x80137718: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_7:
    // 0x8013771C: lw          $t4, 0x38($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X38);
    // 0x80137720: mul.s       $f16, $f0, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80137724: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80137728: lh          $t5, 0x6($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6);
    // 0x8013772C: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x80137730: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80137734: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80137738: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8013773C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80137740: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80137744: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80137748: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x8013774C: add.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f18.d + ctx->f10.d;
    // 0x80137750: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80137754: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x80137758: lw          $t8, 0x38($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X38);
    // 0x8013775C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80137760: lh          $t9, 0x8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8);
    // 0x80137764: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80137768: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8013776C: nop

    // 0x80137770: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80137774: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80137778: div.d       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x8013777C: add.d       $f16, $f10, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f28.d); 
    ctx->f16.d = ctx->f10.d + ctx->f28.d;
    // 0x80137780: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80137784: jal         0x8001EB64
    // 0x80137788: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_8;
    // 0x80137788: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    after_8:
    // 0x8013778C: lw          $t2, 0x38($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X38);
    // 0x80137790: mul.s       $f6, $f0, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80137794: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80137798: lh          $t3, 0xA($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XA);
    // 0x8013779C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801377A0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801377A4: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x801377A8: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x801377AC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801377B0: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801377B4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801377B8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801377BC: div.d       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x801377C0: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x801377C4: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x801377C8: bne         $at, $zero, L_801376C0
    if (ctx->r1 != 0) {
        // 0x801377CC: swc1        $f18, 0xC($t5)
        MEM_W(0XC, ctx->r13) = ctx->f18.u32l;
            goto L_801376C0;
    }
    // 0x801377CC: swc1        $f18, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f18.u32l;
    // 0x801377D0: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801377D4: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x801377D8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801377DC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801377E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801377E4: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x801377E8: ldc1        $f24, -0x2380($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, -0X2380);
    // 0x801377EC: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
    // 0x801377F0: addiu       $s0, $fp, 0x18
    ctx->r16 = ADD32(ctx->r30, 0X18);
    // 0x801377F4: addiu       $s4, $zero, 0xE
    ctx->r20 = ADD32(0, 0XE);
L_801377F8:
    // 0x801377F8: jal         0x8012C6B4
    // 0x801377FC: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_9;
    // 0x801377FC: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_9:
    // 0x80137800: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80137804: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80137808: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    // 0x8013780C: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80137810: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80137814: div.d       $f8, $f16, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = DIV_D(ctx->f16.d, ctx->f22.d);
    // 0x80137818: add.d       $f4, $f8, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f24.d); 
    ctx->f4.d = ctx->f8.d + ctx->f24.d;
    // 0x8013781C: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x80137820: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x80137824: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80137828: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8013782C: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x80137830: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80137834: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80137838: jal         0x8012C6B4
    // 0x8013783C: swc1        $f0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_10;
    // 0x8013783C: swc1        $f0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f0.u32l;
    after_10:
    // 0x80137840: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137844: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80137848: andi        $s2, $v0, 0xFFFF
    ctx->r18 = ctx->r2 & 0XFFFF;
    // 0x8013784C: jal         0x8001EAD0
    // 0x80137850: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_11;
    // 0x80137850: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_11:
    // 0x80137854: lw          $t2, 0x38($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X38);
    // 0x80137858: mul.s       $f6, $f0, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8013785C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80137860: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x80137864: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x80137868: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8013786C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80137870: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80137874: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x80137878: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8013787C: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80137880: div.d       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80137884: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80137888: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8013788C: swc1        $f10, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f10.u32l;
    // 0x80137890: lw          $t6, 0x38($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X38);
    // 0x80137894: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80137898: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x8013789C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801378A0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x801378A4: nop

    // 0x801378A8: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801378AC: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x801378B0: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x801378B4: add.d       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f28.d); 
    ctx->f6.d = ctx->f4.d + ctx->f28.d;
    // 0x801378B8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x801378BC: jal         0x8001EB64
    // 0x801378C0: swc1        $f10, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_12;
    // 0x801378C0: swc1        $f10, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f10.u32l;
    after_12:
    // 0x801378C4: lw          $t0, 0x38($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X38);
    // 0x801378C8: mul.s       $f16, $f0, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x801378CC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801378D0: lh          $t1, 0xA($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XA);
    // 0x801378D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801378D8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801378DC: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x801378E0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801378E4: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801378E8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801378EC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801378F0: div.d       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x801378F4: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801378F8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801378FC: bne         $s1, $s4, L_801377F8
    if (ctx->r17 != ctx->r20) {
        // 0x80137900: swc1        $f18, 0xC($t3)
        MEM_W(0XC, ctx->r11) = ctx->f18.u32l;
            goto L_801377F8;
    }
    // 0x80137900: swc1        $f18, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f18.u32l;
    // 0x80137904: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80137908: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013790C: sh          $zero, 0x3C($s3)
    MEM_H(0X3C, ctx->r19) = 0;
    // 0x80137910: addiu       $a0, $zero, 0x5E7
    ctx->r4 = ADD32(0, 0X5E7);
    // 0x80137914: jal         0x80020718
    // 0x80137918: swc1        $f4, 0x90($s3)
    MEM_W(0X90, ctx->r19) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_13;
    // 0x80137918: swc1        $f4, 0x90($s3)
    MEM_W(0X90, ctx->r19) = ctx->f4.u32l;
    after_13:
    // 0x8013791C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80137920: addiu       $a1, $a1, 0x7970
    ctx->r5 = ADD32(ctx->r5, 0X7970);
    // 0x80137924: jal         0x800058DC
    // 0x80137928: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_14;
    // 0x80137928: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_14:
L_8013792C:
    // 0x8013792C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80137930: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80137934: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80137938: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8013793C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80137940: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80137944: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80137948: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8013794C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80137950: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80137954: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80137958: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8013795C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80137960: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80137964: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80137968: jr          $ra
    // 0x8013796C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8013796C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80137970(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80137970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137970: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80137974: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80137978: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8013797C: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x80137980: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80137984: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80137988: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8013798C: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80137990: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x80137994: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80137998: lh          $t8, 0xA($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA);
    // 0x8013799C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801379A0: lh          $t7, 0x8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X8);
    // 0x801379A4: addiu       $t9, $zero, 0x5E7
    ctx->r25 = ADD32(0, 0X5E7);
    // 0x801379A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801379AC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x801379B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801379B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801379B8: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801379BC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801379C0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801379C4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801379C8: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x801379CC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801379D0: div.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x801379D4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x801379D8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801379DC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801379E0: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x801379E4: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x801379E8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801379EC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801379F0: jal         0x801FCA4C
    // 0x801379F4: nop

    LOOKUP_FUNC(0x801FCA4C)(rdram, ctx);
        goto after_0;
    // 0x801379F4: nop

    after_0:
    // 0x801379F8: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x801379FC: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80137A00: lw          $t0, -0x4330($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4330);
    // 0x80137A04: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
    // 0x80137A08: lh          $t2, 0xA($v1)
    ctx->r10 = MEM_H(ctx->r3, 0XA);
    // 0x80137A0C: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x80137A10: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80137A14: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80137A18: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80137A1C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80137A20: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80137A24: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80137A28: div.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x80137A2C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80137A30: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80137A34: sub.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d - ctx->f4.d;
    // 0x80137A38: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80137A3C: div.d       $f16, $f18, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x80137A40: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80137A44: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80137A48: sub.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f16.d - ctx->f6.d;
    // 0x80137A4C: jal         0x8001EF38
    // 0x80137A50: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x80137A50: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    after_1:
    // 0x80137A54: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80137A58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80137A5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80137A60: lh          $t3, 0x6($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X6);
    // 0x80137A64: lh          $t5, 0xA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XA);
    // 0x80137A68: lh          $t4, 0x8($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X8);
    // 0x80137A6C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80137A70: lw          $a3, 0x90($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X90);
    // 0x80137A74: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80137A78: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80137A7C: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80137A80: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80137A84: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80137A88: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80137A8C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80137A90: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80137A94: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80137A98: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80137A9C: div.d       $f16, $f4, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x80137AA0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80137AA4: div.d       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x80137AA8: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    // 0x80137AAC: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80137AB0: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80137AB4: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80137AB8: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x80137ABC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80137AC0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80137AC4: jal         0x801FD644
    // 0x80137AC8: nop

    LOOKUP_FUNC(0x801FD644)(rdram, ctx);
        goto after_2;
    // 0x80137AC8: nop

    after_2:
    // 0x80137ACC: beql        $v0, $zero, L_80137B48
    if (ctx->r2 == 0) {
        // 0x80137AD0: lw          $t1, 0x38($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X38);
            goto L_80137B48;
    }
    goto skip_0;
    // 0x80137AD0: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    skip_0:
    // 0x80137AD4: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80137AD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80137ADC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80137AE0: lh          $t7, 0x6($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X6);
    // 0x80137AE4: lh          $t9, 0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XA);
    // 0x80137AE8: lh          $t8, 0x8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X8);
    // 0x80137AEC: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80137AF0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80137AF4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80137AF8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80137AFC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80137B00: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80137B04: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80137B08: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80137B0C: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80137B10: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80137B14: div.d       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x80137B18: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80137B1C: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x80137B20: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80137B24: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80137B28: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80137B2C: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80137B30: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x80137B34: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80137B38: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80137B3C: jal         0x80380F94
    // 0x80137B40: nop

    LOOKUP_FUNC(0x80380F94)(rdram, ctx);
        goto after_3;
    // 0x80137B40: nop

    after_3:
    // 0x80137B44: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
L_80137B48:
    // 0x80137B48: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80137B4C: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x80137B50: srl         $t3, $t2, 24
    ctx->r11 = S32(U32(ctx->r10) >> 24);
    // 0x80137B54: beql        $t3, $at, L_80137CF0
    if (ctx->r11 == ctx->r1) {
        // 0x80137B58: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_80137CF0;
    }
    goto skip_1;
    // 0x80137B58: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_1:
    // 0x80137B5C: lhu         $v0, 0x3C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3C);
    // 0x80137B60: andi        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 & 0X1;
    // 0x80137B64: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80137B68: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x80137B6C: beq         $v1, $zero, L_80137CEC
    if (ctx->r3 == 0) {
        // 0x80137B70: sh          $t4, 0x3C($s0)
        MEM_H(0X3C, ctx->r16) = ctx->r12;
            goto L_80137CEC;
    }
    // 0x80137B70: sh          $t4, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r12;
    // 0x80137B74: jal         0x8012C6B4
    // 0x80137B78: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80137B78: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_4:
    // 0x80137B7C: sh          $v0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r2;
    // 0x80137B80: jal         0x8012C6B4
    // 0x80137B84: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x80137B84: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_5:
    // 0x80137B88: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80137B8C: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80137B90: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80137B94: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x80137B98: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80137B9C: lh          $a0, 0x72($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X72);
    // 0x80137BA0: div.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f16.d, ctx->f6.d);
    // 0x80137BA4: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80137BA8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80137BAC: jal         0x8001EAD0
    // 0x80137BB0: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_6;
    // 0x80137BB0: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80137BB4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80137BB8: jal         0x8001EB64
    // 0x80137BBC: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_7;
    // 0x80137BBC: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x80137BC0: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x80137BC4: jal         0x8012C6B4
    // 0x80137BC8: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x80137BC8: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    after_8:
    // 0x80137BCC: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80137BD0: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80137BD4: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80137BD8: lh          $t5, 0x6($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X6);
    // 0x80137BDC: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
    // 0x80137BE0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80137BE4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80137BE8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80137BEC: lh          $t7, 0xA($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA);
    // 0x80137BF0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80137BF4: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x80137BF8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80137BFC: lwc1        $f6, 0x90($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80137C00: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x80137C04: addiu       $t9, $zero, 0x26
    ctx->r25 = ADD32(0, 0X26);
    // 0x80137C08: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x80137C0C: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80137C10: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80137C14: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80137C18: div.d       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f20.d);
    // 0x80137C1C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80137C20: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80137C24: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137C28: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80137C2C: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x80137C30: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x80137C34: addiu       $t4, $zero, -0x4
    ctx->r12 = ADD32(0, -0X4);
    // 0x80137C38: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80137C3C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80137C40: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80137C44: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80137C48: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80137C4C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80137C50: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80137C54: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80137C58: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80137C5C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80137C60: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80137C64: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80137C68: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80137C6C: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80137C70: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80137C74: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80137C78: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x80137C7C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80137C80: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x80137C84: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80137C88: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x80137C8C: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80137C90: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x80137C94: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80137C98: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80137C9C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80137CA0: cvt.s.d     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f14.fl = CVT_S_D(ctx->f16.d);
    // 0x80137CA4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80137CA8: lwc1        $f10, -0x2378($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2378);
    // 0x80137CAC: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x80137CB0: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80137CB4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137CB8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80137CBC: add.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f4.d + ctx->f18.d;
    // 0x80137CC0: ldc1        $f18, -0x2370($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2370);
    // 0x80137CC4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137CC8: cvt.d.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.d = CVT_D_W(ctx->f16.u32l);
    // 0x80137CCC: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80137CD0: div.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f18.d);
    // 0x80137CD4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80137CD8: ldc1        $f6, -0x2368($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2368);
    // 0x80137CDC: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x80137CE0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80137CE4: jal         0x80129FB8
    // 0x80137CE8: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_9;
    // 0x80137CE8: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_9:
L_80137CEC:
    // 0x80137CEC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80137CF0:
    // 0x80137CF0: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x80137CF4: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80137CF8: jr          $ra
    // 0x80137CFC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80137CFC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80137d00(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80137d00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137D00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137D08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80137D0C: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x80137D10: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80137D14: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    // 0x80137D18: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80137D1C: jal         0x80133A24
    // 0x80137D20: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x80137D20: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_0:
    // 0x80137D24: beq         $v0, $zero, L_80137E00
    if (ctx->r2 == 0) {
        // 0x80137D28: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80137E00;
    }
    // 0x80137D28: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80137D2C: lw          $v0, 0x38($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X38);
    // 0x80137D30: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x80137D34: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80137D38: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80137D3C: beq         $at, $zero, L_80137E00
    if (ctx->r1 == 0) {
        // 0x80137D40: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80137E00;
    }
    // 0x80137D40: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80137D44: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137D48: addu        $at, $at, $t8
    gpr jr_addend_80137D50 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80137D4C: lw          $t8, -0x2360($at)
    ctx->r24 = ADD32(ctx->r1, -0X2360);
    // 0x80137D50: jr          $t8
    // 0x80137D54: nop

    switch (jr_addend_80137D50 >> 2) {
        case 0: goto L_80137D58; break;
        case 1: goto L_80137D90; break;
        case 2: goto L_80137DC0; break;
        case 3: goto L_80137DD8; break;
        case 4: goto L_80137DF0; break;
        default: switch_error(__func__, 0x80137D50, 0x8018DCA0);
    }
    // 0x80137D54: nop

L_80137D58:
    // 0x80137D58: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137D5C: lwc1        $f4, -0x234C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X234C);
    // 0x80137D60: lui         $at, 0xC479
    ctx->r1 = S32(0XC479 << 16);
    // 0x80137D64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80137D68: swc1        $f4, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f4.u32l;
    // 0x80137D6C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80137D70: swc1        $f6, 0x98($a2)
    MEM_W(0X98, ctx->r6) = ctx->f6.u32l;
    // 0x80137D74: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x80137D78: addiu       $a1, $a1, 0x7E10
    ctx->r5 = ADD32(ctx->r5, 0X7E10);
    // 0x80137D7C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80137D80: jal         0x800058DC
    // 0x80137D84: sh          $t9, 0x9E($a2)
    MEM_H(0X9E, ctx->r6) = ctx->r25;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80137D84: sh          $t9, 0x9E($a2)
    MEM_H(0X9E, ctx->r6) = ctx->r25;
    after_1:
    // 0x80137D88: b           L_80137E04
    // 0x80137D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80137E04;
    // 0x80137D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80137D90:
    // 0x80137D90: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137D94: lwc1        $f8, -0x2348($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2348);
    // 0x80137D98: lui         $at, 0xC479
    ctx->r1 = S32(0XC479 << 16);
    // 0x80137D9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80137DA0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80137DA4: addiu       $a1, $a1, -0x7E30
    ctx->r5 = ADD32(ctx->r5, -0X7E30);
    // 0x80137DA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80137DAC: swc1        $f8, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f8.u32l;
    // 0x80137DB0: jal         0x800058DC
    // 0x80137DB4: swc1        $f10, 0x98($a2)
    MEM_W(0X98, ctx->r6) = ctx->f10.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80137DB4: swc1        $f10, 0x98($a2)
    MEM_W(0X98, ctx->r6) = ctx->f10.u32l;
    after_2:
    // 0x80137DB8: b           L_80137E04
    // 0x80137DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80137E04;
    // 0x80137DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80137DC0:
    // 0x80137DC0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80137DC4: addiu       $a1, $a1, -0x7C34
    ctx->r5 = ADD32(ctx->r5, -0X7C34);
    // 0x80137DC8: jal         0x800058DC
    // 0x80137DCC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80137DCC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80137DD0: b           L_80137E04
    // 0x80137DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80137E04;
    // 0x80137DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80137DD8:
    // 0x80137DD8: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80137DDC: addiu       $a1, $a1, -0x7834
    ctx->r5 = ADD32(ctx->r5, -0X7834);
    // 0x80137DE0: jal         0x800058DC
    // 0x80137DE4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80137DE4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x80137DE8: b           L_80137E04
    // 0x80137DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80137E04;
    // 0x80137DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80137DF0:
    // 0x80137DF0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80137DF4: addiu       $a1, $a1, -0x7470
    ctx->r5 = ADD32(ctx->r5, -0X7470);
    // 0x80137DF8: jal         0x800058DC
    // 0x80137DFC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80137DFC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
L_80137E00:
    // 0x80137E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80137E04:
    // 0x80137E04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80137E08: jr          $ra
    // 0x80137E0C: nop

    return;
    // 0x80137E0C: nop

;}
RECOMP_FUNC void M7_FUN_80137e10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137E10: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80137E14: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80137E18: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80137E1C: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80137E20: lhu         $t6, 0x9E($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X9E);
    // 0x80137E24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80137E28: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80137E2C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80137E30: sh          $t7, 0x9E($a0)
    MEM_H(0X9E, ctx->r4) = ctx->r15;
    // 0x80137E34: bgez        $t8, L_80137E48
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80137E38: andi        $t9, $t8, 0x1
        ctx->r25 = ctx->r24 & 0X1;
            goto L_80137E48;
    }
    // 0x80137E38: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80137E3C: beq         $t9, $zero, L_80137E48
    if (ctx->r25 == 0) {
        // 0x80137E40: nop
    
            goto L_80137E48;
    }
    // 0x80137E40: nop

    // 0x80137E44: addiu       $t9, $t9, -0x2
    ctx->r25 = ADD32(ctx->r25, -0X2);
L_80137E48:
    // 0x80137E48: bnel        $t9, $zero, L_80138190
    if (ctx->r25 != 0) {
        // 0x80137E4C: lw          $t0, 0x38($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X38);
            goto L_80138190;
    }
    goto skip_0;
    // 0x80137E4C: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    skip_0:
    // 0x80137E50: lhu         $t0, 0x9C($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X9C);
    // 0x80137E54: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    // 0x80137E58: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80137E5C: jal         0x8012C6B4
    // 0x80137E60: sh          $t1, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r9;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80137E60: sh          $t1, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r9;
    after_0:
    // 0x80137E64: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x80137E68: beq         $v1, $zero, L_80137E98
    if (ctx->r3 == 0) {
        // 0x80137E6C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80137E98;
    }
    // 0x80137E6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80137E70: beq         $v1, $at, L_80137FEC
    if (ctx->r3 == ctx->r1) {
        // 0x80137E74: addiu       $t4, $zero, 0xB
        ctx->r12 = ADD32(0, 0XB);
            goto L_80137FEC;
    }
    // 0x80137E74: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x80137E78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80137E7C: beq         $v1, $at, L_80137FF4
    if (ctx->r3 == ctx->r1) {
        // 0x80137E80: addiu       $t5, $zero, 0xC
        ctx->r13 = ADD32(0, 0XC);
            goto L_80137FF4;
    }
    // 0x80137E80: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80137E84: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80137E88: beq         $v1, $at, L_80137FFC
    if (ctx->r3 == ctx->r1) {
        // 0x80137E8C: addiu       $t6, $zero, 0xD
        ctx->r14 = ADD32(0, 0XD);
            goto L_80137FFC;
    }
    // 0x80137E8C: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x80137E90: b           L_80138004
    // 0x80137E94: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
        goto L_80138004;
    // 0x80137E94: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
L_80137E98:
    // 0x80137E98: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80137E9C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137EA0: ldc1        $f8, -0x2340($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2340);
    // 0x80137EA4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80137EA8: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80137EAC: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80137EB0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137EB4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80137EB8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80137EBC: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80137EC0: swc1        $f18, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f18.u32l;
    // 0x80137EC4: ldc1        $f8, -0x2338($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2338);
    // 0x80137EC8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80137ECC: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80137ED0: jal         0x8012C6B4
    // 0x80137ED4: swc1        $f18, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80137ED4: swc1        $f18, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f18.u32l;
    after_1:
    // 0x80137ED8: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80137EDC: jal         0x8012C6B4
    // 0x80137EE0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80137EE0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_2:
    // 0x80137EE4: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80137EE8: jal         0x8012C6B4
    // 0x80137EEC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x80137EEC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_3:
    // 0x80137EF0: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80137EF4: jal         0x8012C6B4
    // 0x80137EF8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80137EF8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_4:
    // 0x80137EFC: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80137F00: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80137F04: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80137F08: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80137F0C: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80137F10: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80137F14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80137F18: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80137F1C: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80137F20: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x80137F24: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80137F28: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80137F2C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80137F30: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80137F34: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80137F38: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80137F3C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80137F40: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80137F44: add.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d + ctx->f16.d;
    // 0x80137F48: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80137F4C: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80137F50: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80137F54: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80137F58: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80137F5C: addiu       $t5, $zero, 0x4B
    ctx->r13 = ADD32(0, 0X4B);
    // 0x80137F60: addiu       $t6, $zero, 0x4B
    ctx->r14 = ADD32(0, 0X4B);
    // 0x80137F64: sub.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80137F68: addiu       $t7, $zero, 0x4B
    ctx->r15 = ADD32(0, 0X4B);
    // 0x80137F6C: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x80137F70: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80137F74: lwc1        $f6, 0x98($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80137F78: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x80137F7C: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x80137F80: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80137F84: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x80137F88: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80137F8C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80137F90: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80137F94: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80137F98: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80137F9C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80137FA0: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x80137FA4: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80137FA8: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80137FAC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80137FB0: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80137FB4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80137FB8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80137FBC: div.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f16.d);
    // 0x80137FC0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80137FC4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80137FC8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80137FCC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80137FD0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80137FD4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80137FD8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80137FDC: jal         0x80129FB8
    // 0x80137FE0: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_5;
    // 0x80137FE0: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80137FE4: b           L_801381B4
    // 0x80137FE8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_801381B4;
    // 0x80137FE8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80137FEC:
    // 0x80137FEC: b           L_80138000
    // 0x80137FF0: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
        goto L_80138000;
    // 0x80137FF0: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
L_80137FF4:
    // 0x80137FF4: b           L_80138000
    // 0x80137FF8: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
        goto L_80138000;
    // 0x80137FF8: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
L_80137FFC:
    // 0x80137FFC: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
L_80138000:
    // 0x80138000: lwc1        $f18, 0x94($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X94);
L_80138004:
    // 0x80138004: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80138008: ldc1        $f6, -0x2330($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2330);
    // 0x8013800C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80138010: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80138014: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80138018: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013801C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80138020: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80138024: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80138028: swc1        $f10, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f10.u32l;
    // 0x8013802C: ldc1        $f6, -0x2328($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2328);
    // 0x80138030: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80138034: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80138038: jal         0x8012C6B4
    // 0x8013803C: swc1        $f10, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x8013803C: swc1        $f10, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f10.u32l;
    after_6:
    // 0x80138040: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80138044: jal         0x8012C6B4
    // 0x80138048: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x80138048: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_7:
    // 0x8013804C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80138050: jal         0x8012C6B4
    // 0x80138054: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x80138054: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_8:
    // 0x80138058: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8013805C: jal         0x8012C6B4
    // 0x80138060: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_9;
    // 0x80138060: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_9:
    // 0x80138064: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80138068: jal         0x8012C6B4
    // 0x8013806C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_10;
    // 0x8013806C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_10:
    // 0x80138070: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80138074: jal         0x8012C6B4
    // 0x80138078: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_11;
    // 0x80138078: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_11:
    // 0x8013807C: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80138080: jal         0x8012C6B4
    // 0x80138084: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_12;
    // 0x80138084: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_12:
    // 0x80138088: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8013808C: jal         0x8012C6B4
    // 0x80138090: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_13;
    // 0x80138090: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_13:
    // 0x80138094: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80138098: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8013809C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801380A0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x801380A4: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x801380A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801380AC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801380B0: lwc1        $f6, 0x94($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801380B4: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x801380B8: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801380BC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801380C0: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x801380C4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801380C8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801380CC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801380D0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801380D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801380D8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801380DC: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x801380E0: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x801380E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801380E8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801380EC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x801380F0: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x801380F4: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x801380F8: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x801380FC: sub.s       $f12, $f8, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80138100: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80138104: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80138108: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x8013810C: lwc1        $f4, 0x98($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80138110: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80138114: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80138118: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8013811C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80138120: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80138124: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80138128: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8013812C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80138130: addiu       $t4, $t3, 0xE0
    ctx->r12 = ADD32(ctx->r11, 0XE0);
    // 0x80138134: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80138138: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x8013813C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80138140: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80138144: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80138148: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8013814C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80138150: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80138154: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80138158: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x8013815C: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80138160: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80138164: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80138168: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8013816C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80138170: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80138174: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80138178: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8013817C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80138180: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80138184: jal         0x80129FB8
    // 0x80138188: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_14;
    // 0x80138188: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x8013818C: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
L_80138190:
    // 0x80138190: lw          $a0, 0x10($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X10);
    // 0x80138194: jal         0x80133A24
    // 0x80138198: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_15;
    // 0x80138198: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_15:
    // 0x8013819C: bne         $v0, $zero, L_801381B0
    if (ctx->r2 != 0) {
        // 0x801381A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801381B0;
    }
    // 0x801381A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801381A4: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801381A8: jal         0x800058DC
    // 0x801381AC: addiu       $a1, $a1, -0x7E3C
    ctx->r5 = ADD32(ctx->r5, -0X7E3C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_16;
    // 0x801381AC: addiu       $a1, $a1, -0x7E3C
    ctx->r5 = ADD32(ctx->r5, -0X7E3C);
    after_16:
L_801381B0:
    // 0x801381B0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801381B4:
    // 0x801381B4: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801381B8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x801381BC: jr          $ra
    // 0x801381C0: nop

    return;
    // 0x801381C0: nop

;}
RECOMP_FUNC void M7_FUN_801381c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801381C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801381C8: jr          $ra
    // 0x801381CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801381CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801381d0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801381d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801381D0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801381D4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801381D8: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801381DC: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x801381E0: lhu         $t6, 0x9E($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X9E);
    // 0x801381E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801381E8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801381EC: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x801381F0: sh          $t7, 0x9E($a0)
    MEM_H(0X9E, ctx->r4) = ctx->r15;
    // 0x801381F4: bgez        $t8, L_80138208
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801381F8: andi        $t9, $t8, 0x7
        ctx->r25 = ctx->r24 & 0X7;
            goto L_80138208;
    }
    // 0x801381F8: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x801381FC: beq         $t9, $zero, L_80138208
    if (ctx->r25 == 0) {
        // 0x80138200: nop
    
            goto L_80138208;
    }
    // 0x80138200: nop

    // 0x80138204: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
L_80138208:
    // 0x80138208: bnel        $t9, $zero, L_8013838C
    if (ctx->r25 != 0) {
        // 0x8013820C: lw          $t5, 0x38($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X38);
            goto L_8013838C;
    }
    goto skip_0;
    // 0x8013820C: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    skip_0:
    // 0x80138210: lhu         $t0, 0x9C($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X9C);
    // 0x80138214: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80138218: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x8013821C: sh          $v0, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r2;
    // 0x80138220: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80138224: beq         $v0, $zero, L_80138254
    if (ctx->r2 == 0) {
        // 0x80138228: nop
    
            goto L_80138254;
    }
    // 0x80138228: nop

    // 0x8013822C: beq         $v0, $at, L_8013825C
    if (ctx->r2 == ctx->r1) {
        // 0x80138230: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8013825C;
    }
    // 0x80138230: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80138234: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80138238: beq         $v0, $at, L_80138264
    if (ctx->r2 == ctx->r1) {
        // 0x8013823C: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_80138264;
    }
    // 0x8013823C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80138240: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80138244: beq         $v0, $at, L_8013826C
    if (ctx->r2 == ctx->r1) {
        // 0x80138248: addiu       $t4, $zero, 0x5
        ctx->r12 = ADD32(0, 0X5);
            goto L_8013826C;
    }
    // 0x80138248: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8013824C: b           L_80138274
    // 0x80138250: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
        goto L_80138274;
    // 0x80138250: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
L_80138254:
    // 0x80138254: b           L_80138270
    // 0x80138258: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
        goto L_80138270;
    // 0x80138258: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
L_8013825C:
    // 0x8013825C: b           L_80138270
    // 0x80138260: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
        goto L_80138270;
    // 0x80138260: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
L_80138264:
    // 0x80138264: b           L_80138270
    // 0x80138268: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
        goto L_80138270;
    // 0x80138268: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
L_8013826C:
    // 0x8013826C: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
L_80138270:
    // 0x80138270: lwc1        $f4, 0x94($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X94);
L_80138274:
    // 0x80138274: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80138278: ldc1        $f8, -0x2320($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2320);
    // 0x8013827C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80138280: lwc1        $f18, 0x98($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X98);
    // 0x80138284: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80138288: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013828C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80138290: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80138294: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80138298: swc1        $f16, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f16.u32l;
    // 0x8013829C: ldc1        $f6, -0x2318($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2318);
    // 0x801382A0: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801382A4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801382A8: jal         0x8012C6B4
    // 0x801382AC: swc1        $f10, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x801382AC: swc1        $f10, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f10.u32l;
    after_0:
    // 0x801382B0: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x801382B4: jal         0x8012C6B4
    // 0x801382B8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x801382B8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_1:
    // 0x801382BC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x801382C0: jal         0x8012C6B4
    // 0x801382C4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x801382C4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_2:
    // 0x801382C8: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x801382CC: jal         0x8012C6B4
    // 0x801382D0: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801382D0: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_3:
    // 0x801382D4: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x801382D8: jal         0x8012C6B4
    // 0x801382DC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801382DC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_4:
    // 0x801382E0: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x801382E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801382E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801382EC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801382F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801382F4: lwc1        $f16, -0x2310($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2310);
    // 0x801382F8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801382FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80138300: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80138304: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80138308: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
    // 0x8013830C: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80138310: lw          $a2, 0x98($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X98);
    // 0x80138314: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80138318: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8013831C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80138320: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80138324: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80138328: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8013832C: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x80138330: lui         $a3, 0xBE1B
    ctx->r7 = S32(0XBE1B << 16);
    // 0x80138334: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80138338: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8013833C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80138340: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80138344: addiu       $t9, $t8, 0xE0
    ctx->r25 = ADD32(ctx->r24, 0XE0);
    // 0x80138348: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8013834C: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80138350: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80138354: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80138358: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8013835C: ori         $a3, $a3, 0xA5E3
    ctx->r7 = ctx->r7 | 0XA5E3;
    // 0x80138360: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80138364: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80138368: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8013836C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80138370: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80138374: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80138378: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8013837C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80138380: jal         0x80129FB8
    // 0x80138384: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_5;
    // 0x80138384: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80138388: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
L_8013838C:
    // 0x8013838C: lw          $a0, 0x10($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X10);
    // 0x80138390: jal         0x80133A24
    // 0x80138394: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_6;
    // 0x80138394: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_6:
    // 0x80138398: bne         $v0, $zero, L_801383AC
    if (ctx->r2 != 0) {
        // 0x8013839C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801383AC;
    }
    // 0x8013839C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801383A0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801383A4: jal         0x800058DC
    // 0x801383A8: addiu       $a1, $a1, -0x7C40
    ctx->r5 = ADD32(ctx->r5, -0X7C40);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801383A8: addiu       $a1, $a1, -0x7C40
    ctx->r5 = ADD32(ctx->r5, -0X7C40);
    after_7:
L_801383AC:
    // 0x801383AC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801383B0: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801383B4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x801383B8: jr          $ra
    // 0x801383BC: nop

    return;
    // 0x801383BC: nop

;}
RECOMP_FUNC void M7_FUN_801383c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801383C0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801383C4: jr          $ra
    // 0x801383C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801383C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801383cc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801383cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801383CC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801383D0: sw          $s3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r19;
    // 0x801383D4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801383D8: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x801383DC: sw          $s2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r18;
    // 0x801383E0: sw          $s1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r17;
    // 0x801383E4: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
    // 0x801383E8: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x801383EC: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x801383F0: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x801383F4: jal         0x8012C6B4
    // 0x801383F8: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x801383F8: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_0:
    // 0x801383FC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80138400: jal         0x8012C6B4
    // 0x80138404: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80138404: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_1:
    // 0x80138408: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8013840C: jal         0x8012C6B4
    // 0x80138410: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80138410: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_2:
    // 0x80138414: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80138418: jal         0x8012C6B4
    // 0x8013841C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x8013841C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_3:
    // 0x80138420: lw          $v1, 0x38($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X38);
    // 0x80138424: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80138428: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8013842C: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x80138430: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80138434: lh          $t8, 0xA($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA);
    // 0x80138438: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8013843C: lh          $t7, 0x8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X8);
    // 0x80138440: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80138444: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80138448: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8013844C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80138450: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80138454: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80138458: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8013845C: addiu       $t1, $s0, 0xE0
    ctx->r9 = ADD32(ctx->r16, 0XE0);
    // 0x80138460: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80138464: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80138468: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x8013846C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80138470: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80138474: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x80138478: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8013847C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80138480: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80138484: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80138488: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x8013848C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80138490: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80138494: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80138498: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8013849C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x801384A0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x801384A4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x801384A8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x801384AC: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801384B0: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x801384B4: div.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x801384B8: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x801384BC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801384C0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801384C4: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x801384C8: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x801384CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801384D0: nop

    // 0x801384D4: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x801384D8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801384DC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801384E0: jal         0x80129FB8
    // 0x801384E4: nop

    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_4;
    // 0x801384E4: nop

    after_4:
    // 0x801384E8: jal         0x8012C6B4
    // 0x801384EC: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x801384EC: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_5:
    // 0x801384F0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x801384F4: jal         0x8012C6B4
    // 0x801384F8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x801384F8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_6:
    // 0x801384FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80138500: jal         0x8012C6B4
    // 0x80138504: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x80138504: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_7:
    // 0x80138508: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8013850C: jal         0x8012C6B4
    // 0x80138510: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x80138510: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_8:
    // 0x80138514: lw          $v1, 0x38($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X38);
    // 0x80138518: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8013851C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80138520: lh          $t5, 0x6($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X6);
    // 0x80138524: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
    // 0x80138528: lh          $t7, 0xA($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA);
    // 0x8013852C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80138530: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80138534: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80138538: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013853C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80138540: addiu       $t0, $s0, 0xE0
    ctx->r8 = ADD32(ctx->r16, 0XE0);
    // 0x80138544: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80138548: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8013854C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80138550: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80138554: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x80138558: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x8013855C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80138560: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80138564: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80138568: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x8013856C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80138570: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80138574: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80138578: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013857C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80138580: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80138584: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80138588: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8013858C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80138590: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80138594: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80138598: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8013859C: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x801385A0: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801385A4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x801385A8: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x801385AC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801385B0: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x801385B4: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801385B8: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x801385BC: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x801385C0: lwc1        $f18, -0x230C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X230C);
    // 0x801385C4: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x801385C8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801385CC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801385D0: jal         0x80129FB8
    // 0x801385D4: nop

    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_9;
    // 0x801385D4: nop

    after_9:
    // 0x801385D8: jal         0x8012C6B4
    // 0x801385DC: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_10;
    // 0x801385DC: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_10:
    // 0x801385E0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x801385E4: jal         0x8012C6B4
    // 0x801385E8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_11;
    // 0x801385E8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_11:
    // 0x801385EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801385F0: jal         0x8012C6B4
    // 0x801385F4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_12;
    // 0x801385F4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_12:
    // 0x801385F8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801385FC: jal         0x8012C6B4
    // 0x80138600: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_13;
    // 0x80138600: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_13:
    // 0x80138604: lw          $v1, 0x38($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X38);
    // 0x80138608: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013860C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80138610: lh          $t4, 0x6($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X6);
    // 0x80138614: lh          $t6, 0xA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA);
    // 0x80138618: lh          $t5, 0x8($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X8);
    // 0x8013861C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80138620: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80138624: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80138628: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013862C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80138630: addiu       $t9, $s0, 0xE0
    ctx->r25 = ADD32(ctx->r16, 0XE0);
    // 0x80138634: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80138638: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8013863C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80138640: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80138644: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80138648: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8013864C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80138650: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80138654: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80138658: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x8013865C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80138660: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80138664: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80138668: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8013866C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80138670: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80138674: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80138678: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8013867C: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80138680: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80138684: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80138688: div.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f20.d);
    // 0x8013868C: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x80138690: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80138694: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80138698: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x8013869C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x801386A0: lwc1        $f6, -0x2308($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2308);
    // 0x801386A4: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x801386A8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801386AC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801386B0: jal         0x80129FB8
    // 0x801386B4: nop

    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_14;
    // 0x801386B4: nop

    after_14:
    // 0x801386B8: lw          $v1, 0x38($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X38);
    // 0x801386BC: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801386C0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801386C4: lh          $t3, 0x6($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X6);
    // 0x801386C8: lh          $t4, 0x8($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X8);
    // 0x801386CC: lh          $t5, 0xA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XA);
    // 0x801386D0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x801386D4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x801386D8: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x801386DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801386E0: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x801386E4: addiu       $t6, $zero, 0x4B
    ctx->r14 = ADD32(0, 0X4B);
    // 0x801386E8: addiu       $t7, $zero, 0x4B
    ctx->r15 = ADD32(0, 0X4B);
    // 0x801386EC: addiu       $t8, $zero, 0x4B
    ctx->r24 = ADD32(0, 0X4B);
    // 0x801386F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801386F4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801386F8: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x801386FC: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x80138700: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80138704: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80138708: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8013870C: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x80138710: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80138714: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80138718: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013871C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80138720: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80138724: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80138728: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8013872C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80138730: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80138734: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80138738: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8013873C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80138740: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80138744: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80138748: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8013874C: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80138750: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80138754: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80138758: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x8013875C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80138760: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x80138764: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80138768: div.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f20.d);
    // 0x8013876C: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x80138770: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80138774: nop

    // 0x80138778: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8013877C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80138780: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80138784: jal         0x80129FB8
    // 0x80138788: nop

    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_15;
    // 0x80138788: nop

    after_15:
    // 0x8013878C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80138790: addiu       $a1, $a1, -0x7840
    ctx->r5 = ADD32(ctx->r5, -0X7840);
    // 0x80138794: jal         0x800058DC
    // 0x80138798: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_16;
    // 0x80138798: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_16:
    // 0x8013879C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x801387A0: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x801387A4: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x801387A8: lw          $s0, 0x5C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X5C);
    // 0x801387AC: lw          $s1, 0x60($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X60);
    // 0x801387B0: lw          $s2, 0x64($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X64);
    // 0x801387B4: lw          $s3, 0x68($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X68);
    // 0x801387B8: jr          $ra
    // 0x801387BC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x801387BC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801387c0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801387c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801387C0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801387C4: jr          $ra
    // 0x801387C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801387C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801387cc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801387cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801387CC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x801387D0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801387D4: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801387D8: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x801387DC: lhu         $t6, 0x9E($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X9E);
    // 0x801387E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801387E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801387E8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801387EC: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x801387F0: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x801387F4: mfhi        $t9
    ctx->r25 = hi;
    // 0x801387F8: sh          $t7, 0x9E($a0)
    MEM_H(0X9E, ctx->r4) = ctx->r15;
    // 0x801387FC: bnel        $t9, $zero, L_80138B50
    if (ctx->r25 != 0) {
        // 0x80138800: lw          $t6, 0x38($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X38);
            goto L_80138B50;
    }
    goto skip_0;
    // 0x80138800: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    skip_0:
    // 0x80138804: lhu         $t0, 0x9C($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X9C);
    // 0x80138808: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8013880C: sh          $t1, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r9;
    // 0x80138810: jal         0x8012C6B4
    // 0x80138814: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80138814: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_0:
    // 0x80138818: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x8013881C: beq         $v1, $zero, L_8013884C
    if (ctx->r3 == 0) {
        // 0x80138820: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8013884C;
    }
    // 0x80138820: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80138824: beq         $v1, $at, L_801389AC
    if (ctx->r3 == ctx->r1) {
        // 0x80138828: addiu       $t7, $zero, 0x9
        ctx->r15 = ADD32(0, 0X9);
            goto L_801389AC;
    }
    // 0x80138828: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x8013882C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80138830: beq         $v1, $at, L_801389B4
    if (ctx->r3 == ctx->r1) {
        // 0x80138834: addiu       $t8, $zero, 0xC
        ctx->r24 = ADD32(0, 0XC);
            goto L_801389B4;
    }
    // 0x80138834: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80138838: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8013883C: beq         $v1, $at, L_801389BC
    if (ctx->r3 == ctx->r1) {
        // 0x80138840: addiu       $t9, $zero, 0xD
        ctx->r25 = ADD32(0, 0XD);
            goto L_801389BC;
    }
    // 0x80138840: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
    // 0x80138844: b           L_801389C0
    // 0x80138848: nop

        goto L_801389C0;
    // 0x80138848: nop

L_8013884C:
    // 0x8013884C: jal         0x8012C6B4
    // 0x80138850: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80138850: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x80138854: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80138858: jal         0x8012C6B4
    // 0x8013885C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x8013885C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_2:
    // 0x80138860: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80138864: jal         0x8012C6B4
    // 0x80138868: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x80138868: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_3:
    // 0x8013886C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80138870: jal         0x8012C6B4
    // 0x80138874: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80138874: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_4:
    // 0x80138878: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x8013887C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80138880: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80138884: lh          $t3, 0x6($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X6);
    // 0x80138888: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8013888C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80138890: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80138894: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80138898: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8013889C: lh          $t5, 0x8($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X8);
    // 0x801388A0: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801388A4: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801388A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801388AC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801388B0: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x801388B4: lh          $t7, 0xA($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA);
    // 0x801388B8: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x801388BC: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801388C0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x801388C4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801388C8: div.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x801388CC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x801388D0: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801388D4: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x801388D8: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x801388DC: addiu       $t8, $zero, 0x4B
    ctx->r24 = ADD32(0, 0X4B);
    // 0x801388E0: addiu       $t9, $zero, 0x4B
    ctx->r25 = ADD32(0, 0X4B);
    // 0x801388E4: addiu       $t0, $zero, 0x4B
    ctx->r8 = ADD32(0, 0X4B);
    // 0x801388E8: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x801388EC: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801388F0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801388F4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x801388F8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801388FC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80138900: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80138904: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80138908: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8013890C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80138910: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80138914: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80138918: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8013891C: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x80138920: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80138924: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80138928: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x8013892C: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80138930: sub.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f8.d - ctx->f2.d;
    // 0x80138934: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80138938: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x8013893C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80138940: div.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x80138944: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80138948: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8013894C: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80138950: add.d       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f6.d + ctx->f18.d;
    // 0x80138954: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80138958: cvt.d.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.d = CVT_D_W(ctx->f10.u32l);
    // 0x8013895C: sub.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f4.d - ctx->f2.d;
    // 0x80138960: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80138964: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x80138968: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8013896C: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x80138970: add.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d + ctx->f10.d;
    // 0x80138974: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80138978: sub.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d - ctx->f2.d;
    // 0x8013897C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80138980: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80138984: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80138988: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8013898C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80138990: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80138994: div.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x80138998: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8013899C: jal         0x80129FB8
    // 0x801389A0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_5;
    // 0x801389A0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x801389A4: b           L_80138B74
    // 0x801389A8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80138B74;
    // 0x801389A8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801389AC:
    // 0x801389AC: b           L_801389C0
    // 0x801389B0: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
        goto L_801389C0;
    // 0x801389B0: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
L_801389B4:
    // 0x801389B4: b           L_801389C0
    // 0x801389B8: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
        goto L_801389C0;
    // 0x801389B8: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
L_801389BC:
    // 0x801389BC: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
L_801389C0:
    // 0x801389C0: jal         0x8012C6B4
    // 0x801389C4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x801389C4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_6:
    // 0x801389C8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x801389CC: jal         0x8012C6B4
    // 0x801389D0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x801389D0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_7:
    // 0x801389D4: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x801389D8: jal         0x8012C6B4
    // 0x801389DC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x801389DC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_8:
    // 0x801389E0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x801389E4: jal         0x8012C6B4
    // 0x801389E8: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_9;
    // 0x801389E8: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_9:
    // 0x801389EC: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x801389F0: jal         0x8012C6B4
    // 0x801389F4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_10;
    // 0x801389F4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_10:
    // 0x801389F8: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x801389FC: jal         0x8012C6B4
    // 0x80138A00: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_11;
    // 0x80138A00: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_11:
    // 0x80138A04: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80138A08: jal         0x8012C6B4
    // 0x80138A0C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_12;
    // 0x80138A0C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_12:
    // 0x80138A10: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80138A14: jal         0x8012C6B4
    // 0x80138A18: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_13;
    // 0x80138A18: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_13:
    // 0x80138A1C: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80138A20: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80138A24: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80138A28: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
    // 0x80138A2C: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80138A30: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80138A34: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80138A38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80138A3C: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x80138A40: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x80138A44: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80138A48: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80138A4C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80138A50: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80138A54: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80138A58: lh          $t5, 0xA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XA);
    // 0x80138A5C: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x80138A60: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x80138A64: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80138A68: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80138A6C: div.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x80138A70: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80138A74: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80138A78: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80138A7C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80138A80: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80138A84: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80138A88: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80138A8C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80138A90: addiu       $t0, $t9, 0xE0
    ctx->r8 = ADD32(ctx->r25, 0XE0);
    // 0x80138A94: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80138A98: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80138A9C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80138AA0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80138AA4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80138AA8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80138AAC: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80138AB0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80138AB4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80138AB8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80138ABC: add.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d + ctx->f10.d;
    // 0x80138AC0: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80138AC4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80138AC8: cvt.d.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.d = CVT_D_W(ctx->f6.u32l);
    // 0x80138ACC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80138AD0: sub.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f4.d - ctx->f2.d;
    // 0x80138AD4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80138AD8: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80138ADC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80138AE0: div.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x80138AE4: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80138AE8: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80138AEC: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80138AF0: add.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f18.d + ctx->f6.d;
    // 0x80138AF4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80138AF8: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x80138AFC: cvt.d.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.d = CVT_D_W(ctx->f8.u32l);
    // 0x80138B00: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80138B04: sub.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f10.d - ctx->f2.d;
    // 0x80138B08: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80138B0C: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x80138B10: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80138B14: div.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x80138B18: add.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f18.d + ctx->f8.d;
    // 0x80138B1C: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80138B20: sub.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d - ctx->f2.d;
    // 0x80138B24: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80138B28: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80138B2C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80138B30: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80138B34: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80138B38: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80138B3C: div.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f10.d);
    // 0x80138B40: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x80138B44: jal         0x80129FB8
    // 0x80138B48: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_14;
    // 0x80138B48: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_14:
    // 0x80138B4C: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
L_80138B50:
    // 0x80138B50: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    // 0x80138B54: jal         0x80133A24
    // 0x80138B58: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_15;
    // 0x80138B58: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_15:
    // 0x80138B5C: bne         $v0, $zero, L_80138B70
    if (ctx->r2 != 0) {
        // 0x80138B60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80138B70;
    }
    // 0x80138B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80138B64: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80138B68: jal         0x800058DC
    // 0x80138B6C: addiu       $a1, $a1, -0x747C
    ctx->r5 = ADD32(ctx->r5, -0X747C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_16;
    // 0x80138B6C: addiu       $a1, $a1, -0x747C
    ctx->r5 = ADD32(ctx->r5, -0X747C);
    after_16:
L_80138B70:
    // 0x80138B70: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80138B74:
    // 0x80138B74: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80138B78: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80138B7C: jr          $ra
    // 0x80138B80: nop

    return;
    // 0x80138B80: nop

;}
RECOMP_FUNC void M7_FUN_80138b84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138B84: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80138B88: jr          $ra
    // 0x80138B8C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80138B8C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80138b90(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80138b90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138B90: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80138B94: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80138B98: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80138B9C: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80138BA0: lhu         $t6, 0x9E($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X9E);
    // 0x80138BA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80138BA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80138BAC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80138BB0: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80138BB4: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80138BB8: mfhi        $t9
    ctx->r25 = hi;
    // 0x80138BBC: sh          $t7, 0x9E($a0)
    MEM_H(0X9E, ctx->r4) = ctx->r15;
    // 0x80138BC0: bnel        $t9, $zero, L_80138F14
    if (ctx->r25 != 0) {
        // 0x80138BC4: lw          $t6, 0x38($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X38);
            goto L_80138F14;
    }
    goto skip_0;
    // 0x80138BC4: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    skip_0:
    // 0x80138BC8: lhu         $t0, 0x9C($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X9C);
    // 0x80138BCC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80138BD0: sh          $t1, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r9;
    // 0x80138BD4: jal         0x8012C6B4
    // 0x80138BD8: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_0;
    // 0x80138BD8: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_0:
    // 0x80138BDC: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x80138BE0: beq         $v1, $zero, L_80138C10
    if (ctx->r3 == 0) {
        // 0x80138BE4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80138C10;
    }
    // 0x80138BE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80138BE8: beq         $v1, $at, L_80138D70
    if (ctx->r3 == ctx->r1) {
        // 0x80138BEC: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80138D70;
    }
    // 0x80138BEC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80138BF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80138BF4: beq         $v1, $at, L_80138D78
    if (ctx->r3 == ctx->r1) {
        // 0x80138BF8: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_80138D78;
    }
    // 0x80138BF8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80138BFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80138C00: beq         $v1, $at, L_80138D80
    if (ctx->r3 == ctx->r1) {
        // 0x80138C04: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_80138D80;
    }
    // 0x80138C04: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80138C08: b           L_80138D84
    // 0x80138C0C: nop

        goto L_80138D84;
    // 0x80138C0C: nop

L_80138C10:
    // 0x80138C10: jal         0x8012C6B4
    // 0x80138C14: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_1;
    // 0x80138C14: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x80138C18: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80138C1C: jal         0x8012C6B4
    // 0x80138C20: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_2;
    // 0x80138C20: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_2:
    // 0x80138C24: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80138C28: jal         0x8012C6B4
    // 0x80138C2C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x80138C2C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_3:
    // 0x80138C30: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80138C34: jal         0x8012C6B4
    // 0x80138C38: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x80138C38: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_4:
    // 0x80138C3C: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80138C40: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80138C44: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80138C48: lh          $t3, 0x6($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X6);
    // 0x80138C4C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80138C50: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80138C54: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80138C58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80138C5C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80138C60: lh          $t5, 0x8($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X8);
    // 0x80138C64: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80138C68: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80138C6C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80138C70: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80138C74: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80138C78: lh          $t7, 0xA($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA);
    // 0x80138C7C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80138C80: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x80138C84: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80138C88: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80138C8C: div.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x80138C90: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80138C94: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80138C98: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x80138C9C: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x80138CA0: addiu       $t8, $zero, 0x4B
    ctx->r24 = ADD32(0, 0X4B);
    // 0x80138CA4: addiu       $t9, $zero, 0x4B
    ctx->r25 = ADD32(0, 0X4B);
    // 0x80138CA8: addiu       $t0, $zero, 0x4B
    ctx->r8 = ADD32(0, 0X4B);
    // 0x80138CAC: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80138CB0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80138CB4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80138CB8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80138CBC: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80138CC0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80138CC4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80138CC8: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80138CCC: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80138CD0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80138CD4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80138CD8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80138CDC: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80138CE0: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x80138CE4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80138CE8: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80138CEC: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x80138CF0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80138CF4: sub.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f8.d - ctx->f2.d;
    // 0x80138CF8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80138CFC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x80138D00: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80138D04: div.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x80138D08: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80138D0C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80138D10: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80138D14: add.d       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f6.d + ctx->f18.d;
    // 0x80138D18: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80138D1C: cvt.d.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.d = CVT_D_W(ctx->f10.u32l);
    // 0x80138D20: sub.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f4.d - ctx->f2.d;
    // 0x80138D24: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80138D28: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x80138D2C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80138D30: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x80138D34: add.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d + ctx->f10.d;
    // 0x80138D38: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80138D3C: sub.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d - ctx->f2.d;
    // 0x80138D40: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80138D44: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80138D48: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80138D4C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80138D50: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80138D54: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80138D58: div.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x80138D5C: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80138D60: jal         0x80129FB8
    // 0x80138D64: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_5;
    // 0x80138D64: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80138D68: b           L_80138F38
    // 0x80138D6C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80138F38;
    // 0x80138D6C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80138D70:
    // 0x80138D70: b           L_80138D84
    // 0x80138D74: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
        goto L_80138D84;
    // 0x80138D74: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
L_80138D78:
    // 0x80138D78: b           L_80138D84
    // 0x80138D7C: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
        goto L_80138D84;
    // 0x80138D7C: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
L_80138D80:
    // 0x80138D80: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
L_80138D84:
    // 0x80138D84: jal         0x8012C6B4
    // 0x80138D88: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x80138D88: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_6:
    // 0x80138D8C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80138D90: jal         0x8012C6B4
    // 0x80138D94: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x80138D94: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_7:
    // 0x80138D98: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80138D9C: jal         0x8012C6B4
    // 0x80138DA0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x80138DA0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_8:
    // 0x80138DA4: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80138DA8: jal         0x8012C6B4
    // 0x80138DAC: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_9;
    // 0x80138DAC: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_9:
    // 0x80138DB0: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80138DB4: jal         0x8012C6B4
    // 0x80138DB8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_10;
    // 0x80138DB8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_10:
    // 0x80138DBC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80138DC0: jal         0x8012C6B4
    // 0x80138DC4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_11;
    // 0x80138DC4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_11:
    // 0x80138DC8: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80138DCC: jal         0x8012C6B4
    // 0x80138DD0: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_12;
    // 0x80138DD0: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_12:
    // 0x80138DD4: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80138DD8: jal         0x8012C6B4
    // 0x80138DDC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_13;
    // 0x80138DDC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_13:
    // 0x80138DE0: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80138DE4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80138DE8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80138DEC: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
    // 0x80138DF0: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80138DF4: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80138DF8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80138DFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80138E00: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x80138E04: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x80138E08: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80138E0C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80138E10: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80138E14: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80138E18: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80138E1C: lh          $t5, 0xA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XA);
    // 0x80138E20: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x80138E24: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x80138E28: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80138E2C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80138E30: div.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f0.d);
    // 0x80138E34: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80138E38: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80138E3C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80138E40: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80138E44: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80138E48: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80138E4C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80138E50: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80138E54: addiu       $t0, $t9, 0xE0
    ctx->r8 = ADD32(ctx->r25, 0XE0);
    // 0x80138E58: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80138E5C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80138E60: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80138E64: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80138E68: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80138E6C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80138E70: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80138E74: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80138E78: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80138E7C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80138E80: add.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d + ctx->f10.d;
    // 0x80138E84: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80138E88: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80138E8C: cvt.d.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.d = CVT_D_W(ctx->f6.u32l);
    // 0x80138E90: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80138E94: sub.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f4.d - ctx->f2.d;
    // 0x80138E98: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80138E9C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80138EA0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80138EA4: div.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x80138EA8: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80138EAC: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80138EB0: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80138EB4: add.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f18.d + ctx->f6.d;
    // 0x80138EB8: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80138EBC: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x80138EC0: cvt.d.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.d = CVT_D_W(ctx->f8.u32l);
    // 0x80138EC4: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80138EC8: sub.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f10.d - ctx->f2.d;
    // 0x80138ECC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80138ED0: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x80138ED4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80138ED8: div.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x80138EDC: add.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f18.d + ctx->f8.d;
    // 0x80138EE0: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80138EE4: sub.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d - ctx->f2.d;
    // 0x80138EE8: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80138EEC: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80138EF0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80138EF4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80138EF8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80138EFC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80138F00: div.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f10.d);
    // 0x80138F04: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x80138F08: jal         0x80129FB8
    // 0x80138F0C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x80129FB8)(rdram, ctx);
        goto after_14;
    // 0x80138F0C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_14:
    // 0x80138F10: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
L_80138F14:
    // 0x80138F14: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    // 0x80138F18: jal         0x80133A24
    // 0x80138F1C: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_15;
    // 0x80138F1C: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_15:
    // 0x80138F20: bne         $v0, $zero, L_80138F34
    if (ctx->r2 != 0) {
        // 0x80138F24: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80138F34;
    }
    // 0x80138F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80138F28: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80138F2C: jal         0x800058DC
    // 0x80138F30: addiu       $a1, $a1, -0x70B8
    ctx->r5 = ADD32(ctx->r5, -0X70B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_16;
    // 0x80138F30: addiu       $a1, $a1, -0x70B8
    ctx->r5 = ADD32(ctx->r5, -0X70B8);
    after_16:
L_80138F34:
    // 0x80138F34: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80138F38:
    // 0x80138F38: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80138F3C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80138F40: jr          $ra
    // 0x80138F44: nop

    return;
    // 0x80138F44: nop

;}
RECOMP_FUNC void M7_FUN_80138f48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138F48: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80138F4C: jr          $ra
    // 0x80138F50: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80138F50: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80138f54(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80138f54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138F54: nop

    // 0x80138F58: nop

    // 0x80138F5C: nop

;}
RECOMP_FUNC void M7_FUN_80138f60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138F60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80138F64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80138F68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80138F6C: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x80138F70: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80138F74: srl         $t9, $t7, 16
    ctx->r25 = S32(U32(ctx->r15) >> 16);
    // 0x80138F78: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80138F7C: beql        $t0, $zero, L_80138FC0
    if (ctx->r8 == 0) {
        // 0x80138F80: lw          $t1, 0x38($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X38);
            goto L_80138FC0;
    }
    goto skip_0;
    // 0x80138F80: lw          $t1, 0x38($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X38);
    skip_0:
    // 0x80138F84: jal         0x8012FF4C
    // 0x80138F88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_0;
    // 0x80138F88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80138F8C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80138F90: beq         $v0, $at, L_80138FAC
    if (ctx->r2 == ctx->r1) {
        // 0x80138F94: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80138FAC;
    }
    // 0x80138F94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80138F98: jal         0x8012FF4C
    // 0x80138F9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_1;
    // 0x80138F9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80138FA0: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80138FA4: bne         $v0, $at, L_80138FBC
    if (ctx->r2 != ctx->r1) {
        // 0x80138FA8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80138FBC;
    }
    // 0x80138FA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80138FAC:
    // 0x80138FAC: jal         0x80005700
    // 0x80138FB0: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x80138FB0: nop

    after_2:
    // 0x80138FB4: b           L_80139028
    // 0x80138FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80139028;
    // 0x80138FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138FBC:
    // 0x80138FBC: lw          $t1, 0x38($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X38);
L_80138FC0:
    // 0x80138FC0: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80138FC4: lw          $v0, 0x10($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X10);
    // 0x80138FC8: srl         $t3, $v0, 16
    ctx->r11 = S32(U32(ctx->r2) >> 16);
    // 0x80138FCC: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x80138FD0: beq         $t4, $zero, L_80138FF8
    if (ctx->r12 == 0) {
        // 0x80138FD4: srl         $t7, $v0, 24
        ctx->r15 = S32(U32(ctx->r2) >> 24);
            goto L_80138FF8;
    }
    // 0x80138FD4: srl         $t7, $v0, 24
    ctx->r15 = S32(U32(ctx->r2) >> 24);
    // 0x80138FD8: lbu         $t5, -0x406A($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X406A);
    // 0x80138FDC: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x80138FE0: beql        $t5, $t6, L_80138FFC
    if (ctx->r13 == ctx->r14) {
        // 0x80138FE4: sltiu       $at, $t7, 0x4
        ctx->r1 = ctx->r15 < 0X4 ? 1 : 0;
            goto L_80138FFC;
    }
    goto skip_1;
    // 0x80138FE4: sltiu       $at, $t7, 0x4
    ctx->r1 = ctx->r15 < 0X4 ? 1 : 0;
    skip_1:
    // 0x80138FE8: jal         0x80005700
    // 0x80138FEC: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x80138FEC: nop

    after_3:
    // 0x80138FF0: b           L_80139028
    // 0x80138FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80139028;
    // 0x80138FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138FF8:
    // 0x80138FF8: sltiu       $at, $t7, 0x4
    ctx->r1 = ctx->r15 < 0X4 ? 1 : 0;
L_80138FFC:
    // 0x80138FFC: bne         $at, $zero, L_80139014
    if (ctx->r1 != 0) {
        // 0x80139000: lui         $a1, 0x8014
        ctx->r5 = S32(0X8014 << 16);
            goto L_80139014;
    }
    // 0x80139000: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80139004: jal         0x80005700
    // 0x80139008: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x80139008: nop

    after_4:
    // 0x8013900C: b           L_80139028
    // 0x80139010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80139028;
    // 0x80139010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80139014:
    // 0x80139014: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80139018: sh          $zero, -0x41E6($at)
    MEM_H(-0X41E6, ctx->r1) = 0;
    // 0x8013901C: jal         0x800058DC
    // 0x80139020: addiu       $a1, $a1, -0x6FCC
    ctx->r5 = ADD32(ctx->r5, -0X6FCC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80139020: addiu       $a1, $a1, -0x6FCC
    ctx->r5 = ADD32(ctx->r5, -0X6FCC);
    after_5:
    // 0x80139024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80139028:
    // 0x80139028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013902C: jr          $ra
    // 0x80139030: nop

    return;
    // 0x80139030: nop

;}
RECOMP_FUNC void M7_FUN_80139034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139034: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80139038: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8013903C: lhu         $t6, 0x22A($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X22A);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80139040(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80139040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80139044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80139048: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8013904C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80139050: blez        $t8, L_80139090
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80139054: sh          $t7, 0x22A($v0)
        MEM_H(0X22A, ctx->r2) = ctx->r15;
            goto L_80139090;
    }
    // 0x80139054: sh          $t7, 0x22A($v0)
    MEM_H(0X22A, ctx->r2) = ctx->r15;
    // 0x80139058: lw          $t9, 0x38($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X38);
    // 0x8013905C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80139060: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x80139064: srl         $t1, $t0, 24
    ctx->r9 = S32(U32(ctx->r8) >> 24);
    // 0x80139068: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8013906C: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80139070: lw          $v0, -0x5320($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5320);
    // 0x80139074: beq         $v0, $zero, L_80139088
    if (ctx->r2 == 0) {
        // 0x80139078: nop
    
            goto L_80139088;
    }
    // 0x80139078: nop

    // 0x8013907C: jalr        $v0
    // 0x80139080: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80139080: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80139084: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80139088:
    // 0x80139088: jal         0x80005700
    // 0x8013908C: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x8013908C: nop

    after_1:
L_80139090:
    // 0x80139090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80139094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80139098: jr          $ra
    // 0x8013909C: nop

    return;
    // 0x8013909C: nop

;}
RECOMP_FUNC void M7_FUN_801390a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801390A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801390A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801390A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801390AC: jal         0x8012FF4C
    // 0x801390B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8012FF4C)(rdram, ctx);
        goto after_0;
    // 0x801390B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801390B4: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x801390B8: bne         $v0, $at, L_801390D8
    if (ctx->r2 != ctx->r1) {
        // 0x801390BC: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_801390D8;
    }
    // 0x801390BC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801390C0: lw          $t6, 0x38($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X38);
    // 0x801390C4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801390C8: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801390CC: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x801390D0: beql        $t8, $at, L_80139100
    if (ctx->r24 == ctx->r1) {
        // 0x801390D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80139100;
    }
    goto skip_0;
    // 0x801390D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_801390D8:
    // 0x801390D8: lw          $v0, 0x38($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X38);
    // 0x801390DC: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x801390E0: lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X18);
    // 0x801390E4: srl         $a0, $v1, 16
    ctx->r4 = S32(U32(ctx->r3) >> 16);
    // 0x801390E8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x801390EC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801390F0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801390F4: jal         0x801FC720
    // 0x801390F8: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    LOOKUP_FUNC(0x801FC720)(rdram, ctx);
        goto after_1;
    // 0x801390F8: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    after_1:
    // 0x801390FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80139100:
    // 0x80139100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80139104: jr          $ra
    // 0x80139108: nop

    return;
    // 0x80139108: nop

;}
RECOMP_FUNC void M7_FUN_8013910c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013910C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80139110: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80139114: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80139118: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x8013911C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80139120: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80139124: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x80139128: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013912C: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x80139130: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80139134: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x80139138: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x8013913C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80139140: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80139144: lh          $a3, 0xC($v0)
    ctx->r7 = MEM_H(ctx->r2, 0XC);
    // 0x80139148: srl         $t9, $v1, 16
    ctx->r25 = S32(U32(ctx->r3) >> 16);
    // 0x8013914C: andi        $t0, $v1, 0xFFFF
    ctx->r8 = ctx->r3 & 0XFFFF;
    // 0x80139150: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80139154: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80139158: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8013915C: lw          $t1, 0x18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X18);
    // 0x80139160: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80139164: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80139168: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x8013916C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80139170: srl         $t2, $t1, 16
    ctx->r10 = S32(U32(ctx->r9) >> 16);
    // 0x80139174: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80139178: div.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8013917C: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x80139180: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80139184: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80139188: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x8013918C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80139190: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80139194: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80139198: jal         0x8014ADB4
    // 0x8013919C: nop

    LOOKUP_FUNC(0x8014ADB4)(rdram, ctx);
        goto after_0;
    // 0x8013919C: nop

    after_0:
    // 0x801391A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801391A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801391A8: jr          $ra
    // 0x801391AC: nop

    return;
    // 0x801391AC: nop

;}
RECOMP_FUNC void M7_FUN_801391b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801391B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801391B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801391B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801391BC: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x801391C0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801391C4: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801391C8: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x801391CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801391D0: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x801391D4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801391D8: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x801391DC: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x801391E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801391E4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x801391E8: lh          $a3, 0xC($v0)
    ctx->r7 = MEM_H(ctx->r2, 0XC);
    // 0x801391EC: srl         $t9, $v1, 16
    ctx->r25 = S32(U32(ctx->r3) >> 16);
    // 0x801391F0: andi        $t0, $v1, 0xFFFF
    ctx->r8 = ctx->r3 & 0XFFFF;
    // 0x801391F4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801391F8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801391FC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80139200: lw          $t1, 0x18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X18);
    // 0x80139204: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80139208: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8013920C: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x80139210: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80139214: srl         $t2, $t1, 16
    ctx->r10 = S32(U32(ctx->r9) >> 16);
    // 0x80139218: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8013921C: div.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x80139220: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x80139224: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80139228: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8013922C: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x80139230: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80139234: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80139238: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8013923C: jal         0x8014AEF4
    // 0x80139240: nop

    LOOKUP_FUNC(0x8014AEF4)(rdram, ctx);
        goto after_0;
    // 0x80139240: nop

    after_0:
    // 0x80139244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80139248: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013924C: jr          $ra
    // 0x80139250: nop

    return;
    // 0x80139250: nop

;}
RECOMP_FUNC void M7_FUN_80139254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80139258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013925C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80139260: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80139264: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80139268: lbu         $t6, -0x406A($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X406A);
    // 0x8013926C: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x80139270: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80139274: bnel        $t6, $t8, L_801392A0
    if (ctx->r14 != ctx->r24) {
        // 0x80139278: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801392A0;
    }
    goto skip_0;
    // 0x80139278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013927C: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80139280: lw          $a2, 0x18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X18);
    // 0x80139284: srl         $a0, $v0, 16
    ctx->r4 = S32(U32(ctx->r2) >> 16);
    // 0x80139288: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8013928C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80139290: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80139294: jal         0x801FC720
    // 0x80139298: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    LOOKUP_FUNC(0x801FC720)(rdram, ctx);
        goto after_0;
    // 0x80139298: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    after_0:
    // 0x8013929C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801392A0:
    // 0x801392A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801392A4: jr          $ra
    // 0x801392A8: nop

    return;
    // 0x801392A8: nop

;}
RECOMP_FUNC void M7_FUN_801392ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801392AC: nop

;}
RECOMP_FUNC void M7_FUN_801392b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801392B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801392B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801392B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801392BC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801392C0: jal         0x800058DC
    // 0x801392C4: addiu       $a1, $a1, -0x6D28
    ctx->r5 = ADD32(ctx->r5, -0X6D28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801392C4: addiu       $a1, $a1, -0x6D28
    ctx->r5 = ADD32(ctx->r5, -0X6D28);
    after_0:
    // 0x801392C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801392CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801392D0: jr          $ra
    // 0x801392D4: nop

    return;
    // 0x801392D4: nop

;}
RECOMP_FUNC void M7_FUN_801392d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801392D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801392DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801392E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801392E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801392E8: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801392EC: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x801392F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801392F4: addiu       $a3, $a3, -0x21E0
    ctx->r7 = ADD32(ctx->r7, -0X21E0);
    // 0x801392F8: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x801392FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80139300: jal         0x8001B204
    // 0x80139304: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x80139304: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_0:
    // 0x80139308: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013930C: addiu       $a1, $a1, -0x6CD8
    ctx->r5 = ADD32(ctx->r5, -0X6CD8);
    // 0x80139310: jal         0x800058DC
    // 0x80139314: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80139314: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80139318: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013931C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80139320: jr          $ra
    // 0x80139324: nop

    return;
    // 0x80139324: nop

;}
RECOMP_FUNC void M7_FUN_80139328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139328: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8013932C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80139330: addiu       $t6, $zero, 0x73
    ctx->r14 = ADD32(0, 0X73);
    // 0x80139334: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x80139338: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8013933C: lhu         $t7, -0x6B88($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X6B88);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80139340(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80139340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139340: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80139344: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80139348: andi        $t8, $t7, 0xF000
    ctx->r24 = ctx->r15 & 0XF000;
    // 0x8013934C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80139350: beq         $t8, $zero, L_80139378
    if (ctx->r24 == 0) {
        // 0x80139354: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80139378;
    }
    // 0x80139354: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80139358: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8013935C: andi        $a1, $t6, 0xFFFF
    ctx->r5 = ctx->r14 & 0XFFFF;
    // 0x80139360: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80139364: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80139368: jal         0x8012FE50
    // 0x8013936C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_0;
    // 0x8013936C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80139370: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80139374: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
L_80139378:
    // 0x80139378: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8013937C: addiu       $t0, $zero, 0x72
    ctx->r8 = ADD32(0, 0X72);
    // 0x80139380: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    // 0x80139384: lhu         $v0, 0x3C($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X3C);
    // 0x80139388: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8013938C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80139390: slti        $at, $v0, 0x7D1
    ctx->r1 = SIGNED(ctx->r2) < 0X7D1 ? 1 : 0;
    // 0x80139394: bne         $at, $zero, L_801393B0
    if (ctx->r1 != 0) {
        // 0x80139398: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_801393B0;
    }
    // 0x80139398: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8013939C: sh          $t0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r8;
    // 0x801393A0: jal         0x8012FE50
    // 0x801393A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012FE50)(rdram, ctx);
        goto after_1;
    // 0x801393A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x801393A8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x801393AC: lhu         $v0, 0x3C($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X3C);
L_801393B0:
    // 0x801393B0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x801393B4: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x801393B8: sh          $t2, 0x3C($t3)
    MEM_H(0X3C, ctx->r11) = ctx->r10;
    // 0x801393BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801393C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801393C4: jr          $ra
    // 0x801393C8: nop

    return;
    // 0x801393C8: nop

;}
RECOMP_FUNC void M7_FUN_801393cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801393CC: nop

;}
RECOMP_FUNC void M7_FUN_801393d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801393D0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801393D4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x801393D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801393DC: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x801393E0: blez        $a2, L_801394C4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x801393E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801394C4;
    }
    // 0x801393E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801393E8: andi        $t2, $v1, 0x3
    ctx->r10 = ctx->r3 & 0X3;
    // 0x801393EC: beq         $t2, $zero, L_80139440
    if (ctx->r10 == 0) {
        // 0x801393F0: or          $t1, $t2, $zero
        ctx->r9 = ctx->r10 | 0;
            goto L_80139440;
    }
    // 0x801393F0: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
    // 0x801393F4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x801393F8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801393FC: addiu       $t8, $t8, -0x4384
    ctx->r24 = ADD32(ctx->r24, -0X4384);
    // 0x80139400: sll         $t6, $zero, 3
    ctx->r14 = S32(0 << 3);
    // 0x80139404: sll         $t7, $zero, 1
    ctx->r15 = S32(0 << 1);
    // 0x80139408: sll         $t9, $zero, 4
    ctx->r25 = S32(0 << 4);
    // 0x8013940C: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x80139410: addu        $a1, $a0, $t6
    ctx->r5 = ADD32(ctx->r4, ctx->r14);
    // 0x80139414: addu        $t0, $t9, $t5
    ctx->r8 = ADD32(ctx->r25, ctx->r13);
L_80139418:
    // 0x80139418: lhu         $t6, 0x0($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X0);
    // 0x8013941C: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x80139420: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80139424: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80139428: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8013942C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80139430: bne         $t1, $v0, L_80139418
    if (ctx->r9 != ctx->r2) {
        // 0x80139434: sh          $t6, -0x8($a1)
        MEM_H(-0X8, ctx->r5) = ctx->r14;
            goto L_80139418;
    }
    // 0x80139434: sh          $t6, -0x8($a1)
    MEM_H(-0X8, ctx->r5) = ctx->r14;
    // 0x80139438: beq         $v0, $v1, L_801394C4
    if (ctx->r2 == ctx->r3) {
        // 0x8013943C: nop
    
            goto L_801394C4;
    }
    // 0x8013943C: nop

L_80139440:
    // 0x80139440: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80139444: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x80139448: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x8013944C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80139450: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x80139454: addiu       $t9, $t9, -0x4384
    ctx->r25 = ADD32(ctx->r25, -0X4384);
    // 0x80139458: addu        $a1, $a0, $t7
    ctx->r5 = ADD32(ctx->r4, ctx->r15);
    // 0x8013945C: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80139460: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80139464: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x80139468: addu        $t4, $t7, $t9
    ctx->r12 = ADD32(ctx->r15, ctx->r25);
    // 0x8013946C: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x80139470: addiu       $t2, $t0, 0x20
    ctx->r10 = ADD32(ctx->r8, 0X20);
    // 0x80139474: addiu       $t3, $t0, 0x30
    ctx->r11 = ADD32(ctx->r8, 0X30);
L_80139478:
    // 0x80139478: lhu         $t8, 0x0($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X0);
    // 0x8013947C: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x80139480: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80139484: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80139488: lhu         $t5, -0x6($a3)
    ctx->r13 = MEM_HU(ctx->r7, -0X6);
    // 0x8013948C: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    // 0x80139490: addiu       $t1, $t1, 0x40
    ctx->r9 = ADD32(ctx->r9, 0X40);
    // 0x80139494: sh          $t5, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r13;
    // 0x80139498: lhu         $t6, -0x4($a3)
    ctx->r14 = MEM_HU(ctx->r7, -0X4);
    // 0x8013949C: sw          $t2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r10;
    // 0x801394A0: addiu       $t2, $t2, 0x40
    ctx->r10 = ADD32(ctx->r10, 0X40);
    // 0x801394A4: sh          $t6, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r14;
    // 0x801394A8: lhu         $t7, -0x2($a3)
    ctx->r15 = MEM_HU(ctx->r7, -0X2);
    // 0x801394AC: sw          $t3, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r11;
    // 0x801394B0: addiu       $t3, $t3, 0x40
    ctx->r11 = ADD32(ctx->r11, 0X40);
    // 0x801394B4: addiu       $t0, $t0, 0x40
    ctx->r8 = ADD32(ctx->r8, 0X40);
    // 0x801394B8: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x801394BC: bne         $a3, $t4, L_80139478
    if (ctx->r7 != ctx->r12) {
        // 0x801394C0: sh          $t7, -0x8($a1)
        MEM_H(-0X8, ctx->r5) = ctx->r15;
            goto L_80139478;
    }
    // 0x801394C0: sh          $t7, -0x8($a1)
    MEM_H(-0X8, ctx->r5) = ctx->r15;
L_801394C4:
    // 0x801394C4: jr          $ra
    // 0x801394C8: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
    return;
    // 0x801394C8: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801394cc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801394cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801394CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801394D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801394D4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801394D8: addiu       $a0, $a0, -0x26A0
    ctx->r4 = ADD32(ctx->r4, -0X26A0);
    // 0x801394DC: jal         0x800279F0
    // 0x801394E0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    LOOKUP_FUNC(0x800279F0)(rdram, ctx);
        goto after_0;
    // 0x801394E0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x801394E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801394E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801394EC: jr          $ra
    // 0x801394F0: nop

    return;
    // 0x801394F0: nop

;}
RECOMP_FUNC void M7_FUN_801394f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801394F4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801394F8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801394FC: addiu       $a0, $a0, -0x2680
    ctx->r4 = ADD32(ctx->r4, -0X2680);
    // 0x80139500: addiu       $v1, $v1, -0x26A0
    ctx->r3 = ADD32(ctx->r3, -0X26A0);
    // 0x80139504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80139508:
    // 0x80139508: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8013950C: sb          $v0, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r2;
    // 0x80139510: sb          $v0, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r2;
    // 0x80139514: sb          $v0, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r2;
    // 0x80139518: bne         $v1, $a0, L_80139508
    if (ctx->r3 != ctx->r4) {
        // 0x8013951C: sb          $v0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r2;
            goto L_80139508;
    }
    // 0x8013951C: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
    // 0x80139520: jr          $ra
    // 0x80139524: nop

    return;
    // 0x80139524: nop

;}
RECOMP_FUNC void M7_FUN_80139528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139528: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8013952C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80139530: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80139534: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80139538: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013953C: jr          $ra
    // 0x80139540: sb          $t6, -0x26A0($at)
    MEM_B(-0X26A0, ctx->r1) = ctx->r14;
    return;
    // 0x80139540: sb          $t6, -0x26A0($at)
    MEM_B(-0X26A0, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80139544(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80139544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139544: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80139548: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8013954C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80139550: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80139554: jr          $ra
    // 0x80139558: sb          $zero, -0x26A0($at)
    MEM_B(-0X26A0, ctx->r1) = 0;
    return;
    // 0x80139558: sb          $zero, -0x26A0($at)
    MEM_B(-0X26A0, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013955c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013955c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013955C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80139560: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80139564: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80139568: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013956C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80139570: addiu       $v0, $v0, -0x31A0
    ctx->r2 = ADD32(ctx->r2, -0X31A0);
    // 0x80139574: beq         $a2, $zero, L_80139580
    if (ctx->r6 == 0) {
        // 0x80139578: swc1        $f0, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
            goto L_80139580;
    }
    // 0x80139578: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x8013957C: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
L_80139580:
    // 0x80139580: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80139584: blez        $a0, L_801395DC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80139588: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_801395DC;
    }
    // 0x80139588: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8013958C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80139590:
    // 0x80139590: slti        $at, $a0, 0x13
    ctx->r1 = SIGNED(ctx->r4) < 0X13 ? 1 : 0;
    // 0x80139594: bne         $at, $zero, L_801395A4
    if (ctx->r1 != 0) {
        // 0x80139598: nop
    
            goto L_801395A4;
    }
    // 0x80139598: nop

    // 0x8013959C: bne         $a2, $zero, L_801395AC
    if (ctx->r6 != 0) {
        // 0x801395A0: or          $t0, $a2, $zero
        ctx->r8 = ctx->r6 | 0;
            goto L_801395AC;
    }
    // 0x801395A0: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
L_801395A4:
    // 0x801395A4: b           L_801395AC
    // 0x801395A8: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
        goto L_801395AC;
    // 0x801395A8: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_801395AC:
    // 0x801395AC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x801395B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801395B4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x801395B8: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x801395BC: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x801395C0: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x801395C4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x801395C8: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    // 0x801395CC: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x801395D0: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x801395D4: bne         $at, $zero, L_80139590
    if (ctx->r1 != 0) {
        // 0x801395D8: sw          $t7, -0x14($v0)
        MEM_W(-0X14, ctx->r2) = ctx->r15;
            goto L_80139590;
    }
    // 0x801395D8: sw          $t7, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->r15;
L_801395DC:
    // 0x801395DC: jr          $ra
    // 0x801395E0: nop

    return;
    // 0x801395E0: nop

;}
RECOMP_FUNC void M7_FUN_801395e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801395E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801395E8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801395EC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x801395F0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x801395F4: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801395F8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801395FC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80139600: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80139604: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80139608: lwc1        $f10, 0x3C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x8013960C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80139610: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80139614: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80139618: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8013961C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80139620: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80139624: div.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f24.fl);
    // 0x80139628: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    // 0x8013962C: lwc1        $f2, 0x84($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X84);
    // 0x80139630: lwc1        $f14, 0x88($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X88);
    // 0x80139634: lwc1        $f0, 0x8C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8C);
    // 0x80139638: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8013963C: nop

    // 0x80139640: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80139644: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80139648: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8013964C: jal         0x8002FC20
    // 0x80139650: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80139650: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_0:
    // 0x80139654: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80139658: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8013965C: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80139660: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80139664: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80139668: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8013966C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80139670: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80139674: jal         0x8002FC20
    // 0x80139678: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x80139678: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    after_1:
    // 0x8013967C: lwc1        $f14, 0x150($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X150);
    // 0x80139680: lwc1        $f16, 0x154($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X154);
    // 0x80139684: lwc1        $f2, 0x158($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X158);
    // 0x80139688: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8013968C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80139690: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80139694: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80139698: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8013969C: jal         0x8002FC20
    // 0x801396A0: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x801396A0: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_2:
    // 0x801396A4: add.s       $f10, $f20, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x801396A8: add.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x801396AC: div.s       $f4, $f8, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f24.fl);
    // 0x801396B0: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
    // 0x801396B4: lwc1        $f14, 0x60($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X60);
    // 0x801396B8: lwc1        $f16, 0x64($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X64);
    // 0x801396BC: lwc1        $f2, 0x68($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X68);
    // 0x801396C0: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801396C4: nop

    // 0x801396C8: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801396CC: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x801396D0: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801396D4: jal         0x8002FC20
    // 0x801396D8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_3;
    // 0x801396D8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_3:
    // 0x801396DC: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    // 0x801396E0: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x801396E4: lwc1        $f2, 0x5C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x801396E8: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801396EC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801396F0: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801396F4: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x801396F8: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801396FC: jal         0x8002FC20
    // 0x80139700: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_4;
    // 0x80139700: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_4:
    // 0x80139704: lwc1        $f14, 0x144($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X144);
    // 0x80139708: lwc1        $f16, 0x148($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X148);
    // 0x8013970C: lwc1        $f2, 0x14C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x80139710: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80139714: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80139718: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8013971C: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80139720: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80139724: jal         0x8002FC20
    // 0x80139728: add.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_5;
    // 0x80139728: add.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f18.fl;
    after_5:
    // 0x8013972C: add.s       $f6, $f20, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80139730: add.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80139734: div.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80139738: swc1        $f4, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f4.u32l;
    // 0x8013973C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80139740: div.s       $f18, $f8, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f24.fl);
    // 0x80139744: lwc1        $f8, 0x54($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X54);
    // 0x80139748: swc1        $f18, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f18.u32l;
    // 0x8013974C: lwc1        $f6, 0x178($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X178);
    // 0x80139750: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x80139754: lwc1        $f6, 0x60($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X60);
    // 0x80139758: div.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8013975C: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80139760: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80139764: swc1        $f10, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f10.u32l;
    // 0x80139768: lwc1        $f14, 0x108($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X108);
    // 0x8013976C: lwc1        $f16, 0x10C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80139770: lwc1        $f2, 0x110($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80139774: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80139778: nop

    // 0x8013977C: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80139780: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80139784: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80139788: jal         0x8002FC20
    // 0x8013978C: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_6;
    // 0x8013978C: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_6:
    // 0x80139790: lwc1        $f14, 0xFC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x80139794: lwc1        $f16, 0x100($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X100);
    // 0x80139798: lwc1        $f2, 0x104($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X104);
    // 0x8013979C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801397A0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801397A4: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801397A8: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801397AC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801397B0: jal         0x8002FC20
    // 0x801397B4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_7;
    // 0x801397B4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_7:
    // 0x801397B8: lwc1        $f14, 0x114($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X114);
    // 0x801397BC: lwc1        $f16, 0x118($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X118);
    // 0x801397C0: lwc1        $f2, 0x11C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x801397C4: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801397C8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801397CC: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801397D0: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x801397D4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801397D8: jal         0x8002FC20
    // 0x801397DC: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_8;
    // 0x801397DC: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_8:
    // 0x801397E0: add.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x801397E4: add.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x801397E8: div.s       $f10, $f18, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f24.fl);
    // 0x801397EC: swc1        $f10, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f10.u32l;
    // 0x801397F0: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x801397F4: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x801397F8: lwc1        $f2, 0x74($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801397FC: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80139800: nop

    // 0x80139804: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80139808: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8013980C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80139810: jal         0x8002FC20
    // 0x80139814: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_9;
    // 0x80139814: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_9:
    // 0x80139818: div.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8013981C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80139820: swc1        $f10, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f10.u32l;
    // 0x80139824: lwc1        $f2, 0x130($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X130);
    // 0x80139828: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8013982C: nop

    // 0x80139830: bc1fl       L_80139844
    if (!c1cs) {
        // 0x80139834: mov.s       $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
            goto L_80139844;
    }
    goto skip_0;
    // 0x80139834: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    skip_0:
    // 0x80139838: b           L_80139844
    // 0x8013983C: neg.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = -ctx->f2.fl;
        goto L_80139844;
    // 0x8013983C: neg.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = -ctx->f2.fl;
    // 0x80139840: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
L_80139844:
    // 0x80139844: div.s       $f6, $f20, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = DIV_S(ctx->f20.fl, ctx->f24.fl);
    // 0x80139848: swc1        $f6, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f6.u32l;
    // 0x8013984C: lwc1        $f0, 0x13C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X13C);
    // 0x80139850: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80139854: nop

    // 0x80139858: bc1fl       L_8013986C
    if (!c1cs) {
        // 0x8013985C: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_8013986C;
    }
    goto skip_1;
    // 0x8013985C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_1:
    // 0x80139860: b           L_8013986C
    // 0x80139864: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
        goto L_8013986C;
    // 0x80139864: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
    // 0x80139868: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_8013986C:
    // 0x8013986C: div.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = DIV_S(ctx->f20.fl, ctx->f24.fl);
    // 0x80139870: swc1        $f4, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f4.u32l;
    // 0x80139874: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80139878: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8013987C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80139880: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80139884: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80139888: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8013988C: jr          $ra
    // 0x80139890: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80139890: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80139894(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80139894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139894: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80139898: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8013989C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801398A0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801398A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801398A8: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x801398AC: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x801398B0: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x801398B4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801398B8: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801398BC: sh          $t6, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r14;
    // 0x801398C0: lhu         $t0, 0xE($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0XE);
    // 0x801398C4: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x801398C8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801398CC: andi        $t0, $t0, 0xFFF
    ctx->r8 = ctx->r8 & 0XFFF;
    // 0x801398D0: andi        $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 & 0XFFFF;
    // 0x801398D4: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x801398D8: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x801398DC: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x801398E0: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    // 0x801398E4: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    // 0x801398E8: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801398EC: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801398F0: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x801398F4: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x801398F8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801398FC: addiu       $t2, $t2, -0x29A0
    ctx->r10 = ADD32(ctx->r10, -0X29A0);
    // 0x80139900: addiu       $a0, $a1, 0x28
    ctx->r4 = ADD32(ctx->r5, 0X28);
    // 0x80139904: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x80139908: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8013990C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80139910: addiu       $s0, $s0, -0x31A0
    ctx->r16 = ADD32(ctx->r16, -0X31A0);
    // 0x80139914: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x80139918: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8013991C: sh          $t7, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r15;
    // 0x80139920: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x80139924: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80139928: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
    // 0x8013992C: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    // 0x80139930: jal         0x800279F0
    // 0x80139934: sh          $t8, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x800279F0)(rdram, ctx);
        goto after_0;
    // 0x80139934: sh          $t8, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r24;
    after_0:
    // 0x80139938: lw          $v1, 0xA0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA0);
    // 0x8013993C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80139940: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80139944: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80139948: addiu       $t1, $t1, -0x4410
    ctx->r9 = ADD32(ctx->r9, -0X4410);
    // 0x8013994C: sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
    // 0x80139950: lhu         $t9, 0x2C($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X2C);
    // 0x80139954: addiu       $t4, $t9, -0x2
    ctx->r12 = ADD32(ctx->r25, -0X2);
    // 0x80139958: sltiu       $at, $t4, 0xE
    ctx->r1 = ctx->r12 < 0XE ? 1 : 0;
    // 0x8013995C: beq         $at, $zero, L_80139990
    if (ctx->r1 == 0) {
        // 0x80139960: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80139990;
    }
    // 0x80139960: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80139964: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80139968: addu        $at, $at, $t4
    gpr jr_addend_80139970 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8013996C: lw          $t4, -0x207C($at)
    ctx->r12 = ADD32(ctx->r1, -0X207C);
    // 0x80139970: jr          $t4
    // 0x80139974: nop

    switch (jr_addend_80139970 >> 2) {
        case 0: goto L_80139978; break;
        case 1: goto L_80139990; break;
        case 2: goto L_80139990; break;
        case 3: goto L_80139984; break;
        case 4: goto L_80139990; break;
        case 5: goto L_80139990; break;
        case 6: goto L_80139990; break;
        case 7: goto L_80139990; break;
        case 8: goto L_80139984; break;
        case 9: goto L_80139984; break;
        case 10: goto L_80139990; break;
        case 11: goto L_80139990; break;
        case 12: goto L_80139990; break;
        case 13: goto L_80139984; break;
        default: switch_error(__func__, 0x80139970, 0x8018DF84);
    }
    // 0x80139974: nop

L_80139978:
    // 0x80139978: addiu       $t5, $zero, 0x3000
    ctx->r13 = ADD32(0, 0X3000);
    // 0x8013997C: b           L_801399CC
    // 0x80139980: sh          $t5, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r13;
        goto L_801399CC;
    // 0x80139980: sh          $t5, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r13;
L_80139984:
    // 0x80139984: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x80139988: b           L_801399CC
    // 0x8013998C: sh          $t6, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r14;
        goto L_801399CC;
    // 0x8013998C: sh          $t6, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r14;
L_80139990:
    // 0x80139990: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
    // 0x80139994: jal         0x80126944
    // 0x80139998: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_1;
    // 0x80139998: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    after_1:
    // 0x8013999C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801399A0: addiu       $t1, $t1, -0x4410
    ctx->r9 = ADD32(ctx->r9, -0X4410);
    // 0x801399A4: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x801399A8: beq         $v0, $zero, L_801399C4
    if (ctx->r2 == 0) {
        // 0x801399AC: lw          $t3, 0x40($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X40);
            goto L_801399C4;
    }
    // 0x801399AC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x801399B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801399B4: bne         $v0, $at, L_801399C4
    if (ctx->r2 != ctx->r1) {
        // 0x801399B8: addiu       $t7, $zero, 0x1000
        ctx->r15 = ADD32(0, 0X1000);
            goto L_801399C4;
    }
    // 0x801399B8: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x801399BC: b           L_801399C8
    // 0x801399C0: sh          $t7, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r15;
        goto L_801399C8;
    // 0x801399C0: sh          $t7, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r15;
L_801399C4:
    // 0x801399C4: sh          $zero, 0x18($s2)
    MEM_H(0X18, ctx->r18) = 0;
L_801399C8:
    // 0x801399C8: lw          $v1, 0xA0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA0);
L_801399CC:
    // 0x801399CC: lbu         $v0, 0x74($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X74);
    // 0x801399D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801399D4: addiu       $a1, $s2, 0x1C
    ctx->r5 = ADD32(ctx->r18, 0X1C);
    // 0x801399D8: beq         $v0, $zero, L_801399E8
    if (ctx->r2 == 0) {
        // 0x801399DC: or          $a2, $s1, $zero
        ctx->r6 = ctx->r17 | 0;
            goto L_801399E8;
    }
    // 0x801399DC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801399E0: bnel        $v0, $at, L_80139A00
    if (ctx->r2 != ctx->r1) {
        // 0x801399E4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80139A00;
    }
    goto skip_0;
    // 0x801399E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
L_801399E8:
    // 0x801399E8: sw          $v1, 0xDC($t1)
    MEM_W(0XDC, ctx->r9) = ctx->r3;
    // 0x801399EC: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x801399F0: sw          $s2, 0x444($t1)
    MEM_W(0X444, ctx->r9) = ctx->r18;
    // 0x801399F4: b           L_80139A20
    // 0x801399F8: sw          $t9, 0xE0($t1)
    MEM_W(0XE0, ctx->r9) = ctx->r25;
        goto L_80139A20;
    // 0x801399F8: sw          $t9, 0xE0($t1)
    MEM_W(0XE0, ctx->r9) = ctx->r25;
    // 0x801399FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80139A00:
    // 0x80139A00: beq         $v0, $at, L_80139A10
    if (ctx->r2 == ctx->r1) {
        // 0x80139A04: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80139A10;
    }
    // 0x80139A04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80139A08: bnel        $v0, $at, L_80139A24
    if (ctx->r2 != ctx->r1) {
        // 0x80139A0C: addiu       $at, $zero, 0x29
        ctx->r1 = ADD32(0, 0X29);
            goto L_80139A24;
    }
    goto skip_1;
    // 0x80139A0C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    skip_1:
L_80139A10:
    // 0x80139A10: sw          $v1, 0xEC($t1)
    MEM_W(0XEC, ctx->r9) = ctx->r3;
    // 0x80139A14: lw          $t5, 0x24($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X24);
    // 0x80139A18: sw          $s2, 0x448($t1)
    MEM_W(0X448, ctx->r9) = ctx->r18;
    // 0x80139A1C: sw          $t5, 0xF0($t1)
    MEM_W(0XF0, ctx->r9) = ctx->r13;
L_80139A20:
    // 0x80139A20: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
L_80139A24:
    // 0x80139A24: beq         $t3, $at, L_80139A48
    if (ctx->r11 == ctx->r1) {
        // 0x80139A28: lui         $t6, 0x8017
        ctx->r14 = S32(0X8017 << 16);
            goto L_80139A48;
    }
    // 0x80139A28: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80139A2C: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80139A30: beq         $t3, $at, L_80139A48
    if (ctx->r11 == ctx->r1) {
        // 0x80139A34: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_80139A48;
    }
    // 0x80139A34: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x80139A38: beq         $t3, $at, L_80139A48
    if (ctx->r11 == ctx->r1) {
        // 0x80139A3C: addiu       $at, $zero, 0x2C
        ctx->r1 = ADD32(0, 0X2C);
            goto L_80139A48;
    }
    // 0x80139A3C: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x80139A40: bnel        $t3, $at, L_80139A58
    if (ctx->r11 != ctx->r1) {
        // 0x80139A44: lhu         $a0, 0x9A($sp)
        ctx->r4 = MEM_HU(ctx->r29, 0X9A);
            goto L_80139A58;
    }
    goto skip_2;
    // 0x80139A44: lhu         $a0, 0x9A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X9A);
    skip_2:
L_80139A48:
    // 0x80139A48: lw          $t6, 0x1D8C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1D8C);
    // 0x80139A4C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80139A50: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x80139A54: lhu         $a0, 0x9A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X9A);
L_80139A58:
    // 0x80139A58: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
    // 0x80139A5C: jal         0x8013955C
    // 0x80139A60: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x8013955C)(rdram, ctx);
        goto after_2;
    // 0x80139A60: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    after_2:
    // 0x80139A64: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80139A68: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80139A6C: addiu       $a1, $a1, -0x29A0
    ctx->r5 = ADD32(ctx->r5, -0X29A0);
    // 0x80139A70: addiu       $a0, $a0, -0x27A0
    ctx->r4 = ADD32(ctx->r4, -0X27A0);
    // 0x80139A74: jal         0x801393D0
    // 0x80139A78: lhu         $a2, 0x9A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X9A);
    LOOKUP_FUNC(0x801393D0)(rdram, ctx);
        goto after_3;
    // 0x80139A78: lhu         $a2, 0x9A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X9A);
    after_3:
    // 0x80139A7C: lhu         $t8, 0x9A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X9A);
    // 0x80139A80: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80139A84: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80139A88: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80139A8C: blez        $t8, L_80139D10
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80139A90: sw          $t8, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r24;
            goto L_80139D10;
    }
    // 0x80139A90: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80139A94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80139A98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80139A9C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_80139AA0:
    // 0x80139AA0: beq         $s1, $zero, L_80139C8C
    if (ctx->r17 == 0) {
        // 0x80139AA4: lw          $t6, 0xA0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA0);
            goto L_80139C8C;
    }
    // 0x80139AA4: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x80139AA8: addiu       $t4, $s1, -0x1
    ctx->r12 = ADD32(ctx->r17, -0X1);
    // 0x80139AAC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80139AB0: sb          $t4, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r12;
    // 0x80139AB4: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x80139AB8: lbu         $t5, -0x43A8($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X43A8);
    // 0x80139ABC: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80139AC0: addiu       $t9, $sp, 0x68
    ctx->r25 = ADD32(ctx->r29, 0X68);
    // 0x80139AC4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80139AC8: sb          $t6, 0x3D($s0)
    MEM_B(0X3D, ctx->r16) = ctx->r14;
    // 0x80139ACC: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80139AD0: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    // 0x80139AD4: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80139AD8: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x80139ADC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80139AE0: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80139AE4: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x80139AE8: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80139AEC: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x80139AF0: lbu         $a3, 0x3C($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X3C);
    // 0x80139AF4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80139AF8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80139AFC: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80139B00: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80139B04: addiu       $t9, $t8, -0xC
    ctx->r25 = ADD32(ctx->r24, -0XC);
    // 0x80139B08: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x80139B0C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x80139B10: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80139B14: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80139B18: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
    // 0x80139B1C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80139B20: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80139B24: jal         0x8000E980
    // 0x80139B28: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    LOOKUP_FUNC(0x8000E980)(rdram, ctx);
        goto after_4;
    // 0x80139B28: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_4:
    // 0x80139B2C: lh          $t4, 0x68($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X68);
    // 0x80139B30: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80139B34: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80139B38: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80139B3C: sh          $t4, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r12;
    // 0x80139B40: lh          $t5, 0x6A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6A);
    // 0x80139B44: addiu       $t7, $sp, 0x70
    ctx->r15 = ADD32(ctx->r29, 0X70);
    // 0x80139B48: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80139B4C: sh          $t5, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r13;
    // 0x80139B50: lh          $t6, 0x6C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6C);
    // 0x80139B54: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80139B58: addiu       $t5, $t5, -0x43B0
    ctx->r13 = ADD32(ctx->r13, -0X43B0);
    // 0x80139B5C: sh          $t6, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r14;
    // 0x80139B60: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80139B64: lui         $t6, 0x5
    ctx->r14 = S32(0X5 << 16);
    // 0x80139B68: ori         $t6, $t6, 0x8
    ctx->r14 = ctx->r14 | 0X8;
    // 0x80139B6C: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
    // 0x80139B70: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80139B74: sw          $t8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r24;
    // 0x80139B78: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80139B7C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80139B80: addiu       $t7, $t7, -0x26A0
    ctx->r15 = ADD32(ctx->r15, -0X26A0);
    // 0x80139B84: sw          $t9, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r25;
    // 0x80139B88: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80139B8C: bgez        $t4, L_80139BA8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80139B90: nop
    
            goto L_80139BA8;
    }
    // 0x80139B90: nop

    // 0x80139B94: sw          $t5, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r13;
    // 0x80139B98: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x80139B9C: sh          $zero, 0x20($s0)
    MEM_H(0X20, ctx->r16) = 0;
    // 0x80139BA0: b           L_80139C48
    // 0x80139BA4: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
        goto L_80139C48;
    // 0x80139BA4: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
L_80139BA8:
    // 0x80139BA8: bne         $s1, $at, L_80139BF8
    if (ctx->r17 != ctx->r1) {
        // 0x80139BAC: addu        $v0, $s1, $t7
        ctx->r2 = ADD32(ctx->r17, ctx->r15);
            goto L_80139BF8;
    }
    // 0x80139BAC: addu        $v0, $s1, $t7
    ctx->r2 = ADD32(ctx->r17, ctx->r15);
    // 0x80139BB0: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80139BB4: beq         $t3, $at, L_80139BD8
    if (ctx->r11 == ctx->r1) {
        // 0x80139BB8: lhu         $t8, 0x60($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X60);
            goto L_80139BD8;
    }
    // 0x80139BB8: lhu         $t8, 0x60($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X60);
    // 0x80139BBC: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80139BC0: beq         $t3, $at, L_80139BD8
    if (ctx->r11 == ctx->r1) {
        // 0x80139BC4: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_80139BD8;
    }
    // 0x80139BC4: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x80139BC8: beq         $t3, $at, L_80139BD8
    if (ctx->r11 == ctx->r1) {
        // 0x80139BCC: addiu       $at, $zero, 0x2C
        ctx->r1 = ADD32(0, 0X2C);
            goto L_80139BD8;
    }
    // 0x80139BCC: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x80139BD0: bnel        $t3, $at, L_80139BFC
    if (ctx->r11 != ctx->r1) {
        // 0x80139BD4: lhu         $t8, 0x62($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X62);
            goto L_80139BFC;
    }
    goto skip_3;
    // 0x80139BD4: lhu         $t8, 0x62($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X62);
    skip_3:
L_80139BD8:
    // 0x80139BD8: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
    // 0x80139BDC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80139BE0: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80139BE4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80139BE8: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80139BEC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80139BF0: b           L_80139C18
    // 0x80139BF4: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
        goto L_80139C18;
    // 0x80139BF4: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
L_80139BF8:
    // 0x80139BF8: lhu         $t8, 0x62($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X62);
L_80139BFC:
    // 0x80139BFC: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
    // 0x80139C00: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80139C04: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x80139C08: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80139C0C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80139C10: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80139C14: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
L_80139C18:
    // 0x80139C18: lhu         $t8, 0x60($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X60);
    // 0x80139C1C: lui         $t5, 0x4
    ctx->r13 = S32(0X4 << 16);
    // 0x80139C20: lui         $t4, 0x4
    ctx->r12 = S32(0X4 << 16);
    // 0x80139C24: sh          $t8, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r24;
    // 0x80139C28: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80139C2C: ori         $t4, $t4, 0x13
    ctx->r12 = ctx->r12 | 0X13;
    // 0x80139C30: ori         $t5, $t5, 0x15
    ctx->r13 = ctx->r13 | 0X15;
    // 0x80139C34: beql        $t9, $zero, L_80139C48
    if (ctx->r25 == 0) {
        // 0x80139C38: sw          $t5, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r13;
            goto L_80139C48;
    }
    goto skip_4;
    // 0x80139C38: sw          $t5, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r13;
    skip_4:
    // 0x80139C3C: b           L_80139C48
    // 0x80139C40: sw          $t4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r12;
        goto L_80139C48;
    // 0x80139C40: sw          $t4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r12;
    // 0x80139C44: sw          $t5, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r13;
L_80139C48:
    // 0x80139C48: lhu         $a0, 0x62($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X62);
    // 0x80139C4C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80139C50: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
    // 0x80139C54: jal         0x8000522C
    // 0x80139C58: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_5;
    // 0x80139C58: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    after_5:
    // 0x80139C5C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80139C60: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80139C64: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80139C68: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80139C6C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80139C70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80139C74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80139C78: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80139C7C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80139C80: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80139C84: b           L_80139CD8
    // 0x80139C88: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_80139CD8;
    // 0x80139C88: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_80139C8C:
    // 0x80139C8C: sw          $s2, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->r18;
    // 0x80139C90: sh          $zero, 0x10($s0)
    MEM_H(0X10, ctx->r16) = 0;
    // 0x80139C94: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    // 0x80139C98: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80139C9C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80139CA0: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x80139CA4: addiu       $t8, $t8, -0x43B0
    ctx->r24 = ADD32(ctx->r24, -0X43B0);
    // 0x80139CA8: sb          $t0, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r8;
    // 0x80139CAC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80139CB0: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80139CB4: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80139CB8: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80139CBC: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80139CC0: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80139CC4: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x80139CC8: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x80139CCC: sw          $t8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r24;
    // 0x80139CD0: sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // 0x80139CD4: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
L_80139CD8:
    // 0x80139CD8: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80139CDC: ori         $t9, $t9, 0x900
    ctx->r25 = ctx->r25 | 0X900;
    // 0x80139CE0: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x80139CE4: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80139CE8: lhu         $t4, 0xAE($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XAE);
    // 0x80139CEC: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80139CF0: sh          $t5, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r13;
    // 0x80139CF4: sw          $s0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r16;
    // 0x80139CF8: sh          $t4, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r12;
    // 0x80139CFC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80139D00: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80139D04: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x80139D08: bne         $s1, $t6, L_80139AA0
    if (ctx->r17 != ctx->r14) {
        // 0x80139D0C: addiu       $t2, $t2, 0x10
        ctx->r10 = ADD32(ctx->r10, 0X10);
            goto L_80139AA0;
    }
    // 0x80139D0C: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
L_80139D10:
    // 0x80139D10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80139D14: lwc1        $f10, -0x315C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X315C);
    // 0x80139D18: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80139D1C: addiu       $a1, $a1, -0x27A0
    ctx->r5 = ADD32(ctx->r5, -0X27A0);
    // 0x80139D20: swc1        $f10, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f10.u32l;
    // 0x80139D24: jal         0x8000DDF4
    // 0x80139D28: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    LOOKUP_FUNC(0x8000DDF4)(rdram, ctx);
        goto after_6;
    // 0x80139D28: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_6:
    // 0x80139D2C: beq         $v0, $zero, L_80139D3C
    if (ctx->r2 == 0) {
        // 0x80139D30: lw          $a0, 0xA0($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XA0);
            goto L_80139D3C;
    }
    // 0x80139D30: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80139D34: b           L_8013A17C
    // 0x80139D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013A17C;
    // 0x80139D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80139D3C:
    // 0x80139D3C: jal         0x80006214
    // 0x80139D40: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_7;
    // 0x80139D40: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_7:
    // 0x80139D44: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80139D48: lw          $t7, -0x2574($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2574);
    // 0x80139D4C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80139D50: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80139D54: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x80139D58: addiu       $t1, $t1, -0x4410
    ctx->r9 = ADD32(ctx->r9, -0X4410);
    // 0x80139D5C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80139D60: lw          $t8, 0x30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30);
    // 0x80139D64: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80139D68: sw          $t9, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r25;
    // 0x80139D6C: lw          $a2, 0x14($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X14);
    // 0x80139D70: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80139D74: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x80139D78: bne         $a2, $at, L_80139D88
    if (ctx->r6 != ctx->r1) {
        // 0x80139D7C: sll         $t5, $a2, 2
        ctx->r13 = S32(ctx->r6 << 2);
            goto L_80139D88;
    }
    // 0x80139D7C: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x80139D80: b           L_80139DA8
    // 0x80139D84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80139DA8;
    // 0x80139D84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80139D88:
    // 0x80139D88: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80139D8C: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80139D90: jal         0x8000522C
    // 0x80139D94: lhu         $a0, 0x62($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X62);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_8;
    // 0x80139D94: lhu         $a0, 0x62($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X62);
    after_8:
    // 0x80139D98: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80139D9C: addiu       $t1, $t1, -0x4410
    ctx->r9 = ADD32(ctx->r9, -0X4410);
    // 0x80139DA0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80139DA4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80139DA8:
    // 0x80139DA8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80139DAC: blez        $t7, L_80139F4C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80139DB0: andi        $v0, $t7, 0x1
        ctx->r2 = ctx->r15 & 0X1;
            goto L_80139F4C;
    }
    // 0x80139DB0: andi        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 & 0X1;
    // 0x80139DB4: beq         $v0, $zero, L_80139E40
    if (ctx->r2 == 0) {
        // 0x80139DB8: lui         $t8, 0x8009
        ctx->r24 = S32(0X8009 << 16);
            goto L_80139E40;
    }
    // 0x80139DB8: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80139DBC: lw          $t8, -0x2578($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2578);
    // 0x80139DC0: beq         $a2, $zero, L_80139DDC
    if (ctx->r6 == 0) {
        // 0x80139DC4: lw          $v0, 0x2C($t8)
        ctx->r2 = MEM_W(ctx->r24, 0X2C);
            goto L_80139DDC;
    }
    // 0x80139DC4: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x80139DC8: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80139DCC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80139DD0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80139DD4: b           L_80139DF0
    // 0x80139DD8: swc1        $f4, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f4.u32l;
        goto L_80139DF0;
    // 0x80139DD8: swc1        $f4, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f4.u32l;
L_80139DDC:
    // 0x80139DDC: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80139DE0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80139DE4: nop

    // 0x80139DE8: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x80139DEC: swc1        $f6, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f6.u32l;
L_80139DF0:
    // 0x80139DF0: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x80139DF4: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x80139DF8: bltzl       $t4, L_80139E34
    if (SIGNED(ctx->r12) < 0) {
        // 0x80139DFC: lw          $t9, 0x3C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X3C);
            goto L_80139E34;
    }
    goto skip_5;
    // 0x80139DFC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    skip_5:
    // 0x80139E00: sb          $t0, 0x48($v0)
    MEM_B(0X48, ctx->r2) = ctx->r8;
    // 0x80139E04: sb          $t0, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r8;
    // 0x80139E08: sb          $t0, 0x4A($v0)
    MEM_B(0X4A, ctx->r2) = ctx->r8;
    // 0x80139E0C: sb          $t0, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r8;
    // 0x80139E10: lbu         $t5, 0xF32($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0XF32);
    // 0x80139E14: sb          $t5, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r13;
    // 0x80139E18: lbu         $t6, 0xF33($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0XF33);
    // 0x80139E1C: sb          $t6, 0x4D($v0)
    MEM_B(0X4D, ctx->r2) = ctx->r14;
    // 0x80139E20: lbu         $t7, 0xF34($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0XF34);
    // 0x80139E24: sb          $t7, 0x4E($v0)
    MEM_B(0X4E, ctx->r2) = ctx->r15;
    // 0x80139E28: lbu         $t8, 0xF35($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0XF35);
    // 0x80139E2C: sb          $t8, 0x4F($v0)
    MEM_B(0X4F, ctx->r2) = ctx->r24;
    // 0x80139E30: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
L_80139E34:
    // 0x80139E34: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80139E38: beq         $s1, $t9, L_80139F4C
    if (ctx->r17 == ctx->r25) {
        // 0x80139E3C: nop
    
            goto L_80139F4C;
    }
    // 0x80139E3C: nop

L_80139E40:
    // 0x80139E40: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80139E44: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x80139E48: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80139E4C: addiu       $t7, $t7, -0x2578
    ctx->r15 = ADD32(ctx->r15, -0X2578);
    // 0x80139E50: sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17 << 2);
    // 0x80139E54: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80139E58: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80139E5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80139E60: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x80139E64: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x80139E68: addu        $v1, $t4, $a1
    ctx->r3 = ADD32(ctx->r12, ctx->r5);
L_80139E6C:
    // 0x80139E6C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80139E70: addu        $t9, $a2, $a1
    ctx->r25 = ADD32(ctx->r6, ctx->r5);
    // 0x80139E74: beq         $a2, $zero, L_80139E90
    if (ctx->r6 == 0) {
        // 0x80139E78: lw          $v0, 0x2C($t8)
        ctx->r2 = MEM_W(ctx->r24, 0X2C);
            goto L_80139E90;
    }
    // 0x80139E78: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x80139E7C: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80139E80: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80139E84: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80139E88: b           L_80139E98
    // 0x80139E8C: swc1        $f16, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f16.u32l;
        goto L_80139E98;
    // 0x80139E8C: swc1        $f16, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f16.u32l;
L_80139E90:
    // 0x80139E90: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
    // 0x80139E94: swc1        $f18, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f18.u32l;
L_80139E98:
    // 0x80139E98: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80139E9C: bltzl       $t4, L_80139ED8
    if (SIGNED(ctx->r12) < 0) {
        // 0x80139EA0: lw          $t9, 0x4($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X4);
            goto L_80139ED8;
    }
    goto skip_6;
    // 0x80139EA0: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    skip_6:
    // 0x80139EA4: sb          $t0, 0x48($v0)
    MEM_B(0X48, ctx->r2) = ctx->r8;
    // 0x80139EA8: sb          $t0, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r8;
    // 0x80139EAC: sb          $t0, 0x4A($v0)
    MEM_B(0X4A, ctx->r2) = ctx->r8;
    // 0x80139EB0: sb          $t0, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r8;
    // 0x80139EB4: lbu         $t5, 0xF32($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0XF32);
    // 0x80139EB8: sb          $t5, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r13;
    // 0x80139EBC: lbu         $t6, 0xF33($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0XF33);
    // 0x80139EC0: sb          $t6, 0x4D($v0)
    MEM_B(0X4D, ctx->r2) = ctx->r14;
    // 0x80139EC4: lbu         $t7, 0xF34($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0XF34);
    // 0x80139EC8: sb          $t7, 0x4E($v0)
    MEM_B(0X4E, ctx->r2) = ctx->r15;
    // 0x80139ECC: lbu         $t8, 0xF35($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0XF35);
    // 0x80139ED0: sb          $t8, 0x4F($v0)
    MEM_B(0X4F, ctx->r2) = ctx->r24;
    // 0x80139ED4: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
L_80139ED8:
    // 0x80139ED8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80139EDC: beq         $a2, $zero, L_80139EFC
    if (ctx->r6 == 0) {
        // 0x80139EE0: lw          $v0, 0x2C($t9)
        ctx->r2 = MEM_W(ctx->r25, 0X2C);
            goto L_80139EFC;
    }
    // 0x80139EE0: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x80139EE4: addu        $t4, $a2, $a1
    ctx->r12 = ADD32(ctx->r6, ctx->r5);
    // 0x80139EE8: lwc1        $f4, 0x4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80139EEC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80139EF0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80139EF4: b           L_80139F04
    // 0x80139EF8: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
        goto L_80139F04;
    // 0x80139EF8: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
L_80139EFC:
    // 0x80139EFC: cvt.s.d     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f10.fl = CVT_S_D(ctx->f0.d);
    // 0x80139F00: swc1        $f10, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f10.u32l;
L_80139F04:
    // 0x80139F04: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x80139F08: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80139F0C: bltz        $t5, L_80139F44
    if (SIGNED(ctx->r13) < 0) {
        // 0x80139F10: nop
    
            goto L_80139F44;
    }
    // 0x80139F10: nop

    // 0x80139F14: sb          $t0, 0x48($v0)
    MEM_B(0X48, ctx->r2) = ctx->r8;
    // 0x80139F18: sb          $t0, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r8;
    // 0x80139F1C: sb          $t0, 0x4A($v0)
    MEM_B(0X4A, ctx->r2) = ctx->r8;
    // 0x80139F20: sb          $t0, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r8;
    // 0x80139F24: lbu         $t6, 0xF32($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0XF32);
    // 0x80139F28: sb          $t6, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r14;
    // 0x80139F2C: lbu         $t7, 0xF33($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0XF33);
    // 0x80139F30: sb          $t7, 0x4D($v0)
    MEM_B(0X4D, ctx->r2) = ctx->r15;
    // 0x80139F34: lbu         $t8, 0xF34($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0XF34);
    // 0x80139F38: sb          $t8, 0x4E($v0)
    MEM_B(0X4E, ctx->r2) = ctx->r24;
    // 0x80139F3C: lbu         $t9, 0xF35($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0XF35);
    // 0x80139F40: sb          $t9, 0x4F($v0)
    MEM_B(0X4F, ctx->r2) = ctx->r25;
L_80139F44:
    // 0x80139F44: bne         $a0, $a3, L_80139E6C
    if (ctx->r4 != ctx->r7) {
        // 0x80139F48: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80139E6C;
    }
    // 0x80139F48: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80139F4C:
    // 0x80139F4C: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80139F50: lw          $t4, -0x2578($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2578);
    // 0x80139F54: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80139F58: lwc1        $f0, -0x2044($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2044);
    // 0x80139F5C: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x80139F60: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80139F64: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80139F68: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x80139F6C: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80139F70: jal         0x8000522C
    // 0x80139F74: lhu         $a0, 0x62($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X62);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_9;
    // 0x80139F74: lhu         $a0, 0x62($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X62);
    after_9:
    // 0x80139F78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80139F7C: jal         0x801395E4
    // 0x80139F80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    LOOKUP_FUNC(0x801395E4)(rdram, ctx);
        goto after_10;
    // 0x80139F80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x80139F84: lwc1        $f16, 0x68($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X68);
    // 0x80139F88: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80139F8C: ldc1        $f0, -0x2040($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2040);
    // 0x80139F90: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80139F94: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80139F98: add.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f18.d + ctx->f0.d;
    // 0x80139F9C: lw          $v0, 0xA0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA0);
    // 0x80139FA0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80139FA4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80139FA8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80139FAC: nop

    // 0x80139FB0: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80139FB4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80139FB8: nop

    // 0x80139FBC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80139FC0: beql        $t6, $zero, L_8013A014
    if (ctx->r14 == 0) {
        // 0x80139FC4: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_8013A014;
    }
    goto skip_7;
    // 0x80139FC4: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_7:
    // 0x80139FC8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80139FCC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80139FD0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80139FD4: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x80139FD8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80139FDC: nop

    // 0x80139FE0: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x80139FE4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80139FE8: nop

    // 0x80139FEC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80139FF0: bne         $t6, $zero, L_8013A008
    if (ctx->r14 != 0) {
        // 0x80139FF4: nop
    
            goto L_8013A008;
    }
    // 0x80139FF4: nop

    // 0x80139FF8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80139FFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8013A000: b           L_8013A020
    // 0x8013A004: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8013A020;
    // 0x8013A004: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8013A008:
    // 0x8013A008: b           L_8013A020
    // 0x8013A00C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8013A020;
    // 0x8013A00C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8013A010: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_8013A014:
    // 0x8013A014: nop

    // 0x8013A018: bltz        $t6, L_8013A008
    if (SIGNED(ctx->r14) < 0) {
        // 0x8013A01C: nop
    
            goto L_8013A008;
    }
    // 0x8013A01C: nop

L_8013A020:
    // 0x8013A020: sb          $t6, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r14;
    // 0x8013A024: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8013A028: lwc1        $f8, 0x50($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X50);
    // 0x8013A02C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8013A030: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8013A034: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8013A038: add.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f10.d + ctx->f0.d;
    // 0x8013A03C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8013A040: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8013A044: nop

    // 0x8013A048: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x8013A04C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8013A050: nop

    // 0x8013A054: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8013A058: beql        $t8, $zero, L_8013A0AC
    if (ctx->r24 == 0) {
        // 0x8013A05C: mfc1        $t8, $f18
        ctx->r24 = (int32_t)ctx->f18.u32l;
            goto L_8013A0AC;
    }
    goto skip_8;
    // 0x8013A05C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    skip_8:
    // 0x8013A060: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8013A064: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8013A068: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8013A06C: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x8013A070: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8013A074: nop

    // 0x8013A078: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x8013A07C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8013A080: nop

    // 0x8013A084: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8013A088: bne         $t8, $zero, L_8013A0A0
    if (ctx->r24 != 0) {
        // 0x8013A08C: nop
    
            goto L_8013A0A0;
    }
    // 0x8013A08C: nop

    // 0x8013A090: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8013A094: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8013A098: b           L_8013A0B8
    // 0x8013A09C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8013A0B8;
    // 0x8013A09C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8013A0A0:
    // 0x8013A0A0: b           L_8013A0B8
    // 0x8013A0A4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8013A0B8;
    // 0x8013A0A4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8013A0A8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
L_8013A0AC:
    // 0x8013A0AC: nop

    // 0x8013A0B0: bltz        $t8, L_8013A0A0
    if (SIGNED(ctx->r24) < 0) {
        // 0x8013A0B4: nop
    
            goto L_8013A0A0;
    }
    // 0x8013A0B4: nop

L_8013A0B8:
    // 0x8013A0B8: sb          $t8, 0x4D($v0)
    MEM_B(0X4D, ctx->r2) = ctx->r24;
    // 0x8013A0BC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8013A0C0: lwc1        $f4, 0x68($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X68);
    // 0x8013A0C4: lwc1        $f2, 0x6C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X6C);
    // 0x8013A0C8: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8013A0CC: nop

    // 0x8013A0D0: bc1fl       L_8013A174
    if (!c1cs) {
        // 0x8013A0D4: lbu         $t5, 0x4C($v0)
        ctx->r13 = MEM_BU(ctx->r2, 0X4C);
            goto L_8013A174;
    }
    goto skip_9;
    // 0x8013A0D4: lbu         $t5, 0x4C($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4C);
    skip_9:
    // 0x8013A0D8: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8013A0DC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8013A0E0: add.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d + ctx->f0.d;
    // 0x8013A0E4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8013A0E8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8013A0EC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8013A0F0: nop

    // 0x8013A0F4: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x8013A0F8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8013A0FC: nop

    // 0x8013A100: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8013A104: beql        $t4, $zero, L_8013A158
    if (ctx->r12 == 0) {
        // 0x8013A108: mfc1        $t4, $f10
        ctx->r12 = (int32_t)ctx->f10.u32l;
            goto L_8013A158;
    }
    goto skip_10;
    // 0x8013A108: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    skip_10:
    // 0x8013A10C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8013A110: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8013A114: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8013A118: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x8013A11C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8013A120: nop

    // 0x8013A124: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x8013A128: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8013A12C: nop

    // 0x8013A130: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8013A134: bne         $t4, $zero, L_8013A14C
    if (ctx->r12 != 0) {
        // 0x8013A138: nop
    
            goto L_8013A14C;
    }
    // 0x8013A138: nop

    // 0x8013A13C: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8013A140: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8013A144: b           L_8013A164
    // 0x8013A148: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8013A164;
    // 0x8013A148: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8013A14C:
    // 0x8013A14C: b           L_8013A164
    // 0x8013A150: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8013A164;
    // 0x8013A150: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8013A154: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
L_8013A158:
    // 0x8013A158: nop

    // 0x8013A15C: bltz        $t4, L_8013A14C
    if (SIGNED(ctx->r12) < 0) {
        // 0x8013A160: nop
    
            goto L_8013A14C;
    }
    // 0x8013A160: nop

L_8013A164:
    // 0x8013A164: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8013A168: b           L_8013A178
    // 0x8013A16C: sb          $t4, 0x4E($v0)
    MEM_B(0X4E, ctx->r2) = ctx->r12;
        goto L_8013A178;
    // 0x8013A16C: sb          $t4, 0x4E($v0)
    MEM_B(0X4E, ctx->r2) = ctx->r12;
    // 0x8013A170: lbu         $t5, 0x4C($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4C);
L_8013A174:
    // 0x8013A174: sb          $t5, 0x4E($v0)
    MEM_B(0X4E, ctx->r2) = ctx->r13;
L_8013A178:
    // 0x8013A178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013A17C:
    // 0x8013A17C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8013A180: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013A184: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8013A188: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8013A18C: jr          $ra
    // 0x8013A190: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8013A190: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013a194(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013a194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013A198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013A19C: jal         0x80139894
    // 0x8013A1A0: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    LOOKUP_FUNC(0x80139894)(rdram, ctx);
        goto after_0;
    // 0x8013A1A0: addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_0:
    // 0x8013A1A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013A1A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013A1AC: jr          $ra
    // 0x8013A1B0: nop

    return;
    // 0x8013A1B0: nop

;}
RECOMP_FUNC void M7_FUN_8013a1b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A1B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8013A1B8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013A1BC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8013A1C0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8013A1C4: lw          $a3, 0x10($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X10);
    // 0x8013A1C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013A1CC: lw          $v0, 0x18($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X18);
    // 0x8013A1D0: andi        $t7, $a3, 0x1
    ctx->r15 = ctx->r7 & 0X1;
    // 0x8013A1D4: addiu       $t0, $sp, 0x4
    ctx->r8 = ADD32(ctx->r29, 0X4);
    // 0x8013A1D8: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x8013A1DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8013A1E0: beq         $t7, $zero, L_8013A224
    if (ctx->r15 == 0) {
        // 0x8013A1E4: lbu         $a1, 0xD($v1)
        ctx->r5 = MEM_BU(ctx->r3, 0XD);
            goto L_8013A224;
    }
    // 0x8013A1E4: lbu         $a1, 0xD($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0XD);
    // 0x8013A1E8: sb          $t8, 0x76($v1)
    MEM_B(0X76, ctx->r3) = ctx->r24;
    // 0x8013A1EC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8013A1F0: sw          $t1, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r9;
    // 0x8013A1F4: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x8013A1F8: sw          $t9, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r25;
    // 0x8013A1FC: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8013A200: sw          $t1, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r9;
    // 0x8013A204: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8013A208: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8013A20C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x8013A210: sw          $t5, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->r13;
    // 0x8013A214: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x8013A218: sw          $t4, 0x60($t3)
    MEM_W(0X60, ctx->r11) = ctx->r12;
    // 0x8013A21C: lw          $t5, 0x8($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X8);
    // 0x8013A220: sw          $t5, 0x64($t3)
    MEM_W(0X64, ctx->r11) = ctx->r13;
L_8013A224:
    // 0x8013A224: beq         $a3, $zero, L_8013A284
    if (ctx->r7 == 0) {
        // 0x8013A228: addiu       $t0, $sp, 0x4
        ctx->r8 = ADD32(ctx->r29, 0X4);
            goto L_8013A284;
    }
    // 0x8013A228: addiu       $t0, $sp, 0x4
    ctx->r8 = ADD32(ctx->r29, 0X4);
    // 0x8013A22C: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x8013A230: bne         $at, $zero, L_8013A284
    if (ctx->r1 != 0) {
        // 0x8013A234: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8013A284;
    }
    // 0x8013A234: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8013A238: andi        $t6, $a3, 0x1
    ctx->r14 = ctx->r7 & 0X1;
L_8013A23C:
    // 0x8013A23C: beq         $t6, $zero, L_8013A26C
    if (ctx->r14 == 0) {
        // 0x8013A240: srl         $a3, $a3, 1
        ctx->r7 = S32(U32(ctx->r7) >> 1);
            goto L_8013A26C;
    }
    // 0x8013A240: srl         $a3, $a3, 1
    ctx->r7 = S32(U32(ctx->r7) >> 1);
    // 0x8013A244: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8013A248: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8013A24C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8013A250: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8013A254: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x8013A258: sw          $t3, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->r11;
    // 0x8013A25C: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x8013A260: sw          $t2, 0x60($t1)
    MEM_W(0X60, ctx->r9) = ctx->r10;
    // 0x8013A264: lw          $t3, 0x8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X8);
    // 0x8013A268: sw          $t3, 0x64($t1)
    MEM_W(0X64, ctx->r9) = ctx->r11;
L_8013A26C:
    // 0x8013A26C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8013A270: beq         $a3, $zero, L_8013A284
    if (ctx->r7 == 0) {
        // 0x8013A274: andi        $a2, $a2, 0xFF
        ctx->r6 = ctx->r6 & 0XFF;
            goto L_8013A284;
    }
    // 0x8013A274: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8013A278: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8013A27C: bnel        $at, $zero, L_8013A23C
    if (ctx->r1 != 0) {
        // 0x8013A280: andi        $t6, $a3, 0x1
        ctx->r14 = ctx->r7 & 0X1;
            goto L_8013A23C;
    }
    goto skip_0;
    // 0x8013A280: andi        $t6, $a3, 0x1
    ctx->r14 = ctx->r7 & 0X1;
    skip_0:
L_8013A284:
    // 0x8013A284: jr          $ra
    // 0x8013A288: nop

    return;
    // 0x8013A288: nop

;}
RECOMP_FUNC void M7_FUN_8013a28c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A28C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013A290: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013A294: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8013A298: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8013A29C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8013A2A0: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x8013A2A4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013A2A8: lui         $t9, 0x3
    ctx->r25 = S32(0X3 << 16);
    // 0x8013A2AC: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8013A2B0: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8013A2B4: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x8013A2B8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8013A2BC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013A2C0: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    // 0x8013A2C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8013A2C8: jal         0x8013A1B4
    // 0x8013A2CC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_0;
    // 0x8013A2CC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x8013A2D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013A2D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013A2D8: jr          $ra
    // 0x8013A2DC: nop

    return;
    // 0x8013A2DC: nop

;}
RECOMP_FUNC void M7_FUN_8013a2e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A2E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013A2E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013A2E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8013A2EC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8013A2F0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8013A2F4: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x8013A2F8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013A2FC: lui         $t9, 0xFF
    ctx->r25 = S32(0XFF << 16);
    // 0x8013A300: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8013A304: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8013A308: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x8013A30C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8013A310: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013A314: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    // 0x8013A318: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8013A31C: jal         0x8013A1B4
    // 0x8013A320: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_0;
    // 0x8013A320: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x8013A324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013A328: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013A32C: jr          $ra
    // 0x8013A330: nop

    return;
    // 0x8013A330: nop

;}
RECOMP_FUNC void M7_FUN_8013a334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A334: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8013A338: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8013A33C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013A340: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013A344: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x8013A348: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x8013A34C: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    // 0x8013A350: addiu       $t6, $t6, -0x4340
    ctx->r14 = ADD32(ctx->r14, -0X4340);
    // 0x8013A354: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013A358: addiu       $t2, $sp, 0x2C
    ctx->r10 = ADD32(ctx->r29, 0X2C);
    // 0x8013A35C: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8013A360: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8013A364: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8013A368: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8013A36C: slti        $at, $a3, 0x19
    ctx->r1 = SIGNED(ctx->r7) < 0X19 ? 1 : 0;
    // 0x8013A370: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8013A374: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8013A378: sw          $t8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r24;
    // 0x8013A37C: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x8013A380: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x8013A384: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8013A388: lhu         $t1, 0xE($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0XE);
    // 0x8013A38C: lw          $t5, 0x1C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C);
    // 0x8013A390: andi        $t1, $t1, 0xFFF
    ctx->r9 = ctx->r9 & 0XFFF;
    // 0x8013A394: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
    // 0x8013A398: bne         $t5, $zero, L_8013A3C0
    if (ctx->r13 != 0) {
        // 0x8013A39C: nop
    
            goto L_8013A3C0;
    }
    // 0x8013A39C: nop

    // 0x8013A3A0: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x8013A3A4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8013A3A8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8013A3AC: lw          $t6, 0x4($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X4);
    // 0x8013A3B0: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8013A3B4: lw          $t7, 0x8($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X8);
    // 0x8013A3B8: b           L_8013A5D4
    // 0x8013A3BC: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
        goto L_8013A5D4;
    // 0x8013A3BC: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
L_8013A3C0:
    // 0x8013A3C0: bne         $at, $zero, L_8013A524
    if (ctx->r1 != 0) {
        // 0x8013A3C4: or          $t0, $a3, $zero
        ctx->r8 = ctx->r7 | 0;
            goto L_8013A524;
    }
    // 0x8013A3C4: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8013A3C8: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x8013A3CC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8013A3D0: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x8013A3D4: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8013A3D8: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x8013A3DC: lw          $t3, 0x10($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X10);
    // 0x8013A3E0: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8013A3E4: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8013A3E8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8013A3EC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8013A3F0: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x8013A3F4: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    // 0x8013A3F8: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x8013A3FC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8013A400: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x8013A404: addu        $a1, $t7, $a2
    ctx->r5 = ADD32(ctx->r15, ctx->r6);
    // 0x8013A408: addiu       $a1, $a1, -0xC
    ctx->r5 = ADD32(ctx->r5, -0XC);
    // 0x8013A40C: jal         0x8000522C
    // 0x8013A410: sh          $a3, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_0;
    // 0x8013A410: sh          $a3, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r7;
    after_0:
    // 0x8013A414: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8013A418: lhu         $a3, 0x9E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X9E);
    // 0x8013A41C: addiu       $t8, $sp, 0x38
    ctx->r24 = ADD32(ctx->r29, 0X38);
    // 0x8013A420: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8013A424: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8013A428: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8013A42C: sll         $t5, $a3, 1
    ctx->r13 = S32(ctx->r7 << 1);
    // 0x8013A430: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8013A434: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x8013A438: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8013A43C: addiu       $t2, $sp, 0x2C
    ctx->r10 = ADD32(ctx->r29, 0X2C);
    // 0x8013A440: sw          $t3, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r11;
    // 0x8013A444: lhu         $t6, -0x4384($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4384);
    // 0x8013A448: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x8013A44C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8013A450: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x8013A454: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8013A458: lw          $a0, 0x1C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X1C);
    // 0x8013A45C: bne         $a0, $zero, L_8013A484
    if (ctx->r4 != 0) {
        // 0x8013A460: nop
    
            goto L_8013A484;
    }
    // 0x8013A460: nop

    // 0x8013A464: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x8013A468: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8013A46C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8013A470: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8013A474: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x8013A478: lw          $t5, 0x8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X8);
    // 0x8013A47C: b           L_8013A5D4
    // 0x8013A480: sw          $t5, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r13;
        goto L_8013A5D4;
    // 0x8013A480: sw          $t5, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r13;
L_8013A484:
    // 0x8013A484: jal         0x8000B67C
    // 0x8013A488: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8000B67C)(rdram, ctx);
        goto after_1;
    // 0x8013A488: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x8013A48C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8013A490: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8013A494: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8013A498: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8013A49C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8013A4A0: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8013A4A4: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8013A4A8: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8013A4AC: addiu       $t2, $sp, 0x2C
    ctx->r10 = ADD32(ctx->r29, 0X2C);
    // 0x8013A4B0: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8013A4B4: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8013A4B8: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8013A4BC: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8013A4C0: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8013A4C4: mul.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8013A4C8: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8013A4CC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8013A4D0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8013A4D4: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8013A4D8: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8013A4DC: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8013A4E0: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8013A4E4: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8013A4E8: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8013A4EC: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8013A4F0: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8013A4F4: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8013A4F8: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8013A4FC: mul.s       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8013A500: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8013A504: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8013A508: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8013A50C: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8013A510: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8013A514: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8013A518: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8013A51C: b           L_8013A5B8
    // 0x8013A520: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
        goto L_8013A5B8;
    // 0x8013A520: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
L_8013A524:
    // 0x8013A524: beq         $a3, $zero, L_8013A590
    if (ctx->r7 == 0) {
        // 0x8013A528: lw          $t5, 0x94($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X94);
            goto L_8013A590;
    }
    // 0x8013A528: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8013A52C: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x8013A530: sll         $t4, $a3, 2
    ctx->r12 = S32(ctx->r7 << 2);
    // 0x8013A534: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x8013A538: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8013A53C: lw          $a0, 0x1C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X1C);
    // 0x8013A540: bne         $a0, $zero, L_8013A568
    if (ctx->r4 != 0) {
        // 0x8013A544: nop
    
            goto L_8013A568;
    }
    // 0x8013A544: nop

    // 0x8013A548: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8013A54C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8013A550: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8013A554: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x8013A558: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x8013A55C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x8013A560: b           L_8013A5D4
    // 0x8013A564: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
        goto L_8013A5D4;
    // 0x8013A564: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
L_8013A568:
    // 0x8013A568: jal         0x8000B67C
    // 0x8013A56C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8000B67C)(rdram, ctx);
        goto after_2;
    // 0x8013A56C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x8013A570: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8013A574: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8013A578: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8013A57C: addiu       $t2, $sp, 0x2C
    ctx->r10 = ADD32(ctx->r29, 0X2C);
    // 0x8013A580: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8013A584: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8013A588: b           L_8013A5B8
    // 0x8013A58C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
        goto L_8013A5B8;
    // 0x8013A58C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
L_8013A590:
    // 0x8013A590: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8013A594: addu        $t4, $t5, $t6
    ctx->r12 = ADD32(ctx->r13, ctx->r14);
    // 0x8013A598: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8013A59C: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x8013A5A0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8013A5A4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8013A5A8: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8013A5AC: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8013A5B0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8013A5B4: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
L_8013A5B8:
    // 0x8013A5B8: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8013A5BC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8013A5C0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8013A5C4: lw          $t8, 0x4($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X4);
    // 0x8013A5C8: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8013A5CC: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x8013A5D0: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
L_8013A5D4:
    // 0x8013A5D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013A5D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013A5DC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x8013A5E0: jr          $ra
    // 0x8013A5E4: nop

    return;
    // 0x8013A5E4: nop

;}
RECOMP_FUNC void M7_FUN_8013a5e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A5E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8013A5EC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8013A5F0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8013A5F4: sll         $t9, $a1, 5
    ctx->r25 = S32(ctx->r5 << 5);
    // 0x8013A5F8: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8013A5FC: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x8013A600: addiu       $t1, $t1, -0x6D50
    ctx->r9 = ADD32(ctx->r9, -0X6D50);
    // 0x8013A604: addu        $t0, $t9, $at
    ctx->r8 = ADD32(ctx->r25, ctx->r1);
    // 0x8013A608: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8013A60C: lh          $t2, 0x1CA($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X1CA);
    // 0x8013A610: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x8013A614: lh          $t5, 0x1CC($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X1CC);
    // 0x8013A618: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8013A61C: div         $zero, $t3, $a3
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r7)));
    // 0x8013A620: mflo        $t4
    ctx->r12 = lo;
    // 0x8013A624: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8013A628: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8013A62C: div         $zero, $t5, $a3
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r7)));
    // 0x8013A630: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013A634: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8013A638: lh          $t7, -0x41DE($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X41DE);
    // 0x8013A63C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013A640: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8013A644: addiu       $t8, $zero, 0x2800
    ctx->r24 = ADD32(0, 0X2800);
    // 0x8013A648: subu        $a2, $t8, $t7
    ctx->r6 = SUB32(ctx->r24, ctx->r15);
    // 0x8013A64C: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8013A650: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8013A654: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x8013A658: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8013A65C: mflo        $t6
    ctx->r14 = lo;
    // 0x8013A660: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8013A664: andi        $a2, $a2, 0x1FFF
    ctx->r6 = ctx->r6 & 0X1FFF;
    // 0x8013A668: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8013A66C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8013A670: bne         $a3, $zero, L_8013A67C
    if (ctx->r7 != 0) {
        // 0x8013A674: nop
    
            goto L_8013A67C;
    }
    // 0x8013A674: nop

    // 0x8013A678: break       7
    do_break(2148771448);
L_8013A67C:
    // 0x8013A67C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8013A680: bne         $a3, $at, L_8013A694
    if (ctx->r7 != ctx->r1) {
        // 0x8013A684: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8013A694;
    }
    // 0x8013A684: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8013A688: bne         $t3, $at, L_8013A694
    if (ctx->r11 != ctx->r1) {
        // 0x8013A68C: nop
    
            goto L_8013A694;
    }
    // 0x8013A68C: nop

    // 0x8013A690: break       6
    do_break(2148771472);
L_8013A694:
    // 0x8013A694: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8013A698: bne         $a3, $zero, L_8013A6A4
    if (ctx->r7 != 0) {
        // 0x8013A69C: nop
    
            goto L_8013A6A4;
    }
    // 0x8013A69C: nop

    // 0x8013A6A0: break       7
    do_break(2148771488);
L_8013A6A4:
    // 0x8013A6A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8013A6A8: bne         $a3, $at, L_8013A6BC
    if (ctx->r7 != ctx->r1) {
        // 0x8013A6AC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8013A6BC;
    }
    // 0x8013A6AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8013A6B0: bne         $t5, $at, L_8013A6BC
    if (ctx->r13 != ctx->r1) {
        // 0x8013A6B4: nop
    
            goto L_8013A6BC;
    }
    // 0x8013A6B4: nop

    // 0x8013A6B8: break       6
    do_break(2148771512);
L_8013A6BC:
    // 0x8013A6BC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8013A6C0: bc1fl       L_8013A6D4
    if (!c1cs) {
        // 0x8013A6C4: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8013A6D4;
    }
    goto skip_0;
    // 0x8013A6C4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x8013A6C8: b           L_8013A6D4
    // 0x8013A6CC: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_8013A6D4;
    // 0x8013A6CC: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x8013A6D0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8013A6D4:
    // 0x8013A6D4: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8013A6D8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8013A6DC: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8013A6E0: c.le.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d <= ctx->f8.d;
    // 0x8013A6E4: nop

    // 0x8013A6E8: bc1tl       L_8013A724
    if (c1cs) {
        // 0x8013A6EC: sw          $v1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r3;
            goto L_8013A724;
    }
    goto skip_1;
    // 0x8013A6EC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    skip_1:
    // 0x8013A6F0: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x8013A6F4: nop

    // 0x8013A6F8: bc1fl       L_8013A70C
    if (!c1cs) {
        // 0x8013A6FC: mov.s       $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
            goto L_8013A70C;
    }
    goto skip_2;
    // 0x8013A6FC: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    skip_2:
    // 0x8013A700: b           L_8013A70C
    // 0x8013A704: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
        goto L_8013A70C;
    // 0x8013A704: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
    // 0x8013A708: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_8013A70C:
    // 0x8013A70C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8013A710: c.le.d      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.d <= ctx->f10.d;
    // 0x8013A714: nop

    // 0x8013A718: bc1fl       L_8013A7C8
    if (!c1cs) {
        // 0x8013A71C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013A7C8;
    }
    goto skip_3;
    // 0x8013A71C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8013A720: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
L_8013A724:
    // 0x8013A724: sh          $a2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r6;
    // 0x8013A728: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x8013A72C: jal         0x8001EF38
    // 0x8013A730: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_0;
    // 0x8013A730: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8013A734: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8013A738: lh          $a2, 0x1E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X1E);
    // 0x8013A73C: sh          $v0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r2;
    // 0x8013A740: lh          $t8, 0x12($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X12);
    // 0x8013A744: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    // 0x8013A748: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8013A74C: addu        $t7, $t8, $a2
    ctx->r15 = ADD32(ctx->r24, ctx->r6);
    // 0x8013A750: jal         0x8001EAD0
    // 0x8013A754: sh          $t7, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r15;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x8013A754: sh          $t7, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r15;
    after_1:
    // 0x8013A758: lh          $a2, 0x1E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X1E);
    // 0x8013A75C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8013A760: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    // 0x8013A764: jal         0x8001EB64
    // 0x8013A768: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x8013A768: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x8013A76C: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8013A770: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8013A774: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8013A778: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013A77C: mul.s       $f18, $f14, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8013A780: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013A784: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8013A788: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8013A78C: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8013A790: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8013A794: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8013A798: nop

    // 0x8013A79C: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8013A7A0: nop

    // 0x8013A7A4: mul.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8013A7A8: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8013A7AC: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8013A7B0: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8013A7B4: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8013A7B8: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8013A7BC: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8013A7C0: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
    // 0x8013A7C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A7C8:
    // 0x8013A7C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8013A7CC: jr          $ra
    // 0x8013A7D0: nop

    return;
    // 0x8013A7D0: nop

;}
