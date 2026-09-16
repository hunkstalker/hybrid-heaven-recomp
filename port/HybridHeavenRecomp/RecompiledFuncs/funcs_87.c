#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M9_FUN_801f7b2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7B2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801F7B30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801F7B34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F7B38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F7B3C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801F7B40: jal         0x8001EB64
    // 0x801F7B44: lh          $a0, 0x94($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X94);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x801F7B44: lh          $a0, 0x94($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X94);
    after_0:
    // 0x801F7B48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F7B4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F7B50: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F7B54: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F7B58: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801F7B5C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F7B60: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x801F7B64: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F7B68: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801F7B6C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F7B70: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801F7B74: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x801F7B78: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F7B7C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F7B80: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F7B84: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801F7B88: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x801F7B8C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F7B90: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F7B94: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F7B98: nop

    // 0x801F7B9C: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x801F7BA0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F7BA4: nop

    // 0x801F7BA8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801F7BAC: beql        $t7, $zero, L_801F7C00
    if (ctx->r15 == 0) {
        // 0x801F7BB0: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_801F7C00;
    }
    goto skip_0;
    // 0x801F7BB0: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x801F7BB4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F7BB8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F7BBC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F7BC0: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x801F7BC4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F7BC8: nop

    // 0x801F7BCC: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x801F7BD0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F7BD4: nop

    // 0x801F7BD8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801F7BDC: bne         $t7, $zero, L_801F7BF4
    if (ctx->r15 != 0) {
        // 0x801F7BE0: nop
    
            goto L_801F7BF4;
    }
    // 0x801F7BE0: nop

    // 0x801F7BE4: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x801F7BE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F7BEC: b           L_801F7C0C
    // 0x801F7BF0: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801F7C0C;
    // 0x801F7BF0: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801F7BF4:
    // 0x801F7BF4: b           L_801F7C0C
    // 0x801F7BF8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801F7C0C;
    // 0x801F7BF8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801F7BFC: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_801F7C00:
    // 0x801F7C00: nop

    // 0x801F7C04: bltz        $t7, L_801F7BF4
    if (SIGNED(ctx->r15) < 0) {
        // 0x801F7C08: nop
    
            goto L_801F7BF4;
    }
    // 0x801F7C08: nop

L_801F7C0C:
    // 0x801F7C0C: sb          $t7, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r15;
    // 0x801F7C10: lh          $a0, 0x94($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X94);
    // 0x801F7C14: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F7C18: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x801F7C1C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801F7C20: jal         0x8001EB64
    // 0x801F7C24: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x801F7C24: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x801F7C28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F7C2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F7C30: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F7C34: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F7C38: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x801F7C3C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F7C40: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x801F7C44: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F7C48: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801F7C4C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F7C50: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801F7C54: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x801F7C58: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F7C5C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F7C60: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801F7C64: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801F7C68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7C6C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801F7C70: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801F7C74: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801F7C78: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801F7C7C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801F7C80: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801F7C84: nop

    // 0x801F7C88: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x801F7C8C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801F7C90: nop

    // 0x801F7C94: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801F7C98: beql        $t9, $zero, L_801F7CEC
    if (ctx->r25 == 0) {
        // 0x801F7C9C: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_801F7CEC;
    }
    goto skip_1;
    // 0x801F7C9C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x801F7CA0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F7CA4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F7CA8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801F7CAC: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x801F7CB0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801F7CB4: nop

    // 0x801F7CB8: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x801F7CBC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801F7CC0: nop

    // 0x801F7CC4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801F7CC8: bne         $t9, $zero, L_801F7CE0
    if (ctx->r25 != 0) {
        // 0x801F7CCC: nop
    
            goto L_801F7CE0;
    }
    // 0x801F7CCC: nop

    // 0x801F7CD0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x801F7CD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F7CD8: b           L_801F7CF8
    // 0x801F7CDC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801F7CF8;
    // 0x801F7CDC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801F7CE0:
    // 0x801F7CE0: b           L_801F7CF8
    // 0x801F7CE4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801F7CF8;
    // 0x801F7CE4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801F7CE8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_801F7CEC:
    // 0x801F7CEC: nop

    // 0x801F7CF0: bltz        $t9, L_801F7CE0
    if (SIGNED(ctx->r25) < 0) {
        // 0x801F7CF4: nop
    
            goto L_801F7CE0;
    }
    // 0x801F7CF4: nop

L_801F7CF8:
    // 0x801F7CF8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801F7CFC: sb          $t9, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r25;
    // 0x801F7D00: jal         0x80147AA8
    // 0x801F7D04: lbu         $a3, 0x26($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X26);
    LOOKUP_FUNC(0x80147AA8)(rdram, ctx);
        goto after_2;
    // 0x801F7D04: lbu         $a3, 0x26($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X26);
    after_2:
    // 0x801F7D08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F7D0C: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x801F7D10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F7D14: jal         0x80147AF0
    // 0x801F7D18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80147AF0)(rdram, ctx);
        goto after_3;
    // 0x801F7D18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x801F7D1C: lh          $v0, 0x94($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X94);
    // 0x801F7D20: addiu       $t7, $zero, 0x43
    ctx->r15 = ADD32(0, 0X43);
    // 0x801F7D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F7D28: bgez        $v0, L_801F7D3C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801F7D2C: addiu       $t1, $v0, 0x60
        ctx->r9 = ADD32(ctx->r2, 0X60);
            goto L_801F7D3C;
    }
    // 0x801F7D2C: addiu       $t1, $v0, 0x60
    ctx->r9 = ADD32(ctx->r2, 0X60);
    // 0x801F7D30: addiu       $t0, $v0, 0x200
    ctx->r8 = ADD32(ctx->r2, 0X200);
    // 0x801F7D34: b           L_801F7D40
    // 0x801F7D38: sh          $t0, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r8;
        goto L_801F7D40;
    // 0x801F7D38: sh          $t0, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r8;
L_801F7D3C:
    // 0x801F7D3C: sh          $t1, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r9;
L_801F7D40:
    // 0x801F7D40: lh          $v0, 0x94($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X94);
    // 0x801F7D44: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F7D48: addiu       $a1, $a1, 0x7DB4
    ctx->r5 = ADD32(ctx->r5, 0X7DB4);
    // 0x801F7D4C: andi        $t2, $v0, 0x1000
    ctx->r10 = ctx->r2 & 0X1000;
    // 0x801F7D50: beq         $t2, $zero, L_801F7D68
    if (ctx->r10 == 0) {
        // 0x801F7D54: andi        $t5, $v0, 0x1FFF
        ctx->r13 = ctx->r2 & 0X1FFF;
            goto L_801F7D68;
    }
    // 0x801F7D54: andi        $t5, $v0, 0x1FFF
    ctx->r13 = ctx->r2 & 0X1FFF;
    // 0x801F7D58: andi        $t3, $v0, 0x1FFF
    ctx->r11 = ctx->r2 & 0X1FFF;
    // 0x801F7D5C: addiu       $t4, $t3, -0x2000
    ctx->r12 = ADD32(ctx->r11, -0X2000);
    // 0x801F7D60: b           L_801F7D6C
    // 0x801F7D64: sh          $t4, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r12;
        goto L_801F7D6C;
    // 0x801F7D64: sh          $t4, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r12;
L_801F7D68:
    // 0x801F7D68: sh          $t5, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r13;
L_801F7D6C:
    // 0x801F7D6C: lhu         $v0, 0x3C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3C);
    // 0x801F7D70: slti        $v1, $v0, 0x67
    ctx->r3 = SIGNED(ctx->r2) < 0X67 ? 1 : 0;
    // 0x801F7D74: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x801F7D78: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801F7D7C: beq         $v1, $zero, L_801F7DA0
    if (ctx->r3 == 0) {
        // 0x801F7D80: sh          $t6, 0x3C($s0)
        MEM_H(0X3C, ctx->r16) = ctx->r14;
            goto L_801F7DA0;
    }
    // 0x801F7D80: sh          $t6, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r14;
    // 0x801F7D84: addiu       $v0, $zero, -0x1000
    ctx->r2 = ADD32(0, -0X1000);
    // 0x801F7D88: sh          $v0, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r2;
    // 0x801F7D8C: sh          $v0, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r2;
    // 0x801F7D90: sh          $zero, 0x96($s0)
    MEM_H(0X96, ctx->r16) = 0;
    // 0x801F7D94: sh          $v0, 0x98($s0)
    MEM_H(0X98, ctx->r16) = ctx->r2;
    // 0x801F7D98: jal         0x800058DC
    // 0x801F7D9C: sh          $t7, 0x9A($s0)
    MEM_H(0X9A, ctx->r16) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801F7D9C: sh          $t7, 0x9A($s0)
    MEM_H(0X9A, ctx->r16) = ctx->r15;
    after_4:
L_801F7DA0:
    // 0x801F7DA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801F7DA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801F7DA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801F7DAC: jr          $ra
    // 0x801F7DB0: nop

    return;
    // 0x801F7DB0: nop

;}
RECOMP_FUNC void M9_FUN_801f7db4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F7DB4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F7DB8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F7DBC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F7DC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F7DC4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801F7DC8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801F7DCC: jal         0x8001EB64
    // 0x801F7DD0: lh          $a0, 0x90($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X90);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x801F7DD0: lh          $a0, 0x90($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X90);
    after_0:
    // 0x801F7DD4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F7DD8: ldc1        $f2, -0x7320($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X7320);
    // 0x801F7DDC: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801F7DE0: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x801F7DE4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x801F7DE8: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x801F7DEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F7DF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F7DF4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801F7DF8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801F7DFC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801F7E00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F7E04: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x801F7E08: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801F7E0C: mul.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x801F7E10: nop

    // 0x801F7E14: mul.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801F7E18: add.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = ctx->f16.d + ctx->f12.d;
    // 0x801F7E1C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F7E20: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F7E24: nop

    // 0x801F7E28: cvt.w.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_D(ctx->f18.d);
    // 0x801F7E2C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F7E30: nop

    // 0x801F7E34: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801F7E38: beq         $t7, $zero, L_801F7E8C
    if (ctx->r15 == 0) {
        // 0x801F7E3C: nop
    
            goto L_801F7E8C;
    }
    // 0x801F7E3C: nop

    // 0x801F7E40: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801F7E44: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F7E48: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F7E4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F7E50: sub.d       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f18.d - ctx->f4.d;
    // 0x801F7E54: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F7E58: nop

    // 0x801F7E5C: cvt.w.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_D(ctx->f4.d);
    // 0x801F7E60: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F7E64: nop

    // 0x801F7E68: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801F7E6C: bne         $t7, $zero, L_801F7E84
    if (ctx->r15 != 0) {
        // 0x801F7E70: nop
    
            goto L_801F7E84;
    }
    // 0x801F7E70: nop

    // 0x801F7E74: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x801F7E78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F7E7C: b           L_801F7E9C
    // 0x801F7E80: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801F7E9C;
    // 0x801F7E80: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801F7E84:
    // 0x801F7E84: b           L_801F7E9C
    // 0x801F7E88: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801F7E9C;
    // 0x801F7E88: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_801F7E8C:
    // 0x801F7E8C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x801F7E90: nop

    // 0x801F7E94: bltz        $t7, L_801F7E84
    if (SIGNED(ctx->r15) < 0) {
        // 0x801F7E98: nop
    
            goto L_801F7E84;
    }
    // 0x801F7E98: nop

L_801F7E9C:
    // 0x801F7E9C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F7EA0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801F7EA4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F7EA8: ldc1        $f10, -0x7318($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X7318);
    // 0x801F7EAC: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x801F7EB0: sb          $t7, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r15;
    // 0x801F7EB4: lh          $v0, 0x90($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X90);
    // 0x801F7EB8: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x801F7EBC: trunc.w.d   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_D(ctx->f16.d);
    // 0x801F7EC0: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x801F7EC4: nop

    // 0x801F7EC8: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x801F7ECC: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x801F7ED0: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x801F7ED4: beq         $at, $zero, L_801F7EF4
    if (ctx->r1 == 0) {
        // 0x801F7ED8: nop
    
            goto L_801F7EF4;
    }
    // 0x801F7ED8: nop

    // 0x801F7EDC: bgez        $v0, L_801F7EF0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801F7EE0: addiu       $t4, $v0, 0x60
        ctx->r12 = ADD32(ctx->r2, 0X60);
            goto L_801F7EF0;
    }
    // 0x801F7EE0: addiu       $t4, $v0, 0x60
    ctx->r12 = ADD32(ctx->r2, 0X60);
    // 0x801F7EE4: addiu       $t3, $v0, 0x240
    ctx->r11 = ADD32(ctx->r2, 0X240);
    // 0x801F7EE8: b           L_801F7EF4
    // 0x801F7EEC: sh          $t3, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r11;
        goto L_801F7EF4;
    // 0x801F7EEC: sh          $t3, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r11;
L_801F7EF0:
    // 0x801F7EF0: sh          $t4, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r12;
L_801F7EF4:
    // 0x801F7EF4: jal         0x8001EB64
    // 0x801F7EF8: lh          $a0, 0x92($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X92);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x801F7EF8: lh          $a0, 0x92($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X92);
    after_1:
    // 0x801F7EFC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F7F00: ldc1        $f2, -0x7310($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X7310);
    // 0x801F7F04: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801F7F08: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x801F7F0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F7F10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F7F14: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801F7F18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F7F1C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801F7F20: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801F7F24: mul.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x801F7F28: nop

    // 0x801F7F2C: mul.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801F7F30: add.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = ctx->f16.d + ctx->f12.d;
    // 0x801F7F34: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801F7F38: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F7F3C: nop

    // 0x801F7F40: cvt.w.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_D(ctx->f18.d);
    // 0x801F7F44: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F7F48: nop

    // 0x801F7F4C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801F7F50: beq         $t6, $zero, L_801F7FA4
    if (ctx->r14 == 0) {
        // 0x801F7F54: nop
    
            goto L_801F7FA4;
    }
    // 0x801F7F54: nop

    // 0x801F7F58: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801F7F5C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801F7F60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F7F64: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F7F68: sub.d       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f18.d - ctx->f4.d;
    // 0x801F7F6C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801F7F70: nop

    // 0x801F7F74: cvt.w.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_D(ctx->f4.d);
    // 0x801F7F78: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801F7F7C: nop

    // 0x801F7F80: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801F7F84: bne         $t6, $zero, L_801F7F9C
    if (ctx->r14 != 0) {
        // 0x801F7F88: nop
    
            goto L_801F7F9C;
    }
    // 0x801F7F88: nop

    // 0x801F7F8C: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x801F7F90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F7F94: b           L_801F7FB4
    // 0x801F7F98: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801F7FB4;
    // 0x801F7F98: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801F7F9C:
    // 0x801F7F9C: b           L_801F7FB4
    // 0x801F7FA0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801F7FB4;
    // 0x801F7FA0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_801F7FA4:
    // 0x801F7FA4: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x801F7FA8: nop

    // 0x801F7FAC: bltz        $t6, L_801F7F9C
    if (SIGNED(ctx->r14) < 0) {
        // 0x801F7FB0: nop
    
            goto L_801F7F9C;
    }
    // 0x801F7FB0: nop

L_801F7FB4:
    // 0x801F7FB4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801F7FB8: sb          $t6, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r14;
    // 0x801F7FBC: jal         0x8001EB64
    // 0x801F7FC0: lh          $a0, 0x94($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X94);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x801F7FC0: lh          $a0, 0x94($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X94);
    after_2:
    // 0x801F7FC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F7FC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F7FCC: lui         $at, 0x4069
    ctx->r1 = S32(0X4069 << 16);
    // 0x801F7FD0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F7FD4: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x801F7FD8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F7FDC: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x801F7FE0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801F7FE4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801F7FE8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801F7FEC: mul.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f20.d);
    // 0x801F7FF0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801F7FF4: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x801F7FF8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801F7FFC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801F8000: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801F8004: nop

    // 0x801F8008: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x801F800C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801F8010: nop

    // 0x801F8014: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801F8018: beq         $t8, $zero, L_801F8068
    if (ctx->r24 == 0) {
        // 0x801F801C: lui         $at, 0x41E0
        ctx->r1 = S32(0X41E0 << 16);
            goto L_801F8068;
    }
    // 0x801F801C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801F8020: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801F8024: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801F8028: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801F802C: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x801F8030: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801F8034: nop

    // 0x801F8038: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x801F803C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801F8040: nop

    // 0x801F8044: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801F8048: bne         $t8, $zero, L_801F8060
    if (ctx->r24 != 0) {
        // 0x801F804C: nop
    
            goto L_801F8060;
    }
    // 0x801F804C: nop

    // 0x801F8050: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x801F8054: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F8058: b           L_801F8078
    // 0x801F805C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_801F8078;
    // 0x801F805C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_801F8060:
    // 0x801F8060: b           L_801F8078
    // 0x801F8064: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_801F8078;
    // 0x801F8064: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_801F8068:
    // 0x801F8068: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x801F806C: nop

    // 0x801F8070: bltz        $t8, L_801F8060
    if (SIGNED(ctx->r24) < 0) {
        // 0x801F8074: nop
    
            goto L_801F8060;
    }
    // 0x801F8074: nop

