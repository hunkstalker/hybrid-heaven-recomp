#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FUN_80002bac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002BAC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80002BB0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80002BB4: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80002BB8: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x80002BBC: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80002BC0: lw          $t6, 0x7780($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7780);
    // 0x80002BC4: lui         $at, 0x8003
    ctx->r1 = S32(0X8003 << 16);
    // 0x80002BC8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80002BCC: beq         $t6, $zero, L_80002BD8
    if (ctx->r14 == 0) {
        // 0x80002BD0: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_80002BD8;
    }
    // 0x80002BD0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80002BD4: sw          $t7, 0x7770($at)
    MEM_W(0X7770, ctx->r1) = ctx->r15;
L_80002BD8:
    // 0x80002BD8: jr          $ra
    // 0x80002BDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80002BDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80002be0(rdram, ctx);
;}
RECOMP_FUNC void FUN_80002be0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002BE0: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x80002BE4: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80002BE8: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80002BEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80002BF0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80002BF4: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x80002BF8: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80002BFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80002C00: addiu       $t7, $t7, -0x3190
    ctx->r15 = ADD32(ctx->r15, -0X3190);
    // 0x80002C04: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80002C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002C0C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80002C10: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80002C14: addiu       $a0, $a0, -0x31E0
    ctx->r4 = ADD32(ctx->r4, -0X31E0);
    // 0x80002C18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80002C1C: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
    // 0x80002C20: jal         0x80032FB0
    // 0x80002C24: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80032FB0)(rdram, ctx);
        goto after_0;
    // 0x80002C24: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80002C28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80002C2C: bne         $v0, $at, L_80002C38
    if (ctx->r2 != ctx->r1) {
        // 0x80002C30: lbu         $v1, 0x27($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X27);
            goto L_80002C38;
    }
    // 0x80002C30: lbu         $v1, 0x27($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X27);
    // 0x80002C34: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80002C38:
    // 0x80002C38: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80002C3C: addiu       $a0, $a0, -0x31E0
    ctx->r4 = ADD32(ctx->r4, -0X31E0);
    // 0x80002C40: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80002C44: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80002C48: jal         0x80027D04
    // 0x80002C4C: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80027D04)(rdram, ctx);
        goto after_1;
    // 0x80002C4C: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    after_1:
    // 0x80002C50: bne         $v0, $zero, L_80002C5C
    if (ctx->r2 != 0) {
        // 0x80002C54: lbu         $v1, 0x27($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X27);
            goto L_80002C5C;
    }
    // 0x80002C54: lbu         $v1, 0x27($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X27);
    // 0x80002C58: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
L_80002C5C:
    // 0x80002C5C: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80002C60: addiu       $a0, $a0, -0x31E0
    ctx->r4 = ADD32(ctx->r4, -0X31E0);
    // 0x80002C64: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80002C68: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80002C6C: jal         0x80031FF0
    // 0x80002C70: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80031FF0)(rdram, ctx);
        goto after_2;
    // 0x80002C70: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    after_2:
    // 0x80002C74: bne         $v0, $zero, L_80002C80
    if (ctx->r2 != 0) {
        // 0x80002C78: lbu         $v1, 0x27($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X27);
            goto L_80002C80;
    }
    // 0x80002C78: lbu         $v1, 0x27($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X27);
    // 0x80002C7C: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
L_80002C80:
    // 0x80002C80: bne         $v1, $zero, L_80002CEC
    if (ctx->r3 != 0) {
        // 0x80002C84: lui         $a0, 0x8006
        ctx->r4 = S32(0X8006 << 16);
            goto L_80002CEC;
    }
    // 0x80002C84: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80002C88: addiu       $a0, $a0, -0x31E0
    ctx->r4 = ADD32(ctx->r4, -0X31E0);
    // 0x80002C8C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80002C90: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80002C94: jal         0x80032FB0
    // 0x80002C98: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80032FB0)(rdram, ctx);
        goto after_3;
    // 0x80002C98: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    after_3:
    // 0x80002C9C: sltiu       $at, $v0, 0xC
    ctx->r1 = ctx->r2 < 0XC ? 1 : 0;
    // 0x80002CA0: beq         $at, $zero, L_80002CEC
    if (ctx->r1 == 0) {
        // 0x80002CA4: lbu         $v1, 0x27($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X27);
            goto L_80002CEC;
    }
    // 0x80002CA4: lbu         $v1, 0x27($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X27);
    // 0x80002CA8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80002CAC: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80002CB0: addu        $at, $at, $t8
    gpr jr_addend_80002CB8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80002CB4: lw          $t8, -0x4630($at)
    ctx->r24 = ADD32(ctx->r1, -0X4630);
    // 0x80002CB8: jr          $t8
    // 0x80002CBC: nop

    switch (jr_addend_80002CB8 >> 2) {
        case 0: goto L_80002CC0; break;
        case 1: goto L_80002CC8; break;
        case 2: goto L_80002CD0; break;
        case 3: goto L_80002CEC; break;
        case 4: goto L_80002CD8; break;
        case 5: goto L_80002CEC; break;
        case 6: goto L_80002CEC; break;
        case 7: goto L_80002CEC; break;
        case 8: goto L_80002CEC; break;
        case 9: goto L_80002CEC; break;
        case 10: goto L_80002CE0; break;
        case 11: goto L_80002CE8; break;
        default: switch_error(__func__, 0x80002CB8, 0x8004B9D0);
    }
    // 0x80002CBC: nop

L_80002CC0:
    // 0x80002CC0: b           L_80002CEC
    // 0x80002CC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80002CEC;
    // 0x80002CC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80002CC8:
    // 0x80002CC8: b           L_80002CEC
    // 0x80002CCC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80002CEC;
    // 0x80002CCC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80002CD0:
    // 0x80002CD0: b           L_80002CEC
    // 0x80002CD4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80002CEC;
    // 0x80002CD4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80002CD8:
    // 0x80002CD8: b           L_80002CEC
    // 0x80002CDC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80002CEC;
    // 0x80002CDC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80002CE0:
    // 0x80002CE0: b           L_80002CEC
    // 0x80002CE4: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_80002CEC;
    // 0x80002CE4: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80002CE8:
    // 0x80002CE8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80002CEC:
    // 0x80002CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002CF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80002CF4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80002CF8: jr          $ra
    // 0x80002CFC: nop

    return;
    // 0x80002CFC: nop

;}
RECOMP_FUNC void FUN_80002d00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002D00: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x80002D04: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80002D08: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80002D0C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80002D10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80002D14: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x80002D18: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80002D1C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80002D20: addiu       $t7, $t7, -0x3190
    ctx->r15 = ADD32(ctx->r15, -0X3190);
    // 0x80002D24: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80002D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002D2C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80002D30: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80002D34: addiu       $a0, $a0, -0x31E0
    ctx->r4 = ADD32(ctx->r4, -0X31E0);
    // 0x80002D38: jal         0x80032FB0
    // 0x80002D3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80032FB0)(rdram, ctx);
        goto after_0;
    // 0x80002D3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80002D40: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80002D44: bne         $v0, $at, L_80002D54
    if (ctx->r2 != ctx->r1) {
        // 0x80002D48: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80002D54;
    }
    // 0x80002D48: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80002D4C: jal         0x800308D0
    // 0x80002D50: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x800308D0)(rdram, ctx);
        goto after_1;
    // 0x80002D50: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
L_80002D54:
    // 0x80002D54: sltiu       $at, $v0, 0xC
    ctx->r1 = ctx->r2 < 0XC ? 1 : 0;
    // 0x80002D58: beq         $at, $zero, L_80002DA4
    if (ctx->r1 == 0) {
        // 0x80002D5C: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80002DA4;
    }
    // 0x80002D5C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80002D60: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80002D64: addu        $at, $at, $t8
    gpr jr_addend_80002D6C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80002D68: lw          $t8, -0x4600($at)
    ctx->r24 = ADD32(ctx->r1, -0X4600);
    // 0x80002D6C: jr          $t8
    // 0x80002D70: nop

    switch (jr_addend_80002D6C >> 2) {
        case 0: goto L_80002D74; break;
        case 1: goto L_80002D7C; break;
        case 2: goto L_80002D84; break;
        case 3: goto L_80002DA4; break;
        case 4: goto L_80002D8C; break;
        case 5: goto L_80002DA4; break;
        case 6: goto L_80002DA4; break;
        case 7: goto L_80002DA4; break;
        case 8: goto L_80002DA4; break;
        case 9: goto L_80002DA4; break;
        case 10: goto L_80002D94; break;
        case 11: goto L_80002D9C; break;
        default: switch_error(__func__, 0x80002D6C, 0x8004BA00);
    }
    // 0x80002D70: nop

L_80002D74:
    // 0x80002D74: b           L_80002DA8
    // 0x80002D78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80002DA8;
    // 0x80002D78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80002D7C:
    // 0x80002D7C: b           L_80002DA8
    // 0x80002D80: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80002DA8;
    // 0x80002D80: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80002D84:
    // 0x80002D84: b           L_80002DA8
    // 0x80002D88: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80002DA8;
    // 0x80002D88: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80002D8C:
    // 0x80002D8C: b           L_80002DA8
    // 0x80002D90: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80002DA8;
    // 0x80002D90: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80002D94:
    // 0x80002D94: b           L_80002DA8
    // 0x80002D98: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_80002DA8;
    // 0x80002D98: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80002D9C:
    // 0x80002D9C: b           L_80002DA8
    // 0x80002DA0: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80002DA8;
    // 0x80002DA0: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80002DA4:
    // 0x80002DA4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80002DA8:
    // 0x80002DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002DAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80002DB0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80002DB4: jr          $ra
    // 0x80002DB8: nop

    return;
    // 0x80002DB8: nop

;}
RECOMP_FUNC void FUN_80002dbc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002DBC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80002DC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002DC4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80002DC8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80002DCC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80002DD0: jal         0x80002BE0
    // 0x80002DD4: lbu         $a0, 0x53($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X53);
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_0;
    // 0x80002DD4: lbu         $a0, 0x53($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X53);
    after_0:
    // 0x80002DD8: bne         $v0, $zero, L_80002EDC
    if (ctx->r2 != 0) {
        // 0x80002DDC: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_80002EDC;
    }
    // 0x80002DDC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80002DE0: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x80002DE4: addiu       $t7, $t7, 0x7790
    ctx->r15 = ADD32(ctx->r15, 0X7790);
    // 0x80002DE8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80002DEC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80002DF0: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x80002DF4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80002DF8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80002DFC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80002E00: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80002E04: lui         $t4, 0x8006
    ctx->r12 = S32(0X8006 << 16);
    // 0x80002E08: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80002E0C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80002E10: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80002E14: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80002E18: addiu       $t4, $t4, -0x3190
    ctx->r12 = ADD32(ctx->r12, -0X3190);
    // 0x80002E1C: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80002E20: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80002E24: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80002E28: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80002E2C: addiu       $t5, $sp, 0x2E
    ctx->r13 = ADD32(ctx->r29, 0X2E);
    // 0x80002E30: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x80002E34: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x80002E38: lbu         $t2, 0x53($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X53);
    // 0x80002E3C: lbu         $t0, 0x57($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X57);
    // 0x80002E40: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x80002E44: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80002E48: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80002E4C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80002E50: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80002E54: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80002E58: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x80002E5C: sb          $t1, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r9;
    // 0x80002E60: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80002E64: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80002E68: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80002E6C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80002E70: lhu         $a1, 0x2C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2C);
    // 0x80002E74: jal         0x8002EE40
    // 0x80002E78: addiu       $a3, $sp, 0x32
    ctx->r7 = ADD32(ctx->r29, 0X32);
    LOOKUP_FUNC(0x8002EE40)(rdram, ctx);
        goto after_1;
    // 0x80002E78: addiu       $a3, $sp, 0x32
    ctx->r7 = ADD32(ctx->r29, 0X32);
    after_1:
    // 0x80002E7C: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x80002E80: beq         $at, $zero, L_80002EDC
    if (ctx->r1 == 0) {
        // 0x80002E84: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80002EDC;
    }
    // 0x80002E84: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80002E88: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80002E8C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80002E90: addu        $at, $at, $t7
    gpr jr_addend_80002E98 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80002E94: lw          $t7, -0x45D0($at)
    ctx->r15 = ADD32(ctx->r1, -0X45D0);
    // 0x80002E98: jr          $t7
    // 0x80002E9C: nop

    switch (jr_addend_80002E98 >> 2) {
        case 0: goto L_80002EA0; break;
        case 1: goto L_80002EB4; break;
        case 2: goto L_80002EBC; break;
        case 3: goto L_80002EC4; break;
        case 4: goto L_80002ECC; break;
        case 5: goto L_80002ED4; break;
        default: switch_error(__func__, 0x80002E98, 0x8004BA30);
    }
    // 0x80002E9C: nop

L_80002EA0:
    // 0x80002EA0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80002EA4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80002EA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80002EAC: b           L_80002EDC
    // 0x80002EB0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
        goto L_80002EDC;
    // 0x80002EB0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
L_80002EB4:
    // 0x80002EB4: b           L_80002EDC
    // 0x80002EB8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80002EDC;
    // 0x80002EB8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80002EBC:
    // 0x80002EBC: b           L_80002EDC
    // 0x80002EC0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80002EDC;
    // 0x80002EC0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80002EC4:
    // 0x80002EC4: b           L_80002EDC
    // 0x80002EC8: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
        goto L_80002EDC;
    // 0x80002EC8: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_80002ECC:
    // 0x80002ECC: b           L_80002EDC
    // 0x80002ED0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80002EDC;
    // 0x80002ED0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80002ED4:
    // 0x80002ED4: b           L_80002EDC
    // 0x80002ED8: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
        goto L_80002EDC;
    // 0x80002ED8: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_80002EDC:
    // 0x80002EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002EE0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80002EE4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80002EE8: jr          $ra
    // 0x80002EEC: nop

    return;
    // 0x80002EEC: nop

;}
RECOMP_FUNC void FUN_80002ef0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002EF0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80002EF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80002EF8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80002EFC: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80002F00: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80002F04: jal         0x80002BE0
    // 0x80002F08: lbu         $a0, 0x5B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X5B);
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_0;
    // 0x80002F08: lbu         $a0, 0x5B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X5B);
    after_0:
    // 0x80002F0C: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80002F10: bne         $v0, $zero, L_80003028
    if (ctx->r2 != 0) {
        // 0x80002F14: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_80003028;
    }
    // 0x80002F14: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80002F18: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x80002F1C: addiu       $t7, $t7, 0x7790
    ctx->r15 = ADD32(ctx->r15, 0X7790);
    // 0x80002F20: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80002F24: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80002F28: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x80002F2C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80002F30: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80002F34: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80002F38: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80002F3C: lui         $t5, 0x8006
    ctx->r13 = S32(0X8006 << 16);
    // 0x80002F40: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80002F44: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80002F48: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80002F4C: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80002F50: addiu       $t5, $t5, -0x3190
    ctx->r13 = ADD32(ctx->r13, -0X3190);
    // 0x80002F54: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80002F58: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80002F5C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80002F60: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80002F64: addiu       $t7, $sp, 0x4C
    ctx->r15 = ADD32(ctx->r29, 0X4C);
    // 0x80002F68: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x80002F6C: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x80002F70: lbu         $t3, 0x5B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X5B);
    // 0x80002F74: lbu         $t1, 0x5F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X5F);
    // 0x80002F78: addiu       $t6, $sp, 0x36
    ctx->r14 = ADD32(ctx->r29, 0X36);
    // 0x80002F7C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80002F80: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80002F84: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80002F88: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80002F8C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80002F90: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x80002F94: sb          $t2, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r10;
    // 0x80002F98: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80002F9C: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x80002FA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80002FA4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80002FA8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80002FAC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80002FB0: lhu         $a1, 0x34($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X34);
    // 0x80002FB4: jal         0x8002A350
    // 0x80002FB8: addiu       $a3, $sp, 0x3A
    ctx->r7 = ADD32(ctx->r29, 0X3A);
    LOOKUP_FUNC(0x8002A350)(rdram, ctx);
        goto after_1;
    // 0x80002FB8: addiu       $a3, $sp, 0x3A
    ctx->r7 = ADD32(ctx->r29, 0X3A);
    after_1:
    // 0x80002FBC: sltiu       $at, $v0, 0xA
    ctx->r1 = ctx->r2 < 0XA ? 1 : 0;
    // 0x80002FC0: beq         $at, $zero, L_80003024
    if (ctx->r1 == 0) {
        // 0x80002FC4: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80003024;
    }
    // 0x80002FC4: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80002FC8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80002FCC: addu        $at, $at, $t8
    gpr jr_addend_80002FD4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80002FD0: lw          $t8, -0x45B8($at)
    ctx->r24 = ADD32(ctx->r1, -0X45B8);
    // 0x80002FD4: jr          $t8
    // 0x80002FD8: nop

    switch (jr_addend_80002FD4 >> 2) {
        case 0: goto L_80002FDC; break;
        case 1: goto L_80002FE4; break;
        case 2: goto L_80002FEC; break;
        case 3: goto L_80002FF4; break;
        case 4: goto L_80002FFC; break;
        case 5: goto L_80003004; break;
        case 6: goto L_80003024; break;
        case 7: goto L_8000300C; break;
        case 8: goto L_80003014; break;
        case 9: goto L_8000301C; break;
        default: switch_error(__func__, 0x80002FD4, 0x8004BA48);
    }
    // 0x80002FD8: nop

L_80002FDC:
    // 0x80002FDC: b           L_80003028
    // 0x80002FE0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80003028;
    // 0x80002FE0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80002FE4:
    // 0x80002FE4: b           L_80003028
    // 0x80002FE8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80003028;
    // 0x80002FE8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80002FEC:
    // 0x80002FEC: b           L_80003028
    // 0x80002FF0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80003028;
    // 0x80002FF0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80002FF4:
    // 0x80002FF4: b           L_80003028
    // 0x80002FF8: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
        goto L_80003028;
    // 0x80002FF8: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_80002FFC:
    // 0x80002FFC: b           L_80003028
    // 0x80003000: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80003028;
    // 0x80003000: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80003004:
    // 0x80003004: b           L_80003028
    // 0x80003008: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
        goto L_80003028;
    // 0x80003008: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_8000300C:
    // 0x8000300C: b           L_80003028
    // 0x80003010: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
        goto L_80003028;
    // 0x80003010: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_80003014:
    // 0x80003014: b           L_80003028
    // 0x80003018: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
        goto L_80003028;
    // 0x80003018: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
L_8000301C:
    // 0x8000301C: b           L_80003028
    // 0x80003020: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
        goto L_80003028;
    // 0x80003020: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
L_80003024:
    // 0x80003024: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80003028:
    // 0x80003028: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000302C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80003030: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80003034: jr          $ra
    // 0x80003038: nop

    return;
    // 0x80003038: nop

;}
RECOMP_FUNC void FUN_8000303c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000303C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80003040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80003044: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80003048: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8000304C: jal         0x80002BE0
    // 0x80003050: lbu         $a0, 0x53($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X53);
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_0;
    // 0x80003050: lbu         $a0, 0x53($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X53);
    after_0:
    // 0x80003054: bne         $v0, $zero, L_80003104
    if (ctx->r2 != 0) {
        // 0x80003058: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_80003104;
    }
    // 0x80003058: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8000305C: lbu         $t6, 0x53($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X53);
    // 0x80003060: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80003064: addiu       $t8, $t8, -0x3190
    ctx->r24 = ADD32(ctx->r24, -0X3190);
    // 0x80003068: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000306C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80003070: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80003074: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80003078: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8000307C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80003080: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80003084: lbu         $a1, 0x57($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X57);
    // 0x80003088: jal         0x80032DD0
    // 0x8000308C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80032DD0)(rdram, ctx);
        goto after_1;
    // 0x8000308C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80003090: bne         $v0, $zero, L_800030B0
    if (ctx->r2 != 0) {
        // 0x80003094: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_800030B0;
    }
    // 0x80003094: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80003098: addiu       $t9, $sp, 0x32
    ctx->r25 = ADD32(ctx->r29, 0X32);
    // 0x8000309C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800030A0: lhu         $a1, 0x30($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X30);
    // 0x800030A4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800030A8: jal         0x80031BC0
    // 0x800030AC: addiu       $a3, $sp, 0x36
    ctx->r7 = ADD32(ctx->r29, 0X36);
    LOOKUP_FUNC(0x80031BC0)(rdram, ctx);
        goto after_2;
    // 0x800030AC: addiu       $a3, $sp, 0x36
    ctx->r7 = ADD32(ctx->r29, 0X36);
    after_2:
L_800030B0:
    // 0x800030B0: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x800030B4: beq         $at, $zero, L_80003104
    if (ctx->r1 == 0) {
        // 0x800030B8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80003104;
    }
    // 0x800030B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800030BC: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x800030C0: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800030C4: addu        $at, $at, $t0
    gpr jr_addend_800030CC = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800030C8: lw          $t0, -0x4590($at)
    ctx->r8 = ADD32(ctx->r1, -0X4590);
    // 0x800030CC: jr          $t0
    // 0x800030D0: nop

    switch (jr_addend_800030CC >> 2) {
        case 0: goto L_800030D4; break;
        case 1: goto L_800030DC; break;
        case 2: goto L_800030E4; break;
        case 3: goto L_800030EC; break;
        case 4: goto L_800030F4; break;
        case 5: goto L_800030FC; break;
        default: switch_error(__func__, 0x800030CC, 0x8004BA70);
    }
    // 0x800030D0: nop

L_800030D4:
    // 0x800030D4: b           L_80003104
    // 0x800030D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80003104;
    // 0x800030D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800030DC:
    // 0x800030DC: b           L_80003104
    // 0x800030E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80003104;
    // 0x800030E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800030E4:
    // 0x800030E4: b           L_80003104
    // 0x800030E8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80003104;
    // 0x800030E8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800030EC:
    // 0x800030EC: b           L_80003104
    // 0x800030F0: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
        goto L_80003104;
    // 0x800030F0: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_800030F4:
    // 0x800030F4: b           L_80003104
    // 0x800030F8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80003104;
    // 0x800030F8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800030FC:
    // 0x800030FC: b           L_80003104
    // 0x80003100: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
        goto L_80003104;
    // 0x80003100: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_80003104:
    // 0x80003104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80003108: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8000310C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80003110: jr          $ra
    // 0x80003114: nop

    return;
    // 0x80003114: nop

;}
RECOMP_FUNC void FUN_80003118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003118: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000311C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003120: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80003124: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80003128: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8000312C: jal         0x80002BE0
    // 0x80003130: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_0;
    // 0x80003130: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    after_0:
    // 0x80003134: bne         $v0, $zero, L_800031D8
    if (ctx->r2 != 0) {
        // 0x80003138: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_800031D8;
    }
    // 0x80003138: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8000313C: lbu         $t7, 0x2B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2B);
    // 0x80003140: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x80003144: addiu       $t9, $t9, -0x3190
    ctx->r25 = ADD32(ctx->r25, -0X3190);
    // 0x80003148: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000314C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80003150: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80003154: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80003158: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8000315C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80003160: jal         0x80026450
    // 0x80003164: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x80026450)(rdram, ctx);
        goto after_1;
    // 0x80003164: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80003168: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x8000316C: beq         $at, $zero, L_800031D8
    if (ctx->r1 == 0) {
        // 0x80003170: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800031D8;
    }
    // 0x80003170: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80003174: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80003178: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000317C: addu        $at, $at, $t0
    gpr jr_addend_80003184 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80003180: lw          $t0, -0x4578($at)
    ctx->r8 = ADD32(ctx->r1, -0X4578);
    // 0x80003184: jr          $t0
    // 0x80003188: nop

    switch (jr_addend_80003184 >> 2) {
        case 0: goto L_8000318C; break;
        case 1: goto L_800031B0; break;
        case 2: goto L_800031B8; break;
        case 3: goto L_800031C0; break;
        case 4: goto L_800031C8; break;
        case 5: goto L_800031D0; break;
        default: switch_error(__func__, 0x80003184, 0x8004BA88);
    }
    // 0x80003188: nop

L_8000318C:
    // 0x8000318C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80003190: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80003194: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80003198: bgez        $t1, L_800031A8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8000319C: sra         $t2, $t1, 8
        ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
            goto L_800031A8;
    }
    // 0x8000319C: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x800031A0: addiu       $at, $t1, 0xFF
    ctx->r1 = ADD32(ctx->r9, 0XFF);
    // 0x800031A4: sra         $t2, $at, 8
    ctx->r10 = S32(SIGNED(ctx->r1) >> 8);
L_800031A8:
    // 0x800031A8: b           L_800031D8
    // 0x800031AC: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
        goto L_800031D8;
    // 0x800031AC: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
L_800031B0:
    // 0x800031B0: b           L_800031D8
    // 0x800031B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800031D8;
    // 0x800031B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800031B8:
    // 0x800031B8: b           L_800031D8
    // 0x800031BC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_800031D8;
    // 0x800031BC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800031C0:
    // 0x800031C0: b           L_800031D8
    // 0x800031C4: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
        goto L_800031D8;
    // 0x800031C4: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_800031C8:
    // 0x800031C8: b           L_800031D8
    // 0x800031CC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_800031D8;
    // 0x800031CC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800031D0:
    // 0x800031D0: b           L_800031D8
    // 0x800031D4: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
        goto L_800031D8;
    // 0x800031D4: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_800031D8:
    // 0x800031D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800031DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800031E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800031E4: jr          $ra
    // 0x800031E8: nop

    return;
    // 0x800031E8: nop

