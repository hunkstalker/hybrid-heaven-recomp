#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M54_FUN_80383ca8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383CA8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383CAC: addiu       $a2, $a2, -0x2440
    ctx->r6 = ADD32(ctx->r6, -0X2440);
    // 0x80383CB0: sw          $a1, -0x2444($at)
    MEM_W(-0X2444, ctx->r1) = ctx->r5;
    // 0x80383CB4: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x80383CB8: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80383CBC: addiu       $v0, $v0, -0x244C
    ctx->r2 = ADD32(ctx->r2, -0X244C);
    // 0x80383CC0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80383CC4: addiu       $t9, $t8, -0x9
    ctx->r25 = ADD32(ctx->r24, -0X9);
    // 0x80383CC8: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80383CCC: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x80383CD0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80383CD4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80383CD8: beq         $at, $zero, L_80383D00
    if (ctx->r1 == 0) {
            // 0x80383CDC: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    LOOKUP_FUNC(0x80383D00)(rdram, ctx);
    return;
    }
    // 0x80383CDC: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x80383CE0: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x80383CE4: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x80383CE8: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80383CEC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383CF0: jr          $ra
    // 0x80383CF4: sw          $a1, -0x2434($at)
    MEM_W(-0X2434, ctx->r1) = ctx->r5;
    return;
    // 0x80383CF4: sw          $a1, -0x2434($at)
    MEM_W(-0X2434, ctx->r1) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M54_FUN_80383cf8(rdram, ctx);
;}
RECOMP_FUNC void M54_FUN_80383cf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383CF8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383CFC: sw          $zero, -0x2444($at)
    MEM_W(-0X2444, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M54_FUN_80383d00(rdram, ctx);
;}
RECOMP_FUNC void M54_FUN_80383d00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383D00: jr          $ra
    // 0x80383D04: nop

    return;
    // 0x80383D04: nop

;}
RECOMP_FUNC void M54_FUN_80383d08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383D08: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80383D0C: addiu       $a0, $a0, -0x2434
    ctx->r4 = ADD32(ctx->r4, -0X2434);
    // 0x80383D10: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M54_FUN_80383d14(rdram, ctx);
;}
RECOMP_FUNC void M54_FUN_80383d14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383D14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80383D18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80383D1C: sltiu       $at, $v1, 0x5
    ctx->r1 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x80383D20: beq         $at, $zero, L_80383E44
    if (ctx->r1 == 0) {
        // 0x80383D24: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_80383E44;
    }
    // 0x80383D24: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80383D28: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383D2C: addu        $at, $at, $t6
    gpr jr_addend_80383D34 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80383D30: lw          $t6, -0x2260($at)
    ctx->r14 = ADD32(ctx->r1, -0X2260);
    // 0x80383D34: jr          $t6
    // 0x80383D38: nop

    switch (jr_addend_80383D34 >> 2) {
        case 0: goto L_80383D3C; break;
        case 1: goto L_80383D48; break;
        case 2: goto L_80383D94; break;
        case 3: goto L_80383DE8; break;
        case 4: goto L_80383E30; break;
        default: switch_error(__func__, 0x80383D34, 0x8038DDA0);
    }
    // 0x80383D38: nop

L_80383D3C:
    // 0x80383D3C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383D40: b           L_80383E44
    // 0x80383D44: sw          $zero, -0x2430($at)
    MEM_W(-0X2430, ctx->r1) = 0;
        goto L_80383E44;
    // 0x80383D44: sw          $zero, -0x2430($at)
    MEM_W(-0X2430, ctx->r1) = 0;
L_80383D48:
    // 0x80383D48: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80383D4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80383D50: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383D54: addiu       $v0, $v0, -0x242C
    ctx->r2 = ADD32(ctx->r2, -0X242C);
    // 0x80383D58: sw          $t7, -0x2430($at)
    MEM_W(-0X2430, ctx->r1) = ctx->r15;
    // 0x80383D5C: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80383D60: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80383D64: addiu       $a1, $a1, -0x243C
    ctx->r5 = ADD32(ctx->r5, -0X243C);
    // 0x80383D68: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x80383D6C: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80383D70: slti        $at, $t0, 0xF1
    ctx->r1 = SIGNED(ctx->r8) < 0XF1 ? 1 : 0;
    // 0x80383D74: bne         $at, $zero, L_80383D8C
    if (ctx->r1 != 0) {
        // 0x80383D78: sb          $t9, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r25;
            goto L_80383D8C;
    }
    // 0x80383D78: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80383D7C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80383D80: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x80383D84: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80383D88: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
L_80383D8C:
    // 0x80383D8C: b           L_80383E44
    // 0x80383D90: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_80383E44;
    // 0x80383D90: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80383D94:
    // 0x80383D94: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80383D98: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80383D9C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383DA0: addiu       $a1, $a1, -0x243C
    ctx->r5 = ADD32(ctx->r5, -0X243C);
    // 0x80383DA4: sw          $t3, -0x2430($at)
    MEM_W(-0X2430, ctx->r1) = ctx->r11;
    // 0x80383DA8: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80383DAC: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80383DB0: addiu       $v0, $v0, -0x242C
    ctx->r2 = ADD32(ctx->r2, -0X242C);
    // 0x80383DB4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80383DB8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80383DBC: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x80383DC0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80383DC4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383DC8: sw          $zero, -0x2428($at)
    MEM_W(-0X2428, ctx->r1) = 0;
    // 0x80383DCC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80383DD0: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80383DD4: slti        $at, $t7, 0x61
    ctx->r1 = SIGNED(ctx->r15) < 0X61 ? 1 : 0;
    // 0x80383DD8: bnel        $at, $zero, L_80383E48
    if (ctx->r1 != 0) {
        // 0x80383DDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80383E48;
    }
    goto skip_0;
    // 0x80383DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80383DE0: b           L_80383E44
    // 0x80383DE4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
        goto L_80383E44;
    // 0x80383DE4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_80383DE8:
    // 0x80383DE8: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80383DEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80383DF0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383DF4: addiu       $v0, $v0, -0x242C
    ctx->r2 = ADD32(ctx->r2, -0X242C);
    // 0x80383DF8: sw          $t9, -0x2430($at)
    MEM_W(-0X2430, ctx->r1) = ctx->r25;
    // 0x80383DFC: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80383E00: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80383E04: addiu       $a1, $a1, -0x243C
    ctx->r5 = ADD32(ctx->r5, -0X243C);
    // 0x80383E08: addiu       $t1, $t0, -0xC
    ctx->r9 = ADD32(ctx->r8, -0XC);
    // 0x80383E0C: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80383E10: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x80383E14: beq         $at, $zero, L_80383E28
    if (ctx->r1 == 0) {
        // 0x80383E18: sb          $t1, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r9;
            goto L_80383E28;
    }
    // 0x80383E18: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80383E1C: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x80383E20: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80383E24: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
L_80383E28:
    // 0x80383E28: b           L_80383E44
    // 0x80383E2C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_80383E44;
    // 0x80383E2C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80383E30:
    // 0x80383E30: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80383E34: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383E38: sb          $t4, -0x2450($at)
    MEM_B(-0X2450, ctx->r1) = ctx->r12;
    // 0x80383E3C: jal         0x80020744
    // 0x80383E40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80383E40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
L_80383E44:
    // 0x80383E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80383E48:
    // 0x80383E48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80383E4C: jr          $ra
    // 0x80383E50: nop

    return;
    // 0x80383E50: nop

;}
RECOMP_FUNC void M54_FUN_80383e54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383E54: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80383E58: lw          $t6, -0x2428($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2428);
    // 0x80383E5C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383E60: sw          $a1, -0x2240($at)
    MEM_W(-0X2240, ctx->r1) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M54_FUN_80383e64(rdram, ctx);
;}
RECOMP_FUNC void M54_FUN_80383e64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383E64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80383E68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80383E6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80383E70: bne         $t6, $at, L_80383E98
    if (ctx->r14 != ctx->r1) {
        // 0x80383E74: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80383E98;
    }
    // 0x80383E74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80383E78: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80383E7C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80383E80: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80383E84: addiu       $a2, $a2, -0x28C4
    ctx->r6 = ADD32(ctx->r6, -0X28C4);
    // 0x80383E88: addiu       $a1, $a1, -0x42D0
    ctx->r5 = ADD32(ctx->r5, -0X42D0);
    // 0x80383E8C: addiu       $a0, $a0, -0x245C
    ctx->r4 = ADD32(ctx->r4, -0X245C);
    // 0x80383E90: jal         0x80383F34
    // 0x80383E94: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x80383F34)(rdram, ctx);
        goto after_0;
    // 0x80383E94: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_0:
L_80383E98:
    // 0x80383E98: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80383E9C: lw          $t7, -0x2444($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2444);
    // 0x80383EA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80383EA4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80383EA8: bne         $t7, $at, L_80383ECC
    if (ctx->r15 != ctx->r1) {
        // 0x80383EAC: addiu       $a0, $a0, -0x2504
        ctx->r4 = ADD32(ctx->r4, -0X2504);
            goto L_80383ECC;
    }
    // 0x80383EAC: addiu       $a0, $a0, -0x2504
    ctx->r4 = ADD32(ctx->r4, -0X2504);
    // 0x80383EB0: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80383EB4: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80383EB8: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80383EBC: lbu         $a3, -0x2440($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X2440);
    // 0x80383EC0: addiu       $a2, $a2, -0x40D0
    ctx->r6 = ADD32(ctx->r6, -0X40D0);
    // 0x80383EC4: jal         0x80383F34
    // 0x80383EC8: addiu       $a1, $a1, 0x5070
    ctx->r5 = ADD32(ctx->r5, 0X5070);
    LOOKUP_FUNC(0x80383F34)(rdram, ctx);
        goto after_1;
    // 0x80383EC8: addiu       $a1, $a1, 0x5070
    ctx->r5 = ADD32(ctx->r5, 0X5070);
    after_1:
L_80383ECC:
    // 0x80383ECC: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80383ED0: lw          $t8, -0x2430($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2430);
    // 0x80383ED4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80383ED8: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80383EDC: bne         $t8, $at, L_80383F00
    if (ctx->r24 != ctx->r1) {
        // 0x80383EE0: addiu       $a0, $a0, -0x24BC
        ctx->r4 = ADD32(ctx->r4, -0X24BC);
            goto L_80383F00;
    }
    // 0x80383EE0: addiu       $a0, $a0, -0x24BC
    ctx->r4 = ADD32(ctx->r4, -0X24BC);
    // 0x80383EE4: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80383EE8: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80383EEC: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80383EF0: lbu         $a3, -0x242C($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X242C);
    // 0x80383EF4: addiu       $a2, $a2, -0x2D44
    ctx->r6 = ADD32(ctx->r6, -0X2D44);
    // 0x80383EF8: jal         0x80383F34
    // 0x80383EFC: addiu       $a1, $a1, 0x7D30
    ctx->r5 = ADD32(ctx->r5, 0X7D30);
    LOOKUP_FUNC(0x80383F34)(rdram, ctx);
        goto after_2;
    // 0x80383EFC: addiu       $a1, $a1, 0x7D30
    ctx->r5 = ADD32(ctx->r5, 0X7D30);
    after_2:
L_80383F00:
    // 0x80383F00: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80383F04: lw          $a0, -0x2240($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2240);
    // 0x80383F08: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383F0C: lui         $t0, 0xDF00
    ctx->r8 = S32(0XDF00 << 16);
    // 0x80383F10: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80383F14: sw          $t9, -0x2240($at)
    MEM_W(-0X2240, ctx->r1) = ctx->r25;
    // 0x80383F18: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80383F1C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80383F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80383F24: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80383F28: lw          $v0, -0x2240($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2240);
    // 0x80383F2C: jr          $ra
    // 0x80383F30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80383F30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M54_FUN_80383f34(rdram, ctx);
;}
RECOMP_FUNC void M54_FUN_80383f34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383F34: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80383F38: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80383F3C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80383F40: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80383F44: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80383F48: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80383F4C: andi        $s1, $a3, 0xFF
    ctx->r17 = ctx->r7 & 0XFF;
    // 0x80383F50: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80383F54: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80383F58: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80383F5C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80383F60: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80383F64: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80383F68: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80383F6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80383F70: jal         0x80001060
    // 0x80383F74: sw          $a3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x80383F74: sw          $a3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r7;
    after_0:
    // 0x80383F78: beq         $v0, $zero, L_80383F88
    if (ctx->r2 == 0) {
        // 0x80383F7C: lui         $s0, 0x8039
        ctx->r16 = S32(0X8039 << 16);
            goto L_80383F88;
    }
    // 0x80383F7C: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x80383F80: b           L_80383F8C
    // 0x80383F84: addiu       $t5, $zero, 0x200
    ctx->r13 = ADD32(0, 0X200);
        goto L_80383F8C;
    // 0x80383F84: addiu       $t5, $zero, 0x200
    ctx->r13 = ADD32(0, 0X200);
L_80383F88:
    // 0x80383F88: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
L_80383F8C:
    // 0x80383F8C: addiu       $s0, $s0, -0x2240
    ctx->r16 = ADD32(ctx->r16, -0X2240);
    // 0x80383F90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80383F94: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80383F98: addiu       $t8, $t8, -0x2420
    ctx->r24 = ADD32(ctx->r24, -0X2420);
    // 0x80383F9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80383FA0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80383FA4: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80383FA8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80383FAC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80383FB0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80383FB4: andi        $t7, $s1, 0xFF
    ctx->r15 = ctx->r17 & 0XFF;
    // 0x80383FB8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80383FBC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80383FC0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80383FC4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80383FC8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80383FCC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80383FD0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80383FD4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80383FD8: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x80383FDC: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x80383FE0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80383FE4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80383FE8: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x80383FEC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80383FF0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80383FF4: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x80383FF8: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80383FFC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80384000: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80384004: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80384008: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8038400C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80384010: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80384014: andi        $t3, $t5, 0xFFFF
    ctx->r11 = ctx->r13 & 0XFFFF;
    // 0x80384018: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8038401C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80384020: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80384024: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80384028: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8038402C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80384030: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x80384034: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80384038: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8038403C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80384040: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80384044: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80384048: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8038404C: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x80384050: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80384054: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80384058: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8038405C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80384060: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80384064: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80384068: sll         $t7, $t3, 16
    ctx->r15 = S32(ctx->r11 << 16);
    // 0x8038406C: addiu       $t9, $t2, 0x8
    ctx->r25 = ADD32(ctx->r10, 0X8);
    // 0x80384070: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80384074: or          $t4, $t7, $t3
    ctx->r12 = ctx->r15 | ctx->r11;
    // 0x80384078: lui         $fp, 0xF550
    ctx->r30 = S32(0XF550 << 16);
    // 0x8038407C: lui         $s7, 0xFD50
    ctx->r23 = S32(0XFD50 << 16);
    // 0x80384080: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80384084: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_80384088:
    // 0x80384088: lbu         $t8, 0x0($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X0);
    // 0x8038408C: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x80384090: beql        $t9, $zero, L_8038424C
    if (ctx->r25 == 0) {
        // 0x80384094: lh          $v0, 0x4($s5)
        ctx->r2 = MEM_H(ctx->r21, 0X4);
            goto L_8038424C;
    }
    goto skip_0;
    // 0x80384094: lh          $v0, 0x4($s5)
    ctx->r2 = MEM_H(ctx->r21, 0X4);
    skip_0:
    // 0x80384098: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8038409C: lui         $t9, 0x706
    ctx->r25 = S32(0X706 << 16);
    // 0x803840A0: ori         $t9, $t9, 0x4190
    ctx->r25 = ctx->r25 | 0X4190;
    // 0x803840A4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x803840A8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x803840AC: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x803840B0: lw          $t7, 0x8($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X8);
    // 0x803840B4: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x803840B8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x803840BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x803840C0: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x803840C4: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x803840C8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x803840CC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x803840D0: sw          $fp, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r30;
    // 0x803840D4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x803840D8: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x803840DC: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x803840E0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x803840E4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x803840E8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x803840EC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x803840F0: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x803840F4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x803840F8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x803840FC: lhu         $t6, 0x2($s6)
    ctx->r14 = MEM_HU(ctx->r22, 0X2);
    // 0x80384100: lhu         $a2, 0x0($s6)
    ctx->r6 = MEM_HU(ctx->r22, 0X0);
    // 0x80384104: multu       $a2, $t6
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80384108: mflo        $a3
    ctx->r7 = lo;
    // 0x8038410C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80384110: sra         $a3, $a3, 1
    ctx->r7 = S32(SIGNED(ctx->r7) >> 1);
    // 0x80384114: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80384118: slti        $at, $a3, 0x7FF
    ctx->r1 = SIGNED(ctx->r7) < 0X7FF ? 1 : 0;
    // 0x8038411C: beq         $at, $zero, L_8038412C
    if (ctx->r1 == 0) {
        // 0x80384120: nop
    
            goto L_8038412C;
    }
    // 0x80384120: nop

    // 0x80384124: b           L_8038412C
    // 0x80384128: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
        goto L_8038412C;
    // 0x80384128: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
L_8038412C:
    // 0x8038412C: bgez        $a2, L_8038413C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80384130: sra         $v0, $a2, 3
        ctx->r2 = S32(SIGNED(ctx->r6) >> 3);
            goto L_8038413C;
    }
    // 0x80384130: sra         $v0, $a2, 3
    ctx->r2 = S32(SIGNED(ctx->r6) >> 3);
    // 0x80384134: addiu       $at, $a2, 0x7
    ctx->r1 = ADD32(ctx->r6, 0X7);
    // 0x80384138: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8038413C:
    // 0x8038413C: bgtz        $v0, L_8038414C
    if (SIGNED(ctx->r2) > 0) {
        // 0x80384140: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8038414C;
    }
    // 0x80384140: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80384144: b           L_8038414C
    // 0x80384148: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8038414C;
    // 0x80384148: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8038414C:
    // 0x8038414C: bgtz        $v0, L_8038415C
    if (SIGNED(ctx->r2) > 0) {
        // 0x80384150: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_8038415C;
    }
    // 0x80384150: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x80384154: b           L_80384160
    // 0x80384158: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80384160;
    // 0x80384158: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8038415C:
    // 0x8038415C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80384160:
    // 0x80384160: div         $zero, $t7, $a2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r6)));
    // 0x80384164: bne         $a2, $zero, L_80384170
    if (ctx->r6 != 0) {
        // 0x80384168: nop
    
            goto L_80384170;
    }
    // 0x80384168: nop

    // 0x8038416C: break       7
    do_break(2151170412);
L_80384170:
    // 0x80384170: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80384174: bne         $a2, $at, L_80384188
    if (ctx->r6 != ctx->r1) {
        // 0x80384178: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80384188;
    }
    // 0x80384178: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8038417C: bne         $t7, $at, L_80384188
    if (ctx->r15 != ctx->r1) {
        // 0x80384180: nop
    
            goto L_80384188;
    }
    // 0x80384180: nop

    // 0x80384184: break       6
    do_break(2151170436);
L_80384188:
    // 0x80384188: mflo        $t8
    ctx->r24 = lo;
    // 0x8038418C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80384190: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80384194: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x80384198: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8038419C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x803841A0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x803841A4: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x803841A8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x803841AC: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x803841B0: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x803841B4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x803841B8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x803841BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x803841C0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x803841C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x803841C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x803841CC: addiu       $s6, $s6, 0xC
    ctx->r22 = ADD32(ctx->r22, 0XC);
    // 0x803841D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x803841D4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x803841D8: lhu         $t9, -0xC($s6)
    ctx->r25 = MEM_HU(ctx->r22, -0XC);
    // 0x803841DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803841E0: addiu       $t7, $t9, 0x7
    ctx->r15 = ADD32(ctx->r25, 0X7);
    // 0x803841E4: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x803841E8: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x803841EC: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x803841F0: lui         $t6, 0x6
    ctx->r14 = S32(0X6 << 16);
    // 0x803841F4: ori         $t6, $t6, 0x4190
    ctx->r14 = ctx->r14 | 0X4190;
    // 0x803841F8: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x803841FC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80384200: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80384204: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80384208: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8038420C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80384210: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80384214: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80384218: lhu         $t7, -0xC($s6)
    ctx->r15 = MEM_HU(ctx->r22, -0XC);
    // 0x8038421C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80384220: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x80384224: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80384228: lhu         $t6, -0xA($s6)
    ctx->r14 = MEM_HU(ctx->r22, -0XA);
    // 0x8038422C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80384230: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80384234: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x80384238: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8038423C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80384240: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80384244: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80384248: lh          $v0, 0x4($s5)
    ctx->r2 = MEM_H(ctx->r21, 0X4);
L_8038424C:
    // 0x8038424C: lh          $v1, 0x6($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X6);
    // 0x80384250: lbu         $t9, 0x1($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X1);
    // 0x80384254: lbu         $t7, 0x2($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X2);
    // 0x80384258: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8038425C: addu        $s3, $v0, $t9
    ctx->r19 = ADD32(ctx->r2, ctx->r25);
    // 0x80384260: addu        $s4, $v1, $t7
    ctx->r20 = ADD32(ctx->r3, ctx->r15);
    // 0x80384264: sll         $s3, $s3, 2
    ctx->r19 = S32(ctx->r19 << 2);
    // 0x80384268: sll         $s4, $s4, 2
    ctx->r20 = S32(ctx->r20 << 2);
    // 0x8038426C: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
    // 0x80384270: jal         0x80001060
    // 0x80384274: sll         $s2, $v1, 2
    ctx->r18 = S32(ctx->r3 << 2);
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_1;
    // 0x80384274: sll         $s2, $v1, 2
    ctx->r18 = S32(ctx->r3 << 2);
    after_1:
    // 0x80384278: beq         $v0, $zero, L_80384290
    if (ctx->r2 == 0) {
        // 0x8038427C: lw          $t4, 0x40($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X40);
            goto L_80384290;
    }
    // 0x8038427C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80384280: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x80384284: sll         $s2, $s2, 1
    ctx->r18 = S32(ctx->r18 << 1);
    // 0x80384288: sll         $s3, $s3, 1
    ctx->r19 = S32(ctx->r19 << 1);
    // 0x8038428C: sll         $s4, $s4, 1
    ctx->r20 = S32(ctx->r20 << 1);