L_801F8078:
    // 0x801F8078: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801F807C: sb          $t8, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r24;
    // 0x801F8080: jal         0x8001EB64
    // 0x801F8084: lh          $a0, 0x96($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X96);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x801F8084: lh          $a0, 0x96($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X96);
    after_3:
    // 0x801F8088: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F808C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F8090: lui         $at, 0x4054
    ctx->r1 = S32(0X4054 << 16);
    // 0x801F8094: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801F8098: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x801F809C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F80A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801F80A4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801F80A8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801F80AC: mul.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x801F80B0: nop

    // 0x801F80B4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801F80B8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801F80BC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801F80C0: nop

    // 0x801F80C4: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x801F80C8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801F80CC: nop

    // 0x801F80D0: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801F80D4: beq         $t0, $zero, L_801F8124
    if (ctx->r8 == 0) {
        // 0x801F80D8: nop
    
            goto L_801F8124;
    }
    // 0x801F80D8: nop

    // 0x801F80DC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801F80E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F80E4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801F80E8: sub.d       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f10.d - ctx->f16.d;
    // 0x801F80EC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801F80F0: nop

    // 0x801F80F4: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x801F80F8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801F80FC: nop

    // 0x801F8100: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801F8104: bne         $t0, $zero, L_801F811C
    if (ctx->r8 != 0) {
        // 0x801F8108: nop
    
            goto L_801F811C;
    }
    // 0x801F8108: nop

    // 0x801F810C: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x801F8110: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F8114: b           L_801F8134
    // 0x801F8118: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_801F8134;
    // 0x801F8118: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_801F811C:
    // 0x801F811C: b           L_801F8134
    // 0x801F8120: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_801F8134;
    // 0x801F8120: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_801F8124:
    // 0x801F8124: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x801F8128: nop

    // 0x801F812C: bltz        $t0, L_801F811C
    if (SIGNED(ctx->r8) < 0) {
        // 0x801F8130: nop
    
            goto L_801F811C;
    }
    // 0x801F8130: nop

L_801F8134:
    // 0x801F8134: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801F8138: sb          $t0, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r8;
    // 0x801F813C: jal         0x8001EB64
    // 0x801F8140: lh          $a0, 0x98($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X98);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_4;
    // 0x801F8140: lh          $a0, 0x98($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X98);
    after_4:
    // 0x801F8144: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F8148: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F814C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F8150: ldc1        $f10, -0x7308($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X7308);
    // 0x801F8154: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x801F8158: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801F815C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801F8160: addiu       $t3, $zero, 0x46
    ctx->r11 = ADD32(0, 0X46);
    // 0x801F8164: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801F8168: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F816C: mul.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x801F8170: nop

    // 0x801F8174: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801F8178: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801F817C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801F8180: nop

    // 0x801F8184: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x801F8188: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801F818C: nop

    // 0x801F8190: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x801F8194: beq         $t2, $zero, L_801F81E4
    if (ctx->r10 == 0) {
        // 0x801F8198: nop
    
            goto L_801F81E4;
    }
    // 0x801F8198: nop

    // 0x801F819C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801F81A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F81A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801F81A8: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x801F81AC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801F81B0: nop

    // 0x801F81B4: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x801F81B8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801F81BC: nop

    // 0x801F81C0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x801F81C4: bne         $t2, $zero, L_801F81DC
    if (ctx->r10 != 0) {
        // 0x801F81C8: nop
    
            goto L_801F81DC;
    }
    // 0x801F81C8: nop

    // 0x801F81CC: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x801F81D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F81D4: b           L_801F81F4
    // 0x801F81D8: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_801F81F4;
    // 0x801F81D8: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_801F81DC:
    // 0x801F81DC: b           L_801F81F4
    // 0x801F81E0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_801F81F4;
    // 0x801F81E0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_801F81E4:
    // 0x801F81E4: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x801F81E8: nop

    // 0x801F81EC: bltz        $t2, L_801F81DC
    if (SIGNED(ctx->r10) < 0) {
        // 0x801F81F0: nop
    
            goto L_801F81DC;
    }
    // 0x801F81F0: nop

L_801F81F4:
    // 0x801F81F4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801F81F8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801F81FC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F8200: ldc1        $f8, -0x7300($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X7300);
    // 0x801F8204: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x801F8208: sb          $t2, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r10;
    // 0x801F820C: lh          $t8, 0x90($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X90);
    // 0x801F8210: addiu       $t3, $zero, -0x6E
    ctx->r11 = ADD32(0, -0X6E);
    // 0x801F8214: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x801F8218: trunc.w.d   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x801F821C: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x801F8220: nop

    // 0x801F8224: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x801F8228: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x801F822C: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801F8230: beql        $at, $zero, L_801F824C
    if (ctx->r1 == 0) {
        // 0x801F8234: lh          $t0, 0x9A($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X9A);
            goto L_801F824C;
    }
    goto skip_0;
    // 0x801F8234: lh          $t0, 0x9A($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X9A);
    skip_0:
    // 0x801F8238: lh          $v0, 0x98($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X98);
    // 0x801F823C: bgez        $v0, L_801F8248
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801F8240: addiu       $t9, $v0, 0x60
        ctx->r25 = ADD32(ctx->r2, 0X60);
            goto L_801F8248;
    }
    // 0x801F8240: addiu       $t9, $v0, 0x60
    ctx->r25 = ADD32(ctx->r2, 0X60);
    // 0x801F8244: sh          $t9, 0x98($s0)
    MEM_H(0X98, ctx->r16) = ctx->r25;
L_801F8248:
    // 0x801F8248: lh          $t0, 0x9A($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X9A);
L_801F824C:
    // 0x801F824C: addiu       $t1, $t0, -0x5
    ctx->r9 = ADD32(ctx->r8, -0X5);
    // 0x801F8250: sh          $t1, 0x9A($s0)
    MEM_H(0X9A, ctx->r16) = ctx->r9;
    // 0x801F8254: lh          $t2, 0x9A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X9A);
    // 0x801F8258: slti        $at, $t2, -0x6E
    ctx->r1 = SIGNED(ctx->r10) < -0X6E ? 1 : 0;
    // 0x801F825C: beql        $at, $zero, L_801F826C
    if (ctx->r1 == 0) {
        // 0x801F8260: lbu         $a1, 0x2F($sp)
        ctx->r5 = MEM_BU(ctx->r29, 0X2F);
            goto L_801F826C;
    }
    goto skip_1;
    // 0x801F8260: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    skip_1:
    // 0x801F8264: sh          $t3, 0x9A($s0)
    MEM_H(0X9A, ctx->r16) = ctx->r11;
    // 0x801F8268: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
L_801F826C:
    // 0x801F826C: lbu         $a2, 0x2E($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2E);
    // 0x801F8270: jal         0x80147AA8
    // 0x801F8274: lbu         $a3, 0x2D($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2D);
    LOOKUP_FUNC(0x80147AA8)(rdram, ctx);
        goto after_5;
    // 0x801F8274: lbu         $a3, 0x2D($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2D);
    after_5:
    // 0x801F8278: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F827C: lbu         $a1, 0x2C($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2C);
    // 0x801F8280: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    // 0x801F8284: jal         0x80147AF0
    // 0x801F8288: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80147AF0)(rdram, ctx);
        goto after_6;
    // 0x801F8288: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x801F828C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F8290: lb          $a1, 0x9B($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X9B);
    // 0x801F8294: addiu       $a2, $zero, -0x64
    ctx->r6 = ADD32(0, -0X64);
    // 0x801F8298: jal         0x80147C28
    // 0x801F829C: addiu       $a3, $zero, -0x43
    ctx->r7 = ADD32(0, -0X43);
    LOOKUP_FUNC(0x80147C28)(rdram, ctx);
        goto after_7;
    // 0x801F829C: addiu       $a3, $zero, -0x43
    ctx->r7 = ADD32(0, -0X43);
    after_7:
    // 0x801F82A0: lh          $t4, 0x98($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X98);
    // 0x801F82A4: slti        $at, $t4, -0x7FF
    ctx->r1 = SIGNED(ctx->r12) < -0X7FF ? 1 : 0;
    // 0x801F82A8: bnel        $at, $zero, L_801F82C4
    if (ctx->r1 != 0) {
        // 0x801F82AC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801F82C4;
    }
    goto skip_2;
    // 0x801F82AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x801F82B0: jal         0x801FA2E0
    // 0x801F82B4: nop

    LOOKUP_FUNC(0x801FA2E0)(rdram, ctx);
        goto after_8;
    // 0x801F82B4: nop

    after_8:
    // 0x801F82B8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801F82BC: sh          $t5, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r13;
    // 0x801F82C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F82C4:
    // 0x801F82C4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801F82C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F82CC: jr          $ra
    // 0x801F82D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801F82D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f82d4(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f82d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F82D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F82D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F82DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F82E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F82E4: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801F82E8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801F82EC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F82F0: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801F82F4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801F82F8: beq         $v1, $zero, L_801F831C
    if (ctx->r3 == 0) {
        // 0x801F82FC: sh          $t6, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r14;
            goto L_801F831C;
    }
    // 0x801F82FC: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x801F8300: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F8304: sw          $zero, -0x501C($at)
    MEM_W(-0X501C, ctx->r1) = 0;
    // 0x801F8308: lw          $a0, -0x5020($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5020);
    // 0x801F830C: jal         0x801479A8
    // 0x801F8310: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801479A8)(rdram, ctx);
        goto after_0;
    // 0x801F8310: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F8314: jal         0x80005700
    // 0x801F8318: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801F8318: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_801F831C:
    // 0x801F831C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F8320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F8324: jr          $ra
    // 0x801F8328: nop

    return;
    // 0x801F8328: nop

;}
RECOMP_FUNC void M9_FUN_801f832c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F832C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F8330: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F8334: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801F8338: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F833C: jal         0x801C3B3C
    // 0x801F8340: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_0;
    // 0x801F8340: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F8344: bnel        $v0, $zero, L_801F83A8
    if (ctx->r2 != 0) {
        // 0x801F8348: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801F83A8;
    }
    goto skip_0;
    // 0x801F8348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801F834C: lbu         $t6, 0xAE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F8350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F8354: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F8358: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801F835C: bgez        $t6, L_801F8370
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801F8360: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F8370;
    }
    // 0x801F8360: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F8364: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F8368: nop

    // 0x801F836C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F8370:
    // 0x801F8370: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F8374: jal         0x801F4170
    // 0x801F8378: nop

    LOOKUP_FUNC(0x801F4170)(rdram, ctx);
        goto after_1;
    // 0x801F8378: nop

    after_1:
    // 0x801F837C: beql        $v0, $zero, L_801F83A8
    if (ctx->r2 == 0) {
        // 0x801F8380: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801F83A8;
    }
    goto skip_1;
    // 0x801F8380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801F8384: jal         0x801F5230
    // 0x801F8388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_2;
    // 0x801F8388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801F838C: jal         0x801F5210
    // 0x801F8390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5210)(rdram, ctx);
        goto after_3;
    // 0x801F8390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801F8394: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F8398: addiu       $a1, $a1, -0x7C48
    ctx->r5 = ADD32(ctx->r5, -0X7C48);
    // 0x801F839C: jal         0x800058DC
    // 0x801F83A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801F83A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801F83A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801F83A8:
    // 0x801F83A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801F83AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F83B0: jr          $ra
    // 0x801F83B4: nop

    return;
    // 0x801F83B4: nop

;}
RECOMP_FUNC void M9_FUN_801f83b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F83B8: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x801F83BC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801F83C0: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x801F83C4: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x801F83C8: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801F83CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F83D0: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x801F83D4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x801F83D8: jal         0x8013A334
    // 0x801F83DC: sw          $a2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_0;
    // 0x801F83DC: sw          $a2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801F83E0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F83E4: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x801F83E8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F83EC: lwc1        $f0, -0x72F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72F8);
    // 0x801F83F0: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801F83F4: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801F83F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F83FC: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F8400: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x801F8404: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801F8408: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F840C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F8410: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801F8414: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801F8418: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801F841C: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801F8420: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801F8424: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x801F8428: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801F842C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801F8430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F8434: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801F8438: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801F843C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801F8440: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x801F8444: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801F8448: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801F844C: jal         0x801F3C90
    // 0x801F8450: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801F3C90)(rdram, ctx);
        goto after_1;
    // 0x801F8450: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x801F8454: beq         $v0, $zero, L_801F864C
    if (ctx->r2 == 0) {
        // 0x801F8458: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801F864C;
    }
    // 0x801F8458: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F845C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801F8460: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x801F8464: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x801F8468: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F846C: sh          $t7, 0x78($t8)
    MEM_H(0X78, ctx->r24) = ctx->r15;
    // 0x801F8470: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801F8474: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801F8478: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801F847C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x801F8480: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x801F8484: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801F8488: jal         0x801F4620
    // 0x801F848C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801F4620)(rdram, ctx);
        goto after_2;
    // 0x801F848C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x801F8490: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801F8494: addiu       $t1, $sp, 0x78
    ctx->r9 = ADD32(ctx->r29, 0X78);
    // 0x801F8498: addiu       $t2, $sp, 0x7C
    ctx->r10 = ADD32(ctx->r29, 0X7C);
    // 0x801F849C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F84A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F84A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F84A8: lhu         $a1, 0x12($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X12);
    // 0x801F84AC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801F84B0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801F84B4: jal         0x80130AA0
    // 0x801F84B8: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    LOOKUP_FUNC(0x80130AA0)(rdram, ctx);
        goto after_3;
    // 0x801F84B8: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    after_3:
    // 0x801F84BC: addiu       $t3, $sp, 0x78
    ctx->r11 = ADD32(ctx->r29, 0X78);
    // 0x801F84C0: addiu       $t4, $sp, 0x7C
    ctx->r12 = ADD32(ctx->r29, 0X7C);
    // 0x801F84C4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801F84C8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801F84CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F84D0: addiu       $a1, $zero, 0xD55
    ctx->r5 = ADD32(0, 0XD55);
    // 0x801F84D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F84D8: jal         0x80130AA0
    // 0x801F84DC: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    LOOKUP_FUNC(0x80130AA0)(rdram, ctx);
        goto after_4;
    // 0x801F84DC: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    after_4:
    // 0x801F84E0: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x801F84E4: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x801F84E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F84EC: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x801F84F0: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801F84F4: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801F84F8: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F84FC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F8500: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801F8504: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F8508: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801F850C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801F8510: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801F8514: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801F8518: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801F851C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801F8520: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x801F8524: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F8528: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x801F852C: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x801F8530: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801F8534: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F8538: lwc1        $f18, 0xC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC);
    // 0x801F853C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x801F8540: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801F8544: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801F8548: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801F854C: jal         0x801F4620
    // 0x801F8550: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801F4620)(rdram, ctx);
        goto after_5;
    // 0x801F8550: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x801F8554: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801F8558: addiu       $t0, $sp, 0x6C
    ctx->r8 = ADD32(ctx->r29, 0X6C);
    // 0x801F855C: addiu       $t1, $sp, 0x70
    ctx->r9 = ADD32(ctx->r29, 0X70);
    // 0x801F8560: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F8564: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F8568: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F856C: lhu         $a1, 0x12($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X12);
    // 0x801F8570: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801F8574: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801F8578: jal         0x80130AA0
    // 0x801F857C: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    LOOKUP_FUNC(0x80130AA0)(rdram, ctx);
        goto after_6;
    // 0x801F857C: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    after_6:
    // 0x801F8580: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801F8584: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801F8588: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801F858C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801F8590: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F8594: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F8598: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x801F859C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801F85A0: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F85A4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801F85A8: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801F85AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801F85B0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801F85B4: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x801F85B8: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801F85BC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801F85C0: addiu       $a0, $a0, -0x7630
    ctx->r4 = ADD32(ctx->r4, -0X7630);
    // 0x801F85C4: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F85C8: addiu       $a1, $zero, 0x780
    ctx->r5 = ADD32(0, 0X780);
    // 0x801F85CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801F85D0: lwc1        $f4, 0x8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X8);
    // 0x801F85D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F85D8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801F85DC: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801F85E0: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x801F85E4: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801F85E8: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F85EC: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x801F85F0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801F85F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F85F8: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801F85FC: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801F8600: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801F8604: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x801F8608: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x801F860C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x801F8610: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x801F8614: swc1        $f20, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f20.u32l;
    // 0x801F8618: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801F861C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x801F8620: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801F8624: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801F8628: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801F862C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x801F8630: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x801F8634: jal         0x8011AAF4
    // 0x801F8638: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_7;
    // 0x801F8638: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x801F863C: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F8640: addiu       $a1, $a1, -0x7998
    ctx->r5 = ADD32(ctx->r5, -0X7998);
    // 0x801F8644: jal         0x800058DC
    // 0x801F8648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801F8648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_801F864C:
    // 0x801F864C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x801F8650: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x801F8654: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x801F8658: jr          $ra
    // 0x801F865C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x801F865C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f8660(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f8660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8660: jr          $ra
    // 0x801F8664: nop

    return;
    // 0x801F8664: nop

