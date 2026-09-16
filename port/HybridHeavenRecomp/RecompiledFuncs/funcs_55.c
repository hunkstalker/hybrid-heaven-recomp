#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801d4f1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4F1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D4F20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D4F24: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801D4F28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D4F2C: jal         0x801CC540
    // 0x801D4F30: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D4F30: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D4F34: beq         $v0, $zero, L_801D4F54
    if (ctx->r2 == 0) {
        // 0x801D4F38: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D4F54;
    }
    // 0x801D4F38: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D4F3C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D4F40: addiu       $a1, $a1, 0x4F1C
    ctx->r5 = ADD32(ctx->r5, 0X4F1C);
    // 0x801D4F44: jal         0x800058DC
    // 0x801D4F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D4F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801D4F4C: b           L_801D516C
    // 0x801D4F50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801D516C;
    // 0x801D4F50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D4F54:
    // 0x801D4F54: lw          $t6, -0x49A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X49A0);
    // 0x801D4F58: beq         $t6, $zero, L_801D4FAC
    if (ctx->r14 == 0) {
        // 0x801D4F5C: nop
    
            goto L_801D4FAC;
    }
    // 0x801D4F5C: nop

    // 0x801D4F60: jal         0x80006214
    // 0x801D4F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D4F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801D4F68: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D4F6C: lw          $t7, -0x49A0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X49A0);
    // 0x801D4F70: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D4F74: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D4F78: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D4F7C: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D4F80: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D4F84: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D4F88: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D4F8C: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D4F90: jal         0x8013A28C
    // 0x801D4F94: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D4F94: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D4F98: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x801D4F9C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D4FA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4FA4: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D4FA8: sw          $zero, -0x49A0($at)
    MEM_W(-0X49A0, ctx->r1) = 0;
L_801D4FAC:
    // 0x801D4FAC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D4FB0: lw          $v0, -0x499C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X499C);
    // 0x801D4FB4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D4FB8: beq         $v0, $zero, L_801D5084
    if (ctx->r2 == 0) {
        // 0x801D4FBC: nop
    
            goto L_801D5084;
    }
    // 0x801D4FBC: nop

    // 0x801D4FC0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D4FC4: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x801D4FC8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D4FCC: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D4FD0: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D4FD4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D4FD8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D4FDC: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D4FE0: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D4FE4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D4FE8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D4FEC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D4FF0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D4FF4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D4FF8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D4FFC: nop

    // 0x801D5000: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D5004: beql        $t4, $zero, L_801D5054
    if (ctx->r12 == 0) {
        // 0x801D5008: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D5054;
    }
    goto skip_0;
    // 0x801D5008: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D500C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D5010: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D5014: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D5018: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D501C: nop

    // 0x801D5020: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D5024: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D5028: nop

    // 0x801D502C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D5030: bne         $t4, $zero, L_801D5048
    if (ctx->r12 != 0) {
        // 0x801D5034: nop
    
            goto L_801D5048;
    }
    // 0x801D5034: nop

    // 0x801D5038: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D503C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D5040: b           L_801D5060
    // 0x801D5044: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D5060;
    // 0x801D5044: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D5048:
    // 0x801D5048: b           L_801D5060
    // 0x801D504C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D5060;
    // 0x801D504C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D5050: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D5054:
    // 0x801D5054: nop

    // 0x801D5058: bltz        $t4, L_801D5048
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D505C: nop
    
            goto L_801D5048;
    }
    // 0x801D505C: nop

L_801D5060:
    // 0x801D5060: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D5064: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D5068: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D506C: jal         0x80011140
    // 0x801D5070: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D5070: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D5074: beq         $v0, $zero, L_801D5130
    if (ctx->r2 == 0) {
        // 0x801D5078: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D5130;
    }
    // 0x801D5078: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D507C: b           L_801D5130
    // 0x801D5080: sw          $zero, -0x499C($at)
    MEM_W(-0X499C, ctx->r1) = 0;
        goto L_801D5130;
    // 0x801D5080: sw          $zero, -0x499C($at)
    MEM_W(-0X499C, ctx->r1) = 0;
L_801D5084:
    // 0x801D5084: jal         0x80010550
    // 0x801D5088: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D5088: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    after_5:
    // 0x801D508C: beq         $v0, $zero, L_801D50A4
    if (ctx->r2 == 0) {
        // 0x801D5090: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D50A4;
    }
    // 0x801D5090: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5094: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D5098: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D509C: b           L_801D50A8
    // 0x801D50A0: sw          $t5, -0x497C($at)
    MEM_W(-0X497C, ctx->r1) = ctx->r13;
        goto L_801D50A8;
    // 0x801D50A0: sw          $t5, -0x497C($at)
    MEM_W(-0X497C, ctx->r1) = ctx->r13;
L_801D50A4:
    // 0x801D50A4: sw          $zero, -0x497C($at)
    MEM_W(-0X497C, ctx->r1) = 0;
L_801D50A8:
    // 0x801D50A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801D50AC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D50B0: addiu       $t6, $t6, 0x1640
    ctx->r14 = ADD32(ctx->r14, 0X1640);
    // 0x801D50B4: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x801D50B8: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801D50BC: addiu       $t2, $t2, -0x3FD8
    ctx->r10 = ADD32(ctx->r10, -0X3FD8);
    // 0x801D50C0: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D50C4: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D50C8: addiu       $t1, $t1, 0x1630
    ctx->r9 = ADD32(ctx->r9, 0X1630);
    // 0x801D50CC: lw          $t0, 0x5C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X5C);
    // 0x801D50D0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D50D4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D50D8: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x801D50DC: lw          $t9, 0x60($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X60);
    // 0x801D50E0: addiu       $a0, $a0, 0x1650
    ctx->r4 = ADD32(ctx->r4, 0X1650);
    // 0x801D50E4: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x801D50E8: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x801D50EC: lw          $t0, 0x64($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X64);
    // 0x801D50F0: sw          $t0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r8;
    // 0x801D50F4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801D50F8: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801D50FC: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x801D5100: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801D5104: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x801D5108: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x801D510C: sw          $a1, -0x49BC($at)
    MEM_W(-0X49BC, ctx->r1) = ctx->r5;
    // 0x801D5110: jal         0x8013A334
    // 0x801D5114: lw          $a2, 0x5C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_6;
    // 0x801D5114: lw          $a2, 0x5C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X5C);
    after_6:
    // 0x801D5118: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D511C: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    // 0x801D5120: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801D5124: lw          $a2, 0x5C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X5C);
    // 0x801D5128: jal         0x8013A334
    // 0x801D512C: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_7;
    // 0x801D512C: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    after_7:
L_801D5130:
    // 0x801D5130: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801D5134: lw          $t5, -0x4984($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4984);
    // 0x801D5138: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D513C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D5140: beq         $t5, $zero, L_801D5154
    if (ctx->r13 == 0) {
        // 0x801D5144: lui         $t8, 0x801E
        ctx->r24 = S32(0X801E << 16);
            goto L_801D5154;
    }
    // 0x801D5144: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D5148: lw          $t7, -0x4980($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4980);
    // 0x801D514C: lw          $t6, -0x4988($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4988);
    // 0x801D5150: sb          $t7, 0x22($t6)
    MEM_B(0X22, ctx->r14) = ctx->r15;
L_801D5154:
    // 0x801D5154: lw          $t8, -0x49B8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X49B8);
    // 0x801D5158: beql        $t8, $zero, L_801D516C
    if (ctx->r24 == 0) {
        // 0x801D515C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801D516C;
    }
    goto skip_1;
    // 0x801D515C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801D5160: jal         0x801D52B8
    // 0x801D5164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801D52B8)(rdram, ctx);
        goto after_8;
    // 0x801D5164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801D5168: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D516C:
    // 0x801D516C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801D5170: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D5174: jr          $ra
    // 0x801D5178: nop

    return;
    // 0x801D5178: nop