;}
RECOMP_FUNC void FUN_800031ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800031EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800031F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800031F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800031F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800031FC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80003200: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80003204: jal         0x80002BE0
    // 0x80003208: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_0;
    // 0x80003208: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    after_0:
    // 0x8000320C: bne         $v0, $zero, L_800032CC
    if (ctx->r2 != 0) {
        // 0x80003210: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_800032CC;
    }
    // 0x80003210: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80003214: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x80003218: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x8000321C: jal         0x80002DBC
    // 0x80003220: addiu       $a2, $sp, 0x26
    ctx->r6 = ADD32(ctx->r29, 0X26);
    LOOKUP_FUNC(0x80002DBC)(rdram, ctx);
        goto after_1;
    // 0x80003220: addiu       $a2, $sp, 0x26
    ctx->r6 = ADD32(ctx->r29, 0X26);
    after_1:
    // 0x80003224: bne         $v0, $zero, L_800032CC
    if (ctx->r2 != 0) {
        // 0x80003228: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_800032CC;
    }
    // 0x80003228: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8000322C: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x80003230: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x80003234: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80003238: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000323C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80003240: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80003244: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80003248: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8000324C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80003250: addiu       $t8, $t8, -0x3190
    ctx->r24 = ADD32(ctx->r24, -0X3190);
    // 0x80003254: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80003258: lbu         $a1, 0x26($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X26);
    // 0x8000325C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80003260: lhu         $a3, 0x32($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X32);
    // 0x80003264: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80003268: jal         0x80029784
    // 0x8000326C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80029784)(rdram, ctx);
        goto after_2;
    // 0x8000326C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_2:
    // 0x80003270: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x80003274: beq         $at, $zero, L_800032CC
    if (ctx->r1 == 0) {
        // 0x80003278: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800032CC;
    }
    // 0x80003278: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000327C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80003280: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80003284: addu        $at, $at, $t1
    gpr jr_addend_8000328C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80003288: lw          $t1, -0x4560($at)
    ctx->r9 = ADD32(ctx->r1, -0X4560);
    // 0x8000328C: jr          $t1
    // 0x80003290: nop

    switch (jr_addend_8000328C >> 2) {
        case 0: goto L_80003294; break;
        case 1: goto L_8000329C; break;
        case 2: goto L_800032A4; break;
        case 3: goto L_800032AC; break;
        case 4: goto L_800032B4; break;
        case 5: goto L_800032BC; break;
        case 6: goto L_800032C4; break;
        default: switch_error(__func__, 0x8000328C, 0x8004BAA0);
    }
    // 0x80003290: nop

L_80003294:
    // 0x80003294: b           L_800032CC
    // 0x80003298: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800032CC;
    // 0x80003298: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000329C:
    // 0x8000329C: b           L_800032CC
    // 0x800032A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800032CC;
    // 0x800032A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800032A4:
    // 0x800032A4: b           L_800032CC
    // 0x800032A8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_800032CC;
    // 0x800032A8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800032AC:
    // 0x800032AC: b           L_800032CC
    // 0x800032B0: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
        goto L_800032CC;
    // 0x800032B0: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_800032B4:
    // 0x800032B4: b           L_800032CC
    // 0x800032B8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_800032CC;
    // 0x800032B8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800032BC:
    // 0x800032BC: b           L_800032CC
    // 0x800032C0: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
        goto L_800032CC;
    // 0x800032C0: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_800032C4:
    // 0x800032C4: b           L_800032CC
    // 0x800032C8: addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
        goto L_800032CC;
    // 0x800032C8: addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
L_800032CC:
    // 0x800032CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800032D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800032D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800032D8: jr          $ra
    // 0x800032DC: nop

    return;
    // 0x800032DC: nop

;}
RECOMP_FUNC void FUN_800032e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800032E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800032E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800032E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800032EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800032F0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800032F4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800032F8: jal         0x80002BE0
    // 0x800032FC: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_0;
    // 0x800032FC: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    after_0:
    // 0x80003300: bne         $v0, $zero, L_800033B8
    if (ctx->r2 != 0) {
        // 0x80003304: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_800033B8;
    }
    // 0x80003304: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80003308: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x8000330C: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x80003310: jal         0x80002DBC
    // 0x80003314: addiu       $a2, $sp, 0x26
    ctx->r6 = ADD32(ctx->r29, 0X26);
    LOOKUP_FUNC(0x80002DBC)(rdram, ctx);
        goto after_1;
    // 0x80003314: addiu       $a2, $sp, 0x26
    ctx->r6 = ADD32(ctx->r29, 0X26);
    after_1:
    // 0x80003318: bne         $v0, $zero, L_800033B8
    if (ctx->r2 != 0) {
        // 0x8000331C: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_800033B8;
    }
    // 0x8000331C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80003320: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x80003324: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x80003328: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8000332C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80003330: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80003334: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80003338: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x8000333C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80003340: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80003344: addiu       $t8, $t8, -0x3190
    ctx->r24 = ADD32(ctx->r24, -0X3190);
    // 0x80003348: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x8000334C: lbu         $a1, 0x26($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X26);
    // 0x80003350: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80003354: lhu         $a3, 0x32($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X32);
    // 0x80003358: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8000335C: jal         0x80029784
    // 0x80003360: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80029784)(rdram, ctx);
        goto after_2;
    // 0x80003360: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_2:
    // 0x80003364: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x80003368: beq         $at, $zero, L_800033B8
    if (ctx->r1 == 0) {
        // 0x8000336C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800033B8;
    }
    // 0x8000336C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80003370: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80003374: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80003378: addu        $at, $at, $t1
    gpr jr_addend_80003380 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8000337C: lw          $t1, -0x4544($at)
    ctx->r9 = ADD32(ctx->r1, -0X4544);
    // 0x80003380: jr          $t1
    // 0x80003384: nop

    switch (jr_addend_80003380 >> 2) {
        case 0: goto L_80003388; break;
        case 1: goto L_80003390; break;
        case 2: goto L_80003398; break;
        case 3: goto L_800033A0; break;
        case 4: goto L_800033A8; break;
        case 5: goto L_800033B0; break;
        default: switch_error(__func__, 0x80003380, 0x8004BABC);
    }
    // 0x80003384: nop

L_80003388:
    // 0x80003388: b           L_800033B8
    // 0x8000338C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800033B8;
    // 0x8000338C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80003390:
    // 0x80003390: b           L_800033B8
    // 0x80003394: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800033B8;
    // 0x80003394: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80003398:
    // 0x80003398: b           L_800033B8
    // 0x8000339C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_800033B8;
    // 0x8000339C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800033A0:
    // 0x800033A0: b           L_800033B8
    // 0x800033A4: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
        goto L_800033B8;
    // 0x800033A4: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_800033A8:
    // 0x800033A8: b           L_800033B8
    // 0x800033AC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_800033B8;
    // 0x800033AC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800033B0:
    // 0x800033B0: b           L_800033B8
    // 0x800033B4: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
        goto L_800033B8;
    // 0x800033B4: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_800033B8:
    // 0x800033B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800033BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800033C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800033C4: jr          $ra
    // 0x800033C8: nop

    return;
    // 0x800033C8: nop

;}
RECOMP_FUNC void FUN_800033cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800033CC: addiu       $sp, $sp, -0x290
    ctx->r29 = ADD32(ctx->r29, -0X290);
    // 0x800033D0: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x800033D4: sw          $a0, 0x290($sp)
    MEM_W(0X290, ctx->r29) = ctx->r4;
    // 0x800033D8: addiu       $t1, $sp, 0xC
    ctx->r9 = ADD32(ctx->r29, 0XC);
    // 0x800033DC: addiu       $t6, $t6, 0x77B0
    ctx->r14 = ADD32(ctx->r14, 0X77B0);
    // 0x800033E0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800033E4: addiu       $t2, $t6, 0x27C
    ctx->r10 = ADD32(ctx->r14, 0X27C);
    // 0x800033E8: or          $t9, $t1, $zero
    ctx->r25 = ctx->r9 | 0;
L_800033EC:
    // 0x800033EC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800033F0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800033F4: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800033F8: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x800033FC: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80003400: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80003404: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80003408: bne         $t6, $t2, L_800033EC
    if (ctx->r14 != ctx->r10) {
        // 0x8000340C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_800033EC;
    }
    // 0x8000340C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80003410: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80003414: sll         $t3, $a0, 5
    ctx->r11 = S32(ctx->r4 << 5);
    // 0x80003418: sll         $t4, $a0, 5
    ctx->r12 = S32(ctx->r4 << 5);
    // 0x8000341C: addu        $a2, $a1, $t4
    ctx->r6 = ADD32(ctx->r5, ctx->r12);
    // 0x80003420: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x80003424: addu        $v1, $a1, $t3
    ctx->r3 = ADD32(ctx->r5, ctx->r11);
    // 0x80003428: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8000342C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003430: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_80003434:
    // 0x80003434: lbu         $t2, 0xE($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0XE);
    // 0x80003438: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000343C: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80003440: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x80003444: addu        $t9, $t1, $t6
    ctx->r25 = ADD32(ctx->r9, ctx->r14);
    // 0x80003448: lhu         $t7, 0x0($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X0);
    // 0x8000344C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80003450: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80003454: sb          $t7, 0x200($v1)
    MEM_B(0X200, ctx->r3) = ctx->r15;
    // 0x80003458: lbu         $t3, 0xD($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0XD);
    // 0x8000345C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80003460: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80003464: lhu         $t2, 0x2($t5)
    ctx->r10 = MEM_HU(ctx->r13, 0X2);
    // 0x80003468: bne         $at, $zero, L_80003434
    if (ctx->r1 != 0) {
        // 0x8000346C: sb          $t2, 0x201($v1)
        MEM_B(0X201, ctx->r3) = ctx->r10;
            goto L_80003434;
    }
    // 0x8000346C: sb          $t2, 0x201($v1)
    MEM_B(0X201, ctx->r3) = ctx->r10;
    // 0x80003470: sb          $zero, 0x202($v1)
    MEM_B(0X202, ctx->r3) = 0;
    // 0x80003474: lbu         $t7, 0xA($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0XA);
    // 0x80003478: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8000347C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80003480: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80003484: addu        $t3, $t1, $t8
    ctx->r11 = ADD32(ctx->r9, ctx->r24);
    // 0x80003488: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8000348C: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x80003490: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80003494: sb          $t4, 0x412($v1)
    MEM_B(0X412, ctx->r3) = ctx->r12;
    // 0x80003498: lbu         $t2, 0xA($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0XA);
    // 0x8000349C: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x800034A0: addu        $t9, $t1, $t6
    ctx->r25 = ADD32(ctx->r9, ctx->r14);
    // 0x800034A4: lhu         $t7, 0x2($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X2);
    // 0x800034A8: sb          $t7, 0x413($v1)
    MEM_B(0X413, ctx->r3) = ctx->r15;
    // 0x800034AC: lbu         $t3, 0xB($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0XB);
    // 0x800034B0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800034B4: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x800034B8: lhu         $t2, 0x0($t5)
    ctx->r10 = MEM_HU(ctx->r13, 0X0);
    // 0x800034BC: sb          $t2, 0x414($v1)
    MEM_B(0X414, ctx->r3) = ctx->r10;
    // 0x800034C0: lbu         $t9, 0xB($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XB);
    // 0x800034C4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800034C8: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x800034CC: lhu         $t3, 0x2($t8)
    ctx->r11 = MEM_HU(ctx->r24, 0X2);
    // 0x800034D0: sb          $t3, 0x415($v1)
    MEM_B(0X415, ctx->r3) = ctx->r11;
    // 0x800034D4: lbu         $t5, 0xC($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0XC);
    // 0x800034D8: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x800034DC: addu        $t6, $t1, $t2
    ctx->r14 = ADD32(ctx->r9, ctx->r10);
    // 0x800034E0: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x800034E4: sb          $t9, 0x416($v1)
    MEM_B(0X416, ctx->r3) = ctx->r25;
    // 0x800034E8: lbu         $t8, 0xC($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XC);
    // 0x800034EC: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x800034F0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800034F4: lhu         $t5, 0x2($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X2);
    // 0x800034F8: sb          $t5, 0x417($v1)
    MEM_B(0X417, ctx->r3) = ctx->r13;
    // 0x800034FC: lbu         $t6, 0xD($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XD);
    // 0x80003500: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80003504: addu        $t7, $t1, $t9
    ctx->r15 = ADD32(ctx->r9, ctx->r25);
    // 0x80003508: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000350C: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x80003510: addu        $t7, $v1, $t9
    ctx->r15 = ADD32(ctx->r3, ctx->r25);
    // 0x80003514: sb          $t8, 0x418($v1)
    MEM_B(0X418, ctx->r3) = ctx->r24;
    // 0x80003518: lbu         $t4, 0xD($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0XD);
    // 0x8000351C: sll         $t8, $a0, 5
    ctx->r24 = S32(ctx->r4 << 5);
    // 0x80003520: addu        $t3, $a1, $t8
    ctx->r11 = ADD32(ctx->r5, ctx->r24);
    // 0x80003524: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80003528: addu        $t2, $t1, $t5
    ctx->r10 = ADD32(ctx->r9, ctx->r13);
    // 0x8000352C: lhu         $t6, 0x2($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X2);
    // 0x80003530: addu        $t2, $a1, $a0
    ctx->r10 = ADD32(ctx->r5, ctx->r4);
    // 0x80003534: sb          $t6, 0x419($v1)
    MEM_B(0X419, ctx->r3) = ctx->r14;
    // 0x80003538: sb          $zero, 0x412($t7)
    MEM_B(0X412, ctx->r15) = 0;
    // 0x8000353C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80003540: addiu       $sp, $sp, 0x290
    ctx->r29 = ADD32(ctx->r29, 0X290);
    // 0x80003544: srl         $t5, $t4, 8
    ctx->r13 = S32(U32(ctx->r12) >> 8);
    // 0x80003548: jr          $ra
    // 0x8000354C: sb          $t5, 0x4A2($t2)
    MEM_B(0X4A2, ctx->r10) = ctx->r13;
    return;
    // 0x8000354C: sb          $t5, 0x4A2($t2)
    MEM_B(0X4A2, ctx->r10) = ctx->r13;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80003550(rdram, ctx);
;}
RECOMP_FUNC void FUN_80003550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003550: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80003554: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80003558: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x8000355C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80003560: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x80003564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003568: addiu       $a3, $zero, 0xA1
    ctx->r7 = ADD32(0, 0XA1);
L_8000356C:
    // 0x8000356C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80003570: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80003574: sb          $a3, 0x202($v1)
    MEM_B(0X202, ctx->r3) = ctx->r7;
    // 0x80003578: bne         $at, $zero, L_8000356C
    if (ctx->r1 != 0) {
        // 0x8000357C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000356C;
    }
    // 0x8000357C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80003580: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x80003584: sb          $zero, 0x202($v1)
    MEM_B(0X202, ctx->r3) = 0;
    // 0x80003588: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8000358C: addu        $a2, $a1, $t7
    ctx->r6 = ADD32(ctx->r5, ctx->r15);
    // 0x80003590: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x80003594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003598:
    // 0x80003598: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000359C: sb          $a3, 0x412($a2)
    MEM_B(0X412, ctx->r6) = ctx->r7;
    // 0x800035A0: sb          $a3, 0x413($a2)
    MEM_B(0X413, ctx->r6) = ctx->r7;
    // 0x800035A4: sb          $a3, 0x414($a2)
    MEM_B(0X414, ctx->r6) = ctx->r7;
    // 0x800035A8: sb          $a3, 0x415($a2)
    MEM_B(0X415, ctx->r6) = ctx->r7;
    // 0x800035AC: bne         $v0, $v1, L_80003598
    if (ctx->r2 != ctx->r3) {
        // 0x800035B0: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80003598;
    }
    // 0x800035B0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800035B4: sb          $zero, 0x412($a2)
    MEM_B(0X412, ctx->r6) = 0;
    // 0x800035B8: addu        $t8, $a1, $a0
    ctx->r24 = ADD32(ctx->r5, ctx->r4);
    // 0x800035BC: jr          $ra
    // 0x800035C0: sb          $zero, 0x4A2($t8)
    MEM_B(0X4A2, ctx->r24) = 0;
    return;
    // 0x800035C0: sb          $zero, 0x4A2($t8)
    MEM_B(0X4A2, ctx->r24) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800035c4(rdram, ctx);
;}
RECOMP_FUNC void FUN_800035c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800035C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800035C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800035CC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800035D0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800035D4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800035D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800035DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800035E0: jal         0x80002BE0
    // 0x800035E4: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    LOOKUP_FUNC(0x80002BE0)(rdram, ctx);
        goto after_0;
    // 0x800035E4: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    after_0:
    // 0x800035E8: beq         $v0, $zero, L_80003620
    if (ctx->r2 == 0) {
        // 0x800035EC: andi        $s2, $v0, 0xFF
        ctx->r18 = ctx->r2 & 0XFF;
            goto L_80003620;
    }
    // 0x800035EC: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x800035F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800035F4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_800035F8:
    // 0x800035F8: jal         0x80003550
    // 0x800035FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80003550)(rdram, ctx);
        goto after_1;
    // 0x800035FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80003600: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80003604: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80003608: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x8000360C: bnel        $at, $zero, L_800035F8
    if (ctx->r1 != 0) {
        // 0x80003610: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_800035F8;
    }
    goto skip_0;
    // 0x80003610: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    skip_0:
    // 0x80003614: sb          $zero, 0x201($s1)
    MEM_B(0X201, ctx->r17) = 0;
    // 0x80003618: b           L_800036AC
    // 0x8000361C: sb          $s2, 0x200($s1)
    MEM_B(0X200, ctx->r17) = ctx->r18;
        goto L_800036AC;
    // 0x8000361C: sb          $s2, 0x200($s1)
    MEM_B(0X200, ctx->r17) = ctx->r18;
L_80003620:
    // 0x80003620: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x80003624: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80003628: addiu       $t8, $t8, -0x3190
    ctx->r24 = ADD32(ctx->r24, -0X3190);
    // 0x8000362C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80003630: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80003634: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80003638: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8000363C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80003640: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x80003644: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80003648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8000364C:
    // 0x8000364C: sll         $t9, $s0, 5
    ctx->r25 = S32(ctx->r16 << 5);
    // 0x80003650: addu        $a2, $s1, $t9
    ctx->r6 = ADD32(ctx->r17, ctx->r25);
    // 0x80003654: jal         0x80032DD0
    // 0x80003658: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80032DD0)(rdram, ctx);
        goto after_2;
    // 0x80003658: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x8000365C: bne         $v0, $zero, L_80003678
    if (ctx->r2 != 0) {
        // 0x80003660: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80003678;
    }
    // 0x80003660: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80003664: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80003668: jal         0x800033CC
    // 0x8000366C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800033CC)(rdram, ctx);
        goto after_3;
    // 0x8000366C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80003670: b           L_80003684
    // 0x80003674: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80003684;
    // 0x80003674: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80003678:
    // 0x80003678: jal         0x80003550
    // 0x8000367C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80003550)(rdram, ctx);
        goto after_4;
    // 0x8000367C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80003680: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80003684:
    // 0x80003684: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80003688: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x8000368C: bne         $at, $zero, L_8000364C
    if (ctx->r1 != 0) {
        // 0x80003690: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8000364C;
    }
    // 0x80003690: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80003694: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x80003698: jal         0x80003118
    // 0x8000369C: addiu       $a1, $sp, 0x35
    ctx->r5 = ADD32(ctx->r29, 0X35);
    LOOKUP_FUNC(0x80003118)(rdram, ctx);
        goto after_5;
    // 0x8000369C: addiu       $a1, $sp, 0x35
    ctx->r5 = ADD32(ctx->r29, 0X35);
    after_5:
    // 0x800036A0: lbu         $t0, 0x35($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X35);
    // 0x800036A4: sb          $zero, 0x200($s1)
    MEM_B(0X200, ctx->r17) = 0;
    // 0x800036A8: sb          $t0, 0x201($s1)
    MEM_B(0X201, ctx->r17) = ctx->r8;
L_800036AC:
    // 0x800036AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800036B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800036B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800036B8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800036BC: jr          $ra
    // 0x800036C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800036C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800036C4: nop

    // 0x800036C8: nop

    // 0x800036CC: nop

    // 0x800036D0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800036D4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800036D8: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x800036DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800036E0: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800036E4: beq         $at, $zero, L_8000381C
    if (ctx->r1 == 0) {
        // 0x800036E8: nop
    
            goto L_8000381C;
    }
    // 0x800036E8: nop

    // 0x800036EC: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
L_800036F0:
    // 0x800036F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800036F4: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x800036F8: beq         $at, $zero, L_8000375C
    if (ctx->r1 == 0) {
        // 0x800036FC: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_8000375C;
    }
    // 0x800036FC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80003700: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80003704: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    // 0x80003708: sra         $t0, $a1, 2
    ctx->r8 = S32(SIGNED(ctx->r5) >> 2);
    // 0x8000370C: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80003710: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80003714: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x80003718: andi        $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 & 0XFFFF;
    // 0x8000371C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80003720: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80003724: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80003728: subu        $a2, $a3, $v1
    ctx->r6 = SUB32(ctx->r7, ctx->r3);
    // 0x8000372C: beq         $t0, $zero, L_80003810
    if (ctx->r8 == 0) {
        // 0x80003730: andi        $t1, $t1, 0xFFFF
        ctx->r9 = ctx->r9 & 0XFFFF;
            goto L_80003810;
    }
    // 0x80003730: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
L_80003734:
    // 0x80003734: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x80003738: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8000373C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80003740: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
    // 0x80003744: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80003748: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000374C: bne         $v1, $zero, L_80003734
    if (ctx->r3 != 0) {
        // 0x80003750: sb          $t9, -0x1($a3)
        MEM_B(-0X1, ctx->r7) = ctx->r25;
            goto L_80003734;
    }
    // 0x80003750: sb          $t9, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r25;
    // 0x80003754: b           L_80003814
    // 0x80003758: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
        goto L_80003814;
    // 0x80003758: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
L_8000375C:
    // 0x8000375C: slti        $at, $a1, 0xA0
    ctx->r1 = SIGNED(ctx->r5) < 0XA0 ? 1 : 0;
    // 0x80003760: beq         $at, $zero, L_8000379C
    if (ctx->r1 == 0) {
        // 0x80003764: andi        $v1, $a1, 0x1F
        ctx->r3 = ctx->r5 & 0X1F;
            goto L_8000379C;
    }
    // 0x80003764: andi        $v1, $a1, 0x1F
    ctx->r3 = ctx->r5 & 0X1F;
    // 0x80003768: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x8000376C: beq         $v1, $zero, L_80003810
    if (ctx->r3 == 0) {
        // 0x80003770: andi        $t1, $t1, 0xFFFF
        ctx->r9 = ctx->r9 & 0XFFFF;
            goto L_80003810;
    }
    // 0x80003770: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
L_80003774:
    // 0x80003774: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
    // 0x80003778: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8000377C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80003780: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
    // 0x80003784: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80003788: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000378C: bne         $v1, $zero, L_80003774
    if (ctx->r3 != 0) {
        // 0x80003790: sb          $t2, -0x1($a3)
        MEM_B(-0X1, ctx->r7) = ctx->r10;
            goto L_80003774;
    }
    // 0x80003790: sb          $t2, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r10;
    // 0x80003794: b           L_80003814
    // 0x80003798: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
        goto L_80003814;
    // 0x80003798: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
L_8000379C:
    // 0x8000379C: slti        $at, $a1, 0xE0
    ctx->r1 = SIGNED(ctx->r5) < 0XE0 ? 1 : 0;
    // 0x800037A0: beq         $at, $zero, L_800037BC
    if (ctx->r1 == 0) {
        // 0x800037A4: andi        $t1, $a1, 0x1F
        ctx->r9 = ctx->r5 & 0X1F;
            goto L_800037BC;
    }
    // 0x800037A4: andi        $t1, $a1, 0x1F
    ctx->r9 = ctx->r5 & 0X1F;
    // 0x800037A8: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x800037AC: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
    // 0x800037B0: lbu         $a2, 0x0($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X0);
    // 0x800037B4: b           L_800037E8
    // 0x800037B8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_800037E8;
    // 0x800037B8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800037BC:
    // 0x800037BC: slti        $at, $a1, 0xFF
    ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
    // 0x800037C0: beq         $at, $zero, L_800037D8
    if (ctx->r1 == 0) {
        // 0x800037C4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800037D8;
    }
    // 0x800037C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800037C8: andi        $t1, $a1, 0x1F
    ctx->r9 = ctx->r5 & 0X1F;
    // 0x800037CC: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x800037D0: b           L_800037E8
    // 0x800037D4: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
        goto L_800037E8;
    // 0x800037D4: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
L_800037D8:
    // 0x800037D8: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    // 0x800037DC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800037E0: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x800037E4: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
L_800037E8:
    // 0x800037E8: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800037EC: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800037F0: beq         $v1, $zero, L_80003810
    if (ctx->r3 == 0) {
        // 0x800037F4: andi        $t1, $t1, 0xFFFF
        ctx->r9 = ctx->r9 & 0XFFFF;
            goto L_80003810;
    }
    // 0x800037F4: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
L_800037F8:
    // 0x800037F8: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800037FC: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80003800: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
    // 0x80003804: sb          $a2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r6;
    // 0x80003808: bne         $v1, $zero, L_800037F8
    if (ctx->r3 != 0) {
        // 0x8000380C: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800037F8;
    }
    // 0x8000380C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_80003810:
    // 0x80003810: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
L_80003814:
    // 0x80003814: bnel        $at, $zero, L_800036F0
    if (ctx->r1 != 0) {
        // 0x80003818: lbu         $v1, 0x0($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X0);
            goto L_800036F0;
    }
    goto skip_1;
    // 0x80003818: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_8000381C:
    // 0x8000381C: jr          $ra
    // 0x80003820: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x80003820: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80003824(rdram, ctx);
;}
RECOMP_FUNC void FUN_80003824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003824: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80003828: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000382C: lui         $fp, 0x8006
    ctx->r30 = S32(0X8006 << 16);
    // 0x80003830: addiu       $fp, $fp, -0x2FEC
    ctx->r30 = ADD32(ctx->r30, -0X2FEC);
    // 0x80003834: sw          $a0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r4;
    // 0x80003838: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x8000383C: lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // 0x80003840: sw          $a0, -0x2FF0($at)
    MEM_W(-0X2FF0, ctx->r1) = ctx->r4;
    // 0x80003844: addiu       $v1, $v1, -0x2FE4
    ctx->r3 = ADD32(ctx->r3, -0X2FE4);
    // 0x80003848: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000384C: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80003850: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x80003854: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80003858: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000385C: sw          $a2, -0x2FE8($at)
    MEM_W(-0X2FE8, ctx->r1) = ctx->r6;
    // 0x80003860: addiu       $t7, $a2, -0x1
    ctx->r15 = ADD32(ctx->r6, -0X1);
    // 0x80003864: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80003868: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000386C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80003870: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80003874: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80003878: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000387C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80003880: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80003884: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80003888: jal         0x80003DB4
    // 0x8000388C: addiu       $s2, $s2, -0x6AE8
    ctx->r18 = ADD32(ctx->r18, -0X6AE8);
    LOOKUP_FUNC(0x80003DB4)(rdram, ctx);
        goto after_0;
    // 0x8000388C: addiu       $s2, $s2, -0x6AE8
    ctx->r18 = ADD32(ctx->r18, -0X6AE8);
    after_0:
    // 0x80003890: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80003894: lw          $t8, -0x2FE4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2FE4);
    // 0x80003898: lui         $s5, 0x8006
    ctx->r21 = S32(0X8006 << 16);
    // 0x8000389C: addiu       $s5, $s5, -0x2FDA
    ctx->r21 = ADD32(ctx->r21, -0X2FDA);
    // 0x800038A0: blezl       $t8, L_80003D0C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800038A4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80003D0C;
    }
    goto skip_0;
    // 0x800038A4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x800038A8: lbu         $s6, 0x0($s2)
    ctx->r22 = MEM_BU(ctx->r18, 0X0);