;}
RECOMP_FUNC void M9_FUN_801f8668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8668: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801F866C: lui         $t6, 0x8021
    ctx->r14 = S32(0X8021 << 16);
    // 0x801F8670: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801F8674: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801F8678: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801F867C: addiu       $t6, $t6, 0x6F0C
    ctx->r14 = ADD32(ctx->r14, 0X6F0C);
    // 0x801F8680: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801F8684: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801F8688: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F868C: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x801F8690: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x801F8694: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x801F8698: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F869C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F86A0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801F86A4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801F86A8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x801F86AC: jal         0x8012CE9C
    // 0x801F86B0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x801F86B0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x801F86B4: bne         $v0, $zero, L_801F874C
    if (ctx->r2 != 0) {
        // 0x801F86B8: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_801F874C;
    }
    // 0x801F86B8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x801F86BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F86C0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801F86C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F86C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801F86CC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801F86D0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801F86D4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801F86D8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801F86DC: jal         0x801F4620
    // 0x801F86E0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801F4620)(rdram, ctx);
        goto after_1;
    // 0x801F86E0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801F86E4: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801F86E8: addiu       $t2, $sp, 0x34
    ctx->r10 = ADD32(ctx->r29, 0X34);
    // 0x801F86EC: addiu       $t3, $sp, 0x38
    ctx->r11 = ADD32(ctx->r29, 0X38);
    // 0x801F86F0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F86F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F86F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F86FC: lhu         $a1, 0x12($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0X12);
    // 0x801F8700: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801F8704: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801F8708: jal         0x80130AA0
    // 0x801F870C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    LOOKUP_FUNC(0x80130AA0)(rdram, ctx);
        goto after_2;
    // 0x801F870C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x801F8710: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801F8714: sb          $t4, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r12;
    // 0x801F8718: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801F871C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801F8720: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F8724: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x801F8728: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801F872C: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x801F8730: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F8734: sh          $t5, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r13;
    // 0x801F8738: addiu       $a1, $a1, -0x78A0
    ctx->r5 = ADD32(ctx->r5, -0X78A0);
    // 0x801F873C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F8740: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x801F8744: jal         0x800058DC
    // 0x801F8748: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801F8748: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    after_3:
L_801F874C:
    // 0x801F874C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801F8750: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801F8754: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801F8758: jr          $ra
    // 0x801F875C: nop

    return;
    // 0x801F875C: nop

;}
RECOMP_FUNC void M9_FUN_801f8760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8760: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x801F8764: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801F8768: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x801F876C: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x801F8770: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x801F8774: lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3C);
    // 0x801F8778: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F877C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801F8780: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801F8784: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801F8788: beq         $v1, $zero, L_801F88EC
    if (ctx->r3 == 0) {
        // 0x801F878C: sh          $t6, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r14;
            goto L_801F88EC;
    }
    // 0x801F878C: sh          $t6, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r14;
    // 0x801F8790: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801F8794: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F8798: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x801F879C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801F87A0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801F87A4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801F87A8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801F87AC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x801F87B0: jal         0x801F4620
    // 0x801F87B4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801F4620)(rdram, ctx);
        goto after_0;
    // 0x801F87B4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801F87B8: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801F87BC: addiu       $t9, $sp, 0x78
    ctx->r25 = ADD32(ctx->r29, 0X78);
    // 0x801F87C0: addiu       $t0, $sp, 0x7C
    ctx->r8 = ADD32(ctx->r29, 0X7C);
    // 0x801F87C4: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801F87C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F87CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F87D0: lhu         $a1, 0x12($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X12);
    // 0x801F87D4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801F87D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801F87DC: jal         0x80130AA0
    // 0x801F87E0: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    LOOKUP_FUNC(0x80130AA0)(rdram, ctx);
        goto after_1;
    // 0x801F87E0: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    after_1:
    // 0x801F87E4: addiu       $t1, $sp, 0x78
    ctx->r9 = ADD32(ctx->r29, 0X78);
    // 0x801F87E8: addiu       $t2, $sp, 0x7C
    ctx->r10 = ADD32(ctx->r29, 0X7C);
    // 0x801F87EC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801F87F0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801F87F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F87F8: ori         $a1, $zero, 0xFFBC
    ctx->r5 = 0 | 0XFFBC;
    // 0x801F87FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8800: jal         0x80130AA0
    // 0x801F8804: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    LOOKUP_FUNC(0x80130AA0)(rdram, ctx);
        goto after_2;
    // 0x801F8804: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    after_2:
    // 0x801F8808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F880C: jal         0x801F4208
    // 0x801F8810: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    LOOKUP_FUNC(0x801F4208)(rdram, ctx);
        goto after_3;
    // 0x801F8810: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_3:
    // 0x801F8814: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801F8818: lw          $t3, -0x4330($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4330);
    // 0x801F881C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x801F8820: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801F8824: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801F8828: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x801F882C: lwc1        $f6, 0x8($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X8);
    // 0x801F8830: jal         0x80147734
    // 0x801F8834: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80147734)(rdram, ctx);
        goto after_4;
    // 0x801F8834: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801F8838: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F883C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801F8840: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801F8844: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F8848: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801F884C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801F8850: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F8854: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801F8858: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801F885C: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801F8860: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x801F8864: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801F8868: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801F886C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801F8870: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801F8874: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F8878: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801F887C: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801F8880: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F8884: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801F8888: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801F888C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801F8890: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x801F8894: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x801F8898: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801F889C: addiu       $a0, $a0, -0x75F4
    ctx->r4 = ADD32(ctx->r4, -0X75F4);
    // 0x801F88A0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x801F88A4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801F88A8: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x801F88AC: addiu       $a1, $zero, 0x7B2
    ctx->r5 = ADD32(0, 0X7B2);
    // 0x801F88B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801F88B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F88B8: swc1        $f20, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f20.u32l;
    // 0x801F88BC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801F88C0: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801F88C4: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x801F88C8: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x801F88CC: jal         0x8011AAF4
    // 0x801F88D0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_5;
    // 0x801F88D0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x801F88D4: jal         0x801479A8
    // 0x801F88D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801479A8)(rdram, ctx);
        goto after_6;
    // 0x801F88D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801F88DC: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F88E0: addiu       $a1, $a1, -0x7700
    ctx->r5 = ADD32(ctx->r5, -0X7700);
    // 0x801F88E4: jal         0x800058DC
    // 0x801F88E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801F88E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_801F88EC:
    // 0x801F88EC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x801F88F0: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x801F88F4: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x801F88F8: jr          $ra
    // 0x801F88FC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x801F88FC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f8900(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f8900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8900: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F8904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F8908: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801F890C: lw          $a3, 0x5C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X5C);
    // 0x801F8910: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801F8914: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801F8918: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801F891C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x801F8920: jal         0x80010550
    // 0x801F8924: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x801F8924: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x801F8928: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x801F892C: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F8930: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801F8934: lw          $t6, 0x30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X30);
    // 0x801F8938: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801F893C: addiu       $a1, $a1, -0x768C
    ctx->r5 = ADD32(ctx->r5, -0X768C);
    // 0x801F8940: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x801F8944: beq         $t7, $zero, L_801F8964
    if (ctx->r15 == 0) {
        // 0x801F8948: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_801F8964;
    }
    // 0x801F8948: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801F894C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F8950: sh          $t8, 0x78($a3)
    MEM_H(0X78, ctx->r7) = ctx->r24;
    // 0x801F8954: sh          $zero, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = 0;
    // 0x801F8958: swc1        $f0, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f0.u32l;
    // 0x801F895C: jal         0x800058DC
    // 0x801F8960: swc1        $f0, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f0.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801F8960: swc1        $f0, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f0.u32l;
    after_1:
L_801F8964:
    // 0x801F8964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F8968: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F896C: jr          $ra
    // 0x801F8970: nop

    return;
    // 0x801F8970: nop

;}
RECOMP_FUNC void M9_FUN_801f8974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8974: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F8978: lui         $t6, 0x8021
    ctx->r14 = S32(0X8021 << 16);
    // 0x801F897C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801F8980: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801F8984: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801F8988: addiu       $t6, $t6, 0x6F18
    ctx->r14 = ADD32(ctx->r14, 0X6F18);
    // 0x801F898C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801F8990: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801F8994: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F8998: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x801F899C: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x801F89A0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F89A4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F89A8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F89AC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801F89B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801F89B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801F89B8: jal         0x8012CE9C
    // 0x801F89BC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_0;
    // 0x801F89BC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x801F89C0: bnel        $v0, $zero, L_801F8A2C
    if (ctx->r2 != 0) {
        // 0x801F89C4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801F8A2C;
    }
    goto skip_0;
    // 0x801F89C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801F89C8: lhu         $t9, 0x70($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X70);
    // 0x801F89CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801F89D0: bnel        $t9, $at, L_801F89E4
    if (ctx->r25 != ctx->r1) {
        // 0x801F89D4: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_801F89E4;
    }
    goto skip_1;
    // 0x801F89D4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x801F89D8: jal         0x80020744
    // 0x801F89DC: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x801F89DC: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_1:
    // 0x801F89E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_801F89E4:
    // 0x801F89E4: jal         0x80010550
    // 0x801F89E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_2;
    // 0x801F89E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x801F89EC: lhu         $t0, 0x3C($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X3C);
    // 0x801F89F0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801F89F4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801F89F8: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x801F89FC: bne         $v1, $at, L_801F8A10
    if (ctx->r3 != ctx->r1) {
        // 0x801F8A00: sh          $t1, 0x3C($s0)
        MEM_H(0X3C, ctx->r16) = ctx->r9;
            goto L_801F8A10;
    }
    // 0x801F8A00: sh          $t1, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r9;
    // 0x801F8A04: jal         0x801FA2E0
    // 0x801F8A08: nop

    LOOKUP_FUNC(0x801FA2E0)(rdram, ctx);
        goto after_3;
    // 0x801F8A08: nop

    after_3:
    // 0x801F8A0C: lhu         $v1, 0x3C($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X3C);
L_801F8A10:
    // 0x801F8A10: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x801F8A14: bne         $v1, $at, L_801F8A28
    if (ctx->r3 != ctx->r1) {
        // 0x801F8A18: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F8A28;
    }
    // 0x801F8A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F8A1C: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F8A20: jal         0x800058DC
    // 0x801F8A24: addiu       $a1, $a1, 0x5F5C
    ctx->r5 = ADD32(ctx->r5, 0X5F5C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801F8A24: addiu       $a1, $a1, 0x5F5C
    ctx->r5 = ADD32(ctx->r5, 0X5F5C);
    after_4:
L_801F8A28:
    // 0x801F8A28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801F8A2C:
    // 0x801F8A2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801F8A30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801F8A34: jr          $ra
    // 0x801F8A38: nop

    return;
    // 0x801F8A38: nop

;}
RECOMP_FUNC void M9_FUN_801f8a3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8A3C: jr          $ra
    // 0x801F8A40: nop

    return;
    // 0x801F8A40: nop

;}
RECOMP_FUNC void M9_FUN_801f8a44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8A44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F8A48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F8A4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F8A50: jal         0x801C3B3C
    // 0x801F8A54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_0;
    // 0x801F8A54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F8A58: bne         $v0, $zero, L_801F8AD8
    if (ctx->r2 != 0) {
        // 0x801F8A5C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801F8AD8;
    }
    // 0x801F8A5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801F8A60: jal         0x801F3FFC
    // 0x801F8A64: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_1;
    // 0x801F8A64: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    after_1:
    // 0x801F8A68: beql        $v0, $zero, L_801F8ADC
    if (ctx->r2 == 0) {
        // 0x801F8A6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F8ADC;
    }
    goto skip_0;
    // 0x801F8A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801F8A70: jal         0x801F5230
    // 0x801F8A74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_2;
    // 0x801F8A74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801F8A78: jal         0x8012C6B4
    // 0x801F8A7C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801F8A7C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_3:
    // 0x801F8A80: addiu       $t6, $v0, -0x5
    ctx->r14 = ADD32(ctx->r2, -0X5);
    // 0x801F8A84: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801F8A88: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F8A8C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801F8A90: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F8A94: jal         0x8012C6B4
    // 0x801F8A98: swc1        $f6, -0x4FD8($at)
    MEM_W(-0X4FD8, ctx->r1) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801F8A98: swc1        $f6, -0x4FD8($at)
    MEM_W(-0X4FD8, ctx->r1) = ctx->f6.u32l;
    after_4:
    // 0x801F8A9C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801F8AA0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F8AA4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801F8AA8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801F8AAC: jal         0x8012C6B4
    // 0x801F8AB0: swc1        $f10, -0x4FD4($at)
    MEM_W(-0X4FD4, ctx->r1) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x801F8AB0: swc1        $f10, -0x4FD4($at)
    MEM_W(-0X4FD4, ctx->r1) = ctx->f10.u32l;
    after_5:
    // 0x801F8AB4: addiu       $t7, $v0, -0x5
    ctx->r15 = ADD32(ctx->r2, -0X5);
    // 0x801F8AB8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x801F8ABC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F8AC0: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F8AC4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801F8AC8: addiu       $a1, $a1, -0x7518
    ctx->r5 = ADD32(ctx->r5, -0X7518);
    // 0x801F8ACC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801F8AD0: jal         0x800058DC
    // 0x801F8AD4: swc1        $f18, -0x4FD0($at)
    MEM_W(-0X4FD0, ctx->r1) = ctx->f18.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801F8AD4: swc1        $f18, -0x4FD0($at)
    MEM_W(-0X4FD0, ctx->r1) = ctx->f18.u32l;
    after_6:
L_801F8AD8:
    // 0x801F8AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801F8ADC:
    // 0x801F8ADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F8AE0: jr          $ra
    // 0x801F8AE4: nop

    return;
    // 0x801F8AE4: nop

;}
RECOMP_FUNC void M9_FUN_801f8ae8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8AE8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801F8AEC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801F8AF0: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801F8AF4: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x801F8AF8: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801F8AFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F8B00: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x801F8B04: jal         0x8012A94C
    // 0x801F8B08: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8012A94C)(rdram, ctx);
        goto after_0;
    // 0x801F8B08: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    after_0:
    // 0x801F8B0C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x801F8B10: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x801F8B14: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x801F8B18: jal         0x8013A334
    // 0x801F8B1C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_1;
    // 0x801F8B1C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_1:
    // 0x801F8B20: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801F8B24: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x801F8B28: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801F8B2C: jal         0x801F467C
    // 0x801F8B30: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x801F467C)(rdram, ctx);
        goto after_2;
    // 0x801F8B30: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_2:
    // 0x801F8B34: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x801F8B38: jal         0x80147768
    // 0x801F8B3C: lui         $a1, 0x41C8
    ctx->r5 = S32(0X41C8 << 16);
    LOOKUP_FUNC(0x80147768)(rdram, ctx);
        goto after_3;
    // 0x801F8B3C: lui         $a1, 0x41C8
    ctx->r5 = S32(0X41C8 << 16);
    after_3:
    // 0x801F8B40: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F8B44: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F8B48: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801F8B4C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801F8B50: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801F8B54: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801F8B58: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801F8B5C: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x801F8B60: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x801F8B64: addiu       $v1, $v1, -0x4FD8
    ctx->r3 = ADD32(ctx->r3, -0X4FD8);
    // 0x801F8B68: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F8B6C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F8B70: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801F8B74: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F8B78: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F8B7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F8B80: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801F8B84: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801F8B88: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801F8B8C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801F8B90: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801F8B94: addiu       $a0, $a0, -0x75B8
    ctx->r4 = ADD32(ctx->r4, -0X75B8);
    // 0x801F8B98: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801F8B9C: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F8BA0: addiu       $a1, $zero, 0x807
    ctx->r5 = ADD32(0, 0X807);
    // 0x801F8BA4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801F8BA8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801F8BAC: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801F8BB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F8BB4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801F8BB8: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F8BBC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801F8BC0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801F8BC4: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801F8BC8: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x801F8BCC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801F8BD0: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801F8BD4: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801F8BD8: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x801F8BDC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F8BE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F8BE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801F8BE8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801F8BEC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801F8BF0: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801F8BF4: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x801F8BF8: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x801F8BFC: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x801F8C00: jal         0x8011AAF4
    // 0x801F8C04: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_4;
    // 0x801F8C04: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x801F8C08: bnel        $v0, $zero, L_801F8C40
    if (ctx->r2 != 0) {
        // 0x801F8C0C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801F8C40;
    }
    goto skip_0;
    // 0x801F8C0C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x801F8C10: jal         0x801FA5C4
    // 0x801F8C14: nop

    LOOKUP_FUNC(0x801FA5C4)(rdram, ctx);
        goto after_5;
    // 0x801F8C14: nop

    after_5:
    // 0x801F8C18: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x801F8C1C: sh          $t3, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r11;
    // 0x801F8C20: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x801F8C24: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801F8C28: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F8C2C: addiu       $a1, $a1, -0x73B0
    ctx->r5 = ADD32(ctx->r5, -0X73B0);
    // 0x801F8C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F8C34: jal         0x800058DC
    // 0x801F8C38: sh          $t4, 0x78($t5)
    MEM_H(0X78, ctx->r13) = ctx->r12;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801F8C38: sh          $t4, 0x78($t5)
    MEM_H(0X78, ctx->r13) = ctx->r12;
    after_6:
    // 0x801F8C3C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801F8C40:
    // 0x801F8C40: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801F8C44: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x801F8C48: jr          $ra
    // 0x801F8C4C: nop

    return;
    // 0x801F8C4C: nop

