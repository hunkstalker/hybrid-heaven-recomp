#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FUN_80005b48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005B48: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80005B4C: beql        $v0, $zero, L_80005B60
    if (ctx->r2 == 0) {
        // 0x80005B50: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80005B60;
    }
    goto skip_0;
    // 0x80005B50: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80005B54: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80005B58: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80005B5C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80005B60:
    // 0x80005B60: beql        $v0, $zero, L_80005B74
    if (ctx->r2 == 0) {
        // 0x80005B64: lw          $v0, 0xC($a0)
        ctx->r2 = MEM_W(ctx->r4, 0XC);
            goto L_80005B74;
    }
    goto skip_1;
    // 0x80005B64: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    skip_1:
    // 0x80005B68: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x80005B6C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80005B70: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
L_80005B74:
    // 0x80005B74: beq         $v0, $zero, L_80005B90
    if (ctx->r2 == 0) {
        // 0x80005B78: nop
    
            goto L_80005B90;
    }
    // 0x80005B78: nop

    // 0x80005B7C: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80005B80: bne         $a0, $t8, L_80005B90
    if (ctx->r4 != ctx->r24) {
        // 0x80005B84: nop
    
            goto L_80005B90;
    }
    // 0x80005B84: nop

    // 0x80005B88: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80005B8C: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
L_80005B90:
    // 0x80005B90: jr          $ra
    // 0x80005B94: nop

    return;
    // 0x80005B94: nop

;}
RECOMP_FUNC void FUN_80005b98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005B98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005B9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005BA0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80005BA4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80005BA8: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    // 0x80005BAC: sw          $t6, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = ctx->r14;
    // 0x80005BB0: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80005BB4: sw          $t7, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = ctx->r15;
    // 0x80005BB8: lw          $t8, 0xC($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XC);
    // 0x80005BBC: sw          $t8, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->r24;
    // 0x80005BC0: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x80005BC4: sw          $t9, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = ctx->r25;
    // 0x80005BC8: lw          $t0, 0x10($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X10);
    // 0x80005BCC: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x80005BD0: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x80005BD4: sw          $t0, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->r8;
    // 0x80005BD8: jal         0x800279F0
    // 0x80005BDC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x800279F0)(rdram, ctx);
        goto after_0;
    // 0x80005BDC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80005BE0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80005BE4: sh          $zero, 0x28($a3)
    MEM_H(0X28, ctx->r7) = 0;
    // 0x80005BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005BEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005BF0: jr          $ra
    // 0x80005BF4: nop

    return;
    // 0x80005BF4: nop

    // 0x80005BF8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80005BFC: lw          $t6, 0x3394($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3394);
    // 0x80005C00: lui         $at, 0x4378
    ctx->r1 = S32(0X4378 << 16);
    // 0x80005C04: ori         $at, $at, 0x1902
    ctx->r1 = ctx->r1 | 0X1902;
    // 0x80005C08: bne         $t6, $at, L_80005C1C
    if (ctx->r14 != ctx->r1) {
        // 0x80005C0C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80005C1C;
    }
    // 0x80005C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005C10: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80005C14: jr          $ra
    // 0x80005C18: lhu         $v0, 0x3398($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3398);
    return;
    // 0x80005C18: lhu         $v0, 0x3398($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3398);
L_80005C1C:
    // 0x80005C1C: jr          $ra
    // 0x80005C20: nop

    return;
    // 0x80005C20: nop

    // 0x80005C24: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80005C28: lw          $t6, 0x3394($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3394);
    // 0x80005C2C: lui         $at, 0x4378
    ctx->r1 = S32(0X4378 << 16);
    // 0x80005C30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005C34: ori         $at, $at, 0x1902
    ctx->r1 = ctx->r1 | 0X1902;
    // 0x80005C38: bne         $t6, $at, L_80005C5C
    if (ctx->r14 != ctx->r1) {
        // 0x80005C3C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80005C5C;
    }
    // 0x80005C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005C40: jal         0x80005CB0
    // 0x80005C44: nop

    LOOKUP_FUNC(0x80005CB0)(rdram, ctx);
        goto after_1;
    // 0x80005C44: nop

    after_1:
    // 0x80005C48: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80005C4C: lhu         $t7, 0x3398($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X3398);
    // 0x80005C50: subu        $v0, $t7, $v0
    ctx->r2 = SUB32(ctx->r15, ctx->r2);
    // 0x80005C54: b           L_80005C60
    // 0x80005C58: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
        goto L_80005C60;
    // 0x80005C58: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80005C5C:
    // 0x80005C5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80005C60:
    // 0x80005C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005C68: jr          $ra
    // 0x80005C6C: nop

    return;
    // 0x80005C6C: nop

;}
RECOMP_FUNC void FUN_80005c70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C70: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80005C74: lw          $t6, 0x3394($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3394);
    // 0x80005C78: lui         $at, 0x4378
    ctx->r1 = S32(0X4378 << 16);
    // 0x80005C7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005C80: ori         $at, $at, 0x1902
    ctx->r1 = ctx->r1 | 0X1902;
    // 0x80005C84: bne         $t6, $at, L_80005C9C
    if (ctx->r14 != ctx->r1) {
        // 0x80005C88: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80005C9C;
    }
    // 0x80005C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005C8C: jal         0x80005CB0
    // 0x80005C90: nop

    LOOKUP_FUNC(0x80005CB0)(rdram, ctx);
        goto after_0;
    // 0x80005C90: nop

    after_0:
    // 0x80005C94: b           L_80005CA4
    // 0x80005C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80005CA4;
    // 0x80005C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80005C9C:
    // 0x80005C9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80005CA4:
    // 0x80005CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005CA8: jr          $ra
    // 0x80005CAC: nop

    return;
    // 0x80005CAC: nop

;}
RECOMP_FUNC void FUN_80005cb0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CB0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80005CB4: lw          $v0, -0x6CA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6CA4);
    // 0x80005CB8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80005CBC: beq         $v0, $zero, L_80005CD4
    if (ctx->r2 == 0) {
        // 0x80005CC0: nop
    
            goto L_80005CD4;
    }
    // 0x80005CC0: nop

    // 0x80005CC4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_80005CC8:
    // 0x80005CC8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80005CCC: bnel        $v0, $zero, L_80005CC8
    if (ctx->r2 != 0) {
        // 0x80005CD0: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_80005CC8;
    }
    goto skip_0;
    // 0x80005CD0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_0:
L_80005CD4:
    // 0x80005CD4: jr          $ra
    // 0x80005CD8: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    return;
    // 0x80005CD8: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80005cdc(rdram, ctx);
;}
RECOMP_FUNC void FUN_80005cdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CDC: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80005CE0: addiu       $a2, $a2, -0x6D50
    ctx->r6 = ADD32(ctx->r6, -0X6D50);
    // 0x80005CE4: lhu         $a1, 0xB6($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0XB6);
    // 0x80005CE8: lw          $v1, 0xC4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC4);
    // 0x80005CEC: lw          $a0, 0xBC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XBC);
    // 0x80005CF0: blez        $a1, L_80005D30
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80005CF4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80005D30;
    }
    // 0x80005CF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005CF8: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
L_80005CFC:
    // 0x80005CFC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80005D00: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80005D04: beql        $t6, $zero, L_80005D1C
    if (ctx->r14 == 0) {
        // 0x80005D08: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80005D1C;
    }
    goto skip_0;
    // 0x80005D08: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_0:
    // 0x80005D0C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80005D10: b           L_80005D28
    // 0x80005D14: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
        goto L_80005D28;
    // 0x80005D14: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x80005D18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80005D1C:
    // 0x80005D1C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x80005D20: jr          $ra
    // 0x80005D24: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80005D24: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80005D28:
    // 0x80005D28: bnel        $at, $zero, L_80005CFC
    if (ctx->r1 != 0) {
        // 0x80005D2C: lbu         $t6, 0x0($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X0);
            goto L_80005CFC;
    }
    goto skip_1;
    // 0x80005D2C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    skip_1:
L_80005D30:
    // 0x80005D30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005D34: jr          $ra
    // 0x80005D38: nop

    return;
    // 0x80005D38: nop

;}
RECOMP_FUNC void FUN_80005d3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D3C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80005D40: addiu       $a2, $a2, -0x6D50
    ctx->r6 = ADD32(ctx->r6, -0X6D50);
    // 0x80005D44: lhu         $a1, 0xB4($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0XB4);
    // 0x80005D48: lw          $v1, 0xC0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XC0);
    // 0x80005D4C: lw          $a0, 0xB8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XB8);
    // 0x80005D50: blez        $a1, L_80005D90
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80005D54: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80005D90;
    }
    // 0x80005D54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005D58: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
L_80005D5C:
    // 0x80005D5C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80005D60: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80005D64: beql        $t6, $zero, L_80005D7C
    if (ctx->r14 == 0) {
        // 0x80005D68: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80005D7C;
    }
    goto skip_0;
    // 0x80005D68: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_0:
    // 0x80005D6C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80005D70: b           L_80005D88
    // 0x80005D74: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
        goto L_80005D88;
    // 0x80005D74: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    // 0x80005D78: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80005D7C:
    // 0x80005D7C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x80005D80: jr          $ra
    // 0x80005D84: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80005D84: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80005D88:
    // 0x80005D88: bnel        $at, $zero, L_80005D5C
    if (ctx->r1 != 0) {
        // 0x80005D8C: lbu         $t6, 0x0($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X0);
            goto L_80005D5C;
    }
    goto skip_1;
    // 0x80005D8C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    skip_1:
L_80005D90:
    // 0x80005D90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005D94: jr          $ra
    // 0x80005D98: nop

    return;
    // 0x80005D98: nop

;}
RECOMP_FUNC void FUN_80005d9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005DA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80005DA4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80005DA8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80005DAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005DB0: beq         $a1, $at, L_80005DCC
    if (ctx->r5 == ctx->r1) {
        // 0x80005DB4: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80005DCC;
    }
    // 0x80005DB4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80005DB8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80005DBC: beql        $v0, $at, L_80005DF4
    if (ctx->r2 == ctx->r1) {
        // 0x80005DC0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80005DF4;
    }
    goto skip_0;
    // 0x80005DC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x80005DC4: b           L_80005E18
    // 0x80005DC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
        goto L_80005E18;
    // 0x80005DC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80005DCC:
    // 0x80005DCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80005DD0: jal         0x80005CDC
    // 0x80005DD4: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80005CDC)(rdram, ctx);
        goto after_0;
    // 0x80005DD4: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    after_0:
    // 0x80005DD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80005DDC: lhu         $a1, 0x1E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1E);
    // 0x80005DE0: sw          $v0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r2;
    // 0x80005DE4: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80005DE8: b           L_80005E34
    // 0x80005DEC: sh          $a1, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r5;
        goto L_80005E34;
    // 0x80005DEC: sh          $a1, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r5;
    // 0x80005DF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80005DF4:
    // 0x80005DF4: jal         0x80005CDC
    // 0x80005DF8: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80005CDC)(rdram, ctx);
        goto after_1;
    // 0x80005DF8: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    after_1:
    // 0x80005DFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80005E00: lhu         $a1, 0x1E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1E);
    // 0x80005E04: sw          $v0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r2;
    // 0x80005E08: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80005E0C: b           L_80005E34
    // 0x80005E10: sh          $a1, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r5;
        goto L_80005E34;
    // 0x80005E10: sh          $a1, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r5;
    // 0x80005E14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80005E18:
    // 0x80005E18: jal         0x80005D3C
    // 0x80005E1C: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80005D3C)(rdram, ctx);
        goto after_2;
    // 0x80005E1C: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    after_2:
    // 0x80005E20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80005E24: lhu         $a1, 0x1E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1E);
    // 0x80005E28: sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    // 0x80005E2C: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x80005E30: sh          $a1, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r5;
L_80005E34:
    // 0x80005E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005E38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005E3C: jr          $ra
    // 0x80005E40: nop

    return;
    // 0x80005E40: nop

;}
RECOMP_FUNC void FUN_80005e44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005E48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80005E4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80005E50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005E54: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80005E58: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80005E5C: addiu       $a0, $a0, -0x6BD4
    ctx->r4 = ADD32(ctx->r4, -0X6BD4);
    // 0x80005E60: jal         0x800063BC
    // 0x80005E64: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    LOOKUP_FUNC(0x800063BC)(rdram, ctx);
        goto after_0;
    // 0x80005E64: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    after_0:
    // 0x80005E68: beq         $v0, $zero, L_80005EC0
    if (ctx->r2 == 0) {
        // 0x80005E6C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80005EC0;
    }
    // 0x80005E6C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80005E70: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80005E74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80005E78: jal         0x80005D9C
    // 0x80005E7C: lhu         $a1, 0xA($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0XA);
    LOOKUP_FUNC(0x80005D9C)(rdram, ctx);
        goto after_1;
    // 0x80005E7C: lhu         $a1, 0xA($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0XA);
    after_1:
    // 0x80005E80: bne         $v0, $zero, L_80005E90
    if (ctx->r2 != 0) {
        // 0x80005E84: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80005E90;
    }
    // 0x80005E84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80005E88: b           L_80005EC4
    // 0x80005E8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005EC4;
    // 0x80005E8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80005E90:
    // 0x80005E90: jal         0x80006370
    // 0x80005E94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006370)(rdram, ctx);
        goto after_2;
    // 0x80005E94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80005E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80005E9C: jal         0x800065EC
    // 0x80005EA0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x800065EC)(rdram, ctx);
        goto after_3;
    // 0x80005EA0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80005EA4: beql        $v0, $zero, L_80005EC0
    if (ctx->r2 == 0) {
        // 0x80005EA8: sw          $zero, 0xC($s0)
        MEM_W(0XC, ctx->r16) = 0;
            goto L_80005EC0;
    }
    goto skip_0;
    // 0x80005EA8: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    skip_0:
    // 0x80005EAC: jal         0x80006088
    // 0x80005EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_4;
    // 0x80005EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80005EB4: b           L_80005EC4
    // 0x80005EB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005EC4;
    // 0x80005EB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005EBC: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
L_80005EC0:
    // 0x80005EC0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80005EC4:
    // 0x80005EC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80005EC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80005ECC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80005ED0: jr          $ra
    // 0x80005ED4: nop

    return;
    // 0x80005ED4: nop

;}
RECOMP_FUNC void FUN_80005ed8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005ED8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005EDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80005EE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80005EE4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80005EE8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80005EEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005EF0: addiu       $a0, $a0, -0x6BD4
    ctx->r4 = ADD32(ctx->r4, -0X6BD4);
    // 0x80005EF4: jal         0x800063BC
    // 0x80005EF8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(0x800063BC)(rdram, ctx);
        goto after_0;
    // 0x80005EF8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80005EFC: beq         $v0, $zero, L_80005F54
    if (ctx->r2 == 0) {
        // 0x80005F00: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80005F54;
    }
    // 0x80005F00: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80005F04: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80005F08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80005F0C: jal         0x80005D9C
    // 0x80005F10: lhu         $a1, 0xA($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0XA);
    LOOKUP_FUNC(0x80005D9C)(rdram, ctx);
        goto after_1;
    // 0x80005F10: lhu         $a1, 0xA($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0XA);
    after_1:
    // 0x80005F14: bne         $v0, $zero, L_80005F24
    if (ctx->r2 != 0) {
        // 0x80005F18: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80005F24;
    }
    // 0x80005F18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80005F1C: b           L_80005F58
    // 0x80005F20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005F58;
    // 0x80005F20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80005F24:
    // 0x80005F24: jal         0x80006370
    // 0x80005F28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006370)(rdram, ctx);
        goto after_2;
    // 0x80005F28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80005F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80005F30: jal         0x800065EC
    // 0x80005F34: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x800065EC)(rdram, ctx);
        goto after_3;
    // 0x80005F34: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80005F38: beql        $v0, $zero, L_80005F54
    if (ctx->r2 == 0) {
        // 0x80005F3C: sw          $zero, 0xC($s0)
        MEM_W(0XC, ctx->r16) = 0;
            goto L_80005F54;
    }
    goto skip_0;
    // 0x80005F3C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    skip_0:
    // 0x80005F40: jal         0x80006088
    // 0x80005F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_4;
    // 0x80005F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80005F48: b           L_80005F58
    // 0x80005F4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005F58;
    // 0x80005F4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005F50: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
L_80005F54:
    // 0x80005F54: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80005F58:
    // 0x80005F58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80005F5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80005F60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80005F64: jr          $ra
    // 0x80005F68: nop

    return;
    // 0x80005F68: nop

;}
RECOMP_FUNC void FUN_80005f6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005F6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005F74: jal         0x80005E44
    // 0x80005F78: nop

    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x80005F78: nop

    after_0:
    // 0x80005F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005F80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005F84: jr          $ra
    // 0x80005F88: nop

    return;
    // 0x80005F88: nop

;}
RECOMP_FUNC void FUN_80005f8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005F8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005F94: jal         0x80005ED8
    // 0x80005F98: nop

    LOOKUP_FUNC(0x80005ED8)(rdram, ctx);
        goto after_0;
    // 0x80005F98: nop

    after_0:
    // 0x80005F9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005FA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005FA4: jr          $ra
    // 0x80005FA8: nop

    return;
    // 0x80005FA8: nop

;}
RECOMP_FUNC void FUN_80005fac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005FAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005FB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80005FB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005FB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80005FBC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80005FC0: lw          $a3, 0x8($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X8);
    // 0x80005FC4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80005FC8: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x80005FCC: beq         $a3, $zero, L_80005FE4
    if (ctx->r7 == 0) {
        // 0x80005FD0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80005FE4;
    }
    // 0x80005FD0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80005FD4: jal         0x800063BC
    // 0x80005FD8: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    LOOKUP_FUNC(0x800063BC)(rdram, ctx);
        goto after_0;
    // 0x80005FD8: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    after_0:
    // 0x80005FDC: b           L_80006020
    // 0x80005FE0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80006020;
    // 0x80005FE0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80005FE4:
    // 0x80005FE4: lw          $v0, 0xB0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XB0);
    // 0x80005FE8: beql        $v0, $zero, L_80006020
    if (ctx->r2 == 0) {
        // 0x80005FEC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80006020;
    }
    goto skip_0;
    // 0x80005FEC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_0:
    // 0x80005FF0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80005FF4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80005FF8: sw          $t7, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r15;
    // 0x80005FFC: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x80006000: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80006004: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80006008: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8000600C: sw          $a1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r5;
    // 0x80006010: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80006014: b           L_80006020
    // 0x80006018: sw          $t8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r24;
        goto L_80006020;
    // 0x80006018: sw          $t8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r24;
    // 0x8000601C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80006020:
    // 0x80006020: beq         $s0, $zero, L_80006070
    if (ctx->r16 == 0) {
        // 0x80006024: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_80006070;
    }
    // 0x80006024: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80006028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000602C: jal         0x80005D9C
    // 0x80006030: lhu         $a1, 0xA($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0XA);
    LOOKUP_FUNC(0x80005D9C)(rdram, ctx);
        goto after_1;
    // 0x80006030: lhu         $a1, 0xA($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0XA);
    after_1:
    // 0x80006034: bne         $v0, $zero, L_80006044
    if (ctx->r2 != 0) {
        // 0x80006038: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80006044;
    }
    // 0x80006038: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000603C: b           L_80006074
    // 0x80006040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80006074;
    // 0x80006040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80006044:
    // 0x80006044: jal         0x80006370
    // 0x80006048: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006370)(rdram, ctx);
        goto after_2;
    // 0x80006048: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8000604C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006050: jal         0x800065EC
    // 0x80006054: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800065EC)(rdram, ctx);
        goto after_3;
    // 0x80006054: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80006058: beql        $v0, $zero, L_80006074
    if (ctx->r2 == 0) {
        // 0x8000605C: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80006074;
    }
    goto skip_1;
    // 0x8000605C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_1:
    // 0x80006060: jal         0x80006088
    // 0x80006064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_4;
    // 0x80006064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80006068: b           L_80006074
    // 0x8000606C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80006074;
    // 0x8000606C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80006070:
    // 0x80006070: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80006074:
    // 0x80006074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80006078: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000607C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80006080: jr          $ra
    // 0x80006084: nop

    return;
    // 0x80006084: nop

