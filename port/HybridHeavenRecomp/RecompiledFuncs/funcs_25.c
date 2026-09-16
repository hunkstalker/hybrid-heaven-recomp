#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_80133a24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133A24: bgez        $a0, L_80133A34
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80133A28: sra         $t6, $a0, 3
        ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
            goto L_80133A34;
    }
    // 0x80133A28: sra         $t6, $a0, 3
    ctx->r14 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80133A2C: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x80133A30: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_80133A34:
    // 0x80133A34: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80133A38: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80133A3C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80133A40: lbu         $t8, -0x23E0($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X23E0);
    // 0x80133A44: bgez        $a0, L_80133A58
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80133A48: andi        $t9, $a0, 0x7
        ctx->r25 = ctx->r4 & 0X7;
            goto L_80133A58;
    }
    // 0x80133A48: andi        $t9, $a0, 0x7
    ctx->r25 = ctx->r4 & 0X7;
    // 0x80133A4C: beq         $t9, $zero, L_80133A58
    if (ctx->r25 == 0) {
        // 0x80133A50: nop
    
            goto L_80133A58;
    }
    // 0x80133A50: nop

    // 0x80133A54: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
L_80133A58:
    // 0x80133A58: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80133A5C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133A60: sllv        $t3, $t1, $t0
    ctx->r11 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x80133A64: and         $v0, $t8, $t3
    ctx->r2 = ctx->r24 & ctx->r11;
    // 0x80133A68: jr          $ra
    // 0x80133A6C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    return;
    // 0x80133A6C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80133a70(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80133a70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133A70: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80133A74: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80133A78: addiu       $v0, $v0, -0x237C
    ctx->r2 = ADD32(ctx->r2, -0X237C);
    // 0x80133A7C: addiu       $v1, $v1, -0x23E0
    ctx->r3 = ADD32(ctx->r3, -0X23E0);
L_80133A80:
    // 0x80133A80: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80133A84: sb          $zero, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = 0;
    // 0x80133A88: sb          $zero, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = 0;
    // 0x80133A8C: sb          $zero, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = 0;
    // 0x80133A90: bne         $v1, $v0, L_80133A80
    if (ctx->r3 != ctx->r2) {
        // 0x80133A94: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_80133A80;
    }
    // 0x80133A94: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x80133A98: jr          $ra
    // 0x80133A9C: nop

    return;
    // 0x80133A9C: nop

;}
RECOMP_FUNC void M7_FUN_80133aa0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133AA0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80133AA4: jr          $ra
    // 0x80133AA8: lw          $v0, -0x5570($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5570);
    return;
    // 0x80133AA8: lw          $v0, -0x5570($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5570);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80133aac(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80133aac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133AAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80133AB0: jr          $ra
    // 0x80133AB4: sw          $a0, -0x5570($at)
    MEM_W(-0X5570, ctx->r1) = ctx->r4;
    return;
    // 0x80133AB4: sw          $a0, -0x5570($at)
    MEM_W(-0X5570, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80133ab8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80133ab8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133AB8: nop

    // 0x80133ABC: nop

;}
RECOMP_FUNC void M7_FUN_80133ac0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133AC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133AC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80133AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133ACC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80133AD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80133AD4: jal         0x80126CC0
    // 0x80133AD8: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    LOOKUP_FUNC(0x80126CC0)(rdram, ctx);
        goto after_0;
    // 0x80133AD8: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    after_0:
    // 0x80133ADC: beq         $v0, $zero, L_80133AF0
    if (ctx->r2 == 0) {
        // 0x80133AE0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80133AF0;
    }
    // 0x80133AE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80133AE4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133AE8: jal         0x800058DC
    // 0x80133AEC: addiu       $a1, $a1, 0x3B00
    ctx->r5 = ADD32(ctx->r5, 0X3B00);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80133AEC: addiu       $a1, $a1, 0x3B00
    ctx->r5 = ADD32(ctx->r5, 0X3B00);
    after_1:
L_80133AF0:
    // 0x80133AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133AF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133AF8: jr          $ra
    // 0x80133AFC: nop

    return;
    // 0x80133AFC: nop

;}
RECOMP_FUNC void M7_FUN_80133b00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133B00: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80133B04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133B08: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80133B0C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80133B10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80133B14: jal         0x8001F74C
    // 0x80133B18: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_0;
    // 0x80133B18: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_0:
    // 0x80133B1C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80133B20: addiu       $t7, $t7, 0x4F30
    ctx->r15 = ADD32(ctx->r15, 0X4F30);
    // 0x80133B24: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133B28: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80133B2C: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x80133B30: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133B34: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80133B38: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80133B3C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80133B40: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80133B44: addiu       $a2, $a2, 0x4F40
    ctx->r6 = ADD32(ctx->r6, 0X4F40);
    // 0x80133B48: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80133B4C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80133B50: lw          $t1, 0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4);
    // 0x80133B54: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80133B58: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80133B5C: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x80133B60: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x80133B64: lw          $t2, 0x8($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X8);
    // 0x80133B68: lw          $t1, 0xC($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XC);
    // 0x80133B6C: sw          $t2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r10;
    // 0x80133B70: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    // 0x80133B74: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x80133B78: lw          $t3, 0x10($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X10);
    // 0x80133B7C: srl         $t4, $t3, 24
    ctx->r12 = S32(U32(ctx->r11) >> 24);
    // 0x80133B80: sltiu       $at, $t4, 0x1A
    ctx->r1 = ctx->r12 < 0X1A ? 1 : 0;
    // 0x80133B84: beq         $at, $zero, L_801352FC
    if (ctx->r1 == 0) {
        // 0x80133B88: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_801352FC;
    }
    // 0x80133B88: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80133B8C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80133B90: addu        $at, $at, $t4
    gpr jr_addend_80133B98 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80133B94: lw          $t4, -0x25E8($at)
    ctx->r12 = ADD32(ctx->r1, -0X25E8);
    // 0x80133B98: jr          $t4
    // 0x80133B9C: nop

    switch (jr_addend_80133B98 >> 2) {
        case 0: goto L_80133BA0; break;
        case 1: goto L_80133BFC; break;
        case 2: goto L_80133C64; break;
        case 3: goto L_80133D98; break;
        case 4: goto L_80133ED8; break;
        case 5: goto L_80133F94; break;
        case 6: goto L_801340F4; break;
        case 7: goto L_80134140; break;
        case 8: goto L_801342C4; break;
        case 9: goto L_801343EC; break;
        case 10: goto L_801344A4; break;
        case 11: goto L_80134620; break;
        case 12: goto L_801346D0; break;
        case 13: goto L_8013478C; break;
        case 14: goto L_801348C0; break;
        case 15: goto L_801352FC; break;
        case 16: goto L_801349C0; break;
        case 17: goto L_80134ADC; break;
        case 18: goto L_80134B70; break;
        case 19: goto L_80134C04; break;
        case 20: goto L_80134D80; break;
        case 21: goto L_80134E4C; break;
        case 22: goto L_80134F74; break;
        case 23: goto L_801350A0; break;
        case 24: goto L_801351D0; break;
        case 25: goto L_80134CC8; break;
        default: switch_error(__func__, 0x80133B98, 0x8018DA18);
    }
    // 0x80133B9C: nop

L_80133BA0:
    // 0x80133BA0: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x80133BA4: ori         $t5, $t5, 0xC00
    ctx->r13 = ctx->r13 | 0XC00;
    // 0x80133BA8: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x80133BAC: jal         0x80005F6C
    // 0x80133BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_1;
    // 0x80133BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80133BB4: jal         0x80006214
    // 0x80133BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x80133BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80133BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133BC0: jal         0x8012636C
    // 0x80133BC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_3;
    // 0x80133BC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80133BC8: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x80133BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133BD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133BD4: lw          $a2, 0x14($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X14);
    // 0x80133BD8: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x80133BDC: jal         0x8012C784
    // 0x80133BE0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_4;
    // 0x80133BE0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_4:
    // 0x80133BE4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80133BE8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80133BEC: addiu       $t7, $t7, -0x5168
    ctx->r15 = ADD32(ctx->r15, -0X5168);
    // 0x80133BF0: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80133BF4: b           L_801352FC
    // 0x80133BF8: sw          $t7, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r15;
        goto L_801352FC;
    // 0x80133BF8: sw          $t7, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r15;
L_80133BFC:
    // 0x80133BFC: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80133C00: ori         $t1, $t1, 0xB00
    ctx->r9 = ctx->r9 | 0XB00;
    // 0x80133C04: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80133C08: jal         0x80005F6C
    // 0x80133C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_5;
    // 0x80133C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80133C10: jal         0x80006214
    // 0x80133C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_6;
    // 0x80133C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80133C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133C1C: jal         0x8012636C
    // 0x80133C20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_7;
    // 0x80133C20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80133C24: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80133C28: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80133C2C: addiu       $t2, $t2, -0x4F08
    ctx->r10 = ADD32(ctx->r10, -0X4F08);
    // 0x80133C30: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80133C34: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80133C38: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80133C3C: sw          $t3, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r11;
    // 0x80133C40: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x80133C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133C48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133C4C: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x80133C50: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x80133C54: jal         0x8012C784
    // 0x80133C58: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_8;
    // 0x80133C58: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_8:
    // 0x80133C5C: b           L_801352FC
    // 0x80133C60: nop

        goto L_801352FC;
    // 0x80133C60: nop

L_80133C64:
    // 0x80133C64: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80133C68: ori         $t8, $t8, 0xA00
    ctx->r24 = ctx->r24 | 0XA00;
    // 0x80133C6C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80133C70: jal         0x80005F6C
    // 0x80133C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_9;
    // 0x80133C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80133C78: jal         0x80006214
    // 0x80133C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_10;
    // 0x80133C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80133C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133C84: jal         0x8012636C
    // 0x80133C88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_11;
    // 0x80133C88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80133C8C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80133C90: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80133C94: addiu       $t2, $t2, -0x48F0
    ctx->r10 = ADD32(ctx->r10, -0X48F0);
    // 0x80133C98: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80133C9C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80133CA0: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x80133CA4: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x80133CA8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80133CAC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80133CB0: ori         $t1, $t9, 0x100
    ctx->r9 = ctx->r25 | 0X100;
    // 0x80133CB4: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    // 0x80133CB8: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80133CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133CC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133CC4: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80133CC8: sw          $t4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r12;
    // 0x80133CCC: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x80133CD0: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80133CD4: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80133CD8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80133CDC: srl         $t9, $t8, 8
    ctx->r25 = S32(U32(ctx->r24) >> 8);
    // 0x80133CE0: sb          $t9, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r25;
    // 0x80133CE4: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80133CE8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80133CEC: lw          $t5, 0x10($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X10);
    // 0x80133CF0: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x80133CF4: sb          $t5, 0x48($t8)
    MEM_B(0X48, ctx->r24) = ctx->r13;
    // 0x80133CF8: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x80133CFC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80133D00: lw          $t1, 0x14($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X14);
    // 0x80133D04: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80133D08: srl         $t9, $t1, 24
    ctx->r25 = S32(U32(ctx->r9) >> 24);
    // 0x80133D0C: sb          $t9, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r25;
    // 0x80133D10: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x80133D14: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80133D18: lw          $t6, 0x14($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X14);
    // 0x80133D1C: lw          $t1, 0x30($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X30);
    // 0x80133D20: srl         $t8, $t6, 16
    ctx->r24 = S32(U32(ctx->r14) >> 16);
    // 0x80133D24: sb          $t8, 0x4A($t1)
    MEM_B(0X4A, ctx->r9) = ctx->r24;
    // 0x80133D28: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80133D2C: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x80133D30: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x80133D34: ori         $t3, $t9, 0x400
    ctx->r11 = ctx->r25 | 0X400;
    // 0x80133D38: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x80133D3C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80133D40: lbu         $t4, 0xF32($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF32);
    // 0x80133D44: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80133D48: sb          $t4, 0x4C($t5)
    MEM_B(0X4C, ctx->r13) = ctx->r12;
    // 0x80133D4C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80133D50: lbu         $t7, 0xF33($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XF33);
    // 0x80133D54: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x80133D58: sb          $t7, 0x4D($t1)
    MEM_B(0X4D, ctx->r9) = ctx->r15;
    // 0x80133D5C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80133D60: lbu         $t2, 0xF34($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XF34);
    // 0x80133D64: lw          $t3, 0x30($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X30);
    // 0x80133D68: sb          $t2, 0x4E($t3)
    MEM_B(0X4E, ctx->r11) = ctx->r10;
    // 0x80133D6C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80133D70: lbu         $t6, 0xF35($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF35);
    // 0x80133D74: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80133D78: sb          $t6, 0x4F($t5)
    MEM_B(0X4F, ctx->r13) = ctx->r14;
    // 0x80133D7C: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x80133D80: lw          $a2, 0x10($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X10);
    // 0x80133D84: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x80133D88: jal         0x8012C784
    // 0x80133D8C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_12;
    // 0x80133D8C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_12:
    // 0x80133D90: b           L_801352FC
    // 0x80133D94: nop

        goto L_801352FC;
    // 0x80133D94: nop

L_80133D98:
    // 0x80133D98: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80133D9C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80133DA0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80133DA4: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80133DA8: sw          $s0, 0x1044($v1)
    MEM_W(0X1044, ctx->r3) = ctx->r16;
    // 0x80133DAC: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80133DB0: jal         0x80005F6C
    // 0x80133DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_13;
    // 0x80133DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80133DB8: jal         0x80006214
    // 0x80133DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_14;
    // 0x80133DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80133DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133DC4: jal         0x8012636C
    // 0x80133DC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_15;
    // 0x80133DC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80133DCC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80133DD0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80133DD4: addiu       $t3, $t3, -0x4998
    ctx->r11 = ADD32(ctx->r11, -0X4998);
    // 0x80133DD8: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80133DDC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80133DE0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80133DE4: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x80133DE8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80133DEC: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80133DF0: ori         $t2, $t9, 0x100
    ctx->r10 = ctx->r25 | 0X100;
    // 0x80133DF4: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x80133DF8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80133DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133E00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133E04: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80133E08: sw          $t4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r12;
    // 0x80133E0C: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x80133E10: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80133E14: lw          $t7, 0x10($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X10);
    // 0x80133E18: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80133E1C: srl         $t9, $t7, 8
    ctx->r25 = S32(U32(ctx->r15) >> 8);
    // 0x80133E20: sb          $t9, 0x4B($t3)
    MEM_B(0X4B, ctx->r11) = ctx->r25;
    // 0x80133E24: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x80133E28: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80133E2C: lw          $t5, 0x10($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X10);
    // 0x80133E30: lw          $t7, 0x30($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X30);
    // 0x80133E34: sb          $t5, 0x48($t7)
    MEM_B(0X48, ctx->r15) = ctx->r13;
    // 0x80133E38: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x80133E3C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80133E40: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80133E44: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x80133E48: srl         $t9, $t2, 24
    ctx->r25 = S32(U32(ctx->r10) >> 24);
    // 0x80133E4C: sb          $t9, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r25;
    // 0x80133E50: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x80133E54: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80133E58: lw          $t8, 0x14($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X14);
    // 0x80133E5C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80133E60: srl         $t7, $t8, 16
    ctx->r15 = S32(U32(ctx->r24) >> 16);
    // 0x80133E64: sb          $t7, 0x4A($t2)
    MEM_B(0X4A, ctx->r10) = ctx->r15;
    // 0x80133E68: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80133E6C: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80133E70: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x80133E74: ori         $t6, $t9, 0x400
    ctx->r14 = ctx->r25 | 0X400;
    // 0x80133E78: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x80133E7C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80133E80: lbu         $t4, 0xF32($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF32);
    // 0x80133E84: lw          $t5, 0x30($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X30);
    // 0x80133E88: sb          $t4, 0x4C($t5)
    MEM_B(0X4C, ctx->r13) = ctx->r12;
    // 0x80133E8C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80133E90: lbu         $t1, 0xF33($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XF33);
    // 0x80133E94: lw          $t2, 0x30($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X30);
    // 0x80133E98: sb          $t1, 0x4D($t2)
    MEM_B(0X4D, ctx->r10) = ctx->r9;
    // 0x80133E9C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80133EA0: lbu         $t3, 0xF34($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XF34);
    // 0x80133EA4: lw          $t6, 0x30($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X30);
    // 0x80133EA8: sb          $t3, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r11;
    // 0x80133EAC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80133EB0: lbu         $t8, 0xF35($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF35);
    // 0x80133EB4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80133EB8: sb          $t8, 0x4F($t5)
    MEM_B(0X4F, ctx->r13) = ctx->r24;
    // 0x80133EBC: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x80133EC0: lw          $a2, 0x10($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X10);
    // 0x80133EC4: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x80133EC8: jal         0x8012C784
    // 0x80133ECC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_16;
    // 0x80133ECC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_16:
    // 0x80133ED0: b           L_801352FC
    // 0x80133ED4: nop

        goto L_801352FC;
    // 0x80133ED4: nop

L_80133ED8:
    // 0x80133ED8: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80133EDC: ori         $t1, $t1, 0xA00
    ctx->r9 = ctx->r9 | 0XA00;
    // 0x80133EE0: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80133EE4: jal         0x80005F6C
    // 0x80133EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_17;
    // 0x80133EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80133EEC: jal         0x80006214
    // 0x80133EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_18;
    // 0x80133EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80133EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133EF8: jal         0x8012636C
    // 0x80133EFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_19;
    // 0x80133EFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80133F00: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80133F04: addiu       $t2, $zero, 0x13
    ctx->r10 = ADD32(0, 0X13);
    // 0x80133F08: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80133F0C: lw          $t3, 0x30($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X30);
    // 0x80133F10: addiu       $t6, $t6, -0x4EB8
    ctx->r14 = ADD32(ctx->r14, -0X4EB8);
    // 0x80133F14: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80133F18: sw          $t2, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r10;
    // 0x80133F1C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80133F20: or          $t4, $t6, $at
    ctx->r12 = ctx->r14 | ctx->r1;
    // 0x80133F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133F28: lw          $t5, 0x30($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X30);
    // 0x80133F2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133F30: sw          $t4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r12;
    // 0x80133F34: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x80133F38: lw          $a2, 0x10($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X10);
    // 0x80133F3C: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x80133F40: jal         0x8012C784
    // 0x80133F44: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_20;
    // 0x80133F44: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_20:
    // 0x80133F48: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80133F4C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80133F50: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80133F54: lbu         $t1, 0xF32($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XF32);
    // 0x80133F58: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x80133F5C: sb          $t1, 0x4C($t2)
    MEM_B(0X4C, ctx->r10) = ctx->r9;
    // 0x80133F60: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80133F64: lbu         $t3, 0xF33($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XF33);
    // 0x80133F68: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x80133F6C: sb          $t3, 0x4D($t8)
    MEM_B(0X4D, ctx->r24) = ctx->r11;
    // 0x80133F70: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80133F74: lbu         $t4, 0xF34($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF34);
    // 0x80133F78: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80133F7C: sb          $t4, 0x4E($t7)
    MEM_B(0X4E, ctx->r15) = ctx->r12;
    // 0x80133F80: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80133F84: lbu         $t9, 0xF35($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF35);
    // 0x80133F88: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80133F8C: b           L_801352FC
    // 0x80133F90: sb          $t9, 0x4F($t2)
    MEM_B(0X4F, ctx->r10) = ctx->r25;
        goto L_801352FC;
    // 0x80133F90: sb          $t9, 0x4F($t2)
    MEM_B(0X4F, ctx->r10) = ctx->r25;
L_80133F94:
    // 0x80133F94: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80133F98: ori         $t6, $t6, 0xC00
    ctx->r14 = ctx->r14 | 0XC00;
    // 0x80133F9C: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80133FA0: jal         0x80005F6C
    // 0x80133FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_21;
    // 0x80133FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80133FA8: jal         0x80006214
    // 0x80133FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_22;
    // 0x80133FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80133FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133FB4: jal         0x8012636C
    // 0x80133FB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_23;
    // 0x80133FB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x80133FBC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80133FC0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80133FC4: addiu       $t3, $t3, -0x5168
    ctx->r11 = ADD32(ctx->r11, -0X5168);
    // 0x80133FC8: lw          $t5, 0x30($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X30);
    // 0x80133FCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133FD0: sw          $t3, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r11;
    // 0x80133FD4: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x80133FD8: lw          $t4, 0x10($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X10);
    // 0x80133FDC: srl         $t7, $t4, 8
    ctx->r15 = S32(U32(ctx->r12) >> 8);
    // 0x80133FE0: andi        $t1, $t7, 0xFF
    ctx->r9 = ctx->r15 & 0XFF;
    // 0x80133FE4: bnel        $t1, $at, L_80134060
    if (ctx->r9 != ctx->r1) {
        // 0x80133FE8: lw          $t2, 0x14($t0)
        ctx->r10 = MEM_W(ctx->r8, 0X14);
            goto L_80134060;
    }
    goto skip_0;
    // 0x80133FE8: lw          $t2, 0x14($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X14);
    skip_0:
    // 0x80133FEC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80133FF0: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x80133FF4: lw          $t6, 0x30($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X30);
    // 0x80133FF8: sw          $t9, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r25;
    // 0x80133FFC: jal         0x8000C3B0
    // 0x80134000: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_24;
    // 0x80134000: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_24:
    // 0x80134004: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80134008: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8013400C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80134010: lw          $t3, 0x30($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X30);
    // 0x80134014: sw          $v0, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r2;
    // 0x80134018: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8013401C: lbu         $t5, 0xF32($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XF32);
    // 0x80134020: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x80134024: sb          $t5, 0x4C($t7)
    MEM_B(0X4C, ctx->r15) = ctx->r13;
    // 0x80134028: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8013402C: lbu         $t1, 0xF33($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XF33);
    // 0x80134030: lw          $t9, 0x30($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X30);
    // 0x80134034: sb          $t1, 0x4D($t9)
    MEM_B(0X4D, ctx->r25) = ctx->r9;
    // 0x80134038: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8013403C: lbu         $t6, 0xF34($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF34);
    // 0x80134040: lw          $t3, 0x30($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X30);
    // 0x80134044: sb          $t6, 0x4E($t3)
    MEM_B(0X4E, ctx->r11) = ctx->r14;
    // 0x80134048: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8013404C: lbu         $t4, 0xF35($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF35);
    // 0x80134050: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80134054: sb          $t4, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r12;
    // 0x80134058: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x8013405C: lw          $t2, 0x14($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X14);
