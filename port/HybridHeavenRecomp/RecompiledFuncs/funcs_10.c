#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FUN_80025b4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025B4C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80025B50: addiu       $a1, $a1, -0x425C
    ctx->r5 = ADD32(ctx->r5, -0X425C);
    // 0x80025B54: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80025B58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80025B5C: lbu         $a0, 0x70($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X70);
    // 0x80025B60: beq         $a0, $zero, L_80025B84
    if (ctx->r4 == 0) {
        // 0x80025B64: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80025B84;
    }
    // 0x80025B64: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80025B68: beq         $v0, $at, L_80025B90
    if (ctx->r2 == ctx->r1) {
        // 0x80025B6C: addiu       $t7, $a0, 0x1
        ctx->r15 = ADD32(ctx->r4, 0X1);
            goto L_80025B90;
    }
    // 0x80025B6C: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x80025B70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80025B74: beq         $v0, $at, L_80025BB8
    if (ctx->r2 == ctx->r1) {
        // 0x80025B78: addiu       $t2, $a0, -0x1
        ctx->r10 = ADD32(ctx->r4, -0X1);
            goto L_80025BB8;
    }
    // 0x80025B78: addiu       $t2, $a0, -0x1
    ctx->r10 = ADD32(ctx->r4, -0X1);
    // 0x80025B7C: jr          $ra
    // 0x80025B80: nop

    return;
    // 0x80025B80: nop

L_80025B84:
    // 0x80025B84: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x80025B88: jr          $ra
    // 0x80025B8C: sb          $t6, 0x70($v1)
    MEM_B(0X70, ctx->r3) = ctx->r14;
    return;
    // 0x80025B8C: sb          $t6, 0x70($v1)
    MEM_B(0X70, ctx->r3) = ctx->r14;
L_80025B90:
    // 0x80025B90: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80025B94: sb          $t7, 0x70($v1)
    MEM_B(0X70, ctx->r3) = ctx->r15;
    // 0x80025B98: addiu       $v0, $v0, -0x4260
    ctx->r2 = ADD32(ctx->r2, -0X4260);
    // 0x80025B9C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80025BA0: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80025BA4: sw          $t8, 0x78($t9)
    MEM_W(0X78, ctx->r25) = ctx->r24;
    // 0x80025BA8: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80025BAC: lw          $t1, 0x74($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X74);
    // 0x80025BB0: jr          $ra
    // 0x80025BB4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    return;
    // 0x80025BB4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_80025BB8:
    // 0x80025BB8: sb          $t2, 0x70($v1)
    MEM_B(0X70, ctx->r3) = ctx->r10;
    // 0x80025BBC: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80025BC0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80025BC4: addiu       $v0, $v0, -0x4260
    ctx->r2 = ADD32(ctx->r2, -0X4260);
    // 0x80025BC8: lw          $t4, 0x78($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X78);
    // 0x80025BCC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80025BD0: jr          $ra
    // 0x80025BD4: nop

    return;
    // 0x80025BD4: nop

;}
RECOMP_FUNC void FUN_80025bd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025BD8: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80025BDC: lw          $a3, -0x425C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X425C);
    // 0x80025BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025BE8: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80025BEC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80025BF0: addiu       $a1, $a1, -0x4260
    ctx->r5 = ADD32(ctx->r5, -0X4260);
    // 0x80025BF4: andi        $t7, $t6, 0x7FFF
    ctx->r15 = ctx->r14 & 0X7FFF;
    // 0x80025BF8: sltiu       $at, $t7, 0x100
    ctx->r1 = ctx->r15 < 0X100 ? 1 : 0;
    // 0x80025BFC: beq         $at, $zero, L_80025C0C
    if (ctx->r1 == 0) {
        // 0x80025C00: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80025C0C;
    }
    // 0x80025C00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80025C04: b           L_80025C0C
    // 0x80025C08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80025C0C;
    // 0x80025C08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80025C0C:
    // 0x80025C0C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80025C10: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80025C14: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x80025C18: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x80025C1C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80025C20: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80025C24: lbu         $t9, -0x4530($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X4530);
    // 0x80025C28: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80025C2C: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80025C30: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x80025C34: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80025C38: slti        $at, $a2, 0x80
    ctx->r1 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // 0x80025C3C: bne         $at, $zero, L_80025C4C
    if (ctx->r1 != 0) {
        // 0x80025C40: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_80025C4C;
    }
    // 0x80025C40: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80025C44: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x80025C48: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_80025C4C:
    // 0x80025C4C: lbu         $t0, 0x10($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X10);
    // 0x80025C50: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80025C54: beql        $t0, $v1, L_80025C84
    if (ctx->r8 == ctx->r3) {
        // 0x80025C58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80025C84;
    }
    goto skip_0;
    // 0x80025C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80025C5C: sb          $a2, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r6;
    // 0x80025C60: lbu         $t1, -0x454C($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X454C);
    // 0x80025C64: addiu       $t3, $t3, -0x4420
    ctx->r11 = ADD32(ctx->r11, -0X4420);
    // 0x80025C68: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x80025C6C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80025C70: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80025C74: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80025C78: jal         0x80030770
    // 0x80025C7C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    LOOKUP_FUNC(0x80030770)(rdram, ctx);
        goto after_0;
    // 0x80025C7C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_0:
    // 0x80025C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80025C84:
    // 0x80025C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025C88: jr          $ra
    // 0x80025C8C: nop

    return;
    // 0x80025C8C: nop

;}
RECOMP_FUNC void FUN_80025c90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025C90: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80025C94: addiu       $v0, $v0, -0x4260
    ctx->r2 = ADD32(ctx->r2, -0X4260);
    // 0x80025C98: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80025C9C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80025CA0: lw          $t8, -0x425C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X425C);
    // 0x80025CA4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80025CA8: sb          $t7, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r15;
    // 0x80025CAC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80025CB0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80025CB4: jr          $ra
    // 0x80025CB8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    return;
    // 0x80025CB8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80025CBC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80025CC0: lbu         $t6, -0x454C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X454C);
    // 0x80025CC4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80025CC8: bne         $t6, $at, L_80025CD4
    if (ctx->r14 != ctx->r1) {
        // 0x80025CCC: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80025CD4;
    }
    // 0x80025CCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80025CD0: sb          $zero, -0x4428($at)
    MEM_B(-0X4428, ctx->r1) = 0;
L_80025CD4:
    // 0x80025CD4: jr          $ra
    // 0x80025CD8: nop

    return;
    // 0x80025CD8: nop

;}
RECOMP_FUNC void FUN_80025cdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025CDC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80025CE0: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x80025CE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025CE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025CEC: lbu         $t6, 0xE($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XE);
    // 0x80025CF0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80025CF4: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80025CF8: beq         $t6, $zero, L_80025D38
    if (ctx->r14 == 0) {
        // 0x80025CFC: lui         $t8, 0x800D
        ctx->r24 = S32(0X800D << 16);
            goto L_80025D38;
    }
    // 0x80025CFC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80025D00: sb          $t7, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r15;
    // 0x80025D04: lbu         $t8, -0x454C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X454C);
    // 0x80025D08: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80025D0C: addiu       $t0, $t0, -0x4420
    ctx->r8 = ADD32(ctx->r8, -0X4420);
    // 0x80025D10: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80025D14: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80025D18: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80025D1C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x80025D20: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x80025D24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025D28: jal         0x80026950
    // 0x80025D2C: addiu       $a3, $zero, 0x1388
    ctx->r7 = ADD32(0, 0X1388);
    LOOKUP_FUNC(0x80026950)(rdram, ctx);
        goto after_0;
    // 0x80025D2C: addiu       $a3, $zero, 0x1388
    ctx->r7 = ADD32(0, 0X1388);
    after_0:
    // 0x80025D30: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80025D34: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
L_80025D38:
    // 0x80025D38: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80025D3C: addiu       $v1, $v1, -0x4260
    ctx->r3 = ADD32(ctx->r3, -0X4260);
    // 0x80025D40: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80025D44: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80025D48: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80025D4C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80025D50: sb          $t2, 0x21($v0)
    MEM_B(0X21, ctx->r2) = ctx->r10;
    // 0x80025D54: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80025D58: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80025D5C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80025D60: lw          $t6, -0x425C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X425C);
    // 0x80025D64: sb          $t5, 0x22($t6)
    MEM_B(0X22, ctx->r14) = ctx->r13;
    // 0x80025D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025D70: jr          $ra
    // 0x80025D74: nop

    return;
    // 0x80025D74: nop

;}
RECOMP_FUNC void FUN_80025d78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025D78: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80025D7C: addiu       $v0, $v0, -0x4260
    ctx->r2 = ADD32(ctx->r2, -0X4260);
    // 0x80025D80: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80025D84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025D88: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80025D8C: addiu       $a0, $a0, -0x425C
    ctx->r4 = ADD32(ctx->r4, -0X425C);
    // 0x80025D90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025D94: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80025D98: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80025D9C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80025DA0: sb          $t7, 0x21($t8)
    MEM_B(0X21, ctx->r24) = ctx->r15;
    // 0x80025DA4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80025DA8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80025DAC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80025DB0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80025DB4: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x80025DB8: sb          $t2, 0x22($t3)
    MEM_B(0X22, ctx->r11) = ctx->r10;
    // 0x80025DBC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80025DC0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80025DC4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80025DC8: lbu         $t6, -0x454C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X454C);
    // 0x80025DCC: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x80025DD0: beql        $at, $zero, L_80025E6C
    if (ctx->r1 == 0) {
        // 0x80025DD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80025E6C;
    }
    goto skip_0;
    // 0x80025DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80025DD8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80025DDC: lbu         $v1, 0x22($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X22);
    // 0x80025DE0: bnel        $v1, $zero, L_80025DF8
    if (ctx->r3 != 0) {
        // 0x80025DE4: lbu         $t7, 0x21($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X21);
            goto L_80025DF8;
    }
    goto skip_1;
    // 0x80025DE4: lbu         $t7, 0x21($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X21);
    skip_1:
    // 0x80025DE8: sb          $zero, 0x24($v0)
    MEM_B(0X24, ctx->r2) = 0;
    // 0x80025DEC: b           L_80025E24
    // 0x80025DF0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80025E24;
    // 0x80025DF0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80025DF4: lbu         $t7, 0x21($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X21);
L_80025DF8:
    // 0x80025DF8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80025DFC: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80025E00: mflo        $t8
    ctx->r24 = lo;
    // 0x80025E04: sra         $t9, $t8, 7
    ctx->r25 = S32(SIGNED(ctx->r24) >> 7);
    // 0x80025E08: sb          $t9, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r25;
    // 0x80025E0C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80025E10: lbu         $t0, 0x24($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X24);
    // 0x80025E14: bnel        $t0, $zero, L_80025E28
    if (ctx->r8 != 0) {
        // 0x80025E18: lbu         $t2, 0x6($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X6);
            goto L_80025E28;
    }
    goto skip_2;
    // 0x80025E18: lbu         $t2, 0x6($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X6);
    skip_2:
    // 0x80025E1C: sb          $t1, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r9;
    // 0x80025E20: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80025E24:
    // 0x80025E24: lbu         $t2, 0x6($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X6);
L_80025E28:
    // 0x80025E28: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80025E2C: sb          $t3, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r11;
    // 0x80025E30: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80025E34: lhu         $t4, 0x4C($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X4C);
    // 0x80025E38: beql        $t4, $zero, L_80025E54
    if (ctx->r12 == 0) {
        // 0x80025E3C: lbu         $t5, 0x6($v0)
        ctx->r13 = MEM_BU(ctx->r2, 0X6);
            goto L_80025E54;
    }
    goto skip_3;
    // 0x80025E3C: lbu         $t5, 0x6($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X6);
    skip_3:
    // 0x80025E40: jal         0x80024358
    // 0x80025E44: nop

    LOOKUP_FUNC(0x80024358)(rdram, ctx);
        goto after_0;
    // 0x80025E44: nop

    after_0:
    // 0x80025E48: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80025E4C: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x80025E50: lbu         $t5, 0x6($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X6);
L_80025E54:
    // 0x80025E54: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80025E58: beql        $t6, $zero, L_80025E6C
    if (ctx->r14 == 0) {
        // 0x80025E5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80025E6C;
    }
    goto skip_4;
    // 0x80025E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80025E60: jal         0x80023D04
    // 0x80025E64: nop

    LOOKUP_FUNC(0x80023D04)(rdram, ctx);
        goto after_1;
    // 0x80025E64: nop

    after_1:
    // 0x80025E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80025E6C:
    // 0x80025E6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025E70: jr          $ra
    // 0x80025E74: nop

    return;
    // 0x80025E74: nop

    // 0x80025E78: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80025E7C: addiu       $a0, $a0, -0x4260
    ctx->r4 = ADD32(ctx->r4, -0X4260);
    // 0x80025E80: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80025E84: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80025E88: addiu       $a1, $a1, -0x425C
    ctx->r5 = ADD32(ctx->r5, -0X425C);
    // 0x80025E8C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80025E90: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80025E94: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80025E98: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80025E9C: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x80025EA0: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80025EA4: sb          $t8, 0xB8($t0)
    MEM_B(0XB8, ctx->r8) = ctx->r24;
    // 0x80025EA8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80025EAC: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80025EB0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80025EB4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80025EB8: lbu         $t4, 0x0($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X0);
    // 0x80025EBC: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80025EC0: sb          $t4, 0xBB($t6)
    MEM_B(0XBB, ctx->r14) = ctx->r12;
    // 0x80025EC4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80025EC8: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80025ECC: jr          $ra
    // 0x80025ED0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    return;
    // 0x80025ED0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80025ed4(rdram, ctx);
;}
RECOMP_FUNC void FUN_80025ed4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025ED4: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80025ED8: addiu       $a3, $a3, -0x4260
    ctx->r7 = ADD32(ctx->r7, -0X4260);
    // 0x80025EDC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80025EE0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80025EE4: addiu       $a1, $a1, -0x424D
    ctx->r5 = ADD32(ctx->r5, -0X424D);
    // 0x80025EE8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80025EEC: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x80025EF0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80025EF4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80025EF8: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80025EFC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80025F00: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80025F04: subu        $a2, $t8, $t7
    ctx->r6 = SUB32(ctx->r24, ctx->r15);
    // 0x80025F08: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80025F0C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80025F10: beq         $at, $zero, L_80026050
    if (ctx->r1 == 0) {
        // 0x80025F14: sw          $t9, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r25;
            goto L_80026050;
    }
    // 0x80025F14: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80025F18: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80025F1C: lw          $a0, -0x425C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X425C);
    // 0x80025F20: addiu       $at, $zero, 0x1D3
    ctx->r1 = ADD32(0, 0X1D3);
    // 0x80025F24: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80025F28: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80025F2C: addiu       $t3, $t3, -0x41F0
    ctx->r11 = ADD32(ctx->r11, -0X41F0);
    // 0x80025F30: andi        $t6, $t5, 0x7FFF
    ctx->r14 = ctx->r13 & 0X7FFF;
    // 0x80025F34: bnel        $t6, $at, L_80025F4C
    if (ctx->r14 != ctx->r1) {
        // 0x80025F38: lhu         $t7, 0x0($t3)
        ctx->r15 = MEM_HU(ctx->r11, 0X0);
            goto L_80025F4C;
    }
    goto skip_0;
    // 0x80025F38: lhu         $t7, 0x0($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X0);
    skip_0:
    // 0x80025F3C: lbu         $t8, 0xBE($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XBE);
    // 0x80025F40: bne         $t8, $zero, L_80026050
    if (ctx->r24 != 0) {
        // 0x80025F44: nop
    
            goto L_80026050;
    }
    // 0x80025F44: nop

    // 0x80025F48: lhu         $t7, 0x0($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X0);
L_80025F4C:
    // 0x80025F4C: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x80025F50: addiu       $t4, $t4, -0x7DE0
    ctx->r12 = ADD32(ctx->r12, -0X7DE0);
    // 0x80025F54: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80025F58: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x80025F5C: andi        $a3, $t0, 0x7F
    ctx->r7 = ctx->r8 & 0X7F;
    // 0x80025F60: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x80025F64: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80025F68: lbu         $t1, 0x0($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0X0);
    // 0x80025F6C: andi        $a3, $a3, 0x7F
    ctx->r7 = ctx->r7 & 0X7F;
    // 0x80025F70: addu        $t6, $t4, $a3
    ctx->r14 = ADD32(ctx->r12, ctx->r7);
    // 0x80025F74: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x80025F78: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
    // 0x80025F7C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80025F80: lhu         $t5, -0x454E($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X454E);
    // 0x80025F84: sll         $t1, $t1, 8
    ctx->r9 = S32(ctx->r9 << 8);
    // 0x80025F88: sra         $t7, $t0, 7
    ctx->r15 = S32(SIGNED(ctx->r8) >> 7);
    // 0x80025F8C: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80025F90: addu        $t9, $t1, $t7
    ctx->r25 = ADD32(ctx->r9, ctx->r15);
    // 0x80025F94: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80025F98: addu        $t1, $t9, $t6
    ctx->r9 = ADD32(ctx->r25, ctx->r14);
    // 0x80025F9C: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
    // 0x80025FA0: andi        $t8, $t1, 0xFF
    ctx->r24 = ctx->r9 & 0XFF;
    // 0x80025FA4: slt         $at, $t8, $a2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80025FA8: bne         $at, $zero, L_80026050
    if (ctx->r1 != 0) {
        // 0x80025FAC: lui         $t3, 0x8005
        ctx->r11 = S32(0X8005 << 16);
            goto L_80026050;
    }
    // 0x80025FAC: lui         $t3, 0x8005
    ctx->r11 = S32(0X8005 << 16);
    // 0x80025FB0: addiu       $t3, $t3, -0x6718
    ctx->r11 = ADD32(ctx->r11, -0X6718);
    // 0x80025FB4: lbu         $t7, 0x0($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X0);
    // 0x80025FB8: sra         $a3, $t1, 8
    ctx->r7 = S32(SIGNED(ctx->r9) >> 8);
    // 0x80025FBC: andi        $a3, $a3, 0x7
    ctx->r7 = ctx->r7 & 0X7;
    // 0x80025FC0: bne         $t7, $v0, L_80025FE8
    if (ctx->r15 != ctx->r2) {
        // 0x80025FC4: andi        $a2, $a3, 0xFF
        ctx->r6 = ctx->r7 & 0XFF;
            goto L_80025FE8;
    }
    // 0x80025FC4: andi        $a2, $a3, 0xFF
    ctx->r6 = ctx->r7 & 0XFF;
    // 0x80025FC8: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x80025FCC: lbu         $t5, -0x6714($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X6714);
    // 0x80025FD0: andi        $t0, $a3, 0xFF
    ctx->r8 = ctx->r7 & 0XFF;
    // 0x80025FD4: bnel        $t5, $t0, L_80025FEC
    if (ctx->r13 != ctx->r8) {
        // 0x80025FD8: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80025FEC;
    }
    goto skip_1;
    // 0x80025FD8: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    skip_1:
    // 0x80025FDC: addiu       $a2, $t0, 0x1
    ctx->r6 = ADD32(ctx->r8, 0X1);
    // 0x80025FE0: andi        $a2, $a2, 0x7
    ctx->r6 = ctx->r6 & 0X7;
    // 0x80025FE4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_80025FE8:
    // 0x80025FE8: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_80025FEC:
    // 0x80025FEC: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80025FF0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80025FF4: addiu       $t6, $t6, -0x4248
    ctx->r14 = ADD32(ctx->r14, -0X4248);
    // 0x80025FF8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80025FFC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80026000: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80026004: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
    // 0x80026008: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x8002600C: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80026010: sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
    // 0x80026014: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80026018: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8002601C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80026020: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80026024: sb          $a2, -0x6714($at)
    MEM_B(-0X6714, ctx->r1) = ctx->r6;
    // 0x80026028: addiu       $t9, $t9, -0x775C
    ctx->r25 = ADD32(ctx->r25, -0X775C);
    // 0x8002602C: addu        $t5, $t8, $t7
    ctx->r13 = ADD32(ctx->r24, ctx->r15);
    // 0x80026030: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x80026034: sh          $t1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r9;
    // 0x80026038: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x8002603C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80026040: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x80026044: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
    // 0x80026048: srl         $t7, $t8, 16
    ctx->r15 = S32(U32(ctx->r24) >> 16);
    // 0x8002604C: sh          $t7, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r15;
