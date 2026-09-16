#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FUN_8002ddb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DDB0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002DDB4: bne         $a1, $at, L_8002DDD8
    if (ctx->r5 != ctx->r1) {
        // 0x8002DDB8: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_8002DDD8;
    }
    // 0x8002DDB8: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x8002DDBC: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x8002DDC0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002DDC4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8002DDC8: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x8002DDCC: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x8002DDD0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8002DDD4: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_8002DDD8:
    // 0x8002DDD8: jr          $ra
    // 0x8002DDDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002DDDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002dde0(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002dde0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DDE0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002DDE4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002DDE8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002DDEC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8002DDF0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8002DDF4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8002DDF8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002DDFC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002DE00: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002DE04: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002DE08: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x8002DE0C: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x8002DE10: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8002DE14: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x8002DE18: ori         $t6, $t6, 0x6C0
    ctx->r14 = ctx->r14 | 0X6C0;
    // 0x8002DE1C: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x8002DE20: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8002DE24: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x8002DE28: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x8002DE2C: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x8002DE30: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x8002DE34: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8002DE38: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8002DE3C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x8002DE40: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8002DE44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002DE48: blez        $t8, L_8002DE8C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8002DE4C: addiu       $s2, $t0, 0x10
        ctx->r18 = ADD32(ctx->r8, 0X10);
            goto L_8002DE8C;
    }
    // 0x8002DE4C: addiu       $s2, $t0, 0x10
    ctx->r18 = ADD32(ctx->r8, 0X10);
    // 0x8002DE50: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_8002DE54:
    // 0x8002DE54: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002DE58: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8002DE5C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8002DE60: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8002DE64: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8002DE68: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x8002DE6C: jalr        $t9
    // 0x8002DE70: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002DE70: nop

    after_0:
    // 0x8002DE74: lw          $t1, 0x14($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X14);
    // 0x8002DE78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002DE7C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8002DE80: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002DE84: bne         $at, $zero, L_8002DE54
    if (ctx->r1 != 0) {
        // 0x8002DE88: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8002DE54;
    }
    // 0x8002DE88: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8002DE8C:
    // 0x8002DE8C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002DE90: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8002DE94: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002DE98: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002DE9C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8002DEA0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8002DEA4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8002DEA8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8002DEAC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8002DEB0: jr          $ra
    // 0x8002DEB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8002DEB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8002DEB8: nop

    // 0x8002DEBC: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002dec0(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002dec0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DEC0: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8002DEC4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002DEC8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8002DECC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8002DED0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8002DED4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8002DED8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8002DEDC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002DEE0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002DEE4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002DEE8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002DEEC: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x8002DEF0: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x8002DEF4: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x8002DEF8: sh          $zero, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = 0;
    // 0x8002DEFC: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x8002DF00: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x8002DF04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002DF08: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x8002DF0C: lw          $s4, 0xA8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA8);
    // 0x8002DF10: beq         $t6, $zero, L_8002E35C
    if (ctx->r14 == 0) {
        // 0x8002DF14: or          $s7, $a3, $zero
        ctx->r23 = ctx->r7 | 0;
            goto L_8002E35C;
    }
    // 0x8002DF14: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x8002DF18: lui         $s6, 0x8005
    ctx->r22 = S32(0X8005 << 16);
    // 0x8002DF1C: lui         $s5, 0x8005
    ctx->r21 = S32(0X8005 << 16);
    // 0x8002DF20: addiu       $s5, $s5, -0x52F0
    ctx->r21 = ADD32(ctx->r21, -0X52F0);
    // 0x8002DF24: addiu       $s6, $s6, -0x51F0
    ctx->r22 = ADD32(ctx->r22, -0X51F0);
    // 0x8002DF28: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8002DF2C: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
L_8002DF30:
    // 0x8002DF30: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x8002DF34: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x8002DF38: lw          $s7, 0x4($v1)
    ctx->r23 = MEM_W(ctx->r3, 0X4);
    // 0x8002DF3C: subu        $s2, $s7, $v0
    ctx->r18 = SUB32(ctx->r23, ctx->r2);
    // 0x8002DF40: slt         $at, $t7, $s2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8002DF44: bnel        $at, $zero, L_8002E360
    if (ctx->r1 != 0) {
        // 0x8002DF48: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8002E360;
    }
    goto skip_0;
    // 0x8002DF48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8002DF4C: lhu         $t8, 0x8($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X8);
    // 0x8002DF50: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x8002DF54: beq         $at, $zero, L_8002E2DC
    if (ctx->r1 == 0) {
        // 0x8002DF58: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8002E2DC;
    }
    // 0x8002DF58: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002DF5C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002DF60: addu        $at, $at, $t8
    gpr jr_addend_8002DF68 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8002DF64: lw          $t8, -0x2C30($at)
    ctx->r24 = ADD32(ctx->r1, -0X2C30);
    // 0x8002DF68: jr          $t8
    // 0x8002DF6C: nop

    switch (jr_addend_8002DF68 >> 2) {
        case 0: goto L_8002E2BC; break;
        case 1: goto L_8002E2DC; break;
        case 2: goto L_8002E2DC; break;
        case 3: goto L_8002E2DC; break;
        case 4: goto L_8002E2DC; break;
        case 5: goto L_8002E2DC; break;
        case 6: goto L_8002E2DC; break;
        case 7: goto L_8002E2DC; break;
        case 8: goto L_8002E2DC; break;
        case 9: goto L_8002E2DC; break;
        case 10: goto L_8002E2DC; break;
        case 11: goto L_8002E0A0; break;
        case 12: goto L_8002E0A0; break;
        case 13: goto L_8002DF70; break;
        case 14: goto L_8002E22C; break;
        case 15: goto L_8002E280; break;
        case 16: goto L_8002E0A0; break;
        default: switch_error(__func__, 0x8002DF68, 0x8004D3D0);
    }
    // 0x8002DF6C: nop

L_8002DF70:
    // 0x8002DF70: lh          $t9, 0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XA);
    // 0x8002DF74: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8002DF78: beql        $t9, $zero, L_8002DF98
    if (ctx->r25 == 0) {
        // 0x8002DF7C: lw          $t9, 0x8($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X8);
            goto L_8002DF98;
    }
    goto skip_1;
    // 0x8002DF7C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x8002DF80: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8002DF84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002DF88: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8002DF8C: jalr        $t9
    // 0x8002DF90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002DF90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8002DF94: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
L_8002DF98:
    // 0x8002DF98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002DF9C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8002DFA0: jalr        $t9
    // 0x8002DFA4: lw          $a2, 0x18($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X18);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8002DFA4: lw          $a2, 0x18($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X18);
    after_1:
    // 0x8002DFA8: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8002DFAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002DFB0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8002DFB4: jalr        $t9
    // 0x8002DFB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8002DFB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8002DFBC: sw          $s3, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r19;
    // 0x8002DFC0: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x8002DFC4: lw          $t0, 0x14($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X14);
    // 0x8002DFC8: sw          $t0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r8;
    // 0x8002DFCC: lh          $v1, 0x10($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X10);
    // 0x8002DFD0: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DFD4: mflo        $a0
    ctx->r4 = lo;
    // 0x8002DFD8: sra         $t1, $a0, 15
    ctx->r9 = S32(SIGNED(ctx->r4) >> 15);
    // 0x8002DFDC: sh          $t1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r9;
    // 0x8002DFE0: lbu         $t2, 0x12($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X12);
    // 0x8002DFE4: sh          $t2, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r10;
    // 0x8002DFE8: lbu         $t3, 0x13($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X13);
    // 0x8002DFEC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8002DFF0: addu        $t5, $s5, $t4
    ctx->r13 = ADD32(ctx->r21, ctx->r12);
    // 0x8002DFF4: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8002DFF8: sh          $t6, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r14;
    // 0x8002DFFC: lbu         $t7, 0x13($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X13);
    // 0x8002E000: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8002E004: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8002E008: addu        $t0, $s6, $t9
    ctx->r8 = ADD32(ctx->r22, ctx->r25);
    // 0x8002E00C: lh          $t1, -0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, -0X2);
    // 0x8002E010: sh          $t1, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r9;
    // 0x8002E014: lw          $t2, 0x14($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X14);
    // 0x8002E018: beql        $t2, $zero, L_8002E030
    if (ctx->r10 == 0) {
        // 0x8002E01C: lh          $v0, 0x18($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X18);
            goto L_8002E030;
    }
    goto skip_2;
    // 0x8002E01C: lh          $v0, 0x18($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18);
    skip_2:
    // 0x8002E020: sh          $s3, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r19;
    // 0x8002E024: b           L_8002E06C
    // 0x8002E028: sh          $s3, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r19;
        goto L_8002E06C;
    // 0x8002E028: sh          $s3, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r19;
    // 0x8002E02C: lh          $v0, 0x18($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18);
L_8002E030:
    // 0x8002E030: lh          $v1, 0x1A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A);
    // 0x8002E034: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x8002E038: addu        $t4, $s5, $t3
    ctx->r12 = ADD32(ctx->r21, ctx->r11);
    // 0x8002E03C: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8002E040: negu        $t8, $t3
    ctx->r24 = SUB32(0, ctx->r11);
    // 0x8002E044: addu        $t9, $s6, $t8
    ctx->r25 = ADD32(ctx->r22, ctx->r24);
    // 0x8002E048: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E04C: mflo        $t6
    ctx->r14 = lo;
    // 0x8002E050: sra         $t7, $t6, 15
    ctx->r15 = S32(SIGNED(ctx->r14) >> 15);
    // 0x8002E054: sh          $t7, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r15;
    // 0x8002E058: lh          $t0, -0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, -0X2);
    // 0x8002E05C: multu       $t0, $v1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E060: mflo        $t1
    ctx->r9 = lo;
    // 0x8002E064: sra         $t2, $t1, 15
    ctx->r10 = S32(SIGNED(ctx->r9) >> 15);
    // 0x8002E068: sh          $t2, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r10;
L_8002E06C:
    // 0x8002E06C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8002E070: beql        $t3, $zero, L_8002E318
    if (ctx->r11 == 0) {
        // 0x8002E074: lh          $t8, 0x7E($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X7E);
            goto L_8002E318;
    }
    goto skip_3;
    // 0x8002E074: lh          $t8, 0x7E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X7E);
    skip_3:
    // 0x8002E078: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8002E07C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8002E080: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x8002E084: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8002E088: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8002E08C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8002E090: jalr        $t9
    // 0x8002E094: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8002E094: nop

    after_3:
    // 0x8002E098: b           L_8002E318
    // 0x8002E09C: lh          $t8, 0x7E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X7E);
        goto L_8002E318;
    // 0x8002E09C: lh          $t8, 0x7E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X7E);
L_8002E0A0:
    // 0x8002E0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002E0A4: addiu       $a1, $sp, 0x8E
    ctx->r5 = ADD32(ctx->r29, 0X8E);
    // 0x8002E0A8: addiu       $a2, $sp, 0x7E
    ctx->r6 = ADD32(ctx->r29, 0X7E);
    // 0x8002E0AC: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8002E0B0: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8002E0B4: jal         0x8002E4A8
    // 0x8002E0B8: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    LOOKUP_FUNC(0x8002E4A8)(rdram, ctx);
        goto after_4;
    // 0x8002E0B8: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    after_4:
    // 0x8002E0BC: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x8002E0C0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8002E0C4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8002E0C8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002E0CC: bnel        $at, $zero, L_8002E130
    if (ctx->r1 != 0) {
        // 0x8002E0D0: lh          $t6, 0x1C($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X1C);
            goto L_8002E130;
    }
    goto skip_4;
    // 0x8002E0D0: lh          $t6, 0x1C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1C);
    skip_4:
    // 0x8002E0D4: lh          $v0, 0x18($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18);
    // 0x8002E0D8: lh          $v1, 0x1A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A);
    // 0x8002E0DC: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x8002E0E0: addu        $t5, $s5, $t4
    ctx->r13 = ADD32(ctx->r21, ctx->r12);
    // 0x8002E0E4: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8002E0E8: negu        $t0, $t4
    ctx->r8 = SUB32(0, ctx->r12);
    // 0x8002E0EC: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x8002E0F0: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E0F4: mflo        $t7
    ctx->r15 = lo;
    // 0x8002E0F8: sra         $t8, $t7, 15
    ctx->r24 = S32(SIGNED(ctx->r15) >> 15);
    // 0x8002E0FC: sh          $t8, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r24;
    // 0x8002E100: lh          $t2, -0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, -0X2);
    // 0x8002E104: lh          $t4, 0x28($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X28);
    // 0x8002E108: sw          $a0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r4;
    // 0x8002E10C: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E110: sh          $t4, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r12;
    // 0x8002E114: mflo        $t3
    ctx->r11 = lo;
    // 0x8002E118: sra         $t9, $t3, 15
    ctx->r25 = S32(SIGNED(ctx->r11) >> 15);
    // 0x8002E11C: sh          $t9, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r25;
    // 0x8002E120: lh          $t5, 0x2E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2E);
    // 0x8002E124: b           L_8002E17C
    // 0x8002E128: sh          $t5, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r13;
        goto L_8002E17C;
    // 0x8002E128: sh          $t5, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r13;
    // 0x8002E12C: lh          $t6, 0x1C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1C);
L_8002E130:
    // 0x8002E130: lh          $a2, 0x26($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X26);
    // 0x8002E134: lhu         $a3, 0x24($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X24);
    // 0x8002E138: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8002E13C: jal         0x8002EA88
    // 0x8002E140: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    LOOKUP_FUNC(0x8002EA88)(rdram, ctx);
        goto after_5;
    // 0x8002E140: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_5:
    // 0x8002E144: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002E148: lh          $t0, 0x1E($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X1E);
    // 0x8002E14C: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x8002E150: lh          $a2, 0x2C($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2C);
    // 0x8002E154: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8002E158: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8002E15C: lhu         $a3, 0x2A($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X2A);
    // 0x8002E160: sh          $t8, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r24;
    // 0x8002E164: jal         0x8002EA88
    // 0x8002E168: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    LOOKUP_FUNC(0x8002EA88)(rdram, ctx);
        goto after_6;
    // 0x8002E168: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_6:
    // 0x8002E16C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002E170: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x8002E174: nop

    // 0x8002E178: sh          $t2, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r10;
L_8002E17C:
    // 0x8002E17C: lh          $t3, 0x1C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X1C);
    // 0x8002E180: bnel        $t3, $zero, L_8002E190
    if (ctx->r11 != 0) {
        // 0x8002E184: lh          $t9, 0x1E($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X1E);
            goto L_8002E190;
    }
    goto skip_5;
    // 0x8002E184: lh          $t9, 0x1E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1E);
    skip_5:
    // 0x8002E188: sh          $s3, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r19;
    // 0x8002E18C: lh          $t9, 0x1E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1E);
L_8002E190:
    // 0x8002E190: bnel        $t9, $zero, L_8002E1A0
    if (ctx->r25 != 0) {
        // 0x8002E194: lw          $v1, 0x3C($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X3C);
            goto L_8002E1A0;
    }
    goto skip_6;
    // 0x8002E194: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    skip_6:
    // 0x8002E198: sh          $s3, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r19;
    // 0x8002E19C: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
L_8002E1A0:
    // 0x8002E1A0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8002E1A4: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x8002E1A8: bnel        $a0, $at, L_8002E1C0
    if (ctx->r4 != ctx->r1) {
        // 0x8002E1AC: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8002E1C0;
    }
    goto skip_7;
    // 0x8002E1AC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_7:
    // 0x8002E1B0: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x8002E1B4: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
    // 0x8002E1B8: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x8002E1BC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_8002E1C0:
    // 0x8002E1C0: bnel        $a0, $at, L_8002E1F0
    if (ctx->r4 != ctx->r1) {
        // 0x8002E1C4: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_8002E1F0;
    }
    goto skip_8;
    // 0x8002E1C4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_8:
    // 0x8002E1C8: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x8002E1CC: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8002E1D0: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E1D4: mflo        $v0
    ctx->r2 = lo;
    // 0x8002E1D8: sra         $t5, $v0, 15
    ctx->r13 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8002E1DC: sh          $t5, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r13;
    // 0x8002E1E0: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x8002E1E4: sw          $t6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r14;
    // 0x8002E1E8: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x8002E1EC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_8002E1F0:
    // 0x8002E1F0: bne         $a0, $at, L_8002E224
    if (ctx->r4 != ctx->r1) {
        // 0x8002E1F4: nop
    
            goto L_8002E224;
    }
    // 0x8002E1F4: nop

    // 0x8002E1F8: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8002E1FC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8002E200: addu        $t0, $s5, $t8
    ctx->r8 = ADD32(ctx->r21, ctx->r24);
    // 0x8002E204: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8002E208: sh          $t1, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r9;
    // 0x8002E20C: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x8002E210: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8002E214: negu        $t9, $t3
    ctx->r25 = SUB32(0, ctx->r11);
    // 0x8002E218: addu        $t4, $s6, $t9
    ctx->r12 = ADD32(ctx->r22, ctx->r25);
    // 0x8002E21C: lh          $t5, -0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, -0X2);
    // 0x8002E220: sh          $t5, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r13;
L_8002E224:
    // 0x8002E224: b           L_8002E314
    // 0x8002E228: sw          $s3, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r19;
        goto L_8002E314;
    // 0x8002E228: sw          $s3, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r19;
L_8002E22C:
    // 0x8002E22C: lh          $t6, 0xA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA);
    // 0x8002E230: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8002E234: beql        $t6, $zero, L_8002E254
    if (ctx->r14 == 0) {
        // 0x8002E238: lw          $t9, 0x8($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X8);
            goto L_8002E254;
    }
    goto skip_9;
    // 0x8002E238: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    skip_9:
    // 0x8002E23C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8002E240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002E244: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8002E248: jalr        $t9
    // 0x8002E24C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8002E24C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8002E250: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
L_8002E254:
    // 0x8002E254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002E258: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8002E25C: jalr        $t9
    // 0x8002E260: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x8002E260: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_8:
    // 0x8002E264: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8002E268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002E26C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8002E270: jalr        $t9
    // 0x8002E274: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x8002E274: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8002E278: b           L_8002E318
    // 0x8002E27C: lh          $t8, 0x7E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X7E);
        goto L_8002E318;
    // 0x8002E27C: lh          $t8, 0x7E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X7E);
L_8002E280:
    // 0x8002E280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002E284: addiu       $a1, $sp, 0x8E
    ctx->r5 = ADD32(ctx->r29, 0X8E);
    // 0x8002E288: addiu       $a2, $sp, 0x7E
    ctx->r6 = ADD32(ctx->r29, 0X7E);
    // 0x8002E28C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8002E290: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8002E294: jal         0x8002E4A8
    // 0x8002E298: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    LOOKUP_FUNC(0x8002E4A8)(rdram, ctx);
        goto after_10;
    // 0x8002E298: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    after_10:
    // 0x8002E29C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8002E2A0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8002E2A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002E2A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002E2AC: jalr        $t9
    // 0x8002E2B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x8002E2B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8002E2B4: b           L_8002E318
    // 0x8002E2B8: lh          $t8, 0x7E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X7E);
        goto L_8002E318;
    // 0x8002E2B8: lh          $t8, 0x7E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X7E);
L_8002E2BC:
    // 0x8002E2BC: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8002E2C0: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8002E2C4: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x8002E2C8: sw          $zero, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = 0;
    // 0x8002E2CC: jal         0x8002C748
    // 0x8002E2D0: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    LOOKUP_FUNC(0x8002C748)(rdram, ctx);
        goto after_12;
    // 0x8002E2D0: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    after_12:
    // 0x8002E2D4: b           L_8002E318
    // 0x8002E2D8: lh          $t8, 0x7E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X7E);
        goto L_8002E318;
    // 0x8002E2D8: lh          $t8, 0x7E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X7E);
L_8002E2DC:
    // 0x8002E2DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002E2E0: addiu       $a1, $sp, 0x8E
    ctx->r5 = ADD32(ctx->r29, 0X8E);
    // 0x8002E2E4: addiu       $a2, $sp, 0x7E
    ctx->r6 = ADD32(ctx->r29, 0X7E);
    // 0x8002E2E8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8002E2EC: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8002E2F0: jal         0x8002E4A8
    // 0x8002E2F4: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    LOOKUP_FUNC(0x8002E4A8)(rdram, ctx);
        goto after_13;
    // 0x8002E2F4: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    after_13:
    // 0x8002E2F8: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    // 0x8002E2FC: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8002E300: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8002E304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002E308: lh          $a1, 0x8($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X8);
    // 0x8002E30C: jalr        $t9
    // 0x8002E310: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x8002E310: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    after_14:
L_8002E314:
    // 0x8002E314: lh          $t8, 0x7E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X7E);
L_8002E318:
    // 0x8002E318: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x8002E31C: sll         $t0, $s2, 1
    ctx->r8 = S32(ctx->r18 << 1);
    // 0x8002E320: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8002E324: subu        $t3, $t2, $s2
    ctx->r11 = SUB32(ctx->r10, ctx->r18);
    // 0x8002E328: sh          $t1, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r9;
    // 0x8002E32C: sw          $t3, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r11;
    // 0x8002E330: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8002E334: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8002E338: bne         $t4, $zero, L_8002E344
    if (ctx->r12 != 0) {
        // 0x8002E33C: sw          $t4, 0x3C($s0)
        MEM_W(0X3C, ctx->r16) = ctx->r12;
            goto L_8002E344;
    }
    // 0x8002E33C: sw          $t4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r12;
    // 0x8002E340: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
L_8002E344:
    // 0x8002E344: jal         0x8002C6D0
    // 0x8002E348: nop

    LOOKUP_FUNC(0x8002C6D0)(rdram, ctx);
        goto after_15;
    // 0x8002E348: nop

    after_15:
    // 0x8002E34C: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x8002E350: lw          $t7, 0x3C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X3C);
    // 0x8002E354: bnel        $t7, $zero, L_8002DF30
    if (ctx->r15 != 0) {
        // 0x8002E358: lw          $v1, 0x3C($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X3C);
            goto L_8002DF30;
    }
    goto skip_10;
    // 0x8002E358: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    skip_10:
L_8002E35C:
    // 0x8002E35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8002E360:
    // 0x8002E360: addiu       $a1, $sp, 0x8E
    ctx->r5 = ADD32(ctx->r29, 0X8E);
    // 0x8002E364: addiu       $a2, $sp, 0x7E
    ctx->r6 = ADD32(ctx->r29, 0X7E);
    // 0x8002E368: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x8002E36C: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x8002E370: jal         0x8002E4A8
    // 0x8002E374: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    LOOKUP_FUNC(0x8002E4A8)(rdram, ctx);
        goto after_16;
    // 0x8002E374: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    after_16:
    // 0x8002E378: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8002E37C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8002E380: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8002E384: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8002E388: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002E38C: beql        $at, $zero, L_8002E39C
    if (ctx->r1 == 0) {
        // 0x8002E390: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8002E39C;
    }
    goto skip_11;
    // 0x8002E390: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_11:
    // 0x8002E394: sw          $a0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r4;
    // 0x8002E398: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8002E39C:
    // 0x8002E39C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002E3A0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8002E3A4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002E3A8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8002E3AC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8002E3B0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8002E3B4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8002E3B8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8002E3BC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8002E3C0: jr          $ra
    // 0x8002E3C4: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8002E3C4: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002e3c8(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002e3c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E3C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002E3CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002E3D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E3D4: beq         $a1, $v0, L_8002E474
    if (ctx->r5 == ctx->r2) {
        // 0x8002E3D8: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8002E474;
    }
    // 0x8002E3D8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002E3DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002E3E0: beq         $a1, $at, L_8002E400
    if (ctx->r5 == ctx->r1) {
        // 0x8002E3E4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8002E400;
    }
    // 0x8002E3E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002E3E8: beq         $a1, $at, L_8002E420
    if (ctx->r5 == ctx->r1) {
        // 0x8002E3EC: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8002E420;
    }
    // 0x8002E3EC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8002E3F0: beql        $a1, $at, L_8002E450
    if (ctx->r5 == ctx->r1) {
        // 0x8002E3F4: lw          $a0, 0x0($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X0);
            goto L_8002E450;
    }
    goto skip_0;
    // 0x8002E3F4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x8002E3F8: b           L_8002E480
    // 0x8002E3FC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
        goto L_8002E480;
    // 0x8002E3FC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_8002E400:
    // 0x8002E400: lw          $v0, 0x40($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X40);
    // 0x8002E404: beql        $v0, $zero, L_8002E418
    if (ctx->r2 == 0) {
        // 0x8002E408: sw          $a2, 0x3C($a3)
        MEM_W(0X3C, ctx->r7) = ctx->r6;
            goto L_8002E418;
    }
    goto skip_1;
    // 0x8002E408: sw          $a2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r6;
    skip_1:
    // 0x8002E40C: b           L_8002E418
    // 0x8002E410: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_8002E418;
    // 0x8002E410: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8002E414: sw          $a2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r6;