;}
RECOMP_FUNC void M9_FUN_801f8c50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8C50: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x801F8C54: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801F8C58: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x801F8C5C: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x801F8C60: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x801F8C64: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801F8C68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801F8C6C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x801F8C70: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x801F8C74: jal         0x8013A334
    // 0x801F8C78: sw          $a2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_0;
    // 0x801F8C78: sw          $a2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801F8C7C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801F8C80: lw          $v1, -0x4328($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4328);
    // 0x801F8C84: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801F8C88: lui         $s0, 0x8022
    ctx->r16 = S32(0X8022 << 16);
    // 0x801F8C8C: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x801F8C90: addiu       $s0, $s0, -0x4FD8
    ctx->r16 = ADD32(ctx->r16, -0X4FD8);
    // 0x801F8C94: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801F8C98: lwc1        $f4, 0x30($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X30);
    // 0x801F8C9C: lui         $a1, 0x3F81
    ctx->r5 = S32(0X3F81 << 16);
    // 0x801F8CA0: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x801F8CA4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801F8CA8: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801F8CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F8CB0: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x801F8CB4: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x801F8CB8: lwc1        $f10, 0x34($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X34);
    // 0x801F8CBC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801F8CC0: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x801F8CC4: lw          $t8, 0x2C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2C);
    // 0x801F8CC8: lwc1        $f4, 0x38($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X38);
    // 0x801F8CCC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801F8CD0: jal         0x801477C4
    // 0x801F8CD4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801477C4)(rdram, ctx);
        goto after_1;
    // 0x801F8CD4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x801F8CD8: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x801F8CDC: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x801F8CE0: addiu       $t0, $t0, -0x4FD0
    ctx->r8 = ADD32(ctx->r8, -0X4FD0);
    // 0x801F8CE4: addiu       $t9, $t9, -0x4FD4
    ctx->r25 = ADD32(ctx->r25, -0X4FD4);
    // 0x801F8CE8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801F8CEC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801F8CF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801F8CF4: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801F8CF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801F8CFC: jal         0x80130AA0
    // 0x801F8D00: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80130AA0)(rdram, ctx);
        goto after_2;
    // 0x801F8D00: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x801F8D04: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801F8D08: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801F8D0C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F8D10: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801F8D14: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x801F8D18: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801F8D1C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F8D20: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801F8D24: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x801F8D28: ldc1        $f4, -0x72F0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X72F0);
    // 0x801F8D2C: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x801F8D30: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801F8D34: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801F8D38: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801F8D3C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801F8D40: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801F8D44: add.d       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f10.d + ctx->f6.d;
    // 0x801F8D48: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801F8D4C: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F8D50: add.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x801F8D54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F8D58: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801F8D5C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801F8D60: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x801F8D64: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801F8D68: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801F8D6C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x801F8D70: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801F8D74: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801F8D78: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801F8D7C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x801F8D80: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x801F8D84: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801F8D88: addiu       $a0, $a0, -0x757C
    ctx->r4 = ADD32(ctx->r4, -0X757C);
    // 0x801F8D8C: addiu       $a1, $zero, 0x820
    ctx->r5 = ADD32(0, 0X820);
    // 0x801F8D90: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801F8D94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F8D98: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801F8D9C: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x801F8DA0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801F8DA4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x801F8DA8: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x801F8DAC: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801F8DB0: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x801F8DB4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801F8DB8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801F8DBC: jal         0x8011AAF4
    // 0x801F8DC0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_3;
    // 0x801F8DC0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x801F8DC4: lui         $t4, 0x8021
    ctx->r12 = S32(0X8021 << 16);
    // 0x801F8DC8: addiu       $t4, $t4, 0x6EE8
    ctx->r12 = ADD32(ctx->r12, 0X6EE8);
    // 0x801F8DCC: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x801F8DD0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x801F8DD4: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x801F8DD8: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x801F8DDC: lw          $a3, 0x4($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X4);
    // 0x801F8DE0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F8DE4: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x801F8DE8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F8DEC: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x801F8DF0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801F8DF4: jal         0x8012CE9C
    // 0x801F8DF8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_4;
    // 0x801F8DF8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_4:
    // 0x801F8DFC: bne         $v0, $zero, L_801F8E38
    if (ctx->r2 != 0) {
        // 0x801F8E00: lw          $a0, 0x84($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X84);
            goto L_801F8E38;
    }
    // 0x801F8E00: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x801F8E04: jal         0x80010550
    // 0x801F8E08: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801F8E08: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    after_5:
    // 0x801F8E0C: jal         0x801FA2E0
    // 0x801F8E10: nop

    LOOKUP_FUNC(0x801FA2E0)(rdram, ctx);
        goto after_6;
    // 0x801F8E10: nop

    after_6:
    // 0x801F8E14: lhu         $v1, 0x3C($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X3C);
    // 0x801F8E18: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F8E1C: addiu       $a1, $a1, 0x5F5C
    ctx->r5 = ADD32(ctx->r5, 0X5F5C);
    // 0x801F8E20: sltiu       $a0, $v1, 0x1
    ctx->r4 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x801F8E24: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x801F8E28: beq         $a0, $zero, L_801F8E38
    if (ctx->r4 == 0) {
        // 0x801F8E2C: sh          $t8, 0x3C($s1)
        MEM_H(0X3C, ctx->r17) = ctx->r24;
            goto L_801F8E38;
    }
    // 0x801F8E2C: sh          $t8, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = ctx->r24;
    // 0x801F8E30: jal         0x800058DC
    // 0x801F8E34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801F8E34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
L_801F8E38:
    // 0x801F8E38: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801F8E3C: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x801F8E40: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x801F8E44: jr          $ra
    // 0x801F8E48: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x801F8E48: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f8e4c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f8e4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8E4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801F8E50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F8E54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801F8E58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F8E5C: jal         0x801C3B3C
    // 0x801F8E60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_0;
    // 0x801F8E60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F8E64: bnel        $v0, $zero, L_801F8F2C
    if (ctx->r2 != 0) {
        // 0x801F8E68: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801F8F2C;
    }
    goto skip_0;
    // 0x801F8E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801F8E6C: lbu         $t6, 0xAE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F8E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F8E74: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F8E78: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801F8E7C: bgez        $t6, L_801F8E90
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801F8E80: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F8E90;
    }
    // 0x801F8E80: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F8E84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F8E88: nop

    // 0x801F8E8C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F8E90:
    // 0x801F8E90: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F8E94: jal         0x801F3FFC
    // 0x801F8E98: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_1;
    // 0x801F8E98: nop

    after_1:
    // 0x801F8E9C: beql        $v0, $zero, L_801F8F2C
    if (ctx->r2 == 0) {
        // 0x801F8EA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801F8F2C;
    }
    goto skip_1;
    // 0x801F8EA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801F8EA4: jal         0x801F5230
    // 0x801F8EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_2;
    // 0x801F8EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801F8EAC: jal         0x801F49E0
    // 0x801F8EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F49E0)(rdram, ctx);
        goto after_3;
    // 0x801F8EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801F8EB4: sb          $v0, 0x90($s0)
    MEM_B(0X90, ctx->r16) = ctx->r2;
    // 0x801F8EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F8EBC: jal         0x801F48C8
    // 0x801F8EC0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x801F48C8)(rdram, ctx);
        goto after_4;
    // 0x801F8EC0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_4:
    // 0x801F8EC4: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x801F8EC8: beq         $t7, $zero, L_801F8ED8
    if (ctx->r15 == 0) {
        // 0x801F8ECC: sb          $v0, 0x91($s0)
        MEM_B(0X91, ctx->r16) = ctx->r2;
            goto L_801F8ED8;
    }
    // 0x801F8ECC: sb          $v0, 0x91($s0)
    MEM_B(0X91, ctx->r16) = ctx->r2;
    // 0x801F8ED0: b           L_801F8F18
    // 0x801F8ED4: sb          $zero, 0x92($s0)
    MEM_B(0X92, ctx->r16) = 0;
        goto L_801F8F18;
    // 0x801F8ED4: sb          $zero, 0x92($s0)
    MEM_B(0X92, ctx->r16) = 0;
L_801F8ED8:
    // 0x801F8ED8: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x801F8EDC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801F8EE0: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x801F8EE4: div         $zero, $t0, $t9
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r25)));
    // 0x801F8EE8: mflo        $t1
    ctx->r9 = lo;
    // 0x801F8EEC: sb          $t8, 0x92($s0)
    MEM_B(0X92, ctx->r16) = ctx->r24;
    // 0x801F8EF0: bne         $t9, $zero, L_801F8EFC
    if (ctx->r25 != 0) {
        // 0x801F8EF4: nop
    
            goto L_801F8EFC;
    }
    // 0x801F8EF4: nop

    // 0x801F8EF8: break       7
    do_break(2149551864);
L_801F8EFC:
    // 0x801F8EFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801F8F00: bne         $t9, $at, L_801F8F14
    if (ctx->r25 != ctx->r1) {
        // 0x801F8F04: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801F8F14;
    }
    // 0x801F8F04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801F8F08: bne         $t0, $at, L_801F8F14
    if (ctx->r8 != ctx->r1) {
        // 0x801F8F0C: nop
    
            goto L_801F8F14;
    }
    // 0x801F8F0C: nop

    // 0x801F8F10: break       6
    do_break(2149551888);
L_801F8F14:
    // 0x801F8F14: sh          $t1, 0x98($s0)
    MEM_H(0X98, ctx->r16) = ctx->r9;
L_801F8F18:
    // 0x801F8F18: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F8F1C: addiu       $a1, $a1, -0x70C4
    ctx->r5 = ADD32(ctx->r5, -0X70C4);
    // 0x801F8F20: jal         0x800058DC
    // 0x801F8F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801F8F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801F8F28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801F8F2C:
    // 0x801F8F2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801F8F30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801F8F34: jr          $ra
    // 0x801F8F38: nop

    return;
    // 0x801F8F38: nop

;}
RECOMP_FUNC void M9_FUN_801f8f3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F8F3C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801F8F40: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801F8F44: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801F8F48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F8F4C: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801F8F50: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x801F8F54: jal         0x8013A334
    // 0x801F8F58: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_0;
    // 0x801F8F58: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x801F8F5C: lbu         $t6, 0x91($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X91);
    // 0x801F8F60: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F8F64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F8F68: bne         $t6, $zero, L_801F8FC4
    if (ctx->r14 != 0) {
        // 0x801F8F6C: lui         $a0, 0x8022
        ctx->r4 = S32(0X8022 << 16);
            goto L_801F8FC4;
    }
    // 0x801F8F6C: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F8F70: lbu         $v0, 0x92($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X92);
    // 0x801F8F74: blez        $v0, L_801F8FC4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801F8F78: nop
    
            goto L_801F8FC4;
    }
    // 0x801F8F78: nop

    // 0x801F8F7C: lbu         $t8, 0x90($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X90);
    // 0x801F8F80: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x801F8F84: sb          $t7, 0x92($s0)
    MEM_B(0X92, ctx->r16) = ctx->r15;
    // 0x801F8F88: beql        $t8, $zero, L_801F8FB0
    if (ctx->r24 == 0) {
        // 0x801F8F8C: lw          $t3, 0x24($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X24);
            goto L_801F8FB0;
    }
    goto skip_0;
    // 0x801F8F8C: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x801F8F90: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801F8F94: lh          $t1, 0x98($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X98);
    // 0x801F8F98: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x801F8F9C: lh          $t0, 0x12($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X12);
    // 0x801F8FA0: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x801F8FA4: b           L_801F8FC4
    // 0x801F8FA8: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
        goto L_801F8FC4;
    // 0x801F8FA8: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
    // 0x801F8FAC: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
L_801F8FB0:
    // 0x801F8FB0: lh          $t5, 0x98($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X98);
    // 0x801F8FB4: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801F8FB8: lh          $t4, 0x12($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X12);
    // 0x801F8FBC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x801F8FC0: sh          $t6, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r14;
L_801F8FC4:
    // 0x801F8FC4: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801F8FC8: lw          $t8, -0x4330($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4330);
    // 0x801F8FCC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801F8FD0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801F8FD4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801F8FD8: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801F8FDC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801F8FE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F8FE4: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F8FE8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801F8FEC: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801F8FF0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801F8FF4: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F8FF8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801F8FFC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801F9000: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801F9004: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F9008: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801F900C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801F9010: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801F9014: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801F9018: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F901C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x801F9020: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x801F9024: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801F9028: addiu       $a0, $a0, -0x7540
    ctx->r4 = ADD32(ctx->r4, -0X7540);
    // 0x801F902C: addiu       $a1, $zero, 0x856
    ctx->r5 = ADD32(0, 0X856);
    // 0x801F9030: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801F9034: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F9038: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x801F903C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801F9040: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x801F9044: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x801F9048: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801F904C: jal         0x8011AAF4
    // 0x801F9050: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_1;
    // 0x801F9050: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801F9054: bnel        $v0, $zero, L_801F907C
    if (ctx->r2 != 0) {
        // 0x801F9058: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801F907C;
    }
    goto skip_1;
    // 0x801F9058: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x801F905C: lbu         $t1, 0x92($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X92);
    // 0x801F9060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F9064: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F9068: bnel        $t1, $zero, L_801F907C
    if (ctx->r9 != 0) {
        // 0x801F906C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801F907C;
    }
    goto skip_2;
    // 0x801F906C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x801F9070: jal         0x800058DC
    // 0x801F9074: addiu       $a1, $a1, -0x6E40
    ctx->r5 = ADD32(ctx->r5, -0X6E40);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801F9074: addiu       $a1, $a1, -0x6E40
    ctx->r5 = ADD32(ctx->r5, -0X6E40);
    after_2:
    // 0x801F9078: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801F907C:
    // 0x801F907C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801F9080: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x801F9084: jr          $ra
    // 0x801F9088: nop

    return;
    // 0x801F9088: nop

;}
RECOMP_FUNC void M9_FUN_801f908c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F908C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F9090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F9094: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F9098: jal         0x801C3B3C
    // 0x801F909C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_0;
    // 0x801F909C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F90A0: bne         $v0, $zero, L_801F90F4
    if (ctx->r2 != 0) {
        // 0x801F90A4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801F90F4;
    }
    // 0x801F90A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801F90A8: lbu         $t6, 0xAE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XAE);
    // 0x801F90AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F90B0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801F90B4: bgez        $t6, L_801F90C8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801F90B8: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F90C8;
    }
    // 0x801F90B8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F90BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F90C0: nop

    // 0x801F90C4: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F90C8:
    // 0x801F90C8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F90CC: jal         0x801F3FFC
    // 0x801F90D0: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_1;
    // 0x801F90D0: nop

    after_1:
    // 0x801F90D4: beql        $v0, $zero, L_801F90F8
    if (ctx->r2 == 0) {
        // 0x801F90D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F90F8;
    }
    goto skip_0;
    // 0x801F90D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801F90DC: jal         0x801F5230
    // 0x801F90E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_2;
    // 0x801F90E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801F90E4: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F90E8: addiu       $a1, $a1, -0x6EFC
    ctx->r5 = ADD32(ctx->r5, -0X6EFC);
    // 0x801F90EC: jal         0x800058DC
    // 0x801F90F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801F90F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_801F90F4:
    // 0x801F90F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801F90F8:
    // 0x801F90F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F90FC: jr          $ra
    // 0x801F9100: nop

    return;
    // 0x801F9100: nop