L_80384290:
    // 0x80384290: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80384294: andi        $t8, $s3, 0xFFF
    ctx->r24 = ctx->r19 & 0XFFF;
    // 0x80384298: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8038429C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x803842A0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x803842A4: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x803842A8: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x803842AC: andi        $t6, $s4, 0xFFF
    ctx->r14 = ctx->r20 & 0XFFF;
    // 0x803842B0: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x803842B4: andi        $t9, $s1, 0xFFF
    ctx->r25 = ctx->r17 & 0XFFF;
    // 0x803842B8: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x803842BC: andi        $t6, $s2, 0xFFF
    ctx->r14 = ctx->r18 & 0XFFF;
    // 0x803842C0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x803842C4: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x803842C8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x803842CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x803842D0: lui         $t7, 0xE100
    ctx->r15 = S32(0XE100 << 16);
    // 0x803842D4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x803842D8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x803842DC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x803842E0: lhu         $t8, 0x8($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X8);
    // 0x803842E4: lhu         $t6, 0xA($s5)
    ctx->r14 = MEM_HU(ctx->r21, 0XA);
    // 0x803842E8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x803842EC: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x803842F0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x803842F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x803842F8: lui         $t9, 0xF100
    ctx->r25 = S32(0XF100 << 16);
    // 0x803842FC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80384300: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80384304: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80384308: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8038430C: lbu         $t6, 0x0($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X0);
    // 0x80384310: slti        $at, $t6, 0x80
    ctx->r1 = SIGNED(ctx->r14) < 0X80 ? 1 : 0;
    // 0x80384314: beql        $at, $zero, L_80384328
    if (ctx->r1 == 0) {
        // 0x80384318: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80384328;
    }
    goto skip_1;
    // 0x80384318: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x8038431C: b           L_80384088
    // 0x80384320: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
        goto L_80384088;
    // 0x80384320: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    // 0x80384324: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80384328:
    // 0x80384328: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8038432C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80384330: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80384334: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80384338: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8038433C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80384340: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80384344: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80384348: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8038434C: jr          $ra
    // 0x80384350: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80384350: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M54_FUN_80384354(rdram, ctx);
;}
RECOMP_FUNC void M54_FUN_80384354(uint8_t* rdram, recomp_context* ctx) {
    do_break(0x80384354u);
    return;
}
RECOMP_FUNC void M24_FUN_801bf1a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF1A0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF1A4: sw          $a0, -0x72A0($at)
    MEM_W(-0X72A0, ctx->r1) = ctx->r4;
    // 0x801BF1A8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF1AC: sw          $a1, -0x729C($at)
    MEM_W(-0X729C, ctx->r1) = ctx->r5;
    // 0x801BF1B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF1B4: sw          $zero, -0x7314($at)
    MEM_W(-0X7314, ctx->r1) = 0;
    // 0x801BF1B8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf1bc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf1bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF1BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801BF1C0: sw          $zero, -0x7308($at)
    MEM_W(-0X7308, ctx->r1) = 0;
    // 0x801BF1C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BF1C8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF1CC: sw          $zero, -0x7304($at)
    MEM_W(-0X7304, ctx->r1) = 0;
    // 0x801BF1D0: jal         0x801BF9B0
    // 0x801BF1D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801BF9B0)(rdram, ctx);
        goto after_0;
    // 0x801BF1D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801BF1D8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF1DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801BF1E0: jal         0x800058DC
    // 0x801BF1E4: addiu       $a1, $a1, -0xE08
    ctx->r5 = ADD32(ctx->r5, -0XE08);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801BF1E4: addiu       $a1, $a1, -0xE08
    ctx->r5 = ADD32(ctx->r5, -0XE08);
    after_1:
    // 0x801BF1E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801BF1EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801BF1F0: jr          $ra
    // 0x801BF1F4: nop

    return;
    // 0x801BF1F4: nop

;}
RECOMP_FUNC void M24_FUN_801bf1f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF1F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801BF1FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BF200: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801BF204: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801BF208: jal         0x801BF9A4
    // 0x801BF20C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF9A4)(rdram, ctx);
        goto after_0;
    // 0x801BF20C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801BF210: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF214: sw          $zero, -0x7310($at)
    MEM_W(-0X7310, ctx->r1) = 0;
    // 0x801BF218: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF21C: jal         0x8038BC00
    // 0x801BF220: sw          $zero, -0x7300($at)
    MEM_W(-0X7300, ctx->r1) = 0;
    LOOKUP_FUNC(0x8038BC00)(rdram, ctx);
        goto after_1;
    // 0x801BF220: sw          $zero, -0x7300($at)
    MEM_W(-0X7300, ctx->r1) = 0;
    after_1:
    // 0x801BF224: jal         0x8038C8D0
    // 0x801BF228: nop

    LOOKUP_FUNC(0x8038C8D0)(rdram, ctx);
        goto after_2;
    // 0x801BF228: nop

    after_2:
    // 0x801BF22C: jal         0x8038CA40
    // 0x801BF230: nop

    LOOKUP_FUNC(0x8038CA40)(rdram, ctx);
        goto after_3;
    // 0x801BF230: nop

    after_3:
    // 0x801BF234: jal         0x8038D1E0
    // 0x801BF238: nop

    LOOKUP_FUNC(0x8038D1E0)(rdram, ctx);
        goto after_4;
    // 0x801BF238: nop

    after_4:
    // 0x801BF23C: jal         0x801C00B8
    // 0x801BF240: nop

    LOOKUP_FUNC(0x801C00B8)(rdram, ctx);
        goto after_5;
    // 0x801BF240: nop

    after_5:
    // 0x801BF244: jal         0x801C13C0
    // 0x801BF248: nop

    LOOKUP_FUNC(0x801C13C0)(rdram, ctx);
        goto after_6;
    // 0x801BF248: nop

    after_6:
    // 0x801BF24C: jal         0x801C1520
    // 0x801BF250: nop

    LOOKUP_FUNC(0x801C1520)(rdram, ctx);
        goto after_7;
    // 0x801BF250: nop

    after_7:
    // 0x801BF254: jal         0x801C1860
    // 0x801BF258: nop

    LOOKUP_FUNC(0x801C1860)(rdram, ctx);
        goto after_8;
    // 0x801BF258: nop

    after_8:
    // 0x801BF25C: jal         0x801C1FD0
    // 0x801BF260: nop

    LOOKUP_FUNC(0x801C1FD0)(rdram, ctx);
        goto after_9;
    // 0x801BF260: nop

    after_9:
    // 0x801BF264: jal         0x801C117C
    // 0x801BF268: nop

    LOOKUP_FUNC(0x801C117C)(rdram, ctx);
        goto after_10;
    // 0x801BF268: nop

    after_10:
    // 0x801BF26C: jal         0x801C1D60
    // 0x801BF270: nop

    LOOKUP_FUNC(0x801C1D60)(rdram, ctx);
        goto after_11;
    // 0x801BF270: nop

    after_11:
    // 0x801BF274: jal         0x801C0C7C
    // 0x801BF278: nop

    LOOKUP_FUNC(0x801C0C7C)(rdram, ctx);
        goto after_12;
    // 0x801BF278: nop

    after_12:
    // 0x801BF27C: jal         0x801C0FA8
    // 0x801BF280: nop

    LOOKUP_FUNC(0x801C0FA8)(rdram, ctx);
        goto after_13;
    // 0x801BF280: nop

    after_13:
    // 0x801BF284: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF288: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF28C: sw          $zero, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = 0;
    // 0x801BF290: addiu       $a1, $a1, -0xD54
    ctx->r5 = ADD32(ctx->r5, -0XD54);
    // 0x801BF294: jal         0x800058DC
    // 0x801BF298: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_14;
    // 0x801BF298: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_14:
    // 0x801BF29C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801BF2A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801BF2A4: jr          $ra
    // 0x801BF2A8: nop

    return;
    // 0x801BF2A8: nop

;}
RECOMP_FUNC void M24_FUN_801bf2ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF2AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801BF2B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BF2B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801BF2B8: jal         0x8038BD3C
    // 0x801BF2BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8038BD3C)(rdram, ctx);
        goto after_0;
    // 0x801BF2BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801BF2C0: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x801BF2C4: beq         $v1, $zero, L_801BF350
    if (ctx->r3 == 0) {
        // 0x801BF2C8: nop
    
            goto L_801BF350;
    }
    // 0x801BF2C8: nop

    // 0x801BF2CC: jal         0x8038B8C0
    // 0x801BF2D0: nop

    LOOKUP_FUNC(0x8038B8C0)(rdram, ctx);
        goto after_1;
    // 0x801BF2D0: nop

    after_1:
    // 0x801BF2D4: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x801BF2D8: beq         $v1, $zero, L_801BF350
    if (ctx->r3 == 0) {
        // 0x801BF2DC: nop
    
            goto L_801BF350;
    }
    // 0x801BF2DC: nop

    // 0x801BF2E0: jal         0x8038BA64
    // 0x801BF2E4: nop

    LOOKUP_FUNC(0x8038BA64)(rdram, ctx);
        goto after_2;
    // 0x801BF2E4: nop

    after_2:
    // 0x801BF2E8: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x801BF2EC: beq         $v1, $zero, L_801BF350
    if (ctx->r3 == 0) {
        // 0x801BF2F0: nop
    
            goto L_801BF350;
    }
    // 0x801BF2F0: nop

    // 0x801BF2F4: jal         0x801CCE00
    // 0x801BF2F8: nop

    LOOKUP_FUNC(0x801CCE00)(rdram, ctx);
        goto after_3;
    // 0x801BF2F8: nop

    after_3:
    // 0x801BF2FC: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x801BF300: beq         $v1, $zero, L_801BF350
    if (ctx->r3 == 0) {
        // 0x801BF304: nop
    
            goto L_801BF350;
    }
    // 0x801BF304: nop

    // 0x801BF308: jal         0x801CDD14
    // 0x801BF30C: nop

    LOOKUP_FUNC(0x801CDD14)(rdram, ctx);
        goto after_4;
    // 0x801BF30C: nop

    after_4:
    // 0x801BF310: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x801BF314: beq         $v1, $zero, L_801BF350
    if (ctx->r3 == 0) {
        // 0x801BF318: nop
    
            goto L_801BF350;
    }
    // 0x801BF318: nop

    // 0x801BF31C: jal         0x8038C968
    // 0x801BF320: nop

    LOOKUP_FUNC(0x8038C968)(rdram, ctx);
        goto after_5;
    // 0x801BF320: nop

    after_5:
    // 0x801BF324: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x801BF328: beq         $v1, $zero, L_801BF350
    if (ctx->r3 == 0) {
        // 0x801BF32C: nop
    
            goto L_801BF350;
    }
    // 0x801BF32C: nop

    // 0x801BF330: jal         0x8038CAE0
    // 0x801BF334: nop

    LOOKUP_FUNC(0x8038CAE0)(rdram, ctx);
        goto after_6;
    // 0x801BF334: nop

    after_6:
    // 0x801BF338: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x801BF33C: beq         $v1, $zero, L_801BF350
    if (ctx->r3 == 0) {
        // 0x801BF340: nop
    
            goto L_801BF350;
    }
    // 0x801BF340: nop

    // 0x801BF344: jal         0x8038D278
    // 0x801BF348: nop

    LOOKUP_FUNC(0x8038D278)(rdram, ctx);
        goto after_7;
    // 0x801BF348: nop

    after_7:
    // 0x801BF34C: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_801BF350:
    // 0x801BF350: beql        $v1, $zero, L_801BF37C
    if (ctx->r3 == 0) {
        // 0x801BF354: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801BF37C;
    }
    goto skip_0;
    // 0x801BF354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801BF358: jal         0x801C0A30
    // 0x801BF35C: nop

    LOOKUP_FUNC(0x801C0A30)(rdram, ctx);
        goto after_8;
    // 0x801BF35C: nop

    after_8:
    // 0x801BF360: jal         0x801C0C44
    // 0x801BF364: nop

    LOOKUP_FUNC(0x801C0C44)(rdram, ctx);
        goto after_9;
    // 0x801BF364: nop

    after_9:
    // 0x801BF368: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF36C: addiu       $a1, $a1, -0xC78
    ctx->r5 = ADD32(ctx->r5, -0XC78);
    // 0x801BF370: jal         0x800058DC
    // 0x801BF374: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_10;
    // 0x801BF374: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_10:
    // 0x801BF378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801BF37C:
    // 0x801BF37C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801BF380: jr          $ra
    // 0x801BF384: nop

    return;
    // 0x801BF384: nop