L_800038AC:
    // 0x800038AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800038B0: jal         0x80003D3C
    // 0x800038B4: sll         $s6, $s6, 24
    ctx->r22 = S32(ctx->r22 << 24);
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_1;
    // 0x800038B4: sll         $s6, $s6, 24
    ctx->r22 = S32(ctx->r22 << 24);
    after_1:
    // 0x800038B8: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800038BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800038C0: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x800038C4: jal         0x80003D3C
    // 0x800038C8: addu        $s6, $s6, $t0
    ctx->r22 = ADD32(ctx->r22, ctx->r8);
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_2;
    // 0x800038C8: addu        $s6, $s6, $t0
    ctx->r22 = ADD32(ctx->r22, ctx->r8);
    after_2:
    // 0x800038CC: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x800038D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800038D4: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800038D8: jal         0x80003D3C
    // 0x800038DC: addu        $s6, $s6, $t2
    ctx->r22 = ADD32(ctx->r22, ctx->r10);
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_3;
    // 0x800038DC: addu        $s6, $s6, $t2
    ctx->r22 = ADD32(ctx->r22, ctx->r10);
    after_3:
    // 0x800038E0: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x800038E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800038E8: jal         0x80003D3C
    // 0x800038EC: addu        $s6, $s6, $t3
    ctx->r22 = ADD32(ctx->r22, ctx->r11);
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_4;
    // 0x800038EC: addu        $s6, $s6, $t3
    ctx->r22 = ADD32(ctx->r22, ctx->r11);
    after_4:
    // 0x800038F0: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x800038F4: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x800038F8: and         $a0, $s6, $at
    ctx->r4 = ctx->r22 & ctx->r1;
    // 0x800038FC: addu        $s7, $v1, $s6
    ctx->r23 = ADD32(ctx->r3, ctx->r22);
    // 0x80003900: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80003904: bne         $a0, $zero, L_80003A7C
    if (ctx->r4 != 0) {
        // 0x80003908: addiu       $s7, $s7, -0x4
        ctx->r23 = ADD32(ctx->r23, -0X4);
            goto L_80003A7C;
    }
    // 0x80003908: addiu       $s7, $s7, -0x4
    ctx->r23 = ADD32(ctx->r23, -0X4);
    // 0x8000390C: sltu        $at, $v1, $s7
    ctx->r1 = ctx->r3 < ctx->r23 ? 1 : 0;
    // 0x80003910: beq         $at, $zero, L_80003A74
    if (ctx->r1 == 0) {
        // 0x80003914: nop
    
            goto L_80003A74;
    }
    // 0x80003914: nop

    // 0x80003918: lbu         $s0, 0x0($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X0);
L_8000391C:
    // 0x8000391C: jal         0x80003D3C
    // 0x80003920: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_5;
    // 0x80003920: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80003924: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x80003928: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8000392C: beq         $at, $zero, L_80003998
    if (ctx->r1 == 0) {
        // 0x80003930: or          $s4, $s0, $zero
        ctx->r20 = ctx->r16 | 0;
            goto L_80003998;
    }
    // 0x80003930: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x80003934: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x80003938: sll         $t5, $s0, 8
    ctx->r13 = S32(ctx->r16 << 8);
    // 0x8000393C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80003940: addu        $s3, $t4, $t5
    ctx->r19 = ADD32(ctx->r12, ctx->r13);
    // 0x80003944: andi        $s3, $s3, 0x3FF
    ctx->r19 = ctx->r19 & 0X3FF;
    // 0x80003948: jal         0x80003D3C
    // 0x8000394C: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_6;
    // 0x8000394C: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    after_6:
    // 0x80003950: sra         $a1, $s4, 2
    ctx->r5 = S32(SIGNED(ctx->r20) >> 2);
    // 0x80003954: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80003958: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8000395C: addiu       $s0, $a1, -0x1
    ctx->r16 = ADD32(ctx->r5, -0X1);
    // 0x80003960: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80003964: subu        $a0, $s1, $s3
    ctx->r4 = SUB32(ctx->r17, ctx->r19);
    // 0x80003968: beq         $a1, $zero, L_80003A64
    if (ctx->r5 == 0) {
        // 0x8000396C: andi        $s0, $s0, 0xFFFF
        ctx->r16 = ctx->r16 & 0XFFFF;
            goto L_80003A64;
    }
    // 0x8000396C: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
L_80003970:
    // 0x80003970: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80003974: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80003978: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8000397C: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80003980: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80003984: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80003988: bne         $v1, $zero, L_80003970
    if (ctx->r3 != 0) {
        // 0x8000398C: sb          $t6, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r14;
            goto L_80003970;
    }
    // 0x8000398C: sb          $t6, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r14;
    // 0x80003990: b           L_80003A68
    // 0x80003994: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
        goto L_80003A68;
    // 0x80003994: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
L_80003998:
    // 0x80003998: slti        $at, $s4, 0xA0
    ctx->r1 = SIGNED(ctx->r20) < 0XA0 ? 1 : 0;
    // 0x8000399C: beq         $at, $zero, L_800039E0
    if (ctx->r1 == 0) {
        // 0x800039A0: andi        $v0, $s4, 0x1F
        ctx->r2 = ctx->r20 & 0X1F;
            goto L_800039E0;
    }
    // 0x800039A0: andi        $v0, $s4, 0x1F
    ctx->r2 = ctx->r20 & 0X1F;
    // 0x800039A4: addiu       $s0, $v0, -0x1
    ctx->r16 = ADD32(ctx->r2, -0X1);
    // 0x800039A8: beq         $v0, $zero, L_80003A64
    if (ctx->r2 == 0) {
        // 0x800039AC: andi        $s0, $s0, 0xFFFF
        ctx->r16 = ctx->r16 & 0XFFFF;
            goto L_80003A64;
    }
    // 0x800039AC: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
L_800039B0:
    // 0x800039B0: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
    // 0x800039B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800039B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800039BC: jal         0x80003D3C
    // 0x800039C0: sb          $t7, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r15;
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_7;
    // 0x800039C0: sb          $t7, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r15;
    after_7:
    // 0x800039C4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800039C8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800039CC: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x800039D0: bne         $v1, $zero, L_800039B0
    if (ctx->r3 != 0) {
        // 0x800039D4: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800039B0;
    }
    // 0x800039D4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800039D8: b           L_80003A68
    // 0x800039DC: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
        goto L_80003A68;
    // 0x800039DC: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
L_800039E0:
    // 0x800039E0: slti        $at, $s4, 0xE0
    ctx->r1 = SIGNED(ctx->r20) < 0XE0 ? 1 : 0;
    // 0x800039E4: beq         $at, $zero, L_80003A08
    if (ctx->r1 == 0) {
        // 0x800039E8: andi        $s0, $s4, 0x1F
        ctx->r16 = ctx->r20 & 0X1F;
            goto L_80003A08;
    }
    // 0x800039E8: andi        $s0, $s4, 0x1F
    ctx->r16 = ctx->r20 & 0X1F;
    // 0x800039EC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800039F0: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x800039F4: lbu         $s3, 0x0($s2)
    ctx->r19 = MEM_BU(ctx->r18, 0X0);
    // 0x800039F8: jal         0x80003D3C
    // 0x800039FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_8;
    // 0x800039FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x80003A00: b           L_80003A3C
    // 0x80003A04: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_80003A3C;
    // 0x80003A04: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80003A08:
    // 0x80003A08: slti        $at, $s4, 0xFF
    ctx->r1 = SIGNED(ctx->r20) < 0XFF ? 1 : 0;
    // 0x80003A0C: beq         $at, $zero, L_80003A24
    if (ctx->r1 == 0) {
        // 0x80003A10: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80003A24;
    }
    // 0x80003A10: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80003A14: andi        $s0, $s4, 0x1F
    ctx->r16 = ctx->r20 & 0X1F;
    // 0x80003A18: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80003A1C: b           L_80003A3C
    // 0x80003A20: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
        goto L_80003A3C;
    // 0x80003A20: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
L_80003A24:
    // 0x80003A24: lbu         $s0, 0x0($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X0);
    // 0x80003A28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80003A2C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80003A30: jal         0x80003D3C
    // 0x80003A34: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_9;
    // 0x80003A34: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    after_9:
    // 0x80003A38: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80003A3C:
    // 0x80003A3C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80003A40: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80003A44: beq         $v1, $zero, L_80003A64
    if (ctx->r3 == 0) {
        // 0x80003A48: andi        $s0, $s0, 0xFFFF
        ctx->r16 = ctx->r16 & 0XFFFF;
            goto L_80003A64;
    }
    // 0x80003A48: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
L_80003A4C:
    // 0x80003A4C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80003A50: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80003A54: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80003A58: sb          $s3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r19;
    // 0x80003A5C: bne         $v1, $zero, L_80003A4C
    if (ctx->r3 != 0) {
        // 0x80003A60: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80003A4C;
    }
    // 0x80003A60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80003A64:
    // 0x80003A64: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
L_80003A68:
    // 0x80003A68: sltu        $at, $t8, $s7
    ctx->r1 = ctx->r24 < ctx->r23 ? 1 : 0;
    // 0x80003A6C: bnel        $at, $zero, L_8000391C
    if (ctx->r1 != 0) {
        // 0x80003A70: lbu         $s0, 0x0($s2)
        ctx->r16 = MEM_BU(ctx->r18, 0X0);
            goto L_8000391C;
    }
    goto skip_1;
    // 0x80003A70: lbu         $s0, 0x0($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X0);
    skip_1:
L_80003A74:
    // 0x80003A74: b           L_80003CD8
    // 0x80003A78: andi        $v1, $s7, 0xF
    ctx->r3 = ctx->r23 & 0XF;
        goto L_80003CD8;
    // 0x80003A78: andi        $v1, $s7, 0xF
    ctx->r3 = ctx->r23 & 0XF;
L_80003A7C:
    // 0x80003A7C: srl         $t0, $a0, 28
    ctx->r8 = S32(U32(ctx->r4) >> 28);
    // 0x80003A80: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80003A84: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x80003A88: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80003A8C: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
    // 0x80003A90: addiu       $a1, $a1, -0x2FDC
    ctx->r5 = ADD32(ctx->r5, -0X2FDC);
    // 0x80003A94: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80003A98: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x80003A9C: sh          $t1, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r9;
    // 0x80003AA0: beq         $at, $zero, L_80003CD4
    if (ctx->r1 == 0) {
        // 0x80003AA4: sw          $s1, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r17;
            goto L_80003CD4;
    }
    // 0x80003AA4: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
L_80003AA8:
    // 0x80003AA8: beql        $v0, $zero, L_80003B18
    if (ctx->r2 == 0) {
        // 0x80003AAC: lui         $at, 0xFFF
        ctx->r1 = S32(0XFFF << 16);
            goto L_80003B18;
    }
    goto skip_2;
    // 0x80003AAC: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    skip_2:
    // 0x80003AB0: lbu         $s6, 0x0($s2)
    ctx->r22 = MEM_BU(ctx->r18, 0X0);
    // 0x80003AB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80003AB8: jal         0x80003D3C
    // 0x80003ABC: sll         $s6, $s6, 24
    ctx->r22 = S32(ctx->r22 << 24);
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_10;
    // 0x80003ABC: sll         $s6, $s6, 24
    ctx->r22 = S32(ctx->r22 << 24);
    after_10:
    // 0x80003AC0: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80003AC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80003AC8: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80003ACC: jal         0x80003D3C
    // 0x80003AD0: addu        $s6, $s6, $t4
    ctx->r22 = ADD32(ctx->r22, ctx->r12);
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_11;
    // 0x80003AD0: addu        $s6, $s6, $t4
    ctx->r22 = ADD32(ctx->r22, ctx->r12);
    after_11:
    // 0x80003AD4: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80003AD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80003ADC: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x80003AE0: jal         0x80003D3C
    // 0x80003AE4: addu        $s6, $s6, $t6
    ctx->r22 = ADD32(ctx->r22, ctx->r14);
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_12;
    // 0x80003AE4: addu        $s6, $s6, $t6
    ctx->r22 = ADD32(ctx->r22, ctx->r14);
    after_12:
    // 0x80003AE8: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80003AEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80003AF0: jal         0x80003D3C
    // 0x80003AF4: addu        $s6, $s6, $t7
    ctx->r22 = ADD32(ctx->r22, ctx->r15);
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_13;
    // 0x80003AF4: addu        $s6, $s6, $t7
    ctx->r22 = ADD32(ctx->r22, ctx->r15);
    after_13:
    // 0x80003AF8: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x80003AFC: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x80003B00: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80003B04: addu        $s7, $v1, $s6
    ctx->r23 = ADD32(ctx->r3, ctx->r22);
    // 0x80003B08: addiu       $s7, $s7, -0x4
    ctx->r23 = ADD32(ctx->r23, -0X4);
    // 0x80003B0C: addiu       $a1, $a1, -0x2FDC
    ctx->r5 = ADD32(ctx->r5, -0X2FDC);
    // 0x80003B10: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80003B14: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
L_80003B18:
    // 0x80003B18: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80003B1C: and         $s6, $s6, $at
    ctx->r22 = ctx->r22 & ctx->r1;
    // 0x80003B20: sltu        $at, $v1, $s7
    ctx->r1 = ctx->r3 < ctx->r23 ? 1 : 0;
    // 0x80003B24: beql        $at, $zero, L_80003CB0
    if (ctx->r1 == 0) {
        // 0x80003B28: lhu         $t8, 0x0($a1)
        ctx->r24 = MEM_HU(ctx->r5, 0X0);
            goto L_80003CB0;
    }
    goto skip_3;
    // 0x80003B28: lhu         $t8, 0x0($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X0);
    skip_3:
    // 0x80003B2C: lbu         $s0, 0x0($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X0);
L_80003B30:
    // 0x80003B30: jal         0x80003D3C
    // 0x80003B34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_14;
    // 0x80003B34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x80003B38: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x80003B3C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80003B40: beq         $at, $zero, L_80003BC0
    if (ctx->r1 == 0) {
        // 0x80003B44: or          $s4, $s0, $zero
        ctx->r20 = ctx->r16 | 0;
            goto L_80003BC0;
    }
    // 0x80003B44: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x80003B48: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80003B4C: sll         $t9, $s0, 8
    ctx->r25 = S32(ctx->r16 << 8);
    // 0x80003B50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80003B54: addu        $s3, $t8, $t9
    ctx->r19 = ADD32(ctx->r24, ctx->r25);
    // 0x80003B58: andi        $s3, $s3, 0x3FF
    ctx->r19 = ctx->r19 & 0X3FF;
    // 0x80003B5C: jal         0x80003D3C
    // 0x80003B60: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_15;
    // 0x80003B60: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    after_15:
    // 0x80003B64: lhu         $t0, 0x0($s5)
    ctx->r8 = MEM_HU(ctx->r21, 0X0);
    // 0x80003B68: sra         $a1, $s4, 2
    ctx->r5 = S32(SIGNED(ctx->r20) >> 2);
    // 0x80003B6C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80003B70: multu       $s3, $t0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003B74: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80003B78: addiu       $s0, $a1, -0x1
    ctx->r16 = ADD32(ctx->r5, -0X1);
    // 0x80003B7C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80003B80: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80003B84: mflo        $t1
    ctx->r9 = lo;
    // 0x80003B88: subu        $a0, $s1, $t1
    ctx->r4 = SUB32(ctx->r17, ctx->r9);
    // 0x80003B8C: beql        $a1, $zero, L_80003C98
    if (ctx->r5 == 0) {
        // 0x80003B90: lw          $v1, 0x0($fp)
        ctx->r3 = MEM_W(ctx->r30, 0X0);
            goto L_80003C98;
    }
    goto skip_4;
    // 0x80003B90: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    skip_4:
L_80003B94:
    // 0x80003B94: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
    // 0x80003B98: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80003B9C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80003BA0: sb          $t2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r10;
    // 0x80003BA4: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003BA8: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80003BAC: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x80003BB0: bne         $v1, $zero, L_80003B94
    if (ctx->r3 != 0) {
        // 0x80003BB4: addu        $a0, $a0, $v0
        ctx->r4 = ADD32(ctx->r4, ctx->r2);
            goto L_80003B94;
    }
    // 0x80003BB4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80003BB8: b           L_80003C98
    // 0x80003BBC: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
        goto L_80003C98;
    // 0x80003BBC: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
L_80003BC0:
    // 0x80003BC0: slti        $at, $s4, 0xA0
    ctx->r1 = SIGNED(ctx->r20) < 0XA0 ? 1 : 0;
    // 0x80003BC4: beq         $at, $zero, L_80003C0C
    if (ctx->r1 == 0) {
        // 0x80003BC8: andi        $v0, $s4, 0x1F
        ctx->r2 = ctx->r20 & 0X1F;
            goto L_80003C0C;
    }
    // 0x80003BC8: andi        $v0, $s4, 0x1F
    ctx->r2 = ctx->r20 & 0X1F;
    // 0x80003BCC: addiu       $s0, $v0, -0x1
    ctx->r16 = ADD32(ctx->r2, -0X1);
    // 0x80003BD0: beq         $v0, $zero, L_80003C94
    if (ctx->r2 == 0) {
        // 0x80003BD4: andi        $s0, $s0, 0xFFFF
        ctx->r16 = ctx->r16 & 0XFFFF;
            goto L_80003C94;
    }
    // 0x80003BD4: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
L_80003BD8:
    // 0x80003BD8: lbu         $t3, 0x0($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X0);
    // 0x80003BDC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80003BE0: sb          $t3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r11;
    // 0x80003BE4: lhu         $t4, 0x0($s5)
    ctx->r12 = MEM_HU(ctx->r21, 0X0);
    // 0x80003BE8: jal         0x80003D3C
    // 0x80003BEC: addu        $s1, $s1, $t4
    ctx->r17 = ADD32(ctx->r17, ctx->r12);
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_16;
    // 0x80003BEC: addu        $s1, $s1, $t4
    ctx->r17 = ADD32(ctx->r17, ctx->r12);
    after_16:
    // 0x80003BF0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80003BF4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80003BF8: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80003BFC: bne         $v1, $zero, L_80003BD8
    if (ctx->r3 != 0) {
        // 0x80003C00: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80003BD8;
    }
    // 0x80003C00: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80003C04: b           L_80003C98
    // 0x80003C08: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
        goto L_80003C98;
    // 0x80003C08: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
L_80003C0C:
    // 0x80003C0C: slti        $at, $s4, 0xE0
    ctx->r1 = SIGNED(ctx->r20) < 0XE0 ? 1 : 0;
    // 0x80003C10: beq         $at, $zero, L_80003C34
    if (ctx->r1 == 0) {
        // 0x80003C14: andi        $s0, $s4, 0x1F
        ctx->r16 = ctx->r20 & 0X1F;
            goto L_80003C34;
    }
    // 0x80003C14: andi        $s0, $s4, 0x1F
    ctx->r16 = ctx->r20 & 0X1F;
    // 0x80003C18: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80003C1C: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80003C20: lbu         $s3, 0x0($s2)
    ctx->r19 = MEM_BU(ctx->r18, 0X0);
    // 0x80003C24: jal         0x80003D3C
    // 0x80003C28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_17;
    // 0x80003C28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x80003C2C: b           L_80003C68
    // 0x80003C30: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_80003C68;
    // 0x80003C30: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80003C34:
    // 0x80003C34: slti        $at, $s4, 0xFF
    ctx->r1 = SIGNED(ctx->r20) < 0XFF ? 1 : 0;
    // 0x80003C38: beq         $at, $zero, L_80003C50
    if (ctx->r1 == 0) {
        // 0x80003C3C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80003C50;
    }
    // 0x80003C3C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80003C40: andi        $s0, $s4, 0x1F
    ctx->r16 = ctx->r20 & 0X1F;
    // 0x80003C44: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80003C48: b           L_80003C68
    // 0x80003C4C: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
        goto L_80003C68;
    // 0x80003C4C: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
L_80003C50:
    // 0x80003C50: lbu         $s0, 0x0($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X0);
    // 0x80003C54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80003C58: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80003C5C: jal         0x80003D3C
    // 0x80003C60: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_18;
    // 0x80003C60: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    after_18:
    // 0x80003C64: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80003C68:
    // 0x80003C68: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80003C6C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80003C70: beq         $v1, $zero, L_80003C94
    if (ctx->r3 == 0) {
        // 0x80003C74: andi        $s0, $s0, 0xFFFF
        ctx->r16 = ctx->r16 & 0XFFFF;
            goto L_80003C94;
    }
    // 0x80003C74: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
L_80003C78:
    // 0x80003C78: sb          $s3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r19;
    // 0x80003C7C: lhu         $t5, 0x0($s5)
    ctx->r13 = MEM_HU(ctx->r21, 0X0);
    // 0x80003C80: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80003C84: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80003C88: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80003C8C: bne         $v1, $zero, L_80003C78
    if (ctx->r3 != 0) {
        // 0x80003C90: addu        $s1, $s1, $t5
        ctx->r17 = ADD32(ctx->r17, ctx->r13);
            goto L_80003C78;
    }
    // 0x80003C90: addu        $s1, $s1, $t5
    ctx->r17 = ADD32(ctx->r17, ctx->r13);
L_80003C94:
    // 0x80003C94: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
L_80003C98:
    // 0x80003C98: sltu        $at, $v1, $s7
    ctx->r1 = ctx->r3 < ctx->r23 ? 1 : 0;
    // 0x80003C9C: bnel        $at, $zero, L_80003B30
    if (ctx->r1 != 0) {
        // 0x80003CA0: lbu         $s0, 0x0($s2)
        ctx->r16 = MEM_BU(ctx->r18, 0X0);
            goto L_80003B30;
    }
    goto skip_5;
    // 0x80003CA0: lbu         $s0, 0x0($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X0);
    skip_5:
    // 0x80003CA4: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x80003CA8: addiu       $a1, $a1, -0x2FDC
    ctx->r5 = ADD32(ctx->r5, -0X2FDC);
    // 0x80003CAC: lhu         $t8, 0x0($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X0);
L_80003CB0:
    // 0x80003CB0: lhu         $t0, 0x0($s5)
    ctx->r8 = MEM_HU(ctx->r21, 0X0);
    // 0x80003CB4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80003CB8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80003CBC: andi        $v0, $t9, 0xFFFF
    ctx->r2 = ctx->r25 & 0XFFFF;
    // 0x80003CC0: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80003CC4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80003CC8: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80003CCC: bne         $at, $zero, L_80003AA8
    if (ctx->r1 != 0) {
        // 0x80003CD0: sh          $t9, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r25;
            goto L_80003AA8;
    }
    // 0x80003CD0: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
L_80003CD4:
    // 0x80003CD4: andi        $v1, $s7, 0xF
    ctx->r3 = ctx->r23 & 0XF;
L_80003CD8:
    // 0x80003CD8: beq         $v1, $zero, L_80003CF8
    if (ctx->r3 == 0) {
        // 0x80003CDC: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_80003CF8;
    }
    // 0x80003CDC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_80003CE0:
    // 0x80003CE0: jal         0x80003D3C
    // 0x80003CE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80003D3C)(rdram, ctx);
        goto after_19;
    // 0x80003CE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_19:
    // 0x80003CE8: andi        $v1, $s7, 0xF
    ctx->r3 = ctx->r23 & 0XF;
    // 0x80003CEC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80003CF0: bne         $v1, $zero, L_80003CE0
    if (ctx->r3 != 0) {
        // 0x80003CF4: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80003CE0;
    }
    // 0x80003CF4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80003CF8:
    // 0x80003CF8: lui         $t1, 0x8006
    ctx->r9 = S32(0X8006 << 16);
    // 0x80003CFC: lw          $t1, -0x2FE4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2FE4);
    // 0x80003D00: bgtzl       $t1, L_800038AC
    if (SIGNED(ctx->r9) > 0) {
        // 0x80003D04: lbu         $s6, 0x0($s2)
        ctx->r22 = MEM_BU(ctx->r18, 0X0);
            goto L_800038AC;
    }
    goto skip_6;
    // 0x80003D04: lbu         $s6, 0x0($s2)
    ctx->r22 = MEM_BU(ctx->r18, 0X0);
    skip_6:
    // 0x80003D08: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80003D0C:
    // 0x80003D0C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80003D10: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80003D14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80003D18: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80003D1C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80003D20: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80003D24: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80003D28: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80003D2C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80003D30: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80003D34: jr          $ra
    // 0x80003D38: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80003D38: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80003D3C(rdram, ctx);
;}
RECOMP_FUNC void FUN_80003D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003D3C: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x80003D40: lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // 0x80003D44: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x80003D48: addiu       $a1, $a1, -0x2FE4
    ctx->r5 = ADD32(ctx->r5, -0X2FE4);
    // 0x80003D4C: addiu       $v1, $v1, -0x2FEC
    ctx->r3 = ADD32(ctx->r3, -0X2FEC);
    // 0x80003D50: addiu       $v0, $v0, -0x2FE0
    ctx->r2 = ADD32(ctx->r2, -0X2FE0);
    // 0x80003D54: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80003D58: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80003D5C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80003D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003D64: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80003D68: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80003D6C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80003D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003D74: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80003D78: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80003D7C: beq         $t9, $zero, L_80003D8C
    if (ctx->r25 == 0) {
        // 0x80003D80: sw          $t1, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r9;
            goto L_80003D8C;
    }
    // 0x80003D80: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80003D84: b           L_80003DA0
    // 0x80003D88: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_80003DA0;
    // 0x80003D88: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80003D8C:
    // 0x80003D8C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80003D90: addiu       $a0, $a0, -0x6AE8
    ctx->r4 = ADD32(ctx->r4, -0X6AE8);
    // 0x80003D94: jal         0x80003DB4
    // 0x80003D98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80003DB4)(rdram, ctx);
        goto after_0;
    // 0x80003D98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80003D9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80003DA0:
    // 0x80003DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80003DA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80003DA8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003DAC: jr          $ra
    // 0x80003DB0: nop

    return;
    // 0x80003DB0: nop