;}
RECOMP_FUNC void M24_FUN_801d517c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D517C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5180: jr          $ra
    // 0x801D5184: sw          $a0, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = ctx->r4;
    return;
    // 0x801D5184: sw          $a0, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5188(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5188: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D518C: jr          $ra
    // 0x801D5190: sw          $a0, -0x4980($at)
    MEM_W(-0X4980, ctx->r1) = ctx->r4;
    return;
    // 0x801D5190: sw          $a0, -0x4980($at)
    MEM_W(-0X4980, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5194(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5194: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D5198: lw          $v0, -0x499C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X499C);
    // 0x801D519C: jr          $ra
    // 0x801D51A0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D51A0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d51a4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d51a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D51A4: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D51A8: lw          $t6, -0x499C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X499C);
    // 0x801D51AC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D51B0: beq         $t6, $zero, L_801D51C0
    if (ctx->r14 == 0) {
            // 0x801D51B4: nop

    LOOKUP_FUNC(0x801D51C0)(rdram, ctx);
    return;
    }
    // 0x801D51B4: nop

    // 0x801D51B8: jr          $ra
    // 0x801D51BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D51BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d51c0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d51c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D51C0: lw          $t7, -0x49A0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X49A0);
    // 0x801D51C4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D51C8: beq         $t7, $zero, L_801D51D8
    if (ctx->r15 == 0) {
            // 0x801D51CC: nop

    LOOKUP_FUNC(0x801D51D8)(rdram, ctx);
    return;
    }
    // 0x801D51CC: nop

    // 0x801D51D0: jr          $ra
    // 0x801D51D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D51D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d51d8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d51d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D51D8: lw          $v0, -0x497C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X497C);
    // 0x801D51DC: jr          $ra
    // 0x801D51E0: nop

    return;
    // 0x801D51E0: nop

;}
RECOMP_FUNC void M24_FUN_801d51e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D51E4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D51E8: jr          $ra
    // 0x801D51EC: addiu       $v0, $v0, 0x1630
    ctx->r2 = ADD32(ctx->r2, 0X1630);
    return;
    // 0x801D51EC: addiu       $v0, $v0, 0x1630
    ctx->r2 = ADD32(ctx->r2, 0X1630);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d51f0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d51f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D51F0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D51F4: addiu       $v0, $v0, -0x49B8
    ctx->r2 = ADD32(ctx->r2, -0X49B8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d51f8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d51f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D51F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D51FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D5200: beq         $a0, $zero, L_801D522C
    if (ctx->r4 == 0) {
        // 0x801D5204: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801D522C;
    }
    // 0x801D5204: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801D5208: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D520C: jal         0x801C0B2C
    // 0x801D5210: sw          $zero, -0x4974($at)
    MEM_W(-0X4974, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D5210: sw          $zero, -0x4974($at)
    MEM_W(-0X4974, ctx->r1) = 0;
    after_0:
    // 0x801D5214: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5218: sw          $v0, 0x1670($at)
    MEM_W(0X1670, ctx->r1) = ctx->r2;
    // 0x801D521C: sw          $v1, 0x1674($at)
    MEM_W(0X1674, ctx->r1) = ctx->r3;
    // 0x801D5220: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5224: b           L_801D5240
    // 0x801D5228: sw          $zero, 0x1678($at)
    MEM_W(0X1678, ctx->r1) = 0;
        goto L_801D5240;
    // 0x801D5228: sw          $zero, 0x1678($at)
    MEM_W(0X1678, ctx->r1) = 0;
L_801D522C:
    // 0x801D522C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D5230: lw          $a0, -0x49C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X49C0);
    // 0x801D5234: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // 0x801D5238: jal         0x8012D844
    // 0x801D523C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801D523C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_801D5240:
    // 0x801D5240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D5244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D5248: jr          $ra
    // 0x801D524C: nop

    return;
    // 0x801D524C: nop

;}
RECOMP_FUNC void M24_FUN_801d5250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5250: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D5254: addiu       $v1, $v1, 0x1640
    ctx->r3 = ADD32(ctx->r3, 0X1640);
    // 0x801D5258: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D525C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D5260: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D5264: beql        $a0, $t6, L_801D5278
    if (ctx->r4 == ctx->r14) {
        // 0x801D5268: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D5278;
    }
    goto skip_0;
    // 0x801D5268: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D526C: jr          $ra
    // 0x801D5270: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D5270: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D5274: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D5278:
    // 0x801D5278: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D527C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D5280: jr          $ra
    // 0x801D5284: nop

    return;
    // 0x801D5284: nop

;}
RECOMP_FUNC void M24_FUN_801d5288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5288: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D528C: jr          $ra
    // 0x801D5290: lw          $v0, -0x49C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X49C0);
    return;
    // 0x801D5290: lw          $v0, -0x49C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X49C0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5294(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5294: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D5298: jr          $ra
    // 0x801D529C: lw          $v0, -0x49BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X49BC);
    return;
    // 0x801D529C: lw          $v0, -0x49BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X49BC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d52a0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d52a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D52A0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D52A4: jr          $ra
    // 0x801D52A8: addiu       $v0, $v0, 0x1650
    ctx->r2 = ADD32(ctx->r2, 0X1650);
    return;
    // 0x801D52A8: addiu       $v0, $v0, 0x1650
    ctx->r2 = ADD32(ctx->r2, 0X1650);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d52ac(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d52ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D52AC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D52B0: jr          $ra
    // 0x801D52B4: addiu       $v0, $v0, 0x1660
    ctx->r2 = ADD32(ctx->r2, 0X1660);
    return;
    // 0x801D52B4: addiu       $v0, $v0, 0x1660
    ctx->r2 = ADD32(ctx->r2, 0X1660);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d52b8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d52b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D52B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D52BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D52C0: jal         0x801C0B2C
    // 0x801D52C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D52C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D52C8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D52CC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D52D0: lw          $t7, 0x1674($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1674);
    // 0x801D52D4: lw          $t6, 0x1670($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1670);
    // 0x801D52D8: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801D52DC: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801D52E0: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801D52E4: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801D52E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D52EC: jal         0x80034C24
    // 0x801D52F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801D52F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D52F4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D52F8: ldc1        $f4, -0x2A70($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2A70);
    // 0x801D52FC: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D5300: addiu       $a3, $a3, 0x1678
    ctx->r7 = ADD32(ctx->r7, 0X1678);
    // 0x801D5304: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801D5308: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801D530C: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D5310: addiu       $t1, $t1, -0x4970
    ctx->r9 = ADD32(ctx->r9, -0X4970);
    // 0x801D5314: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801D5318: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x801D531C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D5320: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D5324: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801D5328: nop

    // 0x801D532C: bc1fl       L_801D540C
    if (!c1cs) {
        // 0x801D5330: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D540C;
    }
    goto skip_0;
    // 0x801D5330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D5334: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801D5338: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D533C: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // 0x801D5340: beq         $v0, $zero, L_801D5364
    if (ctx->r2 == 0) {
        // 0x801D5344: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801D5364;
    }
    // 0x801D5344: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D5348: beq         $v0, $at, L_801D5380
    if (ctx->r2 == ctx->r1) {
        // 0x801D534C: addiu       $a1, $zero, 0x118
        ctx->r5 = ADD32(0, 0X118);
            goto L_801D5380;
    }
    // 0x801D534C: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // 0x801D5350: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D5354: beq         $v0, $at, L_801D53A0
    if (ctx->r2 == ctx->r1) {
        // 0x801D5358: addiu       $a1, $zero, 0x118
        ctx->r5 = ADD32(0, 0X118);
            goto L_801D53A0;
    }
    // 0x801D5358: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // 0x801D535C: b           L_801D53C0
    // 0x801D5360: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801D53C0;
    // 0x801D5360: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D5364:
    // 0x801D5364: jal         0x8012D844
    // 0x801D5368: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801D5368: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D536C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D5370: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D5374: addiu       $a3, $a3, 0x1678
    ctx->r7 = ADD32(ctx->r7, 0X1678);
    // 0x801D5378: b           L_801D53BC
    // 0x801D537C: lw          $a0, 0x1678($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1678);
        goto L_801D53BC;
    // 0x801D537C: lw          $a0, 0x1678($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1678);
L_801D5380:
    // 0x801D5380: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D5384: jal         0x8012D844
    // 0x801D5388: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801D5388: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801D538C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D5390: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D5394: addiu       $a3, $a3, 0x1678
    ctx->r7 = ADD32(ctx->r7, 0X1678);
    // 0x801D5398: b           L_801D53BC
    // 0x801D539C: lw          $a0, 0x1678($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1678);
        goto L_801D53BC;
    // 0x801D539C: lw          $a0, 0x1678($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1678);
L_801D53A0:
    // 0x801D53A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D53A4: jal         0x8012D844
    // 0x801D53A8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x801D53A8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x801D53AC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D53B0: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D53B4: addiu       $a3, $a3, 0x1678
    ctx->r7 = ADD32(ctx->r7, 0X1678);
    // 0x801D53B8: lw          $a0, 0x1678($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1678);
L_801D53BC:
    // 0x801D53BC: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D53C0:
    // 0x801D53C0: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    // 0x801D53C4: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801D53C8: bne         $at, $zero, L_801D53F4
    if (ctx->r1 != 0) {
        // 0x801D53CC: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801D53F4;
    }
    // 0x801D53CC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801D53D0: jal         0x801C0B2C
    // 0x801D53D4: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801D53D4: nop

    after_5:
    // 0x801D53D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D53DC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D53E0: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D53E4: addiu       $a3, $a3, 0x1678
    ctx->r7 = ADD32(ctx->r7, 0X1678);
    // 0x801D53E8: lw          $a0, 0x1678($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1678);
    // 0x801D53EC: sw          $v0, 0x1670($at)
    MEM_W(0X1670, ctx->r1) = ctx->r2;
    // 0x801D53F0: sw          $v1, 0x1674($at)
    MEM_W(0X1674, ctx->r1) = ctx->r3;
L_801D53F4:
    // 0x801D53F4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801D53F8: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801D53FC: mfhi        $t3
    ctx->r11 = hi;
    // 0x801D5400: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801D5404: nop

    // 0x801D5408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D540C:
    // 0x801D540C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D5410: jr          $ra
    // 0x801D5414: nop

    return;
    // 0x801D5414: nop

;}
RECOMP_FUNC void M24_FUN_801d5418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5418: nop

    // 0x801D541C: nop