L_80134060:
    // 0x80134060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134068: srl         $t1, $t2, 16
    ctx->r9 = S32(U32(ctx->r10) >> 16);
    // 0x8013406C: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x80134070: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80134074: sw          $t8, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r24;
    // 0x80134078: lw          $t3, 0x14($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X14);
    // 0x8013407C: sll         $t5, $t3, 16
    ctx->r13 = S32(ctx->r11 << 16);
    // 0x80134080: sra         $t4, $t5, 16
    ctx->r12 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80134084: sw          $t4, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r12;
    // 0x80134088: lw          $t7, 0x18($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X18);
    // 0x8013408C: srl         $t2, $t7, 16
    ctx->r10 = S32(U32(ctx->r15) >> 16);
    // 0x80134090: sll         $t1, $t2, 16
    ctx->r9 = S32(ctx->r10 << 16);
    // 0x80134094: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80134098: sw          $t9, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r25;
    // 0x8013409C: lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X10);
    // 0x801340A0: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x801340A4: jal         0x8012C784
    // 0x801340A8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_25;
    // 0x801340A8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_25:
    // 0x801340AC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801340B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801340B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801340B8: lw          $t6, 0x30($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X30);
    // 0x801340BC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801340C0: addiu       $a1, $a1, 0x532C
    ctx->r5 = ADD32(ctx->r5, 0X532C);
    // 0x801340C4: swc1        $f4, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f4.u32l;
    // 0x801340C8: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801340CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801340D0: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801340D4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801340D8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801340DC: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801340E0: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x801340E4: jal         0x800058DC
    // 0x801340E8: swc1        $f0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f0.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_26;
    // 0x801340E8: swc1        $f0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f0.u32l;
    after_26:
    // 0x801340EC: b           L_80135310
    // 0x801340F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135310;
    // 0x801340F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801340F4:
    // 0x801340F4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801340F8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801340FC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80134100: addiu       $t7, $t7, -0x1A50
    ctx->r15 = ADD32(ctx->r15, -0X1A50);
    // 0x80134104: addiu       $t2, $t2, -0x1944
    ctx->r10 = ADD32(ctx->r10, -0X1944);
    // 0x80134108: addiu       $t1, $t1, 0x7014
    ctx->r9 = ADD32(ctx->r9, 0X7014);
    // 0x8013410C: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x80134110: sw          $t2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r10;
    // 0x80134114: sw          $t1, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r9;
    // 0x80134118: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8013411C: addiu       $t9, $t9, 0x53C0
    ctx->r25 = ADD32(ctx->r25, 0X53C0);
    // 0x80134120: lhu         $a1, 0x2($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X2);
    // 0x80134124: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80134128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013412C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80134130: jal         0x8013B570
    // 0x80134134: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_27;
    // 0x80134134: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_27:
    // 0x80134138: b           L_80135310
    // 0x8013413C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135310;
    // 0x8013413C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80134140:
    // 0x80134140: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80134144: ori         $t8, $t8, 0xC00
    ctx->r24 = ctx->r24 | 0XC00;
    // 0x80134148: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8013414C: jal         0x80005F6C
    // 0x80134150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_28;
    // 0x80134150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80134154: jal         0x80006214
    // 0x80134158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_29;
    // 0x80134158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8013415C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134160: jal         0x8012636C
    // 0x80134164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_30;
    // 0x80134164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_30:
    // 0x80134168: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8013416C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80134170: addiu       $t6, $t6, -0x5168
    ctx->r14 = ADD32(ctx->r14, -0X5168);
    // 0x80134174: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80134178: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013417C: sw          $t6, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r14;
    // 0x80134180: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x80134184: lw          $a3, 0x10($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X10);
    // 0x80134188: srl         $t7, $a3, 8
    ctx->r15 = S32(U32(ctx->r7) >> 8);
    // 0x8013418C: andi        $t2, $t7, 0xFF
    ctx->r10 = ctx->r15 & 0XFF;
    // 0x80134190: bnel        $t2, $at, L_80134210
    if (ctx->r10 != ctx->r1) {
        // 0x80134194: srl         $a2, $a3, 16
        ctx->r6 = S32(U32(ctx->r7) >> 16);
            goto L_80134210;
    }
    goto skip_1;
    // 0x80134194: srl         $a2, $a3, 16
    ctx->r6 = S32(U32(ctx->r7) >> 16);
    skip_1:
    // 0x80134198: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8013419C: addiu       $t1, $zero, 0x13
    ctx->r9 = ADD32(0, 0X13);
    // 0x801341A0: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801341A4: sw          $t1, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r9;
    // 0x801341A8: jal         0x8000C3B0
    // 0x801341AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_31;
    // 0x801341AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_31:
    // 0x801341B0: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801341B4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801341B8: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801341BC: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x801341C0: sw          $v0, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r2;
    // 0x801341C4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801341C8: lbu         $t5, 0xF32($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XF32);
    // 0x801341CC: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x801341D0: sb          $t5, 0x4C($t7)
    MEM_B(0X4C, ctx->r15) = ctx->r13;
    // 0x801341D4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801341D8: lbu         $t2, 0xF33($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XF33);
    // 0x801341DC: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801341E0: sb          $t2, 0x4D($t1)
    MEM_B(0X4D, ctx->r9) = ctx->r10;
    // 0x801341E4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801341E8: lbu         $t8, 0xF34($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF34);
    // 0x801341EC: lw          $t6, 0x30($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X30);
    // 0x801341F0: sb          $t8, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r24;
    // 0x801341F4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801341F8: lbu         $t4, 0xF35($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF35);
    // 0x801341FC: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80134200: sb          $t4, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r12;
    // 0x80134204: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x80134208: lw          $a3, 0x10($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X10);
    // 0x8013420C: srl         $a2, $a3, 16
    ctx->r6 = S32(U32(ctx->r7) >> 16);
L_80134210:
    // 0x80134210: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80134214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134218: jal         0x8012C784
    // 0x8013421C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_32;
    // 0x8013421C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x80134220: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x80134224: lw          $v0, 0x10($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X10);
    // 0x80134228: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8013422C: bnel        $v0, $zero, L_8013426C
    if (ctx->r2 != 0) {
        // 0x80134230: mtc1        $v0, $f8
        ctx->f8.u32l = ctx->r2;
            goto L_8013426C;
    }
    goto skip_2;
    // 0x80134230: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    skip_2:
    // 0x80134234: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80134238: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013423C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134240: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x80134244: swc1        $f6, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f6.u32l;
    // 0x80134248: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8013424C: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80134250: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80134254: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80134258: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8013425C: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80134260: b           L_801352FC
    // 0x80134264: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
        goto L_801352FC;
    // 0x80134264: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x80134268: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
L_8013426C:
    // 0x8013426C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80134270: bgez        $v0, L_80134288
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80134274: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80134288;
    }
    // 0x80134274: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80134278: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8013427C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80134280: nop

    // 0x80134284: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80134288:
    // 0x80134288: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x8013428C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80134290: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80134294: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80134298: div.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x8013429C: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x801342A0: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x801342A4: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x801342A8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801342AC: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x801342B0: swc1        $f0, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f0.u32l;
    // 0x801342B4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801342B8: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801342BC: b           L_801352FC
    // 0x801342C0: swc1        $f0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f0.u32l;
        goto L_801352FC;
    // 0x801342C0: swc1        $f0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f0.u32l;
L_801342C4:
    // 0x801342C4: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x801342C8: ori         $t8, $t8, 0xC00
    ctx->r24 = ctx->r24 | 0XC00;
    // 0x801342CC: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801342D0: jal         0x80005F6C
    // 0x801342D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_33;
    // 0x801342D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x801342D8: jal         0x80006214
    // 0x801342DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_34;
    // 0x801342DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x801342E0: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x801342E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801342E8: lwc1        $f0, -0x2580($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2580);
    // 0x801342EC: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x801342F0: addiu       $t6, $zero, 0x73
    ctx->r14 = ADD32(0, 0X73);
    // 0x801342F4: lui         $t7, 0x300
    ctx->r15 = S32(0X300 << 16);
    // 0x801342F8: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x801342FC: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80134300: addiu       $t7, $t7, 0x210
    ctx->r15 = ADD32(ctx->r15, 0X210);
    // 0x80134304: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80134308: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x8013430C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80134310: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134314: sw          $t7, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->r15;
    // 0x80134318: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x8013431C: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80134320: addiu       $a1, $a1, 0x5420
    ctx->r5 = ADD32(ctx->r5, 0X5420);
    // 0x80134324: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80134328: lw          $t2, 0x2C($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X2C);
    // 0x8013432C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134330: srl         $t8, $t3, 16
    ctx->r24 = S32(U32(ctx->r11) >> 16);
    // 0x80134334: andi        $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 & 0XFF;
    // 0x80134338: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8013433C: addu        $t4, $v1, $t6
    ctx->r12 = ADD32(ctx->r3, ctx->r14);
    // 0x80134340: lh          $t9, 0x11E($t4)
    ctx->r25 = MEM_H(ctx->r12, 0X11E);
    // 0x80134344: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80134348: nop

    // 0x8013434C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80134350: swc1        $f16, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f16.u32l;
    // 0x80134354: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x80134358: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8013435C: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80134360: lw          $t2, 0x2C($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X2C);
    // 0x80134364: srl         $t8, $t3, 16
    ctx->r24 = S32(U32(ctx->r11) >> 16);
    // 0x80134368: andi        $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 & 0XFF;
    // 0x8013436C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80134370: addu        $t4, $v1, $t6
    ctx->r12 = ADD32(ctx->r3, ctx->r14);
    // 0x80134374: lh          $t9, 0x130($t4)
    ctx->r25 = MEM_H(ctx->r12, 0X130);
    // 0x80134378: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8013437C: nop

    // 0x80134380: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80134384: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
    // 0x80134388: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x8013438C: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80134390: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80134394: lw          $t2, 0x2C($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X2C);
    // 0x80134398: srl         $t8, $t3, 16
    ctx->r24 = S32(U32(ctx->r11) >> 16);
    // 0x8013439C: andi        $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 & 0XFF;
    // 0x801343A0: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x801343A4: addu        $t4, $v1, $t6
    ctx->r12 = ADD32(ctx->r3, ctx->r14);
    // 0x801343A8: lh          $t9, 0x142($t4)
    ctx->r25 = MEM_H(ctx->r12, 0X142);
    // 0x801343AC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801343B0: nop

    // 0x801343B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801343B8: swc1        $f6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f6.u32l;
    // 0x801343BC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801343C0: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801343C4: swc1        $f0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f0.u32l;
    // 0x801343C8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801343CC: lw          $t5, 0x30($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X30);
    // 0x801343D0: swc1        $f0, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f0.u32l;
    // 0x801343D4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801343D8: lw          $t4, 0x30($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X30);
    // 0x801343DC: jal         0x800058DC
    // 0x801343E0: swc1        $f0, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f0.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_35;
    // 0x801343E0: swc1        $f0, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f0.u32l;
    after_35:
    // 0x801343E4: b           L_80135310
    // 0x801343E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135310;
    // 0x801343E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801343EC:
    // 0x801343EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801343F0: jal         0x80005F6C
    // 0x801343F4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_36;
    // 0x801343F4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_36:
    // 0x801343F8: jal         0x80006214
    // 0x801343FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_37;
    // 0x801343FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80134400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134404: jal         0x8012636C
    // 0x80134408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_38;
    // 0x80134408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x8013440C: lhu         $t9, 0x36($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X36);
    // 0x80134410: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80134414: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80134418: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8013441C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80134420: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x80134424: lw          $t8, 0x10($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X10);
    // 0x80134428: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8013442C: srl         $t5, $t8, 16
    ctx->r13 = S32(U32(ctx->r24) >> 16);
    // 0x80134430: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80134434: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80134438: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x8013443C: addu        $t9, $t1, $t4
    ctx->r25 = ADD32(ctx->r9, ctx->r12);
    // 0x80134440: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80134444: jal         0x8000522C
    // 0x80134448: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_39;
    // 0x80134448: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    after_39:
    // 0x8013444C: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x80134450: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x80134454: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134458: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x8013445C: addiu       $a1, $a1, 0x54CC
    ctx->r5 = ADD32(ctx->r5, 0X54CC);
    // 0x80134460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134464: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80134468: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
    // 0x8013446C: lw          $t2, 0x2C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2C);
    // 0x80134470: lwc1        $f16, 0x8($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80134474: swc1        $f16, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f16.u32l;
    // 0x80134478: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
    // 0x8013447C: lwc1        $f10, 0xC($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80134480: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
    // 0x80134484: swc1        $f10, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f10.u32l;
    // 0x80134488: lw          $t8, 0x2C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2C);
    // 0x8013448C: lh          $t5, 0x12($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X12);
    // 0x80134490: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80134494: jal         0x800058DC
    // 0x80134498: sh          $t5, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r13;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_40;
    // 0x80134498: sh          $t5, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r13;
    after_40:
    // 0x8013449C: b           L_80135310
    // 0x801344A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135310;
    // 0x801344A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801344A4:
    // 0x801344A4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x801344A8: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x801344AC: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x801344B0: jal         0x80005F6C
    // 0x801344B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_41;
    // 0x801344B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x801344B8: jal         0x80006214
    // 0x801344BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_42;
    // 0x801344BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x801344C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801344C4: jal         0x8012636C
    // 0x801344C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_43;
    // 0x801344C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_43:
    // 0x801344CC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801344D0: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x801344D4: ori         $t1, $t1, 0x600
    ctx->r9 = ctx->r9 | 0X600;
    // 0x801344D8: sw          $t1, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r9;
    // 0x801344DC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801344E0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x801344E4: addiu       $t3, $t3, -0x4A58
    ctx->r11 = ADD32(ctx->r11, -0X4A58);
    // 0x801344E8: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801344EC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801344F0: or          $t8, $t3, $at
    ctx->r24 = ctx->r11 | ctx->r1;
    // 0x801344F4: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x801344F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801344FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134500: ori         $t2, $t7, 0x100
    ctx->r10 = ctx->r15 | 0X100;
    // 0x80134504: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x80134508: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8013450C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80134510: sw          $t8, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r24;
    // 0x80134514: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x80134518: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8013451C: lw          $t4, 0x10($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X10);
    // 0x80134520: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80134524: srl         $t7, $t4, 8
    ctx->r15 = S32(U32(ctx->r12) >> 8);
    // 0x80134528: sb          $t7, 0x4B($t3)
    MEM_B(0X4B, ctx->r11) = ctx->r15;
    // 0x8013452C: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x80134530: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80134534: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x80134538: lw          $t4, 0x30($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X30);
    // 0x8013453C: sb          $t6, 0x48($t4)
    MEM_B(0X48, ctx->r12) = ctx->r14;
    // 0x80134540: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x80134544: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80134548: lw          $t2, 0x14($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X14);
    // 0x8013454C: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80134550: srl         $t7, $t2, 24
    ctx->r15 = S32(U32(ctx->r10) >> 24);
    // 0x80134554: sb          $t7, 0x49($t5)
    MEM_B(0X49, ctx->r13) = ctx->r15;
    // 0x80134558: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x8013455C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80134560: lw          $t1, 0x14($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X14);
    // 0x80134564: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x80134568: srl         $t4, $t1, 16
    ctx->r12 = S32(U32(ctx->r9) >> 16);
    // 0x8013456C: sb          $t4, 0x4A($t2)
    MEM_B(0X4A, ctx->r10) = ctx->r12;
    // 0x80134570: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80134574: lw          $a2, 0x10($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X10);
    // 0x80134578: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x8013457C: jal         0x8012C784
    // 0x80134580: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_44;
    // 0x80134580: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_44:
    // 0x80134584: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x80134588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013458C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134590: lw          $t7, 0x14($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X14);
    // 0x80134594: srl         $t8, $t7, 8
    ctx->r24 = S32(U32(ctx->r15) >> 8);
    // 0x80134598: sll         $t1, $t8, 24
    ctx->r9 = S32(ctx->r24 << 24);
    // 0x8013459C: sra         $t6, $t1, 24
    ctx->r14 = S32(SIGNED(ctx->r9) >> 24);
    // 0x801345A0: sw          $t6, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r14;
    // 0x801345A4: lw          $t4, 0x14($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X14);
    // 0x801345A8: sll         $t2, $t4, 24
    ctx->r10 = S32(ctx->r12 << 24);
    // 0x801345AC: sra         $t3, $t2, 24
    ctx->r11 = S32(SIGNED(ctx->r10) >> 24);
    // 0x801345B0: sw          $t3, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r11;
    // 0x801345B4: lw          $t7, 0x18($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X18);
    // 0x801345B8: srl         $t5, $t7, 24
    ctx->r13 = S32(U32(ctx->r15) >> 24);
    // 0x801345BC: sll         $t8, $t5, 24
    ctx->r24 = S32(ctx->r13 << 24);
    // 0x801345C0: sra         $t1, $t8, 24
    ctx->r9 = S32(SIGNED(ctx->r24) >> 24);
    // 0x801345C4: sw          $t1, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r9;
    // 0x801345C8: lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X10);
    // 0x801345CC: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x801345D0: jal         0x8012C784
    // 0x801345D4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_45;
    // 0x801345D4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_45:
    // 0x801345D8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801345DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801345E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801345E4: lw          $t9, 0x30($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X30);
    // 0x801345E8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801345EC: addiu       $a1, $a1, 0x532C
    ctx->r5 = ADD32(ctx->r5, 0X532C);
    // 0x801345F0: swc1        $f18, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f18.u32l;
    // 0x801345F4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801345F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801345FC: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x80134600: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80134604: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80134608: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8013460C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80134610: jal         0x800058DC
    // 0x80134614: swc1        $f0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f0.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_46;
    // 0x80134614: swc1        $f0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f0.u32l;
    after_46:
    // 0x80134618: b           L_80135310
    // 0x8013461C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135310;
    // 0x8013461C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80134620:
    // 0x80134620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134624: jal         0x80005F6C
    // 0x80134628: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_47;
    // 0x80134628: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_47:
    // 0x8013462C: jal         0x80006214
    // 0x80134630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_48;
    // 0x80134630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x80134634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134638: jal         0x8012636C
    // 0x8013463C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_49;
    // 0x8013463C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_49:
    // 0x80134640: lhu         $t7, 0x36($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X36);
    // 0x80134644: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x80134648: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8013464C: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x80134650: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80134654: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x80134658: lw          $t9, 0x10($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X10);
    // 0x8013465C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80134660: srl         $t4, $t9, 16
    ctx->r12 = S32(U32(ctx->r25) >> 16);
    // 0x80134664: andi        $t2, $t4, 0xFF
    ctx->r10 = ctx->r12 & 0XFF;
    // 0x80134668: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8013466C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80134670: addu        $t7, $t1, $t3
    ctx->r15 = ADD32(ctx->r9, ctx->r11);
    // 0x80134674: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80134678: jal         0x8000522C
    // 0x8013467C: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_50;
    // 0x8013467C: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    after_50:
    // 0x80134680: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    // 0x80134684: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x80134688: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x8013468C: ori         $t8, $t5, 0x800
    ctx->r24 = ctx->r13 | 0X800;
    // 0x80134690: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    // 0x80134694: lw          $t6, 0x30($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X30);
    // 0x80134698: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8013469C: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
    // 0x801346A0: lw          $t9, 0x30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X30);
    // 0x801346A4: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x801346A8: swc1        $f6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f6.u32l;
    // 0x801346AC: lw          $t4, 0x30($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X30);
    // 0x801346B0: lwc1        $f8, 0xC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XC);
    // 0x801346B4: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
    // 0x801346B8: swc1        $f8, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f8.u32l;
    // 0x801346BC: lw          $t2, 0x30($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X30);
    // 0x801346C0: lh          $t1, 0x12($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X12);
    // 0x801346C4: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x801346C8: b           L_801352FC
    // 0x801346CC: sh          $t1, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r9;
        goto L_801352FC;
    // 0x801346CC: sh          $t1, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r9;
