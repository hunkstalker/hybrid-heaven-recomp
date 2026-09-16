#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M7_FUN_80148ddc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148DDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80148DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148DE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80148DE8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80148DEC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80148DF0: jal         0x80006214
    // 0x80148DF4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x80148DF4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80148DF8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80148DFC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80148E00: addiu       $a1, $a1, -0x2578
    ctx->r5 = ADD32(ctx->r5, -0X2578);
    // 0x80148E04: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80148E08: lhu         $a3, 0x32($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X32);
    // 0x80148E0C: jal         0x8013A334
    // 0x80148E10: lw          $a2, 0x5C($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X5C);
    LOOKUP_FUNC(0x8013A334)(rdram, ctx);
        goto after_1;
    // 0x80148E10: lw          $a2, 0x5C($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X5C);
    after_1:
    // 0x80148E14: addiu       $t7, $sp, 0x1C
    ctx->r15 = ADD32(ctx->r29, 0X1C);
    // 0x80148E18: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80148E1C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80148E20: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80148E24: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80148E28: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80148E2C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80148E30: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x80148E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80148E38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80148E3C: jr          $ra
    // 0x80148E40: nop

    return;
    // 0x80148E40: nop

;}
RECOMP_FUNC void M7_FUN_80148e44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148E44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80148E48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148E4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80148E50: jal         0x80147D60
    // 0x80148E54: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    LOOKUP_FUNC(0x80147D60)(rdram, ctx);
        goto after_0;
    // 0x80148E54: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_0:
    // 0x80148E58: jal         0x80147218
    // 0x80148E5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80147218)(rdram, ctx);
        goto after_1;
    // 0x80148E5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80148E60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80148E64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80148E68: jr          $ra
    // 0x80148E6C: nop

    return;
    // 0x80148E6C: nop

;}
RECOMP_FUNC void M7_FUN_80148e70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148E70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80148E74: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80148E78: jr          $ra
    // 0x80148E7C: sb          $a0, 0x1D58($at)
    MEM_B(0X1D58, ctx->r1) = ctx->r4;
    return;
    // 0x80148E7C: sb          $a0, 0x1D58($at)
    MEM_B(0X1D58, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80148e80(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80148e80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148E80: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80148E84: lbu         $t6, 0x1D58($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1D58);
    // 0x80148E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80148E8C: bne         $t6, $zero, L_80148E9C
    if (ctx->r14 != 0) {
            // 0x80148E90: nop

    LOOKUP_FUNC(0x80148E9C)(rdram, ctx);
    return;
    }
    // 0x80148E90: nop

    // 0x80148E94: jr          $ra
    // 0x80148E98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80148E98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80148e9c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80148e9c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148E9C: jr          $ra
    // 0x80148EA0: nop

    return;
    // 0x80148EA0: nop

;}
RECOMP_FUNC void M7_FUN_80148ea4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148EA4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80148EA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80148EAC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80148EB0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80148EB4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80148EB8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80148EBC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80148EC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80148EC4: addiu       $t6, $t6, 0x1DA8
    ctx->r14 = ADD32(ctx->r14, 0X1DA8);
    // 0x80148EC8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80148ECC: addiu       $s4, $sp, 0x44
    ctx->r20 = ADD32(ctx->r29, 0X44);
    // 0x80148ED0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80148ED4: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x80148ED8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80148EDC: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
    // 0x80148EE0: sw          $t7, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r15;
    // 0x80148EE4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80148EE8: sw          $t8, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r24;
    // 0x80148EEC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80148EF0: sw          $t7, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r15;
    // 0x80148EF4: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80148EF8: sw          $t8, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r24;
    // 0x80148EFC: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80148F00: sw          $t7, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r15;
    // 0x80148F04: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x80148F08: jal         0x80126944
    // 0x80148F0C: sw          $t8, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->r24;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x80148F0C: sw          $t8, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->r24;
    after_0:
    // 0x80148F10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80148F14: bne         $v0, $at, L_80148F20
    if (ctx->r2 != ctx->r1) {
        // 0x80148F18: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80148F20;
    }
    // 0x80148F18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80148F1C: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
L_80148F20:
    // 0x80148F20: blez        $s1, L_80148F74
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80148F24: or          $s2, $s1, $zero
        ctx->r18 = ctx->r17 | 0;
            goto L_80148F74;
    }
    // 0x80148F24: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x80148F28: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80148F2C: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x80148F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80148F34:
    // 0x80148F34: lbu         $v1, 0x1036($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1036);
    // 0x80148F38: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80148F3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80148F40: bne         $v1, $v0, L_80148F60
    if (ctx->r3 != ctx->r2) {
        // 0x80148F44: sll         $t9, $v1, 1
        ctx->r25 = S32(ctx->r3 << 1);
            goto L_80148F60;
    }
    // 0x80148F44: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x80148F48: addu        $t0, $s4, $t9
    ctx->r8 = ADD32(ctx->r20, ctx->r25);
    // 0x80148F4C: jal         0x80126A0C
    // 0x80148F50: lhu         $a1, 0x0($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X0);
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_1;
    // 0x80148F50: lhu         $a1, 0x0($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X0);
    after_1:
    // 0x80148F54: lbu         $t1, 0x1036($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X1036);
    // 0x80148F58: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80148F5C: sb          $t2, 0x1036($s1)
    MEM_B(0X1036, ctx->r17) = ctx->r10;
L_80148F60:
    // 0x80148F60: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80148F64: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80148F68: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80148F6C: bne         $at, $zero, L_80148F34
    if (ctx->r1 != 0) {
        // 0x80148F70: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80148F34;
    }
    // 0x80148F70: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80148F74:
    // 0x80148F74: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80148F78: addiu       $s1, $s1, -0x4410
    ctx->r17 = ADD32(ctx->r17, -0X4410);
    // 0x80148F7C: lbu         $t3, 0x1036($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X1036);
    // 0x80148F80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80148F84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80148F88: slt         $at, $t3, $s2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80148F8C: bne         $at, $zero, L_80148FA4
    if (ctx->r1 != 0) {
        // 0x80148F90: nop
    
            goto L_80148FA4;
    }
    // 0x80148F90: nop

    // 0x80148F94: jal         0x80148E70
    // 0x80148F98: sb          $zero, 0x1036($s1)
    MEM_B(0X1036, ctx->r17) = 0;
    LOOKUP_FUNC(0x80148E70)(rdram, ctx);
        goto after_2;
    // 0x80148F98: sb          $zero, 0x1036($s1)
    MEM_B(0X1036, ctx->r17) = 0;
    after_2:
    // 0x80148F9C: b           L_80148FA4
    // 0x80148FA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80148FA4;
    // 0x80148FA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80148FA4:
    // 0x80148FA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80148FA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80148FAC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80148FB0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80148FB4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80148FB8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80148FBC: jr          $ra
    // 0x80148FC0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80148FC0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80148fc4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80148fc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148FC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80148FC8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80148FCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80148FD0: sw          $a1, -0x12F0($at)
    MEM_W(-0X12F0, ctx->r1) = ctx->r5;
    // 0x80148FD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148FD8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80148FDC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80148FE0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80148FE4: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80148FE8: addiu       $v0, $v0, -0x12EC
    ctx->r2 = ADD32(ctx->r2, -0X12EC);
    // 0x80148FEC: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x80148FF0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80148FF4: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
    // 0x80148FF8: sb          $a3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r7;
    // 0x80148FFC: jal         0x800058DC
    // 0x80149000: addiu       $a1, $a1, -0x554C
    ctx->r5 = ADD32(ctx->r5, -0X554C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x80149000: addiu       $a1, $a1, -0x554C
    ctx->r5 = ADD32(ctx->r5, -0X554C);
    after_0:
    // 0x80149004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149008: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014900C: jr          $ra
    // 0x80149010: nop

    return;
    // 0x80149010: nop

;}
RECOMP_FUNC void M7_FUN_80149014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80149018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014901C: jal         0x80126E88
    // 0x80149020: addiu       $a0, $zero, 0x113
    ctx->r4 = ADD32(0, 0X113);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_0;
    // 0x80149020: addiu       $a0, $zero, 0x113
    ctx->r4 = ADD32(0, 0X113);
    after_0:
    // 0x80149024: beq         $v0, $zero, L_80149034
    if (ctx->r2 == 0) {
        // 0x80149028: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80149034;
    }
    // 0x80149028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014902C: b           L_80149038
    // 0x80149030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80149038;
    // 0x80149030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80149034:
    // 0x80149034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80149038:
    // 0x80149038: jr          $ra
    // 0x8014903C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8014903C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80149040(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80149040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149040: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80149044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80149048: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x8014904C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80149050: sb          $t6, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r14;
    // 0x80149054: jal         0x80126E88
    // 0x80149058: addiu       $a0, $zero, 0x114
    ctx->r4 = ADD32(0, 0X114);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_0;
    // 0x80149058: addiu       $a0, $zero, 0x114
    ctx->r4 = ADD32(0, 0X114);
    after_0:
    // 0x8014905C: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x80149060: jal         0x80126E88
    // 0x80149064: addiu       $a0, $zero, 0x115
    ctx->r4 = ADD32(0, 0X115);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_1;
    // 0x80149064: addiu       $a0, $zero, 0x115
    ctx->r4 = ADD32(0, 0X115);
    after_1:
    // 0x80149068: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8014906C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80149070: jal         0x80126E88
    // 0x80149074: addiu       $a0, $zero, 0x116
    ctx->r4 = ADD32(0, 0X116);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_2;
    // 0x80149074: addiu       $a0, $zero, 0x116
    ctx->r4 = ADD32(0, 0X116);
    after_2:
    // 0x80149078: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8014907C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80149080: jal         0x80126E88
    // 0x80149084: addiu       $a0, $zero, 0x117
    ctx->r4 = ADD32(0, 0X117);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_3;
    // 0x80149084: addiu       $a0, $zero, 0x117
    ctx->r4 = ADD32(0, 0X117);
    after_3:
    // 0x80149088: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8014908C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80149090: jal         0x80126E88
    // 0x80149094: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_4;
    // 0x80149094: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    after_4:
    // 0x80149098: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8014909C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801490A0: jal         0x80126E88
    // 0x801490A4: addiu       $a0, $zero, 0x119
    ctx->r4 = ADD32(0, 0X119);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_5;
    // 0x801490A4: addiu       $a0, $zero, 0x119
    ctx->r4 = ADD32(0, 0X119);
    after_5:
    // 0x801490A8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x801490AC: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801490B0: jal         0x80126E88
    // 0x801490B4: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_6;
    // 0x801490B4: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    after_6:
    // 0x801490B8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x801490BC: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801490C0: jal         0x80126E88
    // 0x801490C4: addiu       $a0, $zero, 0x11B
    ctx->r4 = ADD32(0, 0X11B);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_7;
    // 0x801490C4: addiu       $a0, $zero, 0x11B
    ctx->r4 = ADD32(0, 0X11B);
    after_7:
    // 0x801490C8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x801490CC: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801490D0: jal         0x80126E88
    // 0x801490D4: addiu       $a0, $zero, 0x11C
    ctx->r4 = ADD32(0, 0X11C);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_8;
    // 0x801490D4: addiu       $a0, $zero, 0x11C
    ctx->r4 = ADD32(0, 0X11C);
    after_8:
    // 0x801490D8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x801490DC: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801490E0: jal         0x80126E88
    // 0x801490E4: addiu       $a0, $zero, 0x11D
    ctx->r4 = ADD32(0, 0X11D);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_9;
    // 0x801490E4: addiu       $a0, $zero, 0x11D
    ctx->r4 = ADD32(0, 0X11D);
    after_9:
    // 0x801490E8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x801490EC: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801490F0: jal         0x80126E88
    // 0x801490F4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_10;
    // 0x801490F4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_10:
    // 0x801490F8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x801490FC: jal         0x80126944
    // 0x80149100: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_11;
    // 0x80149100: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    after_11:
    // 0x80149104: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80149108: beq         $v0, $at, L_80149148
    if (ctx->r2 == ctx->r1) {
        // 0x8014910C: nop
    
            goto L_80149148;
    }
    // 0x8014910C: nop

    // 0x80149110: jal         0x80126E88
    // 0x80149114: addiu       $a0, $zero, 0x11E
    ctx->r4 = ADD32(0, 0X11E);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_12;
    // 0x80149114: addiu       $a0, $zero, 0x11E
    ctx->r4 = ADD32(0, 0X11E);
    after_12:
    // 0x80149118: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8014911C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80149120: jal         0x80126E88
    // 0x80149124: addiu       $a0, $zero, 0x11F
    ctx->r4 = ADD32(0, 0X11F);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_13;
    // 0x80149124: addiu       $a0, $zero, 0x11F
    ctx->r4 = ADD32(0, 0X11F);
    after_13:
    // 0x80149128: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8014912C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80149130: jal         0x80126E88
    // 0x80149134: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_14;
    // 0x80149134: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    after_14:
    // 0x80149138: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8014913C: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x80149140: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80149144: sb          $t7, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r15;