;}
RECOMP_FUNC void FUN_80003db4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003DB4: lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // 0x80003DB8: addiu       $v1, $v1, -0x2FE8
    ctx->r3 = ADD32(ctx->r3, -0X2FE8);
    // 0x80003DBC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80003DC0: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80003DC4: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x80003DC8: addiu       $a0, $a0, -0x2FE0
    ctx->r4 = ADD32(ctx->r4, -0X2FE0);
    // 0x80003DCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003DD0: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80003DD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003DD8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80003DDC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80003DE0: bgez        $t8, L_80003E00
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80003DE4: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80003E00;
    }
    // 0x80003DE4: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80003DE8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80003DEC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80003DF0: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80003DF4: addu        $a2, $t6, $t0
    ctx->r6 = ADD32(ctx->r14, ctx->r8);
    // 0x80003DF8: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80003DFC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80003E00:
    // 0x80003E00: blez        $a2, L_80003E20
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80003E04: lui         $a0, 0x8006
        ctx->r4 = S32(0X8006 << 16);
            goto L_80003E20;
    }
    // 0x80003E04: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80003E08: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80003E0C: addiu       $a1, $a1, -0x6AE8
    ctx->r5 = ADD32(ctx->r5, -0X6AE8);
    // 0x80003E10: jal         0x80001FE8
    // 0x80003E14: lw          $a0, -0x2FF0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FF0);
    LOOKUP_FUNC(0x80001FE8)(rdram, ctx);
        goto after_0;
    // 0x80003E14: lw          $a0, -0x2FF0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FF0);
    after_0:
    // 0x80003E18: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80003E1C: lw          $a2, -0x2FE0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2FE0);
L_80003E20:
    // 0x80003E20: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x80003E24: lw          $t2, -0x2FF0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2FF0);
    // 0x80003E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80003E2C: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x80003E30: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x80003E34: sw          $t3, -0x2FF0($at)
    MEM_W(-0X2FF0, ctx->r1) = ctx->r11;
    // 0x80003E38: jr          $ra
    // 0x80003E3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80003E3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80003e40(rdram, ctx);
;}
RECOMP_FUNC void FUN_80003e40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003E40: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x80003E44: lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // 0x80003E48: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x80003E4C: addiu       $a1, $a1, -0x2FC4
    ctx->r5 = ADD32(ctx->r5, -0X2FC4);
    // 0x80003E50: addiu       $v1, $v1, -0x2FCC
    ctx->r3 = ADD32(ctx->r3, -0X2FCC);
    // 0x80003E54: addiu       $v0, $v0, -0x2FC0
    ctx->r2 = ADD32(ctx->r2, -0X2FC0);
    // 0x80003E58: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80003E5C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80003E60: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80003E64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003E68: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80003E6C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80003E70: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80003E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003E78: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80003E7C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80003E80: beq         $t9, $zero, L_80003E90
    if (ctx->r25 == 0) {
        // 0x80003E84: sw          $t1, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r9;
            goto L_80003E90;
    }
    // 0x80003E84: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80003E88: b           L_80003EA4
    // 0x80003E8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_80003EA4;
    // 0x80003E8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80003E90:
    // 0x80003E90: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80003E94: addiu       $a0, $a0, -0x4AE8
    ctx->r4 = ADD32(ctx->r4, -0X4AE8);
    // 0x80003E98: jal         0x80003EB8
    // 0x80003E9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80003EB8)(rdram, ctx);
        goto after_0;
    // 0x80003E9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80003EA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80003EA4:
    // 0x80003EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80003EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80003EAC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003EB0: jr          $ra
    // 0x80003EB4: nop

    return;
    // 0x80003EB4: nop

;}
RECOMP_FUNC void FUN_80003eb8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003EB8: lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // 0x80003EBC: addiu       $v1, $v1, -0x2FC8
    ctx->r3 = ADD32(ctx->r3, -0X2FC8);
    // 0x80003EC0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80003EC4: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80003EC8: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x80003ECC: addiu       $a0, $a0, -0x2FC0
    ctx->r4 = ADD32(ctx->r4, -0X2FC0);
    // 0x80003ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003ED4: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80003ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003EDC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80003EE0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80003EE4: bgez        $t8, L_80003F04
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80003EE8: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80003F04;
    }
    // 0x80003EE8: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80003EEC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80003EF0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80003EF4: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80003EF8: addu        $a2, $t6, $t0
    ctx->r6 = ADD32(ctx->r14, ctx->r8);
    // 0x80003EFC: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80003F00: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80003F04:
    // 0x80003F04: blez        $a2, L_80003F24
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80003F08: lui         $a0, 0x8006
        ctx->r4 = S32(0X8006 << 16);
            goto L_80003F24;
    }
    // 0x80003F08: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80003F0C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80003F10: addiu       $a1, $a1, -0x4AE8
    ctx->r5 = ADD32(ctx->r5, -0X4AE8);
    // 0x80003F14: jal         0x80001FE8
    // 0x80003F18: lw          $a0, -0x2FD0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FD0);
    LOOKUP_FUNC(0x80001FE8)(rdram, ctx);
        goto after_0;
    // 0x80003F18: lw          $a0, -0x2FD0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FD0);
    after_0:
    // 0x80003F1C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80003F20: lw          $a2, -0x2FC0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2FC0);
L_80003F24:
    // 0x80003F24: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x80003F28: lw          $t2, -0x2FD0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2FD0);
    // 0x80003F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80003F30: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x80003F34: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x80003F38: sw          $t3, -0x2FD0($at)
    MEM_W(-0X2FD0, ctx->r1) = ctx->r11;
    // 0x80003F3C: jr          $ra
    // 0x80003F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80003F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80003f44(rdram, ctx);
;}
RECOMP_FUNC void FUN_80003f44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003F44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80003F48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80003F4C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80003F50: addiu       $s0, $s0, -0x6D50
    ctx->r16 = ADD32(ctx->r16, -0X6D50);
    // 0x80003F54: lbu         $t6, 0x42EC($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X42EC);
    // 0x80003F58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80003F5C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80003F60: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80003F64: bne         $t6, $zero, L_80003FD4
    if (ctx->r14 != 0) {
        // 0x80003F68: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80003FD4;
    }
    // 0x80003F68: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80003F6C: lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // 0x80003F70: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80003F74: lui         $s2, 0x8006
    ctx->r18 = S32(0X8006 << 16);
    // 0x80003F78: addiu       $s2, $s2, -0x2FCC
    ctx->r18 = ADD32(ctx->r18, -0X2FCC);
    // 0x80003F7C: addiu       $a0, $a0, -0x2FC4
    ctx->r4 = ADD32(ctx->r4, -0X2FC4);
    // 0x80003F80: addiu       $v1, $v1, -0x2FD0
    ctx->r3 = ADD32(ctx->r3, -0X2FD0);
    // 0x80003F84: sw          $zero, 0x42D8($s0)
    MEM_W(0X42D8, ctx->r16) = 0;
    // 0x80003F88: sw          $zero, 0x42DC($s0)
    MEM_W(0X42DC, ctx->r16) = 0;
    // 0x80003F8C: sb          $zero, 0x42E0($s0)
    MEM_B(0X42E0, ctx->r16) = 0;
    // 0x80003F90: sb          $zero, 0x42E1($s0)
    MEM_B(0X42E1, ctx->r16) = 0;
    // 0x80003F94: sh          $zero, 0x42E2($s0)
    MEM_H(0X42E2, ctx->r16) = 0;
    // 0x80003F98: sh          $zero, 0x42E4($s0)
    MEM_H(0X42E4, ctx->r16) = 0;
    // 0x80003F9C: sw          $zero, 0x42E8($s0)
    MEM_W(0X42E8, ctx->r16) = 0;
    // 0x80003FA0: sw          $a1, 0x42F8($s0)
    MEM_W(0X42F8, ctx->r16) = ctx->r5;
    // 0x80003FA4: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80003FA8: sw          $a3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r7;
    // 0x80003FAC: sw          $a3, 0x42F0($s0)
    MEM_W(0X42F0, ctx->r16) = ctx->r7;
    // 0x80003FB0: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80003FB4: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x80003FB8: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80003FBC: sw          $a2, -0x2FC8($at)
    MEM_W(-0X2FC8, ctx->r1) = ctx->r6;
    // 0x80003FC0: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    // 0x80003FC4: addiu       $t0, $t0, -0x4AE8
    ctx->r8 = ADD32(ctx->r8, -0X4AE8);
    // 0x80003FC8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80003FCC: jal         0x80003EB8
    // 0x80003FD0: sw          $t0, 0x42D4($s0)
    MEM_W(0X42D4, ctx->r16) = ctx->r8;
    LOOKUP_FUNC(0x80003EB8)(rdram, ctx);
        goto after_0;
    // 0x80003FD0: sw          $t0, 0x42D4($s0)
    MEM_W(0X42D4, ctx->r16) = ctx->r8;
    after_0:
L_80003FD4:
    // 0x80003FD4: lw          $v1, 0x42F8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X42F8);
    // 0x80003FD8: lui         $t1, 0x8006
    ctx->r9 = S32(0X8006 << 16);
    // 0x80003FDC: lui         $s2, 0x8006
    ctx->r18 = S32(0X8006 << 16);
    // 0x80003FE0: sw          $v1, 0x42BC($s0)
    MEM_W(0X42BC, ctx->r16) = ctx->r3;
    // 0x80003FE4: lw          $t1, -0x2FC4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2FC4);
    // 0x80003FE8: addiu       $s2, $s2, -0x2FCC
    ctx->r18 = ADD32(ctx->r18, -0X2FCC);
    // 0x80003FEC: bgtzl       $t1, L_80004004
    if (SIGNED(ctx->r9) > 0) {
        // 0x80003FF0: lbu         $t3, 0x42EC($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X42EC);
            goto L_80004004;
    }
    goto skip_0;
    // 0x80003FF0: lbu         $t3, 0x42EC($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X42EC);
    skip_0:
    // 0x80003FF4: lbu         $t2, 0x42EC($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X42EC);
    // 0x80003FF8: beq         $t2, $zero, L_800042E4
    if (ctx->r10 == 0) {
        // 0x80003FFC: nop
    
            goto L_800042E4;
    }
    // 0x80003FFC: nop

    // 0x80004000: lbu         $t3, 0x42EC($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X42EC);
L_80004004:
    // 0x80004004: bnel        $t3, $zero, L_80004098
    if (ctx->r11 != 0) {
        // 0x80004008: lw          $a0, 0x0($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X0);
            goto L_80004098;
    }
    goto skip_1;
    // 0x80004008: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    skip_1:
    // 0x8000400C: lw          $a0, 0x42D4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X42D4);
    // 0x80004010: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x80004014: sll         $t5, $t4, 24
    ctx->r13 = S32(ctx->r12 << 24);
    // 0x80004018: jal         0x80003E40
    // 0x8000401C: sw          $t5, 0x42E8($s0)
    MEM_W(0X42E8, ctx->r16) = ctx->r13;
    LOOKUP_FUNC(0x80003E40)(rdram, ctx);
        goto after_1;
    // 0x8000401C: sw          $t5, 0x42E8($s0)
    MEM_W(0X42E8, ctx->r16) = ctx->r13;
    after_1:
    // 0x80004020: sw          $v0, 0x42D4($s0)
    MEM_W(0X42D4, ctx->r16) = ctx->r2;
    // 0x80004024: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80004028: lw          $t6, 0x42E8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X42E8);
    // 0x8000402C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80004030: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80004034: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80004038: jal         0x80003E40
    // 0x8000403C: sw          $t9, 0x42E8($s0)
    MEM_W(0X42E8, ctx->r16) = ctx->r25;
    LOOKUP_FUNC(0x80003E40)(rdram, ctx);
        goto after_2;
    // 0x8000403C: sw          $t9, 0x42E8($s0)
    MEM_W(0X42E8, ctx->r16) = ctx->r25;
    after_2:
    // 0x80004040: sw          $v0, 0x42D4($s0)
    MEM_W(0X42D4, ctx->r16) = ctx->r2;
    // 0x80004044: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80004048: lw          $t0, 0x42E8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X42E8);
    // 0x8000404C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80004050: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x80004054: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80004058: jal         0x80003E40
    // 0x8000405C: sw          $t3, 0x42E8($s0)
    MEM_W(0X42E8, ctx->r16) = ctx->r11;
    LOOKUP_FUNC(0x80003E40)(rdram, ctx);
        goto after_3;
    // 0x8000405C: sw          $t3, 0x42E8($s0)
    MEM_W(0X42E8, ctx->r16) = ctx->r11;
    after_3:
    // 0x80004060: sw          $v0, 0x42D4($s0)
    MEM_W(0X42D4, ctx->r16) = ctx->r2;
    // 0x80004064: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80004068: lw          $t4, 0x42E8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X42E8);
    // 0x8000406C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80004070: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x80004074: jal         0x80003E40
    // 0x80004078: sw          $t7, 0x42E8($s0)
    MEM_W(0X42E8, ctx->r16) = ctx->r15;
    LOOKUP_FUNC(0x80003E40)(rdram, ctx);
        goto after_4;
    // 0x80004078: sw          $t7, 0x42E8($s0)
    MEM_W(0X42E8, ctx->r16) = ctx->r15;
    after_4:
    // 0x8000407C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80004080: lw          $t8, 0x42E8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X42E8);
    // 0x80004084: sw          $v0, 0x42D4($s0)
    MEM_W(0X42D4, ctx->r16) = ctx->r2;
    // 0x80004088: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8000408C: addiu       $t1, $t9, -0x4
    ctx->r9 = ADD32(ctx->r25, -0X4);
    // 0x80004090: sw          $t1, 0x42DC($s0)
    MEM_W(0X42DC, ctx->r16) = ctx->r9;
    // 0x80004094: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
L_80004098:
    // 0x80004098: lw          $v1, 0x42DC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X42DC);
    // 0x8000409C: sb          $zero, 0x42EC($s0)
    MEM_B(0X42EC, ctx->r16) = 0;
    // 0x800040A0: sltu        $at, $a0, $v1
    ctx->r1 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x800040A4: beql        $at, $zero, L_80004294
    if (ctx->r1 == 0) {
        // 0x800040A8: andi        $a0, $v1, 0xF
        ctx->r4 = ctx->r3 & 0XF;
            goto L_80004294;
    }
    goto skip_2;
    // 0x800040A8: andi        $a0, $v1, 0xF
    ctx->r4 = ctx->r3 & 0XF;
    skip_2:
    // 0x800040AC: lw          $t2, 0x42F0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X42F0);
L_800040B0:
    // 0x800040B0: lw          $t0, 0x42CC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X42CC);
    // 0x800040B4: subu        $t3, $a0, $t2
    ctx->r11 = SUB32(ctx->r4, ctx->r10);
    // 0x800040B8: sltu        $at, $t0, $t3
    ctx->r1 = ctx->r8 < ctx->r11 ? 1 : 0;
    // 0x800040BC: beq         $at, $zero, L_800040D4
    if (ctx->r1 == 0) {
        // 0x800040C0: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800040D4;
    }
    // 0x800040C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800040C4: sw          $a0, 0x42F0($s0)
    MEM_W(0X42F0, ctx->r16) = ctx->r4;
    // 0x800040C8: sb          $t4, 0x42EC($s0)
    MEM_B(0X42EC, ctx->r16) = ctx->r12;
    // 0x800040CC: b           L_800042F0
    // 0x800040D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800042F0;
    // 0x800040D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800040D4:
    // 0x800040D4: lw          $a0, 0x42D4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X42D4);
    // 0x800040D8: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x800040DC: jal         0x80003E40
    // 0x800040E0: sb          $t5, 0x42E0($s0)
    MEM_B(0X42E0, ctx->r16) = ctx->r13;
    LOOKUP_FUNC(0x80003E40)(rdram, ctx);
        goto after_5;
    // 0x800040E0: sb          $t5, 0x42E0($s0)
    MEM_B(0X42E0, ctx->r16) = ctx->r13;
    after_5:
    // 0x800040E4: lbu         $a1, 0x42E0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X42E0);
    // 0x800040E8: sw          $v0, 0x42D4($s0)
    MEM_W(0X42D4, ctx->r16) = ctx->r2;
    // 0x800040EC: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x800040F0: beq         $at, $zero, L_80004180
    if (ctx->r1 == 0) {
        // 0x800040F4: sra         $t7, $a1, 2
        ctx->r15 = S32(SIGNED(ctx->r5) >> 2);
            goto L_80004180;
    }
    // 0x800040F4: sra         $t7, $a1, 2
    ctx->r15 = S32(SIGNED(ctx->r5) >> 2);
    // 0x800040F8: addiu       $t6, $t7, 0x2
    ctx->r14 = ADD32(ctx->r15, 0X2);
    // 0x800040FC: sh          $t6, 0x42E2($s0)
    MEM_H(0X42E2, ctx->r16) = ctx->r14;
    // 0x80004100: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80004104: sll         $t9, $a1, 8
    ctx->r25 = S32(ctx->r5 << 8);
    // 0x80004108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000410C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80004110: andi        $t2, $t1, 0x3FF
    ctx->r10 = ctx->r9 & 0X3FF;
    // 0x80004114: jal         0x80003E40
    // 0x80004118: sh          $t2, 0x42E4($s0)
    MEM_H(0X42E4, ctx->r16) = ctx->r10;
    LOOKUP_FUNC(0x80003E40)(rdram, ctx);
        goto after_6;
    // 0x80004118: sh          $t2, 0x42E4($s0)
    MEM_H(0X42E4, ctx->r16) = ctx->r10;
    after_6:
    // 0x8000411C: lw          $t0, 0x42F8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X42F8);
    // 0x80004120: lhu         $t3, 0x42E4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X42E4);
    // 0x80004124: lhu         $v1, 0x42E2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X42E2);
    // 0x80004128: sw          $v0, 0x42D4($s0)
    MEM_W(0X42D4, ctx->r16) = ctx->r2;
    // 0x8000412C: subu        $t4, $t0, $t3
    ctx->r12 = SUB32(ctx->r8, ctx->r11);
    // 0x80004130: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80004134: sw          $t4, 0x42D8($s0)
    MEM_W(0X42D8, ctx->r16) = ctx->r12;
    // 0x80004138: beq         $v1, $zero, L_8000427C
    if (ctx->r3 == 0) {
        // 0x8000413C: sh          $t5, 0x42E2($s0)
        MEM_H(0X42E2, ctx->r16) = ctx->r13;
            goto L_8000427C;
    }
    // 0x8000413C: sh          $t5, 0x42E2($s0)
    MEM_H(0X42E2, ctx->r16) = ctx->r13;
L_80004140:
    // 0x80004140: lw          $t7, 0x42D8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X42D8);
    // 0x80004144: lw          $t8, 0x42F8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X42F8);
    // 0x80004148: lbu         $t6, 0x0($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X0);
    // 0x8000414C: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x80004150: lhu         $v1, 0x42E2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X42E2);
    // 0x80004154: lw          $t2, 0x42D8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X42D8);
    // 0x80004158: lw          $t9, 0x42F8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X42F8);
    // 0x8000415C: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x80004160: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x80004164: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80004168: sw          $t1, 0x42F8($s0)
    MEM_W(0X42F8, ctx->r16) = ctx->r9;
    // 0x8000416C: sw          $t0, 0x42D8($s0)
    MEM_W(0X42D8, ctx->r16) = ctx->r8;
    // 0x80004170: bne         $v1, $zero, L_80004140
    if (ctx->r3 != 0) {
        // 0x80004174: sh          $t3, 0x42E2($s0)
        MEM_H(0X42E2, ctx->r16) = ctx->r11;
            goto L_80004140;
    }
    // 0x80004174: sh          $t3, 0x42E2($s0)
    MEM_H(0X42E2, ctx->r16) = ctx->r11;
    // 0x80004178: b           L_80004280
    // 0x8000417C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
        goto L_80004280;
    // 0x8000417C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
L_80004180:
    // 0x80004180: slti        $at, $a1, 0xA0
    ctx->r1 = SIGNED(ctx->r5) < 0XA0 ? 1 : 0;
    // 0x80004184: beq         $at, $zero, L_800041E0
    if (ctx->r1 == 0) {
        // 0x80004188: andi        $t4, $a1, 0x1F
        ctx->r12 = ctx->r5 & 0X1F;
            goto L_800041E0;
    }
    // 0x80004188: andi        $t4, $a1, 0x1F
    ctx->r12 = ctx->r5 & 0X1F;
    // 0x8000418C: andi        $v1, $t4, 0xFFFF
    ctx->r3 = ctx->r12 & 0XFFFF;
    // 0x80004190: sh          $t4, 0x42E2($s0)
    MEM_H(0X42E2, ctx->r16) = ctx->r12;
    // 0x80004194: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80004198: beq         $v1, $zero, L_8000427C
    if (ctx->r3 == 0) {
        // 0x8000419C: sh          $t5, 0x42E2($s0)
        MEM_H(0X42E2, ctx->r16) = ctx->r13;
            goto L_8000427C;
    }
    // 0x8000419C: sh          $t5, 0x42E2($s0)
    MEM_H(0X42E2, ctx->r16) = ctx->r13;
L_800041A0:
    // 0x800041A0: lw          $t7, 0x42D4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X42D4);
    // 0x800041A4: lw          $t8, 0x42F8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X42F8);
    // 0x800041A8: lbu         $t6, 0x0($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X0);
    // 0x800041AC: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x800041B0: lw          $t9, 0x42F8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X42F8);
    // 0x800041B4: lw          $a0, 0x42D4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X42D4);
    // 0x800041B8: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x800041BC: jal         0x80003E40
    // 0x800041C0: sw          $t1, 0x42F8($s0)
    MEM_W(0X42F8, ctx->r16) = ctx->r9;
    LOOKUP_FUNC(0x80003E40)(rdram, ctx);
        goto after_7;
    // 0x800041C0: sw          $t1, 0x42F8($s0)
    MEM_W(0X42F8, ctx->r16) = ctx->r9;
    after_7:
    // 0x800041C4: lhu         $v1, 0x42E2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X42E2);
    // 0x800041C8: sw          $v0, 0x42D4($s0)
    MEM_W(0X42D4, ctx->r16) = ctx->r2;
    // 0x800041CC: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x800041D0: bne         $v1, $zero, L_800041A0
    if (ctx->r3 != 0) {
        // 0x800041D4: sh          $t2, 0x42E2($s0)
        MEM_H(0X42E2, ctx->r16) = ctx->r10;
            goto L_800041A0;
    }
    // 0x800041D4: sh          $t2, 0x42E2($s0)
    MEM_H(0X42E2, ctx->r16) = ctx->r10;
    // 0x800041D8: b           L_80004280
    // 0x800041DC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
        goto L_80004280;
    // 0x800041DC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
L_800041E0:
    // 0x800041E0: slti        $at, $a1, 0xE0
    ctx->r1 = SIGNED(ctx->r5) < 0XE0 ? 1 : 0;
    // 0x800041E4: beq         $at, $zero, L_8000420C
    if (ctx->r1 == 0) {
        // 0x800041E8: andi        $t0, $a1, 0x1F
        ctx->r8 = ctx->r5 & 0X1F;
            goto L_8000420C;
    }
    // 0x800041E8: andi        $t0, $a1, 0x1F
    ctx->r8 = ctx->r5 & 0X1F;
    // 0x800041EC: lw          $a0, 0x42D4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X42D4);
    // 0x800041F0: addiu       $t3, $t0, 0x2
    ctx->r11 = ADD32(ctx->r8, 0X2);
    // 0x800041F4: sh          $t3, 0x42E2($s0)
    MEM_H(0X42E2, ctx->r16) = ctx->r11;
    // 0x800041F8: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x800041FC: jal         0x80003E40
    // 0x80004200: sb          $t4, 0x42E1($s0)
    MEM_B(0X42E1, ctx->r16) = ctx->r12;
    LOOKUP_FUNC(0x80003E40)(rdram, ctx);
        goto after_8;
    // 0x80004200: sb          $t4, 0x42E1($s0)
    MEM_B(0X42E1, ctx->r16) = ctx->r12;
    after_8:
    // 0x80004204: b           L_80004244
    // 0x80004208: sw          $v0, 0x42D4($s0)
    MEM_W(0X42D4, ctx->r16) = ctx->r2;
        goto L_80004244;
    // 0x80004208: sw          $v0, 0x42D4($s0)
    MEM_W(0X42D4, ctx->r16) = ctx->r2;
L_8000420C:
    // 0x8000420C: slti        $at, $a1, 0xFF
    ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
    // 0x80004210: beq         $at, $zero, L_80004228
    if (ctx->r1 == 0) {
        // 0x80004214: andi        $t5, $a1, 0x1F
        ctx->r13 = ctx->r5 & 0X1F;
            goto L_80004228;
    }
    // 0x80004214: andi        $t5, $a1, 0x1F
    ctx->r13 = ctx->r5 & 0X1F;
    // 0x80004218: addiu       $t7, $t5, 0x2
    ctx->r15 = ADD32(ctx->r13, 0X2);
    // 0x8000421C: sh          $t7, 0x42E2($s0)
    MEM_H(0X42E2, ctx->r16) = ctx->r15;
    // 0x80004220: b           L_80004244
    // 0x80004224: sb          $zero, 0x42E1($s0)
    MEM_B(0X42E1, ctx->r16) = 0;
        goto L_80004244;
    // 0x80004224: sb          $zero, 0x42E1($s0)
    MEM_B(0X42E1, ctx->r16) = 0;