;}
RECOMP_FUNC void FUN_80006088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006088: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000608C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80006090: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80006094: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80006098: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000609C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800060A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800060A4: jal         0x800064C4
    // 0x800060A8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    LOOKUP_FUNC(0x800064C4)(rdram, ctx);
        goto after_0;
    // 0x800060A8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_0:
    // 0x800060AC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800060B0: beql        $v0, $zero, L_80006130
    if (ctx->r2 == 0) {
        // 0x800060B4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80006130;
    }
    goto skip_0;
    // 0x800060B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800060B8: beq         $v0, $zero, L_8000612C
    if (ctx->r2 == 0) {
        // 0x800060BC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000612C;
    }
    // 0x800060BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800060C0: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x800060C4: addiu       $s3, $s3, -0x2708
    ctx->r19 = ADD32(ctx->r19, -0X2708);
    // 0x800060C8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800060CC:
    // 0x800060CC: jal         0x800064C4
    // 0x800060D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800064C4)(rdram, ctx);
        goto after_1;
    // 0x800060D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800060D4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800060D8: beq         $v0, $zero, L_80006100
    if (ctx->r2 == 0) {
        // 0x800060DC: nop
    
            goto L_80006100;
    }
    // 0x800060DC: nop

    // 0x800060E0: beq         $s1, $zero, L_800060F8
    if (ctx->r17 == 0) {
        // 0x800060E4: sll         $t6, $s2, 2
        ctx->r14 = S32(ctx->r18 << 2);
            goto L_800060F8;
    }
    // 0x800060E4: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x800060E8: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x800060EC: sw          $s1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r17;
    // 0x800060F0: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800060F4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800060F8:
    // 0x800060F8: b           L_80006124
    // 0x800060FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80006124;
    // 0x800060FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80006100:
    // 0x80006100: bne         $s1, $zero, L_80006124
    if (ctx->r17 != 0) {
        // 0x80006104: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80006124;
    }
    // 0x80006104: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80006108: beq         $s2, $zero, L_80006124
    if (ctx->r18 == 0) {
        // 0x8000610C: addiu       $v0, $s2, -0x1
        ctx->r2 = ADD32(ctx->r18, -0X1);
            goto L_80006124;
    }
    // 0x8000610C: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x80006110: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80006114: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x80006118: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x8000611C: b           L_80006124
    // 0x80006120: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_80006124;
    // 0x80006120: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80006124:
    // 0x80006124: bnel        $s0, $zero, L_800060CC
    if (ctx->r16 != 0) {
        // 0x80006128: lw          $s1, 0x0($s0)
        ctx->r17 = MEM_W(ctx->r16, 0X0);
            goto L_800060CC;
    }
    goto skip_1;
    // 0x80006128: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    skip_1:
L_8000612C:
    // 0x8000612C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80006130:
    // 0x80006130: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80006134: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80006138: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000613C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80006140: jr          $ra
    // 0x80006144: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80006144: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80006148(rdram, ctx);
;}
RECOMP_FUNC void FUN_80006148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006148: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000614C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80006150: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006154: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80006158: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x8000615C: lw          $a3, 0x18($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X18);
    // 0x80006160: lw          $s0, 0xC($a0)
    ctx->r16 = MEM_W(ctx->r4, 0XC);
    // 0x80006164: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80006168: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x8000616C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80006170: jal         0x80006088
    // 0x80006174: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_0;
    // 0x80006174: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x80006178: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8000617C: beq         $s0, $zero, L_80006198
    if (ctx->r16 == 0) {
        // 0x80006180: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_80006198;
    }
    // 0x80006180: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80006184: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80006188: jal         0x80005FAC
    // 0x8000618C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_1;
    // 0x8000618C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80006190: b           L_800061A8
    // 0x80006194: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800061A8;
    // 0x80006194: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80006198:
    // 0x80006198: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000619C: jal         0x80005E44
    // 0x800061A0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_2;
    // 0x800061A0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x800061A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800061A8:
    // 0x800061A8: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x800061AC: beql        $v1, $zero, L_800061C0
    if (ctx->r3 == 0) {
        // 0x800061B0: lw          $v1, 0x10($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X10);
            goto L_800061C0;
    }
    goto skip_0;
    // 0x800061B0: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x800061B4: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x800061B8: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
    // 0x800061BC: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
L_800061C0:
    // 0x800061C0: beql        $v1, $zero, L_800061D4
    if (ctx->r3 == 0) {
        // 0x800061C4: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_800061D4;
    }
    goto skip_1;
    // 0x800061C4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800061C8: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x800061CC: sw          $t9, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r25;
    // 0x800061D0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_800061D4:
    // 0x800061D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800061D8: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x800061DC: beq         $v1, $zero, L_800061EC
    if (ctx->r3 == 0) {
        // 0x800061E0: sw          $a0, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r4;
            goto L_800061EC;
    }
    // 0x800061E0: sw          $a0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r4;
    // 0x800061E4: b           L_800061F4
    // 0x800061E8: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
        goto L_800061F4;
    // 0x800061E8: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
L_800061EC:
    // 0x800061EC: lw          $t0, 0x18($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X18);
    // 0x800061F0: sw          $v0, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r2;
L_800061F4:
    // 0x800061F4: beql        $a0, $zero, L_80006204
    if (ctx->r4 == 0) {
        // 0x800061F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80006204;
    }
    goto skip_2;
    // 0x800061F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800061FC: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x80006200: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80006204:
    // 0x80006204: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80006208: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000620C: jr          $ra
    // 0x80006210: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80006210: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80006214(rdram, ctx);
;}
RECOMP_FUNC void FUN_80006214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006214: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80006218: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8000621C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80006220: beq         $v0, $zero, L_80006240
    if (ctx->r2 == 0) {
        // 0x80006224: addiu       $a0, $a0, -0x2578
        ctx->r4 = ADD32(ctx->r4, -0X2578);
            goto L_80006240;
    }
    // 0x80006224: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x80006228: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8000622C:
    // 0x8000622C: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80006230: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80006234: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80006238: bnel        $v0, $zero, L_8000622C
    if (ctx->r2 != 0) {
        // 0x8000623C: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_8000622C;
    }
    goto skip_0;
    // 0x8000623C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    skip_0:
L_80006240:
    // 0x80006240: jr          $ra
    // 0x80006244: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80006244: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80006248(rdram, ctx);
;}
RECOMP_FUNC void FUN_80006248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006248: beq         $a1, $zero, L_800062CC
    if (ctx->r5 == 0) {
        // 0x8000624C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800062CC;
    }
    // 0x8000624C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80006250: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x80006254: addiu       $a3, $a3, -0x2708
    ctx->r7 = ADD32(ctx->r7, -0X2708);
    // 0x80006258: lhu         $t6, 0x20($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X20);
L_8000625C:
    // 0x8000625C: beq         $a0, $t6, L_800062CC
    if (ctx->r4 == ctx->r14) {
        // 0x80006260: nop
    
            goto L_800062CC;
    }
    // 0x80006260: nop

    // 0x80006264: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x80006268: beql        $v1, $zero, L_8000629C
    if (ctx->r3 == 0) {
        // 0x8000626C: lw          $a2, 0x0($a1)
        ctx->r6 = MEM_W(ctx->r5, 0X0);
            goto L_8000629C;
    }
    goto skip_0;
    // 0x8000626C: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80006270: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x80006274: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80006278: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8000627C: beq         $a2, $zero, L_80006290
    if (ctx->r6 == 0) {
        // 0x80006280: nop
    
            goto L_80006290;
    }
    // 0x80006280: nop

    // 0x80006284: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x80006288: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x8000628C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80006290:
    // 0x80006290: b           L_800062C4
    // 0x80006294: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_800062C4;
    // 0x80006294: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80006298: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
L_8000629C:
    // 0x8000629C: bne         $a2, $zero, L_800062C4
    if (ctx->r6 != 0) {
        // 0x800062A0: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_800062C4;
    }
    // 0x800062A0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800062A4: beq         $v0, $zero, L_800062C4
    if (ctx->r2 == 0) {
        // 0x800062A8: nop
    
            goto L_800062C4;
    }
    // 0x800062A8: nop

    // 0x800062AC: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // 0x800062B0: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800062B4: addu        $t0, $a3, $t9
    ctx->r8 = ADD32(ctx->r7, ctx->r25);
    // 0x800062B8: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800062BC: b           L_800062C4
    // 0x800062C0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_800062C4;
    // 0x800062C0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800062C4:
    // 0x800062C4: bnel        $a1, $zero, L_8000625C
    if (ctx->r5 != 0) {
        // 0x800062C8: lhu         $t6, 0x20($a1)
        ctx->r14 = MEM_HU(ctx->r5, 0X20);
            goto L_8000625C;
    }
    goto skip_1;
    // 0x800062C8: lhu         $t6, 0x20($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X20);
    skip_1:
L_800062CC:
    // 0x800062CC: jr          $ra
    // 0x800062D0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800062D0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800062d4(rdram, ctx);
;}
RECOMP_FUNC void FUN_800062d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800062D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800062D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800062DC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x800062E0: jal         0x80006248
    // 0x800062E4: addiu       $a1, $a1, -0x6BD4
    ctx->r5 = ADD32(ctx->r5, -0X6BD4);
    LOOKUP_FUNC(0x80006248)(rdram, ctx);
        goto after_0;
    // 0x800062E4: addiu       $a1, $a1, -0x6BD4
    ctx->r5 = ADD32(ctx->r5, -0X6BD4);
    after_0:
    // 0x800062E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800062EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800062F0: jr          $ra
    // 0x800062F4: nop

    return;
    // 0x800062F4: nop

;}
RECOMP_FUNC void FUN_800062f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800062F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800062FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006300: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80006304: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80006308: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000630C: bnel        $t6, $zero, L_80006320
    if (ctx->r14 != 0) {
        // 0x80006310: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80006320;
    }
    goto skip_0;
    // 0x80006310: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x80006314: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80006318: beq         $t7, $zero, L_80006360
    if (ctx->r15 == 0) {
        // 0x8000631C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80006360;
    }
    // 0x8000631C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80006320:
    // 0x80006320: jal         0x8000659C
    // 0x80006324: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8000659C)(rdram, ctx);
        goto after_0;
    // 0x80006324: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80006328: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8000632C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80006330: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80006334: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    // 0x80006338: addiu       $a0, $a0, -0x6BD4
    ctx->r4 = ADD32(ctx->r4, -0X6BD4);
    // 0x8000633C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80006340: bne         $v0, $zero, L_80006358
    if (ctx->r2 != 0) {
        // 0x80006344: sw          $t8, 0x24($a2)
        MEM_W(0X24, ctx->r6) = ctx->r24;
            goto L_80006358;
    }
    // 0x80006344: sw          $t8, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r24;
    // 0x80006348: jal         0x80006414
    // 0x8000634C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(0x80006414)(rdram, ctx);
        goto after_1;
    // 0x8000634C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
    // 0x80006350: b           L_80006364
    // 0x80006354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006364;
    // 0x80006354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006358:
    // 0x80006358: jal         0x80006414
    // 0x8000635C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    LOOKUP_FUNC(0x80006414)(rdram, ctx);
        goto after_2;
    // 0x8000635C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    after_2:
L_80006360:
    // 0x80006360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006364:
    // 0x80006364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006368: jr          $ra
    // 0x8000636C: nop

    return;
    // 0x8000636C: nop

;}
RECOMP_FUNC void FUN_80006370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006370: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80006374: beql        $v0, $zero, L_800063AC
    if (ctx->r2 == 0) {
        // 0x80006378: sw          $a1, 0x24($a0)
        MEM_W(0X24, ctx->r4) = ctx->r5;
            goto L_800063AC;
    }
    goto skip_0;
    // 0x80006378: sw          $a1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r5;
    skip_0:
    // 0x8000637C: beq         $v0, $zero, L_800063A0
    if (ctx->r2 == 0) {
        // 0x80006380: addiu       $v1, $a0, 0x24
        ctx->r3 = ADD32(ctx->r4, 0X24);
            goto L_800063A0;
    }
    // 0x80006380: addiu       $v1, $a0, 0x24
    ctx->r3 = ADD32(ctx->r4, 0X24);
    // 0x80006384: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80006388: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
L_8000638C:
    // 0x8000638C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80006390: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x80006394: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80006398: bnel        $v0, $zero, L_8000638C
    if (ctx->r2 != 0) {
        // 0x8000639C: sw          $v0, 0x14($a1)
        MEM_W(0X14, ctx->r5) = ctx->r2;
            goto L_8000638C;
    }
    goto skip_1;
    // 0x8000639C: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    skip_1:
L_800063A0:
    // 0x800063A0: b           L_800063B0
    // 0x800063A4: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
        goto L_800063B0;
    // 0x800063A4: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800063A8: sw          $a1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r5;
L_800063AC:
    // 0x800063AC: sw          $zero, 0x14($a1)
    MEM_W(0X14, ctx->r5) = 0;
L_800063B0:
    // 0x800063B0: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x800063B4: jr          $ra
    // 0x800063B8: sw          $a0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r4;
    return;
    // 0x800063B8: sw          $a0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800063bc(rdram, ctx);
;}
RECOMP_FUNC void FUN_800063bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800063BC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800063C0: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x800063C4: lw          $v0, 0xB0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XB0);
    // 0x800063C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800063CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800063D0: beq         $v0, $zero, L_80006400
    if (ctx->r2 == 0) {
        // 0x800063D4: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80006400;
    }
    // 0x800063D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800063D8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800063DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800063E0: sw          $t6, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r14;
    // 0x800063E4: sw          $a2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r6;
    // 0x800063E8: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800063EC: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x800063F0: jal         0x80006414
    // 0x800063F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80006414)(rdram, ctx);
        goto after_0;
    // 0x800063F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800063F8: b           L_80006404
    // 0x800063FC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_80006404;
    // 0x800063FC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80006400:
    // 0x80006400: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80006404:
    // 0x80006404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006408: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000640C: jr          $ra
    // 0x80006410: nop

    return;
    // 0x80006410: nop

;}
RECOMP_FUNC void FUN_80006414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006414: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    // 0x80006418: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8000641C: sltu        $at, $t6, $v0
    ctx->r1 = ctx->r14 < ctx->r2 ? 1 : 0;
    // 0x80006420: beql        $at, $zero, L_80006478
    if (ctx->r1 == 0) {
        // 0x80006424: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_80006478;
    }
    goto skip_0;
    // 0x80006424: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80006428: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x8000642C: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x80006430: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80006434: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x80006438: sw          $t8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r24;
    // 0x8000643C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80006440: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80006444: beql        $v0, $zero, L_80006454
    if (ctx->r2 == 0) {
        // 0x80006448: lw          $t9, 0xC($a1)
        ctx->r25 = MEM_W(ctx->r5, 0XC);
            goto L_80006454;
    }
    goto skip_1;
    // 0x80006448: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    skip_1:
    // 0x8000644C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80006450: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
L_80006454:
    // 0x80006454: beq         $t9, $zero, L_800064BC
    if (ctx->r25 == 0) {
        // 0x80006458: nop
    
            goto L_800064BC;
    }
    // 0x80006458: nop

    // 0x8000645C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80006460: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80006464: bne         $a0, $t0, L_800064BC
    if (ctx->r4 != ctx->r8) {
        // 0x80006468: nop
    
            goto L_800064BC;
    }
    // 0x80006468: nop

    // 0x8000646C: jr          $ra
    // 0x80006470: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    return;
    // 0x80006470: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
L_80006474:
    // 0x80006474: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_80006478:
    // 0x80006478: beql        $v1, $zero, L_8000649C
    if (ctx->r3 == 0) {
        // 0x8000647C: sw          $v1, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r3;
            goto L_8000649C;
    }
    goto skip_2;
    // 0x8000647C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    skip_2:
    // 0x80006480: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
    // 0x80006484: sltu        $at, $t1, $v0
    ctx->r1 = ctx->r9 < ctx->r2 ? 1 : 0;
    // 0x80006488: bnel        $at, $zero, L_8000649C
    if (ctx->r1 != 0) {
        // 0x8000648C: sw          $v1, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r3;
            goto L_8000649C;
    }
    goto skip_3;
    // 0x8000648C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    skip_3:
    // 0x80006490: b           L_80006474
    // 0x80006494: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_80006474;
    // 0x80006494: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80006498: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_8000649C:
    // 0x8000649C: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x800064A0: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x800064A4: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x800064A8: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800064AC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800064B0: beq         $v0, $zero, L_800064BC
    if (ctx->r2 == 0) {
        // 0x800064B4: nop
    
            goto L_800064BC;
    }
    // 0x800064B4: nop

    // 0x800064B8: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
L_800064BC:
    // 0x800064BC: jr          $ra
    // 0x800064C0: nop

    return;
    // 0x800064C0: nop

;}
RECOMP_FUNC void FUN_800064c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800064C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800064C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800064CC: jal         0x8000659C
    // 0x800064D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8000659C)(rdram, ctx);
        goto after_0;
    // 0x800064D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800064D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800064D8: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x800064DC: beql        $v0, $zero, L_800064F4
    if (ctx->r2 == 0) {
        // 0x800064E0: lw          $t7, 0x10($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X10);
            goto L_800064F4;
    }
    goto skip_0;
    // 0x800064E0: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    skip_0:
    // 0x800064E4: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x800064E8: b           L_800064FC
    // 0x800064EC: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
        goto L_800064FC;
    // 0x800064EC: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    // 0x800064F0: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
L_800064F4:
    // 0x800064F4: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x800064F8: sw          $t7, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r15;
L_800064FC:
    // 0x800064FC: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80006500: beq         $v0, $zero, L_80006510
    if (ctx->r2 == 0) {
        // 0x80006504: nop
    
            goto L_80006510;
    }
    // 0x80006504: nop

    // 0x80006508: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x8000650C: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
L_80006510:
    // 0x80006510: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80006514: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x80006518: lw          $t0, 0xB0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XB0);
    // 0x8000651C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80006520: sw          $a0, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = ctx->r4;
    // 0x80006524: lw          $v1, 0x2C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X2C);
    // 0x80006528: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x8000652C: beql        $v1, $zero, L_8000655C
    if (ctx->r3 == 0) {
        // 0x80006530: lw          $v1, 0x30($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X30);
            goto L_8000655C;
    }
    goto skip_1;
    // 0x80006530: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
    skip_1:
    // 0x80006534: lw          $t1, 0xB8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XB8);
    // 0x80006538: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x8000653C: lw          $t4, 0xC0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC0);
    // 0x80006540: subu        $t2, $v1, $t1
    ctx->r10 = SUB32(ctx->r3, ctx->r9);
    // 0x80006544: divu        $zero, $t2, $at
    lo = S32(U32(ctx->r10) / U32(ctx->r1)); hi = S32(U32(ctx->r10) % U32(ctx->r1));
    // 0x80006548: mflo        $t3
    ctx->r11 = lo;
    // 0x8000654C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80006550: b           L_80006584
    // 0x80006554: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
        goto L_80006584;
    // 0x80006554: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x80006558: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
L_8000655C:
    // 0x8000655C: beql        $v1, $zero, L_80006588
    if (ctx->r3 == 0) {
        // 0x80006560: sw          $zero, 0x2C($a0)
        MEM_W(0X2C, ctx->r4) = 0;
            goto L_80006588;
    }
    goto skip_2;
    // 0x80006560: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    skip_2:
    // 0x80006564: lw          $t6, 0xBC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XBC);
    // 0x80006568: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x8000656C: lw          $t9, 0xC4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC4);
    // 0x80006570: subu        $t7, $v1, $t6
    ctx->r15 = SUB32(ctx->r3, ctx->r14);
    // 0x80006574: divu        $zero, $t7, $at
    lo = S32(U32(ctx->r15) / U32(ctx->r1)); hi = S32(U32(ctx->r15) % U32(ctx->r1));
    // 0x80006578: mflo        $t8
    ctx->r24 = lo;
    // 0x8000657C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80006580: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_80006584:
    // 0x80006584: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
L_80006588:
    // 0x80006588: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x8000658C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006590: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006594: jr          $ra
    // 0x80006598: nop

    return;
    // 0x80006598: nop

;}
RECOMP_FUNC void FUN_8000659c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000659C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800065A0: beql        $v0, $zero, L_800065B4
    if (ctx->r2 == 0) {
        // 0x800065A4: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_800065B4;
    }
    goto skip_0;
    // 0x800065A4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800065A8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800065AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800065B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800065B4:
    // 0x800065B4: beql        $v0, $zero, L_800065C8
    if (ctx->r2 == 0) {
        // 0x800065B8: lw          $v0, 0xC($a0)
        ctx->r2 = MEM_W(ctx->r4, 0XC);
            goto L_800065C8;
    }
    goto skip_1;
    // 0x800065B8: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    skip_1:
    // 0x800065BC: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800065C0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800065C4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
L_800065C8:
    // 0x800065C8: beq         $v0, $zero, L_800065E4
    if (ctx->r2 == 0) {
        // 0x800065CC: nop
    
            goto L_800065E4;
    }
    // 0x800065CC: nop

    // 0x800065D0: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800065D4: bne         $a0, $t8, L_800065E4
    if (ctx->r4 != ctx->r24) {
        // 0x800065D8: nop
    
            goto L_800065E4;
    }
    // 0x800065D8: nop

    // 0x800065DC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800065E0: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
L_800065E4:
    // 0x800065E4: jr          $ra
    // 0x800065E8: nop

    return;
    // 0x800065E8: nop

;}
RECOMP_FUNC void FUN_800065ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800065EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800065F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800065F4: lhu         $t6, 0xA($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XA);
    // 0x800065F8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800065FC: sh          $t6, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r14;
    // 0x80006600: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80006604: andi        $t0, $t6, 0xFFFF
    ctx->r8 = ctx->r14 & 0XFFFF;
    // 0x80006608: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8000660C: sh          $t7, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r15;
    // 0x80006610: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80006614: sltiu       $at, $t1, 0xD
    ctx->r1 = ctx->r9 < 0XD ? 1 : 0;
    // 0x80006618: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8000661C: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x80006620: lhu         $t9, 0x8($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X8);
    // 0x80006624: beq         $at, $zero, L_80006708
    if (ctx->r1 == 0) {
        // 0x80006628: sh          $t9, 0x28($a0)
        MEM_H(0X28, ctx->r4) = ctx->r25;
            goto L_80006708;
    }
    // 0x80006628: sh          $t9, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r25;
    // 0x8000662C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80006630: addu        $at, $at, $t1
    gpr jr_addend_80006638 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80006634: lw          $t1, -0x3C18($at)
    ctx->r9 = ADD32(ctx->r1, -0X3C18);
    // 0x80006638: jr          $t1
    // 0x8000663C: nop

    switch (jr_addend_80006638 >> 2) {
        case 0: goto L_80006640; break;
        case 1: goto L_80006650; break;
        case 2: goto L_80006660; break;
        case 3: goto L_80006670; break;
        case 4: goto L_80006680; break;
        case 5: goto L_80006690; break;
        case 6: goto L_800066B0; break;
        case 7: goto L_800066D0; break;
        case 8: goto L_800066E0; break;
        case 9: goto L_800066F0; break;
        case 10: goto L_80006700; break;
        case 11: goto L_800066A0; break;
        case 12: goto L_800066C0; break;
        default: switch_error(__func__, 0x80006638, 0x8004C3E8);
    }
    // 0x8000663C: nop