L_801346D0:
    // 0x801346D0: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x801346D4: ori         $t3, $t3, 0xA00
    ctx->r11 = ctx->r11 | 0XA00;
    // 0x801346D8: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x801346DC: jal         0x80005F6C
    // 0x801346E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_51;
    // 0x801346E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x801346E4: jal         0x80006214
    // 0x801346E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_52;
    // 0x801346E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x801346EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801346F0: jal         0x8012636C
    // 0x801346F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_53;
    // 0x801346F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_53:
    // 0x801346F8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801346FC: addiu       $t7, $zero, 0x13
    ctx->r15 = ADD32(0, 0X13);
    // 0x80134700: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80134704: lw          $t8, 0x30($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X30);
    // 0x80134708: addiu       $t6, $t6, -0x4E60
    ctx->r14 = ADD32(ctx->r14, -0X4E60);
    // 0x8013470C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80134710: sw          $t7, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r15;
    // 0x80134714: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80134718: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8013471C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134720: lw          $t2, 0x30($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X30);
    // 0x80134724: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134728: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
    // 0x8013472C: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x80134730: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    // 0x80134734: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x80134738: jal         0x8012C784
    // 0x8013473C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_54;
    // 0x8013473C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_54:
    // 0x80134740: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80134744: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80134748: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8013474C: lbu         $t3, 0xF32($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XF32);
    // 0x80134750: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80134754: sb          $t3, 0x4C($t7)
    MEM_B(0X4C, ctx->r15) = ctx->r11;
    // 0x80134758: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8013475C: lbu         $t8, 0xF33($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF33);
    // 0x80134760: lw          $t4, 0x30($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X30);
    // 0x80134764: sb          $t8, 0x4D($t4)
    MEM_B(0X4D, ctx->r12) = ctx->r24;
    // 0x80134768: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8013476C: lbu         $t9, 0xF34($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF34);
    // 0x80134770: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80134774: sb          $t9, 0x4E($t1)
    MEM_B(0X4E, ctx->r9) = ctx->r25;
    // 0x80134778: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8013477C: lbu         $t5, 0xF35($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XF35);
    // 0x80134780: lw          $t7, 0x30($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X30);
    // 0x80134784: b           L_801352FC
    // 0x80134788: sb          $t5, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r13;
        goto L_801352FC;
    // 0x80134788: sb          $t5, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r13;
L_8013478C:
    // 0x8013478C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80134790: ori         $t6, $t6, 0xA00
    ctx->r14 = ctx->r14 | 0XA00;
    // 0x80134794: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80134798: jal         0x80005F6C
    // 0x8013479C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_55;
    // 0x8013479C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x801347A0: jal         0x80006214
    // 0x801347A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_56;
    // 0x801347A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x801347A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801347AC: jal         0x8012636C
    // 0x801347B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_57;
    // 0x801347B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_57:
    // 0x801347B4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801347B8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x801347BC: addiu       $t9, $t9, -0x4940
    ctx->r25 = ADD32(ctx->r25, -0X4940);
    // 0x801347C0: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801347C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801347C8: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x801347CC: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x801347D0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801347D4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801347D8: ori         $t2, $t4, 0x100
    ctx->r10 = ctx->r12 | 0X100;
    // 0x801347DC: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x801347E0: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801347E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801347E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801347EC: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801347F0: sw          $t1, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r9;
    // 0x801347F4: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x801347F8: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801347FC: lw          $t6, 0x10($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X10);
    // 0x80134800: lw          $t9, 0x30($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X30);
    // 0x80134804: srl         $t4, $t6, 8
    ctx->r12 = S32(U32(ctx->r14) >> 8);
    // 0x80134808: sb          $t4, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r12;
    // 0x8013480C: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80134810: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80134814: lw          $t5, 0x10($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X10);
    // 0x80134818: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x8013481C: sb          $t5, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r13;
    // 0x80134820: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x80134824: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80134828: lw          $t2, 0x14($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X14);
    // 0x8013482C: lw          $t3, 0x30($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X30);
    // 0x80134830: srl         $t4, $t2, 24
    ctx->r12 = S32(U32(ctx->r10) >> 24);
    // 0x80134834: sb          $t4, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r12;
    // 0x80134838: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x8013483C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80134840: lw          $t7, 0x14($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X14);
    // 0x80134844: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x80134848: srl         $t6, $t7, 16
    ctx->r14 = S32(U32(ctx->r15) >> 16);
    // 0x8013484C: sb          $t6, 0x4A($t2)
    MEM_B(0X4A, ctx->r10) = ctx->r14;
    // 0x80134850: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80134854: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80134858: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x8013485C: ori         $t3, $t4, 0x400
    ctx->r11 = ctx->r12 | 0X400;
    // 0x80134860: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x80134864: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80134868: lbu         $t1, 0xF32($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XF32);
    // 0x8013486C: lw          $t5, 0x30($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X30);
    // 0x80134870: sb          $t1, 0x4C($t5)
    MEM_B(0X4C, ctx->r13) = ctx->r9;
    // 0x80134874: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80134878: lbu         $t8, 0xF33($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF33);
    // 0x8013487C: lw          $t2, 0x30($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X30);
    // 0x80134880: sb          $t8, 0x4D($t2)
    MEM_B(0X4D, ctx->r10) = ctx->r24;
    // 0x80134884: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80134888: lbu         $t9, 0xF34($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF34);
    // 0x8013488C: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x80134890: sb          $t9, 0x4E($t3)
    MEM_B(0X4E, ctx->r11) = ctx->r25;
    // 0x80134894: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80134898: lbu         $t7, 0xF35($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XF35);
    // 0x8013489C: lw          $t5, 0x30($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X30);
    // 0x801348A0: sb          $t7, 0x4F($t5)
    MEM_B(0X4F, ctx->r13) = ctx->r15;
    // 0x801348A4: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x801348A8: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x801348AC: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x801348B0: jal         0x8012C784
    // 0x801348B4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_58;
    // 0x801348B4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_58:
    // 0x801348B8: b           L_801352FC
    // 0x801348BC: nop

        goto L_801352FC;
    // 0x801348BC: nop

L_801348C0:
    // 0x801348C0: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x801348C4: ori         $t8, $t8, 0xC00
    ctx->r24 = ctx->r24 | 0XC00;
    // 0x801348C8: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801348CC: jal         0x80005F6C
    // 0x801348D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_59;
    // 0x801348D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x801348D4: jal         0x80006214
    // 0x801348D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_60;
    // 0x801348D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x801348DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801348E0: jal         0x8012636C
    // 0x801348E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_61;
    // 0x801348E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_61:
    // 0x801348E8: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801348EC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x801348F0: addiu       $t2, $t2, -0x5168
    ctx->r10 = ADD32(ctx->r10, -0X5168);
    // 0x801348F4: lw          $t9, 0x30($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X30);
    // 0x801348F8: addiu       $t3, $zero, 0x13
    ctx->r11 = ADD32(0, 0X13);
    // 0x801348FC: sw          $t2, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r10;
    // 0x80134900: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80134904: lw          $t7, 0x30($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X30);
    // 0x80134908: sw          $t3, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r11;
    // 0x8013490C: jal         0x8000C3B0
    // 0x80134910: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_62;
    // 0x80134910: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_62:
    // 0x80134914: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80134918: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8013491C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80134920: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80134924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013492C: sw          $v0, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r2;
    // 0x80134930: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80134934: lbu         $t8, 0xF32($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF32);
    // 0x80134938: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8013493C: lw          $t2, 0x30($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X30);
    // 0x80134940: sb          $t8, 0x4C($t2)
    MEM_B(0X4C, ctx->r10) = ctx->r24;
    // 0x80134944: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80134948: lbu         $t9, 0xF33($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF33);
    // 0x8013494C: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x80134950: sb          $t9, 0x4D($t3)
    MEM_B(0X4D, ctx->r11) = ctx->r25;
    // 0x80134954: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80134958: lbu         $t7, 0xF34($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XF34);
    // 0x8013495C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80134960: sb          $t7, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r15;
    // 0x80134964: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80134968: lbu         $t4, 0xF35($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF35);
    // 0x8013496C: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x80134970: jal         0x8012C784
    // 0x80134974: sb          $t4, 0x4F($t2)
    MEM_B(0X4F, ctx->r10) = ctx->r12;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_63;
    // 0x80134974: sb          $t4, 0x4F($t2)
    MEM_B(0X4F, ctx->r10) = ctx->r12;
    after_63:
    // 0x80134978: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8013497C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80134980: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80134984: lw          $t9, 0x30($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X30);
    // 0x80134988: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013498C: addiu       $a1, $a1, 0x5520
    ctx->r5 = ADD32(ctx->r5, 0X5520);
    // 0x80134990: swc1        $f16, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f16.u32l;
    // 0x80134994: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80134998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013499C: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801349A0: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801349A4: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801349A8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801349AC: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x801349B0: jal         0x800058DC
    // 0x801349B4: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_64;
    // 0x801349B4: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    after_64:
    // 0x801349B8: b           L_80135310
    // 0x801349BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135310;
    // 0x801349BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801349C0:
    // 0x801349C0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x801349C4: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x801349C8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x801349CC: jal         0x80005F6C
    // 0x801349D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_65;
    // 0x801349D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_65:
    // 0x801349D4: jal         0x80006214
    // 0x801349D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_66;
    // 0x801349D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_66:
    // 0x801349DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801349E0: jal         0x8012636C
    // 0x801349E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_67;
    // 0x801349E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_67:
    // 0x801349E8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801349EC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x801349F0: addiu       $t1, $t1, -0x5548
    ctx->r9 = ADD32(ctx->r9, -0X5548);
    // 0x801349F4: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801349F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801349FC: or          $t9, $t1, $at
    ctx->r25 = ctx->r9 | ctx->r1;
    // 0x80134A00: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x80134A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134A0C: ori         $t2, $t4, 0x300
    ctx->r10 = ctx->r12 | 0X300;
    // 0x80134A10: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x80134A14: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80134A18: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80134A1C: sw          $t9, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r25;
    // 0x80134A20: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x80134A24: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80134A28: lw          $t6, 0x10($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X10);
    // 0x80134A2C: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x80134A30: srl         $t4, $t6, 8
    ctx->r12 = S32(U32(ctx->r14) >> 8);
    // 0x80134A34: sb          $t4, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r12;
    // 0x80134A38: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80134A3C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80134A40: lw          $t5, 0x10($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X10);
    // 0x80134A44: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x80134A48: sb          $t5, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r13;
    // 0x80134A4C: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x80134A50: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80134A54: lw          $t2, 0x14($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X14);
    // 0x80134A58: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x80134A5C: srl         $t4, $t2, 24
    ctx->r12 = S32(U32(ctx->r10) >> 24);
    // 0x80134A60: sb          $t4, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r12;
    // 0x80134A64: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x80134A68: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80134A6C: lw          $t7, 0x14($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X14);
    // 0x80134A70: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x80134A74: srl         $t6, $t7, 16
    ctx->r14 = S32(U32(ctx->r15) >> 16);
    // 0x80134A78: sb          $t6, 0x4A($t2)
    MEM_B(0X4A, ctx->r10) = ctx->r14;
    // 0x80134A7C: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x80134A80: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80134A84: lw          $t4, 0x14($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X14);
    // 0x80134A88: lw          $t5, 0x30($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X30);
    // 0x80134A8C: srl         $t9, $t4, 8
    ctx->r25 = S32(U32(ctx->r12) >> 8);
    // 0x80134A90: sb          $t9, 0x4C($t5)
    MEM_B(0X4C, ctx->r13) = ctx->r25;
    // 0x80134A94: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x80134A98: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80134A9C: lw          $t2, 0x14($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X14);
    // 0x80134AA0: lw          $t4, 0x30($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X30);
    // 0x80134AA4: sb          $t2, 0x4D($t4)
    MEM_B(0X4D, ctx->r12) = ctx->r10;
    // 0x80134AA8: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80134AAC: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80134AB0: lw          $t7, 0x18($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X18);
    // 0x80134AB4: lw          $t8, 0x30($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X30);
    // 0x80134AB8: srl         $t9, $t7, 24
    ctx->r25 = S32(U32(ctx->r15) >> 24);
    // 0x80134ABC: sb          $t9, 0x4E($t8)
    MEM_B(0X4E, ctx->r24) = ctx->r25;
    // 0x80134AC0: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x80134AC4: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x80134AC8: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x80134ACC: jal         0x8012C784
    // 0x80134AD0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_68;
    // 0x80134AD0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_68:
    // 0x80134AD4: b           L_801352FC
    // 0x80134AD8: nop

        goto L_801352FC;
    // 0x80134AD8: nop

L_80134ADC:
    // 0x80134ADC: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80134AE0: ori         $t1, $t1, 0x400
    ctx->r9 = ctx->r9 | 0X400;
    // 0x80134AE4: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80134AE8: jal         0x80005F6C
    // 0x80134AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_69;
    // 0x80134AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_69:
    // 0x80134AF0: jal         0x80006214
    // 0x80134AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_70;
    // 0x80134AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_70:
    // 0x80134AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134AFC: jal         0x8012636C
    // 0x80134B00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_71;
    // 0x80134B00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_71:
    // 0x80134B04: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80134B08: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80134B0C: addiu       $t7, $t7, -0x54E8
    ctx->r15 = ADD32(ctx->r15, -0X54E8);
    // 0x80134B10: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x80134B14: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80134B18: or          $t5, $t7, $at
    ctx->r13 = ctx->r15 | ctx->r1;
    // 0x80134B1C: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x80134B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134B28: ori         $t3, $t4, 0x100
    ctx->r11 = ctx->r12 | 0X100;
    // 0x80134B2C: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x80134B30: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80134B34: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80134B38: sw          $t5, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r13;
    // 0x80134B3C: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x80134B40: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80134B44: lw          $t1, 0x10($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X10);
    // 0x80134B48: lw          $t7, 0x30($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X30);
    // 0x80134B4C: srl         $t4, $t1, 8
    ctx->r12 = S32(U32(ctx->r9) >> 8);
    // 0x80134B50: sb          $t4, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = ctx->r12;
    // 0x80134B54: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x80134B58: lw          $a2, 0x10($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X10);
    // 0x80134B5C: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x80134B60: jal         0x8012C784
    // 0x80134B64: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_72;
    // 0x80134B64: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_72:
    // 0x80134B68: b           L_801352FC
    // 0x80134B6C: nop

        goto L_801352FC;
    // 0x80134B6C: nop

L_80134B70:
    // 0x80134B70: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x80134B74: ori         $t5, $t5, 0x400
    ctx->r13 = ctx->r13 | 0X400;
    // 0x80134B78: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x80134B7C: jal         0x80005F6C
    // 0x80134B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_73;
    // 0x80134B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_73:
    // 0x80134B84: jal         0x80006214
    // 0x80134B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_74;
    // 0x80134B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_74:
    // 0x80134B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134B90: jal         0x8012636C
    // 0x80134B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_75;
    // 0x80134B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_75:
    // 0x80134B98: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80134B9C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80134BA0: addiu       $t2, $t2, -0x5498
    ctx->r10 = ADD32(ctx->r10, -0X5498);
    // 0x80134BA4: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80134BA8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80134BAC: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80134BB0: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80134BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134BB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134BBC: ori         $t1, $t6, 0x100
    ctx->r9 = ctx->r14 | 0X100;
    // 0x80134BC0: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    // 0x80134BC4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80134BC8: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x80134BCC: sw          $t3, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r11;
    // 0x80134BD0: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x80134BD4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80134BD8: lw          $t5, 0x10($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X10);
    // 0x80134BDC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80134BE0: srl         $t6, $t5, 8
    ctx->r14 = S32(U32(ctx->r13) >> 8);
    // 0x80134BE4: sb          $t6, 0x4B($t2)
    MEM_B(0X4B, ctx->r10) = ctx->r14;
    // 0x80134BE8: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x80134BEC: lw          $a2, 0x10($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X10);
    // 0x80134BF0: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x80134BF4: jal         0x8012C784
    // 0x80134BF8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_76;
    // 0x80134BF8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_76:
    // 0x80134BFC: b           L_801352FC
    // 0x80134C00: nop

        goto L_801352FC;
    // 0x80134C00: nop

L_80134C04:
    // 0x80134C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134C08: jal         0x80005F6C
    // 0x80134C0C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_77;
    // 0x80134C0C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_77:
    // 0x80134C10: jal         0x80006214
    // 0x80134C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_78;
    // 0x80134C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_78:
    // 0x80134C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134C1C: jal         0x8012636C
    // 0x80134C20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_79;
    // 0x80134C20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_79:
    // 0x80134C24: lhu         $t3, 0x36($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X36);
    // 0x80134C28: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x80134C2C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80134C30: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x80134C34: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80134C38: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x80134C3C: lw          $t1, 0x10($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X10);
    // 0x80134C40: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x80134C44: srl         $t6, $t1, 16
    ctx->r14 = S32(U32(ctx->r9) >> 16);
    // 0x80134C48: andi        $t2, $t6, 0xFF
    ctx->r10 = ctx->r14 & 0XFF;
    // 0x80134C4C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80134C50: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80134C54: addu        $t3, $t5, $t4
    ctx->r11 = ADD32(ctx->r13, ctx->r12);
    // 0x80134C58: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80134C5C: jal         0x8000522C
    // 0x80134C60: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_80;
    // 0x80134C60: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    after_80:
    // 0x80134C64: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80134C68: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x80134C6C: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x80134C70: ori         $t9, $t7, 0x800
    ctx->r25 = ctx->r15 | 0X800;
    // 0x80134C74: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x80134C78: lw          $t8, 0x30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30);
    // 0x80134C7C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134C80: addiu       $a1, $a1, 0x55D8
    ctx->r5 = ADD32(ctx->r5, 0X55D8);
    // 0x80134C84: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80134C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134C8C: swc1        $f10, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f10.u32l;
    // 0x80134C90: lw          $t1, 0x30($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X30);
    // 0x80134C94: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80134C98: swc1        $f18, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f18.u32l;
    // 0x80134C9C: lw          $t6, 0x30($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X30);
    // 0x80134CA0: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80134CA4: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
    // 0x80134CA8: swc1        $f4, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f4.u32l;
    // 0x80134CAC: lw          $t2, 0x30($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X30);
    // 0x80134CB0: lh          $t5, 0x12($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X12);
    // 0x80134CB4: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80134CB8: jal         0x800058DC
    // 0x80134CBC: sh          $t5, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r13;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_81;
    // 0x80134CBC: sh          $t5, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r13;
    after_81:
    // 0x80134CC0: b           L_80135310
    // 0x80134CC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135310;
    // 0x80134CC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80134CC8:
    // 0x80134CC8: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80134CCC: ori         $t4, $t4, 0xC00
    ctx->r12 = ctx->r12 | 0XC00;
    // 0x80134CD0: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x80134CD4: jal         0x80005F6C
    // 0x80134CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_82;
    // 0x80134CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_82:
    // 0x80134CDC: jal         0x80006214
    // 0x80134CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_83;
    // 0x80134CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_83:
    // 0x80134CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134CE8: jal         0x8012636C
    // 0x80134CEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_84;
    // 0x80134CEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_84:
    // 0x80134CF0: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80134CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134CFC: lw          $a2, 0x10($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X10);
    // 0x80134D00: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x80134D04: jal         0x8012C784
    // 0x80134D08: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_85;
    // 0x80134D08: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_85:
    // 0x80134D0C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80134D10: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80134D14: addiu       $t7, $t7, -0x50C8
    ctx->r15 = ADD32(ctx->r15, -0X50C8);
    // 0x80134D18: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x80134D1C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80134D20: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80134D24: sw          $t7, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r15;
    // 0x80134D28: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80134D2C: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80134D30: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80134D34: ori         $t2, $t6, 0x400
    ctx->r10 = ctx->r14 | 0X400;
    // 0x80134D38: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x80134D3C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80134D40: lbu         $t5, 0xF32($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XF32);
    // 0x80134D44: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x80134D48: sb          $t5, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = ctx->r13;
    // 0x80134D4C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80134D50: lbu         $t9, 0xF33($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF33);
    // 0x80134D54: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80134D58: sb          $t9, 0x4D($t8)
    MEM_B(0X4D, ctx->r24) = ctx->r25;
    // 0x80134D5C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80134D60: lbu         $t1, 0xF34($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XF34);
    // 0x80134D64: lw          $t2, 0x30($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X30);
    // 0x80134D68: sb          $t1, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = ctx->r9;
    // 0x80134D6C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80134D70: lbu         $t4, 0xF35($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF35);
    // 0x80134D74: lw          $t3, 0x30($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X30);
    // 0x80134D78: b           L_801352FC
    // 0x80134D7C: sb          $t4, 0x4F($t3)
    MEM_B(0X4F, ctx->r11) = ctx->r12;
        goto L_801352FC;
    // 0x80134D7C: sb          $t4, 0x4F($t3)
    MEM_B(0X4F, ctx->r11) = ctx->r12;