L_8002E418:
    // 0x8002E418: b           L_8002E494
    // 0x8002E41C: sw          $a2, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r6;
        goto L_8002E494;
    // 0x8002E41C: sw          $a2, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r6;
L_8002E420:
    // 0x8002E420: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8002E424: sw          $v0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r2;
    // 0x8002E428: sw          $zero, 0x48($a3)
    MEM_W(0X48, ctx->r7) = 0;
    // 0x8002E42C: beq         $a0, $zero, L_8002E494
    if (ctx->r4 == 0) {
        // 0x8002E430: sh          $v0, 0x1A($a3)
        MEM_H(0X1A, ctx->r7) = ctx->r2;
            goto L_8002E494;
    }
    // 0x8002E430: sh          $v0, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r2;
    // 0x8002E434: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8002E438: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002E43C: jalr        $t9
    // 0x8002E440: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002E440: nop

    after_0:
    // 0x8002E444: b           L_8002E498
    // 0x8002E448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002E498;
    // 0x8002E448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E44C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_8002E450:
    // 0x8002E450: sw          $v0, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r2;
    // 0x8002E454: beql        $a0, $zero, L_8002E498
    if (ctx->r4 == 0) {
        // 0x8002E458: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002E498;
    }
    goto skip_2;
    // 0x8002E458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8002E45C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8002E460: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8002E464: jalr        $t9
    // 0x8002E468: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8002E468: nop

    after_1:
    // 0x8002E46C: b           L_8002E498
    // 0x8002E470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002E498;
    // 0x8002E470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002E474:
    // 0x8002E474: b           L_8002E494
    // 0x8002E478: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_8002E494;
    // 0x8002E478: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x8002E47C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_8002E480:
    // 0x8002E480: beql        $a0, $zero, L_8002E498
    if (ctx->r4 == 0) {
        // 0x8002E484: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002E498;
    }
    goto skip_3;
    // 0x8002E484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8002E488: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8002E48C: jalr        $t9
    // 0x8002E490: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8002E490: nop

    after_2:
L_8002E494:
    // 0x8002E494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002E498:
    // 0x8002E498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002E49C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002E4A0: jr          $ra
    // 0x8002E4A4: nop

    return;
    // 0x8002E4A4: nop

;}
RECOMP_FUNC void FUN_8002e4a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E4A8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8002E4AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002E4B0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8002E4B4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8002E4B8: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8002E4BC: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8002E4C0: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8002E4C4: lw          $t6, 0x48($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X48);
    // 0x8002E4C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002E4CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002E4D0: bne         $t6, $at, L_8002E4E0
    if (ctx->r14 != ctx->r1) {
        // 0x8002E4D4: lw          $s1, 0x0($a0)
        ctx->r17 = MEM_W(ctx->r4, 0X0);
            goto L_8002E4E0;
    }
    // 0x8002E4D4: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
    // 0x8002E4D8: bne         $a3, $zero, L_8002E4E8
    if (ctx->r7 != 0) {
        // 0x8002E4DC: lw          $t8, 0x74($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X74);
            goto L_8002E4E8;
    }
    // 0x8002E4DC: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
L_8002E4E0:
    // 0x8002E4E0: b           L_8002E77C
    // 0x8002E4E4: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
        goto L_8002E77C;
    // 0x8002E4E4: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
L_8002E4E8:
    // 0x8002E4E8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002E4EC: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x8002E4F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002E4F4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8002E4F8: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8002E4FC: jalr        $t9
    // 0x8002E500: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002E500: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    after_0:
    // 0x8002E504: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8002E508: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8002E50C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8002E510: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8002E514: addiu       $s1, $v0, 0x10
    ctx->r17 = ADD32(ctx->r2, 0X10);
    // 0x8002E518: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8002E51C: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8002E520: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8002E524: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8002E528: lui         $at, 0x808
    ctx->r1 = S32(0X808 << 16);
    // 0x8002E52C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8002E530: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8002E534: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8002E538: andi        $t0, $t5, 0xFFFF
    ctx->r8 = ctx->r13 & 0XFFFF;
    // 0x8002E53C: addiu       $t8, $t6, 0x440
    ctx->r24 = ADD32(ctx->r14, 0X440);
    // 0x8002E540: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8002E544: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x8002E548: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8002E54C: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x8002E550: addiu       $t3, $t2, 0x580
    ctx->r11 = ADD32(ctx->r10, 0X580);
    // 0x8002E554: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8002E558: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x8002E55C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8002E560: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x8002E564: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8002E568: addiu       $t7, $v1, 0x800
    ctx->r15 = ADD32(ctx->r3, 0X800);
    // 0x8002E56C: addiu       $t9, $v1, 0x6C0
    ctx->r25 = ADD32(ctx->r3, 0X6C0);
    // 0x8002E570: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x8002E574: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8002E578: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8002E57C: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x8002E580: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x8002E584: lui         $t7, 0x308
    ctx->r15 = S32(0X308 << 16);
    // 0x8002E588: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8002E58C: beql        $t2, $zero, L_8002E73C
    if (ctx->r10 == 0) {
        // 0x8002E590: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_8002E73C;
    }
    goto skip_0;
    // 0x8002E590: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    skip_0:
    // 0x8002E594: lh          $t3, 0x18($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X18);
    // 0x8002E598: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    // 0x8002E59C: lh          $t7, 0x1A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A);
    // 0x8002E5A0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8002E5A4: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8002E5A8: lh          $t6, -0x52F0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X52F0);
    // 0x8002E5AC: lh          $t8, 0x1C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1C);
    // 0x8002E5B0: lw          $t1, 0x34($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X34);
    // 0x8002E5B4: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E5B8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8002E5BC: addiu       $t2, $s0, 0x24
    ctx->r10 = ADD32(ctx->r16, 0X24);
    // 0x8002E5C0: cvt.d.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.d = CVT_D_W(ctx->f4.u32l);
    // 0x8002E5C4: mflo        $t5
    ctx->r13 = lo;
    // 0x8002E5C8: sra         $t9, $t5, 15
    ctx->r25 = S32(SIGNED(ctx->r13) >> 15);
    // 0x8002E5CC: sh          $t9, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r25;
    // 0x8002E5D0: lh          $t0, 0x28($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X28);
    // 0x8002E5D4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8002E5D8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002E5DC: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8002E5E0: jal         0x8002E8A4
    // 0x8002E5E4: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    LOOKUP_FUNC(0x8002E8A4)(rdram, ctx);
        goto after_1;
    // 0x8002E5E4: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    after_1:
    // 0x8002E5E8: lh          $t3, 0x18($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X18);
    // 0x8002E5EC: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8002E5F0: sh          $v0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r2;
    // 0x8002E5F4: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8002E5F8: negu        $t6, $t4
    ctx->r14 = SUB32(0, ctx->r12);
    // 0x8002E5FC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8002E600: lh          $t7, -0x51F2($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X51F2);
    // 0x8002E604: lh          $t5, 0x1A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A);
    // 0x8002E608: lh          $t0, 0x1E($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X1E);
    // 0x8002E60C: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x8002E610: multu       $t7, $t5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E614: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8002E618: addiu       $t3, $s0, 0x2A
    ctx->r11 = ADD32(ctx->r16, 0X2A);
    // 0x8002E61C: cvt.d.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.d = CVT_D_W(ctx->f8.u32l);
    // 0x8002E620: mflo        $t9
    ctx->r25 = lo;
    // 0x8002E624: sra         $t8, $t9, 15
    ctx->r24 = S32(SIGNED(ctx->r25) >> 15);
    // 0x8002E628: sh          $t8, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r24;
    // 0x8002E62C: lh          $t1, 0x2E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2E);
    // 0x8002E630: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8002E634: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002E638: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8002E63C: jal         0x8002E8A4
    // 0x8002E640: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    LOOKUP_FUNC(0x8002E8A4)(rdram, ctx);
        goto after_2;
    // 0x8002E640: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    after_2:
    // 0x8002E644: lh          $t4, 0x1C($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1C);
    // 0x8002E648: sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    // 0x8002E64C: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8002E650: lui         $at, 0x906
    ctx->r1 = S32(0X906 << 16);
    // 0x8002E654: andi        $t6, $t4, 0xFFFF
    ctx->r14 = ctx->r12 & 0XFFFF;
    // 0x8002E658: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002E65C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002E660: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8002E664: lh          $t5, 0x1E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1E);
    // 0x8002E668: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8002E66C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002E670: lui         $at, 0x904
    ctx->r1 = S32(0X904 << 16);
    // 0x8002E674: andi        $t9, $t5, 0xFFFF
    ctx->r25 = ctx->r13 & 0XFFFF;
    // 0x8002E678: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8002E67C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8002E680: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8002E684: lh          $t0, 0x28($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X28);
    // 0x8002E688: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8002E68C: lui         $at, 0x902
    ctx->r1 = S32(0X902 << 16);
    // 0x8002E690: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x8002E694: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8002E698: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002E69C: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x8002E6A0: lh          $t4, 0x26($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X26);
    // 0x8002E6A4: lhu         $t5, 0x24($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X24);
    // 0x8002E6A8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8002E6AC: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x8002E6B0: or          $t9, $t6, $t5
    ctx->r25 = ctx->r14 | ctx->r13;
    // 0x8002E6B4: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8002E6B8: lh          $t8, 0x2E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2E);
    // 0x8002E6BC: lui         $at, 0x900
    ctx->r1 = S32(0X900 << 16);
    // 0x8002E6C0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8002E6C4: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x8002E6C8: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x8002E6CC: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x8002E6D0: lh          $t3, 0x2C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2C);
    // 0x8002E6D4: lhu         $t6, 0x2A($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X2A);
    // 0x8002E6D8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8002E6DC: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8002E6E0: or          $t5, $t4, $t6
    ctx->r13 = ctx->r12 | ctx->r14;
    // 0x8002E6E4: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x8002E6E8: lh          $t9, 0x20($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X20);
    // 0x8002E6EC: lui         $at, 0x908
    ctx->r1 = S32(0X908 << 16);
    // 0x8002E6F0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8002E6F4: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x8002E6F8: or          $t0, $t8, $at
    ctx->r8 = ctx->r24 | ctx->r1;
    // 0x8002E6FC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8002E700: lh          $t1, 0x22($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X22);
    // 0x8002E704: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8002E708: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8002E70C: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8002E710: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8002E714: lui         $t3, 0x309
    ctx->r11 = S32(0X309 << 16);
    // 0x8002E718: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8002E71C: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x8002E720: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8002E724: jal         0x80028A10
    // 0x8002E728: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_3;
    // 0x8002E728: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    after_3:
    // 0x8002E72C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8002E730: b           L_8002E754
    // 0x8002E734: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_8002E754;
    // 0x8002E734: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8002E738: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8002E73C:
    // 0x8002E73C: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x8002E740: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x8002E744: jal         0x80028A10
    // 0x8002E748: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_4;
    // 0x8002E748: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    after_4:
    // 0x8002E74C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8002E750: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8002E754:
    // 0x8002E754: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8002E758: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8002E75C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8002E760: lh          $t6, 0x0($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X0);
    // 0x8002E764: addu        $t9, $t6, $t5
    ctx->r25 = ADD32(ctx->r14, ctx->r13);
    // 0x8002E768: sh          $t9, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r25;
    // 0x8002E76C: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x8002E770: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8002E774: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8002E778: sw          $t1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r9;
L_8002E77C:
    // 0x8002E77C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002E780: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8002E784: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8002E788: jr          $ra
    // 0x8002E78C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8002E78C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002e790(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002e790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E790: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x8002E794: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002E798: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8002E79C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002E7A0: c.eq.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d == ctx->f2.d;
    // 0x8002E7A4: nop

    // 0x8002E7A8: bc1fl       L_8002E7BC
    if (!c1cs) {
        // 0x8002E7AC: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_8002E7BC;
    }
    goto skip_0;
    // 0x8002E7AC: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_0:
    // 0x8002E7B0: jr          $ra
    // 0x8002E7B4: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    return;
    // 0x8002E7B4: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x8002E7B8: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_8002E7BC:
    // 0x8002E7BC: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8002E7C0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8002E7C4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002E7C8: bc1fl       L_8002E7DC
    if (!c1cs) {
        // 0x8002E7CC: neg.d       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
            goto L_8002E7DC;
    }
    goto skip_1;
    // 0x8002E7CC: neg.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
    skip_1:
    // 0x8002E7D0: b           L_8002E7DC
    // 0x8002E7D4: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_8002E7DC;
    // 0x8002E7D4: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x8002E7D8: neg.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
L_8002E7DC:
    // 0x8002E7DC: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x8002E7E0: nop

    // 0x8002E7E4: bc1fl       L_8002E81C
    if (!c1cs) {
        // 0x8002E7E8: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_8002E81C;
    }
    goto skip_2;
    // 0x8002E7E8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    skip_2:
    // 0x8002E7EC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002E7F0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E7F4: nop

L_8002E7F8:
    // 0x8002E7F8: mul.d       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f16.d);
    // 0x8002E7FC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8002E800: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8002E804: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8002E808: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x8002E80C: nop

    // 0x8002E810: bc1t        L_8002E7F8
    if (c1cs) {
        // 0x8002E814: nop
    
            goto L_8002E7F8;
    }
    // 0x8002E814: nop

    // 0x8002E818: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
L_8002E81C:
    // 0x8002E81C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002E820: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E824: nop

    // 0x8002E828: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x8002E82C: nop

    // 0x8002E830: bc1fl       L_8002E858
    if (!c1cs) {
        // 0x8002E834: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_8002E858;
    }
    goto skip_3;
    // 0x8002E834: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_3:
    // 0x8002E838: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
L_8002E83C:
    // 0x8002E83C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8002E840: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x8002E844: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8002E848: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8002E84C: bc1tl       L_8002E83C
    if (c1cs) {
        // 0x8002E850: add.d       $f0, $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
            goto L_8002E83C;
    }
    goto skip_4;
    // 0x8002E850: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
    skip_4:
    // 0x8002E854: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_8002E858:
    // 0x8002E858: nop

    // 0x8002E85C: bc1fl       L_8002E870
    if (!c1cs) {
        // 0x8002E860: neg.d       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
            goto L_8002E870;
    }
    goto skip_5;
    // 0x8002E860: neg.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
    skip_5:
    // 0x8002E864: b           L_8002E870
    // 0x8002E868: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
        goto L_8002E870;
    // 0x8002E868: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
    // 0x8002E86C: neg.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
L_8002E870:
    // 0x8002E870: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    // 0x8002E874: jr          $ra
    // 0x8002E878: nop

    return;
    // 0x8002E878: nop

;}
RECOMP_FUNC void FUN_8002e87c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E87C: beq         $a2, $zero, L_8002E89C
    if (ctx->r6 == 0) {
        // 0x8002E880: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8002E89C;
    }
    // 0x8002E880: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002E884: sllv        $t7, $t6, $a2
    ctx->r15 = S32(ctx->r14 << (ctx->r6 & 31));
    // 0x8002E888: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8002E88C: nop

    // 0x8002E890: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8002E894: mul.d       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x8002E898: nop

L_8002E89C:
    // 0x8002E89C: jr          $ra
    // 0x8002E8A0: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    return;
    // 0x8002E8A0: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002e8a4(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002e8a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E8A4: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8002E8A8: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x8002E8AC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8002E8B0: mov.d       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.d = ctx->f12.d;
    // 0x8002E8B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002E8B8: bne         $a0, $zero, L_8002E8EC
    if (ctx->r4 != 0) {
        // 0x8002E8BC: sdc1        $f22, 0x18($sp)
        CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
            goto L_8002E8EC;
    }
    // 0x8002E8BC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8002E8C0: c.le.d      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.d <= ctx->f14.d;
    // 0x8002E8C4: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x8002E8C8: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8002E8CC: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8002E8D0: bc1f        L_8002E8E4
    if (!c1cs) {
        // 0x8002E8D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002E8E4;
    }
    // 0x8002E8D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002E8D8: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x8002E8DC: b           L_8002EA74
    // 0x8002E8E0: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
        goto L_8002EA74;
    // 0x8002E8E0: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_8002E8E4:
    // 0x8002E8E4: b           L_8002EA74
    // 0x8002E8E8: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
        goto L_8002EA74;
    // 0x8002E8E8: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
L_8002E8EC:
    // 0x8002E8EC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002E8F0: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x8002E8F4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8002E8F8: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8002E8FC: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8002E900: c.lt.d      $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f14.d < ctx->f22.d;
    // 0x8002E904: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E908: addiu       $t0, $t0, -0x51F0
    ctx->r8 = ADD32(ctx->r8, -0X51F0);
    // 0x8002E90C: addiu       $t2, $t0, 0x3C
    ctx->r10 = ADD32(ctx->r8, 0X3C);
    // 0x8002E910: bc1f        L_8002E91C
    if (!c1cs) {
        // 0x8002E914: addiu       $t9, $sp, 0x38
        ctx->r25 = ADD32(ctx->r29, 0X38);
            goto L_8002E91C;
    }
    // 0x8002E914: addiu       $t9, $sp, 0x38
    ctx->r25 = ADD32(ctx->r29, 0X38);
    // 0x8002E918: mov.d       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.d = ctx->f22.d;
L_8002E91C:
    // 0x8002E91C: c.le.d      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.d <= ctx->f4.d;
    // 0x8002E920: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x8002E924: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002E928: bc1f        L_8002E93C
    if (!c1cs) {
        // 0x8002E92C: cvt.d.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
            goto L_8002E93C;
    }
    // 0x8002E92C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8002E930: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8002E934: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8002E938: nop

L_8002E93C:
    // 0x8002E93C: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8002E940: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8002E944: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8002E948: sw          $at, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r1;
    // 0x8002E94C: lw          $at, -0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X8);
    // 0x8002E950: sw          $at, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r1;
    // 0x8002E954: lw          $at, -0x4($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X4);
    // 0x8002E958: bne         $t0, $t2, L_8002E93C
    if (ctx->r8 != ctx->r10) {
        // 0x8002E95C: sw          $at, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r1;
            goto L_8002E93C;
    }
    // 0x8002E95C: sw          $at, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r1;
    // 0x8002E960: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8002E964: div.d       $f12, $f22, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f8.d); 
    ctx->f12.d = DIV_D(ctx->f22.d, ctx->f8.d);
    // 0x8002E968: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x8002E96C: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x8002E970: jal         0x8002E87C
    // 0x8002E974: sdc1        $f14, 0xC0($sp)
    CHECK_FR(ctx, 14);
    SD(ctx->f14.u64, 0XC0, ctx->r29);
    LOOKUP_FUNC(0x8002E87C)(rdram, ctx);
        goto after_0;
    // 0x8002E974: sdc1        $f14, 0xC0($sp)
    CHECK_FR(ctx, 14);
    SD(ctx->f14.u64, 0XC0, ctx->r29);
    after_0:
    // 0x8002E978: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8002E97C: ldc1        $f14, 0xC0($sp)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r29, 0XC0);
    // 0x8002E980: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    // 0x8002E984: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8002E988: div.d       $f12, $f14, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f20.d); 
    ctx->f12.d = DIV_D(ctx->f14.d, ctx->f20.d);
    // 0x8002E98C: jal         0x8002E790
    // 0x8002E990: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8002E790)(rdram, ctx);
        goto after_1;
    // 0x8002E990: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    after_1:
    // 0x8002E994: mov.d       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.d = ctx->f0.d;
    // 0x8002E998: jal         0x8002E87C
    // 0x8002E99C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8002E87C)(rdram, ctx);
        goto after_2;
    // 0x8002E99C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8002E9A0: trunc.w.d   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8002E9A4: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8002E9A8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002E9AC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8002E9B0: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8002E9B4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8002E9B8: ldc1        $f18, -0x2BE8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2BE8);
    // 0x8002E9BC: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8002E9C0: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8002E9C4: addu        $t7, $sp, $t6
    ctx->r15 = ADD32(ctx->r29, ctx->r14);
    // 0x8002E9C8: ldc1        $f4, -0x8($t7)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r15, -0X8);
    // 0x8002E9CC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002E9D0: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8002E9D4: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x8002E9D8: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x8002E9DC: mul.d       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8002E9E0: jal         0x8002E87C
    // 0x8002E9E4: sdc1        $f14, 0xA0($sp)
    CHECK_FR(ctx, 14);
    SD(ctx->f14.u64, 0XA0, ctx->r29);
    LOOKUP_FUNC(0x8002E87C)(rdram, ctx);
        goto after_3;
    // 0x8002E9E4: sdc1        $f14, 0xA0($sp)
    CHECK_FR(ctx, 14);
    SD(ctx->f14.u64, 0XA0, ctx->r29);
    after_3:
    // 0x8002E9E8: ldc1        $f14, 0xA0($sp)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r29, 0XA0);
    // 0x8002E9EC: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x8002E9F0: mov.d       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.d = ctx->f22.d;
    // 0x8002E9F4: div.d       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f0.d); 
    ctx->f14.d = DIV_D(ctx->f14.d, ctx->f0.d);
    // 0x8002E9F8: beq         $v0, $zero, L_8002EA20
    if (ctx->r2 == 0) {
        // 0x8002E9FC: add.d       $f2, $f22, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f14.d); 
    ctx->f2.d = ctx->f22.d + ctx->f14.d;
            goto L_8002EA20;
    }
    // 0x8002E9FC: add.d       $f2, $f22, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f14.d); 
    ctx->f2.d = ctx->f22.d + ctx->f14.d;
L_8002EA00:
    // 0x8002EA00: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x8002EA04: beq         $t1, $zero, L_8002EA14
    if (ctx->r9 == 0) {
        // 0x8002EA08: sra         $t2, $v0, 1
        ctx->r10 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8002EA14;
    }
    // 0x8002EA08: sra         $t2, $v0, 1
    ctx->r10 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8002EA0C: mul.d       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f2.d);
    // 0x8002EA10: nop

L_8002EA14:
    // 0x8002EA14: mul.d       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x8002EA18: bne         $t2, $zero, L_8002EA00
    if (ctx->r10 != 0) {
        // 0x8002EA1C: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8002EA00;
    }
    // 0x8002EA1C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8002EA20:
    // 0x8002EA20: mul.d       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = MUL_D(ctx->f12.d, ctx->f12.d);
    // 0x8002EA24: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002EA28: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8002EA2C: mul.d       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f0.d, ctx->f0.d);
    // 0x8002EA30: nop

    // 0x8002EA34: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x8002EA38: trunc.w.d   $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = TRUNC_W_D(ctx->f12.d);
    // 0x8002EA3C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x8002EA40: ldc1        $f6, -0x2BE0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2BE0);
    // 0x8002EA44: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8002EA48: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002EA4C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8002EA50: nop

    // 0x8002EA54: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002EA58: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002EA5C: sub.d       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f12.d - ctx->f10.d;
    // 0x8002EA60: mul.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8002EA64: trunc.w.d   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x8002EA68: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8002EA6C: nop

    // 0x8002EA70: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