;}
RECOMP_FUNC void M24_FUN_801d5420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5420: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5424: sw          $a0, -0x48F0($at)
    MEM_W(-0X48F0, ctx->r1) = ctx->r4;
    // 0x801D5428: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D542C: sw          $zero, -0x48D0($at)
    MEM_W(-0X48D0, ctx->r1) = 0;
    // 0x801D5430: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5434: sw          $zero, -0x48CC($at)
    MEM_W(-0X48CC, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5438(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5438: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D543C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5440: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D5444: sw          $t6, -0x48AC($at)
    MEM_W(-0X48AC, ctx->r1) = ctx->r14;
    // 0x801D5448: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801D544C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D5450: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D5454: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5458: addiu       $t7, $t7, 0x5484
    ctx->r15 = ADD32(ctx->r15, 0X5484);
    // 0x801D545C: sw          $zero, -0x48E8($at)
    MEM_W(-0X48E8, ctx->r1) = 0;
    // 0x801D5460: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D5464: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x801D5468: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D546C: jal         0x8013B570
    // 0x801D5470: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D5470: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D5474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D5478: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D547C: jr          $ra
    // 0x801D5480: nop

    return;
    // 0x801D5480: nop

;}
RECOMP_FUNC void M24_FUN_801d5484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D5488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D548C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D5490: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D5494: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D5498: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D549C: beq         $t6, $zero, L_801D54C8
    if (ctx->r14 == 0) {
        // 0x801D54A0: nop
    
            goto L_801D54C8;
    }
    // 0x801D54A0: nop

    // 0x801D54A4: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x801D54A8: jal         0x8012D844
    // 0x801D54AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D54AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D54B0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D54B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D54B8: jal         0x800058DC
    // 0x801D54BC: addiu       $a1, $a1, 0x54E0
    ctx->r5 = ADD32(ctx->r5, 0X54E0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D54BC: addiu       $a1, $a1, 0x54E0
    ctx->r5 = ADD32(ctx->r5, 0X54E0);
    after_1:
    // 0x801D54C0: b           L_801D54D4
    // 0x801D54C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D54D4;
    // 0x801D54C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D54C8:
    // 0x801D54C8: jal         0x800058DC
    // 0x801D54CC: addiu       $a1, $a1, 0x5484
    ctx->r5 = ADD32(ctx->r5, 0X5484);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D54CC: addiu       $a1, $a1, 0x5484
    ctx->r5 = ADD32(ctx->r5, 0X5484);
    after_2:
    // 0x801D54D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D54D4:
    // 0x801D54D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D54D8: jr          $ra
    // 0x801D54DC: nop

    return;
    // 0x801D54DC: nop

;}
RECOMP_FUNC void M24_FUN_801d54e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D54E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D54E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D54E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D54EC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D54F0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801D54F4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D54F8: beq         $t6, $zero, L_801D5638
    if (ctx->r14 == 0) {
        // 0x801D54FC: nop
    
            goto L_801D5638;
    }
    // 0x801D54FC: nop

    // 0x801D5500: lw          $t7, -0x48B4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X48B4);
    // 0x801D5504: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801D5508: addiu       $a2, $a2, -0x48C8
    ctx->r6 = ADD32(ctx->r6, -0X48C8);
    // 0x801D550C: beq         $t7, $zero, L_801D560C
    if (ctx->r15 == 0) {
        // 0x801D5510: nop
    
            goto L_801D560C;
    }
    // 0x801D5510: nop

    // 0x801D5514: lw          $a1, 0x30($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X30);
    // 0x801D5518: jal         0x80005FAC
    // 0x801D551C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_0;
    // 0x801D551C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801D5520: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801D5524: addiu       $a1, $a1, 0x1CF0
    ctx->r5 = ADD32(ctx->r5, 0X1CF0);
    // 0x801D5528: lw          $t9, 0x980($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X980);
    // 0x801D552C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D5530: addiu       $v1, $v1, -0x48B8
    ctx->r3 = ADD32(ctx->r3, -0X48B8);
    // 0x801D5534: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801D5538: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801D553C: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x801D5540: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801D5544: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x801D5548: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D554C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801D5550: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    // 0x801D5554: lw          $t4, 0x980($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X980);
    // 0x801D5558: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D555C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801D5560: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801D5564: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D5568: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x801D556C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x801D5570: ori         $at, $at, 0x15
    ctx->r1 = ctx->r1 | 0X15;
    // 0x801D5574: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x801D5578: lw          $t9, 0x980($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X980);
    // 0x801D557C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801D5580: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801D5584: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x801D5588: lhu         $t2, 0x2($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X2);
    // 0x801D558C: sh          $t2, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r10;
    // 0x801D5590: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801D5594: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801D5598: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x801D559C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D55A0: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D55A4: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x801D55A8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801D55AC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D55B0: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x801D55B4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801D55B8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801D55BC: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x801D55C0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801D55C4: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D55C8: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801D55CC: swc1        $f2, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f2.u32l;
    // 0x801D55D0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801D55D4: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801D55D8: swc1        $f2, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f2.u32l;
    // 0x801D55DC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D55E0: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D55E4: swc1        $f2, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f2.u32l;
    // 0x801D55E8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801D55EC: lw          $a0, 0x2C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X2C);
    // 0x801D55F0: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x801D55F4: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x801D55F8: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
    // 0x801D55FC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801D5600: lw          $t1, -0x48B0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X48B0);
    // 0x801D5604: b           L_801D5620
    // 0x801D5608: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
        goto L_801D5620;
    // 0x801D5608: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
L_801D560C:
    // 0x801D560C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D5610: addiu       $v1, $v1, -0x48B8
    ctx->r3 = ADD32(ctx->r3, -0X48B8);
    // 0x801D5614: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801D5618: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D561C: sw          $zero, -0x48B0($at)
    MEM_W(-0X48B0, ctx->r1) = 0;
L_801D5620:
    // 0x801D5620: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D5624: addiu       $a1, $a1, 0x5658
    ctx->r5 = ADD32(ctx->r5, 0X5658);
    // 0x801D5628: jal         0x800058DC
    // 0x801D562C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D562C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x801D5630: b           L_801D564C
    // 0x801D5634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D564C;
    // 0x801D5634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D5638:
    // 0x801D5638: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D563C: addiu       $a1, $a1, 0x54E0
    ctx->r5 = ADD32(ctx->r5, 0X54E0);
    // 0x801D5640: jal         0x800058DC
    // 0x801D5644: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D5644: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x801D5648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D564C:
    // 0x801D564C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D5650: jr          $ra
    // 0x801D5654: nop

    return;
    // 0x801D5654: nop

;}
RECOMP_FUNC void M24_FUN_801d5658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5658: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D565C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D5660: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801D5664: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D5668: jal         0x801CC540
    // 0x801D566C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D566C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D5670: beq         $v0, $zero, L_801D5690
    if (ctx->r2 == 0) {
        // 0x801D5674: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D5690;
    }
    // 0x801D5674: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D5678: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D567C: addiu       $a1, $a1, 0x5658
    ctx->r5 = ADD32(ctx->r5, 0X5658);
    // 0x801D5680: jal         0x800058DC
    // 0x801D5684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D5684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801D5688: b           L_801D58B4
    // 0x801D568C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801D58B4;
    // 0x801D568C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D5690:
    // 0x801D5690: lw          $t6, -0x48D0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X48D0);
    // 0x801D5694: beq         $t6, $zero, L_801D56F4
    if (ctx->r14 == 0) {
        // 0x801D5698: nop
    
            goto L_801D56F4;
    }
    // 0x801D5698: nop

    // 0x801D569C: jal         0x80006214
    // 0x801D56A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D56A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801D56A4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D56A8: lw          $t7, -0x48D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X48D0);
    // 0x801D56AC: lui         $t0, 0x1B
    ctx->r8 = S32(0X1B << 16);
    // 0x801D56B0: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x801D56B4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D56B8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D56BC: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D56C0: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D56C4: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D56C8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D56CC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D56D0: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D56D4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801D56D8: jal         0x8013A1B4
    // 0x801D56DC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_3;
    // 0x801D56DC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D56E0: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x801D56E4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801D56E8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D56EC: sb          $t1, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r9;
    // 0x801D56F0: sw          $zero, -0x48D0($at)
    MEM_W(-0X48D0, ctx->r1) = 0;