L_80026050:
    // 0x80026050: jr          $ra
    // 0x80026054: nop

    return;
    // 0x80026054: nop

;}
RECOMP_FUNC void FUN_80026058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026058: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002605C: addiu       $v1, $v1, -0x4260
    ctx->r3 = ADD32(ctx->r3, -0X4260);
    // 0x80026060: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80026064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002606C: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x80026070: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80026074: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80026078: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002607C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80026080: jal         0x80026140
    // 0x80026084: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80026140)(rdram, ctx);
        goto after_0;
    // 0x80026084: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80026088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002608C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026090: jr          $ra
    // 0x80026094: nop

    return;
    // 0x80026094: nop

;}
RECOMP_FUNC void FUN_80026098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026098: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002609C: addiu       $v1, $v1, -0x4260
    ctx->r3 = ADD32(ctx->r3, -0X4260);
    // 0x800260A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800260A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800260A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800260AC: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800260B0: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x800260B4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800260B8: lbu         $a2, 0x0($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X0);
    // 0x800260BC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800260C0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800260C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800260C8: jal         0x80026140
    // 0x800260CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80026140)(rdram, ctx);
        goto after_0;
    // 0x800260CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800260D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800260D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800260D8: jr          $ra
    // 0x800260DC: nop

    return;
    // 0x800260DC: nop

;}
RECOMP_FUNC void FUN_800260e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800260E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800260E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800260E8: jal         0x800261C4
    // 0x800260EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x800261C4)(rdram, ctx);
        goto after_0;
    // 0x800260EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x800260F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800260F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800260F8: jr          $ra
    // 0x800260FC: nop

    return;
    // 0x800260FC: nop

;}
RECOMP_FUNC void FUN_80026100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026108: jal         0x800261C4
    // 0x8002610C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x800261C4)(rdram, ctx);
        goto after_0;
    // 0x8002610C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80026110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026118: jr          $ra
    // 0x8002611C: nop

    return;
    // 0x8002611C: nop

;}
RECOMP_FUNC void FUN_80026120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026128: jal         0x800261C4
    // 0x8002612C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x800261C4)(rdram, ctx);
        goto after_0;
    // 0x8002612C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80026130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026138: jr          $ra
    // 0x8002613C: nop

    return;
    // 0x8002613C: nop

;}
RECOMP_FUNC void FUN_80026140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026140: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80026144: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80026148: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8002614C: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x80026150: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80026154: lhu         $v0, -0x685C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X685C);
    // 0x80026158: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8002615C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80026160: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80026164: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80026168: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8002616C: beq         $v0, $zero, L_800261BC
    if (ctx->r2 == 0) {
        // 0x80026170: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_800261BC;
    }
    // 0x80026170: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80026174: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80026178: addiu       $a1, $a1, -0x4230
    ctx->r5 = ADD32(ctx->r5, -0X4230);
    // 0x8002617C: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80026180: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80026184: addiu       $t8, $t8, -0x4228
    ctx->r24 = ADD32(ctx->r24, -0X4228);
    // 0x80026188: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8002618C: beq         $at, $zero, L_800261BC
    if (ctx->r1 == 0) {
        // 0x80026190: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_800261BC;
    }
    // 0x80026190: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80026194: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x80026198: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8002619C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800261A0: lbu         $t9, 0x3($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3);
    // 0x800261A4: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x800261A8: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800261AC: sb          $a2, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r6;
    // 0x800261B0: sh          $a3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r7;
    // 0x800261B4: sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
    // 0x800261B8: sb          $t9, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r25;
L_800261BC:
    // 0x800261BC: jr          $ra
    // 0x800261C0: nop

    return;
    // 0x800261C0: nop

;}
RECOMP_FUNC void FUN_800261c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800261C4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800261C8: addiu       $v1, $v1, -0x4260
    ctx->r3 = ADD32(ctx->r3, -0X4260);
    // 0x800261CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800261D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800261D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800261D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800261DC: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800261E0: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x800261E4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800261E8: lbu         $a2, 0x0($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X0);
    // 0x800261EC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800261F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800261F4: lbu         $a3, 0x0($t7)
    ctx->r7 = MEM_BU(ctx->r15, 0X0);
    // 0x800261F8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800261FC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80026200: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x80026204: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80026208: sll         $a3, $a3, 8
    ctx->r7 = S32(ctx->r7 << 8);
    // 0x8002620C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80026210: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80026214: jal         0x80026140
    // 0x80026218: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    LOOKUP_FUNC(0x80026140)(rdram, ctx);
        goto after_0;
    // 0x80026218: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    after_0:
    // 0x8002621C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026224: jr          $ra
    // 0x80026228: nop

    return;
    // 0x80026228: nop

;}
RECOMP_FUNC void FUN_8002622c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002622C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80026230: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x80026234: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002623C: lbu         $t6, 0xE($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XE);
    // 0x80026240: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80026244: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80026248: beq         $t6, $zero, L_80026288
    if (ctx->r14 == 0) {
        // 0x8002624C: lui         $t8, 0x800D
        ctx->r24 = S32(0X800D << 16);
            goto L_80026288;
    }
    // 0x8002624C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80026250: sb          $t7, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r15;
    // 0x80026254: lbu         $t8, -0x454C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X454C);
    // 0x80026258: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8002625C: addiu       $t0, $t0, -0x4420
    ctx->r8 = ADD32(ctx->r8, -0X4420);
    // 0x80026260: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80026264: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80026268: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002626C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x80026270: lw          $a0, -0x6710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6710);
    // 0x80026274: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80026278: jal         0x80026950
    // 0x8002627C: addiu       $a3, $zero, 0x1388
    ctx->r7 = ADD32(0, 0X1388);
    LOOKUP_FUNC(0x80026950)(rdram, ctx);
        goto after_0;
    // 0x8002627C: addiu       $a3, $zero, 0x1388
    ctx->r7 = ADD32(0, 0X1388);
    after_0:
    // 0x80026280: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80026284: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
L_80026288:
    // 0x80026288: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8002628C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80026290: lw          $v0, -0x425C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X425C);
    // 0x80026294: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80026298: sb          $t1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r9;
    // 0x8002629C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800262A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800262A4: jr          $ra
    // 0x800262A8: nop

    return;
    // 0x800262A8: nop

    // 0x800262AC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800262B0: addiu       $v0, $v0, -0x4260
    ctx->r2 = ADD32(ctx->r2, -0X4260);
    // 0x800262B4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800262B8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800262BC: jr          $ra
    // 0x800262C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x800262C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800262C4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800262C8: addiu       $v0, $v0, -0x4260
    ctx->r2 = ADD32(ctx->r2, -0X4260);
    // 0x800262CC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800262D0: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800262D4: jr          $ra
    // 0x800262D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x800262D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800262DC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800262E0: addiu       $v0, $v0, -0x4260
    ctx->r2 = ADD32(ctx->r2, -0X4260);
    // 0x800262E4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800262E8: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x800262EC: jr          $ra
    // 0x800262F0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x800262F0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800262F4: nop

    // 0x800262F8: nop

    // 0x800262FC: nop

;}
RECOMP_FUNC void FUN_800267f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800267F0: mfc0        $t4, Status
    ctx->r12 = cop0_status_read(ctx);
    // 0x800267F4: andi        $v0, $t4, 0xFF01
    ctx->r2 = ctx->r12 & 0XFF01;
    // 0x800267F8: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x800267FC: addiu       $t0, $t0, -0x6680
    ctx->r8 = ADD32(ctx->r8, -0X6680);
    // 0x80026800: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80026804: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80026808: xor         $t0, $t3, $at
    ctx->r8 = ctx->r11 ^ ctx->r1;
    // 0x8002680C: andi        $t0, $t0, 0xFF00
    ctx->r8 = ctx->r8 & 0XFF00;
    // 0x80026810: or          $v0, $v0, $t0
    ctx->r2 = ctx->r2 | ctx->r8;
    // 0x80026814: lui         $t2, 0xA430
    ctx->r10 = S32(0XA430 << 16);
    // 0x80026818: lw          $t2, 0xC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XC);
    // 0x8002681C: beq         $t2, $zero, L_80026834
    if (ctx->r10 == 0) {
        // 0x80026820: srl         $t1, $t3, 16
        ctx->r9 = S32(U32(ctx->r11) >> 16);
            goto L_80026834;
    }
    // 0x80026820: srl         $t1, $t3, 16
    ctx->r9 = S32(U32(ctx->r11) >> 16);
    // 0x80026824: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80026828: xor         $t1, $t1, $at
    ctx->r9 = ctx->r9 ^ ctx->r1;
    // 0x8002682C: andi        $t1, $t1, 0x3F
    ctx->r9 = ctx->r9 & 0X3F;
    // 0x80026830: or          $t2, $t2, $t1
    ctx->r10 = ctx->r10 | ctx->r9;
L_80026834:
    // 0x80026834: sll         $t2, $t2, 16
    ctx->r10 = S32(ctx->r10 << 16);
    // 0x80026838: or          $v0, $v0, $t2
    ctx->r2 = ctx->r2 | ctx->r10;
    // 0x8002683C: lui         $at, 0x3F
    ctx->r1 = S32(0X3F << 16);
    // 0x80026840: and         $t0, $a0, $at
    ctx->r8 = ctx->r4 & ctx->r1;
    // 0x80026844: and         $t0, $t0, $t3
    ctx->r8 = ctx->r8 & ctx->r11;
    // 0x80026848: srl         $t0, $t0, 15
    ctx->r8 = S32(U32(ctx->r8) >> 15);
    // 0x8002684C: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x80026850: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x80026854: lhu         $t2, -0x2DE0($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2DE0);
    // 0x80026858: lui         $at, 0xA430
    ctx->r1 = S32(0XA430 << 16);
    // 0x8002685C: sw          $t2, 0xC($at)
    MEM_W(0XC, ctx->r1) = ctx->r10;
    // 0x80026860: andi        $t0, $a0, 0xFF01
    ctx->r8 = ctx->r4 & 0XFF01;
    // 0x80026864: andi        $t1, $t3, 0xFF00
    ctx->r9 = ctx->r11 & 0XFF00;
    // 0x80026868: and         $t0, $t0, $t1
    ctx->r8 = ctx->r8 & ctx->r9;
    // 0x8002686C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80026870: ori         $at, $at, 0xFF
    ctx->r1 = ctx->r1 | 0XFF;
    // 0x80026874: and         $t4, $t4, $at
    ctx->r12 = ctx->r12 & ctx->r1;
    // 0x80026878: or          $t4, $t4, $t0
    ctx->r12 = ctx->r12 | ctx->r8;
    // 0x8002687C: mtc0        $t4, Status
    cop0_status_write(ctx, ctx->r12);    // 0x80026880: nop

    // 0x80026884: nop

    // 0x80026888: jr          $ra
    // 0x8002688C: nop

    return;
    // 0x8002688C: nop

;}
RECOMP_FUNC void FUN_80026890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026890: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80026894: beql        $v0, $zero, L_800268A8
    if (ctx->r2 == 0) {
        // 0x80026898: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_800268A8;
    }
    goto skip_0;
    // 0x80026898: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x8002689C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800268A0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800268A4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_800268A8:
    // 0x800268A8: beq         $v0, $zero, L_800268B8
    if (ctx->r2 == 0) {
        // 0x800268AC: nop
    
            goto L_800268B8;
    }
    // 0x800268AC: nop

    // 0x800268B0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800268B4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800268B8:
    // 0x800268B8: jr          $ra
    // 0x800268BC: nop

    return;
    // 0x800268BC: nop

;}
RECOMP_FUNC void FUN_800268c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800268C0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800268C4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800268C8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800268CC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800268D0: beq         $v0, $zero, L_800268DC
    if (ctx->r2 == 0) {
        // 0x800268D4: nop
    
            goto L_800268DC;
    }
    // 0x800268D4: nop

    // 0x800268D8: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
L_800268DC:
    // 0x800268DC: jr          $ra
    // 0x800268E0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    return;
    // 0x800268E0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800268e4(rdram, ctx);
;}
RECOMP_FUNC void FUN_800268e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800268E4: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x800268E8: lw          $t6, -0x6710($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6710);
    // 0x800268EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800268F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800268F4: beql        $t6, $zero, L_80026910
    if (ctx->r14 == 0) {
        // 0x800268F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80026910;
    }
    goto skip_0;
    // 0x800268F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800268FC: jal         0x80034F60
    // 0x80026900: nop

    LOOKUP_FUNC(0x80034F60)(rdram, ctx);
        goto after_0;
    // 0x80026900: nop

    after_0:
    // 0x80026904: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80026908: sw          $zero, -0x6710($at)
    MEM_W(-0X6710, ctx->r1) = 0;
    // 0x8002690C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80026910:
    // 0x80026910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026914: jr          $ra
    // 0x80026918: nop

    return;
    // 0x80026918: nop

;}
RECOMP_FUNC void FUN_8002691c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002691C: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x80026920: addiu       $v0, $v0, -0x6710
    ctx->r2 = ADD32(ctx->r2, -0X6710);
    // 0x80026924: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80026928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002692C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026930: bnel        $t6, $zero, L_80026944
    if (ctx->r14 != 0) {
        // 0x80026934: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80026944;
    }
    goto skip_0;
    // 0x80026934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80026938: jal         0x8002C1D0
    // 0x8002693C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    LOOKUP_FUNC(0x8002C1D0)(rdram, ctx);
        goto after_0;
    // 0x8002693C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_0:
    // 0x80026940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80026944:
    // 0x80026944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026948: jr          $ra
    // 0x8002694C: nop

    return;
    // 0x8002694C: nop

;}
RECOMP_FUNC void FUN_80026950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026950: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026958: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002695C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80026960: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80026964: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x80026968: beql        $t7, $zero, L_800269E0
    if (ctx->r15 == 0) {
        // 0x8002696C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800269E0;
    }
    goto skip_0;
    // 0x8002696C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80026970: jal         0x8002C6A0
    // 0x80026974: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8002C6A0)(rdram, ctx);
        goto after_0;
    // 0x80026974: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80026978: beq         $v0, $zero, L_800269DC
    if (ctx->r2 == 0) {
        // 0x8002697C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800269DC;
    }
    // 0x8002697C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80026980: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80026984: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x80026988: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8002698C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80026990: lw          $t1, 0xD8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD8);
    // 0x80026994: sh          $t3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r11;
    // 0x80026998: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8002699C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800269A0: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x800269A4: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    // 0x800269A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800269AC: jal         0x8002C7CC
    // 0x800269B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x8002C7CC)(rdram, ctx);
        goto after_1;
    // 0x800269B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800269B4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800269B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800269BC: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x800269C0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800269C4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800269C8: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x800269CC: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x800269D0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800269D4: jalr        $t9
    // 0x800269D8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800269D8: nop

    after_2:
L_800269DC:
    // 0x800269DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800269E0:
    // 0x800269E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800269E4: jr          $ra
    // 0x800269E8: nop

    return;
    // 0x800269E8: nop

    // 0x800269EC: nop

;}
RECOMP_FUNC void FUN_800269f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800269F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800269F4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800269F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800269FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80026A00: addiu       $t6, $t6, -0x41E0
    ctx->r14 = ADD32(ctx->r14, -0X41E0);
    // 0x80026A04: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80026A08: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80026A0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80026A10: jal         0x800317D0
    // 0x80026A14: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x800317D0)(rdram, ctx);
        goto after_0;
    // 0x80026A14: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
    // 0x80026A18: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80026A1C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80026A20: beq         $t8, $zero, L_80026A38
    if (ctx->r24 == 0) {
        // 0x80026A24: nop
    
            goto L_80026A38;
    }
    // 0x80026A24: nop

    // 0x80026A28: jal         0x80028A10
    // 0x80026A2C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_1;
    // 0x80026A2C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x80026A30: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80026A34: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
L_80026A38:
    // 0x80026A38: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80026A3C: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x80026A40: beq         $t1, $zero, L_80026A58
    if (ctx->r9 == 0) {
        // 0x80026A44: nop
    
            goto L_80026A58;
    }
    // 0x80026A44: nop

    // 0x80026A48: jal         0x80028A10
    // 0x80026A4C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_2;
    // 0x80026A4C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_2:
    // 0x80026A50: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80026A54: sw          $v0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r2;
L_80026A58:
    // 0x80026A58: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80026A5C: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x80026A60: beq         $t4, $zero, L_80026A78
    if (ctx->r12 == 0) {
        // 0x80026A64: nop
    
            goto L_80026A78;
    }
    // 0x80026A64: nop

    // 0x80026A68: jal         0x80028A10
    // 0x80026A6C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_3;
    // 0x80026A6C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_3:
    // 0x80026A70: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80026A74: sw          $v0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r2;
L_80026A78:
    // 0x80026A78: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80026A7C: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x80026A80: beq         $t7, $zero, L_80026A98
    if (ctx->r15 == 0) {
        // 0x80026A84: nop
    
            goto L_80026A98;
    }
    // 0x80026A84: nop

    // 0x80026A88: jal         0x80028A10
    // 0x80026A8C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_4;
    // 0x80026A8C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_4:
    // 0x80026A90: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80026A94: sw          $v0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r2;
L_80026A98:
    // 0x80026A98: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80026A9C: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x80026AA0: beq         $t0, $zero, L_80026AB8
    if (ctx->r8 == 0) {
        // 0x80026AA4: nop
    
            goto L_80026AB8;
    }
    // 0x80026AA4: nop

    // 0x80026AA8: jal         0x80028A10
    // 0x80026AAC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_5;
    // 0x80026AAC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_5:
    // 0x80026AB0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80026AB4: sw          $v0, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r2;
L_80026AB8:
    // 0x80026AB8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80026ABC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80026AC0: beq         $t3, $zero, L_80026AD8
    if (ctx->r11 == 0) {
        // 0x80026AC4: nop
    
            goto L_80026AD8;
    }
    // 0x80026AC4: nop

    // 0x80026AC8: jal         0x80028A10
    // 0x80026ACC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_6;
    // 0x80026ACC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_6:
    // 0x80026AD0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80026AD4: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