L_8002EA74:
    // 0x8002EA74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002EA78: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8002EA7C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8002EA80: jr          $ra
    // 0x8002EA84: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8002EA84: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002ea88(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002ea88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EA88: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8002EA8C: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8002EA90: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8002EA94: andi        $t8, $a3, 0xFFFF
    ctx->r24 = ctx->r7 & 0XFFFF;
    // 0x8002EA98: sra         $t9, $a1, 3
    ctx->r25 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8002EA9C: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8002EAA0: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002EAA4: bne         $t9, $zero, L_8002EAB4
    if (ctx->r25 != 0) {
        // 0x8002EAA8: or          $a1, $t9, $zero
        ctx->r5 = ctx->r25 | 0;
            goto L_8002EAB4;
    }
    // 0x8002EAA8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8002EAAC: jr          $ra
    // 0x8002EAB0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x8002EAB0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8002EAB4:
    // 0x8002EAB4: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x8002EAB8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8002EABC: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x8002EAC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002EAC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002EAC8: bgez        $a3, L_8002EAE0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8002EACC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8002EAE0;
    }
    // 0x8002EACC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002EAD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8002EAD4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002EAD8: nop

    // 0x8002EADC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8002EAE0:
    // 0x8002EAE0: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8002EAE4: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8002EAE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002EAEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002EAF0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002EAF4: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x8002EAF8: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8002EAFC: andi        $t1, $a1, 0x1
    ctx->r9 = ctx->r5 & 0X1;
L_8002EB00:
    // 0x8002EB00: beq         $t1, $zero, L_8002EB10
    if (ctx->r9 == 0) {
        // 0x8002EB04: sra         $t2, $a1, 1
        ctx->r10 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8002EB10;
    }
    // 0x8002EB04: sra         $t2, $a1, 1
    ctx->r10 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8002EB08: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8002EB0C: nop

L_8002EB10:
    // 0x8002EB10: beq         $t2, $zero, L_8002EB28
    if (ctx->r10 == 0) {
        // 0x8002EB14: or          $a1, $t2, $zero
        ctx->r5 = ctx->r10 | 0;
            goto L_8002EB28;
    }
    // 0x8002EB14: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8002EB18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002EB1C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8002EB20: bnel        $v0, $v1, L_8002EB00
    if (ctx->r2 != ctx->r3) {
        // 0x8002EB24: andi        $t1, $a1, 0x1
        ctx->r9 = ctx->r5 & 0X1;
            goto L_8002EB00;
    }
    goto skip_0;
    // 0x8002EB24: andi        $t1, $a1, 0x1
    ctx->r9 = ctx->r5 & 0X1;
    skip_0:
L_8002EB28:
    // 0x8002EB28: mul.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8002EB2C: nop

    // 0x8002EB30: jr          $ra
    // 0x8002EB34: nop

    return;
    // 0x8002EB34: nop

    // 0x8002EB38: nop

    // 0x8002EB3C: nop

;}
RECOMP_FUNC void FUN_8002eb40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EB40: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x8002EB44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002EB48: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x8002EB4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002EB50: beq         $at, $zero, L_8002EC00
    if (ctx->r1 == 0) {
        // 0x8002EB54: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8002EC00;
    }
    // 0x8002EB54: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002EB58: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002EB5C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002EB60: addu        $at, $at, $t6
    gpr jr_addend_8002EB68 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002EB64: lw          $t6, -0x2BD0($at)
    ctx->r14 = ADD32(ctx->r1, -0X2BD0);
    // 0x8002EB68: jr          $t6
    // 0x8002EB6C: nop

    switch (jr_addend_8002EB68 >> 2) {
        case 0: goto L_8002EB70; break;
        case 1: goto L_8002EC00; break;
        case 2: goto L_8002EC00; break;
        case 3: goto L_8002EB78; break;
        case 4: goto L_8002EC00; break;
        case 5: goto L_8002EC00; break;
        case 6: goto L_8002EBE4; break;
        case 7: goto L_8002EBF4; break;
        case 8: goto L_8002EBB4; break;
        default: switch_error(__func__, 0x8002EB68, 0x8004D430);
    }
    // 0x8002EB6C: nop

L_8002EB70:
    // 0x8002EB70: b           L_8002EC18
    // 0x8002EB74: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_8002EC18;
    // 0x8002EB74: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
L_8002EB78:
    // 0x8002EB78: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8002EB7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002EB80: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002EB84: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
    // 0x8002EB88: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x8002EB8C: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x8002EB90: beq         $a0, $zero, L_8002EC18
    if (ctx->r4 == 0) {
        // 0x8002EB94: swc1        $f4, 0x20($a3)
        MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
            goto L_8002EC18;
    }
    // 0x8002EB94: swc1        $f4, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
    // 0x8002EB98: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8002EB9C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002EBA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002EBA4: jalr        $t9
    // 0x8002EBA8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002EBA8: nop

    after_0:
    // 0x8002EBAC: b           L_8002EC1C
    // 0x8002EBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002EC1C;
    // 0x8002EBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002EBB4:
    // 0x8002EBB4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8002EBB8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002EBBC: sw          $t8, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r24;
    // 0x8002EBC0: beql        $a0, $zero, L_8002EC1C
    if (ctx->r4 == 0) {
        // 0x8002EBC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002EC1C;
    }
    goto skip_0;
    // 0x8002EBC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002EBC8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8002EBCC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8002EBD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002EBD4: jalr        $t9
    // 0x8002EBD8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8002EBD8: nop

    after_1:
    // 0x8002EBDC: b           L_8002EC1C
    // 0x8002EBE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002EC1C;
    // 0x8002EBE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002EBE4:
    // 0x8002EBE4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8002EBE8: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002EBEC: b           L_8002EC18
    // 0x8002EBF0: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
        goto L_8002EC18;
    // 0x8002EBF0: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
L_8002EBF4:
    // 0x8002EBF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002EBF8: b           L_8002EC18
    // 0x8002EBFC: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
        goto L_8002EC18;
    // 0x8002EBFC: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
L_8002EC00:
    // 0x8002EC00: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8002EC04: beql        $a0, $zero, L_8002EC1C
    if (ctx->r4 == 0) {
        // 0x8002EC08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002EC1C;
    }
    goto skip_1;
    // 0x8002EC08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8002EC0C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8002EC10: jalr        $t9
    // 0x8002EC14: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8002EC14: nop

    after_2:
L_8002EC18:
    // 0x8002EC18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002EC1C:
    // 0x8002EC1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002EC20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002EC24: jr          $ra
    // 0x8002EC28: nop

    return;
    // 0x8002EC28: nop

;}
RECOMP_FUNC void FUN_8002ec2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EC2C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8002EC30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002EC34: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8002EC38: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8002EC3C: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x8002EC40: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8002EC44: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x8002EC48: bne         $a2, $zero, L_8002EC58
    if (ctx->r6 != 0) {
        // 0x8002EC4C: sh          $t6, 0x46($sp)
        MEM_H(0X46, ctx->r29) = ctx->r14;
            goto L_8002EC58;
    }
    // 0x8002EC4C: sh          $t6, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r14;
    // 0x8002EC50: b           L_8002EE24
    // 0x8002EC54: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
        goto L_8002EE24;
    // 0x8002EC54: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
L_8002EC58:
    // 0x8002EC58: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x8002EC5C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8002EC60: beql        $t7, $zero, L_8002ECCC
    if (ctx->r15 == 0) {
        // 0x8002EC64: lwc1        $f2, 0x18($t0)
        ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
            goto L_8002ECCC;
    }
    goto skip_0;
    // 0x8002EC64: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    skip_0:
    // 0x8002EC68: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002EC6C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x8002EC70: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x8002EC74: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8002EC78: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x8002EC7C: jalr        $t9
    // 0x8002EC80: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002EC80: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_0:
    // 0x8002EC84: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x8002EC88: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002EC8C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002EC90: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8002EC94: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x8002EC98: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8002EC9C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8002ECA0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8002ECA4: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8002ECA8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8002ECAC: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8002ECB0: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x8002ECB4: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x8002ECB8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8002ECBC: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x8002ECC0: b           L_8002EE20
    // 0x8002ECC4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_8002EE20;
    // 0x8002ECC4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8002ECC8: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
L_8002ECCC:
    // 0x8002ECCC: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002ECD0: ldc1        $f4, -0x2BA8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2BA8);
    // 0x8002ECD4: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8002ECD8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002ECDC: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8002ECE0: nop

    // 0x8002ECE4: bc1fl       L_8002ECFC
    if (!c1cs) {
        // 0x8002ECE8: lui         $at, 0x4700
        ctx->r1 = S32(0X4700 << 16);
            goto L_8002ECFC;
    }
    goto skip_1;
    // 0x8002ECE8: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    skip_1:
    // 0x8002ECEC: lwc1        $f8, -0x2BA0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BA0);
    // 0x8002ECF0: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x8002ECF4: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8002ECF8: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
L_8002ECFC:
    // 0x8002ECFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002ED00: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8002ED04: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x8002ED08: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8002ED0C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8002ED10: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8002ED14: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8002ED18: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8002ED1C: nop

    // 0x8002ED20: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002ED24: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002ED28: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x8002ED2C: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8002ED30: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8002ED34: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x8002ED38: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x8002ED3C: lwc1        $f10, 0x18($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8002ED40: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8002ED44: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002ED48: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002ED4C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8002ED50: nop

    // 0x8002ED54: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x8002ED58: nop

    // 0x8002ED5C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002ED60: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8002ED64: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x8002ED68: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8002ED6C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x8002ED70: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8002ED74: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002ED78: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x8002ED7C: jalr        $t9
    // 0x8002ED80: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8002ED80: nop

    after_1:
    // 0x8002ED84: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002ED88: lh          $t5, 0x46($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X46);
    // 0x8002ED8C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8002ED90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002ED94: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8002ED98: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8002ED9C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8002EDA0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8002EDA4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002EDA8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002EDAC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8002EDB0: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8002EDB4: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x8002EDB8: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8002EDBC: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8002EDC0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002EDC4: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x8002EDC8: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8002EDCC: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8002EDD0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002EDD4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8002EDD8: lw          $t3, 0x24($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X24);
    // 0x8002EDDC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8002EDE0: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8002EDE4: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x8002EDE8: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x8002EDEC: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x8002EDF0: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x8002EDF4: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8002EDF8: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8002EDFC: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x8002EE00: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x8002EE04: jal         0x80028A10
    // 0x8002EE08: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_2;
    // 0x8002EE08: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_2:
    // 0x8002EE0C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8002EE10: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002EE14: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8002EE18: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x8002EE1C: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
L_8002EE20:
    // 0x8002EE20: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8002EE24:
    // 0x8002EE24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002EE28: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8002EE2C: jr          $ra
    // 0x8002EE30: nop

    return;
    // 0x8002EE30: nop

    // 0x8002EE34: nop

    // 0x8002EE38: nop

    // 0x8002EE3C: nop

;}
RECOMP_FUNC void FUN_8002f010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F014: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002F018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F01C: beq         $a1, $at, L_8002F174
    if (ctx->r5 == ctx->r1) {
        // 0x8002F020: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8002F174;
    }
    // 0x8002F020: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002F024: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8002F028: bnel        $a1, $at, L_8002F1D8
    if (ctx->r5 != ctx->r1) {
        // 0x8002F02C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002F1D8;
    }
    goto skip_0;
    // 0x8002F02C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002F030: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
    // 0x8002F034: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8002F038: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x8002F03C: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002F040: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x8002F044: lbu         $v0, 0x8($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X8);
    // 0x8002F048: beql        $v0, $zero, L_8002F068
    if (ctx->r2 == 0) {
        // 0x8002F04C: lw          $v0, 0x28($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X28);
            goto L_8002F068;
    }
    goto skip_1;
    // 0x8002F04C: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    skip_1:
    // 0x8002F050: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002F054: beq         $v0, $a0, L_8002F128
    if (ctx->r2 == ctx->r4) {
        // 0x8002F058: lui         $t0, 0x8003
        ctx->r8 = S32(0X8003 << 16);
            goto L_8002F128;
    }
    // 0x8002F058: lui         $t0, 0x8003
    ctx->r8 = S32(0X8003 << 16);
    // 0x8002F05C: b           L_8002F1D8
    // 0x8002F060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002F1D8;
    // 0x8002F060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F064: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
L_8002F068:
    // 0x8002F068: addiu       $t7, $t7, -0x944
    ctx->r15 = ADD32(ctx->r15, -0X944);
    // 0x8002F06C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x8002F070: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8002F074: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8002F078: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x8002F07C: mflo        $t9
    ctx->r25 = lo;
    // 0x8002F080: bne         $a1, $zero, L_8002F08C
    if (ctx->r5 != 0) {
        // 0x8002F084: nop
    
            goto L_8002F08C;
    }
    // 0x8002F084: nop

    // 0x8002F088: break       7
    do_break(2147676296);
L_8002F08C:
    // 0x8002F08C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002F090: bne         $a1, $at, L_8002F0A4
    if (ctx->r5 != ctx->r1) {
        // 0x8002F094: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002F0A4;
    }
    // 0x8002F094: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002F098: bne         $t8, $at, L_8002F0A4
    if (ctx->r24 != ctx->r1) {
        // 0x8002F09C: nop
    
            goto L_8002F0A4;
    }
    // 0x8002F09C: nop

    // 0x8002F0A0: break       6
    do_break(2147676320);
L_8002F0A4:
    // 0x8002F0A4: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002F0A8: mflo        $t0
    ctx->r8 = lo;
    // 0x8002F0AC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8002F0B0: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x8002F0B4: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x8002F0B8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8002F0BC: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8002F0C0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8002F0C4: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002F0C8: mflo        $t4
    ctx->r12 = lo;
    // 0x8002F0CC: sw          $t4, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r12;
    // 0x8002F0D0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8002F0D4: beql        $v1, $zero, L_8002F11C
    if (ctx->r3 == 0) {
        // 0x8002F0D8: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_8002F11C;
    }
    goto skip_2;
    // 0x8002F0D8: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_2:
    // 0x8002F0DC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8002F0E0: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    // 0x8002F0E4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8002F0E8: sw          $t5, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r13;
    // 0x8002F0EC: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x8002F0F0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002F0F4: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x8002F0F8: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x8002F0FC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8002F100: sw          $t9, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r25;
    // 0x8002F104: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8002F108: jal         0x80031AE0
    // 0x8002F10C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    LOOKUP_FUNC(0x80031AE0)(rdram, ctx);
        goto after_0;
    // 0x8002F10C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x8002F110: b           L_8002F1D8
    // 0x8002F114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002F1D8;
    // 0x8002F114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F118: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_8002F11C:
    // 0x8002F11C: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x8002F120: b           L_8002F1D4
    // 0x8002F124: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_8002F1D4;
    // 0x8002F124: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_8002F128:
    // 0x8002F128: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x8002F12C: addiu       $t0, $t0, -0xE1C
    ctx->r8 = ADD32(ctx->r8, -0XE1C);
    // 0x8002F130: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x8002F134: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8002F138: beql        $v1, $zero, L_8002F168
    if (ctx->r3 == 0) {
        // 0x8002F13C: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_8002F168;
    }
    goto skip_3;
    // 0x8002F13C: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_3:
    // 0x8002F140: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8002F144: sw          $t1, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r9;
    // 0x8002F148: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x8002F14C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8002F150: sw          $t3, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r11;
    // 0x8002F154: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x8002F158: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8002F15C: b           L_8002F1D4
    // 0x8002F160: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
        goto L_8002F1D4;
    // 0x8002F160: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
    // 0x8002F164: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_8002F168:
    // 0x8002F168: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x8002F16C: b           L_8002F1D4
    // 0x8002F170: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_8002F1D4;
    // 0x8002F170: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_8002F174:
    // 0x8002F174: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x8002F178: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002F17C: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x8002F180: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x8002F184: beq         $v0, $zero, L_8002F1D4
    if (ctx->r2 == 0) {
        // 0x8002F188: sw          $zero, 0x38($a3)
        MEM_W(0X38, ctx->r7) = 0;
            goto L_8002F1D4;
    }
    // 0x8002F188: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x8002F18C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8002F190: sw          $t6, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r14;
    // 0x8002F194: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x8002F198: bne         $v1, $zero, L_8002F1B8
    if (ctx->r3 != 0) {
        // 0x8002F19C: nop
    
            goto L_8002F1B8;
    }
    // 0x8002F19C: nop

    // 0x8002F1A0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8002F1A4: beql        $v1, $zero, L_8002F1D8
    if (ctx->r3 == 0) {
        // 0x8002F1A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002F1D8;
    }
    goto skip_4;
    // 0x8002F1A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8002F1AC: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x8002F1B0: b           L_8002F1D4
    // 0x8002F1B4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
        goto L_8002F1D4;
    // 0x8002F1B4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
L_8002F1B8:
    // 0x8002F1B8: bnel        $a0, $v1, L_8002F1D8
    if (ctx->r4 != ctx->r3) {
        // 0x8002F1BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002F1D8;
    }
    goto skip_5;
    // 0x8002F1BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8002F1C0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8002F1C4: beql        $v1, $zero, L_8002F1D8
    if (ctx->r3 == 0) {
        // 0x8002F1C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002F1D8;
    }
    goto skip_6;
    // 0x8002F1C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8002F1CC: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8002F1D0: sw          $t8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r24;
L_8002F1D4:
    // 0x8002F1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002F1D8:
    // 0x8002F1D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002F1DC: jr          $ra
    // 0x8002F1E0: nop

    return;
    // 0x8002F1E0: nop

;}
RECOMP_FUNC void FUN_8002f1e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F1E4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8002F1E8: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8002F1EC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8002F1F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002F1F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002F1F8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8002F1FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002F200: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8002F204: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002F208: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8002F20C: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x8002F210: bne         $a2, $zero, L_8002F220
    if (ctx->r6 != 0) {
        // 0x8002F214: or          $t1, $t0, $zero
        ctx->r9 = ctx->r8 | 0;
            goto L_8002F220;
    }
    // 0x8002F214: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x8002F218: b           L_8002F574
    // 0x8002F21C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8002F574;
    // 0x8002F21C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8002F220:
    // 0x8002F220: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x8002F224: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x8002F228: addu        $t6, $v0, $s3
    ctx->r14 = ADD32(ctx->r2, ctx->r19);
    // 0x8002F22C: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x8002F230: beql        $at, $zero, L_8002F444
    if (ctx->r1 == 0) {
        // 0x8002F234: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_8002F444;
    }
    goto skip_0;
    // 0x8002F234: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_0:
    // 0x8002F238: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8002F23C: subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
    // 0x8002F240: beql        $t7, $zero, L_8002F444
    if (ctx->r15 == 0) {
        // 0x8002F244: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_8002F444;
    }
    goto skip_1;
    // 0x8002F244: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_1:
    // 0x8002F248: blez        $s2, L_8002F2C4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8002F24C: sll         $s1, $s2, 1
        ctx->r17 = S32(ctx->r18 << 1);
            goto L_8002F2C4;
    }
    // 0x8002F24C: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x8002F250: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x8002F254: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8002F258: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8002F25C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8002F260: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002F264: jalr        $t9
    // 0x8002F268: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002F268: nop

    after_0:
    // 0x8002F26C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8002F270: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x8002F274: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8002F278: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x8002F27C: addu        $a3, $s1, $a2
    ctx->r7 = ADD32(ctx->r17, ctx->r6);
    // 0x8002F280: andi        $t5, $a3, 0x7
    ctx->r13 = ctx->r7 & 0X7;
    // 0x8002F284: subu        $t6, $a3, $t5
    ctx->r14 = SUB32(ctx->r7, ctx->r13);
    // 0x8002F288: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8002F28C: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x8002F290: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8002F294: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002F298: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002F29C: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8002F2A0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8002F2A4: subu        $t3, $v0, $a2
    ctx->r11 = SUB32(ctx->r2, ctx->r6);
    // 0x8002F2A8: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x8002F2AC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8002F2B0: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x8002F2B4: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8002F2B8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8002F2BC: b           L_8002F2C8
    // 0x8002F2C0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_8002F2C8;
    // 0x8002F2C0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_8002F2C4:
    // 0x8002F2C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8002F2C8:
    // 0x8002F2C8: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x8002F2CC: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8002F2D0: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x8002F2D4: sh          $t5, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r13;
    // 0x8002F2D8: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x8002F2DC: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x8002F2E0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8002F2E4: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x8002F2E8: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x8002F2EC: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8002F2F0: sw          $t8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r24;
    // 0x8002F2F4: beq         $at, $zero, L_8002F41C
    if (ctx->r1 == 0) {
        // 0x8002F2F8: lh          $t0, 0x0($t2)
        ctx->r8 = MEM_H(ctx->r10, 0X0);
            goto L_8002F41C;
    }
    // 0x8002F2F8: lh          $t0, 0x0($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X0);
    // 0x8002F2FC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_8002F300:
    // 0x8002F300: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002F304: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x8002F308: beq         $v0, $at, L_8002F31C
    if (ctx->r2 == ctx->r1) {
        // 0x8002F30C: subu        $s3, $s3, $s2
        ctx->r19 = SUB32(ctx->r19, ctx->r18);
            goto L_8002F31C;
    }
    // 0x8002F30C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x8002F310: beq         $v0, $zero, L_8002F31C
    if (ctx->r2 == 0) {
        // 0x8002F314: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8002F31C;
    }
    // 0x8002F314: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x8002F318: sw          $t3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r11;
L_8002F31C:
    // 0x8002F31C: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x8002F320: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x8002F324: subu        $v0, $t4, $t5
    ctx->r2 = SUB32(ctx->r12, ctx->r13);
    // 0x8002F328: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x8002F32C: beq         $at, $zero, L_8002F33C
    if (ctx->r1 == 0) {
        // 0x8002F330: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8002F33C;
    }
    // 0x8002F330: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8002F334: b           L_8002F33C
    // 0x8002F338: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
        goto L_8002F33C;
    // 0x8002F338: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_8002F33C:
    // 0x8002F33C: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x8002F340: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8002F344: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x8002F348: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8002F34C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8002F350: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x8002F354: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002F358: jalr        $t9
    // 0x8002F35C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8002F35C: nop

    after_1:
    // 0x8002F360: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8002F364: andi        $a1, $v0, 0x7
    ctx->r5 = ctx->r2 & 0X7;
    // 0x8002F368: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F36C: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x8002F370: beq         $v1, $zero, L_8002F384
    if (ctx->r3 == 0) {
        // 0x8002F374: addu        $a3, $s1, $a1
        ctx->r7 = ADD32(ctx->r17, ctx->r5);
            goto L_8002F384;
    }
    // 0x8002F374: addu        $a3, $s1, $a1
    ctx->r7 = ADD32(ctx->r17, ctx->r5);
    // 0x8002F378: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8002F37C: b           L_8002F388
    // 0x8002F380: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
        goto L_8002F388;
    // 0x8002F380: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
L_8002F384:
    // 0x8002F384: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8002F388:
    // 0x8002F388: addu        $t7, $t0, $a2
    ctx->r15 = ADD32(ctx->r8, ctx->r6);
    // 0x8002F38C: andi        $t4, $a3, 0x7
    ctx->r12 = ctx->r7 & 0X7;
    // 0x8002F390: subu        $t5, $a3, $t4
    ctx->r13 = SUB32(ctx->r7, ctx->r12);
    // 0x8002F394: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8002F398: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8002F39C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8002F3A0: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x8002F3A4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8002F3A8: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x8002F3AC: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8002F3B0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8002F3B4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8002F3B8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8002F3BC: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x8002F3C0: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x8002F3C4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8002F3C8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8002F3CC: bne         $a1, $zero, L_8002F3D8
    if (ctx->r5 != 0) {
        // 0x8002F3D0: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_8002F3D8;
    }
    // 0x8002F3D0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8002F3D4: beq         $a2, $zero, L_8002F410
    if (ctx->r6 == 0) {
        // 0x8002F3D8: addu        $t3, $t0, $a1
        ctx->r11 = ADD32(ctx->r8, ctx->r5);
            goto L_8002F410;
    }