L_801D56F4:
    // 0x801D56F4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D56F8: lw          $v0, -0x48CC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X48CC);
    // 0x801D56FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D5700: beq         $v0, $zero, L_801D57CC
    if (ctx->r2 == 0) {
        // 0x801D5704: nop
    
            goto L_801D57CC;
    }
    // 0x801D5704: nop

    // 0x801D5708: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801D570C: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x801D5710: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D5714: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x801D5718: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x801D571C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D5720: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801D5724: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x801D5728: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x801D572C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D5730: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D5734: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801D5738: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D573C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D5740: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801D5744: nop

    // 0x801D5748: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801D574C: beql        $t5, $zero, L_801D579C
    if (ctx->r13 == 0) {
        // 0x801D5750: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_801D579C;
    }
    goto skip_0;
    // 0x801D5750: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D5754: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D5758: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D575C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D5760: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801D5764: nop

    // 0x801D5768: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D576C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801D5770: nop

    // 0x801D5774: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801D5778: bne         $t5, $zero, L_801D5790
    if (ctx->r13 != 0) {
        // 0x801D577C: nop
    
            goto L_801D5790;
    }
    // 0x801D577C: nop

    // 0x801D5780: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x801D5784: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D5788: b           L_801D57A8
    // 0x801D578C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_801D57A8;
    // 0x801D578C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_801D5790:
    // 0x801D5790: b           L_801D57A8
    // 0x801D5794: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_801D57A8;
    // 0x801D5794: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801D5798: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_801D579C:
    // 0x801D579C: nop

    // 0x801D57A0: bltz        $t5, L_801D5790
    if (SIGNED(ctx->r13) < 0) {
        // 0x801D57A4: nop
    
            goto L_801D5790;
    }
    // 0x801D57A4: nop

L_801D57A8:
    // 0x801D57A8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D57AC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801D57B0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D57B4: jal         0x80011140
    // 0x801D57B8: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D57B8: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D57BC: beq         $v0, $zero, L_801D5878
    if (ctx->r2 == 0) {
        // 0x801D57C0: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D5878;
    }
    // 0x801D57C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D57C4: b           L_801D5878
    // 0x801D57C8: sw          $zero, -0x48CC($at)
    MEM_W(-0X48CC, ctx->r1) = 0;
        goto L_801D5878;
    // 0x801D57C8: sw          $zero, -0x48CC($at)
    MEM_W(-0X48CC, ctx->r1) = 0;
L_801D57CC:
    // 0x801D57CC: jal         0x80010550
    // 0x801D57D0: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D57D0: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    after_5:
    // 0x801D57D4: beq         $v0, $zero, L_801D57EC
    if (ctx->r2 == 0) {
        // 0x801D57D8: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D57EC;
    }
    // 0x801D57D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D57DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D57E0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D57E4: b           L_801D57F0
    // 0x801D57E8: sw          $t6, -0x48AC($at)
    MEM_W(-0X48AC, ctx->r1) = ctx->r14;
        goto L_801D57F0;
    // 0x801D57E8: sw          $t6, -0x48AC($at)
    MEM_W(-0X48AC, ctx->r1) = ctx->r14;
L_801D57EC:
    // 0x801D57EC: sw          $zero, -0x48AC($at)
    MEM_W(-0X48AC, ctx->r1) = 0;