L_80026AD8:
    // 0x80026AD8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80026ADC: lw          $t6, 0x38($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X38);
    // 0x80026AE0: beq         $t6, $zero, L_80026AF8
    if (ctx->r14 == 0) {
        // 0x80026AE4: nop
    
            goto L_80026AF8;
    }
    // 0x80026AE4: nop

    // 0x80026AE8: jal         0x80028A10
    // 0x80026AEC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    LOOKUP_FUNC(0x80028A10)(rdram, ctx);
        goto after_7;
    // 0x80026AEC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_7:
    // 0x80026AF0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80026AF4: sw          $v0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r2;
L_80026AF8:
    // 0x80026AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026AFC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80026B00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026B04: jr          $ra
    // 0x80026B08: nop

    return;
    // 0x80026B08: nop

;}
RECOMP_FUNC void FUN_80026e58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026E58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80026E5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80026E60: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80026E64: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80026E68: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x80026E6C: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80026E70: ddivu       $zero, $t6, $t7
    DDIVU(U64(ctx->r14), U64(ctx->r15), &lo, &hi);
    // 0x80026E74: bne         $t7, $zero, L_80026E80
    if (ctx->r15 != 0) {
        // 0x80026E78: nop
    
            goto L_80026E80;
    }
    // 0x80026E78: nop

    // 0x80026E7C: break       7
    do_break(2147643004);
L_80026E80:
    // 0x80026E80: mflo        $v0
    ctx->r2 = lo;
    // 0x80026E84: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x80026E88: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x80026E8C: jr          $ra
    // 0x80026E90: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80026E90: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    // 0x80026E94: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80026E98: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80026E9C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80026EA0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80026EA4: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x80026EA8: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80026EAC: dsllv       $v0, $t6, $t7
    ctx->r2 = ctx->r14 << (ctx->r15 & 63);
    // 0x80026EB0: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x80026EB4: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x80026EB8: jr          $ra
    // 0x80026EBC: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80026EBC: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    // 0x80026EC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80026EC4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80026EC8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80026ECC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80026ED0: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x80026ED4: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80026ED8: ddivu       $zero, $t6, $t7
    DDIVU(U64(ctx->r14), U64(ctx->r15), &lo, &hi);
    // 0x80026EDC: bne         $t7, $zero, L_80026EE8
    if (ctx->r15 != 0) {
        // 0x80026EE0: nop
    
            goto L_80026EE8;
    }
    // 0x80026EE0: nop

    // 0x80026EE4: break       7
    do_break(2147643108);
L_80026EE8:
    // 0x80026EE8: mfhi        $v0
    ctx->r2 = hi;
    // 0x80026EEC: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x80026EF0: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x80026EF4: jr          $ra
    // 0x80026EF8: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80026EF8: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    // 0x80026EFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80026F00: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80026F04: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80026F08: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80026F0C: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x80026F10: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80026F14: ddiv        $zero, $t6, $t7
    DDIV(S64(ctx->r14), S64(ctx->r15), &lo, &hi);
    // 0x80026F18: nop

    // 0x80026F1C: bne         $t7, $zero, L_80026F28
    if (ctx->r15 != 0) {
        // 0x80026F20: nop
    
            goto L_80026F28;
    }
    // 0x80026F20: nop

    // 0x80026F24: break       7
    do_break(2147643172);
L_80026F28:
    // 0x80026F28: daddiu      $at, $zero, -0x1
    ctx->r1 = 0 + -0X1;
    // 0x80026F2C: bne         $t7, $at, L_80026F44
    if (ctx->r15 != ctx->r1) {
        // 0x80026F30: daddiu      $at, $zero, 0x1
        ctx->r1 = 0 + 0X1;
            goto L_80026F44;
    }
    // 0x80026F30: daddiu      $at, $zero, 0x1
    ctx->r1 = 0 + 0X1;
    // 0x80026F34: dsll32      $at, $at, 31
    ctx->r1 = ctx->r1 << (31 + 32);
    // 0x80026F38: bne         $t6, $at, L_80026F44
    if (ctx->r14 != ctx->r1) {
        // 0x80026F3C: nop
    
            goto L_80026F44;
    }
    // 0x80026F3C: nop

    // 0x80026F40: break       6
    do_break(2147643200);
L_80026F44:
    // 0x80026F44: mflo        $v0
    ctx->r2 = lo;
    // 0x80026F48: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x80026F4C: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x80026F50: jr          $ra
    // 0x80026F54: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80026F54: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80026f58(rdram, ctx);
;}
RECOMP_FUNC void FUN_80026f58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026F58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80026F5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80026F60: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80026F64: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80026F68: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x80026F6C: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80026F70: dmultu      $t6, $t7
    DMULTU(U64(ctx->r14), U64(ctx->r15), &lo, &hi);
    // 0x80026F74: mflo        $v0
    ctx->r2 = lo;
    // 0x80026F78: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x80026F7C: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x80026F80: jr          $ra
    // 0x80026F84: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80026F84: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    // 0x80026F88: lh          $t7, 0x12($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X12);
    // 0x80026F8C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80026F90: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80026F94: ld          $t6, 0x8($sp)
    ctx->r14 = LD(ctx->r29, 0X8);
    // 0x80026F98: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x80026F9C: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x80026FA0: ddivu       $zero, $t6, $t9
    DDIVU(U64(ctx->r14), U64(ctx->r25), &lo, &hi);
    // 0x80026FA4: bne         $t9, $zero, L_80026FB0
    if (ctx->r25 != 0) {
        // 0x80026FA8: nop
    
            goto L_80026FB0;
    }
    // 0x80026FA8: nop

    // 0x80026FAC: break       7
    do_break(2147643308);
L_80026FB0:
    // 0x80026FB0: mflo        $t0
    ctx->r8 = lo;
    // 0x80026FB4: sd          $t0, 0x0($a0)
    SD(ctx->r8, 0X0, ctx->r4);
    // 0x80026FB8: lh          $t2, 0x12($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X12);
    // 0x80026FBC: ld          $t1, 0x8($sp)
    ctx->r9 = LD(ctx->r29, 0X8);
    // 0x80026FC0: or          $t3, $t2, $zero
    ctx->r11 = ctx->r10 | 0;
    // 0x80026FC4: or          $t4, $t3, $zero
    ctx->r12 = ctx->r11 | 0;
    // 0x80026FC8: ddivu       $zero, $t1, $t4
    DDIVU(U64(ctx->r9), U64(ctx->r12), &lo, &hi);
    // 0x80026FCC: bne         $t4, $zero, L_80026FD8
    if (ctx->r12 != 0) {
        // 0x80026FD0: nop
    
            goto L_80026FD8;
    }
    // 0x80026FD0: nop

    // 0x80026FD4: break       7
    do_break(2147643348);
L_80026FD8:
    // 0x80026FD8: mfhi        $t5
    ctx->r13 = hi;
    // 0x80026FDC: sd          $t5, 0x0($a1)
    SD(ctx->r13, 0X0, ctx->r5);
    // 0x80026FE0: jr          $ra
    // 0x80026FE4: nop

    return;
    // 0x80026FE4: nop

;}
RECOMP_FUNC void FUN_80026fe8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026FE8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80026FEC: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x80026FF0: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x80026FF4: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x80026FF8: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x80026FFC: ld          $t7, 0x10($sp)
    ctx->r15 = LD(ctx->r29, 0X10);
    // 0x80027000: ld          $t6, 0x8($sp)
    ctx->r14 = LD(ctx->r29, 0X8);
    // 0x80027004: ddiv        $zero, $t6, $t7
    DDIV(S64(ctx->r14), S64(ctx->r15), &lo, &hi);
    // 0x80027008: nop

    // 0x8002700C: bne         $t7, $zero, L_80027018
    if (ctx->r15 != 0) {
        // 0x80027010: nop
    
            goto L_80027018;
    }
    // 0x80027010: nop

    // 0x80027014: break       7
    do_break(2147643412);
L_80027018:
    // 0x80027018: daddiu      $at, $zero, -0x1
    ctx->r1 = 0 + -0X1;
    // 0x8002701C: bne         $t7, $at, L_80027034
    if (ctx->r15 != ctx->r1) {
        // 0x80027020: daddiu      $at, $zero, 0x1
        ctx->r1 = 0 + 0X1;
            goto L_80027034;
    }
    // 0x80027020: daddiu      $at, $zero, 0x1
    ctx->r1 = 0 + 0X1;
    // 0x80027024: dsll32      $at, $at, 31
    ctx->r1 = ctx->r1 << (31 + 32);
    // 0x80027028: bne         $t6, $at, L_80027034
    if (ctx->r14 != ctx->r1) {
        // 0x8002702C: nop
    
            goto L_80027034;
    }
    // 0x8002702C: nop

    // 0x80027030: break       6
    do_break(2147643440);
L_80027034:
    // 0x80027034: mfhi        $t8
    ctx->r24 = hi;
    // 0x80027038: sd          $t8, 0x0($sp)
    SD(ctx->r24, 0X0, ctx->r29);
    // 0x8002703C: bgez        $t8, L_8002704C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80027040: nop
    
            goto L_8002704C;
    }
    // 0x80027040: nop

    // 0x80027044: bgtz        $t7, L_80027064
    if (SIGNED(ctx->r15) > 0) {
        // 0x80027048: nop
    
            goto L_80027064;
    }
    // 0x80027048: nop

L_8002704C:
    // 0x8002704C: ld          $t9, 0x0($sp)
    ctx->r25 = LD(ctx->r29, 0X0);
    // 0x80027050: blez        $t9, L_80027074
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80027054: nop
    
            goto L_80027074;
    }
    // 0x80027054: nop

    // 0x80027058: ld          $t0, 0x10($sp)
    ctx->r8 = LD(ctx->r29, 0X10);
    // 0x8002705C: bgez        $t0, L_80027074
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80027060: nop
    
            goto L_80027074;
    }
    // 0x80027060: nop

L_80027064:
    // 0x80027064: ld          $t1, 0x0($sp)
    ctx->r9 = LD(ctx->r29, 0X0);
    // 0x80027068: ld          $t2, 0x10($sp)
    ctx->r10 = LD(ctx->r29, 0X10);
    // 0x8002706C: daddu       $t3, $t1, $t2
    ctx->r11 = ctx->r9 + ctx->r10;
    // 0x80027070: sd          $t3, 0x0($sp)
    SD(ctx->r11, 0X0, ctx->r29);
L_80027074:
    // 0x80027074: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80027078: lw          $v1, 0x4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4);
    // 0x8002707C: jr          $ra
    // 0x80027080: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80027080: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80027084: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80027088: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8002708C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80027090: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80027094: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x80027098: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x8002709C: dsrav       $v0, $t6, $t7
    ctx->r2 = SIGNED(ctx->r14) >> (ctx->r15 & 63);
    // 0x800270A0: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x800270A4: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x800270A8: jr          $ra
    // 0x800270AC: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x800270AC: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    // 0x800270B0: lui         $k0, 0x8002
    ctx->r26 = S32(0X8002 << 16);
    // 0x800270B4: addiu       $k0, $k0, 0x70C0
    ctx->r26 = ADD32(ctx->r26, 0X70C0);
    // 0x800270B8: jr          $k0
    // 0x800270BC: nop

    LOOKUP_FUNC(ctx->r26)(rdram, ctx);
    return;
    // 0x800270BC: nop

    // 0x800270C0: lui         $k0, 0x800D
    ctx->r26 = S32(0X800D << 16);
    // 0x800270C4: addiu       $k0, $k0, -0x3FE0
    ctx->r26 = ADD32(ctx->r26, -0X3FE0);
    // 0x800270C8: sd          $at, 0x20($k0)
    SD(ctx->r1, 0X20, ctx->r26);
    // 0x800270CC: mfc0        $k1, Status
    ctx->r27 = cop0_status_read(ctx);
    // 0x800270D0: sw          $k1, 0x118($k0)
    MEM_W(0X118, ctx->r26) = ctx->r27;
    // 0x800270D4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800270D8: and         $k1, $k1, $at
    ctx->r27 = ctx->r27 & ctx->r1;
    // 0x800270DC: mtc0        $k1, Status
    cop0_status_write(ctx, ctx->r27);    // 0x800270E0: sd          $t0, 0x58($k0)
    SD(ctx->r8, 0X58, ctx->r26);
    // 0x800270E4: sd          $t1, 0x60($k0)
    SD(ctx->r9, 0X60, ctx->r26);
    // 0x800270E8: sd          $t2, 0x68($k0)
    SD(ctx->r10, 0X68, ctx->r26);
    // 0x800270EC: sw          $zero, 0x18($k0)
    MEM_W(0X18, ctx->r26) = 0;
    // 0x800270F0: mfc0        $t0, Cause
    ctx->r8 = cop0_cause_read(ctx);
    // 0x800270F4: or          $t0, $k0, $zero
    ctx->r8 = ctx->r26 | 0;
    // 0x800270F8: lui         $k0, 0x8005
    ctx->r26 = S32(0X8005 << 16);
    // 0x800270FC: lw          $k0, -0x66C0($k0)
    ctx->r26 = MEM_W(ctx->r26, -0X66C0);
    // 0x80027100: ld          $t1, 0x20($t0)
    ctx->r9 = LD(ctx->r8, 0X20);
    // 0x80027104: sd          $t1, 0x20($k0)
    SD(ctx->r9, 0X20, ctx->r26);
    // 0x80027108: ld          $t1, 0x118($t0)
    ctx->r9 = LD(ctx->r8, 0X118);
    // 0x8002710C: sd          $t1, 0x118($k0)
    SD(ctx->r9, 0X118, ctx->r26);
    // 0x80027110: ld          $t1, 0x58($t0)
    ctx->r9 = LD(ctx->r8, 0X58);
    // 0x80027114: sd          $t1, 0x58($k0)
    SD(ctx->r9, 0X58, ctx->r26);
    // 0x80027118: ld          $t1, 0x60($t0)
    ctx->r9 = LD(ctx->r8, 0X60);
    // 0x8002711C: sd          $t1, 0x60($k0)
    SD(ctx->r9, 0X60, ctx->r26);
    // 0x80027120: ld          $t1, 0x68($t0)
    ctx->r9 = LD(ctx->r8, 0X68);
    // 0x80027124: sd          $t1, 0x68($k0)
    SD(ctx->r9, 0X68, ctx->r26);
    // 0x80027128: lw          $k1, 0x118($k0)
    ctx->r27 = MEM_W(ctx->r26, 0X118);
    // 0x8002712C: mflo        $t0
    ctx->r8 = lo;
    // 0x80027130: sd          $t0, 0x108($k0)
    SD(ctx->r8, 0X108, ctx->r26);
    // 0x80027134: mfhi        $t0
    ctx->r8 = hi;
    // 0x80027138: andi        $t1, $k1, 0xFF00
    ctx->r9 = ctx->r27 & 0XFF00;
    // 0x8002713C: sd          $v0, 0x28($k0)
    SD(ctx->r2, 0X28, ctx->r26);
    // 0x80027140: sd          $v1, 0x30($k0)
    SD(ctx->r3, 0X30, ctx->r26);
    // 0x80027144: sd          $a0, 0x38($k0)
    SD(ctx->r4, 0X38, ctx->r26);
    // 0x80027148: sd          $a1, 0x40($k0)
    SD(ctx->r5, 0X40, ctx->r26);
    // 0x8002714C: sd          $a2, 0x48($k0)
    SD(ctx->r6, 0X48, ctx->r26);
    // 0x80027150: sd          $a3, 0x50($k0)
    SD(ctx->r7, 0X50, ctx->r26);
    // 0x80027154: sd          $t3, 0x70($k0)
    SD(ctx->r11, 0X70, ctx->r26);
    // 0x80027158: sd          $t4, 0x78($k0)
    SD(ctx->r12, 0X78, ctx->r26);
    // 0x8002715C: sd          $t5, 0x80($k0)
    SD(ctx->r13, 0X80, ctx->r26);
    // 0x80027160: sd          $t6, 0x88($k0)
    SD(ctx->r14, 0X88, ctx->r26);
    // 0x80027164: sd          $t7, 0x90($k0)
    SD(ctx->r15, 0X90, ctx->r26);
    // 0x80027168: sd          $s0, 0x98($k0)
    SD(ctx->r16, 0X98, ctx->r26);
    // 0x8002716C: sd          $s1, 0xA0($k0)
    SD(ctx->r17, 0XA0, ctx->r26);
    // 0x80027170: sd          $s2, 0xA8($k0)
    SD(ctx->r18, 0XA8, ctx->r26);
    // 0x80027174: sd          $s3, 0xB0($k0)
    SD(ctx->r19, 0XB0, ctx->r26);
    // 0x80027178: sd          $s4, 0xB8($k0)
    SD(ctx->r20, 0XB8, ctx->r26);
    // 0x8002717C: sd          $s5, 0xC0($k0)
    SD(ctx->r21, 0XC0, ctx->r26);
    // 0x80027180: sd          $s6, 0xC8($k0)
    SD(ctx->r22, 0XC8, ctx->r26);
    // 0x80027184: sd          $s7, 0xD0($k0)
    SD(ctx->r23, 0XD0, ctx->r26);
    // 0x80027188: sd          $t8, 0xD8($k0)
    SD(ctx->r24, 0XD8, ctx->r26);
    // 0x8002718C: sd          $t9, 0xE0($k0)
    SD(ctx->r25, 0XE0, ctx->r26);
    // 0x80027190: sd          $gp, 0xE8($k0)
    SD(ctx->r28, 0XE8, ctx->r26);
    // 0x80027194: sd          $sp, 0xF0($k0)
    SD(ctx->r29, 0XF0, ctx->r26);
    // 0x80027198: sd          $fp, 0xF8($k0)
    SD(ctx->r30, 0XF8, ctx->r26);
    // 0x8002719C: sd          $ra, 0x100($k0)
    SD(ctx->r31, 0X100, ctx->r26);
    // 0x800271A0: beq         $t1, $zero, L_800271E8
    if (ctx->r9 == 0) {
        // 0x800271A4: sd          $t0, 0x110($k0)
        SD(ctx->r8, 0X110, ctx->r26);
            goto L_800271E8;
    }
    // 0x800271A4: sd          $t0, 0x110($k0)
    SD(ctx->r8, 0X110, ctx->r26);
    // 0x800271A8: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x800271AC: addiu       $t0, $t0, -0x6680
    ctx->r8 = ADD32(ctx->r8, -0X6680);
    // 0x800271B0: lw          $t0, 0x0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X0);
    // 0x800271B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800271B8: xor         $t2, $t0, $at
    ctx->r10 = ctx->r8 ^ ctx->r1;
    // 0x800271BC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800271C0: andi        $t2, $t2, 0xFF00
    ctx->r10 = ctx->r10 & 0XFF00;
    // 0x800271C4: ori         $at, $at, 0xFF
    ctx->r1 = ctx->r1 | 0XFF;
    // 0x800271C8: or          $t4, $t1, $t2
    ctx->r12 = ctx->r9 | ctx->r10;
    // 0x800271CC: and         $t3, $k1, $at
    ctx->r11 = ctx->r27 & ctx->r1;
    // 0x800271D0: andi        $t0, $t0, 0xFF00
    ctx->r8 = ctx->r8 & 0XFF00;
    // 0x800271D4: or          $t3, $t3, $t4
    ctx->r11 = ctx->r11 | ctx->r12;
    // 0x800271D8: and         $t1, $t1, $t0
    ctx->r9 = ctx->r9 & ctx->r8;
    // 0x800271DC: and         $k1, $k1, $at
    ctx->r27 = ctx->r27 & ctx->r1;
    // 0x800271E0: sw          $t3, 0x118($k0)
    MEM_W(0X118, ctx->r26) = ctx->r11;
    // 0x800271E4: or          $k1, $k1, $t1
    ctx->r27 = ctx->r27 | ctx->r9;