;}
RECOMP_FUNC void M9_FUN_801f9104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9104: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801F9108: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801F910C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801F9110: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801F9114: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x801F9118: jal         0x8013A334
    // 0x801F911C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_0;
    // 0x801F911C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x801F9120: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x801F9124: jal         0x8012A94C
    // 0x801F9128: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8012A94C)(rdram, ctx);
        goto after_1;
    // 0x801F9128: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_1:
    // 0x801F912C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801F9130: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x801F9134: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F9138: lwc1        $f0, -0x72E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X72E8);
    // 0x801F913C: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F9140: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801F9144: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F9148: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F914C: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x801F9150: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801F9154: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F9158: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F915C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801F9160: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801F9164: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801F9168: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801F916C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801F9170: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801F9174: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x801F9178: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801F917C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801F9180: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801F9184: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801F9188: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x801F918C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801F9190: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801F9194: jal         0x801F3C90
    // 0x801F9198: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801F3C90)(rdram, ctx);
        goto after_2;
    // 0x801F9198: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x801F919C: beq         $v0, $zero, L_801F91B0
    if (ctx->r2 == 0) {
        // 0x801F91A0: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_801F91B0;
    }
    // 0x801F91A0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x801F91A4: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F91A8: jal         0x800058DC
    // 0x801F91AC: addiu       $a1, $a1, -0x6E40
    ctx->r5 = ADD32(ctx->r5, -0X6E40);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801F91AC: addiu       $a1, $a1, -0x6E40
    ctx->r5 = ADD32(ctx->r5, -0X6E40);
    after_3:
L_801F91B0:
    // 0x801F91B0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801F91B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801F91B8: jr          $ra
    // 0x801F91BC: nop

    return;
    // 0x801F91BC: nop

;}
RECOMP_FUNC void M9_FUN_801f91c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F91C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801F91C4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801F91C8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801F91CC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801F91D0: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801F91D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F91D8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x801F91DC: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x801F91E0: jal         0x8013A334
    // 0x801F91E4: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_0;
    // 0x801F91E4: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801F91E8: jal         0x801F5210
    // 0x801F91EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5210)(rdram, ctx);
        goto after_1;
    // 0x801F91EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801F91F0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801F91F4: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x801F91F8: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x801F91FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F9200: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801F9204: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F9208: lwc1        $f16, -0x72E4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X72E4);
    // 0x801F920C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F9210: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x801F9214: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F9218: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F921C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801F9220: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801F9224: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801F9228: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801F922C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801F9230: lwc1        $f8, -0x72E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X72E0);
    // 0x801F9234: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801F9238: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801F923C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F9240: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x801F9244: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801F9248: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801F924C: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x801F9250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F9254: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801F9258: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x801F925C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801F9260: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x801F9264: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x801F9268: jal         0x801F3C90
    // 0x801F926C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801F3C90)(rdram, ctx);
        goto after_2;
    // 0x801F926C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801F9270: lhu         $t7, 0x70($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X70);
    // 0x801F9274: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x801F9278: bnel        $t7, $at, L_801F928C
    if (ctx->r15 != ctx->r1) {
        // 0x801F927C: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_801F928C;
    }
    goto skip_0;
    // 0x801F927C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x801F9280: jal         0x80020744
    // 0x801F9284: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_3;
    // 0x801F9284: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_3:
    // 0x801F9288: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_801F928C:
    // 0x801F928C: jal         0x80010550
    // 0x801F9290: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_4;
    // 0x801F9290: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x801F9294: beq         $v0, $zero, L_801F9304
    if (ctx->r2 == 0) {
        // 0x801F9298: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_801F9304;
    }
    // 0x801F9298: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801F929C: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x801F92A0: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F92A4: addiu       $a1, $a1, -0x6CE8
    ctx->r5 = ADD32(ctx->r5, -0X6CE8);
    // 0x801F92A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F92AC: jal         0x800058DC
    // 0x801F92B0: sh          $t8, 0x78($t9)
    MEM_H(0X78, ctx->r25) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801F92B0: sh          $t8, 0x78($t9)
    MEM_H(0X78, ctx->r25) = ctx->r24;
    after_5:
    // 0x801F92B4: jal         0x8012C6B4
    // 0x801F92B8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x801F92B8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_6:
    // 0x801F92BC: addiu       $t0, $v0, -0x5
    ctx->r8 = ADD32(ctx->r2, -0X5);
    // 0x801F92C0: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x801F92C4: lui         $s0, 0x8022
    ctx->r16 = S32(0X8022 << 16);
    // 0x801F92C8: addiu       $s0, $s0, -0x4FD8
    ctx->r16 = ADD32(ctx->r16, -0X4FD8);
    // 0x801F92CC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801F92D0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801F92D4: jal         0x8012C6B4
    // 0x801F92D8: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_7;
    // 0x801F92D8: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    after_7:
    // 0x801F92DC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801F92E0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801F92E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F92E8: jal         0x8012C6B4
    // 0x801F92EC: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_8;
    // 0x801F92EC: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    after_8:
    // 0x801F92F0: addiu       $t1, $v0, -0x5
    ctx->r9 = ADD32(ctx->r2, -0X5);
    // 0x801F92F4: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801F92F8: nop

    // 0x801F92FC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801F9300: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_801F9304:
    // 0x801F9304: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801F9308: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801F930C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801F9310: jr          $ra
    // 0x801F9314: nop

    return;
    // 0x801F9314: nop

;}
RECOMP_FUNC void M9_FUN_801f9318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9318: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801F931C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801F9320: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x801F9324: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x801F9328: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x801F932C: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    // 0x801F9330: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801F9334: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x801F9338: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x801F933C: jal         0x8013A334
    // 0x801F9340: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_0;
    // 0x801F9340: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x801F9344: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x801F9348: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x801F934C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F9350: jal         0x801F467C
    // 0x801F9354: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x801F467C)(rdram, ctx);
        goto after_1;
    // 0x801F9354: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_1:
    // 0x801F9358: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x801F935C: jal         0x80147768
    // 0x801F9360: lui         $a1, 0x41B0
    ctx->r5 = S32(0X41B0 << 16);
    LOOKUP_FUNC(0x80147768)(rdram, ctx);
        goto after_2;
    // 0x801F9360: lui         $a1, 0x41B0
    ctx->r5 = S32(0X41B0 << 16);
    after_2:
    // 0x801F9364: lw          $t8, 0x24($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X24);
    // 0x801F9368: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801F936C: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801F9370: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801F9374: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F9378: lwc1        $f14, -0x72DC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X72DC);
    // 0x801F937C: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F9380: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F9384: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x801F9388: addiu       $v1, $v1, -0x4FD8
    ctx->r3 = ADD32(ctx->r3, -0X4FD8);
    // 0x801F938C: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F9390: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801F9394: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F9398: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801F939C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801F93A0: add.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x801F93A4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801F93A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F93AC: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F93B0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801F93B4: add.s       $f16, $f12, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x801F93B8: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801F93BC: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801F93C0: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801F93C4: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801F93C8: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x801F93CC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F93D0: lwc1        $f16, -0x72D8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X72D8);
    // 0x801F93D4: add.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x801F93D8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801F93DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F93E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801F93E4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801F93E8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801F93EC: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x801F93F0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801F93F4: add.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801F93F8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x801F93FC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801F9400: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801F9404: add.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801F9408: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x801F940C: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x801F9410: jal         0x801F3C90
    // 0x801F9414: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801F3C90)(rdram, ctx);
        goto after_3;
    // 0x801F9414: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x801F9418: lui         $t9, 0x8021
    ctx->r25 = S32(0X8021 << 16);
    // 0x801F941C: sb          $v0, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r2;
    // 0x801F9420: addiu       $t9, $t9, 0x6EE8
    ctx->r25 = ADD32(ctx->r25, 0X6EE8);
    // 0x801F9424: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801F9428: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x801F942C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x801F9430: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x801F9434: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x801F9438: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F943C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801F9440: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F9444: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801F9448: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801F944C: jal         0x8012CE9C
    // 0x801F9450: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_4;
    // 0x801F9450: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_4:
    // 0x801F9454: bnel        $v0, $zero, L_801F949C
    if (ctx->r2 != 0) {
        // 0x801F9458: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801F949C;
    }
    goto skip_0;
    // 0x801F9458: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x801F945C: jal         0x801FA2E0
    // 0x801F9460: nop

    LOOKUP_FUNC(0x801FA2E0)(rdram, ctx);
        goto after_5;
    // 0x801F9460: nop

    after_5:
    // 0x801F9464: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x801F9468: jal         0x80010550
    // 0x801F946C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_6;
    // 0x801F946C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x801F9470: beq         $v0, $zero, L_801F9498
    if (ctx->r2 == 0) {
        // 0x801F9474: lb          $t3, 0x43($sp)
        ctx->r11 = MEM_B(ctx->r29, 0X43);
            goto L_801F9498;
    }
    // 0x801F9474: lb          $t3, 0x43($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X43);
    // 0x801F9478: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F947C: bne         $t3, $at, L_801F9498
    if (ctx->r11 != ctx->r1) {
        // 0x801F9480: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_801F9498;
    }
    // 0x801F9480: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801F9484: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F9488: sh          $t4, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r12;
    // 0x801F948C: addiu       $a1, $a1, 0x5F5C
    ctx->r5 = ADD32(ctx->r5, 0X5F5C);
    // 0x801F9490: jal         0x800058DC
    // 0x801F9494: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801F9494: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
L_801F9498:
    // 0x801F9498: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801F949C:
    // 0x801F949C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x801F94A0: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x801F94A4: jr          $ra
    // 0x801F94A8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801F94A8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f94ac(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f94ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F94AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F94B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F94B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F94B8: jal         0x801C3B3C
    // 0x801F94BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_0;
    // 0x801F94BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F94C0: bne         $v0, $zero, L_801F9514
    if (ctx->r2 != 0) {
        // 0x801F94C4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801F9514;
    }
    // 0x801F94C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801F94C8: lbu         $t6, 0xAE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XAE);
    // 0x801F94CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F94D0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801F94D4: bgez        $t6, L_801F94E8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801F94D8: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F94E8;
    }
    // 0x801F94D8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F94DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F94E0: nop

    // 0x801F94E4: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F94E8:
    // 0x801F94E8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F94EC: jal         0x801F3FFC
    // 0x801F94F0: nop

    LOOKUP_FUNC(0x801F3FFC)(rdram, ctx);
        goto after_1;
    // 0x801F94F0: nop

    after_1:
    // 0x801F94F4: beql        $v0, $zero, L_801F9518
    if (ctx->r2 == 0) {
        // 0x801F94F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F9518;
    }
    goto skip_0;
    // 0x801F94F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801F94FC: jal         0x801F5230
    // 0x801F9500: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_2;
    // 0x801F9500: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801F9504: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F9508: addiu       $a1, $a1, -0x6ADC
    ctx->r5 = ADD32(ctx->r5, -0X6ADC);
    // 0x801F950C: jal         0x800058DC
    // 0x801F9510: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801F9510: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_801F9514:
    // 0x801F9514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801F9518:
    // 0x801F9518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F951C: jr          $ra
    // 0x801F9520: nop

    return;
    // 0x801F9520: nop

;}
RECOMP_FUNC void M9_FUN_801f9524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9524: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801F9528: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801F952C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801F9530: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F9534: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801F9538: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x801F953C: jal         0x8013A334
    // 0x801F9540: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_0;
    // 0x801F9540: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x801F9544: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F9548: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F954C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801F9550: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x801F9554: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801F9558: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801F955C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801F9560: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F9564: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x801F9568: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F956C: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801F9570: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801F9574: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801F9578: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801F957C: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F9580: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801F9584: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F9588: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801F958C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F9590: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801F9594: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801F9598: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801F959C: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801F95A0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801F95A4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801F95A8: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801F95AC: addiu       $a0, $a0, -0x7504
    ctx->r4 = ADD32(ctx->r4, -0X7504);
    // 0x801F95B0: addiu       $a1, $zero, 0x8E0
    ctx->r5 = ADD32(0, 0X8E0);
    // 0x801F95B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801F95B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F95BC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801F95C0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801F95C4: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x801F95C8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801F95CC: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x801F95D0: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x801F95D4: jal         0x8011AAF4
    // 0x801F95D8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_1;
    // 0x801F95D8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x801F95DC: bnel        $v0, $zero, L_801F9654
    if (ctx->r2 != 0) {
        // 0x801F95E0: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801F9654;
    }
    goto skip_0;
    // 0x801F95E0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x801F95E4: jal         0x801F5210
    // 0x801F95E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5210)(rdram, ctx);
        goto after_2;
    // 0x801F95E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801F95EC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801F95F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F95F4: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x801F95F8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801F95FC: sb          $t0, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r8;
    // 0x801F9600: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x801F9604: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801F9608: jal         0x8001EB64
    // 0x801F960C: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x801F960C: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_3:
    // 0x801F9610: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801F9614: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F9618: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801F961C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801F9620: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x801F9624: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801F9628: jal         0x8001EAD0
    // 0x801F962C: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x801F962C: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_4:
    // 0x801F9630: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801F9634: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F9638: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F963C: addiu       $a1, $a1, -0x699C
    ctx->r5 = ADD32(ctx->r5, -0X699C);
    // 0x801F9640: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801F9644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F9648: jal         0x800058DC
    // 0x801F964C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801F964C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x801F9650: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801F9654:
    // 0x801F9654: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801F9658: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x801F965C: jr          $ra
    // 0x801F9660: nop

    return;
    // 0x801F9660: nop

;}
RECOMP_FUNC void M9_FUN_801f9664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9664: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801F9668: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801F966C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801F9670: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x801F9674: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801F9678: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F967C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x801F9680: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x801F9684: jal         0x8013A334
    // 0x801F9688: sw          $a2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_0;
    // 0x801F9688: sw          $a2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r6;
    after_0:
    // 0x801F968C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801F9690: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F9694: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801F9698: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x801F969C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F96A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801F96A4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801F96A8: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F96AC: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x801F96B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F96B4: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801F96B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F96BC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801F96C0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801F96C4: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F96C8: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801F96CC: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801F96D0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801F96D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F96D8: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801F96DC: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F96E0: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801F96E4: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801F96E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801F96EC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801F96F0: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801F96F4: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801F96F8: addiu       $a0, $a0, -0x74C8
    ctx->r4 = ADD32(ctx->r4, -0X74C8);
    // 0x801F96FC: addiu       $a1, $zero, 0x8F8
    ctx->r5 = ADD32(0, 0X8F8);
    // 0x801F9700: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801F9704: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F9708: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801F970C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801F9710: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801F9714: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801F9718: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x801F971C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x801F9720: jal         0x8011AAF4
    // 0x801F9724: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_1;
    // 0x801F9724: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x801F9728: lhu         $t0, 0x70($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X70);
    // 0x801F972C: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x801F9730: bnel        $t0, $at, L_801F9754
    if (ctx->r8 != ctx->r1) {
        // 0x801F9734: lw          $a0, 0x6C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X6C);
            goto L_801F9754;
    }
    goto skip_0;
    // 0x801F9734: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    skip_0:
    // 0x801F9738: jal         0x80020744
    // 0x801F973C: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x801F973C: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_2:
    // 0x801F9740: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801F9744: nop

    // 0x801F9748: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x801F974C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x801F9750: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