L_80006640:
    // 0x80006640: jal         0x80007BD0
    // 0x80006644: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    LOOKUP_FUNC(0x80007BD0)(rdram, ctx);
        goto after_0;
    // 0x80006644: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    after_0:
    // 0x80006648: b           L_8000670C
    // 0x8000664C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000670C;
    // 0x8000664C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006650:
    // 0x80006650: jal         0x800080D4
    // 0x80006654: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    LOOKUP_FUNC(0x800080D4)(rdram, ctx);
        goto after_1;
    // 0x80006654: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    after_1:
    // 0x80006658: b           L_8000670C
    // 0x8000665C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000670C;
    // 0x8000665C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006660:
    // 0x80006660: jal         0x800085A0
    // 0x80006664: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    LOOKUP_FUNC(0x800085A0)(rdram, ctx);
        goto after_2;
    // 0x80006664: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    after_2:
    // 0x80006668: b           L_8000670C
    // 0x8000666C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000670C;
    // 0x8000666C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006670:
    // 0x80006670: jal         0x80008A0C
    // 0x80006674: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    LOOKUP_FUNC(0x80008A0C)(rdram, ctx);
        goto after_3;
    // 0x80006674: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    after_3:
    // 0x80006678: b           L_8000670C
    // 0x8000667C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000670C;
    // 0x8000667C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006680:
    // 0x80006680: jal         0x80008E60
    // 0x80006684: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    LOOKUP_FUNC(0x80008E60)(rdram, ctx);
        goto after_4;
    // 0x80006684: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    after_4:
    // 0x80006688: b           L_8000670C
    // 0x8000668C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000670C;
    // 0x8000668C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006690:
    // 0x80006690: jal         0x8000B960
    // 0x80006694: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    LOOKUP_FUNC(0x8000B960)(rdram, ctx);
        goto after_5;
    // 0x80006694: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    after_5:
    // 0x80006698: b           L_8000670C
    // 0x8000669C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000670C;
    // 0x8000669C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800066A0:
    // 0x800066A0: jal         0x8000BAD8
    // 0x800066A4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    LOOKUP_FUNC(0x8000BAD8)(rdram, ctx);
        goto after_6;
    // 0x800066A4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    after_6:
    // 0x800066A8: b           L_8000670C
    // 0x800066AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000670C;
    // 0x800066AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800066B0:
    // 0x800066B0: jal         0x8000D100
    // 0x800066B4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    LOOKUP_FUNC(0x8000D100)(rdram, ctx);
        goto after_7;
    // 0x800066B4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    after_7:
    // 0x800066B8: b           L_8000670C
    // 0x800066BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000670C;
    // 0x800066BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800066C0:
    // 0x800066C0: jal         0x80011900
    // 0x800066C4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    LOOKUP_FUNC(0x80011900)(rdram, ctx);
        goto after_8;
    // 0x800066C4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    after_8:
    // 0x800066C8: b           L_8000670C
    // 0x800066CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000670C;
    // 0x800066CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800066D0:
    // 0x800066D0: jal         0x8000A780
    // 0x800066D4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    LOOKUP_FUNC(0x8000A780)(rdram, ctx);
        goto after_9;
    // 0x800066D4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    after_9:
    // 0x800066D8: b           L_8000670C
    // 0x800066DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000670C;
    // 0x800066DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800066E0:
    // 0x800066E0: jal         0x80009190
    // 0x800066E4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    LOOKUP_FUNC(0x80009190)(rdram, ctx);
        goto after_10;
    // 0x800066E4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    after_10:
    // 0x800066E8: b           L_8000670C
    // 0x800066EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000670C;
    // 0x800066EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800066F0:
    // 0x800066F0: jal         0x8000A060
    // 0x800066F4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    LOOKUP_FUNC(0x8000A060)(rdram, ctx);
        goto after_11;
    // 0x800066F4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    after_11:
    // 0x800066F8: b           L_8000670C
    // 0x800066FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000670C;
    // 0x800066FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006700:
    // 0x80006700: jal         0x80013730
    // 0x80006704: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    LOOKUP_FUNC(0x80013730)(rdram, ctx);
        goto after_12;
    // 0x80006704: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    after_12:
L_80006708:
    // 0x80006708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000670C:
    // 0x8000670C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80006714: jr          $ra
    // 0x80006718: nop

    return;
    // 0x80006718: nop

;}
RECOMP_FUNC void FUN_8000671c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000671C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80006720: addiu       $a1, $a1, -0x2A38
    ctx->r5 = ADD32(ctx->r5, -0X2A38);
    // 0x80006724: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80006728: lw          $t6, -0x2A34($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2A34);
    // 0x8000672C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80006730: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x80006734: beq         $at, $zero, L_80006748
    if (ctx->r1 == 0) {
        // 0x80006738: addiu       $t7, $v1, 0x40
        ctx->r15 = ADD32(ctx->r3, 0X40);
            goto L_80006748;
    }
    // 0x80006738: addiu       $t7, $v1, 0x40
    ctx->r15 = ADD32(ctx->r3, 0X40);
    // 0x8000673C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80006740: jr          $ra
    // 0x80006744: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80006744: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80006748:
    // 0x80006748: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000674C: jr          $ra
    // 0x80006750: nop

    return;
    // 0x80006750: nop

;}
RECOMP_FUNC void FUN_80006754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006754: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80006758: addiu       $a1, $a1, -0x2A40
    ctx->r5 = ADD32(ctx->r5, -0X2A40);
    // 0x8000675C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80006760: lw          $t6, -0x2A3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2A3C);
    // 0x80006764: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80006768: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x8000676C: beq         $at, $zero, L_80006780
    if (ctx->r1 == 0) {
        // 0x80006770: addiu       $t7, $v1, 0x10
        ctx->r15 = ADD32(ctx->r3, 0X10);
            goto L_80006780;
    }
    // 0x80006770: addiu       $t7, $v1, 0x10
    ctx->r15 = ADD32(ctx->r3, 0X10);
    // 0x80006774: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80006778: jr          $ra
    // 0x8000677C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000677C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80006780:
    // 0x80006780: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80006784: jr          $ra
    // 0x80006788: nop

    return;
    // 0x80006788: nop

    // 0x8000678C: nop

;}
RECOMP_FUNC void FUN_80006790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006790: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80006794: addiu       $a0, $a0, -0x2A44
    ctx->r4 = ADD32(ctx->r4, -0X2A44);
    // 0x80006798: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000679C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800067A0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800067A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800067A8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800067AC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800067B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800067B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800067B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800067BC: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x800067C0: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x800067C4: addiu       $s3, $s3, -0x6D50
    ctx->r19 = ADD32(ctx->r19, -0X6D50);
    // 0x800067C8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800067CC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800067D0: lh          $t8, 0x9E($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X9E);
    // 0x800067D4: bne         $t8, $zero, L_800067E4
    if (ctx->r24 != 0) {
        // 0x800067D8: nop
    
            goto L_800067E4;
    }
    // 0x800067D8: nop

    // 0x800067DC: jal         0x800079B0
    // 0x800067E0: nop

    LOOKUP_FUNC(0x800079B0)(rdram, ctx);
        goto after_0;
    // 0x800067E0: nop

    after_0:
L_800067E4:
    // 0x800067E4: jal         0x80007750
    // 0x800067E8: nop

    LOOKUP_FUNC(0x80007750)(rdram, ctx);
        goto after_1;
    // 0x800067E8: nop

    after_1:
    // 0x800067EC: lh          $t9, 0xA0($s3)
    ctx->r25 = MEM_H(ctx->r19, 0XA0);
    // 0x800067F0: bnel        $t9, $zero, L_80006804
    if (ctx->r25 != 0) {
        // 0x800067F4: lh          $t0, 0xA4($s3)
        ctx->r8 = MEM_H(ctx->r19, 0XA4);
            goto L_80006804;
    }
    goto skip_0;
    // 0x800067F4: lh          $t0, 0xA4($s3)
    ctx->r8 = MEM_H(ctx->r19, 0XA4);
    skip_0:
    // 0x800067F8: jal         0x800078AC
    // 0x800067FC: nop

    LOOKUP_FUNC(0x800078AC)(rdram, ctx);
        goto after_2;
    // 0x800067FC: nop

    after_2:
    // 0x80006800: lh          $t0, 0xA4($s3)
    ctx->r8 = MEM_H(ctx->r19, 0XA4);
L_80006804:
    // 0x80006804: ori         $s1, $zero, 0x8000
    ctx->r17 = 0 | 0X8000;
    // 0x80006808: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000680C: bnel        $t0, $zero, L_800068A8
    if (ctx->r8 != 0) {
        // 0x80006810: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800068A8;
    }
    goto skip_1;
    // 0x80006810: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
L_80006814:
    // 0x80006814: lw          $s0, 0x17C($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X17C);
    // 0x80006818: beql        $s0, $zero, L_80006890
    if (ctx->r16 == 0) {
        // 0x8000681C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80006890;
    }
    goto skip_2;
    // 0x8000681C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x80006820: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80006824: sltiu       $at, $t1, -0x2
    ctx->r1 = ctx->r9 < -0X2 ? 1 : 0;
    // 0x80006828: bnel        $at, $zero, L_80006890
    if (ctx->r1 != 0) {
        // 0x8000682C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80006890;
    }
    goto skip_3;
    // 0x8000682C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x80006830: lhu         $t2, 0x2A($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2A);
L_80006834:
    // 0x80006834: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x80006838: beql        $at, $zero, L_80006874
    if (ctx->r1 == 0) {
        // 0x8000683C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80006874;
    }
    goto skip_4;
    // 0x8000683C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x80006840: lhu         $t3, 0x28($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X28);
    // 0x80006844: and         $t4, $t3, $s1
    ctx->r12 = ctx->r11 & ctx->r17;
    // 0x80006848: beql        $t4, $zero, L_80006874
    if (ctx->r12 == 0) {
        // 0x8000684C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80006874;
    }
    goto skip_5;
    // 0x8000684C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_5:
    // 0x80006850: jal         0x80006AB4
    // 0x80006854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006AB4)(rdram, ctx);
        goto after_3;
    // 0x80006854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80006858: beq         $v0, $zero, L_80006870
    if (ctx->r2 == 0) {
        // 0x8000685C: andi        $a0, $s1, 0xFFFF
        ctx->r4 = ctx->r17 & 0XFFFF;
            goto L_80006870;
    }
    // 0x8000685C: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80006860: jal         0x800068C0
    // 0x80006864: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800068C0)(rdram, ctx);
        goto after_4;
    // 0x80006864: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80006868: b           L_80006890
    // 0x8000686C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80006890;
    // 0x8000686C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80006870:
    // 0x80006870: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80006874:
    // 0x80006874: beql        $s0, $zero, L_80006890
    if (ctx->r16 == 0) {
        // 0x80006878: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80006890;
    }
    goto skip_6;
    // 0x80006878: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_6:
    // 0x8000687C: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x80006880: sltiu       $at, $t5, -0x2
    ctx->r1 = ctx->r13 < -0X2 ? 1 : 0;
    // 0x80006884: beql        $at, $zero, L_80006834
    if (ctx->r1 == 0) {
        // 0x80006888: lhu         $t2, 0x2A($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0X2A);
            goto L_80006834;
    }
    goto skip_7;
    // 0x80006888: lhu         $t2, 0x2A($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2A);
    skip_7:
    // 0x8000688C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80006890:
    // 0x80006890: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
    // 0x80006894: slti        $at, $s2, 0x10
    ctx->r1 = SIGNED(ctx->r18) < 0X10 ? 1 : 0;
    // 0x80006898: srl         $s1, $s1, 1
    ctx->r17 = S32(U32(ctx->r17) >> 1);
    // 0x8000689C: bne         $at, $zero, L_80006814
    if (ctx->r1 != 0) {
        // 0x800068A0: andi        $s1, $s1, 0xFFFF
        ctx->r17 = ctx->r17 & 0XFFFF;
            goto L_80006814;
    }
    // 0x800068A0: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x800068A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800068A8:
    // 0x800068A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800068AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800068B0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800068B4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800068B8: jr          $ra
    // 0x800068BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800068BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800068c0(rdram, ctx);
;}
RECOMP_FUNC void FUN_800068c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800068C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800068C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800068C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800068CC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800068D0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800068D4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800068D8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800068DC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800068E0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800068E4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800068E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800068EC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800068F0: beq         $a1, $zero, L_80006988
    if (ctx->r5 == 0) {
        // 0x800068F4: sw          $zero, -0x2AB8($at)
        MEM_W(-0X2AB8, ctx->r1) = 0;
            goto L_80006988;
    }
    // 0x800068F4: sw          $zero, -0x2AB8($at)
    MEM_W(-0X2AB8, ctx->r1) = 0;
    // 0x800068F8: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x800068FC: addiu       $s3, $s3, -0x2A28
    ctx->r19 = ADD32(ctx->r19, -0X2A28);
    // 0x80006900: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80006904: lhu         $t6, 0x28($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X28);
L_80006908:
    // 0x80006908: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8000690C: and         $t7, $t6, $s4
    ctx->r15 = ctx->r14 & ctx->r20;
    // 0x80006910: beql        $t7, $zero, L_80006934
    if (ctx->r15 == 0) {
        // 0x80006914: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_80006934;
    }
    goto skip_0;
    // 0x80006914: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x80006918: jal         0x80006AB4
    // 0x8000691C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006AB4)(rdram, ctx);
        goto after_0;
    // 0x8000691C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80006920: beql        $v0, $zero, L_80006934
    if (ctx->r2 == 0) {
        // 0x80006924: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_80006934;
    }
    goto skip_1;
    // 0x80006924: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x80006928: jal         0x800069A8
    // 0x8000692C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800069A8)(rdram, ctx);
        goto after_1;
    // 0x8000692C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80006930: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_80006934:
    // 0x80006934: beq         $v0, $zero, L_8000695C
    if (ctx->r2 == 0) {
        // 0x80006938: nop
    
            goto L_8000695C;
    }
    // 0x80006938: nop

    // 0x8000693C: beq         $s1, $zero, L_80006954
    if (ctx->r17 == 0) {
        // 0x80006940: sll         $t8, $s2, 2
        ctx->r24 = S32(ctx->r18 << 2);
            goto L_80006954;
    }
    // 0x80006940: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x80006944: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x80006948: sw          $s1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r17;
    // 0x8000694C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80006950: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80006954:
    // 0x80006954: b           L_80006980
    // 0x80006958: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80006980;
    // 0x80006958: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8000695C:
    // 0x8000695C: bne         $s1, $zero, L_80006980
    if (ctx->r17 != 0) {
        // 0x80006960: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80006980;
    }
    // 0x80006960: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80006964: beq         $s2, $zero, L_80006980
    if (ctx->r18 == 0) {
        // 0x80006968: addiu       $v0, $s2, -0x1
        ctx->r2 = ADD32(ctx->r18, -0X1);
            goto L_80006980;
    }
    // 0x80006968: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x8000696C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80006970: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x80006974: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
    // 0x80006978: b           L_80006980
    // 0x8000697C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_80006980;
    // 0x8000697C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80006980:
    // 0x80006980: bnel        $s0, $zero, L_80006908
    if (ctx->r16 != 0) {
        // 0x80006984: lhu         $t6, 0x28($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X28);
            goto L_80006908;
    }
    goto skip_2;
    // 0x80006984: lhu         $t6, 0x28($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X28);
    skip_2:
L_80006988:
    // 0x80006988: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000698C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006990: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80006994: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80006998: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000699C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800069A0: jr          $ra
    // 0x800069A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800069A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800069a8(rdram, ctx);
;}
RECOMP_FUNC void FUN_800069a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800069A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800069AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800069B0: lhu         $t6, 0x2A($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2A);
    // 0x800069B4: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800069B8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800069BC: sltiu       $at, $t7, 0xD
    ctx->r1 = ctx->r15 < 0XD ? 1 : 0;
    // 0x800069C0: beq         $at, $zero, L_80006AA4
    if (ctx->r1 == 0) {
        // 0x800069C4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80006AA4;
    }
    // 0x800069C4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800069C8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800069CC: addu        $at, $at, $t7
    gpr jr_addend_800069D4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800069D0: lw          $t7, -0x3BE0($at)
    ctx->r15 = ADD32(ctx->r1, -0X3BE0);
    // 0x800069D4: jr          $t7
    // 0x800069D8: nop

    switch (jr_addend_800069D4 >> 2) {
        case 0: goto L_800069DC; break;
        case 1: goto L_800069EC; break;
        case 2: goto L_800069FC; break;
        case 3: goto L_80006A0C; break;
        case 4: goto L_80006A1C; break;
        case 5: goto L_80006A2C; break;
        case 6: goto L_80006A4C; break;
        case 7: goto L_80006A6C; break;
        case 8: goto L_80006A7C; break;
        case 9: goto L_80006A8C; break;
        case 10: goto L_80006A9C; break;
        case 11: goto L_80006A3C; break;
        case 12: goto L_80006A5C; break;
        default: switch_error(__func__, 0x800069D4, 0x8004C420);
    }
    // 0x800069D8: nop

L_800069DC:
    // 0x800069DC: jal         0x80007DE4
    // 0x800069E0: nop

    LOOKUP_FUNC(0x80007DE4)(rdram, ctx);
        goto after_0;
    // 0x800069E0: nop

    after_0:
    // 0x800069E4: b           L_80006AA8
    // 0x800069E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006AA8;
    // 0x800069E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800069EC:
    // 0x800069EC: jal         0x800082C4
    // 0x800069F0: nop

    LOOKUP_FUNC(0x800082C4)(rdram, ctx);
        goto after_1;
    // 0x800069F0: nop

    after_1:
    // 0x800069F4: b           L_80006AA8
    // 0x800069F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006AA8;
    // 0x800069F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800069FC:
    // 0x800069FC: jal         0x80008754
    // 0x80006A00: nop

    LOOKUP_FUNC(0x80008754)(rdram, ctx);
        goto after_2;
    // 0x80006A00: nop

    after_2:
    // 0x80006A04: b           L_80006AA8
    // 0x80006A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006AA8;
    // 0x80006A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A0C:
    // 0x80006A0C: jal         0x80008B9C
    // 0x80006A10: nop

    LOOKUP_FUNC(0x80008B9C)(rdram, ctx);
        goto after_3;
    // 0x80006A10: nop

    after_3:
    // 0x80006A14: b           L_80006AA8
    // 0x80006A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006AA8;
    // 0x80006A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A1C:
    // 0x80006A1C: jal         0x80008F30
    // 0x80006A20: nop

    LOOKUP_FUNC(0x80008F30)(rdram, ctx);
        goto after_4;
    // 0x80006A20: nop

    after_4:
    // 0x80006A24: b           L_80006AA8
    // 0x80006A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006AA8;
    // 0x80006A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A2C:
    // 0x80006A2C: jal         0x8000C768
    // 0x80006A30: nop

    LOOKUP_FUNC(0x8000C768)(rdram, ctx);
        goto after_5;
    // 0x80006A30: nop

    after_5:
    // 0x80006A34: b           L_80006AA8
    // 0x80006A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006AA8;
    // 0x80006A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A3C:
    // 0x80006A3C: jal         0x8000C768
    // 0x80006A40: nop

    LOOKUP_FUNC(0x8000C768)(rdram, ctx);
        goto after_6;
    // 0x80006A40: nop

    after_6:
    // 0x80006A44: b           L_80006AA8
    // 0x80006A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006AA8;
    // 0x80006A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A4C:
    // 0x80006A4C: jal         0x8000D1CC
    // 0x80006A50: nop

    LOOKUP_FUNC(0x8000D1CC)(rdram, ctx);
        goto after_7;
    // 0x80006A50: nop

    after_7:
    // 0x80006A54: b           L_80006AA8
    // 0x80006A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006AA8;
    // 0x80006A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A5C:
    // 0x80006A5C: jal         0x80011958
    // 0x80006A60: nop

    LOOKUP_FUNC(0x80011958)(rdram, ctx);
        goto after_8;
    // 0x80006A60: nop

    after_8:
    // 0x80006A64: b           L_80006AA8
    // 0x80006A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006AA8;
    // 0x80006A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A6C:
    // 0x80006A6C: jal         0x8000A828
    // 0x80006A70: nop

    LOOKUP_FUNC(0x8000A828)(rdram, ctx);
        goto after_9;
    // 0x80006A70: nop

    after_9:
    // 0x80006A74: b           L_80006AA8
    // 0x80006A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006AA8;
    // 0x80006A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A7C:
    // 0x80006A7C: jal         0x8000919C
    // 0x80006A80: nop

    LOOKUP_FUNC(0x8000919C)(rdram, ctx);
        goto after_10;
    // 0x80006A80: nop

    after_10:
    // 0x80006A84: b           L_80006AA8
    // 0x80006A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006AA8;
    // 0x80006A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A8C:
    // 0x80006A8C: jal         0x8000A06C
    // 0x80006A90: nop

    LOOKUP_FUNC(0x8000A06C)(rdram, ctx);
        goto after_11;
    // 0x80006A90: nop

    after_11:
    // 0x80006A94: b           L_80006AA8
    // 0x80006A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006AA8;
    // 0x80006A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A9C:
    // 0x80006A9C: jal         0x80013828
    // 0x80006AA0: nop

    LOOKUP_FUNC(0x80013828)(rdram, ctx);
        goto after_12;
    // 0x80006AA0: nop

    after_12:
L_80006AA4:
    // 0x80006AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006AA8:
    // 0x80006AA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006AAC: jr          $ra
    // 0x80006AB0: nop

    return;
    // 0x80006AB0: nop

;}
RECOMP_FUNC void FUN_80006ab4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006AB4: lbu         $v1, 0x22($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X22);
    // 0x80006AB8: beq         $v1, $zero, L_80006AE8
    if (ctx->r3 == 0) {
        // 0x80006ABC: nop
    
            goto L_80006AE8;
    }
    // 0x80006ABC: nop

    // 0x80006AC0: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80006AC4: beq         $t6, $zero, L_80006AE8
    if (ctx->r14 == 0) {
        // 0x80006AC8: nop
    
            goto L_80006AE8;
    }
    // 0x80006AC8: nop

    // 0x80006ACC: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    // 0x80006AD0: lbu         $v1, 0x22($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X22);
L_80006AD4:
    // 0x80006AD4: beq         $v1, $zero, L_80006AE8
    if (ctx->r3 == 0) {
        // 0x80006AD8: nop
    
            goto L_80006AE8;
    }
    // 0x80006AD8: nop

    // 0x80006ADC: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    // 0x80006AE0: bnel        $a0, $zero, L_80006AD4
    if (ctx->r4 != 0) {
        // 0x80006AE4: lbu         $v1, 0x22($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X22);
            goto L_80006AD4;
    }
    goto skip_0;
    // 0x80006AE4: lbu         $v1, 0x22($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X22);
    skip_0:
L_80006AE8:
    // 0x80006AE8: jr          $ra
    // 0x80006AEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80006AEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80006af0(rdram, ctx);
;}
RECOMP_FUNC void FUN_80006af0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006AF0: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80006AF4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80006AF8: lbu         $t6, -0x3CE6($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3CE6);
    // 0x80006AFC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80006B00: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80006B04: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80006B08: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80006B0C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80006B10: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80006B14: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80006B18: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80006B1C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80006B20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80006B24: bne         $t6, $zero, L_80006B38
    if (ctx->r14 != 0) {
        // 0x80006B28: sdc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
            goto L_80006B38;
    }
    // 0x80006B28: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80006B2C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80006B30: lbu         $t7, -0x394A($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X394A);
    // 0x80006B34: beq         $t7, $zero, L_80006F58
    if (ctx->r15 == 0) {
        // 0x80006B38: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_80006F58;
    }
L_80006B38:
    // 0x80006B38: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_80006B3C:
    // 0x80006B3C: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x80006B40: addu        $at, $at, $s7
    ctx->r1 = ADD32(ctx->r1, ctx->r23);
    // 0x80006B44: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80006B48: andi        $s7, $s7, 0xFFFF
    ctx->r23 = ctx->r23 & 0XFFFF;
    // 0x80006B4C: sb          $zero, 0x2D20($at)
    MEM_B(0X2D20, ctx->r1) = 0;
    // 0x80006B50: slti        $at, $s7, 0x3
    ctx->r1 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
    // 0x80006B54: bne         $at, $zero, L_80006B3C
    if (ctx->r1 != 0) {
        // 0x80006B58: nop
    
            goto L_80006B3C;
    }
    // 0x80006B58: nop

    // 0x80006B5C: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80006B60: ori         $s1, $zero, 0x8000
    ctx->r17 = 0 | 0X8000;
    // 0x80006B64: addiu       $s2, $s2, -0x6D50
    ctx->r18 = ADD32(ctx->r18, -0X6D50);
    // 0x80006B68: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_80006B6C:
    // 0x80006B6C: lw          $s0, 0x17C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X17C);
    // 0x80006B70: beql        $s0, $zero, L_80006BE8
    if (ctx->r16 == 0) {
        // 0x80006B74: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_80006BE8;
    }
    goto skip_0;
    // 0x80006B74: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    skip_0:
    // 0x80006B78: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80006B7C: sltiu       $at, $t8, -0x2
    ctx->r1 = ctx->r24 < -0X2 ? 1 : 0;
    // 0x80006B80: bnel        $at, $zero, L_80006BE8
    if (ctx->r1 != 0) {
        // 0x80006B84: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_80006BE8;
    }
    goto skip_1;
    // 0x80006B84: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    skip_1:
    // 0x80006B88: lhu         $t9, 0x2A($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2A);
L_80006B8C:
    // 0x80006B8C: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x80006B90: beql        $at, $zero, L_80006BCC
    if (ctx->r1 == 0) {
        // 0x80006B94: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80006BCC;
    }
    goto skip_2;
    // 0x80006B94: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80006B98: lhu         $t0, 0x28($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X28);
    // 0x80006B9C: and         $t1, $t0, $s1
    ctx->r9 = ctx->r8 & ctx->r17;
    // 0x80006BA0: beql        $t1, $zero, L_80006BCC
    if (ctx->r9 == 0) {
        // 0x80006BA4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80006BCC;
    }
    goto skip_3;
    // 0x80006BA4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x80006BA8: jal         0x80006AB4
    // 0x80006BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006AB4)(rdram, ctx);
        goto after_0;
    // 0x80006BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80006BB0: beq         $v0, $zero, L_80006BC8
    if (ctx->r2 == 0) {
        // 0x80006BB4: andi        $a0, $s1, 0xFFFF
        ctx->r4 = ctx->r17 & 0XFFFF;
            goto L_80006BC8;
    }
    // 0x80006BB4: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80006BB8: jal         0x80006F8C
    // 0x80006BBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006F8C)(rdram, ctx);
        goto after_1;
    // 0x80006BBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80006BC0: b           L_80006BE8
    // 0x80006BC4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
        goto L_80006BE8;
    // 0x80006BC4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_80006BC8:
    // 0x80006BC8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80006BCC:
    // 0x80006BCC: beql        $s0, $zero, L_80006BE8
    if (ctx->r16 == 0) {
        // 0x80006BD0: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_80006BE8;
    }
    goto skip_4;
    // 0x80006BD0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    skip_4:
    // 0x80006BD4: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80006BD8: sltiu       $at, $t2, -0x2
    ctx->r1 = ctx->r10 < -0X2 ? 1 : 0;
    // 0x80006BDC: beql        $at, $zero, L_80006B8C
    if (ctx->r1 == 0) {
        // 0x80006BE0: lhu         $t9, 0x2A($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0X2A);
            goto L_80006B8C;
    }
    goto skip_5;
    // 0x80006BE0: lhu         $t9, 0x2A($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2A);
    skip_5:
    // 0x80006BE4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_80006BE8:
    // 0x80006BE8: andi        $s7, $s7, 0xFFFF
    ctx->r23 = ctx->r23 & 0XFFFF;
    // 0x80006BEC: slti        $at, $s7, 0x10
    ctx->r1 = SIGNED(ctx->r23) < 0X10 ? 1 : 0;
    // 0x80006BF0: srl         $s1, $s1, 1
    ctx->r17 = S32(U32(ctx->r17) >> 1);
    // 0x80006BF4: bne         $at, $zero, L_80006B6C
    if (ctx->r1 != 0) {
        // 0x80006BF8: andi        $s1, $s1, 0xFFFF
        ctx->r17 = ctx->r17 & 0XFFFF;
            goto L_80006B6C;
    }
    // 0x80006BF8: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x80006BFC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80006C00: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80006C04: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80006C08: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80006C0C: addiu       $s6, $zero, 0x84
    ctx->r22 = ADD32(0, 0X84);
    // 0x80006C10: addiu       $s5, $zero, 0x84
    ctx->r21 = ADD32(0, 0X84);
    // 0x80006C14: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80006C18:
    // 0x80006C18: lui         $t3, 0x8006
    ctx->r11 = S32(0X8006 << 16);
    // 0x80006C1C: addiu       $t3, $t3, 0x2D20
    ctx->r11 = ADD32(ctx->r11, 0X2D20);
    // 0x80006C20: addu        $s4, $s7, $t3
    ctx->r20 = ADD32(ctx->r23, ctx->r11);
    // 0x80006C24: lbu         $t4, 0x0($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X0);
    // 0x80006C28: sll         $t5, $s7, 5
    ctx->r13 = S32(ctx->r23 << 5);
    // 0x80006C2C: subu        $t5, $t5, $s7
    ctx->r13 = SUB32(ctx->r13, ctx->r23);
    // 0x80006C30: blez        $t4, L_80006DB4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80006C34: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80006DB4;
    }
    // 0x80006C34: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80006C38: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80006C3C: subu        $t5, $t5, $s7
    ctx->r13 = SUB32(ctx->r13, ctx->r23);
    // 0x80006C40: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x80006C44: addiu       $t6, $t6, -0x2FB0
    ctx->r14 = ADD32(ctx->r14, -0X2FB0);
    // 0x80006C48: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80006C4C: addu        $s3, $t5, $t6
    ctx->r19 = ADD32(ctx->r13, ctx->r14);
L_80006C50:
    // 0x80006C50: multu       $s1, $s6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006C54: mflo        $t7
    ctx->r15 = lo;
    // 0x80006C58: addu        $s0, $s3, $t7
    ctx->r16 = ADD32(ctx->r19, ctx->r15);
    // 0x80006C5C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80006C60: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x80006C64: lhu         $a0, 0x6C($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X6C);
    // 0x80006C68: andi        $t8, $a0, 0x300
    ctx->r24 = ctx->r4 & 0X300;
    // 0x80006C6C: beq         $t8, $zero, L_80006D98
    if (ctx->r24 == 0) {
        // 0x80006C70: andi        $t9, $a0, 0xF0
        ctx->r25 = ctx->r4 & 0XF0;
            goto L_80006D98;
    }
    // 0x80006C70: andi        $t9, $a0, 0xF0
    ctx->r25 = ctx->r4 & 0XF0;
    // 0x80006C74: addiu       $t0, $t9, -0x10
    ctx->r8 = ADD32(ctx->r25, -0X10);
    // 0x80006C78: sltiu       $at, $t0, 0x91
    ctx->r1 = ctx->r8 < 0X91 ? 1 : 0;
    // 0x80006C7C: beq         $at, $zero, L_80006D98
    if (ctx->r1 == 0) {
        // 0x80006C80: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80006D98;
    }
    // 0x80006C80: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80006C84: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80006C88: addu        $at, $at, $t0
    gpr jr_addend_80006C90 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80006C8C: lw          $t0, -0x3B5C($at)
    ctx->r8 = ADD32(ctx->r1, -0X3B5C);
    // 0x80006C90: jr          $t0
    // 0x80006C94: nop

    switch (jr_addend_80006C90 >> 2) {
        case 0: goto L_80006D00; break;
        case 1: goto L_80006D98; break;
        case 2: goto L_80006D98; break;
        case 3: goto L_80006D98; break;
        case 4: goto L_80006D98; break;
        case 5: goto L_80006D98; break;
        case 6: goto L_80006D98; break;
        case 7: goto L_80006D98; break;
        case 8: goto L_80006D98; break;
        case 9: goto L_80006D98; break;
        case 10: goto L_80006D98; break;
        case 11: goto L_80006D98; break;
        case 12: goto L_80006D98; break;
        case 13: goto L_80006D98; break;
        case 14: goto L_80006D98; break;
        case 15: goto L_80006D98; break;
        case 16: goto L_80006CC8; break;
        case 17: goto L_80006D98; break;
        case 18: goto L_80006D98; break;
        case 19: goto L_80006D98; break;
        case 20: goto L_80006D98; break;
        case 21: goto L_80006D98; break;
        case 22: goto L_80006D98; break;
        case 23: goto L_80006D98; break;
        case 24: goto L_80006D98; break;
        case 25: goto L_80006D98; break;
        case 26: goto L_80006D98; break;
        case 27: goto L_80006D98; break;
        case 28: goto L_80006D98; break;
        case 29: goto L_80006D98; break;
        case 30: goto L_80006D98; break;
        case 31: goto L_80006D98; break;
        case 32: goto L_80006C98; break;
        case 33: goto L_80006D98; break;
        case 34: goto L_80006D98; break;
        case 35: goto L_80006D98; break;
        case 36: goto L_80006D98; break;
        case 37: goto L_80006D98; break;
        case 38: goto L_80006D98; break;
        case 39: goto L_80006D98; break;
        case 40: goto L_80006D98; break;
        case 41: goto L_80006D98; break;
        case 42: goto L_80006D98; break;
        case 43: goto L_80006D98; break;
        case 44: goto L_80006D98; break;
        case 45: goto L_80006D98; break;
        case 46: goto L_80006D98; break;
        case 47: goto L_80006D98; break;
        case 48: goto L_80006D30; break;
        case 49: goto L_80006D98; break;
        case 50: goto L_80006D98; break;
        case 51: goto L_80006D98; break;
        case 52: goto L_80006D98; break;
        case 53: goto L_80006D98; break;
        case 54: goto L_80006D98; break;
        case 55: goto L_80006D98; break;
        case 56: goto L_80006D98; break;
        case 57: goto L_80006D98; break;
        case 58: goto L_80006D98; break;
        case 59: goto L_80006D98; break;
        case 60: goto L_80006D98; break;
        case 61: goto L_80006D98; break;
        case 62: goto L_80006D98; break;
        case 63: goto L_80006D98; break;
        case 64: goto L_80006D30; break;
        case 65: goto L_80006D98; break;
        case 66: goto L_80006D98; break;
        case 67: goto L_80006D98; break;
        case 68: goto L_80006D98; break;
        case 69: goto L_80006D98; break;
        case 70: goto L_80006D98; break;
        case 71: goto L_80006D98; break;
        case 72: goto L_80006D98; break;
        case 73: goto L_80006D98; break;
        case 74: goto L_80006D98; break;
        case 75: goto L_80006D98; break;
        case 76: goto L_80006D98; break;
        case 77: goto L_80006D98; break;
        case 78: goto L_80006D98; break;
        case 79: goto L_80006D98; break;
        case 80: goto L_80006D30; break;
        case 81: goto L_80006D98; break;
        case 82: goto L_80006D98; break;
        case 83: goto L_80006D98; break;
        case 84: goto L_80006D98; break;
        case 85: goto L_80006D98; break;
        case 86: goto L_80006D98; break;
        case 87: goto L_80006D98; break;
        case 88: goto L_80006D98; break;
        case 89: goto L_80006D98; break;
        case 90: goto L_80006D98; break;
        case 91: goto L_80006D98; break;
        case 92: goto L_80006D98; break;
        case 93: goto L_80006D98; break;
        case 94: goto L_80006D98; break;
        case 95: goto L_80006D98; break;
        case 96: goto L_80006D30; break;
        case 97: goto L_80006D98; break;
        case 98: goto L_80006D98; break;
        case 99: goto L_80006D98; break;
        case 100: goto L_80006D98; break;
        case 101: goto L_80006D98; break;
        case 102: goto L_80006D98; break;
        case 103: goto L_80006D98; break;
        case 104: goto L_80006D98; break;
        case 105: goto L_80006D98; break;
        case 106: goto L_80006D98; break;
        case 107: goto L_80006D98; break;
        case 108: goto L_80006D98; break;
        case 109: goto L_80006D98; break;
        case 110: goto L_80006D98; break;
        case 111: goto L_80006D98; break;
        case 112: goto L_80006D30; break;
        case 113: goto L_80006D98; break;
        case 114: goto L_80006D98; break;
        case 115: goto L_80006D98; break;
        case 116: goto L_80006D98; break;
        case 117: goto L_80006D98; break;
        case 118: goto L_80006D98; break;
        case 119: goto L_80006D98; break;
        case 120: goto L_80006D98; break;
        case 121: goto L_80006D98; break;
        case 122: goto L_80006D98; break;
        case 123: goto L_80006D98; break;
        case 124: goto L_80006D98; break;
        case 125: goto L_80006D98; break;
        case 126: goto L_80006D98; break;
        case 127: goto L_80006D98; break;
        case 128: goto L_80006D30; break;
        case 129: goto L_80006D98; break;
        case 130: goto L_80006D98; break;
        case 131: goto L_80006D98; break;
        case 132: goto L_80006D98; break;
        case 133: goto L_80006D98; break;
        case 134: goto L_80006D98; break;
        case 135: goto L_80006D98; break;
        case 136: goto L_80006D98; break;
        case 137: goto L_80006D98; break;
        case 138: goto L_80006D98; break;
        case 139: goto L_80006D98; break;
        case 140: goto L_80006D98; break;
        case 141: goto L_80006D98; break;
        case 142: goto L_80006D98; break;
        case 143: goto L_80006D98; break;
        case 144: goto L_80006CEC; break;
        default: switch_error(__func__, 0x80006C90, 0x8004C4A4);
    }
    // 0x80006C94: nop

L_80006C98:
    // 0x80006C98: sb          $s2, 0x80($s0)
    MEM_B(0X80, ctx->r16) = ctx->r18;
    // 0x80006C9C: lw          $t1, 0x2C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X2C);
    // 0x80006CA0: lwc1        $f4, 0x98($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X98);
    // 0x80006CA4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80006CA8: lw          $t2, 0x2C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2C);
    // 0x80006CAC: lwc1        $f6, 0x9C($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X9C);
    // 0x80006CB0: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80006CB4: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
    // 0x80006CB8: lwc1        $f8, 0xA0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XA0);
    // 0x80006CBC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80006CC0: b           L_80006D98
    // 0x80006CC4: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
        goto L_80006D98;
    // 0x80006CC4: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
L_80006CC8:
    // 0x80006CC8: multu       $s1, $s5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006CD0: mflo        $t4
    ctx->r12 = lo;
    // 0x80006CD4: addu        $a1, $s3, $t4
    ctx->r5 = ADD32(ctx->r19, ctx->r12);
    // 0x80006CD8: jal         0x80007328
    // 0x80006CDC: addiu       $a1, $a1, 0x84
    ctx->r5 = ADD32(ctx->r5, 0X84);
    LOOKUP_FUNC(0x80007328)(rdram, ctx);
        goto after_2;
    // 0x80006CDC: addiu       $a1, $a1, 0x84
    ctx->r5 = ADD32(ctx->r5, 0X84);
    after_2:
    // 0x80006CE0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80006CE4: b           L_80006D98
    // 0x80006CE8: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
        goto L_80006D98;
    // 0x80006CE8: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
L_80006CEC:
    // 0x80006CEC: jal         0x8000736C
    // 0x80006CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8000736C)(rdram, ctx);
        goto after_3;
    // 0x80006CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80006CF4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80006CF8: b           L_80006D98
    // 0x80006CFC: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
        goto L_80006D98;
    // 0x80006CFC: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
L_80006D00:
    // 0x80006D00: sb          $s2, 0x80($s0)
    MEM_B(0X80, ctx->r16) = ctx->r18;
    // 0x80006D04: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x80006D08: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80006D0C: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80006D10: lw          $t8, 0x2C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2C);
    // 0x80006D14: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80006D18: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x80006D1C: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x80006D20: lwc1        $f18, 0xC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80006D24: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x80006D28: b           L_80006D98
    // 0x80006D2C: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
        goto L_80006D98;
    // 0x80006D2C: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
L_80006D30:
    // 0x80006D30: sb          $s2, 0x80($s0)
    MEM_B(0X80, ctx->r16) = ctx->r18;
    // 0x80006D34: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x80006D38: lwc1        $f4, 0xA4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XA4);
    // 0x80006D3C: lwc1        $f6, 0x98($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X98);
    // 0x80006D40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006D44: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80006D48: mul.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f20.d);
    // 0x80006D4C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80006D50: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x80006D54: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x80006D58: lwc1        $f4, 0xA8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XA8);
    // 0x80006D5C: lwc1        $f6, 0x9C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X9C);
    // 0x80006D60: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006D64: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80006D68: mul.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f20.d);
    // 0x80006D6C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80006D70: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80006D74: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x80006D78: lwc1        $f4, 0xAC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XAC);
    // 0x80006D7C: lwc1        $f6, 0xA0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XA0);
    // 0x80006D80: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006D84: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80006D88: mul.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f20.d);
    // 0x80006D8C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80006D90: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x80006D94: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
L_80006D98:
    // 0x80006D98: sh          $zero, 0x74($v0)
    MEM_H(0X74, ctx->r2) = 0;
    // 0x80006D9C: lbu         $t0, 0x0($s4)
    ctx->r8 = MEM_BU(ctx->r20, 0X0);
    // 0x80006DA0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80006DA4: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x80006DA8: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80006DAC: bne         $at, $zero, L_80006C50
    if (ctx->r1 != 0) {
        // 0x80006DB0: nop
    
            goto L_80006C50;
    }
    // 0x80006DB0: nop

