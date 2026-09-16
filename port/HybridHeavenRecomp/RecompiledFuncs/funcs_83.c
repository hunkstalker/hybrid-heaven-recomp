#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M8_FUN_801dabdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DABDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DABE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DABE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DABE8: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801DABEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DABF0: bnel        $t6, $at, L_801DAC14
    if (ctx->r14 != ctx->r1) {
        // 0x801DABF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801DAC14;
    }
    goto skip_0;
    // 0x801DABF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801DABF8: jal         0x80133980
    // 0x801DABFC: addiu       $a0, $zero, 0x287
    ctx->r4 = ADD32(0, 0X287);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x801DABFC: addiu       $a0, $zero, 0x287
    ctx->r4 = ADD32(0, 0X287);
    after_0:
    // 0x801DAC00: jal         0x80020718
    // 0x801DAC04: addiu       $a0, $zero, 0x649
    ctx->r4 = ADD32(0, 0X649);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_1;
    // 0x801DAC04: addiu       $a0, $zero, 0x649
    ctx->r4 = ADD32(0, 0X649);
    after_1:
    // 0x801DAC08: jal         0x80020718
    // 0x801DAC0C: addiu       $a0, $zero, 0x6C0
    ctx->r4 = ADD32(0, 0X6C0);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_2;
    // 0x801DAC0C: addiu       $a0, $zero, 0x6C0
    ctx->r4 = ADD32(0, 0X6C0);
    after_2:
    // 0x801DAC10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DAC14:
    // 0x801DAC14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DAC18: jr          $ra
    // 0x801DAC1C: nop

    return;
    // 0x801DAC1C: nop

;}
RECOMP_FUNC void M8_FUN_801dac20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAC20: nop

    // 0x801DAC24: nop

    // 0x801DAC28: nop

    // 0x801DAC2C: nop

;}
RECOMP_FUNC void M8_FUN_801dac30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAC30: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DAC34: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801DAC38: lhu         $t6, 0x104($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X104);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801dac3c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801dac3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAC3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801DAC40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801DAC44: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801DAC48: sb          $t6, 0x35($a0)
    MEM_B(0X35, ctx->r4) = ctx->r14;
    // 0x801DAC4C: lhu         $t7, 0x104($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X104);
    // 0x801DAC50: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801DAC54: addiu       $t9, $t9, -0x537C
    ctx->r25 = ADD32(ctx->r25, -0X537C);
    // 0x801DAC58: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801DAC5C: sh          $t8, 0x104($v0)
    MEM_H(0X104, ctx->r2) = ctx->r24;
    // 0x801DAC60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801DAC64: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x801DAC68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801DAC6C: jal         0x8013B570
    // 0x801DAC70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801DAC70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x801DAC74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801DAC78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801DAC7C: jr          $ra
    // 0x801DAC80: nop

    return;
    // 0x801DAC80: nop

;}
RECOMP_FUNC void M8_FUN_801dac84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAC84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DAC88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DAC8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801DAC90: lw          $a3, 0x5C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X5C);
    // 0x801DAC94: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x801DAC98: addiu       $a1, $zero, 0x330
    ctx->r5 = ADD32(0, 0X330);
    // 0x801DAC9C: lhu         $t7, 0xC($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0XC);
    // 0x801DACA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801DACA4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DACA8: blez        $t7, L_801DAE50
    if (SIGNED(ctx->r15) <= 0) {
        // 0x801DACAC: addiu       $t0, $zero, 0x320
        ctx->r8 = ADD32(0, 0X320);
            goto L_801DAE50;
    }
    // 0x801DACAC: addiu       $t0, $zero, 0x320
    ctx->r8 = ADD32(0, 0X320);
    // 0x801DACB0: lwc1        $f18, 0x3B24($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3B24);
    // 0x801DACB4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DACB8: lwc1        $f16, 0x3B28($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3B28);
    // 0x801DACBC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DACC0: lwc1        $f14, 0x3B2C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X3B2C);
    // 0x801DACC4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DACC8: lwc1        $f12, 0x3B30($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X3B30);
    // 0x801DACCC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DACD0: lwc1        $f2, 0x3B34($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X3B34);
    // 0x801DACD4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801DACD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801DACDC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x801DACE0: sltiu       $at, $a2, 0x11
    ctx->r1 = ctx->r6 < 0X11 ? 1 : 0;
L_801DACE4:
    // 0x801DACE4: beq         $at, $zero, L_801DADD8
    if (ctx->r1 == 0) {
        // 0x801DACE8: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_801DADD8;
    }
    // 0x801DACE8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x801DACEC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x801DACF0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DACF4: addu        $at, $at, $t8
    gpr jr_addend_801DACFC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801DACF8: lw          $t8, 0x3B38($at)
    ctx->r24 = ADD32(ctx->r1, 0X3B38);
    // 0x801DACFC: jr          $t8
    // 0x801DAD00: nop

    switch (jr_addend_801DACFC >> 2) {
        case 0: goto L_801DAD04; break;
        case 1: goto L_801DAD14; break;
        case 2: goto L_801DAD2C; break;
        case 3: goto L_801DAD44; break;
        case 4: goto L_801DAD5C; break;
        case 5: goto L_801DAD74; break;
        case 6: goto L_801DAD8C; break;
        case 7: goto L_801DAD9C; break;
        case 8: goto L_801DAD74; break;
        case 9: goto L_801DAD8C; break;
        case 10: goto L_801DAD9C; break;
        case 11: goto L_801DADAC; break;
        case 12: goto L_801DADBC; break;
        case 13: goto L_801DADCC; break;
        case 14: goto L_801DADAC; break;
        case 15: goto L_801DADBC; break;
        case 16: goto L_801DADCC; break;
        default: switch_error(__func__, 0x801DACFC, 0x801E3B38);
    }
    // 0x801DAD00: nop

L_801DAD04:
    // 0x801DAD04: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801DAD08: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x801DAD0C: b           L_801DADD8
    // 0x801DAD10: swc1        $f0, 0x70($t1)
    MEM_W(0X70, ctx->r9) = ctx->f0.u32l;
        goto L_801DADD8;
    // 0x801DAD10: swc1        $f0, 0x70($t1)
    MEM_W(0X70, ctx->r9) = ctx->f0.u32l;
L_801DAD14:
    // 0x801DAD14: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801DAD18: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DAD1C: lwc1        $f4, 0x3B7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3B7C);
    // 0x801DAD20: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801DAD24: b           L_801DADD8
    // 0x801DAD28: swc1        $f4, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f4.u32l;
        goto L_801DADD8;
    // 0x801DAD28: swc1        $f4, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f4.u32l;
L_801DAD2C:
    // 0x801DAD2C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801DAD30: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DAD34: lwc1        $f6, 0x3B80($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X3B80);
    // 0x801DAD38: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801DAD3C: b           L_801DADD8
    // 0x801DAD40: swc1        $f6, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->f6.u32l;
        goto L_801DADD8;
    // 0x801DAD40: swc1        $f6, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->f6.u32l;
L_801DAD44:
    // 0x801DAD44: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801DAD48: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DAD4C: lwc1        $f8, 0x3B84($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3B84);
    // 0x801DAD50: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801DAD54: b           L_801DADD8
    // 0x801DAD58: swc1        $f8, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->f8.u32l;
        goto L_801DADD8;
    // 0x801DAD58: swc1        $f8, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->f8.u32l;
L_801DAD5C:
    // 0x801DAD5C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801DAD60: lui         $at, 0x4118
    ctx->r1 = S32(0X4118 << 16);
    // 0x801DAD64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DAD68: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801DAD6C: b           L_801DADD8
    // 0x801DAD70: swc1        $f10, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f10.u32l;
        goto L_801DADD8;
    // 0x801DAD70: swc1        $f10, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f10.u32l;
L_801DAD74:
    // 0x801DAD74: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801DAD78: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DAD7C: lwc1        $f4, 0x3B88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3B88);
    // 0x801DAD80: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801DAD84: b           L_801DADD8
    // 0x801DAD88: swc1        $f4, 0x70($t2)
    MEM_W(0X70, ctx->r10) = ctx->f4.u32l;
        goto L_801DADD8;
    // 0x801DAD88: swc1        $f4, 0x70($t2)
    MEM_W(0X70, ctx->r10) = ctx->f4.u32l;
L_801DAD8C:
    // 0x801DAD8C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801DAD90: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801DAD94: b           L_801DADD8
    // 0x801DAD98: swc1        $f18, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->f18.u32l;
        goto L_801DADD8;
    // 0x801DAD98: swc1        $f18, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->f18.u32l;
L_801DAD9C:
    // 0x801DAD9C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801DADA0: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801DADA4: b           L_801DADD8
    // 0x801DADA8: swc1        $f16, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f16.u32l;
        goto L_801DADD8;
    // 0x801DADA8: swc1        $f16, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f16.u32l;
L_801DADAC:
    // 0x801DADAC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801DADB0: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801DADB4: b           L_801DADD8
    // 0x801DADB8: swc1        $f14, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f14.u32l;
        goto L_801DADD8;
    // 0x801DADB8: swc1        $f14, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f14.u32l;
L_801DADBC:
    // 0x801DADBC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801DADC0: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x801DADC4: b           L_801DADD8
    // 0x801DADC8: swc1        $f12, 0x70($t1)
    MEM_W(0X70, ctx->r9) = ctx->f12.u32l;
        goto L_801DADD8;
    // 0x801DADC8: swc1        $f12, 0x70($t1)
    MEM_W(0X70, ctx->r9) = ctx->f12.u32l;
L_801DADCC:
    // 0x801DADCC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801DADD0: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801DADD4: swc1        $f2, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f2.u32l;
L_801DADD8:
    // 0x801DADD8: sltiu       $at, $v0, 0x11
    ctx->r1 = ctx->r2 < 0X11 ? 1 : 0;
    // 0x801DADDC: beq         $at, $zero, L_801DAE24
    if (ctx->r1 == 0) {
        // 0x801DADE0: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_801DAE24;
    }
    // 0x801DADE0: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x801DADE4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DADE8: addu        $at, $at, $t4
    gpr jr_addend_801DADF0 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801DADEC: lw          $t4, 0x3B8C($at)
    ctx->r12 = ADD32(ctx->r1, 0X3B8C);
    // 0x801DADF0: jr          $t4
    // 0x801DADF4: nop

    switch (jr_addend_801DADF0 >> 2) {
        case 0: goto L_801DADF8; break;
        case 1: goto L_801DAE08; break;
        case 2: goto L_801DAE08; break;
        case 3: goto L_801DAE08; break;
        case 4: goto L_801DAE08; break;
        case 5: goto L_801DAE18; break;
        case 6: goto L_801DAE18; break;
        case 7: goto L_801DAE08; break;
        case 8: goto L_801DAE18; break;
        case 9: goto L_801DAE18; break;
        case 10: goto L_801DAE08; break;
        case 11: goto L_801DAE18; break;
        case 12: goto L_801DAE18; break;
        case 13: goto L_801DAE08; break;
        case 14: goto L_801DAE18; break;
        case 15: goto L_801DAE18; break;
        case 16: goto L_801DAE08; break;
        default: switch_error(__func__, 0x801DADF0, 0x801E3B8C);
    }
    // 0x801DADF4: nop

L_801DADF8:
    // 0x801DADF8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801DADFC: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801DAE00: b           L_801DAE24
    // 0x801DAE04: sh          $a0, 0x6C($t6)
    MEM_H(0X6C, ctx->r14) = ctx->r4;
        goto L_801DAE24;
    // 0x801DAE04: sh          $a0, 0x6C($t6)
    MEM_H(0X6C, ctx->r14) = ctx->r4;
L_801DAE08:
    // 0x801DAE08: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801DAE0C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801DAE10: b           L_801DAE24
    // 0x801DAE14: sh          $a1, 0x6C($t8)
    MEM_H(0X6C, ctx->r24) = ctx->r5;
        goto L_801DAE24;
    // 0x801DAE14: sh          $a1, 0x6C($t8)
    MEM_H(0X6C, ctx->r24) = ctx->r5;
L_801DAE18:
    // 0x801DAE18: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801DAE1C: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x801DAE20: sh          $t0, 0x6C($t1)
    MEM_H(0X6C, ctx->r9) = ctx->r8;
L_801DAE24:
    // 0x801DAE24: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801DAE28: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x801DAE2C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801DAE30: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x801DAE34: lhu         $t3, 0x6C($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X6C);
    // 0x801DAE38: ori         $t4, $t3, 0x2
    ctx->r12 = ctx->r11 | 0X2;
    // 0x801DAE3C: sh          $t4, 0x6C($v0)
    MEM_H(0X6C, ctx->r2) = ctx->r12;
    // 0x801DAE40: lhu         $t5, 0xC($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0XC);
    // 0x801DAE44: slt         $at, $a2, $t5
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801DAE48: bnel        $at, $zero, L_801DACE4
    if (ctx->r1 != 0) {
        // 0x801DAE4C: sltiu       $at, $a2, 0x11
        ctx->r1 = ctx->r6 < 0X11 ? 1 : 0;
            goto L_801DACE4;
    }
    goto skip_0;
    // 0x801DAE4C: sltiu       $at, $a2, 0x11
    ctx->r1 = ctx->r6 < 0X11 ? 1 : 0;
    skip_0:
L_801DAE50:
    // 0x801DAE50: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801DAE54: addiu       $a1, $a1, -0x5190
    ctx->r5 = ADD32(ctx->r5, -0X5190);
    // 0x801DAE58: jal         0x800058DC
    // 0x801DAE5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801DAE5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x801DAE60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DAE64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DAE68: jr          $ra
    // 0x801DAE6C: nop

    return;
    // 0x801DAE6C: nop

;}
RECOMP_FUNC void M8_FUN_801dae70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAE70: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DAE74: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DAE78: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801DAE7C: sb          $zero, 0x4A90($at)
    MEM_B(0X4A90, ctx->r1) = 0;
    // 0x801DAE80: lw          $t6, 0xE0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801dae84(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801dae84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAE84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DAE88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DAE8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DAE90: lwc1        $f4, 0x198($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X198);
    // 0x801DAE94: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801DAE98: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801DAE9C: addiu       $a1, $a1, -0x5118
    ctx->r5 = ADD32(ctx->r5, -0X5118);
    // 0x801DAEA0: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801DAEA4: lw          $t8, 0xE0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE0);
    // 0x801DAEA8: lwc1        $f6, 0x19C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X19C);
    // 0x801DAEAC: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801DAEB0: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x801DAEB4: lw          $t0, 0xE0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE0);
    // 0x801DAEB8: lwc1        $f8, 0x1A0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1A0);
    // 0x801DAEBC: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801DAEC0: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x801DAEC4: lw          $t3, 0xE0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XE0);
    // 0x801DAEC8: lh          $t2, 0x32($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X32);
    // 0x801DAECC: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801DAED0: jal         0x800058DC
    // 0x801DAED4: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801DAED4: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    after_0:
    // 0x801DAED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DAEDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DAEE0: jr          $ra
    // 0x801DAEE4: nop

    return;
    // 0x801DAEE4: nop

;}
RECOMP_FUNC void M8_FUN_801daee8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DAEE8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801DAEEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801DAEF0: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801DAEF4: addiu       $s0, $s0, -0x4410
    ctx->r16 = ADD32(ctx->r16, -0X4410);
    // 0x801DAEF8: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801DAEFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801DAF00: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801DAF04: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801DAF08: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801DAF0C: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801DAF10: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801DAF14: jal         0x80108634
    // 0x801DAF18: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    LOOKUP_FUNC(0x80108634)(rdram, ctx);
        goto after_0;
    // 0x801DAF18: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    after_0:
    // 0x801DAF1C: beql        $v0, $zero, L_801DAF58
    if (ctx->r2 == 0) {
        // 0x801DAF20: lw          $t3, 0xE0($s0)
        ctx->r11 = MEM_W(ctx->r16, 0XE0);
            goto L_801DAF58;
    }
    goto skip_0;
    // 0x801DAF20: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
    skip_0:
    // 0x801DAF24: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x801DAF28: lwc1        $f4, 0x374($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X374);
    // 0x801DAF2C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801DAF30: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x801DAF34: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x801DAF38: lwc1        $f6, 0x378($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X378);
    // 0x801DAF3C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801DAF40: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x801DAF44: lw          $t1, 0xE0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE0);
    // 0x801DAF48: lwc1        $f8, 0x37C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X37C);
    // 0x801DAF4C: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801DAF50: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x801DAF54: lw          $t3, 0xE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XE0);
L_801DAF58:
    // 0x801DAF58: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801DAF5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DAF60: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801DAF64: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801DAF68: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801DAF6C: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801DAF70: sub.s       $f16, $f14, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x801DAF74: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801DAF78: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x801DAF7C: lw          $t4, 0xE0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE0);
    // 0x801DAF80: lw          $v0, 0x2C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X2C);
    // 0x801DAF84: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801DAF88: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x801DAF8C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801DAF90: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801DAF94: jal         0x8010843C
    // 0x801DAF98: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_1;
    // 0x801DAF98: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801DAF9C: beq         $v0, $zero, L_801DAFD4
    if (ctx->r2 == 0) {
        // 0x801DAFA0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_801DAFD4;
    }
    // 0x801DAFA0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801DAFA4: lw          $t5, 0xE0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE0);
    // 0x801DAFA8: lwc1        $f6, 0x374($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X374);
    // 0x801DAFAC: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801DAFB0: swc1        $f6, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f6.u32l;
    // 0x801DAFB4: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x801DAFB8: lwc1        $f8, 0x378($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X378);
    // 0x801DAFBC: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801DAFC0: swc1        $f8, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f8.u32l;
    // 0x801DAFC4: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x801DAFC8: lwc1        $f10, 0x37C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X37C);
    // 0x801DAFCC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801DAFD0: swc1        $f10, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f10.u32l;
L_801DAFD4:
    // 0x801DAFD4: lw          $v1, 0xE0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XE0);
    // 0x801DAFD8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801DAFDC: addiu       $a0, $a0, -0x6D50
    ctx->r4 = ADD32(ctx->r4, -0X6D50);
    // 0x801DAFE0: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x801DAFE4: lhu         $t1, 0x1CE($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X1CE);
    // 0x801DAFE8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801DAFEC: andi        $t2, $t1, 0xF00
    ctx->r10 = ctx->r9 & 0XF00;
    // 0x801DAFF0: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x801DAFF4: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801DAFF8: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x801DAFFC: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801DB000: beq         $t2, $zero, L_801DB0B8
    if (ctx->r10 == 0) {
        // 0x801DB004: sb          $zero, 0x230($s0)
        MEM_B(0X230, ctx->r16) = 0;
            goto L_801DB0B8;
    }
    // 0x801DB004: sb          $zero, 0x230($s0)
    MEM_B(0X230, ctx->r16) = 0;
    // 0x801DB008: lh          $t5, 0x1CA($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X1CA);
    // 0x801DB00C: lh          $t4, 0x1CC($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X1CC);
    // 0x801DB010: sb          $t3, 0x230($s0)
    MEM_B(0X230, ctx->r16) = ctx->r11;
    // 0x801DB014: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x801DB018: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x801DB01C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x801DB020: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x801DB024: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801DB028: jal         0x8001EF38
    // 0x801DB02C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x801DB02C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_2:
    // 0x801DB030: lhu         $v1, 0x232($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X232);
    // 0x801DB034: lw          $t4, 0xE0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XE0);
    // 0x801DB038: addiu       $t9, $v0, -0x800
    ctx->r25 = ADD32(ctx->r2, -0X800);
    // 0x801DB03C: addu        $v1, $t9, $v1
    ctx->r3 = ADD32(ctx->r25, ctx->r3);
    // 0x801DB040: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801DB044: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x801DB048: addiu       $t0, $zero, 0x800
    ctx->r8 = ADD32(0, 0X800);
    // 0x801DB04C: subu        $t2, $t0, $v1
    ctx->r10 = SUB32(ctx->r8, ctx->r3);
    // 0x801DB050: andi        $t3, $t2, 0x1FFF
    ctx->r11 = ctx->r10 & 0X1FFF;
    // 0x801DB054: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x801DB058: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801DB05C: sh          $t3, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r11;
    // 0x801DB060: jal         0x8001EB64
    // 0x801DB064: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x801DB064: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_3:
    // 0x801DB068: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801DB06C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DB070: lw          $t6, 0xE0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XE0);
    // 0x801DB074: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801DB078: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801DB07C: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801DB080: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801DB084: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801DB088: jal         0x8001EAD0
    // 0x801DB08C: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x801DB08C: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    after_4:
    // 0x801DB090: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801DB094: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DB098: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x801DB09C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801DB0A0: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801DB0A4: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801DB0A8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801DB0AC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801DB0B0: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x801DB0B4: lw          $v1, 0xE0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XE0);
L_801DB0B8:
    // 0x801DB0B8: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x801DB0BC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801DB0C0: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801DB0C4: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801DB0C8: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x801DB0CC: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801DB0D0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801DB0D4: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801DB0D8: jal         0x8010843C
    // 0x801DB0DC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8010843C)(rdram, ctx);
        goto after_5;
    // 0x801DB0DC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x801DB0E0: beql        $v0, $zero, L_801DB180
    if (ctx->r2 == 0) {
        // 0x801DB0E4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801DB180;
    }
    goto skip_1;
    // 0x801DB0E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801DB0E8: lw          $t8, 0xE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XE0);
    // 0x801DB0EC: lwc1        $f6, 0x374($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X374);
    // 0x801DB0F0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801DB0F4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801DB0F8: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x801DB0FC: lw          $t0, 0xE0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XE0);
    // 0x801DB100: lwc1        $f4, 0x378($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X378);
    // 0x801DB104: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801DB108: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    // 0x801DB10C: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801DB110: lwc1        $f10, 0x37C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X37C);
    // 0x801DB114: lw          $t4, 0x2C($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X2C);
    // 0x801DB118: swc1        $f10, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f10.u32l;
    // 0x801DB11C: lbu         $v0, 0x35A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35A);
    // 0x801DB120: beq         $v0, $at, L_801DB134
    if (ctx->r2 == ctx->r1) {
        // 0x801DB124: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801DB134;
    }
    // 0x801DB124: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801DB128: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801DB12C: bnel        $v1, $at, L_801DB180
    if (ctx->r3 != ctx->r1) {
        // 0x801DB130: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801DB180;
    }
    goto skip_2;
    // 0x801DB130: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
L_801DB134:
    // 0x801DB134: lw          $t3, 0x38C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38C);
    // 0x801DB138: sb          $v0, 0x90($t3)
    MEM_B(0X90, ctx->r11) = ctx->r2;
    // 0x801DB13C: lw          $t5, 0xE0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XE0);
    // 0x801DB140: lwc1        $f8, 0x198($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X198);
    // 0x801DB144: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801DB148: swc1        $f8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f8.u32l;
    // 0x801DB14C: lw          $t7, 0xE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XE0);
    // 0x801DB150: lwc1        $f16, 0x19C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X19C);
    // 0x801DB154: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801DB158: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x801DB15C: lw          $t9, 0xE0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XE0);
    // 0x801DB160: lwc1        $f18, 0x1A0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1A0);
    // 0x801DB164: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801DB168: swc1        $f18, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f18.u32l;
    // 0x801DB16C: lw          $t2, 0xE0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XE0);
    // 0x801DB170: lh          $t1, 0x32($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X32);
    // 0x801DB174: lw          $t4, 0x2C($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X2C);
    // 0x801DB178: sh          $t1, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r9;
    // 0x801DB17C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801DB180:
    // 0x801DB180: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801DB184: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801DB188: jr          $ra
    // 0x801DB18C: nop

    return;
    // 0x801DB18C: nop

;}
RECOMP_FUNC void M8_FUN_801db190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DB190: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801DB194: addiu       $a0, $a0, -0x6D50
    ctx->r4 = ADD32(ctx->r4, -0X6D50);
    // 0x801DB198: lhu         $v1, 0x1C8($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X1C8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801db19c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801db19c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DB19C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801DB1A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801DB1A4: andi        $t6, $v1, 0x800
    ctx->r14 = ctx->r3 & 0X800;
    // 0x801DB1A8: beq         $t6, $zero, L_801DB1C4
    if (ctx->r14 == 0) {
        // 0x801DB1AC: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_801DB1C4;
    }
    // 0x801DB1AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801DB1B0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801DB1B4: addiu       $v0, $v0, 0x4A90
    ctx->r2 = ADD32(ctx->r2, 0X4A90);
    // 0x801DB1B8: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x801DB1BC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801DB1C0: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
L_801DB1C4:
    // 0x801DB1C4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801DB1C8: andi        $t9, $v1, 0x400
    ctx->r25 = ctx->r3 & 0X400;
    // 0x801DB1CC: beq         $t9, $zero, L_801DB1E0
    if (ctx->r25 == 0) {
        // 0x801DB1D0: addiu       $v0, $v0, 0x4A90
        ctx->r2 = ADD32(ctx->r2, 0X4A90);
            goto L_801DB1E0;
    }
    // 0x801DB1D0: addiu       $v0, $v0, 0x4A90
    ctx->r2 = ADD32(ctx->r2, 0X4A90);
    // 0x801DB1D4: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x801DB1D8: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x801DB1DC: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
L_801DB1E0:
    // 0x801DB1E0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x801DB1E4: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801DB1E8: bgtz        $v1, L_801DB1F8
    if (SIGNED(ctx->r3) > 0) {
        // 0x801DB1EC: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_801DB1F8;
    }
    // 0x801DB1EC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801DB1F0: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x801DB1F4: andi        $v1, $t2, 0xFF
    ctx->r3 = ctx->r10 & 0XFF;
L_801DB1F8:
    // 0x801DB1F8: lw          $t3, -0x43C0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X43C0);
    // 0x801DB1FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801DB200: blez        $v1, L_801DB224
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801DB204: lw          $s0, 0x8($t3)
        ctx->r16 = MEM_W(ctx->r11, 0X8);
            goto L_801DB224;
    }
    // 0x801DB204: lw          $s0, 0x8($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X8);
    // 0x801DB208: beq         $s0, $zero, L_801DB224
    if (ctx->r16 == 0) {
        // 0x801DB20C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_801DB224;
    }
    // 0x801DB20C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_801DB210:
    // 0x801DB210: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801DB214: beq         $at, $zero, L_801DB224
    if (ctx->r1 == 0) {
        // 0x801DB218: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_801DB224;
    }
    // 0x801DB218: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x801DB21C: bnel        $s0, $zero, L_801DB210
    if (ctx->r16 != 0) {
        // 0x801DB220: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_801DB210;
    }
    goto skip_0;
    // 0x801DB220: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
L_801DB224:
    // 0x801DB224: lhu         $v1, 0x1C6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X1C6);
    // 0x801DB228: andi        $t4, $v1, 0x100
    ctx->r12 = ctx->r3 & 0X100;
    // 0x801DB22C: beql        $t4, $zero, L_801DB254
    if (ctx->r12 == 0) {
        // 0x801DB230: andi        $t8, $v1, 0x200
        ctx->r24 = ctx->r3 & 0X200;
            goto L_801DB254;
    }
    goto skip_1;
    // 0x801DB230: andi        $t8, $v1, 0x200
    ctx->r24 = ctx->r3 & 0X200;
    skip_1:
    // 0x801DB234: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x801DB238: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801DB23C: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x801DB240: lh          $t6, 0x12($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X12);
    // 0x801DB244: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801DB248: sh          $t7, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r15;
    // 0x801DB24C: lhu         $v1, -0x6B8A($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6B8A);
    // 0x801DB250: andi        $t8, $v1, 0x200
    ctx->r24 = ctx->r3 & 0X200;
L_801DB254:
    // 0x801DB254: beql        $t8, $zero, L_801DB27C
    if (ctx->r24 == 0) {
        // 0x801DB258: andi        $t2, $v1, 0x1
        ctx->r10 = ctx->r3 & 0X1;
            goto L_801DB27C;
    }
    goto skip_2;
    // 0x801DB258: andi        $t2, $v1, 0x1
    ctx->r10 = ctx->r3 & 0X1;
    skip_2:
    // 0x801DB25C: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801DB260: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801DB264: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801DB268: lh          $t0, 0x12($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X12);
    // 0x801DB26C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x801DB270: sh          $t1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r9;
    // 0x801DB274: lhu         $v1, -0x6B8A($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6B8A);
    // 0x801DB278: andi        $t2, $v1, 0x1
    ctx->r10 = ctx->r3 & 0X1;
L_801DB27C:
    // 0x801DB27C: beql        $t2, $zero, L_801DB2D8
    if (ctx->r10 == 0) {
        // 0x801DB280: andi        $t9, $v1, 0x2
        ctx->r25 = ctx->r3 & 0X2;
            goto L_801DB2D8;
    }
    goto skip_3;
    // 0x801DB280: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
    skip_3:
    // 0x801DB284: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801DB288: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801DB28C: jal         0x8001EAD0
    // 0x801DB290: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x801DB290: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_0:
    // 0x801DB294: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x801DB298: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x801DB29C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801DB2A0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x801DB2A4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x801DB2A8: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801DB2AC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801DB2B0: jal         0x8001EB64
    // 0x801DB2B4: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x801DB2B4: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_1:
    // 0x801DB2B8: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801DB2BC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801DB2C0: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801DB2C4: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801DB2C8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x801DB2CC: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x801DB2D0: lhu         $v1, -0x6B8A($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6B8A);
    // 0x801DB2D4: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
L_801DB2D8:
    // 0x801DB2D8: beql        $t9, $zero, L_801DB334
    if (ctx->r25 == 0) {
        // 0x801DB2DC: andi        $t6, $v1, 0x8
        ctx->r14 = ctx->r3 & 0X8;
            goto L_801DB334;
    }
    goto skip_4;
    // 0x801DB2DC: andi        $t6, $v1, 0x8
    ctx->r14 = ctx->r3 & 0X8;
    skip_4:
    // 0x801DB2E0: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801DB2E4: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801DB2E8: jal         0x8001EAD0
    // 0x801DB2EC: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x801DB2EC: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_2:
    // 0x801DB2F0: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801DB2F4: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x801DB2F8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801DB2FC: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x801DB300: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x801DB304: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801DB308: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801DB30C: jal         0x8001EB64
    // 0x801DB310: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x801DB310: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_3:
    // 0x801DB314: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x801DB318: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801DB31C: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x801DB320: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801DB324: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x801DB328: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x801DB32C: lhu         $v1, -0x6B8A($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6B8A);
    // 0x801DB330: andi        $t6, $v1, 0x8
    ctx->r14 = ctx->r3 & 0X8;
L_801DB334:
    // 0x801DB334: beql        $t6, $zero, L_801DB390
    if (ctx->r14 == 0) {
        // 0x801DB338: andi        $t3, $v1, 0x4
        ctx->r11 = ctx->r3 & 0X4;
            goto L_801DB390;
    }
    goto skip_5;
    // 0x801DB338: andi        $t3, $v1, 0x4
    ctx->r11 = ctx->r3 & 0X4;
    skip_5:
    // 0x801DB33C: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801DB340: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801DB344: jal         0x8001EAD0
    // 0x801DB348: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_4;
    // 0x801DB348: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_4:
    // 0x801DB34C: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801DB350: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801DB354: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801DB358: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801DB35C: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x801DB360: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801DB364: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801DB368: jal         0x8001EB64
    // 0x801DB36C: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_5;
    // 0x801DB36C: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_5:
    // 0x801DB370: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x801DB374: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801DB378: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x801DB37C: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801DB380: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x801DB384: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x801DB388: lhu         $v1, -0x6B8A($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6B8A);
    // 0x801DB38C: andi        $t3, $v1, 0x4
    ctx->r11 = ctx->r3 & 0X4;
L_801DB390:
    // 0x801DB390: beql        $t3, $zero, L_801DB3E4
    if (ctx->r11 == 0) {
        // 0x801DB394: lw          $t0, 0x24($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X24);
            goto L_801DB3E4;
    }
    goto skip_6;
    // 0x801DB394: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    skip_6:
    // 0x801DB398: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801DB39C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801DB3A0: jal         0x8001EAD0
    // 0x801DB3A4: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_6;
    // 0x801DB3A4: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_6:
    // 0x801DB3A8: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801DB3AC: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x801DB3B0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801DB3B4: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x801DB3B8: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x801DB3BC: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801DB3C0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801DB3C4: jal         0x8001EB64
    // 0x801DB3C8: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_7;
    // 0x801DB3C8: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_7:
    // 0x801DB3CC: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801DB3D0: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801DB3D4: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801DB3D8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x801DB3DC: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x801DB3E0: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
L_801DB3E4:
    // 0x801DB3E4: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801DB3E8: addiu       $a3, $a3, 0x3B00
    ctx->r7 = ADD32(ctx->r7, 0X3B00);
    // 0x801DB3EC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801DB3F0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801DB3F4: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801DB3F8: lh          $t2, 0x12($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X12);
    // 0x801DB3FC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801DB400: jal         0x8001B204
    // 0x801DB404: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_8;
    // 0x801DB404: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_8:
    // 0x801DB408: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x801DB40C: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801DB410: addiu       $a3, $a3, 0x3B0C
    ctx->r7 = ADD32(ctx->r7, 0X3B0C);
    // 0x801DB414: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801DB418: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x801DB41C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801DB420: lwc1        $f16, 0x4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X4);
    // 0x801DB424: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    // 0x801DB428: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801DB42C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x801DB430: jal         0x8001B204
    // 0x801DB434: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_9;
    // 0x801DB434: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_9:
    // 0x801DB438: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801DB43C: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801DB440: addiu       $a3, $a3, 0x3B18
    ctx->r7 = ADD32(ctx->r7, 0X3B18);
    // 0x801DB444: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801DB448: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x801DB44C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801DB450: lwc1        $f4, 0xC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC);
    // 0x801DB454: addiu       $a2, $zero, 0x74
    ctx->r6 = ADD32(0, 0X74);
    // 0x801DB458: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801DB45C: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x801DB460: jal         0x8001B204
    // 0x801DB464: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_10;
    // 0x801DB464: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_10:
    // 0x801DB468: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801DB46C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801DB470: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801DB474: jr          $ra
    // 0x801DB478: nop

    return;
    // 0x801DB478: nop

;}
RECOMP_FUNC void M8_FUN_801db47c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DB47C: nop

;}
RECOMP_FUNC void M8_FUN_801db480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DB480: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801DB484: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801DB488: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801DB48C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801DB490: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801DB494: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x801DB498: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x801DB49C: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    // 0x801DB4A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801DB4A4: lhu         $v0, 0x80($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X80);
    // 0x801DB4A8: lw          $s1, 0x7C($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X7C);
    // 0x801DB4AC: bne         $v0, $at, L_801DB540
    if (ctx->r2 != ctx->r1) {
        // 0x801DB4B0: lw          $t0, 0x8($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X8);
            goto L_801DB540;
    }
    // 0x801DB4B0: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x801DB4B4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801DB4B8: addiu       $v1, $s0, 0x1C
    ctx->r3 = ADD32(ctx->r16, 0X1C);
    // 0x801DB4BC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801DB4C0: lhu         $a0, 0xC($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XC);
    // 0x801DB4C4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x801DB4C8: jal         0x80011590
    // 0x801DB4CC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_0;
    // 0x801DB4CC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x801DB4D0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x801DB4D4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x801DB4D8: lui         $t4, 0xE3
    ctx->r12 = S32(0XE3 << 16);
    // 0x801DB4DC: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x801DB4E0: lhu         $t7, 0x4($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X4);
    // 0x801DB4E4: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x801DB4E8: lbu         $t8, 0x5F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X5F);
    // 0x801DB4EC: xori        $t1, $t7, 0x10
    ctx->r9 = ctx->r15 ^ 0X10;
    // 0x801DB4F0: beql        $t8, $zero, L_801DB500
    if (ctx->r24 == 0) {
        // 0x801DB4F4: lwc1        $f4, 0x58($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
            goto L_801DB500;
    }
    goto skip_0;
    // 0x801DB4F4: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    skip_0:
    // 0x801DB4F8: sh          $t1, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r9;
    // 0x801DB4FC: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
L_801DB500:
    // 0x801DB500: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801DB504: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x801DB508: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x801DB50C: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x801DB510: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x801DB514: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801DB518: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x801DB51C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801DB520: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x801DB524: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x801DB528: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801DB52C: jal         0x8013A1B4
    // 0x801DB530: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A1B4)(rdram, ctx);
        goto after_1;
    // 0x801DB530: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x801DB534: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x801DB538: sh          $zero, 0x80($s0)
    MEM_H(0X80, ctx->r16) = 0;
    // 0x801DB53C: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
L_801DB540:
    // 0x801DB540: bne         $v0, $zero, L_801DB598
    if (ctx->r2 != 0) {
        // 0x801DB544: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801DB598;
    }
    // 0x801DB544: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801DB548: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x801DB54C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DB550: jal         0x80010550
    // 0x801DB554: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_2;
    // 0x801DB554: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_2:
    // 0x801DB558: beq         $v0, $zero, L_801DB6A0
    if (ctx->r2 == 0) {
        // 0x801DB55C: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_801DB6A0;
    }
    // 0x801DB55C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x801DB560: bnel        $t0, $zero, L_801DB574
    if (ctx->r8 != 0) {
        // 0x801DB564: lhu         $t5, 0x6($s1)
        ctx->r13 = MEM_HU(ctx->r17, 0X6);
            goto L_801DB574;
    }
    goto skip_1;
    // 0x801DB564: lhu         $t5, 0x6($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X6);
    skip_1:
    // 0x801DB568: b           L_801DB6A4
    // 0x801DB56C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801DB6A4;
    // 0x801DB56C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801DB570: lhu         $t5, 0x6($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X6);
L_801DB574:
    // 0x801DB574: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801DB578: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801DB57C: beql        $t5, $zero, L_801DB590
    if (ctx->r13 == 0) {
        // 0x801DB580: sw          $t0, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r8;
            goto L_801DB590;
    }
    goto skip_2;
    // 0x801DB580: sw          $t0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r8;
    skip_2:
    // 0x801DB584: b           L_801DB6A0
    // 0x801DB588: sh          $t6, 0x80($s0)
    MEM_H(0X80, ctx->r16) = ctx->r14;
        goto L_801DB6A0;
    // 0x801DB588: sh          $t6, 0x80($s0)
    MEM_H(0X80, ctx->r16) = ctx->r14;
    // 0x801DB58C: sw          $t0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r8;
L_801DB590:
    // 0x801DB590: b           L_801DB6A0
    // 0x801DB594: sh          $t7, 0x80($s0)
    MEM_H(0X80, ctx->r16) = ctx->r15;
        goto L_801DB6A0;
    // 0x801DB594: sh          $t7, 0x80($s0)
    MEM_H(0X80, ctx->r16) = ctx->r15;
L_801DB598:
    // 0x801DB598: bnel        $v0, $at, L_801DB620
    if (ctx->r2 != ctx->r1) {
        // 0x801DB59C: lw          $t8, 0x0($t0)
        ctx->r24 = MEM_W(ctx->r8, 0X0);
            goto L_801DB620;
    }
    goto skip_3;
    // 0x801DB59C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    skip_3:
    // 0x801DB5A0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801DB5A4: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801DB5A8: jal         0x80011590
    // 0x801DB5AC: lhu         $a0, 0xC($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XC);
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_3;
    // 0x801DB5AC: lhu         $a0, 0xC($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XC);
    after_3:
    // 0x801DB5B0: lbu         $t1, 0x5F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X5F);
    // 0x801DB5B4: sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    // 0x801DB5B8: lhu         $t9, 0x4($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X4);
    // 0x801DB5BC: beq         $t1, $zero, L_801DB5CC
    if (ctx->r9 == 0) {
        // 0x801DB5C0: sh          $t9, 0x42($sp)
        MEM_H(0X42, ctx->r29) = ctx->r25;
            goto L_801DB5CC;
    }
    // 0x801DB5C0: sh          $t9, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r25;
    // 0x801DB5C4: xori        $t3, $t9, 0x10
    ctx->r11 = ctx->r25 ^ 0X10;
    // 0x801DB5C8: sh          $t3, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r11;
L_801DB5CC:
    // 0x801DB5CC: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801DB5D0: addiu       $t4, $sp, 0x3C
    ctx->r12 = ADD32(ctx->r29, 0X3C);
    // 0x801DB5D4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x801DB5D8: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x801DB5DC: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x801DB5E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DB5E4: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x801DB5E8: lw          $a3, 0x4($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X4);
    // 0x801DB5EC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801DB5F0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801DB5F4: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x801DB5F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801DB5FC: lhu         $t7, 0x82($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X82);
    // 0x801DB600: jal         0x80011140
    // 0x801DB604: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801DB604: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_4:
    // 0x801DB608: beql        $v0, $zero, L_801DB6A4
    if (ctx->r2 == 0) {
        // 0x801DB60C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801DB6A4;
    }
    goto skip_4;
    // 0x801DB60C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x801DB610: sw          $s1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r17;
    // 0x801DB614: b           L_801DB6A0
    // 0x801DB618: sh          $zero, 0x80($s0)
    MEM_H(0X80, ctx->r16) = 0;
        goto L_801DB6A0;
    // 0x801DB618: sh          $zero, 0x80($s0)
    MEM_H(0X80, ctx->r16) = 0;
    // 0x801DB61C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
L_801DB620:
    // 0x801DB620: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801DB624: lhu         $a0, 0xC($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0XC);
    // 0x801DB628: jal         0x80011590
    // 0x801DB62C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_5;
    // 0x801DB62C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_5:
    // 0x801DB630: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x801DB634: lbu         $t1, 0x5F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X5F);
    // 0x801DB638: sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    // 0x801DB63C: lhu         $t9, 0x4($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X4);
    // 0x801DB640: beq         $t1, $zero, L_801DB650
    if (ctx->r9 == 0) {
        // 0x801DB644: sh          $t9, 0x42($sp)
        MEM_H(0X42, ctx->r29) = ctx->r25;
            goto L_801DB650;
    }
    // 0x801DB644: sh          $t9, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r25;
    // 0x801DB648: xori        $t3, $t9, 0x10
    ctx->r11 = ctx->r25 ^ 0X10;
    // 0x801DB64C: sh          $t3, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r11;
L_801DB650:
    // 0x801DB650: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801DB654: addiu       $t4, $sp, 0x3C
    ctx->r12 = ADD32(ctx->r29, 0X3C);
    // 0x801DB658: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x801DB65C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x801DB660: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x801DB664: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DB668: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x801DB66C: lw          $a3, 0x4($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X4);
    // 0x801DB670: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801DB674: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801DB678: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x801DB67C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801DB680: lhu         $t7, 0x6($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X6);
    // 0x801DB684: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x801DB688: jal         0x80011140
    // 0x801DB68C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_6;
    // 0x801DB68C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_6:
    // 0x801DB690: beq         $v0, $zero, L_801DB6A0
    if (ctx->r2 == 0) {
        // 0x801DB694: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_801DB6A0;
    }
    // 0x801DB694: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x801DB698: sw          $t0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r8;
    // 0x801DB69C: sh          $zero, 0x80($s0)
    MEM_H(0X80, ctx->r16) = 0;
L_801DB6A0:
    // 0x801DB6A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801DB6A4:
    // 0x801DB6A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801DB6A8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801DB6AC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801DB6B0: jr          $ra
    // 0x801DB6B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801DB6B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801db6b8(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801db6b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DB6B8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801DB6BC: lw          $t6, -0x4334($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4334);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801db6c0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801db6c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DB6C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DB6C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801DB6C8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801DB6CC: bne         $a0, $t6, L_801DB6E0
    if (ctx->r4 != ctx->r14) {
        // 0x801DB6D0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801DB6E0;
    }
    // 0x801DB6D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DB6D4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DB6D8: b           L_801DB6E8
    // 0x801DB6DC: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_801DB6E8;
    // 0x801DB6DC: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_801DB6E0:
    // 0x801DB6E0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DB6E4: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
L_801DB6E8:
    // 0x801DB6E8: beq         $a2, $zero, L_801DB700
    if (ctx->r6 == 0) {
        // 0x801DB6EC: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_801DB700;
    }
    // 0x801DB6EC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801DB6F0: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801DB6F4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801DB6F8: b           L_801DB710
    // 0x801DB6FC: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
        goto L_801DB710;
    // 0x801DB6FC: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_801DB700:
    // 0x801DB700: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801DB704: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801DB708: nop

    // 0x801DB70C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_801DB710:
    // 0x801DB710: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x801DB714: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801DB718: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801DB71C: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x801DB720: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x801DB724: bne         $t9, $at, L_801DB734
    if (ctx->r25 != ctx->r1) {
        // 0x801DB728: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_801DB734;
    }
    // 0x801DB728: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801DB72C: b           L_801DB734
    // 0x801DB730: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_801DB734;
    // 0x801DB730: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_801DB734:
    // 0x801DB734: jal         0x801DB480
    // 0x801DB738: nop

    LOOKUP_FUNC(0x801DB480)(rdram, ctx);
        goto after_0;
    // 0x801DB738: nop

    after_0:
    // 0x801DB73C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DB740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DB744: jr          $ra
    // 0x801DB748: nop

    return;
    // 0x801DB748: nop

;}
RECOMP_FUNC void M8_FUN_801db74c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DB74C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801DB750: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x801DB754: nop

    // 0x801DB758: bc1fl       L_801DB76C
    if (!c1cs) {
        // 0x801DB75C: lwc1        $f6, 0x0($a2)
        ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
            goto L_801DB76C;
    }
    goto skip_0;
    // 0x801DB75C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x801DB760: jr          $ra
    // 0x801DB764: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    return;
    // 0x801DB764: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    // 0x801DB768: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
L_801DB76C:
    // 0x801DB76C: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x801DB770: nop

    // 0x801DB774: bc1f        L_801DB780
    if (!c1cs) {
        // 0x801DB778: nop
    
            goto L_801DB780;
    }
    // 0x801DB778: nop

    // 0x801DB77C: swc1        $f12, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f12.u32l;
L_801DB780:
    // 0x801DB780: jr          $ra
    // 0x801DB784: nop

    return;
    // 0x801DB784: nop

;}
RECOMP_FUNC void M8_FUN_801db788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DB788: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801DB78C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801DB790: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801DB794: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801DB798: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801DB79C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801DB7A0: lwc1        $f6, 0xA4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XA4);
    // 0x801DB7A4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801DB7A8: lwc1        $f10, 0xAC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XAC);
    // 0x801DB7AC: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801DB7B0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DB7B4: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801DB7B8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801DB7BC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801DB7C0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801DB7C4: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x801DB7C8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801DB7CC: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x801DB7D0: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x801DB7D4: addiu       $a2, $a3, 0xBC
    ctx->r6 = ADD32(ctx->r7, 0XBC);
    // 0x801DB7D8: addiu       $a1, $a3, 0xB0
    ctx->r5 = ADD32(ctx->r7, 0XB0);
    // 0x801DB7DC: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x801DB7E0: jal         0x801DB74C
    // 0x801DB7E4: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    LOOKUP_FUNC(0x801DB74C)(rdram, ctx);
        goto after_0;
    // 0x801DB7E4: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x801DB7E8: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801DB7EC: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801DB7F0: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801DB7F4: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x801DB7F8: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801DB7FC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801DB800: addiu       $a1, $s0, 0xB8
    ctx->r5 = ADD32(ctx->r16, 0XB8);
    // 0x801DB804: addiu       $a2, $s0, 0xC4
    ctx->r6 = ADD32(ctx->r16, 0XC4);
    // 0x801DB808: mul.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x801DB80C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801DB810: jal         0x801DB74C
    // 0x801DB814: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    LOOKUP_FUNC(0x801DB74C)(rdram, ctx);
        goto after_1;
    // 0x801DB814: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x801DB818: lbu         $t6, 0x4B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4B);
    // 0x801DB81C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801DB820: addiu       $a1, $s0, 0xCC
    ctx->r5 = ADD32(ctx->r16, 0XCC);
    // 0x801DB824: beql        $t6, $zero, L_801DB858
    if (ctx->r14 == 0) {
        // 0x801DB828: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801DB858;
    }
    goto skip_0;
    // 0x801DB828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801DB82C: jal         0x801DB74C
    // 0x801DB830: addiu       $a2, $s0, 0xD8
    ctx->r6 = ADD32(ctx->r16, 0XD8);
    LOOKUP_FUNC(0x801DB74C)(rdram, ctx);
        goto after_2;
    // 0x801DB830: addiu       $a2, $s0, 0xD8
    ctx->r6 = ADD32(ctx->r16, 0XD8);
    after_2:
    // 0x801DB834: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801DB838: addiu       $a1, $s0, 0xC8
    ctx->r5 = ADD32(ctx->r16, 0XC8);
    // 0x801DB83C: jal         0x801DB74C
    // 0x801DB840: addiu       $a2, $s0, 0xD4
    ctx->r6 = ADD32(ctx->r16, 0XD4);
    LOOKUP_FUNC(0x801DB74C)(rdram, ctx);
        goto after_3;
    // 0x801DB840: addiu       $a2, $s0, 0xD4
    ctx->r6 = ADD32(ctx->r16, 0XD4);
    after_3:
    // 0x801DB844: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801DB848: addiu       $a1, $s0, 0xD0
    ctx->r5 = ADD32(ctx->r16, 0XD0);
    // 0x801DB84C: jal         0x801DB74C
    // 0x801DB850: addiu       $a2, $s0, 0xDC
    ctx->r6 = ADD32(ctx->r16, 0XDC);
    LOOKUP_FUNC(0x801DB74C)(rdram, ctx);
        goto after_4;
    // 0x801DB850: addiu       $a2, $s0, 0xDC
    ctx->r6 = ADD32(ctx->r16, 0XDC);
    after_4:
    // 0x801DB854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801DB858:
    // 0x801DB858: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801DB85C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801DB860: jr          $ra
    // 0x801DB864: nop

    return;
    // 0x801DB864: nop

;}
RECOMP_FUNC void M8_FUN_801db868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DB868: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x801DB86C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801DB870: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801DB874: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801DB878: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801DB87C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801DB880: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801DB884: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x801DB888: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801DB88C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801DB890: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x801DB894: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801DB898: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801DB89C: lh          $v0, 0x12($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X12);
    // 0x801DB8A0: negu        $s0, $v0
    ctx->r16 = SUB32(0, ctx->r2);
    // 0x801DB8A4: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x801DB8A8: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x801DB8AC: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801DB8B0: jal         0x8001EAD0
    // 0x801DB8B4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x801DB8B4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x801DB8B8: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x801DB8BC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801DB8C0: jal         0x8001EB64
    // 0x801DB8C4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x801DB8C4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x801DB8C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DB8CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DB8D0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801DB8D4: addiu       $t8, $s2, 0xB0
    ctx->r24 = ADD32(ctx->r18, 0XB0);
    // 0x801DB8D8: swc1        $f4, 0xB8($s2)
    MEM_W(0XB8, ctx->r18) = ctx->f4.u32l;
    // 0x801DB8DC: swc1        $f6, 0xB4($s2)
    MEM_W(0XB4, ctx->r18) = ctx->f6.u32l;
    // 0x801DB8E0: swc1        $f8, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->f8.u32l;
    // 0x801DB8E4: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x801DB8E8: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x801DB8EC: addiu       $t9, $sp, 0x6C
    ctx->r25 = ADD32(ctx->r29, 0X6C);
    // 0x801DB8F0: addiu       $t3, $s2, 0xBC
    ctx->r11 = ADD32(ctx->r18, 0XBC);
    // 0x801DB8F4: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x801DB8F8: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x801DB8FC: addiu       $t5, $sp, 0x6C
    ctx->r13 = ADD32(ctx->r29, 0X6C);
    // 0x801DB900: addiu       $t4, $sp, 0x78
    ctx->r12 = ADD32(ctx->r29, 0X78);
    // 0x801DB904: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x801DB908: lw          $t2, 0x8($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X8);
    // 0x801DB90C: addiu       $t8, $sp, 0x78
    ctx->r24 = ADD32(ctx->r29, 0X78);
    // 0x801DB910: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801DB914: sw          $t2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r10;
    // 0x801DB918: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x801DB91C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801DB920: addiu       $t2, $s2, 0xC8
    ctx->r10 = ADD32(ctx->r18, 0XC8);
    // 0x801DB924: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x801DB928: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801DB92C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801DB930: addiu       $s1, $s4, 0x1C
    ctx->r17 = ADD32(ctx->r20, 0X1C);
    // 0x801DB934: addiu       $s3, $sp, 0xAC
    ctx->r19 = ADD32(ctx->r29, 0XAC);
    // 0x801DB938: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x801DB93C: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x801DB940: sw          $t7, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r15;
    // 0x801DB944: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801DB948: addiu       $t7, $s2, 0xD4
    ctx->r15 = ADD32(ctx->r18, 0XD4);
    // 0x801DB94C: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x801DB950: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801DB954: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x801DB958: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801DB95C: addiu       $t9, $sp, 0x78
    ctx->r25 = ADD32(ctx->r29, 0X78);
    // 0x801DB960: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x801DB964: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x801DB968: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x801DB96C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x801DB970: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x801DB974: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x801DB978: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x801DB97C: sw          $t6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r14;
    // 0x801DB980: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x801DB984: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801DB988: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x801DB98C: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801DB990: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x801DB994: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801DB998: sw          $t1, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r9;
    // 0x801DB99C: lhu         $v1, 0xC($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0XC);
    // 0x801DB9A0: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x801DB9A4: bnel        $at, $zero, L_801DBB24
    if (ctx->r1 != 0) {
        // 0x801DB9A8: addiu       $s3, $sp, 0xAC
        ctx->r19 = ADD32(ctx->r29, 0XAC);
            goto L_801DBB24;
    }
    goto skip_0;
    // 0x801DB9A8: addiu       $s3, $sp, 0xAC
    ctx->r19 = ADD32(ctx->r29, 0XAC);
    skip_0:
L_801DB9AC:
    // 0x801DB9AC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801DB9B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801DB9B4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x801DB9B8: lbu         $t2, 0x22($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X22);
    // 0x801DB9BC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x801DB9C0: beql        $t2, $zero, L_801DBB14
    if (ctx->r10 == 0) {
        // 0x801DB9C4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801DBB14;
    }
    goto skip_1;
    // 0x801DB9C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x801DB9C8: lw          $t3, 0x1C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1C);
    // 0x801DB9CC: bne         $t3, $zero, L_801DBA90
    if (ctx->r11 != 0) {
        // 0x801DB9D0: nop
    
            goto L_801DBA90;
    }
    // 0x801DB9D0: nop

    // 0x801DB9D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801DB9D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801DB9DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801DB9E0: swc1        $f10, 0xB8($s2)
    MEM_W(0XB8, ctx->r18) = ctx->f10.u32l;
    // 0x801DB9E4: swc1        $f16, 0xB4($s2)
    MEM_W(0XB4, ctx->r18) = ctx->f16.u32l;
    // 0x801DB9E8: swc1        $f18, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->f18.u32l;
    // 0x801DB9EC: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x801DB9F0: addiu       $t4, $sp, 0x6C
    ctx->r12 = ADD32(ctx->r29, 0X6C);
    // 0x801DB9F4: addiu       $t9, $sp, 0x6C
    ctx->r25 = ADD32(ctx->r29, 0X6C);
    // 0x801DB9F8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801DB9FC: addiu       $t3, $sp, 0x6C
    ctx->r11 = ADD32(ctx->r29, 0X6C);
    // 0x801DBA00: addiu       $t2, $sp, 0x78
    ctx->r10 = ADD32(ctx->r29, 0X78);
    // 0x801DBA04: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x801DBA08: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801DBA0C: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x801DBA10: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x801DBA14: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x801DBA18: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801DBA1C: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x801DBA20: addiu       $t7, $sp, 0x78
    ctx->r15 = ADD32(ctx->r29, 0X78);
    // 0x801DBA24: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x801DBA28: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801DBA2C: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x801DBA30: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801DBA34: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x801DBA38: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801DBA3C: addiu       $t1, $sp, 0x78
    ctx->r9 = ADD32(ctx->r29, 0X78);
    // 0x801DBA40: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801DBA44: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801DBA48: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801DBA4C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801DBA50: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
    // 0x801DBA54: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801DBA58: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x801DBA5C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801DBA60: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801DBA64: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801DBA68: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801DBA6C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801DBA70: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801DBA74: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x801DBA78: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x801DBA7C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801DBA80: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x801DBA84: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801DBA88: b           L_801DBE6C
    // 0x801DBA8C: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
        goto L_801DBE6C;
    // 0x801DBA8C: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
L_801DBA90:
    // 0x801DBA90: jal         0x8013A334
    // 0x801DBA94: andi        $a3, $s0, 0xFFFF
    ctx->r7 = ctx->r16 & 0XFFFF;
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_2;
    // 0x801DBA94: andi        $a3, $s0, 0xFFFF
    ctx->r7 = ctx->r16 & 0XFFFF;
    after_2:
    // 0x801DBA98: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801DBA9C: beq         $s0, $at, L_801DBAD4
    if (ctx->r16 == ctx->r1) {
        // 0x801DBAA0: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_801DBAD4;
    }
    // 0x801DBAA0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x801DBAA4: beq         $s0, $at, L_801DBAD4
    if (ctx->r16 == ctx->r1) {
        // 0x801DBAA8: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_801DBAD4;
    }
    // 0x801DBAA8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801DBAAC: beq         $s0, $at, L_801DBAD4
    if (ctx->r16 == ctx->r1) {
        // 0x801DBAB0: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_801DBAD4;
    }
    // 0x801DBAB0: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x801DBAB4: beq         $s0, $at, L_801DBAD4
    if (ctx->r16 == ctx->r1) {
        // 0x801DBAB8: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_801DBAD4;
    }
    // 0x801DBAB8: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x801DBABC: beq         $s0, $at, L_801DBAD4
    if (ctx->r16 == ctx->r1) {
        // 0x801DBAC0: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_801DBAD4;
    }
    // 0x801DBAC0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x801DBAC4: beq         $s0, $at, L_801DBAD4
    if (ctx->r16 == ctx->r1) {
        // 0x801DBAC8: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_801DBAD4;
    }
    // 0x801DBAC8: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x801DBACC: bne         $s0, $at, L_801DBADC
    if (ctx->r16 != ctx->r1) {
        // 0x801DBAD0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801DBADC;
    }
    // 0x801DBAD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801DBAD4:
    // 0x801DBAD4: b           L_801DBADC
    // 0x801DBAD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801DBADC;
    // 0x801DBAD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801DBADC:
    // 0x801DBADC: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x801DBAE0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x801DBAE4: sw          $t5, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r13;
    // 0x801DBAE8: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x801DBAEC: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DBAF0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DBAF4: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x801DBAF8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x801DBAFC: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801DBB00: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801DBB04: jal         0x801DB788
    // 0x801DBB08: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DB788)(rdram, ctx);
        goto after_3;
    // 0x801DBB08: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_3:
    // 0x801DBB0C: lhu         $v1, 0xC($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0XC);
    // 0x801DBB10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801DBB14:
    // 0x801DBB14: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801DBB18: bne         $at, $zero, L_801DB9AC
    if (ctx->r1 != 0) {
        // 0x801DBB1C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_801DB9AC;
    }
    // 0x801DBB1C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801DBB20: addiu       $s3, $sp, 0xAC
    ctx->r19 = ADD32(ctx->r29, 0XAC);
L_801DBB24:
    // 0x801DBB24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801DBB28: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x801DBB2C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x801DBB30: jal         0x8013A334
    // 0x801DBB34: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_4;
    // 0x801DBB34: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    after_4:
    // 0x801DBB38: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x801DBB3C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801DBB40: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x801DBB44: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x801DBB48: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x801DBB4C: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DBB50: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DBB54: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x801DBB58: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801DBB5C: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801DBB60: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801DBB64: jal         0x801DB788
    // 0x801DBB68: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DB788)(rdram, ctx);
        goto after_5;
    // 0x801DBB68: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_5:
    // 0x801DBB6C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801DBB70: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x801DBB74: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x801DBB78: jal         0x8013A334
    // 0x801DBB7C: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_6;
    // 0x801DBB7C: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    after_6:
    // 0x801DBB80: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x801DBB84: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801DBB88: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x801DBB8C: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x801DBB90: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x801DBB94: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DBB98: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DBB9C: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x801DBBA0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801DBBA4: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801DBBA8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801DBBAC: jal         0x801DB788
    // 0x801DBBB0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DB788)(rdram, ctx);
        goto after_7;
    // 0x801DBBB0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_7:
    // 0x801DBBB4: lw          $t2, 0x24($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X24);
    // 0x801DBBB8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x801DBBBC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801DBBC0: lw          $t5, 0xA4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XA4);
    // 0x801DBBC4: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    // 0x801DBBC8: lw          $t4, 0xA8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XA8);
    // 0x801DBBCC: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x801DBBD0: sw          $t4, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r12;
    // 0x801DBBD4: lw          $t5, 0xAC($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XAC);
    // 0x801DBBD8: sw          $t5, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r13;
    // 0x801DBBDC: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x801DBBE0: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x801DBBE4: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DBBE8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DBBEC: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x801DBBF0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801DBBF4: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801DBBF8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801DBBFC: jal         0x801DB788
    // 0x801DBC00: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DB788)(rdram, ctx);
        goto after_8;
    // 0x801DBC00: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_8:
    // 0x801DBC04: lw          $t8, 0x30($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X30);
    // 0x801DBC08: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x801DBC0C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801DBC10: lw          $t1, 0xA4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XA4);
    // 0x801DBC14: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x801DBC18: lw          $t0, 0xA8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XA8);
    // 0x801DBC1C: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x801DBC20: sw          $t0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r8;
    // 0x801DBC24: lw          $t1, 0xAC($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XAC);
    // 0x801DBC28: sw          $t1, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r9;
    // 0x801DBC2C: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
    // 0x801DBC30: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x801DBC34: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DBC38: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DBC3C: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x801DBC40: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801DBC44: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801DBC48: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801DBC4C: jal         0x801DB788
    // 0x801DBC50: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DB788)(rdram, ctx);
        goto after_9;
    // 0x801DBC50: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_9:
    // 0x801DBC54: lw          $t4, 0x3C($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X3C);
    // 0x801DBC58: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x801DBC5C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801DBC60: lw          $t7, 0xA4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XA4);
    // 0x801DBC64: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x801DBC68: lw          $t6, 0xA8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XA8);
    // 0x801DBC6C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x801DBC70: sw          $t6, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r14;
    // 0x801DBC74: lw          $t7, 0xAC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XAC);
    // 0x801DBC78: sw          $t7, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r15;
    // 0x801DBC7C: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x801DBC80: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x801DBC84: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DBC88: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DBC8C: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x801DBC90: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801DBC94: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801DBC98: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801DBC9C: jal         0x801DB788
    // 0x801DBCA0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DB788)(rdram, ctx);
        goto after_10;
    // 0x801DBCA0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_10:
    // 0x801DBCA4: lw          $t0, 0x48($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X48);
    // 0x801DBCA8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x801DBCAC: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801DBCB0: lw          $t3, 0xA4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XA4);
    // 0x801DBCB4: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x801DBCB8: lw          $t2, 0xA8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XA8);
    // 0x801DBCBC: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x801DBCC0: sw          $t2, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r10;
    // 0x801DBCC4: lw          $t3, 0xAC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XAC);
    // 0x801DBCC8: sw          $t3, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r11;
    // 0x801DBCCC: sw          $t5, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r13;
    // 0x801DBCD0: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x801DBCD4: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DBCD8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DBCDC: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x801DBCE0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801DBCE4: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801DBCE8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801DBCEC: jal         0x801DB788
    // 0x801DBCF0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DB788)(rdram, ctx);
        goto after_11;
    // 0x801DBCF0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_11:
    // 0x801DBCF4: lw          $t6, 0x18($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X18);
    // 0x801DBCF8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801DBCFC: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x801DBD00: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801DBD04: lw          $t9, 0xA4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XA4);
    // 0x801DBD08: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x801DBD0C: lw          $t8, 0xA8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XA8);
    // 0x801DBD10: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x801DBD14: sw          $t8, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r24;
    // 0x801DBD18: lw          $t9, 0xAC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XAC);
    // 0x801DBD1C: sw          $t9, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r25;
    // 0x801DBD20: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x801DBD24: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x801DBD28: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DBD2C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DBD30: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x801DBD34: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801DBD38: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801DBD3C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801DBD40: jal         0x801DB788
    // 0x801DBD44: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DB788)(rdram, ctx);
        goto after_12;
    // 0x801DBD44: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_12:
    // 0x801DBD48: lw          $t3, 0x4($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X4);
    // 0x801DBD4C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801DBD50: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x801DBD54: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801DBD58: lw          $t6, 0xA4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XA4);
    // 0x801DBD5C: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x801DBD60: lw          $t5, 0xA8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XA8);
    // 0x801DBD64: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x801DBD68: sw          $t5, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r13;
    // 0x801DBD6C: lw          $t6, 0xAC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XAC);
    // 0x801DBD70: sw          $t6, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r14;
    // 0x801DBD74: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x801DBD78: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x801DBD7C: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DBD80: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DBD84: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x801DBD88: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801DBD8C: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801DBD90: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801DBD94: jal         0x801DB788
    // 0x801DBD98: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DB788)(rdram, ctx);
        goto after_13;
    // 0x801DBD98: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_13:
    // 0x801DBD9C: lhu         $t0, 0xC($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0XC);
    // 0x801DBDA0: slti        $at, $t0, 0x18
    ctx->r1 = SIGNED(ctx->r8) < 0X18 ? 1 : 0;
    // 0x801DBDA4: bne         $at, $zero, L_801DBDFC
    if (ctx->r1 != 0) {
        // 0x801DBDA8: nop
    
            goto L_801DBDFC;
    }
    // 0x801DBDA8: nop

    // 0x801DBDAC: lw          $t1, 0x60($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X60);
    // 0x801DBDB0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x801DBDB4: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801DBDB8: lw          $t4, 0xA4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XA4);
    // 0x801DBDBC: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x801DBDC0: lw          $t3, 0xA8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XA8);
    // 0x801DBDC4: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x801DBDC8: sw          $t3, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r11;
    // 0x801DBDCC: lw          $t4, 0xAC($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XAC);
    // 0x801DBDD0: sw          $t4, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r12;
    // 0x801DBDD4: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x801DBDD8: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x801DBDDC: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DBDE0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DBDE4: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x801DBDE8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801DBDEC: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801DBDF0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801DBDF4: jal         0x801DB788
    // 0x801DBDF8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DB788)(rdram, ctx);
        goto after_14;
    // 0x801DBDF8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_14:
L_801DBDFC:
    // 0x801DBDFC: jal         0x80126944
    // 0x801DBE00: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_15;
    // 0x801DBE00: nop

    after_15:
    // 0x801DBE04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DBE08: bnel        $v0, $at, L_801DBE70
    if (ctx->r2 != ctx->r1) {
        // 0x801DBE0C: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_801DBE70;
    }
    goto skip_2;
    // 0x801DBE0C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_2:
    // 0x801DBE10: lbu         $t7, 0x74($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X74);
    // 0x801DBE14: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801DBE18: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801DBE1C: beq         $t7, $at, L_801DBE6C
    if (ctx->r15 == ctx->r1) {
        // 0x801DBE20: addiu       $v1, $v1, -0x4410
        ctx->r3 = ADD32(ctx->r3, -0X4410);
            goto L_801DBE6C;
    }
    // 0x801DBE20: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801DBE24: lbu         $v0, 0x1031($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1031);
    // 0x801DBE28: blez        $v0, L_801DBE6C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801DBE2C: slti        $at, $v0, 0xE
        ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
            goto L_801DBE6C;
    }
    // 0x801DBE2C: slti        $at, $v0, 0xE
    ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
    // 0x801DBE30: beq         $at, $zero, L_801DBE6C
    if (ctx->r1 == 0) {
        // 0x801DBE34: addiu       $t0, $zero, 0x6
        ctx->r8 = ADD32(0, 0X6);
            goto L_801DBE6C;
    }
    // 0x801DBE34: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x801DBE38: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x801DBE3C: lw          $t9, 0xDC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XDC);
    // 0x801DBE40: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DBE44: lw          $a0, 0x18($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X18);
    // 0x801DBE48: addiu       $v0, $v0, -0x3C28
    ctx->r2 = ADD32(ctx->r2, -0X3C28);
    // 0x801DBE4C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x801DBE50: bne         $a0, $t9, L_801DBE64
    if (ctx->r4 != ctx->r25) {
        // 0x801DBE54: nop
    
            goto L_801DBE64;
    }
    // 0x801DBE54: nop

    // 0x801DBE58: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DBE5C: b           L_801DBE64
    // 0x801DBE60: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
        goto L_801DBE64;
    // 0x801DBE60: addiu       $v0, $v0, -0x3FC4
    ctx->r2 = ADD32(ctx->r2, -0X3FC4);
L_801DBE64:
    // 0x801DBE64: jal         0x802261CC
    // 0x801DBE68: sb          $t0, 0x392($v0)
    MEM_B(0X392, ctx->r2) = ctx->r8;
    LOOKUP_FUNC(0x802261CC)(rdram, ctx);
        goto after_16;
    // 0x801DBE68: sb          $t0, 0x392($v0)
    MEM_B(0X392, ctx->r2) = ctx->r8;
    after_16:
L_801DBE6C:
    // 0x801DBE6C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801DBE70:
    // 0x801DBE70: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801DBE74: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x801DBE78: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801DBE7C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801DBE80: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801DBE84: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801DBE88: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801DBE8C: jr          $ra
    // 0x801DBE90: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x801DBE90: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801dbe94(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801dbe94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DBE94: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DBE98: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801DBE9C: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x801DBEA0: bne         $at, $zero, L_801DBEAC
    if (ctx->r1 != 0) {
        // 0x801DBEA4: lw          $v0, 0x5C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X5C);
            goto L_801DBEAC;
    }
    // 0x801DBEA4: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x801DBEA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_801DBEAC:
    // 0x801DBEAC: lbu         $v1, 0x75($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X75);
    // 0x801DBEB0: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801DBEB4: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x801DBEB8: bnel        $at, $zero, L_801DBECC
    if (ctx->r1 != 0) {
        // 0x801DBEBC: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_801DBECC;
    }
    goto skip_0;
    // 0x801DBEBC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    skip_0:
    // 0x801DBEC0: sb          $zero, 0x75($v0)
    MEM_B(0X75, ctx->r2) = 0;
    // 0x801DBEC4: andi        $v1, $zero, 0xFF
    ctx->r3 = 0 & 0XFF;
    // 0x801DBEC8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
L_801DBECC:
    // 0x801DBECC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DBED0: lw          $t7, 0x15B8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X15B8);
    // 0x801DBED4: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x801DBED8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801DBEDC: jr          $ra
    // 0x801DBEE0: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    return;
    // 0x801DBEE0: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801dbee4(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801dbee4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DBEE4: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x801DBEE8: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x801DBEEC: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x801DBEF0: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x801DBEF4: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x801DBEF8: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x801DBEFC: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x801DBF00: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x801DBF04: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x801DBF08: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x801DBF0C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801DBF10: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x801DBF14: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x801DBF18: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x801DBF1C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x801DBF20: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801DBF24: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801DBF28: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    // 0x801DBF2C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801DBF30: addiu       $t7, $sp, 0xDC
    ctx->r15 = ADD32(ctx->r29, 0XDC);
    // 0x801DBF34: addiu       $s4, $s0, 0xA4
    ctx->r20 = ADD32(ctx->r16, 0XA4);
    // 0x801DBF38: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x801DBF3C: lw          $s3, 0x2C($t6)
    ctx->r19 = MEM_W(ctx->r14, 0X2C);
    // 0x801DBF40: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x801DBF44: lw          $t8, 0x4($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X4);
    // 0x801DBF48: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x801DBF4C: lw          $t9, 0x8($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X8);
    // 0x801DBF50: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x801DBF54: jal         0x8001EAD0
    // 0x801DBF58: lh          $a0, 0x12($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_0;
    // 0x801DBF58: lh          $a0, 0x12($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X12);
    after_0:
    // 0x801DBF5C: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x801DBF60: jal         0x8001EB64
    // 0x801DBF64: lh          $a0, 0x12($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_1;
    // 0x801DBF64: lh          $a0, 0x12($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X12);
    after_1:
    // 0x801DBF68: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x801DBF6C: addiu       $s2, $s2, -0x4410
    ctx->r18 = ADD32(ctx->r18, -0X4410);
    // 0x801DBF70: lbu         $t0, 0x1031($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X1031);
    // 0x801DBF74: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x801DBF78: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x801DBF7C: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x801DBF80: beq         $at, $zero, L_801DBF90
    if (ctx->r1 == 0) {
        // 0x801DBF84: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_801DBF90;
    }
    // 0x801DBF84: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801DBF88: b           L_801DC200
    // 0x801DBF8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801DC200;
    // 0x801DBF8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801DBF90:
    // 0x801DBF90: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801DBF94: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DBF98: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x801DBF9C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801DBFA0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801DBFA4: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x801DBFA8: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x801DBFAC: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x801DBFB0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x801DBFB4: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    // 0x801DBFB8: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
L_801DBFBC:
    // 0x801DBFBC: addiu       $t1, $sp, 0xDC
    ctx->r9 = ADD32(ctx->r29, 0XDC);
    // 0x801DBFC0: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x801DBFC4: lw          $t2, 0x4($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X4);
    // 0x801DBFC8: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x801DBFCC: lw          $t3, 0x8($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X8);
    // 0x801DBFD0: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
    // 0x801DBFD4: lwc1        $f20, 0x4($s3)
    ctx->f20.u32l = MEM_W(ctx->r19, 0X4);
    // 0x801DBFD8: lwc1        $f22, 0x8($s3)
    ctx->f22.u32l = MEM_W(ctx->r19, 0X8);
    // 0x801DBFDC: beq         $s1, $zero, L_801DC004
    if (ctx->r17 == 0) {
        // 0x801DBFE0: lwc1        $f24, 0xC($s3)
        ctx->f24.u32l = MEM_W(ctx->r19, 0XC);
            goto L_801DC004;
    }
    // 0x801DBFE0: lwc1        $f24, 0xC($s3)
    ctx->f24.u32l = MEM_W(ctx->r19, 0XC);
    // 0x801DBFE4: beql        $s1, $s6, L_801DC020
    if (ctx->r17 == ctx->r22) {
        // 0x801DBFE8: lwc1        $f4, 0xC4($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
            goto L_801DC020;
    }
    goto skip_0;
    // 0x801DBFE8: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    skip_0:
    // 0x801DBFEC: beql        $s1, $s7, L_801DC038
    if (ctx->r17 == ctx->r23) {
        // 0x801DBFF0: lwc1        $f10, 0xBC($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0XBC);
            goto L_801DC038;
    }
    goto skip_1;
    // 0x801DBFF0: lwc1        $f10, 0xBC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XBC);
    skip_1:
    // 0x801DBFF4: beql        $s1, $fp, L_801DC050
    if (ctx->r17 == ctx->r30) {
        // 0x801DBFF8: lwc1        $f8, 0xBC($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0XBC);
            goto L_801DC050;
    }
    goto skip_2;
    // 0x801DBFF8: lwc1        $f8, 0xBC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XBC);
    skip_2:
    // 0x801DBFFC: b           L_801DC050
    // 0x801DC000: lwc1        $f8, 0xBC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XBC);
        goto L_801DC050;
    // 0x801DC000: lwc1        $f8, 0xBC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XBC);
L_801DC004:
    // 0x801DC004: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x801DC008: lwc1        $f8, 0xB8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x801DC00C: lwc1        $f0, 0xB0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x801DC010: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801DC014: b           L_801DC060
    // 0x801DC018: div.s       $f2, $f10, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f26.fl);
        goto L_801DC060;
    // 0x801DC018: div.s       $f2, $f10, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f26.fl);
    // 0x801DC01C: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
L_801DC020:
    // 0x801DC020: lwc1        $f6, 0xB8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x801DC024: lwc1        $f0, 0xBC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XBC);
    // 0x801DC028: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801DC02C: b           L_801DC060
    // 0x801DC030: div.s       $f2, $f8, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f26.fl);
        goto L_801DC060;
    // 0x801DC030: div.s       $f2, $f8, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f26.fl);
    // 0x801DC034: lwc1        $f10, 0xBC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XBC);
L_801DC038:
    // 0x801DC038: lwc1        $f4, 0xB0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x801DC03C: lwc1        $f2, 0xB8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x801DC040: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801DC044: b           L_801DC060
    // 0x801DC048: div.s       $f0, $f6, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f26.fl);
        goto L_801DC060;
    // 0x801DC048: div.s       $f0, $f6, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f26.fl);
    // 0x801DC04C: lwc1        $f8, 0xBC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XBC);
L_801DC050:
    // 0x801DC050: lwc1        $f10, 0xB0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x801DC054: lwc1        $f2, 0xC4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x801DC058: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801DC05C: div.s       $f0, $f4, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f26.fl);
L_801DC060:
    // 0x801DC060: mul.s       $f6, $f0, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x801DC064: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801DC068: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x801DC06C: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x801DC070: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x801DC074: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x801DC078: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x801DC07C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x801DC080: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x801DC084: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x801DC088: mul.s       $f10, $f2, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f30.fl);
    // 0x801DC08C: swc1        $f12, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f12.u32l;
    // 0x801DC090: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801DC094: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801DC098: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x801DC09C: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x801DC0A0: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x801DC0A4: add.s       $f24, $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f18.fl;
    // 0x801DC0A8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801DC0AC: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x801DC0B0: add.d       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f28.d); 
    ctx->f10.d = ctx->f8.d + ctx->f28.d;
    // 0x801DC0B4: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x801DC0B8: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x801DC0BC: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x801DC0C0: swc1        $f14, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f14.u32l;
    // 0x801DC0C4: add.d       $f10, $f10, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f28.d); 
    ctx->f10.d = ctx->f10.d + ctx->f28.d;
    // 0x801DC0C8: cvt.s.d     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f22.fl = CVT_S_D(ctx->f10.d);
    // 0x801DC0CC: jal         0x80108480
    // 0x801DC0D0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    LOOKUP_FUNC(0x80108480)(rdram, ctx);
        goto after_2;
    // 0x801DC0D0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_2:
    // 0x801DC0D4: beq         $v0, $zero, L_801DC15C
    if (ctx->r2 == 0) {
        // 0x801DC0D8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_801DC15C;
    }
    // 0x801DC0D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801DC0DC: lwc1        $f10, 0x380($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X380);
    // 0x801DC0E0: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x801DC0E4: lwc1        $f8, 0x384($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X384);
    // 0x801DC0E8: lwc1        $f4, 0xE0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x801DC0EC: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x801DC0F0: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x801DC0F4: lwc1        $f10, 0x388($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X388);
    // 0x801DC0F8: sub.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x801DC0FC: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801DC100: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x801DC104: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x801DC108: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801DC10C: swc1        $f2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f2.u32l;
    // 0x801DC110: swc1        $f0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f0.u32l;
    // 0x801DC114: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x801DC118: swc1        $f12, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f12.u32l;
    // 0x801DC11C: addiu       $t5, $sp, 0xB8
    ctx->r13 = ADD32(ctx->r29, 0XB8);
    // 0x801DC120: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801DC124: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x801DC128: add.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801DC12C: c.lt.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl < ctx->f14.fl;
    // 0x801DC130: swc1        $f14, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f14.u32l;
    // 0x801DC134: bc1fl       L_801DC160
    if (!c1cs) {
        // 0x801DC138: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801DC160;
    }
    goto skip_3;
    // 0x801DC138: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_3:
    // 0x801DC13C: swc1        $f14, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f14.u32l;
    // 0x801DC140: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801DC144: addiu       $t4, $sp, 0xC4
    ctx->r12 = ADD32(ctx->r29, 0XC4);
    // 0x801DC148: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x801DC14C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801DC150: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x801DC154: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x801DC158: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
L_801DC15C:
    // 0x801DC15C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_801DC160:
    // 0x801DC160: bnel        $s1, $at, L_801DBFBC
    if (ctx->r17 != ctx->r1) {
        // 0x801DC164: lw          $t3, 0x0($s4)
        ctx->r11 = MEM_W(ctx->r20, 0X0);
            goto L_801DBFBC;
    }
    goto skip_4;
    // 0x801DC164: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    skip_4:
    // 0x801DC168: bne         $s5, $zero, L_801DC178
    if (ctx->r21 != 0) {
        // 0x801DC16C: nop
    
            goto L_801DC178;
    }
    // 0x801DC16C: nop

    // 0x801DC170: b           L_801DC200
    // 0x801DC174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801DC200;
    // 0x801DC174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801DC178:
    // 0x801DC178: jal         0x8002FC20
    // 0x801DC17C: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_3;
    // 0x801DC17C: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    after_3:
    // 0x801DC180: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801DC184: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x801DC188: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801DC18C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801DC190: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x801DC194: c.le.d      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.d <= ctx->f12.d;
    // 0x801DC198: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DC19C: bc1f        L_801DC1A8
    if (!c1cs) {
        // 0x801DC1A0: nop
    
            goto L_801DC1A8;
    }
    // 0x801DC1A0: nop

    // 0x801DC1A4: lwc1        $f2, 0x3D10($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X3D10);
L_801DC1A8:
    // 0x801DC1A8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DC1AC: ldc1        $f10, 0x3D18($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X3D18);
    // 0x801DC1B0: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x801DC1B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801DC1B8: div.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f6.d);
    // 0x801DC1BC: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801DC1C0: lwc1        $f10, 0xA4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x801DC1C4: sub.d       $f4, $f12, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f12.d - ctx->f8.d;
    // 0x801DC1C8: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x801DC1CC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801DC1D0: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801DC1D4: swc1        $f4, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f4.u32l;
    // 0x801DC1D8: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801DC1DC: lwc1        $f6, 0xA8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x801DC1E0: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801DC1E4: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801DC1E8: swc1        $f4, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f4.u32l;
    // 0x801DC1EC: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x801DC1F0: lwc1        $f10, 0xAC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x801DC1F4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801DC1F8: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801DC1FC: swc1        $f4, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f4.u32l;
L_801DC200:
    // 0x801DC200: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x801DC204: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801DC208: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801DC20C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x801DC210: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x801DC214: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x801DC218: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x801DC21C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801DC220: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x801DC224: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x801DC228: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x801DC22C: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x801DC230: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x801DC234: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x801DC238: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x801DC23C: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x801DC240: jr          $ra
    // 0x801DC244: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x801DC244: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801dc248(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801dc248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DC248: nop

    // 0x801DC24C: nop

;}
RECOMP_FUNC void M8_FUN_801dc250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DC250: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801DC254: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801DC258: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801DC25C: addiu       $s0, $v0, 0x17C0
    ctx->r16 = ADD32(ctx->r2, 0X17C0);
    // 0x801DC260: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801DC264: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801DC268: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801DC26C: lhu         $a1, 0x4($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X4);
    // 0x801DC270: beq         $t6, $zero, L_801DC4F8
    if (ctx->r14 == 0) {
        // 0x801DC274: lwc1        $f0, 0x8($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
            goto L_801DC4F8;
    }
    // 0x801DC274: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801DC278: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801DC27C: addiu       $t7, $t7, 0x17C0
    ctx->r15 = ADD32(ctx->r15, 0X17C0);
    // 0x801DC280: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
L_801DC284:
    // 0x801DC284: bnel        $v1, $v0, L_801DC4EC
    if (ctx->r3 != ctx->r2) {
        // 0x801DC288: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_801DC4EC;
    }
    goto skip_0;
    // 0x801DC288: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x801DC28C: lbu         $t8, 0x4($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X4);
    // 0x801DC290: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DC294: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801DC298: bgez        $t8, L_801DC2AC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801DC29C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801DC2AC;
    }
    // 0x801DC29C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801DC2A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DC2A4: nop

    // 0x801DC2A8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801DC2AC:
    // 0x801DC2AC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801DC2B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC2B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DC2B8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801DC2BC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC2C0: nop

    // 0x801DC2C4: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DC2C8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC2CC: nop

    // 0x801DC2D0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC2D4: beql        $a0, $zero, L_801DC324
    if (ctx->r4 == 0) {
        // 0x801DC2D8: mfc1        $a0, $f16
        ctx->r4 = (int32_t)ctx->f16.u32l;
            goto L_801DC324;
    }
    goto skip_1;
    // 0x801DC2D8: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x801DC2DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801DC2E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC2E4: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801DC2E8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC2EC: nop

    // 0x801DC2F0: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801DC2F4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC2F8: nop

    // 0x801DC2FC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC300: bne         $a0, $zero, L_801DC318
    if (ctx->r4 != 0) {
        // 0x801DC304: nop
    
            goto L_801DC318;
    }
    // 0x801DC304: nop

    // 0x801DC308: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x801DC30C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DC310: b           L_801DC330
    // 0x801DC314: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DC330;
    // 0x801DC314: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DC318:
    // 0x801DC318: b           L_801DC330
    // 0x801DC31C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DC330;
    // 0x801DC31C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DC320: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
L_801DC324:
    // 0x801DC324: nop

    // 0x801DC328: bltz        $a0, L_801DC318
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DC32C: nop
    
            goto L_801DC318;
    }
    // 0x801DC32C: nop

L_801DC330:
    // 0x801DC330: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801DC334: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DC338: sh          $a1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r5;
    // 0x801DC33C: jal         0x80011590
    // 0x801DC340: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_0;
    // 0x801DC340: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x801DC344: lhu         $v1, 0x2E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2E);
    // 0x801DC348: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801DC34C: beq         $v1, $v0, L_801DC4D8
    if (ctx->r3 == ctx->r2) {
        // 0x801DC350: nop
    
            goto L_801DC4D8;
    }
    // 0x801DC350: nop

    // 0x801DC354: lbu         $t0, 0x5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X5);
    // 0x801DC358: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DC35C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x801DC360: bgez        $t0, L_801DC374
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801DC364: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801DC374;
    }
    // 0x801DC364: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801DC368: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DC36C: nop

    // 0x801DC370: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_801DC374:
    // 0x801DC374: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801DC378: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC37C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DC380: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801DC384: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC388: nop

    // 0x801DC38C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DC390: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC394: nop

    // 0x801DC398: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC39C: beql        $a0, $zero, L_801DC3EC
    if (ctx->r4 == 0) {
        // 0x801DC3A0: mfc1        $a0, $f16
        ctx->r4 = (int32_t)ctx->f16.u32l;
            goto L_801DC3EC;
    }
    goto skip_2;
    // 0x801DC3A0: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x801DC3A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801DC3A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC3AC: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801DC3B0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC3B4: nop

    // 0x801DC3B8: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801DC3BC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC3C0: nop

    // 0x801DC3C4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC3C8: bne         $a0, $zero, L_801DC3E0
    if (ctx->r4 != 0) {
        // 0x801DC3CC: nop
    
            goto L_801DC3E0;
    }
    // 0x801DC3CC: nop

    // 0x801DC3D0: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x801DC3D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DC3D8: b           L_801DC3F8
    // 0x801DC3DC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DC3F8;
    // 0x801DC3DC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DC3E0:
    // 0x801DC3E0: b           L_801DC3F8
    // 0x801DC3E4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DC3F8;
    // 0x801DC3E4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DC3E8: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
L_801DC3EC:
    // 0x801DC3EC: nop

    // 0x801DC3F0: bltz        $a0, L_801DC3E0
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DC3F4: nop
    
            goto L_801DC3E0;
    }
    // 0x801DC3F4: nop

L_801DC3F8:
    // 0x801DC3F8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801DC3FC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DC400: jal         0x80011590
    // 0x801DC404: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_1;
    // 0x801DC404: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x801DC408: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801DC40C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801DC410: beq         $v1, $v0, L_801DC4D8
    if (ctx->r3 == ctx->r2) {
        // 0x801DC414: nop
    
            goto L_801DC4D8;
    }
    // 0x801DC414: nop

    // 0x801DC418: lbu         $t2, 0x6($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X6);
    // 0x801DC41C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DC420: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x801DC424: bgez        $t2, L_801DC438
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801DC428: cvt.s.w     $f8, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801DC438;
    }
    // 0x801DC428: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801DC42C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DC430: nop

    // 0x801DC434: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_801DC438:
    // 0x801DC438: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801DC43C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC440: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DC444: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801DC448: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC44C: nop

    // 0x801DC450: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DC454: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC458: nop

    // 0x801DC45C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC460: beql        $a0, $zero, L_801DC4B0
    if (ctx->r4 == 0) {
        // 0x801DC464: mfc1        $a0, $f16
        ctx->r4 = (int32_t)ctx->f16.u32l;
            goto L_801DC4B0;
    }
    goto skip_3;
    // 0x801DC464: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x801DC468: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801DC46C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC470: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801DC474: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC478: nop

    // 0x801DC47C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801DC480: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC484: nop

    // 0x801DC488: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC48C: bne         $a0, $zero, L_801DC4A4
    if (ctx->r4 != 0) {
        // 0x801DC490: nop
    
            goto L_801DC4A4;
    }
    // 0x801DC490: nop

    // 0x801DC494: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x801DC498: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DC49C: b           L_801DC4BC
    // 0x801DC4A0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DC4BC;
    // 0x801DC4A0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DC4A4:
    // 0x801DC4A4: b           L_801DC4BC
    // 0x801DC4A8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DC4BC;
    // 0x801DC4A8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DC4AC: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
L_801DC4B0:
    // 0x801DC4B0: nop

    // 0x801DC4B4: bltz        $a0, L_801DC4A4
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DC4B8: nop
    
            goto L_801DC4A4;
    }
    // 0x801DC4B8: nop

L_801DC4BC:
    // 0x801DC4BC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801DC4C0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DC4C4: jal         0x80011590
    // 0x801DC4C8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_2;
    // 0x801DC4C8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x801DC4CC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801DC4D0: bne         $v1, $v0, L_801DC4E0
    if (ctx->r3 != ctx->r2) {
        // 0x801DC4D4: nop
    
            goto L_801DC4E0;
    }
    // 0x801DC4D4: nop

L_801DC4D8:
    // 0x801DC4D8: b           L_801DC4FC
    // 0x801DC4DC: lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7);
        goto L_801DC4FC;
    // 0x801DC4DC: lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7);
L_801DC4E0:
    // 0x801DC4E0: b           L_801DC4FC
    // 0x801DC4E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801DC4FC;
    // 0x801DC4E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801DC4E8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_801DC4EC:
    // 0x801DC4EC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801DC4F0: bne         $v0, $zero, L_801DC284
    if (ctx->r2 != 0) {
        // 0x801DC4F4: nop
    
            goto L_801DC284;
    }
    // 0x801DC4F4: nop

L_801DC4F8:
    // 0x801DC4F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801DC4FC:
    // 0x801DC4FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801DC500: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801DC504: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801DC508: jr          $ra
    // 0x801DC50C: nop

    return;
    // 0x801DC50C: nop

;}
RECOMP_FUNC void M8_FUN_801dc510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DC510: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801DC514: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DC518: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801DC51C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801DC520: lhu         $a2, 0x4($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X4);
    // 0x801DC524: beq         $v0, $zero, L_801DC6EC
    if (ctx->r2 == 0) {
        // 0x801DC528: lwc1        $f0, 0x8($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
            goto L_801DC6EC;
    }
    // 0x801DC528: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
L_801DC52C:
    // 0x801DC52C: bnel        $v1, $v0, L_801DC6E0
    if (ctx->r3 != ctx->r2) {
        // 0x801DC530: lw          $v0, 0xC($a1)
        ctx->r2 = MEM_W(ctx->r5, 0XC);
            goto L_801DC6E0;
    }
    goto skip_0;
    // 0x801DC530: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    skip_0:
    // 0x801DC534: lhu         $t6, 0x4($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X4);
    // 0x801DC538: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DC53C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801DC540: bgez        $t6, L_801DC554
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801DC544: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801DC554;
    }
    // 0x801DC544: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801DC548: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DC54C: nop

    // 0x801DC550: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801DC554:
    // 0x801DC554: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801DC558: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC55C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DC560: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801DC564: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC568: nop

    // 0x801DC56C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DC570: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC574: nop

    // 0x801DC578: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC57C: beql        $a0, $zero, L_801DC5CC
    if (ctx->r4 == 0) {
        // 0x801DC580: mfc1        $a0, $f16
        ctx->r4 = (int32_t)ctx->f16.u32l;
            goto L_801DC5CC;
    }
    goto skip_1;
    // 0x801DC580: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x801DC584: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801DC588: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC58C: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801DC590: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC594: nop

    // 0x801DC598: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801DC59C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC5A0: nop

    // 0x801DC5A4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC5A8: bne         $a0, $zero, L_801DC5C0
    if (ctx->r4 != 0) {
        // 0x801DC5AC: nop
    
            goto L_801DC5C0;
    }
    // 0x801DC5AC: nop

    // 0x801DC5B0: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x801DC5B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DC5B8: b           L_801DC5D8
    // 0x801DC5BC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DC5D8;
    // 0x801DC5BC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DC5C0:
    // 0x801DC5C0: b           L_801DC5D8
    // 0x801DC5C4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DC5D8;
    // 0x801DC5C4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DC5C8: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
L_801DC5CC:
    // 0x801DC5CC: nop

    // 0x801DC5D0: bltz        $a0, L_801DC5C0
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DC5D4: nop
    
            goto L_801DC5C0;
    }
    // 0x801DC5D4: nop

L_801DC5D8:
    // 0x801DC5D8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801DC5DC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DC5E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801DC5E4: sh          $a2, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r6;
    // 0x801DC5E8: jal         0x80011590
    // 0x801DC5EC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_0;
    // 0x801DC5EC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x801DC5F0: lhu         $v1, 0x22($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X22);
    // 0x801DC5F4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801DC5F8: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801DC5FC: beq         $v1, $v0, L_801DC6CC
    if (ctx->r3 == ctx->r2) {
        // 0x801DC600: nop
    
            goto L_801DC6CC;
    }
    // 0x801DC600: nop

    // 0x801DC604: lhu         $t8, 0x6($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6);
    // 0x801DC608: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DC60C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x801DC610: bgez        $t8, L_801DC624
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801DC614: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801DC624;
    }
    // 0x801DC614: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801DC618: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DC61C: nop

    // 0x801DC620: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_801DC624:
    // 0x801DC624: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801DC628: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC62C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DC630: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801DC634: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC638: nop

    // 0x801DC63C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DC640: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC644: nop

    // 0x801DC648: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC64C: beql        $a0, $zero, L_801DC69C
    if (ctx->r4 == 0) {
        // 0x801DC650: mfc1        $a0, $f10
        ctx->r4 = (int32_t)ctx->f10.u32l;
            goto L_801DC69C;
    }
    goto skip_2;
    // 0x801DC650: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    skip_2:
    // 0x801DC654: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DC658: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC65C: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801DC660: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC664: nop

    // 0x801DC668: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DC66C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC670: nop

    // 0x801DC674: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC678: bne         $a0, $zero, L_801DC690
    if (ctx->r4 != 0) {
        // 0x801DC67C: nop
    
            goto L_801DC690;
    }
    // 0x801DC67C: nop

    // 0x801DC680: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x801DC684: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DC688: b           L_801DC6A8
    // 0x801DC68C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DC6A8;
    // 0x801DC68C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DC690:
    // 0x801DC690: b           L_801DC6A8
    // 0x801DC694: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DC6A8;
    // 0x801DC694: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DC698: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
L_801DC69C:
    // 0x801DC69C: nop

    // 0x801DC6A0: bltz        $a0, L_801DC690
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DC6A4: nop
    
            goto L_801DC690;
    }
    // 0x801DC6A4: nop

L_801DC6A8:
    // 0x801DC6A8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801DC6AC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DC6B0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x801DC6B4: jal         0x80011590
    // 0x801DC6B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_1;
    // 0x801DC6B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x801DC6BC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801DC6C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801DC6C4: bne         $v1, $v0, L_801DC6D4
    if (ctx->r3 != ctx->r2) {
        // 0x801DC6C8: nop
    
            goto L_801DC6D4;
    }
    // 0x801DC6C8: nop

L_801DC6CC:
    // 0x801DC6CC: b           L_801DC6F0
    // 0x801DC6D0: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
        goto L_801DC6F0;
    // 0x801DC6D0: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
L_801DC6D4:
    // 0x801DC6D4: b           L_801DC6F0
    // 0x801DC6D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801DC6F0;
    // 0x801DC6D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801DC6DC: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
L_801DC6E0:
    // 0x801DC6E0: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x801DC6E4: bne         $v0, $zero, L_801DC52C
    if (ctx->r2 != 0) {
        // 0x801DC6E8: nop
    
            goto L_801DC52C;
    }
    // 0x801DC6E8: nop

L_801DC6EC:
    // 0x801DC6EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801DC6F0:
    // 0x801DC6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DC6F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801DC6F8: jr          $ra
    // 0x801DC6FC: nop

    return;
    // 0x801DC6FC: nop

;}
RECOMP_FUNC void M8_FUN_801dc700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DC700: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801DC704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DC708: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801DC70C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801DC710: lhu         $a2, 0x4($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X4);
    // 0x801DC714: beq         $v0, $zero, L_801DC9B0
    if (ctx->r2 == 0) {
        // 0x801DC718: lwc1        $f0, 0x8($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
            goto L_801DC9B0;
    }
    // 0x801DC718: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
L_801DC71C:
    // 0x801DC71C: bnel        $v1, $v0, L_801DC9A4
    if (ctx->r3 != ctx->r2) {
        // 0x801DC720: lw          $v0, 0x8($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X8);
            goto L_801DC9A4;
    }
    goto skip_0;
    // 0x801DC720: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    skip_0:
    // 0x801DC724: lbu         $t6, 0x4($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X4);
    // 0x801DC728: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DC72C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801DC730: bgez        $t6, L_801DC744
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801DC734: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801DC744;
    }
    // 0x801DC734: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801DC738: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DC73C: nop

    // 0x801DC740: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801DC744:
    // 0x801DC744: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801DC748: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC74C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DC750: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801DC754: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC758: nop

    // 0x801DC75C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DC760: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC764: nop

    // 0x801DC768: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC76C: beql        $a0, $zero, L_801DC7BC
    if (ctx->r4 == 0) {
        // 0x801DC770: mfc1        $a0, $f16
        ctx->r4 = (int32_t)ctx->f16.u32l;
            goto L_801DC7BC;
    }
    goto skip_1;
    // 0x801DC770: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x801DC774: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801DC778: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC77C: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801DC780: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC784: nop

    // 0x801DC788: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801DC78C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC790: nop

    // 0x801DC794: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC798: bne         $a0, $zero, L_801DC7B0
    if (ctx->r4 != 0) {
        // 0x801DC79C: nop
    
            goto L_801DC7B0;
    }
    // 0x801DC79C: nop

    // 0x801DC7A0: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x801DC7A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DC7A8: b           L_801DC7C8
    // 0x801DC7AC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DC7C8;
    // 0x801DC7AC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DC7B0:
    // 0x801DC7B0: b           L_801DC7C8
    // 0x801DC7B4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DC7C8;
    // 0x801DC7B4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DC7B8: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
L_801DC7BC:
    // 0x801DC7BC: nop

    // 0x801DC7C0: bltz        $a0, L_801DC7B0
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DC7C4: nop
    
            goto L_801DC7B0;
    }
    // 0x801DC7C4: nop

L_801DC7C8:
    // 0x801DC7C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801DC7CC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DC7D0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801DC7D4: sh          $a2, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r6;
    // 0x801DC7D8: jal         0x80011590
    // 0x801DC7DC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_0;
    // 0x801DC7DC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x801DC7E0: lhu         $v1, 0x22($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X22);
    // 0x801DC7E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801DC7E8: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801DC7EC: bnel        $v1, $v0, L_801DC800
    if (ctx->r3 != ctx->r2) {
        // 0x801DC7F0: lbu         $t8, 0x5($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X5);
            goto L_801DC800;
    }
    goto skip_2;
    // 0x801DC7F0: lbu         $t8, 0x5($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X5);
    skip_2:
    // 0x801DC7F4: b           L_801DC9B4
    // 0x801DC7F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801DC9B4;
    // 0x801DC7F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801DC7FC: lbu         $t8, 0x5($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X5);
L_801DC800:
    // 0x801DC800: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DC804: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x801DC808: bgez        $t8, L_801DC81C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801DC80C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801DC81C;
    }
    // 0x801DC80C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801DC810: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DC814: nop

    // 0x801DC818: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_801DC81C:
    // 0x801DC81C: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801DC820: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC824: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DC828: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801DC82C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC830: nop

    // 0x801DC834: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DC838: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC83C: nop

    // 0x801DC840: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC844: beql        $a0, $zero, L_801DC894
    if (ctx->r4 == 0) {
        // 0x801DC848: mfc1        $a0, $f16
        ctx->r4 = (int32_t)ctx->f16.u32l;
            goto L_801DC894;
    }
    goto skip_3;
    // 0x801DC848: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x801DC84C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801DC850: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC854: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801DC858: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC85C: nop

    // 0x801DC860: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801DC864: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC868: nop

    // 0x801DC86C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC870: bne         $a0, $zero, L_801DC888
    if (ctx->r4 != 0) {
        // 0x801DC874: nop
    
            goto L_801DC888;
    }
    // 0x801DC874: nop

    // 0x801DC878: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x801DC87C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DC880: b           L_801DC8A0
    // 0x801DC884: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DC8A0;
    // 0x801DC884: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DC888:
    // 0x801DC888: b           L_801DC8A0
    // 0x801DC88C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DC8A0;
    // 0x801DC88C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DC890: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
L_801DC894:
    // 0x801DC894: nop

    // 0x801DC898: bltz        $a0, L_801DC888
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DC89C: nop
    
            goto L_801DC888;
    }
    // 0x801DC89C: nop

L_801DC8A0:
    // 0x801DC8A0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801DC8A4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DC8A8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x801DC8AC: jal         0x80011590
    // 0x801DC8B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_1;
    // 0x801DC8B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x801DC8B4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801DC8B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801DC8BC: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801DC8C0: bnel        $v1, $v0, L_801DC8D4
    if (ctx->r3 != ctx->r2) {
        // 0x801DC8C4: lbu         $t0, 0x6($a1)
        ctx->r8 = MEM_BU(ctx->r5, 0X6);
            goto L_801DC8D4;
    }
    goto skip_4;
    // 0x801DC8C4: lbu         $t0, 0x6($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X6);
    skip_4:
    // 0x801DC8C8: b           L_801DC9B4
    // 0x801DC8CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801DC9B4;
    // 0x801DC8CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801DC8D0: lbu         $t0, 0x6($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X6);
L_801DC8D4:
    // 0x801DC8D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DC8D8: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x801DC8DC: bgez        $t0, L_801DC8F0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801DC8E0: cvt.s.w     $f8, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801DC8F0;
    }
    // 0x801DC8E0: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801DC8E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DC8E8: nop

    // 0x801DC8EC: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_801DC8F0:
    // 0x801DC8F0: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801DC8F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC8F8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DC8FC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801DC900: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC904: nop

    // 0x801DC908: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DC90C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC910: nop

    // 0x801DC914: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC918: beql        $a0, $zero, L_801DC968
    if (ctx->r4 == 0) {
        // 0x801DC91C: mfc1        $a0, $f16
        ctx->r4 = (int32_t)ctx->f16.u32l;
            goto L_801DC968;
    }
    goto skip_5;
    // 0x801DC91C: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    skip_5:
    // 0x801DC920: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801DC924: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DC928: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801DC92C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DC930: nop

    // 0x801DC934: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801DC938: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DC93C: nop

    // 0x801DC940: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DC944: bne         $a0, $zero, L_801DC95C
    if (ctx->r4 != 0) {
        // 0x801DC948: nop
    
            goto L_801DC95C;
    }
    // 0x801DC948: nop

    // 0x801DC94C: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x801DC950: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DC954: b           L_801DC974
    // 0x801DC958: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DC974;
    // 0x801DC958: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DC95C:
    // 0x801DC95C: b           L_801DC974
    // 0x801DC960: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DC974;
    // 0x801DC960: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DC964: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
L_801DC968:
    // 0x801DC968: nop

    // 0x801DC96C: bltz        $a0, L_801DC95C
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DC970: nop
    
            goto L_801DC95C;
    }
    // 0x801DC970: nop

L_801DC974:
    // 0x801DC974: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801DC978: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DC97C: jal         0x80011590
    // 0x801DC980: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_2;
    // 0x801DC980: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_2:
    // 0x801DC984: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801DC988: bne         $v1, $v0, L_801DC998
    if (ctx->r3 != ctx->r2) {
        // 0x801DC98C: nop
    
            goto L_801DC998;
    }
    // 0x801DC98C: nop

    // 0x801DC990: b           L_801DC9B4
    // 0x801DC994: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801DC9B4;
    // 0x801DC994: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801DC998:
    // 0x801DC998: b           L_801DC9B4
    // 0x801DC99C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801DC9B4;
    // 0x801DC99C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801DC9A0: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
L_801DC9A4:
    // 0x801DC9A4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x801DC9A8: bne         $v0, $zero, L_801DC71C
    if (ctx->r2 != 0) {
        // 0x801DC9AC: nop
    
            goto L_801DC71C;
    }
    // 0x801DC9AC: nop

L_801DC9B0:
    // 0x801DC9B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801DC9B4:
    // 0x801DC9B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DC9B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801DC9BC: jr          $ra
    // 0x801DC9C0: nop

    return;
    // 0x801DC9C0: nop

;}
RECOMP_FUNC void M8_FUN_801dc9c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DC9C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801DC9C8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801DC9CC: lhu         $t6, 0x36($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X36);
    // 0x801DC9D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DC9D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801DC9D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801DC9DC: beq         $t6, $zero, L_801DCC40
    if (ctx->r14 == 0) {
        // 0x801DC9E0: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_801DCC40;
    }
    // 0x801DC9E0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801DC9E4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801DC9E8: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x801DC9EC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801DC9F0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801DC9F4: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801DC9F8: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801DC9FC: lwc1        $f6, 0x30($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801DCA00: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801DCA04: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DCA08: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801DCA0C: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801DCA10: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801DCA14: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801DCA18: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801DCA1C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801DCA20: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801DCA24: jal         0x8002FC20
    // 0x801DCA28: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x801DCA28: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_0:
    // 0x801DCA2C: lui         $at, 0x4035
    ctx->r1 = S32(0X4035 << 16);
    // 0x801DCA30: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801DCA34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DCA38: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x801DCA3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DCA40: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x801DCA44: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801DCA48: bc1f        L_801DCA58
    if (!c1cs) {
        // 0x801DCA4C: nop
    
            goto L_801DCA58;
    }
    // 0x801DCA4C: nop

    // 0x801DCA50: b           L_801DCA7C
    // 0x801DCA54: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
        goto L_801DCA7C;
    // 0x801DCA54: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
L_801DCA58:
    // 0x801DCA58: ldc1        $f6, 0x3D30($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X3D30);
    // 0x801DCA5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DCA60: ldc1        $f8, 0x3D38($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X3D38);
    // 0x801DCA64: add.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d + ctx->f8.d;
    // 0x801DCA68: div.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = DIV_D(ctx->f6.d, ctx->f10.d);
    // 0x801DCA6C: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x801DCA70: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x801DCA74: nop

    // 0x801DCA78: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_801DCA7C:
    // 0x801DCA7C: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801DCA80: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x801DCA84: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DCA88: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x801DCA8C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x801DCA90: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x801DCA94: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801DCA98: bc1f        L_801DCAA8
    if (!c1cs) {
        // 0x801DCA9C: nop
    
            goto L_801DCAA8;
    }
    // 0x801DCA9C: nop

    // 0x801DCAA0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801DCAA4: nop

L_801DCAA8:
    // 0x801DCAA8: bgez        $v0, L_801DCABC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801DCAAC: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801DCABC;
    }
    // 0x801DCAAC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801DCAB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DCAB4: nop

    // 0x801DCAB8: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_801DCABC:
    // 0x801DCABC: mul.s       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x801DCAC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DCAC4: ldc1        $f8, 0x3D40($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X3D40);
    // 0x801DCAC8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801DCACC: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x801DCAD0: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x801DCAD4: nop

    // 0x801DCAD8: bc1f        L_801DCAE8
    if (!c1cs) {
        // 0x801DCADC: nop
    
            goto L_801DCAE8;
    }
    // 0x801DCADC: nop

    // 0x801DCAE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801DCAE4: nop

L_801DCAE8:
    // 0x801DCAE8: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x801DCAEC: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801DCAF0: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801DCAF4: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801DCAF8: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801DCAFC: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801DCB00: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801DCB04: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801DCB08: jal         0x8001EF38
    // 0x801DCB0C: sub.s       $f14, $f18, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f8.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x801DCB0C: sub.s       $f14, $f18, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f8.fl;
    after_1:
    // 0x801DCB10: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801DCB14: lw          $t0, -0x4328($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4328);
    // 0x801DCB18: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x801DCB1C: lwc1        $f6, 0x44($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801DCB20: lwc1        $f10, 0x38($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801DCB24: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x801DCB28: lwc1        $f18, 0x30($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801DCB2C: sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // 0x801DCB30: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801DCB34: jal         0x8001EF38
    // 0x801DCB38: sub.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f18.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_2;
    // 0x801DCB38: sub.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f18.fl;
    after_2:
    // 0x801DCB3C: lh          $a0, 0x24($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X24);
    // 0x801DCB40: subu        $v1, $a0, $v0
    ctx->r3 = SUB32(ctx->r4, ctx->r2);
    // 0x801DCB44: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x801DCB48: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x801DCB4C: andi        $t1, $v1, 0x1000
    ctx->r9 = ctx->r3 & 0X1000;
    // 0x801DCB50: beq         $t1, $zero, L_801DCB6C
    if (ctx->r9 == 0) {
        // 0x801DCB54: andi        $a0, $v1, 0x1FFF
        ctx->r4 = ctx->r3 & 0X1FFF;
            goto L_801DCB6C;
    }
    // 0x801DCB54: andi        $a0, $v1, 0x1FFF
    ctx->r4 = ctx->r3 & 0X1FFF;
    // 0x801DCB58: andi        $a0, $v1, 0x1FFF
    ctx->r4 = ctx->r3 & 0X1FFF;
    // 0x801DCB5C: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, -0X2000);
    // 0x801DCB60: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801DCB64: b           L_801DCB74
    // 0x801DCB68: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
        goto L_801DCB74;
    // 0x801DCB68: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_801DCB6C:
    // 0x801DCB6C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801DCB70: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_801DCB74:
    // 0x801DCB74: jal         0x8001EAD0
    // 0x801DCB78: nop

    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_3;
    // 0x801DCB78: nop

    after_3:
    // 0x801DCB7C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DCB80: ldc1        $f6, 0x3D48($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X3D48);
    // 0x801DCB84: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801DCB88: lui         $at, 0x4050
    ctx->r1 = S32(0X4050 << 16);
    // 0x801DCB8C: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x801DCB90: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801DCB94: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DCB98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801DCB9C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801DCBA0: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    // 0x801DCBA4: add.d       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f10.d + ctx->f4.d;
    // 0x801DCBA8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801DCBAC: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801DCBB0: nop

    // 0x801DCBB4: cvt.w.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_D(ctx->f18.d);
    // 0x801DCBB8: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801DCBBC: nop

    // 0x801DCBC0: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801DCBC4: beql        $a1, $zero, L_801DCC18
    if (ctx->r5 == 0) {
        // 0x801DCBC8: mfc1        $a1, $f8
        ctx->r5 = (int32_t)ctx->f8.u32l;
            goto L_801DCC18;
    }
    goto skip_0;
    // 0x801DCBC8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x801DCBCC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801DCBD0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801DCBD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801DCBD8: sub.d       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f18.d - ctx->f8.d;
    // 0x801DCBDC: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801DCBE0: nop

    // 0x801DCBE4: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x801DCBE8: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x801DCBEC: nop

    // 0x801DCBF0: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x801DCBF4: bne         $a1, $zero, L_801DCC0C
    if (ctx->r5 != 0) {
        // 0x801DCBF8: nop
    
            goto L_801DCC0C;
    }
    // 0x801DCBF8: nop

    // 0x801DCBFC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801DCC00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DCC04: b           L_801DCC24
    // 0x801DCC08: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_801DCC24;
    // 0x801DCC08: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_801DCC0C:
    // 0x801DCC0C: b           L_801DCC24
    // 0x801DCC10: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_801DCC24;
    // 0x801DCC10: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801DCC14: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
L_801DCC18:
    // 0x801DCC18: nop

    // 0x801DCC1C: bltz        $a1, L_801DCC0C
    if (SIGNED(ctx->r5) < 0) {
        // 0x801DCC20: nop
    
            goto L_801DCC0C;
    }
    // 0x801DCC20: nop

L_801DCC24:
    // 0x801DCC24: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801DCC28: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801DCC2C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801DCC30: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801DCC34: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801DCC38: jal         0x800207D0
    // 0x801DCC3C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x800207D0)(rdram, ctx);
        goto after_4;
    // 0x801DCC3C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_4:
L_801DCC40:
    // 0x801DCC40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DCC44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801DCC48: jr          $ra
    // 0x801DCC4C: nop

    return;
    // 0x801DCC4C: nop

;}
RECOMP_FUNC void M8_FUN_801dcc50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DCC50: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801DCC54: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DCC58: addiu       $t6, $a0, -0x661
    ctx->r14 = ADD32(ctx->r4, -0X661);
    // 0x801DCC5C: sltiu       $at, $t6, 0x1F
    ctx->r1 = ctx->r14 < 0X1F ? 1 : 0;
    // 0x801DCC60: beq         $at, $zero, L_801DCCA4
    if (ctx->r1 == 0) {
        // 0x801DCC64: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_801DCCA4;
    }
    // 0x801DCC64: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DCC68: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DCC6C: addu        $at, $at, $t6
    gpr jr_addend_801DCC74 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801DCC70: lw          $t6, 0x3D50($at)
    ctx->r14 = ADD32(ctx->r1, 0X3D50);
    // 0x801DCC74: jr          $t6
    // 0x801DCC78: nop

    switch (jr_addend_801DCC74 >> 2) {
        case 0: goto L_801DCCA4; break;
        case 1: goto L_801DCCA4; break;
        case 2: goto L_801DCCA4; break;
        case 3: goto L_801DCCA4; break;
        case 4: goto L_801DCCA4; break;
        case 5: goto L_801DCCA4; break;
        case 6: goto L_801DCCA4; break;
        case 7: goto L_801DCCA4; break;
        case 8: goto L_801DCCA4; break;
        case 9: goto L_801DCCA4; break;
        case 10: goto L_801DCCA4; break;
        case 11: goto L_801DCCA4; break;
        case 12: goto L_801DCCA4; break;
        case 13: goto L_801DCCA4; break;
        case 14: goto L_801DCCA4; break;
        case 15: goto L_801DCC9C; break;
        case 16: goto L_801DCC9C; break;
        case 17: goto L_801DCC84; break;
        case 18: goto L_801DCC84; break;
        case 19: goto L_801DCC7C; break;
        case 20: goto L_801DCC7C; break;
        case 21: goto L_801DCCA4; break;
        case 22: goto L_801DCCA4; break;
        case 23: goto L_801DCC9C; break;
        case 24: goto L_801DCC9C; break;
        case 25: goto L_801DCC94; break;
        case 26: goto L_801DCC94; break;
        case 27: goto L_801DCC8C; break;
        case 28: goto L_801DCC8C; break;
        case 29: goto L_801DCC94; break;
        case 30: goto L_801DCC94; break;
        default: switch_error(__func__, 0x801DCC74, 0x801E3D50);
    }
    // 0x801DCC78: nop

L_801DCC7C:
    // 0x801DCC7C: jr          $ra
    // 0x801DCC80: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x801DCC80: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801DCC84:
    // 0x801DCC84: jr          $ra
    // 0x801DCC88: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801DCC88: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801DCC8C:
    // 0x801DCC8C: jr          $ra
    // 0x801DCC90: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801DCC90: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801DCC94:
    // 0x801DCC94: jr          $ra
    // 0x801DCC98: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801DCC98: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801DCC9C:
    // 0x801DCC9C: jr          $ra
    // 0x801DCCA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801DCCA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801DCCA4:
    // 0x801DCCA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801DCCA8: jr          $ra
    // 0x801DCCAC: nop

    return;
    // 0x801DCCAC: nop

;}
RECOMP_FUNC void M8_FUN_801dccb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DCCB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801DCCB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DCCB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801DCCBC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801DCCC0: jal         0x801DC250
    // 0x801DCCC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801DC250)(rdram, ctx);
        goto after_0;
    // 0x801DCCC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801DCCC8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801DCCCC: addiu       $a2, $a2, -0x4410
    ctx->r6 = ADD32(ctx->r6, -0X4410);
    // 0x801DCCD0: lhu         $t6, 0x4($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X4);
    // 0x801DCCD4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801DCCD8: lbu         $t9, 0x35B($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X35B);
    // 0x801DCCDC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DCCE0: lbu         $t7, 0x16A0($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X16A0);
    // 0x801DCCE4: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x801DCCE8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801DCCEC: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x801DCCF0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x801DCCF4: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x801DCCF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DCCFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801DCD00: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x801DCD04: beq         $v0, $at, L_801DCD28
    if (ctx->r2 == ctx->r1) {
        // 0x801DCD08: lhu         $a0, 0x15E0($a0)
        ctx->r4 = MEM_HU(ctx->r4, 0X15E0);
            goto L_801DCD28;
    }
    // 0x801DCD08: lhu         $a0, 0x15E0($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X15E0);
    // 0x801DCD0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801DCD10: beq         $v0, $at, L_801DCD5C
    if (ctx->r2 == ctx->r1) {
        // 0x801DCD14: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801DCD5C;
    }
    // 0x801DCD14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801DCD18: beql        $v0, $at, L_801DCD70
    if (ctx->r2 == ctx->r1) {
        // 0x801DCD1C: sh          $a0, 0x1C($sp)
        MEM_H(0X1C, ctx->r29) = ctx->r4;
            goto L_801DCD70;
    }
    goto skip_0;
    // 0x801DCD1C: sh          $a0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r4;
    skip_0:
    // 0x801DCD20: b           L_801DCDAC
    // 0x801DCD24: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
        goto L_801DCDAC;
    // 0x801DCD24: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_801DCD28:
    // 0x801DCD28: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
    // 0x801DCD2C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x801DCD30: lui         $at, 0x190
    ctx->r1 = S32(0X190 << 16);
    // 0x801DCD34: ori         $at, $at, 0x220
    ctx->r1 = ctx->r1 | 0X220;
    // 0x801DCD38: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x801DCD3C: beq         $v0, $at, L_801DCD4C
    if (ctx->r2 == ctx->r1) {
        // 0x801DCD40: lui         $at, 0x190
        ctx->r1 = S32(0X190 << 16);
            goto L_801DCD4C;
    }
    // 0x801DCD40: lui         $at, 0x190
    ctx->r1 = S32(0X190 << 16);
    // 0x801DCD44: ori         $at, $at, 0x1E6
    ctx->r1 = ctx->r1 | 0X1E6;
    // 0x801DCD48: bne         $v0, $at, L_801DCDAC
    if (ctx->r2 != ctx->r1) {
        // 0x801DCD4C: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801DCDAC;
    }
L_801DCD4C:
    // 0x801DCD4C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DCD50: lwc1        $f4, 0x3DCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3DCC);
    // 0x801DCD54: b           L_801DCDAC
    // 0x801DCD58: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
        goto L_801DCDAC;
    // 0x801DCD58: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
L_801DCD5C:
    // 0x801DCD5C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x801DCD60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DCD64: nop

    // 0x801DCD68: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x801DCD6C: sh          $a0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r4;
L_801DCD70:
    // 0x801DCD70: jal         0x801DCC50
    // 0x801DCD74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801DCC50)(rdram, ctx);
        goto after_1;
    // 0x801DCD74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x801DCD78: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x801DCD7C: lhu         $a0, 0x1C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1C);
    // 0x801DCD80: bne         $at, $zero, L_801DCD90
    if (ctx->r1 != 0) {
        // 0x801DCD84: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_801DCD90;
    }
    // 0x801DCD84: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801DCD88: b           L_801DCDAC
    // 0x801DCD8C: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
        goto L_801DCDAC;
    // 0x801DCD8C: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
L_801DCD90:
    // 0x801DCD90: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x801DCD94: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801DCD98: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801DCD9C: lhu         $t4, 0x177C($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X177C);
    // 0x801DCDA0: b           L_801DCDAC
    // 0x801DCDA4: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
        goto L_801DCDAC;
    // 0x801DCDA4: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x801DCDA8: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_801DCDAC:
    // 0x801DCDAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DCDB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801DCDB4: jr          $ra
    // 0x801DCDB8: nop

    return;
    // 0x801DCDB8: nop

;}
RECOMP_FUNC void M8_FUN_801dcdbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DCDBC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801DCDC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801DCDC4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801DCDC8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801DCDCC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801DCDD0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x801DCDD4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801DCDD8: lui         $at, 0xFE97
    ctx->r1 = S32(0XFE97 << 16);
    // 0x801DCDDC: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x801DCDE0: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x801DCDE4: sltiu       $at, $t7, 0x51
    ctx->r1 = ctx->r15 < 0X51 ? 1 : 0;
    // 0x801DCDE8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801DCDEC: beq         $at, $zero, L_801DE444
    if (ctx->r1 == 0) {
        // 0x801DCDF0: lwc1        $f0, 0x8($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
            goto L_801DE444;
    }
    // 0x801DCDF0: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801DCDF4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DCDF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DCDFC: addu        $at, $at, $t7
    gpr jr_addend_801DCE04 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801DCE00: lw          $t7, 0x3DD0($at)
    ctx->r15 = ADD32(ctx->r1, 0X3DD0);
    // 0x801DCE04: jr          $t7
    // 0x801DCE08: nop

    switch (jr_addend_801DCE04 >> 2) {
        case 0: goto L_801DCE0C; break;
        case 1: goto L_801DE444; break;
        case 2: goto L_801DE444; break;
        case 3: goto L_801DE444; break;
        case 4: goto L_801DE444; break;
        case 5: goto L_801DE444; break;
        case 6: goto L_801DE444; break;
        case 7: goto L_801DE444; break;
        case 8: goto L_801DE444; break;
        case 9: goto L_801DE444; break;
        case 10: goto L_801DE444; break;
        case 11: goto L_801DE444; break;
        case 12: goto L_801DE444; break;
        case 13: goto L_801DE444; break;
        case 14: goto L_801DE444; break;
        case 15: goto L_801DE444; break;
        case 16: goto L_801DE444; break;
        case 17: goto L_801DE444; break;
        case 18: goto L_801DE444; break;
        case 19: goto L_801DD9AC; break;
        case 20: goto L_801DE444; break;
        case 21: goto L_801DE444; break;
        case 22: goto L_801DE2D4; break;
        case 23: goto L_801DE21C; break;
        case 24: goto L_801DE2D4; break;
        case 25: goto L_801DE2D4; break;
        case 26: goto L_801DDFD8; break;
        case 27: goto L_801DE2D4; break;
        case 28: goto L_801DDC84; break;
        case 29: goto L_801DDB8C; break;
        case 30: goto L_801DDE5C; break;
        case 31: goto L_801DE444; break;
        case 32: goto L_801DE444; break;
        case 33: goto L_801DD5B4; break;
        case 34: goto L_801DE444; break;
        case 35: goto L_801DE444; break;
        case 36: goto L_801DD754; break;
        case 37: goto L_801DE444; break;
        case 38: goto L_801DE444; break;
        case 39: goto L_801DE444; break;
        case 40: goto L_801DE444; break;
        case 41: goto L_801DD454; break;
        case 42: goto L_801DE444; break;
        case 43: goto L_801DE444; break;
        case 44: goto L_801DE444; break;
        case 45: goto L_801DDD64; break;
        case 46: goto L_801DE21C; break;
        case 47: goto L_801DD948; break;
        case 48: goto L_801DE444; break;
        case 49: goto L_801DE444; break;
        case 50: goto L_801DE444; break;
        case 51: goto L_801DE444; break;
        case 52: goto L_801DE444; break;
        case 53: goto L_801DE444; break;
        case 54: goto L_801DE444; break;
        case 55: goto L_801DE444; break;
        case 56: goto L_801DE444; break;
        case 57: goto L_801DE444; break;
        case 58: goto L_801DE444; break;
        case 59: goto L_801DE444; break;
        case 60: goto L_801DCEF8; break;
        case 61: goto L_801DD094; break;
        case 62: goto L_801DD240; break;
        case 63: goto L_801DE444; break;
        case 64: goto L_801DE444; break;
        case 65: goto L_801DE444; break;
        case 66: goto L_801DE444; break;
        case 67: goto L_801DE444; break;
        case 68: goto L_801DE444; break;
        case 69: goto L_801DE444; break;
        case 70: goto L_801DE444; break;
        case 71: goto L_801DE444; break;
        case 72: goto L_801DE444; break;
        case 73: goto L_801DE444; break;
        case 74: goto L_801DD3EC; break;
        case 75: goto L_801DD47C; break;
        case 76: goto L_801DD4E4; break;
        case 77: goto L_801DE444; break;
        case 78: goto L_801DE444; break;
        case 79: goto L_801DD54C; break;
        case 80: goto L_801DD54C; break;
        default: switch_error(__func__, 0x801DCE04, 0x801E3DD0);
    }
    // 0x801DCE08: nop

L_801DCE0C:
    // 0x801DCE0C: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x801DCE10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DCE14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DCE18: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DCE1C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801DCE20: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801DCE24: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DCE28: nop

    // 0x801DCE2C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DCE30: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DCE34: nop

    // 0x801DCE38: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DCE3C: beql        $a0, $zero, L_801DCE8C
    if (ctx->r4 == 0) {
        // 0x801DCE40: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_801DCE8C;
    }
    goto skip_0;
    // 0x801DCE40: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x801DCE44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DCE48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DCE4C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801DCE50: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DCE54: nop

    // 0x801DCE58: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801DCE5C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DCE60: nop

    // 0x801DCE64: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DCE68: bne         $a0, $zero, L_801DCE80
    if (ctx->r4 != 0) {
        // 0x801DCE6C: nop
    
            goto L_801DCE80;
    }
    // 0x801DCE6C: nop

    // 0x801DCE70: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x801DCE74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DCE78: b           L_801DCE98
    // 0x801DCE7C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DCE98;
    // 0x801DCE7C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DCE80:
    // 0x801DCE80: b           L_801DCE98
    // 0x801DCE84: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DCE98;
    // 0x801DCE84: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DCE88: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_801DCE8C:
    // 0x801DCE8C: nop

    // 0x801DCE90: bltz        $a0, L_801DCE80
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DCE94: nop
    
            goto L_801DCE80;
    }
    // 0x801DCE94: nop

L_801DCE98:
    // 0x801DCE98: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801DCE9C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DCEA0: jal         0x80011590
    // 0x801DCEA4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_0;
    // 0x801DCEA4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x801DCEA8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DCEAC: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801DCEB0: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801DCEB4: lhu         $t9, 0x4($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X4);
    // 0x801DCEB8: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801DCEBC: bnel        $t9, $v0, L_801DE458
    if (ctx->r25 != ctx->r2) {
        // 0x801DCEC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801DE458;
    }
    goto skip_1;
    // 0x801DCEC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801DCEC4: lhu         $t0, -0x440C($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X440C);
    // 0x801DCEC8: lbu         $t3, -0x40B5($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X40B5);
    // 0x801DCECC: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801DCED0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801DCED4: lbu         $t1, 0x16A0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X16A0);
    // 0x801DCED8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x801DCEDC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801DCEE0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x801DCEE4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x801DCEE8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DCEEC: lhu         $t6, 0x15E8($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X15E8);
    // 0x801DCEF0: b           L_801DE454
    // 0x801DCEF4: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
        goto L_801DE454;
    // 0x801DCEF4: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
L_801DCEF8:
    // 0x801DCEF8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801DCEFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DCF00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DCF04: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DCF08: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801DCF0C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801DCF10: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DCF14: nop

    // 0x801DCF18: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DCF1C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DCF20: nop

    // 0x801DCF24: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DCF28: beql        $a0, $zero, L_801DCF78
    if (ctx->r4 == 0) {
        // 0x801DCF2C: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_801DCF78;
    }
    goto skip_2;
    // 0x801DCF2C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x801DCF30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DCF34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DCF38: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DCF3C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DCF40: nop

    // 0x801DCF44: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DCF48: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DCF4C: nop

    // 0x801DCF50: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DCF54: bne         $a0, $zero, L_801DCF6C
    if (ctx->r4 != 0) {
        // 0x801DCF58: nop
    
            goto L_801DCF6C;
    }
    // 0x801DCF58: nop

    // 0x801DCF5C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801DCF60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DCF64: b           L_801DCF84
    // 0x801DCF68: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DCF84;
    // 0x801DCF68: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DCF6C:
    // 0x801DCF6C: b           L_801DCF84
    // 0x801DCF70: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DCF84;
    // 0x801DCF70: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DCF74: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_801DCF78:
    // 0x801DCF78: nop

    // 0x801DCF7C: bltz        $a0, L_801DCF6C
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DCF80: nop
    
            goto L_801DCF6C;
    }
    // 0x801DCF80: nop

L_801DCF84:
    // 0x801DCF84: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801DCF88: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DCF8C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x801DCF90: jal         0x80011590
    // 0x801DCF94: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_1;
    // 0x801DCF94: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x801DCF98: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DCF9C: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801DCFA0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801DCFA4: lhu         $t9, 0x4($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X4);
    // 0x801DCFA8: beq         $t9, $v0, L_801DD054
    if (ctx->r25 == ctx->r2) {
        // 0x801DCFAC: nop
    
            goto L_801DD054;
    }
    // 0x801DCFAC: nop

    // 0x801DCFB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DCFB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DCFB8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DCFBC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801DCFC0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801DCFC4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DCFC8: nop

    // 0x801DCFCC: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DCFD0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DCFD4: nop

    // 0x801DCFD8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DCFDC: beql        $a0, $zero, L_801DD02C
    if (ctx->r4 == 0) {
        // 0x801DCFE0: mfc1        $a0, $f4
        ctx->r4 = (int32_t)ctx->f4.u32l;
            goto L_801DD02C;
    }
    goto skip_3;
    // 0x801DCFE0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    skip_3:
    // 0x801DCFE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DCFE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DCFEC: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801DCFF0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DCFF4: nop

    // 0x801DCFF8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DCFFC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DD000: nop

    // 0x801DD004: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DD008: bne         $a0, $zero, L_801DD020
    if (ctx->r4 != 0) {
        // 0x801DD00C: nop
    
            goto L_801DD020;
    }
    // 0x801DD00C: nop

    // 0x801DD010: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x801DD014: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DD018: b           L_801DD038
    // 0x801DD01C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DD038;
    // 0x801DD01C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DD020:
    // 0x801DD020: b           L_801DD038
    // 0x801DD024: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DD038;
    // 0x801DD024: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DD028: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
L_801DD02C:
    // 0x801DD02C: nop

    // 0x801DD030: bltz        $a0, L_801DD020
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DD034: nop
    
            goto L_801DD020;
    }
    // 0x801DD034: nop

L_801DD038:
    // 0x801DD038: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801DD03C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DD040: jal         0x80011590
    // 0x801DD044: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_2;
    // 0x801DD044: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x801DD048: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD04C: lhu         $t1, 0x4($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD050: bne         $t1, $v0, L_801DE454
    if (ctx->r9 != ctx->r2) {
        // 0x801DD054: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801DE454;
    }
L_801DD054:
    // 0x801DD054: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DD058: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801DD05C: lhu         $t3, 0x4($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X4);
    // 0x801DD060: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801DD064: lbu         $t5, 0x35B($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X35B);
    // 0x801DD068: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x801DD06C: lbu         $t2, 0x16A0($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X16A0);
    // 0x801DD070: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x801DD074: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801DD078: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x801DD07C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x801DD080: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801DD084: lhu         $t8, 0x15E8($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X15E8);
    // 0x801DD088: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD08C: b           L_801DE454
    // 0x801DD090: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
        goto L_801DE454;
    // 0x801DD090: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
L_801DD094:
    // 0x801DD094: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801DD098: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DD09C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DD0A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DD0A4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801DD0A8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801DD0AC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DD0B0: nop

    // 0x801DD0B4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801DD0B8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DD0BC: nop

    // 0x801DD0C0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DD0C4: beql        $a0, $zero, L_801DD114
    if (ctx->r4 == 0) {
        // 0x801DD0C8: mfc1        $a0, $f10
        ctx->r4 = (int32_t)ctx->f10.u32l;
            goto L_801DD114;
    }
    goto skip_4;
    // 0x801DD0C8: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x801DD0CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DD0D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DD0D4: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801DD0D8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DD0DC: nop

    // 0x801DD0E0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DD0E4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DD0E8: nop

    // 0x801DD0EC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DD0F0: bne         $a0, $zero, L_801DD108
    if (ctx->r4 != 0) {
        // 0x801DD0F4: nop
    
            goto L_801DD108;
    }
    // 0x801DD0F4: nop

    // 0x801DD0F8: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x801DD0FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DD100: b           L_801DD120
    // 0x801DD104: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DD120;
    // 0x801DD104: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DD108:
    // 0x801DD108: b           L_801DD120
    // 0x801DD10C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DD120;
    // 0x801DD10C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DD110: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
L_801DD114:
    // 0x801DD114: nop

    // 0x801DD118: bltz        $a0, L_801DD108
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DD11C: nop
    
            goto L_801DD108;
    }
    // 0x801DD11C: nop

L_801DD120:
    // 0x801DD120: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801DD124: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DD128: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x801DD12C: jal         0x80011590
    // 0x801DD130: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_3;
    // 0x801DD130: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x801DD134: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD138: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801DD13C: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x801DD140: lhu         $t1, 0x4($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD144: beq         $t1, $v0, L_801DD1F0
    if (ctx->r9 == ctx->r2) {
        // 0x801DD148: nop
    
            goto L_801DD1F0;
    }
    // 0x801DD148: nop

    // 0x801DD14C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DD150: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DD154: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DD158: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801DD15C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801DD160: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DD164: nop

    // 0x801DD168: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DD16C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DD170: nop

    // 0x801DD174: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DD178: beql        $a0, $zero, L_801DD1C8
    if (ctx->r4 == 0) {
        // 0x801DD17C: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_801DD1C8;
    }
    goto skip_5;
    // 0x801DD17C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_5:
    // 0x801DD180: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DD184: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DD188: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801DD18C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DD190: nop

    // 0x801DD194: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801DD198: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DD19C: nop

    // 0x801DD1A0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DD1A4: bne         $a0, $zero, L_801DD1BC
    if (ctx->r4 != 0) {
        // 0x801DD1A8: nop
    
            goto L_801DD1BC;
    }
    // 0x801DD1A8: nop

    // 0x801DD1AC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x801DD1B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DD1B4: b           L_801DD1D4
    // 0x801DD1B8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DD1D4;
    // 0x801DD1B8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DD1BC:
    // 0x801DD1BC: b           L_801DD1D4
    // 0x801DD1C0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DD1D4;
    // 0x801DD1C0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DD1C4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_801DD1C8:
    // 0x801DD1C8: nop

    // 0x801DD1CC: bltz        $a0, L_801DD1BC
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DD1D0: nop
    
            goto L_801DD1BC;
    }
    // 0x801DD1D0: nop

L_801DD1D4:
    // 0x801DD1D4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801DD1D8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DD1DC: jal         0x80011590
    // 0x801DD1E0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_4;
    // 0x801DD1E0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_4:
    // 0x801DD1E4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD1E8: lhu         $t2, 0x4($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD1EC: bne         $t2, $v0, L_801DD22C
    if (ctx->r10 != ctx->r2) {
        // 0x801DD1F0: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801DD22C;
    }
L_801DD1F0:
    // 0x801DD1F0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DD1F4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801DD1F8: lhu         $t5, 0x4($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X4);
    // 0x801DD1FC: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801DD200: lbu         $t7, 0x35B($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X35B);
    // 0x801DD204: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x801DD208: lbu         $t4, 0x16A0($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X16A0);
    // 0x801DD20C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x801DD210: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801DD214: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x801DD218: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x801DD21C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801DD220: lhu         $t0, 0x15E8($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X15E8);
    // 0x801DD224: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD228: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
L_801DD22C:
    // 0x801DD22C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DD230: lwc1        $f10, 0x3F14($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3F14);
    // 0x801DD234: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x801DD238: b           L_801DE454
    // 0x801DD23C: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
        goto L_801DE454;
    // 0x801DD23C: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
L_801DD240:
    // 0x801DD240: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801DD244: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DD248: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DD24C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DD250: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801DD254: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801DD258: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DD25C: nop

    // 0x801DD260: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DD264: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DD268: nop

    // 0x801DD26C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DD270: beql        $a0, $zero, L_801DD2C0
    if (ctx->r4 == 0) {
        // 0x801DD274: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_801DD2C0;
    }
    goto skip_6;
    // 0x801DD274: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_6:
    // 0x801DD278: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DD27C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DD280: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801DD284: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DD288: nop

    // 0x801DD28C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801DD290: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DD294: nop

    // 0x801DD298: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DD29C: bne         $a0, $zero, L_801DD2B4
    if (ctx->r4 != 0) {
        // 0x801DD2A0: nop
    
            goto L_801DD2B4;
    }
    // 0x801DD2A0: nop

    // 0x801DD2A4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x801DD2A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DD2AC: b           L_801DD2CC
    // 0x801DD2B0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DD2CC;
    // 0x801DD2B0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DD2B4:
    // 0x801DD2B4: b           L_801DD2CC
    // 0x801DD2B8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DD2CC;
    // 0x801DD2B8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DD2BC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_801DD2C0:
    // 0x801DD2C0: nop

    // 0x801DD2C4: bltz        $a0, L_801DD2B4
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DD2C8: nop
    
            goto L_801DD2B4;
    }
    // 0x801DD2C8: nop

L_801DD2CC:
    // 0x801DD2CC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801DD2D0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DD2D4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x801DD2D8: jal         0x80011590
    // 0x801DD2DC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_5;
    // 0x801DD2DC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x801DD2E0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD2E4: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801DD2E8: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x801DD2EC: lhu         $t5, 0x4($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD2F0: beq         $t5, $v0, L_801DD39C
    if (ctx->r13 == ctx->r2) {
        // 0x801DD2F4: nop
    
            goto L_801DD39C;
    }
    // 0x801DD2F4: nop

    // 0x801DD2F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DD2FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DD300: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DD304: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801DD308: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801DD30C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DD310: nop

    // 0x801DD314: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DD318: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DD31C: nop

    // 0x801DD320: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DD324: beql        $a0, $zero, L_801DD374
    if (ctx->r4 == 0) {
        // 0x801DD328: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_801DD374;
    }
    goto skip_7;
    // 0x801DD328: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_7:
    // 0x801DD32C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DD330: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DD334: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DD338: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DD33C: nop

    // 0x801DD340: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DD344: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DD348: nop

    // 0x801DD34C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DD350: bne         $a0, $zero, L_801DD368
    if (ctx->r4 != 0) {
        // 0x801DD354: nop
    
            goto L_801DD368;
    }
    // 0x801DD354: nop

    // 0x801DD358: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801DD35C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DD360: b           L_801DD380
    // 0x801DD364: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DD380;
    // 0x801DD364: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DD368:
    // 0x801DD368: b           L_801DD380
    // 0x801DD36C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DD380;
    // 0x801DD36C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DD370: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_801DD374:
    // 0x801DD374: nop

    // 0x801DD378: bltz        $a0, L_801DD368
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DD37C: nop
    
            goto L_801DD368;
    }
    // 0x801DD37C: nop

L_801DD380:
    // 0x801DD380: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801DD384: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DD388: jal         0x80011590
    // 0x801DD38C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_6;
    // 0x801DD38C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_6:
    // 0x801DD390: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD394: lhu         $t7, 0x4($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD398: bne         $t7, $v0, L_801DD3D8
    if (ctx->r15 != ctx->r2) {
        // 0x801DD39C: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801DD3D8;
    }
L_801DD39C:
    // 0x801DD39C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DD3A0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801DD3A4: lhu         $t6, 0x4($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X4);
    // 0x801DD3A8: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801DD3AC: lbu         $t0, 0x35B($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X35B);
    // 0x801DD3B0: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x801DD3B4: lbu         $t8, 0x16A0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X16A0);
    // 0x801DD3B8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x801DD3BC: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801DD3C0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x801DD3C4: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x801DD3C8: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x801DD3CC: lhu         $t2, 0x15E0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X15E0);
    // 0x801DD3D0: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD3D4: sh          $t2, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r10;
L_801DD3D8:
    // 0x801DD3D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DD3DC: lwc1        $f8, 0x3F18($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3F18);
    // 0x801DD3E0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x801DD3E4: b           L_801DE454
    // 0x801DD3E8: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
        goto L_801DE454;
    // 0x801DD3E8: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
L_801DD3EC:
    // 0x801DD3EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DD3F0: jal         0x80011590
    // 0x801DD3F4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_7;
    // 0x801DD3F4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_7:
    // 0x801DD3F8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD3FC: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801DD400: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DD404: lhu         $t7, 0x4($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD408: bne         $t7, $v0, L_801DD444
    if (ctx->r15 != ctx->r2) {
        // 0x801DD40C: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801DD444;
    }
    // 0x801DD40C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DD410: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801DD414: lhu         $t6, 0x4($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X4);
    // 0x801DD418: lbu         $t9, 0x35B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X35B);
    // 0x801DD41C: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801DD420: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x801DD424: lbu         $t8, 0x16A0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X16A0);
    // 0x801DD428: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x801DD42C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD430: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x801DD434: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x801DD438: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x801DD43C: lhu         $t2, 0x15E0($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X15E0);
    // 0x801DD440: sh          $t2, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r10;
L_801DD444:
    // 0x801DD444: lwc1        $f10, 0x3F1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3F1C);
    // 0x801DD448: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x801DD44C: b           L_801DE454
    // 0x801DD450: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
        goto L_801DE454;
    // 0x801DD450: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
L_801DD454:
    // 0x801DD454: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801DD458: jal         0x80011590
    // 0x801DD45C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_8;
    // 0x801DD45C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_8:
    // 0x801DD460: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD464: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD468: lhu         $t7, 0x4($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD46C: bne         $t7, $v0, L_801DE454
    if (ctx->r15 != ctx->r2) {
        // 0x801DD470: addiu       $t6, $zero, 0x118
        ctx->r14 = ADD32(0, 0X118);
            goto L_801DE454;
    }
    // 0x801DD470: addiu       $t6, $zero, 0x118
    ctx->r14 = ADD32(0, 0X118);
    // 0x801DD474: b           L_801DE454
    // 0x801DD478: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
        goto L_801DE454;
    // 0x801DD478: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
L_801DD47C:
    // 0x801DD47C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DD480: jal         0x80011590
    // 0x801DD484: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_9;
    // 0x801DD484: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_9:
    // 0x801DD488: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD48C: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801DD490: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DD494: lhu         $t9, 0x4($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD498: bne         $t9, $v0, L_801DD4D4
    if (ctx->r25 != ctx->r2) {
        // 0x801DD49C: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801DD4D4;
    }
    // 0x801DD49C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DD4A0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801DD4A4: lhu         $t0, 0x4($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X4);
    // 0x801DD4A8: lbu         $t2, 0x35B($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X35B);
    // 0x801DD4AC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801DD4B0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801DD4B4: lbu         $t1, 0x16A0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X16A0);
    // 0x801DD4B8: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x801DD4BC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD4C0: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x801DD4C4: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x801DD4C8: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x801DD4CC: lhu         $t7, 0x15E0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X15E0);
    // 0x801DD4D0: sh          $t7, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r15;
L_801DD4D4:
    // 0x801DD4D4: lwc1        $f4, 0x3F20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3F20);
    // 0x801DD4D8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x801DD4DC: b           L_801DE454
    // 0x801DD4E0: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
        goto L_801DE454;
    // 0x801DD4E0: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
L_801DD4E4:
    // 0x801DD4E4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x801DD4E8: jal         0x80011590
    // 0x801DD4EC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_10;
    // 0x801DD4EC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_10:
    // 0x801DD4F0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD4F4: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801DD4F8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DD4FC: lhu         $t9, 0x4($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD500: bne         $t9, $v0, L_801DD53C
    if (ctx->r25 != ctx->r2) {
        // 0x801DD504: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801DD53C;
    }
    // 0x801DD504: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DD508: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801DD50C: lhu         $t0, 0x4($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X4);
    // 0x801DD510: lbu         $t3, 0x35B($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X35B);
    // 0x801DD514: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801DD518: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801DD51C: lbu         $t1, 0x16A0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X16A0);
    // 0x801DD520: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x801DD524: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD528: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x801DD52C: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x801DD530: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x801DD534: lhu         $t7, 0x15E0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X15E0);
    // 0x801DD538: sh          $t7, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r15;
L_801DD53C:
    // 0x801DD53C: lwc1        $f6, 0x3F24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X3F24);
    // 0x801DD540: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x801DD544: b           L_801DE454
    // 0x801DD548: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
        goto L_801DE454;
    // 0x801DD548: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
L_801DD54C:
    // 0x801DD54C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801DD550: jal         0x80011590
    // 0x801DD554: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_11;
    // 0x801DD554: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_11:
    // 0x801DD558: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD55C: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801DD560: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DD564: lhu         $t9, 0x4($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD568: bne         $t9, $v0, L_801DD5A4
    if (ctx->r25 != ctx->r2) {
        // 0x801DD56C: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801DD5A4;
    }
    // 0x801DD56C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DD570: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801DD574: lhu         $t0, 0x4($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X4);
    // 0x801DD578: lbu         $t2, 0x35B($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X35B);
    // 0x801DD57C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801DD580: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801DD584: lbu         $t1, 0x16A0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X16A0);
    // 0x801DD588: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x801DD58C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD590: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x801DD594: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x801DD598: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x801DD59C: lhu         $t7, 0x15E0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X15E0);
    // 0x801DD5A0: sh          $t7, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r15;
L_801DD5A4:
    // 0x801DD5A4: lwc1        $f8, 0x3F28($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3F28);
    // 0x801DD5A8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x801DD5AC: b           L_801DE454
    // 0x801DD5B0: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
        goto L_801DE454;
    // 0x801DD5B0: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
L_801DD5B4:
    // 0x801DD5B4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x801DD5B8: jal         0x80011590
    // 0x801DD5BC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_12;
    // 0x801DD5BC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_12:
    // 0x801DD5C0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD5C4: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x801DD5C8: lhu         $t9, 0x4($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD5CC: beq         $t9, $v0, L_801DD5E8
    if (ctx->r25 == ctx->r2) {
        // 0x801DD5D0: nop
    
            goto L_801DD5E8;
    }
    // 0x801DD5D0: nop

    // 0x801DD5D4: jal         0x80011590
    // 0x801DD5D8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_13;
    // 0x801DD5D8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_13:
    // 0x801DD5DC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD5E0: lhu         $t0, 0x4($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD5E4: bne         $t0, $v0, L_801DE454
    if (ctx->r8 != ctx->r2) {
        // 0x801DD5E8: lui         $t1, 0x801C
        ctx->r9 = S32(0X801C << 16);
            goto L_801DE454;
    }
L_801DD5E8:
    // 0x801DD5E8: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801DD5EC: lw          $t1, -0x4330($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4330);
    // 0x801DD5F0: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801DD5F4: jal         0x8001EAD0
    // 0x801DD5F8: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_14;
    // 0x801DD5F8: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_14:
    // 0x801DD5FC: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801DD600: lw          $t3, -0x4330($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4330);
    // 0x801DD604: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801DD608: lw          $t5, 0x2C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X2C);
    // 0x801DD60C: jal         0x8001EB64
    // 0x801DD610: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_15;
    // 0x801DD610: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_15:
    // 0x801DD614: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801DD618: lw          $t4, -0x4330($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4330);
    // 0x801DD61C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801DD620: lw          $t7, 0x2C($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X2C);
    // 0x801DD624: jal         0x8001EAD0
    // 0x801DD628: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_16;
    // 0x801DD628: lh          $a0, 0x12($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X12);
    after_16:
    // 0x801DD62C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801DD630: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x801DD634: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801DD638: lw          $t8, 0x2C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X2C);
    // 0x801DD63C: jal         0x8001EB64
    // 0x801DD640: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_17;
    // 0x801DD640: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_17:
    // 0x801DD644: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801DD648: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801DD64C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801DD650: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801DD654: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801DD658: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801DD65C: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x801DD660: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801DD664: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801DD668: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801DD66C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801DD670: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801DD674: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x801DD678: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801DD67C: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801DD680: add.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f10.d + ctx->f2.d;
    // 0x801DD684: add.d       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f16.d + ctx->f8.d;
    // 0x801DD688: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x801DD68C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801DD690: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x801DD694: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801DD698: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801DD69C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801DD6A0: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x801DD6A4: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801DD6A8: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801DD6AC: add.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d + ctx->f18.d;
    // 0x801DD6B0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801DD6B4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801DD6B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DD6BC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801DD6C0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801DD6C4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801DD6C8: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801DD6CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DD6D0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801DD6D4: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x801DD6D8: add.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f8.d + ctx->f2.d;
    // 0x801DD6DC: sub.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f16.d - ctx->f6.d;
    // 0x801DD6E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DD6E4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801DD6E8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801DD6EC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801DD6F0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801DD6F4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801DD6F8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801DD6FC: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801DD700: add.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f8.d + ctx->f18.d;
    // 0x801DD704: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801DD708: jal         0x801C5A1C
    // 0x801DD70C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_18;
    // 0x801DD70C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_18:
    // 0x801DD710: beq         $v0, $zero, L_801DE454
    if (ctx->r2 == 0) {
        // 0x801DD714: lui         $t0, 0x801E
        ctx->r8 = S32(0X801E << 16);
            goto L_801DE454;
    }
    // 0x801DD714: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801DD718: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DD71C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801DD720: lhu         $t9, 0x4($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X4);
    // 0x801DD724: lbu         $t2, 0x35B($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X35B);
    // 0x801DD728: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801DD72C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801DD730: lbu         $t0, 0x16A0($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X16A0);
    // 0x801DD734: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x801DD738: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD73C: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x801DD740: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x801DD744: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x801DD748: lhu         $t4, 0x15E8($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X15E8);
    // 0x801DD74C: b           L_801DE454
    // 0x801DD750: sh          $t4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r12;
        goto L_801DE454;
    // 0x801DD750: sh          $t4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r12;
L_801DD754:
    // 0x801DD754: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x801DD758: jal         0x80011590
    // 0x801DD75C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_19;
    // 0x801DD75C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_19:
    // 0x801DD760: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD764: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x801DD768: lhu         $t6, 0x4($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD76C: beq         $t6, $v0, L_801DD7A4
    if (ctx->r14 == ctx->r2) {
        // 0x801DD770: nop
    
            goto L_801DD7A4;
    }
    // 0x801DD770: nop

    // 0x801DD774: jal         0x80011590
    // 0x801DD778: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_20;
    // 0x801DD778: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_20:
    // 0x801DD77C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD780: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x801DD784: lhu         $t8, 0x4($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD788: beq         $t8, $v0, L_801DD7A4
    if (ctx->r24 == ctx->r2) {
        // 0x801DD78C: nop
    
            goto L_801DD7A4;
    }
    // 0x801DD78C: nop

    // 0x801DD790: jal         0x80011590
    // 0x801DD794: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_21;
    // 0x801DD794: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_21:
    // 0x801DD798: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD79C: lhu         $t9, 0x4($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD7A0: bne         $t9, $v0, L_801DE454
    if (ctx->r25 != ctx->r2) {
        // 0x801DD7A4: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801DE454;
    }
L_801DD7A4:
    // 0x801DD7A4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DD7A8: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801DD7AC: lhu         $t0, 0x4($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X4);
    // 0x801DD7B0: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801DD7B4: lbu         $t3, 0x35B($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X35B);
    // 0x801DD7B8: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x801DD7BC: lbu         $t2, 0x16A0($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X16A0);
    // 0x801DD7C0: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x801DD7C4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801DD7C8: sll         $t1, $t2, 4
    ctx->r9 = S32(ctx->r10 << 4);
    // 0x801DD7CC: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x801DD7D0: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x801DD7D4: lhu         $t7, 0x15E8($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X15E8);
    // 0x801DD7D8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD7DC: sh          $t7, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r15;
    // 0x801DD7E0: lw          $t8, 0xE0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE0);
    // 0x801DD7E4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801DD7E8: jal         0x8001EAD0
    // 0x801DD7EC: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_22;
    // 0x801DD7EC: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_22:
    // 0x801DD7F0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801DD7F4: lw          $t0, -0x4330($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4330);
    // 0x801DD7F8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801DD7FC: lw          $t2, 0x2C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X2C);
    // 0x801DD800: jal         0x8001EB64
    // 0x801DD804: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_23;
    // 0x801DD804: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_23:
    // 0x801DD808: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801DD80C: lw          $t3, -0x4330($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4330);
    // 0x801DD810: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801DD814: lw          $t1, 0x2C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X2C);
    // 0x801DD818: jal         0x8001EAD0
    // 0x801DD81C: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_24;
    // 0x801DD81C: lh          $a0, 0x12($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X12);
    after_24:
    // 0x801DD820: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801DD824: lw          $t5, -0x4330($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4330);
    // 0x801DD828: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801DD82C: lw          $t4, 0x2C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X2C);
    // 0x801DD830: jal         0x8001EB64
    // 0x801DD834: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_25;
    // 0x801DD834: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_25:
    // 0x801DD838: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801DD83C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801DD840: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801DD844: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801DD848: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DD84C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801DD850: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x801DD854: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801DD858: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801DD85C: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801DD860: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801DD864: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DD868: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801DD86C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801DD870: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801DD874: add.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f6.d + ctx->f2.d;
    // 0x801DD878: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x801DD87C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x801DD880: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801DD884: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x801DD888: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DD88C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801DD890: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801DD894: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x801DD898: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801DD89C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801DD8A0: add.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f8.d + ctx->f18.d;
    // 0x801DD8A4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801DD8A8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801DD8AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801DD8B0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801DD8B4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801DD8B8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801DD8BC: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801DD8C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801DD8C4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801DD8C8: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801DD8CC: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x801DD8D0: sub.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f16.d - ctx->f10.d;
    // 0x801DD8D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801DD8D8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801DD8DC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801DD8E0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801DD8E4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801DD8E8: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801DD8EC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801DD8F0: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801DD8F4: add.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d + ctx->f18.d;
    // 0x801DD8F8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801DD8FC: jal         0x801C5A1C
    // 0x801DD900: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_26;
    // 0x801DD900: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_26:
    // 0x801DD904: beq         $v0, $zero, L_801DE454
    if (ctx->r2 == 0) {
        // 0x801DD908: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801DE454;
    }
    // 0x801DD908: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801DD90C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DD910: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801DD914: lhu         $t7, 0x4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4);
    // 0x801DD918: lbu         $t9, 0x35B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X35B);
    // 0x801DD91C: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801DD920: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801DD924: lbu         $t6, 0x16A0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X16A0);
    // 0x801DD928: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x801DD92C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD930: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x801DD934: addu        $t2, $t8, $t0
    ctx->r10 = ADD32(ctx->r24, ctx->r8);
    // 0x801DD938: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801DD93C: lhu         $t3, 0x15E8($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X15E8);
    // 0x801DD940: b           L_801DE454
    // 0x801DD944: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
        goto L_801DE454;
    // 0x801DD944: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
L_801DD948:
    // 0x801DD948: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x801DD94C: jal         0x80011590
    // 0x801DD950: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_27;
    // 0x801DD950: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_27:
    // 0x801DD954: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD958: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    // 0x801DD95C: lhu         $t5, 0x4($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD960: beql        $t5, $v0, L_801DD9A0
    if (ctx->r13 == ctx->r2) {
        // 0x801DD964: lw          $t9, 0x3C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X3C);
            goto L_801DD9A0;
    }
    goto skip_8;
    // 0x801DD964: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    skip_8:
    // 0x801DD968: jal         0x80011590
    // 0x801DD96C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_28;
    // 0x801DD96C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_28:
    // 0x801DD970: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD974: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x801DD978: lhu         $t4, 0x4($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD97C: beql        $t4, $v0, L_801DD9A0
    if (ctx->r12 == ctx->r2) {
        // 0x801DD980: lw          $t9, 0x3C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X3C);
            goto L_801DD9A0;
    }
    goto skip_9;
    // 0x801DD980: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    skip_9:
    // 0x801DD984: jal         0x80011590
    // 0x801DD988: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_29;
    // 0x801DD988: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_29:
    // 0x801DD98C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DD990: lhu         $t7, 0x4($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X4);
    // 0x801DD994: bnel        $t7, $v0, L_801DE458
    if (ctx->r15 != ctx->r2) {
        // 0x801DD998: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801DE458;
    }
    goto skip_10;
    // 0x801DD998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x801DD99C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
L_801DD9A0:
    // 0x801DD9A0: addiu       $t6, $zero, 0x68C
    ctx->r14 = ADD32(0, 0X68C);
    // 0x801DD9A4: b           L_801DE454
    // 0x801DD9A8: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
        goto L_801DE454;
    // 0x801DD9A8: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
L_801DD9AC:
    // 0x801DD9AC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801DD9B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DD9B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DD9B8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DD9BC: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801DD9C0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801DD9C4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DD9C8: nop

    // 0x801DD9CC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DD9D0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DD9D4: nop

    // 0x801DD9D8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DD9DC: beql        $a0, $zero, L_801DDA2C
    if (ctx->r4 == 0) {
        // 0x801DD9E0: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_801DDA2C;
    }
    goto skip_11;
    // 0x801DD9E0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_11:
    // 0x801DD9E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DD9E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DD9EC: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DD9F0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DD9F4: nop

    // 0x801DD9F8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DD9FC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DDA00: nop

    // 0x801DDA04: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DDA08: bne         $a0, $zero, L_801DDA20
    if (ctx->r4 != 0) {
        // 0x801DDA0C: nop
    
            goto L_801DDA20;
    }
    // 0x801DDA0C: nop

    // 0x801DDA10: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801DDA14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DDA18: b           L_801DDA38
    // 0x801DDA1C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DDA38;
    // 0x801DDA1C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DDA20:
    // 0x801DDA20: b           L_801DDA38
    // 0x801DDA24: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DDA38;
    // 0x801DDA24: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DDA28: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_801DDA2C:
    // 0x801DDA2C: nop

    // 0x801DDA30: bltz        $a0, L_801DDA20
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DDA34: nop
    
            goto L_801DDA20;
    }
    // 0x801DDA34: nop

L_801DDA38:
    // 0x801DDA38: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801DDA3C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DDA40: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x801DDA44: jal         0x80011590
    // 0x801DDA48: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_30;
    // 0x801DDA48: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_30:
    // 0x801DDA4C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DDA50: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801DDA54: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801DDA58: lhu         $t0, 0x4($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X4);
    // 0x801DDA5C: beq         $t0, $v0, L_801DDB08
    if (ctx->r8 == ctx->r2) {
        // 0x801DDA60: nop
    
            goto L_801DDB08;
    }
    // 0x801DDA60: nop

    // 0x801DDA64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DDA68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DDA6C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DDA70: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801DDA74: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801DDA78: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DDA7C: nop

    // 0x801DDA80: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DDA84: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DDA88: nop

    // 0x801DDA8C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DDA90: beql        $a0, $zero, L_801DDAE0
    if (ctx->r4 == 0) {
        // 0x801DDA94: mfc1        $a0, $f4
        ctx->r4 = (int32_t)ctx->f4.u32l;
            goto L_801DDAE0;
    }
    goto skip_12;
    // 0x801DDA94: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    skip_12:
    // 0x801DDA98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DDA9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DDAA0: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801DDAA4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DDAA8: nop

    // 0x801DDAAC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DDAB0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DDAB4: nop

    // 0x801DDAB8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DDABC: bne         $a0, $zero, L_801DDAD4
    if (ctx->r4 != 0) {
        // 0x801DDAC0: nop
    
            goto L_801DDAD4;
    }
    // 0x801DDAC0: nop

    // 0x801DDAC4: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x801DDAC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DDACC: b           L_801DDAEC
    // 0x801DDAD0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DDAEC;
    // 0x801DDAD0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DDAD4:
    // 0x801DDAD4: b           L_801DDAEC
    // 0x801DDAD8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DDAEC;
    // 0x801DDAD8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DDADC: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
L_801DDAE0:
    // 0x801DDAE0: nop

    // 0x801DDAE4: bltz        $a0, L_801DDAD4
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DDAE8: nop
    
            goto L_801DDAD4;
    }
    // 0x801DDAE8: nop

L_801DDAEC:
    // 0x801DDAEC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801DDAF0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DDAF4: jal         0x80011590
    // 0x801DDAF8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_31;
    // 0x801DDAF8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_31:
    // 0x801DDAFC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DDB00: lhu         $t3, 0x4($a3)
    ctx->r11 = MEM_HU(ctx->r7, 0X4);
    // 0x801DDB04: bne         $t3, $v0, L_801DE454
    if (ctx->r11 != ctx->r2) {
        // 0x801DDB08: lui         $t1, 0x801C
        ctx->r9 = S32(0X801C << 16);
            goto L_801DE454;
    }
L_801DDB08:
    // 0x801DDB08: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801DDB0C: lhu         $t1, -0x440C($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X440C);
    // 0x801DDB10: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801DDB14: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801DDB18: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x801DDB1C: lbu         $t5, 0x16A0($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X16A0);
    // 0x801DDB20: lbu         $t7, -0x40B5($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X40B5);
    // 0x801DDB24: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801DDB28: sll         $t4, $t5, 4
    ctx->r12 = S32(ctx->r13 << 4);
    // 0x801DDB2C: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x801DDB30: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x801DDB34: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x801DDB38: lhu         $t8, 0x15E0($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X15E0);
    // 0x801DDB3C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x801DDB40: addiu       $at, $zero, 0x672
    ctx->r1 = ADD32(0, 0X672);
    // 0x801DDB44: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x801DDB48: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x801DDB4C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x801DDB50: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
    // 0x801DDB54: beq         $v0, $at, L_801DDB74
    if (ctx->r2 == ctx->r1) {
        // 0x801DDB58: addiu       $at, $zero, 0x673
        ctx->r1 = ADD32(0, 0X673);
            goto L_801DDB74;
    }
    // 0x801DDB58: addiu       $at, $zero, 0x673
    ctx->r1 = ADD32(0, 0X673);
    // 0x801DDB5C: beq         $v0, $at, L_801DDB74
    if (ctx->r2 == ctx->r1) {
        // 0x801DDB60: addiu       $at, $zero, 0x674
        ctx->r1 = ADD32(0, 0X674);
            goto L_801DDB74;
    }
    // 0x801DDB60: addiu       $at, $zero, 0x674
    ctx->r1 = ADD32(0, 0X674);
    // 0x801DDB64: beq         $v0, $at, L_801DDB74
    if (ctx->r2 == ctx->r1) {
        // 0x801DDB68: addiu       $at, $zero, 0x675
        ctx->r1 = ADD32(0, 0X675);
            goto L_801DDB74;
    }
    // 0x801DDB68: addiu       $at, $zero, 0x675
    ctx->r1 = ADD32(0, 0X675);
    // 0x801DDB6C: bne         $v0, $at, L_801DDB80
    if (ctx->r2 != ctx->r1) {
        // 0x801DDB70: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_801DDB80;
    }
    // 0x801DDB70: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_801DDB74:
    // 0x801DDB74: addiu       $t3, $zero, 0x68D
    ctx->r11 = ADD32(0, 0X68D);
    // 0x801DDB78: b           L_801DE454
    // 0x801DDB7C: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
        goto L_801DE454;
    // 0x801DDB7C: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
L_801DDB80:
    // 0x801DDB80: addiu       $t5, $zero, 0x68C
    ctx->r13 = ADD32(0, 0X68C);
    // 0x801DDB84: b           L_801DE454
    // 0x801DDB88: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
        goto L_801DE454;
    // 0x801DDB88: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
L_801DDB8C:
    // 0x801DDB8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DDB90: jal         0x80011590
    // 0x801DDB94: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_32;
    // 0x801DDB94: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_32:
    // 0x801DDB98: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DDB9C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x801DDBA0: lhu         $t4, 0x4($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X4);
    // 0x801DDBA4: beq         $t4, $v0, L_801DDBC0
    if (ctx->r12 == ctx->r2) {
        // 0x801DDBA8: nop
    
            goto L_801DDBC0;
    }
    // 0x801DDBA8: nop

    // 0x801DDBAC: jal         0x80011590
    // 0x801DDBB0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_33;
    // 0x801DDBB0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_33:
    // 0x801DDBB4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DDBB8: lhu         $t6, 0x4($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X4);
    // 0x801DDBBC: bne         $t6, $v0, L_801DE454
    if (ctx->r14 != ctx->r2) {
        // 0x801DDBC0: lui         $t9, 0x801C
        ctx->r25 = S32(0X801C << 16);
            goto L_801DE454;
    }
L_801DDBC0:
    // 0x801DDBC0: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801DDBC4: lw          $t9, -0x4330($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4330);
    // 0x801DDBC8: lw          $t8, 0x2C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X2C);
    // 0x801DDBCC: jal         0x8001EAD0
    // 0x801DDBD0: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_34;
    // 0x801DDBD0: lh          $a0, 0x12($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X12);
    after_34:
    // 0x801DDBD4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801DDBD8: lw          $t0, -0x4330($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4330);
    // 0x801DDBDC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801DDBE0: lw          $t2, 0x2C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X2C);
    // 0x801DDBE4: jal         0x8001EB64
    // 0x801DDBE8: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_35;
    // 0x801DDBE8: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_35:
    // 0x801DDBEC: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801DDBF0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801DDBF4: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801DDBF8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801DDBFC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801DDC00: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801DDC04: mul.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x801DDC08: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801DDC0C: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x801DDC10: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801DDC14: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801DDC18: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x801DDC1C: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801DDC20: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801DDC24: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801DDC28: mul.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801DDC2C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x801DDC30: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801DDC34: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801DDC38: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801DDC3C: jal         0x801C5A1C
    // 0x801DDC40: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_36;
    // 0x801DDC40: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_36:
    // 0x801DDC44: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801DDC48: lbu         $v1, -0x40B6($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X40B6);
    // 0x801DDC4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801DDC50: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801DDC54: beq         $v1, $at, L_801DDC78
    if (ctx->r3 == ctx->r1) {
        // 0x801DDC58: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801DDC78;
    }
    // 0x801DDC58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801DDC5C: beq         $v1, $at, L_801DDC6C
    if (ctx->r3 == ctx->r1) {
        // 0x801DDC60: lw          $t1, 0x3C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X3C);
            goto L_801DDC6C;
    }
    // 0x801DDC60: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x801DDC64: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801DDC68: bne         $v1, $at, L_801DE454
    if (ctx->r3 != ctx->r1) {
        // 0x801DDC6C: addiu       $t3, $zero, 0x6A7
        ctx->r11 = ADD32(0, 0X6A7);
            goto L_801DE454;
    }
L_801DDC6C:
    // 0x801DDC6C: addiu       $t3, $zero, 0x6A7
    ctx->r11 = ADD32(0, 0X6A7);
    // 0x801DDC70: b           L_801DE454
    // 0x801DDC74: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
        goto L_801DE454;
    // 0x801DDC74: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
L_801DDC78:
    // 0x801DDC78: addiu       $t5, $zero, 0x6A8
    ctx->r13 = ADD32(0, 0X6A8);
    // 0x801DDC7C: b           L_801DE454
    // 0x801DDC80: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
        goto L_801DE454;
    // 0x801DDC80: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
L_801DDC84:
    // 0x801DDC84: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801DDC88: jal         0x80011590
    // 0x801DDC8C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_37;
    // 0x801DDC8C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_37:
    // 0x801DDC90: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DDC94: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801DDC98: lhu         $t4, 0x4($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X4);
    // 0x801DDC9C: bnel        $t4, $v0, L_801DE458
    if (ctx->r12 != ctx->r2) {
        // 0x801DDCA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801DE458;
    }
    goto skip_13;
    // 0x801DDCA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x801DDCA4: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x801DDCA8: lw          $t9, 0x2C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X2C);
    // 0x801DDCAC: jal         0x8001EAD0
    // 0x801DDCB0: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_38;
    // 0x801DDCB0: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_38:
    // 0x801DDCB4: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801DDCB8: lw          $t8, -0x4330($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4330);
    // 0x801DDCBC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801DDCC0: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x801DDCC4: jal         0x8001EB64
    // 0x801DDCC8: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_39;
    // 0x801DDCC8: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    after_39:
    // 0x801DDCCC: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801DDCD0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801DDCD4: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801DDCD8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801DDCDC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801DDCE0: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801DDCE4: mul.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x801DDCE8: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801DDCEC: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x801DDCF0: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801DDCF4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801DDCF8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x801DDCFC: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x801DDD00: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801DDD04: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801DDD08: mul.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x801DDD0C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x801DDD10: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801DDD14: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x801DDD18: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801DDD1C: jal         0x801C5A1C
    // 0x801DDD20: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_40;
    // 0x801DDD20: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_40:
    // 0x801DDD24: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801DDD28: lbu         $v1, -0x40B6($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X40B6);
    // 0x801DDD2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801DDD30: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x801DDD34: beq         $v1, $at, L_801DDD58
    if (ctx->r3 == ctx->r1) {
        // 0x801DDD38: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801DDD58;
    }
    // 0x801DDD38: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801DDD3C: beq         $v1, $at, L_801DDD4C
    if (ctx->r3 == ctx->r1) {
        // 0x801DDD40: lw          $t3, 0x3C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X3C);
            goto L_801DDD4C;
    }
    // 0x801DDD40: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x801DDD44: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801DDD48: bne         $v1, $at, L_801DE454
    if (ctx->r3 != ctx->r1) {
        // 0x801DDD4C: addiu       $t2, $zero, 0x6A7
        ctx->r10 = ADD32(0, 0X6A7);
            goto L_801DE454;
    }
L_801DDD4C:
    // 0x801DDD4C: addiu       $t2, $zero, 0x6A7
    ctx->r10 = ADD32(0, 0X6A7);
    // 0x801DDD50: b           L_801DE454
    // 0x801DDD54: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
        goto L_801DE454;
    // 0x801DDD54: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
L_801DDD58:
    // 0x801DDD58: addiu       $t1, $zero, 0x6A8
    ctx->r9 = ADD32(0, 0X6A8);
    // 0x801DDD5C: b           L_801DE454
    // 0x801DDD60: sh          $t1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r9;
        goto L_801DE454;
    // 0x801DDD60: sh          $t1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r9;
L_801DDD64:
    // 0x801DDD64: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801DDD68: jal         0x80011590
    // 0x801DDD6C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_41;
    // 0x801DDD6C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_41:
    // 0x801DDD70: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DDD74: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801DDD78: lhu         $t7, 0x4($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X4);
    // 0x801DDD7C: beq         $t7, $v0, L_801DDD98
    if (ctx->r15 == ctx->r2) {
        // 0x801DDD80: nop
    
            goto L_801DDD98;
    }
    // 0x801DDD80: nop

    // 0x801DDD84: jal         0x80011590
    // 0x801DDD88: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_42;
    // 0x801DDD88: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_42:
    // 0x801DDD8C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DDD90: lhu         $t4, 0x4($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X4);
    // 0x801DDD94: bne         $t4, $v0, L_801DE454
    if (ctx->r12 != ctx->r2) {
        // 0x801DDD98: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_801DE454;
    }
L_801DDD98:
    // 0x801DDD98: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801DDD9C: lw          $t6, -0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4330);
    // 0x801DDDA0: lw          $t9, 0x2C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X2C);
    // 0x801DDDA4: jal         0x8001EAD0
    // 0x801DDDA8: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_43;
    // 0x801DDDA8: lh          $a0, 0x12($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X12);
    after_43:
    // 0x801DDDAC: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801DDDB0: lw          $t8, -0x4330($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4330);
    // 0x801DDDB4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801DDDB8: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x801DDDBC: jal         0x8001EB64
    // 0x801DDDC0: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_44;
    // 0x801DDDC0: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    after_44:
    // 0x801DDDC4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801DDDC8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801DDDCC: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801DDDD0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801DDDD4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801DDDD8: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801DDDDC: mul.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801DDDE0: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801DDDE4: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x801DDDE8: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801DDDEC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801DDDF0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x801DDDF4: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801DDDF8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x801DDDFC: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801DDE00: mul.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x801DDE04: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x801DDE08: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801DDE0C: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x801DDE10: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801DDE14: jal         0x801C5A1C
    // 0x801DDE18: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_45;
    // 0x801DDE18: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_45:
    // 0x801DDE1C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801DDE20: lbu         $v1, -0x40B6($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X40B6);
    // 0x801DDE24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801DDE28: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x801DDE2C: beq         $v1, $at, L_801DDE50
    if (ctx->r3 == ctx->r1) {
        // 0x801DDE30: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801DDE50;
    }
    // 0x801DDE30: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801DDE34: beq         $v1, $at, L_801DDE44
    if (ctx->r3 == ctx->r1) {
        // 0x801DDE38: lw          $t3, 0x3C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X3C);
            goto L_801DDE44;
    }
    // 0x801DDE38: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x801DDE3C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801DDE40: bne         $v1, $at, L_801DE454
    if (ctx->r3 != ctx->r1) {
        // 0x801DDE44: addiu       $t2, $zero, 0x6A7
        ctx->r10 = ADD32(0, 0X6A7);
            goto L_801DE454;
    }
L_801DDE44:
    // 0x801DDE44: addiu       $t2, $zero, 0x6A7
    ctx->r10 = ADD32(0, 0X6A7);
    // 0x801DDE48: b           L_801DE454
    // 0x801DDE4C: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
        goto L_801DE454;
    // 0x801DDE4C: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
L_801DDE50:
    // 0x801DDE50: addiu       $t1, $zero, 0x6A8
    ctx->r9 = ADD32(0, 0X6A8);
    // 0x801DDE54: b           L_801DE454
    // 0x801DDE58: sh          $t1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r9;
        goto L_801DE454;
    // 0x801DDE58: sh          $t1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r9;
L_801DDE5C:
    // 0x801DDE5C: lhu         $t7, 0x4($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X4);
    // 0x801DDE60: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801DDE64: andi        $t4, $t7, 0x2
    ctx->r12 = ctx->r15 & 0X2;
    // 0x801DDE68: beq         $t4, $zero, L_801DDF68
    if (ctx->r12 == 0) {
        // 0x801DDE6C: nop
    
            goto L_801DDF68;
    }
    // 0x801DDE6C: nop

    // 0x801DDE70: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801DDE74: jal         0x80011590
    // 0x801DDE78: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_46;
    // 0x801DDE78: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_46:
    // 0x801DDE7C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DDE80: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x801DDE84: lhu         $t6, 0x4($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X4);
    // 0x801DDE88: beq         $t6, $v0, L_801DDEA4
    if (ctx->r14 == ctx->r2) {
        // 0x801DDE8C: nop
    
            goto L_801DDEA4;
    }
    // 0x801DDE8C: nop

    // 0x801DDE90: jal         0x80011590
    // 0x801DDE94: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_47;
    // 0x801DDE94: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_47:
    // 0x801DDE98: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DDE9C: lhu         $t9, 0x4($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X4);
    // 0x801DDEA0: bne         $t9, $v0, L_801DE454
    if (ctx->r25 != ctx->r2) {
        // 0x801DDEA4: lui         $t8, 0x801C
        ctx->r24 = S32(0X801C << 16);
            goto L_801DE454;
    }
L_801DDEA4:
    // 0x801DDEA4: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801DDEA8: lw          $t8, -0x4330($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4330);
    // 0x801DDEAC: lw          $t0, 0x2C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X2C);
    // 0x801DDEB0: jal         0x8001EAD0
    // 0x801DDEB4: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_48;
    // 0x801DDEB4: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    after_48:
    // 0x801DDEB8: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801DDEBC: lw          $t2, -0x4330($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4330);
    // 0x801DDEC0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801DDEC4: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801DDEC8: jal         0x8001EB64
    // 0x801DDECC: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_49;
    // 0x801DDECC: lh          $a0, 0x12($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X12);
    after_49:
    // 0x801DDED0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801DDED4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801DDED8: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x801DDEDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801DDEE0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801DDEE4: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801DDEE8: mul.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x801DDEEC: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801DDEF0: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x801DDEF4: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801DDEF8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801DDEFC: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x801DDF00: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801DDF04: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801DDF08: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801DDF0C: mul.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x801DDF10: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x801DDF14: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801DDF18: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801DDF1C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801DDF20: jal         0x801C5A1C
    // 0x801DDF24: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_50;
    // 0x801DDF24: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_50:
    // 0x801DDF28: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801DDF2C: lbu         $v1, -0x40B6($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X40B6);
    // 0x801DDF30: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801DDF34: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x801DDF38: beq         $v1, $at, L_801DDF5C
    if (ctx->r3 == ctx->r1) {
        // 0x801DDF3C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801DDF5C;
    }
    // 0x801DDF3C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801DDF40: beq         $v1, $at, L_801DDF50
    if (ctx->r3 == ctx->r1) {
        // 0x801DDF44: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_801DDF50;
    }
    // 0x801DDF44: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x801DDF48: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801DDF4C: bne         $v1, $at, L_801DE454
    if (ctx->r3 != ctx->r1) {
        // 0x801DDF50: addiu       $t1, $zero, 0x6A7
        ctx->r9 = ADD32(0, 0X6A7);
            goto L_801DE454;
    }
L_801DDF50:
    // 0x801DDF50: addiu       $t1, $zero, 0x6A7
    ctx->r9 = ADD32(0, 0X6A7);
    // 0x801DDF54: b           L_801DE454
    // 0x801DDF58: sh          $t1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r9;
        goto L_801DE454;
    // 0x801DDF58: sh          $t1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r9;
L_801DDF5C:
    // 0x801DDF5C: addiu       $t7, $zero, 0x6A8
    ctx->r15 = ADD32(0, 0X6A8);
    // 0x801DDF60: b           L_801DE454
    // 0x801DDF64: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
        goto L_801DE454;
    // 0x801DDF64: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
L_801DDF68:
    // 0x801DDF68: jal         0x80011590
    // 0x801DDF6C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_51;
    // 0x801DDF6C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_51:
    // 0x801DDF70: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DDF74: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x801DDF78: lhu         $t6, 0x4($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X4);
    // 0x801DDF7C: beq         $t6, $v0, L_801DDF98
    if (ctx->r14 == ctx->r2) {
        // 0x801DDF80: nop
    
            goto L_801DDF98;
    }
    // 0x801DDF80: nop

    // 0x801DDF84: jal         0x80011590
    // 0x801DDF88: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_52;
    // 0x801DDF88: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_52:
    // 0x801DDF8C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DDF90: lhu         $t9, 0x4($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X4);
    // 0x801DDF94: bne         $t9, $v0, L_801DE454
    if (ctx->r25 != ctx->r2) {
        // 0x801DDF98: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801DE454;
    }
L_801DDF98:
    // 0x801DDF98: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DDF9C: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801DDFA0: lhu         $t8, 0x4($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X4);
    // 0x801DDFA4: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801DDFA8: lbu         $t3, 0x35B($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X35B);
    // 0x801DDFAC: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x801DDFB0: lbu         $t0, 0x16A0($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X16A0);
    // 0x801DDFB4: sll         $t1, $t3, 1
    ctx->r9 = S32(ctx->r11 << 1);
    // 0x801DDFB8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801DDFBC: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x801DDFC0: addu        $t5, $t2, $t1
    ctx->r13 = ADD32(ctx->r10, ctx->r9);
    // 0x801DDFC4: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DDFC8: lhu         $t7, 0x15E8($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X15E8);
    // 0x801DDFCC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x801DDFD0: b           L_801DE454
    // 0x801DDFD4: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
        goto L_801DE454;
    // 0x801DDFD4: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
L_801DDFD8:
    // 0x801DDFD8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801DDFDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DDFE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DDFE4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DDFE8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801DDFEC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801DDFF0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DDFF4: nop

    // 0x801DDFF8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801DDFFC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DE000: nop

    // 0x801DE004: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DE008: beql        $a0, $zero, L_801DE058
    if (ctx->r4 == 0) {
        // 0x801DE00C: mfc1        $a0, $f10
        ctx->r4 = (int32_t)ctx->f10.u32l;
            goto L_801DE058;
    }
    goto skip_14;
    // 0x801DE00C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    skip_14:
    // 0x801DE010: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DE014: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DE018: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801DE01C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DE020: nop

    // 0x801DE024: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DE028: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DE02C: nop

    // 0x801DE030: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DE034: bne         $a0, $zero, L_801DE04C
    if (ctx->r4 != 0) {
        // 0x801DE038: nop
    
            goto L_801DE04C;
    }
    // 0x801DE038: nop

    // 0x801DE03C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x801DE040: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DE044: b           L_801DE064
    // 0x801DE048: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DE064;
    // 0x801DE048: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DE04C:
    // 0x801DE04C: b           L_801DE064
    // 0x801DE050: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DE064;
    // 0x801DE050: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DE054: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
L_801DE058:
    // 0x801DE058: nop

    // 0x801DE05C: bltz        $a0, L_801DE04C
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DE060: nop
    
            goto L_801DE04C;
    }
    // 0x801DE060: nop

L_801DE064:
    // 0x801DE064: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801DE068: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DE06C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x801DE070: jal         0x80011590
    // 0x801DE074: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_53;
    // 0x801DE074: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_53:
    // 0x801DE078: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DE07C: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801DE080: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x801DE084: lhu         $t9, 0x4($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X4);
    // 0x801DE088: beql        $t9, $v0, L_801DE210
    if (ctx->r25 == ctx->r2) {
        // 0x801DE08C: lw          $t9, 0x3C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X3C);
            goto L_801DE210;
    }
    goto skip_15;
    // 0x801DE08C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    skip_15:
    // 0x801DE090: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DE094: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DE098: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DE09C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801DE0A0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801DE0A4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DE0A8: nop

    // 0x801DE0AC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DE0B0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DE0B4: nop

    // 0x801DE0B8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DE0BC: beql        $a0, $zero, L_801DE10C
    if (ctx->r4 == 0) {
        // 0x801DE0C0: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_801DE10C;
    }
    goto skip_16;
    // 0x801DE0C0: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_16:
    // 0x801DE0C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DE0C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DE0CC: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801DE0D0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DE0D4: nop

    // 0x801DE0D8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801DE0DC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DE0E0: nop

    // 0x801DE0E4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DE0E8: bne         $a0, $zero, L_801DE100
    if (ctx->r4 != 0) {
        // 0x801DE0EC: nop
    
            goto L_801DE100;
    }
    // 0x801DE0EC: nop

    // 0x801DE0F0: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x801DE0F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DE0F8: b           L_801DE118
    // 0x801DE0FC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DE118;
    // 0x801DE0FC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DE100:
    // 0x801DE100: b           L_801DE118
    // 0x801DE104: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DE118;
    // 0x801DE104: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DE108: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_801DE10C:
    // 0x801DE10C: nop

    // 0x801DE110: bltz        $a0, L_801DE100
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DE114: nop
    
            goto L_801DE100;
    }
    // 0x801DE114: nop

L_801DE118:
    // 0x801DE118: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801DE11C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DE120: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x801DE124: jal         0x80011590
    // 0x801DE128: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_54;
    // 0x801DE128: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_54:
    // 0x801DE12C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DE130: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801DE134: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801DE138: lhu         $t0, 0x4($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X4);
    // 0x801DE13C: bnel        $t0, $v0, L_801DE158
    if (ctx->r8 != ctx->r2) {
        // 0x801DE140: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_801DE158;
    }
    goto skip_17;
    // 0x801DE140: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_17:
    // 0x801DE144: lhu         $t3, 0x6($a3)
    ctx->r11 = MEM_HU(ctx->r7, 0X6);
    // 0x801DE148: andi        $t2, $t3, 0x2
    ctx->r10 = ctx->r11 & 0X2;
    // 0x801DE14C: beql        $t2, $zero, L_801DE210
    if (ctx->r10 == 0) {
        // 0x801DE150: lw          $t9, 0x3C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X3C);
            goto L_801DE210;
    }
    goto skip_18;
    // 0x801DE150: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    skip_18:
    // 0x801DE154: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_801DE158:
    // 0x801DE158: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DE15C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DE160: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801DE164: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801DE168: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DE16C: nop

    // 0x801DE170: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DE174: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DE178: nop

    // 0x801DE17C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DE180: beql        $a0, $zero, L_801DE1D0
    if (ctx->r4 == 0) {
        // 0x801DE184: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_801DE1D0;
    }
    goto skip_19;
    // 0x801DE184: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_19:
    // 0x801DE188: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DE18C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DE190: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DE194: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DE198: nop

    // 0x801DE19C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DE1A0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DE1A4: nop

    // 0x801DE1A8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DE1AC: bne         $a0, $zero, L_801DE1C4
    if (ctx->r4 != 0) {
        // 0x801DE1B0: nop
    
            goto L_801DE1C4;
    }
    // 0x801DE1B0: nop

    // 0x801DE1B4: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801DE1B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DE1BC: b           L_801DE1DC
    // 0x801DE1C0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DE1DC;
    // 0x801DE1C0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DE1C4:
    // 0x801DE1C4: b           L_801DE1DC
    // 0x801DE1C8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DE1DC;
    // 0x801DE1C8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DE1CC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_801DE1D0:
    // 0x801DE1D0: nop

    // 0x801DE1D4: bltz        $a0, L_801DE1C4
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DE1D8: nop
    
            goto L_801DE1C4;
    }
    // 0x801DE1D8: nop

L_801DE1DC:
    // 0x801DE1DC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801DE1E0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DE1E4: jal         0x80011590
    // 0x801DE1E8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_55;
    // 0x801DE1E8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_55:
    // 0x801DE1EC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DE1F0: lhu         $t5, 0x4($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X4);
    // 0x801DE1F4: bnel        $t5, $v0, L_801DE458
    if (ctx->r13 != ctx->r2) {
        // 0x801DE1F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801DE458;
    }
    goto skip_20;
    // 0x801DE1F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_20:
    // 0x801DE1FC: lhu         $t7, 0x6($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X6);
    // 0x801DE200: andi        $t4, $t7, 0x2
    ctx->r12 = ctx->r15 & 0X2;
    // 0x801DE204: beql        $t4, $zero, L_801DE458
    if (ctx->r12 == 0) {
        // 0x801DE208: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801DE458;
    }
    goto skip_21;
    // 0x801DE208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_21:
    // 0x801DE20C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
L_801DE210:
    // 0x801DE210: addiu       $t6, $zero, 0x677
    ctx->r14 = ADD32(0, 0X677);
    // 0x801DE214: b           L_801DE454
    // 0x801DE218: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
        goto L_801DE454;
    // 0x801DE218: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
L_801DE21C:
    // 0x801DE21C: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x801DE220: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DE224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DE228: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DE22C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801DE230: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801DE234: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DE238: nop

    // 0x801DE23C: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DE240: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DE244: nop

    // 0x801DE248: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DE24C: beql        $a0, $zero, L_801DE29C
    if (ctx->r4 == 0) {
        // 0x801DE250: mfc1        $a0, $f4
        ctx->r4 = (int32_t)ctx->f4.u32l;
            goto L_801DE29C;
    }
    goto skip_22;
    // 0x801DE250: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    skip_22:
    // 0x801DE254: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DE258: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DE25C: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801DE260: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DE264: nop

    // 0x801DE268: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DE26C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DE270: nop

    // 0x801DE274: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DE278: bne         $a0, $zero, L_801DE290
    if (ctx->r4 != 0) {
        // 0x801DE27C: nop
    
            goto L_801DE290;
    }
    // 0x801DE27C: nop

    // 0x801DE280: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x801DE284: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DE288: b           L_801DE2A8
    // 0x801DE28C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DE2A8;
    // 0x801DE28C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DE290:
    // 0x801DE290: b           L_801DE2A8
    // 0x801DE294: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DE2A8;
    // 0x801DE294: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DE298: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
L_801DE29C:
    // 0x801DE29C: nop

    // 0x801DE2A0: bltz        $a0, L_801DE290
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DE2A4: nop
    
            goto L_801DE290;
    }
    // 0x801DE2A4: nop

L_801DE2A8:
    // 0x801DE2A8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801DE2AC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DE2B0: jal         0x80011590
    // 0x801DE2B4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_56;
    // 0x801DE2B4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_56:
    // 0x801DE2B8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DE2BC: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x801DE2C0: lhu         $t0, 0x4($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X4);
    // 0x801DE2C4: bne         $t0, $v0, L_801DE454
    if (ctx->r8 != ctx->r2) {
        // 0x801DE2C8: addiu       $t3, $zero, 0x677
        ctx->r11 = ADD32(0, 0X677);
            goto L_801DE454;
    }
    // 0x801DE2C8: addiu       $t3, $zero, 0x677
    ctx->r11 = ADD32(0, 0X677);
    // 0x801DE2CC: b           L_801DE454
    // 0x801DE2D0: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
        goto L_801DE454;
    // 0x801DE2D0: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
L_801DE2D4:
    // 0x801DE2D4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801DE2D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DE2DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DE2E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DE2E4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801DE2E8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801DE2EC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DE2F0: nop

    // 0x801DE2F4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801DE2F8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DE2FC: nop

    // 0x801DE300: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DE304: beql        $a0, $zero, L_801DE354
    if (ctx->r4 == 0) {
        // 0x801DE308: mfc1        $a0, $f10
        ctx->r4 = (int32_t)ctx->f10.u32l;
            goto L_801DE354;
    }
    goto skip_23;
    // 0x801DE308: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    skip_23:
    // 0x801DE30C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DE310: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DE314: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801DE318: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DE31C: nop

    // 0x801DE320: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DE324: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DE328: nop

    // 0x801DE32C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DE330: bne         $a0, $zero, L_801DE348
    if (ctx->r4 != 0) {
        // 0x801DE334: nop
    
            goto L_801DE348;
    }
    // 0x801DE334: nop

    // 0x801DE338: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x801DE33C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DE340: b           L_801DE360
    // 0x801DE344: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DE360;
    // 0x801DE344: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DE348:
    // 0x801DE348: b           L_801DE360
    // 0x801DE34C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DE360;
    // 0x801DE34C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DE350: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
L_801DE354:
    // 0x801DE354: nop

    // 0x801DE358: bltz        $a0, L_801DE348
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DE35C: nop
    
            goto L_801DE348;
    }
    // 0x801DE35C: nop

L_801DE360:
    // 0x801DE360: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801DE364: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DE368: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x801DE36C: jal         0x80011590
    // 0x801DE370: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_57;
    // 0x801DE370: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_57:
    // 0x801DE374: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DE378: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801DE37C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801DE380: lhu         $t5, 0x4($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X4);
    // 0x801DE384: beql        $t5, $v0, L_801DE438
    if (ctx->r13 == ctx->r2) {
        // 0x801DE388: lw          $t9, 0x3C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X3C);
            goto L_801DE438;
    }
    goto skip_24;
    // 0x801DE388: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    skip_24:
    // 0x801DE38C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DE390: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DE394: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DE398: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801DE39C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801DE3A0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DE3A4: nop

    // 0x801DE3A8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DE3AC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DE3B0: nop

    // 0x801DE3B4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DE3B8: beql        $a0, $zero, L_801DE408
    if (ctx->r4 == 0) {
        // 0x801DE3BC: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_801DE408;
    }
    goto skip_25;
    // 0x801DE3BC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_25:
    // 0x801DE3C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DE3C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DE3C8: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801DE3CC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DE3D0: nop

    // 0x801DE3D4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801DE3D8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DE3DC: nop

    // 0x801DE3E0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DE3E4: bne         $a0, $zero, L_801DE3FC
    if (ctx->r4 != 0) {
        // 0x801DE3E8: nop
    
            goto L_801DE3FC;
    }
    // 0x801DE3E8: nop

    // 0x801DE3EC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x801DE3F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DE3F4: b           L_801DE414
    // 0x801DE3F8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DE414;
    // 0x801DE3F8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DE3FC:
    // 0x801DE3FC: b           L_801DE414
    // 0x801DE400: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DE414;
    // 0x801DE400: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DE404: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_801DE408:
    // 0x801DE408: nop

    // 0x801DE40C: bltz        $a0, L_801DE3FC
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DE410: nop
    
            goto L_801DE3FC;
    }
    // 0x801DE410: nop

L_801DE414:
    // 0x801DE414: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801DE418: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DE41C: jal         0x80011590
    // 0x801DE420: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_58;
    // 0x801DE420: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_58:
    // 0x801DE424: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801DE428: lhu         $t4, 0x4($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X4);
    // 0x801DE42C: bnel        $t4, $v0, L_801DE458
    if (ctx->r12 != ctx->r2) {
        // 0x801DE430: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801DE458;
    }
    goto skip_26;
    // 0x801DE430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_26:
    // 0x801DE434: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
L_801DE438:
    // 0x801DE438: addiu       $t6, $zero, 0x677
    ctx->r14 = ADD32(0, 0X677);
    // 0x801DE43C: b           L_801DE454
    // 0x801DE440: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
        goto L_801DE454;
    // 0x801DE440: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
L_801DE444:
    // 0x801DE444: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801DE448: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x801DE44C: jal         0x801DCCB0
    // 0x801DE450: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(0x801DCCB0)(rdram, ctx);
        goto after_59;
    // 0x801DE450: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_59:
L_801DE454:
    // 0x801DE454: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801DE458:
    // 0x801DE458: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801DE45C: jr          $ra
    // 0x801DE460: nop

    return;
    // 0x801DE460: nop

;}
RECOMP_FUNC void M8_FUN_801de464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DE464: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801DE468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DE46C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801DE470: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801DE474: jal         0x801DC250
    // 0x801DE478: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DC250)(rdram, ctx);
        goto after_0;
    // 0x801DE478: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x801DE47C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DE480: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801DE484: beq         $v0, $at, L_801DE49C
    if (ctx->r2 == ctx->r1) {
        // 0x801DE488: andi        $a1, $v0, 0xFF
        ctx->r5 = ctx->r2 & 0XFF;
            goto L_801DE49C;
    }
    // 0x801DE488: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x801DE48C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801DE490: beq         $v0, $at, L_801DE49C
    if (ctx->r2 == ctx->r1) {
        // 0x801DE494: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801DE49C;
    }
    // 0x801DE494: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801DE498: bne         $v0, $at, L_801DE57C
    if (ctx->r2 != ctx->r1) {
        // 0x801DE49C: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801DE57C;
    }
L_801DE49C:
    // 0x801DE49C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DE4A0: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801DE4A4: lhu         $t6, 0x4($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X4);
    // 0x801DE4A8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801DE4AC: lbu         $t9, 0x35B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X35B);
    // 0x801DE4B0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DE4B4: lbu         $t7, 0x16A0($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X16A0);
    // 0x801DE4B8: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x801DE4BC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801DE4C0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x801DE4C4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x801DE4C8: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x801DE4CC: lhu         $a0, 0x15E0($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X15E0);
    // 0x801DE4D0: sb          $a1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r5;
    // 0x801DE4D4: jal         0x801DCC50
    // 0x801DE4D8: sh          $a0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801DCC50)(rdram, ctx);
        goto after_1;
    // 0x801DE4D8: sh          $a0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x801DE4DC: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    // 0x801DE4E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801DE4E4: lhu         $a0, 0x1C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1C);
    // 0x801DE4E8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801DE4EC: bne         $a1, $at, L_801DE504
    if (ctx->r5 != ctx->r1) {
        // 0x801DE4F0: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_801DE504;
    }
    // 0x801DE4F0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x801DE4F4: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x801DE4F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DE4FC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x801DE500: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
L_801DE504:
    // 0x801DE504: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801DE508: bne         $v1, $at, L_801DE518
    if (ctx->r3 != ctx->r1) {
        // 0x801DE50C: sll         $t4, $v0, 1
        ctx->r12 = S32(ctx->r2 << 1);
            goto L_801DE518;
    }
    // 0x801DE50C: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x801DE510: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x801DE514: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_801DE518:
    // 0x801DE518: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x801DE51C: bne         $at, $zero, L_801DE52C
    if (ctx->r1 != 0) {
        // 0x801DE520: sll         $t3, $a1, 2
        ctx->r11 = S32(ctx->r5 << 2);
            goto L_801DE52C;
    }
    // 0x801DE520: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x801DE524: b           L_801DE548
    // 0x801DE528: sh          $a0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r4;
        goto L_801DE548;
    // 0x801DE528: sh          $a0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r4;
L_801DE52C:
    // 0x801DE52C: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x801DE530: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DE534: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x801DE538: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801DE53C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DE540: lhu         $t6, 0x177C($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X177C);
    // 0x801DE544: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_801DE548:
    // 0x801DE548: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801DE54C: lui         $at, 0x190
    ctx->r1 = S32(0X190 << 16);
    // 0x801DE550: ori         $at, $at, 0x220
    ctx->r1 = ctx->r1 | 0X220;
    // 0x801DE554: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x801DE558: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x801DE55C: beq         $v0, $at, L_801DE56C
    if (ctx->r2 == ctx->r1) {
        // 0x801DE560: lui         $at, 0x190
        ctx->r1 = S32(0X190 << 16);
            goto L_801DE56C;
    }
    // 0x801DE560: lui         $at, 0x190
    ctx->r1 = S32(0X190 << 16);
    // 0x801DE564: ori         $at, $at, 0x1E6
    ctx->r1 = ctx->r1 | 0X1E6;
    // 0x801DE568: bne         $v0, $at, L_801DE580
    if (ctx->r2 != ctx->r1) {
        // 0x801DE56C: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801DE580;
    }
L_801DE56C:
    // 0x801DE56C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE570: lwc1        $f6, 0x3F2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X3F2C);
    // 0x801DE574: b           L_801DE580
    // 0x801DE578: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
        goto L_801DE580;
    // 0x801DE578: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
L_801DE57C:
    // 0x801DE57C: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
L_801DE580:
    // 0x801DE580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DE584: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801DE588: jr          $ra
    // 0x801DE58C: nop

    return;
    // 0x801DE58C: nop

;}
RECOMP_FUNC void M8_FUN_801de590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DE590: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801DE594: lw          $t6, -0x4334($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4334);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801de598(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801de598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DE598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DE59C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DE5A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DE5A4: bne         $a0, $t6, L_801DE5C4
    if (ctx->r4 != ctx->r14) {
        // 0x801DE5A8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_801DE5C4;
    }
    // 0x801DE5A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801DE5AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801DE5B0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x801DE5B4: jal         0x801DCCB0
    // 0x801DE5B8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    LOOKUP_FUNC(0x801DCCB0)(rdram, ctx);
        goto after_0;
    // 0x801DE5B8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x801DE5BC: b           L_801DE5D8
    // 0x801DE5C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801DE5D8;
    // 0x801DE5C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DE5C4:
    // 0x801DE5C4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801DE5C8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801DE5CC: jal         0x801DE464
    // 0x801DE5D0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    LOOKUP_FUNC(0x801DE464)(rdram, ctx);
        goto after_1;
    // 0x801DE5D0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_1:
    // 0x801DE5D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801DE5D8:
    // 0x801DE5D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DE5DC: jr          $ra
    // 0x801DE5E0: nop

    return;
    // 0x801DE5E0: nop

;}
RECOMP_FUNC void M8_FUN_801de5e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DE5E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801DE5E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DE5EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801DE5F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801DE5F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801DE5F8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801DE5FC: jal         0x801DC250
    // 0x801DE600: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x801DC250)(rdram, ctx);
        goto after_0;
    // 0x801DE600: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x801DE604: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801DE608: lw          $t7, -0x4334($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4334);
    // 0x801DE60C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801DE610: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x801DE614: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x801DE618: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x801DE61C: bne         $t6, $t7, L_801DE628
    if (ctx->r14 != ctx->r15) {
        // 0x801DE620: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_801DE628;
    }
    // 0x801DE620: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801DE624: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_801DE628:
    // 0x801DE628: beq         $v0, $zero, L_801DE6E0
    if (ctx->r2 == 0) {
        // 0x801DE62C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801DE6E0;
    }
    // 0x801DE62C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801DE630: bne         $v0, $at, L_801DE648
    if (ctx->r2 != ctx->r1) {
        // 0x801DE634: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801DE648;
    }
    // 0x801DE634: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801DE638: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x801DE63C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DE640: nop

    // 0x801DE644: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
L_801DE648:
    // 0x801DE648: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801DE64C: bne         $a2, $v1, L_801DE65C
    if (ctx->r6 != ctx->r3) {
        // 0x801DE650: sll         $t8, $a1, 4
        ctx->r24 = S32(ctx->r5 << 4);
            goto L_801DE65C;
    }
    // 0x801DE650: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x801DE654: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x801DE658: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
L_801DE65C:
    // 0x801DE65C: lbu         $v0, 0x2B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2B);
    // 0x801DE660: sll         $t2, $a0, 1
    ctx->r10 = S32(ctx->r4 << 1);
    // 0x801DE664: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801DE668: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x801DE66C: bne         $a2, $zero, L_801DE678
    if (ctx->r6 != 0) {
        // 0x801DE670: nop
    
            goto L_801DE678;
    }
    // 0x801DE670: nop

    // 0x801DE674: break       7
    do_break(2149443188);
L_801DE678:
    // 0x801DE678: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801DE67C: bne         $a2, $at, L_801DE690
    if (ctx->r6 != ctx->r1) {
        // 0x801DE680: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801DE690;
    }
    // 0x801DE680: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DE684: bne         $v0, $at, L_801DE690
    if (ctx->r2 != ctx->r1) {
        // 0x801DE688: nop
    
            goto L_801DE690;
    }
    // 0x801DE688: nop

    // 0x801DE68C: break       6
    do_break(2149443212);
L_801DE690:
    // 0x801DE690: mfhi        $v0
    ctx->r2 = hi;
    // 0x801DE694: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x801DE698: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x801DE69C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x801DE6A0: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x801DE6A4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801DE6A8: lhu         $t4, 0x179E($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X179E);
    // 0x801DE6AC: lui         $at, 0x190
    ctx->r1 = S32(0X190 << 16);
    // 0x801DE6B0: ori         $at, $at, 0x220
    ctx->r1 = ctx->r1 | 0X220;
    // 0x801DE6B4: sh          $t4, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r12;
    // 0x801DE6B8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x801DE6BC: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x801DE6C0: beq         $v1, $at, L_801DE6D0
    if (ctx->r3 == ctx->r1) {
        // 0x801DE6C4: lui         $at, 0x190
        ctx->r1 = S32(0X190 << 16);
            goto L_801DE6D0;
    }
    // 0x801DE6C4: lui         $at, 0x190
    ctx->r1 = S32(0X190 << 16);
    // 0x801DE6C8: ori         $at, $at, 0x1E6
    ctx->r1 = ctx->r1 | 0X1E6;
    // 0x801DE6CC: bne         $v1, $at, L_801DE6E4
    if (ctx->r3 != ctx->r1) {
        // 0x801DE6D0: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801DE6E4;
    }
L_801DE6D0:
    // 0x801DE6D0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE6D4: lwc1        $f6, 0x3F30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X3F30);
    // 0x801DE6D8: b           L_801DE6E4
    // 0x801DE6DC: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
        goto L_801DE6E4;
    // 0x801DE6DC: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
L_801DE6E0:
    // 0x801DE6E0: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
L_801DE6E4:
    // 0x801DE6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DE6E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801DE6EC: jr          $ra
    // 0x801DE6F0: nop

    return;
    // 0x801DE6F0: nop

;}
RECOMP_FUNC void M8_FUN_801de6f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DE6F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801DE6F8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801DE6FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801DE700: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801DE704: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801DE708: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x801DE70C: addiu       $t7, $t7, 0x2008
    ctx->r15 = ADD32(ctx->r15, 0X2008);
    // 0x801DE710: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801DE714: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801DE718: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x801DE71C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801DE720: addiu       $a1, $a1, 0x1FD0
    ctx->r5 = ADD32(ctx->r5, 0X1FD0);
    // 0x801DE724: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801DE728: jal         0x801DC700
    // 0x801DE72C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    LOOKUP_FUNC(0x801DC700)(rdram, ctx);
        goto after_0;
    // 0x801DE72C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    after_0:
    // 0x801DE730: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x801DE734: bne         $v1, $zero, L_801DE744
    if (ctx->r3 != 0) {
        // 0x801DE738: andi        $t1, $v0, 0xFF
        ctx->r9 = ctx->r2 & 0XFF;
            goto L_801DE744;
    }
    // 0x801DE738: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x801DE73C: b           L_801DE7DC
    // 0x801DE740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801DE7DC;
    // 0x801DE740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801DE744:
    // 0x801DE744: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x801DE748: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801DE74C: addiu       $t2, $sp, 0x34
    ctx->r10 = ADD32(ctx->r29, 0X34);
    // 0x801DE750: andi        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 & 0X1;
    // 0x801DE754: bne         $v1, $at, L_801DE7A4
    if (ctx->r3 != ctx->r1) {
        // 0x801DE758: andi        $t0, $t0, 0xFF
        ctx->r8 = ctx->r8 & 0XFF;
            goto L_801DE7A4;
    }
    // 0x801DE758: andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // 0x801DE75C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801DE760: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x801DE764: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x801DE768: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
    // 0x801DE76C: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    // 0x801DE770: addu        $a3, $sp, $t5
    ctx->r7 = ADD32(ctx->r29, ctx->r13);
    // 0x801DE774: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DE778: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DE77C: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x801DE780: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801DE784: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x801DE788: lhu         $a3, 0x28($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X28);
    // 0x801DE78C: sb          $t1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r9;
    // 0x801DE790: sb          $t0, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r8;
    // 0x801DE794: jal         0x801DC9C4
    // 0x801DE798: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801DC9C4)(rdram, ctx);
        goto after_1;
    // 0x801DE798: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801DE79C: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x801DE7A0: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
L_801DE7A4:
    // 0x801DE7A4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x801DE7A8: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x801DE7AC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801DE7B0: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x801DE7B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801DE7B8: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x801DE7BC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801DE7C0: sll         $t9, $t1, 1
    ctx->r25 = S32(ctx->r9 << 1);
    // 0x801DE7C4: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x801DE7C8: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x801DE7CC: addu        $v0, $sp, $t2
    ctx->r2 = ADD32(ctx->r29, ctx->r10);
    // 0x801DE7D0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801DE7D4: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x801DE7D8: lhu         $v0, 0x26($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X26);
L_801DE7DC:
    // 0x801DE7DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801DE7E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801DE7E4: jr          $ra
    // 0x801DE7E8: nop

    return;
    // 0x801DE7E8: nop

;}
RECOMP_FUNC void M8_FUN_801de7ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DE7EC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801DE7F0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801DE7F4: lhu         $t6, 0x4($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801de7f8(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801de7f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DE7F8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x801DE7FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801DE800: slti        $at, $t6, 0xDC
    ctx->r1 = SIGNED(ctx->r14) < 0XDC ? 1 : 0;
    // 0x801DE804: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801DE808: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x801DE80C: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x801DE810: beq         $at, $zero, L_801DFA90
    if (ctx->r1 == 0) {
        // 0x801DE814: sh          $zero, 0x72($sp)
        MEM_H(0X72, ctx->r29) = 0;
            goto L_801DFA90;
    }
    // 0x801DE814: sh          $zero, 0x72($sp)
    MEM_H(0X72, ctx->r29) = 0;
    // 0x801DE818: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x801DE81C: addiu       $s0, $a1, 0x1C
    ctx->r16 = ADD32(ctx->r5, 0X1C);
    // 0x801DE820: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801DE824: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x801DE828: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x801DE82C: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x801DE830: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x801DE834: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801DE838: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801DE83C: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x801DE840: lw          $t2, 0x24($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X24);
    // 0x801DE844: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801DE848: lwc1        $f8, 0xC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XC);
    // 0x801DE84C: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x801DE850: lw          $t4, 0x6C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X6C);
    // 0x801DE854: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801DE858: bnel        $v0, $t4, L_801DE874
    if (ctx->r2 != ctx->r12) {
        // 0x801DE85C: sw          $v0, 0x6C($t8)
        MEM_W(0X6C, ctx->r24) = ctx->r2;
            goto L_801DE874;
    }
    goto skip_0;
    // 0x801DE85C: sw          $v0, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->r2;
    skip_0:
    // 0x801DE860: lhu         $t5, 0x4($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X4);
    // 0x801DE864: lhu         $t6, 0x70($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X70);
    // 0x801DE868: beql        $t5, $t6, L_801DFA94
    if (ctx->r13 == ctx->r14) {
        // 0x801DE86C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801DFA94;
    }
    goto skip_1;
    // 0x801DE86C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801DE870: sw          $v0, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->r2;
L_801DE874:
    // 0x801DE874: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x801DE878: lhu         $t9, 0x4($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X4);
    // 0x801DE87C: lui         $at, 0x191
    ctx->r1 = S32(0X191 << 16);
    // 0x801DE880: ori         $at, $at, 0xCF
    ctx->r1 = ctx->r1 | 0XCF;
    // 0x801DE884: sh          $t9, 0x70($t0)
    MEM_H(0X70, ctx->r8) = ctx->r25;
    // 0x801DE888: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801DE88C: beq         $v0, $at, L_801DE950
    if (ctx->r2 == ctx->r1) {
        // 0x801DE890: lui         $at, 0x191
        ctx->r1 = S32(0X191 << 16);
            goto L_801DE950;
    }
    // 0x801DE890: lui         $at, 0x191
    ctx->r1 = S32(0X191 << 16);
    // 0x801DE894: ori         $at, $at, 0x16
    ctx->r1 = ctx->r1 | 0X16;
    // 0x801DE898: beq         $v0, $at, L_801DE950
    if (ctx->r2 == ctx->r1) {
        // 0x801DE89C: lui         $at, 0x191
        ctx->r1 = S32(0X191 << 16);
            goto L_801DE950;
    }
    // 0x801DE89C: lui         $at, 0x191
    ctx->r1 = S32(0X191 << 16);
    // 0x801DE8A0: ori         $at, $at, 0x8
    ctx->r1 = ctx->r1 | 0X8;
    // 0x801DE8A4: beq         $v0, $at, L_801DE950
    if (ctx->r2 == ctx->r1) {
        // 0x801DE8A8: lw          $t1, 0x84($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X84);
            goto L_801DE950;
    }
    // 0x801DE8A8: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x801DE8AC: lbu         $v0, 0x74($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X74);
    // 0x801DE8B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801DE8B4: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x801DE8B8: beq         $v0, $at, L_801DE8C8
    if (ctx->r2 == ctx->r1) {
        // 0x801DE8BC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801DE8C8;
    }
    // 0x801DE8BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801DE8C0: bnel        $v0, $at, L_801DE954
    if (ctx->r2 != ctx->r1) {
        // 0x801DE8C4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801DE954;
    }
    goto skip_2;
    // 0x801DE8C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_2:
L_801DE8C8:
    // 0x801DE8C8: lhu         $v0, 0xE($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XE);
    // 0x801DE8CC: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x801DE8D0: beq         $v0, $at, L_801DE950
    if (ctx->r2 == ctx->r1) {
        // 0x801DE8D4: addiu       $at, $zero, 0x33
        ctx->r1 = ADD32(0, 0X33);
            goto L_801DE950;
    }
    // 0x801DE8D4: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x801DE8D8: beq         $v0, $at, L_801DE950
    if (ctx->r2 == ctx->r1) {
        // 0x801DE8DC: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_801DE950;
    }
    // 0x801DE8DC: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x801DE8E0: beq         $v0, $at, L_801DE950
    if (ctx->r2 == ctx->r1) {
        // 0x801DE8E4: andi        $t3, $v0, 0x7FFF
        ctx->r11 = ctx->r2 & 0X7FFF;
            goto L_801DE950;
    }
    // 0x801DE8E4: andi        $t3, $v0, 0x7FFF
    ctx->r11 = ctx->r2 & 0X7FFF;
    // 0x801DE8E8: addiu       $at, $zero, 0xF8
    ctx->r1 = ADD32(0, 0XF8);
    // 0x801DE8EC: beq         $t3, $at, L_801DE950
    if (ctx->r11 == ctx->r1) {
        // 0x801DE8F0: addiu       $at, $zero, 0x149
        ctx->r1 = ADD32(0, 0X149);
            goto L_801DE950;
    }
    // 0x801DE8F0: addiu       $at, $zero, 0x149
    ctx->r1 = ADD32(0, 0X149);
    // 0x801DE8F4: beql        $v0, $at, L_801DE954
    if (ctx->r2 == ctx->r1) {
        // 0x801DE8F8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801DE954;
    }
    goto skip_3;
    // 0x801DE8F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_3:
    // 0x801DE8FC: lhu         $t4, 0x2C($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X2C);
    // 0x801DE900: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801DE904: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801DE908: beq         $t4, $at, L_801DE950
    if (ctx->r12 == ctx->r1) {
        // 0x801DE90C: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_801DE950;
    }
    // 0x801DE90C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801DE910: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801DE914: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DE918: lw          $t7, 0xE8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XE8);
    // 0x801DE91C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801DE920: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x801DE924: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x801DE928: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801DE92C: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801DE930: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801DE934: lwc1        $f12, 0x30($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801DE938: lwc1        $f14, 0x34($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801DE93C: lw          $a2, 0x38($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X38);
    // 0x801DE940: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801DE944: jal         0x801084C4
    // 0x801DE948: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801084C4)(rdram, ctx);
        goto after_0;
    // 0x801DE948: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801DE94C: bne         $v0, $zero, L_801DFA90
    if (ctx->r2 != 0) {
        // 0x801DE950: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801DFA90;
    }
L_801DE950:
    // 0x801DE950: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_801DE954:
    // 0x801DE954: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801DE958: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801DE95C: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801DE960: swc1        $f2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f2.u32l;
    // 0x801DE964: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801DE968: ori         $at, $at, 0xF
    ctx->r1 = ctx->r1 | 0XF;
    // 0x801DE96C: bne         $v0, $at, L_801DEAFC
    if (ctx->r2 != ctx->r1) {
        // 0x801DE970: lui         $at, 0x4140
        ctx->r1 = S32(0X4140 << 16);
            goto L_801DEAFC;
    }
    // 0x801DE970: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801DE974: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DE978: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DE97C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DE980: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801DE984: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801DE988: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DE98C: nop

    // 0x801DE990: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801DE994: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DE998: nop

    // 0x801DE99C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DE9A0: beql        $a0, $zero, L_801DE9F0
    if (ctx->r4 == 0) {
        // 0x801DE9A4: mfc1        $a0, $f10
        ctx->r4 = (int32_t)ctx->f10.u32l;
            goto L_801DE9F0;
    }
    goto skip_4;
    // 0x801DE9A4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x801DE9A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DE9AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DE9B0: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801DE9B4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DE9B8: nop

    // 0x801DE9BC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DE9C0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DE9C4: nop

    // 0x801DE9C8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DE9CC: bne         $a0, $zero, L_801DE9E4
    if (ctx->r4 != 0) {
        // 0x801DE9D0: nop
    
            goto L_801DE9E4;
    }
    // 0x801DE9D0: nop

    // 0x801DE9D4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x801DE9D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DE9DC: b           L_801DE9FC
    // 0x801DE9E0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DE9FC;
    // 0x801DE9E0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DE9E4:
    // 0x801DE9E4: b           L_801DE9FC
    // 0x801DE9E8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DE9FC;
    // 0x801DE9E8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DE9EC: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
L_801DE9F0:
    // 0x801DE9F0: nop

    // 0x801DE9F4: bltz        $a0, L_801DE9E4
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DE9F8: nop
    
            goto L_801DE9E4;
    }
    // 0x801DE9F8: nop

L_801DE9FC:
    // 0x801DE9FC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801DEA00: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x801DEA04: jal         0x80011590
    // 0x801DEA08: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_1;
    // 0x801DEA08: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x801DEA0C: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x801DEA10: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801DEA14: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x801DEA18: beql        $t6, $v0, L_801DEAC0
    if (ctx->r14 == ctx->r2) {
        // 0x801DEA1C: addiu       $t0, $zero, 0x68E
        ctx->r8 = ADD32(0, 0X68E);
            goto L_801DEAC0;
    }
    goto skip_5;
    // 0x801DEA1C: addiu       $t0, $zero, 0x68E
    ctx->r8 = ADD32(0, 0X68E);
    skip_5:
    // 0x801DEA20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DEA24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DEA28: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DEA2C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801DEA30: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801DEA34: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DEA38: nop

    // 0x801DEA3C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DEA40: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DEA44: nop

    // 0x801DEA48: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DEA4C: beql        $a0, $zero, L_801DEA9C
    if (ctx->r4 == 0) {
        // 0x801DEA50: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_801DEA9C;
    }
    goto skip_6;
    // 0x801DEA50: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_6:
    // 0x801DEA54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DEA58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DEA5C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801DEA60: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DEA64: nop

    // 0x801DEA68: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801DEA6C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DEA70: nop

    // 0x801DEA74: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DEA78: bne         $a0, $zero, L_801DEA90
    if (ctx->r4 != 0) {
        // 0x801DEA7C: nop
    
            goto L_801DEA90;
    }
    // 0x801DEA7C: nop

    // 0x801DEA80: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x801DEA84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DEA88: b           L_801DEAA8
    // 0x801DEA8C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DEAA8;
    // 0x801DEA8C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DEA90:
    // 0x801DEA90: b           L_801DEAA8
    // 0x801DEA94: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DEAA8;
    // 0x801DEA94: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DEA98: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_801DEA9C:
    // 0x801DEA9C: nop

    // 0x801DEAA0: bltz        $a0, L_801DEA90
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DEAA4: nop
    
            goto L_801DEA90;
    }
    // 0x801DEAA4: nop

L_801DEAA8:
    // 0x801DEAA8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801DEAAC: jal         0x80011590
    // 0x801DEAB0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_2;
    // 0x801DEAB0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_2:
    // 0x801DEAB4: lhu         $t9, 0x4($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X4);
    // 0x801DEAB8: bne         $t9, $v0, L_801DEAC4
    if (ctx->r25 != ctx->r2) {
        // 0x801DEABC: addiu       $t0, $zero, 0x68E
        ctx->r8 = ADD32(0, 0X68E);
            goto L_801DEAC4;
    }
    // 0x801DEABC: addiu       $t0, $zero, 0x68E
    ctx->r8 = ADD32(0, 0X68E);
L_801DEAC0:
    // 0x801DEAC0: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
L_801DEAC4:
    // 0x801DEAC4: addiu       $t1, $sp, 0x60
    ctx->r9 = ADD32(ctx->r29, 0X60);
    // 0x801DEAC8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801DEACC: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801DEAD0: lhu         $a3, 0x72($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X72);
    // 0x801DEAD4: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
    // 0x801DEAD8: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    // 0x801DEADC: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DEAE0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DEAE4: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x801DEAE8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801DEAEC: jal         0x801DC9C4
    // 0x801DEAF0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DC9C4)(rdram, ctx);
        goto after_3;
    // 0x801DEAF0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_3:
    // 0x801DEAF4: b           L_801DFA94
    // 0x801DEAF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801DFA94;
    // 0x801DEAF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801DEAFC:
    // 0x801DEAFC: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801DEB00: ori         $at, $at, 0xD
    ctx->r1 = ctx->r1 | 0XD;
    // 0x801DEB04: bne         $v0, $at, L_801DEB54
    if (ctx->r2 != ctx->r1) {
        // 0x801DEB08: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_801DEB54;
    }
    // 0x801DEB08: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801DEB0C: lhu         $t4, 0x4($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X4);
    // 0x801DEB10: addiu       $t7, $zero, 0x1FD
    ctx->r15 = ADD32(0, 0X1FD);
    // 0x801DEB14: addiu       $t5, $sp, 0x60
    ctx->r13 = ADD32(ctx->r29, 0X60);
    // 0x801DEB18: bnel        $t4, $zero, L_801DEB28
    if (ctx->r12 != 0) {
        // 0x801DEB1C: lw          $t8, 0x0($t5)
        ctx->r24 = MEM_W(ctx->r13, 0X0);
            goto L_801DEB28;
    }
    goto skip_7;
    // 0x801DEB1C: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    skip_7:
    // 0x801DEB20: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
    // 0x801DEB24: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
L_801DEB28:
    // 0x801DEB28: lhu         $a3, 0x72($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X72);
    // 0x801DEB2C: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x801DEB30: lw          $a1, 0x4($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X4);
    // 0x801DEB34: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DEB38: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DEB3C: lw          $a2, 0x8($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X8);
    // 0x801DEB40: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x801DEB44: jal         0x801DC9C4
    // 0x801DEB48: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DC9C4)(rdram, ctx);
        goto after_4;
    // 0x801DEB48: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_4:
    // 0x801DEB4C: b           L_801DFA94
    // 0x801DEB50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801DFA94;
    // 0x801DEB50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801DEB54:
    // 0x801DEB54: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801DEB58: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801DEB5C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801DEB60: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801DEB64: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801DEB68: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x801DEB6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DEB70: sub.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f2.d - ctx->f10.d;
    // 0x801DEB74: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801DEB78: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801DEB7C: add.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d + ctx->f6.d;
    // 0x801DEB80: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801DEB84: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x801DEB88: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801DEB8C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801DEB90: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x801DEB94: jal         0x801C5A1C
    // 0x801DEB98: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_5;
    // 0x801DEB98: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x801DEB9C: bne         $v0, $zero, L_801DECE4
    if (ctx->r2 != 0) {
        // 0x801DEBA0: lui         $t9, 0x801C
        ctx->r25 = S32(0X801C << 16);
            goto L_801DECE4;
    }
    // 0x801DEBA0: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801DEBA4: lw          $t9, -0x4330($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4330);
    // 0x801DEBA8: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801DEBAC: jal         0x8001EAD0
    // 0x801DEBB0: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_6;
    // 0x801DEBB0: lh          $a0, 0x12($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X12);
    after_6:
    // 0x801DEBB4: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801DEBB8: lw          $t1, -0x4330($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4330);
    // 0x801DEBBC: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x801DEBC0: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801DEBC4: jal         0x8001EB64
    // 0x801DEBC8: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_7;
    // 0x801DEBC8: lh          $a0, 0x12($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X12);
    after_7:
    // 0x801DEBCC: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801DEBD0: lw          $t3, -0x4330($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4330);
    // 0x801DEBD4: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x801DEBD8: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x801DEBDC: jal         0x8001EAD0
    // 0x801DEBE0: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_8;
    // 0x801DEBE0: lh          $a0, 0x12($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X12);
    after_8:
    // 0x801DEBE4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801DEBE8: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x801DEBEC: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x801DEBF0: lw          $t5, 0x2C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X2C);
    // 0x801DEBF4: jal         0x8001EB64
    // 0x801DEBF8: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_9;
    // 0x801DEBF8: lh          $a0, 0x12($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X12);
    after_9:
    // 0x801DEBFC: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801DEC00: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801DEC04: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801DEC08: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801DEC0C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DEC10: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x801DEC14: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x801DEC18: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x801DEC1C: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801DEC20: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801DEC24: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801DEC28: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DEC2C: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x801DEC30: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801DEC34: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801DEC38: add.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f8.d + ctx->f16.d;
    // 0x801DEC3C: add.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d + ctx->f6.d;
    // 0x801DEC40: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x801DEC44: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801DEC48: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x801DEC4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801DEC50: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801DEC54: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801DEC58: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x801DEC5C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801DEC60: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801DEC64: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x801DEC68: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801DEC6C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801DEC70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DEC74: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801DEC78: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x801DEC7C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801DEC80: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801DEC84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DEC88: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801DEC8C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801DEC90: add.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f6.d + ctx->f16.d;
    // 0x801DEC94: sub.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f2.d - ctx->f4.d;
    // 0x801DEC98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DEC9C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801DECA0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801DECA4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801DECA8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801DECAC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x801DECB0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801DECB4: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x801DECB8: add.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f6.d + ctx->f18.d;
    // 0x801DECBC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801DECC0: jal         0x801C5A1C
    // 0x801DECC4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_10;
    // 0x801DECC4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x801DECC8: bnel        $v0, $zero, L_801DECE8
    if (ctx->r2 != 0) {
        // 0x801DECCC: lw          $t8, 0x84($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X84);
            goto L_801DECE8;
    }
    goto skip_8;
    // 0x801DECCC: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    skip_8:
    // 0x801DECD0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801DECD4: lui         $at, 0x168
    ctx->r1 = S32(0X168 << 16);
    // 0x801DECD8: ori         $at, $at, 0x1F
    ctx->r1 = ctx->r1 | 0X1F;
    // 0x801DECDC: bnel        $t6, $at, L_801DFA94
    if (ctx->r14 != ctx->r1) {
        // 0x801DECE0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801DFA94;
    }
    goto skip_9;
    // 0x801DECE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_9:
L_801DECE4:
    // 0x801DECE4: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
L_801DECE8:
    // 0x801DECE8: lhu         $v0, 0xE($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0XE);
    // 0x801DECEC: slti        $at, $v0, 0x11D
    ctx->r1 = SIGNED(ctx->r2) < 0X11D ? 1 : 0;
    // 0x801DECF0: bne         $at, $zero, L_801DED28
    if (ctx->r1 != 0) {
        // 0x801DECF4: addiu       $at, $zero, 0x141
        ctx->r1 = ADD32(0, 0X141);
            goto L_801DED28;
    }
    // 0x801DECF4: addiu       $at, $zero, 0x141
    ctx->r1 = ADD32(0, 0X141);
    // 0x801DECF8: beq         $v0, $at, L_801DFA54
    if (ctx->r2 == ctx->r1) {
        // 0x801DECFC: addiu       $at, $zero, 0x142
        ctx->r1 = ADD32(0, 0X142);
            goto L_801DFA54;
    }
    // 0x801DECFC: addiu       $at, $zero, 0x142
    ctx->r1 = ADD32(0, 0X142);
    // 0x801DED00: beq         $v0, $at, L_801DFA54
    if (ctx->r2 == ctx->r1) {
        // 0x801DED04: addiu       $at, $zero, 0x148
        ctx->r1 = ADD32(0, 0X148);
            goto L_801DFA54;
    }
    // 0x801DED04: addiu       $at, $zero, 0x148
    ctx->r1 = ADD32(0, 0X148);
    // 0x801DED08: beq         $v0, $at, L_801DF334
    if (ctx->r2 == ctx->r1) {
        // 0x801DED0C: addiu       $at, $zero, 0x4057
        ctx->r1 = ADD32(0, 0X4057);
            goto L_801DF334;
    }
    // 0x801DED0C: addiu       $at, $zero, 0x4057
    ctx->r1 = ADD32(0, 0X4057);
    // 0x801DED10: beq         $v0, $at, L_801DF994
    if (ctx->r2 == ctx->r1) {
        // 0x801DED14: ori         $at, $zero, 0x80F8
        ctx->r1 = 0 | 0X80F8;
            goto L_801DF994;
    }
    // 0x801DED14: ori         $at, $zero, 0x80F8
    ctx->r1 = 0 | 0X80F8;
    // 0x801DED18: beq         $v0, $at, L_801DEF68
    if (ctx->r2 == ctx->r1) {
        // 0x801DED1C: addiu       $t5, $sp, 0x60
        ctx->r13 = ADD32(ctx->r29, 0X60);
            goto L_801DEF68;
    }
    // 0x801DED1C: addiu       $t5, $sp, 0x60
    ctx->r13 = ADD32(ctx->r29, 0X60);
    // 0x801DED20: b           L_801DFA3C
    // 0x801DED24: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
        goto L_801DFA3C;
    // 0x801DED24: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
L_801DED28:
    // 0x801DED28: slti        $at, $v0, 0xF9
    ctx->r1 = SIGNED(ctx->r2) < 0XF9 ? 1 : 0;
    // 0x801DED2C: bne         $at, $zero, L_801DED4C
    if (ctx->r1 != 0) {
        // 0x801DED30: addiu       $at, $zero, 0x11B
        ctx->r1 = ADD32(0, 0X11B);
            goto L_801DED4C;
    }
    // 0x801DED30: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    // 0x801DED34: beq         $v0, $at, L_801DEDC8
    if (ctx->r2 == ctx->r1) {
        // 0x801DED38: addiu       $at, $zero, 0x11C
        ctx->r1 = ADD32(0, 0X11C);
            goto L_801DEDC8;
    }
    // 0x801DED38: addiu       $at, $zero, 0x11C
    ctx->r1 = ADD32(0, 0X11C);
    // 0x801DED3C: beq         $v0, $at, L_801DEDC8
    if (ctx->r2 == ctx->r1) {
        // 0x801DED40: nop
    
            goto L_801DEDC8;
    }
    // 0x801DED40: nop

    // 0x801DED44: b           L_801DFA3C
    // 0x801DED48: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
        goto L_801DFA3C;
    // 0x801DED48: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
L_801DED4C:
    // 0x801DED4C: slti        $at, $v0, 0x5A
    ctx->r1 = SIGNED(ctx->r2) < 0X5A ? 1 : 0;
    // 0x801DED50: bne         $at, $zero, L_801DED78
    if (ctx->r1 != 0) {
        // 0x801DED54: addiu       $t9, $v0, -0xF4
        ctx->r25 = ADD32(ctx->r2, -0XF4);
            goto L_801DED78;
    }
    // 0x801DED54: addiu       $t9, $v0, -0xF4
    ctx->r25 = ADD32(ctx->r2, -0XF4);
    // 0x801DED58: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x801DED5C: beq         $at, $zero, L_801DFA38
    if (ctx->r1 == 0) {
        // 0x801DED60: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_801DFA38;
    }
    // 0x801DED60: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DED64: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DED68: addu        $at, $at, $t9
    gpr jr_addend_801DED70 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801DED6C: lw          $t9, 0x3F34($at)
    ctx->r25 = ADD32(ctx->r1, 0X3F34);
    // 0x801DED70: jr          $t9
    // 0x801DED74: nop

    switch (jr_addend_801DED70 >> 2) {
        case 0: goto L_801DF9B0; break;
        case 1: goto L_801DF9D0; break;
        case 2: goto L_801DF9D0; break;
        case 3: goto L_801DFA54; break;
        case 4: goto L_801DEEE4; break;
        default: switch_error(__func__, 0x801DED70, 0x801E3F34);
    }
    // 0x801DED74: nop

L_801DED78:
    // 0x801DED78: slti        $at, $v0, 0x37
    ctx->r1 = SIGNED(ctx->r2) < 0X37 ? 1 : 0;
    // 0x801DED7C: bne         $at, $zero, L_801DEDA8
    if (ctx->r1 != 0) {
        // 0x801DED80: addiu       $t1, $v0, -0x29
        ctx->r9 = ADD32(ctx->r2, -0X29);
            goto L_801DEDA8;
    }
    // 0x801DED80: addiu       $t1, $v0, -0x29
    ctx->r9 = ADD32(ctx->r2, -0X29);
    // 0x801DED84: addiu       $t0, $v0, -0x50
    ctx->r8 = ADD32(ctx->r2, -0X50);
    // 0x801DED88: sltiu       $at, $t0, 0xA
    ctx->r1 = ctx->r8 < 0XA ? 1 : 0;
    // 0x801DED8C: beq         $at, $zero, L_801DFA38
    if (ctx->r1 == 0) {
        // 0x801DED90: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_801DFA38;
    }
    // 0x801DED90: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DED94: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DED98: addu        $at, $at, $t0
    gpr jr_addend_801DEDA0 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801DED9C: lw          $t0, 0x3F48($at)
    ctx->r8 = ADD32(ctx->r1, 0X3F48);
    // 0x801DEDA0: jr          $t0
    // 0x801DEDA4: nop

    switch (jr_addend_801DEDA0 >> 2) {
        case 0: goto L_801DEE38; break;
        case 1: goto L_801DEFA4; break;
        case 2: goto L_801DFA38; break;
        case 3: goto L_801DFA38; break;
        case 4: goto L_801DFA38; break;
        case 5: goto L_801DFA38; break;
        case 6: goto L_801DFA38; break;
        case 7: goto L_801DF994; break;
        case 8: goto L_801DF360; break;
        case 9: goto L_801DF994; break;
        default: switch_error(__func__, 0x801DEDA0, 0x801E3F48);
    }
    // 0x801DEDA4: nop

L_801DEDA8:
    // 0x801DEDA8: sltiu       $at, $t1, 0xE
    ctx->r1 = ctx->r9 < 0XE ? 1 : 0;
    // 0x801DEDAC: beq         $at, $zero, L_801DFA38
    if (ctx->r1 == 0) {
        // 0x801DEDB0: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_801DFA38;
    }
    // 0x801DEDB0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DEDB4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DEDB8: addu        $at, $at, $t1
    gpr jr_addend_801DEDC0 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801DEDBC: lw          $t1, 0x3F70($at)
    ctx->r9 = ADD32(ctx->r1, 0X3F70);
    // 0x801DEDC0: jr          $t1
    // 0x801DEDC4: nop

    switch (jr_addend_801DEDC0 >> 2) {
        case 0: goto L_801DEDC8; break;
        case 1: goto L_801DFA54; break;
        case 2: goto L_801DF334; break;
        case 3: goto L_801DEDC8; break;
        case 4: goto L_801DEDC8; break;
        case 5: goto L_801DF014; break;
        case 6: goto L_801DFA54; break;
        case 7: goto L_801DF994; break;
        case 8: goto L_801DF334; break;
        case 9: goto L_801DF6DC; break;
        case 10: goto L_801DF9F4; break;
        case 11: goto L_801DF9F4; break;
        case 12: goto L_801DFA54; break;
        case 13: goto L_801DFA54; break;
        default: switch_error(__func__, 0x801DEDC0, 0x801E3F70);
    }
    // 0x801DEDC4: nop

L_801DEDC8:
    // 0x801DEDC8: jal         0x80126944
    // 0x801DEDCC: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_11;
    // 0x801DEDCC: nop

    after_11:
    // 0x801DEDD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DEDD4: bne         $v0, $at, L_801DEDF4
    if (ctx->r2 != ctx->r1) {
        // 0x801DEDD8: lw          $a0, 0x80($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X80);
            goto L_801DEDF4;
    }
    // 0x801DEDD8: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801DEDDC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DEDE0: addiu       $a2, $sp, 0x72
    ctx->r6 = ADD32(ctx->r29, 0X72);
    // 0x801DEDE4: jal         0x801DE590
    // 0x801DEDE8: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x801DE590)(rdram, ctx);
        goto after_12;
    // 0x801DEDE8: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_12:
    // 0x801DEDEC: b           L_801DFA58
    // 0x801DEDF0: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
        goto L_801DFA58;
    // 0x801DEDF0: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
L_801DEDF4:
    // 0x801DEDF4: jal         0x80126944
    // 0x801DEDF8: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_13;
    // 0x801DEDF8: nop

    after_13:
    // 0x801DEDFC: bne         $v0, $zero, L_801DFA54
    if (ctx->r2 != 0) {
        // 0x801DEE00: addiu       $t2, $sp, 0x60
        ctx->r10 = ADD32(ctx->r29, 0X60);
            goto L_801DFA54;
    }
    // 0x801DEE00: addiu       $t2, $sp, 0x60
    ctx->r10 = ADD32(ctx->r29, 0X60);
    // 0x801DEE04: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801DEE08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801DEE0C: addiu       $a1, $sp, 0x72
    ctx->r5 = ADD32(ctx->r29, 0X72);
    // 0x801DEE10: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x801DEE14: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801DEE18: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801DEE1C: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x801DEE20: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801DEE24: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801DEE28: jal         0x801DCDBC
    // 0x801DEE2C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x801DCDBC)(rdram, ctx);
        goto after_14;
    // 0x801DEE2C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_14:
    // 0x801DEE30: b           L_801DFA58
    // 0x801DEE34: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
        goto L_801DFA58;
    // 0x801DEE34: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
L_801DEE38:
    // 0x801DEE38: jal         0x80126944
    // 0x801DEE3C: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_15;
    // 0x801DEE3C: nop

    after_15:
    // 0x801DEE40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DEE44: bne         $v0, $at, L_801DEE70
    if (ctx->r2 != ctx->r1) {
        // 0x801DEE48: addiu       $t5, $sp, 0x60
        ctx->r13 = ADD32(ctx->r29, 0X60);
            goto L_801DEE70;
    }
    // 0x801DEE48: addiu       $t5, $sp, 0x60
    ctx->r13 = ADD32(ctx->r29, 0X60);
    // 0x801DEE4C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801DEE50: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801DEE54: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801DEE58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DEE5C: addiu       $a2, $sp, 0x72
    ctx->r6 = ADD32(ctx->r29, 0X72);
    // 0x801DEE60: jal         0x801DE5E4
    // 0x801DEE64: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x801DE5E4)(rdram, ctx);
        goto after_16;
    // 0x801DEE64: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_16:
    // 0x801DEE68: b           L_801DFA58
    // 0x801DEE6C: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
        goto L_801DFA58;
    // 0x801DEE6C: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
L_801DEE70:
    // 0x801DEE70: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x801DEE74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801DEE78: addiu       $a1, $sp, 0x72
    ctx->r5 = ADD32(ctx->r29, 0X72);
    // 0x801DEE7C: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x801DEE80: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801DEE84: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801DEE88: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x801DEE8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801DEE90: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x801DEE94: jal         0x801DCDBC
    // 0x801DEE98: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x801DCDBC)(rdram, ctx);
        goto after_17;
    // 0x801DEE98: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_17:
    // 0x801DEE9C: lhu         $t9, 0x72($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X72);
    // 0x801DEEA0: addiu       $at, $zero, 0x672
    ctx->r1 = ADD32(0, 0X672);
    // 0x801DEEA4: beql        $t9, $zero, L_801DFA58
    if (ctx->r25 == 0) {
        // 0x801DEEA8: lhu         $t5, 0x72($sp)
        ctx->r13 = MEM_HU(ctx->r29, 0X72);
            goto L_801DFA58;
    }
    goto skip_10;
    // 0x801DEEA8: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
    skip_10:
    // 0x801DEEAC: beq         $t9, $at, L_801DFA54
    if (ctx->r25 == ctx->r1) {
        // 0x801DEEB0: addiu       $at, $zero, 0x674
        ctx->r1 = ADD32(0, 0X674);
            goto L_801DFA54;
    }
    // 0x801DEEB0: addiu       $at, $zero, 0x674
    ctx->r1 = ADD32(0, 0X674);
    // 0x801DEEB4: beq         $t9, $at, L_801DFA54
    if (ctx->r25 == ctx->r1) {
        // 0x801DEEB8: addiu       $at, $zero, 0x673
        ctx->r1 = ADD32(0, 0X673);
            goto L_801DFA54;
    }
    // 0x801DEEB8: addiu       $at, $zero, 0x673
    ctx->r1 = ADD32(0, 0X673);
    // 0x801DEEBC: beq         $t9, $at, L_801DFA54
    if (ctx->r25 == ctx->r1) {
        // 0x801DEEC0: addiu       $at, $zero, 0x675
        ctx->r1 = ADD32(0, 0X675);
            goto L_801DFA54;
    }
    // 0x801DEEC0: addiu       $at, $zero, 0x675
    ctx->r1 = ADD32(0, 0X675);
    // 0x801DEEC4: beq         $t9, $at, L_801DFA54
    if (ctx->r25 == ctx->r1) {
        // 0x801DEEC8: addiu       $at, $zero, 0x68C
        ctx->r1 = ADD32(0, 0X68C);
            goto L_801DFA54;
    }
    // 0x801DEEC8: addiu       $at, $zero, 0x68C
    ctx->r1 = ADD32(0, 0X68C);
    // 0x801DEECC: beq         $t9, $at, L_801DFA54
    if (ctx->r25 == ctx->r1) {
        // 0x801DEED0: addiu       $at, $zero, 0x68D
        ctx->r1 = ADD32(0, 0X68D);
            goto L_801DFA54;
    }
    // 0x801DEED0: addiu       $at, $zero, 0x68D
    ctx->r1 = ADD32(0, 0X68D);
    // 0x801DEED4: beq         $t9, $at, L_801DFA54
    if (ctx->r25 == ctx->r1) {
        // 0x801DEED8: addiu       $t0, $zero, 0x654
        ctx->r8 = ADD32(0, 0X654);
            goto L_801DFA54;
    }
    // 0x801DEED8: addiu       $t0, $zero, 0x654
    ctx->r8 = ADD32(0, 0X654);
    // 0x801DEEDC: b           L_801DFA54
    // 0x801DEEE0: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
        goto L_801DFA54;
    // 0x801DEEE0: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
L_801DEEE4:
    // 0x801DEEE4: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801DEEE8: lhu         $t1, -0x440C($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X440C);
    // 0x801DEEEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801DEEF0: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801DEEF4: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x801DEEF8: beq         $at, $zero, L_801DEF30
    if (ctx->r1 == 0) {
        // 0x801DEEFC: addiu       $t2, $sp, 0x60
        ctx->r10 = ADD32(ctx->r29, 0X60);
            goto L_801DEF30;
    }
    // 0x801DEEFC: addiu       $t2, $sp, 0x60
    ctx->r10 = ADD32(ctx->r29, 0X60);
    // 0x801DEF00: jal         0x801DC510
    // 0x801DEF04: addiu       $a1, $a1, 0x1F7C
    ctx->r5 = ADD32(ctx->r5, 0X1F7C);
    LOOKUP_FUNC(0x801DC510)(rdram, ctx);
        goto after_18;
    // 0x801DEF04: addiu       $a1, $a1, 0x1F7C
    ctx->r5 = ADD32(ctx->r5, 0X1F7C);
    after_18:
    // 0x801DEF08: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801DEF0C: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x801DEF10: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801DEF14: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801DEF18: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801DEF1C: sh          $v0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r2;
    // 0x801DEF20: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801DEF24: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801DEF28: b           L_801DFA54
    // 0x801DEF2C: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
        goto L_801DFA54;
    // 0x801DEF2C: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
L_801DEF30:
    // 0x801DEF30: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801DEF34: addiu       $t7, $sp, 0x6C
    ctx->r15 = ADD32(ctx->r29, 0X6C);
    // 0x801DEF38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801DEF3C: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x801DEF40: lw          $a2, 0x4($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X4);
    // 0x801DEF44: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801DEF48: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801DEF4C: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x801DEF50: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801DEF54: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801DEF58: jal         0x801DE6F4
    // 0x801DEF5C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801DE6F4)(rdram, ctx);
        goto after_19;
    // 0x801DEF5C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_19:
    // 0x801DEF60: b           L_801DFA54
    // 0x801DEF64: sh          $v0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r2;
        goto L_801DFA54;
    // 0x801DEF64: sh          $v0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r2;
L_801DEF68:
    // 0x801DEF68: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x801DEF6C: addiu       $t9, $sp, 0x6C
    ctx->r25 = ADD32(ctx->r29, 0X6C);
    // 0x801DEF70: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801DEF74: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x801DEF78: lw          $a2, 0x4($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X4);
    // 0x801DEF7C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801DEF80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801DEF84: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801DEF88: lw          $a3, 0x8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X8);
    // 0x801DEF8C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801DEF90: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801DEF94: jal         0x801DE6F4
    // 0x801DEF98: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801DE6F4)(rdram, ctx);
        goto after_20;
    // 0x801DEF98: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_20:
    // 0x801DEF9C: b           L_801DFA54
    // 0x801DEFA0: sh          $v0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r2;
        goto L_801DFA54;
    // 0x801DEFA0: sh          $v0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r2;
L_801DEFA4:
    // 0x801DEFA4: jal         0x80126944
    // 0x801DEFA8: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_21;
    // 0x801DEFA8: nop

    after_21:
    // 0x801DEFAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DEFB0: bne         $v0, $at, L_801DEFDC
    if (ctx->r2 != ctx->r1) {
        // 0x801DEFB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801DEFDC;
    }
    // 0x801DEFB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801DEFB8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801DEFBC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801DEFC0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801DEFC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DEFC8: addiu       $a2, $sp, 0x72
    ctx->r6 = ADD32(ctx->r29, 0X72);
    // 0x801DEFCC: jal         0x801DE5E4
    // 0x801DEFD0: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x801DE5E4)(rdram, ctx);
        goto after_22;
    // 0x801DEFD0: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_22:
    // 0x801DEFD4: b           L_801DFA58
    // 0x801DEFD8: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
        goto L_801DFA58;
    // 0x801DEFD8: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
L_801DEFDC:
    // 0x801DEFDC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801DEFE0: jal         0x801DC510
    // 0x801DEFE4: addiu       $a1, $a1, 0x1F58
    ctx->r5 = ADD32(ctx->r5, 0X1F58);
    LOOKUP_FUNC(0x801DC510)(rdram, ctx);
        goto after_23;
    // 0x801DEFE4: addiu       $a1, $a1, 0x1F58
    ctx->r5 = ADD32(ctx->r5, 0X1F58);
    after_23:
    // 0x801DEFE8: bne         $v0, $zero, L_801DFA54
    if (ctx->r2 != 0) {
        // 0x801DEFEC: sh          $v0, 0x72($sp)
        MEM_H(0X72, ctx->r29) = ctx->r2;
            goto L_801DFA54;
    }
    // 0x801DEFEC: sh          $v0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r2;
    // 0x801DEFF0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x801DEFF4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801DEFF8: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801DEFFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DF000: addiu       $a2, $sp, 0x72
    ctx->r6 = ADD32(ctx->r29, 0X72);
    // 0x801DF004: jal         0x801DE5E4
    // 0x801DF008: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x801DE5E4)(rdram, ctx);
        goto after_24;
    // 0x801DF008: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_24:
    // 0x801DF00C: b           L_801DFA58
    // 0x801DF010: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
        goto L_801DFA58;
    // 0x801DF010: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
L_801DF014:
    // 0x801DF014: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801DF018: lui         $at, 0x191
    ctx->r1 = S32(0X191 << 16);
    // 0x801DF01C: ori         $at, $at, 0xCF
    ctx->r1 = ctx->r1 | 0XCF;
    // 0x801DF020: bne         $t3, $at, L_801DF308
    if (ctx->r11 != ctx->r1) {
        // 0x801DF024: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_801DF308;
    }
    // 0x801DF024: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801DF028: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DF02C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801DF030: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF034: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DF038: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801DF03C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801DF040: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF044: nop

    // 0x801DF048: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DF04C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF050: nop

    // 0x801DF054: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF058: beql        $a0, $zero, L_801DF0A8
    if (ctx->r4 == 0) {
        // 0x801DF05C: mfc1        $a0, $f4
        ctx->r4 = (int32_t)ctx->f4.u32l;
            goto L_801DF0A8;
    }
    goto skip_11;
    // 0x801DF05C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    skip_11:
    // 0x801DF060: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DF064: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF068: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801DF06C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF070: nop

    // 0x801DF074: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DF078: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF07C: nop

    // 0x801DF080: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF084: bne         $a0, $zero, L_801DF09C
    if (ctx->r4 != 0) {
        // 0x801DF088: nop
    
            goto L_801DF09C;
    }
    // 0x801DF088: nop

    // 0x801DF08C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x801DF090: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DF094: b           L_801DF0B4
    // 0x801DF098: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DF0B4;
    // 0x801DF098: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DF09C:
    // 0x801DF09C: b           L_801DF0B4
    // 0x801DF0A0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DF0B4;
    // 0x801DF0A0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DF0A4: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
L_801DF0A8:
    // 0x801DF0A8: nop

    // 0x801DF0AC: bltz        $a0, L_801DF09C
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DF0B0: nop
    
            goto L_801DF09C;
    }
    // 0x801DF0B0: nop

L_801DF0B4:
    // 0x801DF0B4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801DF0B8: jal         0x80011590
    // 0x801DF0BC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_25;
    // 0x801DF0BC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_25:
    // 0x801DF0C0: lhu         $t7, 0x4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X4);
    // 0x801DF0C4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801DF0C8: beq         $t7, $v0, L_801DF2C0
    if (ctx->r15 == ctx->r2) {
        // 0x801DF0CC: nop
    
            goto L_801DF2C0;
    }
    // 0x801DF0CC: nop

    // 0x801DF0D0: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801DF0D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DF0D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF0DC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DF0E0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801DF0E4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801DF0E8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF0EC: nop

    // 0x801DF0F0: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DF0F4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF0F8: nop

    // 0x801DF0FC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF100: beql        $a0, $zero, L_801DF150
    if (ctx->r4 == 0) {
        // 0x801DF104: mfc1        $a0, $f4
        ctx->r4 = (int32_t)ctx->f4.u32l;
            goto L_801DF150;
    }
    goto skip_12;
    // 0x801DF104: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    skip_12:
    // 0x801DF108: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DF10C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF110: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801DF114: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF118: nop

    // 0x801DF11C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DF120: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF124: nop

    // 0x801DF128: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF12C: bne         $a0, $zero, L_801DF144
    if (ctx->r4 != 0) {
        // 0x801DF130: nop
    
            goto L_801DF144;
    }
    // 0x801DF130: nop

    // 0x801DF134: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x801DF138: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DF13C: b           L_801DF15C
    // 0x801DF140: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DF15C;
    // 0x801DF140: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DF144:
    // 0x801DF144: b           L_801DF15C
    // 0x801DF148: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DF15C;
    // 0x801DF148: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DF14C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
L_801DF150:
    // 0x801DF150: nop

    // 0x801DF154: bltz        $a0, L_801DF144
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DF158: nop
    
            goto L_801DF144;
    }
    // 0x801DF158: nop

L_801DF15C:
    // 0x801DF15C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801DF160: jal         0x80011590
    // 0x801DF164: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_26;
    // 0x801DF164: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_26:
    // 0x801DF168: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x801DF16C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801DF170: beq         $t6, $v0, L_801DF2C0
    if (ctx->r14 == ctx->r2) {
        // 0x801DF174: nop
    
            goto L_801DF2C0;
    }
    // 0x801DF174: nop

    // 0x801DF178: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801DF17C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DF180: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF184: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DF188: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801DF18C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801DF190: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF194: nop

    // 0x801DF198: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DF19C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF1A0: nop

    // 0x801DF1A4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF1A8: beql        $a0, $zero, L_801DF1F8
    if (ctx->r4 == 0) {
        // 0x801DF1AC: mfc1        $a0, $f4
        ctx->r4 = (int32_t)ctx->f4.u32l;
            goto L_801DF1F8;
    }
    goto skip_13;
    // 0x801DF1AC: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    skip_13:
    // 0x801DF1B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DF1B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF1B8: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801DF1BC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF1C0: nop

    // 0x801DF1C4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DF1C8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF1CC: nop

    // 0x801DF1D0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF1D4: bne         $a0, $zero, L_801DF1EC
    if (ctx->r4 != 0) {
        // 0x801DF1D8: nop
    
            goto L_801DF1EC;
    }
    // 0x801DF1D8: nop

    // 0x801DF1DC: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x801DF1E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DF1E4: b           L_801DF204
    // 0x801DF1E8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DF204;
    // 0x801DF1E8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DF1EC:
    // 0x801DF1EC: b           L_801DF204
    // 0x801DF1F0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DF204;
    // 0x801DF1F0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DF1F4: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
L_801DF1F8:
    // 0x801DF1F8: nop

    // 0x801DF1FC: bltz        $a0, L_801DF1EC
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DF200: nop
    
            goto L_801DF1EC;
    }
    // 0x801DF200: nop

L_801DF204:
    // 0x801DF204: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801DF208: jal         0x80011590
    // 0x801DF20C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_27;
    // 0x801DF20C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_27:
    // 0x801DF210: lhu         $t9, 0x4($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X4);
    // 0x801DF214: lui         $at, 0x41E8
    ctx->r1 = S32(0X41E8 << 16);
    // 0x801DF218: beq         $t9, $v0, L_801DF2C0
    if (ctx->r25 == ctx->r2) {
        // 0x801DF21C: nop
    
            goto L_801DF2C0;
    }
    // 0x801DF21C: nop

    // 0x801DF220: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801DF224: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DF228: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF22C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DF230: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801DF234: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801DF238: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF23C: nop

    // 0x801DF240: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801DF244: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF248: nop

    // 0x801DF24C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF250: beql        $a0, $zero, L_801DF2A0
    if (ctx->r4 == 0) {
        // 0x801DF254: mfc1        $a0, $f4
        ctx->r4 = (int32_t)ctx->f4.u32l;
            goto L_801DF2A0;
    }
    goto skip_14;
    // 0x801DF254: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    skip_14:
    // 0x801DF258: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DF25C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF260: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801DF264: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF268: nop

    // 0x801DF26C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DF270: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF274: nop

    // 0x801DF278: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF27C: bne         $a0, $zero, L_801DF294
    if (ctx->r4 != 0) {
        // 0x801DF280: nop
    
            goto L_801DF294;
    }
    // 0x801DF280: nop

    // 0x801DF284: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x801DF288: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DF28C: b           L_801DF2AC
    // 0x801DF290: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DF2AC;
    // 0x801DF290: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DF294:
    // 0x801DF294: b           L_801DF2AC
    // 0x801DF298: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DF2AC;
    // 0x801DF298: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DF29C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
L_801DF2A0:
    // 0x801DF2A0: nop

    // 0x801DF2A4: bltz        $a0, L_801DF294
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DF2A8: nop
    
            goto L_801DF294;
    }
    // 0x801DF2A8: nop

L_801DF2AC:
    // 0x801DF2AC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801DF2B0: jal         0x80011590
    // 0x801DF2B4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_28;
    // 0x801DF2B4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_28:
    // 0x801DF2B8: lhu         $t1, 0x4($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X4);
    // 0x801DF2BC: bne         $t1, $v0, L_801DF308
    if (ctx->r9 != ctx->r2) {
        // 0x801DF2C0: lui         $t2, 0x801C
        ctx->r10 = S32(0X801C << 16);
            goto L_801DF308;
    }
L_801DF2C0:
    // 0x801DF2C0: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801DF2C4: lhu         $t2, -0x440C($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X440C);
    // 0x801DF2C8: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801DF2CC: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801DF2D0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801DF2D4: lbu         $t3, 0x16A0($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X16A0);
    // 0x801DF2D8: lbu         $t7, -0x40B5($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X40B5);
    // 0x801DF2DC: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801DF2E0: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x801DF2E4: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x801DF2E8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x801DF2EC: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x801DF2F0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DF2F4: lhu         $t8, 0x15E8($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X15E8);
    // 0x801DF2F8: lwc1        $f6, 0x3FA8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X3FA8);
    // 0x801DF2FC: sh          $t8, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r24;
    // 0x801DF300: b           L_801DFA54
    // 0x801DF304: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
        goto L_801DFA54;
    // 0x801DF304: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
L_801DF308:
    // 0x801DF308: jal         0x80126944
    // 0x801DF30C: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_29;
    // 0x801DF30C: nop

    after_29:
    // 0x801DF310: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DF314: bne         $v0, $at, L_801DFA54
    if (ctx->r2 != ctx->r1) {
        // 0x801DF318: lw          $a0, 0x80($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X80);
            goto L_801DFA54;
    }
    // 0x801DF318: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801DF31C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DF320: addiu       $a2, $sp, 0x72
    ctx->r6 = ADD32(ctx->r29, 0X72);
    // 0x801DF324: jal         0x801DE590
    // 0x801DF328: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x801DE590)(rdram, ctx);
        goto after_30;
    // 0x801DF328: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_30:
    // 0x801DF32C: b           L_801DFA58
    // 0x801DF330: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
        goto L_801DFA58;
    // 0x801DF330: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
L_801DF334:
    // 0x801DF334: jal         0x80126944
    // 0x801DF338: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_31;
    // 0x801DF338: nop

    after_31:
    // 0x801DF33C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DF340: bne         $v0, $at, L_801DFA54
    if (ctx->r2 != ctx->r1) {
        // 0x801DF344: lw          $a0, 0x80($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X80);
            goto L_801DFA54;
    }
    // 0x801DF344: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801DF348: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DF34C: addiu       $a2, $sp, 0x72
    ctx->r6 = ADD32(ctx->r29, 0X72);
    // 0x801DF350: jal         0x801DE590
    // 0x801DF354: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x801DE590)(rdram, ctx);
        goto after_32;
    // 0x801DF354: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_32:
    // 0x801DF358: b           L_801DFA58
    // 0x801DF35C: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
        goto L_801DFA58;
    // 0x801DF35C: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
L_801DF360:
    // 0x801DF360: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801DF364: lui         $at, 0x191
    ctx->r1 = S32(0X191 << 16);
    // 0x801DF368: ori         $at, $at, 0x16
    ctx->r1 = ctx->r1 | 0X16;
    // 0x801DF36C: bne         $t9, $at, L_801DF6C0
    if (ctx->r25 != ctx->r1) {
        // 0x801DF370: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_801DF6C0;
    }
    // 0x801DF370: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801DF374: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DF378: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801DF37C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF380: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DF384: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801DF388: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801DF38C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF390: nop

    // 0x801DF394: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DF398: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF39C: nop

    // 0x801DF3A0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF3A4: beql        $a0, $zero, L_801DF3F4
    if (ctx->r4 == 0) {
        // 0x801DF3A8: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_801DF3F4;
    }
    goto skip_15;
    // 0x801DF3A8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_15:
    // 0x801DF3AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DF3B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF3B4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DF3B8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF3BC: nop

    // 0x801DF3C0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DF3C4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF3C8: nop

    // 0x801DF3CC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF3D0: bne         $a0, $zero, L_801DF3E8
    if (ctx->r4 != 0) {
        // 0x801DF3D4: nop
    
            goto L_801DF3E8;
    }
    // 0x801DF3D4: nop

    // 0x801DF3D8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801DF3DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DF3E0: b           L_801DF400
    // 0x801DF3E4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DF400;
    // 0x801DF3E4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DF3E8:
    // 0x801DF3E8: b           L_801DF400
    // 0x801DF3EC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DF400;
    // 0x801DF3EC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DF3F0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_801DF3F4:
    // 0x801DF3F4: nop

    // 0x801DF3F8: bltz        $a0, L_801DF3E8
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DF3FC: nop
    
            goto L_801DF3E8;
    }
    // 0x801DF3FC: nop

L_801DF400:
    // 0x801DF400: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801DF404: jal         0x80011590
    // 0x801DF408: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_33;
    // 0x801DF408: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_33:
    // 0x801DF40C: lhu         $t1, 0x4($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X4);
    // 0x801DF410: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801DF414: beql        $t1, $v0, L_801DF6B8
    if (ctx->r9 == ctx->r2) {
        // 0x801DF418: addiu       $t0, $zero, 0x662
        ctx->r8 = ADD32(0, 0X662);
            goto L_801DF6B8;
    }
    goto skip_16;
    // 0x801DF418: addiu       $t0, $zero, 0x662
    ctx->r8 = ADD32(0, 0X662);
    skip_16:
    // 0x801DF41C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801DF420: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DF424: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF428: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DF42C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801DF430: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801DF434: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF438: nop

    // 0x801DF43C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DF440: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF444: nop

    // 0x801DF448: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF44C: beql        $a0, $zero, L_801DF49C
    if (ctx->r4 == 0) {
        // 0x801DF450: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_801DF49C;
    }
    goto skip_17;
    // 0x801DF450: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_17:
    // 0x801DF454: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DF458: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF45C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DF460: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF464: nop

    // 0x801DF468: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DF46C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF470: nop

    // 0x801DF474: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF478: bne         $a0, $zero, L_801DF490
    if (ctx->r4 != 0) {
        // 0x801DF47C: nop
    
            goto L_801DF490;
    }
    // 0x801DF47C: nop

    // 0x801DF480: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801DF484: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DF488: b           L_801DF4A8
    // 0x801DF48C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DF4A8;
    // 0x801DF48C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DF490:
    // 0x801DF490: b           L_801DF4A8
    // 0x801DF494: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DF4A8;
    // 0x801DF494: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DF498: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_801DF49C:
    // 0x801DF49C: nop

    // 0x801DF4A0: bltz        $a0, L_801DF490
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DF4A4: nop
    
            goto L_801DF490;
    }
    // 0x801DF4A4: nop

L_801DF4A8:
    // 0x801DF4A8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801DF4AC: jal         0x80011590
    // 0x801DF4B0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_34;
    // 0x801DF4B0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_34:
    // 0x801DF4B4: lhu         $t3, 0x4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X4);
    // 0x801DF4B8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801DF4BC: beql        $t3, $v0, L_801DF6B8
    if (ctx->r11 == ctx->r2) {
        // 0x801DF4C0: addiu       $t0, $zero, 0x662
        ctx->r8 = ADD32(0, 0X662);
            goto L_801DF6B8;
    }
    goto skip_18;
    // 0x801DF4C0: addiu       $t0, $zero, 0x662
    ctx->r8 = ADD32(0, 0X662);
    skip_18:
    // 0x801DF4C4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801DF4C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DF4CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF4D0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DF4D4: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801DF4D8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801DF4DC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF4E0: nop

    // 0x801DF4E4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DF4E8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF4EC: nop

    // 0x801DF4F0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF4F4: beql        $a0, $zero, L_801DF544
    if (ctx->r4 == 0) {
        // 0x801DF4F8: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_801DF544;
    }
    goto skip_19;
    // 0x801DF4F8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_19:
    // 0x801DF4FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DF500: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF504: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DF508: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF50C: nop

    // 0x801DF510: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DF514: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF518: nop

    // 0x801DF51C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF520: bne         $a0, $zero, L_801DF538
    if (ctx->r4 != 0) {
        // 0x801DF524: nop
    
            goto L_801DF538;
    }
    // 0x801DF524: nop

    // 0x801DF528: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801DF52C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DF530: b           L_801DF550
    // 0x801DF534: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DF550;
    // 0x801DF534: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DF538:
    // 0x801DF538: b           L_801DF550
    // 0x801DF53C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DF550;
    // 0x801DF53C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DF540: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_801DF544:
    // 0x801DF544: nop

    // 0x801DF548: bltz        $a0, L_801DF538
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DF54C: nop
    
            goto L_801DF538;
    }
    // 0x801DF54C: nop

L_801DF550:
    // 0x801DF550: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801DF554: jal         0x80011590
    // 0x801DF558: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_35;
    // 0x801DF558: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_35:
    // 0x801DF55C: lhu         $t4, 0x4($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X4);
    // 0x801DF560: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x801DF564: beql        $t4, $v0, L_801DF6B8
    if (ctx->r12 == ctx->r2) {
        // 0x801DF568: addiu       $t0, $zero, 0x662
        ctx->r8 = ADD32(0, 0X662);
            goto L_801DF6B8;
    }
    goto skip_20;
    // 0x801DF568: addiu       $t0, $zero, 0x662
    ctx->r8 = ADD32(0, 0X662);
    skip_20:
    // 0x801DF56C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801DF570: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DF574: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF578: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DF57C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801DF580: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801DF584: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF588: nop

    // 0x801DF58C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DF590: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF594: nop

    // 0x801DF598: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF59C: beql        $a0, $zero, L_801DF5EC
    if (ctx->r4 == 0) {
        // 0x801DF5A0: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_801DF5EC;
    }
    goto skip_21;
    // 0x801DF5A0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_21:
    // 0x801DF5A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DF5A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF5AC: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DF5B0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF5B4: nop

    // 0x801DF5B8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DF5BC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF5C0: nop

    // 0x801DF5C4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF5C8: bne         $a0, $zero, L_801DF5E0
    if (ctx->r4 != 0) {
        // 0x801DF5CC: nop
    
            goto L_801DF5E0;
    }
    // 0x801DF5CC: nop

    // 0x801DF5D0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801DF5D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DF5D8: b           L_801DF5F8
    // 0x801DF5DC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DF5F8;
    // 0x801DF5DC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DF5E0:
    // 0x801DF5E0: b           L_801DF5F8
    // 0x801DF5E4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DF5F8;
    // 0x801DF5E4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DF5E8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_801DF5EC:
    // 0x801DF5EC: nop

    // 0x801DF5F0: bltz        $a0, L_801DF5E0
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DF5F4: nop
    
            goto L_801DF5E0;
    }
    // 0x801DF5F4: nop

L_801DF5F8:
    // 0x801DF5F8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801DF5FC: jal         0x80011590
    // 0x801DF600: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_36;
    // 0x801DF600: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_36:
    // 0x801DF604: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x801DF608: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x801DF60C: beql        $t6, $v0, L_801DF6B8
    if (ctx->r14 == ctx->r2) {
        // 0x801DF610: addiu       $t0, $zero, 0x662
        ctx->r8 = ADD32(0, 0X662);
            goto L_801DF6B8;
    }
    goto skip_22;
    // 0x801DF610: addiu       $t0, $zero, 0x662
    ctx->r8 = ADD32(0, 0X662);
    skip_22:
    // 0x801DF614: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801DF618: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DF61C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF620: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DF624: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801DF628: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801DF62C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF630: nop

    // 0x801DF634: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DF638: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF63C: nop

    // 0x801DF640: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF644: beql        $a0, $zero, L_801DF694
    if (ctx->r4 == 0) {
        // 0x801DF648: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_801DF694;
    }
    goto skip_23;
    // 0x801DF648: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_23:
    // 0x801DF64C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DF650: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF654: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DF658: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF65C: nop

    // 0x801DF660: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DF664: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF668: nop

    // 0x801DF66C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF670: bne         $a0, $zero, L_801DF688
    if (ctx->r4 != 0) {
        // 0x801DF674: nop
    
            goto L_801DF688;
    }
    // 0x801DF674: nop

    // 0x801DF678: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801DF67C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DF680: b           L_801DF6A0
    // 0x801DF684: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DF6A0;
    // 0x801DF684: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DF688:
    // 0x801DF688: b           L_801DF6A0
    // 0x801DF68C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DF6A0;
    // 0x801DF68C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DF690: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_801DF694:
    // 0x801DF694: nop

    // 0x801DF698: bltz        $a0, L_801DF688
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DF69C: nop
    
            goto L_801DF688;
    }
    // 0x801DF69C: nop

L_801DF6A0:
    // 0x801DF6A0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801DF6A4: jal         0x80011590
    // 0x801DF6A8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_37;
    // 0x801DF6A8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_37:
    // 0x801DF6AC: lhu         $t9, 0x4($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X4);
    // 0x801DF6B0: bne         $t9, $v0, L_801DF6C0
    if (ctx->r25 != ctx->r2) {
        // 0x801DF6B4: addiu       $t0, $zero, 0x662
        ctx->r8 = ADD32(0, 0X662);
            goto L_801DF6C0;
    }
    // 0x801DF6B4: addiu       $t0, $zero, 0x662
    ctx->r8 = ADD32(0, 0X662);
L_801DF6B8:
    // 0x801DF6B8: b           L_801DFA54
    // 0x801DF6BC: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
        goto L_801DFA54;
    // 0x801DF6BC: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
L_801DF6C0:
    // 0x801DF6C0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801DF6C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DF6C8: addiu       $a2, $sp, 0x72
    ctx->r6 = ADD32(ctx->r29, 0X72);
    // 0x801DF6CC: jal         0x801DE590
    // 0x801DF6D0: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x801DE590)(rdram, ctx);
        goto after_38;
    // 0x801DF6D0: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_38:
    // 0x801DF6D4: b           L_801DFA58
    // 0x801DF6D8: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
        goto L_801DFA58;
    // 0x801DF6D8: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
L_801DF6DC:
    // 0x801DF6DC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801DF6E0: lui         $at, 0x320
    ctx->r1 = S32(0X320 << 16);
    // 0x801DF6E4: ori         $at, $at, 0x15
    ctx->r1 = ctx->r1 | 0X15;
    // 0x801DF6E8: bne         $t1, $at, L_801DF994
    if (ctx->r9 != ctx->r1) {
        // 0x801DF6EC: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_801DF994;
    }
    // 0x801DF6EC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801DF6F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DF6F4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801DF6F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF6FC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DF700: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801DF704: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801DF708: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF70C: nop

    // 0x801DF710: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DF714: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF718: nop

    // 0x801DF71C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF720: beql        $a0, $zero, L_801DF770
    if (ctx->r4 == 0) {
        // 0x801DF724: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_801DF770;
    }
    goto skip_24;
    // 0x801DF724: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_24:
    // 0x801DF728: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DF72C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF730: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DF734: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF738: nop

    // 0x801DF73C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DF740: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF744: nop

    // 0x801DF748: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF74C: bne         $a0, $zero, L_801DF764
    if (ctx->r4 != 0) {
        // 0x801DF750: nop
    
            goto L_801DF764;
    }
    // 0x801DF750: nop

    // 0x801DF754: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801DF758: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DF75C: b           L_801DF77C
    // 0x801DF760: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DF77C;
    // 0x801DF760: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DF764:
    // 0x801DF764: b           L_801DF77C
    // 0x801DF768: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DF77C;
    // 0x801DF768: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DF76C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_801DF770:
    // 0x801DF770: nop

    // 0x801DF774: bltz        $a0, L_801DF764
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DF778: nop
    
            goto L_801DF764;
    }
    // 0x801DF778: nop

L_801DF77C:
    // 0x801DF77C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801DF780: jal         0x80011590
    // 0x801DF784: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_39;
    // 0x801DF784: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_39:
    // 0x801DF788: lhu         $t3, 0x4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X4);
    // 0x801DF78C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801DF790: beql        $t3, $v0, L_801DF98C
    if (ctx->r11 == ctx->r2) {
        // 0x801DF794: addiu       $t0, $zero, 0x684
        ctx->r8 = ADD32(0, 0X684);
            goto L_801DF98C;
    }
    goto skip_25;
    // 0x801DF794: addiu       $t0, $zero, 0x684
    ctx->r8 = ADD32(0, 0X684);
    skip_25:
    // 0x801DF798: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801DF79C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DF7A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF7A4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DF7A8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801DF7AC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801DF7B0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF7B4: nop

    // 0x801DF7B8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DF7BC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF7C0: nop

    // 0x801DF7C4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF7C8: beql        $a0, $zero, L_801DF818
    if (ctx->r4 == 0) {
        // 0x801DF7CC: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_801DF818;
    }
    goto skip_26;
    // 0x801DF7CC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_26:
    // 0x801DF7D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DF7D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF7D8: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DF7DC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF7E0: nop

    // 0x801DF7E4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DF7E8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF7EC: nop

    // 0x801DF7F0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF7F4: bne         $a0, $zero, L_801DF80C
    if (ctx->r4 != 0) {
        // 0x801DF7F8: nop
    
            goto L_801DF80C;
    }
    // 0x801DF7F8: nop

    // 0x801DF7FC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801DF800: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DF804: b           L_801DF824
    // 0x801DF808: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DF824;
    // 0x801DF808: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DF80C:
    // 0x801DF80C: b           L_801DF824
    // 0x801DF810: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DF824;
    // 0x801DF810: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DF814: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_801DF818:
    // 0x801DF818: nop

    // 0x801DF81C: bltz        $a0, L_801DF80C
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DF820: nop
    
            goto L_801DF80C;
    }
    // 0x801DF820: nop

L_801DF824:
    // 0x801DF824: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801DF828: jal         0x80011590
    // 0x801DF82C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_40;
    // 0x801DF82C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_40:
    // 0x801DF830: lhu         $t4, 0x4($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X4);
    // 0x801DF834: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x801DF838: beql        $t4, $v0, L_801DF98C
    if (ctx->r12 == ctx->r2) {
        // 0x801DF83C: addiu       $t0, $zero, 0x684
        ctx->r8 = ADD32(0, 0X684);
            goto L_801DF98C;
    }
    goto skip_27;
    // 0x801DF83C: addiu       $t0, $zero, 0x684
    ctx->r8 = ADD32(0, 0X684);
    skip_27:
    // 0x801DF840: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801DF844: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DF848: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF84C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DF850: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801DF854: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801DF858: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF85C: nop

    // 0x801DF860: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DF864: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF868: nop

    // 0x801DF86C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF870: beql        $a0, $zero, L_801DF8C0
    if (ctx->r4 == 0) {
        // 0x801DF874: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_801DF8C0;
    }
    goto skip_28;
    // 0x801DF874: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_28:
    // 0x801DF878: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DF87C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF880: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DF884: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF888: nop

    // 0x801DF88C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DF890: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF894: nop

    // 0x801DF898: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF89C: bne         $a0, $zero, L_801DF8B4
    if (ctx->r4 != 0) {
        // 0x801DF8A0: nop
    
            goto L_801DF8B4;
    }
    // 0x801DF8A0: nop

    // 0x801DF8A4: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801DF8A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DF8AC: b           L_801DF8CC
    // 0x801DF8B0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DF8CC;
    // 0x801DF8B0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DF8B4:
    // 0x801DF8B4: b           L_801DF8CC
    // 0x801DF8B8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DF8CC;
    // 0x801DF8B8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DF8BC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_801DF8C0:
    // 0x801DF8C0: nop

    // 0x801DF8C4: bltz        $a0, L_801DF8B4
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DF8C8: nop
    
            goto L_801DF8B4;
    }
    // 0x801DF8C8: nop

L_801DF8CC:
    // 0x801DF8CC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801DF8D0: jal         0x80011590
    // 0x801DF8D4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_41;
    // 0x801DF8D4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_41:
    // 0x801DF8D8: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x801DF8DC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801DF8E0: beql        $t6, $v0, L_801DF98C
    if (ctx->r14 == ctx->r2) {
        // 0x801DF8E4: addiu       $t0, $zero, 0x684
        ctx->r8 = ADD32(0, 0X684);
            goto L_801DF98C;
    }
    goto skip_29;
    // 0x801DF8E4: addiu       $t0, $zero, 0x684
    ctx->r8 = ADD32(0, 0X684);
    skip_29:
    // 0x801DF8E8: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801DF8EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DF8F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF8F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801DF8F8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801DF8FC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801DF900: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF904: nop

    // 0x801DF908: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801DF90C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF910: nop

    // 0x801DF914: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF918: beql        $a0, $zero, L_801DF968
    if (ctx->r4 == 0) {
        // 0x801DF91C: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_801DF968;
    }
    goto skip_30;
    // 0x801DF91C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_30:
    // 0x801DF920: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DF924: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801DF928: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801DF92C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801DF930: nop

    // 0x801DF934: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801DF938: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801DF93C: nop

    // 0x801DF940: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801DF944: bne         $a0, $zero, L_801DF95C
    if (ctx->r4 != 0) {
        // 0x801DF948: nop
    
            goto L_801DF95C;
    }
    // 0x801DF948: nop

    // 0x801DF94C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801DF950: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801DF954: b           L_801DF974
    // 0x801DF958: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801DF974;
    // 0x801DF958: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801DF95C:
    // 0x801DF95C: b           L_801DF974
    // 0x801DF960: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801DF974;
    // 0x801DF960: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801DF964: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_801DF968:
    // 0x801DF968: nop

    // 0x801DF96C: bltz        $a0, L_801DF95C
    if (SIGNED(ctx->r4) < 0) {
        // 0x801DF970: nop
    
            goto L_801DF95C;
    }
    // 0x801DF970: nop

L_801DF974:
    // 0x801DF974: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801DF978: jal         0x80011590
    // 0x801DF97C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80011590)(rdram, ctx);
        goto after_42;
    // 0x801DF97C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_42:
    // 0x801DF980: lhu         $t9, 0x4($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X4);
    // 0x801DF984: bne         $t9, $v0, L_801DF994
    if (ctx->r25 != ctx->r2) {
        // 0x801DF988: addiu       $t0, $zero, 0x684
        ctx->r8 = ADD32(0, 0X684);
            goto L_801DF994;
    }
    // 0x801DF988: addiu       $t0, $zero, 0x684
    ctx->r8 = ADD32(0, 0X684);
L_801DF98C:
    // 0x801DF98C: b           L_801DFA54
    // 0x801DF990: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
        goto L_801DFA54;
    // 0x801DF990: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
L_801DF994:
    // 0x801DF994: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801DF998: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DF99C: addiu       $a2, $sp, 0x72
    ctx->r6 = ADD32(ctx->r29, 0X72);
    // 0x801DF9A0: jal         0x801DE590
    // 0x801DF9A4: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x801DE590)(rdram, ctx);
        goto after_43;
    // 0x801DF9A4: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_43:
    // 0x801DF9A8: b           L_801DFA58
    // 0x801DF9AC: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
        goto L_801DFA58;
    // 0x801DF9AC: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
L_801DF9B0:
    // 0x801DF9B0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801DF9B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DF9B8: addiu       $a2, $sp, 0x72
    ctx->r6 = ADD32(ctx->r29, 0X72);
    // 0x801DF9BC: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    // 0x801DF9C0: jal         0x801DE5E4
    // 0x801DF9C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x801DE5E4)(rdram, ctx);
        goto after_44;
    // 0x801DF9C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_44:
    // 0x801DF9C8: b           L_801DFA58
    // 0x801DF9CC: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
        goto L_801DFA58;
    // 0x801DF9CC: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
L_801DF9D0:
    // 0x801DF9D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801DF9D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801DF9D8: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801DF9DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DF9E0: addiu       $a2, $sp, 0x72
    ctx->r6 = ADD32(ctx->r29, 0X72);
    // 0x801DF9E4: jal         0x801DE5E4
    // 0x801DF9E8: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x801DE5E4)(rdram, ctx);
        goto after_45;
    // 0x801DF9E8: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_45:
    // 0x801DF9EC: b           L_801DFA58
    // 0x801DF9F0: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
        goto L_801DFA58;
    // 0x801DF9F0: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
L_801DF9F4:
    // 0x801DF9F4: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801DF9F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DF9FC: addiu       $a2, $sp, 0x72
    ctx->r6 = ADD32(ctx->r29, 0X72);
    // 0x801DFA00: jal         0x801DE590
    // 0x801DFA04: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x801DE590)(rdram, ctx);
        goto after_46;
    // 0x801DFA04: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_46:
    // 0x801DFA08: lhu         $t2, 0x72($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X72);
    // 0x801DFA0C: beql        $t2, $zero, L_801DFA58
    if (ctx->r10 == 0) {
        // 0x801DFA10: lhu         $t5, 0x72($sp)
        ctx->r13 = MEM_HU(ctx->r29, 0X72);
            goto L_801DFA58;
    }
    goto skip_31;
    // 0x801DFA10: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
    skip_31:
    // 0x801DFA14: jal         0x801DFE28
    // 0x801DFA18: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    LOOKUP_FUNC(0x801DFE28)(rdram, ctx);
        goto after_47;
    // 0x801DFA18: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_47:
    // 0x801DFA1C: beq         $v0, $zero, L_801DFA30
    if (ctx->r2 == 0) {
        // 0x801DFA20: addiu       $t7, $zero, 0x6BC
        ctx->r15 = ADD32(0, 0X6BC);
            goto L_801DFA30;
    }
    // 0x801DFA20: addiu       $t7, $zero, 0x6BC
    ctx->r15 = ADD32(0, 0X6BC);
    // 0x801DFA24: addiu       $t3, $zero, 0x6BE
    ctx->r11 = ADD32(0, 0X6BE);
    // 0x801DFA28: b           L_801DFA54
    // 0x801DFA2C: sh          $t3, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r11;
        goto L_801DFA54;
    // 0x801DFA2C: sh          $t3, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r11;
L_801DFA30:
    // 0x801DFA30: b           L_801DFA54
    // 0x801DFA34: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
        goto L_801DFA54;
    // 0x801DFA34: sh          $t7, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r15;
L_801DFA38:
    // 0x801DFA38: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
L_801DFA3C:
    // 0x801DFA3C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801DFA40: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801DFA44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801DFA48: addiu       $a2, $sp, 0x72
    ctx->r6 = ADD32(ctx->r29, 0X72);
    // 0x801DFA4C: jal         0x801DE5E4
    // 0x801DFA50: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    LOOKUP_FUNC(0x801DE5E4)(rdram, ctx);
        goto after_48;
    // 0x801DFA50: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_48:
L_801DFA54:
    // 0x801DFA54: lhu         $t5, 0x72($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X72);
L_801DFA58:
    // 0x801DFA58: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x801DFA5C: beql        $t5, $zero, L_801DFA94
    if (ctx->r13 == 0) {
        // 0x801DFA60: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801DFA94;
    }
    goto skip_32;
    // 0x801DFA60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_32:
    // 0x801DFA64: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x801DFA68: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801DFA6C: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x801DFA70: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x801DFA74: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x801DFA78: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DFA7C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DFA80: lw          $a2, 0x8($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8);
    // 0x801DFA84: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801DFA88: jal         0x801DC9C4
    // 0x801DFA8C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DC9C4)(rdram, ctx);
        goto after_49;
    // 0x801DFA8C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_49:
L_801DFA90:
    // 0x801DFA90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801DFA94:
    // 0x801DFA94: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801DFA98: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x801DFA9C: jr          $ra
    // 0x801DFAA0: nop

    return;
    // 0x801DFAA0: nop

;}
RECOMP_FUNC void M8_FUN_801dfaa4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DFAA4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801DFAA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801DFAAC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801DFAB0: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801DFAB4: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x801DFAB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801DFABC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801DFAC0: addiu       $t2, $sp, 0x34
    ctx->r10 = ADD32(ctx->r29, 0X34);
    // 0x801DFAC4: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801DFAC8: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x801DFACC: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x801DFAD0: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x801DFAD4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801DFAD8: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x801DFADC: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x801DFAE0: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x801DFAE4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801DFAE8: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x801DFAEC: bne         $v1, $at, L_801DFB2C
    if (ctx->r3 != ctx->r1) {
        // 0x801DFAF0: swc1        $f8, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
            goto L_801DFB2C;
    }
    // 0x801DFAF0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x801DFAF4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801DFAF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801DFAFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DFB00: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
    // 0x801DFB04: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    // 0x801DFB08: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DFB0C: addiu       $a3, $zero, 0x30F
    ctx->r7 = ADD32(0, 0X30F);
    // 0x801DFB10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DFB14: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x801DFB18: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801DFB1C: jal         0x801DC9C4
    // 0x801DFB20: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DC9C4)(rdram, ctx);
        goto after_0;
    // 0x801DFB20: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_0:
    // 0x801DFB24: b           L_801DFC9C
    // 0x801DFB28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801DFC9C;
    // 0x801DFB28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801DFB2C:
    // 0x801DFB2C: lw          $t5, -0x4330($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4330);
    // 0x801DFB30: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801DFB34: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801DFB38: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x801DFB3C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801DFB40: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801DFB44: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801DFB48: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801DFB4C: cvt.d.s     $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.d = CVT_D_S(ctx->f14.fl);
    // 0x801DFB50: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x801DFB54: sub.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d - ctx->f18.d;
    // 0x801DFB58: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801DFB5C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x801DFB60: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801DFB64: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801DFB68: jal         0x801C5A1C
    // 0x801DFB6C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_1;
    // 0x801DFB6C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801DFB70: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801DFB74: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801DFB78: beq         $v0, $zero, L_801DFC98
    if (ctx->r2 == 0) {
        // 0x801DFB7C: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_801DFC98;
    }
    // 0x801DFB7C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x801DFB80: lhu         $t6, 0x4($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X4);
    // 0x801DFB84: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801DFB88: lbu         $t9, 0x35B($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X35B);
    // 0x801DFB8C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DFB90: lbu         $t7, 0x16A0($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X16A0);
    // 0x801DFB94: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x801DFB98: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801DFB9C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x801DFBA0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x801DFBA4: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // 0x801DFBA8: lhu         $a3, 0x15E0($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X15E0);
    // 0x801DFBAC: addiu       $at, $zero, 0x677
    ctx->r1 = ADD32(0, 0X677);
    // 0x801DFBB0: addiu       $t2, $sp, 0x34
    ctx->r10 = ADD32(ctx->r29, 0X34);
    // 0x801DFBB4: beq         $a3, $at, L_801DFC00
    if (ctx->r7 == ctx->r1) {
        // 0x801DFBB8: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_801DFC00;
    }
    // 0x801DFBB8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x801DFBBC: addiu       $at, $zero, 0x679
    ctx->r1 = ADD32(0, 0X679);
    // 0x801DFBC0: beq         $a3, $at, L_801DFC00
    if (ctx->r7 == ctx->r1) {
        // 0x801DFBC4: addiu       $at, $zero, 0x676
        ctx->r1 = ADD32(0, 0X676);
            goto L_801DFC00;
    }
    // 0x801DFBC4: addiu       $at, $zero, 0x676
    ctx->r1 = ADD32(0, 0X676);
    // 0x801DFBC8: beq         $a3, $at, L_801DFC00
    if (ctx->r7 == ctx->r1) {
        // 0x801DFBCC: addiu       $at, $zero, 0x678
        ctx->r1 = ADD32(0, 0X678);
            goto L_801DFC00;
    }
    // 0x801DFBCC: addiu       $at, $zero, 0x678
    ctx->r1 = ADD32(0, 0X678);
    // 0x801DFBD0: beq         $a3, $at, L_801DFC00
    if (ctx->r7 == ctx->r1) {
        // 0x801DFBD4: addiu       $at, $zero, 0x66E
        ctx->r1 = ADD32(0, 0X66E);
            goto L_801DFC00;
    }
    // 0x801DFBD4: addiu       $at, $zero, 0x66E
    ctx->r1 = ADD32(0, 0X66E);
    // 0x801DFBD8: beq         $a3, $at, L_801DFC00
    if (ctx->r7 == ctx->r1) {
        // 0x801DFBDC: addiu       $at, $zero, 0x670
        ctx->r1 = ADD32(0, 0X670);
            goto L_801DFC00;
    }
    // 0x801DFBDC: addiu       $at, $zero, 0x670
    ctx->r1 = ADD32(0, 0X670);
    // 0x801DFBE0: beq         $a3, $at, L_801DFC00
    if (ctx->r7 == ctx->r1) {
        // 0x801DFBE4: addiu       $at, $zero, 0x66F
        ctx->r1 = ADD32(0, 0X66F);
            goto L_801DFC00;
    }
    // 0x801DFBE4: addiu       $at, $zero, 0x66F
    ctx->r1 = ADD32(0, 0X66F);
    // 0x801DFBE8: beq         $a3, $at, L_801DFC00
    if (ctx->r7 == ctx->r1) {
        // 0x801DFBEC: addiu       $at, $zero, 0x671
        ctx->r1 = ADD32(0, 0X671);
            goto L_801DFC00;
    }
    // 0x801DFBEC: addiu       $at, $zero, 0x671
    ctx->r1 = ADD32(0, 0X671);
    // 0x801DFBF0: beq         $a3, $at, L_801DFC00
    if (ctx->r7 == ctx->r1) {
        // 0x801DFBF4: addiu       $at, $zero, 0x661
        ctx->r1 = ADD32(0, 0X661);
            goto L_801DFC00;
    }
    // 0x801DFBF4: addiu       $at, $zero, 0x661
    ctx->r1 = ADD32(0, 0X661);
    // 0x801DFBF8: bnel        $a3, $at, L_801DFC1C
    if (ctx->r7 != ctx->r1) {
        // 0x801DFBFC: addiu       $at, $zero, 0x672
        ctx->r1 = ADD32(0, 0X672);
            goto L_801DFC1C;
    }
    goto skip_0;
    // 0x801DFBFC: addiu       $at, $zero, 0x672
    ctx->r1 = ADD32(0, 0X672);
    skip_0:
L_801DFC00:
    // 0x801DFC00: bne         $v1, $zero, L_801DFC10
    if (ctx->r3 != 0) {
        // 0x801DFC04: nop
    
            goto L_801DFC10;
    }
    // 0x801DFC04: nop

    // 0x801DFC08: b           L_801DFC64
    // 0x801DFC0C: addiu       $a3, $zero, 0x308
    ctx->r7 = ADD32(0, 0X308);
        goto L_801DFC64;
    // 0x801DFC0C: addiu       $a3, $zero, 0x308
    ctx->r7 = ADD32(0, 0X308);
L_801DFC10:
    // 0x801DFC10: b           L_801DFC64
    // 0x801DFC14: addiu       $a3, $zero, 0x30C
    ctx->r7 = ADD32(0, 0X30C);
        goto L_801DFC64;
    // 0x801DFC14: addiu       $a3, $zero, 0x30C
    ctx->r7 = ADD32(0, 0X30C);
    // 0x801DFC18: addiu       $at, $zero, 0x672
    ctx->r1 = ADD32(0, 0X672);
L_801DFC1C:
    // 0x801DFC1C: beq         $v0, $at, L_801DFC3C
    if (ctx->r2 == ctx->r1) {
        // 0x801DFC20: addiu       $at, $zero, 0x674
        ctx->r1 = ADD32(0, 0X674);
            goto L_801DFC3C;
    }
    // 0x801DFC20: addiu       $at, $zero, 0x674
    ctx->r1 = ADD32(0, 0X674);
    // 0x801DFC24: beq         $v0, $at, L_801DFC3C
    if (ctx->r2 == ctx->r1) {
        // 0x801DFC28: addiu       $at, $zero, 0x673
        ctx->r1 = ADD32(0, 0X673);
            goto L_801DFC3C;
    }
    // 0x801DFC28: addiu       $at, $zero, 0x673
    ctx->r1 = ADD32(0, 0X673);
    // 0x801DFC2C: beq         $v0, $at, L_801DFC3C
    if (ctx->r2 == ctx->r1) {
        // 0x801DFC30: addiu       $at, $zero, 0x675
        ctx->r1 = ADD32(0, 0X675);
            goto L_801DFC3C;
    }
    // 0x801DFC30: addiu       $at, $zero, 0x675
    ctx->r1 = ADD32(0, 0X675);
    // 0x801DFC34: bne         $v0, $at, L_801DFC54
    if (ctx->r2 != ctx->r1) {
        // 0x801DFC38: nop
    
            goto L_801DFC54;
    }
    // 0x801DFC38: nop

L_801DFC3C:
    // 0x801DFC3C: bne         $v1, $zero, L_801DFC4C
    if (ctx->r3 != 0) {
        // 0x801DFC40: nop
    
            goto L_801DFC4C;
    }
    // 0x801DFC40: nop

    // 0x801DFC44: b           L_801DFC64
    // 0x801DFC48: addiu       $a3, $zero, 0x30A
    ctx->r7 = ADD32(0, 0X30A);
        goto L_801DFC64;
    // 0x801DFC48: addiu       $a3, $zero, 0x30A
    ctx->r7 = ADD32(0, 0X30A);
L_801DFC4C:
    // 0x801DFC4C: b           L_801DFC64
    // 0x801DFC50: addiu       $a3, $zero, 0x30E
    ctx->r7 = ADD32(0, 0X30E);
        goto L_801DFC64;
    // 0x801DFC50: addiu       $a3, $zero, 0x30E
    ctx->r7 = ADD32(0, 0X30E);
L_801DFC54:
    // 0x801DFC54: bne         $v1, $zero, L_801DFC64
    if (ctx->r3 != 0) {
        // 0x801DFC58: addiu       $a3, $zero, 0x30D
        ctx->r7 = ADD32(0, 0X30D);
            goto L_801DFC64;
    }
    // 0x801DFC58: addiu       $a3, $zero, 0x30D
    ctx->r7 = ADD32(0, 0X30D);
    // 0x801DFC5C: b           L_801DFC64
    // 0x801DFC60: addiu       $a3, $zero, 0x309
    ctx->r7 = ADD32(0, 0X309);
        goto L_801DFC64;
    // 0x801DFC60: addiu       $a3, $zero, 0x309
    ctx->r7 = ADD32(0, 0X309);
L_801DFC64:
    // 0x801DFC64: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801DFC68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801DFC6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DFC70: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
    // 0x801DFC74: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    // 0x801DFC78: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DFC7C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DFC80: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x801DFC84: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801DFC88: jal         0x801DC9C4
    // 0x801DFC8C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DC9C4)(rdram, ctx);
        goto after_2;
    // 0x801DFC8C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_2:
    // 0x801DFC90: b           L_801DFC9C
    // 0x801DFC94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801DFC9C;
    // 0x801DFC94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801DFC98:
    // 0x801DFC98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801DFC9C:
    // 0x801DFC9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801DFCA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801DFCA4: jr          $ra
    // 0x801DFCA8: nop

    return;
    // 0x801DFCA8: nop

;}
RECOMP_FUNC void M8_FUN_801dfcac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DFCAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801DFCB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801DFCB4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801DFCB8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801DFCBC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801DFCC0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801DFCC4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x801DFCC8: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801DFCCC: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x801DFCD0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x801DFCD4: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x801DFCD8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x801DFCDC: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x801DFCE0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801DFCE4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801DFCE8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DFCEC: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x801DFCF0: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801DFCF4: sub.d       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f0.d - ctx->f10.d;
    // 0x801DFCF8: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801DFCFC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801DFD00: add.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d + ctx->f6.d;
    // 0x801DFD04: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x801DFD08: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801DFD0C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801DFD10: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x801DFD14: jal         0x801C5A1C
    // 0x801DFD18: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
        goto after_0;
    // 0x801DFD18: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x801DFD1C: beq         $v0, $zero, L_801DFDF0
    if (ctx->r2 == 0) {
        // 0x801DFD20: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801DFDF0;
    }
    // 0x801DFD20: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801DFD24: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801DFD28: lhu         $t9, 0x4($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X4);
    // 0x801DFD2C: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801DFD30: lbu         $t2, 0x35B($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X35B);
    // 0x801DFD34: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801DFD38: lbu         $t0, 0x16A0($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X16A0);
    // 0x801DFD3C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x801DFD40: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801DFD44: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x801DFD48: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x801DFD4C: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x801DFD50: lhu         $v1, 0x15E0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X15E0);
    // 0x801DFD54: addiu       $at, $zero, 0x677
    ctx->r1 = ADD32(0, 0X677);
    // 0x801DFD58: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801DFD5C: beq         $v1, $at, L_801DFDAC
    if (ctx->r3 == ctx->r1) {
        // 0x801DFD60: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801DFDAC;
    }
    // 0x801DFD60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801DFD64: addiu       $at, $zero, 0x67B
    ctx->r1 = ADD32(0, 0X67B);
    // 0x801DFD68: beq         $v1, $at, L_801DFDAC
    if (ctx->r3 == ctx->r1) {
        // 0x801DFD6C: addiu       $at, $zero, 0x676
        ctx->r1 = ADD32(0, 0X676);
            goto L_801DFDAC;
    }
    // 0x801DFD6C: addiu       $at, $zero, 0x676
    ctx->r1 = ADD32(0, 0X676);
    // 0x801DFD70: beq         $v1, $at, L_801DFDAC
    if (ctx->r3 == ctx->r1) {
        // 0x801DFD74: addiu       $at, $zero, 0x67A
        ctx->r1 = ADD32(0, 0X67A);
            goto L_801DFDAC;
    }
    // 0x801DFD74: addiu       $at, $zero, 0x67A
    ctx->r1 = ADD32(0, 0X67A);
    // 0x801DFD78: beq         $v1, $at, L_801DFDAC
    if (ctx->r3 == ctx->r1) {
        // 0x801DFD7C: addiu       $at, $zero, 0x66E
        ctx->r1 = ADD32(0, 0X66E);
            goto L_801DFDAC;
    }
    // 0x801DFD7C: addiu       $at, $zero, 0x66E
    ctx->r1 = ADD32(0, 0X66E);
    // 0x801DFD80: beq         $v1, $at, L_801DFDAC
    if (ctx->r3 == ctx->r1) {
        // 0x801DFD84: addiu       $at, $zero, 0x672
        ctx->r1 = ADD32(0, 0X672);
            goto L_801DFDAC;
    }
    // 0x801DFD84: addiu       $at, $zero, 0x672
    ctx->r1 = ADD32(0, 0X672);
    // 0x801DFD88: beq         $v1, $at, L_801DFDAC
    if (ctx->r3 == ctx->r1) {
        // 0x801DFD8C: addiu       $at, $zero, 0x66F
        ctx->r1 = ADD32(0, 0X66F);
            goto L_801DFDAC;
    }
    // 0x801DFD8C: addiu       $at, $zero, 0x66F
    ctx->r1 = ADD32(0, 0X66F);
    // 0x801DFD90: beq         $v1, $at, L_801DFDAC
    if (ctx->r3 == ctx->r1) {
        // 0x801DFD94: addiu       $at, $zero, 0x673
        ctx->r1 = ADD32(0, 0X673);
            goto L_801DFDAC;
    }
    // 0x801DFD94: addiu       $at, $zero, 0x673
    ctx->r1 = ADD32(0, 0X673);
    // 0x801DFD98: beq         $v1, $at, L_801DFDAC
    if (ctx->r3 == ctx->r1) {
        // 0x801DFD9C: addiu       $at, $zero, 0x661
        ctx->r1 = ADD32(0, 0X661);
            goto L_801DFDAC;
    }
    // 0x801DFD9C: addiu       $at, $zero, 0x661
    ctx->r1 = ADD32(0, 0X661);
    // 0x801DFDA0: beq         $v1, $at, L_801DFDAC
    if (ctx->r3 == ctx->r1) {
        // 0x801DFDA4: addiu       $at, $zero, 0x67F
        ctx->r1 = ADD32(0, 0X67F);
            goto L_801DFDAC;
    }
    // 0x801DFDA4: addiu       $at, $zero, 0x67F
    ctx->r1 = ADD32(0, 0X67F);
    // 0x801DFDA8: bne         $v1, $at, L_801DFDB4
    if (ctx->r3 != ctx->r1) {
        // 0x801DFDAC: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_801DFDB4;
    }
L_801DFDAC:
    // 0x801DFDAC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801DFDB0: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
L_801DFDB4:
    // 0x801DFDB4: addiu       $at, $zero, 0x67B
    ctx->r1 = ADD32(0, 0X67B);
    // 0x801DFDB8: beq         $v0, $at, L_801DFDE8
    if (ctx->r2 == ctx->r1) {
        // 0x801DFDBC: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_801DFDE8;
    }
    // 0x801DFDBC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x801DFDC0: addiu       $at, $zero, 0x67A
    ctx->r1 = ADD32(0, 0X67A);
    // 0x801DFDC4: beq         $v0, $at, L_801DFDE8
    if (ctx->r2 == ctx->r1) {
        // 0x801DFDC8: addiu       $at, $zero, 0x67D
        ctx->r1 = ADD32(0, 0X67D);
            goto L_801DFDE8;
    }
    // 0x801DFDC8: addiu       $at, $zero, 0x67D
    ctx->r1 = ADD32(0, 0X67D);
    // 0x801DFDCC: beq         $v0, $at, L_801DFDE8
    if (ctx->r2 == ctx->r1) {
        // 0x801DFDD0: addiu       $at, $zero, 0x67C
        ctx->r1 = ADD32(0, 0X67C);
            goto L_801DFDE8;
    }
    // 0x801DFDD0: addiu       $at, $zero, 0x67C
    ctx->r1 = ADD32(0, 0X67C);
    // 0x801DFDD4: beq         $v0, $at, L_801DFDE8
    if (ctx->r2 == ctx->r1) {
        // 0x801DFDD8: addiu       $at, $zero, 0x67F
        ctx->r1 = ADD32(0, 0X67F);
            goto L_801DFDE8;
    }
    // 0x801DFDD8: addiu       $at, $zero, 0x67F
    ctx->r1 = ADD32(0, 0X67F);
    // 0x801DFDDC: beq         $v0, $at, L_801DFDE8
    if (ctx->r2 == ctx->r1) {
        // 0x801DFDE0: addiu       $at, $zero, 0x67E
        ctx->r1 = ADD32(0, 0X67E);
            goto L_801DFDE8;
    }
    // 0x801DFDE0: addiu       $at, $zero, 0x67E
    ctx->r1 = ADD32(0, 0X67E);
    // 0x801DFDE4: bne         $v0, $at, L_801DFDF0
    if (ctx->r2 != ctx->r1) {
        // 0x801DFDE8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801DFDF0;
    }
L_801DFDE8:
    // 0x801DFDE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801DFDEC: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
L_801DFDF0:
    // 0x801DFDF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801DFDF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801DFDF8: jr          $ra
    // 0x801DFDFC: nop

    return;
    // 0x801DFDFC: nop

;}
RECOMP_FUNC void M8_FUN_801dfe00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DFE00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801DFE04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DFE08: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    // 0x801DFE0C: jal         0x801DFCAC
    // 0x801DFE10: addiu       $a2, $sp, 0x1E
    ctx->r6 = ADD32(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x801DFCAC)(rdram, ctx);
        goto after_0;
    // 0x801DFE10: addiu       $a2, $sp, 0x1E
    ctx->r6 = ADD32(ctx->r29, 0X1E);
    after_0:
    // 0x801DFE14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DFE18: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x801DFE1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801DFE20: jr          $ra
    // 0x801DFE24: nop

    return;
    // 0x801DFE24: nop

;}
RECOMP_FUNC void M8_FUN_801dfe28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DFE28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801DFE2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DFE30: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    // 0x801DFE34: jal         0x801DFCAC
    // 0x801DFE38: addiu       $a2, $sp, 0x1E
    ctx->r6 = ADD32(ctx->r29, 0X1E);
    LOOKUP_FUNC(0x801DFCAC)(rdram, ctx);
        goto after_0;
    // 0x801DFE38: addiu       $a2, $sp, 0x1E
    ctx->r6 = ADD32(ctx->r29, 0X1E);
    after_0:
    // 0x801DFE3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DFE40: lbu         $v0, 0x1E($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1E);
    // 0x801DFE44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801DFE48: jr          $ra
    // 0x801DFE4C: nop

    return;
    // 0x801DFE4C: nop

;}
RECOMP_FUNC void M8_FUN_801dfe50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DFE50: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801DFE54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801DFE58: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801DFE5C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x801DFE60: lbu         $t3, 0x4F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4F);
    // 0x801DFE64: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFE68: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x801DFE6C: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x801DFE70: lwc1        $f0, 0x3FAC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3FAC);
    // 0x801DFE74: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801DFE78: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801DFE7C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801DFE80: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801DFE84: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x801DFE88: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x801DFE8C: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x801DFE90: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x801DFE94: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801DFE98: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x801DFE9C: lw          $t1, 0x24($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X24);
    // 0x801DFEA0: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801DFEA4: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x801DFEA8: beq         $t3, $at, L_801DFEC4
    if (ctx->r11 == ctx->r1) {
        // 0x801DFEAC: swc1        $f8, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
            goto L_801DFEC4;
    }
    // 0x801DFEAC: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x801DFEB0: jal         0x801DFE00
    // 0x801DFEB4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x801DFE00)(rdram, ctx);
        goto after_0;
    // 0x801DFEB4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x801DFEB8: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801DFEBC: b           L_801DFF0C
    // 0x801DFEC0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_801DFF0C;
    // 0x801DFEC0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_801DFEC4:
    // 0x801DFEC4: lhu         $v0, -0x440C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X440C);
    // 0x801DFEC8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801DFECC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801DFED0: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x801DFED4: bnel        $v0, $at, L_801DFEE8
    if (ctx->r2 != ctx->r1) {
        // 0x801DFED8: addiu       $at, $zero, 0x38
        ctx->r1 = ADD32(0, 0X38);
            goto L_801DFEE8;
    }
    goto skip_0;
    // 0x801DFED8: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    skip_0:
    // 0x801DFEDC: b           L_801DFF0C
    // 0x801DFEE0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801DFF0C;
    // 0x801DFEE0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801DFEE4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
L_801DFEE8:
    // 0x801DFEE8: bne         $v0, $at, L_801DFF0C
    if (ctx->r2 != ctx->r1) {
        // 0x801DFEEC: addiu       $a0, $zero, 0x238
        ctx->r4 = ADD32(0, 0X238);
            goto L_801DFF0C;
    }
    // 0x801DFEEC: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    // 0x801DFEF0: sb          $v1, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r3;
    // 0x801DFEF4: jal         0x80020DAC
    // 0x801DFEF8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80020DAC)(rdram, ctx);
        goto after_1;
    // 0x801DFEF8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x801DFEFC: lbu         $v1, 0x2F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X2F);
    // 0x801DFF00: beq         $v0, $zero, L_801DFF0C
    if (ctx->r2 == 0) {
        // 0x801DFF04: lwc1        $f0, 0x3C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_801DFF0C;
    }
    // 0x801DFF04: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801DFF08: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801DFF0C:
    // 0x801DFF0C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x801DFF10: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x801DFF14: addiu       $t5, $sp, 0x30
    ctx->r13 = ADD32(ctx->r29, 0X30);
    // 0x801DFF18: lhu         $v0, 0xE($t4)
    ctx->r2 = MEM_HU(ctx->r12, 0XE);
    // 0x801DFF1C: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x801DFF20: beq         $v0, $at, L_801DFF58
    if (ctx->r2 == ctx->r1) {
        // 0x801DFF24: addiu       $at, $zero, 0x2C
        ctx->r1 = ADD32(0, 0X2C);
            goto L_801DFF58;
    }
    // 0x801DFF24: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x801DFF28: beq         $v0, $at, L_801DFF58
    if (ctx->r2 == ctx->r1) {
        // 0x801DFF2C: addiu       $at, $zero, 0x50
        ctx->r1 = ADD32(0, 0X50);
            goto L_801DFF58;
    }
    // 0x801DFF2C: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x801DFF30: beq         $v0, $at, L_801DFF9C
    if (ctx->r2 == ctx->r1) {
        // 0x801DFF34: addiu       $t2, $sp, 0x30
        ctx->r10 = ADD32(ctx->r29, 0X30);
            goto L_801DFF9C;
    }
    // 0x801DFF34: addiu       $t2, $sp, 0x30
    ctx->r10 = ADD32(ctx->r29, 0X30);
    // 0x801DFF38: addiu       $at, $zero, 0x11B
    ctx->r1 = ADD32(0, 0X11B);
    // 0x801DFF3C: beq         $v0, $at, L_801DFFE4
    if (ctx->r2 == ctx->r1) {
        // 0x801DFF40: addiu       $t9, $sp, 0x30
        ctx->r25 = ADD32(ctx->r29, 0X30);
            goto L_801DFFE4;
    }
    // 0x801DFF40: addiu       $t9, $sp, 0x30
    ctx->r25 = ADD32(ctx->r29, 0X30);
    // 0x801DFF44: addiu       $at, $zero, 0x11C
    ctx->r1 = ADD32(0, 0X11C);
    // 0x801DFF48: beql        $v0, $at, L_801DFFE8
    if (ctx->r2 == ctx->r1) {
        // 0x801DFF4C: lw          $t1, 0x0($t9)
        ctx->r9 = MEM_W(ctx->r25, 0X0);
            goto L_801DFFE8;
    }
    goto skip_1;
    // 0x801DFF4C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    skip_1:
    // 0x801DFF50: b           L_801DFFE8
    // 0x801DFF54: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
        goto L_801DFFE8;
    // 0x801DFF54: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
L_801DFF58:
    // 0x801DFF58: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801DFF5C: lbu         $t8, 0x4F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4F);
    // 0x801DFF60: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801DFF64: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x801DFF68: lw          $a1, 0x4($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X4);
    // 0x801DFF6C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801DFF70: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x801DFF74: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DFF78: lw          $a2, 0x8($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X8);
    // 0x801DFF7C: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // 0x801DFF80: lhu         $a3, 0x202C($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X202C);
    // 0x801DFF84: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801DFF88: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DFF8C: jal         0x801DC9C4
    // 0x801DFF90: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DC9C4)(rdram, ctx);
        goto after_2;
    // 0x801DFF90: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_2:
    // 0x801DFF94: b           L_801E0028
    // 0x801DFF98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801E0028;
    // 0x801DFF98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801DFF9C:
    // 0x801DFF9C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801DFFA0: lbu         $t5, 0x4F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4F);
    // 0x801DFFA4: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x801DFFA8: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
    // 0x801DFFAC: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    // 0x801DFFB0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801DFFB4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801DFFB8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801DFFBC: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x801DFFC0: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801DFFC4: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x801DFFC8: lhu         $a3, 0x2048($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X2048);
    // 0x801DFFCC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801DFFD0: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801DFFD4: jal         0x801DC9C4
    // 0x801DFFD8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DC9C4)(rdram, ctx);
        goto after_3;
    // 0x801DFFD8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_3:
    // 0x801DFFDC: b           L_801E0028
    // 0x801DFFE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801E0028;
    // 0x801DFFE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801DFFE4:
    // 0x801DFFE4: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
L_801DFFE8:
    // 0x801DFFE8: lbu         $t2, 0x4F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4F);
    // 0x801DFFEC: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x801DFFF0: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x801DFFF4: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    // 0x801DFFF8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801DFFFC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x801E0000: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E0004: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    // 0x801E0008: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801E000C: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x801E0010: lhu         $a3, 0x2010($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X2010);
    // 0x801E0014: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801E0018: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801E001C: jal         0x801DC9C4
    // 0x801E0020: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801DC9C4)(rdram, ctx);
        goto after_4;
    // 0x801E0020: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_4:
    // 0x801E0024: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801E0028:
    // 0x801E0028: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801E002C: jr          $ra
    // 0x801E0030: nop

    return;
    // 0x801E0030: nop

;}
RECOMP_FUNC void M8_FUN_801e0034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E0034: nop

    // 0x801E0038: nop

    // 0x801E003C: nop

;}
RECOMP_FUNC void M8_FUN_801e0040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E0040: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E0044: lhu         $t6, -0x3520($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3520);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801e0048(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801e0048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E0048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E004C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E0050: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x801E0054: beql        $t7, $zero, L_801E0070
    if (ctx->r15 == 0) {
        // 0x801E0058: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_801E0070;
    }
    goto skip_0;
    // 0x801E0058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x801E005C: jal         0x8001F74C
    // 0x801E0060: nop

    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_0;
    // 0x801E0060: nop

    after_0:
    // 0x801E0064: b           L_801E018C
    // 0x801E0068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801E018C;
    // 0x801E0068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E006C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_801E0070:
    // 0x801E0070: jal         0x8001F75C
    // 0x801E0074: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001F75C)(rdram, ctx);
        goto after_1;
    // 0x801E0074: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x801E0078: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801E007C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801E0080: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E0084: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x801E0088: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x801E008C: ldc1        $f0, 0x4008($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X4008);
    // 0x801E0090: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801E0094: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801E0098: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E009C: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x801E00A0: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801E00A4: lwc1        $f16, 0x44($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X44);
    // 0x801E00A8: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801E00AC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801E00B0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E00B4: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x801E00B8: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x801E00BC: lwc1        $f6, 0x48($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X48);
    // 0x801E00C0: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x801E00C4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801E00C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E00CC: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x801E00D0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x801E00D4: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x801E00D8: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x801E00DC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801E00E0: add.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f16.d + ctx->f0.d;
    // 0x801E00E4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E00E8: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x801E00EC: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x801E00F0: lw          $v0, 0x30($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X30);
    // 0x801E00F4: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801E00F8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801E00FC: add.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f8.d + ctx->f0.d;
    // 0x801E0100: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E0104: swc1        $f16, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f16.u32l;
    // 0x801E0108: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x801E010C: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x801E0110: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801E0114: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x801E0118: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x801E011C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E0120: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    // 0x801E0124: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x801E0128: lwc1        $f16, 0x94($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801E012C: lh          $t5, 0x92($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X92);
    // 0x801E0130: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E0134: swc1        $f18, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f18.u32l;
    // 0x801E0138: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x801E013C: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x801E0140: lbu         $v1, 0x4B($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4B);
    // 0x801E0144: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
    // 0x801E0148: bgezl       $v1, L_801E0158
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801E014C: slti        $at, $v1, 0x100
        ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
            goto L_801E0158;
    }
    goto skip_1;
    // 0x801E014C: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    skip_1:
    // 0x801E0150: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801E0154: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
L_801E0158:
    // 0x801E0158: bnel        $at, $zero, L_801E0168
    if (ctx->r1 != 0) {
        // 0x801E015C: sb          $v1, 0x4B($v0)
        MEM_B(0X4B, ctx->r2) = ctx->r3;
            goto L_801E0168;
    }
    goto skip_2;
    // 0x801E015C: sb          $v1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r3;
    skip_2:
    // 0x801E0160: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801E0164: sb          $v1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r3;
L_801E0168:
    // 0x801E0168: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x801E016C: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x801E0170: bne         $t7, $zero, L_801E0180
    if (ctx->r15 != 0) {
        // 0x801E0174: nop
    
            goto L_801E0180;
    }
    // 0x801E0174: nop

    // 0x801E0178: bnel        $v1, $zero, L_801E018C
    if (ctx->r3 != 0) {
        // 0x801E017C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801E018C;
    }
    goto skip_3;
    // 0x801E017C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_801E0180:
    // 0x801E0180: jal         0x80005700
    // 0x801E0184: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x801E0184: nop

    after_2:
    // 0x801E0188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801E018C:
    // 0x801E018C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E0190: jr          $ra
    // 0x801E0194: nop

    return;
    // 0x801E0194: nop

;}
RECOMP_FUNC void M8_FUN_801e0198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E0198: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E019C: lhu         $t6, -0x3520($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3520);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801e01a0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801e01a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E01A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E01A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E01A8: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x801E01AC: beql        $t7, $zero, L_801E01C8
    if (ctx->r15 == 0) {
        // 0x801E01B0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_801E01C8;
    }
    goto skip_0;
    // 0x801E01B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x801E01B4: jal         0x8001F74C
    // 0x801E01B8: nop

    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_0;
    // 0x801E01B8: nop

    after_0:
    // 0x801E01BC: b           L_801E0288
    // 0x801E01C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801E0288;
    // 0x801E01C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E01C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_801E01C8:
    // 0x801E01C8: jal         0x8001F75C
    // 0x801E01CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8001F75C)(rdram, ctx);
        goto after_1;
    // 0x801E01CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x801E01D0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801E01D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801E01D8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x801E01DC: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x801E01E0: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801E01E4: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801E01E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E01EC: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x801E01F0: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801E01F4: lwc1        $f16, 0x44($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X44);
    // 0x801E01F8: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x801E01FC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801E0200: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E0204: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x801E0208: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x801E020C: lwc1        $f6, 0x48($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X48);
    // 0x801E0210: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x801E0214: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801E0218: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E021C: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x801E0220: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x801E0224: lwc1        $f16, 0x94($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801E0228: lh          $t2, 0x92($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X92);
    // 0x801E022C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E0230: swc1        $f18, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f18.u32l;
    // 0x801E0234: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x801E0238: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    // 0x801E023C: lbu         $v1, 0x4B($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4B);
    // 0x801E0240: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x801E0244: bgezl       $v1, L_801E0254
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801E0248: slti        $at, $v1, 0x100
        ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
            goto L_801E0254;
    }
    goto skip_1;
    // 0x801E0248: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    skip_1:
    // 0x801E024C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801E0250: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
L_801E0254:
    // 0x801E0254: bnel        $at, $zero, L_801E0264
    if (ctx->r1 != 0) {
        // 0x801E0258: sb          $v1, 0x4B($v0)
        MEM_B(0X4B, ctx->r2) = ctx->r3;
            goto L_801E0264;
    }
    goto skip_2;
    // 0x801E0258: sb          $v1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r3;
    skip_2:
    // 0x801E025C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801E0260: sb          $v1, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r3;
L_801E0264:
    // 0x801E0264: lw          $t3, 0x30($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X30);
    // 0x801E0268: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x801E026C: bne         $t4, $zero, L_801E027C
    if (ctx->r12 != 0) {
        // 0x801E0270: nop
    
            goto L_801E027C;
    }
    // 0x801E0270: nop

    // 0x801E0274: bnel        $v1, $zero, L_801E0288
    if (ctx->r3 != 0) {
        // 0x801E0278: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801E0288;
    }
    goto skip_3;
    // 0x801E0278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_801E027C:
    // 0x801E027C: jal         0x80005700
    // 0x801E0280: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x801E0280: nop

    after_2:
    // 0x801E0284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801E0288:
    // 0x801E0288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E028C: jr          $ra
    // 0x801E0290: nop

    return;
    // 0x801E0290: nop

;}
RECOMP_FUNC void M8_FUN_801e0294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E0294: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801E0298: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E029C: sb          $v0, 0x20F8($at)
    MEM_B(0X20F8, ctx->r1) = ctx->r2;
    // 0x801E02A0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E02A4: sb          $v0, 0x20FC($at)
    MEM_B(0X20FC, ctx->r1) = ctx->r2;
    // 0x801E02A8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E02AC: sb          $v0, 0x2100($at)
    MEM_B(0X2100, ctx->r1) = ctx->r2;
    // 0x801E02B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E02B4: sb          $v0, 0x2104($at)
    MEM_B(0X2104, ctx->r1) = ctx->r2;
    // 0x801E02B8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E02BC: sb          $v0, 0x2108($at)
    MEM_B(0X2108, ctx->r1) = ctx->r2;
    // 0x801E02C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E02C4: sb          $v0, 0x210C($at)
    MEM_B(0X210C, ctx->r1) = ctx->r2;
    // 0x801E02C8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E02CC: sb          $v0, 0x2110($at)
    MEM_B(0X2110, ctx->r1) = ctx->r2;
    // 0x801E02D0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E02D4: jr          $ra
    // 0x801E02D8: sb          $zero, 0x2114($at)
    MEM_B(0X2114, ctx->r1) = 0;
    return;
    // 0x801E02D8: sb          $zero, 0x2114($at)
    MEM_B(0X2114, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801e02dc(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801e02dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E02DC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801E02E0: lbu         $t6, 0x93($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X93);
    // 0x801E02E4: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801E02E8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801E02EC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801E02F0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801E02F4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E02F8: addiu       $t8, $t8, 0x2118
    ctx->r24 = ADD32(ctx->r24, 0X2118);
    // 0x801E02FC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801E0300: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x801E0304: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801E0308: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x801E030C: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x801E0310: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x801E0314: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x801E0318: jal         0x80017064
    // 0x801E031C: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_0;
    // 0x801E031C: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    after_0:
    // 0x801E0320: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801E0324: bne         $v0, $at, L_801E0334
    if (ctx->r2 != ctx->r1) {
        // 0x801E0328: lbu         $t9, 0x93($sp)
        ctx->r25 = MEM_BU(ctx->r29, 0X93);
            goto L_801E0334;
    }
    // 0x801E0328: lbu         $t9, 0x93($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X93);
    // 0x801E032C: b           L_801E0634
    // 0x801E0330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801E0634;
    // 0x801E0330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801E0334:
    // 0x801E0334: beq         $t9, $zero, L_801E0348
    if (ctx->r25 == 0) {
        // 0x801E0338: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801E0348;
    }
    // 0x801E0338: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801E033C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801E0340: b           L_801E034C
    // 0x801E0344: addiu       $v0, $v0, 0x2084
    ctx->r2 = ADD32(ctx->r2, 0X2084);
        goto L_801E034C;
    // 0x801E0344: addiu       $v0, $v0, 0x2084
    ctx->r2 = ADD32(ctx->r2, 0X2084);
L_801E0348:
    // 0x801E0348: addiu       $v0, $v0, 0x2070
    ctx->r2 = ADD32(ctx->r2, 0X2070);
L_801E034C:
    // 0x801E034C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801E0350: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E0354: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x801E0358: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x801E035C: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x801E0360: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801E0364: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x801E0368: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x801E036C: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x801E0370: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801E0374: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x801E0378: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x801E037C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801E0380: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801E0384: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x801E0388: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801E038C: jal         0x8012C4D0
    // 0x801E0390: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_1;
    // 0x801E0390: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_1:
    // 0x801E0394: beq         $v0, $zero, L_801E0630
    if (ctx->r2 == 0) {
        // 0x801E0398: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_801E0630;
    }
    // 0x801E0398: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801E039C: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801E03A0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801E03A4: addiu       $v0, $v0, 0x2114
    ctx->r2 = ADD32(ctx->r2, 0X2114);
    // 0x801E03A8: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x801E03AC: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801E03B0: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x801E03B4: addiu       $t5, $t5, 0x4F40
    ctx->r13 = ADD32(ctx->r13, 0X4F40);
    // 0x801E03B8: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x801E03BC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801E03C0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x801E03C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801E03C8: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x801E03CC: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801E03D0: swc1        $f10, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f10.u32l;
    // 0x801E03D4: lb          $t7, 0x8B($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X8B);
    // 0x801E03D8: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x801E03DC: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x801E03E0: sh          $t8, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r24;
    // 0x801E03E4: lbu         $t9, 0x97($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X97);
    // 0x801E03E8: sb          $t9, 0x91($s0)
    MEM_B(0X91, ctx->r16) = ctx->r25;
    // 0x801E03EC: lbu         $t4, 0x93($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X93);
    // 0x801E03F0: sh          $zero, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = 0;
    // 0x801E03F4: sb          $t4, 0x90($s0)
    MEM_B(0X90, ctx->r16) = ctx->r12;
    // 0x801E03F8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801E03FC: lw          $t8, 0x10($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X10);
    // 0x801E0400: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x801E0404: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801E0408: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x801E040C: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x801E0410: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
    // 0x801E0414: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x801E0418: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
    // 0x801E041C: jal         0x80005E44
    // 0x801E0420: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x801E0420: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    after_2:
    // 0x801E0424: jal         0x80006214
    // 0x801E0428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801E0428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801E042C: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801E0430: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801E0434: lwc1        $f0, 0x8C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x801E0438: lw          $t4, 0x30($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X30);
    // 0x801E043C: addiu       $t9, $zero, 0x1800
    ctx->r25 = ADD32(0, 0X1800);
    // 0x801E0440: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801E0444: swc1        $f16, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f16.u32l;
    // 0x801E0448: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x801E044C: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801E0450: addiu       $v1, $v1, 0x20F8
    ctx->r3 = ADD32(ctx->r3, 0X20F8);
    // 0x801E0454: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801E0458: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E045C: addiu       $a0, $a0, 0x20FC
    ctx->r4 = ADD32(ctx->r4, 0X20FC);
    // 0x801E0460: swc1        $f18, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f18.u32l;
    // 0x801E0464: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801E0468: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801E046C: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801E0470: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801E0474: addiu       $t3, $t3, 0x2100
    ctx->r11 = ADD32(ctx->r11, 0X2100);
    // 0x801E0478: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801E047C: swc1        $f4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f4.u32l;
    // 0x801E0480: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801E0484: addiu       $v0, $v0, 0x2110
    ctx->r2 = ADD32(ctx->r2, 0X2110);
    // 0x801E0488: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801E048C: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801E0490: addiu       $t2, $t2, -0x4410
    ctx->r10 = ADD32(ctx->r10, -0X4410);
    // 0x801E0494: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801E0498: sh          $t9, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r25;
    // 0x801E049C: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801E04A0: addiu       $t0, $t0, 0x2108
    ctx->r8 = ADD32(ctx->r8, 0X2108);
    // 0x801E04A4: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801E04A8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801E04AC: addiu       $t1, $t1, 0x210C
    ctx->r9 = ADD32(ctx->r9, 0X210C);
    // 0x801E04B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E04B4: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    // 0x801E04B8: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801E04BC: lw          $t4, 0x30($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X30);
    // 0x801E04C0: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
    // 0x801E04C4: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801E04C8: lw          $t5, 0x30($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X30);
    // 0x801E04CC: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x801E04D0: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801E04D4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801E04D8: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    // 0x801E04DC: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801E04E0: lw          $t4, 0x30($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X30);
    // 0x801E04E4: swc1        $f0, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f0.u32l;
    // 0x801E04E8: lbu         $t5, 0x6F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X6F);
    // 0x801E04EC: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x801E04F0: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801E04F4: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801E04F8: addiu       $v1, $v1, 0x2104
    ctx->r3 = ADD32(ctx->r3, 0X2104);
    // 0x801E04FC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801E0500: sb          $t5, 0x48($t7)
    MEM_B(0X48, ctx->r15) = ctx->r13;
    // 0x801E0504: lbu         $t4, 0x73($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X73);
    // 0x801E0508: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x801E050C: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801E0510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801E0514: lw          $t6, 0x30($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X30);
    // 0x801E0518: sb          $t4, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r12;
    // 0x801E051C: lbu         $t7, 0x77($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X77);
    // 0x801E0520: sb          $t7, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r15;
    // 0x801E0524: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801E0528: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801E052C: sb          $t7, 0x4A($t9)
    MEM_B(0X4A, ctx->r25) = ctx->r15;
    // 0x801E0530: lbu         $t6, 0x87($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X87);
    // 0x801E0534: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x801E0538: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x801E053C: lw          $t8, 0x30($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X30);
    // 0x801E0540: sb          $t6, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = ctx->r14;
    // 0x801E0544: lbu         $t9, 0xF32($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0XF32);
    // 0x801E0548: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x801E054C: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801E0550: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801E0554: sb          $t9, 0x4C($t5)
    MEM_B(0X4C, ctx->r13) = ctx->r25;
    // 0x801E0558: lbu         $t8, 0xF33($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0XF33);
    // 0x801E055C: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x801E0560: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801E0564: lw          $t4, 0x30($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X30);
    // 0x801E0568: sb          $t8, 0x4D($t4)
    MEM_B(0X4D, ctx->r12) = ctx->r24;
    // 0x801E056C: lbu         $t5, 0xF34($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0XF34);
    // 0x801E0570: sb          $t5, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r13;
    // 0x801E0574: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801E0578: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801E057C: sb          $t5, 0x4E($t7)
    MEM_B(0X4E, ctx->r15) = ctx->r13;
    // 0x801E0580: lhu         $a3, 0x4($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X4);
    // 0x801E0584: jal         0x8012C89C
    // 0x801E0588: lhu         $a2, 0x2($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X2);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_4;
    // 0x801E0588: lhu         $a2, 0x2($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X2);
    after_4:
    // 0x801E058C: lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6);
    // 0x801E0590: lbu         $t8, 0x97($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X97);
    // 0x801E0594: beq         $v0, $zero, L_801E05DC
    if (ctx->r2 == 0) {
        // 0x801E0598: andi        $t4, $t8, 0x1
        ctx->r12 = ctx->r24 & 0X1;
            goto L_801E05DC;
    }
    // 0x801E0598: andi        $t4, $t8, 0x1
    ctx->r12 = ctx->r24 & 0X1;
    // 0x801E059C: beq         $t4, $zero, L_801E05C8
    if (ctx->r12 == 0) {
        // 0x801E05A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801E05C8;
    }
    // 0x801E05A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801E05A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801E05A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801E05AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801E05B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801E05B4: lhu         $a2, 0x8($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X8);
    // 0x801E05B8: jal         0x8012D814
    // 0x801E05BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    LOOKUP_FUNC(0x8012D814)(rdram, ctx);
        goto after_5;
    // 0x801E05BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_5:
    // 0x801E05C0: b           L_801E05E0
    // 0x801E05C4: lhu         $a2, 0xA($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0XA);
        goto L_801E05E0;
    // 0x801E05C4: lhu         $a2, 0xA($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0XA);
L_801E05C8:
    // 0x801E05C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801E05CC: lhu         $a2, 0x8($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X8);
    // 0x801E05D0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801E05D4: jal         0x8012D814
    // 0x801E05D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x8012D814)(rdram, ctx);
        goto after_6;
    // 0x801E05D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
L_801E05DC:
    // 0x801E05DC: lhu         $a2, 0xA($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0XA);
L_801E05E0:
    // 0x801E05E0: beql        $a2, $zero, L_801E0604
    if (ctx->r6 == 0) {
        // 0x801E05E4: lw          $t7, 0x24($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X24);
            goto L_801E0604;
    }
    goto skip_0;
    // 0x801E05E4: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x801E05E8: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801E05EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801E05F0: lhu         $a3, 0xC($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0XC);
    // 0x801E05F4: lw          $a1, 0x30($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X30);
    // 0x801E05F8: jal         0x8012CF8C
    // 0x801E05FC: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_7;
    // 0x801E05FC: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_7:
    // 0x801E0600: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
L_801E0604:
    // 0x801E0604: lw          $t5, 0x14($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X14);
    // 0x801E0608: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801E060C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801E0610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801E0614: sw          $t5, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r13;
    // 0x801E0618: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801E061C: lw          $t4, 0x18($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X18);
    // 0x801E0620: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801E0624: or          $t9, $t4, $at
    ctx->r25 = ctx->r12 | ctx->r1;
    // 0x801E0628: b           L_801E0634
    // 0x801E062C: sw          $t9, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r25;
        goto L_801E0634;
    // 0x801E062C: sw          $t9, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r25;
L_801E0630:
    // 0x801E0630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801E0634:
    // 0x801E0634: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801E0638: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801E063C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801E0640: jr          $ra
    // 0x801E0644: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801E0644: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801e0648(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801e0648(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x801E0648u);
    return;
}
RECOMP_FUNC void M9_FUN_801e4aa0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4AA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801e4aa4(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801e4aa4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4AA4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801E4AA8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801E4AAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E4AB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801E4AB4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801E4AB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801E4ABC: jal         0x80126CC0
    // 0x801E4AC0: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    LOOKUP_FUNC(0x80126CC0)(rdram, ctx);
        goto after_0;
    // 0x801E4AC0: addiu       $a1, $a1, 0x6EAC
    ctx->r5 = ADD32(ctx->r5, 0X6EAC);
    after_0:
    // 0x801E4AC4: beq         $v0, $zero, L_801E4CB8
    if (ctx->r2 == 0) {
        // 0x801E4AC8: lui         $t7, 0x8016
        ctx->r15 = S32(0X8016 << 16);
            goto L_801E4CB8;
    }
    // 0x801E4AC8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x801E4ACC: addiu       $t7, $t7, 0x4F40
    ctx->r15 = ADD32(ctx->r15, 0X4F40);
    // 0x801E4AD0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801E4AD4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801E4AD8: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x801E4ADC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801E4AE0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801E4AE4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801E4AE8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801E4AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801E4AF0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801E4AF4: jal         0x8001F74C
    // 0x801E4AF8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    LOOKUP_FUNC(0x8001F74C)(rdram, ctx);
        goto after_1;
    // 0x801E4AF8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    after_1:
    // 0x801E4AFC: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x801E4B00: ori         $t0, $t0, 0xC00
    ctx->r8 = ctx->r8 | 0XC00;
    // 0x801E4B04: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x801E4B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801E4B0C: jal         0x80005E44
    // 0x801E4B10: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x801E4B10: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x801E4B14: jal         0x80006214
    // 0x801E4B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x801E4B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801E4B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801E4B20: jal         0x8012636C
    // 0x801E4B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x8012636C)(rdram, ctx);
        goto after_4;
    // 0x801E4B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x801E4B28: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x801E4B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801E4B30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E4B34: lw          $a2, 0x14($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X14);
    // 0x801E4B38: srl         $a2, $a2, 8
    ctx->r6 = S32(U32(ctx->r6) >> 8);
    // 0x801E4B3C: jal         0x8012C784
    // 0x801E4B40: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(0x8012C784)(rdram, ctx);
        goto after_5;
    // 0x801E4B40: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_5:
    // 0x801E4B44: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801E4B48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E4B4C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801E4B50: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801E4B54: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801E4B58: swc1        $f0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f0.u32l;
    // 0x801E4B5C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801E4B60: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801E4B64: swc1        $f0, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f0.u32l;
    // 0x801E4B68: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801E4B6C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801E4B70: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x801E4B74: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x801E4B78: lhu         $t0, 0x36($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X36);
    // 0x801E4B7C: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x801E4B80: ori         $t9, $t8, 0x800
    ctx->r25 = ctx->r24 | 0X800;
    // 0x801E4B84: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801E4B88: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x801E4B8C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x801E4B90: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x801E4B94: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x801E4B98: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x801E4B9C: srl         $t6, $t5, 24
    ctx->r14 = S32(U32(ctx->r13) >> 24);
    // 0x801E4BA0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801E4BA4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801E4BA8: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x801E4BAC: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x801E4BB0: jal         0x8000522C
    // 0x801E4BB4: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_6;
    // 0x801E4BB4: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    after_6:
    // 0x801E4BB8: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x801E4BBC: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x801E4BC0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x801E4BC4: lw          $t9, 0x30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X30);
    // 0x801E4BC8: addiu       $t5, $t5, -0x5168
    ctx->r13 = ADD32(ctx->r13, -0X5168);
    // 0x801E4BCC: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x801E4BD0: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
    // 0x801E4BD4: lw          $t0, 0x30($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X30);
    // 0x801E4BD8: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801E4BDC: swc1        $f6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f6.u32l;
    // 0x801E4BE0: lw          $t1, 0x30($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X30);
    // 0x801E4BE4: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x801E4BE8: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
    // 0x801E4BEC: swc1        $f8, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f8.u32l;
    // 0x801E4BF0: lw          $t2, 0x30($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X30);
    // 0x801E4BF4: lh          $t4, 0x12($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X12);
    // 0x801E4BF8: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x801E4BFC: sh          $t4, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r12;
    // 0x801E4C00: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801E4C04: lw          $t3, 0x30($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X30);
    // 0x801E4C08: sw          $t5, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r13;
    // 0x801E4C0C: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x801E4C10: lw          $a1, 0x10($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X10);
    // 0x801E4C14: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801E4C18: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x801E4C1C: beql        $t8, $zero, L_801E4C9C
    if (ctx->r24 == 0) {
        // 0x801E4C20: andi        $t3, $a1, 0x2
        ctx->r11 = ctx->r5 & 0X2;
            goto L_801E4C9C;
    }
    goto skip_0;
    // 0x801E4C20: andi        $t3, $a1, 0x2
    ctx->r11 = ctx->r5 & 0X2;
    skip_0:
    // 0x801E4C24: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x801E4C28: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x801E4C2C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801E4C30: sw          $t9, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r25;
    // 0x801E4C34: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801E4C38: jal         0x8000C3B0
    // 0x801E4C3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8000C3B0)(rdram, ctx);
        goto after_7;
    // 0x801E4C3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_7:
    // 0x801E4C40: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801E4C44: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801E4C48: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801E4C4C: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x801E4C50: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801E4C54: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
    // 0x801E4C58: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801E4C5C: lbu         $t6, 0xF32($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF32);
    // 0x801E4C60: lw          $t3, 0x30($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X30);
    // 0x801E4C64: sb          $t6, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = ctx->r14;
    // 0x801E4C68: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801E4C6C: lbu         $t7, 0xF33($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XF33);
    // 0x801E4C70: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801E4C74: sb          $t7, 0x4D($t0)
    MEM_B(0X4D, ctx->r8) = ctx->r15;
    // 0x801E4C78: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801E4C7C: lbu         $t9, 0xF34($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF34);
    // 0x801E4C80: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801E4C84: sb          $t9, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = ctx->r25;
    // 0x801E4C88: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801E4C8C: lbu         $t4, 0xF35($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF35);
    // 0x801E4C90: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801E4C94: sb          $t4, 0x4F($t6)
    MEM_B(0X4F, ctx->r14) = ctx->r12;
    // 0x801E4C98: andi        $t3, $a1, 0x2
    ctx->r11 = ctx->r5 & 0X2;
L_801E4C9C:
    // 0x801E4C9C: beq         $t3, $zero, L_801E4CAC
    if (ctx->r11 == 0) {
        // 0x801E4CA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801E4CAC;
    }
    // 0x801E4CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801E4CA4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801E4CA8: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
L_801E4CAC:
    // 0x801E4CAC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E4CB0: jal         0x800058DC
    // 0x801E4CB4: addiu       $a1, $a1, 0x4CCC
    ctx->r5 = ADD32(ctx->r5, 0X4CCC);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801E4CB4: addiu       $a1, $a1, 0x4CCC
    ctx->r5 = ADD32(ctx->r5, 0X4CCC);
    after_8:
L_801E4CB8:
    // 0x801E4CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E4CBC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801E4CC0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801E4CC4: jr          $ra
    // 0x801E4CC8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801E4CC8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M9_FUN_801e4ccc(rdram, ctx);
;}
RECOMP_FUNC void M9_FUN_801e4ccc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E4CCC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801E4CD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E4CD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801E4CD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801E4CDC: jal         0x80126944
    // 0x801E4CE0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x801E4CE0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801E4CE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801E4CE8: bne         $v0, $at, L_801E4D00
    if (ctx->r2 != ctx->r1) {
        // 0x801E4CEC: lui         $t6, 0x801C
        ctx->r14 = S32(0X801C << 16);
            goto L_801E4D00;
    }
    // 0x801E4CEC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E4CF0: lbu         $t6, -0x33DF($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X33DF);
    // 0x801E4CF4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x801E4CF8: beql        $t6, $at, L_801E4D30
    if (ctx->r14 == ctx->r1) {
        // 0x801E4CFC: lhu         $t8, 0x36($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X36);
            goto L_801E4D30;
    }
    goto skip_0;
    // 0x801E4CFC: lhu         $t8, 0x36($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X36);
    skip_0:
L_801E4D00:
    // 0x801E4D00: jal         0x80126944
    // 0x801E4D04: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_1;
    // 0x801E4D04: nop

    after_1:
    // 0x801E4D08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801E4D0C: bnel        $v0, $at, L_801E4D30
    if (ctx->r2 != ctx->r1) {
        // 0x801E4D10: lhu         $t8, 0x36($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X36);
            goto L_801E4D30;
    }
    goto skip_1;
    // 0x801E4D10: lhu         $t8, 0x36($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X36);
    skip_1:
    // 0x801E4D14: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x801E4D18: lw          $v1, 0x14($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X14);
    // 0x801E4D1C: srl         $v1, $v1, 16
    ctx->r3 = S32(U32(ctx->r3) >> 16);
    // 0x801E4D20: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x801E4D24: bnel        $v1, $zero, L_801E4D74
    if (ctx->r3 != 0) {
        // 0x801E4D28: lhu         $t7, 0x36($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X36);
            goto L_801E4D74;
    }
    goto skip_2;
    // 0x801E4D28: lhu         $t7, 0x36($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X36);
    skip_2:
    // 0x801E4D2C: lhu         $t8, 0x36($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X36);
L_801E4D30:
    // 0x801E4D30: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x801E4D34: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801E4D38: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801E4D3C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x801E4D40: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x801E4D44: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x801E4D48: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801E4D4C: srl         $t4, $t3, 24
    ctx->r12 = S32(U32(ctx->r11) >> 24);
    // 0x801E4D50: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801E4D54: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801E4D58: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x801E4D5C: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x801E4D60: jal         0x8000522C
    // 0x801E4D64: lhu         $a0, 0x0($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X0);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_2;
    // 0x801E4D64: lhu         $a0, 0x0($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X0);
    after_2:
    // 0x801E4D68: b           L_801E4DA4
    // 0x801E4D6C: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
        goto L_801E4DA4;
    // 0x801E4D6C: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x801E4D70: lhu         $t7, 0x36($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X36);
L_801E4D74:
    // 0x801E4D74: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801E4D78: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x801E4D7C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801E4D80: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x801E4D84: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1CEC);
    // 0x801E4D88: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x801E4D8C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801E4D90: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x801E4D94: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x801E4D98: jal         0x8000522C
    // 0x801E4D9C: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    LOOKUP_FUNC(0x8000522C)(rdram, ctx);
        goto after_3;
    // 0x801E4D9C: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    after_3:
    // 0x801E4DA0: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
L_801E4DA4:
    // 0x801E4DA4: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x801E4DA8: lw          $v1, 0x10($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X10);
    // 0x801E4DAC: andi        $t1, $v1, 0x200
    ctx->r9 = ctx->r3 & 0X200;
    // 0x801E4DB0: beql        $t1, $zero, L_801E4EF4
    if (ctx->r9 == 0) {
        // 0x801E4DB4: andi        $t3, $v1, 0x1
        ctx->r11 = ctx->r3 & 0X1;
            goto L_801E4EF4;
    }
    goto skip_3;
    // 0x801E4DB4: andi        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 & 0X1;
    skip_3:
    // 0x801E4DB8: lwc1        $f4, 0x90($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801E4DBC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x801E4DC0: ldc1        $f8, -0x7EF0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X7EF0);
    // 0x801E4DC4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801E4DC8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801E4DCC: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801E4DD0: swc1        $f4, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f4.u32l;
    // 0x801E4DD4: jal         0x8001518C
    // 0x801E4DD8: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    LOOKUP_FUNC(0x8001518C)(rdram, ctx);
        goto after_4;
    // 0x801E4DD8: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    after_4:
    // 0x801E4DDC: jal         0x80029280
    // 0x801E4DE0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x80029280)(rdram, ctx);
        goto after_5;
    // 0x801E4DE0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x801E4DE4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801E4DE8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801E4DEC: nop

    // 0x801E4DF0: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x801E4DF4: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x801E4DF8: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x801E4DFC: jal         0x8001518C
    // 0x801E4E00: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    LOOKUP_FUNC(0x8001518C)(rdram, ctx);
        goto after_6;
    // 0x801E4E00: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    after_6:
    // 0x801E4E04: jal         0x80032720
    // 0x801E4E08: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    LOOKUP_FUNC(0x80032720)(rdram, ctx);
        goto after_7;
    // 0x801E4E08: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x801E4E0C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801E4E10: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E4E14: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801E4E18: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x801E4E1C: add.s       $f2, $f10, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x801E4E20: mul.s       $f16, $f4, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x801E4E24: nop

    // 0x801E4E28: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801E4E2C: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x801E4E30: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801E4E34: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x801E4E38: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x801E4E3C: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x801E4E40: jal         0x8002FC20
    // 0x801E4E44: add.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_8;
    // 0x801E4E44: add.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f18.fl;
    after_8:
    // 0x801E4E48: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801E4E4C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801E4E50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E4E54: div.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801E4E58: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801E4E5C: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801E4E60: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801E4E64: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801E4E68: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801E4E6C: nop

    // 0x801E4E70: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801E4E74: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801E4E78: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801E4E7C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x801E4E80: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x801E4E84: sb          $t6, -0x34EA($at)
    MEM_B(-0X34EA, ctx->r1) = ctx->r14;
    // 0x801E4E88: jal         0x8002FC20
    // 0x801E4E8C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_9;
    // 0x801E4E8C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_9:
    // 0x801E4E90: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801E4E94: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801E4E98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E4E9C: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801E4EA0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801E4EA4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801E4EA8: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801E4EAC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801E4EB0: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x801E4EB4: jal         0x8002FC20
    // 0x801E4EB8: sb          $t8, -0x34E9($at)
    MEM_B(-0X34E9, ctx->r1) = ctx->r24;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_10;
    // 0x801E4EB8: sb          $t8, -0x34E9($at)
    MEM_B(-0X34E9, ctx->r1) = ctx->r24;
    after_10:
    // 0x801E4EBC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801E4EC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E4EC4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801E4EC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E4ECC: div.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801E4ED0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801E4ED4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801E4ED8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801E4EDC: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x801E4EE0: nop

    // 0x801E4EE4: sb          $t0, -0x34E8($at)
    MEM_B(-0X34E8, ctx->r1) = ctx->r8;
    // 0x801E4EE8: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x801E4EEC: lw          $v1, 0x10($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X10);
    // 0x801E4EF0: andi        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 & 0X1;
L_801E4EF4:
    // 0x801E4EF4: beq         $t3, $zero, L_801E4F44
    if (ctx->r11 == 0) {
        // 0x801E4EF8: lw          $v0, 0x4C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X4C);
            goto L_801E4F44;
    }
    // 0x801E4EF8: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x801E4EFC: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801E4F00: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801E4F04: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801E4F08: lbu         $t4, 0xF32($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF32);
    // 0x801E4F0C: lw          $t5, 0x30($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X30);
    // 0x801E4F10: sb          $t4, 0x4C($t5)
    MEM_B(0X4C, ctx->r13) = ctx->r12;
    // 0x801E4F14: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801E4F18: lbu         $t6, 0xF33($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF33);
    // 0x801E4F1C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801E4F20: sb          $t6, 0x4D($t8)
    MEM_B(0X4D, ctx->r24) = ctx->r14;
    // 0x801E4F24: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801E4F28: lbu         $t9, 0xF34($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF34);
    // 0x801E4F2C: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x801E4F30: sb          $t9, 0x4E($t2)
    MEM_B(0X4E, ctx->r10) = ctx->r25;
    // 0x801E4F34: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801E4F38: lbu         $t3, 0xF35($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XF35);
    // 0x801E4F3C: lw          $t4, 0x30($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X30);
    // 0x801E4F40: sb          $t3, 0x4F($t4)
    MEM_B(0X4F, ctx->r12) = ctx->r11;
L_801E4F44:
    // 0x801E4F44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E4F48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801E4F4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801E4F50: jr          $ra
    // 0x801E4F54: nop

    return;
    // 0x801E4F54: nop

;}