L_80149148:
    // 0x80149148: jal         0x80148E70
    // 0x8014914C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x80148E70)(rdram, ctx);
        goto after_15;
    // 0x8014914C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x80149150: lbu         $t8, 0x26($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X26);
    // 0x80149154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80149158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014915C: bne         $t8, $s0, L_8014916C
    if (ctx->r24 != ctx->r16) {
        // 0x80149160: nop
    
            goto L_8014916C;
    }
    // 0x80149160: nop

    // 0x80149164: b           L_8014916C
    // 0x80149168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014916C;
    // 0x80149168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014916C:
    // 0x8014916C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80149170: jr          $ra
    // 0x80149174: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80149174: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80149178(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80149178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014917C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149180: jal         0x80126E88
    // 0x80149184: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_0;
    // 0x80149184: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_0:
    // 0x80149188: beq         $v0, $zero, L_80149198
    if (ctx->r2 == 0) {
        // 0x8014918C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80149198;
    }
    // 0x8014918C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149190: b           L_8014919C
    // 0x80149194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014919C;
    // 0x80149194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80149198:
    // 0x80149198: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014919C:
    // 0x8014919C: jr          $ra
    // 0x801491A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801491A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801491a4(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801491a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801491A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801491A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801491AC: jal         0x80126E88
    // 0x801491B0: addiu       $a0, $zero, 0x123
    ctx->r4 = ADD32(0, 0X123);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_0;
    // 0x801491B0: addiu       $a0, $zero, 0x123
    ctx->r4 = ADD32(0, 0X123);
    after_0:
    // 0x801491B4: beq         $v0, $zero, L_801491C4
    if (ctx->r2 == 0) {
        // 0x801491B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801491C4;
    }
    // 0x801491B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801491BC: b           L_801491C8
    // 0x801491C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801491C8;
    // 0x801491C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801491C4:
    // 0x801491C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801491C8:
    // 0x801491C8: jr          $ra
    // 0x801491CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801491CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801491d0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801491d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801491D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801491D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801491D8: jal         0x80126E88
    // 0x801491DC: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_0;
    // 0x801491DC: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    after_0:
    // 0x801491E0: beq         $v0, $zero, L_801491F0
    if (ctx->r2 == 0) {
        // 0x801491E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801491F0;
    }
    // 0x801491E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801491E8: b           L_801491F4
    // 0x801491EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801491F4;
    // 0x801491EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801491F0:
    // 0x801491F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801491F4:
    // 0x801491F4: jr          $ra
    // 0x801491F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801491F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801491fc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801491fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801491FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80149200: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80149204: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80149208: jal         0x80126E88
    // 0x8014920C: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_0;
    // 0x8014920C: addiu       $a0, $zero, 0x125
    ctx->r4 = ADD32(0, 0X125);
    after_0:
    // 0x80149210: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x80149214: jal         0x80126E88
    // 0x80149218: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_1;
    // 0x80149218: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_1:
    // 0x8014921C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80149220: lhu         $t6, -0x43E4($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X43E4);
    // 0x80149224: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80149228: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8014922C: bne         $t6, $at, L_8014925C
    if (ctx->r14 != ctx->r1) {
        // 0x80149230: andi        $s0, $s0, 0xFF
        ctx->r16 = ctx->r16 & 0XFF;
            goto L_8014925C;
    }
    // 0x80149230: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80149234: jal         0x80126E88
    // 0x80149238: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_2;
    // 0x80149238: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_2:
    // 0x8014923C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80149240: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80149244: jal         0x80126E88
    // 0x80149248: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_3;
    // 0x80149248: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    after_3:
    // 0x8014924C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80149250: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80149254: b           L_801492A8
    // 0x80149258: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_801492A8;
    // 0x80149258: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_8014925C:
    // 0x8014925C: jal         0x80236C9C
    // 0x80149260: nop

    LOOKUP_FUNC(0x80236C9C)(rdram, ctx);
        goto after_4;
    // 0x80149260: nop

    after_4:
    // 0x80149264: beq         $v0, $zero, L_80149294
    if (ctx->r2 == 0) {
        // 0x80149268: nop
    
            goto L_80149294;
    }
    // 0x80149268: nop

    // 0x8014926C: jal         0x80126E88
    // 0x80149270: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_5;
    // 0x80149270: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    after_5:
    // 0x80149274: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80149278: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8014927C: jal         0x80126E88
    // 0x80149280: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_6;
    // 0x80149280: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    after_6:
    // 0x80149284: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80149288: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8014928C: b           L_801492A8
    // 0x80149290: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_801492A8;
    // 0x80149290: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80149294:
    // 0x80149294: jal         0x80126E88
    // 0x80149298: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_7;
    // 0x80149298: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    after_7:
    // 0x8014929C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x801492A0: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801492A4: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_801492A8:
    // 0x801492A8: bne         $v1, $s0, L_801492B8
    if (ctx->r3 != ctx->r16) {
        // 0x801492AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801492B8;
    }
    // 0x801492AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801492B0: b           L_801492BC
    // 0x801492B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801492BC;
    // 0x801492B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801492B8:
    // 0x801492B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801492BC:
    // 0x801492BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801492C0: jr          $ra
    // 0x801492C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801492C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801492c8(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801492c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801492C8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801492CC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801492D0: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x801492D4: addiu       $v1, $sp, 0x4
    ctx->r3 = ADD32(ctx->r29, 0X4);
    // 0x801492D8: addiu       $t6, $t6, 0x1DC4
    ctx->r14 = ADD32(ctx->r14, 0X1DC4);
    // 0x801492DC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801492E0: addiu       $t0, $t6, 0x54
    ctx->r8 = ADD32(ctx->r14, 0X54);
    // 0x801492E4: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_801492E8:
    // 0x801492E8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801492EC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801492F0: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801492F4: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x801492F8: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x801492FC: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80149300: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80149304: bne         $t6, $t0, L_801492E8
    if (ctx->r14 != ctx->r8) {
        // 0x80149308: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_801492E8;
    }
    // 0x80149308: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8014930C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80149310: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x80149314: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80149318: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8014931C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80149320: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x80149324: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
    // 0x80149328: jr          $ra
    // 0x8014932C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8014932C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80149330(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80149330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80149334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149338: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014933C: jal         0x801492C8
    // 0x80149340: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    LOOKUP_FUNC(0x801492C8)(rdram, ctx);
        goto after_0;
    // 0x80149340: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_0:
    // 0x80149344: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80149348: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x8014934C: jal         0x80126A0C
    // 0x80149350: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_1;
    // 0x80149350: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80149354: bne         $v0, $zero, L_80149364
    if (ctx->r2 != 0) {
        // 0x80149358: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80149364;
    }
    // 0x80149358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014935C: b           L_80149368
    // 0x80149360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80149368;
    // 0x80149360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80149364:
    // 0x80149364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80149368:
    // 0x80149368: jr          $ra
    // 0x8014936C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8014936C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80149370(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80149370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149370: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80149374: addiu       $v1, $v1, 0x1C28
    ctx->r3 = ADD32(ctx->r3, 0X1C28);
    // 0x80149378: lb          $t6, 0x10($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X10);
    // 0x8014937C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80149380: lb          $t8, 0x11($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X11);
    // 0x80149384: lb          $t9, 0x12($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X12);
    // 0x80149388: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8014938C: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80149390: sb          $t7, 0xF2F($v0)
    MEM_B(0XF2F, ctx->r2) = ctx->r15;
    // 0x80149394: sb          $t8, 0xF30($v0)
    MEM_B(0XF30, ctx->r2) = ctx->r24;
    // 0x80149398: jr          $ra
    // 0x8014939C: sb          $t9, 0xF31($v0)
    MEM_B(0XF31, ctx->r2) = ctx->r25;
    return;
    // 0x8014939C: sb          $t9, 0xF31($v0)
    MEM_B(0XF31, ctx->r2) = ctx->r25;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801493a0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801493a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801493A0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801493A4: addiu       $v1, $v1, 0x1D5C
    ctx->r3 = ADD32(ctx->r3, 0X1D5C);
    // 0x801493A8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_801493ac(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_801493ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801493AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801493B0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801493B4: addiu       $v0, $v0, 0x1D60
    ctx->r2 = ADD32(ctx->r2, 0X1D60);
    // 0x801493B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801493BC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801493C0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801493C4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801493C8: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x801493CC: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801493D0: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801493D4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801493D8: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801493DC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801493E0: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801493E4: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x801493E8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801493EC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801493F0: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801493F4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801493F8: lwc1        $f8, 0xC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XC);
    // 0x801493FC: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x80149400: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80149404: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80149408: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8014940C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80149410: lh          $t0, 0x10($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X10);
    // 0x80149414: sh          $t0, 0x10($t2)
    MEM_H(0X10, ctx->r10) = ctx->r8;
    // 0x80149418: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8014941C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80149420: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80149424: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x80149428: lh          $t5, 0x12($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X12);
    // 0x8014942C: sh          $t5, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r13;
    // 0x80149430: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80149434: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80149438: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8014943C: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80149440: lh          $t1, 0x14($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X14);
    // 0x80149444: sh          $t1, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r9;
    // 0x80149448: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8014944C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80149450: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80149454: lw          $t5, 0x30($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X30);
    // 0x80149458: lwc1        $f10, 0x18($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X18);
    // 0x8014945C: swc1        $f10, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f10.u32l;
    // 0x80149460: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80149464: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80149468: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8014946C: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80149470: lwc1        $f16, 0x1C($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80149474: swc1        $f16, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f16.u32l;
    // 0x80149478: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8014947C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80149480: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x80149484: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80149488: lwc1        $f18, 0x20($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X20);
    // 0x8014948C: jal         0x80149370
    // 0x80149490: swc1        $f18, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f18.u32l;
    LOOKUP_FUNC(0x80149370)(rdram, ctx);
        goto after_0;
    // 0x80149490: swc1        $f18, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f18.u32l;
    after_0:
    // 0x80149494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014949C: jr          $ra
    // 0x801494A0: nop

    return;
    // 0x801494A0: nop

;}
RECOMP_FUNC void M7_FUN_801494a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801494A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801494A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801494AC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801494B0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801494B4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801494B8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x801494BC: jal         0x80148768
    // 0x801494C0: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x80148768)(rdram, ctx);
        goto after_0;
    // 0x801494C0: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    after_0:
    // 0x801494C4: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x801494C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801494CC: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801494D0: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801494D4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x801494D8: bne         $t0, $at, L_80149524
    if (ctx->r8 != ctx->r1) {
        // 0x801494DC: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80149524;
    }
    // 0x801494DC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x801494E0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x801494E4: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801494E8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801494EC: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801494F0: addiu       $t7, $t7, 0x1ABC
    ctx->r15 = ADD32(ctx->r15, 0X1ABC);
    // 0x801494F4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x801494F8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801494FC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80149500: lhu         $a1, 0x2($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X2);
    // 0x80149504: lbu         $a2, 0x4($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X4);
    // 0x80149508: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8014950C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80149510: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80149514: jal         0x80147E34
    // 0x80149518: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x80147E34)(rdram, ctx);
        goto after_1;
    // 0x80149518: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8014951C: b           L_8014956C
    // 0x80149520: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_8014956C;
    // 0x80149520: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80149524:
    // 0x80149524: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80149528: bne         $a0, $at, L_8014956C
    if (ctx->r4 != ctx->r1) {
        // 0x8014952C: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_8014956C;
    }
    // 0x8014952C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80149530: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x80149534: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80149538: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8014953C: addiu       $t9, $t9, 0x1ABC
    ctx->r25 = ADD32(ctx->r25, 0X1ABC);
    // 0x80149540: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80149544: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80149548: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8014954C: lhu         $a1, 0x2($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X2);
    // 0x80149550: lbu         $a2, 0x5($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X5);
    // 0x80149554: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80149558: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8014955C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80149560: jal         0x80147E34
    // 0x80149564: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(0x80147E34)(rdram, ctx);
        goto after_2;
    // 0x80149564: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80149568: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_8014956C:
    // 0x8014956C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80149570: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80149574: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80149578: jr          $ra
    // 0x8014957C: nop

    return;
    // 0x8014957C: nop

;}
RECOMP_FUNC void M7_FUN_80149580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149580: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80149584: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80149588: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8014958C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80149590: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80149594: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    // 0x80149598: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8014959C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801495A0: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801495A4: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801495A8: beq         $a1, $zero, L_80149674
    if (ctx->r5 == 0) {
        // 0x801495AC: lwc1        $f12, 0xC($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
            goto L_80149674;
    }
    // 0x801495AC: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801495B0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801495B4: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x801495B8: sh          $t7, 0x168($v0)
    MEM_H(0X168, ctx->r2) = ctx->r15;
    // 0x801495BC: addiu       $t8, $t8, 0x1D8C
    ctx->r24 = ADD32(ctx->r24, 0X1D8C);
    // 0x801495C0: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801495C4: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x801495C8: lw          $a0, 0x3C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X3C);
    // 0x801495CC: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x801495D0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801495D4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801495D8: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x801495DC: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x801495E0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801495E4: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x801495E8: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x801495EC: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801495F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801495F4: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x801495F8: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x801495FC: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80149600: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80149604: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80149608: jal         0x8012C4D0
    // 0x8014960C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x8014960C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_0:
    // 0x80149610: lbu         $a1, 0x43($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X43);
    // 0x80149614: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80149618: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8014961C: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80149620: addiu       $v1, $v1, -0x12D4
    ctx->r3 = ADD32(ctx->r3, -0X12D4);
    // 0x80149624: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80149628: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8014962C: sb          $a1, 0x90($v0)
    MEM_B(0X90, ctx->r2) = ctx->r5;
    // 0x80149630: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80149634: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80149638: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8014963C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80149640: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80149644: jal         0x801494A4
    // 0x80149648: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    LOOKUP_FUNC(0x801494A4)(rdram, ctx);
        goto after_1;
    // 0x80149648: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8014964C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80149650: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80149654: sw          $v0, 0x1D60($at)
    MEM_W(0X1D60, ctx->r1) = ctx->r2;
    // 0x80149658: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8014965C: jal         0x80149370
    // 0x80149660: sw          $t4, 0x1D5C($at)
    MEM_W(0X1D5C, ctx->r1) = ctx->r12;
    LOOKUP_FUNC(0x80149370)(rdram, ctx);
        goto after_2;
    // 0x80149660: sw          $t4, 0x1D5C($at)
    MEM_W(0X1D5C, ctx->r1) = ctx->r12;
    after_2:
    // 0x80149664: jal         0x801493A0
    // 0x80149668: nop

    LOOKUP_FUNC(0x801493A0)(rdram, ctx);
        goto after_3;
    // 0x80149668: nop

    after_3:
    // 0x8014966C: jal         0x80006214
    // 0x80149670: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_4;
    // 0x80149670: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
L_80149674:
    // 0x80149674: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80149678: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8014967C: jr          $ra
    // 0x80149680: nop

    return;
    // 0x80149680: nop

;}
RECOMP_FUNC void M7_FUN_80149684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80149688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014968C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80149690: jal         0x80006088
    // 0x80149694: lw          $a0, 0x1D60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1D60);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_0;
    // 0x80149694: lw          $a0, 0x1D60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1D60);
    after_0:
    // 0x80149698: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014969C: sh          $zero, -0x42A8($at)
    MEM_H(-0X42A8, ctx->r1) = 0;
    // 0x801496A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801496A4: sw          $zero, 0x1D60($at)
    MEM_W(0X1D60, ctx->r1) = 0;
    // 0x801496A8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801496AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801496B0: addiu       $v0, $v0, -0x12D4
    ctx->r2 = ADD32(ctx->r2, -0X12D4);
    // 0x801496B4: sw          $zero, 0x1D5C($at)
    MEM_W(0X1D5C, ctx->r1) = 0;
    // 0x801496B8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801496BC: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x801496C0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801496C4: sh          $t6, 0x3C($t7)
    MEM_H(0X3C, ctx->r15) = ctx->r14;
    // 0x801496C8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x801496CC: jal         0x800058DC
    // 0x801496D0: addiu       $a1, $a1, -0x68F8
    ctx->r5 = ADD32(ctx->r5, -0X68F8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801496D0: addiu       $a1, $a1, -0x68F8
    ctx->r5 = ADD32(ctx->r5, -0X68F8);
    after_1:
    // 0x801496D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801496D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801496DC: jr          $ra
    // 0x801496E0: nop

    return;
    // 0x801496E0: nop

;}
RECOMP_FUNC void M7_FUN_801496e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801496E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801496E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801496EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801496F0: jal         0x801493A0
    // 0x801496F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801493A0)(rdram, ctx);
        goto after_0;
    // 0x801496F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801496F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801496FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80149700: jr          $ra
    // 0x80149704: nop

    return;
    // 0x80149704: nop

;}
RECOMP_FUNC void M7_FUN_80149708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149708: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014970C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149710: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80149714: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80149718: lhu         $t6, 0x3C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X3C);
    // 0x8014971C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80149720: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80149724: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80149728: bne         $t8, $zero, L_8014974C
    if (ctx->r24 != 0) {
        // 0x8014972C: sh          $t7, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r15;
            goto L_8014974C;
    }
    // 0x8014972C: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x80149730: lbu         $a0, 0x90($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X90);
    // 0x80149734: jal         0x801492C8
    // 0x80149738: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801492C8)(rdram, ctx);
        goto after_0;
    // 0x80149738: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8014973C: jal         0x80126E88
    // 0x80149740: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    LOOKUP_FUNC(0x80126E88)(rdram, ctx);
        goto after_1;
    // 0x80149740: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_1:
    // 0x80149744: jal         0x80005700
    // 0x80149748: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x80149748: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8014974C:
    // 0x8014974C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80149754: jr          $ra
    // 0x80149758: nop

    return;
    // 0x80149758: nop

;}
RECOMP_FUNC void M7_FUN_8014975c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014975C: jr          $ra
    // 0x80149760: nop

    return;
    // 0x80149760: nop

;}
RECOMP_FUNC void M7_FUN_80149764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149764: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80149768: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8014976C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80149770: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80149774: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80149778: sb          $zero, 0x47($sp)
    MEM_B(0X47, ctx->r29) = 0;
    // 0x8014977C: addiu       $a1, $zero, 0x113
    ctx->r5 = ADD32(0, 0X113);
    // 0x80149780: jal         0x80126A0C
    // 0x80149784: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x80149784: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80149788: beq         $v0, $zero, L_8014986C
    if (ctx->r2 == 0) {
        // 0x8014978C: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_8014986C;
    }
    // 0x8014978C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80149790: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80149794: jal         0x80148044
    // 0x80149798: sb          $t6, -0x33DB($at)
    MEM_B(-0X33DB, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x80148044)(rdram, ctx);
        goto after_1;
    // 0x80149798: sb          $t6, -0x33DB($at)
    MEM_B(-0X33DB, ctx->r1) = ctx->r14;
    after_1:
    // 0x8014979C: bne         $v0, $zero, L_801497AC
    if (ctx->r2 != 0) {
        // 0x801497A0: nop
    
            goto L_801497AC;
    }
    // 0x801497A0: nop

    // 0x801497A4: jal         0x801FBB30
    // 0x801497A8: nop

    LOOKUP_FUNC(0x801FBB30)(rdram, ctx);
        goto after_2;
    // 0x801497A8: nop

    after_2:
L_801497AC:
    // 0x801497AC: jal         0x80020744
    // 0x801497B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_3;
    // 0x801497B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x801497B4: jal         0x80116E80
    // 0x801497B8: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_4;
    // 0x801497B8: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_4:
    // 0x801497BC: jal         0x80116E80
    // 0x801497C0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_5;
    // 0x801497C0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_5:
    // 0x801497C4: jal         0x80116E80
    // 0x801497C8: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    LOOKUP_FUNC(0x80116E80)(rdram, ctx);
        goto after_6;
    // 0x801497C8: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    after_6:
    // 0x801497CC: addiu       $t7, $zero, 0x140
    ctx->r15 = ADD32(0, 0X140);
    // 0x801497D0: addiu       $t8, $zero, 0xF0
    ctx->r24 = ADD32(0, 0XF0);
    // 0x801497D4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801497D8: addiu       $t0, $zero, 0x66
    ctx->r8 = ADD32(0, 0X66);
    // 0x801497DC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801497E0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801497E4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801497E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801497EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801497F0: addiu       $a1, $sp, 0x47
    ctx->r5 = ADD32(ctx->r29, 0X47);
    // 0x801497F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801497F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801497FC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80149800: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80149804: jal         0x80146178
    // 0x80149808: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_7;
    // 0x80149808: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_7:
    // 0x8014980C: jal         0x80006214
    // 0x80149810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_8;
    // 0x80149810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80149814: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80149818: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8014981C: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x80149820: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80149824: lw          $t5, -0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, -0X4);
    // 0x80149828: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8014982C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80149830: sh          $t1, 0x28($t5)
    MEM_H(0X28, ctx->r13) = ctx->r9;
    // 0x80149834: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80149838: addiu       $t7, $t7, -0x4374
    ctx->r15 = ADD32(ctx->r15, -0X4374);
    // 0x8014983C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80149840: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80149844: addiu       $t0, $t0, -0x3FC4
    ctx->r8 = ADD32(ctx->r8, -0X3FC4);
    // 0x80149848: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014984C: sb          $t6, 0x92($s0)
    MEM_B(0X92, ctx->r16) = ctx->r14;
    // 0x80149850: sw          $t7, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->r15;
    // 0x80149854: sb          $t8, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r24;
    // 0x80149858: sb          $t9, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r25;
    // 0x8014985C: sw          $t0, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r8;
    // 0x80149860: addiu       $a1, $a1, -0x6734
    ctx->r5 = ADD32(ctx->r5, -0X6734);
    // 0x80149864: jal         0x800058DC
    // 0x80149868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x80149868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_8014986C:
    // 0x8014986C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80149870: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80149874: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80149878: jr          $ra
    // 0x8014987C: nop

    return;
    // 0x8014987C: nop

;}
RECOMP_FUNC void M7_FUN_80149880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80149884: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80149888: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014988C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149890: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80149894: sb          $t6, -0x33DB($at)
    MEM_B(-0X33DB, ctx->r1) = ctx->r14;
    // 0x80149898: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8014989C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801498A0: sb          $v0, 0x92($a0)
    MEM_B(0X92, ctx->r4) = ctx->r2;
    // 0x801498A4: lw          $t8, 0x94($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X94);
    // 0x801498A8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801498AC: sb          $v0, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r2;
    // 0x801498B0: addiu       $a1, $a1, -0x617C
    ctx->r5 = ADD32(ctx->r5, -0X617C);
    // 0x801498B4: jal         0x800058DC
    // 0x801498B8: sw          $t8, 0xA4($a0)
    MEM_W(0XA4, ctx->r4) = ctx->r24;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801498B8: sw          $t8, 0xA4($a0)
    MEM_W(0XA4, ctx->r4) = ctx->r24;
    after_0:
    // 0x801498BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801498C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801498C4: jr          $ra
    // 0x801498C8: nop

    return;
    // 0x801498C8: nop