L_80004228:
    // 0x80004228: lw          $a0, 0x42D4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X42D4);
    // 0x8000422C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80004230: addiu       $t8, $t6, 0x2
    ctx->r24 = ADD32(ctx->r14, 0X2);
    // 0x80004234: jal         0x80003E40
    // 0x80004238: sh          $t8, 0x42E2($s0)
    MEM_H(0X42E2, ctx->r16) = ctx->r24;
    LOOKUP_FUNC(0x80003E40)(rdram, ctx);
        goto after_9;
    // 0x80004238: sh          $t8, 0x42E2($s0)
    MEM_H(0X42E2, ctx->r16) = ctx->r24;
    after_9:
    // 0x8000423C: sw          $v0, 0x42D4($s0)
    MEM_W(0X42D4, ctx->r16) = ctx->r2;
    // 0x80004240: sb          $zero, 0x42E1($s0)
    MEM_B(0X42E1, ctx->r16) = 0;
L_80004244:
    // 0x80004244: lhu         $v1, 0x42E2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X42E2);
    // 0x80004248: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x8000424C: beq         $v1, $zero, L_8000427C
    if (ctx->r3 == 0) {
        // 0x80004250: sh          $t9, 0x42E2($s0)
        MEM_H(0X42E2, ctx->r16) = ctx->r25;
            goto L_8000427C;
    }
    // 0x80004250: sh          $t9, 0x42E2($s0)
    MEM_H(0X42E2, ctx->r16) = ctx->r25;
L_80004254:
    // 0x80004254: lbu         $t1, 0x42E1($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X42E1);
    // 0x80004258: lw          $t2, 0x42F8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X42F8);
    // 0x8000425C: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
    // 0x80004260: lhu         $v1, 0x42E2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X42E2);
    // 0x80004264: lw          $t0, 0x42F8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X42F8);
    // 0x80004268: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8000426C: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x80004270: sw          $t3, 0x42F8($s0)
    MEM_W(0X42F8, ctx->r16) = ctx->r11;
    // 0x80004274: bne         $v1, $zero, L_80004254
    if (ctx->r3 != 0) {
        // 0x80004278: sh          $t4, 0x42E2($s0)
        MEM_H(0X42E2, ctx->r16) = ctx->r12;
            goto L_80004254;
    }
    // 0x80004278: sh          $t4, 0x42E2($s0)
    MEM_H(0X42E2, ctx->r16) = ctx->r12;
L_8000427C:
    // 0x8000427C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
L_80004280:
    // 0x80004280: lw          $v1, 0x42DC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X42DC);
    // 0x80004284: sltu        $at, $a0, $v1
    ctx->r1 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x80004288: bnel        $at, $zero, L_800040B0
    if (ctx->r1 != 0) {
        // 0x8000428C: lw          $t2, 0x42F0($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X42F0);
            goto L_800040B0;
    }
    goto skip_3;
    // 0x8000428C: lw          $t2, 0x42F0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X42F0);
    skip_3:
    // 0x80004290: andi        $a0, $v1, 0xF
    ctx->r4 = ctx->r3 & 0XF;
L_80004294:
    // 0x80004294: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x80004298: beq         $a0, $zero, L_800042C0
    if (ctx->r4 == 0) {
        // 0x8000429C: sw          $t5, 0x42DC($s0)
        MEM_W(0X42DC, ctx->r16) = ctx->r13;
            goto L_800042C0;
    }
    // 0x8000429C: sw          $t5, 0x42DC($s0)
    MEM_W(0X42DC, ctx->r16) = ctx->r13;
L_800042A0:
    // 0x800042A0: jal         0x80003E40
    // 0x800042A4: lw          $a0, 0x42D4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X42D4);
    LOOKUP_FUNC(0x80003E40)(rdram, ctx);
        goto after_10;
    // 0x800042A4: lw          $a0, 0x42D4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X42D4);
    after_10:
    // 0x800042A8: lw          $v1, 0x42DC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X42DC);
    // 0x800042AC: sw          $v0, 0x42D4($s0)
    MEM_W(0X42D4, ctx->r16) = ctx->r2;
    // 0x800042B0: andi        $a0, $v1, 0xF
    ctx->r4 = ctx->r3 & 0XF;
    // 0x800042B4: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x800042B8: bne         $a0, $zero, L_800042A0
    if (ctx->r4 != 0) {
        // 0x800042BC: sw          $t7, 0x42DC($s0)
        MEM_W(0X42DC, ctx->r16) = ctx->r15;
            goto L_800042A0;
    }
    // 0x800042BC: sw          $t7, 0x42DC($s0)
    MEM_W(0X42DC, ctx->r16) = ctx->r15;
L_800042C0:
    // 0x800042C0: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x800042C4: lw          $t6, -0x2FC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2FC4);
    // 0x800042C8: bgtzl       $t6, L_80004004
    if (SIGNED(ctx->r14) > 0) {
        // 0x800042CC: lbu         $t3, 0x42EC($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X42EC);
            goto L_80004004;
    }
    goto skip_4;
    // 0x800042CC: lbu         $t3, 0x42EC($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X42EC);
    skip_4:
    // 0x800042D0: lbu         $t8, 0x42EC($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X42EC);
    // 0x800042D4: bnel        $t8, $zero, L_80004004
    if (ctx->r24 != 0) {
        // 0x800042D8: lbu         $t3, 0x42EC($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X42EC);
            goto L_80004004;
    }
    goto skip_5;
    // 0x800042D8: lbu         $t3, 0x42EC($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X42EC);
    skip_5:
    // 0x800042DC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800042E0: lw          $v1, -0x2A58($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2A58);
L_800042E4:
    // 0x800042E4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800042E8: sb          $zero, -0x2A64($at)
    MEM_B(-0X2A64, ctx->r1) = 0;
    // 0x800042EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800042F0:
    // 0x800042F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800042F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800042F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800042FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80004300: jr          $ra
    // 0x80004304: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80004304: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80004308: nop

    // 0x8000430C: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80004310(rdram, ctx);
;}
RECOMP_FUNC void FUN_80004310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004310: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80004314: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x80004318: lbu         $t6, 0x1BD($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1BD);
    // 0x8000431C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80004320: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80004324: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80004328: sw          $a0, -0x6B0C($at)
    MEM_W(-0X6B0C, ctx->r1) = ctx->r4;
    // 0x8000432C: lbu         $t8, 0x1BD($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1BD);
    // 0x80004330: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80004334: jr          $ra
    // 0x80004338: sb          $t9, 0x1BD($v0)
    MEM_B(0X1BD, ctx->r2) = ctx->r25;
    return;
    // 0x80004338: sb          $t9, 0x1BD($v0)
    MEM_B(0X1BD, ctx->r2) = ctx->r25;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_8000433c(rdram, ctx);
;}
RECOMP_FUNC void FUN_8000433c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000433C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80004340: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80004344: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80004348: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8000434C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80004350: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80004354: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x80004358: lui         $s5, 0xFFF
    ctx->r21 = S32(0XFFF << 16);
    // 0x8000435C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80004360: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80004364: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80004368: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000436C: addiu       $s6, $s6, -0x6B0C
    ctx->r22 = ADD32(ctx->r22, -0X6B0C);
    // 0x80004370: ori         $s5, $s5, 0xFFFF
    ctx->r21 = ctx->r21 | 0XFFFF;
    // 0x80004374: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80004378: lui         $s4, 0x4000
    ctx->r20 = S32(0X4000 << 16);
    // 0x8000437C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_80004380:
    // 0x80004380: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x80004384: beq         $v0, $zero, L_8000443C
    if (ctx->r2 == 0) {
        // 0x80004388: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000443C;
    }
    // 0x80004388: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8000438C:
    // 0x8000438C: jal         0x80016F90
    // 0x80004390: nop

    LOOKUP_FUNC(0x80016F90)(rdram, ctx);
        goto after_0;
    // 0x80004390: nop

    after_0:
    // 0x80004394: jal         0x80017014
    // 0x80004398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x80017014)(rdram, ctx);
        goto after_1;
    // 0x80004398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8000439C: bnel        $v0, $zero, L_8000443C
    if (ctx->r2 != 0) {
        // 0x800043A0: sw          $zero, 0x0($s6)
        MEM_W(0X0, ctx->r22) = 0;
            goto L_8000443C;
    }
    goto skip_0;
    // 0x800043A0: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    skip_0:
    // 0x800043A4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800043A8: and         $s0, $t6, $s5
    ctx->r16 = ctx->r14 & ctx->r21;
    // 0x800043AC: andi        $s2, $s0, 0xFFFF
    ctx->r18 = ctx->r16 & 0XFFFF;
    // 0x800043B0: jal         0x80017064
    // 0x800043B4: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_2;
    // 0x800043B4: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    after_2:
    // 0x800043B8: beql        $v0, $s3, L_800043DC
    if (ctx->r2 == ctx->r19) {
        // 0x800043BC: lw          $a1, 0x4($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X4);
            goto L_800043DC;
    }
    goto skip_1;
    // 0x800043BC: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    skip_1:
    // 0x800043C0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800043C4: and         $t8, $t7, $s4
    ctx->r24 = ctx->r15 & ctx->r20;
    // 0x800043C8: bnel        $t8, $zero, L_8000443C
    if (ctx->r24 != 0) {
        // 0x800043CC: sw          $zero, 0x0($s6)
        MEM_W(0X0, ctx->r22) = 0;
            goto L_8000443C;
    }
    goto skip_2;
    // 0x800043CC: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    skip_2:
    // 0x800043D0: b           L_8000438C
    // 0x800043D4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
        goto L_8000438C;
    // 0x800043D4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800043D8: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
L_800043DC:
    // 0x800043DC: beq         $a1, $zero, L_800043FC
    if (ctx->r5 == 0) {
        // 0x800043E0: nop
    
            goto L_800043FC;
    }
    // 0x800043E0: nop

    // 0x800043E4: bne         $a1, $s3, L_8000440C
    if (ctx->r5 != ctx->r19) {
        // 0x800043E8: nop
    
            goto L_8000440C;
    }
    // 0x800043E8: nop

    // 0x800043EC: jal         0x80004484
    // 0x800043F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80004484)(rdram, ctx);
        goto after_3;
    // 0x800043F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800043F4: b           L_80004418
    // 0x800043F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80004418;
    // 0x800043F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800043FC:
    // 0x800043FC: jal         0x800045E8
    // 0x80004400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800045E8)(rdram, ctx);
        goto after_4;
    // 0x80004400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80004404: b           L_80004418
    // 0x80004408: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80004418;
    // 0x80004408: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8000440C:
    // 0x8000440C: jal         0x80004664
    // 0x80004410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80004664)(rdram, ctx);
        goto after_5;
    // 0x80004410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80004414: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80004418:
    // 0x80004418: jal         0x80004ADC
    // 0x8000441C: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    LOOKUP_FUNC(0x80004ADC)(rdram, ctx);
        goto after_6;
    // 0x8000441C: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    after_6:
    // 0x80004420: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80004424: and         $t0, $t9, $s4
    ctx->r8 = ctx->r25 & ctx->r20;
    // 0x80004428: bnel        $t0, $zero, L_8000443C
    if (ctx->r8 != 0) {
        // 0x8000442C: sw          $zero, 0x0($s6)
        MEM_W(0X0, ctx->r22) = 0;
            goto L_8000443C;
    }
    goto skip_3;
    // 0x8000442C: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    skip_3:
    // 0x80004430: b           L_8000438C
    // 0x80004434: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
        goto L_8000438C;
    // 0x80004434: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80004438: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
L_8000443C:
    // 0x8000443C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80004440: andi        $s7, $s7, 0xFF
    ctx->r23 = ctx->r23 & 0XFF;
    // 0x80004444: slti        $at, $s7, 0x8
    ctx->r1 = SIGNED(ctx->r23) < 0X8 ? 1 : 0;
    // 0x80004448: bne         $at, $zero, L_80004380
    if (ctx->r1 != 0) {
        // 0x8000444C: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_80004380;
    }
    // 0x8000444C: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80004450: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80004454: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80004458: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000445C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80004460: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80004464: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80004468: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000446C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80004470: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80004474: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80004478: sb          $zero, -0x6B93($at)
    MEM_B(-0X6B93, ctx->r1) = 0;
    // 0x8000447C: jr          $ra
    // 0x80004480: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80004480: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80004484(rdram, ctx);
;}
RECOMP_FUNC void FUN_80004484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004484: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80004488: lw          $a1, -0x43F0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X43F0);
    // 0x8000448C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80004490: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80004494: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    // 0x80004498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000449C: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    // 0x800044A0: jal         0x8000469C
    // 0x800044A4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_0;
    // 0x800044A4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800044A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800044AC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800044B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800044B4: jr          $ra
    // 0x800044B8: nop

    return;
    // 0x800044B8: nop

;}
RECOMP_FUNC void FUN_800044bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800044BC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x800044C0: lw          $a1, -0x6B90($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6B90);
    // 0x800044C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800044C8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800044CC: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    // 0x800044D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800044D4: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    // 0x800044D8: jal         0x8000469C
    // 0x800044DC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_0;
    // 0x800044DC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800044E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800044E4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800044E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800044EC: sw          $v0, -0x6B90($at)
    MEM_W(-0X6B90, ctx->r1) = ctx->r2;
    // 0x800044F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800044F4: jr          $ra
    // 0x800044F8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800044F8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800044fc(rdram, ctx);
;}
RECOMP_FUNC void FUN_800044fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800044FC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80004500: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80004504: lw          $v0, -0x43F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X43F0);
    // 0x80004508: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x8000450C: lw          $a1, 0x42A8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X42A8);
    // 0x80004510: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004514: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80004518: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x8000451C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004520: bne         $a1, $zero, L_80004530
    if (ctx->r5 != 0) {
        // 0x80004524: and         $v0, $v0, $at
        ctx->r2 = ctx->r2 & ctx->r1;
            goto L_80004530;
    }
    // 0x80004524: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x80004528: sw          $v0, 0x42A8($v1)
    MEM_W(0X42A8, ctx->r3) = ctx->r2;
    // 0x8000452C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80004530:
    // 0x80004530: jal         0x80004838
    // 0x80004534: nop

    LOOKUP_FUNC(0x80004838)(rdram, ctx);
        goto after_0;
    // 0x80004534: nop

    after_0:
    // 0x80004538: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8000453C: bne         $v0, $zero, L_8000454C
    if (ctx->r2 != 0) {
        // 0x80004540: addiu       $v1, $v1, -0x6D50
        ctx->r3 = ADD32(ctx->r3, -0X6D50);
            goto L_8000454C;
    }
    // 0x80004540: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x80004544: b           L_80004550
    // 0x80004548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80004550;
    // 0x80004548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000454C:
    // 0x8000454C: lw          $v0, 0x42A8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X42A8);
L_80004550:
    // 0x80004550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004558: jr          $ra
    // 0x8000455C: nop

    return;
    // 0x8000455C: nop

;}
RECOMP_FUNC void FUN_80004560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004560: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80004564: lw          $t6, -0x2AA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AA8);
    // 0x80004568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000456C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004570: bne         $t6, $zero, L_800045B8
    if (ctx->r14 != 0) {
        // 0x80004574: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800045B8;
    }
    // 0x80004574: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80004578: or          $t8, $a0, $zero
    ctx->r24 = ctx->r4 | 0;
    // 0x8000457C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80004580: lui         $t1, 0x8003
    ctx->r9 = S32(0X8003 << 16);
    // 0x80004584: addiu       $t1, $t1, 0x7C5C
    ctx->r9 = ADD32(ctx->r9, 0X7C5C);
    // 0x80004588: addiu       $t0, $t9, -0x8
    ctx->r8 = ADD32(ctx->r25, -0X8);
    // 0x8000458C: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80004590: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x80004594: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80004598: jal         0x8001F290
    // 0x8000459C: subu        $a0, $t2, $t3
    ctx->r4 = SUB32(ctx->r10, ctx->r11);
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_0;
    // 0x8000459C: subu        $a0, $t2, $t3
    ctx->r4 = SUB32(ctx->r10, ctx->r11);
    after_0:
    // 0x800045A0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800045A4: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x800045A8: sw          $v0, 0x42A8($v1)
    MEM_W(0X42A8, ctx->r3) = ctx->r2;
    // 0x800045AC: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x800045B0: jal         0x8001752C
    // 0x800045B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    LOOKUP_FUNC(0x8001752C)(rdram, ctx);
        goto after_1;
    // 0x800045B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
L_800045B8:
    // 0x800045B8: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x800045BC: lw          $a1, -0x2AA8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2AA8);
    // 0x800045C0: jal         0x80004838
    // 0x800045C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80004838)(rdram, ctx);
        goto after_2;
    // 0x800045C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800045C8: bne         $v0, $zero, L_800045D8
    if (ctx->r2 != 0) {
        // 0x800045CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800045D8;
    }
    // 0x800045CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800045D0: b           L_800045E0
    // 0x800045D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800045E0;
    // 0x800045D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800045D8:
    // 0x800045D8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800045DC: lw          $v0, -0x2AA8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AA8);
L_800045E0:
    // 0x800045E0: jr          $ra
    // 0x800045E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800045E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800045e8(rdram, ctx);
;}
RECOMP_FUNC void FUN_800045e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800045E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800045EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800045F0: beq         $a0, $zero, L_80004604
    if (ctx->r4 == 0) {
        // 0x800045F4: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80004604;
    }
    // 0x800045F4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800045F8: sltiu       $at, $a0, 0x271
    ctx->r1 = ctx->r4 < 0X271 ? 1 : 0;
    // 0x800045FC: bne         $at, $zero, L_8000460C
    if (ctx->r1 != 0) {
        // 0x80004600: sll         $t7, $a2, 3
        ctx->r15 = S32(ctx->r6 << 3);
            goto L_8000460C;
    }
    // 0x80004600: sll         $t7, $a2, 3
    ctx->r15 = S32(ctx->r6 << 3);
L_80004604:
    // 0x80004604: b           L_80004654
    // 0x80004608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80004654;
    // 0x80004608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000460C:
    // 0x8000460C: lui         $t9, 0x8003
    ctx->r25 = S32(0X8003 << 16);
    // 0x80004610: addiu       $t9, $t9, 0x7C5C
    ctx->r25 = ADD32(ctx->r25, 0X7C5C);
    // 0x80004614: addiu       $t8, $t7, -0x8
    ctx->r24 = ADD32(ctx->r15, -0X8);
    // 0x80004618: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8000461C: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80004620: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80004624: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80004628: jal         0x8001F290
    // 0x8000462C: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_0;
    // 0x8000462C: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    after_0:
    // 0x80004630: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80004634: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80004638: jal         0x8000469C
    // 0x8000463C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_1;
    // 0x8000463C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80004640: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80004644: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80004648: jal         0x80016EAC
    // 0x8000464C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    LOOKUP_FUNC(0x80016EAC)(rdram, ctx);
        goto after_2;
    // 0x8000464C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    after_2:
    // 0x80004650: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80004654:
    // 0x80004654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004658: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000465C: jr          $ra
    // 0x80004660: nop

    return;
    // 0x80004660: nop

;}
RECOMP_FUNC void FUN_80004664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004664: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000466C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80004670: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80004674: jal         0x80016EAC
    // 0x80004678: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x80016EAC)(rdram, ctx);
        goto after_0;
    // 0x80004678: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_0:
    // 0x8000467C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80004680: jal         0x8000469C
    // 0x80004684: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_1;
    // 0x80004684: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80004688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000468C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80004690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004694: jr          $ra
    // 0x80004698: nop

    return;
    // 0x80004698: nop

;}
RECOMP_FUNC void FUN_8000469c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000469C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800046A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800046A4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800046A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800046AC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800046B0: beq         $a0, $zero, L_800046C4
    if (ctx->r4 == 0) {
        // 0x800046B4: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800046C4;
    }
    // 0x800046B4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800046B8: sltiu       $at, $a0, 0x271
    ctx->r1 = ctx->r4 < 0X271 ? 1 : 0;
    // 0x800046BC: bne         $at, $zero, L_800046CC
    if (ctx->r1 != 0) {
        // 0x800046C0: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_800046CC;
    }
    // 0x800046C0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
L_800046C4:
    // 0x800046C4: b           L_80004824
    // 0x800046C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80004824;
    // 0x800046C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800046CC:
    // 0x800046CC: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800046D0: addiu       $a1, $a1, -0x7020
    ctx->r5 = ADD32(ctx->r5, -0X7020);
    // 0x800046D4: lui         $t1, 0x7FFF
    ctx->r9 = S32(0X7FFF << 16);
    // 0x800046D8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800046DC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800046E0: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x800046E4: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x800046E8: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x800046EC: lw          $t3, 0x14($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X14);
    // 0x800046F0: and         $t9, $t8, $t1
    ctx->r25 = ctx->r24 & ctx->r9;
    // 0x800046F4: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x800046F8: addiu       $t8, $t8, 0x7C5C
    ctx->r24 = ADD32(ctx->r24, 0X7C5C);
    // 0x800046FC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80004700: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80004704: and         $t4, $t3, $t1
    ctx->r12 = ctx->r11 & ctx->r9;
    // 0x80004708: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8000470C: subu        $t0, $t4, $t9
    ctx->r8 = SUB32(ctx->r12, ctx->r25);
    // 0x80004710: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80004714: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80004718: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8000471C: addiu       $t2, $t2, -0x23E8
    ctx->r10 = ADD32(ctx->r10, -0X23E8);
    // 0x80004720: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80004724: subu        $t4, $t9, $t3
    ctx->r12 = SUB32(ctx->r25, ctx->r11);
    // 0x80004728: addu        $a3, $t4, $s0
    ctx->r7 = ADD32(ctx->r12, ctx->r16);
    // 0x8000472C: beq         $t0, $zero, L_800047E8
    if (ctx->r8 == 0) {
        // 0x80004730: sb          $t5, 0x0($t2)
        MEM_B(0X0, ctx->r10) = ctx->r13;
            goto L_800047E8;
    }
    // 0x80004730: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
    // 0x80004734: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80004738: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000473C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80004740: addu        $v0, $a1, $t7
    ctx->r2 = ADD32(ctx->r5, ctx->r15);
    // 0x80004744: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80004748: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8000474C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80004750: sll         $t8, $a0, 0
    ctx->r24 = S32(ctx->r4 << 0);
    // 0x80004754: bgezl       $t8, L_800047C0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80004758: addiu       $v0, $t0, 0x1
        ctx->r2 = ADD32(ctx->r8, 0X1);
            goto L_800047C0;
    }
    goto skip_0;
    // 0x80004758: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x8000475C: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x80004760: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80004764: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80004768: and         $t3, $t9, $t1
    ctx->r11 = ctx->r25 & ctx->r9;
    // 0x8000476C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80004770: jal         0x80003824
    // 0x80004774: subu        $a2, $t3, $a0
    ctx->r6 = SUB32(ctx->r11, ctx->r4);
    LOOKUP_FUNC(0x80003824)(rdram, ctx);
        goto after_0;
    // 0x80004774: subu        $a2, $t3, $a0
    ctx->r6 = SUB32(ctx->r11, ctx->r4);
    after_0:
    // 0x80004778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000477C: subu        $a1, $v0, $s0
    ctx->r5 = SUB32(ctx->r2, ctx->r16);
    // 0x80004780: jal         0x80028A90
    // 0x80004784: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80028A90)(rdram, ctx);
        goto after_1;
    // 0x80004784: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80004788: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8000478C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004790: subu        $a1, $a2, $s0
    ctx->r5 = SUB32(ctx->r6, ctx->r16);
    // 0x80004794: jal         0x80030640
    // 0x80004798: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80030640)(rdram, ctx);
        goto after_2;
    // 0x80004798: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x8000479C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800047A0: jal         0x800306C0
    // 0x800047A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800306C0)(rdram, ctx);
        goto after_3;
    // 0x800047A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800047A8: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x800047AC: addiu       $t2, $t2, -0x23E8
    ctx->r10 = ADD32(ctx->r10, -0X23E8);
    // 0x800047B0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800047B4: b           L_800047E8
    // 0x800047B8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_800047E8;
    // 0x800047B8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800047BC: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
L_800047C0:
    // 0x800047C0: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x800047C4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800047C8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800047CC: jal         0x80001FE8
    // 0x800047D0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80001FE8)(rdram, ctx);
        goto after_4;
    // 0x800047D0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_4:
    // 0x800047D4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800047D8: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x800047DC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800047E0: addiu       $t2, $t2, -0x23E8
    ctx->r10 = ADD32(ctx->r10, -0X23E8);
    // 0x800047E4: addu        $a2, $s0, $v0
    ctx->r6 = ADD32(ctx->r16, ctx->r2);
L_800047E8:
    // 0x800047E8: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x800047EC: beq         $v1, $zero, L_80004804
    if (ctx->r3 == 0) {
        // 0x800047F0: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80004804;
    }
    // 0x800047F0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_800047F4:
    // 0x800047F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800047F8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800047FC: bne         $v1, $zero, L_800047F4
    if (ctx->r3 != 0) {
        // 0x80004800: andi        $v0, $v0, 0xFF
        ctx->r2 = ctx->r2 & 0XFF;
            goto L_800047F4;
    }
    // 0x80004800: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80004804:
    // 0x80004804: sltu        $at, $a2, $a3
    ctx->r1 = ctx->r6 < ctx->r7 ? 1 : 0;
    // 0x80004808: beq         $at, $zero, L_80004820
    if (ctx->r1 == 0) {
        // 0x8000480C: sb          $zero, 0x0($t2)
        MEM_B(0X0, ctx->r10) = 0;
            goto L_80004820;
    }
    // 0x8000480C: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
L_80004810:
    // 0x80004810: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80004814: sltu        $at, $a2, $a3
    ctx->r1 = ctx->r6 < ctx->r7 ? 1 : 0;
    // 0x80004818: bne         $at, $zero, L_80004810
    if (ctx->r1 != 0) {
        // 0x8000481C: sb          $zero, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = 0;
            goto L_80004810;
    }
    // 0x8000481C: sb          $zero, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = 0;
L_80004820:
    // 0x80004820: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80004824:
    // 0x80004824: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80004828: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000482C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80004830: jr          $ra
    // 0x80004834: nop

    return;
    // 0x80004834: nop