L_80006DB4:
    // 0x80006DB4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80006DB8: andi        $s7, $s7, 0xFFFF
    ctx->r23 = ctx->r23 & 0XFFFF;
    // 0x80006DBC: slti        $at, $s7, 0x3
    ctx->r1 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
    // 0x80006DC0: bne         $at, $zero, L_80006C18
    if (ctx->r1 != 0) {
        // 0x80006DC4: nop
    
            goto L_80006C18;
    }
    // 0x80006DC4: nop

    // 0x80006DC8: sh          $zero, 0xB2($sp)
    MEM_H(0XB2, ctx->r29) = 0;
    // 0x80006DCC: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_80006DD0:
    // 0x80006DD0: bne         $fp, $zero, L_80006DF8
    if (ctx->r30 != 0) {
        // 0x80006DD4: lui         $t2, 0x801C
        ctx->r10 = S32(0X801C << 16);
            goto L_80006DF8;
    }
    // 0x80006DD4: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80006DD8: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80006DDC: lbu         $t1, -0x3CE6($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X3CE6);
    // 0x80006DE0: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80006DE4: addiu       $s5, $s5, -0x3FC4
    ctx->r21 = ADD32(ctx->r21, -0X3FC4);
    // 0x80006DE8: beql        $t1, $zero, L_80006F44
    if (ctx->r9 == 0) {
        // 0x80006DEC: lhu         $t8, 0xB2($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0XB2);
            goto L_80006F44;
    }
    goto skip_6;
    // 0x80006DEC: lhu         $t8, 0xB2($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XB2);
    skip_6:
    // 0x80006DF0: b           L_80006E10
    // 0x80006DF4: sh          $zero, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = 0;
        goto L_80006E10;
    // 0x80006DF4: sh          $zero, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = 0;
L_80006DF8:
    // 0x80006DF8: lbu         $t2, -0x394A($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X394A);
    // 0x80006DFC: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80006E00: addiu       $s5, $s5, -0x3C28
    ctx->r21 = ADD32(ctx->r21, -0X3C28);
    // 0x80006E04: beql        $t2, $zero, L_80006F44
    if (ctx->r10 == 0) {
        // 0x80006E08: lhu         $t8, 0xB2($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0XB2);
            goto L_80006F44;
    }
    goto skip_7;
    // 0x80006E08: lhu         $t8, 0xB2($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XB2);
    skip_7:
    // 0x80006E0C: sh          $zero, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = 0;
L_80006E10:
    // 0x80006E10: lhu         $t3, 0xB2($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0XB2);
    // 0x80006E14: lui         $t4, 0x8006
    ctx->r12 = S32(0X8006 << 16);
    // 0x80006E18: addiu       $t4, $t4, 0x2D20
    ctx->r12 = ADD32(ctx->r12, 0X2D20);
    // 0x80006E1C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80006E20: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x80006E24: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x80006E28: sll         $t6, $t3, 5
    ctx->r14 = S32(ctx->r11 << 5);
    // 0x80006E2C: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x80006E30: blez        $v0, L_80006F40
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80006E34: sll         $t6, $t6, 4
        ctx->r14 = S32(ctx->r14 << 4);
            goto L_80006F40;
    }
    // 0x80006E34: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80006E38: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x80006E3C: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80006E40: addiu       $t7, $t7, -0x2FB0
    ctx->r15 = ADD32(ctx->r15, -0X2FB0);
    // 0x80006E44: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80006E48: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80006E4C: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
L_80006E50:
    // 0x80006E50: lhu         $t0, 0xB0($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0XB0);
    // 0x80006E54: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80006E58: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80006E5C: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006E60: mflo        $t1
    ctx->r9 = lo;
    // 0x80006E64: addu        $s2, $t9, $t1
    ctx->r18 = ADD32(ctx->r25, ctx->r9);
    // 0x80006E68: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80006E6C: lw          $t4, 0x2C($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X2C);
    // 0x80006E70: lhu         $t5, 0x6C($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6C);
    // 0x80006E74: andi        $t3, $t5, 0x200
    ctx->r11 = ctx->r13 & 0X200;
    // 0x80006E78: beql        $t3, $zero, L_80006F2C
    if (ctx->r11 == 0) {
        // 0x80006E7C: lhu         $t3, 0xB0($sp)
        ctx->r11 = MEM_HU(ctx->r29, 0XB0);
            goto L_80006F2C;
    }
    goto skip_8;
    // 0x80006E7C: lhu         $t3, 0xB0($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0XB0);
    skip_8:
    // 0x80006E80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80006E84:
    // 0x80006E84: beq         $fp, $v0, L_80006F0C
    if (ctx->r30 == ctx->r2) {
        // 0x80006E88: lui         $t6, 0x8006
        ctx->r14 = S32(0X8006 << 16);
            goto L_80006F0C;
    }
    // 0x80006E88: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x80006E8C: addiu       $t6, $t6, 0x2D20
    ctx->r14 = ADD32(ctx->r14, 0X2D20);
    // 0x80006E90: addu        $s4, $s7, $t6
    ctx->r20 = ADD32(ctx->r23, ctx->r14);
    // 0x80006E94: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x80006E98: sll         $t7, $s7, 5
    ctx->r15 = S32(ctx->r23 << 5);
    // 0x80006E9C: subu        $t7, $t7, $s7
    ctx->r15 = SUB32(ctx->r15, ctx->r23);
    // 0x80006EA0: blez        $v0, L_80006F0C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80006EA4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80006F0C;
    }
    // 0x80006EA4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80006EA8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80006EAC: subu        $t7, $t7, $s7
    ctx->r15 = SUB32(ctx->r15, ctx->r23);
    // 0x80006EB0: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80006EB4: addiu       $t8, $t8, -0x2FB0
    ctx->r24 = ADD32(ctx->r24, -0X2FB0);
    // 0x80006EB8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80006EBC: addu        $s3, $t7, $t8
    ctx->r19 = ADD32(ctx->r15, ctx->r24);
L_80006EC0:
    // 0x80006EC0: multu       $s1, $s6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006EC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80006EC8: mflo        $t0
    ctx->r8 = lo;
    // 0x80006ECC: addu        $s0, $s3, $t0
    ctx->r16 = ADD32(ctx->r19, ctx->r8);
    // 0x80006ED0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80006ED4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80006ED8: lw          $t1, 0x2C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X2C);
    // 0x80006EDC: lhu         $t2, 0x6C($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6C);
    // 0x80006EE0: andi        $t4, $t2, 0x100
    ctx->r12 = ctx->r10 & 0X100;
    // 0x80006EE4: beql        $t4, $zero, L_80006EFC
    if (ctx->r12 == 0) {
        // 0x80006EE8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80006EFC;
    }
    goto skip_9;
    // 0x80006EE8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_9:
    // 0x80006EEC: jal         0x800073AC
    // 0x80006EF0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    LOOKUP_FUNC(0x800073AC)(rdram, ctx);
        goto after_4;
    // 0x80006EF0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_4:
    // 0x80006EF4: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x80006EF8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80006EFC:
    // 0x80006EFC: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x80006F00: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80006F04: bne         $at, $zero, L_80006EC0
    if (ctx->r1 != 0) {
        // 0x80006F08: nop
    
            goto L_80006EC0;
    }
    // 0x80006F08: nop

L_80006F0C:
    // 0x80006F0C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80006F10: andi        $s7, $s7, 0xFFFF
    ctx->r23 = ctx->r23 & 0XFFFF;
    // 0x80006F14: slti        $at, $s7, 0x3
    ctx->r1 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
    // 0x80006F18: bne         $at, $zero, L_80006E84
    if (ctx->r1 != 0) {
        // 0x80006F1C: or          $v0, $s7, $zero
        ctx->r2 = ctx->r23 | 0;
            goto L_80006E84;
    }
    // 0x80006F1C: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x80006F20: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80006F24: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x80006F28: lhu         $t3, 0xB0($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0XB0);
L_80006F2C:
    // 0x80006F2C: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x80006F30: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80006F34: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80006F38: bne         $at, $zero, L_80006E50
    if (ctx->r1 != 0) {
        // 0x80006F3C: sh          $t6, 0xB0($sp)
        MEM_H(0XB0, ctx->r29) = ctx->r14;
            goto L_80006E50;
    }
    // 0x80006F3C: sh          $t6, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = ctx->r14;
L_80006F40:
    // 0x80006F40: lhu         $t8, 0xB2($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XB2);
L_80006F44:
    // 0x80006F44: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80006F48: andi        $fp, $t0, 0xFFFF
    ctx->r30 = ctx->r8 & 0XFFFF;
    // 0x80006F4C: slti        $at, $fp, 0x2
    ctx->r1 = SIGNED(ctx->r30) < 0X2 ? 1 : 0;
    // 0x80006F50: bne         $at, $zero, L_80006DD0
    if (ctx->r1 != 0) {
        // 0x80006F54: sh          $t0, 0xB2($sp)
        MEM_H(0XB2, ctx->r29) = ctx->r8;
            goto L_80006DD0;
    }
    // 0x80006F54: sh          $t0, 0xB2($sp)
    MEM_H(0XB2, ctx->r29) = ctx->r8;
L_80006F58:
    // 0x80006F58: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80006F5C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80006F60: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80006F64: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80006F68: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80006F6C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80006F70: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80006F74: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80006F78: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80006F7C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80006F80: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80006F84: jr          $ra
    // 0x80006F88: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80006F88: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80006f8c(rdram, ctx);
;}
RECOMP_FUNC void FUN_80006f8c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006F8C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80006F90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80006F94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006F98: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80006F9C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80006FA0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80006FA4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80006FA8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80006FAC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80006FB0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80006FB4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80006FB8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80006FBC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80006FC0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80006FC4: beq         $a1, $zero, L_800070E4
    if (ctx->r5 == 0) {
        // 0x80006FC8: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800070E4;
    }
    // 0x80006FC8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80006FCC: lui         $s7, 0x8006
    ctx->r23 = S32(0X8006 << 16);
    // 0x80006FD0: lui         $s6, 0x8006
    ctx->r22 = S32(0X8006 << 16);
    // 0x80006FD4: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80006FD8: addiu       $s3, $s3, -0x2A28
    ctx->r19 = ADD32(ctx->r19, -0X2A28);
    // 0x80006FDC: addiu       $s6, $s6, -0x2FB0
    ctx->r22 = ADD32(ctx->r22, -0X2FB0);
    // 0x80006FE0: addiu       $s7, $s7, 0x2D20
    ctx->r23 = ADD32(ctx->r23, 0X2D20);
    // 0x80006FE4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80006FE8: addiu       $fp, $zero, 0x84
    ctx->r30 = ADD32(0, 0X84);
    // 0x80006FEC: addiu       $s5, $zero, 0x6
    ctx->r21 = ADD32(0, 0X6);
    // 0x80006FF0: lhu         $t6, 0x28($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X28);
L_80006FF4:
    // 0x80006FF4: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80006FF8: and         $t7, $t6, $s4
    ctx->r15 = ctx->r14 & ctx->r20;
    // 0x80006FFC: beql        $t7, $zero, L_80007090
    if (ctx->r15 == 0) {
        // 0x80007000: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_80007090;
    }
    goto skip_0;
    // 0x80007000: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x80007004: jal         0x80006AB4
    // 0x80007008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006AB4)(rdram, ctx);
        goto after_0;
    // 0x80007008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000700C: beql        $v0, $zero, L_80007090
    if (ctx->r2 == 0) {
        // 0x80007010: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_80007090;
    }
    goto skip_1;
    // 0x80007010: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x80007014: lhu         $t8, 0x2A($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X2A);
    // 0x80007018: bnel        $s5, $t8, L_80007090
    if (ctx->r21 != ctx->r24) {
        // 0x8000701C: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_80007090;
    }
    goto skip_2;
    // 0x8000701C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x80007020: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x80007024: lhu         $v0, 0x6C($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X6C);
    // 0x80007028: andi        $t0, $v0, 0xF0
    ctx->r8 = ctx->r2 & 0XF0;
    // 0x8000702C: beq         $t0, $zero, L_8000708C
    if (ctx->r8 == 0) {
        // 0x80007030: andi        $t1, $v0, 0x2
        ctx->r9 = ctx->r2 & 0X2;
            goto L_8000708C;
    }
    // 0x80007030: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
    // 0x80007034: beq         $t1, $zero, L_80007044
    if (ctx->r9 == 0) {
        // 0x80007038: andi        $t2, $v0, 0x4
        ctx->r10 = ctx->r2 & 0X4;
            goto L_80007044;
    }
    // 0x80007038: andi        $t2, $v0, 0x4
    ctx->r10 = ctx->r2 & 0X4;
    // 0x8000703C: b           L_80007054
    // 0x80007040: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80007054;
    // 0x80007040: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80007044:
    // 0x80007044: beq         $t2, $zero, L_80007054
    if (ctx->r10 == 0) {
        // 0x80007048: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80007054;
    }
    // 0x80007048: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8000704C: b           L_80007054
    // 0x80007050: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80007054;
    // 0x80007050: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80007054:
    // 0x80007054: addu        $v0, $s7, $a0
    ctx->r2 = ADD32(ctx->r23, ctx->r4);
    // 0x80007058: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000705C: sll         $t3, $a0, 5
    ctx->r11 = S32(ctx->r4 << 5);
    // 0x80007060: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x80007064: multu       $v1, $fp
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80007068: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x8000706C: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x80007070: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80007074: addu        $t4, $s6, $t3
    ctx->r12 = ADD32(ctx->r22, ctx->r11);
    // 0x80007078: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8000707C: mflo        $t5
    ctx->r13 = lo;
    // 0x80007080: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80007084: sw          $s0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r16;
    // 0x80007088: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_8000708C:
    // 0x8000708C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_80007090:
    // 0x80007090: beq         $v0, $zero, L_800070B8
    if (ctx->r2 == 0) {
        // 0x80007094: nop
    
            goto L_800070B8;
    }
    // 0x80007094: nop

    // 0x80007098: beq         $s1, $zero, L_800070B0
    if (ctx->r17 == 0) {
        // 0x8000709C: sll         $t8, $s2, 2
        ctx->r24 = S32(ctx->r18 << 2);
            goto L_800070B0;
    }
    // 0x8000709C: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x800070A0: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x800070A4: sw          $s1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r17;
    // 0x800070A8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800070AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800070B0:
    // 0x800070B0: b           L_800070DC
    // 0x800070B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800070DC;
    // 0x800070B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800070B8:
    // 0x800070B8: bne         $s1, $zero, L_800070DC
    if (ctx->r17 != 0) {
        // 0x800070BC: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800070DC;
    }
    // 0x800070BC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800070C0: beq         $s2, $zero, L_800070DC
    if (ctx->r18 == 0) {
        // 0x800070C4: addiu       $v0, $s2, -0x1
        ctx->r2 = ADD32(ctx->r18, -0X1);
            goto L_800070DC;
    }
    // 0x800070C4: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x800070C8: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x800070CC: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x800070D0: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
    // 0x800070D4: b           L_800070DC
    // 0x800070D8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_800070DC;
    // 0x800070D8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800070DC:
    // 0x800070DC: bnel        $s0, $zero, L_80006FF4
    if (ctx->r16 != 0) {
        // 0x800070E0: lhu         $t6, 0x28($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X28);
            goto L_80006FF4;
    }
    goto skip_3;
    // 0x800070E0: lhu         $t6, 0x28($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X28);
    skip_3:
L_800070E4:
    // 0x800070E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800070E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800070EC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800070F0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800070F4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800070F8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800070FC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80007100: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80007104: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80007108: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000710C: jr          $ra
    // 0x80007110: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80007110: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80007114(rdram, ctx);
;}
RECOMP_FUNC void FUN_80007114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007114: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80007118: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000711C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80007120: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80007124: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80007128: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8000712C: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80007130: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80007134: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80007138: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8000713C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80007140: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80007144: lwc1        $f20, 0x6C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80007148: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000714C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80007150: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80007154: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
    // 0x80007158: lw          $t0, 0x98($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X98);
    // 0x8000715C: addiu       $t1, $sp, 0x48
    ctx->r9 = ADD32(ctx->r29, 0X48);
    // 0x80007160: addiu       $t4, $sp, 0x3C
    ctx->r12 = ADD32(ctx->r29, 0X3C);
    // 0x80007164: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x80007168: lw          $t9, 0x9C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X9C);
    // 0x8000716C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80007170: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80007174: lw          $t0, 0xA0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XA0);
    // 0x80007178: sw          $t0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r8;
    // 0x8000717C: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80007180: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80007184: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80007188: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8000718C: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80007190: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x80007194: sub.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x80007198: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x8000719C: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x800071A0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800071A4: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
    // 0x800071A8: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    // 0x800071AC: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x800071B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800071B4: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x800071B8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800071BC: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x800071C0: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800071C4: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800071C8: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x800071CC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800071D0: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x800071D4: jal         0x800075B4
    // 0x800071D8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x800075B4)(rdram, ctx);
        goto after_0;
    // 0x800071D8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x800071DC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800071E0: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800071E4: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800071E8: swc1        $f0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f0.u32l;
    // 0x800071EC: lw          $t8, 0x2C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X2C);
    // 0x800071F0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800071F4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800071F8: lwc1        $f4, 0x70($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X70);
    // 0x800071FC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80007200: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80007204: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80007208: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8000720C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80007210: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80007214: trunc.w.d   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_D(ctx->f16.d);
    // 0x80007218: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x8000721C: nop

    // 0x80007220: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80007224: sb          $t1, 0x80($s0)
    MEM_B(0X80, ctx->r16) = ctx->r9;
    // 0x80007228: lb          $v0, 0x80($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X80);
    // 0x8000722C: bgtz        $v0, L_80007240
    if (SIGNED(ctx->r2) > 0) {
        // 0x80007230: slti        $at, $v0, 0xB
        ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
            goto L_80007240;
    }
    // 0x80007230: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80007234: sb          $t2, 0x80($s0)
    MEM_B(0X80, ctx->r16) = ctx->r10;
    // 0x80007238: b           L_80007250
    // 0x8000723C: lb          $v0, 0x80($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X80);
        goto L_80007250;
    // 0x8000723C: lb          $v0, 0x80($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X80);
L_80007240:
    // 0x80007240: bne         $at, $zero, L_80007250
    if (ctx->r1 != 0) {
        // 0x80007244: addiu       $t3, $zero, 0xA
        ctx->r11 = ADD32(0, 0XA);
            goto L_80007250;
    }
    // 0x80007244: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80007248: sb          $t3, 0x80($s0)
    MEM_B(0X80, ctx->r16) = ctx->r11;
    // 0x8000724C: lb          $v0, 0x80($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X80);
L_80007250:
    // 0x80007250: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x80007254: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80007258: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8000725C: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80007260: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80007264: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80007268: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000726C: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80007270: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x80007274: lb          $t5, 0x80($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X80);
    // 0x80007278: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8000727C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80007280: nop

    // 0x80007284: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80007288: div.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8000728C: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x80007290: lb          $t6, 0x80($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X80);
    // 0x80007294: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80007298: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8000729C: nop

    // 0x800072A0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800072A4: div.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800072A8: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x800072AC: lb          $t9, 0x80($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X80);
    // 0x800072B0: blez        $t9, L_80007314
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800072B4: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_80007314;
    }
    // 0x800072B4: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
L_800072B8:
    // 0x800072B8: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800072BC: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800072C0: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800072C4: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800072C8: sll         $a0, $v1, 24
    ctx->r4 = S32(ctx->r3 << 24);
    // 0x800072CC: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x800072D0: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800072D4: mflo        $t0
    ctx->r8 = lo;
    // 0x800072D8: addu        $v0, $s0, $t0
    ctx->r2 = ADD32(ctx->r16, ctx->r8);
    // 0x800072DC: add.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800072E0: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x800072E4: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800072E8: mul.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800072EC: add.s       $f6, $f16, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x800072F0: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x800072F4: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800072F8: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800072FC: add.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x80007300: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80007304: lb          $t1, 0x80($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X80);
    // 0x80007308: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000730C: bnel        $at, $zero, L_800072B8
    if (ctx->r1 != 0) {
        // 0x80007310: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_800072B8;
    }
    goto skip_0;
    // 0x80007310: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    skip_0:
L_80007314:
    // 0x80007314: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80007318: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8000731C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80007320: jr          $ra
    // 0x80007324: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80007324: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_80007328(rdram, ctx);
;}
RECOMP_FUNC void FUN_80007328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000732C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007330: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80007334: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80007338: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x8000733C: lw          $t0, 0x98($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X98);
    // 0x80007340: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x80007344: lw          $a2, 0x9C($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X9C);
    // 0x80007348: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8000734C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80007350: lw          $a3, 0xA0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0XA0);
    // 0x80007354: jal         0x80007114
    // 0x80007358: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80007114)(rdram, ctx);
        goto after_0;
    // 0x80007358: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000735C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007364: jr          $ra
    // 0x80007368: nop

    return;
    // 0x80007368: nop

;}
RECOMP_FUNC void FUN_8000736c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000736C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007374: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80007378: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8000737C: lw          $t9, 0xA4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XA4);
    // 0x80007380: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80007384: lw          $a2, 0xA8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XA8);
    // 0x80007388: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8000738C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80007390: lw          $a3, 0xAC($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XAC);
    // 0x80007394: jal         0x80007114
    // 0x80007398: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80007114)(rdram, ctx);
        goto after_0;
    // 0x80007398: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000739C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800073A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800073A4: jr          $ra
    // 0x800073A8: nop

    return;
    // 0x800073A8: nop