;}
RECOMP_FUNC void M24_FUN_801bf388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF388: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801BF38C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF390: sw          $t6, -0x7314($at)
    MEM_W(-0X7314, ctx->r1) = ctx->r14;
    // 0x801BF394: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf398(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801BF39C: sw          $a0, -0x72A0($at)
    MEM_W(-0X72A0, ctx->r1) = ctx->r4;
    // 0x801BF3A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BF3A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF3A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801BF3AC: jal         0x801C0A68
    // 0x801BF3B0: sw          $a1, -0x729C($at)
    MEM_W(-0X729C, ctx->r1) = ctx->r5;
    LOOKUP_FUNC(0x801C0A68)(rdram, ctx);
        goto after_0;
    // 0x801BF3B0: sw          $a1, -0x729C($at)
    MEM_W(-0X729C, ctx->r1) = ctx->r5;
    after_0:
    // 0x801BF3B4: jal         0x801C0C50
    // 0x801BF3B8: nop

    LOOKUP_FUNC(0x801C0C50)(rdram, ctx);
        goto after_1;
    // 0x801BF3B8: nop

    after_1:
    // 0x801BF3BC: jal         0x801BFA58
    // 0x801BF3C0: nop

    LOOKUP_FUNC(0x801BFA58)(rdram, ctx);
        goto after_2;
    // 0x801BF3C0: nop

    after_2:
    // 0x801BF3C4: beq         $v0, $zero, L_801BF3F4
    if (ctx->r2 == 0) {
        // 0x801BF3C8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801BF3F4;
    }
    // 0x801BF3C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801BF3CC: jal         0x8038BCE0
    // 0x801BF3D0: nop

    LOOKUP_FUNC(0x8038BCE0)(rdram, ctx);
        goto after_3;
    // 0x801BF3D0: nop

    after_3:
    // 0x801BF3D4: jal         0x8038C914
    // 0x801BF3D8: nop

    LOOKUP_FUNC(0x8038C914)(rdram, ctx);
        goto after_4;
    // 0x801BF3D8: nop

    after_4:
    // 0x801BF3DC: jal         0x8038CA8C
    // 0x801BF3E0: nop

    LOOKUP_FUNC(0x8038CA8C)(rdram, ctx);
        goto after_5;
    // 0x801BF3E0: nop

    after_5:
    // 0x801BF3E4: jal         0x8038D224
    // 0x801BF3E8: nop

    LOOKUP_FUNC(0x8038D224)(rdram, ctx);
        goto after_6;
    // 0x801BF3E8: nop

    after_6:
    // 0x801BF3EC: b           L_801BF408
    // 0x801BF3F0: nop

        goto L_801BF408;
    // 0x801BF3F0: nop

L_801BF3F4:
    // 0x801BF3F4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF3F8: jal         0x800058DC
    // 0x801BF3FC: addiu       $a1, $a1, -0xAB4
    ctx->r5 = ADD32(ctx->r5, -0XAB4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x801BF3FC: addiu       $a1, $a1, -0xAB4
    ctx->r5 = ADD32(ctx->r5, -0XAB4);
    after_7:
    // 0x801BF400: b           L_801BF498
    // 0x801BF404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801BF498;
    // 0x801BF404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801BF408:
    // 0x801BF408: jal         0x801C02FC
    // 0x801BF40C: nop

    LOOKUP_FUNC(0x801C02FC)(rdram, ctx);
        goto after_8;
    // 0x801BF40C: nop

    after_8:
    // 0x801BF410: beq         $v0, $zero, L_801BF44C
    if (ctx->r2 == 0) {
        // 0x801BF414: nop
    
            goto L_801BF44C;
    }
    // 0x801BF414: nop

    // 0x801BF418: jal         0x801C012C
    // 0x801BF41C: nop

    LOOKUP_FUNC(0x801C012C)(rdram, ctx);
        goto after_9;
    // 0x801BF41C: nop

    after_9:
    // 0x801BF420: beql        $v0, $zero, L_801BF498
    if (ctx->r2 == 0) {
        // 0x801BF424: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801BF498;
    }
    goto skip_0;
    // 0x801BF424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801BF428: jal         0x801C0190
    // 0x801BF42C: nop

    LOOKUP_FUNC(0x801C0190)(rdram, ctx);
        goto after_10;
    // 0x801BF42C: nop

    after_10:
    // 0x801BF430: beq         $v0, $zero, L_801BF494
    if (ctx->r2 == 0) {
        // 0x801BF434: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801BF494;
    }
    // 0x801BF434: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801BF438: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF43C: jal         0x800058DC
    // 0x801BF440: addiu       $a1, $a1, -0xB5C
    ctx->r5 = ADD32(ctx->r5, -0XB5C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_11;
    // 0x801BF440: addiu       $a1, $a1, -0xB5C
    ctx->r5 = ADD32(ctx->r5, -0XB5C);
    after_11:
    // 0x801BF444: b           L_801BF498
    // 0x801BF448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801BF498;
    // 0x801BF448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801BF44C:
    // 0x801BF44C: jal         0x801C0C68
    // 0x801BF450: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    LOOKUP_FUNC(0x801C0C68)(rdram, ctx);
        goto after_12;
    // 0x801BF450: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_12:
    // 0x801BF454: beql        $v0, $zero, L_801BF498
    if (ctx->r2 == 0) {
        // 0x801BF458: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801BF498;
    }
    goto skip_1;
    // 0x801BF458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801BF45C: jal         0x801C012C
    // 0x801BF460: nop

    LOOKUP_FUNC(0x801C012C)(rdram, ctx);
        goto after_13;
    // 0x801BF460: nop

    after_13:
    // 0x801BF464: beql        $v0, $zero, L_801BF498
    if (ctx->r2 == 0) {
        // 0x801BF468: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801BF498;
    }
    goto skip_2;
    // 0x801BF468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x801BF46C: jal         0x801C0190
    // 0x801BF470: nop

    LOOKUP_FUNC(0x801C0190)(rdram, ctx);
        goto after_14;
    // 0x801BF470: nop

    after_14:
    // 0x801BF474: beq         $v0, $zero, L_801BF494
    if (ctx->r2 == 0) {
        // 0x801BF478: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_801BF494;
    }
    // 0x801BF478: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801BF47C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF480: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF484: sw          $t8, -0x7304($at)
    MEM_W(-0X7304, ctx->r1) = ctx->r24;
    // 0x801BF488: addiu       $a1, $a1, -0xB5C
    ctx->r5 = ADD32(ctx->r5, -0XB5C);
    // 0x801BF48C: jal         0x800058DC
    // 0x801BF490: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_15;
    // 0x801BF490: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_15:
L_801BF494:
    // 0x801BF494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801BF498:
    // 0x801BF498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801BF49C: jr          $ra
    // 0x801BF4A0: nop

    return;
    // 0x801BF4A0: nop

;}
RECOMP_FUNC void M24_FUN_801bf4a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF4A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801BF4A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801BF4AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801BF4B0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801BF4B4: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x801BF4B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801BF4BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801BF4C0: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801BF4C4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801BF4C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801BF4CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801BF4D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801BF4D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801BF4D8: jal         0x8038C97C
    // 0x801BF4DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_0;
    // 0x801BF4DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x801BF4E0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF4E4: addiu       $a1, $a1, -0xB00
    ctx->r5 = ADD32(ctx->r5, -0XB00);
    // 0x801BF4E8: jal         0x800058DC
    // 0x801BF4EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801BF4EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801BF4F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801BF4F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801BF4F8: jr          $ra
    // 0x801BF4FC: nop

    return;
    // 0x801BF4FC: nop

;}
RECOMP_FUNC void M24_FUN_801bf500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF500: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801BF504: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf508(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801BF50C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BF510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801BF514: bne         $t6, $zero, L_801BF53C
    if (ctx->r14 != 0) {
        // 0x801BF518: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801BF53C;
    }
    // 0x801BF518: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801BF51C: jal         0x80142570
    // 0x801BF520: nop

    LOOKUP_FUNC(0x80142570)(rdram, ctx);
        goto after_0;
    // 0x801BF520: nop

    after_0:
    // 0x801BF524: jal         0x801C0254
    // 0x801BF528: nop

    LOOKUP_FUNC(0x801C0254)(rdram, ctx);
        goto after_1;
    // 0x801BF528: nop

    after_1:
    // 0x801BF52C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF530: addiu       $a1, $a1, -0xAB4
    ctx->r5 = ADD32(ctx->r5, -0XAB4);
    // 0x801BF534: jal         0x800058DC
    // 0x801BF538: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801BF538: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_801BF53C:
    // 0x801BF53C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801BF540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801BF544: jr          $ra
    // 0x801BF548: nop

    return;
    // 0x801BF548: nop

;}
RECOMP_FUNC void M24_FUN_801bf54c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF54C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801BF550: lw          $t6, -0x7308($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7308);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf554(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF554: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801BF558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BF55C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801BF560: bne         $t6, $zero, L_801BF570
    if (ctx->r14 != 0) {
        // 0x801BF564: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801BF570;
    }
    // 0x801BF564: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801BF568: jal         0x801BFFCC
    // 0x801BF56C: nop

    LOOKUP_FUNC(0x801BFFCC)(rdram, ctx);
        goto after_0;
    // 0x801BF56C: nop

    after_0:
L_801BF570:
    // 0x801BF570: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF574: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF578: sw          $zero, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = 0;
    // 0x801BF57C: addiu       $a1, $a1, -0xA68
    ctx->r5 = ADD32(ctx->r5, -0XA68);
    // 0x801BF580: jal         0x800058DC
    // 0x801BF584: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801BF584: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801BF588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801BF58C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801BF590: jr          $ra
    // 0x801BF594: nop

    return;
    // 0x801BF594: nop

;}
RECOMP_FUNC void M24_FUN_801bf598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF598: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801BF59C: lw          $t6, -0x7308($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7308);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf5a0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf5a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF5A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801BF5A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BF5A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801BF5AC: beq         $t6, $zero, L_801BF5D4
    if (ctx->r14 == 0) {
        // 0x801BF5B0: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801BF5D4;
    }
    // 0x801BF5B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801BF5B4: jal         0x801C0058
    // 0x801BF5B8: nop

    LOOKUP_FUNC(0x801C0058)(rdram, ctx);
        goto after_0;
    // 0x801BF5B8: nop

    after_0:
    // 0x801BF5BC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF5C0: addiu       $a1, $a1, -0x9FC
    ctx->r5 = ADD32(ctx->r5, -0X9FC);
    // 0x801BF5C4: jal         0x800058DC
    // 0x801BF5C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801BF5C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801BF5CC: b           L_801BF5F8
    // 0x801BF5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801BF5F8;
    // 0x801BF5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801BF5D4:
    // 0x801BF5D4: jal         0x801BF9B0
    // 0x801BF5D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801BF9B0)(rdram, ctx);
        goto after_2;
    // 0x801BF5D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801BF5DC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF5E0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801BF5E4: sw          $zero, -0x7300($at)
    MEM_W(-0X7300, ctx->r1) = 0;
    // 0x801BF5E8: addiu       $a1, $a1, -0xC78
    ctx->r5 = ADD32(ctx->r5, -0XC78);
    // 0x801BF5EC: jal         0x800058DC
    // 0x801BF5F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801BF5F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x801BF5F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801BF5F8:
    // 0x801BF5F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801BF5FC: jr          $ra
    // 0x801BF600: nop

    return;
    // 0x801BF600: nop