;}
RECOMP_FUNC void FUN_80004838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004838: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000483C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80004840: addiu       $t0, $t0, -0x6D50
    ctx->r8 = ADD32(ctx->r8, -0X6D50);
    // 0x80004844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004848: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8000484C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80004850: beq         $a0, $zero, L_80004864
    if (ctx->r4 == 0) {
        // 0x80004854: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80004864;
    }
    // 0x80004854: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80004858: sltiu       $at, $a0, 0x271
    ctx->r1 = ctx->r4 < 0X271 ? 1 : 0;
    // 0x8000485C: bne         $at, $zero, L_8000486C
    if (ctx->r1 != 0) {
        // 0x80004860: lui         $t3, 0x8004
        ctx->r11 = S32(0X8004 << 16);
            goto L_8000486C;
    }
    // 0x80004860: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
L_80004864:
    // 0x80004864: b           L_80004ACC
    // 0x80004868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80004ACC;
    // 0x80004868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000486C:
    // 0x8000486C: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x80004870: addiu       $t3, $t3, -0x7020
    ctx->r11 = ADD32(ctx->r11, -0X7020);
    // 0x80004874: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80004878: addu        $a0, $t3, $t6
    ctx->r4 = ADD32(ctx->r11, ctx->r14);
    // 0x8000487C: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x80004880: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x80004884: lui         $t4, 0x7FFF
    ctx->r12 = S32(0X7FFF << 16);
    // 0x80004888: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x8000488C: and         $t9, $t8, $t4
    ctx->r25 = ctx->r24 & ctx->r12;
    // 0x80004890: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x80004894: and         $a3, $t7, $t4
    ctx->r7 = ctx->r15 & ctx->r12;
    // 0x80004898: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x8000489C: addiu       $t8, $t8, 0x7C5C
    ctx->r24 = ADD32(ctx->r24, 0X7C5C);
    // 0x800048A0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800048A4: subu        $t2, $t9, $a3
    ctx->r10 = SUB32(ctx->r25, ctx->r7);
    // 0x800048A8: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800048AC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800048B0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800048B4: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x800048B8: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x800048BC: lbu         $t9, 0x42AD($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X42AD);
    // 0x800048C0: addiu       $t5, $t5, -0x23E8
    ctx->r13 = ADD32(ctx->r13, -0X23E8);
    // 0x800048C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800048C8: sb          $a0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r4;
    // 0x800048CC: bne         $t9, $zero, L_80004904
    if (ctx->r25 != 0) {
        // 0x800048D0: addu        $t1, $t7, $t8
        ctx->r9 = ADD32(ctx->r15, ctx->r24);
            goto L_80004904;
    }
    // 0x800048D0: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x800048D4: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800048D8: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800048DC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800048E0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800048E4: addiu       $v0, $t2, 0x1
    ctx->r2 = ADD32(ctx->r10, 0X1);
    // 0x800048E8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800048EC: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x800048F0: sb          $a0, 0x42AD($t0)
    MEM_B(0X42AD, ctx->r8) = ctx->r4;
    // 0x800048F4: sw          $v0, 0x42B8($t0)
    MEM_W(0X42B8, ctx->r8) = ctx->r2;
    // 0x800048F8: sw          $v0, 0x42BC($t0)
    MEM_W(0X42BC, ctx->r8) = ctx->r2;
    // 0x800048FC: sw          $t8, 0x42B0($t0)
    MEM_W(0X42B0, ctx->r8) = ctx->r24;
    // 0x80004900: sw          $t9, 0x42B4($t0)
    MEM_W(0X42B4, ctx->r8) = ctx->r25;
L_80004904:
    // 0x80004904: beq         $t2, $zero, L_80004A8C
    if (ctx->r10 == 0) {
        // 0x80004908: sll         $t6, $a2, 2
        ctx->r14 = S32(ctx->r6 << 2);
            goto L_80004A8C;
    }
    // 0x80004908: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8000490C: addu        $v0, $t3, $t6
    ctx->r2 = ADD32(ctx->r11, ctx->r14);
    // 0x80004910: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x80004914: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80004918: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000491C: sll         $t8, $t7, 0
    ctx->r24 = S32(ctx->r15 << 0);
    // 0x80004920: bgezl       $t8, L_800049D0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80004924: lw          $a3, 0x42CC($t0)
        ctx->r7 = MEM_W(ctx->r8, 0X42CC);
            goto L_800049D0;
    }
    goto skip_0;
    // 0x80004924: lw          $a3, 0x42CC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X42CC);
    skip_0:
    // 0x80004928: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x8000492C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80004930: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80004934: and         $t6, $t9, $t4
    ctx->r14 = ctx->r25 & ctx->r12;
    // 0x80004938: jal         0x80003F44
    // 0x8000493C: subu        $a2, $t6, $a3
    ctx->r6 = SUB32(ctx->r14, ctx->r7);
    LOOKUP_FUNC(0x80003F44)(rdram, ctx);
        goto after_0;
    // 0x8000493C: subu        $a2, $t6, $a3
    ctx->r6 = SUB32(ctx->r14, ctx->r7);
    after_0:
    // 0x80004940: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80004944: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80004948: jal         0x80028A90
    // 0x8000494C: subu        $a1, $v0, $a0
    ctx->r5 = SUB32(ctx->r2, ctx->r4);
    LOOKUP_FUNC(0x80028A90)(rdram, ctx);
        goto after_1;
    // 0x8000494C: subu        $a1, $v0, $a0
    ctx->r5 = SUB32(ctx->r2, ctx->r4);
    after_1:
    // 0x80004950: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80004954: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80004958: subu        $a1, $v1, $a0
    ctx->r5 = SUB32(ctx->r3, ctx->r4);
    // 0x8000495C: jal         0x80030640
    // 0x80004960: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80030640)(rdram, ctx);
        goto after_2;
    // 0x80004960: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x80004964: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80004968: jal         0x800306C0
    // 0x8000496C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    LOOKUP_FUNC(0x800306C0)(rdram, ctx);
        goto after_3;
    // 0x8000496C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x80004970: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80004974: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80004978: addiu       $t0, $t0, -0x6D50
    ctx->r8 = ADD32(ctx->r8, -0X6D50);
    // 0x8000497C: bne         $v1, $zero, L_800049B0
    if (ctx->r3 != 0) {
        // 0x80004980: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_800049B0;
    }
    // 0x80004980: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80004984: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x80004988: beq         $v1, $zero, L_800049A0
    if (ctx->r3 == 0) {
        // 0x8000498C: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_800049A0;
    }
    // 0x8000498C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80004990:
    // 0x80004990: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80004994: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80004998: bne         $v1, $zero, L_80004990
    if (ctx->r3 != 0) {
        // 0x8000499C: andi        $v0, $v0, 0xFF
        ctx->r2 = ctx->r2 & 0XFF;
            goto L_80004990;
    }
    // 0x8000499C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_800049A0:
    // 0x800049A0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800049A4: sb          $zero, -0x23E8($at)
    MEM_B(-0X23E8, ctx->r1) = 0;
    // 0x800049A8: b           L_80004ACC
    // 0x800049AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80004ACC;
    // 0x800049AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800049B0:
    // 0x800049B0: lw          $t7, 0x42F8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X42F8);
    // 0x800049B4: lw          $t8, 0x42BC($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X42BC);
    // 0x800049B8: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x800049BC: addiu       $t5, $t5, -0x23E8
    ctx->r13 = ADD32(ctx->r13, -0X23E8);
    // 0x800049C0: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800049C4: b           L_80004A8C
    // 0x800049C8: sw          $t9, 0x42BC($t0)
    MEM_W(0X42BC, ctx->r8) = ctx->r25;
        goto L_80004A8C;
    // 0x800049C8: sw          $t9, 0x42BC($t0)
    MEM_W(0X42BC, ctx->r8) = ctx->r25;
    // 0x800049CC: lw          $a3, 0x42CC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X42CC);
L_800049D0:
    // 0x800049D0: lw          $a2, 0x42B8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X42B8);
    // 0x800049D4: addiu       $v0, $t2, 0x1
    ctx->r2 = ADD32(ctx->r10, 0X1);
    // 0x800049D8: sltu        $at, $a3, $a2
    ctx->r1 = ctx->r7 < ctx->r6 ? 1 : 0;
    // 0x800049DC: beql        $at, $zero, L_80004A54
    if (ctx->r1 == 0) {
        // 0x800049E0: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_80004A54;
    }
    goto skip_1;
    // 0x800049E0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    skip_1:
    // 0x800049E4: lw          $a0, 0x42B0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X42B0);
    // 0x800049E8: lw          $a1, 0x42B4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X42B4);
    // 0x800049EC: jal         0x80001FE8
    // 0x800049F0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    LOOKUP_FUNC(0x80001FE8)(rdram, ctx);
        goto after_4;
    // 0x800049F0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_4:
    // 0x800049F4: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800049F8: addiu       $t0, $t0, -0x6D50
    ctx->r8 = ADD32(ctx->r8, -0X6D50);
    // 0x800049FC: lw          $a3, 0x42CC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X42CC);
    // 0x80004A00: lw          $t6, 0x42B8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X42B8);
    // 0x80004A04: lw          $t8, 0x42B0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X42B0);
    // 0x80004A08: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x80004A0C: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x80004A10: lw          $t6, 0x42B4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X42B4);
    // 0x80004A14: sw          $t7, 0x42B8($t0)
    MEM_W(0X42B8, ctx->r8) = ctx->r15;
    // 0x80004A18: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x80004A1C: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80004A20: sw          $t9, 0x42B0($t0)
    MEM_W(0X42B0, ctx->r8) = ctx->r25;
    // 0x80004A24: sw          $t7, 0x42B4($t0)
    MEM_W(0X42B4, ctx->r8) = ctx->r15;
    // 0x80004A28: beq         $v1, $zero, L_80004A40
    if (ctx->r3 == 0) {
        // 0x80004A2C: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80004A40;
    }
    // 0x80004A2C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80004A30:
    // 0x80004A30: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80004A34: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80004A38: bne         $v1, $zero, L_80004A30
    if (ctx->r3 != 0) {
        // 0x80004A3C: andi        $v0, $v0, 0xFF
        ctx->r2 = ctx->r2 & 0XFF;
            goto L_80004A30;
    }
    // 0x80004A3C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80004A40:
    // 0x80004A40: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80004A44: sb          $zero, -0x23E8($at)
    MEM_B(-0X23E8, ctx->r1) = 0;
    // 0x80004A48: b           L_80004ACC
    // 0x80004A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80004ACC;
    // 0x80004A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80004A50: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
L_80004A54:
    // 0x80004A54: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x80004A58: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80004A5C: lw          $a0, 0x42B0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X42B0);
    // 0x80004A60: lw          $a1, 0x42B4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X42B4);
    // 0x80004A64: jal         0x80001FE8
    // 0x80004A68: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80001FE8)(rdram, ctx);
        goto after_5;
    // 0x80004A68: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_5:
    // 0x80004A6C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80004A70: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80004A74: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80004A78: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80004A7C: addiu       $t0, $t0, -0x6D50
    ctx->r8 = ADD32(ctx->r8, -0X6D50);
    // 0x80004A80: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80004A84: addiu       $t5, $t5, -0x23E8
    ctx->r13 = ADD32(ctx->r13, -0X23E8);
    // 0x80004A88: addu        $v1, $t8, $v0
    ctx->r3 = ADD32(ctx->r24, ctx->r2);
L_80004A8C:
    // 0x80004A8C: sltu        $at, $v1, $t1
    ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
    // 0x80004A90: beq         $at, $zero, L_80004AA8
    if (ctx->r1 == 0) {
        // 0x80004A94: sb          $zero, 0x42AD($t0)
        MEM_B(0X42AD, ctx->r8) = 0;
            goto L_80004AA8;
    }
    // 0x80004A94: sb          $zero, 0x42AD($t0)
    MEM_B(0X42AD, ctx->r8) = 0;
L_80004A98:
    // 0x80004A98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80004A9C: sltu        $at, $v1, $t1
    ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
    // 0x80004AA0: bne         $at, $zero, L_80004A98
    if (ctx->r1 != 0) {
        // 0x80004AA4: sb          $zero, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = 0;
            goto L_80004A98;
    }
    // 0x80004AA4: sb          $zero, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = 0;
L_80004AA8:
    // 0x80004AA8: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x80004AAC: beq         $v1, $zero, L_80004AC4
    if (ctx->r3 == 0) {
        // 0x80004AB0: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80004AC4;
    }
    // 0x80004AB0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80004AB4:
    // 0x80004AB4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80004AB8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80004ABC: bne         $v1, $zero, L_80004AB4
    if (ctx->r3 != 0) {
        // 0x80004AC0: andi        $v0, $v0, 0xFF
        ctx->r2 = ctx->r2 & 0XFF;
            goto L_80004AB4;
    }
    // 0x80004AC0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80004AC4:
    // 0x80004AC4: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x80004AC8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80004ACC:
    // 0x80004ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004AD0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80004AD4: jr          $ra
    // 0x80004AD8: nop

    return;
    // 0x80004AD8: nop

;}
RECOMP_FUNC void FUN_80004adc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004ADC: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x80004AE0: lhu         $t7, 0x7A30($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X7A30);
    // 0x80004AE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80004AE8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80004AEC: andi        $a3, $a0, 0xFFFF
    ctx->r7 = ctx->r4 & 0XFFFF;
    // 0x80004AF0: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80004AF4: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80004AF8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80004AFC: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
    // 0x80004B00: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80004B04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80004B08: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80004B0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004B10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004B14: lw          $s1, 0x29B8($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X29B8);
    // 0x80004B18: bne         $at, $zero, L_80004B54
    if (ctx->r1 != 0) {
        // 0x80004B1C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80004B54;
    }
    // 0x80004B1C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80004B20: lui         $t9, 0x8003
    ctx->r25 = S32(0X8003 << 16);
    // 0x80004B24: addiu       $t9, $t9, 0x7A30
    ctx->r25 = ADD32(ctx->r25, 0X7A30);
    // 0x80004B28: sll         $t8, $zero, 1
    ctx->r24 = S32(0 << 1);
    // 0x80004B2C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80004B30: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
L_80004B34:
    // 0x80004B34: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80004B38: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80004B3C: bne         $v1, $zero, L_80004B4C
    if (ctx->r3 != 0) {
        // 0x80004B40: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80004B4C;
    }
    // 0x80004B40: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80004B44: b           L_80004B98
    // 0x80004B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80004B98;
    // 0x80004B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80004B4C:
    // 0x80004B4C: beql        $at, $zero, L_80004B34
    if (ctx->r1 == 0) {
        // 0x80004B50: lhu         $v1, 0x4($v0)
        ctx->r3 = MEM_HU(ctx->r2, 0X4);
            goto L_80004B34;
    }
    goto skip_0;
    // 0x80004B50: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    skip_0:
L_80004B54:
    // 0x80004B54: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x80004B58: lui         $t1, 0x8003
    ctx->r9 = S32(0X8003 << 16);
    // 0x80004B5C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80004B60: lhu         $t1, 0x7A32($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X7A32);
    // 0x80004B64: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80004B68: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x80004B6C: beq         $s0, $zero, L_80004B94
    if (ctx->r16 == 0) {
        // 0x80004B70: subu        $s2, $a1, $t2
        ctx->r18 = SUB32(ctx->r5, ctx->r10);
            goto L_80004B94;
    }
    // 0x80004B70: subu        $s2, $a1, $t2
    ctx->r18 = SUB32(ctx->r5, ctx->r10);
    // 0x80004B74: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
L_80004B78:
    // 0x80004B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004B7C: jal         0x80004D20
    // 0x80004B80: addu        $a1, $t3, $s2
    ctx->r5 = ADD32(ctx->r11, ctx->r18);
    LOOKUP_FUNC(0x80004D20)(rdram, ctx);
        goto after_0;
    // 0x80004B80: addu        $a1, $t3, $s2
    ctx->r5 = ADD32(ctx->r11, ctx->r18);
    after_0:
    // 0x80004B84: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
    // 0x80004B88: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80004B8C: bnel        $s0, $zero, L_80004B78
    if (ctx->r16 != 0) {
        // 0x80004B90: lw          $t3, 0x4($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X4);
            goto L_80004B78;
    }
    goto skip_1;
    // 0x80004B90: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    skip_1:
L_80004B94:
    // 0x80004B94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80004B98:
    // 0x80004B98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80004B9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004BA0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80004BA4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80004BA8: jr          $ra
    // 0x80004BAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80004BAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80004bb0(rdram, ctx);
;}
RECOMP_FUNC void FUN_80004bb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004BB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80004BB4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80004BB8: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x80004BBC: addiu       $s1, $s1, -0x6D50
    ctx->r17 = ADD32(ctx->r17, -0X6D50);
    // 0x80004BC0: lbu         $t0, 0x42C8($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X42C8);
    // 0x80004BC4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80004BC8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004BCC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80004BD0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80004BD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004BD8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80004BDC: andi        $a3, $a0, 0xFFFF
    ctx->r7 = ctx->r4 & 0XFFFF;
    // 0x80004BE0: bne         $t0, $zero, L_80004BFC
    if (ctx->r8 != 0) {
        // 0x80004BE4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80004BFC;
    }
    // 0x80004BE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004BE8: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80004BEC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80004BF0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80004BF4: lw          $t7, 0x29B8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X29B8);
    // 0x80004BF8: sw          $t7, 0x42F4($s1)
    MEM_W(0X42F4, ctx->r17) = ctx->r15;
L_80004BFC:
    // 0x80004BFC: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x80004C00: lhu         $t8, 0x7A30($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X7A30);
    // 0x80004C04: lui         $s4, 0x8003
    ctx->r20 = S32(0X8003 << 16);
    // 0x80004C08: addiu       $s4, $s4, 0x7744
    ctx->r20 = ADD32(ctx->r20, 0X7744);
    // 0x80004C0C: slt         $at, $a3, $t8
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80004C10: bne         $at, $zero, L_80004C4C
    if (ctx->r1 != 0) {
        // 0x80004C14: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80004C4C;
    }
    // 0x80004C14: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80004C18: lui         $t1, 0x8003
    ctx->r9 = S32(0X8003 << 16);
    // 0x80004C1C: addiu       $t1, $t1, 0x7A30
    ctx->r9 = ADD32(ctx->r9, 0X7A30);
    // 0x80004C20: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x80004C24: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x80004C28: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
L_80004C2C:
    // 0x80004C2C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80004C30: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80004C34: bne         $v1, $zero, L_80004C44
    if (ctx->r3 != 0) {
        // 0x80004C38: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80004C44;
    }
    // 0x80004C38: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80004C3C: b           L_80004D00
    // 0x80004C40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80004D00;
    // 0x80004C40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80004C44:
    // 0x80004C44: beql        $at, $zero, L_80004C2C
    if (ctx->r1 == 0) {
        // 0x80004C48: lhu         $v1, 0x4($v0)
        ctx->r3 = MEM_HU(ctx->r2, 0X4);
            goto L_80004C2C;
    }
    goto skip_0;
    // 0x80004C48: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    skip_0:
L_80004C4C:
    // 0x80004C4C: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x80004C50: lui         $t3, 0x8003
    ctx->r11 = S32(0X8003 << 16);
    // 0x80004C54: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80004C58: lhu         $t3, 0x7A32($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X7A32);
    // 0x80004C5C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80004C60: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x80004C64: bne         $t0, $zero, L_80004C70
    if (ctx->r8 != 0) {
        // 0x80004C68: subu        $s3, $a1, $t4
        ctx->r19 = SUB32(ctx->r5, ctx->r12);
            goto L_80004C70;
    }
    // 0x80004C68: subu        $s3, $a1, $t4
    ctx->r19 = SUB32(ctx->r5, ctx->r12);
    // 0x80004C6C: sb          $t5, 0x42C8($s1)
    MEM_B(0X42C8, ctx->r17) = ctx->r13;
L_80004C70:
    // 0x80004C70: lw          $v0, 0x42F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X42F4);
    // 0x80004C74: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80004C78: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80004C7C: beq         $s0, $zero, L_80004CDC
    if (ctx->r16 == 0) {
        // 0x80004C80: addu        $s2, $v1, $s3
        ctx->r18 = ADD32(ctx->r3, ctx->r19);
            goto L_80004CDC;
    }
    // 0x80004C80: addu        $s2, $v1, $s3
    ctx->r18 = ADD32(ctx->r3, ctx->r19);
    // 0x80004C84: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
L_80004C88:
    // 0x80004C88: lw          $t9, 0x42BC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X42BC);
    // 0x80004C8C: lw          $t7, 0x42CC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X42CC);
    // 0x80004C90: addu        $v1, $t6, $s3
    ctx->r3 = ADD32(ctx->r14, ctx->r19);
    // 0x80004C94: subu        $t8, $v1, $s2
    ctx->r24 = SUB32(ctx->r3, ctx->r18);
    // 0x80004C98: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80004C9C: sltu        $at, $t7, $t1
    ctx->r1 = ctx->r15 < ctx->r9 ? 1 : 0;
    // 0x80004CA0: beq         $at, $zero, L_80004CB4
    if (ctx->r1 == 0) {
        // 0x80004CA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80004CB4;
    }
    // 0x80004CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004CA8: sw          $zero, 0x42BC($s1)
    MEM_W(0X42BC, ctx->r17) = 0;
    // 0x80004CAC: b           L_80004D00
    // 0x80004CB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80004D00;
    // 0x80004CB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80004CB4:
    // 0x80004CB4: jal         0x80004D20
    // 0x80004CB8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80004D20)(rdram, ctx);
        goto after_0;
    // 0x80004CB8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_0:
    // 0x80004CBC: lw          $t2, 0x42F4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X42F4);
    // 0x80004CC0: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80004CC4: sw          $t3, 0x42F4($s1)
    MEM_W(0X42F4, ctx->r17) = ctx->r11;
    // 0x80004CC8: lw          $s0, 0x0($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X0);
    // 0x80004CCC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80004CD0: bnel        $s0, $zero, L_80004C88
    if (ctx->r16 != 0) {
        // 0x80004CD4: lw          $t6, 0x4($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X4);
            goto L_80004C88;
    }
    goto skip_1;
    // 0x80004CD4: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x80004CD8: lw          $v1, 0x4($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X4);
L_80004CDC:
    // 0x80004CDC: lw          $t4, 0x42D0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X42D0);
    // 0x80004CE0: lw          $t9, 0x42BC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X42BC);
    // 0x80004CE4: sb          $zero, 0x42C8($s1)
    MEM_B(0X42C8, ctx->r17) = 0;
    // 0x80004CE8: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80004CEC: addu        $t6, $t5, $s3
    ctx->r14 = ADD32(ctx->r13, ctx->r19);
    // 0x80004CF0: subu        $t8, $t6, $s2
    ctx->r24 = SUB32(ctx->r14, ctx->r18);
    // 0x80004CF4: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x80004CF8: sw          $t7, 0x42D0($s1)
    MEM_W(0X42D0, ctx->r17) = ctx->r15;
    // 0x80004CFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80004D00:
    // 0x80004D00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80004D04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004D08: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80004D0C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80004D10: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80004D14: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80004D18: jr          $ra
    // 0x80004D1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80004D1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80004d20(rdram, ctx);
;}
RECOMP_FUNC void FUN_80004d20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004D20: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80004D24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80004D28: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80004D2C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80004D30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004D34: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80004D38: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80004D3C: jal         0x80004F98
    // 0x80004D40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80004F98)(rdram, ctx);
        goto after_0;
    // 0x80004D40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80004D44: sltiu       $at, $v0, 0x2001
    ctx->r1 = ctx->r2 < 0X2001 ? 1 : 0;
    // 0x80004D48: beq         $at, $zero, L_80004D6C
    if (ctx->r1 == 0) {
        // 0x80004D4C: lw          $a2, 0x60($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X60);
            goto L_80004D6C;
    }
    // 0x80004D4C: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x80004D50: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    // 0x80004D54: jal         0x8001F290
    // 0x80004D58: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_1;
    // 0x80004D58: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    after_1:
    // 0x80004D5C: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x80004D60: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80004D64: b           L_80004DE8
    // 0x80004D68: sb          $zero, 0x67($sp)
    MEM_B(0X67, ctx->r29) = 0;
        goto L_80004DE8;
    // 0x80004D68: sb          $zero, 0x67($sp)
    MEM_B(0X67, ctx->r29) = 0;
L_80004D6C:
    // 0x80004D6C: jal         0x80001060
    // 0x80004D70: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_2;
    // 0x80004D70: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    after_2:
    // 0x80004D74: beq         $v0, $zero, L_80004D98
    if (ctx->r2 == 0) {
        // 0x80004D78: lw          $a2, 0x60($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X60);
            goto L_80004D98;
    }
    // 0x80004D78: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x80004D7C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80004D80: lh          $t6, -0x6CB0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6CB0);
    // 0x80004D84: lui         $t8, 0x8040
    ctx->r24 = S32(0X8040 << 16);
    // 0x80004D88: addiu       $t8, $t8, 0x0
    ctx->r24 = ADD32(ctx->r24, 0X0);
    // 0x80004D8C: sll         $t7, $t6, 20
    ctx->r15 = S32(ctx->r14 << 20);
    // 0x80004D90: b           L_80004DC8
    // 0x80004D94: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
        goto L_80004DC8;
    // 0x80004D94: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
L_80004D98:
    // 0x80004D98: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80004D9C: lh          $t9, -0x6CB0($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X6CB0);
    // 0x80004DA0: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80004DA4: addiu       $t1, $t1, -0x800
    ctx->r9 = ADD32(ctx->r9, -0X800);
    // 0x80004DA8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80004DAC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80004DB0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80004DB4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80004DB8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80004DBC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80004DC0: sll         $t0, $t0, 11
    ctx->r8 = S32(ctx->r8 << 11);
    // 0x80004DC4: addu        $s0, $t0, $t1
    ctx->r16 = ADD32(ctx->r8, ctx->r9);
L_80004DC8:
    // 0x80004DC8: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80004DCC: lh          $t3, -0x6CAC($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X6CAC);
    // 0x80004DD0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80004DD4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80004DD8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80004DDC: sb          $t2, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r10;
    // 0x80004DE0: sh          $t4, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = ctx->r12;
    // 0x80004DE4: sh          $t3, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r11;