L_800271E8:
    // 0x800271E8: lui         $t1, 0xA430
    ctx->r9 = S32(0XA430 << 16);
    // 0x800271EC: lw          $t1, 0xC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XC);
    // 0x800271F0: beq         $t1, $zero, L_80027220
    if (ctx->r9 == 0) {
        // 0x800271F4: nop
    
            goto L_80027220;
    }
    // 0x800271F4: nop

    // 0x800271F8: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x800271FC: addiu       $t0, $t0, -0x6680
    ctx->r8 = ADD32(ctx->r8, -0X6680);
    // 0x80027200: lw          $t0, 0x0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X0);
    // 0x80027204: lw          $t4, 0x128($k0)
    ctx->r12 = MEM_W(ctx->r26, 0X128);
    // 0x80027208: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002720C: srl         $t0, $t0, 16
    ctx->r8 = S32(U32(ctx->r8) >> 16);
    // 0x80027210: xor         $t0, $t0, $at
    ctx->r8 = ctx->r8 ^ ctx->r1;
    // 0x80027214: andi        $t0, $t0, 0x3F
    ctx->r8 = ctx->r8 & 0X3F;
    // 0x80027218: and         $t0, $t0, $t4
    ctx->r8 = ctx->r8 & ctx->r12;
    // 0x8002721C: or          $t1, $t1, $t0
    ctx->r9 = ctx->r9 | ctx->r8;
L_80027220:
    // 0x80027220: sw          $t1, 0x128($k0)
    MEM_W(0X128, ctx->r26) = ctx->r9;
    // 0x80027224: mfc0        $t0, EPC
    ctx->r8 = cop0_register_read(ctx, 14);
    // 0x80027228: sw          $t0, 0x11C($k0)
    MEM_W(0X11C, ctx->r26) = ctx->r8;
    // 0x8002722C: lw          $t0, 0x18($k0)
    ctx->r8 = MEM_W(ctx->r26, 0X18);
    // 0x80027230: beq         $t0, $zero, L_80027284
    if (ctx->r8 == 0) {
        // 0x80027234: nop
    
            goto L_80027284;
    }
    // 0x80027234: nop

    // 0x80027238: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8002723C: nop

    // 0x80027240: sw          $t0, 0x12C($k0)
    MEM_W(0X12C, ctx->r26) = ctx->r8;
    // 0x80027244: sdc1        $f0, 0x130($k0)
    CHECK_FR(ctx, 0);
    SD(ctx->f0.u64, 0X130, ctx->r26);
    // 0x80027248: sdc1        $f2, 0x138($k0)
    CHECK_FR(ctx, 2);
    SD(ctx->f2.u64, 0X138, ctx->r26);
    // 0x8002724C: sdc1        $f4, 0x140($k0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X140, ctx->r26);
    // 0x80027250: sdc1        $f6, 0x148($k0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X148, ctx->r26);
    // 0x80027254: sdc1        $f8, 0x150($k0)
    CHECK_FR(ctx, 8);
    SD(ctx->f8.u64, 0X150, ctx->r26);
    // 0x80027258: sdc1        $f10, 0x158($k0)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X158, ctx->r26);
    // 0x8002725C: sdc1        $f12, 0x160($k0)
    CHECK_FR(ctx, 12);
    SD(ctx->f12.u64, 0X160, ctx->r26);
    // 0x80027260: sdc1        $f14, 0x168($k0)
    CHECK_FR(ctx, 14);
    SD(ctx->f14.u64, 0X168, ctx->r26);
    // 0x80027264: sdc1        $f16, 0x170($k0)
    CHECK_FR(ctx, 16);
    SD(ctx->f16.u64, 0X170, ctx->r26);
    // 0x80027268: sdc1        $f18, 0x178($k0)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0X178, ctx->r26);
    // 0x8002726C: sdc1        $f20, 0x180($k0)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X180, ctx->r26);
    // 0x80027270: sdc1        $f22, 0x188($k0)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X188, ctx->r26);
    // 0x80027274: sdc1        $f24, 0x190($k0)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X190, ctx->r26);
    // 0x80027278: sdc1        $f26, 0x198($k0)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X198, ctx->r26);
    // 0x8002727C: sdc1        $f28, 0x1A0($k0)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X1A0, ctx->r26);
    // 0x80027280: sdc1        $f30, 0x1A8($k0)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X1A8, ctx->r26);
L_80027284:
    // 0x80027284: mfc0        $t0, Cause
    ctx->r8 = cop0_cause_read(ctx);
    // 0x80027288: sw          $t0, 0x120($k0)
    MEM_W(0X120, ctx->r26) = ctx->r8;
    // 0x8002728C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80027290: sh          $t1, 0x10($k0)
    MEM_H(0X10, ctx->r26) = ctx->r9;
    // 0x80027294: andi        $t1, $t0, 0x7C
    ctx->r9 = ctx->r8 & 0X7C;
    // 0x80027298: addiu       $t2, $zero, 0x24
    ctx->r10 = ADD32(0, 0X24);
    // 0x8002729C: beq         $t1, $t2, L_80027550
    if (ctx->r9 == ctx->r10) {
        // 0x800272A0: nop
    
            goto L_80027550;
    }
    // 0x800272A0: nop

    // 0x800272A4: addiu       $t2, $zero, 0x2C
    ctx->r10 = ADD32(0, 0X2C);
    // 0x800272A8: beq         $t1, $t2, L_80027698
    if (ctx->r9 == ctx->r10) {
            // 0x800272AC: nop

    LOOKUP_FUNC(0x80027698)(rdram, ctx);
    return;
    }
    // 0x800272AC: nop

    // 0x800272B0: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x800272B4: bne         $t1, $t2, L_800275B4
    if (ctx->r9 != ctx->r10) {
            // 0x800272B8: nop

    LOOKUP_FUNC(0x800275B4)(rdram, ctx);
    return;
    }
    // 0x800272B8: nop

    // 0x800272BC: and         $s0, $k1, $t0
    ctx->r16 = ctx->r27 & ctx->r8;
L_800272C0:
    // 0x800272C0: andi        $t1, $s0, 0xFF00
    ctx->r9 = ctx->r16 & 0XFF00;
    // 0x800272C4: srl         $t2, $t1, 12
    ctx->r10 = S32(U32(ctx->r9) >> 12);
    // 0x800272C8: bne         $t2, $zero, L_800272D8
    if (ctx->r10 != 0) {
        // 0x800272CC: nop
    
            goto L_800272D8;
    }
    // 0x800272CC: nop

    // 0x800272D0: srl         $t2, $t1, 8
    ctx->r10 = S32(U32(ctx->r9) >> 8);
    // 0x800272D4: addi        $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
L_800272D8:
    // 0x800272D8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800272DC: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800272E0: lbu         $t2, -0x2D60($at)
    ctx->r10 = MEM_BU(ctx->r1, -0X2D60);
    // 0x800272E4: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800272E8: addu        $at, $at, $t2
    gpr jr_addend_800272F0 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800272EC: lw          $t2, -0x2D40($at)
    ctx->r10 = ADD32(ctx->r1, -0X2D40);
    // 0x800272F0: jr          $t2
    // 0x800272F4: nop

    switch (jr_addend_800272F0 >> 2) {
        case 0: goto L_80027568; break;
        case 1: goto L_80027530; break;
        case 2: goto L_80027510; break;
        case 3: goto L_80027374; break;
        case 4: goto L_80027330; break;
        case 5: goto L_800274B4; break;
        case 6: goto L_800272F8; break;
        case 7: goto L_80027304; break;
        case 8: goto L_80027310; break;
        default: switch_error(__func__, 0x800272F0, 0x8004D2C0);
    }
    // 0x800272F4: nop

L_800272F8:
    // 0x800272F8: addiu       $at, $zero, -0x2001
    ctx->r1 = ADD32(0, -0X2001);
    // 0x800272FC: b           L_800272C0
    // 0x80027300: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
        goto L_800272C0;
    // 0x80027300: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
L_80027304:
    // 0x80027304: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x80027308: b           L_800272C0
    // 0x8002730C: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
        goto L_800272C0;
    // 0x8002730C: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
L_80027310:
    // 0x80027310: mfc0        $t1, Compare
    ctx->r9 = cop0_register_read(ctx, 11);
    // 0x80027314: mtc0        $t1, Compare
    cop0_register_write(ctx, 11, ctx->r9);    // 0x80027318: jal         0x800275E4
    // 0x8002731C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    LOOKUP_FUNC(0x800275E4)(rdram, ctx);
        goto after_0;
    // 0x8002731C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_0:
    // 0x80027320: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80027324: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80027328: b           L_800272C0
    // 0x8002732C: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
        goto L_800272C0;
    // 0x8002732C: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
L_80027330:
    // 0x80027330: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80027334: addiu       $t1, $t1, -0x6700
    ctx->r9 = ADD32(ctx->r9, -0X6700);
    // 0x80027338: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8002733C: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80027340: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
    // 0x80027344: beq         $t2, $zero, L_80027364
    if (ctx->r10 == 0) {
        // 0x80027348: addi        $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_80027364;
    }
    // 0x80027348: addi        $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8002734C: jalr        $t2
    // 0x80027350: lw          $sp, 0x4($t1)
    ctx->r29 = MEM_W(ctx->r9, 0X4);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
        goto after_1;
    // 0x80027350: lw          $sp, 0x4($t1)
    ctx->r29 = MEM_W(ctx->r9, 0X4);
    after_1:
    // 0x80027354: beq         $v0, $zero, L_80027364
    if (ctx->r2 == 0) {
        // 0x80027358: nop
    
            goto L_80027364;
    }
    // 0x80027358: nop

    // 0x8002735C: b           L_80027568
    // 0x80027360: nop

        goto L_80027568;
    // 0x80027360: nop

L_80027364:
    // 0x80027364: jal         0x800275E4
    // 0x80027368: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x800275E4)(rdram, ctx);
        goto after_2;
    // 0x80027368: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x8002736C: b           L_800272C0
    // 0x80027370: nop

        goto L_800272C0;
    // 0x80027370: nop

L_80027374:
    // 0x80027374: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x80027378: addiu       $t0, $t0, -0x6680
    ctx->r8 = ADD32(ctx->r8, -0X6680);
    // 0x8002737C: lw          $t0, 0x0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X0);
    // 0x80027380: lui         $s1, 0xA430
    ctx->r17 = S32(0XA430 << 16);
    // 0x80027384: lw          $s1, 0x8($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X8);
    // 0x80027388: srl         $t0, $t0, 16
    ctx->r8 = S32(U32(ctx->r8) >> 16);
    // 0x8002738C: and         $s1, $s1, $t0
    ctx->r17 = ctx->r17 & ctx->r8;
    // 0x80027390: andi        $t1, $s1, 0x1
    ctx->r9 = ctx->r17 & 0X1;
    // 0x80027394: beq         $t1, $zero, L_800273E4
    if (ctx->r9 == 0) {
        // 0x80027398: nop
    
            goto L_800273E4;
    }
    // 0x80027398: nop

    // 0x8002739C: lui         $t4, 0xA404
    ctx->r12 = S32(0XA404 << 16);
    // 0x800273A0: lw          $t4, 0x10($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X10);
    // 0x800273A4: ori         $t1, $zero, 0x8008
    ctx->r9 = 0 | 0X8008;
    // 0x800273A8: lui         $at, 0xA404
    ctx->r1 = S32(0XA404 << 16);
    // 0x800273AC: andi        $t4, $t4, 0x300
    ctx->r12 = ctx->r12 & 0X300;
    // 0x800273B0: andi        $s1, $s1, 0x3E
    ctx->r17 = ctx->r17 & 0X3E;
    // 0x800273B4: beq         $t4, $zero, L_800273D4
    if (ctx->r12 == 0) {
        // 0x800273B8: sw          $t1, 0x10($at)
        MEM_W(0X10, ctx->r1) = ctx->r9;
            goto L_800273D4;
    }
    // 0x800273B8: sw          $t1, 0x10($at)
    MEM_W(0X10, ctx->r1) = ctx->r9;
    // 0x800273BC: jal         0x800275E4
    // 0x800273C0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    LOOKUP_FUNC(0x800275E4)(rdram, ctx);
        goto after_3;
    // 0x800273C0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_3:
    // 0x800273C4: beq         $s1, $zero, L_800274A8
    if (ctx->r17 == 0) {
        // 0x800273C8: nop
    
            goto L_800274A8;
    }
    // 0x800273C8: nop

    // 0x800273CC: b           L_800273E4
    // 0x800273D0: nop

        goto L_800273E4;
    // 0x800273D0: nop

L_800273D4:
    // 0x800273D4: jal         0x800275E4
    // 0x800273D8: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    LOOKUP_FUNC(0x800275E4)(rdram, ctx);
        goto after_4;
    // 0x800273D8: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    after_4:
    // 0x800273DC: beq         $s1, $zero, L_800274A8
    if (ctx->r17 == 0) {
        // 0x800273E0: nop
    
            goto L_800274A8;
    }
    // 0x800273E0: nop

L_800273E4:
    // 0x800273E4: andi        $t1, $s1, 0x8
    ctx->r9 = ctx->r17 & 0X8;
    // 0x800273E8: beq         $t1, $zero, L_80027408
    if (ctx->r9 == 0) {
        // 0x800273EC: lui         $at, 0xA440
        ctx->r1 = S32(0XA440 << 16);
            goto L_80027408;
    }
    // 0x800273EC: lui         $at, 0xA440
    ctx->r1 = S32(0XA440 << 16);
    // 0x800273F0: andi        $s1, $s1, 0x37
    ctx->r17 = ctx->r17 & 0X37;
    // 0x800273F4: sw          $zero, 0x10($at)
    MEM_W(0X10, ctx->r1) = 0;
    // 0x800273F8: jal         0x800275E4
    // 0x800273FC: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    LOOKUP_FUNC(0x800275E4)(rdram, ctx);
        goto after_5;
    // 0x800273FC: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_5:
    // 0x80027400: beq         $s1, $zero, L_800274A8
    if (ctx->r17 == 0) {
        // 0x80027404: nop
    
            goto L_800274A8;
    }
    // 0x80027404: nop

L_80027408:
    // 0x80027408: andi        $t1, $s1, 0x4
    ctx->r9 = ctx->r17 & 0X4;
    // 0x8002740C: beq         $t1, $zero, L_80027434
    if (ctx->r9 == 0) {
        // 0x80027410: nop
    
            goto L_80027434;
    }
    // 0x80027410: nop

    // 0x80027414: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80027418: lui         $at, 0xA450
    ctx->r1 = S32(0XA450 << 16);
    // 0x8002741C: andi        $s1, $s1, 0x3B
    ctx->r17 = ctx->r17 & 0X3B;
    // 0x80027420: sw          $t1, 0xC($at)
    MEM_W(0XC, ctx->r1) = ctx->r9;
    // 0x80027424: jal         0x800275E4
    // 0x80027428: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    LOOKUP_FUNC(0x800275E4)(rdram, ctx);
        goto after_6;
    // 0x80027428: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_6:
    // 0x8002742C: beq         $s1, $zero, L_800274A8
    if (ctx->r17 == 0) {
        // 0x80027430: nop
    
            goto L_800274A8;
    }
    // 0x80027430: nop

L_80027434:
    // 0x80027434: andi        $t1, $s1, 0x2
    ctx->r9 = ctx->r17 & 0X2;
    // 0x80027438: beq         $t1, $zero, L_80027458
    if (ctx->r9 == 0) {
        // 0x8002743C: lui         $at, 0xA480
        ctx->r1 = S32(0XA480 << 16);
            goto L_80027458;
    }
    // 0x8002743C: lui         $at, 0xA480
    ctx->r1 = S32(0XA480 << 16);
    // 0x80027440: andi        $s1, $s1, 0x3D
    ctx->r17 = ctx->r17 & 0X3D;
    // 0x80027444: sw          $zero, 0x18($at)
    MEM_W(0X18, ctx->r1) = 0;
    // 0x80027448: jal         0x800275E4
    // 0x8002744C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x800275E4)(rdram, ctx);
        goto after_7;
    // 0x8002744C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_7:
    // 0x80027450: beq         $s1, $zero, L_800274A8
    if (ctx->r17 == 0) {
        // 0x80027454: nop
    
            goto L_800274A8;
    }
    // 0x80027454: nop

L_80027458:
    // 0x80027458: andi        $t1, $s1, 0x10
    ctx->r9 = ctx->r17 & 0X10;
    // 0x8002745C: beq         $t1, $zero, L_80027484
    if (ctx->r9 == 0) {
        // 0x80027460: nop
    
            goto L_80027484;
    }
    // 0x80027460: nop

    // 0x80027464: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80027468: lui         $at, 0xA460
    ctx->r1 = S32(0XA460 << 16);
    // 0x8002746C: andi        $s1, $s1, 0x2F
    ctx->r17 = ctx->r17 & 0X2F;
    // 0x80027470: sw          $t1, 0x10($at)
    MEM_W(0X10, ctx->r1) = ctx->r9;
    // 0x80027474: jal         0x800275E4
    // 0x80027478: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x800275E4)(rdram, ctx);
        goto after_8;
    // 0x80027478: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_8:
    // 0x8002747C: beq         $s1, $zero, L_800274A8
    if (ctx->r17 == 0) {
        // 0x80027480: nop
    
            goto L_800274A8;
    }
    // 0x80027480: nop

L_80027484:
    // 0x80027484: andi        $t1, $s1, 0x20
    ctx->r9 = ctx->r17 & 0X20;
    // 0x80027488: beq         $t1, $zero, L_800274A8
    if (ctx->r9 == 0) {
        // 0x8002748C: nop
    
            goto L_800274A8;
    }
    // 0x8002748C: nop

    // 0x80027490: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x80027494: lui         $at, 0xA430
    ctx->r1 = S32(0XA430 << 16);
    // 0x80027498: andi        $s1, $s1, 0x1F
    ctx->r17 = ctx->r17 & 0X1F;
    // 0x8002749C: sw          $t1, 0x0($at)
    MEM_W(0X0, ctx->r1) = ctx->r9;
    // 0x800274A0: jal         0x800275E4
    // 0x800274A4: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    LOOKUP_FUNC(0x800275E4)(rdram, ctx);
        goto after_9;
    // 0x800274A4: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_9:
L_800274A8:
    // 0x800274A8: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x800274AC: b           L_800272C0
    // 0x800274B0: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
        goto L_800272C0;
    // 0x800274B0: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