;}
RECOMP_FUNC void M24_FUN_801bf604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF604: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801BF608: jr          $ra
    // 0x801BF60C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x801BF60C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf610(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF610: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF614: jr          $ra
    // 0x801BF618: sw          $a0, -0x17D8($at)
    MEM_W(-0X17D8, ctx->r1) = ctx->r4;
    return;
    // 0x801BF618: sw          $a0, -0x17D8($at)
    MEM_W(-0X17D8, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf61c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf61c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF61C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF620: jr          $ra
    // 0x801BF624: sw          $a0, -0x731C($at)
    MEM_W(-0X731C, ctx->r1) = ctx->r4;
    return;
    // 0x801BF624: sw          $a0, -0x731C($at)
    MEM_W(-0X731C, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf628(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF628: slti        $at, $a0, 0x9
    ctx->r1 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
    // 0x801BF62C: bne         $at, $zero, L_801BF63C
    if (ctx->r1 != 0) {
            // 0x801BF630: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    LOOKUP_FUNC(0x801BF63C)(rdram, ctx);
    return;
    }
    // 0x801BF630: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801BF634: jr          $ra
    // 0x801BF638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801BF638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf63c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf63c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF63C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801BF640: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801BF644: lw          $t7, -0x72FC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X72FC);
    // 0x801BF648: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x801BF64C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801BF650: addiu       $t1, $t7, 0x1F8
    ctx->r9 = ADD32(ctx->r15, 0X1F8);
L_801BF654:
    // 0x801BF654: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801BF658: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801BF65C: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x801BF660: sw          $t9, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r25;
    // 0x801BF664: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x801BF668: sw          $t8, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r24;
    // 0x801BF66C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x801BF670: bne         $t7, $t1, L_801BF654
    if (ctx->r15 != ctx->r9) {
        // 0x801BF674: sw          $t9, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r25;
            goto L_801BF654;
    }
    // 0x801BF674: sw          $t9, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r25;
    // 0x801BF678: jr          $ra
    // 0x801BF67C: nop

    return;
    // 0x801BF67C: nop

;}
RECOMP_FUNC void M24_FUN_801bf680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF680: slti        $at, $a0, 0x9
    ctx->r1 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
    // 0x801BF684: bne         $at, $zero, L_801BF694
    if (ctx->r1 != 0) {
            // 0x801BF688: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    LOOKUP_FUNC(0x801BF694)(rdram, ctx);
    return;
    }
    // 0x801BF688: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801BF68C: jr          $ra
    // 0x801BF690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801BF690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf694(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF694: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801BF698: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801BF69C: lw          $t7, -0x72FC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X72FC);
    // 0x801BF6A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801BF6A4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x801BF6A8: jr          $ra
    // 0x801BF6AC: nop

    return;
    // 0x801BF6AC: nop

;}
RECOMP_FUNC void M24_FUN_801bf6b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF6B0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801BF6B4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801BF6B8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x801BF6BC: jr          $ra
    // 0x801BF6C0: lw          $v0, -0x72FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72FC);
    return;
    // 0x801BF6C0: lw          $v0, -0x72FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72FC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf6c4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf6c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF6C4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801BF6C8: addiu       $t7, $t7, -0x72FC
    ctx->r15 = ADD32(ctx->r15, -0X72FC);
    // 0x801BF6CC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801BF6D0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x801BF6D4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801BF6D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801BF6DC: addiu       $v0, $zero, 0x1E0
    ctx->r2 = ADD32(0, 0X1E0);
    // 0x801BF6E0: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
L_801BF6E4:
    // 0x801BF6E4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801BF6E8: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x801BF6EC: sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // 0x801BF6F0: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801BF6F4: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x801BF6F8: sw          $zero, 0xC($t2)
    MEM_W(0XC, ctx->r10) = 0;
    // 0x801BF6FC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801BF700: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x801BF704: sw          $zero, 0x10($t4)
    MEM_W(0X10, ctx->r12) = 0;
    // 0x801BF708: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801BF70C: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x801BF710: sw          $a0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r4;
    // 0x801BF714: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801BF718: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x801BF71C: sw          $zero, 0x24($t8)
    MEM_W(0X24, ctx->r24) = 0;
    // 0x801BF720: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801BF724: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x801BF728: sw          $zero, 0x28($t0)
    MEM_W(0X28, ctx->r8) = 0;
    // 0x801BF72C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801BF730: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x801BF734: sw          $a0, 0x38($t2)
    MEM_W(0X38, ctx->r10) = ctx->r4;
    // 0x801BF738: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801BF73C: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x801BF740: sw          $zero, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = 0;
    // 0x801BF744: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801BF748: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x801BF74C: sw          $zero, 0x40($t6)
    MEM_W(0X40, ctx->r14) = 0;
    // 0x801BF750: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801BF754: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x801BF758: sw          $a0, 0x50($t8)
    MEM_W(0X50, ctx->r24) = ctx->r4;
    // 0x801BF75C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801BF760: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x801BF764: sw          $zero, 0x54($t0)
    MEM_W(0X54, ctx->r8) = 0;
    // 0x801BF768: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801BF76C: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x801BF770: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    // 0x801BF774: bne         $a1, $v0, L_801BF6E4
    if (ctx->r5 != ctx->r2) {
        // 0x801BF778: sw          $zero, 0x58($t2)
        MEM_W(0X58, ctx->r10) = 0;
            goto L_801BF6E4;
    }
    // 0x801BF778: sw          $zero, 0x58($t2)
    MEM_W(0X58, ctx->r10) = 0;
    // 0x801BF77C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801BF780: lui         $t3, 0x4
    ctx->r11 = S32(0X4 << 16);
    // 0x801BF784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801BF788: sw          $t3, 0x1E8($t4)
    MEM_W(0X1E8, ctx->r12) = ctx->r11;
    // 0x801BF78C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801BF790: sh          $zero, 0x1EC($t5)
    MEM_H(0X1EC, ctx->r13) = 0;
    // 0x801BF794: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801BF798: jr          $ra
    // 0x801BF79C: sw          $zero, 0x1F0($t6)
    MEM_W(0X1F0, ctx->r14) = 0;
    return;
    // 0x801BF79C: sw          $zero, 0x1F0($t6)
    MEM_W(0X1F0, ctx->r14) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf7a0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf7a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF7A0: sll         $t7, $a1, 0
    ctx->r15 = S32(ctx->r5 << 0);
    // 0x801BF7A4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801BF7A8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801BF7AC: bgez        $t7, L_801BF800
    if (SIGNED(ctx->r15) >= 0) {
            // 0x801BF7B0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801BF800)(rdram, ctx);
    return;
    }
    // 0x801BF7B0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801BF7B4: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801BF7B8: addiu       $t9, $t9, -0x72FC
    ctx->r25 = ADD32(ctx->r25, -0X72FC);
    // 0x801BF7BC: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x801BF7C0: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x801BF7C4: addiu       $t1, $sp, 0x4
    ctx->r9 = ADD32(ctx->r29, 0X4);
    // 0x801BF7C8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801BF7CC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801BF7D0: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x801BF7D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801BF7D8: sw          $t3, 0x1E8($t0)
    MEM_W(0X1E8, ctx->r8) = ctx->r11;
    // 0x801BF7DC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801BF7E0: sw          $t2, 0x1EC($t0)
    MEM_W(0X1EC, ctx->r8) = ctx->r10;
    // 0x801BF7E4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801BF7E8: sw          $t3, 0x1F0($t0)
    MEM_W(0X1F0, ctx->r8) = ctx->r11;
    // 0x801BF7EC: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x801BF7F0: lw          $t4, 0x1E8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X1E8);
    // 0x801BF7F4: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x801BF7F8: jr          $ra
    // 0x801BF7FC: sw          $t5, 0x1E8($a1)
    MEM_W(0X1E8, ctx->r5) = ctx->r13;
    return;
    // 0x801BF7FC: sw          $t5, 0x1E8($a1)
    MEM_W(0X1E8, ctx->r5) = ctx->r13;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf800(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF800: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801BF804: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801BF808: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x801BF80C: lw          $a1, -0x72FC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X72FC);
    // 0x801BF810: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x801BF814: lw          $t7, 0x1E8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1E8);
    // 0x801BF818: sltu        $at, $t7, $t8
    ctx->r1 = ctx->r15 < ctx->r24 ? 1 : 0;
    // 0x801BF81C: beq         $at, $zero, L_801BF844
    if (ctx->r1 == 0) {
            // 0x801BF820: addiu       $t9, $sp, 0x4
    ctx->r25 = ADD32(ctx->r29, 0X4);
    LOOKUP_FUNC(0x801BF844)(rdram, ctx);
    return;
    }
    // 0x801BF820: addiu       $t9, $sp, 0x4
    ctx->r25 = ADD32(ctx->r29, 0X4);
    // 0x801BF824: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801BF828: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801BF82C: sw          $t1, 0x1E8($a1)
    MEM_W(0X1E8, ctx->r5) = ctx->r9;
    // 0x801BF830: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801BF834: sw          $t0, 0x1EC($a1)
    MEM_W(0X1EC, ctx->r5) = ctx->r8;
    // 0x801BF838: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801BF83C: jr          $ra
    // 0x801BF840: sw          $t1, 0x1F0($a1)
    MEM_W(0X1F0, ctx->r5) = ctx->r9;
    return;
    // 0x801BF840: sw          $t1, 0x1F0($a1)
    MEM_W(0X1F0, ctx->r5) = ctx->r9;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf844(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801BF848: jr          $ra
    // 0x801BF84C: nop

    return;
    // 0x801BF84C: nop

;}
RECOMP_FUNC void M24_FUN_801bf850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801BF854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801BF858: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BF85C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x801BF860: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801BF864: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x801BF868: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x801BF86C: jal         0x801C00FC
    // 0x801BF870: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x801C00FC)(rdram, ctx);
        goto after_0;
    // 0x801BF870: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x801BF874: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x801BF878: lui         $t0, 0x5
    ctx->r8 = S32(0X5 << 16);
    // 0x801BF87C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801BF880: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801BF884: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801BF888: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x801BF88C: bne         $at, $zero, L_801BF8BC
    if (ctx->r1 != 0) {
        // 0x801BF890: subu        $t7, $v1, $t0
        ctx->r15 = SUB32(ctx->r3, ctx->r8);
            goto L_801BF8BC;
    }
    // 0x801BF890: subu        $t7, $v1, $t0
    ctx->r15 = SUB32(ctx->r3, ctx->r8);
    // 0x801BF894: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x801BF898: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801BF89C: addu        $t1, $t6, $t9
    ctx->r9 = ADD32(ctx->r14, ctx->r25);
    // 0x801BF8A0: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x801BF8A4: lhu         $a0, 0x4($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X4);
    // 0x801BF8A8: lw          $a1, 0x8($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X8);
    // 0x801BF8AC: jalr        $t9
    // 0x801BF8B0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x801BF8B0: nop

    after_1:
    // 0x801BF8B4: b           L_801BF958
    // 0x801BF8B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801BF958;
    // 0x801BF8B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801BF8BC:
    // 0x801BF8BC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x801BF8C0: beq         $v1, $at, L_801BF8FC
    if (ctx->r3 == ctx->r1) {
        // 0x801BF8C4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801BF8FC;
    }
    // 0x801BF8C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801BF8C8: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x801BF8CC: beq         $v1, $at, L_801BF90C
    if (ctx->r3 == ctx->r1) {
        // 0x801BF8D0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801BF90C;
    }
    // 0x801BF8D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801BF8D4: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x801BF8D8: beq         $v1, $at, L_801BF91C
    if (ctx->r3 == ctx->r1) {
        // 0x801BF8DC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801BF91C;
    }
    // 0x801BF8DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801BF8E0: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x801BF8E4: beq         $v1, $at, L_801BF92C
    if (ctx->r3 == ctx->r1) {
        // 0x801BF8E8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801BF92C;
    }
    // 0x801BF8E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801BF8EC: beq         $v1, $t0, L_801BF93C
    if (ctx->r3 == ctx->r8) {
        // 0x801BF8F0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801BF93C;
    }
    // 0x801BF8F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801BF8F4: b           L_801BF958
    // 0x801BF8F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801BF958;
    // 0x801BF8F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801BF8FC:
    // 0x801BF8FC: jal         0x801C0464
    // 0x801BF900: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(0x801C0464)(rdram, ctx);
        goto after_2;
    // 0x801BF900: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x801BF904: b           L_801BF958
    // 0x801BF908: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801BF958;
    // 0x801BF908: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801BF90C:
    // 0x801BF90C: jal         0x801C0640
    // 0x801BF910: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(0x801C0640)(rdram, ctx);
        goto after_3;
    // 0x801BF910: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x801BF914: b           L_801BF958
    // 0x801BF918: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801BF958;
    // 0x801BF918: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801BF91C:
    // 0x801BF91C: jal         0x801C06C0
    // 0x801BF920: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(0x801C06C0)(rdram, ctx);
        goto after_4;
    // 0x801BF920: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_4:
    // 0x801BF924: b           L_801BF958
    // 0x801BF928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801BF958;
    // 0x801BF928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801BF92C:
    // 0x801BF92C: jal         0x801C0740
    // 0x801BF930: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(0x801C0740)(rdram, ctx);
        goto after_5;
    // 0x801BF930: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_5:
    // 0x801BF934: b           L_801BF958
    // 0x801BF938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801BF958;
    // 0x801BF938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801BF93C:
    // 0x801BF93C: jal         0x801C0750
    // 0x801BF940: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(0x801C0750)(rdram, ctx);
        goto after_6;
    // 0x801BF940: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_6:
    // 0x801BF944: b           L_801BF958
    // 0x801BF948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801BF958;
    // 0x801BF948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801BF94C: b           L_801BF958
    // 0x801BF950: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801BF958;
    // 0x801BF950: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801BF954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801BF958:
    // 0x801BF958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801BF95C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801BF960: jr          $ra
    // 0x801BF964: nop

    return;
    // 0x801BF964: nop

;}
RECOMP_FUNC void M24_FUN_801bf968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF968: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801BF96C: jr          $ra
    // 0x801BF970: lw          $v0, -0x7314($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7314);
    return;
    // 0x801BF970: lw          $v0, -0x7314($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7314);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf974(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF974: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801BF978: bne         $a0, $at, L_801BF988
    if (ctx->r4 != ctx->r1) {
            // 0x801BF97C: nop

    LOOKUP_FUNC(0x801BF988)(rdram, ctx);
    return;
    }
    // 0x801BF97C: nop

    // 0x801BF980: jr          $ra
    // 0x801BF984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801BF984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf988(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF988: beq         $a0, $zero, L_801BF998
    if (ctx->r4 == 0) {
        // 0x801BF98C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_801BF998;
    }
    // 0x801BF98C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801BF990: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801BF994: sllv        $v1, $t6, $a0
    ctx->r3 = S32(ctx->r14 << (ctx->r4 & 31));