L_80004DE8:
    // 0x80004DE8: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80004DEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80004DF0: jal         0x80004EE8
    // 0x80004DF4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80004EE8)(rdram, ctx);
        goto after_3;
    // 0x80004DF4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    after_3:
    // 0x80004DF8: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x80004DFC: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x80004E00: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x80004E04: bne         $t5, $at, L_80004E58
    if (ctx->r13 != ctx->r1) {
        // 0x80004E08: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80004E58;
    }
    // 0x80004E08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80004E0C: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x80004E10: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80004E14: bne         $t6, $at, L_80004E58
    if (ctx->r14 != ctx->r1) {
        // 0x80004E18: nop
    
            goto L_80004E58;
    }
    // 0x80004E18: nop

    // 0x80004E1C: lbu         $t7, 0x2($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2);
    // 0x80004E20: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80004E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004E28: bne         $t7, $at, L_80004E58
    if (ctx->r15 != ctx->r1) {
        // 0x80004E2C: nop
    
            goto L_80004E58;
    }
    // 0x80004E2C: nop

    // 0x80004E30: jal         0x80015420
    // 0x80004E34: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80015420)(rdram, ctx);
        goto after_4;
    // 0x80004E34: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x80004E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004E3C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80004E40: jal         0x80015488
    // 0x80004E44: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    LOOKUP_FUNC(0x80015488)(rdram, ctx);
        goto after_5;
    // 0x80004E44: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x80004E48: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80004E4C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80004E50: b           L_80004E84
    // 0x80004E54: addu        $a2, $a0, $t8
    ctx->r6 = ADD32(ctx->r4, ctx->r24);
        goto L_80004E84;
    // 0x80004E54: addu        $a2, $a0, $t8
    ctx->r6 = ADD32(ctx->r4, ctx->r24);
L_80004E58:
    // 0x80004E58: beq         $v0, $s0, L_80004E84
    if (ctx->r2 == ctx->r16) {
        // 0x80004E5C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80004E84;
    }
    // 0x80004E5C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80004E60: subu        $a0, $a1, $s0
    ctx->r4 = SUB32(ctx->r5, ctx->r16);
    // 0x80004E64: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80004E68:
    // 0x80004E68: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80004E6C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80004E70: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80004E74: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80004E78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80004E7C: bne         $at, $zero, L_80004E68
    if (ctx->r1 != 0) {
        // 0x80004E80: sb          $t0, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r8;
            goto L_80004E68;
    }
    // 0x80004E80: sb          $t0, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r8;
L_80004E84:
    // 0x80004E84: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80004E88: subu        $a1, $a2, $a0
    ctx->r5 = SUB32(ctx->r6, ctx->r4);
    // 0x80004E8C: jal         0x80028A90
    // 0x80004E90: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80028A90)(rdram, ctx);
        goto after_6;
    // 0x80004E90: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_6:
    // 0x80004E94: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80004E98: jal         0x80030640
    // 0x80004E9C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80030640)(rdram, ctx);
        goto after_7;
    // 0x80004E9C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80004EA0: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80004EA4: jal         0x800306C0
    // 0x80004EA8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800306C0)(rdram, ctx);
        goto after_8;
    // 0x80004EA8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x80004EAC: lbu         $t1, 0x67($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X67);
    // 0x80004EB0: lh          $t2, 0x32($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X32);
    // 0x80004EB4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80004EB8: bne         $t1, $zero, L_80004ED0
    if (ctx->r9 != 0) {
        // 0x80004EBC: nop
    
            goto L_80004ED0;
    }
    // 0x80004EBC: nop

    // 0x80004EC0: jal         0x8001F540
    // 0x80004EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_9;
    // 0x80004EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80004EC8: b           L_80004ED8
    // 0x80004ECC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80004ED8;
    // 0x80004ECC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80004ED0:
    // 0x80004ED0: sh          $t2, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = ctx->r10;
    // 0x80004ED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80004ED8:
    // 0x80004ED8: lbu         $v0, 0x67($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X67);
    // 0x80004EDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004EE0: jr          $ra
    // 0x80004EE4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80004EE4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80004ee8(rdram, ctx);
;}
RECOMP_FUNC void FUN_80004ee8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004EE8: ori         $at, $zero, 0x8B8A
    ctx->r1 = 0 | 0X8B8A;
    // 0x80004EEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80004EF0: sltu        $at, $a0, $at
    ctx->r1 = ctx->r4 < ctx->r1 ? 1 : 0;
    // 0x80004EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004EF8: bne         $at, $zero, L_80004F08
    if (ctx->r1 != 0) {
        // 0x80004EFC: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80004F08;
    }
    // 0x80004EFC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80004F00: b           L_80004F88
    // 0x80004F04: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80004F88;
    // 0x80004F04: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80004F08:
    // 0x80004F08: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80004F0C: sltu        $at, $a0, $at
    ctx->r1 = ctx->r4 < ctx->r1 ? 1 : 0;
    // 0x80004F10: bne         $at, $zero, L_80004F80
    if (ctx->r1 != 0) {
        // 0x80004F14: addiu       $a1, $sp, 0x2C
        ctx->r5 = ADD32(ctx->r29, 0X2C);
            goto L_80004F80;
    }
    // 0x80004F14: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80004F18: jal         0x80004F98
    // 0x80004F1C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80004F98)(rdram, ctx);
        goto after_0;
    // 0x80004F1C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x80004F20: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80004F24: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80004F28: beq         $v0, $zero, L_80004F78
    if (ctx->r2 == 0) {
        // 0x80004F2C: addu        $t0, $a3, $v0
        ctx->r8 = ADD32(ctx->r7, ctx->r2);
            goto L_80004F78;
    }
    // 0x80004F2C: addu        $t0, $a3, $v0
    ctx->r8 = ADD32(ctx->r7, ctx->r2);
    // 0x80004F30: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80004F34: addiu       $v0, $v0, -0x23E8
    ctx->r2 = ADD32(ctx->r2, -0X23E8);
    // 0x80004F38: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80004F3C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x80004F40: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80004F44: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80004F48: jal         0x80001FE8
    // 0x80004F4C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80001FE8)(rdram, ctx);
        goto after_1;
    // 0x80004F4C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_1:
    // 0x80004F50: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x80004F54: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80004F58: beq         $v1, $zero, L_80004F70
    if (ctx->r3 == 0) {
        // 0x80004F5C: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80004F70;
    }
    // 0x80004F5C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80004F60:
    // 0x80004F60: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80004F64: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80004F68: bne         $v1, $zero, L_80004F60
    if (ctx->r3 != 0) {
        // 0x80004F6C: andi        $v0, $v0, 0xFF
        ctx->r2 = ctx->r2 & 0XFF;
            goto L_80004F60;
    }
    // 0x80004F6C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80004F70:
    // 0x80004F70: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80004F74: sb          $zero, -0x23E8($at)
    MEM_B(-0X23E8, ctx->r1) = 0;
L_80004F78:
    // 0x80004F78: b           L_80004F88
    // 0x80004F7C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80004F88;
    // 0x80004F7C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80004F80:
    // 0x80004F80: jal         0x8000469C
    // 0x80004F84: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    LOOKUP_FUNC(0x8000469C)(rdram, ctx);
        goto after_2;
    // 0x80004F84: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
L_80004F88:
    // 0x80004F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004F8C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80004F90: jr          $ra
    // 0x80004F94: nop

    return;
    // 0x80004F94: nop

;}
RECOMP_FUNC void FUN_80004f98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004F98: ori         $at, $zero, 0x8B8A
    ctx->r1 = 0 | 0X8B8A;
    // 0x80004F9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80004FA0: sltu        $at, $a0, $at
    ctx->r1 = ctx->r4 < ctx->r1 ? 1 : 0;
    // 0x80004FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004FA8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80004FAC: bne         $at, $zero, L_80004FC8
    if (ctx->r1 != 0) {
        // 0x80004FB0: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80004FC8;
    }
    // 0x80004FB0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80004FB4: beq         $a1, $zero, L_80004FC0
    if (ctx->r5 == 0) {
        // 0x80004FB8: nop
    
            goto L_80004FC0;
    }
    // 0x80004FB8: nop

    // 0x80004FBC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80004FC0:
    // 0x80004FC0: b           L_8000510C
    // 0x80004FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000510C;
    // 0x80004FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80004FC8:
    // 0x80004FC8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80004FCC: sltu        $at, $a2, $at
    ctx->r1 = ctx->r6 < ctx->r1 ? 1 : 0;
    // 0x80004FD0: bne         $at, $zero, L_800050D0
    if (ctx->r1 != 0) {
        // 0x80004FD4: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_800050D0;
    }
    // 0x80004FD4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80004FD8: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80004FDC: addiu       $a3, $a3, -0x6648
    ctx->r7 = ADD32(ctx->r7, -0X6648);
    // 0x80004FE0: lhu         $t7, 0x0($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X0);
    // 0x80004FE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80004FE8: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80004FEC: beql        $t7, $zero, L_8000502C
    if (ctx->r15 == 0) {
        // 0x80004FF0: addiu       $a1, $a1, -0x2
        ctx->r5 = ADD32(ctx->r5, -0X2);
            goto L_8000502C;
    }
    goto skip_0;
    // 0x80004FF0: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    skip_0:
    // 0x80004FF4: lhu         $t8, -0x6648($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X6648);
    // 0x80004FF8: sll         $t9, $zero, 1
    ctx->r25 = S32(0 << 1);
    // 0x80004FFC: addu        $v1, $a3, $t9
    ctx->r3 = ADD32(ctx->r7, ctx->r25);
    // 0x80005000: sltu        $at, $a2, $t8
    ctx->r1 = ctx->r6 < ctx->r24 ? 1 : 0;
    // 0x80005004: bnel        $at, $zero, L_8000502C
    if (ctx->r1 != 0) {
        // 0x80005008: addiu       $a1, $a1, -0x2
        ctx->r5 = ADD32(ctx->r5, -0X2);
            goto L_8000502C;
    }
    goto skip_1;
    // 0x80005008: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    skip_1:
    // 0x8000500C: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
L_80005010:
    // 0x80005010: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80005014: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80005018: beq         $v0, $zero, L_80005028
    if (ctx->r2 == 0) {
        // 0x8000501C: sltu        $at, $a2, $v0
        ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
            goto L_80005028;
    }
    // 0x8000501C: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x80005020: beql        $at, $zero, L_80005010
    if (ctx->r1 == 0) {
        // 0x80005024: lhu         $v0, 0x4($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X4);
            goto L_80005010;
    }
    goto skip_2;
    // 0x80005024: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    skip_2:
L_80005028:
    // 0x80005028: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
L_8000502C:
    // 0x8000502C: sll         $t1, $a1, 1
    ctx->r9 = S32(ctx->r5 << 1);
    // 0x80005030: addu        $v1, $a3, $t1
    ctx->r3 = ADD32(ctx->r7, ctx->r9);
    // 0x80005034: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x80005038: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8000503C: jal         0x8000511C
    // 0x80005040: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8000511C)(rdram, ctx);
        goto after_0;
    // 0x80005040: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80005044: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80005048: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8000504C: jal         0x80005144
    // 0x80005050: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    LOOKUP_FUNC(0x80005144)(rdram, ctx);
        goto after_1;
    // 0x80005050: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    after_1:
    // 0x80005054: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80005058: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x8000505C: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80005060: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80005064: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x80005068: addiu       $t4, $t4, -0x6588
    ctx->r12 = ADD32(ctx->r12, -0X6588);
    // 0x8000506C: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80005070: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80005074: lw          $a3, 0x4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X4);
    // 0x80005078: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000507C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80005080: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80005084: and         $t5, $a1, $at
    ctx->r13 = ctx->r5 & ctx->r1;
    // 0x80005088: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8000508C: beq         $a3, $zero, L_800050B4
    if (ctx->r7 == 0) {
        // 0x80005090: addu        $t0, $t5, $t6
        ctx->r8 = ADD32(ctx->r13, ctx->r14);
            goto L_800050B4;
    }
    // 0x80005090: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x80005094: lhu         $a0, 0x4($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X4);
    // 0x80005098: addiu       $t7, $a2, 0x1
    ctx->r15 = ADD32(ctx->r6, 0X1);
    // 0x8000509C: beq         $a0, $zero, L_800050AC
    if (ctx->r4 == 0) {
        // 0x800050A0: sltu        $at, $t7, $a0
        ctx->r1 = ctx->r15 < ctx->r4 ? 1 : 0;
            goto L_800050AC;
    }
    // 0x800050A0: sltu        $at, $t7, $a0
    ctx->r1 = ctx->r15 < ctx->r4 ? 1 : 0;
    // 0x800050A4: beql        $at, $zero, L_800050B8
    if (ctx->r1 == 0) {
        // 0x800050A8: subu        $v1, $v0, $t0
        ctx->r3 = SUB32(ctx->r2, ctx->r8);
            goto L_800050B8;
    }
    goto skip_3;
    // 0x800050A8: subu        $v1, $v0, $t0
    ctx->r3 = SUB32(ctx->r2, ctx->r8);
    skip_3:
L_800050AC:
    // 0x800050AC: b           L_800050B8
    // 0x800050B0: subu        $v1, $a3, $a1
    ctx->r3 = SUB32(ctx->r7, ctx->r5);
        goto L_800050B8;
    // 0x800050B0: subu        $v1, $a3, $a1
    ctx->r3 = SUB32(ctx->r7, ctx->r5);
L_800050B4:
    // 0x800050B4: subu        $v1, $v0, $t0
    ctx->r3 = SUB32(ctx->r2, ctx->r8);
L_800050B8:
    // 0x800050B8: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800050BC: beq         $v0, $zero, L_800050C8
    if (ctx->r2 == 0) {
        // 0x800050C0: nop
    
            goto L_800050C8;
    }
    // 0x800050C0: nop

    // 0x800050C4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_800050C8:
    // 0x800050C8: b           L_8000510C
    // 0x800050CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8000510C;
    // 0x800050CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800050D0:
    // 0x800050D0: beq         $t8, $zero, L_800050EC
    if (ctx->r24 == 0) {
        // 0x800050D4: andi        $a0, $a2, 0xFFFF
        ctx->r4 = ctx->r6 & 0XFFFF;
            goto L_800050EC;
    }
    // 0x800050D4: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x800050D8: jal         0x8000511C
    // 0x800050DC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8000511C)(rdram, ctx);
        goto after_2;
    // 0x800050DC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_2:
    // 0x800050E0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800050E4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800050E8: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
L_800050EC:
    // 0x800050EC: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x800050F0: jal         0x80005144
    // 0x800050F4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80005144)(rdram, ctx);
        goto after_3;
    // 0x800050F4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_3:
    // 0x800050F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800050FC: jal         0x8000511C
    // 0x80005100: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8000511C)(rdram, ctx);
        goto after_4;
    // 0x80005100: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_4:
    // 0x80005104: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80005108: subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
L_8000510C:
    // 0x8000510C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005110: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80005114: jr          $ra
    // 0x80005118: nop

    return;
    // 0x80005118: nop

;}
RECOMP_FUNC void FUN_8000511c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000511C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80005120: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80005124: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80005128: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000512C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80005130: lw          $v0, -0x7014($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7014);
    // 0x80005134: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x80005138: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000513C: jr          $ra
    // 0x80005140: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    return;
    // 0x80005140: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80005144(rdram, ctx);
;}
RECOMP_FUNC void FUN_80005144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005144: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80005148: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8000514C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80005150: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80005154: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80005158: lw          $t7, -0x7010($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7010);
    // 0x8000515C: lui         $v1, 0x7FFF
    ctx->r3 = S32(0X7FFF << 16);
    // 0x80005160: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80005164: and         $t8, $t7, $v1
    ctx->r24 = ctx->r15 & ctx->r3;
    // 0x80005168: jr          $ra
    // 0x8000516C: and         $v0, $t8, $v1
    ctx->r2 = ctx->r24 & ctx->r3;
    return;
    // 0x8000516C: and         $v0, $t8, $v1
    ctx->r2 = ctx->r24 & ctx->r3;
    // 0x80005170: bne         $a0, $zero, L_80005180
    if (ctx->r4 != 0) {
        // 0x80005174: sll         $t7, $a0, 3
        ctx->r15 = S32(ctx->r4 << 3);
            goto L_80005180;
    }
    // 0x80005174: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x80005178: jr          $ra
    // 0x8000517C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000517C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80005180:
    // 0x80005180: lui         $t9, 0x8003
    ctx->r25 = S32(0X8003 << 16);
    // 0x80005184: addiu       $t9, $t9, 0x7C5C
    ctx->r25 = ADD32(ctx->r25, 0X7C5C);
    // 0x80005188: addiu       $t8, $t7, -0x8
    ctx->r24 = ADD32(ctx->r15, -0X8);
    // 0x8000518C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80005190: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x80005194: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80005198: subu        $v0, $t0, $t1
    ctx->r2 = SUB32(ctx->r8, ctx->r9);
    // 0x8000519C: jr          $ra
    // 0x800051A0: nop

    return;
    // 0x800051A0: nop

    // 0x800051A4: bne         $a0, $zero, L_800051B4
    if (ctx->r4 != 0) {
        // 0x800051A8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800051B4;
    }
    // 0x800051A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800051AC: jr          $ra
    // 0x800051B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800051B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800051B4:
    // 0x800051B4: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x800051B8: lhu         $t6, 0x7A30($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X7A30);
    // 0x800051BC: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x800051C0: addiu       $t8, $t8, 0x7A30
    ctx->r24 = ADD32(ctx->r24, 0X7A30);
    // 0x800051C4: beq         $t6, $zero, L_800051F8
    if (ctx->r14 == 0) {
        // 0x800051C8: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_800051F8;
    }
    // 0x800051C8: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800051CC: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800051D0: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x800051D4: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
L_800051D8:
    // 0x800051D8: beql        $at, $zero, L_800051EC
    if (ctx->r1 == 0) {
        // 0x800051DC: lhu         $a1, 0x4($v1)
        ctx->r5 = MEM_HU(ctx->r3, 0X4);
            goto L_800051EC;
    }
    goto skip_0;
    // 0x800051DC: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x800051E0: jr          $ra
    // 0x800051E4: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    return;
    // 0x800051E4: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x800051E8: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
L_800051EC:
    // 0x800051EC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800051F0: bnel        $a1, $zero, L_800051D8
    if (ctx->r5 != 0) {
        // 0x800051F4: sltu        $at, $a0, $a1
        ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
            goto L_800051D8;
    }
    goto skip_1;
    // 0x800051F4: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    skip_1:
L_800051F8:
    // 0x800051F8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800051FC: jr          $ra
    // 0x80005200: nop

    return;
    // 0x80005200: nop

;}
RECOMP_FUNC void FUN_80005204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000520C: jal         0x80017064
    // 0x80005210: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_0;
    // 0x80005210: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80005214: jal         0x8001703C
    // 0x80005218: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x8001703C)(rdram, ctx);
        goto after_1;
    // 0x80005218: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8000521C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005224: jr          $ra
    // 0x80005228: nop

    return;
    // 0x80005228: nop

;}
RECOMP_FUNC void FUN_8000522c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000522C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005234: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80005238: jal         0x80017064
    // 0x8000523C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x80017064)(rdram, ctx);
        goto after_0;
    // 0x8000523C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80005240: jal         0x8001703C
    // 0x80005244: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x8001703C)(rdram, ctx);
        goto after_1;
    // 0x80005244: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80005248: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000524C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005250: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80005254: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80005258: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8000525C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80005260: jr          $ra
    // 0x80005264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80005264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005268: nop

    // 0x8000526C: nop

    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80005270(rdram, ctx);
;}
RECOMP_FUNC void FUN_80005270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005270: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80005274: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80005278: lui         $fp, 0x8009
    ctx->r30 = S32(0X8009 << 16);
    // 0x8000527C: addiu       $fp, $fp, -0x6D50
    ctx->r30 = ADD32(ctx->r30, -0X6D50);
    // 0x80005280: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005284: lw          $s0, 0xC8($fp)
    ctx->r16 = MEM_W(ctx->r30, 0XC8);
    // 0x80005288: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000528C: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x80005290: addiu       $s1, $s1, -0x2A2C
    ctx->r17 = ADD32(ctx->r17, -0X2A2C);
    // 0x80005294: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80005298: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000529C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800052A0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800052A4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800052A8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800052AC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800052B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800052B4: sb          $zero, 0x1BC($fp)
    MEM_B(0X1BC, ctx->r30) = 0;
    // 0x800052B8: beq         $s0, $zero, L_80005414
    if (ctx->r16 == 0) {
        // 0x800052BC: sw          $s0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r16;
            goto L_80005414;
    }
    // 0x800052BC: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x800052C0: andi        $t7, $zero, 0xFF
    ctx->r15 = 0 & 0XFF;
    // 0x800052C4: bne         $t7, $zero, L_80005414
    if (ctx->r15 != 0) {
        // 0x800052C8: lui         $s7, 0x8009
        ctx->r23 = S32(0X8009 << 16);
            goto L_80005414;
    }
    // 0x800052C8: lui         $s7, 0x8009
    ctx->r23 = S32(0X8009 << 16);
    // 0x800052CC: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x800052D0: lui         $s4, 0x8009
    ctx->r20 = S32(0X8009 << 16);
    // 0x800052D4: addiu       $s4, $s4, -0x2A30
    ctx->r20 = ADD32(ctx->r20, -0X2A30);
    // 0x800052D8: addiu       $s6, $s6, -0x2578
    ctx->r22 = ADD32(ctx->r22, -0X2578);
    // 0x800052DC: addiu       $s7, $s7, -0x2A28
    ctx->r23 = ADD32(ctx->r23, -0X2A28);
    // 0x800052E0: lui         $s5, 0x80
    ctx->r21 = S32(0X80 << 16);
    // 0x800052E4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
L_800052E8:
    // 0x800052E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800052EC: jal         0x80006214
    // 0x800052F0: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x800052F0: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    after_0:
    // 0x800052F4: jal         0x8001F718
    // 0x800052F8: lw          $s3, 0x0($s1)
    ctx->r19 = MEM_W(ctx->r17, 0X0);
    LOOKUP_FUNC(0x8001F718)(rdram, ctx);
        goto after_1;
    // 0x800052F8: lw          $s3, 0x0($s1)
    ctx->r19 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x800052FC: beql        $v0, $zero, L_80005318
    if (ctx->r2 == 0) {
        // 0x80005300: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_80005318;
    }
    goto skip_0;
    // 0x80005300: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x80005304: jal         0x8001F76C
    // 0x80005308: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    LOOKUP_FUNC(0x8001F76C)(rdram, ctx);
        goto after_2;
    // 0x80005308: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x8000530C: bnel        $v0, $zero, L_8000538C
    if (ctx->r2 != 0) {
        // 0x80005310: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_8000538C;
    }
    goto skip_1;
    // 0x80005310: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x80005314: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80005318:
    // 0x80005318: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x8000531C: beq         $v0, $zero, L_80005338
    if (ctx->r2 == 0) {
        // 0x80005320: and         $t9, $v0, $s5
        ctx->r25 = ctx->r2 & ctx->r21;
            goto L_80005338;
    }
    // 0x80005320: and         $t9, $v0, $s5
    ctx->r25 = ctx->r2 & ctx->r21;
    // 0x80005324: bne         $t9, $zero, L_80005338
    if (ctx->r25 != 0) {
        // 0x80005328: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80005338;
    }
    // 0x80005328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000532C: jalr        $v0
    // 0x80005330: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x80005330: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_3:
    // 0x80005334: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80005338:
    // 0x80005338: bne         $s3, $s0, L_80005364
    if (ctx->r19 != ctx->r16) {
        // 0x8000533C: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80005364;
    }
    // 0x8000533C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80005340: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80005344: beq         $v0, $zero, L_80005364
    if (ctx->r2 == 0) {
        // 0x80005348: and         $t0, $v0, $s5
        ctx->r8 = ctx->r2 & ctx->r21;
            goto L_80005364;
    }
    // 0x80005348: and         $t0, $v0, $s5
    ctx->r8 = ctx->r2 & ctx->r21;
    // 0x8000534C: bne         $t0, $zero, L_80005364
    if (ctx->r8 != 0) {
        // 0x80005350: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80005364;
    }
    // 0x80005350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80005354: jalr        $v0
    // 0x80005358: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80005358: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_4:
    // 0x8000535C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80005360: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_80005364:
    // 0x80005364: bnel        $s3, $v1, L_8000538C
    if (ctx->r19 != ctx->r3) {
        // 0x80005368: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_8000538C;
    }
    goto skip_2;
    // 0x80005368: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x8000536C: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80005370: beq         $v0, $zero, L_80005388
    if (ctx->r2 == 0) {
        // 0x80005374: and         $t1, $v0, $s5
        ctx->r9 = ctx->r2 & ctx->r21;
            goto L_80005388;
    }
    // 0x80005374: and         $t1, $v0, $s5
    ctx->r9 = ctx->r2 & ctx->r21;
    // 0x80005378: bne         $t1, $zero, L_80005388
    if (ctx->r9 != 0) {
        // 0x8000537C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80005388;
    }
    // 0x8000537C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80005380: jalr        $v0
    // 0x80005384: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x80005384: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_5:
L_80005388:
    // 0x80005388: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_8000538C:
    // 0x8000538C: beql        $s0, $zero, L_800053CC
    if (ctx->r16 == 0) {
        // 0x80005390: lw          $v0, 0x0($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X0);
            goto L_800053CC;
    }
    goto skip_3;
    // 0x80005390: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    skip_3:
    // 0x80005394: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80005398: beql        $v1, $zero, L_800053CC
    if (ctx->r3 == 0) {
        // 0x8000539C: lw          $v0, 0x0($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X0);
            goto L_800053CC;
    }
    goto skip_4;
    // 0x8000539C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    skip_4:
    // 0x800053A0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800053A4: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x800053A8: addu        $t3, $s7, $t2
    ctx->r11 = ADD32(ctx->r23, ctx->r10);
    // 0x800053AC: beq         $v0, $zero, L_800053C0
    if (ctx->r2 == 0) {
        // 0x800053B0: nop
    
            goto L_800053C0;
    }
    // 0x800053B0: nop

    // 0x800053B4: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x800053B8: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800053BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800053C0:
    // 0x800053C0: b           L_800053FC
    // 0x800053C4: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
        goto L_800053FC;
    // 0x800053C4: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x800053C8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