;}
RECOMP_FUNC void M7_FUN_801498cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801498CC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801498D0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801498D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801498D8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801498DC: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x801498E0: lui         $a0, 0xF00
    ctx->r4 = S32(0XF00 << 16);
    // 0x801498E4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801498E8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801498EC: sb          $zero, 0x54($sp)
    MEM_B(0X54, ctx->r29) = 0;
    // 0x801498F0: ori         $a0, $a0, 0xF0F
    ctx->r4 = ctx->r4 | 0XF0F;
    // 0x801498F4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801498F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801498FC: jal         0x80002364
    // 0x80149900: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80002364)(rdram, ctx);
        goto after_0;
    // 0x80149900: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80149904: sb          $zero, 0x91($s1)
    MEM_B(0X91, ctx->r17) = 0;
    // 0x80149908: jal         0x80006214
    // 0x8014990C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x8014990C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80149910: addiu       $s2, $sp, 0x54
    ctx->r18 = ADD32(ctx->r29, 0X54);
    // 0x80149914: addiu       $t6, $zero, 0x70
    ctx->r14 = ADD32(0, 0X70);
    // 0x80149918: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x8014991C: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80149920: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80149924: addiu       $t0, $zero, 0x20E
    ctx->r8 = ADD32(0, 0X20E);
    // 0x80149928: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8014992C: sb          $v0, 0x56($sp)
    MEM_B(0X56, ctx->r29) = ctx->r2;
    // 0x80149930: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80149934: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80149938: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8014993C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80149940: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80149944: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80149948: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8014994C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80149950: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80149954: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    // 0x80149958: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8014995C: jal         0x80146208
    // 0x80149960: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x80149960: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_2:
    // 0x80149964: addiu       $t2, $zero, 0x5C
    ctx->r10 = ADD32(0, 0X5C);
    // 0x80149968: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8014996C: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80149970: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80149974: addiu       $t6, $zero, 0x20E
    ctx->r14 = ADD32(0, 0X20E);
    // 0x80149978: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8014997C: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x80149980: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80149984: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80149988: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8014998C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80149990: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80149994: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80149998: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014999C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801499A0: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801499A4: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    // 0x801499A8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801499AC: jal         0x80146208
    // 0x801499B0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x801499B0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_3:
    // 0x801499B4: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x801499B8: addiu       $t8, $zero, 0x70
    ctx->r24 = ADD32(0, 0X70);
    // 0x801499BC: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x801499C0: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x801499C4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801499C8: addiu       $t2, $zero, 0x20E
    ctx->r10 = ADD32(0, 0X20E);
    // 0x801499CC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x801499D0: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x801499D4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801499D8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801499DC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801499E0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801499E4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801499E8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801499EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801499F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801499F4: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x801499F8: addiu       $a3, $zero, 0xA6
    ctx->r7 = ADD32(0, 0XA6);
    // 0x801499FC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80149A00: jal         0x80146208
    // 0x80149A04: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x80149A04: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_4:
    // 0x80149A08: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80149A0C: addiu       $t4, $zero, 0x84
    ctx->r12 = ADD32(0, 0X84);
    // 0x80149A10: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x80149A14: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80149A18: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80149A1C: addiu       $t8, $zero, 0x20E
    ctx->r24 = ADD32(0, 0X20E);
    // 0x80149A20: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80149A24: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80149A28: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80149A2C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80149A30: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80149A34: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80149A38: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80149A3C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80149A40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80149A44: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80149A48: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80149A4C: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    // 0x80149A50: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80149A54: jal         0x80146208
    // 0x80149A58: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_5;
    // 0x80149A58: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_5:
    // 0x80149A5C: lbu         $t1, 0x56($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X56);
    // 0x80149A60: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80149A64: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80149A68: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80149A6C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80149A70: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80149A74: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80149A78: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80149A7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80149A80: jal         0x80006214
    // 0x80149A84: sw          $t4, -0x12E8($at)
    MEM_W(-0X12E8, ctx->r1) = ctx->r12;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_6;
    // 0x80149A84: sw          $t4, -0x12E8($at)
    MEM_W(-0X12E8, ctx->r1) = ctx->r12;
    after_6:
    // 0x80149A88: addiu       $t5, $zero, 0x70
    ctx->r13 = ADD32(0, 0X70);
    // 0x80149A8C: addiu       $t6, $zero, 0x68
    ctx->r14 = ADD32(0, 0X68);
    // 0x80149A90: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80149A94: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80149A98: addiu       $t9, $zero, 0x20E
    ctx->r25 = ADD32(0, 0X20E);
    // 0x80149A9C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80149AA0: sb          $v0, 0x56($sp)
    MEM_B(0X56, ctx->r29) = ctx->r2;
    // 0x80149AA4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80149AA8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80149AAC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80149AB0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80149AB4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80149AB8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80149ABC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80149AC0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80149AC4: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80149AC8: addiu       $a3, $zero, 0x26
    ctx->r7 = ADD32(0, 0X26);
    // 0x80149ACC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80149AD0: jal         0x80146208
    // 0x80149AD4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_7;
    // 0x80149AD4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_7:
    // 0x80149AD8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80149ADC: addiu       $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
    // 0x80149AE0: addiu       $t2, $zero, 0x68
    ctx->r10 = ADD32(0, 0X68);
    // 0x80149AE4: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80149AE8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80149AEC: addiu       $t5, $zero, 0x20E
    ctx->r13 = ADD32(0, 0X20E);
    // 0x80149AF0: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80149AF4: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80149AF8: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80149AFC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80149B00: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80149B04: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80149B08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80149B0C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80149B10: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80149B14: addiu       $a3, $zero, 0x6C
    ctx->r7 = ADD32(0, 0X6C);
    // 0x80149B18: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80149B1C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80149B20: jal         0x80146208
    // 0x80149B24: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_8;
    // 0x80149B24: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_8:
    // 0x80149B28: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80149B2C: addiu       $t6, $zero, 0x70
    ctx->r14 = ADD32(0, 0X70);
    // 0x80149B30: addiu       $t7, $zero, 0x68
    ctx->r15 = ADD32(0, 0X68);
    // 0x80149B34: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80149B38: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80149B3C: addiu       $t1, $zero, 0x20E
    ctx->r9 = ADD32(0, 0X20E);
    // 0x80149B40: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80149B44: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80149B48: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80149B4C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80149B50: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80149B54: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80149B58: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80149B5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80149B60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80149B64: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80149B68: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80149B6C: addiu       $a3, $zero, 0xB2
    ctx->r7 = ADD32(0, 0XB2);
    // 0x80149B70: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80149B74: jal         0x80146208
    // 0x80149B78: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_9;
    // 0x80149B78: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_9:
    // 0x80149B7C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80149B80: addiu       $t2, $zero, 0x84
    ctx->r10 = ADD32(0, 0X84);
    // 0x80149B84: addiu       $t3, $zero, 0x68
    ctx->r11 = ADD32(0, 0X68);
    // 0x80149B88: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80149B8C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80149B90: addiu       $t6, $zero, 0x20E
    ctx->r14 = ADD32(0, 0X20E);
    // 0x80149B94: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80149B98: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80149B9C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80149BA0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80149BA4: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80149BA8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80149BAC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80149BB0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80149BB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80149BB8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80149BBC: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80149BC0: addiu       $a3, $zero, 0x6C
    ctx->r7 = ADD32(0, 0X6C);
    // 0x80149BC4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80149BC8: jal         0x80146208
    // 0x80149BCC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_10;
    // 0x80149BCC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_10:
    // 0x80149BD0: lbu         $t9, 0x56($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X56);
    // 0x80149BD4: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80149BD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80149BDC: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80149BE0: addu        $t0, $t8, $t1
    ctx->r8 = ADD32(ctx->r24, ctx->r9);
    // 0x80149BE4: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80149BE8: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80149BEC: addiu       $t3, $zero, 0xA1
    ctx->r11 = ADD32(0, 0XA1);
    // 0x80149BF0: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80149BF4: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x80149BF8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80149BFC: addiu       $t7, $zero, 0x20E
    ctx->r15 = ADD32(0, 0X20E);
    // 0x80149C00: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80149C04: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80149C08: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80149C0C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80149C10: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80149C14: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80149C18: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80149C1C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80149C20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80149C24: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80149C28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80149C2C: addiu       $a3, $zero, 0x95
    ctx->r7 = ADD32(0, 0X95);
    // 0x80149C30: jal         0x80146208
    // 0x80149C34: sw          $t2, -0x12E4($at)
    MEM_W(-0X12E4, ctx->r1) = ctx->r10;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_11;
    // 0x80149C34: sw          $t2, -0x12E4($at)
    MEM_W(-0X12E4, ctx->r1) = ctx->r10;
    after_11:
    // 0x80149C38: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80149C3C: addiu       $a3, $a3, -0x528
    ctx->r7 = ADD32(ctx->r7, -0X528);
    // 0x80149C40: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80149C44: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80149C48: jal         0x8001B204
    // 0x80149C4C: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_12;
    // 0x80149C4C: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    after_12:
    // 0x80149C50: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80149C54: addiu       $a3, $a3, -0x518
    ctx->r7 = ADD32(ctx->r7, -0X518);
    // 0x80149C58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80149C5C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80149C60: jal         0x8001B204
    // 0x80149C64: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_13;
    // 0x80149C64: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    after_13:
    // 0x80149C68: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80149C6C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80149C70: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80149C74: addiu       $a3, $a3, -0x500
    ctx->r7 = ADD32(ctx->r7, -0X500);
    // 0x80149C78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80149C7C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80149C80: jal         0x8001B204
    // 0x80149C84: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_14;
    // 0x80149C84: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    after_14:
    // 0x80149C88: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80149C8C: sb          $t1, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r9;
    // 0x80149C90: jal         0x80148074
    // 0x80149C94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80148074)(rdram, ctx);
        goto after_15;
    // 0x80149C94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80149C98: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80149C9C: addiu       $a1, $a1, -0x6340
    ctx->r5 = ADD32(ctx->r5, -0X6340);
    // 0x80149CA0: jal         0x800058DC
    // 0x80149CA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_16;
    // 0x80149CA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80149CA8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80149CAC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80149CB0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80149CB4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80149CB8: jr          $ra
    // 0x80149CBC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80149CBC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_80149cc0(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_80149cc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149CC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80149CC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80149CC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80149CCC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80149CD0: lw          $a1, 0xA4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XA4);
    // 0x80149CD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80149CD8: lb          $a2, 0xA2($a0)
    ctx->r6 = MEM_B(ctx->r4, 0XA2);
    // 0x80149CDC: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x80149CE0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80149CE4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80149CE8: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x80149CEC: beq         $t6, $zero, L_80149D00
    if (ctx->r14 == 0) {
        // 0x80149CF0: andi        $t9, $v0, 0x400
        ctx->r25 = ctx->r2 & 0X400;
            goto L_80149D00;
    }
    // 0x80149CF0: andi        $t9, $v0, 0x400
    ctx->r25 = ctx->r2 & 0X400;
    // 0x80149CF4: sb          $t7, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r15;
    // 0x80149CF8: b           L_80149D48
    // 0x80149CFC: sb          $t8, 0xA2($a0)
    MEM_B(0XA2, ctx->r4) = ctx->r24;
        goto L_80149D48;
    // 0x80149CFC: sb          $t8, 0xA2($a0)
    MEM_B(0XA2, ctx->r4) = ctx->r24;
L_80149D00:
    // 0x80149D00: beq         $t9, $zero, L_80149D1C
    if (ctx->r25 == 0) {
        // 0x80149D04: andi        $t2, $v0, 0x200
        ctx->r10 = ctx->r2 & 0X200;
            goto L_80149D1C;
    }
    // 0x80149D04: andi        $t2, $v0, 0x200
    ctx->r10 = ctx->r2 & 0X200;
    // 0x80149D08: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80149D0C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80149D10: sb          $t0, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r8;
    // 0x80149D14: b           L_80149D48
    // 0x80149D18: sb          $t1, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r9;
        goto L_80149D48;
    // 0x80149D18: sb          $t1, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r9;
L_80149D1C:
    // 0x80149D1C: beq         $t2, $zero, L_80149D34
    if (ctx->r10 == 0) {
        // 0x80149D20: andi        $t4, $v0, 0x100
        ctx->r12 = ctx->r2 & 0X100;
            goto L_80149D34;
    }
    // 0x80149D20: andi        $t4, $v0, 0x100
    ctx->r12 = ctx->r2 & 0X100;
    // 0x80149D24: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80149D28: sb          $t3, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r11;
    // 0x80149D2C: b           L_80149D48
    // 0x80149D30: sb          $zero, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = 0;
        goto L_80149D48;
    // 0x80149D30: sb          $zero, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = 0;
L_80149D34:
    // 0x80149D34: beq         $t4, $zero, L_80149D48
    if (ctx->r12 == 0) {
        // 0x80149D38: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80149D48;
    }
    // 0x80149D38: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80149D3C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80149D40: sb          $t5, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r13;
    // 0x80149D44: sb          $t6, 0xA2($s0)
    MEM_B(0XA2, ctx->r16) = ctx->r14;
L_80149D48:
    // 0x80149D48: lb          $t7, 0x94($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X94);
    // 0x80149D4C: beql        $t7, $zero, L_80149D84
    if (ctx->r15 == 0) {
        // 0x80149D50: lhu         $v0, 0x4($a1)
        ctx->r2 = MEM_HU(ctx->r5, 0X4);
            goto L_80149D84;
    }
    goto skip_0;
    // 0x80149D50: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    skip_0:
    // 0x80149D54: lbu         $t8, 0xA2($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XA2);
    // 0x80149D58: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x80149D5C: beql        $t8, $a2, L_80149D74
    if (ctx->r24 == ctx->r6) {
        // 0x80149D60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80149D74;
    }
    goto skip_1;
    // 0x80149D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80149D64: jal         0x80020744
    // 0x80149D68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80149D68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80149D6C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80149D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80149D74:
    // 0x80149D74: jal         0x80148074
    // 0x80149D78: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80148074)(rdram, ctx);
        goto after_1;
    // 0x80149D78: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x80149D7C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80149D80: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