L_80134D80:
    // 0x80134D80: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80134D84: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80134D88: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80134D8C: jal         0x80005F6C
    // 0x80134D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_86;
    // 0x80134D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_86:
    // 0x80134D94: jal         0x80006214
    // 0x80134D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_87;
    // 0x80134D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_87:
    // 0x80134D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134DA0: jal         0x8012636C
    // 0x80134DA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_88;
    // 0x80134DA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_88:
    // 0x80134DA8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80134DAC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80134DB0: addiu       $t1, $t1, -0x5448
    ctx->r9 = ADD32(ctx->r9, -0X5448);
    // 0x80134DB4: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80134DB8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80134DBC: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x80134DC0: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x80134DC4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80134DC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134DCC: ori         $t6, $t8, 0x100
    ctx->r14 = ctx->r24 | 0X100;
    // 0x80134DD0: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x80134DD4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80134DD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134DDC: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x80134DE0: sw          $t2, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r10;
    // 0x80134DE4: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80134DE8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80134DEC: lw          $t7, 0x10($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X10);
    // 0x80134DF0: lw          $t1, 0x30($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X30);
    // 0x80134DF4: srl         $t8, $t7, 8
    ctx->r24 = S32(U32(ctx->r15) >> 8);
    // 0x80134DF8: sb          $t8, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r24;
    // 0x80134DFC: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80134E00: lw          $t2, 0x30($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X30);
    // 0x80134E04: sb          $a3, 0x48($t2)
    MEM_B(0X48, ctx->r10) = ctx->r7;
    // 0x80134E08: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80134E0C: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x80134E10: sb          $a3, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r7;
    // 0x80134E14: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80134E18: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x80134E1C: sb          $a3, 0x4A($t9)
    MEM_B(0X4A, ctx->r25) = ctx->r7;
    // 0x80134E20: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x80134E24: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x80134E28: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x80134E2C: jal         0x8012C784
    // 0x80134E30: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_89;
    // 0x80134E30: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_89:
    // 0x80134E34: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134E38: addiu       $a1, $a1, 0x5678
    ctx->r5 = ADD32(ctx->r5, 0X5678);
    // 0x80134E3C: jal         0x800058DC
    // 0x80134E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_90;
    // 0x80134E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_90:
    // 0x80134E44: b           L_80135310
    // 0x80134E48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135310;
    // 0x80134E48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80134E4C:
    // 0x80134E4C: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80134E50: ori         $t8, $t8, 0xA00
    ctx->r24 = ctx->r24 | 0XA00;
    // 0x80134E54: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80134E58: jal         0x80005F6C
    // 0x80134E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_91;
    // 0x80134E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_91:
    // 0x80134E60: jal         0x80006214
    // 0x80134E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_92;
    // 0x80134E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_92:
    // 0x80134E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134E6C: jal         0x8012636C
    // 0x80134E70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_93;
    // 0x80134E70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_93:
    // 0x80134E74: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80134E78: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80134E7C: addiu       $t4, $t4, -0x48F0
    ctx->r12 = ADD32(ctx->r12, -0X48F0);
    // 0x80134E80: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80134E84: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80134E88: or          $t3, $t4, $at
    ctx->r11 = ctx->r12 | ctx->r1;
    // 0x80134E8C: lw          $t5, 0x24($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X24);
    // 0x80134E90: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80134E94: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80134E98: ori         $t2, $t5, 0x100
    ctx->r10 = ctx->r13 | 0X100;
    // 0x80134E9C: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x80134EA0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80134EA4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80134EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134EAC: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x80134EB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134EB4: sw          $t3, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r11;
    // 0x80134EB8: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x80134EBC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80134EC0: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80134EC4: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x80134EC8: srl         $t5, $t8, 8
    ctx->r13 = S32(U32(ctx->r24) >> 8);
    // 0x80134ECC: sb          $t5, 0x4B($t4)
    MEM_B(0X4B, ctx->r12) = ctx->r13;
    // 0x80134ED0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80134ED4: lw          $t3, 0x30($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X30);
    // 0x80134ED8: sb          $a3, 0x48($t3)
    MEM_B(0X48, ctx->r11) = ctx->r7;
    // 0x80134EDC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80134EE0: lw          $t6, 0x30($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X30);
    // 0x80134EE4: sb          $a3, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r7;
    // 0x80134EE8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80134EEC: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x80134EF0: sb          $a3, 0x4A($t1)
    MEM_B(0X4A, ctx->r9) = ctx->r7;
    // 0x80134EF4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80134EF8: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x80134EFC: lw          $t5, 0x24($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X24);
    // 0x80134F00: ori         $t4, $t5, 0x400
    ctx->r12 = ctx->r13 | 0X400;
    // 0x80134F04: sw          $t4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r12;
    // 0x80134F08: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80134F0C: lbu         $t7, 0xF32($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XF32);
    // 0x80134F10: lw          $t9, 0x30($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X30);
    // 0x80134F14: sb          $t7, 0x4C($t9)
    MEM_B(0X4C, ctx->r25) = ctx->r15;
    // 0x80134F18: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80134F1C: lbu         $t6, 0xF33($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF33);
    // 0x80134F20: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x80134F24: sb          $t6, 0x4D($t1)
    MEM_B(0X4D, ctx->r9) = ctx->r14;
    // 0x80134F28: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80134F2C: lbu         $t2, 0xF34($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XF34);
    // 0x80134F30: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x80134F34: sb          $t2, 0x4E($t4)
    MEM_B(0X4E, ctx->r12) = ctx->r10;
    // 0x80134F38: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80134F3C: lbu         $t3, 0xF35($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XF35);
    // 0x80134F40: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x80134F44: sb          $t3, 0x4F($t9)
    MEM_B(0X4F, ctx->r25) = ctx->r11;
    // 0x80134F48: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x80134F4C: lw          $a2, 0x10($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X10);
    // 0x80134F50: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x80134F54: jal         0x8012C784
    // 0x80134F58: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_94;
    // 0x80134F58: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_94:
    // 0x80134F5C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134F60: addiu       $a1, $a1, 0x5678
    ctx->r5 = ADD32(ctx->r5, 0X5678);
    // 0x80134F64: jal         0x800058DC
    // 0x80134F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_95;
    // 0x80134F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_95:
    // 0x80134F6C: b           L_80135310
    // 0x80134F70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135310;
    // 0x80134F70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80134F74:
    // 0x80134F74: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80134F78: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x80134F7C: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80134F80: jal         0x80005F6C
    // 0x80134F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_96;
    // 0x80134F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_96:
    // 0x80134F88: jal         0x80006214
    // 0x80134F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_97;
    // 0x80134F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_97:
    // 0x80134F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134F94: jal         0x8012636C
    // 0x80134F98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_98;
    // 0x80134F98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_98:
    // 0x80134F9C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80134FA0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80134FA4: addiu       $t4, $t4, -0x5548
    ctx->r12 = ADD32(ctx->r12, -0X5548);
    // 0x80134FA8: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x80134FAC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80134FB0: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x80134FB4: lw          $t5, 0x24($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X24);
    // 0x80134FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134FBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134FC0: ori         $t2, $t5, 0x300
    ctx->r10 = ctx->r13 | 0X300;
    // 0x80134FC4: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x80134FC8: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80134FCC: lw          $t9, 0x30($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X30);
    // 0x80134FD0: sw          $t7, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r15;
    // 0x80134FD4: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x80134FD8: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80134FDC: lw          $t6, 0x10($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X10);
    // 0x80134FE0: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x80134FE4: srl         $t5, $t6, 8
    ctx->r13 = S32(U32(ctx->r14) >> 8);
    // 0x80134FE8: sb          $t5, 0x4B($t4)
    MEM_B(0X4B, ctx->r12) = ctx->r13;
    // 0x80134FEC: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80134FF0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80134FF4: lw          $t9, 0x10($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X10);
    // 0x80134FF8: lw          $t6, 0x30($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X30);
    // 0x80134FFC: sb          $t9, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r25;
    // 0x80135000: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x80135004: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80135008: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8013500C: lw          $t3, 0x30($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X30);
    // 0x80135010: srl         $t5, $t2, 24
    ctx->r13 = S32(U32(ctx->r10) >> 24);
    // 0x80135014: sb          $t5, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r13;
    // 0x80135018: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x8013501C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80135020: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80135024: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80135028: srl         $t6, $t8, 16
    ctx->r14 = S32(U32(ctx->r24) >> 16);
    // 0x8013502C: sb          $t6, 0x4A($t2)
    MEM_B(0X4A, ctx->r10) = ctx->r14;
    // 0x80135030: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x80135034: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80135038: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x8013503C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80135040: srl         $t7, $t5, 8
    ctx->r15 = S32(U32(ctx->r13) >> 8);
    // 0x80135044: sb          $t7, 0x4C($t9)
    MEM_B(0X4C, ctx->r25) = ctx->r15;
    // 0x80135048: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x8013504C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80135050: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80135054: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x80135058: sb          $t2, 0x4D($t5)
    MEM_B(0X4D, ctx->r13) = ctx->r10;
    // 0x8013505C: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80135060: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80135064: lw          $t8, 0x18($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X18);
    // 0x80135068: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x8013506C: srl         $t7, $t8, 24
    ctx->r15 = S32(U32(ctx->r24) >> 24);
    // 0x80135070: sb          $t7, 0x4E($t1)
    MEM_B(0X4E, ctx->r9) = ctx->r15;
    // 0x80135074: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x80135078: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x8013507C: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x80135080: jal         0x8012C784
    // 0x80135084: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_99;
    // 0x80135084: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_99:
    // 0x80135088: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013508C: addiu       $a1, $a1, 0x581C
    ctx->r5 = ADD32(ctx->r5, 0X581C);
    // 0x80135090: jal         0x800058DC
    // 0x80135094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_100;
    // 0x80135094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_100:
    // 0x80135098: b           L_80135310
    // 0x8013509C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135310;
    // 0x8013509C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801350A0:
    // 0x801350A0: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x801350A4: ori         $t4, $t4, 0x500
    ctx->r12 = ctx->r12 | 0X500;
    // 0x801350A8: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x801350AC: jal         0x80005F6C
    // 0x801350B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_101;
    // 0x801350B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_101:
    // 0x801350B4: jal         0x80006214
    // 0x801350B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_102;
    // 0x801350B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_102:
    // 0x801350BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801350C0: jal         0x8012636C
    // 0x801350C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_103;
    // 0x801350C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_103:
    // 0x801350C8: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801350CC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801350D0: addiu       $t8, $t8, -0x5548
    ctx->r24 = ADD32(ctx->r24, -0X5548);
    // 0x801350D4: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x801350D8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801350DC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x801350E0: lw          $t5, 0x24($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X24);
    // 0x801350E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801350E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801350EC: ori         $t3, $t5, 0x300
    ctx->r11 = ctx->r13 | 0X300;
    // 0x801350F0: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x801350F4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801350F8: lw          $t1, 0x30($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X30);
    // 0x801350FC: sw          $t9, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r25;
    // 0x80135100: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x80135104: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80135108: lw          $t4, 0x10($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X10);
    // 0x8013510C: lw          $t8, 0x30($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X30);
    // 0x80135110: srl         $t5, $t4, 8
    ctx->r13 = S32(U32(ctx->r12) >> 8);
    // 0x80135114: sb          $t5, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = ctx->r13;
    // 0x80135118: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x8013511C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80135120: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x80135124: lw          $t2, 0x30($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X30);
    // 0x80135128: srl         $t6, $t9, 16
    ctx->r14 = S32(U32(ctx->r25) >> 16);
    // 0x8013512C: sb          $t6, 0x48($t2)
    MEM_B(0X48, ctx->r10) = ctx->r14;
    // 0x80135130: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80135134: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80135138: lw          $t5, 0x14($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X14);
    // 0x8013513C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80135140: srl         $t7, $t5, 8
    ctx->r15 = S32(U32(ctx->r13) >> 8);
    // 0x80135144: sb          $t7, 0x49($t1)
    MEM_B(0X49, ctx->r9) = ctx->r15;
    // 0x80135148: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x8013514C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80135150: lw          $t2, 0x14($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X14);
    // 0x80135154: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x80135158: sb          $t2, 0x4A($t5)
    MEM_B(0X4A, ctx->r13) = ctx->r10;
    // 0x8013515C: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x80135160: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80135164: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x80135168: lw          $t4, 0x30($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X30);
    // 0x8013516C: srl         $t7, $t9, 24
    ctx->r15 = S32(U32(ctx->r25) >> 24);
    // 0x80135170: sb          $t7, 0x4C($t4)
    MEM_B(0X4C, ctx->r12) = ctx->r15;
    // 0x80135174: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x80135178: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8013517C: lw          $t3, 0x18($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X18);
    // 0x80135180: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80135184: srl         $t5, $t3, 16
    ctx->r13 = S32(U32(ctx->r11) >> 16);
    // 0x80135188: sb          $t5, 0x4D($t9)
    MEM_B(0X4D, ctx->r25) = ctx->r13;
    // 0x8013518C: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x80135190: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80135194: lw          $t7, 0x18($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X18);
    // 0x80135198: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x8013519C: srl         $t6, $t7, 8
    ctx->r14 = S32(U32(ctx->r15) >> 8);
    // 0x801351A0: sb          $t6, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = ctx->r14;
    // 0x801351A4: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x801351A8: lw          $a2, 0x10($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X10);
    // 0x801351AC: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x801351B0: jal         0x8012C784
    // 0x801351B4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_104;
    // 0x801351B4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_104:
    // 0x801351B8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801351BC: addiu       $a1, $a1, 0x5678
    ctx->r5 = ADD32(ctx->r5, 0X5678);
    // 0x801351C0: jal         0x800058DC
    // 0x801351C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_105;
    // 0x801351C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_105:
    // 0x801351C8: b           L_80135310
    // 0x801351CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135310;
    // 0x801351CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801351D0:
    // 0x801351D0: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x801351D4: ori         $t5, $t5, 0x600
    ctx->r13 = ctx->r13 | 0X600;
    // 0x801351D8: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x801351DC: jal         0x80005F6C
    // 0x801351E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_106;
    // 0x801351E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_106:
    // 0x801351E4: jal         0x80006214
    // 0x801351E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_107;
    // 0x801351E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_107:
    // 0x801351EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801351F0: jal         0x8012636C
    // 0x801351F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_108;
    // 0x801351F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_108:
    // 0x801351F8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801351FC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80135200: addiu       $t4, $t4, -0x5548
    ctx->r12 = ADD32(ctx->r12, -0X5548);
    // 0x80135204: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80135208: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8013520C: or          $t3, $t4, $at
    ctx->r11 = ctx->r12 | ctx->r1;
    // 0x80135210: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x80135214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013521C: ori         $t7, $t1, 0x300
    ctx->r15 = ctx->r9 | 0X300;
    // 0x80135220: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x80135224: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80135228: lw          $t2, 0x30($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X30);
    // 0x8013522C: sw          $t3, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r11;
    // 0x80135230: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x80135234: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80135238: lw          $t5, 0x10($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X10);
    // 0x8013523C: lw          $t4, 0x30($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X30);
    // 0x80135240: srl         $t1, $t5, 8
    ctx->r9 = S32(U32(ctx->r13) >> 8);
    // 0x80135244: sb          $t1, 0x4B($t4)
    MEM_B(0X4B, ctx->r12) = ctx->r9;
    // 0x80135248: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x8013524C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80135250: lw          $t2, 0x10($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X10);
    // 0x80135254: lw          $t5, 0x30($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X30);
    // 0x80135258: sb          $t2, 0x48($t5)
    MEM_B(0X48, ctx->r13) = ctx->r10;
    // 0x8013525C: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x80135260: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80135264: lw          $t7, 0x14($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X14);
    // 0x80135268: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x8013526C: srl         $t1, $t7, 24
    ctx->r9 = S32(U32(ctx->r15) >> 24);
    // 0x80135270: sb          $t1, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r9;
    // 0x80135274: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80135278: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8013527C: lw          $t8, 0x14($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X14);
    // 0x80135280: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x80135284: srl         $t5, $t8, 16
    ctx->r13 = S32(U32(ctx->r24) >> 16);
    // 0x80135288: sb          $t5, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r13;
    // 0x8013528C: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x80135290: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80135294: lw          $t1, 0x14($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X14);
    // 0x80135298: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x8013529C: srl         $t3, $t1, 8
    ctx->r11 = S32(U32(ctx->r9) >> 8);
    // 0x801352A0: sb          $t3, 0x4C($t2)
    MEM_B(0X4C, ctx->r10) = ctx->r11;
    // 0x801352A4: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x801352A8: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801352AC: lw          $t7, 0x14($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X14);
    // 0x801352B0: lw          $t1, 0x30($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X30);
    // 0x801352B4: sb          $t7, 0x4D($t1)
    MEM_B(0X4D, ctx->r9) = ctx->r15;
    // 0x801352B8: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x801352BC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801352C0: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x801352C4: lw          $t9, 0x30($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X30);
    // 0x801352C8: srl         $t3, $t8, 24
    ctx->r11 = S32(U32(ctx->r24) >> 24);
    // 0x801352CC: sb          $t3, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = ctx->r11;
    // 0x801352D0: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x801352D4: lw          $a2, 0x10($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X10);
    // 0x801352D8: srl         $a2, $a2, 16
    ctx->r6 = S32(U32(ctx->r6) >> 16);
    // 0x801352DC: jal         0x8012C784
    // 0x801352E0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_109;
    // 0x801352E0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_109:
    // 0x801352E4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801352E8: addiu       $a1, $a1, 0x58FC
    ctx->r5 = ADD32(ctx->r5, 0X58FC);
    // 0x801352EC: jal         0x800058DC
    // 0x801352F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_110;
    // 0x801352F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_110:
    // 0x801352F4: b           L_80135310
    // 0x801352F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135310;
    // 0x801352F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801352FC:
    // 0x801352FC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135300: addiu       $a1, $a1, 0x5320
    ctx->r5 = ADD32(ctx->r5, 0X5320);
    // 0x80135304: jal         0x800058DC
    // 0x80135308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_111;
    // 0x80135308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_111:
    // 0x8013530C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80135310:
    // 0x80135310: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80135314: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80135318: jr          $ra
    // 0x8013531C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8013531C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80135320(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80135320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135320: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80135324: jr          $ra
    // 0x80135328: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80135328: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8013532c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8013532c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013532C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80135330: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80135334: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80135338: lbu         $t6, 0xF32($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF32);
    // 0x8013533C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80135340: sb          $t6, 0x4C($t8)
    MEM_B(0X4C, ctx->r24) = ctx->r14;
    // 0x80135344: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80135348: lbu         $t9, 0xF33($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF33);
    // 0x8013534C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80135350: sb          $t9, 0x4D($t1)
    MEM_B(0X4D, ctx->r9) = ctx->r25;
    // 0x80135354: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80135358: lbu         $t2, 0xF34($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XF34);
    // 0x8013535C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80135360: sb          $t2, 0x4E($t4)
    MEM_B(0X4E, ctx->r12) = ctx->r10;
    // 0x80135364: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80135368: lbu         $t5, 0xF35($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XF35);
    // 0x8013536C: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x80135370: sb          $t5, 0x4F($t6)
    MEM_B(0X4F, ctx->r14) = ctx->r13;
    // 0x80135374: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80135378: lw          $t9, 0x90($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X90);
    // 0x8013537C: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80135380: lh          $t0, 0x10($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X10);
    // 0x80135384: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x80135388: sh          $t1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r9;
    // 0x8013538C: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x80135390: lw          $t4, 0x94($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X94);
    // 0x80135394: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80135398: lh          $t2, 0x12($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X12);
    // 0x8013539C: addu        $t7, $t2, $t4
    ctx->r15 = ADD32(ctx->r10, ctx->r12);
    // 0x801353A0: sh          $t7, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r15;
    // 0x801353A4: lw          $t5, 0x24($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X24);
    // 0x801353A8: lw          $t8, 0x98($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X98);
    // 0x801353AC: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x801353B0: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x801353B4: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x801353B8: jr          $ra
    // 0x801353BC: sh          $t0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r8;
    return;
    // 0x801353BC: sh          $t0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r8;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801353c0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801353c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801353C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801353C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801353C8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x801353CC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801353D0: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x801353D4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x801353D8: jal         0x80010550
    // 0x801353DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_0;
    // 0x801353DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x801353E0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801353E4: lw          $t6, 0x38($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X38);
    // 0x801353E8: lw          $t9, 0x24($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X24);
    // 0x801353EC: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801353F0: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801353F4: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x801353F8: sh          $t8, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r24;
    // 0x801353FC: lw          $t4, 0x24($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X24);
    // 0x80135400: lw          $t1, 0x38($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X38);
    // 0x80135404: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x80135408: lw          $t3, 0x14($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X14);
    // 0x8013540C: sh          $t3, 0x14($t5)
    MEM_H(0X14, ctx->r13) = ctx->r11;
    // 0x80135410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80135418: jr          $ra
    // 0x8013541C: nop

    return;
    // 0x8013541C: nop

;}
RECOMP_FUNC void M7_FUN_80135420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135420: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80135424: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x80135428: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013542C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80135430: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80135434: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x80135438: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x8013543C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80135440: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80135444: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80135448: lh          $t2, 0x11E($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X11E);
    // 0x8013544C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80135450: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80135454: nop

    // 0x80135458: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013545C: swc1        $f6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f6.u32l;
    // 0x80135460: lw          $t5, 0x38($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X38);
    // 0x80135464: lw          $t2, 0x24($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X24);
    // 0x80135468: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x8013546C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80135470: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x80135474: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80135478: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8013547C: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80135480: lh          $t1, 0x130($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X130);
    // 0x80135484: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80135488: nop

    // 0x8013548C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80135490: swc1        $f10, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f10.u32l;
    // 0x80135494: lw          $t4, 0x38($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X38);
    // 0x80135498: lw          $t1, 0x24($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X24);
    // 0x8013549C: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x801354A0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801354A4: srl         $t6, $t5, 16
    ctx->r14 = S32(U32(ctx->r13) >> 16);
    // 0x801354A8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801354AC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x801354B0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x801354B4: lh          $t0, 0x142($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X142);
    // 0x801354B8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x801354BC: nop

    // 0x801354C0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801354C4: jr          $ra
    // 0x801354C8: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    return;
    // 0x801354C8: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801354cc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801354cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801354CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801354D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801354D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801354D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801354DC: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801354E0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801354E4: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    // 0x801354E8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x801354EC: jal         0x80133A24
    // 0x801354F0: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801354F0: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_0:
    // 0x801354F4: beq         $v0, $zero, L_8013550C
    if (ctx->r2 == 0) {
        // 0x801354F8: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8013550C;
    }
    // 0x801354F8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801354FC: lw          $t7, 0x2C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X2C);
    // 0x80135500: ori         $t8, $t7, 0x800
    ctx->r24 = ctx->r15 | 0X800;
    // 0x80135504: b           L_80135510
    // 0x80135508: sw          $t8, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r24;
        goto L_80135510;
    // 0x80135508: sw          $t8, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r24;