L_8002F3D8:
    // 0x8002F3D8: addu        $t3, $t0, $a1
    ctx->r11 = ADD32(ctx->r8, ctx->r5);
    // 0x8002F3DC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002F3E0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002F3E4: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x8002F3E8: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8002F3EC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8002F3F0: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x8002F3F4: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x8002F3F8: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x8002F3FC: or          $t3, $t7, $t8
    ctx->r11 = ctx->r15 | ctx->r24;
    // 0x8002F400: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x8002F404: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002F408: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8002F40C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_8002F410:
    // 0x8002F410: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8002F414: bnel        $at, $zero, L_8002F300
    if (ctx->r1 != 0) {
        // 0x8002F418: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_8002F300;
    }
    goto skip_2;
    // 0x8002F418: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_2:
L_8002F41C:
    // 0x8002F41C: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x8002F420: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x8002F424: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x8002F428: addu        $t5, $t4, $s3
    ctx->r13 = ADD32(ctx->r12, ctx->r19);
    // 0x8002F42C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002F430: sw          $t5, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r13;
    // 0x8002F434: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x8002F438: b           L_8002F574
    // 0x8002F43C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8002F574;
    // 0x8002F43C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8002F440: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
L_8002F444:
    // 0x8002F444: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x8002F448: sll         $s1, $s3, 1
    ctx->r17 = S32(ctx->r19 << 1);
    // 0x8002F44C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8002F450: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8002F454: addu        $v1, $a0, $s1
    ctx->r3 = ADD32(ctx->r4, ctx->r17);
    // 0x8002F458: subu        $t3, $v1, $t8
    ctx->r11 = SUB32(ctx->r3, ctx->r24);
    // 0x8002F45C: subu        $s2, $t3, $t4
    ctx->r18 = SUB32(ctx->r11, ctx->r12);
    // 0x8002F460: bgezl       $s2, L_8002F470
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8002F464: slt         $at, $s1, $s2
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_8002F470;
    }
    goto skip_3;
    // 0x8002F464: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    skip_3:
    // 0x8002F468: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002F46C: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
L_8002F470:
    // 0x8002F470: beql        $at, $zero, L_8002F480
    if (ctx->r1 == 0) {
        // 0x8002F474: slt         $at, $s2, $s1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
            goto L_8002F480;
    }
    goto skip_4;
    // 0x8002F474: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
    skip_4:
    // 0x8002F478: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x8002F47C: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
L_8002F480:
    // 0x8002F480: beql        $at, $zero, L_8002F534
    if (ctx->r1 == 0) {
        // 0x8002F484: sw          $v1, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r3;
            goto L_8002F534;
    }
    goto skip_5;
    // 0x8002F484: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
    skip_5:
    // 0x8002F488: blez        $s3, L_8002F508
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8002F48C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8002F508;
    }
    // 0x8002F48C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002F490: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8002F494: subu        $a1, $s1, $s2
    ctx->r5 = SUB32(ctx->r17, ctx->r18);
    // 0x8002F498: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x8002F49C: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8002F4A0: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8002F4A4: jalr        $t9
    // 0x8002F4A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8002F4A8: nop

    after_2:
    // 0x8002F4AC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8002F4B0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8002F4B4: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x8002F4B8: lh          $t5, 0x0($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X0);
    // 0x8002F4BC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8002F4C0: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x8002F4C4: andi        $t8, $a3, 0x7
    ctx->r24 = ctx->r7 & 0X7;
    // 0x8002F4C8: subu        $t3, $a3, $t8
    ctx->r11 = SUB32(ctx->r7, ctx->r24);
    // 0x8002F4CC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8002F4D0: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8002F4D4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002F4D8: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8002F4DC: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8002F4E0: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x8002F4E4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8002F4E8: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x8002F4EC: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x8002F4F0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8002F4F4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8002F4F8: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8002F4FC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8002F500: b           L_8002F508
    // 0x8002F504: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_8002F508;
    // 0x8002F504: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_8002F508:
    // 0x8002F508: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x8002F50C: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x8002F510: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x8002F514: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x8002F518: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x8002F51C: addu        $t4, $t3, $s3
    ctx->r12 = ADD32(ctx->r11, ctx->r19);
    // 0x8002F520: addu        $t5, $t9, $s1
    ctx->r13 = ADD32(ctx->r25, ctx->r17);
    // 0x8002F524: sw          $t4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r12;
    // 0x8002F528: b           L_8002F534
    // 0x8002F52C: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
        goto L_8002F534;
    // 0x8002F52C: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
    // 0x8002F530: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
L_8002F534:
    // 0x8002F534: beq         $s2, $zero, L_8002F570
    if (ctx->r18 == 0) {
        // 0x8002F538: subu        $v1, $s1, $s2
        ctx->r3 = SUB32(ctx->r17, ctx->r18);
            goto L_8002F570;
    }
    // 0x8002F538: subu        $v1, $s1, $s2
    ctx->r3 = SUB32(ctx->r17, ctx->r18);
    // 0x8002F53C: bgez        $v1, L_8002F548
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002F540: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_8002F548;
    }
    // 0x8002F540: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8002F544: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8002F548:
    // 0x8002F548: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    // 0x8002F54C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002F550: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002F554: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8002F558: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8002F55C: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8002F560: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x8002F564: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8002F568: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x8002F56C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_8002F570:
    // 0x8002F570: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8002F574:
    // 0x8002F574: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002F578: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002F57C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002F580: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F584: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8002F588: jr          $ra
    // 0x8002F58C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8002F58C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002f590(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002f590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F594: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002F598: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8002F59C: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x8002F5A0: sll         $t8, $s5, 16
    ctx->r24 = S32(ctx->r21 << 16);
    // 0x8002F5A4: sra         $s5, $t8, 16
    ctx->r21 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002F5A8: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002F5AC: blez        $s1, L_8002F618
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8002F5B0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8002F618;
    }
    // 0x8002F5B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F5B4: lw          $t9, 0x30($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X30);
    // 0x8002F5B8: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x8002F5BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002F5C0: jalr        $t9
    // 0x8002F5C4: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002F5C4: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    after_0:
    // 0x8002F5C8: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x8002F5CC: addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // 0x8002F5D0: andi        $t6, $s3, 0xFFFF
    ctx->r14 = ctx->r19 & 0XFFFF;
    // 0x8002F5D4: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8002F5D8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002F5DC: andi        $t8, $s1, 0x7
    ctx->r24 = ctx->r17 & 0X7;
    // 0x8002F5E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002F5E4: subu        $t9, $s1, $t8
    ctx->r25 = SUB32(ctx->r17, ctx->r24);
    // 0x8002F5E8: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8002F5EC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8002F5F0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002F5F4: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8002F5F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002F5FC: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8002F600: subu        $t9, $v0, $a2
    ctx->r25 = SUB32(ctx->r2, ctx->r6);
    // 0x8002F604: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x8002F608: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8002F60C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8002F610: b           L_8002F61C
    // 0x8002F614: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_8002F61C;
    // 0x8002F614: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8002F618:
    // 0x8002F618: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8002F61C:
    // 0x8002F61C: andi        $t6, $s4, 0x2
    ctx->r14 = ctx->r20 & 0X2;
    // 0x8002F620: beq         $t6, $zero, L_8002F648
    if (ctx->r14 == 0) {
        // 0x8002F624: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8002F648;
    }
    // 0x8002F624: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8002F628: lui         $t7, 0xF00
    ctx->r15 = S32(0XF00 << 16);
    // 0x8002F62C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002F630: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x8002F634: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8002F638: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002F63C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8002F640: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002F644: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8002F648:
    // 0x8002F648: addu        $t6, $s3, $a2
    ctx->r14 = ADD32(ctx->r19, ctx->r6);
    // 0x8002F64C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8002F650: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8002F654: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8002F658: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8002F65C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002F660: sll         $t7, $s6, 1
    ctx->r15 = S32(ctx->r22 << 1);
    // 0x8002F664: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8002F668: sll         $t6, $s5, 16
    ctx->r14 = S32(ctx->r21 << 16);
    // 0x8002F66C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8002F670: andi        $t7, $s4, 0xFF
    ctx->r15 = ctx->r20 & 0XFF;
    // 0x8002F674: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002F678: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8002F67C: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8002F680: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8002F684: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8002F688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002F68C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8002F690: lw          $t9, 0x14($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X14);
    // 0x8002F694: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8002F698: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002F69C: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8002F6A0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8002F6A4: sw          $zero, 0x40($s2)
    MEM_W(0X40, ctx->r18) = 0;
    // 0x8002F6A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F6AC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002F6B0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8002F6B4: jr          $ra
    // 0x8002F6B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002F6B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8002f6bc(rdram, ctx);
;}
RECOMP_FUNC void FUN_8002f6bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F6BC: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8002F6C0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8002F6C4: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x8002F6C8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8002F6CC: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8002F6D0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002F6D4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8002F6D8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8002F6DC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8002F6E0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8002F6E4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8002F6E8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8002F6EC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8002F6F0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002F6F4: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x8002F6F8: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x8002F6FC: bne         $a2, $zero, L_8002F70C
    if (ctx->r6 != 0) {
        // 0x8002F700: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_8002F70C;
    }
    // 0x8002F700: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8002F704: b           L_8002FB2C
    // 0x8002F708: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
        goto L_8002FB2C;
    // 0x8002F708: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
L_8002F70C:
    // 0x8002F70C: lw          $t6, 0x2C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X2C);
    // 0x8002F710: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002F714: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002F718: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x8002F71C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8002F720: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x8002F724: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8002F728: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8002F72C: lw          $t9, 0x28($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X28);
    // 0x8002F730: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8002F734: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002F738: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x8002F73C: addiu       $t2, $a1, 0x8
    ctx->r10 = ADD32(ctx->r5, 0X8);
    // 0x8002F740: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002F744: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002F748: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8002F74C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8002F750: lw          $v1, 0x38($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X38);
    // 0x8002F754: lw          $a0, 0x20($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X20);
    // 0x8002F758: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8002F75C: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x8002F760: sltu        $t1, $a0, $t9
    ctx->r9 = ctx->r4 < ctx->r25 ? 1 : 0;
    // 0x8002F764: beq         $t1, $zero, L_8002F778
    if (ctx->r9 == 0) {
        // 0x8002F768: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_8002F778;
    }
    // 0x8002F768: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8002F76C: lw          $t1, 0x24($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X24);
    // 0x8002F770: sltu        $t6, $zero, $t1
    ctx->r14 = 0 < ctx->r9 ? 1 : 0;
    // 0x8002F774: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
L_8002F778:
    // 0x8002F778: beq         $t1, $zero, L_8002F788
    if (ctx->r9 == 0) {
        // 0x8002F77C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8002F788;
    }
    // 0x8002F77C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8002F780: b           L_8002F788
    // 0x8002F784: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
        goto L_8002F788;
    // 0x8002F784: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
L_8002F788:
    // 0x8002F788: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x8002F78C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x8002F790: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x8002F794: beq         $v1, $zero, L_8002F7A4
    if (ctx->r3 == 0) {
        // 0x8002F798: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8002F7A4;
    }
    // 0x8002F798: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8002F79C: b           L_8002F7A4
    // 0x8002F7A0: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
        goto L_8002F7A4;
    // 0x8002F7A0: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
L_8002F7A4:
    // 0x8002F7A4: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x8002F7A8: bgez        $a0, L_8002F7B4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8002F7AC: nop
    
            goto L_8002F7B4;
    }
    // 0x8002F7AC: nop

    // 0x8002F7B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8002F7B4:
    // 0x8002F7B4: beq         $t1, $zero, L_8002F9BC
    if (ctx->r9 == 0) {
        // 0x8002F7B8: addiu       $fp, $a0, 0xF
        ctx->r30 = ADD32(ctx->r4, 0XF);
            goto L_8002F9BC;
    }
    // 0x8002F7B8: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x8002F7BC: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x8002F7C0: sra         $t8, $fp, 4
    ctx->r24 = S32(SIGNED(ctx->r30) >> 4);
    // 0x8002F7C4: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x8002F7C8: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x8002F7CC: sll         $t1, $t8, 3
    ctx->r9 = S32(ctx->r24 << 3);
    // 0x8002F7D0: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8002F7D4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8002F7D8: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8002F7DC: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x8002F7E0: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x8002F7E4: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x8002F7E8: or          $fp, $t8, $zero
    ctx->r30 = ctx->r24 | 0;
    // 0x8002F7EC: jal         0x8002F590
    // 0x8002F7F0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    LOOKUP_FUNC(0x8002F590)(rdram, ctx);
        goto after_0;
    // 0x8002F7F0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_0:
    // 0x8002F7F4: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x8002F7F8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8002F7FC: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8002F800: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8002F804: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8002F808: beq         $v1, $zero, L_8002F824
    if (ctx->r3 == 0) {
        // 0x8002F80C: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_8002F824;
    }
    // 0x8002F80C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8002F810: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x8002F814: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x8002F818: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002F81C: b           L_8002F830
    // 0x8002F820: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
        goto L_8002F830;
    // 0x8002F820: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_8002F824:
    // 0x8002F824: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x8002F828: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x8002F82C: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
L_8002F830:
    // 0x8002F830: lw          $v0, 0x1C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X1C);
    // 0x8002F834: lw          $t7, 0x28($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X28);
    // 0x8002F838: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002F83C: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x8002F840: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x8002F844: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8002F848: srl         $t9, $v0, 4
    ctx->r25 = S32(U32(ctx->r2) >> 4);
    // 0x8002F84C: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x8002F850: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x8002F854: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8002F858: addiu       $t9, $t7, 0x9
    ctx->r25 = ADD32(ctx->r15, 0X9);
    // 0x8002F85C: sw          $t9, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r25;
    // 0x8002F860: sw          $v0, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r2;
    // 0x8002F864: beq         $at, $zero, L_8002F98C
    if (ctx->r1 == 0) {
        // 0x8002F868: lh          $a2, 0x0($a3)
        ctx->r6 = MEM_H(ctx->r7, 0X0);
            goto L_8002F98C;
    }
    // 0x8002F868: lh          $a2, 0x0($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X0);
    // 0x8002F86C: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
L_8002F870:
    // 0x8002F870: addiu       $t8, $fp, 0x1
    ctx->r24 = ADD32(ctx->r30, 0X1);
    // 0x8002F874: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x8002F878: lw          $v0, 0x24($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X24);
    // 0x8002F87C: addu        $a3, $t6, $a2
    ctx->r7 = ADD32(ctx->r14, ctx->r6);
    // 0x8002F880: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x8002F884: and         $t7, $a3, $at
    ctx->r15 = ctx->r7 & ctx->r1;
    // 0x8002F888: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002F88C: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x8002F890: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8002F894: beq         $v0, $at, L_8002F8A8
    if (ctx->r2 == ctx->r1) {
        // 0x8002F898: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_8002F8A8;
    }
    // 0x8002F898: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x8002F89C: beq         $v0, $zero, L_8002F8A8
    if (ctx->r2 == 0) {
        // 0x8002F8A0: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8002F8A8;
    }
    // 0x8002F8A0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8002F8A4: sw          $t9, 0x24($s7)
    MEM_W(0X24, ctx->r23) = ctx->r25;
L_8002F8A8:
    // 0x8002F8A8: lw          $t8, 0x20($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X20);
    // 0x8002F8AC: lw          $t6, 0x1C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X1C);
    // 0x8002F8B0: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x8002F8B4: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x8002F8B8: subu        $v0, $t8, $t6
    ctx->r2 = SUB32(ctx->r24, ctx->r14);
    // 0x8002F8BC: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x8002F8C0: beq         $at, $zero, L_8002F8D0
    if (ctx->r1 == 0) {
        // 0x8002F8C4: sll         $s5, $a3, 16
        ctx->r21 = S32(ctx->r7 << 16);
            goto L_8002F8D0;
    }
    // 0x8002F8C4: sll         $s5, $a3, 16
    ctx->r21 = S32(ctx->r7 << 16);
    // 0x8002F8C8: b           L_8002F8D4
    // 0x8002F8CC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_8002F8D4;
    // 0x8002F8CC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_8002F8D0:
    // 0x8002F8D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8002F8D4:
    // 0x8002F8D4: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x8002F8D8: sra         $t8, $s5, 16
    ctx->r24 = S32(SIGNED(ctx->r21) >> 16);
    // 0x8002F8DC: or          $s5, $t8, $zero
    ctx->r21 = ctx->r24 | 0;
    // 0x8002F8E0: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x8002F8E4: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x8002F8E8: bgez        $a0, L_8002F8F4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8002F8EC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8002F8F4;
    }
    // 0x8002F8EC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8002F8F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8002F8F4:
    // 0x8002F8F4: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x8002F8F8: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x8002F8FC: sra         $t9, $fp, 4
    ctx->r25 = S32(SIGNED(ctx->r30) >> 4);
    // 0x8002F900: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x8002F904: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8002F908: ori         $t6, $s4, 0x2
    ctx->r14 = ctx->r20 | 0X2;
    // 0x8002F90C: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x8002F910: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8002F914: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8002F918: or          $fp, $t9, $zero
    ctx->r30 = ctx->r25 | 0;
    // 0x8002F91C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x8002F920: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    // 0x8002F924: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x8002F928: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x8002F92C: jal         0x8002F590
    // 0x8002F930: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    LOOKUP_FUNC(0x8002F590)(rdram, ctx);
        goto after_1;
    // 0x8002F930: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_1:
    // 0x8002F934: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x8002F938: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x8002F93C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002F940: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8002F944: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002F948: addu        $t8, $t9, $a3
    ctx->r24 = ADD32(ctx->r25, ctx->r7);
    // 0x8002F94C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8002F950: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8002F954: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x8002F958: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8002F95C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002F960: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8002F964: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8002F968: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x8002F96C: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x8002F970: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002F974: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8002F978: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8002F97C: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002F980: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002F984: bne         $at, $zero, L_8002F870
    if (ctx->r1 != 0) {
        // 0x8002F988: addiu       $t2, $v0, 0x8
        ctx->r10 = ADD32(ctx->r2, 0X8);
            goto L_8002F870;
    }
    // 0x8002F988: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
L_8002F98C:
    // 0x8002F98C: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x8002F990: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x8002F994: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8002F998: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x8002F99C: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x8002F9A0: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x8002F9A4: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x8002F9A8: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x8002F9AC: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x8002F9B0: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x8002F9B4: b           L_8002FB2C
    // 0x8002F9B8: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_8002FB2C;
    // 0x8002F9B8: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_8002F9BC:
    // 0x8002F9BC: lw          $v0, 0x28($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X28);
    // 0x8002F9C0: sra         $t7, $fp, 4
    ctx->r15 = S32(SIGNED(ctx->r30) >> 4);
    // 0x8002F9C4: lw          $t9, 0x44($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X44);
    // 0x8002F9C8: sll         $t1, $t7, 3
    ctx->r9 = S32(ctx->r15 << 3);
    // 0x8002F9CC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8002F9D0: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x8002F9D4: or          $fp, $t7, $zero
    ctx->r30 = ctx->r15 | 0;
    // 0x8002F9D8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8002F9DC: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x8002F9E0: subu        $t6, $t3, $t8
    ctx->r14 = SUB32(ctx->r11, ctx->r24);
    // 0x8002F9E4: subu        $v1, $t6, $t7
    ctx->r3 = SUB32(ctx->r14, ctx->r15);
    // 0x8002F9E8: bgez        $v1, L_8002F9F4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002F9EC: sll         $a1, $fp, 4
        ctx->r5 = S32(ctx->r30 << 4);
            goto L_8002F9F4;
    }
    // 0x8002F9EC: sll         $a1, $fp, 4
    ctx->r5 = S32(ctx->r30 << 4);
    // 0x8002F9F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8002F9F4:
    // 0x8002F9F4: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x8002F9F8: mflo        $v0
    ctx->r2 = lo;
    // 0x8002F9FC: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x8002FA00: addu        $t4, $a1, $a2
    ctx->r12 = ADD32(ctx->r5, ctx->r6);
    // 0x8002FA04: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002FA08: beq         $at, $zero, L_8002FA14
    if (ctx->r1 == 0) {
        // 0x8002FA0C: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_8002FA14;
    }
    // 0x8002FA0C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x8002FA10: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
L_8002FA14:
    // 0x8002FA14: andi        $t8, $a0, 0xF
    ctx->r24 = ctx->r4 & 0XF;
    // 0x8002FA18: subu        $t6, $a0, $t8
    ctx->r14 = SUB32(ctx->r4, ctx->r24);
    // 0x8002FA1C: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002FA20: beq         $at, $zero, L_8002FAD0
    if (ctx->r1 == 0) {
        // 0x8002FA24: subu        $a2, $t1, $v1
        ctx->r6 = SUB32(ctx->r9, ctx->r3);
            goto L_8002FAD0;
    }
    // 0x8002FA24: subu        $a2, $t1, $v1
    ctx->r6 = SUB32(ctx->r9, ctx->r3);
    // 0x8002FA28: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x8002FA2C: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x8002FA30: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002FA34: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x8002FA38: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x8002FA3C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8002FA40: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x8002FA44: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x8002FA48: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x8002FA4C: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x8002FA50: subu        $s6, $a1, $a0
    ctx->r22 = SUB32(ctx->r5, ctx->r4);
    // 0x8002FA54: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8002FA58: jal         0x8002F590
    // 0x8002FA5C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    LOOKUP_FUNC(0x8002F590)(rdram, ctx);
        goto after_2;
    // 0x8002FA5C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_2:
    // 0x8002FA60: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x8002FA64: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x8002FA68: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8002FA6C: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8002FA70: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8002FA74: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002FA78: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x8002FA7C: beq         $v1, $zero, L_8002FA98
    if (ctx->r3 == 0) {
        // 0x8002FA80: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_8002FA98;
    }
    // 0x8002FA80: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8002FA84: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x8002FA88: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8002FA8C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8002FA90: b           L_8002FAA4
    // 0x8002FA94: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
        goto L_8002FAA4;
    // 0x8002FA94: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_8002FA98:
    // 0x8002FA98: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x8002FA9C: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x8002FAA0: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_8002FAA4:
    // 0x8002FAA4: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x8002FAA8: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x8002FAAC: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x8002FAB0: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x8002FAB4: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x8002FAB8: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x8002FABC: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x8002FAC0: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x8002FAC4: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x8002FAC8: b           L_8002FAD8
    // 0x8002FACC: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_8002FAD8;
    // 0x8002FACC: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_8002FAD0:
    // 0x8002FAD0: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x8002FAD4: sw          $t3, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r11;
L_8002FAD8:
    // 0x8002FAD8: beq         $a0, $zero, L_8002FB28
    if (ctx->r4 == 0) {
        // 0x8002FADC: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8002FB28;
    }
    // 0x8002FADC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8002FAE0: beq         $t5, $zero, L_8002FAF8
    if (ctx->r13 == 0) {
        // 0x8002FAE4: sw          $zero, 0x3C($s7)
        MEM_W(0X3C, ctx->r23) = 0;
            goto L_8002FAF8;
    }
    // 0x8002FAE4: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x8002FAE8: subu        $v1, $t4, $a0
    ctx->r3 = SUB32(ctx->r12, ctx->r4);
    // 0x8002FAEC: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8002FAF0: b           L_8002FAFC
    // 0x8002FAF4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_8002FAFC;
    // 0x8002FAF4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_8002FAF8:
    // 0x8002FAF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8002FAFC:
    // 0x8002FAFC: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x8002FB00: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002FB04: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002FB08: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x8002FB0C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8002FB10: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8002FB14: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002FB18: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x8002FB1C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002FB20: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002FB24: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_8002FB28:
    // 0x8002FB28: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8002FB2C:
    // 0x8002FB2C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8002FB30: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8002FB34: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8002FB38: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8002FB3C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8002FB40: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8002FB44: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8002FB48: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8002FB4C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8002FB50: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8002FB54: jr          $ra
    // 0x8002FB58: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8002FB58: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x8002FB5C: nop