L_801F9754:
    // 0x801F9754: jal         0x80010550
    // 0x801F9758: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_3;
    // 0x801F9758: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_3:
    // 0x801F975C: beq         $v0, $zero, L_801F97CC
    if (ctx->r2 == 0) {
        // 0x801F9760: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_801F97CC;
    }
    // 0x801F9760: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801F9764: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x801F9768: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801F976C: jal         0x8012C6B4
    // 0x801F9770: sh          $t1, 0x78($t2)
    MEM_H(0X78, ctx->r10) = ctx->r9;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801F9770: sh          $t1, 0x78($t2)
    MEM_H(0X78, ctx->r10) = ctx->r9;
    after_4:
    // 0x801F9774: addiu       $t3, $v0, -0x5
    ctx->r11 = ADD32(ctx->r2, -0X5);
    // 0x801F9778: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x801F977C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F9780: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801F9784: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801F9788: jal         0x8012C6B4
    // 0x801F978C: swc1        $f18, -0x4FD8($at)
    MEM_W(-0X4FD8, ctx->r1) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x801F978C: swc1        $f18, -0x4FD8($at)
    MEM_W(-0X4FD8, ctx->r1) = ctx->f18.u32l;
    after_5:
    // 0x801F9790: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801F9794: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F9798: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801F979C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F97A0: jal         0x8012C6B4
    // 0x801F97A4: swc1        $f6, -0x4FD4($at)
    MEM_W(-0X4FD4, ctx->r1) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_6;
    // 0x801F97A4: swc1        $f6, -0x4FD4($at)
    MEM_W(-0X4FD4, ctx->r1) = ctx->f6.u32l;
    after_6:
    // 0x801F97A8: addiu       $t4, $v0, -0x5
    ctx->r12 = ADD32(ctx->r2, -0X5);
    // 0x801F97AC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x801F97B0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F97B4: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F97B8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801F97BC: addiu       $a1, $a1, -0x6820
    ctx->r5 = ADD32(ctx->r5, -0X6820);
    // 0x801F97C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F97C4: jal         0x800058DC
    // 0x801F97C8: swc1        $f10, -0x4FD0($at)
    MEM_W(-0X4FD0, ctx->r1) = ctx->f10.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801F97C8: swc1        $f10, -0x4FD0($at)
    MEM_W(-0X4FD0, ctx->r1) = ctx->f10.u32l;
    after_7:
L_801F97CC:
    // 0x801F97CC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801F97D0: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801F97D4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x801F97D8: jr          $ra
    // 0x801F97DC: nop

    return;
    // 0x801F97DC: nop

;}
RECOMP_FUNC void M9_FUN_801f97e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F97E0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801F97E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801F97E8: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x801F97EC: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x801F97F0: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x801F97F4: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    // 0x801F97F8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801F97FC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x801F9800: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x801F9804: jal         0x8013A334
    // 0x801F9808: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_0;
    // 0x801F9808: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x801F980C: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x801F9810: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x801F9814: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F9818: jal         0x801F467C
    // 0x801F981C: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x801F467C)(rdram, ctx);
        goto after_1;
    // 0x801F981C: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_1:
    // 0x801F9820: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x801F9824: jal         0x80147768
    // 0x801F9828: lui         $a1, 0x41B0
    ctx->r5 = S32(0X41B0 << 16);
    LOOKUP_FUNC(0x80147768)(rdram, ctx);
        goto after_2;
    // 0x801F9828: lui         $a1, 0x41B0
    ctx->r5 = S32(0X41B0 << 16);
    after_2:
    // 0x801F982C: lw          $t8, 0x24($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X24);
    // 0x801F9830: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801F9834: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801F9838: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801F983C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F9840: lwc1        $f14, -0x72D4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X72D4);
    // 0x801F9844: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F9848: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F984C: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x801F9850: addiu       $v1, $v1, -0x4FD8
    ctx->r3 = ADD32(ctx->r3, -0X4FD8);
    // 0x801F9854: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F9858: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801F985C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F9860: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801F9864: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801F9868: add.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x801F986C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801F9870: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801F9874: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F9878: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801F987C: add.s       $f16, $f12, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x801F9880: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801F9884: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801F9888: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801F988C: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801F9890: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x801F9894: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F9898: lwc1        $f16, -0x72D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X72D0);
    // 0x801F989C: add.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x801F98A0: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801F98A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F98A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801F98AC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801F98B0: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801F98B4: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x801F98B8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801F98BC: add.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801F98C0: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x801F98C4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801F98C8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801F98CC: add.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801F98D0: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x801F98D4: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x801F98D8: jal         0x801F3C90
    // 0x801F98DC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801F3C90)(rdram, ctx);
        goto after_3;
    // 0x801F98DC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x801F98E0: lui         $t9, 0x8021
    ctx->r25 = S32(0X8021 << 16);
    // 0x801F98E4: sb          $v0, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r2;
    // 0x801F98E8: addiu       $t9, $t9, 0x6EE8
    ctx->r25 = ADD32(ctx->r25, 0X6EE8);
    // 0x801F98EC: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801F98F0: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x801F98F4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x801F98F8: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x801F98FC: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x801F9900: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F9904: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801F9908: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F990C: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801F9910: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801F9914: jal         0x8012CE9C
    // 0x801F9918: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_4;
    // 0x801F9918: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_4:
    // 0x801F991C: bnel        $v0, $zero, L_801F9964
    if (ctx->r2 != 0) {
        // 0x801F9920: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801F9964;
    }
    goto skip_0;
    // 0x801F9920: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x801F9924: jal         0x801FA2E0
    // 0x801F9928: nop

    LOOKUP_FUNC(0x801FA2E0)(rdram, ctx);
        goto after_5;
    // 0x801F9928: nop

    after_5:
    // 0x801F992C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x801F9930: jal         0x80010550
    // 0x801F9934: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_6;
    // 0x801F9934: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x801F9938: beq         $v0, $zero, L_801F9960
    if (ctx->r2 == 0) {
        // 0x801F993C: lb          $t3, 0x43($sp)
        ctx->r11 = MEM_B(ctx->r29, 0X43);
            goto L_801F9960;
    }
    // 0x801F993C: lb          $t3, 0x43($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X43);
    // 0x801F9940: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801F9944: bne         $t3, $at, L_801F9960
    if (ctx->r11 != ctx->r1) {
        // 0x801F9948: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_801F9960;
    }
    // 0x801F9948: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801F994C: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801F9950: sh          $t4, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r12;
    // 0x801F9954: addiu       $a1, $a1, 0x5F5C
    ctx->r5 = ADD32(ctx->r5, 0X5F5C);
    // 0x801F9958: jal         0x800058DC
    // 0x801F995C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801F995C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
L_801F9960:
    // 0x801F9960: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801F9964:
    // 0x801F9964: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x801F9968: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x801F996C: jr          $ra
    // 0x801F9970: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801F9970: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801f9974(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801f9974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9974: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801F9978: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801F997C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801F9980: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801F9984: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801F9988: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F998C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801F9990: jal         0x80010550
    // 0x801F9994: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x801F9994: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801F9998: jal         0x801C3B3C
    // 0x801F999C: nop

    LOOKUP_FUNC(0x801C3B3C)(rdram, ctx);
        goto after_1;
    // 0x801F999C: nop

    after_1:
    // 0x801F99A0: bnel        $v0, $zero, L_801F9A70
    if (ctx->r2 != 0) {
        // 0x801F99A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801F9A70;
    }
    goto skip_0;
    // 0x801F99A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x801F99A8: lbu         $t6, 0xAE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XAE);
    // 0x801F99AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F99B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F99B4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801F99B8: bgez        $t6, L_801F99CC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801F99BC: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801F99CC;
    }
    // 0x801F99BC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F99C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F99C4: nop

    // 0x801F99C8: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801F99CC:
    // 0x801F99CC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801F99D0: jal         0x801F40BC
    // 0x801F99D4: nop

    LOOKUP_FUNC(0x801F40BC)(rdram, ctx);
        goto after_2;
    // 0x801F99D4: nop

    after_2:
    // 0x801F99D8: beq         $v0, $zero, L_801F9A6C
    if (ctx->r2 == 0) {
        // 0x801F99DC: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801F9A6C;
    }
    // 0x801F99DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F99E0: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801F99E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F99E8: jal         0x801F3F70
    // 0x801F99EC: sb          $t7, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r15;
    LOOKUP_FUNC(0x801F3F70)(rdram, ctx);
        goto after_3;
    // 0x801F99EC: sb          $t7, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r15;
    after_3:
    // 0x801F99F0: sh          $v0, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r2;
    // 0x801F99F4: lh          $t1, 0x92($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X92);
    // 0x801F99F8: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801F99FC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F9A00: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x801F9A04: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F9A08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F9A0C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801F9A10: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801F9A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F9A18: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x801F9A1C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801F9A20: jal         0x801F5230
    // 0x801F9A24: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801F5230)(rdram, ctx);
        goto after_4;
    // 0x801F9A24: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x801F9A28: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x801F9A2C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x801F9A30: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801F9A34: jal         0x8013A334
    // 0x801F9A38: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_5;
    // 0x801F9A38: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x801F9A3C: jal         0x801F53C4
    // 0x801F9A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F53C4)(rdram, ctx);
        goto after_6;
    // 0x801F9A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801F9A44: beq         $v0, $zero, L_801F9A54
    if (ctx->r2 == 0) {
        // 0x801F9A48: nop
    
            goto L_801F9A54;
    }
    // 0x801F9A48: nop

    // 0x801F9A4C: jal         0x801F536C
    // 0x801F9A50: nop

    LOOKUP_FUNC(0x801F536C)(rdram, ctx);
        goto after_7;
    // 0x801F9A50: nop

    after_7:
L_801F9A54:
    // 0x801F9A54: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F9A58: addiu       $a1, $a1, -0x6574
    ctx->r5 = ADD32(ctx->r5, -0X6574);
    // 0x801F9A5C: jal         0x800058DC
    // 0x801F9A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801F9A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801F9A64: b           L_801F9A7C
    // 0x801F9A68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801F9A7C;
    // 0x801F9A68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801F9A6C:
    // 0x801F9A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801F9A70:
    // 0x801F9A70: jal         0x8012A94C
    // 0x801F9A74: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x8012A94C)(rdram, ctx);
        goto after_9;
    // 0x801F9A74: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_9:
    // 0x801F9A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801F9A7C:
    // 0x801F9A7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801F9A80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801F9A84: jr          $ra
    // 0x801F9A88: nop

    return;
    // 0x801F9A88: nop

;}
RECOMP_FUNC void M9_FUN_801f9a8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9A8C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801F9A90: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801F9A94: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801F9A98: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x801F9A9C: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801F9AA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F9AA4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801F9AA8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x801F9AAC: jal         0x80010550
    // 0x801F9AB0: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x801F9AB0: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801F9AB4: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x801F9AB8: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x801F9ABC: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x801F9AC0: jal         0x8013A334
    // 0x801F9AC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_1;
    // 0x801F9AC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x801F9AC8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F9ACC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F9AD0: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801F9AD4: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x801F9AD8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801F9ADC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801F9AE0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801F9AE4: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801F9AE8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801F9AEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F9AF0: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801F9AF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801F9AF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F9AFC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801F9B00: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F9B04: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801F9B08: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801F9B0C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801F9B10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F9B14: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801F9B18: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F9B1C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801F9B20: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801F9B24: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x801F9B28: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801F9B2C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801F9B30: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801F9B34: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801F9B38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F9B3C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F9B40: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801F9B44: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801F9B48: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x801F9B4C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x801F9B50: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x801F9B54: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801F9B58: addiu       $a0, $a0, -0x748C
    ctx->r4 = ADD32(ctx->r4, -0X748C);
    // 0x801F9B5C: addiu       $a1, $zero, 0x952
    ctx->r5 = ADD32(0, 0X952);
    // 0x801F9B60: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801F9B64: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x801F9B68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F9B6C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801F9B70: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x801F9B74: jal         0x8011AAF4
    // 0x801F9B78: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_2;
    // 0x801F9B78: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x801F9B7C: bnel        $v0, $zero, L_801F9BB8
    if (ctx->r2 != 0) {
        // 0x801F9B80: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801F9BB8;
    }
    goto skip_0;
    // 0x801F9B80: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x801F9B84: jal         0x801F53C4
    // 0x801F9B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F53C4)(rdram, ctx);
        goto after_3;
    // 0x801F9B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801F9B8C: bnel        $v0, $zero, L_801F9BA0
    if (ctx->r2 != 0) {
        // 0x801F9B90: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_801F9BA0;
    }
    goto skip_1;
    // 0x801F9B90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_1:
    // 0x801F9B94: jal         0x801F536C
    // 0x801F9B98: nop

    LOOKUP_FUNC(0x801F536C)(rdram, ctx);
        goto after_4;
    // 0x801F9B98: nop

    after_4:
    // 0x801F9B9C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_801F9BA0:
    // 0x801F9BA0: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F9BA4: addiu       $a1, $a1, -0x6438
    ctx->r5 = ADD32(ctx->r5, -0X6438);
    // 0x801F9BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F9BAC: jal         0x800058DC
    // 0x801F9BB0: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801F9BB0: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x801F9BB4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801F9BB8:
    // 0x801F9BB8: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801F9BBC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x801F9BC0: jr          $ra
    // 0x801F9BC4: nop

    return;
    // 0x801F9BC4: nop

;}
RECOMP_FUNC void M9_FUN_801f9bc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9BC8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801F9BCC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801F9BD0: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801F9BD4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x801F9BD8: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801F9BDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F9BE0: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x801F9BE4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F9BE8: jal         0x8013A334
    // 0x801F9BEC: sw          $a2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_0;
    // 0x801F9BEC: sw          $a2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r6;
    after_0:
    // 0x801F9BF0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F9BF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F9BF8: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801F9BFC: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x801F9C00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F9C04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801F9C08: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801F9C0C: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801F9C10: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801F9C14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F9C18: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F9C1C: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801F9C20: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801F9C24: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801F9C28: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F9C2C: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F9C30: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801F9C34: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801F9C38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801F9C3C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801F9C40: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801F9C44: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801F9C48: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801F9C4C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801F9C50: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x801F9C54: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801F9C58: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801F9C5C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801F9C60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801F9C64: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801F9C68: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801F9C6C: addiu       $a0, $a0, -0x7450
    ctx->r4 = ADD32(ctx->r4, -0X7450);
    // 0x801F9C70: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x801F9C74: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x801F9C78: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x801F9C7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F9C80: addiu       $a1, $zero, 0x968
    ctx->r5 = ADD32(0, 0X968);
    // 0x801F9C84: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801F9C88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F9C8C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x801F9C90: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x801F9C94: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x801F9C98: jal         0x8011AAF4
    // 0x801F9C9C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_1;
    // 0x801F9C9C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801F9CA0: lw          $t2, 0x2C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X2C);
    // 0x801F9CA4: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x801F9CA8: sw          $t3, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r11;
    // 0x801F9CAC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x801F9CB0: jal         0x80010550
    // 0x801F9CB4: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_2;
    // 0x801F9CB4: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_2:
    // 0x801F9CB8: jal         0x801F5294
    // 0x801F9CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5294)(rdram, ctx);
        goto after_3;
    // 0x801F9CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801F9CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F9CC4: jal         0x8012A94C
    // 0x801F9CC8: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8012A94C)(rdram, ctx);
        goto after_4;
    // 0x801F9CC8: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_4:
    // 0x801F9CCC: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801F9CD0: lwc1        $f6, 0x94($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801F9CD4: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801F9CD8: lwc1        $f4, 0x8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X8);
    // 0x801F9CDC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801F9CE0: nop

    // 0x801F9CE4: bc1fl       L_801F9D58
    if (!c1cs) {
        // 0x801F9CE8: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801F9D58;
    }
    goto skip_0;
    // 0x801F9CE8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x801F9CEC: jal         0x801F5210
    // 0x801F9CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801F5210)(rdram, ctx);
        goto after_5;
    // 0x801F9CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801F9CF4: jal         0x80020744
    // 0x801F9CF8: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_6;
    // 0x801F9CF8: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_6:
    // 0x801F9CFC: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801F9D00: lwc1        $f8, 0x94($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801F9D04: lui         $t8, 0x8021
    ctx->r24 = S32(0X8021 << 16);
    // 0x801F9D08: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801F9D0C: addiu       $t8, $t8, 0x6EDC
    ctx->r24 = ADD32(ctx->r24, 0X6EDC);
    // 0x801F9D10: swc1        $f8, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f8.u32l;
    // 0x801F9D14: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801F9D18: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x801F9D1C: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x801F9D20: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x801F9D24: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801F9D28: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801F9D2C: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x801F9D30: jal         0x8013A28C
    // 0x801F9D34: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_7;
    // 0x801F9D34: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_7:
    // 0x801F9D38: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x801F9D3C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801F9D40: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F9D44: addiu       $a1, $a1, -0x6298
    ctx->r5 = ADD32(ctx->r5, -0X6298);
    // 0x801F9D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F9D4C: jal         0x800058DC
    // 0x801F9D50: sh          $t1, 0x78($t2)
    MEM_H(0X78, ctx->r10) = ctx->r9;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801F9D50: sh          $t1, 0x78($t2)
    MEM_H(0X78, ctx->r10) = ctx->r9;
    after_8:
    // 0x801F9D54: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801F9D58:
    // 0x801F9D58: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801F9D5C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x801F9D60: jr          $ra
    // 0x801F9D64: nop

    return;
    // 0x801F9D64: nop