L_800274B4:
    // 0x800274B4: lw          $k1, 0x118($k0)
    ctx->r27 = MEM_W(ctx->r26, 0X118);
    // 0x800274B8: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x800274BC: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x800274C0: and         $k1, $k1, $at
    ctx->r27 = ctx->r27 & ctx->r1;
    // 0x800274C4: sw          $k1, 0x118($k0)
    MEM_W(0X118, ctx->r26) = ctx->r27;
    // 0x800274C8: addiu       $t1, $t1, -0x6684
    ctx->r9 = ADD32(ctx->r9, -0X6684);
    // 0x800274CC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800274D0: beq         $t2, $zero, L_800274E0
    if (ctx->r10 == 0) {
        // 0x800274D4: addiu       $at, $zero, -0x1001
        ctx->r1 = ADD32(0, -0X1001);
            goto L_800274E0;
    }
    // 0x800274D4: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x800274D8: b           L_80027568
    // 0x800274DC: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
        goto L_80027568;
    // 0x800274DC: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
L_800274E0:
    // 0x800274E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800274E4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800274E8: jal         0x800275E4
    // 0x800274EC: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    LOOKUP_FUNC(0x800275E4)(rdram, ctx);
        goto after_10;
    // 0x800274EC: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    after_10:
    // 0x800274F0: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x800274F4: lw          $t2, -0x66C8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X66C8);
    // 0x800274F8: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x800274FC: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
    // 0x80027500: lw          $k1, 0x118($t2)
    ctx->r27 = MEM_W(ctx->r10, 0X118);
    // 0x80027504: and         $k1, $k1, $at
    ctx->r27 = ctx->r27 & ctx->r1;
    // 0x80027508: b           L_80027568
    // 0x8002750C: sw          $k1, 0x118($t2)
    MEM_W(0X118, ctx->r10) = ctx->r27;
        goto L_80027568;
    // 0x8002750C: sw          $k1, 0x118($t2)
    MEM_W(0X118, ctx->r10) = ctx->r27;
L_80027510:
    // 0x80027510: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x80027514: and         $t0, $t0, $at
    ctx->r8 = ctx->r8 & ctx->r1;
    // 0x80027518: mtc0        $t0, Cause
    cop0_cause_write(ctx, ctx->r8);    // 0x8002751C: jal         0x800275E4
    // 0x80027520: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x800275E4)(rdram, ctx);
        goto after_11;
    // 0x80027520: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_11:
    // 0x80027524: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x80027528: b           L_800272C0
    // 0x8002752C: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
        goto L_800272C0;
    // 0x8002752C: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
L_80027530:
    // 0x80027530: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x80027534: and         $t0, $t0, $at
    ctx->r8 = ctx->r8 & ctx->r1;
    // 0x80027538: mtc0        $t0, Cause
    cop0_cause_write(ctx, ctx->r8);    // 0x8002753C: jal         0x800275E4
    // 0x80027540: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x800275E4)(rdram, ctx);
        goto after_12;
    // 0x80027540: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_12:
    // 0x80027544: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x80027548: b           L_800272C0
    // 0x8002754C: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
        goto L_800272C0;
    // 0x8002754C: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
L_80027550:
    // 0x80027550: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80027554: sh          $t1, 0x12($k0)
    MEM_H(0X12, ctx->r26) = ctx->r9;
    // 0x80027558: jal         0x800275E4
    // 0x8002755C: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x800275E4)(rdram, ctx);
        goto after_13;
    // 0x8002755C: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_13:
    // 0x80027560: b           L_80027568
    // 0x80027564: nop

        goto L_80027568;
    // 0x80027564: nop

L_80027568:
    // 0x80027568: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x8002756C: lw          $t2, -0x66C8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X66C8);
    // 0x80027570: lw          $t1, 0x4($k0)
    ctx->r9 = MEM_W(ctx->r26, 0X4);
    // 0x80027574: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80027578: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002757C: beq         $at, $zero, L_8002759C
    if (ctx->r1 == 0) {
            // 0x80027580: nop

    LOOKUP_FUNC(0x8002759C)(rdram, ctx);
    return;
    }
    // 0x80027580: nop

    // 0x80027584: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80027588: or          $a1, $k0, $zero
    ctx->r5 = ctx->r26 | 0;
    // 0x8002758C: jal         0x800277CC
    // 0x80027590: addiu       $a0, $a0, -0x66C8
    ctx->r4 = ADD32(ctx->r4, -0X66C8);
    LOOKUP_FUNC(0x800277CC)(rdram, ctx);
        goto after_14;
    // 0x80027590: addiu       $a0, $a0, -0x66C8
    ctx->r4 = ADD32(ctx->r4, -0X66C8);
    after_14:
    // 0x80027594: j           L_80027824
    // 0x80027598: nop

    LOOKUP_FUNC(0x80027824)(rdram, ctx);
    return;
    // 0x80027598: nop

;}
RECOMP_FUNC void FUN_8002759c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002759C: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x800275A0: addiu       $t1, $t1, -0x66C8
    ctx->r9 = ADD32(ctx->r9, -0X66C8);
    // 0x800275A4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800275A8: sw          $t2, 0x0($k0)
    MEM_W(0X0, ctx->r26) = ctx->r10;
    // 0x800275AC: j           L_80027824
    // 0x800275B0: sw          $k0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r26;
    LOOKUP_FUNC(0x80027824)(rdram, ctx);
    return;
    // 0x800275B0: sw          $k0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r26;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800275b4(rdram, ctx);
;}
RECOMP_FUNC void FUN_800275b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800275B4: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800275B8: sw          $k0, -0x66BC($at)
    MEM_W(-0X66BC, ctx->r1) = ctx->r26;
    // 0x800275BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800275C0: sh          $t1, 0x10($k0)
    MEM_H(0X10, ctx->r26) = ctx->r9;
    // 0x800275C4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800275C8: sh          $t1, 0x12($k0)
    MEM_H(0X12, ctx->r26) = ctx->r9;
    // 0x800275CC: mfc0        $t2, BadVaddr
    ctx->r10 = cop0_register_read(ctx, 8);
    // 0x800275D0: sw          $t2, 0x124($k0)
    MEM_W(0X124, ctx->r26) = ctx->r10;
    // 0x800275D4: jal         0x800275E4
    // 0x800275D8: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    LOOKUP_FUNC(0x800275E4)(rdram, ctx);
        goto after_0;
    // 0x800275D8: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    after_0:
    // 0x800275DC: j           L_80027824
    // 0x800275E0: nop

    LOOKUP_FUNC(0x80027824)(rdram, ctx);
    return;
    // 0x800275E0: nop

;}
RECOMP_FUNC void FUN_800275e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800275E4: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800275E8: addiu       $t2, $t2, -0x2A10
    ctx->r10 = ADD32(ctx->r10, -0X2A10);
    // 0x800275EC: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x800275F0: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x800275F4: or          $s2, $ra, $zero
    ctx->r18 = ctx->r31 | 0;
    // 0x800275F8: beq         $t1, $zero, L_80027690
    if (ctx->r9 == 0) {
        // 0x800275FC: nop
    
            goto L_80027690;
    }
    // 0x800275FC: nop

    // 0x80027600: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80027604: lw          $t4, 0x10($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X10);
    // 0x80027608: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002760C: beq         $at, $zero, L_80027690
    if (ctx->r1 == 0) {
        // 0x80027610: nop
    
            goto L_80027690;
    }
    // 0x80027610: nop

    // 0x80027614: lw          $t5, 0xC($t1)
    ctx->r13 = MEM_W(ctx->r9, 0XC);
    // 0x80027618: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8002761C: div         $zero, $t5, $t4
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r12)));
    // 0x80027620: bne         $t4, $zero, L_8002762C
    if (ctx->r12 != 0) {
        // 0x80027624: nop
    
            goto L_8002762C;
    }
    // 0x80027624: nop

    // 0x80027628: break       7
    do_break(2147644968);
L_8002762C:
    // 0x8002762C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80027630: bne         $t4, $at, L_80027644
    if (ctx->r12 != ctx->r1) {
        // 0x80027634: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80027644;
    }
    // 0x80027634: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80027638: bne         $t5, $at, L_80027644
    if (ctx->r13 != ctx->r1) {
        // 0x8002763C: nop
    
            goto L_80027644;
    }
    // 0x8002763C: nop

    // 0x80027640: break       6
    do_break(2147644992);
L_80027644:
    // 0x80027644: lw          $t4, 0x14($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X14);
    // 0x80027648: mfhi        $t5
    ctx->r13 = hi;
    // 0x8002764C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80027650: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x80027654: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80027658: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x8002765C: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x80027660: sw          $t2, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r10;
    // 0x80027664: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80027668: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8002766C: beq         $t3, $zero, L_80027690
    if (ctx->r11 == 0) {
        // 0x80027670: nop
    
            goto L_80027690;
    }
    // 0x80027670: nop

    // 0x80027674: jal         0x80027814
    // 0x80027678: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    LOOKUP_FUNC(0x80027814)(rdram, ctx);
        goto after_0;
    // 0x80027678: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_0:
    // 0x8002767C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80027680: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80027684: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80027688: jal         0x800277CC
    // 0x8002768C: addiu       $a0, $a0, -0x66C8
    ctx->r4 = ADD32(ctx->r4, -0X66C8);
    LOOKUP_FUNC(0x800277CC)(rdram, ctx);
        goto after_1;
    // 0x8002768C: addiu       $a0, $a0, -0x66C8
    ctx->r4 = ADD32(ctx->r4, -0X66C8);
    after_1:
L_80027690:
    // 0x80027690: jr          $s2
    // 0x80027694: nop

    LOOKUP_FUNC(ctx->r18)(rdram, ctx);
    return;
    // 0x80027694: nop

;}
RECOMP_FUNC void FUN_80027698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_8002759C:
    // 0x80027698: lui         $at, 0x3000
    ctx->r1 = S32(0X3000 << 16);
L_800275B4:
    // 0x8002769C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800276A0: srl         $t1, $t1, 28
    ctx->r9 = S32(U32(ctx->r9) >> 28);
    // 0x800276A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800276A8: bne         $t1, $t2, L_800275B4
    if (ctx->r9 != ctx->r10) {
            // 0x800276AC: nop

    LOOKUP_FUNC(0x800275B4)(rdram, ctx);
    return;
    }
    // 0x800276AC: nop

    // 0x800276B0: lw          $k1, 0x118($k0)
    ctx->r27 = MEM_W(ctx->r26, 0X118);
    // 0x800276B4: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x800276B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800276BC: or          $k1, $k1, $at
    ctx->r27 = ctx->r27 | ctx->r1;
    // 0x800276C0: sw          $t1, 0x18($k0)
    MEM_W(0X18, ctx->r26) = ctx->r9;
    // 0x800276C4: b           L_8002759C
    // 0x800276C8: sw          $k1, 0x118($k0)
    MEM_W(0X118, ctx->r26) = ctx->r27;
    LOOKUP_FUNC(0x8002759C)(rdram, ctx);
    return;
    // 0x800276C8: sw          $k1, 0x118($k0)
    MEM_W(0X118, ctx->r26) = ctx->r27;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800276cc(rdram, ctx);
;}
RECOMP_FUNC void FUN_800276cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800276CC: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x800276D0: lw          $a1, -0x66C0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X66C0);
    // 0x800276D4: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x800276D8: lw          $k1, 0x18($a1)
    ctx->r27 = MEM_W(ctx->r5, 0X18);
    // 0x800276DC: ori         $t0, $t0, 0x2
    ctx->r8 = ctx->r8 | 0X2;
    // 0x800276E0: sw          $t0, 0x118($a1)
    MEM_W(0X118, ctx->r5) = ctx->r8;
    // 0x800276E4: sd          $s0, 0x98($a1)
    SD(ctx->r16, 0X98, ctx->r5);
    // 0x800276E8: sd          $s1, 0xA0($a1)
    SD(ctx->r17, 0XA0, ctx->r5);
    // 0x800276EC: sd          $s2, 0xA8($a1)
    SD(ctx->r18, 0XA8, ctx->r5);
    // 0x800276F0: sd          $s3, 0xB0($a1)
    SD(ctx->r19, 0XB0, ctx->r5);
    // 0x800276F4: sd          $s4, 0xB8($a1)
    SD(ctx->r20, 0XB8, ctx->r5);
    // 0x800276F8: sd          $s5, 0xC0($a1)
    SD(ctx->r21, 0XC0, ctx->r5);
    // 0x800276FC: sd          $s6, 0xC8($a1)
    SD(ctx->r22, 0XC8, ctx->r5);
    // 0x80027700: sd          $s7, 0xD0($a1)
    SD(ctx->r23, 0XD0, ctx->r5);
    // 0x80027704: sd          $gp, 0xE8($a1)
    SD(ctx->r28, 0XE8, ctx->r5);
    // 0x80027708: sd          $sp, 0xF0($a1)
    SD(ctx->r29, 0XF0, ctx->r5);
    // 0x8002770C: sd          $fp, 0xF8($a1)
    SD(ctx->r30, 0XF8, ctx->r5);
    // 0x80027710: sd          $ra, 0x100($a1)
    SD(ctx->r31, 0X100, ctx->r5);
    // 0x80027714: beq         $k1, $zero, L_8002773C
    if (ctx->r27 == 0) {
        // 0x80027718: sw          $ra, 0x11C($a1)
        MEM_W(0X11C, ctx->r5) = ctx->r31;
            goto L_8002773C;
    }
    // 0x80027718: sw          $ra, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->r31;
    // 0x8002771C: cfc1        $k1, $FpcCsr
    ctx->r27 = get_cop1_cs();
    // 0x80027720: sdc1        $f20, 0x180($a1)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X180, ctx->r5);
    // 0x80027724: sdc1        $f22, 0x188($a1)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X188, ctx->r5);
    // 0x80027728: sdc1        $f24, 0x190($a1)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X190, ctx->r5);
    // 0x8002772C: sdc1        $f26, 0x198($a1)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X198, ctx->r5);
    // 0x80027730: sdc1        $f28, 0x1A0($a1)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X1A0, ctx->r5);
    // 0x80027734: sdc1        $f30, 0x1A8($a1)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X1A8, ctx->r5);
    // 0x80027738: sw          $k1, 0x12C($a1)
    MEM_W(0X12C, ctx->r5) = ctx->r27;
L_8002773C:
    // 0x8002773C: lw          $k1, 0x118($a1)
    ctx->r27 = MEM_W(ctx->r5, 0X118);
    // 0x80027740: andi        $t1, $k1, 0xFF00
    ctx->r9 = ctx->r27 & 0XFF00;
    // 0x80027744: beq         $t1, $zero, L_8002777C
    if (ctx->r9 == 0) {
        // 0x80027748: nop
    
            goto L_8002777C;
    }
    // 0x80027748: nop

    // 0x8002774C: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x80027750: addiu       $t0, $t0, -0x6680
    ctx->r8 = ADD32(ctx->r8, -0X6680);
    // 0x80027754: lw          $t0, 0x0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X0);
    // 0x80027758: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002775C: xor         $t0, $t0, $at
    ctx->r8 = ctx->r8 ^ ctx->r1;
    // 0x80027760: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80027764: andi        $t0, $t0, 0xFF00
    ctx->r8 = ctx->r8 & 0XFF00;
    // 0x80027768: ori         $at, $at, 0xFF
    ctx->r1 = ctx->r1 | 0XFF;
    // 0x8002776C: or          $t1, $t1, $t0
    ctx->r9 = ctx->r9 | ctx->r8;
    // 0x80027770: and         $k1, $k1, $at
    ctx->r27 = ctx->r27 & ctx->r1;
    // 0x80027774: or          $k1, $k1, $t1
    ctx->r27 = ctx->r27 | ctx->r9;
    // 0x80027778: sw          $k1, 0x118($a1)
    MEM_W(0X118, ctx->r5) = ctx->r27;
L_8002777C:
    // 0x8002777C: lui         $k1, 0xA430
    ctx->r27 = S32(0XA430 << 16);
    // 0x80027780: lw          $k1, 0xC($k1)
    ctx->r27 = MEM_W(ctx->r27, 0XC);
    // 0x80027784: beq         $k1, $zero, L_800277B4
    if (ctx->r27 == 0) {
        // 0x80027788: nop
    
            goto L_800277B4;
    }
    // 0x80027788: nop

    // 0x8002778C: lui         $k0, 0x8005
    ctx->r26 = S32(0X8005 << 16);
    // 0x80027790: addiu       $k0, $k0, -0x6680
    ctx->r26 = ADD32(ctx->r26, -0X6680);
    // 0x80027794: lw          $k0, 0x0($k0)
    ctx->r26 = MEM_W(ctx->r26, 0X0);
    // 0x80027798: lw          $t0, 0x128($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X128);
    // 0x8002779C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800277A0: srl         $k0, $k0, 16
    ctx->r26 = S32(U32(ctx->r26) >> 16);
    // 0x800277A4: xor         $k0, $k0, $at
    ctx->r26 = ctx->r26 ^ ctx->r1;
    // 0x800277A8: andi        $k0, $k0, 0x3F
    ctx->r26 = ctx->r26 & 0X3F;
    // 0x800277AC: and         $k0, $k0, $t0
    ctx->r26 = ctx->r26 & ctx->r8;
    // 0x800277B0: or          $k1, $k1, $k0
    ctx->r27 = ctx->r27 | ctx->r26;
L_800277B4:
    // 0x800277B4: beq         $a0, $zero, L_800277C4
    if (ctx->r4 == 0) {
        // 0x800277B8: sw          $k1, 0x128($a1)
        MEM_W(0X128, ctx->r5) = ctx->r27;
            goto L_800277C4;
    }
    // 0x800277B8: sw          $k1, 0x128($a1)
    MEM_W(0X128, ctx->r5) = ctx->r27;
    // 0x800277BC: jal         0x800277CC
    // 0x800277C0: nop

    LOOKUP_FUNC(0x800277CC)(rdram, ctx);
        goto after_0;
    // 0x800277C0: nop

    after_0:
L_800277C4:
    // 0x800277C4: j           L_80027824
    // 0x800277C8: nop

    LOOKUP_FUNC(0x80027824)(rdram, ctx);
    return;
    // 0x800277C8: nop

;}
RECOMP_FUNC void FUN_800277cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800277CC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800277D0: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800277D4: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x800277D8: lw          $t6, 0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4);
    // 0x800277DC: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800277E0: bne         $at, $zero, L_80027800
    if (ctx->r1 != 0) {
        // 0x800277E4: nop
    
            goto L_80027800;
    }
    // 0x800277E4: nop

L_800277E8:
    // 0x800277E8: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x800277EC: lw          $t8, 0x0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X0);
    // 0x800277F0: lw          $t6, 0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4);
    // 0x800277F4: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800277F8: beq         $at, $zero, L_800277E8
    if (ctx->r1 == 0) {
        // 0x800277FC: nop
    
            goto L_800277E8;
    }
    // 0x800277FC: nop

L_80027800:
    // 0x80027800: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80027804: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80027808: sw          $a1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r5;
    // 0x8002780C: jr          $ra
    // 0x80027810: sw          $a0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r4;
    return;
    // 0x80027810: sw          $a0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r4;
;}
RECOMP_FUNC void FUN_800279b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800279B0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800279B4: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800279B8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800279BC: beq         $a3, $zero, L_800279E8
    if (ctx->r7 == 0) {
        // 0x800279C0: nop
    
            goto L_800279E8;
    }
    // 0x800279C0: nop

L_800279C4:
    // 0x800279C4: bne         $a3, $a1, L_800279D8
    if (ctx->r7 != ctx->r5) {
        // 0x800279C8: nop
    
            goto L_800279D8;
    }
    // 0x800279C8: nop

    // 0x800279CC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800279D0: b           L_800279E8
    // 0x800279D4: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
        goto L_800279E8;
    // 0x800279D4: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