L_800053CC:
    // 0x800053CC: bnel        $v0, $zero, L_800053FC
    if (ctx->r2 != 0) {
        // 0x800053D0: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_800053FC;
    }
    goto skip_5;
    // 0x800053D0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    skip_5:
    // 0x800053D4: beql        $s2, $zero, L_800053FC
    if (ctx->r18 == 0) {
        // 0x800053D8: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_800053FC;
    }
    goto skip_6;
    // 0x800053D8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    skip_6:
    // 0x800053DC: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x800053E0: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800053E4: addu        $t5, $s7, $t4
    ctx->r13 = ADD32(ctx->r23, ctx->r12);
    // 0x800053E8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800053EC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800053F0: b           L_800053FC
    // 0x800053F4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
        goto L_800053FC;
    // 0x800053F4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800053F8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_800053FC:
    // 0x800053FC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80005400: beql        $s0, $zero, L_80005418
    if (ctx->r16 == 0) {
        // 0x80005404: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80005418;
    }
    goto skip_7;
    // 0x80005404: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_7:
    // 0x80005408: lbu         $t7, 0x1BC($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X1BC);
    // 0x8000540C: beql        $t7, $zero, L_800052E8
    if (ctx->r15 == 0) {
        // 0x80005410: lw          $t8, 0x0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X0);
            goto L_800052E8;
    }
    goto skip_8;
    // 0x80005410: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    skip_8:
L_80005414:
    // 0x80005414: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80005418:
    // 0x80005418: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000541C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80005420: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80005424: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80005428: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000542C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80005430: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80005434: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80005438: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000543C: jr          $ra
    // 0x80005440: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80005440: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80005444(rdram, ctx);
;}
RECOMP_FUNC void FUN_80005444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005444: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80005448: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8000544C: lhu         $t0, 0x42($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X42);
    // 0x80005450: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005454: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80005458: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
    // 0x8000545C: subu        $a0, $a0, $t0
    ctx->r4 = SUB32(ctx->r4, ctx->r8);
    // 0x80005460: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80005464: subu        $a0, $a0, $t0
    ctx->r4 = SUB32(ctx->r4, ctx->r8);
    // 0x80005468: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8000546C: addiu       $s0, $s0, -0x6D50
    ctx->r16 = ADD32(ctx->r16, -0X6D50);
    // 0x80005470: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80005474: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80005478: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8000547C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80005480: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80005484: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80005488: sb          $t6, 0x1BC($s0)
    MEM_B(0X1BC, ctx->r16) = ctx->r14;
    // 0x8000548C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80005490: jal         0x8001F290
    // 0x80005494: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_0;
    // 0x80005494: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_0:
    // 0x80005498: lhu         $t7, 0x42($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X42);
    // 0x8000549C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800054A0: sw          $v0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r2;
    // 0x800054A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800054A8: lui         $t8, 0x4378
    ctx->r24 = S32(0X4378 << 16);
    // 0x800054AC: sh          $t7, 0x3398($at)
    MEM_H(0X3398, ctx->r1) = ctx->r15;
    // 0x800054B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800054B4: ori         $t8, $t8, 0x1902
    ctx->r24 = ctx->r24 | 0X1902;
    // 0x800054B8: addiu       $a0, $t0, -0x1
    ctx->r4 = ADD32(ctx->r8, -0X1);
    // 0x800054BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800054C0: sw          $t8, 0x3394($at)
    MEM_W(0X3394, ctx->r1) = ctx->r24;
    // 0x800054C4: blez        $a0, L_800054EC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800054C8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800054EC;
    }
    // 0x800054C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800054CC:
    // 0x800054CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800054D0: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800054D4: addiu       $v0, $a1, 0xB4
    ctx->r2 = ADD32(ctx->r5, 0XB4);
    // 0x800054D8: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800054DC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800054E0: bne         $at, $zero, L_800054CC
    if (ctx->r1 != 0) {
        // 0x800054E4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800054CC;
    }
    // 0x800054E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800054E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800054EC:
    // 0x800054EC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800054F0: lhu         $a2, 0x46($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X46);
    // 0x800054F4: sw          $zero, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = 0;
    // 0x800054F8: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    // 0x800054FC: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    // 0x80005500: subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    // 0x80005504: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80005508: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8000550C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80005510: jal         0x8001F290
    // 0x80005514: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_1;
    // 0x80005514: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x80005518: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8000551C: lhu         $v1, 0x3E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X3E);
    // 0x80005520: sw          $v0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r2;
    // 0x80005524: addiu       $a0, $a2, -0x1
    ctx->r4 = ADD32(ctx->r6, -0X1);
    // 0x80005528: blez        $a0, L_8000554C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000552C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000554C;
    }
    // 0x8000552C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80005530:
    // 0x80005530: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80005534: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80005538: addiu       $v0, $a1, 0x34
    ctx->r2 = ADD32(ctx->r5, 0X34);
    // 0x8000553C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80005540: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80005544: bne         $at, $zero, L_80005530
    if (ctx->r1 != 0) {
        // 0x80005548: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80005530;
    }
    // 0x80005548: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8000554C:
    // 0x8000554C: lhu         $v0, 0x4E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X4E);
    // 0x80005550: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80005554: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    // 0x80005558: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x8000555C: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80005560: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80005564: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80005568: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8000556C: sh          $v0, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r2;
    // 0x80005570: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80005574: jal         0x8001F290
    // 0x80005578: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_2;
    // 0x80005578: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    after_2:
    // 0x8000557C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80005580: sw          $v0, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->r2;
    // 0x80005584: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80005588: jal         0x8001F290
    // 0x8000558C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_3;
    // 0x8000558C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_3:
    // 0x80005590: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80005594: sw          $v0, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->r2;
    // 0x80005598: jal         0x800279F0
    // 0x8000559C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x800279F0)(rdram, ctx);
        goto after_4;
    // 0x8000559C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800055A0: lhu         $v0, 0x52($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X52);
    // 0x800055A4: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800055A8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800055AC: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x800055B0: sh          $v0, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r2;
    // 0x800055B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800055B8: jal         0x8001F290
    // 0x800055BC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_5;
    // 0x800055BC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_5:
    // 0x800055C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800055C4: sw          $v0, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->r2;
    // 0x800055C8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800055CC: jal         0x8001F290
    // 0x800055D0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_6;
    // 0x800055D0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_6:
    // 0x800055D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800055D8: sw          $v0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->r2;
    // 0x800055DC: jal         0x800279F0
    // 0x800055E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    LOOKUP_FUNC(0x800279F0)(rdram, ctx);
        goto after_7;
    // 0x800055E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x800055E4: lhu         $a0, 0x4A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4A);
    // 0x800055E8: sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4 << 6);
    // 0x800055EC: jal         0x8001F290
    // 0x800055F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_8;
    // 0x800055F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_8:
    // 0x800055F4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800055F8: sw          $v0, -0x6D10($at)
    MEM_W(-0X6D10, ctx->r1) = ctx->r2;
    // 0x800055FC: jal         0x8001F290
    // 0x80005600: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_9;
    // 0x80005600: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_9:
    // 0x80005604: lhu         $t9, 0x4A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X4A);
    // 0x80005608: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000560C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80005610: sw          $v0, -0x6CC8($at)
    MEM_W(-0X6CC8, ctx->r1) = ctx->r2;
    // 0x80005614: sh          $t9, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r25;
    // 0x80005618: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000561C: jr          $ra
    // 0x80005620: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80005620: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80005624(rdram, ctx);
;}
RECOMP_FUNC void FUN_80005624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005624: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005628: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000562C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80005630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005634: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80005638: addiu       $a0, $a0, -0x6C88
    ctx->r4 = ADD32(ctx->r4, -0X6C88);
    // 0x8000563C: jal         0x800059B0
    // 0x80005640: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    LOOKUP_FUNC(0x800059B0)(rdram, ctx);
        goto after_0;
    // 0x80005640: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    after_0:
    // 0x80005644: beq         $v0, $zero, L_8000565C
    if (ctx->r2 == 0) {
        // 0x80005648: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8000565C;
    }
    // 0x80005648: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000564C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80005650: jal         0x80005B98
    // 0x80005654: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80005B98)(rdram, ctx);
        goto after_1;
    // 0x80005654: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80005658: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_8000565C:
    // 0x8000565C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005660: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80005664: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80005668: jr          $ra
    // 0x8000566C: nop

    return;
    // 0x8000566C: nop

;}
RECOMP_FUNC void FUN_80005670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005670: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005678: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000567C: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x80005680: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80005684: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80005688: beq         $a3, $zero, L_800056A4
    if (ctx->r7 == 0) {
        // 0x8000568C: addiu       $v1, $v1, -0x6D50
        ctx->r3 = ADD32(ctx->r3, -0X6D50);
            goto L_800056A4;
    }
    // 0x8000568C: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x80005690: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80005694: jal         0x800059B0
    // 0x80005698: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    LOOKUP_FUNC(0x800059B0)(rdram, ctx);
        goto after_0;
    // 0x80005698: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    after_0:
    // 0x8000569C: b           L_800056D8
    // 0x800056A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800056D8;
    // 0x800056A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800056A4:
    // 0x800056A4: lw          $v0, 0xAC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XAC);
    // 0x800056A8: beql        $v0, $zero, L_800056D8
    if (ctx->r2 == 0) {
        // 0x800056AC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800056D8;
    }
    goto skip_0;
    // 0x800056AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
    // 0x800056B0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800056B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800056B8: sw          $t7, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = ctx->r15;
    // 0x800056BC: sw          $v0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r2;
    // 0x800056C0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800056C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800056C8: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800056CC: b           L_800056D8
    // 0x800056D0: sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
        goto L_800056D8;
    // 0x800056D0: sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
    // 0x800056D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800056D8:
    // 0x800056D8: beq         $a0, $zero, L_800056EC
    if (ctx->r4 == 0) {
        // 0x800056DC: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_800056EC;
    }
    // 0x800056DC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800056E0: jal         0x80005B98
    // 0x800056E4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80005B98)(rdram, ctx);
        goto after_1;
    // 0x800056E4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x800056E8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800056EC:
    // 0x800056EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800056F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800056F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800056F8: jr          $ra
    // 0x800056FC: nop

    return;
    // 0x800056FC: nop

;}
RECOMP_FUNC void FUN_80005700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005700: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80005704: addiu       $v0, $v0, -0x2A2C
    ctx->r2 = ADD32(ctx->r2, -0X2A2C);
    // 0x80005708: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000570C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80005710: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80005714: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80005718: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000571C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80005720: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80005724: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80005728: bne         $a0, $t6, L_80005734
    if (ctx->r4 != ctx->r14) {
        // 0x8000572C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80005734;
    }
    // 0x8000572C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80005730: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80005734:
    // 0x80005734: jal         0x80005ACC
    // 0x80005738: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005ACC)(rdram, ctx);
        goto after_0;
    // 0x80005738: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8000573C: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80005740: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80005744: beq         $v0, $zero, L_800057C0
    if (ctx->r2 == 0) {
        // 0x80005748: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800057C0;
    }
    // 0x80005748: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000574C: beq         $v0, $zero, L_800057C0
    if (ctx->r2 == 0) {
        // 0x80005750: sw          $zero, 0x8($s0)
        MEM_W(0X8, ctx->r16) = 0;
            goto L_800057C0;
    }
    // 0x80005750: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80005754: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80005758: addiu       $s3, $s3, -0x2898
    ctx->r19 = ADD32(ctx->r19, -0X2898);
    // 0x8000575C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80005760:
    // 0x80005760: jal         0x80005ACC
    // 0x80005764: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005ACC)(rdram, ctx);
        goto after_1;
    // 0x80005764: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80005768: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8000576C: beq         $v0, $zero, L_80005794
    if (ctx->r2 == 0) {
        // 0x80005770: nop
    
            goto L_80005794;
    }
    // 0x80005770: nop

    // 0x80005774: beq         $s0, $zero, L_8000578C
    if (ctx->r16 == 0) {
        // 0x80005778: sll         $t7, $s2, 2
        ctx->r15 = S32(ctx->r18 << 2);
            goto L_8000578C;
    }
    // 0x80005778: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8000577C: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x80005780: sw          $s0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r16;
    // 0x80005784: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80005788: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8000578C:
    // 0x8000578C: b           L_800057B8
    // 0x80005790: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_800057B8;
    // 0x80005790: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80005794:
    // 0x80005794: bne         $s0, $zero, L_800057B8
    if (ctx->r16 != 0) {
        // 0x80005798: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_800057B8;
    }
    // 0x80005798: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x8000579C: beq         $s2, $zero, L_800057B8
    if (ctx->r18 == 0) {
        // 0x800057A0: addiu       $v0, $s2, -0x1
        ctx->r2 = ADD32(ctx->r18, -0X1);
            goto L_800057B8;
    }
    // 0x800057A0: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x800057A4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800057A8: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x800057AC: lw          $s1, 0x0($t0)
    ctx->r17 = MEM_W(ctx->r8, 0X0);
    // 0x800057B0: b           L_800057B8
    // 0x800057B4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_800057B8;
    // 0x800057B4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800057B8:
    // 0x800057B8: bnel        $s1, $zero, L_80005760
    if (ctx->r17 != 0) {
        // 0x800057BC: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_80005760;
    }
    goto skip_0;
    // 0x800057BC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_0:
L_800057C0:
    // 0x800057C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800057C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800057C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800057CC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800057D0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800057D4: jr          $ra
    // 0x800057D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800057D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800057dc(rdram, ctx);
;}
RECOMP_FUNC void FUN_800057dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800057DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800057E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800057E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800057E8: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x800057EC: jal         0x80005700
    // 0x800057F0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x800057F0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800057F4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800057F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800057FC: beq         $a2, $zero, L_80005814
    if (ctx->r6 == 0) {
        // 0x80005800: nop
    
            goto L_80005814;
    }
    // 0x80005800: nop

    // 0x80005804: jal         0x80005670
    // 0x80005808: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x80005808: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8000580C: b           L_80005820
    // 0x80005810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80005820;
    // 0x80005810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80005814:
    // 0x80005814: jal         0x80005624
    // 0x80005818: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80005624)(rdram, ctx);
        goto after_2;
    // 0x80005818: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8000581C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80005820:
    // 0x80005820: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80005824: jr          $ra
    // 0x80005828: nop

    return;
    // 0x80005828: nop

;}
RECOMP_FUNC void FUN_8000582c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000582C: beq         $a1, $zero, L_800058B0
    if (ctx->r5 == 0) {
        // 0x80005830: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800058B0;
    }
    // 0x80005830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005834: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x80005838: addiu       $a3, $a3, -0x2898
    ctx->r7 = ADD32(ctx->r7, -0X2898);
    // 0x8000583C: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
L_80005840:
    // 0x80005840: beq         $a0, $t6, L_800058B0
    if (ctx->r4 == ctx->r14) {
        // 0x80005844: nop
    
            goto L_800058B0;
    }
    // 0x80005844: nop

    // 0x80005848: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x8000584C: beql        $v1, $zero, L_80005880
    if (ctx->r3 == 0) {
        // 0x80005850: lw          $a2, 0x0($a1)
        ctx->r6 = MEM_W(ctx->r5, 0X0);
            goto L_80005880;
    }
    goto skip_0;
    // 0x80005850: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80005854: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x80005858: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8000585C: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80005860: beq         $a2, $zero, L_80005874
    if (ctx->r6 == 0) {
        // 0x80005864: nop
    
            goto L_80005874;
    }
    // 0x80005864: nop

    // 0x80005868: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x8000586C: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x80005870: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80005874:
    // 0x80005874: b           L_800058A8
    // 0x80005878: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_800058A8;
    // 0x80005878: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8000587C: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
L_80005880:
    // 0x80005880: bne         $a2, $zero, L_800058A8
    if (ctx->r6 != 0) {
        // 0x80005884: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_800058A8;
    }
    // 0x80005884: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80005888: beq         $v0, $zero, L_800058A8
    if (ctx->r2 == 0) {
        // 0x8000588C: nop
    
            goto L_800058A8;
    }
    // 0x8000588C: nop

    // 0x80005890: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // 0x80005894: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80005898: addu        $t0, $a3, $t9
    ctx->r8 = ADD32(ctx->r7, ctx->r25);
    // 0x8000589C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800058A0: b           L_800058A8
    // 0x800058A4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_800058A8;
    // 0x800058A4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800058A8:
    // 0x800058A8: bnel        $a1, $zero, L_80005840
    if (ctx->r5 != 0) {
        // 0x800058AC: lw          $t6, 0x10($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X10);
            goto L_80005840;
    }
    goto skip_1;
    // 0x800058AC: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    skip_1:
L_800058B0:
    // 0x800058B0: jr          $ra
    // 0x800058B4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800058B4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800058b8(rdram, ctx);
;}
RECOMP_FUNC void FUN_800058b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800058B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800058BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800058C0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x800058C4: jal         0x8000582C
    // 0x800058C8: addiu       $a1, $a1, -0x6C88
    ctx->r5 = ADD32(ctx->r5, -0X6C88);
    LOOKUP_FUNC(0x8000582C)(rdram, ctx);
        goto after_0;
    // 0x800058C8: addiu       $a1, $a1, -0x6C88
    ctx->r5 = ADD32(ctx->r5, -0X6C88);
    after_0:
    // 0x800058CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800058D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800058D4: jr          $ra
    // 0x800058D8: nop

    return;
    // 0x800058D8: nop

;}
RECOMP_FUNC void FUN_800058dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800058DC: jr          $ra
    // 0x800058E0: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
    return;
    // 0x800058E0: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
    // 0x800058E4: jr          $ra
    // 0x800058E8: sw          $a1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r5;
    return;
    // 0x800058E8: sw          $a1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r5;
    // 0x800058EC: jr          $ra
    // 0x800058F0: sw          $a1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r5;
    return;
    // 0x800058F0: sw          $a1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800058f4(rdram, ctx);
;}
RECOMP_FUNC void FUN_800058f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800058F4: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800058F8: lw          $t6, -0x2A30($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2A30);
    // 0x800058FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005900: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005904: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80005908: bne         $a0, $t6, L_8000591C
    if (ctx->r4 != ctx->r14) {
        // 0x8000590C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8000591C;
    }
    // 0x8000590C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80005910: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80005914: b           L_80005924
    // 0x80005918: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80005924;
    // 0x80005918: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8000591C:
    // 0x8000591C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80005920: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
L_80005924:
    // 0x80005924: bne         $v0, $zero, L_80005938
    if (ctx->r2 != 0) {
        // 0x80005928: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80005938;
    }
    // 0x80005928: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8000592C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80005930: beql        $t7, $zero, L_800059A4
    if (ctx->r15 == 0) {
        // 0x80005934: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800059A4;
    }
    goto skip_0;
    // 0x80005934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80005938:
    // 0x80005938: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8000593C: jal         0x80005B48
    // 0x80005940: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80005B48)(rdram, ctx);
        goto after_0;
    // 0x80005940: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80005944: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80005948: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8000594C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80005950: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    // 0x80005954: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80005958: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000595C: bne         $v0, $zero, L_8000597C
    if (ctx->r2 != 0) {
        // 0x80005960: sw          $t8, 0x14($a2)
        MEM_W(0X14, ctx->r6) = ctx->r24;
            goto L_8000597C;
    }
    // 0x80005960: sw          $t8, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r24;
    // 0x80005964: addiu       $a0, $a0, -0x6C88
    ctx->r4 = ADD32(ctx->r4, -0X6C88);
    // 0x80005968: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000596C: jal         0x80005A04
    // 0x80005970: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80005A04)(rdram, ctx);
        goto after_1;
    // 0x80005970: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80005974: b           L_8000598C
    // 0x80005978: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_8000598C;
    // 0x80005978: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_8000597C:
    // 0x8000597C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80005980: jal         0x80005A04
    // 0x80005984: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x80005A04)(rdram, ctx);
        goto after_2;
    // 0x80005984: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80005988: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_8000598C:
    // 0x8000598C: beql        $v1, $zero, L_800059A4
    if (ctx->r3 == 0) {
        // 0x80005990: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800059A4;
    }
    goto skip_1;
    // 0x80005990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80005994: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80005998: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000599C: sw          $t9, -0x2A30($at)
    MEM_W(-0X2A30, ctx->r1) = ctx->r25;
    // 0x800059A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800059A4:
    // 0x800059A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800059A8: jr          $ra
    // 0x800059AC: nop

    return;
    // 0x800059AC: nop

;}
RECOMP_FUNC void FUN_800059b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800059B0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800059B4: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x800059B8: lw          $v0, 0xAC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XAC);
    // 0x800059BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800059C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800059C4: beq         $v0, $zero, L_800059F0
    if (ctx->r2 == 0) {
        // 0x800059C8: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800059F0;
    }
    // 0x800059C8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800059CC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800059D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800059D4: sw          $t6, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = ctx->r14;
    // 0x800059D8: sw          $a2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r6;
    // 0x800059DC: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800059E0: jal         0x80005A04
    // 0x800059E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80005A04)(rdram, ctx);
        goto after_0;
    // 0x800059E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800059E8: b           L_800059F4
    // 0x800059EC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_800059F4;
    // 0x800059EC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800059F0:
    // 0x800059F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800059F4:
    // 0x800059F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800059F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800059FC: jr          $ra
    // 0x80005A00: nop

    return;
    // 0x80005A00: nop

;}
RECOMP_FUNC void FUN_80005a04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005A04: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80005A08: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x80005A0C: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80005A10: sltu        $at, $t6, $v0
    ctx->r1 = ctx->r14 < ctx->r2 ? 1 : 0;
    // 0x80005A14: beql        $at, $zero, L_80005A6C
    if (ctx->r1 == 0) {
        // 0x80005A18: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_80005A6C;
    }
    goto skip_0;
    // 0x80005A18: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80005A1C: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x80005A20: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x80005A24: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80005A28: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x80005A2C: sw          $t8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r24;
    // 0x80005A30: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80005A34: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80005A38: beql        $v0, $zero, L_80005A48
    if (ctx->r2 == 0) {
        // 0x80005A3C: lw          $t9, 0xC($a1)
        ctx->r25 = MEM_W(ctx->r5, 0XC);
            goto L_80005A48;
    }
    goto skip_1;
    // 0x80005A3C: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    skip_1:
    // 0x80005A40: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80005A44: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
L_80005A48:
    // 0x80005A48: beq         $t9, $zero, L_80005AC4
    if (ctx->r25 == 0) {
        // 0x80005A4C: nop
    
            goto L_80005AC4;
    }
    // 0x80005A4C: nop

    // 0x80005A50: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80005A54: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80005A58: bne         $a0, $t0, L_80005AC4
    if (ctx->r4 != ctx->r8) {
        // 0x80005A5C: nop
    
            goto L_80005AC4;
    }
    // 0x80005A5C: nop

    // 0x80005A60: jr          $ra
    // 0x80005A64: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    return;
    // 0x80005A64: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
L_80005A68:
    // 0x80005A68: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_80005A6C:
    // 0x80005A6C: beql        $v1, $zero, L_80005A90
    if (ctx->r3 == 0) {
        // 0x80005A70: sw          $v1, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r3;
            goto L_80005A90;
    }
    goto skip_2;
    // 0x80005A70: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    skip_2:
    // 0x80005A74: lw          $t1, 0x14($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X14);
    // 0x80005A78: sltu        $at, $t1, $v0
    ctx->r1 = ctx->r9 < ctx->r2 ? 1 : 0;
    // 0x80005A7C: bnel        $at, $zero, L_80005A90
    if (ctx->r1 != 0) {
        // 0x80005A80: sw          $v1, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r3;
            goto L_80005A90;
    }
    goto skip_3;
    // 0x80005A80: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    skip_3:
    // 0x80005A84: b           L_80005A68
    // 0x80005A88: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_80005A68;
    // 0x80005A88: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80005A8C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_80005A90:
    // 0x80005A90: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x80005A94: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x80005A98: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80005A9C: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x80005AA0: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80005AA4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80005AA8: beq         $v0, $zero, L_80005AB4
    if (ctx->r2 == 0) {
        // 0x80005AAC: nop
    
            goto L_80005AB4;
    }
    // 0x80005AAC: nop

    // 0x80005AB0: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
L_80005AB4:
    // 0x80005AB4: lw          $t3, -0x2A2C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2A2C);
    // 0x80005AB8: bne         $a0, $t3, L_80005AC4
    if (ctx->r4 != ctx->r11) {
        // 0x80005ABC: nop
    
            goto L_80005AC4;
    }
    // 0x80005ABC: nop

    // 0x80005AC0: sw          $a1, -0x2A30($at)
    MEM_W(-0X2A30, ctx->r1) = ctx->r5;
L_80005AC4:
    // 0x80005AC4: jr          $ra
    // 0x80005AC8: nop

    return;
    // 0x80005AC8: nop

;}
RECOMP_FUNC void FUN_80005acc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005ACC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80005AD0: addiu       $v0, $v0, -0x2A30
    ctx->r2 = ADD32(ctx->r2, -0X2A30);
    // 0x80005AD4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80005AD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005ADC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80005AE0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80005AE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80005AE8: bne         $a0, $t6, L_80005AF8
    if (ctx->r4 != ctx->r14) {
        // 0x80005AEC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80005AF8;
    }
    // 0x80005AEC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80005AF0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80005AF4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80005AF8:
    // 0x80005AF8: jal         0x80005B48
    // 0x80005AFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005B48)(rdram, ctx);
        goto after_0;
    // 0x80005AFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80005B00: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80005B04: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x80005B08: lw          $t8, 0xAC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XAC);
    // 0x80005B0C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80005B10: sw          $s1, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->r17;
    // 0x80005B14: lw          $s0, 0x24($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X24);
    // 0x80005B18: beql        $s0, $zero, L_80005B38
    if (ctx->r16 == 0) {
        // 0x80005B1C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80005B38;
    }
    goto skip_0;
    // 0x80005B1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80005B20:
    // 0x80005B20: jal         0x80006088
    // 0x80005B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_1;
    // 0x80005B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80005B28: lw          $s0, 0x24($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X24);
    // 0x80005B2C: bne         $s0, $zero, L_80005B20
    if (ctx->r16 != 0) {
        // 0x80005B30: nop
    
            goto L_80005B20;
    }
    // 0x80005B30: nop

    // 0x80005B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80005B38:
    // 0x80005B38: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80005B3C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80005B40: jr          $ra
    // 0x80005B44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80005B44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80005b48(rdram, ctx);
;}