;}
RECOMP_FUNC void FUN_800073ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800073AC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800073B0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800073B4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800073B8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800073BC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800073C0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800073C4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800073C8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800073CC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800073D0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800073D4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800073D8: lwc1        $f6, 0x2EC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X2EC);
    // 0x800073DC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800073E0: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x800073E4: lb          $v1, 0x80($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X80);
    // 0x800073E8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x800073EC: lwc1        $f4, 0x70($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X70);
    // 0x800073F0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800073F4: lwc1        $f10, 0x70($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X70);
    // 0x800073F8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800073FC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80007400: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80007404: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x80007408: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8000740C: blez        $v1, L_8000756C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80007410: add.s       $f20, $f8, $f10
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f10.fl;
            goto L_8000756C;
    }
    // 0x80007410: add.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80007414: lb          $v0, 0x80($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X80);
L_80007418:
    // 0x80007418: blez        $v0, L_80007558
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000741C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80007558;
    }
    // 0x8000741C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80007420: sll         $t0, $s4, 2
    ctx->r8 = S32(ctx->r20 << 2);
    // 0x80007424: subu        $t0, $t0, $s4
    ctx->r8 = SUB32(ctx->r8, ctx->r20);
    // 0x80007428: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8000742C: addu        $s1, $s5, $t0
    ctx->r17 = ADD32(ctx->r21, ctx->r8);
    // 0x80007430: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80007434:
    // 0x80007434: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80007438: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8000743C: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x80007440: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x80007444: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x80007448: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000744C: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80007450: mflo        $t3
    ctx->r11 = lo;
    // 0x80007454: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x80007458: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000745C: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x80007460: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x80007464: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80007468: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8000746C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80007470: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x80007474: jal         0x800075B4
    // 0x80007478: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x800075B4)(rdram, ctx);
        goto after_0;
    // 0x80007478: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_0:
    // 0x8000747C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80007480: nop

    // 0x80007484: bc1fl       L_80007540
    if (!c1cs) {
        // 0x80007488: lb          $v0, 0x80($s2)
        ctx->r2 = MEM_B(ctx->r18, 0X80);
            goto L_80007540;
    }
    goto skip_0;
    // 0x80007488: lb          $v0, 0x80($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X80);
    skip_0:
    // 0x8000748C: lbu         $t7, 0x2E8($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X2E8);
    // 0x80007490: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80007494: addiu       $t0, $zero, 0x201
    ctx->r8 = ADD32(0, 0X201);
    // 0x80007498: bnel        $t7, $zero, L_800074AC
    if (ctx->r15 != 0) {
        // 0x8000749C: lw          $t9, 0x0($s5)
        ctx->r25 = MEM_W(ctx->r21, 0X0);
            goto L_800074AC;
    }
    goto skip_1;
    // 0x8000749C: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    skip_1:
    // 0x800074A0: sb          $t8, 0x2E8($s6)
    MEM_B(0X2E8, ctx->r22) = ctx->r24;
    // 0x800074A4: sb          $zero, 0x2DF($s6)
    MEM_B(0X2DF, ctx->r22) = 0;
    // 0x800074A8: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
L_800074AC:
    // 0x800074AC: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x800074B0: lhu         $v1, 0x74($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X74);
    // 0x800074B4: bne         $v1, $zero, L_800074C4
    if (ctx->r3 != 0) {
        // 0x800074B8: addiu       $t1, $v1, 0x1
        ctx->r9 = ADD32(ctx->r3, 0X1);
            goto L_800074C4;
    }
    // 0x800074B8: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x800074BC: b           L_800074C8
    // 0x800074C0: sh          $t0, 0x74($v0)
    MEM_H(0X74, ctx->r2) = ctx->r8;
        goto L_800074C8;
    // 0x800074C0: sh          $t0, 0x74($v0)
    MEM_H(0X74, ctx->r2) = ctx->r8;
L_800074C4:
    // 0x800074C4: sh          $t1, 0x74($v0)
    MEM_H(0X74, ctx->r2) = ctx->r9;
L_800074C8:
    // 0x800074C8: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x800074CC: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x800074D0: lhu         $v1, 0x74($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X74);
    // 0x800074D4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800074D8: slti        $at, $v1, 0x9
    ctx->r1 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // 0x800074DC: beql        $at, $zero, L_8000758C
    if (ctx->r1 == 0) {
        // 0x800074E0: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8000758C;
    }
    goto skip_2;
    // 0x800074E0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x800074E4: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800074E8: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800074EC: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x800074F0: sw          $t3, 0x74($t5)
    MEM_W(0X74, ctx->r13) = ctx->r11;
    // 0x800074F4: lbu         $t6, 0x2E8($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X2E8);
    // 0x800074F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800074FC: bnel        $t6, $at, L_8000758C
    if (ctx->r14 != ctx->r1) {
        // 0x80007500: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8000758C;
    }
    goto skip_3;
    // 0x80007500: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_3:
    // 0x80007504: lbu         $v0, 0x2DF($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X2DF);
    // 0x80007508: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8000750C: beql        $at, $zero, L_8000758C
    if (ctx->r1 == 0) {
        // 0x80007510: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8000758C;
    }
    goto skip_4;
    // 0x80007510: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_4:
    // 0x80007514: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80007518: addu        $t1, $s6, $v0
    ctx->r9 = ADD32(ctx->r22, ctx->r2);
    // 0x8000751C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80007520: lbu         $t9, 0x68($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X68);
    // 0x80007524: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80007528: sb          $t0, 0x2E0($t1)
    MEM_B(0X2E0, ctx->r9) = ctx->r8;
    // 0x8000752C: lbu         $t2, 0x2DF($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X2DF);
    // 0x80007530: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80007534: b           L_80007588
    // 0x80007538: sb          $t4, 0x2DF($s6)
    MEM_B(0X2DF, ctx->r22) = ctx->r12;
        goto L_80007588;
    // 0x80007538: sb          $t4, 0x2DF($s6)
    MEM_B(0X2DF, ctx->r22) = ctx->r12;
    // 0x8000753C: lb          $v0, 0x80($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X80);
L_80007540:
    // 0x80007540: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80007544: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80007548: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000754C: bne         $at, $zero, L_80007434
    if (ctx->r1 != 0) {
        // 0x80007550: nop
    
            goto L_80007434;
    }
    // 0x80007550: nop

    // 0x80007554: lb          $v1, 0x80($s5)
    ctx->r3 = MEM_B(ctx->r21, 0X80);
L_80007558:
    // 0x80007558: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8000755C: andi        $s4, $s4, 0xFF
    ctx->r20 = ctx->r20 & 0XFF;
    // 0x80007560: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80007564: bne         $at, $zero, L_80007418
    if (ctx->r1 != 0) {
        // 0x80007568: nop
    
            goto L_80007418;
    }
    // 0x80007568: nop

L_8000756C:
    // 0x8000756C: lbu         $t3, 0x2E8($s6)
    ctx->r11 = MEM_BU(ctx->r22, 0X2E8);
    // 0x80007570: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007574: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80007578: bnel        $t3, $at, L_8000758C
    if (ctx->r11 != ctx->r1) {
        // 0x8000757C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8000758C;
    }
    goto skip_5;
    // 0x8000757C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_5:
    // 0x80007580: sb          $t5, 0x2E8($s6)
    MEM_B(0X2E8, ctx->r22) = ctx->r13;
    // 0x80007584: sb          $zero, 0x2DE($s6)
    MEM_B(0X2DE, ctx->r22) = 0;
L_80007588:
    // 0x80007588: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8000758C:
    // 0x8000758C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80007590: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80007594: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80007598: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8000759C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800075A0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800075A4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800075A8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800075AC: jr          $ra
    // 0x800075B0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800075B0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    FUN_800075b4(rdram, ctx);
;}
RECOMP_FUNC void FUN_800075b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800075B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800075B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800075BC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800075C0: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800075C4: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800075C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800075CC: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800075D0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800075D4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800075D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800075DC: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800075E0: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800075E4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800075E8: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800075EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800075F0: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800075F4: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800075F8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800075FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80007600: jal         0x8002FC20
    // 0x80007604: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x80007604: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80007608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000760C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007610: jr          $ra
    // 0x80007614: nop

    return;
    // 0x80007614: nop

;}
RECOMP_FUNC void FUN_80007618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007618: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000761C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80007620: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80007624: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80007628: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000762C: jal         0x8001EB64
    // 0x80007630: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x80007630: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    after_0:
    // 0x80007634: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80007638: jal         0x8001EAD0
    // 0x8000763C: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x8000763C: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    after_1:
    // 0x80007640: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80007644: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80007648: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000764C: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    // 0x80007650: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80007654: nop

    // 0x80007658: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8000765C: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80007660: jal         0x8001EAD0
    // 0x80007664: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x80007664: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80007668: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8000766C: jal         0x8001EB64
    // 0x80007670: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x80007670: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    after_3:
    // 0x80007674: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80007678: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8000767C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80007680: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80007684: nop

    // 0x80007688: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8000768C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80007690: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80007694: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80007698: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8000769C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800076A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800076A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800076A8: jr          $ra
    // 0x800076AC: nop

    return;
    // 0x800076AC: nop

;}
RECOMP_FUNC void FUN_800076b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800076B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800076B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800076B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800076BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800076C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800076C4: jal         0x8001EB64
    // 0x800076C8: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_0;
    // 0x800076C8: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    after_0:
    // 0x800076CC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800076D0: jal         0x8001EAD0
    // 0x800076D4: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_1;
    // 0x800076D4: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    after_1:
    // 0x800076D8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800076DC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800076E0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800076E4: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    // 0x800076E8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800076EC: nop

    // 0x800076F0: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800076F4: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800076F8: jal         0x8001EAD0
    // 0x800076FC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8001EAD0)(rdram, ctx);
        goto after_2;
    // 0x800076FC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80007700: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80007704: jal         0x8001EB64
    // 0x80007708: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    LOOKUP_FUNC(0x8001EB64)(rdram, ctx);
        goto after_3;
    // 0x80007708: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    after_3:
    // 0x8000770C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80007710: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80007714: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80007718: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000771C: nop

    // 0x80007720: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80007724: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80007728: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8000772C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80007730: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80007734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80007738: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000773C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80007740: jr          $ra
    // 0x80007744: nop

    return;
    // 0x80007744: nop

    // 0x80007748: nop

    // 0x8000774C: nop

;}
RECOMP_FUNC void FUN_80007750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007750: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80007754: addiu       $v1, $v1, -0x2A44
    ctx->r3 = ADD32(ctx->r3, -0X2A44);
    // 0x80007758: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000775C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80007760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007764: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80007768: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000776C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80007770: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80007774: jal         0x80001060
    // 0x80007778: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x80007778: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    after_0:
    // 0x8000777C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80007780: beq         $v0, $zero, L_80007808
    if (ctx->r2 == 0) {
        // 0x80007784: addiu       $v1, $v1, -0x2A44
        ctx->r3 = ADD32(ctx->r3, -0X2A44);
            goto L_80007808;
    }
    // 0x80007784: addiu       $v1, $v1, -0x2A44
    ctx->r3 = ADD32(ctx->r3, -0X2A44);
    // 0x80007788: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000778C: lui         $t0, 0xA0
    ctx->r8 = S32(0XA0 << 16);
    // 0x80007790: ori         $t0, $t0, 0x780
    ctx->r8 = ctx->r8 | 0X780;
    // 0x80007794: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80007798: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000779C: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x800077A0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800077A4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800077A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800077AC: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x800077B0: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800077B4: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800077B8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800077BC: lhu         $t2, -0x6CB6($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X6CB6);
    // 0x800077C0: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x800077C4: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    // 0x800077C8: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x800077CC: sll         $t4, $t3, 19
    ctx->r12 = S32(ctx->r11 << 19);
    // 0x800077D0: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800077D4: ori         $t6, $t5, 0x27F
    ctx->r14 = ctx->r13 | 0X27F;
    // 0x800077D8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800077DC: jal         0x80000704
    // 0x800077E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80000704)(rdram, ctx);
        goto after_1;
    // 0x800077E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x800077E4: sll         $t7, $v0, 20
    ctx->r15 = S32(ctx->r2 << 20);
    // 0x800077E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800077EC: lui         $t9, 0x8040
    ctx->r25 = S32(0X8040 << 16);
    // 0x800077F0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800077F4: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x800077F8: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800077FC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80007800: b           L_8000789C
    // 0x80007804: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
        goto L_8000789C;
    // 0x80007804: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
L_80007808:
    // 0x80007808: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000780C: lui         $t3, 0x50
    ctx->r11 = S32(0X50 << 16);
    // 0x80007810: ori         $t3, $t3, 0x3C0
    ctx->r11 = ctx->r11 | 0X3C0;
    // 0x80007814: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80007818: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8000781C: lui         $t2, 0xED00
    ctx->r10 = S32(0XED00 << 16);
    // 0x80007820: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80007824: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80007828: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000782C: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80007830: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80007834: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80007838: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8000783C: lhu         $t5, -0x6CB6($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X6CB6);
    // 0x80007840: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80007844: addiu       $a0, $a0, -0x3B50
    ctx->r4 = ADD32(ctx->r4, -0X3B50);
    // 0x80007848: andi        $t6, $t5, 0x3
    ctx->r14 = ctx->r13 & 0X3;
    // 0x8000784C: sll         $t7, $t6, 19
    ctx->r15 = S32(ctx->r14 << 19);
    // 0x80007850: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80007854: ori         $t9, $t8, 0x13F
    ctx->r25 = ctx->r24 | 0X13F;
    // 0x80007858: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8000785C: jal         0x80000704
    // 0x80007860: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80000704)(rdram, ctx);
        goto after_2;
    // 0x80007860: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80007864: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80007868: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x8000786C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80007870: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x80007874: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80007878: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x8000787C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80007880: sll         $t0, $t0, 11
    ctx->r8 = S32(ctx->r8 << 11);
    // 0x80007884: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80007888: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x8000788C: addiu       $t2, $t2, -0x800
    ctx->r10 = ADD32(ctx->r10, -0X800);
    // 0x80007890: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x80007894: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80007898: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
L_8000789C:
    // 0x8000789C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800078A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800078A4: jr          $ra
    // 0x800078A8: nop

    return;
    // 0x800078A8: nop

;}
RECOMP_FUNC void FUN_800078ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800078AC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800078B0: addiu       $v1, $v1, -0x2A44
    ctx->r3 = ADD32(ctx->r3, -0X2A44);
    // 0x800078B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800078B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800078BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800078C0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800078C4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800078C8: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x800078CC: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x800078D0: lui         $t8, 0x30
    ctx->r24 = S32(0X30 << 16);
    // 0x800078D4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800078D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800078DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800078E0: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x800078E4: lui         $t0, 0xF700
    ctx->r8 = S32(0XF700 << 16);
    // 0x800078E8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800078EC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800078F0: addiu       $a3, $a3, -0x6D50
    ctx->r7 = ADD32(ctx->r7, -0X6D50);
    // 0x800078F4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800078F8: lhu         $t1, 0x92($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X92);
    // 0x800078FC: lhu         $t4, 0x94($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X94);
    // 0x80007900: lhu         $t8, 0x96($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X96);
    // 0x80007904: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x80007908: andi        $t3, $t2, 0xF800
    ctx->r11 = ctx->r10 & 0XF800;
    // 0x8000790C: lhu         $t2, 0x98($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0X98);
    // 0x80007910: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80007914: andi        $t6, $t5, 0x7C0
    ctx->r14 = ctx->r13 & 0X7C0;
    // 0x80007918: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8000791C: andi        $t0, $t9, 0x3E
    ctx->r8 = ctx->r25 & 0X3E;
    // 0x80007920: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x80007924: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x80007928: andi        $t4, $t2, 0x1
    ctx->r12 = ctx->r10 & 0X1;
    // 0x8000792C: or          $a2, $t1, $t4
    ctx->r6 = ctx->r9 | ctx->r12;
    // 0x80007930: sll         $t5, $a2, 16
    ctx->r13 = S32(ctx->r6 << 16);
    // 0x80007934: or          $t3, $t5, $a2
    ctx->r11 = ctx->r13 | ctx->r6;
    // 0x80007938: jal         0x80001060
    // 0x8000793C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x8000793C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    after_0:
    // 0x80007940: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80007944: beq         $v0, $zero, L_8000796C
    if (ctx->r2 == 0) {
        // 0x80007948: addiu       $v1, $v1, -0x2A44
        ctx->r3 = ADD32(ctx->r3, -0X2A44);
            goto L_8000796C;
    }
    // 0x80007948: addiu       $v1, $v1, -0x2A44
    ctx->r3 = ADD32(ctx->r3, -0X2A44);
    // 0x8000794C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007950: lui         $t8, 0xF69F
    ctx->r24 = S32(0XF69F << 16);
    // 0x80007954: ori         $t8, $t8, 0xC77C
    ctx->r24 = ctx->r24 | 0XC77C;
    // 0x80007958: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8000795C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80007960: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80007964: b           L_80007988
    // 0x80007968: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
        goto L_80007988;
    // 0x80007968: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8000796C:
    // 0x8000796C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007970: lui         $t7, 0xF64F
    ctx->r15 = S32(0XF64F << 16);
    // 0x80007974: ori         $t7, $t7, 0xC3BC
    ctx->r15 = ctx->r15 | 0XC3BC;
    // 0x80007978: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000797C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80007980: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80007984: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80007988:
    // 0x80007988: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000798C: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x80007990: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80007994: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80007998: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000799C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800079A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800079A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800079A8: jr          $ra
    // 0x800079AC: nop

    return;
    // 0x800079AC: nop

;}
RECOMP_FUNC void FUN_800079b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800079B0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800079B4: addiu       $v1, $v1, -0x2A44
    ctx->r3 = ADD32(ctx->r3, -0X2A44);
    // 0x800079B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800079BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800079C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800079C4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800079C8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800079CC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800079D0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800079D4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800079D8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800079DC: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800079E0: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x800079E4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800079E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800079EC: lui         $t2, 0x30
    ctx->r10 = S32(0X30 << 16);
    // 0x800079F0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800079F4: jal         0x80001060
    // 0x800079F8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x800079F8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x800079FC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80007A00: beq         $v0, $zero, L_80007AA4
    if (ctx->r2 == 0) {
        // 0x80007A04: addiu       $v1, $v1, -0x2A44
        ctx->r3 = ADD32(ctx->r3, -0X2A44);
            goto L_80007AA4;
    }
    // 0x80007A04: addiu       $v1, $v1, -0x2A44
    ctx->r3 = ADD32(ctx->r3, -0X2A44);
    // 0x80007A08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007A0C: lui         $t5, 0xA0
    ctx->r13 = S32(0XA0 << 16);
    // 0x80007A10: ori         $t5, $t5, 0x780
    ctx->r13 = ctx->r13 | 0X780;
    // 0x80007A14: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80007A18: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80007A1C: lui         $t4, 0xED00
    ctx->r12 = S32(0XED00 << 16);
    // 0x80007A20: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80007A24: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80007A28: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007A2C: lui         $t7, 0xFF10
    ctx->r15 = S32(0XFF10 << 16);
    // 0x80007A30: lui         $a2, 0x70
    ctx->r6 = S32(0X70 << 16);
    // 0x80007A34: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80007A38: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80007A3C: addiu       $a2, $a2, 0x0
    ctx->r6 = ADD32(ctx->r6, 0X0);
    // 0x80007A40: ori         $t7, $t7, 0x27F
    ctx->r15 = ctx->r15 | 0X27F;
    // 0x80007A44: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80007A48: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80007A4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007A50: lui         $t9, 0xFE00
    ctx->r25 = S32(0XFE00 << 16);
    // 0x80007A54: lui         $t4, 0xFFFC
    ctx->r12 = S32(0XFFFC << 16);
    // 0x80007A58: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80007A5C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80007A60: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80007A64: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80007A68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007A6C: ori         $t4, $t4, 0xFFFC
    ctx->r12 = ctx->r12 | 0XFFFC;
    // 0x80007A70: lui         $t3, 0xF700
    ctx->r11 = S32(0XF700 << 16);
    // 0x80007A74: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80007A78: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80007A7C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80007A80: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80007A84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007A88: lui         $t6, 0xF69F
    ctx->r14 = S32(0XF69F << 16);
    // 0x80007A8C: ori         $t6, $t6, 0xC77C
    ctx->r14 = ctx->r14 | 0XC77C;
    // 0x80007A90: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80007A94: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80007A98: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80007A9C: b           L_80007B3C
    // 0x80007AA0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_80007B3C;
    // 0x80007AA0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80007AA4:
    // 0x80007AA4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007AA8: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80007AAC: ori         $t9, $t9, 0x3C0
    ctx->r25 = ctx->r25 | 0X3C0;
    // 0x80007AB0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80007AB4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80007AB8: lui         $t8, 0xED00
    ctx->r24 = S32(0XED00 << 16);
    // 0x80007ABC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80007AC0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80007AC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007AC8: lui         $t3, 0xFF10
    ctx->r11 = S32(0XFF10 << 16);
    // 0x80007ACC: lui         $a2, 0xD
    ctx->r6 = S32(0XD << 16);
    // 0x80007AD0: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80007AD4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80007AD8: addiu       $a2, $a2, -0x1640
    ctx->r6 = ADD32(ctx->r6, -0X1640);
    // 0x80007ADC: ori         $t3, $t3, 0x13F
    ctx->r11 = ctx->r11 | 0X13F;
    // 0x80007AE0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80007AE4: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80007AE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007AEC: lui         $t5, 0xFE00
    ctx->r13 = S32(0XFE00 << 16);
    // 0x80007AF0: lui         $t8, 0xFFFC
    ctx->r24 = S32(0XFFFC << 16);
    // 0x80007AF4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80007AF8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80007AFC: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80007B00: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80007B04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007B08: ori         $t8, $t8, 0xFFFC
    ctx->r24 = ctx->r24 | 0XFFFC;
    // 0x80007B0C: lui         $t7, 0xF700
    ctx->r15 = S32(0XF700 << 16);
    // 0x80007B10: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80007B14: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80007B18: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80007B1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80007B20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007B24: lui         $t2, 0xF64F
    ctx->r10 = S32(0XF64F << 16);
    // 0x80007B28: ori         $t2, $t2, 0xC3BC
    ctx->r10 = ctx->r10 | 0XC3BC;
    // 0x80007B2C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80007B30: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80007B34: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80007B38: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_80007B3C:
    // 0x80007B3C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80007B40: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80007B44: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80007B48: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80007B4C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80007B50: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80007B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007B5C: jr          $ra
    // 0x80007B60: nop

    return;
    // 0x80007B60: nop

    // 0x80007B64: nop

    // 0x80007B68: nop

    // 0x80007B6C: nop