L_801D57F0:
    // 0x801D57F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801D57F4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D57F8: addiu       $t7, $t7, 0x1690
    ctx->r15 = ADD32(ctx->r15, 0X1690);
    // 0x801D57FC: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x801D5800: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801D5804: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x801D5808: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D580C: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801D5810: addiu       $t2, $t2, 0x1680
    ctx->r10 = ADD32(ctx->r10, 0X1680);
    // 0x801D5814: lw          $t1, 0x5C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X5C);
    // 0x801D5818: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D581C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D5820: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x801D5824: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x801D5828: addiu       $a0, $a0, 0x16A0
    ctx->r4 = ADD32(ctx->r4, 0X16A0);
    // 0x801D582C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x801D5830: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x801D5834: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x801D5838: sw          $t1, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r9;
    // 0x801D583C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801D5840: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801D5844: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801D5848: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801D584C: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801D5850: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
    // 0x801D5854: sw          $a1, -0x48EC($at)
    MEM_W(-0X48EC, ctx->r1) = ctx->r5;
    // 0x801D5858: jal         0x8013A334
    // 0x801D585C: lw          $a2, 0x5C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_6;
    // 0x801D585C: lw          $a2, 0x5C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X5C);
    after_6:
    // 0x801D5860: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D5864: addiu       $a0, $a0, 0x16B0
    ctx->r4 = ADD32(ctx->r4, 0X16B0);
    // 0x801D5868: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801D586C: lw          $a2, 0x5C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X5C);
    // 0x801D5870: jal         0x8013A334
    // 0x801D5874: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_7;
    // 0x801D5874: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    after_7:
L_801D5878:
    // 0x801D5878: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D587C: lw          $t6, -0x48B4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X48B4);
    // 0x801D5880: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D5884: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D5888: beq         $t6, $zero, L_801D589C
    if (ctx->r14 == 0) {
        // 0x801D588C: lui         $t9, 0x801E
        ctx->r25 = S32(0X801E << 16);
            goto L_801D589C;
    }
    // 0x801D588C: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801D5890: lw          $t8, -0x48B0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X48B0);
    // 0x801D5894: lw          $t7, -0x48B8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X48B8);
    // 0x801D5898: sb          $t8, 0x22($t7)
    MEM_B(0X22, ctx->r15) = ctx->r24;
L_801D589C:
    // 0x801D589C: lw          $t9, -0x48E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X48E8);
    // 0x801D58A0: beql        $t9, $zero, L_801D58B4
    if (ctx->r25 == 0) {
        // 0x801D58A4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801D58B4;
    }
    goto skip_1;
    // 0x801D58A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801D58A8: jal         0x801D5A00
    // 0x801D58AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801D5A00)(rdram, ctx);
        goto after_8;
    // 0x801D58AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801D58B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D58B4:
    // 0x801D58B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801D58B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D58BC: jr          $ra
    // 0x801D58C0: nop

    return;
    // 0x801D58C0: nop