;}
RECOMP_FUNC void M9_FUN_801f9d68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9D68: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801F9D6C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801F9D70: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x801F9D74: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x801F9D78: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801F9D7C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x801F9D80: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801F9D84: jal         0x8013A334
    // 0x801F9D88: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_0;
    // 0x801F9D88: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801F9D8C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801F9D90: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F9D94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F9D98: addiu       $t1, $t1, -0x4410
    ctx->r9 = ADD32(ctx->r9, -0X4410);
    // 0x801F9D9C: lw          $t8, 0xE0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0XE0);
    // 0x801F9DA0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801F9DA4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801F9DA8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801F9DAC: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801F9DB0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801F9DB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801F9DB8: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801F9DBC: lw          $t9, 0xE8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XE8);
    // 0x801F9DC0: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801F9DC4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801F9DC8: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F9DCC: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F9DD0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801F9DD4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801F9DD8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801F9DDC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801F9DE0: addiu       $a0, $a0, -0x7414
    ctx->r4 = ADD32(ctx->r4, -0X7414);
    // 0x801F9DE4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801F9DE8: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801F9DEC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801F9DF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801F9DF4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801F9DF8: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801F9DFC: addiu       $a1, $zero, 0x986
    ctx->r5 = ADD32(0, 0X986);
    // 0x801F9E00: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x801F9E04: lwc1        $f18, 0x3C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x801F9E08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F9E0C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x801F9E10: lwc1        $f4, 0x40($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801F9E14: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801F9E18: lwc1        $f6, 0x44($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X44);
    // 0x801F9E1C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x801F9E20: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x801F9E24: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x801F9E28: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x801F9E2C: jal         0x8011AAF4
    // 0x801F9E30: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_1;
    // 0x801F9E30: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801F9E34: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x801F9E38: jal         0x80010550
    // 0x801F9E3C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_2;
    // 0x801F9E3C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_2:
    // 0x801F9E40: beql        $v0, $zero, L_801F9EB8
    if (ctx->r2 == 0) {
        // 0x801F9E44: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_801F9EB8;
    }
    goto skip_0;
    // 0x801F9E44: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x801F9E48: jal         0x8012C6B4
    // 0x801F9E4C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_3;
    // 0x801F9E4C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_3:
    // 0x801F9E50: addiu       $t4, $v0, -0x5
    ctx->r12 = ADD32(ctx->r2, -0X5);
    // 0x801F9E54: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x801F9E58: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F9E5C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801F9E60: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801F9E64: jal         0x8012C6B4
    // 0x801F9E68: swc1        $f18, -0x4FD8($at)
    MEM_W(-0X4FD8, ctx->r1) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_4;
    // 0x801F9E68: swc1        $f18, -0x4FD8($at)
    MEM_W(-0X4FD8, ctx->r1) = ctx->f18.u32l;
    after_4:
    // 0x801F9E6C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801F9E70: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F9E74: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801F9E78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801F9E7C: jal         0x8012C6B4
    // 0x801F9E80: swc1        $f6, -0x4FD4($at)
    MEM_W(-0X4FD4, ctx->r1) = ctx->f6.u32l;
    LOOKUP_FUNC(0x8012C6B4)(rdram, ctx);
        goto after_5;
    // 0x801F9E80: swc1        $f6, -0x4FD4($at)
    MEM_W(-0X4FD4, ctx->r1) = ctx->f6.u32l;
    after_5:
    // 0x801F9E84: addiu       $t5, $v0, -0x5
    ctx->r13 = ADD32(ctx->r2, -0X5);
    // 0x801F9E88: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x801F9E8C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x801F9E90: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801F9E94: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801F9E98: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801F9E9C: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801F9EA0: addiu       $a1, $a1, -0x613C
    ctx->r5 = ADD32(ctx->r5, -0X613C);
    // 0x801F9EA4: swc1        $f10, -0x4FD0($at)
    MEM_W(-0X4FD0, ctx->r1) = ctx->f10.u32l;
    // 0x801F9EA8: sh          $t6, 0x78($t7)
    MEM_H(0X78, ctx->r15) = ctx->r14;
    // 0x801F9EAC: jal         0x800058DC
    // 0x801F9EB0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801F9EB0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_6:
    // 0x801F9EB4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801F9EB8:
    // 0x801F9EB8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x801F9EBC: jr          $ra
    // 0x801F9EC0: nop

    return;
    // 0x801F9EC0: nop

;}
RECOMP_FUNC void M9_FUN_801f9ec4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F9EC4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801F9EC8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801F9ECC: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801F9ED0: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x801F9ED4: lw          $a2, 0x5C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X5C);
    // 0x801F9ED8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801F9EDC: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x801F9EE0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x801F9EE4: jal         0x8013A334
    // 0x801F9EE8: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_0;
    // 0x801F9EE8: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    after_0:
    // 0x801F9EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801F9EF0: jal         0x8012A94C
    // 0x801F9EF4: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8012A94C)(rdram, ctx);
        goto after_1;
    // 0x801F9EF4: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_1:
    // 0x801F9EF8: lui         $t6, 0x8021
    ctx->r14 = S32(0X8021 << 16);
    // 0x801F9EFC: addiu       $t6, $t6, 0x6EE8
    ctx->r14 = ADD32(ctx->r14, 0X6EE8);
    // 0x801F9F00: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801F9F04: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x801F9F08: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x801F9F0C: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x801F9F10: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x801F9F14: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801F9F18: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x801F9F1C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801F9F20: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801F9F24: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801F9F28: jal         0x8012CE9C
    // 0x801F9F2C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012CE9C)(rdram, ctx);
        goto after_2;
    // 0x801F9F2C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x801F9F30: bnel        $v0, $zero, L_801FA064
    if (ctx->r2 != 0) {
        // 0x801F9F34: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801FA064;
    }
    goto skip_0;
    // 0x801F9F34: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x801F9F38: jal         0x801FA2E0
    // 0x801F9F3C: nop

    LOOKUP_FUNC(0x801FA2E0)(rdram, ctx);
        goto after_3;
    // 0x801F9F3C: nop

    after_3:
    // 0x801F9F40: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801F9F44: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x801F9F48: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801F9F4C: jal         0x801F467C
    // 0x801F9F50: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x801F467C)(rdram, ctx);
        goto after_4;
    // 0x801F9F50: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_4:
    // 0x801F9F54: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x801F9F58: jal         0x80147768
    // 0x801F9F5C: lui         $a1, 0x41B0
    ctx->r5 = S32(0X41B0 << 16);
    LOOKUP_FUNC(0x80147768)(rdram, ctx);
        goto after_5;
    // 0x801F9F5C: lui         $a1, 0x41B0
    ctx->r5 = S32(0X41B0 << 16);
    after_5:
    // 0x801F9F60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801F9F64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801F9F68: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x801F9F6C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801F9F70: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801F9F74: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801F9F78: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801F9F7C: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x801F9F80: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801F9F84: addiu       $v1, $v1, -0x4FD8
    ctx->r3 = ADD32(ctx->r3, -0X4FD8);
    // 0x801F9F88: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801F9F8C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801F9F90: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801F9F94: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801F9F98: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F9F9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801F9FA0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801F9FA4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801F9FA8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801F9FAC: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801F9FB0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801F9FB4: addiu       $a0, $a0, -0x73D8
    ctx->r4 = ADD32(ctx->r4, -0X73D8);
    // 0x801F9FB8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801F9FBC: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801F9FC0: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801F9FC4: addiu       $a1, $zero, 0x9A6
    ctx->r5 = ADD32(0, 0X9A6);
    // 0x801F9FC8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801F9FCC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801F9FD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801F9FD4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801F9FD8: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801F9FDC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801F9FE0: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801F9FE4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x801F9FE8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801F9FEC: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801F9FF0: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x801F9FF4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801F9FF8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801F9FFC: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801FA000: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x801FA004: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801FA008: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801FA00C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801FA010: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801FA014: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801FA018: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801FA01C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x801FA020: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x801FA024: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801FA028: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x801FA02C: jal         0x8011AAF4
    // 0x801FA030: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_6;
    // 0x801FA030: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x801FA034: sb          $v0, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = ctx->r2;
    // 0x801FA038: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x801FA03C: jal         0x80010550
    // 0x801FA040: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_7;
    // 0x801FA040: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_7:
    // 0x801FA044: beq         $v0, $zero, L_801FA060
    if (ctx->r2 == 0) {
        // 0x801FA048: lb          $t6, 0x5B($sp)
        ctx->r14 = MEM_B(ctx->r29, 0X5B);
            goto L_801FA060;
    }
    // 0x801FA048: lb          $t6, 0x5B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X5B);
    // 0x801FA04C: bne         $t6, $zero, L_801FA060
    if (ctx->r14 != 0) {
        // 0x801FA050: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801FA060;
    }
    // 0x801FA050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801FA054: lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // 0x801FA058: jal         0x800058DC
    // 0x801FA05C: addiu       $a1, $a1, 0x5F5C
    ctx->r5 = ADD32(ctx->r5, 0X5F5C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801FA05C: addiu       $a1, $a1, 0x5F5C
    ctx->r5 = ADD32(ctx->r5, 0X5F5C);
    after_8:
L_801FA060:
    // 0x801FA060: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801FA064:
    // 0x801FA064: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801FA068: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x801FA06C: jr          $ra
    // 0x801FA070: nop

    return;
    // 0x801FA070: nop

;}
RECOMP_FUNC void M9_FUN_801fa074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FA078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FA07C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FA080: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FA084: jal         0x801F3B5C
    // 0x801FA088: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801F3B5C)(rdram, ctx);
        goto after_0;
    // 0x801FA088: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801FA08C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801FA090: addiu       $a1, $a1, 0x7014
    ctx->r5 = ADD32(ctx->r5, 0X7014);
    // 0x801FA094: jal         0x800058DC
    // 0x801FA098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801FA098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801FA09C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FA0A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FA0A4: jr          $ra
    // 0x801FA0A8: nop

    return;
    // 0x801FA0A8: nop

;}
RECOMP_FUNC void M9_FUN_801fa0ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA0AC: nop

;}
RECOMP_FUNC void M9_FUN_801fa0b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA0B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801FA0B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801FA0B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FA0BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801FA0C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801FA0C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801FA0C8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801FA0CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801FA0D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801FA0D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801FA0D8: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x801FA0DC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801FA0E0:
    // 0x801FA0E0: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x801FA0E4: beq         $t6, $zero, L_801FA0FC
    if (ctx->r14 == 0) {
        // 0x801FA0E8: or          $s2, $a1, $zero
        ctx->r18 = ctx->r5 | 0;
            goto L_801FA0FC;
    }
    // 0x801FA0E8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801FA0EC: jal         0x80133980
    // 0x801FA0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x801FA0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801FA0F4: b           L_801FA108
    // 0x801FA0F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_801FA108;
    // 0x801FA0F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_801FA0FC:
    // 0x801FA0FC: jal         0x801339D0
    // 0x801FA100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801339D0)(rdram, ctx);
        goto after_1;
    // 0x801FA100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801FA104: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_801FA108:
    // 0x801FA108: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801FA10C: slti        $at, $s1, 0x5
    ctx->r1 = SIGNED(ctx->r17) < 0X5 ? 1 : 0;
    // 0x801FA110: sra         $a1, $s2, 1
    ctx->r5 = S32(SIGNED(ctx->r18) >> 1);
    // 0x801FA114: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801FA118: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801FA11C: bne         $at, $zero, L_801FA0E0
    if (ctx->r1 != 0) {
        // 0x801FA120: andi        $s0, $s0, 0xFFFF
        ctx->r16 = ctx->r16 & 0XFFFF;
            goto L_801FA0E0;
    }
    // 0x801FA120: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x801FA124: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801FA128: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801FA12C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801FA130: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801FA134: jr          $ra
    // 0x801FA138: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801FA138: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fa13c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fa13c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA13C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801FA140: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801FA144: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FA148: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801FA14C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801FA150: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801FA154: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801FA158: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801FA15C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801FA160: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x801FA164: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801FA168: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x801FA16C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_801FA170:
    // 0x801FA170: jal         0x80133A24
    // 0x801FA174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801FA174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801FA178: beq         $v0, $zero, L_801FA188
    if (ctx->r2 == 0) {
        // 0x801FA17C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801FA188;
    }
    // 0x801FA17C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801FA180: addu        $s3, $s3, $s1
    ctx->r19 = ADD32(ctx->r19, ctx->r17);
    // 0x801FA184: andi        $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 & 0XFF;
L_801FA188:
    // 0x801FA188: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801FA18C: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x801FA190: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x801FA194: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x801FA198: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x801FA19C: bne         $at, $zero, L_801FA170
    if (ctx->r1 != 0) {
        // 0x801FA1A0: andi        $s0, $s0, 0xFFFF
        ctx->r16 = ctx->r16 & 0XFFFF;
            goto L_801FA170;
    }
    // 0x801FA1A0: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x801FA1A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801FA1A8: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x801FA1AC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801FA1B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801FA1B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801FA1B8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801FA1BC: jr          $ra
    // 0x801FA1C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801FA1C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fa1c4(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fa1c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA1C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FA1C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FA1CC: jal         0x801F546C
    // 0x801FA1D0: nop

    LOOKUP_FUNC(0x801F546C)(rdram, ctx);
        goto after_0;
    // 0x801FA1D0: nop

    after_0:
    // 0x801FA1D4: beq         $v0, $zero, L_801FA20C
    if (ctx->r2 == 0) {
        // 0x801FA1D8: lui         $a0, 0x8022
        ctx->r4 = S32(0X8022 << 16);
            goto L_801FA20C;
    }
    // 0x801FA1D8: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801FA1DC: jal         0x801FA13C
    // 0x801FA1E0: lhu         $a0, -0x4F2E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4F2E);
    LOOKUP_FUNC(0x801FA13C)(rdram, ctx);
        goto after_1;
    // 0x801FA1E0: lhu         $a0, -0x4F2E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4F2E);
    after_1:
    // 0x801FA1E4: blez        $v0, L_801FA1F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801FA1E8: andi        $a1, $v0, 0xFF
        ctx->r5 = ctx->r2 & 0XFF;
            goto L_801FA1F8;
    }
    // 0x801FA1E8: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x801FA1EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801FA1F0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x801FA1F4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_801FA1F8:
    // 0x801FA1F8: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x801FA1FC: jal         0x801FA0B0
    // 0x801FA200: lhu         $a0, -0x4F2E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4F2E);
    LOOKUP_FUNC(0x801FA0B0)(rdram, ctx);
        goto after_2;
    // 0x801FA200: lhu         $a0, -0x4F2E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4F2E);
    after_2:
    // 0x801FA204: b           L_801FA210
    // 0x801FA208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FA210;
    // 0x801FA208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FA20C:
    // 0x801FA20C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FA210:
    // 0x801FA210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FA214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FA218: jr          $ra
    // 0x801FA21C: nop

    return;
    // 0x801FA21C: nop

;}
RECOMP_FUNC void M9_FUN_801fa220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA220: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801FA224: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FA228: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x801FA22C: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x801FA230: sh          $t8, -0x4F2E($at)
    MEM_H(-0X4F2E, ctx->r1) = ctx->r24;
    // 0x801FA234: lw          $t9, 0x38($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X38);
    // 0x801FA238: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801FA23C: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x801FA240: jr          $ra
    // 0x801FA244: sb          $t1, -0x4F30($at)
    MEM_B(-0X4F30, ctx->r1) = ctx->r9;
    return;
    // 0x801FA244: sb          $t1, -0x4F30($at)
    MEM_B(-0X4F30, ctx->r1) = ctx->r9;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fa248(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fa248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA248: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801FA24C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801FA250: beq         $a0, $zero, L_801FA294
    if (ctx->r4 == 0) {
        // 0x801FA254: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_801FA294;
    }
    // 0x801FA254: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801FA258: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801FA25C: lw          $a1, 0x30($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X30);
L_801FA260:
    // 0x801FA260: lbu         $v0, 0x4B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X4B);
    // 0x801FA264: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x801FA268: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801FA26C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801FA270: bgezl       $v0, L_801FA288
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801FA274: sb          $v0, 0x4B($a1)
        MEM_B(0X4B, ctx->r5) = ctx->r2;
            goto L_801FA288;
    }
    goto skip_0;
    // 0x801FA274: sb          $v0, 0x4B($a1)
    MEM_B(0X4B, ctx->r5) = ctx->r2;
    skip_0:
    // 0x801FA278: sb          $zero, 0x22($a0)
    MEM_B(0X22, ctx->r4) = 0;
    // 0x801FA27C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801FA280: lw          $a1, 0x30($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X30);
    // 0x801FA284: sb          $v0, 0x4B($a1)
    MEM_B(0X4B, ctx->r5) = ctx->r2;