L_800279D8:
    // 0x800279D8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800279DC: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800279E0: bne         $a3, $zero, L_800279C4
    if (ctx->r7 != 0) {
        // 0x800279E4: nop
    
            goto L_800279C4;
    }
    // 0x800279E4: nop

L_800279E8:
    // 0x800279E8: jr          $ra
    // 0x800279EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800279EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800279f0(rdram, ctx);
;}
RECOMP_FUNC void FUN_800279f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800279F0: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x800279F4: bne         $at, $zero, L_80027A6C
    if (ctx->r1 != 0) {
        // 0x800279F8: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_80027A6C;
    }
    // 0x800279F8: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x800279FC: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x80027A00: beq         $v1, $zero, L_80027A10
    if (ctx->r3 == 0) {
        // 0x80027A04: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_80027A10;
    }
    // 0x80027A04: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x80027A08: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x80027A0C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_80027A10:
    // 0x80027A10: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x80027A14: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80027A18: beq         $a3, $zero, L_80027A4C
    if (ctx->r7 == 0) {
        // 0x80027A1C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_80027A4C;
    }
    // 0x80027A1C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x80027A20: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80027A24:
    // 0x80027A24: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80027A28: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x80027A2C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x80027A30: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x80027A34: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x80027A38: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x80027A3C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x80027A40: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x80027A44: bne         $a0, $a3, L_80027A24
    if (ctx->r4 != ctx->r7) {
        // 0x80027A48: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80027A24;
    }
    // 0x80027A48: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_80027A4C:
    // 0x80027A4C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80027A50: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80027A54: beq         $a3, $zero, L_80027A6C
    if (ctx->r7 == 0) {
        // 0x80027A58: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_80027A6C;
    }
    // 0x80027A58: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x80027A5C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80027A60:
    // 0x80027A60: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80027A64: bne         $a0, $a3, L_80027A60
    if (ctx->r4 != ctx->r7) {
        // 0x80027A68: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80027A60;
    }
    // 0x80027A68: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_80027A6C:
    // 0x80027A6C: blez        $a1, L_80027A84
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80027A70: nop
    
            goto L_80027A84;
    }
    // 0x80027A70: nop

    // 0x80027A74: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_80027A78:
    // 0x80027A78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80027A7C: bne         $a0, $a1, L_80027A78
    if (ctx->r4 != ctx->r5) {
        // 0x80027A80: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_80027A78;
    }
    // 0x80027A80: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_80027A84:
    // 0x80027A84: jr          $ra
    // 0x80027A88: nop

    return;
    // 0x80027A88: nop

    // 0x80027A8C: nop

;}
RECOMP_FUNC void FUN_80027bf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027BF8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80027BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027C00: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80027C04: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80027C08: addiu       $t7, $zero, 0x23
    ctx->r15 = ADD32(0, 0X23);
    // 0x80027C0C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80027C10: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80027C14: addiu       $t0, $zero, 0xC0
    ctx->r8 = ADD32(0, 0XC0);
    // 0x80027C18: sb          $t6, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r14;
    // 0x80027C1C: sb          $t7, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r15;
    // 0x80027C20: sb          $t8, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r24;
    // 0x80027C24: sb          $t9, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r25;
    // 0x80027C28: sb          $t0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r8;
    // 0x80027C2C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80027C30: addiu       $a0, $zero, 0x600
    ctx->r4 = ADD32(0, 0X600);
    // 0x80027C34: jal         0x80034290
    // 0x80027C38: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80034290)(rdram, ctx);
        goto after_0;
    // 0x80027C38: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80027C3C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80027C40: ori         $t1, $v0, 0xC000
    ctx->r9 = ctx->r2 | 0XC000;
    // 0x80027C44: sb          $t1, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r9;
    // 0x80027C48: beq         $a2, $zero, L_80027C94
    if (ctx->r6 == 0) {
        // 0x80027C4C: lw          $v1, 0x4C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X4C);
            goto L_80027C94;
    }
    // 0x80027C4C: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80027C50: blez        $a2, L_80027C94
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80027C54: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80027C94;
    }
    // 0x80027C54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80027C58: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x80027C5C: beq         $a1, $zero, L_80027C78
    if (ctx->r5 == 0) {
        // 0x80027C60: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80027C78;
    }
    // 0x80027C60: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80027C64:
    // 0x80027C64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80027C68: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80027C6C: bne         $a0, $v0, L_80027C64
    if (ctx->r4 != ctx->r2) {
        // 0x80027C70: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80027C64;
    }
    // 0x80027C70: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80027C74: beq         $v0, $a2, L_80027C94
    if (ctx->r2 == ctx->r6) {
        // 0x80027C78: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80027C94;
    }
L_80027C78:
    // 0x80027C78: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80027C7C: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80027C80: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80027C84: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80027C88: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80027C8C: bne         $v0, $a2, L_80027C78
    if (ctx->r2 != ctx->r6) {
        // 0x80027C90: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_80027C78;
    }
    // 0x80027C90: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
L_80027C94:
    // 0x80027C94: addiu       $t2, $sp, 0x24
    ctx->r10 = ADD32(ctx->r29, 0X24);
    // 0x80027C98: addiu       $t4, $t2, 0x24
    ctx->r12 = ADD32(ctx->r10, 0X24);
    // 0x80027C9C: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
L_80027CA0:
    // 0x80027CA0: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80027CA4: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80027CA8: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80027CAC: swl         $at, -0xC($t5)
    do_swl(rdram, -0XC, ctx->r13, ctx->r1);
    // 0x80027CB0: swr         $at, -0x9($t5)
    do_swr(rdram, -0X9, ctx->r13, ctx->r1);
    // 0x80027CB4: lw          $at, -0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X8);
    // 0x80027CB8: swl         $at, -0x8($t5)
    do_swl(rdram, -0X8, ctx->r13, ctx->r1);
    // 0x80027CBC: swr         $at, -0x5($t5)
    do_swr(rdram, -0X5, ctx->r13, ctx->r1);
    // 0x80027CC0: lw          $at, -0x4($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X4);
    // 0x80027CC4: swl         $at, -0x4($t5)
    do_swl(rdram, -0X4, ctx->r13, ctx->r1);
    // 0x80027CC8: bne         $t2, $t4, L_80027CA0
    if (ctx->r10 != ctx->r12) {
        // 0x80027CCC: swr         $at, -0x1($t5)
        do_swr(rdram, -0X1, ctx->r13, ctx->r1);
            goto L_80027CA0;
    }
    // 0x80027CCC: swr         $at, -0x1($t5)
    do_swr(rdram, -0X1, ctx->r13, ctx->r1);
    // 0x80027CD0: lbu         $at, 0x0($t2)
    ctx->r1 = MEM_BU(ctx->r10, 0X0);
    // 0x80027CD4: addiu       $t6, $zero, 0xFE
    ctx->r14 = ADD32(0, 0XFE);
    // 0x80027CD8: addiu       $v1, $v1, 0x27
    ctx->r3 = ADD32(ctx->r3, 0X27);
    // 0x80027CDC: sb          $at, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r1;
    // 0x80027CE0: lbu         $t4, 0x1($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X1);
    // 0x80027CE4: sb          $t4, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r12;
    // 0x80027CE8: lbu         $at, 0x2($t2)
    ctx->r1 = MEM_BU(ctx->r10, 0X2);
    // 0x80027CEC: sb          $at, 0x2($t5)
    MEM_B(0X2, ctx->r13) = ctx->r1;
    // 0x80027CF0: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x80027CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027CF8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80027CFC: jr          $ra
    // 0x80027D00: nop

    return;
    // 0x80027D00: nop

;}
RECOMP_FUNC void FUN_800284c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800284C0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800284C4: addiu       $a1, $a1, -0x4080
    ctx->r5 = ADD32(ctx->r5, -0X4080);
    // 0x800284C8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800284CC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800284D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800284D4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800284D8: addiu       $v1, $v1, -0x4044
    ctx->r3 = ADD32(ctx->r3, -0X4044);
    // 0x800284DC: addiu       $a0, $a0, -0x4080
    ctx->r4 = ADD32(ctx->r4, -0X4080);
L_800284E0:
    // 0x800284E0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800284E4: sltu        $at, $a0, $v1
    ctx->r1 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x800284E8: bne         $at, $zero, L_800284E0
    if (ctx->r1 != 0) {
        // 0x800284EC: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800284E0;
    }
    // 0x800284EC: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x800284F0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800284F4: addiu       $a0, $a0, -0x403F
    ctx->r4 = ADD32(ctx->r4, -0X403F);
    // 0x800284F8: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x800284FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80028500: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80028504: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80028508: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8002850C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80028510: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x80028514: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80028518: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8002851C: sw          $t6, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r14;
    // 0x80028520: sb          $t7, 0xC($sp)
    MEM_B(0XC, ctx->r29) = ctx->r15;
    // 0x80028524: sb          $t8, 0xD($sp)
    MEM_B(0XD, ctx->r29) = ctx->r24;
    // 0x80028528: sb          $t9, 0xE($sp)
    MEM_B(0XE, ctx->r29) = ctx->r25;
    // 0x8002852C: sb          $t0, 0xF($sp)
    MEM_B(0XF, ctx->r29) = ctx->r8;
    // 0x80028530: sh          $t1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r9;
    // 0x80028534: sb          $t2, 0x12($sp)
    MEM_B(0X12, ctx->r29) = ctx->r10;
    // 0x80028538: sb          $t3, 0x13($sp)
    MEM_B(0X13, ctx->r29) = ctx->r11;
    // 0x8002853C: blez        $t4, L_80028578
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80028540: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80028578;
    }
    // 0x80028540: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80028544: addiu       $a1, $sp, 0xC
    ctx->r5 = ADD32(ctx->r29, 0XC);
    // 0x80028548: lw          $at, 0x0($a1)
    ctx->r1 = MEM_W(ctx->r5, 0X0);
L_8002854C:
    // 0x8002854C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80028550: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80028554: swl         $at, -0x8($v0)
    do_swl(rdram, -0X8, ctx->r2, ctx->r1);
    // 0x80028558: swr         $at, -0x5($v0)
    do_swr(rdram, -0X5, ctx->r2, ctx->r1);
    // 0x8002855C: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80028560: swl         $t6, -0x4($v0)
    do_swl(rdram, -0X4, ctx->r2, ctx->r14);
    // 0x80028564: swr         $t6, -0x1($v0)
    do_swr(rdram, -0X1, ctx->r2, ctx->r14);
    // 0x80028568: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8002856C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80028570: bnel        $at, $zero, L_8002854C
    if (ctx->r1 != 0) {
        // 0x80028574: lw          $at, 0x0($a1)
        ctx->r1 = MEM_W(ctx->r5, 0X0);
            goto L_8002854C;
    }
    goto skip_0;
    // 0x80028574: lw          $at, 0x0($a1)
    ctx->r1 = MEM_W(ctx->r5, 0X0);
    skip_0:
L_80028578:
    // 0x80028578: addiu       $t8, $zero, 0xFE
    ctx->r24 = ADD32(0, 0XFE);
    // 0x8002857C: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x80028580: jr          $ra
    // 0x80028584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80028584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80028588: nop

    // 0x8002858C: nop

    // 0x80028590: jr          $ra
    // 0x80028594: nop

    return;
    // 0x80028594: nop

    // 0x80028598: jr          $ra
    // 0x8002859C: nop

    return;
    // 0x8002859C: nop

;}
RECOMP_FUNC void FUN_800285a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800285A0: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x800285A4: bne         $t6, $zero, L_80028684
    if (ctx->r14 != 0) {
        // 0x800285A8: nop
    
            goto L_80028684;
    }
    // 0x800285A8: nop

    // 0x800285AC: lh          $t7, 0xE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE);
    // 0x800285B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800285B4: sb          $t1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r9;
    // 0x800285B8: blez        $t7, L_80028684
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800285BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80028684;
    }
    // 0x800285BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800285C0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800285C4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800285C8: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
L_800285CC:
    // 0x800285CC: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800285D0: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x800285D4: lbu         $t6, 0xE($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XE);
    // 0x800285D8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800285DC: bnel        $t6, $zero, L_80028670
    if (ctx->r14 != 0) {
        // 0x800285E0: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_80028670;
    }
    goto skip_0;
    // 0x800285E0: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_0:
    // 0x800285E4: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800285E8: sb          $t1, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r9;
    // 0x800285EC: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800285F0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800285F4: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x800285F8: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x800285FC: addu        $t6, $t9, $a1
    ctx->r14 = ADD32(ctx->r25, ctx->r5);
    // 0x80028600: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x80028604: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80028608: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x8002860C: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x80028610: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x80028614: bnel        $t9, $zero, L_80028670
    if (ctx->r25 != 0) {
        // 0x80028618: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_80028670;
    }
    goto skip_1;
    // 0x80028618: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_1:
    // 0x8002861C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80028620: lbu         $a2, 0x8($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X8);
    // 0x80028624: sb          $t1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r9;
    // 0x80028628: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x8002862C: bne         $a2, $zero, L_80028654
    if (ctx->r6 != 0) {
        // 0x80028630: sw          $t7, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r15;
            goto L_80028654;
    }
    // 0x80028630: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80028634: lw          $t8, 0x10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X10);
    // 0x80028638: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x8002863C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80028640: beq         $a2, $zero, L_8002866C
    if (ctx->r6 == 0) {
        // 0x80028644: sw          $t9, 0x10($t0)
        MEM_W(0X10, ctx->r8) = ctx->r25;
            goto L_8002866C;
    }
    // 0x80028644: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x80028648: addu        $t6, $a2, $a1
    ctx->r14 = ADD32(ctx->r6, ctx->r5);
    // 0x8002864C: b           L_8002866C
    // 0x80028650: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
        goto L_8002866C;
    // 0x80028650: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
L_80028654:
    // 0x80028654: bnel        $t2, $a2, L_80028670
    if (ctx->r10 != ctx->r6) {
        // 0x80028658: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_80028670;
    }
    goto skip_2;
    // 0x80028658: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_2:
    // 0x8002865C: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x80028660: beq         $a2, $zero, L_8002866C
    if (ctx->r6 == 0) {
        // 0x80028664: addu        $t7, $a2, $a1
        ctx->r15 = ADD32(ctx->r6, ctx->r5);
            goto L_8002866C;
    }
    // 0x80028664: addu        $t7, $a2, $a1
    ctx->r15 = ADD32(ctx->r6, ctx->r5);
    // 0x80028668: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
L_8002866C:
    // 0x8002866C: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
L_80028670:
    // 0x80028670: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80028674: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80028678: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002867C: bnel        $at, $zero, L_800285CC
    if (ctx->r1 != 0) {
        // 0x80028680: lw          $t8, 0x10($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X10);
            goto L_800285CC;
    }
    goto skip_3;
    // 0x80028680: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    skip_3:
L_80028684:
    // 0x80028684: jr          $ra
    // 0x80028688: nop

    return;
    // 0x80028688: nop

    // 0x8002868C: jr          $ra
    // 0x80028690: nop

    return;
    // 0x80028690: nop

;}
RECOMP_FUNC void FUN_80028694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028694: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80028698: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002869C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800286A0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800286A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800286A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800286AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800286B0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800286B4: addiu       $at, $zero, 0x4231
    ctx->r1 = ADD32(0, 0X4231);
    // 0x800286B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800286BC: bne         $t6, $at, L_80028778
    if (ctx->r14 != ctx->r1) {
        // 0x800286C0: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80028778;
    }
    // 0x800286C0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800286C4: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x800286C8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800286CC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800286D0: blez        $t7, L_80028778
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800286D4: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_80028778;
    }
    // 0x800286D4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800286D8: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
L_800286DC:
    // 0x800286DC: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800286E0: beq         $t9, $zero, L_80028760
    if (ctx->r25 == 0) {
        // 0x800286E4: sw          $t9, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r25;
            goto L_80028760;
    }
    // 0x800286E4: sw          $t9, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r25;
    // 0x800286E8: lbu         $t6, 0x2($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2);
    // 0x800286EC: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800286F0: bnel        $t6, $zero, L_80028764
    if (ctx->r14 != 0) {
        // 0x800286F4: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_80028764;
    }
    goto skip_0;
    // 0x800286F4: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_0:
    // 0x800286F8: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x800286FC: sb          $s4, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r20;
    // 0x80028700: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80028704: beq         $v0, $zero, L_8002871C
    if (ctx->r2 == 0) {
        // 0x80028708: addu        $a0, $v0, $s0
        ctx->r4 = ADD32(ctx->r2, ctx->r16);
            goto L_8002871C;
    }
    // 0x80028708: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x8002870C: sw          $a0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r4;
    // 0x80028710: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80028714: jal         0x800285A0
    // 0x80028718: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800285A0)(rdram, ctx);
        goto after_0;
    // 0x80028718: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
L_8002871C:
    // 0x8002871C: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x80028720: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x80028724: blezl       $t8, L_80028764
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80028728: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_80028764;
    }
    goto skip_1;
    // 0x80028728: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_1:
    // 0x8002872C: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
L_80028730:
    // 0x80028730: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80028734: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x80028738: beq         $a0, $zero, L_80028748
    if (ctx->r4 == 0) {
        // 0x8002873C: sw          $a0, 0xC($t3)
        MEM_W(0XC, ctx->r11) = ctx->r4;
            goto L_80028748;
    }
    // 0x8002873C: sw          $a0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r4;
    // 0x80028740: jal         0x800285A0
    // 0x80028744: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800285A0)(rdram, ctx);
        goto after_1;
    // 0x80028744: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
L_80028748:
    // 0x80028748: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x8002874C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80028750: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x80028754: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80028758: bnel        $at, $zero, L_80028730
    if (ctx->r1 != 0) {
        // 0x8002875C: lw          $t9, 0xC($t3)
        ctx->r25 = MEM_W(ctx->r11, 0XC);
            goto L_80028730;
    }
    goto skip_2;
    // 0x8002875C: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
    skip_2:
L_80028760:
    // 0x80028760: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
L_80028764:
    // 0x80028764: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80028768: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8002876C: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80028770: bnel        $at, $zero, L_800286DC
    if (ctx->r1 != 0) {
        // 0x80028774: lw          $t8, 0x4($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X4);
            goto L_800286DC;
    }
    goto skip_3;
    // 0x80028774: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    skip_3:
L_80028778:
    // 0x80028778: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002877C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80028780: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80028784: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80028788: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002878C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80028790: jr          $ra
    // 0x80028794: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80028794: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80028798: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x8002879C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800287A0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800287A4: blez        $t6, L_800287D0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800287A8: nop
    
            goto L_800287D0;
    }
    // 0x800287A8: nop

    // 0x800287AC: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
L_800287B0:
    // 0x800287B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800287B4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800287B8: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800287BC: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x800287C0: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x800287C4: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800287C8: bnel        $at, $zero, L_800287B0
    if (ctx->r1 != 0) {
        // 0x800287CC: lw          $t7, 0x4($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X4);
            goto L_800287B0;
    }
    goto skip_4;
    // 0x800287CC: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    skip_4:
L_800287D0:
    // 0x800287D0: jr          $ra
    // 0x800287D4: nop

    return;
    // 0x800287D4: nop

    // 0x800287D8: nop

    // 0x800287DC: nop