L_80149D84:
    // 0x80149D84: andi        $t0, $v0, 0x8000
    ctx->r8 = ctx->r2 & 0X8000;
    // 0x80149D88: beq         $t0, $zero, L_80149E40
    if (ctx->r8 == 0) {
        // 0x80149D8C: andi        $t2, $v0, 0x4000
        ctx->r10 = ctx->r2 & 0X4000;
            goto L_80149E40;
    }
    // 0x80149D8C: andi        $t2, $v0, 0x4000
    ctx->r10 = ctx->r2 & 0X4000;
    // 0x80149D90: lb          $t1, 0x94($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X94);
    // 0x80149D94: beq         $t1, $zero, L_80149E40
    if (ctx->r9 == 0) {
        // 0x80149D98: nop
    
            goto L_80149E40;
    }
    // 0x80149D98: nop

    // 0x80149D9C: jal         0x80147DCC
    // 0x80149DA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80147DCC)(rdram, ctx);
        goto after_2;
    // 0x80149DA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80149DA4: jal         0x80020744
    // 0x80149DA8: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_3;
    // 0x80149DA8: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_3:
    // 0x80149DAC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80149DB0: jal         0x801471DC
    // 0x80149DB4: lw          $a0, -0x12E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X12E8);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_4;
    // 0x80149DB4: lw          $a0, -0x12E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X12E8);
    after_4:
    // 0x80149DB8: lbu         $v0, 0xA2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA2);
    // 0x80149DBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80149DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80149DC4: beq         $v0, $zero, L_80149DF4
    if (ctx->r2 == 0) {
        // 0x80149DC8: lui         $a1, 0x8038
        ctx->r5 = S32(0X8038 << 16);
            goto L_80149DF4;
    }
    // 0x80149DC8: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80149DCC: beq         $v0, $at, L_80149E04
    if (ctx->r2 == ctx->r1) {
        // 0x80149DD0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80149E04;
    }
    // 0x80149DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80149DD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80149DD8: beq         $v0, $at, L_80149E18
    if (ctx->r2 == ctx->r1) {
        // 0x80149DDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80149E18;
    }
    // 0x80149DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80149DE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80149DE4: beq         $v0, $at, L_80149E2C
    if (ctx->r2 == ctx->r1) {
        // 0x80149DE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80149E2C;
    }
    // 0x80149DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80149DEC: b           L_80149E74
    // 0x80149DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80149E74;
    // 0x80149DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80149DF4:
    // 0x80149DF4: jal         0x800058DC
    // 0x80149DF8: addiu       $a1, $a1, -0x178
    ctx->r5 = ADD32(ctx->r5, -0X178);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x80149DF8: addiu       $a1, $a1, -0x178
    ctx->r5 = ADD32(ctx->r5, -0X178);
    after_5:
    // 0x80149DFC: b           L_80149E74
    // 0x80149E00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80149E74;
    // 0x80149E00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80149E04:
    // 0x80149E04: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80149E08: jal         0x800058DC
    // 0x80149E0C: addiu       $a1, $a1, -0x617C
    ctx->r5 = ADD32(ctx->r5, -0X617C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x80149E0C: addiu       $a1, $a1, -0x617C
    ctx->r5 = ADD32(ctx->r5, -0X617C);
    after_6:
    // 0x80149E10: b           L_80149E74
    // 0x80149E14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80149E74;
    // 0x80149E14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80149E18:
    // 0x80149E18: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80149E1C: jal         0x800058DC
    // 0x80149E20: addiu       $a1, $a1, -0xBD4
    ctx->r5 = ADD32(ctx->r5, -0XBD4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_7;
    // 0x80149E20: addiu       $a1, $a1, -0xBD4
    ctx->r5 = ADD32(ctx->r5, -0XBD4);
    after_7:
    // 0x80149E24: b           L_80149E74
    // 0x80149E28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80149E74;
    // 0x80149E28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80149E2C:
    // 0x80149E2C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80149E30: jal         0x800058DC
    // 0x80149E34: addiu       $a1, $a1, 0x9A4
    ctx->r5 = ADD32(ctx->r5, 0X9A4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x80149E34: addiu       $a1, $a1, 0x9A4
    ctx->r5 = ADD32(ctx->r5, 0X9A4);
    after_8:
    // 0x80149E38: b           L_80149E74
    // 0x80149E3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80149E74;
    // 0x80149E3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80149E40:
    // 0x80149E40: bne         $t2, $zero, L_80149E50
    if (ctx->r10 != 0) {
        // 0x80149E44: andi        $t3, $v0, 0x1000
        ctx->r11 = ctx->r2 & 0X1000;
            goto L_80149E50;
    }
    // 0x80149E44: andi        $t3, $v0, 0x1000
    ctx->r11 = ctx->r2 & 0X1000;
    // 0x80149E48: beql        $t3, $zero, L_80149E74
    if (ctx->r11 == 0) {
        // 0x80149E4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80149E74;
    }
    goto skip_2;
    // 0x80149E4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_80149E50:
    // 0x80149E50: jal         0x80148E44
    // 0x80149E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148E44)(rdram, ctx);
        goto after_9;
    // 0x80149E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80149E58: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80149E5C: addiu       $a1, $a1, -0x54B8
    ctx->r5 = ADD32(ctx->r5, -0X54B8);
    // 0x80149E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80149E64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80149E68: jal         0x80148FC4
    // 0x80149E6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_10;
    // 0x80149E6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x80149E70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80149E74:
    // 0x80149E74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80149E78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80149E7C: jr          $ra
    // 0x80149E80: nop

    return;
    // 0x80149E80: nop

;}
RECOMP_FUNC void M7_FUN_80149e84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149E84: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80149E88: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80149E8C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80149E90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80149E94: jal         0x80148EA4
    // 0x80149E98: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80148EA4)(rdram, ctx);
        goto after_0;
    // 0x80149E98: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x80149E9C: beq         $v0, $zero, L_8014A220
    if (ctx->r2 == 0) {
        // 0x80149EA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8014A220;
    }
    // 0x80149EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80149EA4: sb          $zero, 0x96($s0)
    MEM_B(0X96, ctx->r16) = 0;
    // 0x80149EA8: lb          $t6, 0x96($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X96);
    // 0x80149EAC: sb          $zero, 0x90($s0)
    MEM_B(0X90, ctx->r16) = 0;
    // 0x80149EB0: sb          $zero, 0x94($s0)
    MEM_B(0X94, ctx->r16) = 0;
    // 0x80149EB4: sb          $t6, 0x95($s0)
    MEM_B(0X95, ctx->r16) = ctx->r14;
    // 0x80149EB8: addiu       $t7, $zero, 0x2C
    ctx->r15 = ADD32(0, 0X2C);
    // 0x80149EBC: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80149EC0: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x80149EC4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80149EC8: addiu       $t1, $zero, 0x21C
    ctx->r9 = ADD32(0, 0X21C);
    // 0x80149ECC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80149ED0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80149ED4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80149ED8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80149EDC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80149EE0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80149EE4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80149EE8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80149EEC: addiu       $a1, $sp, 0x4F
    ctx->r5 = ADD32(ctx->r29, 0X4F);
    // 0x80149EF0: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    // 0x80149EF4: jal         0x80146208
    // 0x80149EF8: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x80149EF8: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    after_1:
    // 0x80149EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80149F00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80149F04: jal         0x80145348
    // 0x80149F08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_2;
    // 0x80149F08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80149F0C: jal         0x80006214
    // 0x80149F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_3;
    // 0x80149F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80149F14: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80149F18: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80149F1C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80149F20: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80149F24: lw          $t5, -0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, -0X4);
    // 0x80149F28: addiu       $t6, $zero, 0x2C
    ctx->r14 = ADD32(0, 0X2C);
    // 0x80149F2C: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80149F30: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80149F34: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80149F38: addiu       $t0, $zero, 0x21C
    ctx->r8 = ADD32(0, 0X21C);
    // 0x80149F3C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80149F40: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80149F44: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80149F48: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80149F4C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80149F50: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80149F54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80149F58: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80149F5C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80149F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80149F64: addiu       $a1, $sp, 0x4F
    ctx->r5 = ADD32(ctx->r29, 0X4F);
    // 0x80149F68: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80149F6C: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    // 0x80149F70: jal         0x80146208
    // 0x80149F74: sw          $t5, -0x12E8($at)
    MEM_W(-0X12E8, ctx->r1) = ctx->r13;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x80149F74: sw          $t5, -0x12E8($at)
    MEM_W(-0X12E8, ctx->r1) = ctx->r13;
    after_4:
    // 0x80149F78: jal         0x80006214
    // 0x80149F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_5;
    // 0x80149F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80149F80: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80149F84: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80149F88: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80149F8C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80149F90: lw          $t5, -0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, -0X4);
    // 0x80149F94: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80149F98: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80149F9C: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80149FA0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80149FA4: addiu       $t0, $zero, 0x21C
    ctx->r8 = ADD32(0, 0X21C);
    // 0x80149FA8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80149FAC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80149FB0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80149FB4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80149FB8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80149FBC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80149FC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80149FC4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80149FC8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80149FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80149FD0: addiu       $a1, $sp, 0x4F
    ctx->r5 = ADD32(ctx->r29, 0X4F);
    // 0x80149FD4: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80149FD8: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    // 0x80149FDC: jal         0x80146208
    // 0x80149FE0: sw          $t5, -0x12E0($at)
    MEM_W(-0X12E0, ctx->r1) = ctx->r13;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_6;
    // 0x80149FE0: sw          $t5, -0x12E0($at)
    MEM_W(-0X12E0, ctx->r1) = ctx->r13;
    after_6:
    // 0x80149FE4: jal         0x80006214
    // 0x80149FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_7;
    // 0x80149FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80149FEC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80149FF0: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80149FF4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80149FF8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80149FFC: lw          $t5, -0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, -0X4);
    // 0x8014A000: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8014A004: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8014A008: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8014A00C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8014A010: addiu       $t0, $zero, 0x21C
    ctx->r8 = ADD32(0, 0X21C);
    // 0x8014A014: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8014A018: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8014A01C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8014A020: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8014A024: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8014A028: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8014A02C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8014A030: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8014A034: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8014A038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A03C: addiu       $a1, $sp, 0x4F
    ctx->r5 = ADD32(ctx->r29, 0X4F);
    // 0x8014A040: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8014A044: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x8014A048: jal         0x80146208
    // 0x8014A04C: sw          $t5, -0x12D8($at)
    MEM_W(-0X12D8, ctx->r1) = ctx->r13;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_8;
    // 0x8014A04C: sw          $t5, -0x12D8($at)
    MEM_W(-0X12D8, ctx->r1) = ctx->r13;
    after_8:
    // 0x8014A050: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x8014A054: addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    // 0x8014A058: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8014A05C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8014A060: addiu       $t6, $zero, 0x21C
    ctx->r14 = ADD32(0, 0X21C);
    // 0x8014A064: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8014A068: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8014A06C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8014A070: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8014A074: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8014A078: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8014A07C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8014A080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A084: addiu       $a1, $sp, 0x4F
    ctx->r5 = ADD32(ctx->r29, 0X4F);
    // 0x8014A088: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8014A08C: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x8014A090: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8014A094: jal         0x80146208
    // 0x8014A098: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_9;
    // 0x8014A098: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_9:
    // 0x8014A09C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014A0A0: lw          $v1, -0x12D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X12D8);
    // 0x8014A0A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8014A0A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014A0AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014A0B0:
    // 0x8014A0B0: lb          $t8, 0x91($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X91);
    // 0x8014A0B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8014A0B8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8014A0BC: bne         $a1, $t8, L_8014A0CC
    if (ctx->r5 != ctx->r24) {
        // 0x8014A0C0: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_8014A0CC;
    }
    // 0x8014A0C0: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8014A0C4: b           L_8014A0D0
    // 0x8014A0C8: sb          $v0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r2;
        goto L_8014A0D0;
    // 0x8014A0C8: sb          $v0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r2;
L_8014A0CC:
    // 0x8014A0CC: sb          $zero, 0x22($v1)
    MEM_B(0X22, ctx->r3) = 0;
L_8014A0D0:
    // 0x8014A0D0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8014A0D4: bne         $at, $zero, L_8014A0B0
    if (ctx->r1 != 0) {
        // 0x8014A0D8: lw          $v1, 0x10($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X10);
            goto L_8014A0B0;
    }
    // 0x8014A0D8: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
    // 0x8014A0DC: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8014A0E0: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8014A0E4: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8014A0E8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8014A0EC: addiu       $t3, $zero, 0x209
    ctx->r11 = ADD32(0, 0X209);
    // 0x8014A0F0: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x8014A0F4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8014A0F8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8014A0FC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8014A100: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8014A104: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8014A108: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8014A10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A110: addiu       $a1, $sp, 0x4F
    ctx->r5 = ADD32(ctx->r29, 0X4F);
    // 0x8014A114: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8014A118: addiu       $a3, $zero, 0x4C
    ctx->r7 = ADD32(0, 0X4C);
    // 0x8014A11C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8014A120: jal         0x80146208
    // 0x8014A124: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_10;
    // 0x8014A124: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_10:
    // 0x8014A128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A12C: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8014A130: jal         0x80145348
    // 0x8014A134: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_11;
    // 0x8014A134: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_11:
    // 0x8014A138: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x8014A13C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8014A140: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8014A144: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8014A148: addiu       $t9, $zero, 0x21C
    ctx->r25 = ADD32(0, 0X21C);
    // 0x8014A14C: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x8014A150: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8014A154: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8014A158: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8014A15C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8014A160: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8014A164: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8014A168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A16C: addiu       $a1, $sp, 0x4F
    ctx->r5 = ADD32(ctx->r29, 0X4F);
    // 0x8014A170: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8014A174: addiu       $a3, $zero, 0x57
    ctx->r7 = ADD32(0, 0X57);
    // 0x8014A178: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8014A17C: jal         0x80146208
    // 0x8014A180: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_12;
    // 0x8014A180: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_12:
    // 0x8014A184: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8014A188: addiu       $a3, $a3, -0x4E4
    ctx->r7 = ADD32(ctx->r7, -0X4E4);
    // 0x8014A18C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8014A190: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    // 0x8014A194: jal         0x8001B204
    // 0x8014A198: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_13;
    // 0x8014A198: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    after_13:
    // 0x8014A19C: addiu       $t1, $zero, 0x84
    ctx->r9 = ADD32(0, 0X84);
    // 0x8014A1A0: addiu       $t2, $zero, 0x3D
    ctx->r10 = ADD32(0, 0X3D);
    // 0x8014A1A4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8014A1A8: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x8014A1AC: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8014A1B0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8014A1B4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8014A1B8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8014A1BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A1C0: addiu       $a1, $sp, 0x4F
    ctx->r5 = ADD32(ctx->r29, 0X4F);
    // 0x8014A1C4: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x8014A1C8: addiu       $a3, $zero, 0x8F
    ctx->r7 = ADD32(0, 0X8F);
    // 0x8014A1CC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8014A1D0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8014A1D4: jal         0x80146178
    // 0x8014A1D8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146178)(rdram, ctx);
        goto after_14;
    // 0x8014A1D8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_14:
    // 0x8014A1DC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8014A1E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014A1E4: jal         0x80149370
    // 0x8014A1E8: sh          $t5, -0x42A8($at)
    MEM_H(-0X42A8, ctx->r1) = ctx->r13;
    LOOKUP_FUNC(0x80149370)(rdram, ctx);
        goto after_15;
    // 0x8014A1E8: sh          $t5, -0x42A8($at)
    MEM_H(-0X42A8, ctx->r1) = ctx->r13;
    after_15:
    // 0x8014A1EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A1F0: jal         0x801482BC
    // 0x8014A1F4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    LOOKUP_FUNC(0x801482BC)(rdram, ctx);
        goto after_16;
    // 0x8014A1F4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_16:
    // 0x8014A1F8: sb          $zero, 0x90($s0)
    MEM_B(0X90, ctx->r16) = 0;
    // 0x8014A1FC: sh          $zero, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = 0;
    // 0x8014A200: jal         0x80148500
    // 0x8014A204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148500)(rdram, ctx);
        goto after_17;
    // 0x8014A204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8014A208: jal         0x80148958
    // 0x8014A20C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148958)(rdram, ctx);
        goto after_18;
    // 0x8014A20C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8014A210: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014A214: addiu       $a1, $a1, -0x5DCC
    ctx->r5 = ADD32(ctx->r5, -0X5DCC);
    // 0x8014A218: jal         0x800058DC
    // 0x8014A21C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_19;
    // 0x8014A21C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
L_8014A220:
    // 0x8014A220: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8014A224: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8014A228: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8014A22C: jr          $ra
    // 0x8014A230: nop

    return;
    // 0x8014A230: nop

;}
RECOMP_FUNC void M7_FUN_8014a234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A234: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014A238: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014A23C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014A240: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8014A244: lw          $t6, 0x98($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X98);
    // 0x8014A248: lw          $t0, 0xA4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XA4);
    // 0x8014A24C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014A250: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8014A254: lhu         $v0, 0xC($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0XC);
    // 0x8014A258: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014A25C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8014A260: andi        $t7, $v0, 0x800
    ctx->r15 = ctx->r2 & 0X800;
    // 0x8014A264: beq         $t7, $zero, L_8014A274
    if (ctx->r15 == 0) {
        // 0x8014A268: andi        $t8, $v0, 0x400
        ctx->r24 = ctx->r2 & 0X400;
            goto L_8014A274;
    }
    // 0x8014A268: andi        $t8, $v0, 0x400
    ctx->r24 = ctx->r2 & 0X400;
    // 0x8014A26C: b           L_8014A2A0
    // 0x8014A270: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_8014A2A0;
    // 0x8014A270: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8014A274:
    // 0x8014A274: beq         $t8, $zero, L_8014A284
    if (ctx->r24 == 0) {
        // 0x8014A278: andi        $t9, $v0, 0x200
        ctx->r25 = ctx->r2 & 0X200;
            goto L_8014A284;
    }
    // 0x8014A278: andi        $t9, $v0, 0x200
    ctx->r25 = ctx->r2 & 0X200;
    // 0x8014A27C: b           L_8014A2A0
    // 0x8014A280: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8014A2A0;
    // 0x8014A280: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8014A284:
    // 0x8014A284: beq         $t9, $zero, L_8014A294
    if (ctx->r25 == 0) {
        // 0x8014A288: andi        $t1, $v0, 0x100
        ctx->r9 = ctx->r2 & 0X100;
            goto L_8014A294;
    }
    // 0x8014A288: andi        $t1, $v0, 0x100
    ctx->r9 = ctx->r2 & 0X100;
    // 0x8014A28C: b           L_8014A2A0
    // 0x8014A290: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_8014A2A0;
    // 0x8014A290: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8014A294:
    // 0x8014A294: beql        $t1, $zero, L_8014A2A4
    if (ctx->r9 == 0) {
        // 0x8014A298: sb          $a2, 0x25($sp)
        MEM_B(0X25, ctx->r29) = ctx->r6;
            goto L_8014A2A4;
    }
    goto skip_0;
    // 0x8014A298: sb          $a2, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r6;
    skip_0:
    // 0x8014A29C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8014A2A0:
    // 0x8014A2A0: sb          $a2, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r6;
L_8014A2A4:
    // 0x8014A2A4: sb          $a3, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r7;
    // 0x8014A2A8: jal         0x80149370
    // 0x8014A2AC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(0x80149370)(rdram, ctx);
        goto after_0;
    // 0x8014A2AC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_0:
    // 0x8014A2B0: jal         0x80148B6C
    // 0x8014A2B4: nop

    LOOKUP_FUNC(0x80148B6C)(rdram, ctx);
        goto after_1;
    // 0x8014A2B4: nop

    after_1:
    // 0x8014A2B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A2BC: jal         0x801486A8
    // 0x8014A2C0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    LOOKUP_FUNC(0x801486A8)(rdram, ctx);
        goto after_2;
    // 0x8014A2C0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_2:
    // 0x8014A2C4: lb          $a2, 0x25($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X25);
    // 0x8014A2C8: lb          $a3, 0x24($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X24);
    // 0x8014A2CC: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x8014A2D0: bnel        $a2, $zero, L_8014A2E4
    if (ctx->r6 != 0) {
        // 0x8014A2D4: sb          $a2, 0x25($sp)
        MEM_B(0X25, ctx->r29) = ctx->r6;
            goto L_8014A2E4;
    }
    goto skip_1;
    // 0x8014A2D4: sb          $a2, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r6;
    skip_1:
    // 0x8014A2D8: beq         $a3, $zero, L_8014A360
    if (ctx->r7 == 0) {
        // 0x8014A2DC: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_8014A360;
    }
    // 0x8014A2DC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8014A2E0: sb          $a2, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r6;
L_8014A2E4:
    // 0x8014A2E4: jal         0x80020744
    // 0x8014A2E8: sb          $a3, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_3;
    // 0x8014A2E8: sb          $a3, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r7;
    after_3:
    // 0x8014A2EC: lb          $a2, 0x25($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X25);
    // 0x8014A2F0: lb          $a3, 0x24($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X24);
    // 0x8014A2F4: lb          $t2, 0x95($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X95);
    // 0x8014A2F8: lb          $t4, 0x96($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X96);
    // 0x8014A2FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A300: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x8014A304: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x8014A308: sb          $t3, 0x95($s0)
    MEM_B(0X95, ctx->r16) = ctx->r11;
    // 0x8014A30C: jal         0x80148D84
    // 0x8014A310: sb          $t5, 0x96($s0)
    MEM_B(0X96, ctx->r16) = ctx->r13;
    LOOKUP_FUNC(0x80148D84)(rdram, ctx);
        goto after_4;
    // 0x8014A310: sb          $t5, 0x96($s0)
    MEM_B(0X96, ctx->r16) = ctx->r13;
    after_4:
    // 0x8014A314: lb          $a0, 0x95($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X95);
    // 0x8014A318: jal         0x80148B2C
    // 0x8014A31C: lb          $a1, 0x96($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X96);
    LOOKUP_FUNC(0x80148B2C)(rdram, ctx);
        goto after_5;
    // 0x8014A31C: lb          $a1, 0x96($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X96);
    after_5:
    // 0x8014A320: lbu         $a0, 0x95($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X95);
    // 0x8014A324: jal         0x80148124
    // 0x8014A328: lbu         $a1, 0x96($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X96);
    LOOKUP_FUNC(0x80148124)(rdram, ctx);
        goto after_6;
    // 0x8014A328: lbu         $a1, 0x96($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X96);
    after_6:
    // 0x8014A32C: sb          $v0, 0x90($s0)
    MEM_B(0X90, ctx->r16) = ctx->r2;
    // 0x8014A330: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8014A334: jal         0x80006088
    // 0x8014A338: lw          $a0, 0x1D5C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1D5C);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_7;
    // 0x8014A338: lw          $a0, 0x1D5C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1D5C);
    after_7:
    // 0x8014A33C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8014A340: jal         0x80006088
    // 0x8014A344: lw          $a0, 0x1D60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1D60);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_8;
    // 0x8014A344: lw          $a0, 0x1D60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1D60);
    after_8:
    // 0x8014A348: jal         0x80148500
    // 0x8014A34C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148500)(rdram, ctx);
        goto after_9;
    // 0x8014A34C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8014A350: jal         0x80148958
    // 0x8014A354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148958)(rdram, ctx);
        goto after_10;
    // 0x8014A354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8014A358: b           L_8014A66C
    // 0x8014A35C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8014A66C;
    // 0x8014A35C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014A360:
    // 0x8014A360: jal         0x80148CB0
    // 0x8014A364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148CB0)(rdram, ctx);
        goto after_11;
    // 0x8014A364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8014A368: beq         $v0, $zero, L_8014A398
    if (ctx->r2 == 0) {
        // 0x8014A36C: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_8014A398;
    }
    // 0x8014A36C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8014A370: lbu         $a0, 0x95($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X95);
    // 0x8014A374: jal         0x80148124
    // 0x8014A378: lbu         $a1, 0x96($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X96);
    LOOKUP_FUNC(0x80148124)(rdram, ctx);
        goto after_12;
    // 0x8014A378: lbu         $a1, 0x96($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X96);
    after_12:
    // 0x8014A37C: sb          $v0, 0x90($s0)
    MEM_B(0X90, ctx->r16) = ctx->r2;
    // 0x8014A380: jal         0x80148500
    // 0x8014A384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148500)(rdram, ctx);
        goto after_13;
    // 0x8014A384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8014A388: jal         0x80148958
    // 0x8014A38C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148958)(rdram, ctx);
        goto after_14;
    // 0x8014A38C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8014A390: b           L_8014A66C
    // 0x8014A394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8014A66C;
    // 0x8014A394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014A398:
    // 0x8014A398: lhu         $v0, 0x4($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X4);
    // 0x8014A39C: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
    // 0x8014A3A0: beq         $t7, $zero, L_8014A434
    if (ctx->r15 == 0) {
        // 0x8014A3A4: andi        $t8, $v0, 0x1000
        ctx->r24 = ctx->r2 & 0X1000;
            goto L_8014A434;
    }
    // 0x8014A3A4: andi        $t8, $v0, 0x1000
    ctx->r24 = ctx->r2 & 0X1000;
    // 0x8014A3A8: jal         0x80147DCC
    // 0x8014A3AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80147DCC)(rdram, ctx);
        goto after_15;
    // 0x8014A3AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_15:
    // 0x8014A3B0: jal         0x80126944
    // 0x8014A3B4: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_16;
    // 0x8014A3B4: nop

    after_16:
    // 0x8014A3B8: bne         $v0, $zero, L_8014A3E8
    if (ctx->r2 != 0) {
        // 0x8014A3BC: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_8014A3E8;
    }
    // 0x8014A3BC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8014A3C0: jal         0x801471DC
    // 0x8014A3C4: lw          $a0, -0x12E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X12E8);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_17;
    // 0x8014A3C4: lw          $a0, -0x12E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X12E8);
    after_17:
    // 0x8014A3C8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014A3CC: addiu       $a1, $a1, -0x6734
    ctx->r5 = ADD32(ctx->r5, -0X6734);
    // 0x8014A3D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A3D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8014A3D8: jal         0x80148FC4
    // 0x8014A3DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_18;
    // 0x8014A3DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x8014A3E0: b           L_8014A66C
    // 0x8014A3E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8014A66C;
    // 0x8014A3E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014A3E8:
    // 0x8014A3E8: jal         0x80126944
    // 0x8014A3EC: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_19;
    // 0x8014A3EC: nop

    after_19:
    // 0x8014A3F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8014A3F4: bnel        $v0, $v1, L_8014A66C
    if (ctx->r2 != ctx->r3) {
        // 0x8014A3F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014A66C;
    }
    goto skip_2;
    // 0x8014A3F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8014A3FC: jal         0x80236C60
    // 0x8014A400: nop

    LOOKUP_FUNC(0x80236C60)(rdram, ctx);
        goto after_20;
    // 0x8014A400: nop

    after_20:
    // 0x8014A404: jal         0x80148E44
    // 0x8014A408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148E44)(rdram, ctx);
        goto after_21;
    // 0x8014A408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8014A40C: jal         0x801FBB20
    // 0x8014A410: nop

    LOOKUP_FUNC(0x801FBB20)(rdram, ctx);
        goto after_22;
    // 0x8014A410: nop

    after_22:
    // 0x8014A414: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014A418: addiu       $a1, $a1, -0x54B8
    ctx->r5 = ADD32(ctx->r5, -0X54B8);
    // 0x8014A41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A420: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8014A424: jal         0x80148FC4
    // 0x8014A428: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_23;
    // 0x8014A428: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_23:
    // 0x8014A42C: b           L_8014A66C
    // 0x8014A430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8014A66C;
    // 0x8014A430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014A434:
    // 0x8014A434: beql        $t8, $zero, L_8014A478
    if (ctx->r24 == 0) {
        // 0x8014A438: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_8014A478;
    }
    goto skip_3;
    // 0x8014A438: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    skip_3:
    // 0x8014A43C: jal         0x80126944
    // 0x8014A440: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_24;
    // 0x8014A440: nop

    after_24:
    // 0x8014A444: bnel        $v0, $zero, L_8014A478
    if (ctx->r2 != 0) {
        // 0x8014A448: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_8014A478;
    }
    goto skip_4;
    // 0x8014A448: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    skip_4:
    // 0x8014A44C: jal         0x80148E44
    // 0x8014A450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148E44)(rdram, ctx);
        goto after_25;
    // 0x8014A450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x8014A454: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014A458: addiu       $a1, $a1, -0x54B8
    ctx->r5 = ADD32(ctx->r5, -0X54B8);
    // 0x8014A45C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A460: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8014A464: jal         0x80148FC4
    // 0x8014A468: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_26;
    // 0x8014A468: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_26:
    // 0x8014A46C: b           L_8014A66C
    // 0x8014A470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8014A66C;
    // 0x8014A470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014A474: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
L_8014A478:
    // 0x8014A478: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8014A47C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8014A480: addiu       $t2, $t2, -0x4410
    ctx->r10 = ADD32(ctx->r10, -0X4410);
    // 0x8014A484: addiu       $t3, $t2, 0x44C
    ctx->r11 = ADD32(ctx->r10, 0X44C);
    // 0x8014A488: bne         $t1, $t3, L_8014A498
    if (ctx->r9 != ctx->r11) {
        // 0x8014A48C: lhu         $v0, 0x4($t9)
        ctx->r2 = MEM_HU(ctx->r25, 0X4);
            goto L_8014A498;
    }
    // 0x8014A48C: lhu         $v0, 0x4($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X4);
    // 0x8014A490: b           L_8014A4A0
    // 0x8014A494: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
        goto L_8014A4A0;
    // 0x8014A494: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
L_8014A498:
    // 0x8014A498: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8014A49C: sb          $t4, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r12;
L_8014A4A0:
    // 0x8014A4A0: andi        $t5, $v0, 0x8000
    ctx->r13 = ctx->r2 & 0X8000;
    // 0x8014A4A4: beq         $t5, $zero, L_8014A668
    if (ctx->r13 == 0) {
        // 0x8014A4A8: lui         $t1, 0x8018
        ctx->r9 = S32(0X8018 << 16);
            goto L_8014A668;
    }
    // 0x8014A4A8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8014A4AC: lb          $t6, 0x91($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X91);
    // 0x8014A4B0: lb          $t8, 0x90($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X90);
    // 0x8014A4B4: addiu       $t1, $t1, 0x1ABC
    ctx->r9 = ADD32(ctx->r9, 0X1ABC);
    // 0x8014A4B8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8014A4BC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8014A4C0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8014A4C4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8014A4C8: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8014A4CC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8014A4D0: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x8014A4D4: addu        $v0, $t2, $t1
    ctx->r2 = ADD32(ctx->r10, ctx->r9);
    // 0x8014A4D8: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x8014A4DC: lb          $t3, 0x92($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X92);
    // 0x8014A4E0: lbu         $a1, 0x23($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X23);
    // 0x8014A4E4: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x8014A4E8: beql        $t5, $zero, L_8014A66C
    if (ctx->r13 == 0) {
        // 0x8014A4EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014A66C;
    }
    goto skip_5;
    // 0x8014A4EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8014A4F0: jal         0x8013D4A0
    // 0x8014A4F4: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    LOOKUP_FUNC(0x8013D4A0)(rdram, ctx);
        goto after_27;
    // 0x8014A4F4: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    after_27:
    // 0x8014A4F8: beql        $v0, $zero, L_8014A66C
    if (ctx->r2 == 0) {
        // 0x8014A4FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014A66C;
    }
    goto skip_6;
    // 0x8014A4FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8014A500: jal         0x80148270
    // 0x8014A504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148270)(rdram, ctx);
        goto after_28;
    // 0x8014A504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x8014A508: beql        $v0, $zero, L_8014A66C
    if (ctx->r2 == 0) {
        // 0x8014A50C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014A66C;
    }
    goto skip_7;
    // 0x8014A50C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8014A510: jal         0x80148820
    // 0x8014A514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148820)(rdram, ctx);
        goto after_29;
    // 0x8014A514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8014A518: beq         $v0, $zero, L_8014A668
    if (ctx->r2 == 0) {
        // 0x8014A51C: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_8014A668;
    }
    // 0x8014A51C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8014A520: jal         0x8001F75C
    // 0x8014A524: lw          $a0, -0x4334($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4334);
    LOOKUP_FUNC(0x8001F75C)(rdram, ctx);
        goto after_30;
    // 0x8014A524: lw          $a0, -0x4334($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4334);
    after_30:
    // 0x8014A528: lb          $t6, 0x91($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X91);
    // 0x8014A52C: lb          $t7, 0x90($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X90);
    // 0x8014A530: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8014A534: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x8014A538: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8014A53C: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8014A540: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8014A544: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8014A548: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8014A54C: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x8014A550: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x8014A554: lbu         $t1, 0x1ABD($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X1ABD);
    // 0x8014A558: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8014A55C: sb          $t1, 0x2D9($t3)
    MEM_B(0X2D9, ctx->r11) = ctx->r9;
    // 0x8014A560: jal         0x80232128
    // 0x8014A564: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x80232128)(rdram, ctx);
        goto after_31;
    // 0x8014A564: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_31:
    // 0x8014A568: lb          $t4, 0x91($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X91);
    // 0x8014A56C: lb          $t6, 0x90($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X90);
    // 0x8014A570: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8014A574: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8014A578: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8014A57C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8014A580: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8014A584: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8014A588: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8014A58C: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8014A590: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8014A594: lbu         $a0, 0x1ABD($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1ABD);
    // 0x8014A598: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8014A59C: jal         0x8013D520
    // 0x8014A5A0: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    LOOKUP_FUNC(0x8013D520)(rdram, ctx);
        goto after_32;
    // 0x8014A5A0: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    after_32:
    // 0x8014A5A4: jal         0x80126944
    // 0x8014A5A8: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_33;
    // 0x8014A5A8: nop

    after_33:
    // 0x8014A5AC: bne         $v0, $zero, L_8014A5F4
    if (ctx->r2 != 0) {
        // 0x8014A5B0: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_8014A5F4;
    }
    // 0x8014A5B0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8014A5B4: lb          $t9, 0x91($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X91);
    // 0x8014A5B8: lb          $t1, 0x90($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X90);
    // 0x8014A5BC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8014A5C0: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x8014A5C4: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8014A5C8: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x8014A5CC: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8014A5D0: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8014A5D4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8014A5D8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8014A5DC: addu        $a1, $a1, $t4
    ctx->r5 = ADD32(ctx->r5, ctx->r12);
    // 0x8014A5E0: lbu         $a1, 0x1ABD($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X1ABD);
    // 0x8014A5E4: jal         0x80387A20
    // 0x8014A5E8: lw          $a0, -0x4334($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4334);
    LOOKUP_FUNC(0x80387A20)(rdram, ctx);
        goto after_34;
    // 0x8014A5E8: lw          $a0, -0x4334($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4334);
    after_34:
    // 0x8014A5EC: b           L_8014A630
    // 0x8014A5F0: nop

        goto L_8014A630;
    // 0x8014A5F0: nop

L_8014A5F4:
    // 0x8014A5F4: jal         0x80126944
    // 0x8014A5F8: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_35;
    // 0x8014A5F8: nop

    after_35:
    // 0x8014A5FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8014A600: bne         $v0, $v1, L_8014A630
    if (ctx->r2 != ctx->r3) {
        // 0x8014A604: nop
    
            goto L_8014A630;
    }
    // 0x8014A604: nop

    // 0x8014A608: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8014A60C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8014A610: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014A614: sb          $v1, 0xAB($t6)
    MEM_B(0XAB, ctx->r14) = ctx->r3;
    // 0x8014A618: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8014A61C: lb          $t5, 0x91($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X91);
    // 0x8014A620: sb          $t5, 0xAA($t7)
    MEM_B(0XAA, ctx->r15) = ctx->r13;
    // 0x8014A624: lhu         $t8, -0x3520($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X3520);
    // 0x8014A628: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x8014A62C: sh          $t9, -0x3520($at)
    MEM_H(-0X3520, ctx->r1) = ctx->r25;
L_8014A630:
    // 0x8014A630: jal         0x80147D60
    // 0x8014A634: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    LOOKUP_FUNC(0x80147D60)(rdram, ctx);
        goto after_36;
    // 0x8014A634: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_36:
    // 0x8014A638: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8014A63C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014A640: jal         0x801FBB20
    // 0x8014A644: sb          $t1, -0x33DB($at)
    MEM_B(-0X33DB, ctx->r1) = ctx->r9;
    LOOKUP_FUNC(0x801FBB20)(rdram, ctx);
        goto after_37;
    // 0x8014A644: sb          $t1, -0x33DB($at)
    MEM_B(-0X33DB, ctx->r1) = ctx->r9;
    after_37:
    // 0x8014A648: jal         0x80020744
    // 0x8014A64C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_38;
    // 0x8014A64C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_38:
    // 0x8014A650: jal         0x80020744
    // 0x8014A654: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_39;
    // 0x8014A654: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_39:
    // 0x8014A658: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014A65C: addiu       $a1, $a1, -0x5984
    ctx->r5 = ADD32(ctx->r5, -0X5984);
    // 0x8014A660: jal         0x800058DC
    // 0x8014A664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_40;
    // 0x8014A664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
L_8014A668:
    // 0x8014A668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014A66C:
    // 0x8014A66C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014A670: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014A674: jr          $ra
    // 0x8014A678: nop

    return;
    // 0x8014A678: nop

;}
RECOMP_FUNC void M7_FUN_8014a67c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A67C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014A680: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014A684: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014A688: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8014A68C: lb          $t8, 0x90($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X90);
    // 0x8014A690: lb          $t6, 0x91($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X91);
    // 0x8014A694: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014A698: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8014A69C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8014A6A0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8014A6A4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8014A6A8: lw          $v0, -0x12E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X12E8);
    // 0x8014A6AC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8014A6B0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8014A6B4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8014A6B8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8014A6BC: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x8014A6C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014A6C4: beq         $v0, $zero, L_8014A704
    if (ctx->r2 == 0) {
        // 0x8014A6C8: lbu         $a1, 0x1ABD($a1)
        ctx->r5 = MEM_BU(ctx->r5, 0X1ABD);
            goto L_8014A704;
    }
    // 0x8014A6C8: lbu         $a1, 0x1ABD($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X1ABD);
    // 0x8014A6CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8014A6D0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8014A6D4: addiu       $v1, $v1, 0x1D5C
    ctx->r3 = ADD32(ctx->r3, 0X1D5C);
    // 0x8014A6D8: addiu       $a0, $a0, 0x1D60
    ctx->r4 = ADD32(ctx->r4, 0X1D60);
    // 0x8014A6DC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