L_801BF998:
    // 0x801BF998: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801BF99C: jr          $ra
    // 0x801BF9A0: nop

    return;
    // 0x801BF9A0: nop

;}
RECOMP_FUNC void M24_FUN_801bf9a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF9A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BF9A8: jr          $ra
    // 0x801BF9AC: sw          $a0, -0x7318($at)
    MEM_W(-0X7318, ctx->r1) = ctx->r4;
    return;
    // 0x801BF9AC: sw          $a0, -0x7318($at)
    MEM_W(-0X7318, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bf9b0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bf9b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BF9B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801BF9B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801BF9B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801BF9BC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x801BF9C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801BF9C4: jal         0x80005670
    // 0x801BF9C8: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801BF9C8: addiu       $a1, $a1, 0x4090
    ctx->r5 = ADD32(ctx->r5, 0X4090);
    after_0:
    // 0x801BF9CC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801BF9D0: addiu       $a1, $a1, -0x546C
    ctx->r5 = ADD32(ctx->r5, -0X546C);
    // 0x801BF9D4: jal         0x80005670
    // 0x801BF9D8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_1;
    // 0x801BF9D8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x801BF9DC: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x801BF9E0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801BF9E4: addiu       $a1, $a1, -0x27E4
    ctx->r5 = ADD32(ctx->r5, -0X27E4);
    // 0x801BF9E8: jal         0x80005670
    // 0x801BF9EC: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_2;
    // 0x801BF9EC: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    after_2:
    // 0x801BF9F0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x801BF9F4: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801BF9F8: addiu       $a1, $a1, -0x2788
    ctx->r5 = ADD32(ctx->r5, -0X2788);
    // 0x801BF9FC: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801BFA00: jal         0x80005670
    // 0x801BFA04: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_3;
    // 0x801BFA04: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    after_3:
    // 0x801BFA08: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x801BFA0C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801BFA10: addiu       $a1, $a1, -0x542C
    ctx->r5 = ADD32(ctx->r5, -0X542C);
    // 0x801BFA14: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801BFA18: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801BFA1C: jal         0x80005670
    // 0x801BFA20: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_4;
    // 0x801BFA20: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    after_4:
    // 0x801BFA24: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x801BFA28: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801BFA2C: addiu       $a1, $a1, -0x5500
    ctx->r5 = ADD32(ctx->r5, -0X5500);
    // 0x801BFA30: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801BFA34: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801BFA38: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801BFA3C: jal         0x80005670
    // 0x801BFA40: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_5;
    // 0x801BFA40: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    after_5:
    // 0x801BFA44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801BFA48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801BFA4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801BFA50: jr          $ra
    // 0x801BFA54: nop

    return;
    // 0x801BFA54: nop

;}
RECOMP_FUNC void M24_FUN_801bfa58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BFA58: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801BFA5C: lw          $t6, -0x17D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X17D8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bfa60(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bfa60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BFA60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801BFA64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BFA68: beq         $t6, $zero, L_801BFA80
    if (ctx->r14 == 0) {
        // 0x801BFA6C: nop
    
            goto L_801BFA80;
    }
    // 0x801BFA6C: nop

    // 0x801BFA70: jal         0x801BFAA0
    // 0x801BFA74: nop

    LOOKUP_FUNC(0x801BFAA0)(rdram, ctx);
        goto after_0;
    // 0x801BFA74: nop

    after_0:
    // 0x801BFA78: b           L_801BFA8C
    // 0x801BFA7C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_801BFA8C;
    // 0x801BFA7C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801BFA80:
    // 0x801BFA80: jal         0x801BFD00
    // 0x801BFA84: nop

    LOOKUP_FUNC(0x801BFD00)(rdram, ctx);
        goto after_1;
    // 0x801BFA84: nop

    after_1:
    // 0x801BFA88: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801BFA8C:
    // 0x801BFA8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801BFA90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801BFA94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801BFA98: jr          $ra
    // 0x801BFA9C: nop

    return;
    // 0x801BFA9C: nop

;}
RECOMP_FUNC void M24_FUN_801bfaa0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BFAA0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801BFAA4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801BFAA8: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x801BFAAC: addiu       $s1, $s1, -0x731C
    ctx->r17 = ADD32(ctx->r17, -0X731C);
    // 0x801BFAB0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801BFAB4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801BFAB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801BFABC: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801BFAC0: lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // 0x801BFAC4: addiu       $s2, $s2, -0x7318
    ctx->r18 = ADD32(ctx->r18, -0X7318);
    // 0x801BFAC8: addiu       $s0, $s0, -0x7400
    ctx->r16 = ADD32(ctx->r16, -0X7400);
    // 0x801BFACC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801BFAD0: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x801BFAD4: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x801BFAD8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801BFADC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801BFAE0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801BFAE4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801BFAE8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801BFAEC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x801BFAF0: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x801BFAF4: lui         $s4, 0x801E
    ctx->r20 = S32(0X801E << 16);
    // 0x801BFAF8: addiu       $s4, $s4, -0x7310
    ctx->r20 = ADD32(ctx->r20, -0X7310);
    // 0x801BFAFC: beql        $v1, $zero, L_801BFCE0
    if (ctx->r3 == 0) {
        // 0x801BFB00: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801BFCE0;
    }
    goto skip_0;
    // 0x801BFB00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801BFB04: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x801BFB08: addiu       $s3, $zero, 0x18
    ctx->r19 = ADD32(0, 0X18);
    // 0x801BFB0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801BFB10: multu       $t3, $s3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801BFB14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801BFB18: mflo        $t4
    ctx->r12 = lo;
    // 0x801BFB1C: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x801BFB20: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x801BFB24: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801BFB28: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x801BFB2C: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x801BFB30: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x801BFB34: beq         $t1, $zero, L_801BFB44
    if (ctx->r9 == 0) {
        // 0x801BFB38: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801BFB44;
    }
    // 0x801BFB38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801BFB3C: b           L_801BFB44
    // 0x801BFB40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801BFB44;
    // 0x801BFB40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801BFB44:
    // 0x801BFB44: bne         $v0, $zero, L_801BFC44
    if (ctx->r2 != 0) {
        // 0x801BFB48: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_801BFC44;
    }
    // 0x801BFB48: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x801BFB4C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801BFB50: jal         0x801C0B8C
    // 0x801BFB54: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801BFB54: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x801BFB58: beq         $v0, $zero, L_801BFCDC
    if (ctx->r2 == 0) {
        // 0x801BFB5C: addiu       $s2, $zero, 0x9
        ctx->r18 = ADD32(0, 0X9);
            goto L_801BFCDC;
    }
    // 0x801BFB5C: addiu       $s2, $zero, 0x9
    ctx->r18 = ADD32(0, 0X9);
L_801BFB60:
    // 0x801BFB60: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801BFB64: lw          $t2, -0x731C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X731C);
    // 0x801BFB68: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801BFB6C: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801BFB70: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801BFB74: lw          $t5, -0x7318($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7318);
    // 0x801BFB78: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801BFB7C: lw          $t4, -0x7400($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7400);
    // 0x801BFB80: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801BFB84: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x801BFB88: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801BFB8C: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    // 0x801BFB90: addu        $v1, $t4, $t6
    ctx->r3 = ADD32(ctx->r12, ctx->r14);