;}
RECOMP_FUNC void FUN_800287e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800287E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800287E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800287E8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800287EC: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    // 0x800287F0: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800287F4: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800287F8: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800287FC: beq         $a3, $zero, L_80028834
    if (ctx->r7 == 0) {
        // 0x80028800: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80028834;
    }
    // 0x80028800: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80028804: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x80028808: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8002880C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80028810: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80028814: jal         0x80026890
    // 0x80028818: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80026890)(rdram, ctx);
        goto after_0;
    // 0x80028818: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x8002881C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80028820: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80028824: jal         0x800268C0
    // 0x80028828: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    LOOKUP_FUNC(0x800268C0)(rdram, ctx);
        goto after_1;
    // 0x80028828: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_1:
    // 0x8002882C: b           L_800288B4
    // 0x80028830: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800288B4;
    // 0x80028830: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80028834:
    // 0x80028834: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x80028838: beq         $a3, $zero, L_8002886C
    if (ctx->r7 == 0) {
        // 0x8002883C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8002886C;
    }
    // 0x8002883C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80028840: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x80028844: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80028848: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8002884C: jal         0x80026890
    // 0x80028850: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80026890)(rdram, ctx);
        goto after_2;
    // 0x80028850: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80028854: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80028858: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002885C: jal         0x800268C0
    // 0x80028860: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    LOOKUP_FUNC(0x800268C0)(rdram, ctx);
        goto after_3;
    // 0x80028860: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x80028864: b           L_800288B4
    // 0x80028868: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800288B4;
    // 0x80028868: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_8002886C:
    // 0x8002886C: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x80028870: beql        $a3, $zero, L_800288B8
    if (ctx->r7 == 0) {
        // 0x80028874: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800288B8;
    }
    goto skip_0;
    // 0x80028874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80028878: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
L_8002887C:
    // 0x8002887C: lh          $t9, 0x16($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X16);
    // 0x80028880: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80028884: bnel        $at, $zero, L_800288AC
    if (ctx->r1 != 0) {
        // 0x80028888: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_800288AC;
    }
    goto skip_1;
    // 0x80028888: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x8002888C: lw          $t1, 0xD8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0XD8);
    // 0x80028890: bnel        $t1, $zero, L_800288AC
    if (ctx->r9 != 0) {
        // 0x80028894: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_800288AC;
    }
    goto skip_2;
    // 0x80028894: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x80028898: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x8002889C: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x800288A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800288A4: lh          $a2, 0x16($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X16);
    // 0x800288A8: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
L_800288AC:
    // 0x800288AC: bnel        $a3, $zero, L_8002887C
    if (ctx->r7 != 0) {
        // 0x800288B0: lw          $t8, 0x8($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X8);
            goto L_8002887C;
    }
    goto skip_3;
    // 0x800288B0: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    skip_3:
L_800288B4:
    // 0x800288B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800288B8:
    // 0x800288B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800288BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800288C0: jr          $ra
    // 0x800288C4: nop

    return;
    // 0x800288C4: nop

;}
RECOMP_FUNC void FUN_800288c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800288C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800288CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800288D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800288D4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800288D8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800288DC: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800288E0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800288E4: sh          $t6, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r14;
    // 0x800288E8: lbu         $t7, 0x4($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X4);
    // 0x800288EC: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800288F0: sh          $t7, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r15;
    // 0x800288F4: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x800288F8: sh          $zero, 0x14($a1)
    MEM_H(0X14, ctx->r5) = 0;
    // 0x800288FC: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x80028900: sh          $t8, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r24;
    // 0x80028904: lh          $a2, 0x0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X0);
    // 0x80028908: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8002890C: jal         0x800287E0
    // 0x80028910: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    LOOKUP_FUNC(0x800287E0)(rdram, ctx);
        goto after_0;
    // 0x80028910: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80028914: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80028918: beql        $t9, $zero, L_800289F0
    if (ctx->r25 == 0) {
        // 0x8002891C: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_800289F0;
    }
    goto skip_0;
    // 0x8002891C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80028920: beq         $v0, $zero, L_800289D4
    if (ctx->r2 == 0) {
        // 0x80028924: lw          $a0, 0xC($t9)
        ctx->r4 = MEM_W(ctx->r25, 0XC);
            goto L_800289D4;
    }
    // 0x80028924: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    // 0x80028928: addiu       $t0, $zero, 0x200
    ctx->r8 = ADD32(0, 0X200);
    // 0x8002892C: sw          $t0, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->r8;
    // 0x80028930: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80028934: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80028938: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x8002893C: jal         0x8002C6A0
    // 0x80028940: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8002C6A0)(rdram, ctx);
        goto after_1;
    // 0x80028940: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x80028944: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80028948: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8002894C: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x80028950: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x80028954: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x80028958: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8002895C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80028960: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80028964: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80028968: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002896C: lw          $t7, 0xD8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XD8);
    // 0x80028970: addiu       $t8, $t7, -0x40
    ctx->r24 = ADD32(ctx->r15, -0X40);
    // 0x80028974: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x80028978: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8002897C: jalr        $t9
    // 0x80028980: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80028980: nop

    after_2:
    // 0x80028984: jal         0x8002C6A0
    // 0x80028988: nop

    LOOKUP_FUNC(0x8002C6A0)(rdram, ctx);
        goto after_3;
    // 0x80028988: nop

    after_3:
    // 0x8002898C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80028990: beq         $v0, $zero, L_800289DC
    if (ctx->r2 == 0) {
        // 0x80028994: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800289DC;
    }
    // 0x80028994: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80028998: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8002899C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800289A0: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x800289A4: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x800289A8: lw          $t3, 0xD8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XD8);
    // 0x800289AC: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800289B0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800289B4: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800289B8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800289BC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800289C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800289C4: jalr        $t9
    // 0x800289C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800289C8: nop

    after_4:
    // 0x800289CC: b           L_800289E0
    // 0x800289D0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_800289E0;
    // 0x800289D0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800289D4:
    // 0x800289D4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800289D8: sw          $zero, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = 0;
L_800289DC:
    // 0x800289DC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800289E0:
    // 0x800289E0: sw          $s0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r16;
    // 0x800289E4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800289E8: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800289EC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_800289F0:
    // 0x800289F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800289F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800289F8: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x800289FC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80028A00: jr          $ra
    // 0x80028A04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80028A04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80028A08: nop

    // 0x80028A0C: nop

;}
RECOMP_FUNC void FUN_80028a90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028A90: blez        $a1, L_80028AD8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80028A94: nop
    
            goto L_80028AD8;
    }
    // 0x80028A94: nop

    // 0x80028A98: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x80028A9C: sltu        $at, $a1, $t3
    ctx->r1 = ctx->r5 < ctx->r11 ? 1 : 0;
    // 0x80028AA0: beq         $at, $zero, L_80028AE0
    if (ctx->r1 == 0) {
        // 0x80028AA4: nop
    
            goto L_80028AE0;
    }
    // 0x80028AA4: nop

    // 0x80028AA8: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80028AAC: addu        $t1, $a0, $a1
    ctx->r9 = ADD32(ctx->r4, ctx->r5);
    // 0x80028AB0: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x80028AB4: beq         $at, $zero, L_80028AD8
    if (ctx->r1 == 0) {
        // 0x80028AB8: nop
    
            goto L_80028AD8;
    }
    // 0x80028AB8: nop

    // 0x80028ABC: andi        $t2, $t0, 0xF
    ctx->r10 = ctx->r8 & 0XF;
    // 0x80028AC0: addiu       $t1, $t1, -0x10
    ctx->r9 = ADD32(ctx->r9, -0X10);
    // 0x80028AC4: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
L_80028AC8:
    // 0x80028AC8: cache       0x19, 0x0($t0)

    // 0x80028ACC: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x80028AD0: bne         $at, $zero, L_80028AC8
    if (ctx->r1 != 0) {
        // 0x80028AD4: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_80028AC8;
    }
    // 0x80028AD4: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_80028AD8:
    // 0x80028AD8: jr          $ra
    // 0x80028ADC: nop

    return;
    // 0x80028ADC: nop

L_80028AE0:
    // 0x80028AE0: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80028AE4: addu        $t1, $t0, $t3
    ctx->r9 = ADD32(ctx->r8, ctx->r11);
    // 0x80028AE8: addiu       $t1, $t1, -0x10
    ctx->r9 = ADD32(ctx->r9, -0X10);
L_80028AEC:
    // 0x80028AEC: cache       0x01, 0x0($t0)

    // 0x80028AF0: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x80028AF4: bne         $at, $zero, L_80028AEC
    if (ctx->r1 != 0) {
        // 0x80028AF8: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_80028AEC;
    }
    // 0x80028AF8: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80028AFC: jr          $ra
    // 0x80028B00: nop

    return;
    // 0x80028B00: nop

    // 0x80028B04: nop

    // 0x80028B08: nop

    // 0x80028B0C: nop

;}
RECOMP_FUNC void osInitialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028B10: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80028B14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028B18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80028B1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80028B20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80028B24: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80028B28: jal         0x80028ED0
    // 0x80028B2C: sw          $t6, -0x3FF0($at)
    MEM_W(-0X3FF0, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x80028ED0)(rdram, ctx);
        goto after_0;
    // 0x80028B2C: sw          $t6, -0x3FF0($at)
    MEM_W(-0X3FF0, ctx->r1) = ctx->r14;
    after_0:
    // 0x80028B30: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80028B34: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x80028B38: jal         0x80028EC0
    // 0x80028B3C: or          $a0, $s0, $at
    ctx->r4 = ctx->r16 | ctx->r1;
    LOOKUP_FUNC(0x80028EC0)(rdram, ctx);
        goto after_1;
    // 0x80028B3C: or          $a0, $s0, $at
    ctx->r4 = ctx->r16 | ctx->r1;
    after_1:
    // 0x80028B40: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x80028B44: jal         0x80032DC0
    // 0x80028B48: ori         $a0, $a0, 0x800
    ctx->r4 = ctx->r4 | 0X800;
    LOOKUP_FUNC(0x80032DC0)(rdram, ctx);
        goto after_2;
    // 0x80028B48: ori         $a0, $a0, 0x800
    ctx->r4 = ctx->r4 | 0X800;
    after_2:
    // 0x80028B4C: lui         $a0, 0x1FC0
    ctx->r4 = S32(0X1FC0 << 16);
    // 0x80028B50: ori         $a0, $a0, 0x7FC
    ctx->r4 = ctx->r4 | 0X7FC;
    // 0x80028B54: jal         0x80029640
    // 0x80028B58: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80029640)(rdram, ctx);
        goto after_3;
    // 0x80028B58: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80028B5C: beq         $v0, $zero, L_80028B7C
    if (ctx->r2 == 0) {
        // 0x80028B60: nop
    
            goto L_80028B7C;
    }
    // 0x80028B60: nop

L_80028B64:
    // 0x80028B64: lui         $a0, 0x1FC0
    ctx->r4 = S32(0X1FC0 << 16);
    // 0x80028B68: ori         $a0, $a0, 0x7FC
    ctx->r4 = ctx->r4 | 0X7FC;
    // 0x80028B6C: jal         0x80029640
    // 0x80028B70: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80029640)(rdram, ctx);
        goto after_4;
    // 0x80028B70: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x80028B74: bne         $v0, $zero, L_80028B64
    if (ctx->r2 != 0) {
        // 0x80028B78: nop
    
            goto L_80028B64;
    }
    // 0x80028B78: nop

L_80028B7C:
    // 0x80028B7C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80028B80: lui         $a0, 0x1FC0
    ctx->r4 = S32(0X1FC0 << 16);
    // 0x80028B84: ori         $a0, $a0, 0x7FC
    ctx->r4 = ctx->r4 | 0X7FC;
    // 0x80028B88: ori         $t7, $a1, 0x8
    ctx->r15 = ctx->r5 | 0X8;
    // 0x80028B8C: jal         0x80034640
    // 0x80028B90: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    LOOKUP_FUNC(0x80034640)(rdram, ctx);
        goto after_5;
    // 0x80028B90: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_5:
    // 0x80028B94: beq         $v0, $zero, L_80028BBC
    if (ctx->r2 == 0) {
        // 0x80028B98: nop
    
            goto L_80028BBC;
    }
    // 0x80028B98: nop

L_80028B9C:
    // 0x80028B9C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80028BA0: lui         $a0, 0x1FC0
    ctx->r4 = S32(0X1FC0 << 16);
    // 0x80028BA4: ori         $a0, $a0, 0x7FC
    ctx->r4 = ctx->r4 | 0X7FC;
    // 0x80028BA8: ori         $t8, $a1, 0x8
    ctx->r24 = ctx->r5 | 0X8;
    // 0x80028BAC: jal         0x80034640
    // 0x80028BB0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    LOOKUP_FUNC(0x80034640)(rdram, ctx);
        goto after_6;
    // 0x80028BB0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_6:
    // 0x80028BB4: bne         $v0, $zero, L_80028B9C
    if (ctx->r2 != 0) {
        // 0x80028BB8: nop
    
            goto L_80028B9C;
    }
    // 0x80028BB8: nop

L_80028BBC:
    // 0x80028BBC: lui         $t0, 0x8002
    ctx->r8 = S32(0X8002 << 16);
    // 0x80028BC0: addiu       $t0, $t0, 0x70B0
    ctx->r8 = ADD32(ctx->r8, 0X70B0);
    // 0x80028BC4: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80028BC8: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80028BCC: lui         $t5, 0x8002
    ctx->r13 = S32(0X8002 << 16);
    // 0x80028BD0: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x80028BD4: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80028BD8: addiu       $t5, $t5, 0x70B0
    ctx->r13 = ADD32(ctx->r13, 0X70B0);
    // 0x80028BDC: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80028BE0: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x80028BE4: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80028BE8: ori         $t4, $t4, 0x80
    ctx->r12 = ctx->r12 | 0X80;
    // 0x80028BEC: lui         $t1, 0x8002
    ctx->r9 = S32(0X8002 << 16);
    // 0x80028BF0: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x80028BF4: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x80028BF8: addiu       $t1, $t1, 0x70B0
    ctx->r9 = ADD32(ctx->r9, 0X70B0);
    // 0x80028BFC: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80028C00: sw          $t3, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r11;
    // 0x80028C04: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x80028C08: ori         $t2, $t2, 0x100
    ctx->r10 = ctx->r10 | 0X100;
    // 0x80028C0C: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80028C10: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x80028C14: lw          $t8, 0x4($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X4);
    // 0x80028C18: addiu       $t6, $t6, 0x70B0
    ctx->r14 = ADD32(ctx->r14, 0X70B0);
    // 0x80028C1C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80028C20: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x80028C24: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x80028C28: ori         $t7, $t7, 0x180
    ctx->r15 = ctx->r15 | 0X180;
    // 0x80028C2C: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x80028C30: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x80028C34: lw          $t8, 0xC($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XC);
    // 0x80028C38: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x80028C3C: sw          $t8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r24;
    // 0x80028C40: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80028C44: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x80028C48: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80028C4C: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x80028C50: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x80028C54: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    // 0x80028C58: lw          $t3, 0xC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XC);
    // 0x80028C5C: sw          $t3, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r11;
    // 0x80028C60: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80028C64: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x80028C68: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80028C6C: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x80028C70: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80028C74: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x80028C78: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x80028C7C: jal         0x80028A90
    // 0x80028C80: sw          $t8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r24;
    LOOKUP_FUNC(0x80028A90)(rdram, ctx);
        goto after_7;
    // 0x80028C80: sw          $t8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r24;
    after_7:
    // 0x80028C84: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x80028C88: jal         0x80030640
    // 0x80028C8C: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    LOOKUP_FUNC(0x80030640)(rdram, ctx);
        goto after_8;
    // 0x80028C8C: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    after_8:
    // 0x80028C90: jal         0x80028DB8
    // 0x80028C94: nop

    LOOKUP_FUNC(0x80028DB8)(rdram, ctx);
        goto after_9;
    // 0x80028C94: nop

    after_9:
    // 0x80028C98: jal         0x800304A0
    // 0x80028C9C: nop

    LOOKUP_FUNC(0x800304A0)(rdram, ctx);
        goto after_10;
    // 0x80028C9C: nop

    after_10:
    // 0x80028CA0: jal         0x80033C70
    // 0x80028CA4: nop

    LOOKUP_FUNC(0x80033C70)(rdram, ctx);
        goto after_11;
    // 0x80028CA4: nop

    after_11:
    // 0x80028CA8: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80028CAC: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80028CB0: lw          $a1, -0x668C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X668C);
    // 0x80028CB4: lw          $a0, -0x6690($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6690);
    // 0x80028CB8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80028CBC: jal         0x80026F58
    // 0x80028CC0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80026F58)(rdram, ctx);
        goto after_12;
    // 0x80028CC0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_12:
    // 0x80028CC4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80028CC8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80028CCC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80028CD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80028CD4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80028CD8: jal         0x80026E58
    // 0x80028CDC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80026E58)(rdram, ctx);
        goto after_13;
    // 0x80028CDC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_13:
    // 0x80028CE0: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80028CE4: lw          $t0, 0x30C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30C);
    // 0x80028CE8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80028CEC: sw          $v0, -0x6690($at)
    MEM_W(-0X6690, ctx->r1) = ctx->r2;
    // 0x80028CF0: bne         $t0, $zero, L_80028D08
    if (ctx->r8 != 0) {
        // 0x80028CF4: sw          $v1, -0x668C($at)
        MEM_W(-0X668C, ctx->r1) = ctx->r3;
            goto L_80028D08;
    }
    // 0x80028CF4: sw          $v1, -0x668C($at)
    MEM_W(-0X668C, ctx->r1) = ctx->r3;
    // 0x80028CF8: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x80028CFC: addiu       $a0, $a0, 0x31C
    ctx->r4 = ADD32(ctx->r4, 0X31C);
    // 0x80028D00: jal         0x800279F0
    // 0x80028D04: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    LOOKUP_FUNC(0x800279F0)(rdram, ctx);
        goto after_14;
    // 0x80028D04: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_14:
L_80028D08:
    // 0x80028D08: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80028D0C: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x80028D10: bne         $t9, $zero, L_80028D2C
    if (ctx->r25 != 0) {
        // 0x80028D14: nop
    
            goto L_80028D2C;
    }
    // 0x80028D14: nop

    // 0x80028D18: lui         $t2, 0x2F5
    ctx->r10 = S32(0X2F5 << 16);
    // 0x80028D1C: ori         $t2, $t2, 0xB2D2
    ctx->r10 = ctx->r10 | 0XB2D2;
    // 0x80028D20: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80028D24: b           L_80028D64
    // 0x80028D28: sw          $t2, -0x6688($at)
    MEM_W(-0X6688, ctx->r1) = ctx->r10;
        goto L_80028D64;
    // 0x80028D28: sw          $t2, -0x6688($at)
    MEM_W(-0X6688, ctx->r1) = ctx->r10;