;}
RECOMP_FUNC void FUN_8002fc20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FC20: jr          $ra
    // 0x8002FC24: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x8002FC24: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    // 0x8002FC28: nop

    // 0x8002FC2C: nop

;}
RECOMP_FUNC void osAfterPreNMI(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FC30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002FC34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FC38: jal         0x80035090
    // 0x8002FC3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80035090)(rdram, ctx);
        goto after_0;
    // 0x8002FC3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8002FC40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FC44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002FC48: jr          $ra
    // 0x8002FC4C: nop

    return;
    // 0x8002FC4C: nop

;}
RECOMP_FUNC void FUN_8002fc50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FC50: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8002FC54: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002FC58: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8002FC5C: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8002FC60: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8002FC64: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8002FC68: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8002FC6C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8002FC70: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8002FC74: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8002FC78: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8002FC7C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8002FC80: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x8002FC84: jal         0x80029E30
    // 0x8002FC88: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80029E30)(rdram, ctx);
        goto after_0;
    // 0x8002FC88: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    after_0:
    // 0x8002FC8C: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8002FC90: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8002FC94: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8002FC98: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8002FC9C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8002FCA0: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8002FCA4: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8002FCA8: sub.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8002FCAC: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8002FCB0: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x8002FCB4: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8002FCB8: mul.s       $f10, $f30, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x8002FCBC: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    // 0x8002FCC0: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8002FCC4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002FCC8: jal         0x8002FC20
    // 0x8002FCCC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x8002FCCC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x8002FCD0: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8002FCD4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002FCD8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002FCDC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8002FCE0: lwc1        $f20, 0x88($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002FCE4: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x8002FCE8: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8002FCEC: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8002FCF0: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x8002FCF4: mul.s       $f28, $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x8002FCF8: nop

    // 0x8002FCFC: mul.s       $f30, $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x8002FD00: nop

    // 0x8002FD04: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8002FD08: nop

    // 0x8002FD0C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8002FD10: swc1        $f20, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f20.u32l;
    // 0x8002FD14: mul.s       $f4, $f10, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x8002FD18: sub.s       $f22, $f8, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8002FD1C: mul.s       $f8, $f10, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f28.fl);
    // 0x8002FD20: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002FD24: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8002FD28: sub.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8002FD2C: mul.s       $f8, $f4, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x8002FD30: nop

    // 0x8002FD34: mul.s       $f10, $f6, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x8002FD38: sub.s       $f26, $f8, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8002FD3C: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8002FD40: nop

    // 0x8002FD44: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8002FD48: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002FD4C: mul.s       $f10, $f26, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8002FD50: jal         0x8002FC20
    // 0x8002FD54: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x8002FD54: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x8002FD58: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002FD5C: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8002FD60: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8002FD64: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8002FD68: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002FD6C: div.d       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f20.d, ctx->f4.d);
    // 0x8002FD70: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x8002FD74: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8002FD78: nop

    // 0x8002FD7C: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8002FD80: nop

    // 0x8002FD84: mul.s       $f26, $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x8002FD88: nop

    // 0x8002FD8C: mul.s       $f8, $f30, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f26.fl);
    // 0x8002FD90: nop

    // 0x8002FD94: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8002FD98: sub.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8002FD9C: mul.s       $f6, $f10, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8002FDA0: nop

    // 0x8002FDA4: mul.s       $f8, $f28, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f26.fl);
    // 0x8002FDA8: swc1        $f14, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f14.u32l;
    // 0x8002FDAC: mul.s       $f4, $f28, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f24.fl);
    // 0x8002FDB0: nop

    // 0x8002FDB4: mul.s       $f10, $f30, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x8002FDB8: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8002FDBC: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8002FDC0: nop

    // 0x8002FDC4: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8002FDC8: swc1        $f16, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f16.u32l;
    // 0x8002FDCC: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8002FDD0: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8002FDD4: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002FDD8: swc1        $f18, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f18.u32l;
    // 0x8002FDDC: jal         0x8002FC20
    // 0x8002FDE0: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_3;
    // 0x8002FDE0: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_3:
    // 0x8002FDE4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8002FDE8: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002FDEC: div.d       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f20.d, ctx->f6.d);
    // 0x8002FDF0: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8002FDF4: lwc1        $f14, 0xC8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8002FDF8: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8002FDFC: lwc1        $f18, 0xD0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8002FE00: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x8002FE04: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8002FE08: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8002FE0C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8002FE10: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x8002FE14: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8002FE18: swc1        $f8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f8.u32l;
    // 0x8002FE1C: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8002FE20: nop

    // 0x8002FE24: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8002FE28: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    // 0x8002FE2C: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8002FE30: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002FE34: jal         0x8002FC20
    // 0x8002FE38: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_4;
    // 0x8002FE38: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_4:
    // 0x8002FE3C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8002FE40: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8002FE44: div.d       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f20.d, ctx->f6.d);
    // 0x8002FE48: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8002FE4C: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x8002FE50: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8002FE54: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8002FE58: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8002FE5C: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x8002FE60: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8002FE64: add.s       $f4, $f10, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x8002FE68: swc1        $f8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f8.u32l;
    // 0x8002FE6C: add.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x8002FE70: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002FE74: swc1        $f6, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f6.u32l;
    // 0x8002FE78: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x8002FE7C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002FE80: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8002FE84: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x8002FE88: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8002FE8C: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8002FE90: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8002FE94: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8002FE98: jal         0x8002FC20
    // 0x8002FE9C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_5;
    // 0x8002FE9C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_5:
    // 0x8002FEA0: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002FEA4: ldc1        $f4, -0x2B90($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2B90);
    // 0x8002FEA8: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8002FEAC: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
    // 0x8002FEB0: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x8002FEB4: lw          $v0, 0xE0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE0);
    // 0x8002FEB8: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x8002FEBC: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    // 0x8002FEC0: bc1fl       L_8002FFAC
    if (!c1cs) {
        // 0x8002FEC4: sll         $t3, $v0, 1
        ctx->r11 = S32(ctx->r2 << 1);
            goto L_8002FFAC;
    }
    goto skip_0;
    // 0x8002FEC4: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    skip_0:
    // 0x8002FEC8: div.d       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = DIV_D(ctx->f20.d, ctx->f2.d);
    // 0x8002FECC: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8002FED0: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8002FED4: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002FED8: lw          $v0, 0xE0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE0);
    // 0x8002FEDC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002FEE0: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x8002FEE4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8002FEE8: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
    // 0x8002FEEC: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x8002FEF0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x8002FEF4: mul.s       $f14, $f10, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8002FEF8: nop

    // 0x8002FEFC: mul.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8002FF00: nop

    // 0x8002FF04: mul.s       $f18, $f4, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8002FF08: nop

    // 0x8002FF0C: mul.s       $f6, $f14, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x8002FF10: nop

    // 0x8002FF14: mul.s       $f10, $f16, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x8002FF18: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8002FF1C: mul.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x8002FF20: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8002FF24: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8002FF28: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002FF2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002FF30: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8002FF34: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8002FF38: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8002FF3C: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002FF40: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002FF44: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8002FF48: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8002FF4C: nop

    // 0x8002FF50: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8002FF54: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002FF58: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8002FF5C: mul.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8002FF60: nop

    // 0x8002FF64: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8002FF68: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8002FF6C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002FF70: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8002FF74: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8002FF78: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002FF7C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002FF80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002FF84: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8002FF88: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8002FF8C: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8002FF90: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002FF94: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002FF98: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8002FF9C: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8002FFA0: b           L_8002FFB4
    // 0x8002FFA4: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
        goto L_8002FFB4;
    // 0x8002FFA4: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x8002FFA8: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
L_8002FFAC:
    // 0x8002FFAC: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8002FFB0: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
L_8002FFB4:
    // 0x8002FFB4: lwc1        $f0, 0xD4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8002FFB8: lwc1        $f2, 0xD8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8002FFBC: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8002FFC0: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8002FFC4: nop

    // 0x8002FFC8: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8002FFCC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002FFD0: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8002FFD4: jal         0x8002FC20
    // 0x8002FFD8: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_6;
    // 0x8002FFD8: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_6:
    // 0x8002FFDC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8002FFE0: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8002FFE4: div.d       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f20.d, ctx->f6.d);
    // 0x8002FFE8: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8002FFEC: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x8002FFF0: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8002FFF4: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8002FFF8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8002FFFC: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
    // 0x80030000: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80030004: add.s       $f10, $f4, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f28.fl;
    // 0x80030008: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    // 0x8003000C: add.s       $f4, $f8, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x80030010: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80030014: swc1        $f6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f6.u32l;
    // 0x80030018: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x8003001C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80030020: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80030024: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x80030028: mul.s       $f10, $f4, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8003002C: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x80030030: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80030034: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80030038: jal         0x8002FC20
    // 0x8003003C: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_7;
    // 0x8003003C: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_7:
    // 0x80030040: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80030044: ldc1        $f10, -0x2B88($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2B88);
    // 0x80030048: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8003004C: lw          $v0, 0xE0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE0);
    // 0x80030050: c.lt.d      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.d < ctx->f2.d;
    // 0x80030054: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
    // 0x80030058: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8003005C: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x80030060: bc1f        L_80030140
    if (!c1cs) {
        // 0x80030064: sll         $t3, $v1, 1
        ctx->r11 = S32(ctx->r3 << 1);
            goto L_80030140;
    }
    // 0x80030064: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x80030068: div.d       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = DIV_D(ctx->f20.d, ctx->f2.d);
    // 0x8003006C: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80030070: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80030074: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80030078: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003007C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80030080: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80030084: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80030088: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x8003008C: mul.s       $f14, $f4, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80030090: nop

    // 0x80030094: mul.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80030098: nop

    // 0x8003009C: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800300A0: nop

    // 0x800300A4: mul.s       $f6, $f14, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x800300A8: nop

    // 0x800300AC: mul.s       $f4, $f16, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x800300B0: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800300B4: mul.s       $f10, $f18, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x800300B8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800300BC: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800300C0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800300C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800300C8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800300CC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800300D0: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800300D4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800300D8: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800300DC: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800300E0: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800300E4: nop

    // 0x800300E8: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800300EC: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800300F0: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800300F4: mul.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800300F8: nop

    // 0x800300FC: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80030100: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80030104: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80030108: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003010C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80030110: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80030114: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80030118: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003011C: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80030120: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80030124: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80030128: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8003012C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80030130: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80030134: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80030138: b           L_80030148
    // 0x8003013C: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
        goto L_80030148;
    // 0x8003013C: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
L_80030140:
    // 0x80030140: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x80030144: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
L_80030148:
    // 0x80030148: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8003014C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80030150: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80030154: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80030158: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8003015C: mul.s       $f12, $f22, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x80030160: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80030164: nop

    // 0x80030168: bc1fl       L_8003017C
    if (!c1cs) {
        // 0x8003016C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8003017C;
    }
    goto skip_1;
    // 0x8003016C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_1:
    // 0x80030170: b           L_8003017C
    // 0x80030174: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_8003017C;
    // 0x80030174: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80030178: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8003017C:
    // 0x8003017C: mul.s       $f12, $f24, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f24.fl, ctx->f14.fl);
    // 0x80030180: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80030184: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80030188: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8003018C: bc1f        L_8003019C
    if (!c1cs) {
        // 0x80030190: sb          $t6, 0x8($s0)
        MEM_B(0X8, ctx->r16) = ctx->r14;
            goto L_8003019C;
    }
    // 0x80030190: sb          $t6, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r14;
    // 0x80030194: b           L_800301A0
    // 0x80030198: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800301A0;
    // 0x80030198: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8003019C:
    // 0x8003019C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800301A0:
    // 0x800301A0: mul.s       $f12, $f26, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f26.fl, ctx->f14.fl);
    // 0x800301A4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800301A8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800301AC: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800301B0: bc1f        L_800301C0
    if (!c1cs) {
        // 0x800301B4: sb          $t0, 0x9($s0)
        MEM_B(0X9, ctx->r16) = ctx->r8;
            goto L_800301C0;
    }
    // 0x800301B4: sb          $t0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r8;
    // 0x800301B8: b           L_800301C4
    // 0x800301BC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800301C4;
    // 0x800301BC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800301C0:
    // 0x800301C0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800301C4:
    // 0x800301C4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800301C8: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800301CC: nop

    // 0x800301D0: sb          $t9, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r25;
    // 0x800301D4: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800301D8: mul.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800301DC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800301E0: nop

    // 0x800301E4: bc1fl       L_800301F8
    if (!c1cs) {
        // 0x800301E8: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800301F8;
    }
    goto skip_2;
    // 0x800301E8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_2:
    // 0x800301EC: b           L_800301F8
    // 0x800301F0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800301F8;
    // 0x800301F0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800301F4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800301F8:
    // 0x800301F8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800301FC: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80030200: nop

    // 0x80030204: sb          $t4, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r12;
    // 0x80030208: lwc1        $f8, 0xC0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8003020C: mul.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80030210: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80030214: nop

    // 0x80030218: bc1fl       L_8003022C
    if (!c1cs) {
        // 0x8003021C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8003022C;
    }
    goto skip_3;
    // 0x8003021C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_3:
    // 0x80030220: b           L_8003022C
    // 0x80030224: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_8003022C;
    // 0x80030224: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80030228: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8003022C:
    // 0x8003022C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80030230: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80030234: nop

    // 0x80030238: sb          $t8, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r24;
    // 0x8003023C: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80030240: mul.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80030244: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80030248: nop

    // 0x8003024C: bc1fl       L_80030260
    if (!c1cs) {
        // 0x80030250: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80030260;
    }
    goto skip_4;
    // 0x80030250: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_4:
    // 0x80030254: b           L_80030260
    // 0x80030258: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80030260;
    // 0x80030258: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8003025C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80030260:
    // 0x80030260: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80030264: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80030268: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x8003026C: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x80030270: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80030274: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x80030278: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x8003027C: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x80030280: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    // 0x80030284: sb          $zero, 0x7($s0)
    MEM_B(0X7, ctx->r16) = 0;
    // 0x80030288: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x8003028C: sb          $v0, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r2;
    // 0x80030290: sb          $zero, 0x12($s0)
    MEM_B(0X12, ctx->r16) = 0;
    // 0x80030294: sb          $zero, 0x13($s0)
    MEM_B(0X13, ctx->r16) = 0;
    // 0x80030298: sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    // 0x8003029C: sb          $v0, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r2;
    // 0x800302A0: sb          $zero, 0x16($s0)
    MEM_B(0X16, ctx->r16) = 0;
    // 0x800302A4: sb          $zero, 0x17($s0)
    MEM_B(0X17, ctx->r16) = 0;
    // 0x800302A8: sb          $t2, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = ctx->r10;
    // 0x800302AC: swc1        $f22, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f22.u32l;
    // 0x800302B0: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800302B4: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800302B8: lwc1        $f14, 0xAC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800302BC: mul.s       $f8, $f18, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800302C0: lwc1        $f0, 0xBC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800302C4: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800302C8: mul.s       $f4, $f16, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x800302CC: lwc1        $f2, 0xC4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800302D0: swc1        $f24, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f24.u32l;
    // 0x800302D4: mul.s       $f6, $f14, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f26.fl);
    // 0x800302D8: swc1        $f26, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f26.u32l;
    // 0x800302DC: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x800302E0: swc1        $f12, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f12.u32l;
    // 0x800302E4: swc1        $f2, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f2.u32l;
    // 0x800302E8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800302EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800302F0: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800302F4: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800302F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800302FC: mul.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80030300: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x80030304: swc1        $f4, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f4.u32l;
    // 0x80030308: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8003030C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80030310: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80030314: mul.s       $f8, $f18, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x80030318: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x8003031C: mul.s       $f4, $f16, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x80030320: swc1        $f6, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f6.u32l;
    // 0x80030324: lwc1        $f2, 0x88($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80030328: swc1        $f28, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f28.u32l;
    // 0x8003032C: swc1        $f30, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f30.u32l;
    // 0x80030330: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80030334: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x80030338: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8003033C: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x80030340: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x80030344: swc1        $f2, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f2.u32l;
    // 0x80030348: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8003034C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80030350: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x80030354: swc1        $f10, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f10.u32l;
    // 0x80030358: swc1        $f4, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f4.u32l;
    // 0x8003035C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80030360: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80030364: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80030368: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8003036C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80030370: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80030374: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80030378: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8003037C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80030380: jr          $ra
    // 0x80030384: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80030384: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80030388(rdram, ctx);
;}
RECOMP_FUNC void FUN_80030388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030388: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8003038C: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80030390: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80030394: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80030398: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8003039C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800303A0: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800303A4: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800303A8: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800303AC: lwc1        $f16, 0xB8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800303B0: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800303B4: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800303B8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800303BC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800303C0: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800303C4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800303C8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x800303CC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x800303D0: lwc1        $f18, 0xD4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800303D4: lwc1        $f16, 0xD0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800303D8: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800303DC: lwc1        $f4, 0xD8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800303E0: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800303E4: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800303E8: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x800303EC: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x800303F0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800303F4: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x800303F8: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800303FC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80030400: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80030404: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x80030408: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8003040C: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x80030410: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80030414: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80030418: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x8003041C: jal         0x8002FC50
    // 0x80030420: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8002FC50)(rdram, ctx);
        goto after_0;
    // 0x80030420: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80030424: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80030428: jal         0x80029D30
    // 0x8003042C: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    LOOKUP_FUNC(0x80029D30)(rdram, ctx);
        goto after_1;
    // 0x8003042C: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    after_1:
    // 0x80030430: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80030434: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x80030438: jr          $ra
    // 0x8003043C: nop

    return;
    // 0x8003043C: nop

;}
RECOMP_FUNC void osSyncPrintf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030440: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80030444: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x80030448: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8003044C: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x80030450: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x80030454: jr          $ra
    // 0x80030458: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80030458: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void FUN_8003045c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003045C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80030460: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x80030464: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x80030468: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8003046C: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x80030470: jr          $ra
    // 0x80030474: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80030474: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80030478: nop

    // 0x8003047C: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80030480(rdram, ctx);
;}
RECOMP_FUNC void FUN_80030480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030480: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80030484: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80030488: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x8003048C: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x80030490: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x80030494: jr          $ra
    // 0x80030498: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
    return;
    // 0x80030498: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
    // 0x8003049C: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800304a0(rdram, ctx);
;}
RECOMP_FUNC void FUN_800304a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800304A0: mfc0        $t0, EntryHi
    ctx->r8 = cop0_register_read(ctx, 10);
    // 0x800304A4: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x800304A8: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800304AC: mtc0        $t2, EntryHi
    cop0_register_write(ctx, 10, ctx->r10);    // 0x800304B0: mtc0        $zero, EntryLo0
    cop0_register_write(ctx, 2, 0);    // 0x800304B4: mtc0        $zero, EntryLo1
    cop0_register_write(ctx, 3, 0);L_800304B8:
    // 0x800304B8: mtc0        $t1, Index
    cop0_register_write(ctx, 0, ctx->r9);    // 0x800304BC: nop

    // 0x800304C0: tlbwi

    // 0x800304C4: nop

    // 0x800304C8: nop

    // 0x800304CC: addi        $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800304D0: bgez        $t1, L_800304B8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800304D4: nop
    
            goto L_800304B8;
    }
    // 0x800304D4: nop

    // 0x800304D8: mtc0        $t0, EntryHi
    cop0_register_write(ctx, 10, ctx->r8);    // 0x800304DC: jr          $ra
    // 0x800304E0: nop

    return;
    // 0x800304E0: nop

    // 0x800304E4: nop

    // 0x800304E8: nop

    // 0x800304EC: nop

;}
RECOMP_FUNC void FUN_800305d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800305D0: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x800305D4: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x800305D8: subu        $v0, $v1, $t6
    ctx->r2 = SUB32(ctx->r3, ctx->r14);
    // 0x800305DC: beq         $v1, $v0, L_800305EC
    if (ctx->r3 == ctx->r2) {
        // 0x800305E0: addu        $t7, $a1, $v0
        ctx->r15 = ADD32(ctx->r5, ctx->r2);
            goto L_800305EC;
    }
    // 0x800305E0: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x800305E4: b           L_800305F0
    // 0x800305E8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_800305F0;
    // 0x800305E8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_800305EC:
    // 0x800305EC: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_800305F0:
    // 0x800305F0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800305F4: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x800305F8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800305FC: jr          $ra
    // 0x80030600: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    return;
    // 0x80030600: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80030604: nop

    // 0x80030608: nop

    // 0x8003060C: nop

;}
RECOMP_FUNC void FUN_80030640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030640: blez        $a1, L_80030688
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80030644: nop
    
            goto L_80030688;
    }
    // 0x80030644: nop

    // 0x80030648: addiu       $t3, $zero, 0x4000
    ctx->r11 = ADD32(0, 0X4000);
    // 0x8003064C: sltu        $at, $a1, $t3
    ctx->r1 = ctx->r5 < ctx->r11 ? 1 : 0;
    // 0x80030650: beq         $at, $zero, L_80030690
    if (ctx->r1 == 0) {
        // 0x80030654: nop
    
            goto L_80030690;
    }
    // 0x80030654: nop

    // 0x80030658: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8003065C: addu        $t1, $a0, $a1
    ctx->r9 = ADD32(ctx->r4, ctx->r5);
    // 0x80030660: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x80030664: beq         $at, $zero, L_80030688
    if (ctx->r1 == 0) {
        // 0x80030668: nop
    
            goto L_80030688;
    }
    // 0x80030668: nop

    // 0x8003066C: andi        $t2, $t0, 0x1F
    ctx->r10 = ctx->r8 & 0X1F;
    // 0x80030670: addiu       $t1, $t1, -0x20
    ctx->r9 = ADD32(ctx->r9, -0X20);
    // 0x80030674: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
L_80030678:
    // 0x80030678: cache       0x10, 0x0($t0)

    // 0x8003067C: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x80030680: bne         $at, $zero, L_80030678
    if (ctx->r1 != 0) {
        // 0x80030684: addiu       $t0, $t0, 0x20
        ctx->r8 = ADD32(ctx->r8, 0X20);
            goto L_80030678;
    }
    // 0x80030684: addiu       $t0, $t0, 0x20
    ctx->r8 = ADD32(ctx->r8, 0X20);
L_80030688:
    // 0x80030688: jr          $ra
    // 0x8003068C: nop

    return;
    // 0x8003068C: nop

L_80030690:
    // 0x80030690: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80030694: addu        $t1, $t0, $t3
    ctx->r9 = ADD32(ctx->r8, ctx->r11);
    // 0x80030698: addiu       $t1, $t1, -0x20
    ctx->r9 = ADD32(ctx->r9, -0X20);
L_8003069C:
    // 0x8003069C: cache       0x00, 0x0($t0)

    // 0x800306A0: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x800306A4: bne         $at, $zero, L_8003069C
    if (ctx->r1 != 0) {
        // 0x800306A8: addiu       $t0, $t0, 0x20
        ctx->r8 = ADD32(ctx->r8, 0X20);
            goto L_8003069C;
    }
    // 0x800306A8: addiu       $t0, $t0, 0x20
    ctx->r8 = ADD32(ctx->r8, 0X20);
    // 0x800306AC: jr          $ra
    // 0x800306B0: nop

    return;
    // 0x800306B0: nop

    // 0x800306B4: nop

    // 0x800306B8: nop

    // 0x800306BC: nop