L_801FA288:
    // 0x801FA288: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    // 0x801FA28C: bnel        $a0, $zero, L_801FA260
    if (ctx->r4 != 0) {
        // 0x801FA290: lw          $a1, 0x30($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X30);
            goto L_801FA260;
    }
    goto skip_1;
    // 0x801FA290: lw          $a1, 0x30($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X30);
    skip_1:
L_801FA294:
    // 0x801FA294: jr          $ra
    // 0x801FA298: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801FA298: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fa29c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fa29c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA29C: beq         $a0, $zero, L_801FA2D8
    if (ctx->r4 == 0) {
        // 0x801FA2A0: nop
    
            goto L_801FA2D8;
    }
    // 0x801FA2A0: nop

    // 0x801FA2A4: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
L_801FA2A8:
    // 0x801FA2A8: lbu         $v0, 0xB($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XB);
    // 0x801FA2AC: addiu       $v0, $v0, -0x11
    ctx->r2 = ADD32(ctx->r2, -0X11);
    // 0x801FA2B0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x801FA2B4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801FA2B8: bgezl       $v0, L_801FA2CC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801FA2BC: sb          $v0, 0xB($v1)
        MEM_B(0XB, ctx->r3) = ctx->r2;
            goto L_801FA2CC;
    }
    goto skip_0;
    // 0x801FA2BC: sb          $v0, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r2;
    skip_0:
    // 0x801FA2C0: sb          $zero, 0x22($a0)
    MEM_B(0X22, ctx->r4) = 0;
    // 0x801FA2C4: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
    // 0x801FA2C8: sb          $v0, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r2;
L_801FA2CC:
    // 0x801FA2CC: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    // 0x801FA2D0: bnel        $a0, $zero, L_801FA2A8
    if (ctx->r4 != 0) {
        // 0x801FA2D4: lw          $v1, 0x30($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X30);
            goto L_801FA2A8;
    }
    goto skip_1;
    // 0x801FA2D4: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
    skip_1:
L_801FA2D8:
    // 0x801FA2D8: jr          $ra
    // 0x801FA2DC: nop

    return;
    // 0x801FA2DC: nop

;}
RECOMP_FUNC void M9_FUN_801fa2e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA2E0: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x801FA2E4: addiu       $v1, $v1, 0x70B4
    ctx->r3 = ADD32(ctx->r3, 0X70B4);
    // 0x801FA2E8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fa2ec(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fa2ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA2EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801FA2F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801FA2F4: bne         $t6, $zero, L_801FA360
    if (ctx->r14 != 0) {
        // 0x801FA2F8: lui         $t7, 0x8021
        ctx->r15 = S32(0X8021 << 16);
            goto L_801FA360;
    }
    // 0x801FA2F8: lui         $t7, 0x8021
    ctx->r15 = S32(0X8021 << 16);
    // 0x801FA2FC: addiu       $t7, $t7, 0x7028
    ctx->r15 = ADD32(ctx->r15, 0X7028);
    // 0x801FA300: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801FA304: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801FA308: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x801FA30C: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801FA310: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801FA314: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801FA318: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x801FA31C: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x801FA320: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801FA324: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801FA328: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x801FA32C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801FA330: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801FA334: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801FA338: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x801FA33C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801FA340: jal         0x8012C4D0
    // 0x801FA344: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x801FA344: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x801FA348: lui         $v1, 0x8021
    ctx->r3 = S32(0X8021 << 16);
    // 0x801FA34C: addiu       $v1, $v1, 0x70B4
    ctx->r3 = ADD32(ctx->r3, 0X70B4);
    // 0x801FA350: beq         $v0, $zero, L_801FA360
    if (ctx->r2 == 0) {
        // 0x801FA354: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_801FA360;
    }
    // 0x801FA354: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801FA358: b           L_801FA364
    // 0x801FA35C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FA364;
    // 0x801FA35C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FA360:
    // 0x801FA360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FA364:
    // 0x801FA364: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801FA368: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801FA36C: jr          $ra
    // 0x801FA370: nop

    return;
    // 0x801FA370: nop

;}
RECOMP_FUNC void M9_FUN_801fa374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA374: lui         $t0, 0x8021
    ctx->r8 = S32(0X8021 << 16);
    // 0x801FA378: addiu       $t0, $t0, 0x70B4
    ctx->r8 = ADD32(ctx->r8, 0X70B4);
    // 0x801FA37C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fa380(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fa380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA380: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801FA384: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801FA388: bne         $t6, $zero, L_801FA3FC
    if (ctx->r14 != 0) {
        // 0x801FA38C: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_801FA3FC;
    }
    // 0x801FA38C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801FA390: lui         $t7, 0x8021
    ctx->r15 = S32(0X8021 << 16);
    // 0x801FA394: addiu       $t7, $t7, 0x703C
    ctx->r15 = ADD32(ctx->r15, 0X703C);
    // 0x801FA398: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801FA39C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x801FA3A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801FA3A4: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801FA3A8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801FA3AC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801FA3B0: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x801FA3B4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801FA3B8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801FA3BC: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x801FA3C0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801FA3C4: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801FA3C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801FA3CC: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x801FA3D0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801FA3D4: jal         0x8012C4D0
    // 0x801FA3D8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x801FA3D8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x801FA3DC: lui         $t0, 0x8021
    ctx->r8 = S32(0X8021 << 16);
    // 0x801FA3E0: addiu       $t0, $t0, 0x70B4
    ctx->r8 = ADD32(ctx->r8, 0X70B4);
    // 0x801FA3E4: beq         $v0, $zero, L_801FA3FC
    if (ctx->r2 == 0) {
        // 0x801FA3E8: sw          $v0, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r2;
            goto L_801FA3FC;
    }
    // 0x801FA3E8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x801FA3EC: lbu         $t2, 0x2B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2B);
    // 0x801FA3F0: sb          $t2, 0xAF($v0)
    MEM_B(0XAF, ctx->r2) = ctx->r10;
    // 0x801FA3F4: b           L_801FA400
    // 0x801FA3F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FA400;
    // 0x801FA3F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FA3FC:
    // 0x801FA3FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FA400:
    // 0x801FA400: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801FA404: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801FA408: jr          $ra
    // 0x801FA40C: nop

    return;
    // 0x801FA40C: nop

;}
RECOMP_FUNC void M9_FUN_801fa410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA410: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801FA414: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801FA418: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801FA41C: beq         $a0, $zero, L_801FA504
    if (ctx->r4 == 0) {
        // 0x801FA420: sw          $ra, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r31;
            goto L_801FA504;
    }
    // 0x801FA420: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801FA424: lui         $t6, 0x8021
    ctx->r14 = S32(0X8021 << 16);
    // 0x801FA428: addiu       $t6, $t6, 0x7064
    ctx->r14 = ADD32(ctx->r14, 0X7064);
    // 0x801FA42C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801FA430: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801FA434: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801FA438: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x801FA43C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801FA440: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801FA444: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x801FA448: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801FA44C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801FA450: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x801FA454: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801FA458: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801FA45C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801FA460: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801FA464: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801FA468: jal         0x8012C4D0
    // 0x801FA46C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x801FA46C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x801FA470: lui         $a0, 0x8021
    ctx->r4 = S32(0X8021 << 16);
    // 0x801FA474: addiu       $a0, $a0, 0x70B8
    ctx->r4 = ADD32(ctx->r4, 0X70B8);
    // 0x801FA478: beq         $v0, $zero, L_801FA490
    if (ctx->r2 == 0) {
        // 0x801FA47C: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_801FA490;
    }
    // 0x801FA47C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x801FA480: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x801FA484: sh          $t0, 0x72($v0)
    MEM_H(0X72, ctx->r2) = ctx->r8;
    // 0x801FA488: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x801FA48C: sw          $t1, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r9;
L_801FA490:
    // 0x801FA490: lui         $t2, 0x8021
    ctx->r10 = S32(0X8021 << 16);
    // 0x801FA494: addiu       $t2, $t2, 0x7078
    ctx->r10 = ADD32(ctx->r10, 0X7078);
    // 0x801FA498: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801FA49C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801FA4A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801FA4A4: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x801FA4A8: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801FA4AC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801FA4B0: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x801FA4B4: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801FA4B8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801FA4BC: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x801FA4C0: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x801FA4C4: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801FA4C8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801FA4CC: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x801FA4D0: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x801FA4D4: jal         0x8012C4D0
    // 0x801FA4D8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_1;
    // 0x801FA4D8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_1:
    // 0x801FA4DC: lui         $a0, 0x8021
    ctx->r4 = S32(0X8021 << 16);
    // 0x801FA4E0: addiu       $a0, $a0, 0x70BC
    ctx->r4 = ADD32(ctx->r4, 0X70BC);
    // 0x801FA4E4: beq         $v0, $zero, L_801FA4FC
    if (ctx->r2 == 0) {
        // 0x801FA4E8: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_801FA4FC;
    }
    // 0x801FA4E8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x801FA4EC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x801FA4F0: sh          $t6, 0x72($v0)
    MEM_H(0X72, ctx->r2) = ctx->r14;
    // 0x801FA4F4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x801FA4F8: sw          $t7, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r15;
L_801FA4FC:
    // 0x801FA4FC: b           L_801FA508
    // 0x801FA500: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FA508;
    // 0x801FA500: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FA504:
    // 0x801FA504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FA508:
    // 0x801FA508: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801FA50C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801FA510: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801FA514: jr          $ra
    // 0x801FA518: nop

    return;
    // 0x801FA518: nop

;}
RECOMP_FUNC void M9_FUN_801fa51c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA51C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FA520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FA524: beq         $a0, $zero, L_801FA55C
    if (ctx->r4 == 0) {
        // 0x801FA528: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_801FA55C;
    }
    // 0x801FA528: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801FA52C: lw          $a0, 0xAC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XAC);
    // 0x801FA530: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FA534: addiu       $a1, $a1, -0x5548
    ctx->r5 = ADD32(ctx->r5, -0X5548);
    // 0x801FA538: jal         0x800058DC
    // 0x801FA53C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801FA53C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801FA540: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801FA544: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FA548: addiu       $a1, $a1, -0x51F8
    ctx->r5 = ADD32(ctx->r5, -0X51F8);
    // 0x801FA54C: jal         0x800058DC
    // 0x801FA550: lw          $a0, 0xB0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XB0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801FA550: lw          $a0, 0xB0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XB0);
    after_1:
    // 0x801FA554: b           L_801FA560
    // 0x801FA558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FA560;
    // 0x801FA558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FA55C:
    // 0x801FA55C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FA560:
    // 0x801FA560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FA564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FA568: jr          $ra
    // 0x801FA56C: nop

    return;
    // 0x801FA56C: nop

;}
RECOMP_FUNC void M9_FUN_801fa570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FA574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FA578: beq         $a0, $zero, L_801FA5B0
    if (ctx->r4 == 0) {
        // 0x801FA57C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_801FA5B0;
    }
    // 0x801FA57C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801FA580: lw          $a0, 0xAC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XAC);
    // 0x801FA584: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FA588: addiu       $a1, $a1, -0x5438
    ctx->r5 = ADD32(ctx->r5, -0X5438);
    // 0x801FA58C: jal         0x800058DC
    // 0x801FA590: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801FA590: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801FA594: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801FA598: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FA59C: addiu       $a1, $a1, -0x51CC
    ctx->r5 = ADD32(ctx->r5, -0X51CC);
    // 0x801FA5A0: jal         0x800058DC
    // 0x801FA5A4: lw          $a0, 0xB0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XB0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801FA5A4: lw          $a0, 0xB0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XB0);
    after_1:
    // 0x801FA5A8: b           L_801FA5B4
    // 0x801FA5AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FA5B4;
    // 0x801FA5AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FA5B0:
    // 0x801FA5B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FA5B4:
    // 0x801FA5B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FA5B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FA5BC: jr          $ra
    // 0x801FA5C0: nop

    return;
    // 0x801FA5C0: nop

;}
RECOMP_FUNC void M9_FUN_801fa5c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA5C4: lui         $a0, 0x8021
    ctx->r4 = S32(0X8021 << 16);
    // 0x801FA5C8: lw          $a0, 0x70C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70C0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fa5cc(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fa5cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA5CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FA5D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FA5D4: beq         $a0, $zero, L_801FA5F0
    if (ctx->r4 == 0) {
        // 0x801FA5D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801FA5F0;
    }
    // 0x801FA5D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801FA5DC: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801FA5E0: jal         0x800058DC
    // 0x801FA5E4: addiu       $a1, $a1, -0x4EC4
    ctx->r5 = ADD32(ctx->r5, -0X4EC4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801FA5E4: addiu       $a1, $a1, -0x4EC4
    ctx->r5 = ADD32(ctx->r5, -0X4EC4);
    after_0:
    // 0x801FA5E8: b           L_801FA5F0
    // 0x801FA5EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FA5F0;
    // 0x801FA5EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FA5F0:
    // 0x801FA5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FA5F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FA5F8: jr          $ra
    // 0x801FA5FC: nop

    return;
    // 0x801FA5FC: nop

;}
RECOMP_FUNC void M9_FUN_801fa600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA600: beq         $a0, $zero, L_801FA61C
    if (ctx->r4 == 0) {
            // 0x801FA604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    LOOKUP_FUNC(0x801FA61C)(rdram, ctx);
    return;
    }
    // 0x801FA604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801FA608: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801FA60C: lw          $v0, 0x10($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X10);
    // 0x801FA610: srl         $v0, $v0, 24
    ctx->r2 = S32(U32(ctx->r2) >> 24);
    // 0x801FA614: jr          $ra
    // 0x801FA618: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    return;
    // 0x801FA618: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801fa61c(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801fa61c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA61C: jr          $ra
    // 0x801FA620: nop

    return;
    // 0x801FA620: nop

;}
RECOMP_FUNC void M9_FUN_801fa624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA624: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801FA628: lui         $t6, 0x8021
    ctx->r14 = S32(0X8021 << 16);
    // 0x801FA62C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801FA630: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801FA634: addiu       $t6, $t6, 0x708C
    ctx->r14 = ADD32(ctx->r14, 0X708C);
    // 0x801FA638: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801FA63C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801FA640: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801FA644: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x801FA648: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801FA64C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801FA650: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x801FA654: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x801FA658: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801FA65C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801FA660: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x801FA664: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801FA668: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801FA66C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801FA670: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801FA674: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801FA678: jal         0x8012C4D0
    // 0x801FA67C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x801FA67C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x801FA680: beq         $v0, $zero, L_801FA69C
    if (ctx->r2 == 0) {
        // 0x801FA684: addiu       $t0, $zero, 0x5
        ctx->r8 = ADD32(0, 0X5);
            goto L_801FA69C;
    }
    // 0x801FA684: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x801FA688: sh          $t0, 0x3C($v0)
    MEM_H(0X3C, ctx->r2) = ctx->r8;
    // 0x801FA68C: lhu         $t1, 0x2A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2A);
    // 0x801FA690: sh          $t1, 0x94($v0)
    MEM_H(0X94, ctx->r2) = ctx->r9;
    // 0x801FA694: b           L_801FA6A0
    // 0x801FA698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801FA6A0;
    // 0x801FA698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801FA69C:
    // 0x801FA69C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801FA6A0:
    // 0x801FA6A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801FA6A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801FA6A8: jr          $ra
    // 0x801FA6AC: nop

    return;
    // 0x801FA6AC: nop

;}
RECOMP_FUNC void M9_FUN_801fa6b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801FA6B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801FA6B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801FA6B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801FA6BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801FA6C0: lhu         $t6, 0x3C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X3C);
    // 0x801FA6C4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801FA6C8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x801FA6CC: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x801FA6D0: bne         $t8, $zero, L_801FA6EC
    if (ctx->r24 != 0) {
        // 0x801FA6D4: sh          $t7, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r15;
            goto L_801FA6EC;
    }
    // 0x801FA6D4: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x801FA6D8: lhu         $a0, 0x94($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X94);
    // 0x801FA6DC: jal         0x80126E88
    // 0x801FA6E0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_0;
    // 0x801FA6E0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x801FA6E4: jal         0x80005700
    // 0x801FA6E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801FA6E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_801FA6EC:
    // 0x801FA6EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801FA6F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801FA6F4: jr          $ra
    // 0x801FA6F8: nop

    return;
    // 0x801FA6F8: nop

;}