;}
RECOMP_FUNC void FUN_80007b70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007B78: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80007B7C: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // 0x80007B80: ori         $a1, $a1, 0x4308
    ctx->r5 = ctx->r5 | 0X4308;
    // 0x80007B84: jal         0x8001F160
    // 0x80007B88: addiu       $a0, $a0, -0x6D50
    ctx->r4 = ADD32(ctx->r4, -0X6D50);
    LOOKUP_FUNC(0x8001F160)(rdram, ctx);
        goto after_0;
    // 0x80007B88: addiu       $a0, $a0, -0x6D50
    ctx->r4 = ADD32(ctx->r4, -0X6D50);
    after_0:
    // 0x80007B8C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80007B90: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x80007B94: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80007B98: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80007B9C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80007BA0: sh          $t6, 0x98($v0)
    MEM_H(0X98, ctx->r2) = ctx->r14;
    // 0x80007BA4: sh          $t7, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r15;
    // 0x80007BA8: sw          $v1, 0xDC($v0)
    MEM_W(0XDC, ctx->r2) = ctx->r3;
    // 0x80007BAC: jal         0x8001F6D0
    // 0x80007BB0: sw          $v1, 0x1A0($v0)
    MEM_W(0X1A0, ctx->r2) = ctx->r3;
    LOOKUP_FUNC(0x8001F6D0)(rdram, ctx);
        goto after_1;
    // 0x80007BB0: sw          $v1, 0x1A0($v0)
    MEM_W(0X1A0, ctx->r2) = ctx->r3;
    after_1:
    // 0x80007BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007BBC: jr          $ra
    // 0x80007BC0: nop

    return;
    // 0x80007BC0: nop

    // 0x80007BC4: nop

    // 0x80007BC8: nop

    // 0x80007BCC: nop

;}
RECOMP_FUNC void FUN_80007bd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007BD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007BD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80007BDC: sb          $t6, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r14;
    // 0x80007BE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80007BE4: jal         0x80130290
    // 0x80007BE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80130290)(rdram, ctx);
        goto after_0;
    // 0x80007BE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80007BEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80007BF0: beq         $v0, $zero, L_80007C58
    if (ctx->r2 == 0) {
        // 0x80007BF4: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80007C58;
    }
    // 0x80007BF4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80007BF8: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80007BFC: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80007C00: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80007C04: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x80007C08: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x80007C0C: addiu       $t1, $zero, 0x260
    ctx->r9 = ADD32(0, 0X260);
    // 0x80007C10: addiu       $t3, $zero, 0x1D0
    ctx->r11 = ADD32(0, 0X1D0);
    // 0x80007C14: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x80007C18: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80007C1C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80007C20: addiu       $t6, $t6, 0x33B0
    ctx->r14 = ADD32(ctx->r14, 0X33B0);
    // 0x80007C24: sh          $t1, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r9;
    // 0x80007C28: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80007C2C: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
    // 0x80007C30: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80007C34: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x80007C38: sw          $t8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r24;
    // 0x80007C3C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80007C40: sw          $t7, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r15;
    // 0x80007C44: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80007C48: sw          $t8, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r24;
    // 0x80007C4C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80007C50: b           L_80007D2C
    // 0x80007C54: sw          $t7, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r15;
        goto L_80007D2C;
    // 0x80007C54: sw          $t7, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r15;
L_80007C58:
    // 0x80007C58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80007C5C: jal         0x801302CC
    // 0x80007C60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_1;
    // 0x80007C60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80007C64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80007C68: beq         $v0, $zero, L_80007CD0
    if (ctx->r2 == 0) {
        // 0x80007C6C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80007CD0;
    }
    // 0x80007C6C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80007C70: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x80007C74: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80007C78: addiu       $t1, $zero, 0x5A
    ctx->r9 = ADD32(0, 0X5A);
    // 0x80007C7C: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x80007C80: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80007C84: addiu       $t3, $zero, 0x260
    ctx->r11 = ADD32(0, 0X260);
    // 0x80007C88: addiu       $t5, $zero, 0x186
    ctx->r13 = ADD32(0, 0X186);
    // 0x80007C8C: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x80007C90: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80007C94: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80007C98: addiu       $t8, $t8, 0x33C0
    ctx->r24 = ADD32(ctx->r24, 0X33C0);
    // 0x80007C9C: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x80007CA0: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80007CA4: sh          $t5, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r13;
    // 0x80007CA8: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80007CAC: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x80007CB0: sw          $t0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r8;
    // 0x80007CB4: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80007CB8: sw          $t9, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r25;
    // 0x80007CBC: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80007CC0: sw          $t0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r8;
    // 0x80007CC4: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80007CC8: b           L_80007D2C
    // 0x80007CCC: sw          $t9, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r25;
        goto L_80007D2C;
    // 0x80007CCC: sw          $t9, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r25;
L_80007CD0:
    // 0x80007CD0: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80007CD4: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80007CD8: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80007CDC: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x80007CE0: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80007CE4: addiu       $t5, $zero, 0x130
    ctx->r13 = ADD32(0, 0X130);
    // 0x80007CE8: addiu       $t7, $zero, 0xE8
    ctx->r15 = ADD32(0, 0XE8);
    // 0x80007CEC: sh          $t3, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r11;
    // 0x80007CF0: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80007CF4: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80007CF8: addiu       $t0, $t0, 0x33A0
    ctx->r8 = ADD32(ctx->r8, 0X33A0);
    // 0x80007CFC: sh          $t5, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r13;
    // 0x80007D00: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80007D04: sh          $t7, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r15;
    // 0x80007D08: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80007D0C: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x80007D10: sw          $t2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r10;
    // 0x80007D14: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80007D18: sw          $t1, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r9;
    // 0x80007D1C: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80007D20: sw          $t2, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r10;
    // 0x80007D24: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80007D28: sw          $t1, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r9;
L_80007D2C:
    // 0x80007D2C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80007D30: lw          $t3, 0x2C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X2C);
    // 0x80007D34: swc1        $f4, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f4.u32l;
    // 0x80007D38: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80007D3C: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80007D40: swc1        $f6, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f6.u32l;
    // 0x80007D44: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x80007D48: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80007D4C: swc1        $f8, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f8.u32l;
    // 0x80007D50: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80007D54: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80007D58: swc1        $f10, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f10.u32l;
    // 0x80007D5C: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x80007D60: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80007D64: swc1        $f16, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f16.u32l;
    // 0x80007D68: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80007D6C: lwc1        $f18, 0x14($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80007D70: swc1        $f18, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->f18.u32l;
    // 0x80007D74: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x80007D78: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80007D7C: swc1        $f4, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f4.u32l;
    // 0x80007D80: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x80007D84: lwc1        $f6, 0x1C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80007D88: swc1        $f6, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->f6.u32l;
    // 0x80007D8C: lw          $t1, 0x2C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X2C);
    // 0x80007D90: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80007D94: swc1        $f8, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f8.u32l;
    // 0x80007D98: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80007D9C: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80007DA0: swc1        $f10, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f10.u32l;
    // 0x80007DA4: lw          $t3, 0x2C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X2C);
    // 0x80007DA8: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80007DAC: swc1        $f16, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f16.u32l;
    // 0x80007DB0: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80007DB4: lwc1        $f18, 0x2C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80007DB8: swc1        $f18, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f18.u32l;
    // 0x80007DBC: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x80007DC0: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80007DC4: swc1        $f4, 0x4C($t5)
    MEM_W(0X4C, ctx->r13) = ctx->f4.u32l;
    // 0x80007DC8: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80007DCC: lwc1        $f6, 0x34($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X34);
    // 0x80007DD0: swc1        $f6, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->f6.u32l;
    // 0x80007DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007DD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007DDC: jr          $ra
    // 0x80007DE0: nop

    return;
    // 0x80007DE0: nop

;}
RECOMP_FUNC void FUN_80007de4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007DE4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80007DE8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80007DEC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80007DF0: jal         0x8000671C
    // 0x80007DF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    LOOKUP_FUNC(0x8000671C)(rdram, ctx);
        goto after_0;
    // 0x80007DF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80007DF8: jal         0x8000671C
    // 0x80007DFC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8000671C)(rdram, ctx);
        goto after_1;
    // 0x80007DFC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80007E00: jal         0x80006754
    // 0x80007E04: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x80006754)(rdram, ctx);
        goto after_2;
    // 0x80007E04: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_2:
    // 0x80007E08: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80007E0C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80007E10: addiu       $t1, $t1, -0x2A44
    ctx->r9 = ADD32(ctx->r9, -0X2A44);
    // 0x80007E14: sw          $a0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r4;
    // 0x80007E18: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80007E1C: lui         $ra, 0x8009
    ctx->r31 = S32(0X8009 << 16);
    // 0x80007E20: addiu       $ra, $ra, -0x6D50
    ctx->r31 = ADD32(ctx->r31, -0X6D50);
    // 0x80007E24: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80007E28: sw          $s0, 0x1B0($ra)
    MEM_W(0X1B0, ctx->r31) = ctx->r16;
    // 0x80007E2C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80007E30: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80007E34: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80007E38: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80007E3C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80007E40: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x80007E44: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80007E48: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80007E4C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80007E50: lw          $t6, 0x10($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X10);
    // 0x80007E54: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x80007E58: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x80007E5C: lui         $t8, 0xDC08
    ctx->r24 = S32(0XDC08 << 16);
    // 0x80007E60: ori         $t8, $t8, 0x8
    ctx->r24 = ctx->r24 | 0X8;
    // 0x80007E64: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x80007E68: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80007E6C: lui         $t6, 0xD9C0
    ctx->r14 = S32(0XD9C0 << 16);
    // 0x80007E70: ori         $t6, $t6, 0xF9FA
    ctx->r14 = ctx->r14 | 0XF9FA;
    // 0x80007E74: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80007E78: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80007E7C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80007E80: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80007E84: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80007E88: lui         $t8, 0xD700
    ctx->r24 = S32(0XD700 << 16);
    // 0x80007E8C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80007E90: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80007E94: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80007E98: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80007E9C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80007EA0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80007EA4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80007EA8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80007EAC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80007EB0: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x80007EB4: lwc1        $f4, 0x24($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X24);
    // 0x80007EB8: lw          $a2, 0x1C($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X1C);
    // 0x80007EBC: lw          $a3, 0x20($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X20);
    // 0x80007EC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80007EC4: lwc1        $f6, 0x28($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X28);
    // 0x80007EC8: addiu       $a1, $t0, 0x18
    ctx->r5 = ADD32(ctx->r8, 0X18);
    // 0x80007ECC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80007ED0: lwc1        $f8, 0x2C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x80007ED4: jal         0x80029220
    // 0x80007ED8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80029220)(rdram, ctx);
        goto after_3;
    // 0x80007ED8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80007EDC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80007EE0: addiu       $t1, $t1, -0x2A44
    ctx->r9 = ADD32(ctx->r9, -0X2A44);
    // 0x80007EE4: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80007EE8: lui         $t6, 0xDB0E
    ctx->r14 = S32(0XDB0E << 16);
    // 0x80007EEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80007EF0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80007EF4: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80007EF8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80007EFC: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80007F00: lui         $t6, 0xDA38
    ctx->r14 = S32(0XDA38 << 16);
    // 0x80007F04: ori         $t6, $t6, 0x7
    ctx->r14 = ctx->r14 | 0X7;
    // 0x80007F08: lhu         $t8, 0x18($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X18);
    // 0x80007F0C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80007F10: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80007F14: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80007F18: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80007F1C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80007F20: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80007F24: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x80007F28: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80007F2C: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x80007F30: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80007F34: lwc1        $f10, 0x3C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x80007F38: lw          $a1, 0x30($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X30);
    // 0x80007F3C: lw          $a2, 0x34($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X34);
    // 0x80007F40: lw          $a3, 0x38($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X38);
    // 0x80007F44: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80007F48: lwc1        $f16, 0x40($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X40);
    // 0x80007F4C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80007F50: lwc1        $f18, 0x44($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X44);
    // 0x80007F54: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x80007F58: lwc1        $f4, 0x48($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X48);
    // 0x80007F5C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80007F60: lwc1        $f6, 0x4C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4C);
    // 0x80007F64: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80007F68: lwc1        $f8, 0x50($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X50);
    // 0x80007F6C: jal         0x8002A2C8
    // 0x80007F70: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8002A2C8)(rdram, ctx);
        goto after_4;
    // 0x80007F70: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80007F74: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80007F78: addiu       $t1, $t1, -0x2A44
    ctx->r9 = ADD32(ctx->r9, -0X2A44);
    // 0x80007F7C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80007F80: lui         $t6, 0xDA38
    ctx->r14 = S32(0XDA38 << 16);
    // 0x80007F84: ori         $t6, $t6, 0x5
    ctx->r14 = ctx->r14 | 0X5;
    // 0x80007F88: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80007F8C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80007F90: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80007F94: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80007F98: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80007F9C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80007FA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80007FA4: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x80007FA8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80007FAC: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80007FB0: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80007FB4: lui         $ra, 0x8009
    ctx->r31 = S32(0X8009 << 16);
    // 0x80007FB8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80007FBC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80007FC0: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x80007FC4: addiu       $ra, $ra, -0x6D50
    ctx->r31 = ADD32(ctx->r31, -0X6D50);
    // 0x80007FC8: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x80007FCC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80007FD0: nop

    // 0x80007FD4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80007FD8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80007FDC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80007FE0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80007FE4: nop

    // 0x80007FE8: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80007FEC: lh          $t8, 0x2($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X2);
    // 0x80007FF0: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80007FF4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80007FF8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80007FFC: nop

    // 0x80008000: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008004: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80008008: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8000800C: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80008010: nop

    // 0x80008014: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80008018: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8000801C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80008020: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x80008024: lh          $t6, 0x4($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X4);
    // 0x80008028: lh          $t7, 0x6($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X6);
    // 0x8000802C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80008030: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80008034: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80008038: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000803C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80008040: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80008044: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80008048: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8000804C: nop

    // 0x80008050: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80008054: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80008058: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8000805C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80008060: nop

    // 0x80008064: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80008068: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8000806C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80008070: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x80008074: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008078: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x8000807C: sh          $t6, 0x1B4($ra)
    MEM_H(0X1B4, ctx->r31) = ctx->r14;
    // 0x80008080: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80008084: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x80008088: sh          $t8, 0x1B6($ra)
    MEM_H(0X1B6, ctx->r31) = ctx->r24;
    // 0x8000808C: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x80008090: lh          $t6, 0x4($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X4);
    // 0x80008094: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80008098: sh          $t6, 0x1B8($ra)
    MEM_H(0X1B8, ctx->r31) = ctx->r14;
    // 0x8000809C: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800080A0: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x800080A4: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x800080A8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800080AC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800080B0: sh          $t8, 0x1BA($ra)
    MEM_H(0X1BA, ctx->r31) = ctx->r24;
    // 0x800080B4: addiu       $t7, $t7, 0x33E0
    ctx->r15 = ADD32(ctx->r15, 0X33E0);
    // 0x800080B8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800080BC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800080C0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800080C4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800080C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800080CC: jr          $ra
    // 0x800080D0: nop

    return;
    // 0x800080D0: nop

;}
RECOMP_FUNC void FUN_800080d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800080D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800080D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800080DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800080E0: sb          $t6, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r14;
    // 0x800080E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800080E8: jal         0x80130290
    // 0x800080EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80130290)(rdram, ctx);
        goto after_0;
    // 0x800080EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800080F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800080F4: beq         $v0, $zero, L_8000815C
    if (ctx->r2 == 0) {
        // 0x800080F8: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8000815C;
    }
    // 0x800080F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800080FC: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80008100: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80008104: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80008108: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x8000810C: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x80008110: addiu       $t1, $zero, 0x260
    ctx->r9 = ADD32(0, 0X260);
    // 0x80008114: addiu       $t3, $zero, 0x1D0
    ctx->r11 = ADD32(0, 0X1D0);
    // 0x80008118: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x8000811C: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80008120: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80008124: addiu       $t6, $t6, 0x33B0
    ctx->r14 = ADD32(ctx->r14, 0X33B0);
    // 0x80008128: sh          $t1, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r9;
    // 0x8000812C: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80008130: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
    // 0x80008134: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80008138: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x8000813C: sw          $t8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r24;
    // 0x80008140: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80008144: sw          $t7, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r15;
    // 0x80008148: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8000814C: sw          $t8, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r24;
    // 0x80008150: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80008154: b           L_80008230
    // 0x80008158: sw          $t7, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r15;
        goto L_80008230;
    // 0x80008158: sw          $t7, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r15;
L_8000815C:
    // 0x8000815C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80008160: jal         0x801302CC
    // 0x80008164: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_1;
    // 0x80008164: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80008168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000816C: beq         $v0, $zero, L_800081D4
    if (ctx->r2 == 0) {
        // 0x80008170: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_800081D4;
    }
    // 0x80008170: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80008174: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x80008178: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8000817C: addiu       $t1, $zero, 0x5A
    ctx->r9 = ADD32(0, 0X5A);
    // 0x80008180: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x80008184: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80008188: addiu       $t3, $zero, 0x260
    ctx->r11 = ADD32(0, 0X260);
    // 0x8000818C: addiu       $t5, $zero, 0x186
    ctx->r13 = ADD32(0, 0X186);
    // 0x80008190: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x80008194: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80008198: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8000819C: addiu       $t8, $t8, 0x33C0
    ctx->r24 = ADD32(ctx->r24, 0X33C0);
    // 0x800081A0: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x800081A4: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x800081A8: sh          $t5, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r13;
    // 0x800081AC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800081B0: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x800081B4: sw          $t0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r8;
    // 0x800081B8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800081BC: sw          $t9, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r25;
    // 0x800081C0: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x800081C4: sw          $t0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r8;
    // 0x800081C8: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800081CC: b           L_80008230
    // 0x800081D0: sw          $t9, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r25;
        goto L_80008230;
    // 0x800081D0: sw          $t9, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r25;
L_800081D4:
    // 0x800081D4: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x800081D8: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x800081DC: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800081E0: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x800081E4: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x800081E8: addiu       $t5, $zero, 0x130
    ctx->r13 = ADD32(0, 0X130);
    // 0x800081EC: addiu       $t7, $zero, 0xE8
    ctx->r15 = ADD32(0, 0XE8);
    // 0x800081F0: sh          $t3, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r11;
    // 0x800081F4: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x800081F8: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x800081FC: addiu       $t0, $t0, 0x33A0
    ctx->r8 = ADD32(ctx->r8, 0X33A0);
    // 0x80008200: sh          $t5, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r13;
    // 0x80008204: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80008208: sh          $t7, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r15;
    // 0x8000820C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80008210: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x80008214: sw          $t2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r10;
    // 0x80008218: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8000821C: sw          $t1, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r9;
    // 0x80008220: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80008224: sw          $t2, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r10;
    // 0x80008228: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8000822C: sw          $t1, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r9;
L_80008230:
    // 0x80008230: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80008234: lw          $t3, 0x2C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X2C);
    // 0x80008238: swc1        $f4, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f4.u32l;
    // 0x8000823C: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80008240: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80008244: swc1        $f6, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f6.u32l;
    // 0x80008248: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x8000824C: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80008250: swc1        $f8, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f8.u32l;
    // 0x80008254: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80008258: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8000825C: swc1        $f10, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f10.u32l;
    // 0x80008260: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x80008264: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80008268: swc1        $f16, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f16.u32l;
    // 0x8000826C: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80008270: lwc1        $f18, 0x14($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80008274: swc1        $f18, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->f18.u32l;
    // 0x80008278: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x8000827C: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80008280: swc1        $f4, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f4.u32l;
    // 0x80008284: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x80008288: lwc1        $f6, 0x1C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8000828C: swc1        $f6, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->f6.u32l;
    // 0x80008290: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80008294: lh          $t1, 0x20($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X20);
    // 0x80008298: sh          $t1, 0x3C($t2)
    MEM_H(0X3C, ctx->r10) = ctx->r9;
    // 0x8000829C: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x800082A0: lh          $t3, 0x22($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X22);
    // 0x800082A4: sh          $t3, 0x3E($t4)
    MEM_H(0X3E, ctx->r12) = ctx->r11;
    // 0x800082A8: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x800082AC: lh          $t5, 0x24($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X24);
    // 0x800082B0: sh          $t5, 0x40($t6)
    MEM_H(0X40, ctx->r14) = ctx->r13;
    // 0x800082B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800082B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800082BC: jr          $ra
    // 0x800082C0: nop

    return;
    // 0x800082C0: nop