L_8013550C:
    // 0x8013550C: sw          $zero, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = 0;
L_80135510:
    // 0x80135510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80135518: jr          $ra
    // 0x8013551C: nop

    return;
    // 0x8013551C: nop

;}
RECOMP_FUNC void M7_FUN_80135520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135520: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80135524: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135528: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013552C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80135530: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x80135534: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80135538: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x8013553C: addiu       $t9, $t8, -0x4
    ctx->r25 = ADD32(ctx->r24, -0X4);
    // 0x80135540: jal         0x80126944
    // 0x80135544: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x80135544: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    after_0:
    // 0x80135548: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013554C: bnel        $v0, $at, L_80135570
    if (ctx->r2 != ctx->r1) {
        // 0x80135550: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80135570;
    }
    goto skip_0;
    // 0x80135550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80135554: jal         0x80020718
    // 0x80135558: addiu       $a0, $zero, 0x6B4
    ctx->r4 = ADD32(0, 0X6B4);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_1;
    // 0x80135558: addiu       $a0, $zero, 0x6B4
    ctx->r4 = ADD32(0, 0X6B4);
    after_1:
    // 0x8013555C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135560: addiu       $a1, $a1, 0x557C
    ctx->r5 = ADD32(ctx->r5, 0X557C);
    // 0x80135564: jal         0x800058DC
    // 0x80135568: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80135568: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8013556C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80135570:
    // 0x80135570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80135574: jr          $ra
    // 0x80135578: nop

    return;
    // 0x80135578: nop

;}
RECOMP_FUNC void M7_FUN_8013557c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013557C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80135580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135584: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80135588: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8013558C: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x80135590: lw          $v0, 0x30($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X30);
    // 0x80135594: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x80135598: addiu       $t9, $t8, -0x4
    ctx->r25 = ADD32(ctx->r24, -0X4);
    // 0x8013559C: jal         0x80126944
    // 0x801355A0: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x801355A0: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    after_0:
    // 0x801355A4: bne         $v0, $zero, L_801355C8
    if (ctx->r2 != 0) {
        // 0x801355A8: addiu       $a0, $zero, 0x1F9
        ctx->r4 = ADD32(0, 0X1F9);
            goto L_801355C8;
    }
    // 0x801355A8: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    // 0x801355AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801355B0: jal         0x801FC720
    // 0x801355B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x801FC720)(rdram, ctx);
        goto after_1;
    // 0x801355B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801355B8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801355BC: addiu       $a1, $a1, 0x5520
    ctx->r5 = ADD32(ctx->r5, 0X5520);
    // 0x801355C0: jal         0x800058DC
    // 0x801355C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801355C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_801355C8:
    // 0x801355C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801355CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801355D0: jr          $ra
    // 0x801355D4: nop

    return;
    // 0x801355D4: nop

;}
RECOMP_FUNC void M7_FUN_801355d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801355D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801355DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801355E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801355E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801355E8: jal         0x80126944
    // 0x801355EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x801355EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801355F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801355F4: bne         $v0, $at, L_8013560C
    if (ctx->r2 != ctx->r1) {
        // 0x801355F8: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_8013560C;
    }
    // 0x801355F8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801355FC: lbu         $t6, -0x33DF($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X33DF);
    // 0x80135600: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80135604: beql        $t6, $at, L_80135624
    if (ctx->r14 == ctx->r1) {
        // 0x80135608: lw          $t7, 0x38($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X38);
            goto L_80135624;
    }
    goto skip_0;
    // 0x80135608: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    skip_0:
L_8013560C:
    // 0x8013560C: jal         0x80126944
    // 0x80135610: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_1;
    // 0x80135610: nop

    after_1:
    // 0x80135614: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80135618: beql        $v0, $at, L_80135648
    if (ctx->r2 == ctx->r1) {
        // 0x8013561C: lw          $t8, 0x38($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X38);
            goto L_80135648;
    }
    goto skip_1;
    // 0x8013561C: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    skip_1:
    // 0x80135620: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
L_80135624:
    // 0x80135624: lhu         $a0, 0x36($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X36);
    // 0x80135628: lw          $a1, 0x14($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X14);
    // 0x8013562C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80135630: srl         $a1, $a1, 16
    ctx->r5 = S32(U32(ctx->r5) >> 16);
    // 0x80135634: jal         0x8012C97C
    // 0x80135638: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_2;
    // 0x80135638: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_2:
    // 0x8013563C: b           L_80135664
    // 0x80135640: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
        goto L_80135664;
    // 0x80135640: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x80135644: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
L_80135648:
    // 0x80135648: lhu         $a0, 0x36($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X36);
    // 0x8013564C: lw          $a1, 0x14($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X14);
    // 0x80135650: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80135654: srl         $a1, $a1, 8
    ctx->r5 = S32(U32(ctx->r5) >> 8);
    // 0x80135658: jal         0x8012C97C
    // 0x8013565C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x8012C97C)(rdram, ctx);
        goto after_3;
    // 0x8013565C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_3:
    // 0x80135660: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
L_80135664:
    // 0x80135664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80135668: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013566C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80135670: jr          $ra
    // 0x80135674: nop

    return;
    // 0x80135674: nop

;}
RECOMP_FUNC void M7_FUN_80135678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135678: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x8013567C: lh          $t6, 0x5C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X5C);
    // 0x80135680: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80135684: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80135688: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8013568C: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x80135690: srl         $v0, $v0, 24
    ctx->r2 = S32(U32(ctx->r2) >> 24);
    // 0x80135694: cvt.d.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.d = CVT_D_W(ctx->f18.u32l);
    // 0x80135698: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8013569C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x801356A0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801356A4: mtc1        $v0, $f14
    ctx->f14.u32l = ctx->r2;
    // 0x801356A8: add.d       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f18.d + ctx->f12.d;
    // 0x801356AC: srl         $a2, $t0, 8
    ctx->r6 = S32(U32(ctx->r8) >> 8);
    // 0x801356B0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801356B4: cvt.d.w     $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.d = CVT_D_W(ctx->f14.u32l);
    // 0x801356B8: bgez        $v0, L_801356D4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801356BC: andi        $t0, $t0, 0xFF
        ctx->r8 = ctx->r8 & 0XFF;
            goto L_801356D4;
    }
    // 0x801356BC: andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // 0x801356C0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801356C4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801356C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801356CC: nop

    // 0x801356D0: add.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f16.d + ctx->f18.d;
L_801356D4:
    // 0x801356D4: add.d       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f16.d + ctx->f12.d;
    // 0x801356D8: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x801356DC: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x801356E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801356E4: div.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f4.d);
    // 0x801356E8: addiu       $v1, $a0, 0x5C
    ctx->r3 = ADD32(ctx->r4, 0X5C);
    // 0x801356EC: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801356F0: bgez        $a2, L_80135704
    if (SIGNED(ctx->r6) >= 0) {
        // 0x801356F4: cvt.s.d     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
            goto L_80135704;
    }
    // 0x801356F4: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x801356F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801356FC: nop

    // 0x80135700: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_80135704:
    // 0x80135704: bgez        $t0, L_8013571C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80135708: cvt.s.w     $f8, $f16
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8013571C;
    }
    // 0x80135708: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8013570C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80135710: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135714: nop

    // 0x80135718: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_8013571C:
    // 0x8013571C: sub.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80135720: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80135724: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80135728: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8013572C: add.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80135730: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80135734: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80135738: nop

    // 0x8013573C: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80135740: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80135744: nop

    // 0x80135748: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8013574C: beql        $t8, $zero, L_8013579C
    if (ctx->r24 == 0) {
        // 0x80135750: mfc1        $t8, $f16
        ctx->r24 = (int32_t)ctx->f16.u32l;
            goto L_8013579C;
    }
    goto skip_0;
    // 0x80135750: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x80135754: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80135758: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8013575C: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80135760: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80135764: nop

    // 0x80135768: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8013576C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80135770: nop

    // 0x80135774: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80135778: bne         $t8, $zero, L_80135790
    if (ctx->r24 != 0) {
        // 0x8013577C: nop
    
            goto L_80135790;
    }
    // 0x8013577C: nop

    // 0x80135780: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80135784: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80135788: b           L_801357A8
    // 0x8013578C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_801357A8;
    // 0x8013578C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80135790:
    // 0x80135790: b           L_801357A8
    // 0x80135794: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_801357A8;
    // 0x80135794: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80135798: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
L_8013579C:
    // 0x8013579C: nop

    // 0x801357A0: bltz        $t8, L_80135790
    if (SIGNED(ctx->r24) < 0) {
        // 0x801357A4: nop
    
            goto L_80135790;
    }
    // 0x801357A4: nop

L_801357A8:
    // 0x801357A8: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801357AC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801357B0: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801357B4: sb          $t8, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r24;
    // 0x801357B8: lhu         $t2, 0x5E($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X5E);
    // 0x801357BC: bnel        $t2, $zero, L_801357F8
    if (ctx->r10 != 0) {
        // 0x801357C0: lh          $t7, 0x0($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X0);
            goto L_801357F8;
    }
    goto skip_1;
    // 0x801357C0: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    skip_1:
    // 0x801357C4: addiu       $v1, $a0, 0x5C
    ctx->r3 = ADD32(ctx->r4, 0X5C);
    // 0x801357C8: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x801357CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801357D0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801357D4: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x801357D8: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x801357DC: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801357E0: bne         $at, $zero, L_80135814
    if (ctx->r1 != 0) {
        // 0x801357E4: nop
    
            goto L_80135814;
    }
    // 0x801357E4: nop

    // 0x801357E8: sh          $t6, 0x5E($a0)
    MEM_H(0X5E, ctx->r4) = ctx->r14;
    // 0x801357EC: jr          $ra
    // 0x801357F0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    return;
    // 0x801357F0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x801357F4: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
L_801357F8:
    // 0x801357F8: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x801357FC: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x80135800: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80135804: bgtz        $t8, L_80135814
    if (SIGNED(ctx->r24) > 0) {
        // 0x80135808: nop
    
            goto L_80135814;
    }
    // 0x80135808: nop

    // 0x8013580C: sh          $zero, 0x5E($a0)
    MEM_H(0X5E, ctx->r4) = 0;
    // 0x80135810: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_80135814:
    // 0x80135814: jr          $ra
    // 0x80135818: nop

    return;
    // 0x80135818: nop

;}
RECOMP_FUNC void M7_FUN_8013581c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013581C: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80135820: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80135824: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x80135828: lw          $a2, 0x18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X18);
    // 0x8013582C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80135830: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80135834: srl         $v0, $a2, 16
    ctx->r2 = S32(U32(ctx->r6) >> 16);
    // 0x80135838: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x8013583C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80135840: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80135844: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80135848: bgez        $t6, L_8013585C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8013584C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8013585C;
    }
    // 0x8013584C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80135850: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135854: nop

    // 0x80135858: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_8013585C:
    // 0x8013585C: lh          $t7, 0x5C($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X5C);
    // 0x80135860: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80135864: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80135868: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8013586C: nop

    // 0x80135870: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80135874: bgez        $v0, L_8013588C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80135878: add.d       $f16, $f10, $f14
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f16.d = ctx->f10.d + ctx->f14.d;
            goto L_8013588C;
    }
    // 0x80135878: add.d       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f16.d = ctx->f10.d + ctx->f14.d;
    // 0x8013587C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80135880: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80135884: nop

    // 0x80135888: add.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f4.d + ctx->f6.d;
L_8013588C:
    // 0x8013588C: lh          $t8, 0x8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X8);
    // 0x80135890: add.d       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f4.d + ctx->f14.d;
    // 0x80135894: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80135898: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8013589C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801358A0: div.d       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f8.d);
    // 0x801358A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801358A8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x801358AC: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801358B0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801358B4: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x801358B8: div.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f16.d);
    // 0x801358BC: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x801358C0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x801358C4: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x801358C8: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x801358CC: add.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x801358D0: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x801358D4: lh          $t1, 0x5C($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X5C);
    // 0x801358D8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801358DC: sh          $t2, 0x5C($a0)
    MEM_H(0X5C, ctx->r4) = ctx->r10;
    // 0x801358E0: lh          $t3, 0x5C($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X5C);
    // 0x801358E4: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801358E8: bne         $at, $zero, L_801358F4
    if (ctx->r1 != 0) {
        // 0x801358EC: nop
    
            goto L_801358F4;
    }
    // 0x801358EC: nop

    // 0x801358F0: sh          $zero, 0x5C($a0)
    MEM_H(0X5C, ctx->r4) = 0;
L_801358F4:
    // 0x801358F4: jr          $ra
    // 0x801358F8: nop

    return;
    // 0x801358F8: nop

;}
RECOMP_FUNC void M7_FUN_801358fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801358FC: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x80135900: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x80135904: lw          $v0, 0x18($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X18);
    // 0x80135908: srl         $v0, $v0, 16
    ctx->r2 = S32(U32(ctx->r2) >> 16);
    // 0x8013590C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80135910: beq         $v0, $zero, L_8013596C
    if (ctx->r2 == 0) {
        // 0x80135914: nop
    
            goto L_8013596C;
    }
    // 0x80135914: nop

    // 0x80135918: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x8013591C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80135920: mflo        $t0
    ctx->r8 = lo;
    // 0x80135924: lw          $v1, 0x30($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X30);
    // 0x80135928: lh          $t8, 0x12($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X12);
    // 0x8013592C: bne         $v0, $zero, L_80135938
    if (ctx->r2 != 0) {
        // 0x80135930: nop
    
            goto L_80135938;
    }
    // 0x80135930: nop

    // 0x80135934: break       7
    do_break(2148751668);
L_80135938:
    // 0x80135938: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8013593C: bne         $v0, $at, L_80135950
    if (ctx->r2 != ctx->r1) {
        // 0x80135940: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80135950;
    }
    // 0x80135940: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80135944: bne         $t9, $at, L_80135950
    if (ctx->r25 != ctx->r1) {
        // 0x80135948: nop
    
            goto L_80135950;
    }
    // 0x80135948: nop

    // 0x8013594C: break       6
    do_break(2148751692);
L_80135950:
    // 0x80135950: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80135954: sh          $t1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r9;
    // 0x80135958: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8013595C: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x80135960: lh          $t3, 0x12($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X12);
    // 0x80135964: andi        $t4, $t3, 0x1FFF
    ctx->r12 = ctx->r11 & 0X1FFF;
    // 0x80135968: sh          $t4, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r12;
L_8013596C:
    // 0x8013596C: jr          $ra
    // 0x80135970: nop

    return;
    // 0x80135970: nop

;}
RECOMP_FUNC void M7_FUN_80135974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135974: nop

    // 0x80135978: nop

    // 0x8013597C: nop

;}
RECOMP_FUNC void M7_FUN_80135980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80135984: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80135988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013598C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80135990: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80135994: jal         0x80126CC0
    // 0x80135998: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    LOOKUP_FUNC(0x80126CC0)(rdram, ctx);
        goto after_0;
    // 0x80135998: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    after_0:
    // 0x8013599C: beq         $v0, $zero, L_801359B0
    if (ctx->r2 == 0) {
        // 0x801359A0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801359B0;
    }
    // 0x801359A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801359A4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801359A8: jal         0x800058DC
    // 0x801359AC: addiu       $a1, $a1, 0x59C0
    ctx->r5 = ADD32(ctx->r5, 0X59C0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801359AC: addiu       $a1, $a1, 0x59C0
    ctx->r5 = ADD32(ctx->r5, 0X59C0);
    after_1:
L_801359B0:
    // 0x801359B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801359B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801359B8: jr          $ra
    // 0x801359BC: nop

    return;
    // 0x801359BC: nop

;}
RECOMP_FUNC void M7_FUN_801359c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801359C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801359C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801359C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801359CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801359D0: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x801359D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801359D8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801359DC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x801359E0: srl         $t8, $t7, 24
    ctx->r24 = S32(U32(ctx->r15) >> 24);
    // 0x801359E4: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x801359E8: beq         $at, $zero, L_80135DB4
    if (ctx->r1 == 0) {
        // 0x801359EC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80135DB4;
    }
    // 0x801359EC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801359F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801359F4: addu        $at, $at, $t8
    gpr jr_addend_801359FC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801359F8: lw          $t8, -0x24AC($at)
    ctx->r24 = ADD32(ctx->r1, -0X24AC);
    // 0x801359FC: jr          $t8
    // 0x80135A00: nop

    switch (jr_addend_801359FC >> 2) {
        case 0: goto L_80135A04; break;
        case 1: goto L_80135AF4; break;
        case 2: goto L_80135C20; break;
        case 3: goto L_80135C88; break;
        case 4: goto L_80135AD0; break;
        default: switch_error(__func__, 0x801359FC, 0x8018DB54);
    }
    // 0x80135A00: nop