L_8014A6E0:
    // 0x8014A6E0: beql        $v0, $t1, L_8014A6FC
    if (ctx->r2 == ctx->r9) {
        // 0x8014A6E4: lw          $v0, 0x10($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X10);
            goto L_8014A6FC;
    }
    goto skip_0;
    // 0x8014A6E4: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x8014A6E8: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8014A6EC: beql        $v0, $t2, L_8014A6FC
    if (ctx->r2 == ctx->r10) {
        // 0x8014A6F0: lw          $v0, 0x10($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X10);
            goto L_8014A6FC;
    }
    goto skip_1;
    // 0x8014A6F0: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    skip_1:
    // 0x8014A6F4: sb          $zero, 0x22($v0)
    MEM_B(0X22, ctx->r2) = 0;
    // 0x8014A6F8: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
L_8014A6FC:
    // 0x8014A6FC: bnel        $v0, $zero, L_8014A6E0
    if (ctx->r2 != 0) {
        // 0x8014A700: lw          $t1, 0x0($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X0);
            goto L_8014A6E0;
    }
    goto skip_2;
    // 0x8014A700: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    skip_2:
L_8014A704:
    // 0x8014A704: jal         0x80126944
    // 0x8014A708: sb          $a1, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x8014A708: sb          $a1, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r5;
    after_0:
    // 0x8014A70C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014A710: bne         $v0, $at, L_8014A750
    if (ctx->r2 != ctx->r1) {
        // 0x8014A714: lbu         $a1, 0x23($sp)
        ctx->r5 = MEM_BU(ctx->r29, 0X23);
            goto L_8014A750;
    }
    // 0x8014A714: lbu         $a1, 0x23($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X23);
    // 0x8014A718: jal         0x801487F0
    // 0x8014A71C: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x801487F0)(rdram, ctx);
        goto after_1;
    // 0x8014A71C: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    after_1:
    // 0x8014A720: beq         $v0, $zero, L_8014A750
    if (ctx->r2 == 0) {
        // 0x8014A724: nop
    
            goto L_8014A750;
    }
    // 0x8014A724: nop

    // 0x8014A728: jal         0x80147218
    // 0x8014A72C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80147218)(rdram, ctx);
        goto after_2;
    // 0x8014A72C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8014A730: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014A734: addiu       $a1, $a1, -0x5430
    ctx->r5 = ADD32(ctx->r5, -0X5430);
    // 0x8014A738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A73C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8014A740: jal         0x80148FC4
    // 0x8014A744: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_3;
    // 0x8014A744: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8014A748: b           L_8014A764
    // 0x8014A74C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8014A764;
    // 0x8014A74C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014A750:
    // 0x8014A750: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014A754: addiu       $a1, $a1, -0x588C
    ctx->r5 = ADD32(ctx->r5, -0X588C);
    // 0x8014A758: jal         0x800058DC
    // 0x8014A75C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x8014A75C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8014A760: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014A764:
    // 0x8014A764: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014A768: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014A76C: jr          $ra
    // 0x8014A770: nop

    return;
    // 0x8014A770: nop