;}
RECOMP_FUNC void FUN_800306c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800306C0: blez        $a1, L_80030740
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800306C4: nop
    
            goto L_80030740;
    }
    // 0x800306C4: nop

    // 0x800306C8: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x800306CC: sltu        $at, $a1, $t3
    ctx->r1 = ctx->r5 < ctx->r11 ? 1 : 0;
    // 0x800306D0: beq         $at, $zero, L_80030748
    if (ctx->r1 == 0) {
        // 0x800306D4: nop
    
            goto L_80030748;
    }
    // 0x800306D4: nop

    // 0x800306D8: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800306DC: addu        $t1, $a0, $a1
    ctx->r9 = ADD32(ctx->r4, ctx->r5);
    // 0x800306E0: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x800306E4: beq         $at, $zero, L_80030740
    if (ctx->r1 == 0) {
        // 0x800306E8: nop
    
            goto L_80030740;
    }
    // 0x800306E8: nop

    // 0x800306EC: andi        $t2, $t0, 0xF
    ctx->r10 = ctx->r8 & 0XF;
    // 0x800306F0: beq         $t2, $zero, L_80030710
    if (ctx->r10 == 0) {
        // 0x800306F4: addiu       $t1, $t1, -0x10
        ctx->r9 = ADD32(ctx->r9, -0X10);
            goto L_80030710;
    }
    // 0x800306F4: addiu       $t1, $t1, -0x10
    ctx->r9 = ADD32(ctx->r9, -0X10);
    // 0x800306F8: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x800306FC: cache       0x15, 0x0($t0)

    // 0x80030700: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x80030704: beq         $at, $zero, L_80030740
    if (ctx->r1 == 0) {
        // 0x80030708: nop
    
            goto L_80030740;
    }
    // 0x80030708: nop

    // 0x8003070C: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_80030710:
    // 0x80030710: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x80030714: beq         $t2, $zero, L_80030730
    if (ctx->r10 == 0) {
        // 0x80030718: nop
    
            goto L_80030730;
    }
    // 0x80030718: nop

    // 0x8003071C: subu        $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // 0x80030720: cache       0x15, 0x10($t1)

    // 0x80030724: sltu        $at, $t1, $t0
    ctx->r1 = ctx->r9 < ctx->r8 ? 1 : 0;
    // 0x80030728: bne         $at, $zero, L_80030740
    if (ctx->r1 != 0) {
        // 0x8003072C: nop
    
            goto L_80030740;
    }
    // 0x8003072C: nop

L_80030730:
    // 0x80030730: cache       0x11, 0x0($t0)

    // 0x80030734: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x80030738: bne         $at, $zero, L_80030730
    if (ctx->r1 != 0) {
        // 0x8003073C: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_80030730;
    }
    // 0x8003073C: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_80030740:
    // 0x80030740: jr          $ra
    // 0x80030744: nop

    return;
    // 0x80030744: nop

L_80030748:
    // 0x80030748: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8003074C: addu        $t1, $t0, $t3
    ctx->r9 = ADD32(ctx->r8, ctx->r11);
    // 0x80030750: addiu       $t1, $t1, -0x10
    ctx->r9 = ADD32(ctx->r9, -0X10);
L_80030754:
    // 0x80030754: cache       0x01, 0x0($t0)

    // 0x80030758: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x8003075C: bne         $at, $zero, L_80030754
    if (ctx->r1 != 0) {
        // 0x80030760: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_80030754;
    }
    // 0x80030760: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80030764: jr          $ra
    // 0x80030768: nop

    return;
    // 0x80030768: nop

    // 0x8003076C: nop

;}
RECOMP_FUNC void FUN_80030770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030778: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003077C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80030780: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80030784: beql        $t6, $zero, L_800307F8
    if (ctx->r14 == 0) {
        // 0x80030788: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800307F8;
    }
    goto skip_0;
    // 0x80030788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8003078C: jal         0x8002C6A0
    // 0x80030790: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8002C6A0)(rdram, ctx);
        goto after_0;
    // 0x80030790: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80030794: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x80030798: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8003079C: beq         $v0, $zero, L_800307F4
    if (ctx->r2 == 0) {
        // 0x800307A0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800307F4;
    }
    // 0x800307A0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800307A4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800307A8: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800307AC: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800307B0: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800307B4: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800307B8: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x800307BC: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800307C0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800307C4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800307C8: bne         $at, $zero, L_800307D4
    if (ctx->r1 != 0) {
        // 0x800307CC: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800307D4;
    }
    // 0x800307CC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800307D0: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_800307D4:
    // 0x800307D4: sw          $v1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r3;
    // 0x800307D8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800307DC: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800307E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800307E4: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800307E8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800307EC: jalr        $t9
    // 0x800307F0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800307F0: nop

    after_1:
L_800307F4:
    // 0x800307F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800307F8:
    // 0x800307F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800307FC: jr          $ra
    // 0x80030800: nop

    return;
    // 0x80030800: nop

    // 0x80030804: nop

    // 0x80030808: nop

    // 0x8003080C: nop

;}
RECOMP_FUNC void FUN_80030810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030810: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80030814: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80030818: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003081C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80030820: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80030824: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80030828: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003082C: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80030830: jalr        $t9
    // 0x80030834: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80030834: nop

    after_0:
    // 0x80030838: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8003083C: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x80030840: lui         $t2, 0x440
    ctx->r10 = S32(0X440 << 16);
    // 0x80030844: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x80030848: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x8003084C: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x80030850: ori         $t2, $t2, 0x580
    ctx->r10 = ctx->r10 | 0X580;
    // 0x80030854: lui         $t1, 0xD00
    ctx->r9 = S32(0XD00 << 16);
    // 0x80030858: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8003085C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80030860: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80030864: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80030868: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x8003086C: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x80030870: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x80030874: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80030878: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x8003087C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80030880: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80030884: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80030888: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x8003088C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80030890: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80030894: jr          $ra
    // 0x80030898: nop

    return;
    // 0x80030898: nop

;}
RECOMP_FUNC void FUN_8003089c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003089C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800308A0: beq         $a1, $at, L_800308BC
    if (ctx->r5 == ctx->r1) {
        // 0x800308A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800308BC;
    }
    // 0x800308A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800308A8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800308AC: beql        $a1, $at, L_800308C8
    if (ctx->r5 == ctx->r1) {
        // 0x800308B0: sw          $a2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r6;
            goto L_800308C8;
    }
    goto skip_0;
    // 0x800308B0: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800308B4: jr          $ra
    // 0x800308B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800308B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800308BC:
    // 0x800308BC: jr          $ra
    // 0x800308C0: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    return;
    // 0x800308C0: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x800308C4: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
L_800308C8:
    // 0x800308C8: jr          $ra
    // 0x800308CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800308CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void FUN_80030930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030930: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80030934: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80030938: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x8003093C: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80030940: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80030944: lw          $v1, 0x1C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C);
    // 0x80030948: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8003094C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80030950: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80030954: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80030958: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
    // 0x8003095C: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80030960: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80030964: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80030968: bne         $t1, $at, L_800309A0
    if (ctx->r9 != ctx->r1) {
        // 0x8003096C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800309A0;
    }
    // 0x8003096C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030970: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80030974: lw          $t2, 0x34($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X34);
    // 0x80030978: subu        $t5, $t5, $t9
    ctx->r13 = SUB32(ctx->r13, ctx->r25);
    // 0x8003097C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80030980: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x80030984: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80030988: subu        $t5, $t5, $t9
    ctx->r13 = SUB32(ctx->r13, ctx->r25);
    // 0x8003098C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80030990: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80030994: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80030998: jr          $ra
    // 0x8003099C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    return;
    // 0x8003099C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_800309A0:
    // 0x800309A0: jr          $ra
    // 0x800309A4: nop

    return;
    // 0x800309A4: nop

    // 0x800309A8: nop

    // 0x800309AC: nop

;}
RECOMP_FUNC void FUN_800309b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800309B0: lui         $t6, 0xA404
    ctx->r14 = S32(0XA404 << 16);
    // 0x800309B4: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    // 0x800309B8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800309BC: andi        $t7, $a0, 0x1C
    ctx->r15 = ctx->r4 & 0X1C;
    // 0x800309C0: beq         $t7, $zero, L_800309D0
    if (ctx->r15 == 0) {
        // 0x800309C4: nop
    
            goto L_800309D0;
    }
    // 0x800309C4: nop

    // 0x800309C8: b           L_800309D4
    // 0x800309CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800309D4;
    // 0x800309CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800309D0:
    // 0x800309D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800309D4:
    // 0x800309D4: jr          $ra
    // 0x800309D8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800309D8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800309DC: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800309e0(rdram, ctx);
;}
RECOMP_FUNC void FUN_800309e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800309E0: lui         $t6, 0xA480
    ctx->r14 = S32(0XA480 << 16);
    // 0x800309E4: lw          $a0, 0x18($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X18);
    // 0x800309E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800309EC: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x800309F0: beq         $t7, $zero, L_80030A00
    if (ctx->r15 == 0) {
        // 0x800309F4: nop
    
            goto L_80030A00;
    }
    // 0x800309F4: nop

    // 0x800309F8: b           L_80030A04
    // 0x800309FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80030A04;
    // 0x800309FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80030A00:
    // 0x80030A00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80030A04:
    // 0x80030A04: jr          $ra
    // 0x80030A08: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80030A08: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80030A0C: nop

;}
RECOMP_FUNC void FUN_80030c60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030C60: lui         $v1, 0xA460
    ctx->r3 = S32(0XA460 << 16);
    // 0x80030C64: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x80030C68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030C6C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80030C70: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x80030C74: beql        $t6, $zero, L_80030C90
    if (ctx->r14 == 0) {
        // 0x80030C78: lbu         $v0, 0x9($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X9);
            goto L_80030C90;
    }
    goto skip_0;
    // 0x80030C78: lbu         $v0, 0x9($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9);
    skip_0:
    // 0x80030C7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80030C80:
    // 0x80030C80: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x80030C84: bnel        $t7, $zero, L_80030C80
    if (ctx->r15 != 0) {
        // 0x80030C88: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_80030C80;
    }
    goto skip_1;
    // 0x80030C88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x80030C8C: lbu         $v0, 0x9($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9);
L_80030C90:
    // 0x80030C90: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x80030C94: lbu         $t9, 0x4($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X4);
    // 0x80030C98: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80030C9C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80030CA0: lw          $v1, -0x54D0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X54D0);
    // 0x80030CA4: lbu         $t0, 0x4($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X4);
    // 0x80030CA8: beql        $t9, $t0, L_80030DA0
    if (ctx->r25 == ctx->r8) {
        // 0x80030CAC: lw          $t2, 0xC($a0)
        ctx->r10 = MEM_W(ctx->r4, 0XC);
            goto L_80030DA0;
    }
    goto skip_2;
    // 0x80030CAC: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    skip_2:
    // 0x80030CB0: bne         $v0, $zero, L_80030D18
    if (ctx->r2 != 0) {
        // 0x80030CB4: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80030D18;
    }
    // 0x80030CB4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80030CB8: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x80030CBC: lbu         $t1, 0x5($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X5);
    // 0x80030CC0: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x80030CC4: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x80030CC8: beq         $v0, $t1, L_80030CD4
    if (ctx->r2 == ctx->r9) {
        // 0x80030CCC: lui         $t6, 0xA460
        ctx->r14 = S32(0XA460 << 16);
            goto L_80030CD4;
    }
    // 0x80030CCC: lui         $t6, 0xA460
    ctx->r14 = S32(0XA460 << 16);
    // 0x80030CD0: sw          $v0, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r2;
L_80030CD4:
    // 0x80030CD4: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    // 0x80030CD8: lbu         $t3, 0x6($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X6);
    // 0x80030CDC: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x80030CE0: beql        $v0, $t3, L_80030CF0
    if (ctx->r2 == ctx->r11) {
        // 0x80030CE4: lbu         $v0, 0x7($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X7);
            goto L_80030CF0;
    }
    goto skip_3;
    // 0x80030CE4: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
    skip_3:
    // 0x80030CE8: sw          $v0, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r2;
    // 0x80030CEC: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
L_80030CF0:
    // 0x80030CF0: lbu         $t5, 0x7($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X7);
    // 0x80030CF4: beql        $v0, $t5, L_80030D04
    if (ctx->r2 == ctx->r13) {
        // 0x80030CF8: lbu         $v0, 0x8($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X8);
            goto L_80030D04;
    }
    goto skip_4;
    // 0x80030CF8: lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8);
    skip_4:
    // 0x80030CFC: sw          $v0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r2;
    // 0x80030D00: lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8);
L_80030D04:
    // 0x80030D04: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x80030D08: beql        $v0, $t7, L_80030D78
    if (ctx->r2 == ctx->r15) {
        // 0x80030D0C: lbu         $t7, 0x4($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X4);
            goto L_80030D78;
    }
    goto skip_5;
    // 0x80030D0C: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    skip_5:
    // 0x80030D10: b           L_80030D74
    // 0x80030D14: sw          $v0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r2;
        goto L_80030D74;
    // 0x80030D14: sw          $v0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r2;
L_80030D18:
    // 0x80030D18: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x80030D1C: lbu         $t9, 0x5($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X5);
    // 0x80030D20: lui         $t0, 0xA460
    ctx->r8 = S32(0XA460 << 16);
    // 0x80030D24: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x80030D28: beq         $v0, $t9, L_80030D34
    if (ctx->r2 == ctx->r25) {
        // 0x80030D2C: lui         $t4, 0xA460
        ctx->r12 = S32(0XA460 << 16);
            goto L_80030D34;
    }
    // 0x80030D2C: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x80030D30: sw          $v0, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r2;
L_80030D34:
    // 0x80030D34: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    // 0x80030D38: lbu         $t1, 0x6($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X6);
    // 0x80030D3C: lui         $t6, 0xA460
    ctx->r14 = S32(0XA460 << 16);
    // 0x80030D40: beql        $v0, $t1, L_80030D50
    if (ctx->r2 == ctx->r9) {
        // 0x80030D44: lbu         $v0, 0x7($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X7);
            goto L_80030D50;
    }
    goto skip_6;
    // 0x80030D44: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
    skip_6:
    // 0x80030D48: sw          $v0, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r2;
    // 0x80030D4C: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
L_80030D50:
    // 0x80030D50: lbu         $t3, 0x7($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X7);
    // 0x80030D54: beql        $v0, $t3, L_80030D64
    if (ctx->r2 == ctx->r11) {
        // 0x80030D58: lbu         $v0, 0x8($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X8);
            goto L_80030D64;
    }
    goto skip_7;
    // 0x80030D58: lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8);
    skip_7:
    // 0x80030D5C: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
    // 0x80030D60: lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8);
L_80030D64:
    // 0x80030D64: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x80030D68: beql        $v0, $t5, L_80030D78
    if (ctx->r2 == ctx->r13) {
        // 0x80030D6C: lbu         $t7, 0x4($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X4);
            goto L_80030D78;
    }
    goto skip_8;
    // 0x80030D6C: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    skip_8:
    // 0x80030D70: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
L_80030D74:
    // 0x80030D74: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
L_80030D78:
    // 0x80030D78: sb          $t7, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r15;
    // 0x80030D7C: lbu         $t8, 0x5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X5);
    // 0x80030D80: sb          $t8, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r24;
    // 0x80030D84: lbu         $t9, 0x6($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X6);
    // 0x80030D88: sb          $t9, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r25;
    // 0x80030D8C: lbu         $t0, 0x7($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X7);
    // 0x80030D90: sb          $t0, 0x7($a1)
    MEM_B(0X7, ctx->r5) = ctx->r8;
    // 0x80030D94: lbu         $t1, 0x8($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X8);
    // 0x80030D98: sb          $t1, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r9;
    // 0x80030D9C: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
L_80030DA0:
    // 0x80030DA0: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x80030DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030DA8: or          $t3, $t2, $a3
    ctx->r11 = ctx->r10 | ctx->r7;
    // 0x80030DAC: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80030DB0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80030DB4: jr          $ra
    // 0x80030DB8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    return;
    // 0x80030DB8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80030DBC: nop

;}
RECOMP_FUNC void osViSwapBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030DC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80030DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030DC8: jal         0x80032660
    // 0x80030DCC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80032660)(rdram, ctx);
        goto after_0;
    // 0x80030DCC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80030DD0: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80030DD4: lw          $t7, -0x512C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X512C);
    // 0x80030DD8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80030DDC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80030DE0: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80030DE4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80030DE8: lw          $t8, -0x512C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X512C);
    // 0x80030DEC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80030DF0: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80030DF4: sh          $t0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r8;
    // 0x80030DF8: jal         0x800326D0
    // 0x80030DFC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x800326D0)(rdram, ctx);
        goto after_1;
    // 0x80030DFC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80030E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030E04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80030E08: jr          $ra
    // 0x80030E0C: nop

    return;
    // 0x80030E0C: nop

;}
RECOMP_FUNC void FUN_80031070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031070: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80031074: bne         $at, $zero, L_80031154
    if (ctx->r1 != 0) {
        // 0x80031078: xor         $v0, $a0, $a1
        ctx->r2 = ctx->r4 ^ ctx->r5;
            goto L_80031154;
    }
    // 0x80031078: xor         $v0, $a0, $a1
    ctx->r2 = ctx->r4 ^ ctx->r5;
    // 0x8003107C: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80031080: bne         $v0, $zero, L_800310E8
    if (ctx->r2 != 0) {
        // 0x80031084: negu        $t8, $a0
        ctx->r24 = SUB32(0, ctx->r4);
            goto L_800310E8;
    }
    // 0x80031084: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x80031088: andi        $t8, $t8, 0x3
    ctx->r24 = ctx->r24 & 0X3;
    // 0x8003108C: beq         $t8, $zero, L_800310AC
    if (ctx->r24 == 0) {
        // 0x80031090: subu        $a2, $a2, $t8
        ctx->r6 = SUB32(ctx->r6, ctx->r24);
            goto L_800310AC;
    }
    // 0x80031090: subu        $a2, $a2, $t8
    ctx->r6 = SUB32(ctx->r6, ctx->r24);
    // 0x80031094: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80031098: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    // 0x8003109C: lwl         $v1, 0x0($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0X0);
    // 0x800310A0: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800310A4: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x800310A8: bne         $v0, $v1, L_80031184
    if (ctx->r2 != ctx->r3) {
        // 0x800310AC: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_80031184;
    }
L_800310AC:
    // 0x800310AC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800310B0: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x800310B4: beq         $a3, $zero, L_80031154
    if (ctx->r7 == 0) {
        // 0x800310B8: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_80031154;
    }
    // 0x800310B8: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800310BC: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x800310C0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800310C4:
    // 0x800310C4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800310C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800310CC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800310D0: bne         $v0, $v1, L_80031184
    if (ctx->r2 != ctx->r3) {
        // 0x800310D4: nop
    
            goto L_80031184;
    }
    // 0x800310D4: nop

    // 0x800310D8: bnel        $a0, $a3, L_800310C4
    if (ctx->r4 != ctx->r7) {
        // 0x800310DC: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_800310C4;
    }
    goto skip_0;
    // 0x800310DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800310E0: b           L_80031154
    // 0x800310E4: nop

        goto L_80031154;
    // 0x800310E4: nop

L_800310E8:
    // 0x800310E8: negu        $a3, $a1
    ctx->r7 = SUB32(0, ctx->r5);
    // 0x800310EC: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x800310F0: beq         $a3, $zero, L_8003111C
    if (ctx->r7 == 0) {
        // 0x800310F4: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8003111C;
    }
    // 0x800310F4: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800310F8: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x800310FC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_80031100:
    // 0x80031100: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80031104: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80031108: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8003110C: bne         $v0, $v1, L_80031184
    if (ctx->r2 != ctx->r3) {
        // 0x80031110: nop
    
            goto L_80031184;
    }
    // 0x80031110: nop

    // 0x80031114: bnel        $a0, $a3, L_80031100
    if (ctx->r4 != ctx->r7) {
        // 0x80031118: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_80031100;
    }
    goto skip_1;
    // 0x80031118: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_8003111C:
    // 0x8003111C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80031120: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x80031124: beq         $a3, $zero, L_80031154
    if (ctx->r7 == 0) {
        // 0x80031128: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_80031154;
    }
    // 0x80031128: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8003112C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x80031130: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
L_80031134:
    // 0x80031134: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80031138: lwr         $v0, 0x3($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r4, 0X3);
    // 0x8003113C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80031140: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80031144: bne         $v0, $v1, L_80031184
    if (ctx->r2 != ctx->r3) {
        // 0x80031148: nop
    
            goto L_80031184;
    }
    // 0x80031148: nop

    // 0x8003114C: bnel        $a0, $a3, L_80031134
    if (ctx->r4 != ctx->r7) {
        // 0x80031150: lwl         $v0, 0x0($a0)
        ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
            goto L_80031134;
    }
    goto skip_2;
    // 0x80031150: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    skip_2:
L_80031154:
    // 0x80031154: blez        $a2, L_8003117C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80031158: addu        $a3, $a2, $a0
        ctx->r7 = ADD32(ctx->r6, ctx->r4);
            goto L_8003117C;
    }
    // 0x80031158: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
    // 0x8003115C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_80031160:
    // 0x80031160: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80031164: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80031168: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8003116C: bne         $v0, $v1, L_80031184
    if (ctx->r2 != ctx->r3) {
        // 0x80031170: nop
    
            goto L_80031184;
    }
    // 0x80031170: nop

    // 0x80031174: bnel        $a0, $a3, L_80031160
    if (ctx->r4 != ctx->r7) {
        // 0x80031178: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_80031160;
    }
    goto skip_3;
    // 0x80031178: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_3:
L_8003117C:
    // 0x8003117C: jr          $ra
    // 0x80031180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80031180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80031184:
    // 0x80031184: jr          $ra
    // 0x80031188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80031188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003118C: nop

;}
RECOMP_FUNC void FUN_80031220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031220: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80031224: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x80031228: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8003122C: sw          $t7, -0x296C($at)
    MEM_W(-0X296C, ctx->r1) = ctx->r15;
    // 0x80031230: sw          $t6, -0x2970($at)
    MEM_W(-0X2970, ctx->r1) = ctx->r14;
    // 0x80031234: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80031238: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x8003123C: lw          $t8, -0x51A0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X51A0);
    // 0x80031240: sw          $zero, -0x2968($at)
    MEM_W(-0X2968, ctx->r1) = 0;
    // 0x80031244: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80031248: sw          $zero, -0x2964($at)
    MEM_W(-0X2964, ctx->r1) = 0;
    // 0x8003124C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80031250: sw          $t8, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r24;
    // 0x80031254: lw          $t9, -0x51A0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X51A0);
    // 0x80031258: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x8003125C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x80031260: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80031264: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x80031268: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x8003126C: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x80031270: lw          $t1, -0x51A0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X51A0);
    // 0x80031274: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x80031278: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x8003127C: sw          $t2, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r10;
    // 0x80031280: sw          $t3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r11;
    // 0x80031284: lw          $t4, -0x51A0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X51A0);
    // 0x80031288: lw          $t6, 0x10($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10);
    // 0x8003128C: lw          $t7, 0x14($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X14);
    // 0x80031290: sw          $t6, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r14;
    // 0x80031294: sw          $t7, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r15;
    // 0x80031298: lw          $t5, -0x51A0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X51A0);
    // 0x8003129C: sw          $zero, 0x18($t5)
    MEM_W(0X18, ctx->r13) = 0;
    // 0x800312A0: lw          $t8, -0x51A0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X51A0);
    // 0x800312A4: jr          $ra
    // 0x800312A8: sw          $zero, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = 0;
    return;
    // 0x800312A8: sw          $zero, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = 0;