L_80135A04:
    // 0x80135A04: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80135A08: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x80135A0C: jal         0x80005F6C
    // 0x80135A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_0;
    // 0x80135A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80135A14: jal         0x80006214
    // 0x80135A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80135A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80135A1C: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x80135A20: addiu       $t9, $zero, 0x73
    ctx->r25 = ADD32(0, 0X73);
    // 0x80135A24: lui         $t2, 0x300
    ctx->r10 = S32(0X300 << 16);
    // 0x80135A28: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80135A2C: addiu       $t2, $t2, 0x210
    ctx->r10 = ADD32(ctx->r10, 0X210);
    // 0x80135A30: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80135A34: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    // 0x80135A38: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x80135A3C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80135A40: sw          $t2, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r10;
    // 0x80135A44: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x80135A48: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x80135A4C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80135A50: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80135A54: sh          $t7, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r15;
    // 0x80135A58: bgez        $t8, L_80135A6C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80135A5C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80135A6C;
    }
    // 0x80135A5C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80135A60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135A64: nop

    // 0x80135A68: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80135A6C:
    // 0x80135A6C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80135A70: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80135A74: addiu       $t5, $t5, -0x5168
    ctx->r13 = ADD32(ctx->r13, -0X5168);
    // 0x80135A78: lw          $t9, 0x30($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X30);
    // 0x80135A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135A80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135A84: swc1        $f0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f0.u32l;
    // 0x80135A88: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80135A8C: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x80135A90: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
    // 0x80135A94: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80135A98: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x80135A9C: swc1        $f0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f0.u32l;
    // 0x80135AA0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80135AA4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80135AA8: jal         0x8012636C
    // 0x80135AAC: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_2;
    // 0x80135AAC: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    after_2:
    // 0x80135AB0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80135AB4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135AB8: addiu       $a1, $a1, 0x5DE4
    ctx->r5 = ADD32(ctx->r5, 0X5DE4);
    // 0x80135ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135AC0: jal         0x800058DC
    // 0x80135AC4: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80135AC4: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
    after_3:
    // 0x80135AC8: b           L_80135DC8
    // 0x80135ACC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80135DC8;
    // 0x80135ACC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80135AD0:
    // 0x80135AD0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80135AD4: addiu       $t0, $t0, 0x6DC4
    ctx->r8 = ADD32(ctx->r8, 0X6DC4);
    // 0x80135AD8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135ADC: sw          $t0, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r8;
    // 0x80135AE0: addiu       $a1, $a1, 0x6CA8
    ctx->r5 = ADD32(ctx->r5, 0X6CA8);
    // 0x80135AE4: jal         0x800058DC
    // 0x80135AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80135AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80135AEC: b           L_80135DC8
    // 0x80135AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80135DC8;
    // 0x80135AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80135AF4:
    // 0x80135AF4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80135AF8: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x80135AFC: jal         0x80005F6C
    // 0x80135B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_5;
    // 0x80135B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80135B04: jal         0x80006214
    // 0x80135B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_6;
    // 0x80135B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80135B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135B14: jal         0x8012C784
    // 0x80135B18: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_7;
    // 0x80135B18: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_7:
    // 0x80135B1C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80135B20: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x80135B24: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x80135B28: sw          $t9, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r25;
    // 0x80135B2C: jal         0x8000C3B0
    // 0x80135B30: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_8;
    // 0x80135B30: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_8:
    // 0x80135B34: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80135B38: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80135B3C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80135B40: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x80135B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135B48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135B4C: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
    // 0x80135B50: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80135B54: lbu         $t6, 0xF32($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF32);
    // 0x80135B58: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80135B5C: sb          $t6, 0x4C($t7)
    MEM_B(0X4C, ctx->r15) = ctx->r14;
    // 0x80135B60: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80135B64: lbu         $t8, 0xF33($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF33);
    // 0x80135B68: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80135B6C: sb          $t8, 0x4D($t1)
    MEM_B(0X4D, ctx->r9) = ctx->r24;
    // 0x80135B70: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80135B74: lbu         $t9, 0xF34($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF34);
    // 0x80135B78: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x80135B7C: sb          $t9, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = ctx->r25;
    // 0x80135B80: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80135B84: lbu         $t4, 0xF35($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF35);
    // 0x80135B88: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80135B8C: jal         0x8012636C
    // 0x80135B90: sb          $t4, 0x4F($t6)
    MEM_B(0X4F, ctx->r14) = ctx->r12;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_9;
    // 0x80135B90: sb          $t4, 0x4F($t6)
    MEM_B(0X4F, ctx->r14) = ctx->r12;
    after_9:
    // 0x80135B94: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80135B98: lhu         $t8, 0x36($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X36);
    // 0x80135B9C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80135BA0: ori         $t0, $t7, 0xC00
    ctx->r8 = ctx->r15 | 0XC00;
    // 0x80135BA4: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80135BA8: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
    // 0x80135BAC: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80135BB0: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x80135BB4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80135BB8: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80135BBC: lhu         $a0, 0x0($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X0);
    // 0x80135BC0: jal         0x8000522C
    // 0x80135BC4: lw          $a1, 0xC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_10;
    // 0x80135BC4: lw          $a1, 0xC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC);
    after_10:
    // 0x80135BC8: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x80135BCC: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x80135BD0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135BD4: lw          $t2, 0x30($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X30);
    // 0x80135BD8: addiu       $a1, $a1, 0x6000
    ctx->r5 = ADD32(ctx->r5, 0X6000);
    // 0x80135BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135BE0: lwc1        $f8, 0x4($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80135BE4: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
    // 0x80135BE8: lw          $t5, 0x30($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X30);
    // 0x80135BEC: lwc1        $f10, 0x8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80135BF0: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    // 0x80135BF4: lw          $t4, 0x30($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X30);
    // 0x80135BF8: lwc1        $f16, 0xC($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80135BFC: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
    // 0x80135C00: swc1        $f16, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f16.u32l;
    // 0x80135C04: lw          $t6, 0x30($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X30);
    // 0x80135C08: lh          $t7, 0x12($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X12);
    // 0x80135C0C: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80135C10: jal         0x800058DC
    // 0x80135C14: sh          $t7, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x80135C14: sh          $t7, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r15;
    after_11:
    // 0x80135C18: b           L_80135DC8
    // 0x80135C1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80135DC8;
    // 0x80135C1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80135C20:
    // 0x80135C20: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80135C24: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x80135C28: jal         0x80005F6C
    // 0x80135C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_12;
    // 0x80135C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80135C30: jal         0x80006214
    // 0x80135C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_13;
    // 0x80135C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80135C38: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80135C3C: addiu       $t0, $zero, 0x73
    ctx->r8 = ADD32(0, 0X73);
    // 0x80135C40: lui         $t3, 0x300
    ctx->r11 = S32(0X300 << 16);
    // 0x80135C44: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x80135C48: addiu       $t3, $t3, 0x210
    ctx->r11 = ADD32(ctx->r11, 0X210);
    // 0x80135C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135C50: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x80135C54: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80135C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135C5C: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x80135C60: jal         0x8012636C
    // 0x80135C64: sw          $t3, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->r11;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_14;
    // 0x80135C64: sw          $t3, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->r11;
    after_14:
    // 0x80135C68: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80135C6C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135C70: addiu       $a1, $a1, 0x69B8
    ctx->r5 = ADD32(ctx->r5, 0X69B8);
    // 0x80135C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135C78: jal         0x800058DC
    // 0x80135C7C: sb          $zero, 0x22($t5)
    MEM_B(0X22, ctx->r13) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_15;
    // 0x80135C7C: sb          $zero, 0x22($t5)
    MEM_B(0X22, ctx->r13) = 0;
    after_15:
    // 0x80135C80: b           L_80135DC8
    // 0x80135C84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80135DC8;
    // 0x80135C84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80135C88:
    // 0x80135C88: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80135C8C: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x80135C90: jal         0x80005F6C
    // 0x80135C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005F6C)(rdram, ctx);
        goto after_16;
    // 0x80135C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80135C98: jal         0x80006214
    // 0x80135C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_17;
    // 0x80135C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80135CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135CA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135CA8: jal         0x8012C784
    // 0x80135CAC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_18;
    // 0x80135CAC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_18:
    // 0x80135CB0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80135CB4: addiu       $t4, $zero, 0x13
    ctx->r12 = ADD32(0, 0X13);
    // 0x80135CB8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80135CBC: sw          $t4, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r12;
    // 0x80135CC0: jal         0x8000C3B0
    // 0x80135CC4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_19;
    // 0x80135CC4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_19:
    // 0x80135CC8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80135CCC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80135CD0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80135CD4: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x80135CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135CDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135CE0: sw          $v0, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r2;
    // 0x80135CE4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80135CE8: lbu         $t1, 0xF32($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XF32);
    // 0x80135CEC: lw          $t3, 0x30($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X30);
    // 0x80135CF0: sb          $t1, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = ctx->r9;
    // 0x80135CF4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80135CF8: lbu         $t2, 0xF33($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XF33);
    // 0x80135CFC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80135D00: sb          $t2, 0x4D($t6)
    MEM_B(0X4D, ctx->r14) = ctx->r10;
    // 0x80135D04: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80135D08: lbu         $t4, 0xF34($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF34);
    // 0x80135D0C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80135D10: sb          $t4, 0x4E($t8)
    MEM_B(0X4E, ctx->r24) = ctx->r12;
    // 0x80135D14: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80135D18: lbu         $t0, 0xF35($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0XF35);
    // 0x80135D1C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80135D20: jal         0x8012636C
    // 0x80135D24: sb          $t0, 0x4F($t1)
    MEM_B(0X4F, ctx->r9) = ctx->r8;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_20;
    // 0x80135D24: sb          $t0, 0x4F($t1)
    MEM_B(0X4F, ctx->r9) = ctx->r8;
    after_20:
    // 0x80135D28: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x80135D2C: lhu         $t2, 0x36($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X36);
    // 0x80135D30: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80135D34: ori         $t5, $t3, 0xC00
    ctx->r13 = ctx->r11 | 0XC00;
    // 0x80135D38: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x80135D3C: sw          $t5, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r13;
    // 0x80135D40: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80135D44: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x80135D48: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80135D4C: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80135D50: lhu         $a0, 0x0($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X0);
    // 0x80135D54: jal         0x8000522C
    // 0x80135D58: lw          $a1, 0xC($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XC);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_21;
    // 0x80135D58: lw          $a1, 0xC($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XC);
    after_21:
    // 0x80135D5C: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x80135D60: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x80135D64: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135D68: lw          $t8, 0x30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30);
    // 0x80135D6C: addiu       $a1, $a1, 0x64F4
    ctx->r5 = ADD32(ctx->r5, 0X64F4);
    // 0x80135D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135D74: lwc1        $f18, 0x4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80135D78: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x80135D7C: lw          $t9, 0x30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X30);
    // 0x80135D80: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80135D84: swc1        $f4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f4.u32l;
    // 0x80135D88: lw          $t0, 0x30($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X30);
    // 0x80135D8C: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80135D90: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
    // 0x80135D94: swc1        $f6, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f6.u32l;
    // 0x80135D98: lw          $t1, 0x30($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X30);
    // 0x80135D9C: lh          $t3, 0x12($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X12);
    // 0x80135DA0: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80135DA4: jal         0x800058DC
    // 0x80135DA8: sh          $t3, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r11;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_22;
    // 0x80135DA8: sh          $t3, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r11;
    after_22:
    // 0x80135DAC: b           L_80135DC8
    // 0x80135DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80135DC8;
    // 0x80135DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80135DB4:
    // 0x80135DB4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135DB8: addiu       $a1, $a1, 0x5DD8
    ctx->r5 = ADD32(ctx->r5, 0X5DD8);
    // 0x80135DBC: jal         0x800058DC
    // 0x80135DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_23;
    // 0x80135DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80135DC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80135DC8:
    // 0x80135DC8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80135DCC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80135DD0: jr          $ra
    // 0x80135DD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80135DD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80135dd8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80135dd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135DD8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80135DDC: jr          $ra
    // 0x80135DE0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80135DE0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80135de4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80135de4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135DE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80135DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135DEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80135DF0: lhu         $t6, 0x90($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X90);
    // 0x80135DF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80135DF8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80135DFC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80135E00: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80135E04: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80135E08: nop

    // 0x80135E0C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80135E10: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80135E14: jal         0x8012A630
    // 0x80135E18: nop

    LOOKUP_FUNC(0x8012A630)(rdram, ctx);
        goto after_0;
    // 0x80135E18: nop

    after_0:
    // 0x80135E1C: beq         $v0, $zero, L_80135E44
    if (ctx->r2 == 0) {
        // 0x80135E20: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_80135E44;
    }
    // 0x80135E20: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80135E24: lw          $t9, 0x38($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X38);
    // 0x80135E28: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    // 0x80135E2C: jal         0x80133980
    // 0x80135E30: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_1;
    // 0x80135E30: srl         $a0, $a0, 16
    ctx->r4 = S32(U32(ctx->r4) >> 16);
    after_1:
    // 0x80135E34: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135E38: addiu       $a1, $a1, 0x5E54
    ctx->r5 = ADD32(ctx->r5, 0X5E54);
    // 0x80135E3C: jal         0x800058DC
    // 0x80135E40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80135E40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80135E44:
    // 0x80135E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135E48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80135E4C: jr          $ra
    // 0x80135E50: nop

    return;
    // 0x80135E50: nop

;}
RECOMP_FUNC void M7_FUN_80135e54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135E54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80135E58: jr          $ra
    // 0x80135E5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80135E5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80135e60(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80135e60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135E60: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80135e64(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80135e64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135E64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80135E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135E6C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80135E70: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80135E74: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80135E78: jal         0x8012A630
    // 0x80135E7C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8012A630)(rdram, ctx);
        goto after_0;
    // 0x80135E7C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x80135E80: bne         $v0, $zero, L_80135E90
    if (ctx->r2 != 0) {
        // 0x80135E84: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_80135E90;
    }
    // 0x80135E84: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80135E88: b           L_80135FF0
    // 0x80135E8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80135FF0;
    // 0x80135E8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80135E90:
    // 0x80135E90: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80135E94: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80135E98: jal         0x8001EAD0
    // 0x80135E9C: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x80135E9C: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_1:
    // 0x80135EA0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80135EA4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80135EA8: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x80135EAC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x80135EB0: jal         0x8001EB64
    // 0x80135EB4: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_2;
    // 0x80135EB4: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_2:
    // 0x80135EB8: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80135EBC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80135EC0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80135EC4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80135EC8: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x80135ECC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80135ED0: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80135ED4: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x80135ED8: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80135EDC: lw          $t2, -0x4330($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4330);
    // 0x80135EE0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80135EE4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80135EE8: lw          $v1, 0x2C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X2C);
    // 0x80135EEC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80135EF0: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80135EF4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80135EF8: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80135EFC: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80135F00: jal         0x8001EF38
    // 0x80135F04: sub.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f10.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x80135F04: sub.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f10.fl;
    after_3:
    // 0x80135F08: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80135F0C: lbu         $t9, 0x33($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X33);
    // 0x80135F10: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x80135F14: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80135F18: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    // 0x80135F1C: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
    // 0x80135F20: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80135F24: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80135F28: andi        $t8, $v1, 0x1000
    ctx->r24 = ctx->r3 & 0X1000;
    // 0x80135F2C: beql        $t8, $zero, L_80135F4C
    if (ctx->r24 == 0) {
        // 0x80135F30: andi        $v1, $v1, 0x1FFF
        ctx->r3 = ctx->r3 & 0X1FFF;
            goto L_80135F4C;
    }
    goto skip_0;
    // 0x80135F30: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    skip_0:
    // 0x80135F34: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x80135F38: addiu       $v1, $v1, -0x2000
    ctx->r3 = ADD32(ctx->r3, -0X2000);
    // 0x80135F3C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80135F40: b           L_80135F54
    // 0x80135F44: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80135F54;
    // 0x80135F44: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80135F48: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
L_80135F4C:
    // 0x80135F4C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80135F50: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80135F54:
    // 0x80135F54: bgez        $v1, L_80135F64
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80135F58: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80135F64;
    }
    // 0x80135F58: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80135F5C: b           L_80135F64
    // 0x80135F60: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_80135F64;
    // 0x80135F60: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_80135F64:
    // 0x80135F64: slti        $at, $v0, 0x201
    ctx->r1 = SIGNED(ctx->r2) < 0X201 ? 1 : 0;
    // 0x80135F68: bne         $at, $zero, L_80135F78
    if (ctx->r1 != 0) {
        // 0x80135F6C: nop
    
            goto L_80135F78;
    }
    // 0x80135F6C: nop

    // 0x80135F70: b           L_80135FF0
    // 0x80135F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80135FF0;
    // 0x80135F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80135F78:
    // 0x80135F78: bne         $t9, $zero, L_80135FEC
    if (ctx->r25 != 0) {
        // 0x80135F7C: lui         $t0, 0x801C
        ctx->r8 = S32(0X801C << 16);
            goto L_80135FEC;
    }
    // 0x80135F7C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80135F80: lw          $t0, -0x4330($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4330);
    // 0x80135F84: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80135F88: lh          $t2, 0x12($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X12);
    // 0x80135F8C: subu        $v1, $t2, $a0
    ctx->r3 = SUB32(ctx->r10, ctx->r4);
    // 0x80135F90: addiu       $v1, $v1, 0x1000
    ctx->r3 = ADD32(ctx->r3, 0X1000);
    // 0x80135F94: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80135F98: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80135F9C: andi        $t3, $v1, 0x1000
    ctx->r11 = ctx->r3 & 0X1000;
    // 0x80135FA0: beql        $t3, $zero, L_80135FC0
    if (ctx->r11 == 0) {
        // 0x80135FA4: andi        $v1, $v1, 0x1FFF
        ctx->r3 = ctx->r3 & 0X1FFF;
            goto L_80135FC0;
    }
    goto skip_1;
    // 0x80135FA4: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    skip_1:
    // 0x80135FA8: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x80135FAC: addiu       $v1, $v1, -0x2000
    ctx->r3 = ADD32(ctx->r3, -0X2000);
    // 0x80135FB0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80135FB4: b           L_80135FC8
    // 0x80135FB8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_80135FC8;
    // 0x80135FB8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80135FBC: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
L_80135FC0:
    // 0x80135FC0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80135FC4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80135FC8:
    // 0x80135FC8: bgez        $v1, L_80135FD8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80135FCC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80135FD8;
    }
    // 0x80135FCC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80135FD0: b           L_80135FD8
    // 0x80135FD4: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_80135FD8;
    // 0x80135FD4: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_80135FD8:
    // 0x80135FD8: slti        $at, $v0, 0x401
    ctx->r1 = SIGNED(ctx->r2) < 0X401 ? 1 : 0;
    // 0x80135FDC: bnel        $at, $zero, L_80135FF0
    if (ctx->r1 != 0) {
        // 0x80135FE0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80135FF0;
    }
    goto skip_2;
    // 0x80135FE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80135FE4: b           L_80135FF0
    // 0x80135FE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80135FF0;
    // 0x80135FE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80135FEC:
    // 0x80135FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80135FF0:
    // 0x80135FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135FF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80135FF8: jr          $ra
    // 0x80135FFC: nop

    return;
    // 0x80135FFC: nop

;}
RECOMP_FUNC void M7_FUN_80136000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80136004: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80136008: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8013600C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80136010: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80136014: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80136018: lw          $t6, 0x38($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X38);
    // 0x8013601C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80136020: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80136024: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80136028: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x8013602C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80136030: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80136034: bgez        $t9, L_80136048
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80136038: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80136048;
    }
    // 0x80136038: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013603C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136040: nop

    // 0x80136044: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80136048:
    // 0x80136048: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8013604C: jal         0x80135E60
    // 0x80136050: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    LOOKUP_FUNC(0x80135E60)(rdram, ctx);
        goto after_0;
    // 0x80136050: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_0:
    // 0x80136054: beql        $v0, $zero, L_801361B8
    if (ctx->r2 == 0) {
        // 0x80136058: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801361B8;
    }
    goto skip_0;
    // 0x80136058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8013605C: jal         0x801268F4
    // 0x80136060: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801268F4)(rdram, ctx);
        goto after_1;
    // 0x80136060: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80136064: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80136068: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x8013606C: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80136070: sh          $t0, 0x192($s0)
    MEM_H(0X192, ctx->r16) = ctx->r8;
    // 0x80136074: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x80136078: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8013607C: jal         0x8001EAD0
    // 0x80136080: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x80136080: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_2:
    // 0x80136084: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x80136088: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8013608C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80136090: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x80136094: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80136098: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8013609C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801360A0: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x801360A4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801360A8: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x801360AC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801360B0: swc1        $f8, 0x198($s0)
    MEM_W(0X198, ctx->r16) = ctx->f8.u32l;
    // 0x801360B4: lw          $t5, 0x24($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X24);
    // 0x801360B8: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801360BC: jal         0x8001EB64
    // 0x801360C0: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x801360C0: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    after_3:
    // 0x801360C4: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x801360C8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801360CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801360D0: lw          $t7, 0x24($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X24);
    // 0x801360D4: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801360D8: mul.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801360DC: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801360E0: lwc1        $f4, 0xC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC);
    // 0x801360E4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801360E8: add.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f16.d + ctx->f6.d;
    // 0x801360EC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801360F0: swc1        $f10, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = ctx->f10.u32l;
    // 0x801360F4: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x801360F8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801360FC: jal         0x8001EAD0
    // 0x80136100: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x80136100: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    after_4:
    // 0x80136104: lui         $at, 0xC014
    ctx->r1 = S32(0XC014 << 16);
    // 0x80136108: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8013610C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80136110: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x80136114: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80136118: mul.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8013611C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80136120: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80136124: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80136128: add.d       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f16.d + ctx->f8.d;
    // 0x8013612C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80136130: swc1        $f18, 0xF14($s0)
    MEM_W(0XF14, ctx->r16) = ctx->f18.u32l;
    // 0x80136134: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x80136138: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x8013613C: jal         0x8001EB64
    // 0x80136140: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x80136140: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_5:
    // 0x80136144: lui         $at, 0xC014
    ctx->r1 = S32(0XC014 << 16);
    // 0x80136148: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8013614C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80136150: lw          $t5, 0x24($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X24);
    // 0x80136154: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80136158: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013615C: mul.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80136160: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80136164: lui         $t7, 0x168
    ctx->r15 = S32(0X168 << 16);
    // 0x80136168: ori         $t7, $t7, 0x3E
    ctx->r15 = ctx->r15 | 0X3E;
    // 0x8013616C: lwc1        $f8, 0xC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80136170: addiu       $t8, $zero, 0x1100
    ctx->r24 = ADD32(0, 0X1100);
    // 0x80136174: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136178: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8013617C: addiu       $a1, $a1, 0x61C8
    ctx->r5 = ADD32(ctx->r5, 0X61C8);
    // 0x80136180: add.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d + ctx->f10.d;
    // 0x80136184: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80136188: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8013618C: swc1        $f4, 0xF18($s0)
    MEM_W(0XF18, ctx->r16) = ctx->f4.u32l;
    // 0x80136190: lwc1        $f6, -0x2498($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2498);
    // 0x80136194: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80136198: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013619C: sw          $t7, 0xF10($s0)
    MEM_W(0XF10, ctx->r16) = ctx->r15;
    // 0x801361A0: sh          $zero, 0xF0C($s0)
    MEM_H(0XF0C, ctx->r16) = 0;
    // 0x801361A4: sh          $t8, 0xF00($s0)
    MEM_H(0XF00, ctx->r16) = ctx->r24;
    // 0x801361A8: swc1        $f6, 0xF04($s0)
    MEM_W(0XF04, ctx->r16) = ctx->f6.u32l;
    // 0x801361AC: jal         0x800058DC
    // 0x801361B0: swc1        $f8, 0xF08($s0)
    MEM_W(0XF08, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801361B0: swc1        $f8, 0xF08($s0)
    MEM_W(0XF08, ctx->r16) = ctx->f8.u32l;
    after_6:
    // 0x801361B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801361B8:
    // 0x801361B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801361BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801361C0: jr          $ra
    // 0x801361C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801361C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801361c8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801361c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801361C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801361CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801361D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801361D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801361D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801361DC: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x801361E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801361E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801361E8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x801361EC: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x801361F0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801361F4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801361F8: bgez        $t9, L_8013620C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801361FC: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8013620C;
    }
    // 0x801361FC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80136200: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136204: nop

    // 0x80136208: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8013620C:
    // 0x8013620C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80136210: jal         0x80135E60
    // 0x80136214: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    LOOKUP_FUNC(0x80135E60)(rdram, ctx);
        goto after_0;
    // 0x80136214: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    after_0:
    // 0x80136218: bne         $v0, $zero, L_80136238
    if (ctx->r2 != 0) {
        // 0x8013621C: lui         $t0, 0x801C
        ctx->r8 = S32(0X801C << 16);
            goto L_80136238;
    }
    // 0x8013621C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80136220: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136224: addiu       $a1, $a1, 0x64B4
    ctx->r5 = ADD32(ctx->r5, 0X64B4);
    // 0x80136228: jal         0x800058DC
    // 0x8013622C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8013622C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80136230: b           L_801362CC
    // 0x80136234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801362CC;
    // 0x80136234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80136238:
    // 0x80136238: lhu         $t0, -0x427A($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X427A);
    // 0x8013623C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80136240: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80136244: bnel        $t0, $at, L_801362CC
    if (ctx->r8 != ctx->r1) {
        // 0x80136248: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801362CC;
    }
    goto skip_0;
    // 0x80136248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8013624C: jal         0x8013D4A0
    // 0x80136250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8013D4A0)(rdram, ctx);
        goto after_2;
    // 0x80136250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80136254: bne         $v0, $zero, L_80136294
    if (ctx->r2 != 0) {
        // 0x80136258: lui         $a0, 0x8021
        ctx->r4 = S32(0X8021 << 16);
            goto L_80136294;
    }
    // 0x80136258: lui         $a0, 0x8021
    ctx->r4 = S32(0X8021 << 16);
    // 0x8013625C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80136260: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80136264: lui         $a0, 0x8021
    ctx->r4 = S32(0X8021 << 16);
    // 0x80136268: sh          $t1, -0x427E($at)
    MEM_H(-0X427E, ctx->r1) = ctx->r9;
    // 0x8013626C: jal         0x800179B0
    // 0x80136270: addiu       $a0, $a0, 0x7F5C
    ctx->r4 = ADD32(ctx->r4, 0X7F5C);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_3;
    // 0x80136270: addiu       $a0, $a0, 0x7F5C
    ctx->r4 = ADD32(ctx->r4, 0X7F5C);
    after_3:
    // 0x80136274: jal         0x80020744
    // 0x80136278: addiu       $a0, $zero, 0x3DB
    ctx->r4 = ADD32(0, 0X3DB);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_4;
    // 0x80136278: addiu       $a0, $zero, 0x3DB
    ctx->r4 = ADD32(0, 0X3DB);
    after_4:
    // 0x8013627C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136280: addiu       $a1, $a1, 0x63C8
    ctx->r5 = ADD32(ctx->r5, 0X63C8);
    // 0x80136284: jal         0x800058DC
    // 0x80136288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80136288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8013628C: b           L_801362CC
    // 0x80136290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801362CC;
    // 0x80136290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80136294:
    // 0x80136294: jal         0x800179B0
    // 0x80136298: addiu       $a0, $a0, 0x7F5C
    ctx->r4 = ADD32(ctx->r4, 0X7F5C);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_6;
    // 0x80136298: addiu       $a0, $a0, 0x7F5C
    ctx->r4 = ADD32(ctx->r4, 0X7F5C);
    after_6:
    // 0x8013629C: jal         0x80020744
    // 0x801362A0: addiu       $a0, $zero, 0x3DB
    ctx->r4 = ADD32(0, 0X3DB);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_7;
    // 0x801362A0: addiu       $a0, $zero, 0x3DB
    ctx->r4 = ADD32(0, 0X3DB);
    after_7:
    // 0x801362A4: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x801362A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801362AC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801362B0: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x801362B4: addiu       $a1, $a1, 0x62DC
    ctx->r5 = ADD32(ctx->r5, 0X62DC);
    // 0x801362B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801362BC: srl         $t5, $t3, 8
    ctx->r13 = S32(U32(ctx->r11) >> 8);
    // 0x801362C0: jal         0x800058DC
    // 0x801362C4: sb          $t5, -0x43FA($at)
    MEM_B(-0X43FA, ctx->r1) = ctx->r13;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801362C4: sb          $t5, -0x43FA($at)
    MEM_B(-0X43FA, ctx->r1) = ctx->r13;
    after_8:
    // 0x801362C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801362CC:
    // 0x801362CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801362D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801362D4: jr          $ra
    // 0x801362D8: nop

    return;
    // 0x801362D8: nop