;}
RECOMP_FUNC void M7_FUN_8014a774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A774: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8014A778: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014a77c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014a77c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A77C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8014A780: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8014A784: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014A788: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014A78C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8014A790: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8014A794: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8014A798: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x8014A79C: lw          $t7, 0x98($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X98);
    // 0x8014A7A0: jal         0x80126944
    // 0x8014A7A4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x8014A7A4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    after_0:
    // 0x8014A7A8: bne         $v0, $zero, L_8014A7C8
    if (ctx->r2 != 0) {
        // 0x8014A7AC: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_8014A7C8;
    }
    // 0x8014A7AC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8014A7B0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8014A7B4: lw          $a1, -0x4334($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4334);
    // 0x8014A7B8: jal         0x80148DDC
    // 0x8014A7BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80148DDC)(rdram, ctx);
        goto after_1;
    // 0x8014A7BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x8014A7C0: b           L_8014A870
    // 0x8014A7C4: nop

        goto L_8014A870;
    // 0x8014A7C4: nop

L_8014A7C8:
    // 0x8014A7C8: jal         0x80126944
    // 0x8014A7CC: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_2;
    // 0x8014A7CC: nop

    after_2:
    // 0x8014A7D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014A7D4: bne         $v0, $at, L_8014A870
    if (ctx->r2 != ctx->r1) {
        // 0x8014A7D8: lui         $t8, 0x801C
        ctx->r24 = S32(0X801C << 16);
            goto L_8014A870;
    }
    // 0x8014A7D8: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8014A7DC: lbu         $t8, -0x33E0($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X33E0);
    // 0x8014A7E0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8014A7E4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8014A7E8: beq         $t8, $zero, L_8014A834
    if (ctx->r24 == 0) {
        // 0x8014A7EC: nop
    
            goto L_8014A834;
    }
    // 0x8014A7EC: nop

    // 0x8014A7F0: jal         0x801487B4
    // 0x8014A7F4: lbu         $a0, 0x2D9($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X2D9);
    LOOKUP_FUNC(0x801487B4)(rdram, ctx);
        goto after_3;
    // 0x8014A7F4: lbu         $a0, 0x2D9($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X2D9);
    after_3:
    // 0x8014A7F8: beq         $v0, $zero, L_8014A81C
    if (ctx->r2 == 0) {
        // 0x8014A7FC: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_8014A81C;
    }
    // 0x8014A7FC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8014A800: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8014A804: lw          $a1, -0x4334($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4334);
    // 0x8014A808: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8014A80C: jal         0x80148DDC
    // 0x8014A810: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80148DDC)(rdram, ctx);
        goto after_4;
    // 0x8014A810: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x8014A814: b           L_8014A870
    // 0x8014A818: nop

        goto L_8014A870;
    // 0x8014A818: nop

L_8014A81C:
    // 0x8014A81C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8014A820: lw          $a1, -0x4324($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4324);
    // 0x8014A824: jal         0x80148DDC
    // 0x8014A828: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80148DDC)(rdram, ctx);
        goto after_5;
    // 0x8014A828: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
    // 0x8014A82C: b           L_8014A870
    // 0x8014A830: nop

        goto L_8014A870;
    // 0x8014A830: nop

L_8014A834:
    // 0x8014A834: jal         0x801487B4
    // 0x8014A838: lbu         $a0, 0x2D9($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X2D9);
    LOOKUP_FUNC(0x801487B4)(rdram, ctx);
        goto after_6;
    // 0x8014A838: lbu         $a0, 0x2D9($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X2D9);
    after_6:
    // 0x8014A83C: beq         $v0, $zero, L_8014A860
    if (ctx->r2 == 0) {
        // 0x8014A840: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_8014A860;
    }
    // 0x8014A840: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8014A844: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8014A848: lw          $a1, -0x4324($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4324);
    // 0x8014A84C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8014A850: jal         0x80148DDC
    // 0x8014A854: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80148DDC)(rdram, ctx);
        goto after_7;
    // 0x8014A854: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_7:
    // 0x8014A858: b           L_8014A870
    // 0x8014A85C: nop

        goto L_8014A870;
    // 0x8014A85C: nop

L_8014A860:
    // 0x8014A860: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8014A864: lw          $a1, -0x4334($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4334);
    // 0x8014A868: jal         0x80148DDC
    // 0x8014A86C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80148DDC)(rdram, ctx);
        goto after_8;
    // 0x8014A86C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
L_8014A870:
    // 0x8014A870: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8014A874: lw          $t1, -0x4328($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4328);
    // 0x8014A878: addiu       $t2, $sp, 0x54
    ctx->r10 = ADD32(ctx->r29, 0X54);
    // 0x8014A87C: addiu       $t3, $sp, 0x50
    ctx->r11 = ADD32(ctx->r29, 0X50);
    // 0x8014A880: lw          $a0, 0x2C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X2C);
    // 0x8014A884: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8014A888: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8014A88C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8014A890: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8014A894: jal         0x80130E34
    // 0x8014A898: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    LOOKUP_FUNC(0x80130E34)(rdram, ctx);
        goto after_9;
    // 0x8014A898: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_9:
    // 0x8014A89C: jal         0x80006214
    // 0x8014A8A0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_10;
    // 0x8014A8A0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_10:
    // 0x8014A8A4: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8014A8A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8014A8AC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8014A8B0: addiu       $v1, $v1, 0x1D5C
    ctx->r3 = ADD32(ctx->r3, 0X1D5C);
    // 0x8014A8B4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8014A8B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014A8BC: bc1fl       L_8014A8D4
    if (!c1cs) {
        // 0x8014A8C0: lwc1        $f6, 0x50($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
            goto L_8014A8D4;
    }
    goto skip_0;
    // 0x8014A8C0: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x8014A8C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014A8C8: nop

    // 0x8014A8CC: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8014A8D0: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
L_8014A8D4:
    // 0x8014A8D4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8014A8D8: nop

    // 0x8014A8DC: bc1fl       L_8014A8F4
    if (!c1cs) {
        // 0x8014A8E0: lw          $t4, 0x0($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X0);
            goto L_8014A8F4;
    }
    goto skip_1;
    // 0x8014A8E0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x8014A8E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8014A8E8: nop

    // 0x8014A8EC: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x8014A8F0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
L_8014A8F4:
    // 0x8014A8F4: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8014A8F8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8014A8FC: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x8014A900: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014A904: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8014A908: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8014A90C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8014A910: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014A914: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8014A918: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8014A91C: addiu       $a2, $a2, 0x1D60
    ctx->r6 = ADD32(ctx->r6, 0X1D60);
    // 0x8014A920: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8014A924: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8014A928: addiu       $a1, $zero, 0x2E0
    ctx->r5 = ADD32(0, 0X2E0);
    // 0x8014A92C: div.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8014A930: ldc1        $f6, -0x4A0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X4A0);
    // 0x8014A934: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8014A938: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8014A93C: div.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8014A940: sub.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d - ctx->f10.d;
    // 0x8014A944: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8014A948: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8014A94C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8014A950: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8014A954: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8014A958: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x8014A95C: div.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x8014A960: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8014A964: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x8014A968: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8014A96C: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x8014A970: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8014A974: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x8014A978: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8014A97C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x8014A980: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8014A984: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x8014A988: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8014A98C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8014A990: lwc1        $f10, 0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8014A994: swc1        $f10, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f10.u32l;
    // 0x8014A998: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8014A99C: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x8014A9A0: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8014A9A4: add.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x8014A9A8: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    // 0x8014A9AC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8014A9B0: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x8014A9B4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8014A9B8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8014A9BC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8014A9C0: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8014A9C4: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    // 0x8014A9C8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8014A9CC: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x8014A9D0: swc1        $f0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f0.u32l;
    // 0x8014A9D4: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8014A9D8: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8014A9DC: swc1        $f0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
    // 0x8014A9E0: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x8014A9E4: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8014A9E8: swc1        $f0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f0.u32l;
    // 0x8014A9EC: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x8014A9F0: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x8014A9F4: jal         0x801486A8
    // 0x8014A9F8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    LOOKUP_FUNC(0x801486A8)(rdram, ctx);
        goto after_11;
    // 0x8014A9F8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_11:
    // 0x8014A9FC: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8014AA00: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8014AA04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8014AA08: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8014AA0C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8014AA10: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8014AA14: bc1fl       L_8014AA28
    if (!c1cs) {
        // 0x8014AA18: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8014AA28;
    }
    goto skip_2;
    // 0x8014AA18: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_2:
    // 0x8014AA1C: b           L_8014AA28
    // 0x8014AA20: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_8014AA28;
    // 0x8014AA20: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x8014AA24: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8014AA28:
    // 0x8014AA28: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8014AA2C: nop

    // 0x8014AA30: bc1fl       L_8014AAA8
    if (!c1cs) {
        // 0x8014AA34: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014AAA8;
    }
    goto skip_3;
    // 0x8014AA34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8014AA38: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    // 0x8014AA3C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8014AA40: bc1fl       L_8014AA54
    if (!c1cs) {
        // 0x8014AA44: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_8014AA54;
    }
    goto skip_4;
    // 0x8014AA44: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_4:
    // 0x8014AA48: b           L_8014AA54
    // 0x8014AA4C: neg.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = -ctx->f18.fl;
        goto L_8014AA54;
    // 0x8014AA4C: neg.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = -ctx->f18.fl;
    // 0x8014AA50: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
L_8014AA54:
    // 0x8014AA54: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8014AA58: nop

    // 0x8014AA5C: bc1fl       L_8014AAA8
    if (!c1cs) {
        // 0x8014AA60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014AAA8;
    }
    goto skip_5;
    // 0x8014AA60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8014AA64: jal         0x801471DC
    // 0x8014AA68: lw          $a0, -0x12E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X12E8);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_12;
    // 0x8014AA68: lw          $a0, -0x12E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X12E8);
    after_12:
    // 0x8014AA6C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8014AA70: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014AA74: jal         0x80126944
    // 0x8014AA78: sb          $t4, -0x33DB($at)
    MEM_B(-0X33DB, ctx->r1) = ctx->r12;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_13;
    // 0x8014AA78: sb          $t4, -0x33DB($at)
    MEM_B(-0X33DB, ctx->r1) = ctx->r12;
    after_13:
    // 0x8014AA7C: bne         $v0, $zero, L_8014AA8C
    if (ctx->r2 != 0) {
        // 0x8014AA80: nop
    
            goto L_8014AA8C;
    }
    // 0x8014AA80: nop

    // 0x8014AA84: jal         0x800023A8
    // 0x8014AA88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_14;
    // 0x8014AA88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
L_8014AA8C:
    // 0x8014AA8C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014AA90: addiu       $a1, $a1, -0x5430
    ctx->r5 = ADD32(ctx->r5, -0X5430);
    // 0x8014AA94: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8014AA98: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8014AA9C: jal         0x80148FC4
    // 0x8014AAA0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_15;
    // 0x8014AAA0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_15:
    // 0x8014AAA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014AAA8:
    // 0x8014AAA8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8014AAAC: jr          $ra
    // 0x8014AAB0: nop

    return;
    // 0x8014AAB0: nop

;}
RECOMP_FUNC void M7_FUN_8014aab4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AAB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014AAB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014AABC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014AAC0: lhu         $t6, 0x3C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X3C);
    // 0x8014AAC4: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8014AAC8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8014AACC: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8014AAD0: bne         $t8, $zero, L_8014AB38
    if (ctx->r24 != 0) {
        // 0x8014AAD4: sh          $t7, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r15;
            goto L_8014AB38;
    }
    // 0x8014AAD4: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x8014AAD8: lbu         $t9, -0x12EC($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X12EC);
    // 0x8014AADC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8014AAE0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8014AAE4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8014AAE8: lw          $v0, 0x1AA0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1AA0);
    // 0x8014AAEC: beq         $v0, $zero, L_8014AB00
    if (ctx->r2 == 0) {
        // 0x8014AAF0: nop
    
            goto L_8014AB00;
    }
    // 0x8014AAF0: nop

    // 0x8014AAF4: jalr        $v0
    // 0x8014AAF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8014AAF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014AAFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8014AB00:
    // 0x8014AB00: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8014AB04: lbu         $t1, -0x12EB($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X12EB);
    // 0x8014AB08: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8014AB0C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8014AB10: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8014AB14: lw          $v0, 0x1AA0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1AA0);
    // 0x8014AB18: beq         $v0, $zero, L_8014AB2C
    if (ctx->r2 == 0) {
        // 0x8014AB1C: nop
    
            goto L_8014AB2C;
    }
    // 0x8014AB1C: nop

    // 0x8014AB20: jalr        $v0
    // 0x8014AB24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8014AB24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8014AB28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8014AB2C:
    // 0x8014AB2C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8014AB30: jal         0x800058DC
    // 0x8014AB34: lw          $a1, -0x12F0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X12F0);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8014AB34: lw          $a1, -0x12F0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X12F0);
    after_2:
L_8014AB38:
    // 0x8014AB38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014AB3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014AB40: jr          $ra
    // 0x8014AB44: nop

    return;
    // 0x8014AB44: nop

;}
RECOMP_FUNC void M7_FUN_8014ab48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AB48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014AB4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014AB50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014AB54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014AB58: jal         0x80147D60
    // 0x8014AB5C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    LOOKUP_FUNC(0x80147D60)(rdram, ctx);
        goto after_0;
    // 0x8014AB5C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_0:
    // 0x8014AB60: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014AB64: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x8014AB68: lhu         $t6, 0xEF0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XEF0);
    // 0x8014AB6C: sb          $zero, 0x1035($v0)
    MEM_B(0X1035, ctx->r2) = 0;
    // 0x8014AB70: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x8014AB74: jal         0x80126944
    // 0x8014AB78: sh          $t7, 0xEF0($v0)
    MEM_H(0XEF0, ctx->r2) = ctx->r15;
    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_1;
    // 0x8014AB78: sh          $t7, 0xEF0($v0)
    MEM_H(0XEF0, ctx->r2) = ctx->r15;
    after_1:
    // 0x8014AB7C: bne         $v0, $zero, L_8014AB8C
    if (ctx->r2 != 0) {
        // 0x8014AB80: nop
    
            goto L_8014AB8C;
    }
    // 0x8014AB80: nop

    // 0x8014AB84: jal         0x800023A8
    // 0x8014AB88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x800023A8)(rdram, ctx);
        goto after_2;
    // 0x8014AB88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_8014AB8C:
    // 0x8014AB8C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014AB90: jal         0x8001F6FC
    // 0x8014AB94: sh          $zero, -0x42A8($at)
    MEM_H(-0X42A8, ctx->r1) = 0;
    LOOKUP_FUNC(0x8001F6FC)(rdram, ctx);
        goto after_3;
    // 0x8014AB94: sh          $zero, -0x42A8($at)
    MEM_H(-0X42A8, ctx->r1) = 0;
    after_3:
    // 0x8014AB98: jal         0x80020744
    // 0x8014AB9C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_4;
    // 0x8014AB9C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_4:
    // 0x8014ABA0: jal         0x80148044
    // 0x8014ABA4: nop

    LOOKUP_FUNC(0x80148044)(rdram, ctx);
        goto after_5;
    // 0x8014ABA4: nop

    after_5:
    // 0x8014ABA8: bne         $v0, $zero, L_8014ABB8
    if (ctx->r2 != 0) {
        // 0x8014ABAC: nop
    
            goto L_8014ABB8;
    }
    // 0x8014ABAC: nop

    // 0x8014ABB0: jal         0x801FBB20
    // 0x8014ABB4: nop

    LOOKUP_FUNC(0x801FBB20)(rdram, ctx);
        goto after_6;
    // 0x8014ABB4: nop

    after_6:
L_8014ABB8:
    // 0x8014ABB8: jal         0x80005700
    // 0x8014ABBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_7;
    // 0x8014ABBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_7:
    // 0x8014ABC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014ABC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014ABC8: jr          $ra
    // 0x8014ABCC: nop

    return;
    // 0x8014ABCC: nop

;}
RECOMP_FUNC void M7_FUN_8014abd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014ABD0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014ABD4: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8014ABD8: lbu         $t6, 0x1035($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1035);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014abdc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014abdc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014ABDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014ABE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014ABE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014ABE8: bne         $t6, $zero, L_8014AC34
    if (ctx->r14 != 0) {
        // 0x8014ABEC: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8014AC34;
    }
    // 0x8014ABEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014ABF0: jal         0x80126944
    // 0x8014ABF4: nop

    LOOKUP_FUNC(0x80126944)(rdram, ctx);
        goto after_0;
    // 0x8014ABF4: nop

    after_0:
    // 0x8014ABF8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014ABFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014AC00: bne         $v0, $at, L_8014AC18
    if (ctx->r2 != ctx->r1) {
        // 0x8014AC04: addiu       $v1, $v1, -0x4410
        ctx->r3 = ADD32(ctx->r3, -0X4410);
            goto L_8014AC18;
    }
    // 0x8014AC04: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x8014AC08: jal         0x80236C60
    // 0x8014AC0C: nop

    LOOKUP_FUNC(0x80236C60)(rdram, ctx);
        goto after_1;
    // 0x8014AC0C: nop

    after_1:
    // 0x8014AC10: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014AC14: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
L_8014AC18:
    // 0x8014AC18: lhu         $t7, 0xEF0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0XEF0);
    // 0x8014AC1C: sh          $zero, 0x168($v1)
    MEM_H(0X168, ctx->r3) = 0;
    // 0x8014AC20: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x8014AC24: jal         0x8001F6FC
    // 0x8014AC28: sh          $t8, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r24;
    LOOKUP_FUNC(0x8001F6FC)(rdram, ctx);
        goto after_2;
    // 0x8014AC28: sh          $t8, 0xEF0($v1)
    MEM_H(0XEF0, ctx->r3) = ctx->r24;
    after_2:
    // 0x8014AC2C: jal         0x80005700
    // 0x8014AC30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_3;
    // 0x8014AC30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_8014AC34:
    // 0x8014AC34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014AC38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014AC3C: jr          $ra
    // 0x8014AC40: nop

    return;
    // 0x8014AC40: nop

;}
RECOMP_FUNC void M7_FUN_8014ac44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AC44: nop

    // 0x8014AC48: nop

    // 0x8014AC4C: nop

    // 0x8014AC50: nop

    // 0x8014AC54: nop

    // 0x8014AC58: nop

    // 0x8014AC5C: nop

;}
RECOMP_FUNC void M7_FUN_8014ac60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AC60: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014AC64: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014AC68: addiu       $v0, $v0, -0x10C8
    ctx->r2 = ADD32(ctx->r2, -0X10C8);
    // 0x8014AC6C: addiu       $v1, $v1, -0x12C8
    ctx->r3 = ADD32(ctx->r3, -0X12C8);
L_8014AC70:
    // 0x8014AC70: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x8014AC74: sb          $zero, -0x30($v1)
    MEM_B(-0X30, ctx->r3) = 0;
    // 0x8014AC78: sb          $zero, -0x2F($v1)
    MEM_B(-0X2F, ctx->r3) = 0;
    // 0x8014AC7C: sh          $zero, -0x2E($v1)
    MEM_H(-0X2E, ctx->r3) = 0;
    // 0x8014AC80: sh          $zero, -0x2C($v1)
    MEM_H(-0X2C, ctx->r3) = 0;
    // 0x8014AC84: sh          $zero, -0x2A($v1)
    MEM_H(-0X2A, ctx->r3) = 0;
    // 0x8014AC88: sh          $zero, -0x28($v1)
    MEM_H(-0X28, ctx->r3) = 0;
    // 0x8014AC8C: sh          $zero, -0x26($v1)
    MEM_H(-0X26, ctx->r3) = 0;
    // 0x8014AC90: sh          $zero, -0x22($v1)
    MEM_H(-0X22, ctx->r3) = 0;
    // 0x8014AC94: sb          $zero, -0x24($v1)
    MEM_B(-0X24, ctx->r3) = 0;
    // 0x8014AC98: sb          $zero, -0x23($v1)
    MEM_B(-0X23, ctx->r3) = 0;
    // 0x8014AC9C: sb          $zero, -0x20($v1)
    MEM_B(-0X20, ctx->r3) = 0;
    // 0x8014ACA0: sb          $zero, -0x1F($v1)
    MEM_B(-0X1F, ctx->r3) = 0;
    // 0x8014ACA4: sh          $zero, -0x1E($v1)
    MEM_H(-0X1E, ctx->r3) = 0;
    // 0x8014ACA8: sh          $zero, -0x1C($v1)
    MEM_H(-0X1C, ctx->r3) = 0;
    // 0x8014ACAC: sh          $zero, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = 0;
    // 0x8014ACB0: sh          $zero, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = 0;
    // 0x8014ACB4: sh          $zero, -0x16($v1)
    MEM_H(-0X16, ctx->r3) = 0;
    // 0x8014ACB8: sh          $zero, -0x12($v1)
    MEM_H(-0X12, ctx->r3) = 0;
    // 0x8014ACBC: sb          $zero, -0x14($v1)
    MEM_B(-0X14, ctx->r3) = 0;
    // 0x8014ACC0: sb          $zero, -0x13($v1)
    MEM_B(-0X13, ctx->r3) = 0;
    // 0x8014ACC4: sb          $zero, -0x10($v1)
    MEM_B(-0X10, ctx->r3) = 0;
    // 0x8014ACC8: sb          $zero, -0xF($v1)
    MEM_B(-0XF, ctx->r3) = 0;
    // 0x8014ACCC: sh          $zero, -0xE($v1)
    MEM_H(-0XE, ctx->r3) = 0;
    // 0x8014ACD0: sh          $zero, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = 0;
    // 0x8014ACD4: sh          $zero, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = 0;
    // 0x8014ACD8: sh          $zero, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = 0;
    // 0x8014ACDC: sh          $zero, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = 0;
    // 0x8014ACE0: sh          $zero, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = 0;
    // 0x8014ACE4: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x8014ACE8: sb          $zero, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = 0;
    // 0x8014ACEC: sb          $zero, -0x40($v1)
    MEM_B(-0X40, ctx->r3) = 0;
    // 0x8014ACF0: sb          $zero, -0x3F($v1)
    MEM_B(-0X3F, ctx->r3) = 0;
    // 0x8014ACF4: sh          $zero, -0x3E($v1)
    MEM_H(-0X3E, ctx->r3) = 0;
    // 0x8014ACF8: sh          $zero, -0x3C($v1)
    MEM_H(-0X3C, ctx->r3) = 0;
    // 0x8014ACFC: sh          $zero, -0x3A($v1)
    MEM_H(-0X3A, ctx->r3) = 0;
    // 0x8014AD00: sh          $zero, -0x38($v1)
    MEM_H(-0X38, ctx->r3) = 0;
    // 0x8014AD04: sh          $zero, -0x36($v1)
    MEM_H(-0X36, ctx->r3) = 0;
    // 0x8014AD08: sh          $zero, -0x32($v1)
    MEM_H(-0X32, ctx->r3) = 0;
    // 0x8014AD0C: sb          $zero, -0x34($v1)
    MEM_B(-0X34, ctx->r3) = 0;
    // 0x8014AD10: bne         $v1, $v0, L_8014AC70
    if (ctx->r3 != ctx->r2) {
        // 0x8014AD14: sb          $zero, -0x33($v1)
        MEM_B(-0X33, ctx->r3) = 0;
            goto L_8014AC70;
    }
    // 0x8014AD14: sb          $zero, -0x33($v1)
    MEM_B(-0X33, ctx->r3) = 0;
    // 0x8014AD18: jr          $ra
    // 0x8014AD1C: nop

    return;
    // 0x8014AD1C: nop

;}
RECOMP_FUNC void M7_FUN_8014ad20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AD20: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8014AD24: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014AD28: sh          $t6, -0x12D0($at)
    MEM_H(-0X12D0, ctx->r1) = ctx->r14;
    // 0x8014AD2C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8014AD30: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8014AD34: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8014AD38: sh          $zero, -0x12CE($at)
    MEM_H(-0X12CE, ctx->r1) = 0;
    // 0x8014AD3C: addiu       $v0, $v0, -0xE88
    ctx->r2 = ADD32(ctx->r2, -0XE88);
    // 0x8014AD40: addiu       $v1, $v1, -0x10C8
    ctx->r3 = ADD32(ctx->r3, -0X10C8);
L_8014AD44:
    // 0x8014AD44: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x8014AD48: sb          $zero, -0x24($v1)
    MEM_B(-0X24, ctx->r3) = 0;
    // 0x8014AD4C: sb          $zero, -0x23($v1)
    MEM_B(-0X23, ctx->r3) = 0;
    // 0x8014AD50: sh          $zero, -0x22($v1)
    MEM_H(-0X22, ctx->r3) = 0;
    // 0x8014AD54: sw          $zero, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = 0;
    // 0x8014AD58: sb          $zero, -0x1C($v1)
    MEM_B(-0X1C, ctx->r3) = 0;
    // 0x8014AD5C: sb          $zero, -0x1B($v1)
    MEM_B(-0X1B, ctx->r3) = 0;
    // 0x8014AD60: sb          $zero, -0x18($v1)
    MEM_B(-0X18, ctx->r3) = 0;
    // 0x8014AD64: sb          $zero, -0x17($v1)
    MEM_B(-0X17, ctx->r3) = 0;
    // 0x8014AD68: sh          $zero, -0x16($v1)
    MEM_H(-0X16, ctx->r3) = 0;
    // 0x8014AD6C: sw          $zero, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = 0;
    // 0x8014AD70: sb          $zero, -0x10($v1)
    MEM_B(-0X10, ctx->r3) = 0;
    // 0x8014AD74: sb          $zero, -0xF($v1)
    MEM_B(-0XF, ctx->r3) = 0;
    // 0x8014AD78: sb          $zero, -0xC($v1)
    MEM_B(-0XC, ctx->r3) = 0;
    // 0x8014AD7C: sb          $zero, -0xB($v1)
    MEM_B(-0XB, ctx->r3) = 0;
    // 0x8014AD80: sh          $zero, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = 0;
    // 0x8014AD84: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x8014AD88: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x8014AD8C: sb          $zero, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = 0;
    // 0x8014AD90: sb          $zero, -0x30($v1)
    MEM_B(-0X30, ctx->r3) = 0;
    // 0x8014AD94: sb          $zero, -0x2F($v1)
    MEM_B(-0X2F, ctx->r3) = 0;
    // 0x8014AD98: sh          $zero, -0x2E($v1)
    MEM_H(-0X2E, ctx->r3) = 0;
    // 0x8014AD9C: sw          $zero, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = 0;
    // 0x8014ADA0: sb          $zero, -0x28($v1)
    MEM_B(-0X28, ctx->r3) = 0;
    // 0x8014ADA4: bne         $v1, $v0, L_8014AD44
    if (ctx->r3 != ctx->r2) {
        // 0x8014ADA8: sb          $zero, -0x27($v1)
        MEM_B(-0X27, ctx->r3) = 0;
            goto L_8014AD44;
    }
    // 0x8014ADA8: sb          $zero, -0x27($v1)
    MEM_B(-0X27, ctx->r3) = 0;
    // 0x8014ADAC: jr          $ra
    // 0x8014ADB0: nop

    return;
    // 0x8014ADB0: nop

;}
RECOMP_FUNC void M7_FUN_8014adb4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014ADB4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8014ADB8: lbu         $t6, 0x4F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4F);
    // 0x8014ADBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014ADC0: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x8014ADC4: slti        $at, $t6, 0x2E
    ctx->r1 = SIGNED(ctx->r14) < 0X2E ? 1 : 0;
    // 0x8014ADC8: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x8014ADCC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8014ADD0: bne         $at, $zero, L_8014ADE0
    if (ctx->r1 != 0) {
        // 0x8014ADD4: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_8014ADE0;
    }
    // 0x8014ADD4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8014ADD8: b           L_8014AEE4
    // 0x8014ADDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014AEE4;
    // 0x8014ADDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014ADE0:
    // 0x8014ADE0: lhu         $t7, 0x52($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X52);
    // 0x8014ADE4: lhu         $t8, 0x4A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X4A);
    // 0x8014ADE8: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8014ADEC: bnel        $at, $zero, L_8014AE00
    if (ctx->r1 != 0) {
        // 0x8014ADF0: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_8014AE00;
    }
    goto skip_0;
    // 0x8014ADF0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    skip_0:
    // 0x8014ADF4: b           L_8014AEE4
    // 0x8014ADF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014AEE4;
    // 0x8014ADF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014ADFC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
L_8014AE00:
    // 0x8014AE00: slt         $at, $t8, $at
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8014AE04: bne         $at, $zero, L_8014AE3C
    if (ctx->r1 != 0) {
        // 0x8014AE08: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_8014AE3C;
    }
    // 0x8014AE08: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8014AE0C: jal         0x8014B7CC
    // 0x8014AE10: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014AE10: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x8014AE14: beq         $v0, $zero, L_8014AE24
    if (ctx->r2 == 0) {
        // 0x8014AE18: nop
    
            goto L_8014AE24;
    }
    // 0x8014AE18: nop

    // 0x8014AE1C: b           L_8014AEE4
    // 0x8014AE20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014AEE4;
    // 0x8014AE20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014AE24:
    // 0x8014AE24: jal         0x8014B6F8
    // 0x8014AE28: lhu         $a0, 0x4A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4A);
    LOOKUP_FUNC(0x8014B6F8)(rdram, ctx);
        goto after_1;
    // 0x8014AE28: lhu         $a0, 0x4A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4A);
    after_1:
    // 0x8014AE2C: beq         $v0, $zero, L_8014AE3C
    if (ctx->r2 == 0) {
        // 0x8014AE30: nop
    
            goto L_8014AE3C;
    }
    // 0x8014AE30: nop

    // 0x8014AE34: b           L_8014AEE4
    // 0x8014AE38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014AEE4;
    // 0x8014AE38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014AE3C:
    // 0x8014AE3C: jal         0x8014B670
    // 0x8014AE40: nop

    LOOKUP_FUNC(0x8014B670)(rdram, ctx);
        goto after_2;
    // 0x8014AE40: nop

    after_2:
    // 0x8014AE44: beq         $v0, $zero, L_8014AEE0
    if (ctx->r2 == 0) {
        // 0x8014AE48: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8014AEE0;
    }
    // 0x8014AE48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8014AE4C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8014AE50: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8014AE54: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8014AE58: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8014AE5C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8014AE60: lhu         $t1, 0x4A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X4A);
    // 0x8014AE64: slt         $at, $t0, $at
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8014AE68: bne         $at, $zero, L_8014AE78
    if (ctx->r1 != 0) {
        // 0x8014AE6C: nop
    
            goto L_8014AE78;
    }
    // 0x8014AE6C: nop

    // 0x8014AE70: b           L_8014AE88
    // 0x8014AE74: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
        goto L_8014AE88;
    // 0x8014AE74: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
L_8014AE78:
    // 0x8014AE78: jal         0x8014B518
    // 0x8014AE7C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8014B518)(rdram, ctx);
        goto after_3;
    // 0x8014AE7C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_3:
    // 0x8014AE80: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8014AE84: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
L_8014AE88:
    // 0x8014AE88: lbu         $t2, 0x4F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4F);
    // 0x8014AE8C: sb          $t2, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r10;
    // 0x8014AE90: lhu         $t3, 0x52($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X52);
    // 0x8014AE94: sb          $t3, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r11;
    // 0x8014AE98: lhu         $t5, 0x52($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X52);
    // 0x8014AE9C: lbu         $t4, 0x4F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4F);
    // 0x8014AEA0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8014AEA4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8014AEA8: lh          $a3, 0x46($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X46);
    // 0x8014AEAC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8014AEB0: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8014AEB4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8014AEB8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8014AEBC: jal         0x801FF180
    // 0x8014AEC0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x801FF180)(rdram, ctx);
        goto after_4;
    // 0x8014AEC0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_4:
    // 0x8014AEC4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8014AEC8: bne         $v0, $zero, L_8014AED8
    if (ctx->r2 != 0) {
        // 0x8014AECC: sw          $v0, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r2;
            goto L_8014AED8;
    }
    // 0x8014AECC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8014AED0: b           L_8014AEE4
    // 0x8014AED4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014AEE4;
    // 0x8014AED4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014AED8:
    // 0x8014AED8: b           L_8014AEE4
    // 0x8014AEDC: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
        goto L_8014AEE4;
    // 0x8014AEDC: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