L_801BFB94:
    // 0x801BFB94: multu       $a2, $s3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801BFB98: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801BFB9C: mflo        $t8
    ctx->r24 = lo;
    // 0x801BFBA0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x801BFBA4: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x801BFBA8: and         $t0, $t9, $s1
    ctx->r8 = ctx->r25 & ctx->r17;
    // 0x801BFBAC: beql        $t0, $zero, L_801BFC08
    if (ctx->r8 == 0) {
        // 0x801BFBB0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801BFC08;
    }
    goto skip_1;
    // 0x801BFBB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x801BFBB4: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x801BFBB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801BFBBC: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x801BFBC0: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x801BFBC4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801BFBC8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801BFBCC: lw          $a3, 0x14($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X14);
    // 0x801BFBD0: jal         0x801BF7A0
    // 0x801BFBD4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801BF7A0)(rdram, ctx);
        goto after_1;
    // 0x801BFBD4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x801BFBD8: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801BFBDC: lw          $t3, -0x731C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X731C);
    // 0x801BFBE0: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801BFBE4: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801BFBE8: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x801BFBEC: lw          $t6, -0x7318($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7318);
    // 0x801BFBF0: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x801BFBF4: lw          $t4, -0x7400($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7400);
    // 0x801BFBF8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801BFBFC: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    // 0x801BFC00: addu        $v1, $t4, $t7
    ctx->r3 = ADD32(ctx->r12, ctx->r15);
    // 0x801BFC04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801BFC08:
    // 0x801BFC08: bne         $s0, $s2, L_801BFB94
    if (ctx->r16 != ctx->r18) {
        // 0x801BFC0C: sll         $s1, $s1, 1
        ctx->r17 = S32(ctx->r17 << 1);
            goto L_801BFB94;
    }
    // 0x801BFC0C: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x801BFC10: addiu       $t8, $a2, 0x1
    ctx->r24 = ADD32(ctx->r6, 0X1);
    // 0x801BFC14: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801BFC18: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x801BFC1C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801BFC20: mflo        $t1
    ctx->r9 = lo;
    // 0x801BFC24: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x801BFC28: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x801BFC2C: jal         0x801C0B8C
    // 0x801BFC30: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801BFC30: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    after_2:
    // 0x801BFC34: bne         $v0, $zero, L_801BFB60
    if (ctx->r2 != 0) {
        // 0x801BFC38: nop
    
            goto L_801BFB60;
    }
    // 0x801BFC38: nop

    // 0x801BFC3C: b           L_801BFCE0
    // 0x801BFC40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801BFCE0;
    // 0x801BFC40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801BFC44:
    // 0x801BFC44: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x801BFC48: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801BFC4C: and         $t7, $a1, $at
    ctx->r15 = ctx->r5 & ctx->r1;
    // 0x801BFC50: jal         0x801C0B8C
    // 0x801BFC54: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_3;
    // 0x801BFC54: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_3:
    // 0x801BFC58: beql        $v0, $zero, L_801BFCE0
    if (ctx->r2 == 0) {
        // 0x801BFC5C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801BFCE0;
    }
    goto skip_2;
    // 0x801BFC5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x801BFC60: jal         0x801BFF20
    // 0x801BFC64: nop

    LOOKUP_FUNC(0x801BFF20)(rdram, ctx);
        goto after_4;
    // 0x801BFC64: nop

    after_4:
    // 0x801BFC68: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x801BFC6C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801BFC70: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x801BFC74: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801BFC78: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x801BFC7C: addu        $t4, $s0, $t5
    ctx->r12 = ADD32(ctx->r16, ctx->r13);
    // 0x801BFC80: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x801BFC84: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x801BFC88: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BFC8C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x801BFC90: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801BFC94: mflo        $t7
    ctx->r15 = lo;
    // 0x801BFC98: addu        $t3, $t2, $t7
    ctx->r11 = ADD32(ctx->r10, ctx->r15);
    // 0x801BFC9C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801BFCA0: jal         0x801BFFAC
    // 0x801BFCA4: sw          $t5, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r13;
    LOOKUP_FUNC(0x801BFFAC)(rdram, ctx);
        goto after_5;
    // 0x801BFCA4: sw          $t5, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r13;
    after_5:
    // 0x801BFCA8: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801BFCAC: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x801BFCB0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BFCB4: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x801BFCB8: addu        $t8, $s0, $t0
    ctx->r24 = ADD32(ctx->r16, ctx->r8);
    // 0x801BFCBC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801BFCC0: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x801BFCC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801BFCC8: addu        $t2, $t9, $t6
    ctx->r10 = ADD32(ctx->r25, ctx->r14);
    // 0x801BFCCC: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x801BFCD0: sltiu       $t3, $t7, 0x1
    ctx->r11 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x801BFCD4: b           L_801BFCE0
    // 0x801BFCD8: sw          $t3, -0x7308($at)
    MEM_W(-0X7308, ctx->r1) = ctx->r11;
        goto L_801BFCE0;
    // 0x801BFCD8: sw          $t3, -0x7308($at)
    MEM_W(-0X7308, ctx->r1) = ctx->r11;
L_801BFCDC:
    // 0x801BFCDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801BFCE0:
    // 0x801BFCE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801BFCE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801BFCE8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801BFCEC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801BFCF0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801BFCF4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801BFCF8: jr          $ra
    // 0x801BFCFC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x801BFCFC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bfd00(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bfd00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BFD00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801BFD04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BFD08: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801BFD0C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801BFD10: lw          $a1, -0x7318($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7318);
    // 0x801BFD14: jal         0x801C2024
    // 0x801BFD18: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    LOOKUP_FUNC(0x801C2024)(rdram, ctx);
        goto after_0;
    // 0x801BFD18: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    after_0:
    // 0x801BFD1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801BFD20: beq         $v0, $at, L_801BFE04
    if (ctx->r2 == ctx->r1) {
        // 0x801BFD24: lui         $a0, 0x801E
        ctx->r4 = S32(0X801E << 16);
            goto L_801BFE04;
    }
    // 0x801BFD24: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801BFD28: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801BFD2C: lw          $a1, -0x7318($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7318);
    // 0x801BFD30: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    // 0x801BFD34: jal         0x801C218C
    // 0x801BFD38: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(0x801C218C)(rdram, ctx);
        goto after_1;
    // 0x801BFD38: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x801BFD3C: beq         $v0, $zero, L_801BFDA4
    if (ctx->r2 == 0) {
        // 0x801BFD40: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_801BFDA4;
    }
    // 0x801BFD40: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801BFD44: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801BFD48: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801BFD4C: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801BFD50: addiu       $a2, $a2, -0x72FC
    ctx->r6 = ADD32(ctx->r6, -0X72FC);
    // 0x801BFD54: lw          $a1, -0x7318($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7318);
    // 0x801BFD58: jal         0x801C233C
    // 0x801BFD5C: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    LOOKUP_FUNC(0x801C233C)(rdram, ctx);
        goto after_2;
    // 0x801BFD5C: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    after_2:
    // 0x801BFD60: jal         0x801C1FE8
    // 0x801BFD64: nop

    LOOKUP_FUNC(0x801C1FE8)(rdram, ctx);
        goto after_3;
    // 0x801BFD64: nop

    after_3:
    // 0x801BFD68: jal         0x801C1520
    // 0x801BFD6C: nop

    LOOKUP_FUNC(0x801C1520)(rdram, ctx);
        goto after_4;
    // 0x801BFD6C: nop

    after_4:
    // 0x801BFD70: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801BFD74: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801BFD78: lw          $a1, -0x7318($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7318);
    // 0x801BFD7C: jal         0x801C2024
    // 0x801BFD80: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    LOOKUP_FUNC(0x801C2024)(rdram, ctx);
        goto after_5;
    // 0x801BFD80: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    after_5:
    // 0x801BFD84: bne         $v0, $zero, L_801BFD9C
    if (ctx->r2 != 0) {
        // 0x801BFD88: nop
    
            goto L_801BFD9C;
    }
    // 0x801BFD88: nop

    // 0x801BFD8C: jal         0x801C0A30
    // 0x801BFD90: nop

    LOOKUP_FUNC(0x801C0A30)(rdram, ctx);
        goto after_6;
    // 0x801BFD90: nop

    after_6:
    // 0x801BFD94: jal         0x801C0C44
    // 0x801BFD98: nop

    LOOKUP_FUNC(0x801C0C44)(rdram, ctx);
        goto after_7;
    // 0x801BFD98: nop

    after_7:
L_801BFD9C:
    // 0x801BFD9C: b           L_801BFE50
    // 0x801BFDA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801BFE50;
    // 0x801BFDA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801BFDA4:
    // 0x801BFDA4: bne         $a2, $zero, L_801BFDF4
    if (ctx->r6 != 0) {
        // 0x801BFDA8: lui         $a0, 0x801E
        ctx->r4 = S32(0X801E << 16);
            goto L_801BFDF4;
    }
    // 0x801BFDA8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801BFDAC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801BFDB0: lw          $a1, -0x7318($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7318);
    // 0x801BFDB4: jal         0x801C2058
    // 0x801BFDB8: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    LOOKUP_FUNC(0x801C2058)(rdram, ctx);
        goto after_8;
    // 0x801BFDB8: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    after_8:
    // 0x801BFDBC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x801BFDC0: bne         $v0, $zero, L_801BFDD0
    if (ctx->r2 != 0) {
        // 0x801BFDC4: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_801BFDD0;
    }
    // 0x801BFDC4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x801BFDC8: beq         $v1, $zero, L_801BFDF4
    if (ctx->r3 == 0) {
        // 0x801BFDCC: nop
    
            goto L_801BFDF4;
    }
    // 0x801BFDCC: nop

L_801BFDD0:
    // 0x801BFDD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801BFDD4: jal         0x801C0B8C
    // 0x801BFDD8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_9;
    // 0x801BFDD8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_9:
    // 0x801BFDDC: beq         $v0, $zero, L_801BFDF4
    if (ctx->r2 == 0) {
        // 0x801BFDE0: nop
    
            goto L_801BFDF4;
    }
    // 0x801BFDE0: nop

    // 0x801BFDE4: jal         0x801C1FE8
    // 0x801BFDE8: nop

    LOOKUP_FUNC(0x801C1FE8)(rdram, ctx);
        goto after_10;
    // 0x801BFDE8: nop

    after_10:
    // 0x801BFDEC: b           L_801BFE50
    // 0x801BFDF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801BFE50;
    // 0x801BFDF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801BFDF4:
    // 0x801BFDF4: jal         0x801BFE60
    // 0x801BFDF8: nop

    LOOKUP_FUNC(0x801BFE60)(rdram, ctx);
        goto after_11;
    // 0x801BFDF8: nop

    after_11:
    // 0x801BFDFC: b           L_801BFE50
    // 0x801BFE00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801BFE50;
    // 0x801BFE00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801BFE04:
    // 0x801BFE04: jal         0x801BFF20
    // 0x801BFE08: nop

    LOOKUP_FUNC(0x801BFF20)(rdram, ctx);
        goto after_12;
    // 0x801BFE08: nop

    after_12:
    // 0x801BFE0C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801BFE10: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801BFE14: lw          $a1, -0x7318($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7318);
    // 0x801BFE18: jal         0x801C2090
    // 0x801BFE1C: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    LOOKUP_FUNC(0x801C2090)(rdram, ctx);
        goto after_13;
    // 0x801BFE1C: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    after_13:
    // 0x801BFE20: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BFE24: jal         0x801BFFAC
    // 0x801BFE28: sw          $v0, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r2;
    LOOKUP_FUNC(0x801BFFAC)(rdram, ctx);
        goto after_14;
    // 0x801BFE28: sw          $v0, -0x730C($at)
    MEM_W(-0X730C, ctx->r1) = ctx->r2;
    after_14:
    // 0x801BFE2C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801BFE30: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801BFE34: lw          $a1, -0x7318($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7318);
    // 0x801BFE38: jal         0x801C2000
    // 0x801BFE3C: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    LOOKUP_FUNC(0x801C2000)(rdram, ctx);
        goto after_15;
    // 0x801BFE3C: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    after_15:
    // 0x801BFE40: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801BFE44: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BFE48: sw          $t6, -0x7308($at)
    MEM_W(-0X7308, ctx->r1) = ctx->r14;
    // 0x801BFE4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801BFE50:
    // 0x801BFE50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801BFE54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801BFE58: jr          $ra
    // 0x801BFE5C: nop

    return;
    // 0x801BFE5C: nop