;}
RECOMP_FUNC void M7_FUN_801362dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801362DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801362E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801362E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801362E8: jal         0x800178E8
    // 0x801362EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x801362EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801362F0: beq         $v0, $zero, L_80136344
    if (ctx->r2 == 0) {
        // 0x801362F4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80136344;
    }
    // 0x801362F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801362F8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801362FC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80136300: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80136304: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136308: lui         $t8, 0x2A8
    ctx->r24 = S32(0X2A8 << 16);
    // 0x8013630C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80136310: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80136314: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x80136318: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x8013631C: sh          $t6, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r14;
    // 0x80136320: sh          $t7, 0x192($v0)
    MEM_H(0X192, ctx->r2) = ctx->r15;
    // 0x80136324: sw          $t8, 0xF10($v0)
    MEM_W(0XF10, ctx->r2) = ctx->r24;
    // 0x80136328: sh          $t9, 0xF00($v0)
    MEM_H(0XF00, ctx->r2) = ctx->r25;
    // 0x8013632C: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x80136330: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136334: swc1        $f4, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f4.u32l;
    // 0x80136338: sh          $t0, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r8;
    // 0x8013633C: jal         0x800058DC
    // 0x80136340: addiu       $a1, $a1, 0x6354
    ctx->r5 = ADD32(ctx->r5, 0X6354);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80136340: addiu       $a1, $a1, 0x6354
    ctx->r5 = ADD32(ctx->r5, 0X6354);
    after_1:
L_80136344:
    // 0x80136344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013634C: jr          $ra
    // 0x80136350: nop

    return;
    // 0x80136350: nop

;}
RECOMP_FUNC void M7_FUN_80136354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136354: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013635C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80136360: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x80136364: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80136368: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8013636C: bne         $v0, $at, L_80136384
    if (ctx->r2 != ctx->r1) {
        // 0x80136370: addiu       $a0, $zero, 0x3DE
        ctx->r4 = ADD32(0, 0X3DE);
            goto L_80136384;
    }
    // 0x80136370: addiu       $a0, $zero, 0x3DE
    ctx->r4 = ADD32(0, 0X3DE);
    // 0x80136374: jal         0x80020744
    // 0x80136378: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80136378: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8013637C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80136380: lh          $v0, 0x90($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X90);
L_80136384:
    // 0x80136384: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80136388: bne         $v0, $zero, L_801363B8
    if (ctx->r2 != 0) {
        // 0x8013638C: sh          $t6, 0x90($a2)
        MEM_H(0X90, ctx->r6) = ctx->r14;
            goto L_801363B8;
    }
    // 0x8013638C: sh          $t6, 0x90($a2)
    MEM_H(0X90, ctx->r6) = ctx->r14;
    // 0x80136390: lui         $a0, 0x8021
    ctx->r4 = S32(0X8021 << 16);
    // 0x80136394: addiu       $a0, $a0, 0x7FB0
    ctx->r4 = ADD32(ctx->r4, 0X7FB0);
    // 0x80136398: jal         0x800179B0
    // 0x8013639C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_1;
    // 0x8013639C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x801363A0: jal         0x80020744
    // 0x801363A4: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x801363A4: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    after_2:
    // 0x801363A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801363AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801363B0: jal         0x800058DC
    // 0x801363B4: addiu       $a1, $a1, 0x63C8
    ctx->r5 = ADD32(ctx->r5, 0X63C8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801363B4: addiu       $a1, $a1, 0x63C8
    ctx->r5 = ADD32(ctx->r5, 0X63C8);
    after_3:
L_801363B8:
    // 0x801363B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801363BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801363C0: jr          $ra
    // 0x801363C4: nop

    return;
    // 0x801363C4: nop

;}
RECOMP_FUNC void M7_FUN_801363c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801363C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801363CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801363D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801363D4: jal         0x800178E8
    // 0x801363D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x801363D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801363DC: beql        $v0, $zero, L_80136430
    if (ctx->r2 == 0) {
        // 0x801363E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80136430;
    }
    goto skip_0;
    // 0x801363E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801363E4: jal         0x80020744
    // 0x801363E8: addiu       $a0, $zero, 0x3DE
    ctx->r4 = ADD32(0, 0X3DE);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x801363E8: addiu       $a0, $zero, 0x3DE
    ctx->r4 = ADD32(0, 0X3DE);
    after_1:
    // 0x801363EC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801363F0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801363F4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801363F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801363FC: lui         $t7, 0x2A8
    ctx->r15 = S32(0X2A8 << 16);
    // 0x80136400: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80136404: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x80136408: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    // 0x8013640C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136410: sh          $t6, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r14;
    // 0x80136414: sw          $t7, 0xF10($v0)
    MEM_W(0XF10, ctx->r2) = ctx->r15;
    // 0x80136418: sh          $t8, 0xF00($v0)
    MEM_H(0XF00, ctx->r2) = ctx->r24;
    // 0x8013641C: addiu       $a1, $a1, 0x643C
    ctx->r5 = ADD32(ctx->r5, 0X643C);
    // 0x80136420: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80136424: jal         0x800058DC
    // 0x80136428: swc1        $f4, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f4.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80136428: swc1        $f4, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f4.u32l;
    after_2:
    // 0x8013642C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136430:
    // 0x80136430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136434: jr          $ra
    // 0x80136438: nop

    return;
    // 0x80136438: nop

;}
RECOMP_FUNC void M7_FUN_8013643c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013643C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136440: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80136444: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80136448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013644C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80136450: sh          $t6, -0x427C($at)
    MEM_H(-0X427C, ctx->r1) = ctx->r14;
    // 0x80136454: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x80136458: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8013645C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80136460: srl         $t9, $t8, 16
    ctx->r25 = S32(U32(ctx->r24) >> 16);
    // 0x80136464: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80136468: addiu       $t1, $t0, 0x1E
    ctx->r9 = ADD32(ctx->r8, 0X1E);
    // 0x8013646C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80136470: bgez        $t1, L_80136484
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80136474: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80136484;
    }
    // 0x80136474: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80136478: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013647C: nop

    // 0x80136480: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80136484:
    // 0x80136484: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80136488: jal         0x8012A630
    // 0x8013648C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012A630)(rdram, ctx);
        goto after_0;
    // 0x8013648C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80136490: bne         $v0, $zero, L_801364A4
    if (ctx->r2 != 0) {
        // 0x80136494: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801364A4;
    }
    // 0x80136494: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80136498: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013649C: jal         0x800058DC
    // 0x801364A0: addiu       $a1, $a1, 0x6000
    ctx->r5 = ADD32(ctx->r5, 0X6000);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801364A0: addiu       $a1, $a1, 0x6000
    ctx->r5 = ADD32(ctx->r5, 0X6000);
    after_1:
L_801364A4:
    // 0x801364A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801364A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801364AC: jr          $ra
    // 0x801364B0: nop

    return;
    // 0x801364B0: nop

;}
RECOMP_FUNC void M7_FUN_801364b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801364B4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801364B8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801364BC: lhu         $t7, 0x18E($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X18E);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801364c0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801364c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801364C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801364C4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801364C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801364CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801364D0: bne         $t7, $zero, L_801364E4
    if (ctx->r15 != 0) {
        // 0x801364D4: sh          $t6, 0x194($v0)
        MEM_H(0X194, ctx->r2) = ctx->r14;
            goto L_801364E4;
    }
    // 0x801364D4: sh          $t6, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r14;
    // 0x801364D8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801364DC: jal         0x800058DC
    // 0x801364E0: addiu       $a1, $a1, 0x6000
    ctx->r5 = ADD32(ctx->r5, 0X6000);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801364E0: addiu       $a1, $a1, 0x6000
    ctx->r5 = ADD32(ctx->r5, 0X6000);
    after_0:
L_801364E4:
    // 0x801364E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801364E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801364EC: jr          $ra
    // 0x801364F0: nop

    return;
    // 0x801364F0: nop

;}
RECOMP_FUNC void M7_FUN_801364f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801364F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801364F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801364FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80136500: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80136504: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80136508: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8013650C: lw          $t6, 0x38($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X38);
    // 0x80136510: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80136514: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80136518: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8013651C: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x80136520: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80136524: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80136528: bgez        $t9, L_8013653C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8013652C: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8013653C;
    }
    // 0x8013652C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80136530: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136534: nop

    // 0x80136538: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8013653C:
    // 0x8013653C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80136540: jal         0x80135E60
    // 0x80136544: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    LOOKUP_FUNC(0x80135E60)(rdram, ctx);
        goto after_0;
    // 0x80136544: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    after_0:
    // 0x80136548: beql        $v0, $zero, L_801366AC
    if (ctx->r2 == 0) {
        // 0x8013654C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801366AC;
    }
    goto skip_0;
    // 0x8013654C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80136550: jal         0x801268F4
    // 0x80136554: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801268F4)(rdram, ctx);
        goto after_1;
    // 0x80136554: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80136558: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8013655C: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x80136560: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80136564: sh          $t0, 0x192($s0)
    MEM_H(0X192, ctx->r16) = ctx->r8;
    // 0x80136568: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x8013656C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80136570: jal         0x8001EAD0
    // 0x80136574: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x80136574: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_2:
    // 0x80136578: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8013657C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80136580: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80136584: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x80136588: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8013658C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80136590: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80136594: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80136598: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8013659C: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x801365A0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801365A4: swc1        $f8, 0x198($s0)
    MEM_W(0X198, ctx->r16) = ctx->f8.u32l;
    // 0x801365A8: lw          $t5, 0x24($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X24);
    // 0x801365AC: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801365B0: jal         0x8001EB64
    // 0x801365B4: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x801365B4: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    after_3:
    // 0x801365B8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801365BC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801365C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801365C4: lw          $t7, 0x24($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X24);
    // 0x801365C8: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801365CC: mul.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x801365D0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801365D4: lwc1        $f4, 0xC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC);
    // 0x801365D8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801365DC: add.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f16.d + ctx->f6.d;
    // 0x801365E0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801365E4: swc1        $f10, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = ctx->f10.u32l;
    // 0x801365E8: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x801365EC: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801365F0: jal         0x8001EAD0
    // 0x801365F4: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x801365F4: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    after_4:
    // 0x801365F8: lui         $at, 0xC020
    ctx->r1 = S32(0XC020 << 16);
    // 0x801365FC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80136600: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80136604: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x80136608: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8013660C: mul.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80136610: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80136614: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80136618: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8013661C: add.d       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f16.d + ctx->f8.d;
    // 0x80136620: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80136624: swc1        $f18, 0xF14($s0)
    MEM_W(0XF14, ctx->r16) = ctx->f18.u32l;
    // 0x80136628: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x8013662C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80136630: jal         0x8001EB64
    // 0x80136634: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x80136634: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_5:
    // 0x80136638: lui         $at, 0xC020
    ctx->r1 = S32(0XC020 << 16);
    // 0x8013663C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80136640: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80136644: lw          $t5, 0x24($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X24);
    // 0x80136648: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8013664C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80136650: mul.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80136654: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80136658: lui         $t7, 0x168
    ctx->r15 = S32(0X168 << 16);
    // 0x8013665C: ori         $t7, $t7, 0x3E
    ctx->r15 = ctx->r15 | 0X3E;
    // 0x80136660: lwc1        $f8, 0xC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80136664: addiu       $t8, $zero, 0x1100
    ctx->r24 = ADD32(0, 0X1100);
    // 0x80136668: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013666C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80136670: addiu       $a1, $a1, 0x66BC
    ctx->r5 = ADD32(ctx->r5, 0X66BC);
    // 0x80136674: add.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d + ctx->f10.d;
    // 0x80136678: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013667C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80136680: swc1        $f4, 0xF18($s0)
    MEM_W(0XF18, ctx->r16) = ctx->f4.u32l;
    // 0x80136684: lwc1        $f6, -0x2494($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2494);
    // 0x80136688: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013668C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80136690: sw          $t7, 0xF10($s0)
    MEM_W(0XF10, ctx->r16) = ctx->r15;
    // 0x80136694: sh          $zero, 0xF0C($s0)
    MEM_H(0XF0C, ctx->r16) = 0;
    // 0x80136698: sh          $t8, 0xF00($s0)
    MEM_H(0XF00, ctx->r16) = ctx->r24;
    // 0x8013669C: swc1        $f6, 0xF04($s0)
    MEM_W(0XF04, ctx->r16) = ctx->f6.u32l;
    // 0x801366A0: jal         0x800058DC
    // 0x801366A4: swc1        $f8, 0xF08($s0)
    MEM_W(0XF08, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801366A4: swc1        $f8, 0xF08($s0)
    MEM_W(0XF08, ctx->r16) = ctx->f8.u32l;
    after_6:
    // 0x801366A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801366AC:
    // 0x801366AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801366B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801366B4: jr          $ra
    // 0x801366B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801366B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801366bc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801366bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801366BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801366C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801366C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801366C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801366CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801366D0: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x801366D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801366D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801366DC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x801366E0: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x801366E4: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801366E8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801366EC: bgez        $t9, L_80136700
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801366F0: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80136700;
    }
    // 0x801366F0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801366F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801366F8: nop

    // 0x801366FC: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80136700:
    // 0x80136700: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80136704: jal         0x80135E60
    // 0x80136708: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    LOOKUP_FUNC(0x80135E60)(rdram, ctx);
        goto after_0;
    // 0x80136708: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    after_0:
    // 0x8013670C: bne         $v0, $zero, L_8013672C
    if (ctx->r2 != 0) {
        // 0x80136710: lui         $t0, 0x801C
        ctx->r8 = S32(0X801C << 16);
            goto L_8013672C;
    }
    // 0x80136710: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80136714: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136718: addiu       $a1, $a1, 0x6978
    ctx->r5 = ADD32(ctx->r5, 0X6978);
    // 0x8013671C: jal         0x800058DC
    // 0x80136720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80136720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80136724: b           L_801367B8
    // 0x80136728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801367B8;
    // 0x80136728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013672C:
    // 0x8013672C: lhu         $t0, -0x427A($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X427A);
    // 0x80136730: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80136734: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80136738: bnel        $t0, $at, L_801367B8
    if (ctx->r8 != ctx->r1) {
        // 0x8013673C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801367B8;
    }
    goto skip_0;
    // 0x8013673C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80136740: jal         0x8013D4A0
    // 0x80136744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8013D4A0)(rdram, ctx);
        goto after_2;
    // 0x80136744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80136748: bne         $v0, $zero, L_80136788
    if (ctx->r2 != 0) {
        // 0x8013674C: lui         $a0, 0x8021
        ctx->r4 = S32(0X8021 << 16);
            goto L_80136788;
    }
    // 0x8013674C: lui         $a0, 0x8021
    ctx->r4 = S32(0X8021 << 16);
    // 0x80136750: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80136754: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80136758: lui         $a0, 0x8021
    ctx->r4 = S32(0X8021 << 16);
    // 0x8013675C: sh          $t1, -0x427E($at)
    MEM_H(-0X427E, ctx->r1) = ctx->r9;
    // 0x80136760: jal         0x800179B0
    // 0x80136764: addiu       $a0, $a0, 0x7F5C
    ctx->r4 = ADD32(ctx->r4, 0X7F5C);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_3;
    // 0x80136764: addiu       $a0, $a0, 0x7F5C
    ctx->r4 = ADD32(ctx->r4, 0X7F5C);
    after_3:
    // 0x80136768: jal         0x80020744
    // 0x8013676C: addiu       $a0, $zero, 0x3DB
    ctx->r4 = ADD32(0, 0X3DB);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_4;
    // 0x8013676C: addiu       $a0, $zero, 0x3DB
    ctx->r4 = ADD32(0, 0X3DB);
    after_4:
    // 0x80136770: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136774: addiu       $a1, $a1, 0x6898
    ctx->r5 = ADD32(ctx->r5, 0X6898);
    // 0x80136778: jal         0x800058DC
    // 0x8013677C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x8013677C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80136780: b           L_801367B8
    // 0x80136784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801367B8;
    // 0x80136784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80136788:
    // 0x80136788: jal         0x800179B0
    // 0x8013678C: addiu       $a0, $a0, 0x7F5C
    ctx->r4 = ADD32(ctx->r4, 0X7F5C);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_6;
    // 0x8013678C: addiu       $a0, $a0, 0x7F5C
    ctx->r4 = ADD32(ctx->r4, 0X7F5C);
    after_6:
    // 0x80136790: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x80136794: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80136798: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013679C: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x801367A0: addiu       $a1, $a1, 0x67C8
    ctx->r5 = ADD32(ctx->r5, 0X67C8);
    // 0x801367A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801367A8: srl         $t5, $t3, 8
    ctx->r13 = S32(U32(ctx->r11) >> 8);
    // 0x801367AC: jal         0x800058DC
    // 0x801367B0: sb          $t5, -0x43FA($at)
    MEM_B(-0X43FA, ctx->r1) = ctx->r13;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801367B0: sb          $t5, -0x43FA($at)
    MEM_B(-0X43FA, ctx->r1) = ctx->r13;
    after_7:
    // 0x801367B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801367B8:
    // 0x801367B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801367BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801367C0: jr          $ra
    // 0x801367C4: nop

    return;
    // 0x801367C4: nop