;}
RECOMP_FUNC void M24_FUN_801d58c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D58C4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D58C8: jr          $ra
    // 0x801D58CC: sw          $a0, -0x48B4($at)
    MEM_W(-0X48B4, ctx->r1) = ctx->r4;
    return;
    // 0x801D58CC: sw          $a0, -0x48B4($at)
    MEM_W(-0X48B4, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d58d0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d58d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D58D0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D58D4: jr          $ra
    // 0x801D58D8: sw          $a0, -0x48B0($at)
    MEM_W(-0X48B0, ctx->r1) = ctx->r4;
    return;
    // 0x801D58D8: sw          $a0, -0x48B0($at)
    MEM_W(-0X48B0, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d58dc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d58dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D58DC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D58E0: lw          $v0, -0x48CC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X48CC);
    // 0x801D58E4: jr          $ra
    // 0x801D58E8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D58E8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d58ec(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d58ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D58EC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D58F0: lw          $t6, -0x48CC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X48CC);
    // 0x801D58F4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D58F8: beq         $t6, $zero, L_801D5908
    if (ctx->r14 == 0) {
            // 0x801D58FC: nop

    LOOKUP_FUNC(0x801D5908)(rdram, ctx);
    return;
    }
    // 0x801D58FC: nop

    // 0x801D5900: jr          $ra
    // 0x801D5904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D5904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5908(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5908: lw          $t7, -0x48D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X48D0);
    // 0x801D590C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D5910: beq         $t7, $zero, L_801D5920
    if (ctx->r15 == 0) {
            // 0x801D5914: nop

    LOOKUP_FUNC(0x801D5920)(rdram, ctx);
    return;
    }
    // 0x801D5914: nop

    // 0x801D5918: jr          $ra
    // 0x801D591C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D591C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5920(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5920: lw          $v0, -0x48AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X48AC);
    // 0x801D5924: jr          $ra
    // 0x801D5928: nop

    return;
    // 0x801D5928: nop

;}
RECOMP_FUNC void M24_FUN_801d592c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D592C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D5930: jr          $ra
    // 0x801D5934: addiu       $v0, $v0, 0x1680
    ctx->r2 = ADD32(ctx->r2, 0X1680);
    return;
    // 0x801D5934: addiu       $v0, $v0, 0x1680
    ctx->r2 = ADD32(ctx->r2, 0X1680);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5938(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5938: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D593C: addiu       $v0, $v0, -0x48E8
    ctx->r2 = ADD32(ctx->r2, -0X48E8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5940(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D5944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D5948: beq         $a0, $zero, L_801D5974
    if (ctx->r4 == 0) {
        // 0x801D594C: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801D5974;
    }
    // 0x801D594C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801D5950: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5954: jal         0x801C0B2C
    // 0x801D5958: sw          $zero, -0x48A8($at)
    MEM_W(-0X48A8, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D5958: sw          $zero, -0x48A8($at)
    MEM_W(-0X48A8, ctx->r1) = 0;
    after_0:
    // 0x801D595C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5960: sw          $v0, 0x16C0($at)
    MEM_W(0X16C0, ctx->r1) = ctx->r2;
    // 0x801D5964: sw          $v1, 0x16C4($at)
    MEM_W(0X16C4, ctx->r1) = ctx->r3;
    // 0x801D5968: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D596C: b           L_801D5988
    // 0x801D5970: sw          $zero, 0x16C8($at)
    MEM_W(0X16C8, ctx->r1) = 0;
        goto L_801D5988;
    // 0x801D5970: sw          $zero, 0x16C8($at)
    MEM_W(0X16C8, ctx->r1) = 0;
L_801D5974:
    // 0x801D5974: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D5978: lw          $a0, -0x48F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X48F0);
    // 0x801D597C: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x801D5980: jal         0x8012D844
    // 0x801D5984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801D5984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_801D5988:
    // 0x801D5988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D598C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D5990: jr          $ra
    // 0x801D5994: nop

    return;
    // 0x801D5994: nop

;}
RECOMP_FUNC void M24_FUN_801d5998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5998: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D599C: addiu       $v1, $v1, 0x1690
    ctx->r3 = ADD32(ctx->r3, 0X1690);
    // 0x801D59A0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D59A4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D59A8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D59AC: beql        $a0, $t6, L_801D59C0
    if (ctx->r4 == ctx->r14) {
        // 0x801D59B0: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D59C0;
    }
    goto skip_0;
    // 0x801D59B0: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D59B4: jr          $ra
    // 0x801D59B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D59B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D59BC: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D59C0:
    // 0x801D59C0: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D59C4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D59C8: jr          $ra
    // 0x801D59CC: nop

    return;
    // 0x801D59CC: nop

;}
RECOMP_FUNC void M24_FUN_801d59d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D59D0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D59D4: jr          $ra
    // 0x801D59D8: lw          $v0, -0x48F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X48F0);
    return;
    // 0x801D59D8: lw          $v0, -0x48F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X48F0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d59dc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d59dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D59DC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D59E0: jr          $ra
    // 0x801D59E4: lw          $v0, -0x48EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X48EC);
    return;
    // 0x801D59E4: lw          $v0, -0x48EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X48EC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d59e8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d59e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D59E8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D59EC: jr          $ra
    // 0x801D59F0: addiu       $v0, $v0, 0x16A0
    ctx->r2 = ADD32(ctx->r2, 0X16A0);
    return;
    // 0x801D59F0: addiu       $v0, $v0, 0x16A0
    ctx->r2 = ADD32(ctx->r2, 0X16A0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d59f4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d59f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D59F4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D59F8: jr          $ra
    // 0x801D59FC: addiu       $v0, $v0, 0x16B0
    ctx->r2 = ADD32(ctx->r2, 0X16B0);
    return;
    // 0x801D59FC: addiu       $v0, $v0, 0x16B0
    ctx->r2 = ADD32(ctx->r2, 0X16B0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5a00(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5a00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5A00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D5A04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D5A08: jal         0x801C0B2C
    // 0x801D5A0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D5A0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D5A10: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D5A14: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D5A18: lw          $t7, 0x16C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16C4);
    // 0x801D5A1C: lw          $t6, 0x16C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16C0);
    // 0x801D5A20: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801D5A24: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801D5A28: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801D5A2C: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801D5A30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D5A34: jal         0x80034C24
    // 0x801D5A38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801D5A38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D5A3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5A40: ldc1        $f4, -0x2A60($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2A60);
    // 0x801D5A44: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D5A48: addiu       $a3, $a3, 0x16C8
    ctx->r7 = ADD32(ctx->r7, 0X16C8);
    // 0x801D5A4C: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801D5A50: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801D5A54: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D5A58: addiu       $t1, $t1, -0x48A4
    ctx->r9 = ADD32(ctx->r9, -0X48A4);
    // 0x801D5A5C: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801D5A60: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x801D5A64: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D5A68: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D5A6C: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801D5A70: nop

    // 0x801D5A74: bc1fl       L_801D5B54
    if (!c1cs) {
        // 0x801D5A78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D5B54;
    }
    goto skip_0;
    // 0x801D5A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D5A7C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801D5A80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D5A84: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x801D5A88: beq         $v0, $zero, L_801D5AAC
    if (ctx->r2 == 0) {
        // 0x801D5A8C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801D5AAC;
    }
    // 0x801D5A8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D5A90: beq         $v0, $at, L_801D5AC8
    if (ctx->r2 == ctx->r1) {
        // 0x801D5A94: addiu       $a1, $zero, 0x34
        ctx->r5 = ADD32(0, 0X34);
            goto L_801D5AC8;
    }
    // 0x801D5A94: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x801D5A98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D5A9C: beq         $v0, $at, L_801D5AE8
    if (ctx->r2 == ctx->r1) {
        // 0x801D5AA0: addiu       $a1, $zero, 0x34
        ctx->r5 = ADD32(0, 0X34);
            goto L_801D5AE8;
    }
    // 0x801D5AA0: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x801D5AA4: b           L_801D5B08
    // 0x801D5AA8: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801D5B08;
    // 0x801D5AA8: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D5AAC:
    // 0x801D5AAC: jal         0x8012D844
    // 0x801D5AB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801D5AB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D5AB4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D5AB8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D5ABC: addiu       $a3, $a3, 0x16C8
    ctx->r7 = ADD32(ctx->r7, 0X16C8);
    // 0x801D5AC0: b           L_801D5B04
    // 0x801D5AC4: lw          $a0, 0x16C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C8);
        goto L_801D5B04;
    // 0x801D5AC4: lw          $a0, 0x16C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C8);
L_801D5AC8:
    // 0x801D5AC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D5ACC: jal         0x8012D844
    // 0x801D5AD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801D5AD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801D5AD4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D5AD8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D5ADC: addiu       $a3, $a3, 0x16C8
    ctx->r7 = ADD32(ctx->r7, 0X16C8);
    // 0x801D5AE0: b           L_801D5B04
    // 0x801D5AE4: lw          $a0, 0x16C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C8);
        goto L_801D5B04;
    // 0x801D5AE4: lw          $a0, 0x16C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C8);
L_801D5AE8:
    // 0x801D5AE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D5AEC: jal         0x8012D844
    // 0x801D5AF0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x801D5AF0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x801D5AF4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D5AF8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D5AFC: addiu       $a3, $a3, 0x16C8
    ctx->r7 = ADD32(ctx->r7, 0X16C8);
    // 0x801D5B00: lw          $a0, 0x16C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C8);
L_801D5B04:
    // 0x801D5B04: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D5B08:
    // 0x801D5B08: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    // 0x801D5B0C: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801D5B10: bne         $at, $zero, L_801D5B3C
    if (ctx->r1 != 0) {
        // 0x801D5B14: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801D5B3C;
    }
    // 0x801D5B14: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801D5B18: jal         0x801C0B2C
    // 0x801D5B1C: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801D5B1C: nop

    after_5:
    // 0x801D5B20: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5B24: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D5B28: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D5B2C: addiu       $a3, $a3, 0x16C8
    ctx->r7 = ADD32(ctx->r7, 0X16C8);
    // 0x801D5B30: lw          $a0, 0x16C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C8);
    // 0x801D5B34: sw          $v0, 0x16C0($at)
    MEM_W(0X16C0, ctx->r1) = ctx->r2;
    // 0x801D5B38: sw          $v1, 0x16C4($at)
    MEM_W(0X16C4, ctx->r1) = ctx->r3;
L_801D5B3C:
    // 0x801D5B3C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801D5B40: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801D5B44: mfhi        $t3
    ctx->r11 = hi;
    // 0x801D5B48: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801D5B4C: nop

    // 0x801D5B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D5B54:
    // 0x801D5B54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D5B58: jr          $ra
    // 0x801D5B5C: nop

    return;
    // 0x801D5B5C: nop

;}
RECOMP_FUNC void M24_FUN_801d5b60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5B60: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5B64: sw          $zero, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = 0;
    // 0x801D5B68: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5B6C: sw          $zero, -0x4804($at)
    MEM_W(-0X4804, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5b70(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5b70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5B70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D5B74: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5B78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D5B7C: sw          $t6, -0x47FC($at)
    MEM_W(-0X47FC, ctx->r1) = ctx->r14;
    // 0x801D5B80: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801D5B84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D5B88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D5B8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5B90: addiu       $t7, $t7, 0x5BBC
    ctx->r15 = ADD32(ctx->r15, 0X5BBC);
    // 0x801D5B94: sw          $zero, -0x4820($at)
    MEM_W(-0X4820, ctx->r1) = 0;
    // 0x801D5B98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D5B9C: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x801D5BA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D5BA4: jal         0x8013B570
    // 0x801D5BA8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D5BA8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D5BAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D5BB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D5BB4: jr          $ra
    // 0x801D5BB8: nop

    return;
    // 0x801D5BB8: nop

;}
RECOMP_FUNC void M24_FUN_801d5bbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5BBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D5BC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D5BC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D5BC8: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D5BCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D5BD0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D5BD4: beq         $t6, $zero, L_801D5C00
    if (ctx->r14 == 0) {
        // 0x801D5BD8: nop
    
            goto L_801D5C00;
    }
    // 0x801D5BD8: nop

    // 0x801D5BDC: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x801D5BE0: jal         0x8012D844
    // 0x801D5BE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D5BE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D5BE8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D5BEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D5BF0: jal         0x800058DC
    // 0x801D5BF4: addiu       $a1, $a1, 0x5C18
    ctx->r5 = ADD32(ctx->r5, 0X5C18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D5BF4: addiu       $a1, $a1, 0x5C18
    ctx->r5 = ADD32(ctx->r5, 0X5C18);
    after_1:
    // 0x801D5BF8: b           L_801D5C0C
    // 0x801D5BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D5C0C;
    // 0x801D5BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D5C00:
    // 0x801D5C00: jal         0x800058DC
    // 0x801D5C04: addiu       $a1, $a1, 0x5BBC
    ctx->r5 = ADD32(ctx->r5, 0X5BBC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D5C04: addiu       $a1, $a1, 0x5BBC
    ctx->r5 = ADD32(ctx->r5, 0X5BBC);
    after_2:
    // 0x801D5C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D5C0C:
    // 0x801D5C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D5C10: jr          $ra
    // 0x801D5C14: nop

    return;
    // 0x801D5C14: nop

;}
RECOMP_FUNC void M24_FUN_801d5c18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5C18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D5C1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D5C20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801D5C24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D5C28: jal         0x801CC540
    // 0x801D5C2C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D5C2C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D5C30: beq         $v0, $zero, L_801D5C50
    if (ctx->r2 == 0) {
        // 0x801D5C34: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D5C50;
    }
    // 0x801D5C34: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D5C38: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D5C3C: addiu       $a1, $a1, 0x5C18
    ctx->r5 = ADD32(ctx->r5, 0X5C18);
    // 0x801D5C40: jal         0x800058DC
    // 0x801D5C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D5C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801D5C48: b           L_801D5DE8
    // 0x801D5C4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801D5DE8;
    // 0x801D5C4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D5C50:
    // 0x801D5C50: lw          $t6, -0x4808($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4808);
    // 0x801D5C54: beq         $t6, $zero, L_801D5CA8
    if (ctx->r14 == 0) {
        // 0x801D5C58: nop
    
            goto L_801D5CA8;
    }
    // 0x801D5C58: nop

    // 0x801D5C5C: jal         0x80006214
    // 0x801D5C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D5C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801D5C64: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D5C68: lw          $t7, -0x4808($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4808);
    // 0x801D5C6C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D5C70: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D5C74: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D5C78: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D5C7C: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D5C80: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D5C84: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D5C88: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D5C8C: jal         0x8013A28C
    // 0x801D5C90: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D5C90: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D5C94: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x801D5C98: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D5C9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5CA0: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D5CA4: sw          $zero, -0x4808($at)
    MEM_W(-0X4808, ctx->r1) = 0;
L_801D5CA8:
    // 0x801D5CA8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D5CAC: lw          $v0, -0x4804($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4804);
    // 0x801D5CB0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D5CB4: beq         $v0, $zero, L_801D5D80
    if (ctx->r2 == 0) {
        // 0x801D5CB8: nop
    
            goto L_801D5D80;
    }
    // 0x801D5CB8: nop

    // 0x801D5CBC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D5CC0: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x801D5CC4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D5CC8: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D5CCC: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D5CD0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D5CD4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D5CD8: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D5CDC: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D5CE0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D5CE4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D5CE8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D5CEC: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D5CF0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D5CF4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D5CF8: nop

    // 0x801D5CFC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D5D00: beql        $t4, $zero, L_801D5D50
    if (ctx->r12 == 0) {
        // 0x801D5D04: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D5D50;
    }
    goto skip_0;
    // 0x801D5D04: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D5D08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D5D0C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D5D10: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D5D14: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D5D18: nop

    // 0x801D5D1C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D5D20: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D5D24: nop

    // 0x801D5D28: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D5D2C: bne         $t4, $zero, L_801D5D44
    if (ctx->r12 != 0) {
        // 0x801D5D30: nop
    
            goto L_801D5D44;
    }
    // 0x801D5D30: nop

    // 0x801D5D34: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D5D38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D5D3C: b           L_801D5D5C
    // 0x801D5D40: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D5D5C;
    // 0x801D5D40: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D5D44:
    // 0x801D5D44: b           L_801D5D5C
    // 0x801D5D48: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D5D5C;
    // 0x801D5D48: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D5D4C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D5D50:
    // 0x801D5D50: nop

    // 0x801D5D54: bltz        $t4, L_801D5D44
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D5D58: nop
    
            goto L_801D5D44;
    }
    // 0x801D5D58: nop

L_801D5D5C:
    // 0x801D5D5C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D5D60: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D5D64: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D5D68: jal         0x80011140
    // 0x801D5D6C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D5D6C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D5D70: beq         $v0, $zero, L_801D5DCC
    if (ctx->r2 == 0) {
        // 0x801D5D74: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D5DCC;
    }
    // 0x801D5D74: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5D78: b           L_801D5DCC
    // 0x801D5D7C: sw          $zero, -0x4804($at)
    MEM_W(-0X4804, ctx->r1) = 0;
        goto L_801D5DCC;
    // 0x801D5D7C: sw          $zero, -0x4804($at)
    MEM_W(-0X4804, ctx->r1) = 0;
L_801D5D80:
    // 0x801D5D80: jal         0x80010550
    // 0x801D5D84: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D5D84: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    after_5:
    // 0x801D5D88: beq         $v0, $zero, L_801D5DA0
    if (ctx->r2 == 0) {
        // 0x801D5D8C: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D5DA0;
    }
    // 0x801D5D8C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D5D90: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D5D94: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5D98: b           L_801D5DA8
    // 0x801D5D9C: sw          $t5, -0x47FC($at)
    MEM_W(-0X47FC, ctx->r1) = ctx->r13;
        goto L_801D5DA8;
    // 0x801D5D9C: sw          $t5, -0x47FC($at)
    MEM_W(-0X47FC, ctx->r1) = ctx->r13;
L_801D5DA0:
    // 0x801D5DA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5DA4: sw          $zero, -0x47FC($at)
    MEM_W(-0X47FC, ctx->r1) = 0;
L_801D5DA8:
    // 0x801D5DA8: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801D5DAC: addiu       $t7, $t7, -0x3FD8
    ctx->r15 = ADD32(ctx->r15, -0X3FD8);
    // 0x801D5DB0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D5DB4: addiu       $t6, $t6, 0x16D0
    ctx->r14 = ADD32(ctx->r14, 0X16D0);
    // 0x801D5DB8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D5DBC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801D5DC0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801D5DC4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801D5DC8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
L_801D5DCC:
    // 0x801D5DCC: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801D5DD0: lw          $t0, -0x4820($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4820);
    // 0x801D5DD4: beql        $t0, $zero, L_801D5DE8
    if (ctx->r8 == 0) {
        // 0x801D5DD8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801D5DE8;
    }
    goto skip_1;
    // 0x801D5DD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801D5DDC: jal         0x801D5E9C
    // 0x801D5DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801D5E9C)(rdram, ctx);
        goto after_6;
    // 0x801D5DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801D5DE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D5DE8:
    // 0x801D5DE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801D5DEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D5DF0: jr          $ra
    // 0x801D5DF4: nop

    return;
    // 0x801D5DF4: nop

;}
RECOMP_FUNC void M24_FUN_801d5df8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5DF8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D5DFC: addiu       $v0, $v0, -0x4820
    ctx->r2 = ADD32(ctx->r2, -0X4820);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5e00(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5e00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5E00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D5E04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D5E08: beq         $a0, $zero, L_801D5E30
    if (ctx->r4 == 0) {
        // 0x801D5E0C: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801D5E30;
    }
    // 0x801D5E0C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801D5E10: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5E14: jal         0x801C0B2C
    // 0x801D5E18: sw          $zero, -0x4800($at)
    MEM_W(-0X4800, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D5E18: sw          $zero, -0x4800($at)
    MEM_W(-0X4800, ctx->r1) = 0;
    after_0:
    // 0x801D5E1C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5E20: sw          $v0, 0x16E0($at)
    MEM_W(0X16E0, ctx->r1) = ctx->r2;
    // 0x801D5E24: sw          $v1, 0x16E4($at)
    MEM_W(0X16E4, ctx->r1) = ctx->r3;
    // 0x801D5E28: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5E2C: sw          $zero, 0x16E8($at)
    MEM_W(0X16E8, ctx->r1) = 0;
L_801D5E30:
    // 0x801D5E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D5E34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D5E38: jr          $ra
    // 0x801D5E3C: nop

    return;
    // 0x801D5E3C: nop

;}
RECOMP_FUNC void M24_FUN_801d5e40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5E40: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D5E44: lw          $v0, -0x4804($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4804);
    // 0x801D5E48: jr          $ra
    // 0x801D5E4C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D5E4C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5e50(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5e50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5E50: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D5E54: lw          $t6, -0x4804($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4804);
    // 0x801D5E58: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D5E5C: beq         $t6, $zero, L_801D5E6C
    if (ctx->r14 == 0) {
            // 0x801D5E60: nop

    LOOKUP_FUNC(0x801D5E6C)(rdram, ctx);
    return;
    }
    // 0x801D5E60: nop

    // 0x801D5E64: jr          $ra
    // 0x801D5E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D5E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5e6c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5e6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5E6C: lw          $t7, -0x4808($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4808);
    // 0x801D5E70: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D5E74: beq         $t7, $zero, L_801D5E84
    if (ctx->r15 == 0) {
            // 0x801D5E78: nop

    LOOKUP_FUNC(0x801D5E84)(rdram, ctx);
    return;
    }
    // 0x801D5E78: nop

    // 0x801D5E7C: jr          $ra
    // 0x801D5E80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D5E80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5e84(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5e84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5E84: lw          $v0, -0x47FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X47FC);
    // 0x801D5E88: jr          $ra
    // 0x801D5E8C: nop

    return;
    // 0x801D5E8C: nop

;}
RECOMP_FUNC void M24_FUN_801d5e90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5E90: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D5E94: jr          $ra
    // 0x801D5E98: addiu       $v0, $v0, 0x16D0
    ctx->r2 = ADD32(ctx->r2, 0X16D0);
    return;
    // 0x801D5E98: addiu       $v0, $v0, 0x16D0
    ctx->r2 = ADD32(ctx->r2, 0X16D0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d5e9c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d5e9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5E9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D5EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D5EA4: jal         0x801C0B2C
    // 0x801D5EA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D5EA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D5EAC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D5EB0: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D5EB4: lw          $t7, 0x16E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16E4);
    // 0x801D5EB8: lw          $t6, 0x16E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16E0);
    // 0x801D5EBC: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801D5EC0: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801D5EC4: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801D5EC8: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801D5ECC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D5ED0: jal         0x80034C24
    // 0x801D5ED4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801D5ED4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D5ED8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5EDC: ldc1        $f4, -0x2A50($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2A50);
    // 0x801D5EE0: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D5EE4: addiu       $a3, $a3, 0x16E8
    ctx->r7 = ADD32(ctx->r7, 0X16E8);
    // 0x801D5EE8: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801D5EEC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801D5EF0: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D5EF4: addiu       $t1, $t1, -0x47F8
    ctx->r9 = ADD32(ctx->r9, -0X47F8);
    // 0x801D5EF8: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801D5EFC: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x801D5F00: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D5F04: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D5F08: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801D5F0C: nop

    // 0x801D5F10: bc1fl       L_801D5FF0
    if (!c1cs) {
        // 0x801D5F14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D5FF0;
    }
    goto skip_0;
    // 0x801D5F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D5F18: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801D5F1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D5F20: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x801D5F24: beq         $v0, $zero, L_801D5F48
    if (ctx->r2 == 0) {
        // 0x801D5F28: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801D5F48;
    }
    // 0x801D5F28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D5F2C: beq         $v0, $at, L_801D5F64
    if (ctx->r2 == ctx->r1) {
        // 0x801D5F30: addiu       $a1, $zero, 0x2D
        ctx->r5 = ADD32(0, 0X2D);
            goto L_801D5F64;
    }
    // 0x801D5F30: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x801D5F34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D5F38: beq         $v0, $at, L_801D5F84
    if (ctx->r2 == ctx->r1) {
        // 0x801D5F3C: addiu       $a1, $zero, 0x2D
        ctx->r5 = ADD32(0, 0X2D);
            goto L_801D5F84;
    }
    // 0x801D5F3C: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x801D5F40: b           L_801D5FA4
    // 0x801D5F44: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801D5FA4;
    // 0x801D5F44: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D5F48:
    // 0x801D5F48: jal         0x8012D844
    // 0x801D5F4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801D5F4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D5F50: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D5F54: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D5F58: addiu       $a3, $a3, 0x16E8
    ctx->r7 = ADD32(ctx->r7, 0X16E8);
    // 0x801D5F5C: b           L_801D5FA0
    // 0x801D5F60: lw          $a0, 0x16E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16E8);
        goto L_801D5FA0;
    // 0x801D5F60: lw          $a0, 0x16E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16E8);
L_801D5F64:
    // 0x801D5F64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D5F68: jal         0x8012D844
    // 0x801D5F6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801D5F6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801D5F70: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D5F74: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D5F78: addiu       $a3, $a3, 0x16E8
    ctx->r7 = ADD32(ctx->r7, 0X16E8);
    // 0x801D5F7C: b           L_801D5FA0
    // 0x801D5F80: lw          $a0, 0x16E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16E8);
        goto L_801D5FA0;
    // 0x801D5F80: lw          $a0, 0x16E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16E8);
L_801D5F84:
    // 0x801D5F84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D5F88: jal         0x8012D844
    // 0x801D5F8C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x801D5F8C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x801D5F90: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D5F94: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D5F98: addiu       $a3, $a3, 0x16E8
    ctx->r7 = ADD32(ctx->r7, 0X16E8);
    // 0x801D5F9C: lw          $a0, 0x16E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16E8);
L_801D5FA0:
    // 0x801D5FA0: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D5FA4:
    // 0x801D5FA4: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    // 0x801D5FA8: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801D5FAC: bne         $at, $zero, L_801D5FD8
    if (ctx->r1 != 0) {
        // 0x801D5FB0: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801D5FD8;
    }
    // 0x801D5FB0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801D5FB4: jal         0x801C0B2C
    // 0x801D5FB8: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801D5FB8: nop

    after_5:
    // 0x801D5FBC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D5FC0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D5FC4: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D5FC8: addiu       $a3, $a3, 0x16E8
    ctx->r7 = ADD32(ctx->r7, 0X16E8);
    // 0x801D5FCC: lw          $a0, 0x16E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16E8);
    // 0x801D5FD0: sw          $v0, 0x16E0($at)
    MEM_W(0X16E0, ctx->r1) = ctx->r2;
    // 0x801D5FD4: sw          $v1, 0x16E4($at)
    MEM_W(0X16E4, ctx->r1) = ctx->r3;
L_801D5FD8:
    // 0x801D5FD8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801D5FDC: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801D5FE0: mfhi        $t3
    ctx->r11 = hi;
    // 0x801D5FE4: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801D5FE8: nop

    // 0x801D5FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D5FF0:
    // 0x801D5FF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D5FF4: jr          $ra
    // 0x801D5FF8: nop

    return;
    // 0x801D5FF8: nop

;}
RECOMP_FUNC void M24_FUN_801d5ffc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D5FFC: nop

;}