;}
RECOMP_FUNC void FUN_80031670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031670: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80031674: addiu       $a1, $a1, -0x6688
    ctx->r5 = ADD32(ctx->r5, -0X6688);
    // 0x80031678: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8003167C: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x80031680: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80031684: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80031688: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003168C: bgez        $a0, L_800316A0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80031690: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800316A0;
    }
    // 0x80031690: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80031694: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80031698: nop

    // 0x8003169C: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800316A0:
    // 0x800316A0: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800316A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800316A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800316AC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800316B0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800316B4: lui         $t0, 0xA450
    ctx->r8 = S32(0XA450 << 16);
    // 0x800316B8: lui         $t2, 0xA450
    ctx->r10 = S32(0XA450 << 16);
    // 0x800316BC: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800316C0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800316C4: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x800316C8: nop

    // 0x800316CC: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800316D0: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x800316D4: nop

    // 0x800316D8: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x800316DC: beql        $v1, $zero, L_8003172C
    if (ctx->r3 == 0) {
        // 0x800316E0: mfc1        $v1, $f8
        ctx->r3 = (int32_t)ctx->f8.u32l;
            goto L_8003172C;
    }
    goto skip_0;
    // 0x800316E0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x800316E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800316E8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800316EC: sub.s       $f8, $f0, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800316F0: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x800316F4: nop

    // 0x800316F8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800316FC: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x80031700: nop

    // 0x80031704: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80031708: bne         $v1, $zero, L_80031720
    if (ctx->r3 != 0) {
        // 0x8003170C: nop
    
            goto L_80031720;
    }
    // 0x8003170C: nop

    // 0x80031710: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80031714: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80031718: b           L_80031738
    // 0x8003171C: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_80031738;
    // 0x8003171C: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_80031720:
    // 0x80031720: b           L_80031738
    // 0x80031724: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80031738;
    // 0x80031724: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80031728: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
L_8003172C:
    // 0x8003172C: nop

    // 0x80031730: bltz        $v1, L_80031720
    if (SIGNED(ctx->r3) < 0) {
        // 0x80031734: nop
    
            goto L_80031720;
    }
    // 0x80031734: nop

L_80031738:
    // 0x80031738: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003173C: sltiu       $at, $v1, 0x84
    ctx->r1 = ctx->r3 < 0X84 ? 1 : 0;
    // 0x80031740: beq         $at, $zero, L_80031750
    if (ctx->r1 == 0) {
        // 0x80031744: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_80031750;
    }
    // 0x80031744: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80031748: jr          $ra
    // 0x8003174C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8003174C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80031750:
    // 0x80031750: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80031754: divu        $zero, $v1, $at
    lo = S32(U32(ctx->r3) / U32(ctx->r1)); hi = S32(U32(ctx->r3) % U32(ctx->r1));
    // 0x80031758: mflo        $v0
    ctx->r2 = lo;
    // 0x8003175C: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x80031760: slti        $at, $t8, 0x11
    ctx->r1 = SIGNED(ctx->r24) < 0X11 ? 1 : 0;
    // 0x80031764: bne         $at, $zero, L_80031770
    if (ctx->r1 != 0) {
        // 0x80031768: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_80031770;
    }
    // 0x80031768: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003176C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_80031770:
    // 0x80031770: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x80031774: addiu       $t1, $a0, -0x1
    ctx->r9 = ADD32(ctx->r4, -0X1);
    // 0x80031778: sw          $t1, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r9;
    // 0x8003177C: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80031780: div         $zero, $t3, $v1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r3)));
    // 0x80031784: mflo        $v0
    ctx->r2 = lo;
    // 0x80031788: bne         $v1, $zero, L_80031794
    if (ctx->r3 != 0) {
        // 0x8003178C: nop
    
            goto L_80031794;
    }
    // 0x8003178C: nop

    // 0x80031790: break       7
    do_break(2147686288);
L_80031794:
    // 0x80031794: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80031798: bne         $v1, $at, L_800317AC
    if (ctx->r3 != ctx->r1) {
        // 0x8003179C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800317AC;
    }
    // 0x8003179C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800317A0: bne         $t3, $at, L_800317AC
    if (ctx->r11 != ctx->r1) {
        // 0x800317A4: nop
    
            goto L_800317AC;
    }
    // 0x800317A4: nop

    // 0x800317A8: break       6
    do_break(2147686312);
L_800317AC:
    // 0x800317AC: jr          $ra
    // 0x800317B0: nop

    return;
    // 0x800317B0: nop

    // 0x800317B4: nop

    // 0x800317B8: nop

    // 0x800317BC: nop

;}
RECOMP_FUNC void FUN_800317c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800317C0: mtc0        $a0, Compare
    cop0_register_write(ctx, 11, ctx->r4);    // 0x800317C4: jr          $ra
    // 0x800317C8: nop

    return;
    // 0x800317C8: nop

    // 0x800317CC: nop

;}
RECOMP_FUNC void FUN_800317d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800317D0: beq         $a2, $zero, L_8003183C
    if (ctx->r6 == 0) {
        // 0x800317D4: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8003183C;
    }
    // 0x800317D4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800317D8: beq         $a0, $a1, L_8003183C
    if (ctx->r4 == ctx->r5) {
        // 0x800317DC: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8003183C;
    }
    // 0x800317DC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800317E0: bnel        $at, $zero, L_80031804
    if (ctx->r1 != 0) {
        // 0x800317E4: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80031804;
    }
    goto skip_0;
    // 0x800317E4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x800317E8: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x800317EC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800317F0: beql        $at, $zero, L_80031804
    if (ctx->r1 == 0) {
        // 0x800317F4: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80031804;
    }
    goto skip_1;
    // 0x800317F4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x800317F8: b           L_80031968
    // 0x800317FC: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_80031968;
    // 0x800317FC: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80031800: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80031804:
    // 0x80031804: bne         $at, $zero, L_8003181C
    if (ctx->r1 != 0) {
        // 0x80031808: nop
    
            goto L_8003181C;
    }
    // 0x80031808: nop

    // 0x8003180C: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x80031810: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x80031814: beq         $v0, $v1, L_80031844
    if (ctx->r2 == ctx->r3) {
        // 0x80031818: nop
    
            goto L_80031844;
    }
    // 0x80031818: nop

L_8003181C:
    // 0x8003181C: beq         $a2, $zero, L_8003183C
    if (ctx->r6 == 0) {
        // 0x80031820: nop
    
            goto L_8003183C;
    }
    // 0x80031820: nop

    // 0x80031824: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_80031828:
    // 0x80031828: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8003182C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80031830: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80031834: bne         $a0, $v1, L_80031828
    if (ctx->r4 != ctx->r3) {
        // 0x80031838: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_80031828;
    }
    // 0x80031838: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_8003183C:
    // 0x8003183C: jr          $ra
    // 0x80031840: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x80031840: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80031844:
    // 0x80031844: beq         $v0, $zero, L_800318A8
    if (ctx->r2 == 0) {
        // 0x80031848: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800318A8;
    }
    // 0x80031848: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003184C: beq         $v0, $at, L_8003188C
    if (ctx->r2 == ctx->r1) {
        // 0x80031850: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003188C;
    }
    // 0x80031850: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80031854: beql        $v0, $at, L_80031878
    if (ctx->r2 == ctx->r1) {
        // 0x80031858: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_80031878;
    }
    goto skip_2;
    // 0x80031858: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x8003185C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80031860: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80031864: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80031868: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8003186C: b           L_800318A8
    // 0x80031870: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_800318A8;
    // 0x80031870: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x80031874: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_80031878:
    // 0x80031878: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8003187C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80031880: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80031884: b           L_800318A8
    // 0x80031888: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_800318A8;
    // 0x80031888: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_8003188C:
    // 0x8003188C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80031890: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x80031894: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x80031898: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x8003189C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800318A0: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x800318A4: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_800318A8:
    // 0x800318A8: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800318AC: bnel        $at, $zero, L_80031908
    if (ctx->r1 != 0) {
        // 0x800318B0: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80031908;
    }
    goto skip_3;
    // 0x800318B0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x800318B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800318B8: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800318BC: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800318C0: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800318C4: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x800318C8: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800318CC: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x800318D0: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x800318D4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800318D8: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x800318DC: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800318E0: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x800318E4: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x800318E8: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x800318EC: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x800318F0: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x800318F4: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x800318F8: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x800318FC: b           L_800318A8
    // 0x80031900: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_800318A8;
    // 0x80031900: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_80031904:
    // 0x80031904: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80031908:
    // 0x80031908: bnel        $at, $zero, L_80031944
    if (ctx->r1 != 0) {
        // 0x8003190C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_80031944;
    }
    goto skip_4;
    // 0x8003190C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x80031910: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80031914: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80031918: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8003191C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80031920: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80031924: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80031928: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x8003192C: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x80031930: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x80031934: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x80031938: b           L_80031904
    // 0x8003193C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_80031904;
    // 0x8003193C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_80031940:
    // 0x80031940: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_80031944:
    // 0x80031944: bne         $at, $zero, L_8003181C
    if (ctx->r1 != 0) {
        // 0x80031948: nop
    
            goto L_8003181C;
    }
    // 0x80031948: nop

    // 0x8003194C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80031950: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80031954: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80031958: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8003195C: b           L_80031940
    // 0x80031960: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_80031940;
    // 0x80031960: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x80031964: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80031968:
    // 0x80031968: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8003196C: bne         $at, $zero, L_80031984
    if (ctx->r1 != 0) {
        // 0x80031970: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_80031984;
    }
    // 0x80031970: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x80031974: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x80031978: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x8003197C: beq         $v0, $v1, L_800319B4
    if (ctx->r2 == ctx->r3) {
        // 0x80031980: nop
    
            goto L_800319B4;
    }
    // 0x80031980: nop

L_80031984:
    // 0x80031984: beq         $a2, $zero, L_8003183C
    if (ctx->r6 == 0) {
        // 0x80031988: nop
    
            goto L_8003183C;
    }
    // 0x80031988: nop

    // 0x8003198C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80031990: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80031994: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_80031998:
    // 0x80031998: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8003199C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800319A0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800319A4: bne         $a0, $v1, L_80031998
    if (ctx->r4 != ctx->r3) {
        // 0x800319A8: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_80031998;
    }
    // 0x800319A8: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x800319AC: jr          $ra
    // 0x800319B0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800319B0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800319B4:
    // 0x800319B4: beq         $v0, $zero, L_80031A18
    if (ctx->r2 == 0) {
        // 0x800319B8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80031A18;
    }
    // 0x800319B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800319BC: beq         $v0, $at, L_800319FC
    if (ctx->r2 == ctx->r1) {
        // 0x800319C0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800319FC;
    }
    // 0x800319C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800319C4: beql        $v0, $at, L_800319E8
    if (ctx->r2 == ctx->r1) {
        // 0x800319C8: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_800319E8;
    }
    goto skip_5;
    // 0x800319C8: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x800319CC: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x800319D0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800319D4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800319D8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800319DC: b           L_80031A18
    // 0x800319E0: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_80031A18;
    // 0x800319E0: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800319E4: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_800319E8:
    // 0x800319E8: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x800319EC: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800319F0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800319F4: b           L_80031A18
    // 0x800319F8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_80031A18;
    // 0x800319F8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_800319FC:
    // 0x800319FC: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x80031A00: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x80031A04: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x80031A08: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x80031A0C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x80031A10: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x80031A14: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_80031A18:
    // 0x80031A18: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x80031A1C: bnel        $at, $zero, L_80031A78
    if (ctx->r1 != 0) {
        // 0x80031A20: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80031A78;
    }
    goto skip_6;
    // 0x80031A20: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x80031A24: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80031A28: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x80031A2C: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x80031A30: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x80031A34: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x80031A38: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x80031A3C: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x80031A40: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x80031A44: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x80031A48: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x80031A4C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x80031A50: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x80031A54: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x80031A58: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x80031A5C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x80031A60: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x80031A64: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x80031A68: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x80031A6C: b           L_80031A18
    // 0x80031A70: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_80031A18;
    // 0x80031A70: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_80031A74:
    // 0x80031A74: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80031A78:
    // 0x80031A78: bnel        $at, $zero, L_80031AB4
    if (ctx->r1 != 0) {
        // 0x80031A7C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_80031AB4;
    }
    goto skip_7;
    // 0x80031A7C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x80031A80: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80031A84: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x80031A88: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x80031A8C: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x80031A90: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x80031A94: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x80031A98: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x80031A9C: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x80031AA0: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x80031AA4: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x80031AA8: b           L_80031A74
    // 0x80031AAC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_80031A74;
    // 0x80031AAC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_80031AB0:
    // 0x80031AB0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_80031AB4:
    // 0x80031AB4: bne         $at, $zero, L_80031984
    if (ctx->r1 != 0) {
        // 0x80031AB8: nop
    
            goto L_80031984;
    }
    // 0x80031AB8: nop

    // 0x80031ABC: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80031AC0: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80031AC4: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80031AC8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80031ACC: b           L_80031AB0
    // 0x80031AD0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_80031AB0;
    // 0x80031AD0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80031AD4: nop

    // 0x80031AD8: nop

    // 0x80031ADC: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80031ae0(rdram, ctx);
;}
RECOMP_FUNC void FUN_80031ae0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031AE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80031AE4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80031AE8: blez        $a2, L_80031B4C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80031AEC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80031B4C;
    }
    // 0x80031AEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80031AF0: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x80031AF4: beq         $a1, $zero, L_80031B1C
    if (ctx->r5 == 0) {
        // 0x80031AF8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80031B1C;
    }
    // 0x80031AF8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80031AFC:
    // 0x80031AFC: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80031B00: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80031B04: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80031B08: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80031B0C: bne         $a0, $a3, L_80031AFC
    if (ctx->r4 != ctx->r7) {
        // 0x80031B10: sb          $t6, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r14;
            goto L_80031AFC;
    }
    // 0x80031B10: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x80031B14: beq         $a3, $a2, L_80031B4C
    if (ctx->r7 == ctx->r6) {
        // 0x80031B18: nop
    
            goto L_80031B4C;
    }
    // 0x80031B18: nop

L_80031B1C:
    // 0x80031B1C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80031B20: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80031B24: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80031B28: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x80031B2C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80031B30: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80031B34: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x80031B38: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x80031B3C: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x80031B40: lbu         $t0, -0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X1);
    // 0x80031B44: bne         $a3, $a2, L_80031B1C
    if (ctx->r7 != ctx->r6) {
        // 0x80031B48: sb          $t0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r8;
            goto L_80031B1C;
    }
    // 0x80031B48: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
L_80031B4C:
    // 0x80031B4C: jr          $ra
    // 0x80031B50: nop

    return;
    // 0x80031B50: nop

    // 0x80031B54: nop

    // 0x80031B58: nop

    // 0x80031B5C: nop

;}
RECOMP_FUNC void __osPfsReleasePages(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031D98: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80031D9C: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x80031DA0: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80031DA4: sll         $t8, $v0, 8
    ctx->r24 = S32(ctx->r2 << 8);
    // 0x80031DA8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80031DAC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80031DB0: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80031DB4: sh          $t9, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r25;
    // 0x80031DB8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80031DBC: addiu       $a2, $sp, 0xC
    ctx->r6 = ADD32(ctx->r29, 0XC);
    // 0x80031DC0: addiu       $v1, $sp, 0x8
    ctx->r3 = ADD32(ctx->r29, 0X8);
    // 0x80031DC4: lhu         $at, 0x0($a2)
    ctx->r1 = MEM_HU(ctx->r6, 0X0);
L_80031DC8:
    // 0x80031DC8: sh          $at, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r1;
    // 0x80031DCC: lbu         $t3, 0xD($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XD);
    // 0x80031DD0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80031DD4: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x80031DD8: lhu         $at, 0x0($t5)
    ctx->r1 = MEM_HU(ctx->r13, 0X0);
    // 0x80031DDC: sh          $at, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r1;
    // 0x80031DE0: lbu         $t9, 0x9($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X9);
    // 0x80031DE4: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x80031DE8: addu        $t0, $a1, $t1
    ctx->r8 = ADD32(ctx->r5, ctx->r9);
    // 0x80031DEC: sh          $a3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r7;
    // 0x80031DF0: lw          $t3, 0x60($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X60);
    // 0x80031DF4: lhu         $t2, 0xC($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0XC);
    // 0x80031DF8: lbu         $t4, 0xC($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XC);
    // 0x80031DFC: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80031E00: bnel        $at, $zero, L_80031E14
    if (ctx->r1 != 0) {
        // 0x80031E04: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_80031E14;
    }
    goto skip_0;
    // 0x80031E04: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80031E08: beql        $v0, $t4, L_80031DC8
    if (ctx->r2 == ctx->r12) {
        // 0x80031E0C: lhu         $at, 0x0($a2)
        ctx->r1 = MEM_HU(ctx->r6, 0X0);
            goto L_80031DC8;
    }
    goto skip_1;
    // 0x80031E0C: lhu         $at, 0x0($a2)
    ctx->r1 = MEM_HU(ctx->r6, 0X0);
    skip_1:
    // 0x80031E10: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
L_80031E14:
    // 0x80031E14: lhu         $at, 0x0($a2)
    ctx->r1 = MEM_HU(ctx->r6, 0X0);
    // 0x80031E18: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80031E1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80031E20: jr          $ra
    // 0x80031E24: sh          $at, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r1;
    return;
    // 0x80031E24: sh          $at, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r1;
    // 0x80031E28: nop

    // 0x80031E2C: nop

;}
RECOMP_FUNC void FUN_80031e30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031E30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031E38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80031E3C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80031E40: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80031E44: jal         0x80029E30
    // 0x80031E48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80029E30)(rdram, ctx);
        goto after_0;
    // 0x80031E48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80031E4C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80031E50: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80031E54: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80031E58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80031E5C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80031E60: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80031E64: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80031E68: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80031E6C: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80031E70: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80031E74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80031E78: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80031E7C: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80031E80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80031E84: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80031E88: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80031E8C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80031E90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80031E94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80031E98: sub.s       $f2, $f14, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x80031E9C: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80031EA0: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80031EA4: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x80031EA8: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x80031EAC: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80031EB0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80031EB4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80031EB8: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80031EBC: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80031EC0: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x80031EC4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80031EC8: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80031ECC: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80031ED0: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80031ED4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80031ED8: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80031EDC: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80031EE0: swc1        $f6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f6.u32l;
    // 0x80031EE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80031EE8: nop

    // 0x80031EEC: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x80031EF0: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x80031EF4: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80031EF8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80031EFC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80031F00: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80031F04: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80031F08: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80031F0C: beq         $v1, $a0, L_80031F50
    if (ctx->r3 == ctx->r4) {
        // 0x80031F10: lwc1        $f16, 0xC($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
            goto L_80031F50;
    }
    // 0x80031F10: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
L_80031F14:
    // 0x80031F14: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80031F18: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80031F1C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80031F20: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80031F24: lwc1        $f14, 0x18($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80031F28: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80031F2C: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80031F30: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80031F34: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x80031F38: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80031F3C: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80031F40: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80031F44: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80031F48: bne         $v1, $a0, L_80031F14
    if (ctx->r3 != ctx->r4) {
        // 0x80031F4C: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80031F14;
    }
    // 0x80031F4C: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
L_80031F50:
    // 0x80031F50: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80031F54: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80031F58: swc1        $f12, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f12.u32l;
    // 0x80031F5C: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80031F60: nop

    // 0x80031F64: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80031F68: swc1        $f10, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f10.u32l;
    // 0x80031F6C: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80031F70: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80031F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031F78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031F7C: jr          $ra
    // 0x80031F80: nop

    return;
    // 0x80031F80: nop

;}
RECOMP_FUNC void FUN_80031f84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031F84: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80031F88: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80031F8C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80031F90: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80031F94: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80031F98: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80031F9C: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80031FA0: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80031FA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80031FA8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80031FAC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80031FB0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80031FB4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80031FB8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80031FBC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80031FC0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80031FC4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80031FC8: jal         0x80031E30
    // 0x80031FCC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80031E30)(rdram, ctx);
        goto after_0;
    // 0x80031FCC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80031FD0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80031FD4: jal         0x80029D30
    // 0x80031FD8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    LOOKUP_FUNC(0x80029D30)(rdram, ctx);
        goto after_1;
    // 0x80031FD8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x80031FDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80031FE0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80031FE4: jr          $ra
    // 0x80031FE8: nop

    return;
    // 0x80031FE8: nop

    // 0x80031FEC: nop

;}
RECOMP_FUNC void __osViInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032228: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8003222C: addiu       $a0, $a0, -0x5190
    ctx->r4 = ADD32(ctx->r4, -0X5190);
    // 0x80032230: jal         0x800279F0
    // 0x80032234: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    LOOKUP_FUNC(0x800279F0)(rdram, ctx);
        goto after_0;
    // 0x80032234: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_0:
    // 0x80032238: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8003223C: addiu       $t6, $t6, -0x5190
    ctx->r14 = ADD32(ctx->r14, -0X5190);
    // 0x80032240: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80032244: sw          $t6, -0x5130($at)
    MEM_W(-0X5130, ctx->r1) = ctx->r14;
    // 0x80032248: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8003224C: addiu       $t7, $t6, 0x30
    ctx->r15 = ADD32(ctx->r14, 0X30);
    // 0x80032250: sw          $t7, -0x512C($at)
    MEM_W(-0X512C, ctx->r1) = ctx->r15;
    // 0x80032254: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80032258: sh          $t8, 0x32($t6)
    MEM_H(0X32, ctx->r14) = ctx->r24;
    // 0x8003225C: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x80032260: lw          $t0, -0x5130($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5130);
    // 0x80032264: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80032268: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x8003226C: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x80032270: lw          $t2, -0x512C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X512C);
    // 0x80032274: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80032278: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x8003227C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80032280: lw          $t4, -0x5130($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5130);
    // 0x80032284: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80032288: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x8003228C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80032290: lw          $t5, 0x300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X300);
    // 0x80032294: bne         $t5, $zero, L_800322B4
    if (ctx->r13 != 0) {
        // 0x80032298: nop
    
            goto L_800322B4;
    }
    // 0x80032298: nop

    // 0x8003229C: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x800322A0: lw          $t8, -0x512C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X512C);
    // 0x800322A4: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x800322A8: addiu       $t7, $t7, -0x5120
    ctx->r15 = ADD32(ctx->r15, -0X5120);
    // 0x800322AC: b           L_800322F4
    // 0x800322B0: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
        goto L_800322F4;
    // 0x800322B0: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
L_800322B4:
    // 0x800322B4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800322B8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800322BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800322C0: bne         $t6, $at, L_800322E0
    if (ctx->r14 != ctx->r1) {
        // 0x800322C4: nop
    
            goto L_800322E0;
    }
    // 0x800322C4: nop

    // 0x800322C8: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x800322CC: lw          $t0, -0x512C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X512C);
    // 0x800322D0: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x800322D4: addiu       $t9, $t9, -0x5080
    ctx->r25 = ADD32(ctx->r25, -0X5080);
    // 0x800322D8: b           L_800322F4
    // 0x800322DC: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
        goto L_800322F4;
    // 0x800322DC: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
L_800322E0:
    // 0x800322E0: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x800322E4: lw          $t2, -0x512C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X512C);
    // 0x800322E8: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x800322EC: addiu       $t1, $t1, -0x50D0
    ctx->r9 = ADD32(ctx->r9, -0X50D0);
    // 0x800322F0: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
L_800322F4:
    // 0x800322F4: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x800322F8: lw          $t4, -0x512C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X512C);
    // 0x800322FC: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x80032300: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x80032304: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x80032308: lw          $t5, -0x512C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X512C);
    // 0x8003230C: lui         $t6, 0xA440
    ctx->r14 = S32(0XA440 << 16);
    // 0x80032310: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x80032314: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80032318: sw          $t8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r24;
    // 0x8003231C: lw          $t9, 0x10($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X10);
    // 0x80032320: sltiu       $at, $t9, 0xB
    ctx->r1 = ctx->r25 < 0XB ? 1 : 0;
    // 0x80032324: bne         $at, $zero, L_80032340
    if (ctx->r1 != 0) {
        // 0x80032328: nop
    
            goto L_80032340;
    }
    // 0x80032328: nop

L_8003232C:
    // 0x8003232C: lui         $t0, 0xA440
    ctx->r8 = S32(0XA440 << 16);
    // 0x80032330: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80032334: sltiu       $at, $t1, 0xB
    ctx->r1 = ctx->r9 < 0XB ? 1 : 0;
    // 0x80032338: beq         $at, $zero, L_8003232C
    if (ctx->r1 == 0) {
        // 0x8003233C: nop
    
            goto L_8003232C;
    }
    // 0x8003233C: nop