L_80028D2C:
    // 0x80028D2C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80028D30: lw          $t1, 0x300($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X300);
    // 0x80028D34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80028D38: bne         $t1, $at, L_80028D54
    if (ctx->r9 != ctx->r1) {
        // 0x80028D3C: nop
    
            goto L_80028D54;
    }
    // 0x80028D3C: nop

    // 0x80028D40: lui         $t3, 0x2E6
    ctx->r11 = S32(0X2E6 << 16);
    // 0x80028D44: ori         $t3, $t3, 0x25C
    ctx->r11 = ctx->r11 | 0X25C;
    // 0x80028D48: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80028D4C: b           L_80028D64
    // 0x80028D50: sw          $t3, -0x6688($at)
    MEM_W(-0X6688, ctx->r1) = ctx->r11;
        goto L_80028D64;
    // 0x80028D50: sw          $t3, -0x6688($at)
    MEM_W(-0X6688, ctx->r1) = ctx->r11;
L_80028D54:
    // 0x80028D54: lui         $t5, 0x2E6
    ctx->r13 = S32(0X2E6 << 16);
    // 0x80028D58: ori         $t5, $t5, 0xD354
    ctx->r13 = ctx->r13 | 0XD354;
    // 0x80028D5C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80028D60: sw          $t5, -0x6688($at)
    MEM_W(-0X6688, ctx->r1) = ctx->r13;
L_80028D64:
    // 0x80028D64: jal         0x80033E00
    // 0x80028D68: nop

    LOOKUP_FUNC(0x80033E00)(rdram, ctx);
        goto after_15;
    // 0x80028D68: nop

    after_15:
    // 0x80028D6C: andi        $t4, $v0, 0x1000
    ctx->r12 = ctx->r2 & 0X1000;
    // 0x80028D70: beq         $t4, $zero, L_80028D80
    if (ctx->r12 == 0) {
        // 0x80028D74: nop
    
            goto L_80028D80;
    }
    // 0x80028D74: nop

L_80028D78:
    // 0x80028D78: b           L_80028D78
    pause_self(rdram);
    // 0x80028D7C: nop

L_80028D80:
    // 0x80028D80: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80028D84: lui         $t6, 0xA450
    ctx->r14 = S32(0XA450 << 16);
    // 0x80028D88: sw          $t7, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r15;
    // 0x80028D8C: addiu       $t8, $zero, 0x3FFF
    ctx->r24 = ADD32(0, 0X3FFF);
    // 0x80028D90: lui         $t0, 0xA450
    ctx->r8 = S32(0XA450 << 16);
    // 0x80028D94: sw          $t8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r24;
    // 0x80028D98: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x80028D9C: lui         $t2, 0xA450
    ctx->r10 = S32(0XA450 << 16);
    // 0x80028DA0: sw          $t9, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r25;
    // 0x80028DA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80028DA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80028DAC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80028DB0: jr          $ra
    // 0x80028DB4: nop

    return;
    // 0x80028DB4: nop

;}
RECOMP_FUNC void FUN_80028db8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028DB8: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80028DBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80028DC0: sb          $t6, -0x3DEC($at)
    MEM_B(-0X3DEC, ctx->r1) = ctx->r14;
    // 0x80028DC4: lui         $t7, 0xA460
    ctx->r15 = S32(0XA460 << 16);
    // 0x80028DC8: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80028DCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80028DD0: lui         $t9, 0xA460
    ctx->r25 = S32(0XA460 << 16);
    // 0x80028DD4: sb          $t8, -0x3DEB($at)
    MEM_B(-0X3DEB, ctx->r1) = ctx->r24;
    // 0x80028DD8: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x80028DDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80028DE0: lui         $t1, 0xA460
    ctx->r9 = S32(0XA460 << 16);
    // 0x80028DE4: sb          $t0, -0x3DE8($at)
    MEM_B(-0X3DE8, ctx->r1) = ctx->r8;
    // 0x80028DE8: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x80028DEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80028DF0: lui         $t3, 0xA460
    ctx->r11 = S32(0XA460 << 16);
    // 0x80028DF4: sb          $t2, -0x3DEA($at)
    MEM_B(-0X3DEA, ctx->r1) = ctx->r10;
    // 0x80028DF8: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x80028DFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80028E00: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80028E04: sb          $t4, -0x3DE9($at)
    MEM_B(-0X3DE9, ctx->r1) = ctx->r12;
    // 0x80028E08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80028E0C: sb          $t5, -0x3D74($at)
    MEM_B(-0X3D74, ctx->r1) = ctx->r13;
    // 0x80028E10: lui         $t6, 0xA460
    ctx->r14 = S32(0XA460 << 16);
    // 0x80028E14: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80028E18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80028E1C: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x80028E20: sb          $t7, -0x3D73($at)
    MEM_B(-0X3D73, ctx->r1) = ctx->r15;
    // 0x80028E24: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x80028E28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80028E2C: lui         $t0, 0xA460
    ctx->r8 = S32(0XA460 << 16);
    // 0x80028E30: sb          $t9, -0x3D70($at)
    MEM_B(-0X3D70, ctx->r1) = ctx->r25;
    // 0x80028E34: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x80028E38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80028E3C: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x80028E40: sb          $t1, -0x3D72($at)
    MEM_B(-0X3D72, ctx->r1) = ctx->r9;
    // 0x80028E44: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80028E48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80028E4C: jr          $ra
    // 0x80028E50: sb          $t3, -0x3D71($at)
    MEM_B(-0X3D71, ctx->r1) = ctx->r11;
    return;
    // 0x80028E50: sb          $t3, -0x3D71($at)
    MEM_B(-0X3D71, ctx->r1) = ctx->r11;
    // 0x80028E54: nop

    // 0x80028E58: nop

    // 0x80028E5C: nop

    // 0x80028E60: nop

    // 0x80028E64: nop

    // 0x80028E68: nop

    // 0x80028E6C: nop

    // 0x80028E70: nop

    // 0x80028E74: nop

    // 0x80028E78: nop

    // 0x80028E7C: nop

    // 0x80028E80: nop

    // 0x80028E84: nop

    // 0x80028E88: nop

    // 0x80028E8C: nop

    // 0x80028E90: nop

    // 0x80028E94: nop

    // 0x80028E98: nop

    // 0x80028E9C: nop

    // 0x80028EA0: nop

    // 0x80028EA4: nop

    // 0x80028EA8: nop

    // 0x80028EAC: nop

    // 0x80028EB0: nop

    // 0x80028EB4: nop

    // 0x80028EB8: nop

    // 0x80028EBC: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80028ec0(rdram, ctx);
;}
RECOMP_FUNC void FUN_80028ec0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028EC0: mtc0        $a0, Status
    cop0_status_write(ctx, ctx->r4);    // 0x80028EC4: nop

    // 0x80028EC8: jr          $ra
    // 0x80028ECC: nop

    return;
    // 0x80028ECC: nop

;}
RECOMP_FUNC void __osGetSR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028ED0: mfc0        $v0, Status
    ctx->r2 = cop0_status_read(ctx);
    // 0x80028ED4: jr          $ra
    // 0x80028ED8: nop

    return;
    // 0x80028ED8: nop

    // 0x80028EDC: nop

;}
RECOMP_FUNC void FUN_80028ee0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028EE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80028EEC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80028EF0: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80028EF4: lw          $t9, 0x28($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X28);
    // 0x80028EF8: sll         $t1, $a2, 16
    ctx->r9 = S32(ctx->r6 << 16);
    // 0x80028EFC: sra         $t6, $t1, 16
    ctx->r14 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80028F00: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80028F04: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80028F08: jalr        $t9
    // 0x80028F0C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80028F0C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x80028F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80028F18: jr          $ra
    // 0x80028F1C: nop

    return;
    // 0x80028F1C: nop

;}
RECOMP_FUNC void osViGetCurrentFramebuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028F20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80028F24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028F28: jal         0x80032660
    // 0x80028F2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(0x80032660)(rdram, ctx);
        goto after_0;
    // 0x80028F2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80028F30: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80028F34: lw          $t6, -0x512C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X512C);
    // 0x80028F38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80028F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80028F40: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80028F44: jal         0x800326D0
    // 0x80028F48: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x800326D0)(rdram, ctx);
        goto after_1;
    // 0x80028F48: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_1:
    // 0x80028F4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80028F50: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80028F54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80028F58: jr          $ra
    // 0x80028F5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80028F5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void FUN_80028f60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028F60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028F64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028F68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80028F6C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80028F70: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80028F74: beql        $t6, $zero, L_80028FE0
    if (ctx->r14 == 0) {
        // 0x80028F78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80028FE0;
    }
    goto skip_0;
    // 0x80028F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80028F7C: jal         0x8002C6A0
    // 0x80028F80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8002C6A0)(rdram, ctx);
        goto after_0;
    // 0x80028F80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80028F84: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80028F88: beq         $v0, $zero, L_80028FDC
    if (ctx->r2 == 0) {
        // 0x80028F8C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80028FDC;
    }
    // 0x80028F8C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80028F90: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80028F94: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x80028F98: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x80028F9C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80028FA0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x80028FA4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x80028FA8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80028FAC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80028FB0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80028FB4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80028FB8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80028FBC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x80028FC0: lh          $t4, 0x1A($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1A);
    // 0x80028FC4: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x80028FC8: lw          $t5, 0x8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X8);
    // 0x80028FCC: lw          $a0, 0xC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC);
    // 0x80028FD0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80028FD4: jalr        $t9
    // 0x80028FD8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80028FD8: nop

    after_1:
L_80028FDC:
    // 0x80028FDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80028FE0:
    // 0x80028FE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80028FE4: jr          $ra
    // 0x80028FE8: nop

    return;
    // 0x80028FE8: nop

    // 0x80028FEC: nop

;}
RECOMP_FUNC void FUN_80028ff0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028FF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80028FF4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80028FF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028FFC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80029000: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80029004: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80029008: jal         0x80029E30
    // 0x8002900C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x80029E30)(rdram, ctx);
        goto after_0;
    // 0x8002900C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80029010: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80029014: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80029018: ldc1        $f6, -0x2D10($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2D10);
    // 0x8002901C: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80029020: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80029024: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80029028: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002902C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x80029030: div.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80029034: jal         0x80032720
    // 0x80029038: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    LOOKUP_FUNC(0x80032720)(rdram, ctx);
        goto after_1;
    // 0x80029038: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8002903C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80029040: jal         0x80029280
    // 0x80029044: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    LOOKUP_FUNC(0x80029280)(rdram, ctx);
        goto after_2;
    // 0x80029044: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80029048: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002904C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80029050: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80029054: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80029058: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002905C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80029060: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80029064: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80029068: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8002906C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80029070: sub.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80029074: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80029078: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x8002907C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80029080: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80029084: div.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80029088: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x8002908C: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80029090: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80029094: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x80029098: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8002909C: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800290A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800290A4: nop

    // 0x800290A8: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x800290AC: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800290B0: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800290B4: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x800290B8: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800290BC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800290C0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800290C4: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800290C8: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800290CC: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800290D0: beq         $v1, $a0, L_80029114
    if (ctx->r3 == ctx->r4) {
        // 0x800290D4: lwc1        $f14, 0xC($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
            goto L_80029114;
    }
    // 0x800290D4: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
L_800290D8:
    // 0x800290D8: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800290DC: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800290E0: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800290E4: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800290E8: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800290EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800290F0: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800290F4: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800290F8: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800290FC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80029100: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80029104: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80029108: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002910C: bne         $v1, $a0, L_800290D8
    if (ctx->r3 != ctx->r4) {
        // 0x80029110: swc1        $f2, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
            goto L_800290D8;
    }
    // 0x80029110: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
L_80029114:
    // 0x80029114: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80029118: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002911C: swc1        $f10, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80029120: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80029124: nop

    // 0x80029128: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8002912C: swc1        $f8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80029130: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80029134: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80029138: beq         $a1, $zero, L_80029210
    if (ctx->r5 == 0) {
        // 0x8002913C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80029210;
    }
    // 0x8002913C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80029140: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80029144: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80029148: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8002914C: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80029150: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x80029154: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80029158: bc1fl       L_8002916C
    if (!c1cs) {
        // 0x8002915C: mtc1        $at, $f11
        ctx->f_odd[(11 - 1) * 2] = ctx->r1;
            goto L_8002916C;
    }
    goto skip_0;
    // 0x8002915C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x80029160: b           L_80029210
    // 0x80029164: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
        goto L_80029210;
    // 0x80029164: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80029168: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
L_8002916C:
    // 0x8002916C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80029170: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80029174: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80029178: div.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x8002917C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80029180: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80029184: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80029188: nop

    // 0x8002918C: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80029190: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80029194: nop

    // 0x80029198: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8002919C: beql        $t8, $zero, L_800291F0
    if (ctx->r24 == 0) {
        // 0x800291A0: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_800291F0;
    }
    goto skip_1;
    // 0x800291A0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x800291A4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800291A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800291AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800291B0: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x800291B4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800291B8: nop

    // 0x800291BC: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x800291C0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800291C4: nop

    // 0x800291C8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800291CC: bne         $t8, $zero, L_800291E4
    if (ctx->r24 != 0) {
        // 0x800291D0: nop
    
            goto L_800291E4;
    }
    // 0x800291D0: nop

    // 0x800291D4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800291D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800291DC: b           L_800291FC
    // 0x800291E0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800291FC;
    // 0x800291E0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800291E4:
    // 0x800291E4: b           L_800291FC
    // 0x800291E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800291FC;
    // 0x800291E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800291EC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_800291F0:
    // 0x800291F0: nop

    // 0x800291F4: bltz        $t8, L_800291E4
    if (SIGNED(ctx->r24) < 0) {
        // 0x800291F8: nop
    
            goto L_800291E4;
    }
    // 0x800291F8: nop

L_800291FC:
    // 0x800291FC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80029200: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80029204: bgtz        $t9, L_80029210
    if (SIGNED(ctx->r25) > 0) {
        // 0x80029208: sh          $t8, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r24;
            goto L_80029210;
    }
    // 0x80029208: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8002920C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_80029210:
    // 0x80029210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029214: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80029218: jr          $ra
    // 0x8002921C: nop

    return;
    // 0x8002921C: nop

;}
RECOMP_FUNC void FUN_80029220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029220: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80029224: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80029228: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8002922C: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80029230: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80029234: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80029238: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002923C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80029240: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80029244: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80029248: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8002924C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80029250: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80029254: jal         0x80028FF0
    // 0x80029258: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80028FF0)(rdram, ctx);
        goto after_0;
    // 0x80029258: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8002925C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80029260: jal         0x80029D30
    // 0x80029264: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    LOOKUP_FUNC(0x80029D30)(rdram, ctx);
        goto after_1;
    // 0x80029264: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x80029268: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002926C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80029270: jr          $ra
    // 0x80029274: nop

    return;
    // 0x80029274: nop

    // 0x80029278: nop

    // 0x8002927C: nop

;}
RECOMP_FUNC void FUN_80029280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029280: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x80029284: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80029288: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002928C: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x80029290: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x80029294: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x80029298: beq         $at, $zero, L_80029300
    if (ctx->r1 == 0) {
        // 0x8002929C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80029300;
    }
    // 0x8002929C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800292A0: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x800292A4: bne         $at, $zero, L_800292F8
    if (ctx->r1 != 0) {
        // 0x800292A8: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_800292F8;
    }
    // 0x800292A8: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800292AC: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800292B0: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x800292B4: addiu       $v1, $v1, -0x2D00
    ctx->r3 = ADD32(ctx->r3, -0X2D00);
    // 0x800292B8: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x800292BC: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x800292C0: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800292C4: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800292C8: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800292CC: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800292D0: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x800292D4: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x800292D8: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800292DC: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x800292E0: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800292E4: nop

    // 0x800292E8: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x800292EC: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x800292F0: jr          $ra
    // 0x800292F4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x800292F4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_800292F8:
    // 0x800292F8: jr          $ra
    // 0x800292FC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    return;
    // 0x800292FC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
L_80029300:
    // 0x80029300: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x80029304: beq         $at, $zero, L_80029418
    if (ctx->r1 == 0) {
        // 0x80029308: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
            goto L_80029418;
    }
    // 0x80029308: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002930C: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80029310: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80029314: ldc1        $f10, -0x2CD8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2CD8);
    // 0x80029318: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x8002931C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80029320: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x80029324: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80029328: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002932C: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x80029330: nop

    // 0x80029334: bc1fl       L_80029364
    if (!c1cs) {
        // 0x80029338: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_80029364;
    }
    goto skip_0;
    // 0x80029338: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x8002933C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80029340: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80029344: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80029348: nop

    // 0x8002934C: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x80029350: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x80029354: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80029358: b           L_80029380
    // 0x8002935C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_80029380;
    // 0x8002935C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80029360: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_80029364:
    // 0x80029364: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80029368: nop

    // 0x8002936C: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x80029370: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80029374: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80029378: nop

    // 0x8002937C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_80029380:
    // 0x80029380: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80029384: ldc1        $f18, -0x2CD0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2CD0);
    // 0x80029388: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x8002938C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80029390: ldc1        $f6, -0x2CC8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2CC8);
    // 0x80029394: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x80029398: addiu       $v1, $v1, -0x2D00
    ctx->r3 = ADD32(ctx->r3, -0X2D00);
    // 0x8002939C: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x800293A0: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x800293A4: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x800293A8: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800293AC: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800293B0: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x800293B4: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x800293B8: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x800293BC: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800293C0: nop

    // 0x800293C4: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800293C8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800293CC: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x800293D0: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x800293D4: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x800293D8: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800293DC: bne         $t9, $zero, L_800293FC
    if (ctx->r25 != 0) {
        // 0x800293E0: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_800293FC;
    }
    // 0x800293E0: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x800293E4: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800293E8: nop

    // 0x800293EC: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x800293F0: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800293F4: jr          $ra
    // 0x800293F8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800293F8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800293FC:
    // 0x800293FC: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x80029400: nop

    // 0x80029404: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x80029408: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x8002940C: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x80029410: jr          $ra
    // 0x80029414: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x80029414: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_80029418:
    // 0x80029418: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x8002941C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80029420: bc1t        L_80029434
    if (c1cs) {
        // 0x80029424: nop
    
            goto L_80029434;
    }
    // 0x80029424: nop

    // 0x80029428: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002942C: jr          $ra
    // 0x80029430: lwc1        $f0, -0x2B30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B30);
    return;
    // 0x80029430: lwc1        $f0, -0x2B30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B30);
L_80029434:
    // 0x80029434: lwc1        $f0, -0x2CC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2CC0);
    // 0x80029438: jr          $ra
    // 0x8002943C: nop

    return;
    // 0x8002943C: nop

;}
RECOMP_FUNC void osEPiLinkHandle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029580: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80029584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029588: jal         0x80032660
    // 0x8002958C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80032660)(rdram, ctx);
        goto after_0;
    // 0x8002958C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80029590: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80029594: lw          $t6, -0x54D4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X54D4);
    // 0x80029598: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8002959C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800295A0: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800295A4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800295A8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800295AC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800295B0: jal         0x800326D0
    // 0x800295B4: sw          $t8, -0x54D4($at)
    MEM_W(-0X54D4, ctx->r1) = ctx->r24;
    LOOKUP_FUNC(0x800326D0)(rdram, ctx);
        goto after_1;
    // 0x800295B4: sw          $t8, -0x54D4($at)
    MEM_W(-0X54D4, ctx->r1) = ctx->r24;
    after_1:
    // 0x800295B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800295BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800295C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800295C4: jr          $ra
    // 0x800295C8: nop

    return;
    // 0x800295C8: nop

    // 0x800295CC: nop

;}