;}
RECOMP_FUNC void FUN_800082c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800082C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800082C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800082CC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800082D0: jal         0x8000671C
    // 0x800082D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    LOOKUP_FUNC(0x8000671C)(rdram, ctx);
        goto after_0;
    // 0x800082D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800082D8: jal         0x8000671C
    // 0x800082DC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8000671C)(rdram, ctx);
        goto after_1;
    // 0x800082DC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x800082E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800082E4: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x800082E8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800082EC: addiu       $t1, $t1, -0x2A44
    ctx->r9 = ADD32(ctx->r9, -0X2A44);
    // 0x800082F0: sw          $a0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r4;
    // 0x800082F4: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800082F8: lui         $ra, 0x8009
    ctx->r31 = S32(0X8009 << 16);
    // 0x800082FC: addiu       $ra, $ra, -0x6D50
    ctx->r31 = ADD32(ctx->r31, -0X6D50);
    // 0x80008300: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80008304: sw          $s0, 0x1B0($ra)
    MEM_W(0X1B0, ctx->r31) = ctx->r16;
    // 0x80008308: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8000830C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80008310: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80008314: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80008318: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8000831C: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
    // 0x80008320: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x80008324: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80008328: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8000832C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80008330: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x80008334: lui         $t9, 0xD9C0
    ctx->r25 = S32(0XD9C0 << 16);
    // 0x80008338: ori         $t9, $t9, 0xF9FA
    ctx->r25 = ctx->r25 | 0XF9FA;
    // 0x8000833C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80008340: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80008344: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008348: lui         $t7, 0xD700
    ctx->r15 = S32(0XD700 << 16);
    // 0x8000834C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80008350: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80008354: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80008358: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000835C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008360: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80008364: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80008368: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000836C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80008370: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x80008374: lwc1        $f4, 0x24($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X24);
    // 0x80008378: lw          $a2, 0x1C($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X1C);
    // 0x8000837C: lw          $a3, 0x20($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X20);
    // 0x80008380: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80008384: lwc1        $f6, 0x28($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X28);
    // 0x80008388: addiu       $a1, $t0, 0x18
    ctx->r5 = ADD32(ctx->r8, 0X18);
    // 0x8000838C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80008390: lwc1        $f8, 0x2C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x80008394: jal         0x80029220
    // 0x80008398: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x80029220)(rdram, ctx);
        goto after_2;
    // 0x80008398: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8000839C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x800083A0: addiu       $t1, $t1, -0x2A44
    ctx->r9 = ADD32(ctx->r9, -0X2A44);
    // 0x800083A4: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800083A8: lui         $t9, 0xDB0E
    ctx->r25 = S32(0XDB0E << 16);
    // 0x800083AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800083B0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800083B4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800083B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800083BC: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x800083C0: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800083C4: ori         $t9, $t9, 0x7
    ctx->r25 = ctx->r25 | 0X7;
    // 0x800083C8: lhu         $t7, 0x18($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X18);
    // 0x800083CC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800083D0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800083D4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800083D8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800083DC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800083E0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800083E4: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800083E8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800083EC: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x800083F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800083F4: lh          $t8, 0x3C($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X3C);
    // 0x800083F8: lwc1        $f10, 0x30($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X30);
    // 0x800083FC: lwc1        $f18, 0x34($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X34);
    // 0x80008400: lwc1        $f6, 0x38($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X38);
    // 0x80008404: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80008408: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8000840C: lh          $t6, 0x3E($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X3E);
    // 0x80008410: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80008414: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80008418: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8000841C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80008420: lh          $t8, 0x40($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X40);
    // 0x80008424: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80008428: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8000842C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80008430: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80008434: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80008438: jal         0x80014B2C
    // 0x8000843C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x80014B2C)(rdram, ctx);
        goto after_3;
    // 0x8000843C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_3:
    // 0x80008440: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80008444: addiu       $t1, $t1, -0x2A44
    ctx->r9 = ADD32(ctx->r9, -0X2A44);
    // 0x80008448: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8000844C: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x80008450: ori         $t7, $t7, 0x5
    ctx->r15 = ctx->r15 | 0X5;
    // 0x80008454: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80008458: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8000845C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80008460: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80008464: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80008468: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000846C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80008470: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80008474: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80008478: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8000847C: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80008480: lui         $ra, 0x8009
    ctx->r31 = S32(0X8009 << 16);
    // 0x80008484: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80008488: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8000848C: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x80008490: addiu       $ra, $ra, -0x6D50
    ctx->r31 = ADD32(ctx->r31, -0X6D50);
    // 0x80008494: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x80008498: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8000849C: nop

    // 0x800084A0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800084A4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800084A8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800084AC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800084B0: nop

    // 0x800084B4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800084B8: lh          $t9, 0x2($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X2);
    // 0x800084BC: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800084C0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800084C4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800084C8: nop

    // 0x800084CC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800084D0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800084D4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800084D8: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800084DC: nop

    // 0x800084E0: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800084E4: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800084E8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800084EC: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x800084F0: lh          $t7, 0x4($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X4);
    // 0x800084F4: lh          $t8, 0x6($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X6);
    // 0x800084F8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800084FC: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80008500: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80008504: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80008508: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000850C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80008510: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80008514: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80008518: nop

    // 0x8000851C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80008520: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80008524: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80008528: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8000852C: nop

    // 0x80008530: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80008534: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80008538: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000853C: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x80008540: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008544: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80008548: sh          $t7, 0x1B4($ra)
    MEM_H(0X1B4, ctx->r31) = ctx->r15;
    // 0x8000854C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80008550: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80008554: sh          $t9, 0x1B6($ra)
    MEM_H(0X1B6, ctx->r31) = ctx->r25;
    // 0x80008558: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x8000855C: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x80008560: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80008564: sh          $t7, 0x1B8($ra)
    MEM_H(0X1B8, ctx->r31) = ctx->r15;
    // 0x80008568: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x8000856C: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80008570: lh          $t9, 0x6($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6);
    // 0x80008574: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80008578: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8000857C: sh          $t9, 0x1BA($ra)
    MEM_H(0X1BA, ctx->r31) = ctx->r25;
    // 0x80008580: addiu       $t8, $t8, 0x33E0
    ctx->r24 = ADD32(ctx->r24, 0X33E0);
    // 0x80008584: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80008588: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000858C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80008590: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80008594: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80008598: jr          $ra
    // 0x8000859C: nop

    return;
    // 0x8000859C: nop

;}
RECOMP_FUNC void FUN_800085a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800085A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800085A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800085A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800085AC: sb          $t6, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r14;
    // 0x800085B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800085B4: jal         0x80001060
    // 0x800085B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x800085B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800085BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800085C0: beq         $v0, $zero, L_80008628
    if (ctx->r2 == 0) {
        // 0x800085C4: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80008628;
    }
    // 0x800085C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800085C8: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x800085CC: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x800085D0: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x800085D4: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800085D8: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x800085DC: addiu       $t1, $zero, 0x260
    ctx->r9 = ADD32(0, 0X260);
    // 0x800085E0: addiu       $t3, $zero, 0x1D0
    ctx->r11 = ADD32(0, 0X1D0);
    // 0x800085E4: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x800085E8: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x800085EC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800085F0: addiu       $t6, $t6, 0x33D0
    ctx->r14 = ADD32(ctx->r14, 0X33D0);
    // 0x800085F4: sh          $t1, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r9;
    // 0x800085F8: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x800085FC: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
    // 0x80008600: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80008604: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x80008608: sw          $t8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r24;
    // 0x8000860C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80008610: sw          $t7, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r15;
    // 0x80008614: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80008618: sw          $t8, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r24;
    // 0x8000861C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80008620: b           L_80008684
    // 0x80008624: sw          $t7, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r15;
        goto L_80008684;
    // 0x80008624: sw          $t7, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r15;
L_80008628:
    // 0x80008628: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x8000862C: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80008630: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80008634: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x80008638: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x8000863C: addiu       $t3, $zero, 0x130
    ctx->r11 = ADD32(0, 0X130);
    // 0x80008640: addiu       $t5, $zero, 0xE8
    ctx->r13 = ADD32(0, 0XE8);
    // 0x80008644: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x80008648: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x8000864C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80008650: addiu       $t8, $t8, 0x33A0
    ctx->r24 = ADD32(ctx->r24, 0X33A0);
    // 0x80008654: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x80008658: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8000865C: sh          $t5, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r13;
    // 0x80008660: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80008664: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x80008668: sw          $t0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r8;
    // 0x8000866C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80008670: sw          $t9, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r25;
    // 0x80008674: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80008678: sw          $t0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r8;
    // 0x8000867C: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80008680: sw          $t9, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r25;
L_80008684:
    // 0x80008684: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80008688: lw          $t1, 0x2C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X2C);
    // 0x8000868C: swc1        $f4, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f4.u32l;
    // 0x80008690: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80008694: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80008698: swc1        $f6, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f6.u32l;
    // 0x8000869C: lw          $t3, 0x2C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X2C);
    // 0x800086A0: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800086A4: swc1        $f8, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f8.u32l;
    // 0x800086A8: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x800086AC: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800086B0: swc1        $f10, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f10.u32l;
    // 0x800086B4: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x800086B8: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800086BC: swc1        $f16, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f16.u32l;
    // 0x800086C0: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x800086C4: lwc1        $f18, 0x14($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800086C8: swc1        $f18, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f18.u32l;
    // 0x800086CC: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x800086D0: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800086D4: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
    // 0x800086D8: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x800086DC: lwc1        $f6, 0x1C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800086E0: swc1        $f6, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f6.u32l;
    // 0x800086E4: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x800086E8: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800086EC: swc1        $f8, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->f8.u32l;
    // 0x800086F0: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x800086F4: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800086F8: swc1        $f10, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f10.u32l;
    // 0x800086FC: lw          $t1, 0x2C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X2C);
    // 0x80008700: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80008704: swc1        $f16, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f16.u32l;
    // 0x80008708: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x8000870C: lwc1        $f18, 0x2C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80008710: swc1        $f18, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->f18.u32l;
    // 0x80008714: lw          $t3, 0x2C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X2C);
    // 0x80008718: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x8000871C: swc1        $f4, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f4.u32l;
    // 0x80008720: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80008724: lwc1        $f6, 0x34($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X34);
    // 0x80008728: swc1        $f6, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->f6.u32l;
    // 0x8000872C: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x80008730: lwc1        $f8, 0x38($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X38);
    // 0x80008734: swc1        $f8, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f8.u32l;
    // 0x80008738: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8000873C: lwc1        $f10, 0x3C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80008740: swc1        $f10, 0x54($t6)
    MEM_W(0X54, ctx->r14) = ctx->f10.u32l;
    // 0x80008744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000874C: jr          $ra
    // 0x80008750: nop

    return;
    // 0x80008750: nop

;}
RECOMP_FUNC void FUN_80008754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008754: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80008758: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000875C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80008760: jal         0x8000671C
    // 0x80008764: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    LOOKUP_FUNC(0x8000671C)(rdram, ctx);
        goto after_0;
    // 0x80008764: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80008768: jal         0x8000671C
    // 0x8000876C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x8000671C)(rdram, ctx);
        goto after_1;
    // 0x8000876C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80008770: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80008774: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80008778: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8000877C: addiu       $t1, $t1, -0x2A44
    ctx->r9 = ADD32(ctx->r9, -0X2A44);
    // 0x80008780: sw          $a0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r4;
    // 0x80008784: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008788: lui         $ra, 0x8009
    ctx->r31 = S32(0X8009 << 16);
    // 0x8000878C: addiu       $ra, $ra, -0x6D50
    ctx->r31 = ADD32(ctx->r31, -0X6D50);
    // 0x80008790: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80008794: sw          $s0, 0x1B0($ra)
    MEM_W(0X1B0, ctx->r31) = ctx->r16;
    // 0x80008798: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8000879C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800087A0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800087A4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800087A8: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800087AC: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
    // 0x800087B0: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800087B4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800087B8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800087BC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800087C0: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x800087C4: lui         $t9, 0xD9C0
    ctx->r25 = S32(0XD9C0 << 16);
    // 0x800087C8: ori         $t9, $t9, 0xF9FA
    ctx->r25 = ctx->r25 | 0XF9FA;
    // 0x800087CC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800087D0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800087D4: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800087D8: lui         $t7, 0xD700
    ctx->r15 = S32(0XD700 << 16);
    // 0x800087DC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800087E0: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800087E4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800087E8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800087EC: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800087F0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800087F4: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x800087F8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800087FC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80008800: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x80008804: lwc1        $f4, 0x24($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X24);
    // 0x80008808: lw          $a1, 0x18($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X18);
    // 0x8000880C: lw          $a2, 0x1C($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X1C);
    // 0x80008810: lw          $a3, 0x20($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X20);
    // 0x80008814: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80008818: lwc1        $f6, 0x28($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X28);
    // 0x8000881C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80008820: lwc1        $f8, 0x2C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x80008824: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80008828: lwc1        $f10, 0x30($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X30);
    // 0x8000882C: jal         0x80031F84
    // 0x80008830: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x80031F84)(rdram, ctx);
        goto after_2;
    // 0x80008830: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80008834: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80008838: addiu       $t1, $t1, -0x2A44
    ctx->r9 = ADD32(ctx->r9, -0X2A44);
    // 0x8000883C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80008840: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x80008844: ori         $t9, $t9, 0x7
    ctx->r25 = ctx->r25 | 0X7;
    // 0x80008848: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000884C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80008850: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80008854: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80008858: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000885C: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80008860: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80008864: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x80008868: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8000886C: lwc1        $f16, 0x40($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X40);
    // 0x80008870: lw          $a1, 0x34($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X34);
    // 0x80008874: lw          $a2, 0x38($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X38);
    // 0x80008878: lw          $a3, 0x3C($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X3C);
    // 0x8000887C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80008880: lwc1        $f18, 0x44($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X44);
    // 0x80008884: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80008888: lwc1        $f4, 0x48($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X48);
    // 0x8000888C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80008890: lwc1        $f6, 0x4C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4C);
    // 0x80008894: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80008898: lwc1        $f8, 0x50($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X50);
    // 0x8000889C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800088A0: lwc1        $f10, 0x54($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X54);
    // 0x800088A4: jal         0x8002A2C8
    // 0x800088A8: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8002A2C8)(rdram, ctx);
        goto after_3;
    // 0x800088A8: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x800088AC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x800088B0: addiu       $t1, $t1, -0x2A44
    ctx->r9 = ADD32(ctx->r9, -0X2A44);
    // 0x800088B4: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800088B8: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800088BC: ori         $t9, $t9, 0x5
    ctx->r25 = ctx->r25 | 0X5;
    // 0x800088C0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800088C4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800088C8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800088CC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800088D0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800088D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800088D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800088DC: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800088E0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800088E4: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800088E8: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800088EC: lui         $ra, 0x8009
    ctx->r31 = S32(0X8009 << 16);
    // 0x800088F0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800088F4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800088F8: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x800088FC: addiu       $ra, $ra, -0x6D50
    ctx->r31 = ADD32(ctx->r31, -0X6D50);
    // 0x80008900: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x80008904: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80008908: nop

    // 0x8000890C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80008910: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80008914: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80008918: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8000891C: nop

    // 0x80008920: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80008924: lh          $t7, 0x2($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X2);
    // 0x80008928: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8000892C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80008930: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80008934: nop

    // 0x80008938: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000893C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80008940: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80008944: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80008948: nop

    // 0x8000894C: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80008950: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80008954: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80008958: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x8000895C: lh          $t9, 0x4($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X4);
    // 0x80008960: lh          $t6, 0x6($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X6);
    // 0x80008964: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80008968: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8000896C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80008970: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80008974: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80008978: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000897C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80008980: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80008984: nop

    // 0x80008988: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8000898C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80008990: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80008994: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80008998: nop

    // 0x8000899C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x800089A0: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800089A4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800089A8: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x800089AC: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800089B0: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800089B4: sh          $t9, 0x1B4($ra)
    MEM_H(0X1B4, ctx->r31) = ctx->r25;
    // 0x800089B8: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x800089BC: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x800089C0: sh          $t7, 0x1B6($ra)
    MEM_H(0X1B6, ctx->r31) = ctx->r15;
    // 0x800089C4: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x800089C8: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x800089CC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800089D0: sh          $t9, 0x1B8($ra)
    MEM_H(0X1B8, ctx->r31) = ctx->r25;
    // 0x800089D4: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x800089D8: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x800089DC: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x800089E0: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800089E4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800089E8: sh          $t7, 0x1BA($ra)
    MEM_H(0X1BA, ctx->r31) = ctx->r15;
    // 0x800089EC: addiu       $t6, $t6, 0x33E0
    ctx->r14 = ADD32(ctx->r14, 0X33E0);
    // 0x800089F0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800089F4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800089F8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800089FC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80008A00: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80008A04: jr          $ra
    // 0x80008A08: nop

    return;
    // 0x80008A08: nop

;}
RECOMP_FUNC void FUN_80008a0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008A0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008A10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008A14: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80008A18: sb          $t6, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r14;
    // 0x80008A1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80008A20: jal         0x80001060
    // 0x80008A24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x80008A24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80008A28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80008A2C: beq         $v0, $zero, L_80008A94
    if (ctx->r2 == 0) {
        // 0x80008A30: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80008A94;
    }
    // 0x80008A30: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80008A34: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80008A38: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80008A3C: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80008A40: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x80008A44: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x80008A48: addiu       $t1, $zero, 0x260
    ctx->r9 = ADD32(0, 0X260);
    // 0x80008A4C: addiu       $t3, $zero, 0x1D0
    ctx->r11 = ADD32(0, 0X1D0);
    // 0x80008A50: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x80008A54: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80008A58: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80008A5C: addiu       $t6, $t6, 0x33D0
    ctx->r14 = ADD32(ctx->r14, 0X33D0);
    // 0x80008A60: sh          $t1, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r9;
    // 0x80008A64: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80008A68: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
    // 0x80008A6C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80008A70: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x80008A74: sw          $t8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r24;
    // 0x80008A78: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80008A7C: sw          $t7, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r15;
    // 0x80008A80: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80008A84: sw          $t8, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r24;
    // 0x80008A88: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80008A8C: b           L_80008AF0
    // 0x80008A90: sw          $t7, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r15;
        goto L_80008AF0;
    // 0x80008A90: sw          $t7, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r15;
L_80008A94:
    // 0x80008A94: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x80008A98: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80008A9C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80008AA0: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x80008AA4: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80008AA8: addiu       $t3, $zero, 0x130
    ctx->r11 = ADD32(0, 0X130);
    // 0x80008AAC: addiu       $t5, $zero, 0xE8
    ctx->r13 = ADD32(0, 0XE8);
    // 0x80008AB0: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x80008AB4: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80008AB8: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80008ABC: addiu       $t8, $t8, 0x33A0
    ctx->r24 = ADD32(ctx->r24, 0X33A0);
    // 0x80008AC0: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x80008AC4: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80008AC8: sh          $t5, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r13;
    // 0x80008ACC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80008AD0: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x80008AD4: sw          $t0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r8;
    // 0x80008AD8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80008ADC: sw          $t9, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r25;
    // 0x80008AE0: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80008AE4: sw          $t0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r8;
    // 0x80008AE8: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80008AEC: sw          $t9, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r25;
L_80008AF0:
    // 0x80008AF0: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80008AF4: lw          $t1, 0x2C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X2C);
    // 0x80008AF8: swc1        $f4, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f4.u32l;
    // 0x80008AFC: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80008B00: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80008B04: swc1        $f6, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f6.u32l;
    // 0x80008B08: lw          $t3, 0x2C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X2C);
    // 0x80008B0C: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80008B10: swc1        $f8, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f8.u32l;
    // 0x80008B14: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80008B18: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80008B1C: swc1        $f10, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f10.u32l;
    // 0x80008B20: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x80008B24: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80008B28: swc1        $f16, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f16.u32l;
    // 0x80008B2C: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80008B30: lwc1        $f18, 0x14($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80008B34: swc1        $f18, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f18.u32l;
    // 0x80008B38: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x80008B3C: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80008B40: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
    // 0x80008B44: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80008B48: lwc1        $f6, 0x1C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80008B4C: swc1        $f6, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f6.u32l;
    // 0x80008B50: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x80008B54: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80008B58: swc1        $f8, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->f8.u32l;
    // 0x80008B5C: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x80008B60: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80008B64: swc1        $f10, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f10.u32l;
    // 0x80008B68: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80008B6C: lh          $t1, 0x28($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X28);
    // 0x80008B70: sh          $t1, 0x40($t2)
    MEM_H(0X40, ctx->r10) = ctx->r9;
    // 0x80008B74: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80008B78: lh          $t3, 0x2A($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X2A);
    // 0x80008B7C: sh          $t3, 0x42($t4)
    MEM_H(0X42, ctx->r12) = ctx->r11;
    // 0x80008B80: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80008B84: lh          $t5, 0x2C($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X2C);
    // 0x80008B88: sh          $t5, 0x44($t6)
    MEM_H(0X44, ctx->r14) = ctx->r13;
    // 0x80008B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008B90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008B94: jr          $ra
    // 0x80008B98: nop

    return;
    // 0x80008B98: nop

;}