;}
RECOMP_FUNC void M24_FUN_801bfe60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BFE60: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801BFE64: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801BFE68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801BFE6C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801BFE70: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801BFE74: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801BFE78: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801BFE7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801BFE80: addiu       $t6, $t6, -0x7298
    ctx->r14 = ADD32(ctx->r14, -0X7298);
    // 0x801BFE84: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801BFE88: addiu       $s4, $sp, 0x34
    ctx->r20 = ADD32(ctx->r29, 0X34);
    // 0x801BFE8C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801BFE90: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x801BFE94: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801BFE98: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801BFE9C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x801BFEA0: sw          $t7, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r15;
    // 0x801BFEA4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801BFEA8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801BFEAC: sw          $t8, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r24;
    // 0x801BFEB0: lw          $a1, -0x7318($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7318);
    // 0x801BFEB4: jal         0x801C2090
    // 0x801BFEB8: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    LOOKUP_FUNC(0x801C2090)(rdram, ctx);
        goto after_0;
    // 0x801BFEB8: lw          $a0, -0x731C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X731C);
    after_0:
    // 0x801BFEBC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x801BFEC0: addiu       $s2, $zero, 0x9
    ctx->r18 = ADD32(0, 0X9);
L_801BFEC4:
    // 0x801BFEC4: and         $t9, $s3, $s1
    ctx->r25 = ctx->r19 & ctx->r17;
    // 0x801BFEC8: beql        $t9, $zero, L_801BFEF8
    if (ctx->r25 == 0) {
        // 0x801BFECC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801BFEF8;
    }
    goto skip_0;
    // 0x801BFECC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x801BFED0: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x801BFED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801BFED8: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x801BFEDC: lw          $a2, 0x4($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X4);
    // 0x801BFEE0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801BFEE4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801BFEE8: lw          $a3, 0x8($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X8);
    // 0x801BFEEC: jal         0x801BF7A0
    // 0x801BFEF0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x801BF7A0)(rdram, ctx);
        goto after_1;
    // 0x801BFEF0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x801BFEF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801BFEF8:
    // 0x801BFEF8: bne         $s0, $s2, L_801BFEC4
    if (ctx->r16 != ctx->r18) {
        // 0x801BFEFC: sll         $s1, $s1, 1
        ctx->r17 = S32(ctx->r17 << 1);
            goto L_801BFEC4;
    }
    // 0x801BFEFC: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x801BFF00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801BFF04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801BFF08: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801BFF0C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801BFF10: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801BFF14: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801BFF18: jr          $ra
    // 0x801BFF1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801BFF1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bff20(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bff20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BFF20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801BFF24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801BFF28: jal         0x801C00B8
    // 0x801BFF2C: nop

    LOOKUP_FUNC(0x801C00B8)(rdram, ctx);
        goto after_0;
    // 0x801BFF2C: nop

    after_0:
    // 0x801BFF30: jal         0x801C13C0
    // 0x801BFF34: nop

    LOOKUP_FUNC(0x801C13C0)(rdram, ctx);
        goto after_1;
    // 0x801BFF34: nop

    after_1:
    // 0x801BFF38: jal         0x801C1520
    // 0x801BFF3C: nop

    LOOKUP_FUNC(0x801C1520)(rdram, ctx);
        goto after_2;
    // 0x801BFF3C: nop

    after_2:
    // 0x801BFF40: jal         0x801C1860
    // 0x801BFF44: nop

    LOOKUP_FUNC(0x801C1860)(rdram, ctx);
        goto after_3;
    // 0x801BFF44: nop

    after_3:
    // 0x801BFF48: jal         0x801C1FD0
    // 0x801BFF4C: nop

    LOOKUP_FUNC(0x801C1FD0)(rdram, ctx);
        goto after_4;
    // 0x801BFF4C: nop

    after_4:
    // 0x801BFF50: jal         0x801C117C
    // 0x801BFF54: nop

    LOOKUP_FUNC(0x801C117C)(rdram, ctx);
        goto after_5;
    // 0x801BFF54: nop

    after_5:
    // 0x801BFF58: jal         0x801C1D60
    // 0x801BFF5C: nop

    LOOKUP_FUNC(0x801C1D60)(rdram, ctx);
        goto after_6;
    // 0x801BFF5C: nop

    after_6:
    // 0x801BFF60: jal         0x801C0C7C
    // 0x801BFF64: nop

    LOOKUP_FUNC(0x801C0C7C)(rdram, ctx);
        goto after_7;
    // 0x801BFF64: nop

    after_7:
    // 0x801BFF68: jal         0x801C0FA8
    // 0x801BFF6C: nop

    LOOKUP_FUNC(0x801C0FA8)(rdram, ctx);
        goto after_8;
    // 0x801BFF6C: nop

    after_8:
    // 0x801BFF70: jal         0x801C0A30
    // 0x801BFF74: nop

    LOOKUP_FUNC(0x801C0A30)(rdram, ctx);
        goto after_9;
    // 0x801BFF74: nop

    after_9:
    // 0x801BFF78: jal         0x801C0C44
    // 0x801BFF7C: nop

    LOOKUP_FUNC(0x801C0C44)(rdram, ctx);
        goto after_10;
    // 0x801BFF7C: nop

    after_10:
    // 0x801BFF80: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801BFF84: lw          $t6, -0x72A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X72A0);
    // 0x801BFF88: jal         0x80005700
    // 0x801BFF8C: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_11;
    // 0x801BFF8C: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    after_11:
    // 0x801BFF90: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801BFF94: lw          $t7, -0x72A0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X72A0);
    // 0x801BFF98: sw          $zero, 0x8($t7)
    MEM_W(0X8, ctx->r15) = 0;
    // 0x801BFF9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801BFFA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801BFFA4: jr          $ra
    // 0x801BFFA8: nop

    return;
    // 0x801BFFA8: nop

;}
RECOMP_FUNC void M24_FUN_801bffac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BFFAC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801BFFB0: addiu       $v0, $v0, -0x7318
    ctx->r2 = ADD32(ctx->r2, -0X7318);
    // 0x801BFFB4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801BFFB8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801BFFBC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801BFFC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801BFFC4: jr          $ra
    // 0x801BFFC8: sw          $zero, -0x7310($at)
    MEM_W(-0X7310, ctx->r1) = 0;
    return;
    // 0x801BFFC8: sw          $zero, -0x7310($at)
    MEM_W(-0X7310, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801bffcc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801bffcc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BFFCC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801BFFD0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801BFFD4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801BFFD8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801BFFDC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801BFFE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801BFFE4: lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // 0x801BFFE8: lui         $s3, 0x801E
    ctx->r19 = S32(0X801E << 16);
    // 0x801BFFEC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801BFFF0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x801BFFF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801BFFF8: lw          $s2, -0x730C($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X730C);
    // 0x801BFFFC: addiu       $s3, $s3, -0x72D8
    ctx->r19 = ADD32(ctx->r19, -0X72D8);
    // 0x801C0000: addiu       $s4, $zero, 0x9
    ctx->r20 = ADD32(0, 0X9);
L_801C0004:
    // 0x801C0004: and         $t6, $s2, $s1
    ctx->r14 = ctx->r18 & ctx->r17;
    // 0x801C0008: beq         $t6, $zero, L_801C0028
    if (ctx->r14 == 0) {
        // 0x801C000C: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_801C0028;
    }
    // 0x801C000C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x801C0010: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x801C0014: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x801C0018: beql        $v0, $zero, L_801C002C
    if (ctx->r2 == 0) {
        // 0x801C001C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801C002C;
    }
    goto skip_0;
    // 0x801C001C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x801C0020: jalr        $v0
    // 0x801C0024: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x801C0024: nop

    after_0:
L_801C0028:
    // 0x801C0028: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801C002C:
    // 0x801C002C: bne         $s0, $s4, L_801C0004
    if (ctx->r16 != ctx->r20) {
        // 0x801C0030: sll         $s1, $s1, 1
        ctx->r17 = S32(ctx->r17 << 1);
            goto L_801C0004;
    }
    // 0x801C0030: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x801C0034: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801C0038: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C003C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801C0040: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801C0044: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801C0048: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801C004C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801C0050: jr          $ra
    // 0x801C0054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C0054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c0058(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c0058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C0058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C005C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C0060: jal         0x801C02FC
    // 0x801C0064: nop

    LOOKUP_FUNC(0x801C02FC)(rdram, ctx);
        goto after_0;
    // 0x801C0064: nop

    after_0:
    // 0x801C0068: beq         $v0, $zero, L_801C0080
    if (ctx->r2 == 0) {
        // 0x801C006C: nop
    
            goto L_801C0080;
    }
    // 0x801C006C: nop

    // 0x801C0070: jal         0x801C0760
    // 0x801C0074: nop

    LOOKUP_FUNC(0x801C0760)(rdram, ctx);
        goto after_1;
    // 0x801C0074: nop

    after_1:
    // 0x801C0078: b           L_801C00AC
    // 0x801C007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C00AC;
    // 0x801C007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C0080:
    // 0x801C0080: jal         0x801C0320
    // 0x801C0084: nop

    LOOKUP_FUNC(0x801C0320)(rdram, ctx);
        goto after_2;
    // 0x801C0084: nop

    after_2:
    // 0x801C0088: beq         $v0, $zero, L_801C00A0
    if (ctx->r2 == 0) {
        // 0x801C008C: nop
    
            goto L_801C00A0;
    }
    // 0x801C008C: nop

    // 0x801C0090: jal         0x801C07A8
    // 0x801C0094: nop

    LOOKUP_FUNC(0x801C07A8)(rdram, ctx);
        goto after_3;
    // 0x801C0094: nop

    after_3:
    // 0x801C0098: b           L_801C00AC
    // 0x801C009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C00AC;
    // 0x801C009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C00A0:
    // 0x801C00A0: jal         0x801C0834
    // 0x801C00A4: nop

    LOOKUP_FUNC(0x801C0834)(rdram, ctx);
        goto after_4;
    // 0x801C00A4: nop

    after_4:
    // 0x801C00A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C00AC:
    // 0x801C00AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C00B0: jr          $ra
    // 0x801C00B4: nop

    return;
    // 0x801C00B4: nop

;}
RECOMP_FUNC void M24_FUN_801c00b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C00B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C00BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C00C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C00C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C00C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801C00CC: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
L_801C00D0:
    // 0x801C00D0: jal         0x801BF6C4
    // 0x801C00D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801BF6C4)(rdram, ctx);
        goto after_0;
    // 0x801C00D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801C00D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801C00DC: bne         $s0, $s1, L_801C00D0
    if (ctx->r16 != ctx->r17) {
        // 0x801C00E0: nop
    
            goto L_801C00D0;
    }
    // 0x801C00E0: nop

    // 0x801C00E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C00E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C00EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C00F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C00F4: jr          $ra
    // 0x801C00F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801C00F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c00fc(rdram, ctx);
;}