L_80032340:
    // 0x80032340: lui         $t2, 0xA440
    ctx->r10 = S32(0XA440 << 16);
    // 0x80032344: jal         0x80032360
    // 0x80032348: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    LOOKUP_FUNC(0x80032360)(rdram, ctx);
        goto after_1;
    // 0x80032348: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    after_1:
    // 0x8003234C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032350: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032354: jr          $ra
    // 0x80032358: nop

    return;
    // 0x80032358: nop

    // 0x8003235C: nop

;}
RECOMP_FUNC void __osViSwapContext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032360: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80032364: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80032368: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003236C: lui         $s0, 0x8005
    ctx->r16 = S32(0X8005 << 16);
    // 0x80032370: lui         $t6, 0xA440
    ctx->r14 = S32(0XA440 << 16);
    // 0x80032374: lw          $s0, -0x512C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X512C);
    // 0x80032378: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8003237C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80032380: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80032384: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80032388: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8003238C: jal         0x80028A10
    // 0x80032390: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_0;
    // 0x80032390: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80032394: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80032398: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8003239C: lhu         $t2, 0x0($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X0);
    // 0x800323A0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800323A4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800323A8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800323AC: addu        $a2, $a1, $t0
    ctx->r6 = ADD32(ctx->r5, ctx->r8);
    // 0x800323B0: lw          $t1, 0x28($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X28);
    // 0x800323B4: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x800323B8: beq         $t3, $zero, L_800323DC
    if (ctx->r11 == 0) {
        // 0x800323BC: addu        $a0, $t1, $v0
        ctx->r4 = ADD32(ctx->r9, ctx->r2);
            goto L_800323DC;
    }
    // 0x800323BC: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    // 0x800323C0: lw          $t5, 0x20($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X20);
    // 0x800323C4: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x800323C8: addiu       $at, $zero, -0x1000
    ctx->r1 = ADD32(0, -0X1000);
    // 0x800323CC: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800323D0: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800323D4: b           L_800323E4
    // 0x800323D8: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
        goto L_800323E4;
    // 0x800323D8: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
L_800323DC:
    // 0x800323DC: lw          $t8, 0x20($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X20);
    // 0x800323E0: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
L_800323E4:
    // 0x800323E4: lhu         $t9, 0x0($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X0);
    // 0x800323E8: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x800323EC: beql        $t0, $zero, L_800324C4
    if (ctx->r8 == 0) {
        // 0x800323F0: lw          $t6, 0x2C($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X2C);
            goto L_800324C4;
    }
    goto skip_0;
    // 0x800323F0: lw          $t6, 0x2C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X2C);
    skip_0:
    // 0x800323F4: lw          $v1, 0x2C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X2C);
    // 0x800323F8: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800323FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80032400: andi        $t1, $v1, 0xFFF
    ctx->r9 = ctx->r3 & 0XFFF;
    // 0x80032404: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80032408: bgez        $t1, L_8003241C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8003240C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8003241C;
    }
    // 0x8003240C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80032410: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80032414: nop

    // 0x80032418: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8003241C:
    // 0x8003241C: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80032420: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80032424: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80032428: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8003242C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80032430: nop

    // 0x80032434: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80032438: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8003243C: nop

    // 0x80032440: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80032444: beql        $v0, $zero, L_80032494
    if (ctx->r2 == 0) {
        // 0x80032448: mfc1        $v0, $f18
        ctx->r2 = (int32_t)ctx->f18.u32l;
            goto L_80032494;
    }
    goto skip_1;
    // 0x80032448: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x8003244C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80032450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80032454: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80032458: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8003245C: nop

    // 0x80032460: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80032464: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80032468: nop

    // 0x8003246C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80032470: bne         $v0, $zero, L_80032488
    if (ctx->r2 != 0) {
        // 0x80032474: nop
    
            goto L_80032488;
    }
    // 0x80032474: nop

    // 0x80032478: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8003247C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80032480: b           L_800324A0
    // 0x80032484: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_800324A0;
    // 0x80032484: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80032488:
    // 0x80032488: b           L_800324A0
    // 0x8003248C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800324A0;
    // 0x8003248C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80032490: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
L_80032494:
    // 0x80032494: nop

    // 0x80032498: bltz        $v0, L_80032488
    if (SIGNED(ctx->r2) < 0) {
        // 0x8003249C: nop
    
            goto L_80032488;
    }
    // 0x8003249C: nop

L_800324A0:
    // 0x800324A0: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x800324A4: lw          $t3, 0x2C($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X2C);
    // 0x800324A8: addiu       $at, $zero, -0x1000
    ctx->r1 = ADD32(0, -0X1000);
    // 0x800324AC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800324B0: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x800324B4: or          $t4, $v0, $t5
    ctx->r12 = ctx->r2 | ctx->r13;
    // 0x800324B8: b           L_800324C8
    // 0x800324BC: sw          $t4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r12;
        goto L_800324C8;
    // 0x800324BC: sw          $t4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r12;
    // 0x800324C0: lw          $t6, 0x2C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X2C);
L_800324C4:
    // 0x800324C4: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
L_800324C8:
    // 0x800324C8: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x800324CC: lw          $v0, -0x4FF4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4FF4);
    // 0x800324D0: lw          $t7, 0x30($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X30);
    // 0x800324D4: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x800324D8: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800324DC: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800324E0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800324E4: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800324E8: lw          $a3, 0x1C($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X1C);
    // 0x800324EC: andi        $t1, $v1, 0x20
    ctx->r9 = ctx->r3 & 0X20;
    // 0x800324F0: beq         $t1, $zero, L_800324FC
    if (ctx->r9 == 0) {
        // 0x800324F4: andi        $t2, $v1, 0x40
        ctx->r10 = ctx->r3 & 0X40;
            goto L_800324FC;
    }
    // 0x800324F4: andi        $t2, $v1, 0x40
    ctx->r10 = ctx->r3 & 0X40;
    // 0x800324F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800324FC:
    // 0x800324FC: beql        $t2, $zero, L_80032534
    if (ctx->r10 == 0) {
        // 0x80032500: andi        $t3, $v1, 0x80
        ctx->r11 = ctx->r3 & 0X80;
            goto L_80032534;
    }
    goto skip_2;
    // 0x80032500: andi        $t3, $v1, 0x80
    ctx->r11 = ctx->r3 & 0X80;
    skip_2:
    // 0x80032504: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x80032508: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8003250C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80032510: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80032514: jal         0x80028A10
    // 0x80032518: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_1;
    // 0x80032518: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_1:
    // 0x8003251C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80032520: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80032524: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80032528: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003252C: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x80032530: andi        $t3, $v1, 0x80
    ctx->r11 = ctx->r3 & 0X80;
L_80032534:
    // 0x80032534: beql        $t3, $zero, L_80032578
    if (ctx->r11 == 0) {
        // 0x80032538: lui         $t7, 0xA440
        ctx->r15 = S32(0XA440 << 16);
            goto L_80032578;
    }
    goto skip_3;
    // 0x80032538: lui         $t7, 0xA440
    ctx->r15 = S32(0XA440 << 16);
    skip_3:
    // 0x8003253C: lhu         $t5, 0x28($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X28);
    // 0x80032540: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x80032544: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80032548: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x8003254C: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x80032550: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
    // 0x80032554: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80032558: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8003255C: jal         0x80028A10
    // 0x80032560: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_2;
    // 0x80032560: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_2:
    // 0x80032564: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80032568: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8003256C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80032570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80032574: lui         $t7, 0xA440
    ctx->r15 = S32(0XA440 << 16);
L_80032578:
    // 0x80032578: sw          $a0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r4;
    // 0x8003257C: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x80032580: lui         $t9, 0xA440
    ctx->r25 = S32(0XA440 << 16);
    // 0x80032584: lui         $t1, 0xA440
    ctx->r9 = S32(0XA440 << 16);
    // 0x80032588: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8003258C: lw          $t0, 0xC($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XC);
    // 0x80032590: lui         $t3, 0xA440
    ctx->r11 = S32(0XA440 << 16);
    // 0x80032594: lui         $t4, 0xA440
    ctx->r12 = S32(0XA440 << 16);
    // 0x80032598: sw          $t0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r8;
    // 0x8003259C: lw          $t2, 0x10($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X10);
    // 0x800325A0: lui         $t8, 0xA440
    ctx->r24 = S32(0XA440 << 16);
    // 0x800325A4: lui         $t0, 0xA440
    ctx->r8 = S32(0XA440 << 16);
    // 0x800325A8: sw          $t2, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r10;
    // 0x800325AC: lw          $t5, 0x14($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X14);
    // 0x800325B0: lui         $t2, 0xA440
    ctx->r10 = S32(0XA440 << 16);
    // 0x800325B4: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x800325B8: sw          $t5, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r13;
    // 0x800325BC: lw          $t6, 0x18($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X18);
    // 0x800325C0: lui         $t5, 0xA440
    ctx->r13 = S32(0XA440 << 16);
    // 0x800325C4: addiu       $v0, $v0, -0x5130
    ctx->r2 = ADD32(ctx->r2, -0X5130);
    // 0x800325C8: sw          $t6, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r14;
    // 0x800325CC: sw          $a3, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r7;
    // 0x800325D0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800325D4: lui         $t6, 0xA440
    ctx->r14 = S32(0XA440 << 16);
    // 0x800325D8: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x800325DC: sw          $t9, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r25;
    // 0x800325E0: lw          $t1, 0x34($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X34);
    // 0x800325E4: addiu       $v1, $v1, -0x512C
    ctx->r3 = ADD32(ctx->r3, -0X512C);
    // 0x800325E8: sw          $t1, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r9;
    // 0x800325EC: lw          $t3, 0x38($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X38);
    // 0x800325F0: sw          $t3, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r11;
    // 0x800325F4: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x800325F8: or          $t3, $s0, $zero
    ctx->r11 = ctx->r16 | 0;
    // 0x800325FC: sw          $t4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r12;
    // 0x80032600: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80032604: addiu       $t4, $s0, 0x30
    ctx->r12 = ADD32(ctx->r16, 0X30);
    // 0x80032608: sw          $t7, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r15;
    // 0x8003260C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80032610: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80032614: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80032618: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8003261C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_80032620:
    // 0x80032620: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80032624: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80032628: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8003262C: sw          $at, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r1;
    // 0x80032630: lw          $at, -0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X8);
    // 0x80032634: sw          $at, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r1;
    // 0x80032638: lw          $at, -0x4($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X4);
    // 0x8003263C: bne         $t3, $t4, L_80032620
    if (ctx->r11 != ctx->r12) {
        // 0x80032640: sw          $at, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r1;
            goto L_80032620;
    }
    // 0x80032640: sw          $at, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r1;
    // 0x80032644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80032648: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003264C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80032650: jr          $ra
    // 0x80032654: nop

    return;
    // 0x80032654: nop

    // 0x80032658: nop

    // 0x8003265C: nop

;}
RECOMP_FUNC void FUN_80032660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032660: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x80032664: addiu       $t2, $t2, -0x6680
    ctx->r10 = ADD32(ctx->r10, -0X6680);
    // 0x80032668: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8003266C: andi        $t3, $t3, 0xFF00
    ctx->r11 = ctx->r11 & 0XFF00;
    // 0x80032670: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x80032674: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80032678: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8003267C: mtc0        $t1, Status
    cop0_status_write(ctx, ctx->r9);    // 0x80032680: andi        $v0, $t0, 0x1
    ctx->r2 = ctx->r8 & 0X1;
    // 0x80032684: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x80032688: andi        $t0, $t0, 0xFF00
    ctx->r8 = ctx->r8 & 0XFF00;
    // 0x8003268C: beq         $t0, $t3, L_800326C8
    if (ctx->r8 == ctx->r11) {
        // 0x80032690: lui         $t2, 0x8005
        ctx->r10 = S32(0X8005 << 16);
            goto L_800326C8;
    }
    // 0x80032690: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x80032694: addiu       $t2, $t2, -0x66C0
    ctx->r10 = ADD32(ctx->r10, -0X66C0);
    // 0x80032698: lw          $t1, 0x118($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X118);
    // 0x8003269C: andi        $t2, $t1, 0xFF00
    ctx->r10 = ctx->r9 & 0XFF00;
    // 0x800326A0: and         $t2, $t2, $t0
    ctx->r10 = ctx->r10 & ctx->r8;
    // 0x800326A4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800326A8: ori         $at, $at, 0xFF
    ctx->r1 = ctx->r1 | 0XFF;
    // 0x800326AC: and         $t1, $t1, $at
    ctx->r9 = ctx->r9 & ctx->r1;
    // 0x800326B0: or          $t1, $t1, $t2
    ctx->r9 = ctx->r9 | ctx->r10;
    // 0x800326B4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800326B8: and         $t1, $t1, $at
    ctx->r9 = ctx->r9 & ctx->r1;
    // 0x800326BC: mtc0        $t1, Status
    cop0_status_write(ctx, ctx->r9);    // 0x800326C0: nop

    // 0x800326C4: nop

L_800326C8:
    // 0x800326C8: jr          $ra
    // 0x800326CC: nop

    return;
    // 0x800326CC: nop

;}
RECOMP_FUNC void FUN_800326f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800326F0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x800326F4: lw          $t6, -0x54F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54F0);
    // 0x800326F8: bne         $t6, $zero, L_80032708
    if (ctx->r14 != 0) {
        // 0x800326FC: nop
    
            goto L_80032708;
    }
    // 0x800326FC: nop

    // 0x80032700: jr          $ra
    // 0x80032704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80032704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80032708:
    // 0x80032708: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8003270C: lw          $v0, -0x54E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X54E8);
    // 0x80032710: jr          $ra
    // 0x80032714: nop

    return;
    // 0x80032714: nop

    // 0x80032718: nop

    // 0x8003271C: nop

;}
RECOMP_FUNC void FUN_80032720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032720: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x80032724: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80032728: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8003272C: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80032730: sra         $t6, $v0, 22
    ctx->r14 = S32(SIGNED(ctx->r2) >> 22);
    // 0x80032734: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80032738: slti        $at, $t7, 0x136
    ctx->r1 = SIGNED(ctx->r15) < 0X136 ? 1 : 0;
    // 0x8003273C: beql        $at, $zero, L_80032864
    if (ctx->r1 == 0) {
        // 0x80032740: c.eq.s      $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
            goto L_80032864;
    }
    goto skip_0;
    // 0x80032740: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
    skip_0:
    // 0x80032744: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80032748: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003274C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80032750: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80032754: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80032758: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8003275C: bc1fl       L_80032770
    if (!c1cs) {
        // 0x80032760: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_80032770;
    }
    goto skip_1;
    // 0x80032760: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_1:
    // 0x80032764: b           L_80032770
    // 0x80032768: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
        goto L_80032770;
    // 0x80032768: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x8003276C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_80032770:
    // 0x80032770: ldc1        $f8, -0x2B58($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2B58);
    // 0x80032774: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x80032778: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003277C: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x80032780: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80032784: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80032788: add.d       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = ctx->f10.d + ctx->f18.d;
    // 0x8003278C: c.le.d      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.d <= ctx->f14.d;
    // 0x80032790: nop

    // 0x80032794: bc1fl       L_800327B4
    if (!c1cs) {
        // 0x80032798: sub.d       $f10, $f14, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
            goto L_800327B4;
    }
    goto skip_2;
    // 0x80032798: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
    skip_2:
    // 0x8003279C: add.d       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f14.d + ctx->f18.d;
    // 0x800327A0: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800327A4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800327A8: b           L_800327C4
    // 0x800327AC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
        goto L_800327C4;
    // 0x800327AC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800327B0: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
L_800327B4:
    // 0x800327B4: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800327B8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800327BC: nop

    // 0x800327C0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
L_800327C4:
    // 0x800327C4: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800327C8: ldc1        $f10, -0x2B50($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2B50);
    // 0x800327CC: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800327D0: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800327D4: ldc1        $f6, -0x2B48($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2B48);
    // 0x800327D8: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x800327DC: addiu       $v1, $v1, -0x2B80
    ctx->r3 = ADD32(ctx->r3, -0X2B80);
    // 0x800327E0: sub.d       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f8.d - ctx->f18.d;
    // 0x800327E4: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x800327E8: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x800327EC: ldc1        $f10, 0x20($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X20);
    // 0x800327F0: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800327F4: ldc1        $f6, 0x18($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X18);
    // 0x800327F8: sub.d       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f12.d - ctx->f4.d;
    // 0x800327FC: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x80032800: mul.d       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f14.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80032804: nop

    // 0x80032808: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x8003280C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80032810: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x80032814: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x80032818: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8003281C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x80032820: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x80032824: bne         $t0, $zero, L_80032844
    if (ctx->r8 != 0) {
        // 0x80032828: add.d       $f16, $f10, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
            goto L_80032844;
    }
    // 0x80032828: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x8003282C: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x80032830: nop

    // 0x80032834: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80032838: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x8003283C: jr          $ra
    // 0x80032840: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x80032840: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80032844:
    // 0x80032844: mul.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x80032848: nop

    // 0x8003284C: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80032850: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x80032854: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x80032858: jr          $ra
    // 0x8003285C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x8003285C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80032860: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
L_80032864:
    // 0x80032864: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80032868: bc1t        L_8003287C
    if (c1cs) {
        // 0x8003286C: nop
    
            goto L_8003287C;
    }
    // 0x8003286C: nop

    // 0x80032870: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80032874: jr          $ra
    // 0x80032878: lwc1        $f0, -0x2B30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B30);
    return;
    // 0x80032878: lwc1        $f0, -0x2B30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B30);
L_8003287C:
    // 0x8003287C: lwc1        $f0, -0x2B40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B40);
    // 0x80032880: jr          $ra
    // 0x80032884: nop

    return;
    // 0x80032884: nop

    // 0x80032888: nop

    // 0x8003288C: nop

;}
RECOMP_FUNC void osViSetSpecialFeatures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032898: jal         0x80032660
    // 0x8003289C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80032660)(rdram, ctx);
        goto after_0;
    // 0x8003289C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800328A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800328A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800328A8: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x800328AC: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x800328B0: beq         $t6, $zero, L_800328CC
    if (ctx->r14 == 0) {
        // 0x800328B4: andi        $t9, $a0, 0x2
        ctx->r25 = ctx->r4 & 0X2;
            goto L_800328CC;
    }
    // 0x800328B4: andi        $t9, $a0, 0x2
    ctx->r25 = ctx->r4 & 0X2;
    // 0x800328B8: addiu       $v1, $v1, -0x512C
    ctx->r3 = ADD32(ctx->r3, -0X512C);
    // 0x800328BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800328C0: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x800328C4: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x800328C8: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
L_800328CC:
    // 0x800328CC: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x800328D0: beq         $t9, $zero, L_800328EC
    if (ctx->r25 == 0) {
        // 0x800328D4: addiu       $v1, $v1, -0x512C
        ctx->r3 = ADD32(ctx->r3, -0X512C);
            goto L_800328EC;
    }
    // 0x800328D4: addiu       $v1, $v1, -0x512C
    ctx->r3 = ADD32(ctx->r3, -0X512C);
    // 0x800328D8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800328DC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800328E0: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x800328E4: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800328E8: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
L_800328EC:
    // 0x800328EC: andi        $t2, $a0, 0x4
    ctx->r10 = ctx->r4 & 0X4;
    // 0x800328F0: beq         $t2, $zero, L_80032908
    if (ctx->r10 == 0) {
        // 0x800328F4: andi        $t5, $a0, 0x8
        ctx->r13 = ctx->r4 & 0X8;
            goto L_80032908;
    }
    // 0x800328F4: andi        $t5, $a0, 0x8
    ctx->r13 = ctx->r4 & 0X8;
    // 0x800328F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800328FC: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x80032900: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x80032904: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
L_80032908:
    // 0x80032908: beq         $t5, $zero, L_80032924
    if (ctx->r13 == 0) {
        // 0x8003290C: andi        $t8, $a0, 0x10
        ctx->r24 = ctx->r4 & 0X10;
            goto L_80032924;
    }
    // 0x8003290C: andi        $t8, $a0, 0x10
    ctx->r24 = ctx->r4 & 0X10;
    // 0x80032910: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80032914: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80032918: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x8003291C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80032920: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
L_80032924:
    // 0x80032924: beq         $t8, $zero, L_8003293C
    if (ctx->r24 == 0) {
        // 0x80032928: andi        $t1, $a0, 0x20
        ctx->r9 = ctx->r4 & 0X20;
            goto L_8003293C;
    }
    // 0x80032928: andi        $t1, $a0, 0x20
    ctx->r9 = ctx->r4 & 0X20;
    // 0x8003292C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80032930: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80032934: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80032938: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
L_8003293C:
    // 0x8003293C: beq         $t1, $zero, L_80032958
    if (ctx->r9 == 0) {
        // 0x80032940: andi        $t4, $a0, 0x40
        ctx->r12 = ctx->r4 & 0X40;
            goto L_80032958;
    }
    // 0x80032940: andi        $t4, $a0, 0x40
    ctx->r12 = ctx->r4 & 0X40;
    // 0x80032944: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80032948: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8003294C: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x80032950: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80032954: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
L_80032958:
    // 0x80032958: beq         $t4, $zero, L_80032988
    if (ctx->r12 == 0) {
        // 0x8003295C: andi        $t9, $a0, 0x80
        ctx->r25 = ctx->r4 & 0X80;
            goto L_80032988;
    }
    // 0x8003295C: andi        $t9, $a0, 0x80
    ctx->r25 = ctx->r4 & 0X80;
    // 0x80032960: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80032964: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80032968: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x8003296C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80032970: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x80032974: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80032978: addiu       $at, $zero, -0x301
    ctx->r1 = ADD32(0, -0X301);
    // 0x8003297C: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x80032980: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80032984: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
L_80032988:
    // 0x80032988: beql        $t9, $zero, L_800329C8
    if (ctx->r25 == 0) {
        // 0x8003298C: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_800329C8;
    }
    goto skip_0;
    // 0x8003298C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x80032990: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80032994: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x80032998: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8003299C: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x800329A0: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800329A4: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x800329A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800329AC: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x800329B0: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800329B4: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800329B8: andi        $t5, $t4, 0x300
    ctx->r13 = ctx->r12 & 0X300;
    // 0x800329BC: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x800329C0: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x800329C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_800329C8:
    // 0x800329C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800329CC: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800329D0: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x800329D4: jal         0x800326D0
    // 0x800329D8: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    LOOKUP_FUNC(0x800326D0)(rdram, ctx);
        goto after_1;
    // 0x800329D8: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    after_1:
    // 0x800329DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800329E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800329E4: jr          $ra
    // 0x800329E8: nop

    return;
    // 0x800329E8: nop

    // 0x800329EC: nop

;}
RECOMP_FUNC void osViSetEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800329F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800329F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800329F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800329FC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80032A00: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80032A04: jal         0x80032660
    // 0x80032A08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x80032660)(rdram, ctx);
        goto after_0;
    // 0x80032A08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80032A0C: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80032A10: lw          $t7, -0x512C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X512C);
    // 0x80032A14: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80032A18: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80032A1C: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80032A20: sw          $t6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r14;
    // 0x80032A24: lw          $t9, -0x512C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X512C);
    // 0x80032A28: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80032A2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80032A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80032A34: sw          $t8, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r24;
    // 0x80032A38: lw          $t1, -0x512C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X512C);
    // 0x80032A3C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80032A40: jal         0x800326D0
    // 0x80032A44: sh          $t0, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r8;
    LOOKUP_FUNC(0x800326D0)(rdram, ctx);
        goto after_1;
    // 0x80032A44: sh          $t0, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r8;
    after_1:
    // 0x80032A48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80032A4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80032A50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80032A54: jr          $ra
    // 0x80032A58: nop

    return;
    // 0x80032A58: nop

    // 0x80032A5C: nop

;}