;}
RECOMP_FUNC void M7_FUN_801367c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801367C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801367CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801367D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801367D4: jal         0x800178E8
    // 0x801367D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x801367D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801367DC: beq         $v0, $zero, L_80136830
    if (ctx->r2 == 0) {
        // 0x801367E0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80136830;
    }
    // 0x801367E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801367E4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801367E8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801367EC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801367F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801367F4: lui         $t8, 0x2A8
    ctx->r24 = S32(0X2A8 << 16);
    // 0x801367F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801367FC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80136800: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x80136804: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x80136808: sh          $t6, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r14;
    // 0x8013680C: sh          $t7, 0x192($v0)
    MEM_H(0X192, ctx->r2) = ctx->r15;
    // 0x80136810: sw          $t8, 0xF10($v0)
    MEM_W(0XF10, ctx->r2) = ctx->r24;
    // 0x80136814: sh          $t9, 0xF00($v0)
    MEM_H(0XF00, ctx->r2) = ctx->r25;
    // 0x80136818: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x8013681C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136820: swc1        $f4, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f4.u32l;
    // 0x80136824: sh          $t0, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r8;
    // 0x80136828: jal         0x800058DC
    // 0x8013682C: addiu       $a1, $a1, 0x6840
    ctx->r5 = ADD32(ctx->r5, 0X6840);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x8013682C: addiu       $a1, $a1, 0x6840
    ctx->r5 = ADD32(ctx->r5, 0X6840);
    after_1:
L_80136830:
    // 0x80136830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136838: jr          $ra
    // 0x8013683C: nop

    return;
    // 0x8013683C: nop

;}
RECOMP_FUNC void M7_FUN_80136840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136848: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8013684C: lh          $v0, 0x90($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X90);
    // 0x80136850: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80136854: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80136858: bne         $v0, $zero, L_80136888
    if (ctx->r2 != 0) {
        // 0x8013685C: sh          $t6, 0x90($a0)
        MEM_H(0X90, ctx->r4) = ctx->r14;
            goto L_80136888;
    }
    // 0x8013685C: sh          $t6, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r14;
    // 0x80136860: lui         $a0, 0x8021
    ctx->r4 = S32(0X8021 << 16);
    // 0x80136864: addiu       $a0, $a0, 0x7FB0
    ctx->r4 = ADD32(ctx->r4, 0X7FB0);
    // 0x80136868: jal         0x800179B0
    // 0x8013686C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_0;
    // 0x8013686C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80136870: jal         0x80020744
    // 0x80136874: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x80136874: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    after_1:
    // 0x80136878: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013687C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80136880: jal         0x800058DC
    // 0x80136884: addiu       $a1, $a1, 0x6898
    ctx->r5 = ADD32(ctx->r5, 0X6898);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80136884: addiu       $a1, $a1, 0x6898
    ctx->r5 = ADD32(ctx->r5, 0X6898);
    after_2:
L_80136888:
    // 0x80136888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013688C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136890: jr          $ra
    // 0x80136894: nop

    return;
    // 0x80136894: nop

;}
RECOMP_FUNC void M7_FUN_80136898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136898: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013689C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801368A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801368A4: jal         0x800178E8
    // 0x801368A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x801368A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801368AC: beq         $v0, $zero, L_801368F0
    if (ctx->r2 == 0) {
        // 0x801368B0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_801368F0;
    }
    // 0x801368B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801368B4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801368B8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801368BC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801368C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801368C4: lui         $t7, 0x2A8
    ctx->r15 = S32(0X2A8 << 16);
    // 0x801368C8: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x801368CC: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    // 0x801368D0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801368D4: sh          $t6, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r14;
    // 0x801368D8: sw          $t7, 0xF10($v0)
    MEM_W(0XF10, ctx->r2) = ctx->r15;
    // 0x801368DC: sh          $t8, 0xF00($v0)
    MEM_H(0XF00, ctx->r2) = ctx->r24;
    // 0x801368E0: addiu       $a1, $a1, 0x6900
    ctx->r5 = ADD32(ctx->r5, 0X6900);
    // 0x801368E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801368E8: jal         0x800058DC
    // 0x801368EC: swc1        $f4, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f4.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801368EC: swc1        $f4, 0xF08($v0)
    MEM_W(0XF08, ctx->r2) = ctx->f4.u32l;
    after_1:
L_801368F0:
    // 0x801368F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801368F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801368F8: jr          $ra
    // 0x801368FC: nop

    return;
    // 0x801368FC: nop

;}
RECOMP_FUNC void M7_FUN_80136900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136900: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136904: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80136908: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8013690C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136910: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80136914: sh          $t6, -0x427C($at)
    MEM_H(-0X427C, ctx->r1) = ctx->r14;
    // 0x80136918: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x8013691C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80136920: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80136924: srl         $t9, $t8, 16
    ctx->r25 = S32(U32(ctx->r24) >> 16);
    // 0x80136928: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8013692C: addiu       $t1, $t0, 0x1E
    ctx->r9 = ADD32(ctx->r8, 0X1E);
    // 0x80136930: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80136934: bgez        $t1, L_80136948
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80136938: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80136948;
    }
    // 0x80136938: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013693C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136940: nop

    // 0x80136944: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80136948:
    // 0x80136948: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8013694C: jal         0x8012A630
    // 0x80136950: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012A630)(rdram, ctx);
        goto after_0;
    // 0x80136950: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80136954: bne         $v0, $zero, L_80136968
    if (ctx->r2 != 0) {
        // 0x80136958: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80136968;
    }
    // 0x80136958: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8013695C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136960: jal         0x800058DC
    // 0x80136964: addiu       $a1, $a1, 0x64F4
    ctx->r5 = ADD32(ctx->r5, 0X64F4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80136964: addiu       $a1, $a1, 0x64F4
    ctx->r5 = ADD32(ctx->r5, 0X64F4);
    after_1:
L_80136968:
    // 0x80136968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013696C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136970: jr          $ra
    // 0x80136974: nop

    return;
    // 0x80136974: nop

;}
RECOMP_FUNC void M7_FUN_80136978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136978: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8013697C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80136980: lhu         $t7, 0x18E($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X18E);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80136984(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80136984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136988: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8013698C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136990: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80136994: bne         $t7, $zero, L_801369A8
    if (ctx->r15 != 0) {
        // 0x80136998: sh          $t6, 0x194($v0)
        MEM_H(0X194, ctx->r2) = ctx->r14;
            goto L_801369A8;
    }
    // 0x80136998: sh          $t6, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r14;
    // 0x8013699C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801369A0: jal         0x800058DC
    // 0x801369A4: addiu       $a1, $a1, 0x64F4
    ctx->r5 = ADD32(ctx->r5, 0X64F4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801369A4: addiu       $a1, $a1, 0x64F4
    ctx->r5 = ADD32(ctx->r5, 0X64F4);
    after_0:
L_801369A8:
    // 0x801369A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801369AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801369B0: jr          $ra
    // 0x801369B4: nop

    return;
    // 0x801369B4: nop

;}
RECOMP_FUNC void M7_FUN_801369b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801369B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801369BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801369C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801369C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801369C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801369CC: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x801369D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801369D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801369D8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x801369DC: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x801369E0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801369E4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801369E8: bgez        $t9, L_801369FC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801369EC: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801369FC;
    }
    // 0x801369EC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801369F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801369F4: nop

    // 0x801369F8: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801369FC:
    // 0x801369FC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80136A00: jal         0x80135E60
    // 0x80136A04: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x80135E60)(rdram, ctx);
        goto after_0;
    // 0x80136A04: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x80136A08: beql        $v0, $zero, L_80136AFC
    if (ctx->r2 == 0) {
        // 0x80136A0C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80136AFC;
    }
    goto skip_0;
    // 0x80136A0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80136A10: jal         0x801268F4
    // 0x80136A14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801268F4)(rdram, ctx);
        goto after_1;
    // 0x80136A14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80136A18: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80136A1C: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80136A20: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80136A24: sh          $t0, 0x192($v1)
    MEM_H(0X192, ctx->r3) = ctx->r8;
    // 0x80136A28: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80136A2C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80136A30: jal         0x8001EAD0
    // 0x80136A34: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x80136A34: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_2:
    // 0x80136A38: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80136A3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80136A40: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x80136A44: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80136A48: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80136A4C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80136A50: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80136A54: lwc1        $f16, 0x4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80136A58: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80136A5C: swc1        $f18, 0x198($v1)
    MEM_W(0X198, ctx->r3) = ctx->f18.u32l;
    // 0x80136A60: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x80136A64: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80136A68: jal         0x8001EB64
    // 0x80136A6C: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x80136A6C: lh          $a0, 0x12($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X12);
    after_3:
    // 0x80136A70: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80136A74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136A78: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80136A7C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80136A80: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80136A84: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80136A88: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x80136A8C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80136A90: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80136A94: lui         $t3, 0x168
    ctx->r11 = S32(0X168 << 16);
    // 0x80136A98: ori         $t3, $t3, 0x3E
    ctx->r11 = ctx->r11 | 0X3E;
    // 0x80136A9C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80136AA0: addiu       $t4, $zero, 0x1100
    ctx->r12 = ADD32(0, 0X1100);
    // 0x80136AA4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136AA8: addiu       $a1, $a1, 0x6B0C
    ctx->r5 = ADD32(ctx->r5, 0X6B0C);
    // 0x80136AAC: swc1        $f10, 0x1A0($v1)
    MEM_W(0X1A0, ctx->r3) = ctx->f10.u32l;
    // 0x80136AB0: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80136AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136AB8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80136ABC: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80136AC0: swc1        $f16, 0xF14($v1)
    MEM_W(0XF14, ctx->r3) = ctx->f16.u32l;
    // 0x80136AC4: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80136AC8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80136ACC: lwc1        $f18, 0xC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80136AD0: swc1        $f18, 0xF18($v1)
    MEM_W(0XF18, ctx->r3) = ctx->f18.u32l;
    // 0x80136AD4: lwc1        $f4, -0x2490($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2490);
    // 0x80136AD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80136ADC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136AE0: sw          $t3, 0xF10($v1)
    MEM_W(0XF10, ctx->r3) = ctx->r11;
    // 0x80136AE4: sh          $zero, 0xF0C($v1)
    MEM_H(0XF0C, ctx->r3) = 0;
    // 0x80136AE8: sh          $t4, 0xF00($v1)
    MEM_H(0XF00, ctx->r3) = ctx->r12;
    // 0x80136AEC: swc1        $f4, 0xF04($v1)
    MEM_W(0XF04, ctx->r3) = ctx->f4.u32l;
    // 0x80136AF0: jal         0x800058DC
    // 0x80136AF4: swc1        $f6, 0xF08($v1)
    MEM_W(0XF08, ctx->r3) = ctx->f6.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80136AF4: swc1        $f6, 0xF08($v1)
    MEM_W(0XF08, ctx->r3) = ctx->f6.u32l;
    after_4:
    // 0x80136AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80136AFC:
    // 0x80136AFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80136B00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80136B04: jr          $ra
    // 0x80136B08: nop

    return;
    // 0x80136B08: nop

;}
RECOMP_FUNC void M7_FUN_80136b0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136B0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80136B10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80136B14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80136B18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80136B1C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80136B20: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x80136B24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80136B28: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80136B2C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80136B30: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x80136B34: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80136B38: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80136B3C: bgez        $t9, L_80136B50
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80136B40: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80136B50;
    }
    // 0x80136B40: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80136B44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136B48: nop

    // 0x80136B4C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80136B50:
    // 0x80136B50: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80136B54: jal         0x80135E60
    // 0x80136B58: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x80135E60)(rdram, ctx);
        goto after_0;
    // 0x80136B58: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x80136B5C: bne         $v0, $zero, L_80136B78
    if (ctx->r2 != 0) {
        // 0x80136B60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80136B78;
    }
    // 0x80136B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136B64: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136B68: jal         0x800058DC
    // 0x80136B6C: addiu       $a1, $a1, 0x6C68
    ctx->r5 = ADD32(ctx->r5, 0X6C68);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80136B6C: addiu       $a1, $a1, 0x6C68
    ctx->r5 = ADD32(ctx->r5, 0X6C68);
    after_1:
    // 0x80136B70: b           L_80136BD0
    // 0x80136B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80136BD0;
    // 0x80136B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80136B78:
    // 0x80136B78: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80136B7C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80136B80: lhu         $t0, 0x196($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X196);
    // 0x80136B84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80136B88: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80136B8C: bnel        $t0, $at, L_80136BD0
    if (ctx->r8 != ctx->r1) {
        // 0x80136B90: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80136BD0;
    }
    goto skip_0;
    // 0x80136B90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80136B94: sh          $t1, 0x192($v0)
    MEM_H(0X192, ctx->r2) = ctx->r9;
    // 0x80136B98: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x80136B9C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80136BA0: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80136BA4: srl         $t4, $t3, 8
    ctx->r12 = S32(U32(ctx->r11) >> 8);
    // 0x80136BA8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80136BAC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80136BB0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80136BB4: jal         0x800179B0
    // 0x80136BB8: lw          $a0, -0x53DC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53DC);
    LOOKUP_FUNC(0x800179B0)(rdram, ctx);
        goto after_2;
    // 0x80136BB8: lw          $a0, -0x53DC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53DC);
    after_2:
    // 0x80136BBC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136BC0: addiu       $a1, $a1, 0x6BE0
    ctx->r5 = ADD32(ctx->r5, 0X6BE0);
    // 0x80136BC4: jal         0x800058DC
    // 0x80136BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80136BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80136BCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80136BD0:
    // 0x80136BD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80136BD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80136BD8: jr          $ra
    // 0x80136BDC: nop

    return;
    // 0x80136BDC: nop

;}
RECOMP_FUNC void M7_FUN_80136be0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136BE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80136BEC: jal         0x800178E8
    // 0x80136BF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x800178E8)(rdram, ctx);
        goto after_0;
    // 0x80136BF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80136BF4: beq         $v0, $zero, L_80136C58
    if (ctx->r2 == 0) {
        // 0x80136BF8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80136C58;
    }
    // 0x80136BF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80136BFC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80136C00: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80136C04: sh          $t6, -0x427C($at)
    MEM_H(-0X427C, ctx->r1) = ctx->r14;
    // 0x80136C08: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x80136C0C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80136C10: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80136C14: srl         $t9, $t8, 16
    ctx->r25 = S32(U32(ctx->r24) >> 16);
    // 0x80136C18: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80136C1C: addiu       $t1, $t0, 0x14
    ctx->r9 = ADD32(ctx->r8, 0X14);
    // 0x80136C20: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80136C24: bgez        $t1, L_80136C38
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80136C28: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80136C38;
    }
    // 0x80136C28: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80136C2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136C30: nop

    // 0x80136C34: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80136C38:
    // 0x80136C38: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80136C3C: jal         0x8012A630
    // 0x80136C40: nop

    LOOKUP_FUNC(0x8012A630)(rdram, ctx);
        goto after_1;
    // 0x80136C40: nop

    after_1:
    // 0x80136C44: bne         $v0, $zero, L_80136C58
    if (ctx->r2 != 0) {
        // 0x80136C48: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80136C58;
    }
    // 0x80136C48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80136C4C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136C50: jal         0x800058DC
    // 0x80136C54: addiu       $a1, $a1, 0x69B8
    ctx->r5 = ADD32(ctx->r5, 0X69B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x80136C54: addiu       $a1, $a1, 0x69B8
    ctx->r5 = ADD32(ctx->r5, 0X69B8);
    after_2:
L_80136C58:
    // 0x80136C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136C5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136C60: jr          $ra
    // 0x80136C64: nop

    return;
    // 0x80136C64: nop

;}
RECOMP_FUNC void M7_FUN_80136c68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136C68: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80136C6C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80136C70: lhu         $t7, 0x18E($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X18E);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80136c74(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80136c74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136C74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136C78: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80136C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136C80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80136C84: bne         $t7, $zero, L_80136C98
    if (ctx->r15 != 0) {
        // 0x80136C88: sh          $t6, 0x194($v0)
        MEM_H(0X194, ctx->r2) = ctx->r14;
            goto L_80136C98;
    }
    // 0x80136C88: sh          $t6, 0x194($v0)
    MEM_H(0X194, ctx->r2) = ctx->r14;
    // 0x80136C8C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136C90: jal         0x800058DC
    // 0x80136C94: addiu       $a1, $a1, 0x69B8
    ctx->r5 = ADD32(ctx->r5, 0X69B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80136C94: addiu       $a1, $a1, 0x69B8
    ctx->r5 = ADD32(ctx->r5, 0X69B8);
    after_0:
L_80136C98:
    // 0x80136C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136CA0: jr          $ra
    // 0x80136CA4: nop

    return;
    // 0x80136CA4: nop

;}
RECOMP_FUNC void M7_FUN_80136ca8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136CA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136CAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136CB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80136CB4: jal         0x80150584
    // 0x80136CB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80150584)(rdram, ctx);
        goto after_0;
    // 0x80136CB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80136CBC: beq         $v0, $zero, L_80136CE8
    if (ctx->r2 == 0) {
        // 0x80136CC0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80136CE8;
    }
    // 0x80136CC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80136CC4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80136CC8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80136CCC: lwc1        $f4, 0x2A4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2A4);
    // 0x80136CD0: lwc1        $f6, 0x2A8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2A8);
    // 0x80136CD4: lbu         $t6, 0xF48($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF48);
    // 0x80136CD8: swc1        $f4, 0x29C($v0)
    MEM_W(0X29C, ctx->r2) = ctx->f4.u32l;
    // 0x80136CDC: swc1        $f6, 0x2A0($v0)
    MEM_W(0X2A0, ctx->r2) = ctx->f6.u32l;
    // 0x80136CE0: b           L_80136D6C
    // 0x80136CE4: sb          $t6, 0xF35($v0)
    MEM_B(0XF35, ctx->r2) = ctx->r14;
        goto L_80136D6C;
    // 0x80136CE4: sb          $t6, 0xF35($v0)
    MEM_B(0XF35, ctx->r2) = ctx->r14;
L_80136CE8:
    // 0x80136CE8: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x80136CEC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80136CF0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80136CF4: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80136CF8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80136CFC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136D00: srl         $t0, $t8, 16
    ctx->r8 = S32(U32(ctx->r24) >> 16);
    // 0x80136D04: sb          $t0, 0xF35($v0)
    MEM_B(0XF35, ctx->r2) = ctx->r8;
    // 0x80136D08: lw          $t1, 0x38($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X38);
    // 0x80136D0C: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80136D10: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80136D14: bgez        $t2, L_80136D28
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80136D18: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80136D28;
    }
    // 0x80136D18: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80136D1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80136D20: nop

    // 0x80136D24: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80136D28:
    // 0x80136D28: swc1        $f10, 0x29C($v0)
    MEM_W(0X29C, ctx->r2) = ctx->f10.u32l;
    // 0x80136D2C: lw          $t3, 0x38($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X38);
    // 0x80136D30: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80136D34: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x80136D38: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80136D3C: bgez        $t4, L_80136D50
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80136D40: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80136D50;
    }
    // 0x80136D40: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80136D44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136D48: nop

    // 0x80136D4C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80136D50:
    // 0x80136D50: lhu         $t5, 0x110($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X110);
    // 0x80136D54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80136D58: swc1        $f4, 0x2A0($v0)
    MEM_W(0X2A0, ctx->r2) = ctx->f4.u32l;
    // 0x80136D5C: bnel        $t5, $at, L_80136D70
    if (ctx->r13 != ctx->r1) {
        // 0x80136D60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80136D70;
    }
    goto skip_0;
    // 0x80136D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80136D64: jal         0x800058DC
    // 0x80136D68: addiu       $a1, $a1, 0x6D7C
    ctx->r5 = ADD32(ctx->r5, 0X6D7C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80136D68: addiu       $a1, $a1, 0x6D7C
    ctx->r5 = ADD32(ctx->r5, 0X6D7C);
    after_1:
L_80136D6C:
    // 0x80136D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136D70:
    // 0x80136D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136D74: jr          $ra
    // 0x80136D78: nop

    return;
    // 0x80136D78: nop

;}
RECOMP_FUNC void M7_FUN_80136d7c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136D7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136D84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80136D88: jal         0x80150584
    // 0x80136D8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80150584)(rdram, ctx);
        goto after_0;
    // 0x80136D8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80136D90: beq         $v0, $zero, L_80136DB4
    if (ctx->r2 == 0) {
        // 0x80136D94: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80136DB4;
    }
    // 0x80136D94: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80136D98: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80136D9C: lwc1        $f4, 0x2A4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2A4);
    // 0x80136DA0: lwc1        $f6, 0x2A8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2A8);
    // 0x80136DA4: lbu         $t6, 0xF48($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF48);
    // 0x80136DA8: swc1        $f4, 0x29C($v0)
    MEM_W(0X29C, ctx->r2) = ctx->f4.u32l;
    // 0x80136DAC: swc1        $f6, 0x2A0($v0)
    MEM_W(0X2A0, ctx->r2) = ctx->f6.u32l;
    // 0x80136DB0: sb          $t6, 0xF35($v0)
    MEM_B(0XF35, ctx->r2) = ctx->r14;
L_80136DB4:
    // 0x80136DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136DBC: jr          $ra
    // 0x80136DC0: nop

    return;
    // 0x80136DC0: nop

;}
RECOMP_FUNC void M7_FUN_80136dc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136DC4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80136DC8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x80136DCC: lwc1        $f4, 0x2A4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2A4);
    // 0x80136DD0: lwc1        $f6, 0x2A8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2A8);
    // 0x80136DD4: lbu         $t6, 0xF48($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80136dd8(rdram, ctx);
;}