L_8014AEE0:
    // 0x8014AEE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014AEE4:
    // 0x8014AEE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014AEE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8014AEEC: jr          $ra
    // 0x8014AEF0: nop

    return;
    // 0x8014AEF0: nop

;}
RECOMP_FUNC void M7_FUN_8014aef4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AEF4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8014AEF8: lbu         $t6, 0x4F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4F);
    // 0x8014AEFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014AF00: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x8014AF04: slti        $at, $t6, 0x2E
    ctx->r1 = SIGNED(ctx->r14) < 0X2E ? 1 : 0;
    // 0x8014AF08: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x8014AF0C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8014AF10: bne         $at, $zero, L_8014AF20
    if (ctx->r1 != 0) {
        // 0x8014AF14: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_8014AF20;
    }
    // 0x8014AF14: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8014AF18: b           L_8014B024
    // 0x8014AF1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014B024;
    // 0x8014AF1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014AF20:
    // 0x8014AF20: lhu         $t7, 0x52($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X52);
    // 0x8014AF24: lhu         $t8, 0x4A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X4A);
    // 0x8014AF28: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8014AF2C: bnel        $at, $zero, L_8014AF40
    if (ctx->r1 != 0) {
        // 0x8014AF30: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_8014AF40;
    }
    goto skip_0;
    // 0x8014AF30: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    skip_0:
    // 0x8014AF34: b           L_8014B024
    // 0x8014AF38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014B024;
    // 0x8014AF38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014AF3C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
L_8014AF40:
    // 0x8014AF40: slt         $at, $t8, $at
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8014AF44: bne         $at, $zero, L_8014AF7C
    if (ctx->r1 != 0) {
        // 0x8014AF48: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_8014AF7C;
    }
    // 0x8014AF48: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8014AF4C: jal         0x8014B7CC
    // 0x8014AF50: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014AF50: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x8014AF54: beq         $v0, $zero, L_8014AF64
    if (ctx->r2 == 0) {
        // 0x8014AF58: nop
    
            goto L_8014AF64;
    }
    // 0x8014AF58: nop

    // 0x8014AF5C: b           L_8014B024
    // 0x8014AF60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014B024;
    // 0x8014AF60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014AF64:
    // 0x8014AF64: jal         0x8014B6F8
    // 0x8014AF68: lhu         $a0, 0x4A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4A);
    LOOKUP_FUNC(0x8014B6F8)(rdram, ctx);
        goto after_1;
    // 0x8014AF68: lhu         $a0, 0x4A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4A);
    after_1:
    // 0x8014AF6C: beq         $v0, $zero, L_8014AF7C
    if (ctx->r2 == 0) {
        // 0x8014AF70: nop
    
            goto L_8014AF7C;
    }
    // 0x8014AF70: nop

    // 0x8014AF74: b           L_8014B024
    // 0x8014AF78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014B024;
    // 0x8014AF78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014AF7C:
    // 0x8014AF7C: jal         0x8014B670
    // 0x8014AF80: nop

    LOOKUP_FUNC(0x8014B670)(rdram, ctx);
        goto after_2;
    // 0x8014AF80: nop

    after_2:
    // 0x8014AF84: beq         $v0, $zero, L_8014B020
    if (ctx->r2 == 0) {
        // 0x8014AF88: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8014B020;
    }
    // 0x8014AF88: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8014AF8C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8014AF90: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8014AF94: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8014AF98: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8014AF9C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8014AFA0: lhu         $t1, 0x4A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X4A);
    // 0x8014AFA4: slt         $at, $t0, $at
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8014AFA8: bne         $at, $zero, L_8014AFB8
    if (ctx->r1 != 0) {
        // 0x8014AFAC: nop
    
            goto L_8014AFB8;
    }
    // 0x8014AFAC: nop

    // 0x8014AFB0: b           L_8014AFC8
    // 0x8014AFB4: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
        goto L_8014AFC8;
    // 0x8014AFB4: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
L_8014AFB8:
    // 0x8014AFB8: jal         0x8014B518
    // 0x8014AFBC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x8014B518)(rdram, ctx);
        goto after_3;
    // 0x8014AFBC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_3:
    // 0x8014AFC0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8014AFC4: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
L_8014AFC8:
    // 0x8014AFC8: lbu         $t2, 0x4F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4F);
    // 0x8014AFCC: sb          $t2, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r10;
    // 0x8014AFD0: lhu         $t3, 0x52($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X52);
    // 0x8014AFD4: sb          $t3, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r11;
    // 0x8014AFD8: lhu         $t5, 0x52($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X52);
    // 0x8014AFDC: lbu         $t4, 0x4F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4F);
    // 0x8014AFE0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8014AFE4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8014AFE8: lh          $a3, 0x46($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X46);
    // 0x8014AFEC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8014AFF0: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8014AFF4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8014AFF8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8014AFFC: jal         0x801FF260
    // 0x8014B000: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x801FF260)(rdram, ctx);
        goto after_4;
    // 0x8014B000: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_4:
    // 0x8014B004: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8014B008: bne         $v0, $zero, L_8014B018
    if (ctx->r2 != 0) {
        // 0x8014B00C: sw          $v0, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r2;
            goto L_8014B018;
    }
    // 0x8014B00C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8014B010: b           L_8014B024
    // 0x8014B014: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014B024;
    // 0x8014B014: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014B018:
    // 0x8014B018: b           L_8014B024
    // 0x8014B01C: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
        goto L_8014B024;
    // 0x8014B01C: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
L_8014B020:
    // 0x8014B020: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014B024:
    // 0x8014B024: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014B028: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8014B02C: jr          $ra
    // 0x8014B030: nop

    return;
    // 0x8014B030: nop

;}
RECOMP_FUNC void M7_FUN_8014b034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014B038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014B03C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014B040: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014B044: jal         0x8014B7CC
    // 0x8014B048: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014B048: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_0:
    // 0x8014B04C: beq         $v0, $zero, L_8014B078
    if (ctx->r2 == 0) {
        // 0x8014B050: nop
    
            goto L_8014B078;
    }
    // 0x8014B050: nop

    // 0x8014B054: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8014B058: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8014B05C: lhu         $a1, 0x1E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1E);
    // 0x8014B060: beql        $t6, $zero, L_8014B084
    if (ctx->r14 == 0) {
        // 0x8014B064: lhu         $a0, 0x1A($sp)
        ctx->r4 = MEM_HU(ctx->r29, 0X1A);
            goto L_8014B084;
    }
    goto skip_0;
    // 0x8014B064: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    skip_0:
    // 0x8014B068: jal         0x801FF438
    // 0x8014B06C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    LOOKUP_FUNC(0x801FF438)(rdram, ctx);
        goto after_1;
    // 0x8014B06C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x8014B070: b           L_8014B084
    // 0x8014B074: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
        goto L_8014B084;
    // 0x8014B074: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
L_8014B078:
    // 0x8014B078: b           L_8014B0AC
    // 0x8014B07C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014B0AC;
    // 0x8014B07C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014B080: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
L_8014B084:
    // 0x8014B084: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8014B088: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8014B08C: bnel        $at, $zero, L_8014B0AC
    if (ctx->r1 != 0) {
        // 0x8014B090: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014B0AC;
    }
    goto skip_1;
    // 0x8014B090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8014B094: jal         0x8014B6F8
    // 0x8014B098: nop

    LOOKUP_FUNC(0x8014B6F8)(rdram, ctx);
        goto after_2;
    // 0x8014B098: nop

    after_2:
    // 0x8014B09C: beql        $v0, $zero, L_8014B0AC
    if (ctx->r2 == 0) {
        // 0x8014B0A0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8014B0AC;
    }
    goto skip_2;
    // 0x8014B0A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x8014B0A4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8014B0A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014B0AC:
    // 0x8014B0AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014B0B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014B0B4: jr          $ra
    // 0x8014B0B8: nop

    return;
    // 0x8014B0B8: nop

;}
RECOMP_FUNC void M7_FUN_8014b0bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B0BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014B0C0: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    // 0x8014B0C4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8014B0C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014B0CC: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8014B0D0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8014B0D4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x8014B0D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8014B0DC: beq         $at, $zero, L_8014B0EC
    if (ctx->r1 == 0) {
        // 0x8014B0E0: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_8014B0EC;
    }
    // 0x8014B0E0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8014B0E4: b           L_8014B194
    // 0x8014B0E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014B194;
    // 0x8014B0E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014B0EC:
    // 0x8014B0EC: jal         0x8014B6F8
    // 0x8014B0F0: nop

    LOOKUP_FUNC(0x8014B6F8)(rdram, ctx);
        goto after_0;
    // 0x8014B0F0: nop

    after_0:
    // 0x8014B0F4: beq         $v0, $zero, L_8014B104
    if (ctx->r2 == 0) {
        // 0x8014B0F8: nop
    
            goto L_8014B104;
    }
    // 0x8014B0F8: nop

    // 0x8014B0FC: b           L_8014B194
    // 0x8014B100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014B194;
    // 0x8014B100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014B104:
    // 0x8014B104: jal         0x8014B5E8
    // 0x8014B108: nop

    LOOKUP_FUNC(0x8014B5E8)(rdram, ctx);
        goto after_1;
    // 0x8014B108: nop

    after_1:
    // 0x8014B10C: bne         $v0, $zero, L_8014B11C
    if (ctx->r2 != 0) {
        // 0x8014B110: lbu         $t6, 0x3B($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X3B);
            goto L_8014B11C;
    }
    // 0x8014B110: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x8014B114: b           L_8014B194
    // 0x8014B118: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014B194;
    // 0x8014B118: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014B11C:
    // 0x8014B11C: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8014B120: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8014B124: lbu         $t8, 0x3F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3F);
    // 0x8014B128: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8014B12C: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8014B130: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8014B134: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8014B138: nop

    // 0x8014B13C: sh          $t0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r8;
    // 0x8014B140: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8014B144: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8014B148: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8014B14C: nop

    // 0x8014B150: sh          $t2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r10;
    // 0x8014B154: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8014B158: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8014B15C: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8014B160: nop

    // 0x8014B164: sh          $t4, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r12;
    // 0x8014B168: lh          $t5, 0x26($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X26);
    // 0x8014B16C: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x8014B170: lhu         $t6, 0x2A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2A);
    // 0x8014B174: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x8014B178: lhu         $t7, 0x36($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X36);
    // 0x8014B17C: sh          $t7, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r15;
    // 0x8014B180: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x8014B184: sb          $t8, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r24;
    // 0x8014B188: lhu         $t9, 0x32($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X32);
    // 0x8014B18C: sb          $t9, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r25;
    // 0x8014B190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014B194:
    // 0x8014B194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014B198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014B19C: jr          $ra
    // 0x8014B1A0: nop

    return;
    // 0x8014B1A0: nop

;}
RECOMP_FUNC void M7_FUN_8014b1a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B1A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014B1A8: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    // 0x8014B1AC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8014B1B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014B1B4: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8014B1B8: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8014B1BC: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x8014B1C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8014B1C4: beq         $at, $zero, L_8014B1D4
    if (ctx->r1 == 0) {
        // 0x8014B1C8: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_8014B1D4;
    }
    // 0x8014B1C8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8014B1CC: b           L_8014B27C
    // 0x8014B1D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014B27C;
    // 0x8014B1D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014B1D4:
    // 0x8014B1D4: jal         0x8014B6F8
    // 0x8014B1D8: nop

    LOOKUP_FUNC(0x8014B6F8)(rdram, ctx);
        goto after_0;
    // 0x8014B1D8: nop

    after_0:
    // 0x8014B1DC: beq         $v0, $zero, L_8014B1EC
    if (ctx->r2 == 0) {
        // 0x8014B1E0: nop
    
            goto L_8014B1EC;
    }
    // 0x8014B1E0: nop

    // 0x8014B1E4: b           L_8014B27C
    // 0x8014B1E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014B27C;
    // 0x8014B1E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014B1EC:
    // 0x8014B1EC: jal         0x8014B5E8
    // 0x8014B1F0: nop

    LOOKUP_FUNC(0x8014B5E8)(rdram, ctx);
        goto after_1;
    // 0x8014B1F0: nop

    after_1:
    // 0x8014B1F4: bne         $v0, $zero, L_8014B204
    if (ctx->r2 != 0) {
        // 0x8014B1F8: lbu         $t7, 0x3B($sp)
        ctx->r15 = MEM_BU(ctx->r29, 0X3B);
            goto L_8014B204;
    }
    // 0x8014B1F8: lbu         $t7, 0x3B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3B);
    // 0x8014B1FC: b           L_8014B27C
    // 0x8014B200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014B27C;
    // 0x8014B200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014B204:
    // 0x8014B204: ori         $t8, $t7, 0x3
    ctx->r24 = ctx->r15 | 0X3;
    // 0x8014B208: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8014B20C: lbu         $t9, 0x3F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3F);
    // 0x8014B210: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x8014B214: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8014B218: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8014B21C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8014B220: nop

    // 0x8014B224: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
    // 0x8014B228: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8014B22C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8014B230: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8014B234: nop

    // 0x8014B238: sh          $t3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r11;
    // 0x8014B23C: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8014B240: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8014B244: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8014B248: nop

    // 0x8014B24C: sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // 0x8014B250: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
    // 0x8014B254: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x8014B258: lhu         $t7, 0x2A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X2A);
    // 0x8014B25C: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
    // 0x8014B260: lhu         $t8, 0x36($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X36);
    // 0x8014B264: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
    // 0x8014B268: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
    // 0x8014B26C: sb          $t9, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r25;
    // 0x8014B270: lhu         $t0, 0x32($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X32);
    // 0x8014B274: sb          $t0, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r8;
    // 0x8014B278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014B27C:
    // 0x8014B27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014B280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014B284: jr          $ra
    // 0x8014B288: nop

    return;
    // 0x8014B288: nop

;}
RECOMP_FUNC void M7_FUN_8014b28c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B28C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014B290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014B294: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014B298: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8014B29C: jal         0x8014B7CC
    // 0x8014B2A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014B2A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8014B2A4: beq         $v0, $zero, L_8014B2B8
    if (ctx->r2 == 0) {
        // 0x8014B2A8: lbu         $t6, 0x1F($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X1F);
            goto L_8014B2B8;
    }
    // 0x8014B2A8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8014B2AC: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    // 0x8014B2B0: b           L_8014B2BC
    // 0x8014B2B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014B2BC;
    // 0x8014B2B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014B2B8:
    // 0x8014B2B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014B2BC:
    // 0x8014B2BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014B2C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014B2C4: jr          $ra
    // 0x8014B2C8: nop

    return;
    // 0x8014B2C8: nop

;}
RECOMP_FUNC void M7_FUN_8014b2cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B2CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014B2D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014B2D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014B2D8: jal         0x8014B7CC
    // 0x8014B2DC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014B2DC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8014B2E0: beq         $v0, $zero, L_8014B2F0
    if (ctx->r2 == 0) {
        // 0x8014B2E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014B2F0;
    }
    // 0x8014B2E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014B2E8: b           L_8014B2F4
    // 0x8014B2EC: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
        goto L_8014B2F4;
    // 0x8014B2EC: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
L_8014B2F0:
    // 0x8014B2F0: ori         $v0, $zero, 0xFF00
    ctx->r2 = 0 | 0XFF00;
L_8014B2F4:
    // 0x8014B2F4: jr          $ra
    // 0x8014B2F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8014B2F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014b2fc(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014b2fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B2FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014B300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014B304: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014B308: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8014B30C: jal         0x8014B7CC
    // 0x8014B310: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014B310: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8014B314: beq         $v0, $zero, L_8014B328
    if (ctx->r2 == 0) {
        // 0x8014B318: lbu         $t6, 0x1F($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X1F);
            goto L_8014B328;
    }
    // 0x8014B318: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8014B31C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8014B320: b           L_8014B32C
    // 0x8014B324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014B32C;
    // 0x8014B324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014B328:
    // 0x8014B328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014B32C:
    // 0x8014B32C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014B330: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014B334: jr          $ra
    // 0x8014B338: nop

    return;
    // 0x8014B338: nop

;}
RECOMP_FUNC void M7_FUN_8014b33c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B33C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014B340: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014B344: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014B348: jal         0x8014B7CC
    // 0x8014B34C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014B34C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8014B350: beq         $v0, $zero, L_8014B360
    if (ctx->r2 == 0) {
        // 0x8014B354: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014B360;
    }
    // 0x8014B354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014B358: b           L_8014B364
    // 0x8014B35C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
        goto L_8014B364;
    // 0x8014B35C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
L_8014B360:
    // 0x8014B360: ori         $v0, $zero, 0xFF00
    ctx->r2 = 0 | 0XFF00;
L_8014B364:
    // 0x8014B364: jr          $ra
    // 0x8014B368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8014B368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M7_FUN_8014b36c(rdram, ctx);
;}
RECOMP_FUNC void M7_FUN_8014b36c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B36C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014B370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014B374: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014B378: jal         0x8014B7CC
    // 0x8014B37C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    LOOKUP_FUNC(0x8014B7CC)(rdram, ctx);
        goto after_0;
    // 0x8014B37C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8014B380: beql        $v0, $zero, L_8014B3A0
    if (ctx->r2 == 0) {
        // 0x8014B384: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014B3A0;
    }
    goto skip_0;
    // 0x8014B384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014B388: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8014B38C: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8014B390: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8014B394: b           L_8014B3A0
    // 0x8014B398: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014B3A0;
    // 0x8014B398: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014B39C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014B3A0:
    // 0x8014B3A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014B3A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014B3A8: jr          $ra
    // 0x8014B3AC: nop

    return;
    // 0x8014B3AC: nop

;}
