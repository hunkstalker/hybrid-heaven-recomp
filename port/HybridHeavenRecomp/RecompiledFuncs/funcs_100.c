#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M10_FUN_80234d68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80234D68: jr          $ra
    // 0x80234D6C: nop

    return;
    // 0x80234D6C: nop

;}
RECOMP_FUNC void M10_FUN_80234d70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80234D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80234D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80234D78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80234D7C: lbu         $v0, 0xA9($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA9);
    // 0x80234D80: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80234D84: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80234D88: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80234D8C: bnel        $t6, $zero, L_80234DB0
    if (ctx->r14 != 0) {
        // 0x80234D90: andi        $t8, $v0, 0x2
        ctx->r24 = ctx->r2 & 0X2;
            goto L_80234DB0;
    }
    goto skip_0;
    // 0x80234D90: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    skip_0:
    // 0x80234D94: lw          $a0, 0x10($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X10);
    // 0x80234D98: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80234D9C: jal         0x80145310
    // 0x80234DA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x80234DA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80234DA4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80234DA8: lbu         $v0, 0xA9($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0XA9);
    // 0x80234DAC: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
L_80234DB0:
    // 0x80234DB0: bne         $t8, $zero, L_80234DC4
    if (ctx->r24 != 0) {
        // 0x80234DB4: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80234DC4;
    }
    // 0x80234DB4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80234DB8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80234DBC: jal         0x80145310
    // 0x80234DC0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_1;
    // 0x80234DC0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_1:
L_80234DC4:
    // 0x80234DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80234DC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80234DCC: jr          $ra
    // 0x80234DD0: nop

    return;
    // 0x80234DD0: nop

;}
RECOMP_FUNC void M10_FUN_80234dd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80234DD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80234DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80234DDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80234DE0: lbu         $v0, 0xA9($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA9);
    // 0x80234DE4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80234DE8: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80234DEC: bnel        $t6, $zero, L_80234E10
    if (ctx->r14 != 0) {
        // 0x80234DF0: andi        $t8, $v0, 0x2
        ctx->r24 = ctx->r2 & 0X2;
            goto L_80234E10;
    }
    goto skip_0;
    // 0x80234DF0: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    skip_0:
    // 0x80234DF4: lw          $a0, 0x10($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X10);
    // 0x80234DF8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80234DFC: jal         0x801451C0
    // 0x80234E00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_0;
    // 0x80234E00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80234E04: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80234E08: lbu         $v0, 0xA9($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0XA9);
    // 0x80234E0C: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
L_80234E10:
    // 0x80234E10: bne         $t8, $zero, L_80234E20
    if (ctx->r24 != 0) {
        // 0x80234E14: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80234E20;
    }
    // 0x80234E14: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80234E18: jal         0x801451C0
    // 0x80234E1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_1;
    // 0x80234E1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
L_80234E20:
    // 0x80234E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80234E24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80234E28: jr          $ra
    // 0x80234E2C: nop

    return;
    // 0x80234E2C: nop

;}
RECOMP_FUNC void M10_FUN_80234e30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80234E30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80234E34: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80234E38: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80234E3C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80234E40: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80234E44: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80234E48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80234E4C: lb          $v0, 0xA3($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XA3);
    // 0x80234E50: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80234E54: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80234E58: blez        $v0, L_80234EAC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80234E5C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80234EAC;
    }
    // 0x80234E5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80234E60: lui         $s2, 0x8024
    ctx->r18 = S32(0X8024 << 16);
    // 0x80234E64: addiu       $s2, $s2, 0x7E8
    ctx->r18 = ADD32(ctx->r18, 0X7E8);
    // 0x80234E68: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
L_80234E6C:
    // 0x80234E6C: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80234E70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80234E74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80234E78: mflo        $t6
    ctx->r14 = lo;
    // 0x80234E7C: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x80234E80: lbu         $t8, 0x8($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X8);
    // 0x80234E84: bnel        $t8, $zero, L_80234E9C
    if (ctx->r24 != 0) {
        // 0x80234E88: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80234E9C;
    }
    goto skip_0;
    // 0x80234E88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80234E8C: jal         0x80145310
    // 0x80234E90: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x80234E90: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_0:
    // 0x80234E94: lb          $v0, 0xA3($s4)
    ctx->r2 = MEM_B(ctx->r20, 0XA3);
    // 0x80234E98: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80234E9C:
    // 0x80234E9C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80234EA0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80234EA4: bne         $at, $zero, L_80234E6C
    if (ctx->r1 != 0) {
        // 0x80234EA8: lw          $s1, 0x10($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X10);
            goto L_80234E6C;
    }
    // 0x80234EA8: lw          $s1, 0x10($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X10);
L_80234EAC:
    // 0x80234EAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80234EB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80234EB4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80234EB8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80234EBC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80234EC0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80234EC4: jr          $ra
    // 0x80234EC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80234EC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80234ecc(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80234ecc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80234ECC: jr          $ra
    // 0x80234ED0: nop

    return;
    // 0x80234ED0: nop

;}
RECOMP_FUNC void M10_FUN_80234ed4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80234ED4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80234ED8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80234EDC: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80234EE0: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x80234EE4: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80234EE8: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80234EEC: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80234EF0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80234EF4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80234EF8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80234EFC: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80234F00: lb          $s4, 0xA2($a0)
    ctx->r20 = MEM_B(ctx->r4, 0XA2);
    // 0x80234F04: lb          $s5, 0xA3($a0)
    ctx->r21 = MEM_B(ctx->r4, 0XA3);
    // 0x80234F08: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80234F0C: negu        $at, $s4
    ctx->r1 = SUB32(0, ctx->r20);
    // 0x80234F10: sll         $s4, $at, 3
    ctx->r20 = S32(ctx->r1 << 3);
    // 0x80234F14: addu        $s4, $s4, $at
    ctx->r20 = ADD32(ctx->r20, ctx->r1);
    // 0x80234F18: sll         $s4, $s4, 2
    ctx->r20 = S32(ctx->r20 << 2);
    // 0x80234F1C: subu        $s4, $s4, $at
    ctx->r20 = SUB32(ctx->r20, ctx->r1);
    // 0x80234F20: negu        $at, $s5
    ctx->r1 = SUB32(0, ctx->r21);
    // 0x80234F24: sll         $s5, $at, 3
    ctx->r21 = S32(ctx->r1 << 3);
    // 0x80234F28: addu        $s5, $s5, $at
    ctx->r21 = ADD32(ctx->r21, ctx->r1);
    // 0x80234F2C: sll         $s4, $s4, 3
    ctx->r20 = S32(ctx->r20 << 3);
    // 0x80234F30: addiu       $s5, $s5, 0x9
    ctx->r21 = ADD32(ctx->r21, 0X9);
    // 0x80234F34: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x80234F38: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x80234F3C: andi        $s3, $a3, 0xFF
    ctx->r19 = ctx->r7 & 0XFF;
    // 0x80234F40: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80234F44: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x80234F48: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80234F4C: jal         0x80234450
    // 0x80234F50: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    LOOKUP_FUNC(0x80234450)(rdram, ctx);
        goto after_0;
    // 0x80234F50: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    after_0:
    // 0x80234F54: jal         0x80006214
    // 0x80234F58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x80234F58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80234F5C: lbu         $t6, 0x73($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X73);
    // 0x80234F60: sb          $v0, 0x5E($sp)
    MEM_B(0X5E, ctx->r29) = ctx->r2;
    // 0x80234F64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80234F68: beq         $t6, $zero, L_80235168
    if (ctx->r14 == 0) {
        // 0x80234F6C: sw          $t6, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r14;
            goto L_80235168;
    }
    // 0x80234F6C: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x80234F70: beq         $t6, $at, L_80234F94
    if (ctx->r14 == ctx->r1) {
        // 0x80234F74: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80234F94;
    }
    // 0x80234F74: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80234F78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80234F7C: beq         $t6, $at, L_802350C0
    if (ctx->r14 == ctx->r1) {
        // 0x80234F80: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_802350C0;
    }
    // 0x80234F80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80234F84: beq         $t6, $at, L_8023523C
    if (ctx->r14 == ctx->r1) {
        // 0x80234F88: nop
    
            goto L_8023523C;
    }
    // 0x80234F88: nop

    // 0x80234F8C: b           L_802352E0
    // 0x80234F90: lb          $t4, 0x5E($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X5E);
        goto L_802352E0;
    // 0x80234F90: lb          $t4, 0x5E($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X5E);
L_80234F94:
    // 0x80234F94: addiu       $s4, $s4, -0x46
    ctx->r20 = ADD32(ctx->r20, -0X46);
    // 0x80234F98: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x80234F9C: jal         0x80006214
    // 0x80234FA0: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x80234FA0: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    after_2:
    // 0x80234FA4: sb          $v0, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = ctx->r2;
    // 0x80234FA8: lb          $t7, 0xA3($s2)
    ctx->r15 = MEM_B(ctx->r18, 0XA3);
    // 0x80234FAC: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x80234FB0: addiu       $t8, $t8, -0x1C00
    ctx->r24 = ADD32(ctx->r24, -0X1C00);
    // 0x80234FB4: blez        $t7, L_8023501C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80234FB8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8023501C;
    }
    // 0x80234FB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80234FBC: addu        $s1, $s3, $t8
    ctx->r17 = ADD32(ctx->r19, ctx->r24);
    // 0x80234FC0: addiu       $s3, $zero, 0x8C
    ctx->r19 = ADD32(0, 0X8C);
L_80234FC4:
    // 0x80234FC4: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80234FC8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80234FCC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80234FD0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80234FD4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80234FD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80234FDC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80234FE0: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    // 0x80234FE4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80234FE8: mflo        $t9
    ctx->r25 = lo;
    // 0x80234FEC: addu        $a3, $s4, $t9
    ctx->r7 = ADD32(ctx->r20, ctx->r25);
    // 0x80234FF0: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80234FF4: jal         0x8023448C
    // 0x80234FF8: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_3;
    // 0x80234FF8: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    after_3:
    // 0x80234FFC: lb          $t2, 0xA3($s2)
    ctx->r10 = MEM_B(ctx->r18, 0XA3);
    // 0x80235000: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80235004: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x80235008: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x8023500C: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80235010: bne         $at, $zero, L_80234FC4
    if (ctx->r1 != 0) {
        // 0x80235014: nop
    
            goto L_80234FC4;
    }
    // 0x80235014: nop

    // 0x80235018: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8023501C:
    // 0x8023501C: lb          $t3, 0x5D($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X5D);
    // 0x80235020: addiu       $s3, $zero, 0x8C
    ctx->r19 = ADD32(0, 0X8C);
    // 0x80235024: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80235028: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8023502C: addu        $t5, $s6, $t4
    ctx->r13 = ADD32(ctx->r22, ctx->r12);
    // 0x80235030: jal         0x80234D70
    // 0x80235034: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    LOOKUP_FUNC(0x80234D70)(rdram, ctx);
        goto after_4;
    // 0x80235034: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    after_4:
    // 0x80235038: jal         0x80006214
    // 0x8023503C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_5;
    // 0x8023503C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80235040: sb          $v0, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = ctx->r2;
    // 0x80235044: lb          $t6, 0xA3($s2)
    ctx->r14 = MEM_B(ctx->r18, 0XA3);
    // 0x80235048: blezl       $t6, L_802350A4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8023504C: lb          $t1, 0x5D($sp)
        ctx->r9 = MEM_B(ctx->r29, 0X5D);
            goto L_802350A4;
    }
    goto skip_0;
    // 0x8023504C: lb          $t1, 0x5D($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X5D);
    skip_0:
L_80235050:
    // 0x80235050: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80235054: addu        $t7, $s0, $s7
    ctx->r15 = ADD32(ctx->r16, ctx->r23);
    // 0x80235058: lbu         $a2, 0x0($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X0);
    // 0x8023505C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80235060: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80235064: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80235068: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8023506C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80235070: mflo        $t8
    ctx->r24 = lo;
    // 0x80235074: addu        $a3, $s4, $t8
    ctx->r7 = ADD32(ctx->r20, ctx->r24);
    // 0x80235078: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8023507C: jal         0x802345B0
    // 0x80235080: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    LOOKUP_FUNC(0x802345B0)(rdram, ctx);
        goto after_6;
    // 0x80235080: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    after_6:
    // 0x80235084: lb          $t0, 0xA3($s2)
    ctx->r8 = MEM_B(ctx->r18, 0XA3);
    // 0x80235088: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8023508C: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x80235090: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80235094: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80235098: bne         $at, $zero, L_80235050
    if (ctx->r1 != 0) {
        // 0x8023509C: nop
    
            goto L_80235050;
    }
    // 0x8023509C: nop

    // 0x802350A0: lb          $t1, 0x5D($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X5D);
L_802350A4:
    // 0x802350A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x802350A8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x802350AC: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x802350B0: jal         0x80234DD4
    // 0x802350B4: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    LOOKUP_FUNC(0x80234DD4)(rdram, ctx);
        goto after_7;
    // 0x802350B4: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    after_7:
    // 0x802350B8: b           L_802352E0
    // 0x802350BC: lb          $t4, 0x5E($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X5E);
        goto L_802352E0;
    // 0x802350BC: lb          $t4, 0x5E($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X5E);
L_802350C0:
    // 0x802350C0: jal         0x80006214
    // 0x802350C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_8;
    // 0x802350C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x802350C8: sb          $v0, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = ctx->r2;
    // 0x802350CC: lb          $t4, 0xA3($s2)
    ctx->r12 = MEM_B(ctx->r18, 0XA3);
    // 0x802350D0: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x802350D4: addiu       $t5, $t5, -0x1C00
    ctx->r13 = ADD32(ctx->r13, -0X1C00);
    // 0x802350D8: blez        $t4, L_8023513C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x802350DC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8023513C;
    }
    // 0x802350DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x802350E0: addu        $s1, $s3, $t5
    ctx->r17 = ADD32(ctx->r19, ctx->r13);
    // 0x802350E4: addiu       $s3, $zero, 0x12
    ctx->r19 = ADD32(0, 0X12);
L_802350E8:
    // 0x802350E8: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802350EC: sll         $a3, $s4, 16
    ctx->r7 = S32(ctx->r20 << 16);
    // 0x802350F0: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x802350F4: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x802350F8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x802350FC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80235100: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80235104: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80235108: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8023510C: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    // 0x80235110: mflo        $t6
    ctx->r14 = lo;
    // 0x80235114: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x80235118: jal         0x8023448C
    // 0x8023511C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_9;
    // 0x8023511C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_9:
    // 0x80235120: lb          $t0, 0xA3($s2)
    ctx->r8 = MEM_B(ctx->r18, 0XA3);
    // 0x80235124: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80235128: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x8023512C: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80235130: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80235134: bne         $at, $zero, L_802350E8
    if (ctx->r1 != 0) {
        // 0x80235138: nop
    
            goto L_802350E8;
    }
    // 0x80235138: nop

L_8023513C:
    // 0x8023513C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80235140: jal         0x80234AFC
    // 0x80235144: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    LOOKUP_FUNC(0x80234AFC)(rdram, ctx);
        goto after_10;
    // 0x80235144: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_10:
    // 0x80235148: lb          $t1, 0x5D($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X5D);
    // 0x8023514C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80235150: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80235154: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x80235158: jal         0x80234E30
    // 0x8023515C: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    LOOKUP_FUNC(0x80234E30)(rdram, ctx);
        goto after_11;
    // 0x8023515C: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    after_11:
    // 0x80235160: b           L_802352E0
    // 0x80235164: lb          $t4, 0x5E($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X5E);
        goto L_802352E0;
    // 0x80235164: lb          $t4, 0x5E($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X5E);
L_80235168:
    // 0x80235168: lb          $v1, 0xA3($s2)
    ctx->r3 = MEM_B(ctx->r18, 0XA3);
    // 0x8023516C: lui         $t4, 0x8024
    ctx->r12 = S32(0X8024 << 16);
    // 0x80235170: addiu       $t4, $t4, -0x1C00
    ctx->r12 = ADD32(ctx->r12, -0X1C00);
    // 0x80235174: blez        $v1, L_802351DC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80235178: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_802351DC;
    }
    // 0x80235178: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8023517C: addu        $s1, $s3, $t4
    ctx->r17 = ADD32(ctx->r19, ctx->r12);
    // 0x80235180: addiu       $s3, $zero, 0x12
    ctx->r19 = ADD32(0, 0X12);
L_80235184:
    // 0x80235184: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80235188: sll         $a3, $s4, 16
    ctx->r7 = S32(ctx->r20 << 16);
    // 0x8023518C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80235190: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x80235194: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80235198: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8023519C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x802351A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x802351A4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x802351A8: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    // 0x802351AC: mflo        $t5
    ctx->r13 = lo;
    // 0x802351B0: addu        $t6, $s5, $t5
    ctx->r14 = ADD32(ctx->r21, ctx->r13);
    // 0x802351B4: jal         0x8023448C
    // 0x802351B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_12;
    // 0x802351B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_12:
    // 0x802351BC: lb          $v1, 0xA3($s2)
    ctx->r3 = MEM_B(ctx->r18, 0XA3);
    // 0x802351C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x802351C4: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x802351C8: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x802351CC: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x802351D0: bne         $at, $zero, L_80235184
    if (ctx->r1 != 0) {
        // 0x802351D4: nop
    
            goto L_80235184;
    }
    // 0x802351D4: nop

    // 0x802351D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_802351DC:
    // 0x802351DC: blez        $v1, L_802352DC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x802351E0: addiu       $s3, $zero, 0x12
        ctx->r19 = ADD32(0, 0X12);
            goto L_802352DC;
    }
    // 0x802351E0: addiu       $s3, $zero, 0x12
    ctx->r19 = ADD32(0, 0X12);
L_802351E4:
    // 0x802351E4: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802351E8: addu        $t9, $s0, $s7
    ctx->r25 = ADD32(ctx->r16, ctx->r23);
    // 0x802351EC: lbu         $a2, 0x0($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X0);
    // 0x802351F0: sll         $a3, $s4, 16
    ctx->r7 = S32(ctx->r20 << 16);
    // 0x802351F4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x802351F8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x802351FC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80235200: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80235204: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80235208: mflo        $t0
    ctx->r8 = lo;
    // 0x8023520C: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x80235210: jal         0x802345B0
    // 0x80235214: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x802345B0)(rdram, ctx);
        goto after_13;
    // 0x80235214: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_13:
    // 0x80235218: lb          $t3, 0xA3($s2)
    ctx->r11 = MEM_B(ctx->r18, 0XA3);
    // 0x8023521C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80235220: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x80235224: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80235228: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8023522C: bne         $at, $zero, L_802351E4
    if (ctx->r1 != 0) {
        // 0x80235230: nop
    
            goto L_802351E4;
    }
    // 0x80235230: nop

    // 0x80235234: b           L_802352E0
    // 0x80235238: lb          $t4, 0x5E($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X5E);
        goto L_802352E0;
    // 0x80235238: lb          $t4, 0x5E($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X5E);
L_8023523C:
    // 0x8023523C: jal         0x80006214
    // 0x80235240: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_14;
    // 0x80235240: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x80235244: sb          $v0, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = ctx->r2;
    // 0x80235248: lb          $t4, 0xA3($s2)
    ctx->r12 = MEM_B(ctx->r18, 0XA3);
    // 0x8023524C: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x80235250: addiu       $t5, $t5, -0x1C00
    ctx->r13 = ADD32(ctx->r13, -0X1C00);
    // 0x80235254: blez        $t4, L_802352B8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80235258: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_802352B8;
    }
    // 0x80235258: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8023525C: addu        $s1, $s3, $t5
    ctx->r17 = ADD32(ctx->r19, ctx->r13);
    // 0x80235260: addiu       $s3, $zero, 0x12
    ctx->r19 = ADD32(0, 0X12);
L_80235264:
    // 0x80235264: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80235268: sll         $a3, $s4, 16
    ctx->r7 = S32(ctx->r20 << 16);
    // 0x8023526C: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80235270: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80235274: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80235278: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8023527C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80235280: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80235284: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80235288: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    // 0x8023528C: mflo        $t6
    ctx->r14 = lo;
    // 0x80235290: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x80235294: jal         0x8023448C
    // 0x80235298: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_15;
    // 0x80235298: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_15:
    // 0x8023529C: lb          $t0, 0xA3($s2)
    ctx->r8 = MEM_B(ctx->r18, 0XA3);
    // 0x802352A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x802352A4: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x802352A8: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x802352AC: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x802352B0: bne         $at, $zero, L_80235264
    if (ctx->r1 != 0) {
        // 0x802352B4: nop
    
            goto L_80235264;
    }
    // 0x802352B4: nop

L_802352B8:
    // 0x802352B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x802352BC: jal         0x80234934
    // 0x802352C0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    LOOKUP_FUNC(0x80234934)(rdram, ctx);
        goto after_16;
    // 0x802352C0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_16:
    // 0x802352C4: lb          $t1, 0x5D($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X5D);
    // 0x802352C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x802352CC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x802352D0: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x802352D4: jal         0x80234E30
    // 0x802352D8: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    LOOKUP_FUNC(0x80234E30)(rdram, ctx);
        goto after_17;
    // 0x802352D8: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    after_17:
L_802352DC:
    // 0x802352DC: lb          $t4, 0x5E($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X5E);
L_802352E0:
    // 0x802352E0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802352E4: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x802352E8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x802352EC: addu        $t6, $t5, $s6
    ctx->r14 = ADD32(ctx->r13, ctx->r22);
    // 0x802352F0: sw          $t6, 0x864($at)
    MEM_W(0X864, ctx->r1) = ctx->r14;
    // 0x802352F4: lb          $t7, 0xA3($s2)
    ctx->r15 = MEM_B(ctx->r18, 0XA3);
    // 0x802352F8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802352FC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80235300: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80235304: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80235308: addu        $t0, $t9, $s6
    ctx->r8 = ADD32(ctx->r25, ctx->r22);
    // 0x8023530C: sw          $t0, 0x868($at)
    MEM_W(0X868, ctx->r1) = ctx->r8;
    // 0x80235310: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80235314: bne         $t1, $at, L_80235330
    if (ctx->r9 != ctx->r1) {
        // 0x80235318: lw          $t2, 0x4C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X4C);
            goto L_80235330;
    }
    // 0x80235318: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8023531C: addiu       $a1, $zero, -0xB
    ctx->r5 = ADD32(0, -0XB);
    // 0x80235320: jal         0x802348C8
    // 0x80235324: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    LOOKUP_FUNC(0x802348C8)(rdram, ctx);
        goto after_18;
    // 0x80235324: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_18:
    // 0x80235328: b           L_8023536C
    // 0x8023532C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8023536C;
    // 0x8023532C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80235330:
    // 0x80235330: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80235334: beq         $t2, $at, L_80235348
    if (ctx->r10 == ctx->r1) {
        // 0x80235338: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80235348;
    }
    // 0x80235338: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8023533C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80235340: bne         $t2, $at, L_8023535C
    if (ctx->r10 != ctx->r1) {
        // 0x80235344: addiu       $a1, $zero, -0x50
        ctx->r5 = ADD32(0, -0X50);
            goto L_8023535C;
    }
    // 0x80235344: addiu       $a1, $zero, -0x50
    ctx->r5 = ADD32(0, -0X50);
L_80235348:
    // 0x80235348: addiu       $a1, $zero, -0x78
    ctx->r5 = ADD32(0, -0X78);
    // 0x8023534C: jal         0x802348C8
    // 0x80235350: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    LOOKUP_FUNC(0x802348C8)(rdram, ctx);
        goto after_19;
    // 0x80235350: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_19:
    // 0x80235354: b           L_8023536C
    // 0x80235358: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8023536C;
    // 0x80235358: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8023535C:
    // 0x8023535C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80235360: jal         0x802348C8
    // 0x80235364: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x802348C8)(rdram, ctx);
        goto after_20;
    // 0x80235364: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_20:
    // 0x80235368: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8023536C:
    // 0x8023536C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80235370: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80235374: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80235378: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8023537C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80235380: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80235384: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80235388: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x8023538C: jr          $ra
    // 0x80235390: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80235390: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80235394(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80235394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80235394: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80235398: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x8023539C: lw          $a3, 0x864($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X864);
    // 0x802353A0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x802353A4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x802353A8: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x802353AC: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x802353B0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x802353B4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x802353B8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x802353BC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x802353C0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x802353C4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x802353C8: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x802353CC: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x802353D0: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x802353D4: lb          $t1, 0xA3($fp)
    ctx->r9 = MEM_B(ctx->r30, 0XA3);
    // 0x802353D8: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x802353DC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x802353E0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x802353E4: lh          $t2, 0x4($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X4);
    // 0x802353E8: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x802353EC: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x802353F0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x802353F4: bgez        $t2, L_80235400
    if (SIGNED(ctx->r10) >= 0) {
        // 0x802353F8: addu        $at, $t2, $zero
        ctx->r1 = ADD32(ctx->r10, 0);
            goto L_80235400;
    }
    // 0x802353F8: addu        $at, $t2, $zero
    ctx->r1 = ADD32(ctx->r10, 0);
    // 0x802353FC: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
L_80235400:
    // 0x80235400: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
    // 0x80235404: sll         $t2, $t2, 16
    ctx->r10 = S32(ctx->r10 << 16);
    // 0x80235408: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8023540C: bne         $t1, $at, L_80235420
    if (ctx->r9 != ctx->r1) {
        // 0x80235410: sra         $t2, $t2, 16
        ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
            goto L_80235420;
    }
    // 0x80235410: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80235414: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x80235418: b           L_8023542C
    // 0x8023541C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_8023542C;
    // 0x8023541C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_80235420:
    // 0x80235420: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80235424: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80235428: lh          $v0, 0x0($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X0);
L_8023542C:
    // 0x8023542C: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x80235430: bgez        $t9, L_80235440
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80235434: sra         $t3, $t9, 1
        ctx->r11 = S32(SIGNED(ctx->r25) >> 1);
            goto L_80235440;
    }
    // 0x80235434: sra         $t3, $t9, 1
    ctx->r11 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80235438: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x8023543C: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80235440:
    // 0x80235440: addu        $a1, $t3, $t2
    ctx->r5 = ADD32(ctx->r11, ctx->r10);
    // 0x80235444: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80235448: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8023544C: addu        $t4, $v1, $t2
    ctx->r12 = ADD32(ctx->r3, ctx->r10);
    // 0x80235450: subu        $s4, $t4, $a1
    ctx->r20 = SUB32(ctx->r12, ctx->r5);
    // 0x80235454: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x80235458: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x8023545C: bne         $a1, $at, L_80235538
    if (ctx->r5 != ctx->r1) {
        // 0x80235460: sra         $s4, $s4, 16
        ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
            goto L_80235538;
    }
    // 0x80235460: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80235464: lb          $t5, 0xA4($fp)
    ctx->r13 = MEM_B(ctx->r30, 0XA4);
    // 0x80235468: lui         $s6, 0x8024
    ctx->r22 = S32(0X8024 << 16);
    // 0x8023546C: addiu       $s6, $s6, 0x870
    ctx->r22 = ADD32(ctx->r22, 0X870);
    // 0x80235470: blez        $t5, L_802354C4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80235474: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_802354C4;
    }
    // 0x80235474: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80235478: lui         $s5, 0x8024
    ctx->r21 = S32(0X8024 << 16);
    // 0x8023547C: addiu       $s5, $s5, 0x86C
    ctx->r21 = ADD32(ctx->r21, 0X86C);
    // 0x80235480: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
L_80235484:
    // 0x80235484: sll         $s0, $s1, 2
    ctx->r16 = S32(ctx->r17 << 2);
    // 0x80235488: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8023548C: jal         0x80006088
    // 0x80235490: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_0;
    // 0x80235490: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x80235494: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x80235498: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8023549C: jal         0x80006088
    // 0x802354A0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_1;
    // 0x802354A0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x802354A4: lb          $t3, 0xA4($fp)
    ctx->r11 = MEM_B(ctx->r30, 0XA4);
    // 0x802354A8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x802354AC: sll         $s1, $s1, 24
    ctx->r17 = S32(ctx->r17 << 24);
    // 0x802354B0: sra         $s1, $s1, 24
    ctx->r17 = S32(SIGNED(ctx->r17) >> 24);
    // 0x802354B4: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x802354B8: bnel        $at, $zero, L_80235484
    if (ctx->r1 != 0) {
        // 0x802354BC: lw          $t6, 0x0($s5)
        ctx->r14 = MEM_W(ctx->r21, 0X0);
            goto L_80235484;
    }
    goto skip_0;
    // 0x802354BC: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    skip_0:
    // 0x802354C0: lb          $t1, 0xA3($fp)
    ctx->r9 = MEM_B(ctx->r30, 0XA3);
L_802354C4:
    // 0x802354C4: lui         $s5, 0x8024
    ctx->r21 = S32(0X8024 << 16);
    // 0x802354C8: lui         $s6, 0x8024
    ctx->r22 = S32(0X8024 << 16);
    // 0x802354CC: addiu       $s6, $s6, 0x870
    ctx->r22 = ADD32(ctx->r22, 0X870);
    // 0x802354D0: addiu       $s5, $s5, 0x86C
    ctx->r21 = ADD32(ctx->r21, 0X86C);
    // 0x802354D4: sb          $t1, 0xA4($fp)
    MEM_B(0XA4, ctx->r30) = ctx->r9;
    // 0x802354D8: jal         0x80006214
    // 0x802354DC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x802354DC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_2:
    // 0x802354E0: lb          $t4, 0xA4($fp)
    ctx->r12 = MEM_B(ctx->r30, 0XA4);
    // 0x802354E4: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x802354E8: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x802354EC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x802354F0: subu        $t6, $v1, $t5
    ctx->r14 = SUB32(ctx->r3, ctx->r13);
    // 0x802354F4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x802354F8: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x802354FC: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x80235500: lb          $t9, 0xA4($fp)
    ctx->r25 = MEM_B(ctx->r30, 0XA4);
    // 0x80235504: lui         $s7, 0x8024
    ctx->r23 = S32(0X8024 << 16);
    // 0x80235508: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8023550C: subu        $t3, $v1, $t9
    ctx->r11 = SUB32(ctx->r3, ctx->r25);
    // 0x80235510: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80235514: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80235518: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x8023551C: addiu       $a0, $s7, 0x7E8
    ctx->r4 = ADD32(ctx->r23, 0X7E8);
    // 0x80235520: sb          $zero, 0xA2($fp)
    MEM_B(0XA2, ctx->r30) = 0;
    // 0x80235524: addiu       $a1, $a1, 0x828
    ctx->r5 = ADD32(ctx->r5, 0X828);
    // 0x80235528: jal         0x800317D0
    // 0x8023552C: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    LOOKUP_FUNC(0x800317D0)(rdram, ctx);
        goto after_3;
    // 0x8023552C: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_3:
    // 0x80235530: b           L_80235874
    // 0x80235534: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_80235874;
    // 0x80235534: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80235538:
    // 0x80235538: sw          $a1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r5;
    // 0x8023553C: jal         0x80147D60
    // 0x80235540: sh          $t2, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(0x80147D60)(rdram, ctx);
        goto after_4;
    // 0x80235540: sh          $t2, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r10;
    after_4:
    // 0x80235544: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80235548: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x8023554C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80235550: subu        $v0, $t7, $t6
    ctx->r2 = SUB32(ctx->r15, ctx->r14);
    // 0x80235554: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80235558: mflo        $v0
    ctx->r2 = lo;
    // 0x8023555C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80235560: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x80235564: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80235568: bgez        $v1, L_80235578
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8023556C: sra         $s2, $s2, 16
        ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
            goto L_80235578;
    }
    // 0x8023556C: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80235570: b           L_8023557C
    // 0x80235574: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_8023557C;
    // 0x80235574: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_80235578:
    // 0x80235578: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8023557C:
    // 0x8023557C: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80235580: beq         $at, $zero, L_802355DC
    if (ctx->r1 == 0) {
        // 0x80235584: lbu         $t0, 0x83($sp)
        ctx->r8 = MEM_BU(ctx->r29, 0X83);
            goto L_802355DC;
    }
    // 0x80235584: lbu         $t0, 0x83($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X83);
    // 0x80235588: bgez        $v1, L_80235598
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8023558C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80235598;
    }
    // 0x8023558C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80235590: b           L_80235598
    // 0x80235594: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_80235598;
    // 0x80235594: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_80235598:
    // 0x80235598: div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // 0x8023559C: bne         $v0, $zero, L_802355A8
    if (ctx->r2 != 0) {
        // 0x802355A0: nop
    
            goto L_802355A8;
    }
    // 0x802355A0: nop

    // 0x802355A4: break       7
    do_break(2149799332);
L_802355A8:
    // 0x802355A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x802355AC: bne         $v0, $at, L_802355C0
    if (ctx->r2 != ctx->r1) {
        // 0x802355B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_802355C0;
    }
    // 0x802355B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x802355B4: bne         $v1, $at, L_802355C0
    if (ctx->r3 != ctx->r1) {
        // 0x802355B8: nop
    
            goto L_802355C0;
    }
    // 0x802355B8: nop

    // 0x802355BC: break       6
    do_break(2149799356);
L_802355C0:
    // 0x802355C0: mflo        $s2
    ctx->r18 = lo;
    // 0x802355C4: addu        $at, $s2, $zero
    ctx->r1 = ADD32(ctx->r18, 0);
    // 0x802355C8: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x802355CC: addu        $s2, $s2, $at
    ctx->r18 = ADD32(ctx->r18, ctx->r1);
    // 0x802355D0: sll         $s2, $s2, 1
    ctx->r18 = S32(ctx->r18 << 1);
    // 0x802355D4: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x802355D8: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
L_802355DC:
    // 0x802355DC: lb          $t8, 0xA4($fp)
    ctx->r24 = MEM_B(ctx->r30, 0XA4);
    // 0x802355E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x802355E4: andi        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 & 0X1;
    // 0x802355E8: blez        $t8, L_802356CC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x802355EC: lui         $s7, 0x8024
        ctx->r23 = S32(0X8024 << 16);
            goto L_802356CC;
    }
    // 0x802355EC: lui         $s7, 0x8024
    ctx->r23 = S32(0X8024 << 16);
    // 0x802355F0: lui         $s6, 0x8024
    ctx->r22 = S32(0X8024 << 16);
    // 0x802355F4: lui         $s5, 0x8024
    ctx->r21 = S32(0X8024 << 16);
    // 0x802355F8: addiu       $s5, $s5, 0x86C
    ctx->r21 = ADD32(ctx->r21, 0X86C);
    // 0x802355FC: addiu       $s6, $s6, 0x870
    ctx->r22 = ADD32(ctx->r22, 0X870);
    // 0x80235600: addiu       $s7, $s7, 0x550
    ctx->r23 = ADD32(ctx->r23, 0X550);
    // 0x80235604: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x80235608: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
L_8023560C:
    // 0x8023560C: sll         $s0, $s1, 2
    ctx->r16 = S32(ctx->r17 << 2);
    // 0x80235610: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x80235614: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80235618: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x8023561C: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x80235620: addu        $t7, $t5, $s2
    ctx->r15 = ADD32(ctx->r13, ctx->r18);
    // 0x80235624: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80235628: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x8023562C: addu        $t8, $t6, $s0
    ctx->r24 = ADD32(ctx->r14, ctx->r16);
    // 0x80235630: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80235634: lw          $v1, 0x30($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X30);
    // 0x80235638: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x8023563C: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80235640: beq         $t0, $zero, L_802356AC
    if (ctx->r8 == 0) {
        // 0x80235644: sh          $t4, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r12;
            goto L_802356AC;
    }
    // 0x80235644: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x80235648: multu       $s1, $s3
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8023564C: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x80235650: addiu       $t7, $t7, 0x828
    ctx->r15 = ADD32(ctx->r15, 0X828);
    // 0x80235654: addiu       $a0, $s1, 0x5
    ctx->r4 = ADD32(ctx->r17, 0X5);
    // 0x80235658: addiu       $t9, $zero, 0x82
    ctx->r25 = ADD32(0, 0X82);
    // 0x8023565C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80235660: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80235664: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80235668: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8023566C: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80235670: mflo        $t5
    ctx->r13 = lo;
    // 0x80235674: addu        $v0, $t5, $t7
    ctx->r2 = ADD32(ctx->r13, ctx->r15);
    // 0x80235678: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8023567C: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80235680: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80235684: addu        $t8, $t6, $s2
    ctx->r24 = ADD32(ctx->r14, ctx->r18);
    // 0x80235688: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8023568C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80235690: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x80235694: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80235698: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x8023569C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x802356A0: jal         0x8001B204
    // 0x802356A4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_5;
    // 0x802356A4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_5:
    // 0x802356A8: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
L_802356AC:
    // 0x802356AC: lb          $t5, 0xA4($fp)
    ctx->r13 = MEM_B(ctx->r30, 0XA4);
    // 0x802356B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x802356B4: sll         $s1, $s1, 24
    ctx->r17 = S32(ctx->r17 << 24);
    // 0x802356B8: sra         $s1, $s1, 24
    ctx->r17 = S32(SIGNED(ctx->r17) >> 24);
    // 0x802356BC: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x802356C0: bnel        $at, $zero, L_8023560C
    if (ctx->r1 != 0) {
        // 0x802356C4: lw          $t9, 0x0($s5)
        ctx->r25 = MEM_W(ctx->r21, 0X0);
            goto L_8023560C;
    }
    goto skip_1;
    // 0x802356C4: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    skip_1:
    // 0x802356C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_802356CC:
    // 0x802356CC: lb          $t7, 0xA3($fp)
    ctx->r15 = MEM_B(ctx->r30, 0XA3);
    // 0x802356D0: lbu         $t0, 0x83($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X83);
    // 0x802356D4: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x802356D8: blez        $t7, L_80235870
    if (SIGNED(ctx->r15) <= 0) {
        // 0x802356DC: andi        $t0, $t0, 0x2
        ctx->r8 = ctx->r8 & 0X2;
            goto L_80235870;
    }
    // 0x802356DC: andi        $t0, $t0, 0x2
    ctx->r8 = ctx->r8 & 0X2;
    // 0x802356E0: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x802356E4: lui         $s7, 0x8024
    ctx->r23 = S32(0X8024 << 16);
    // 0x802356E8: lui         $s5, 0x8024
    ctx->r21 = S32(0X8024 << 16);
    // 0x802356EC: addu        $t1, $t6, $s2
    ctx->r9 = ADD32(ctx->r14, ctx->r18);
    // 0x802356F0: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x802356F4: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x802356F8: addiu       $a0, $a0, 0x864
    ctx->r4 = ADD32(ctx->r4, 0X864);
    // 0x802356FC: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80235700: addiu       $s5, $s5, 0x868
    ctx->r21 = ADD32(ctx->r21, 0X868);
    // 0x80235704: addiu       $s7, $s7, 0x7E8
    ctx->r23 = ADD32(ctx->r23, 0X7E8);
    // 0x80235708: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x8023570C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
L_80235710:
    // 0x80235710: sll         $s0, $s1, 2
    ctx->r16 = S32(ctx->r17 << 2);
    // 0x80235714: slti        $at, $t1, 0x97
    ctx->r1 = SIGNED(ctx->r9) < 0X97 ? 1 : 0;
    // 0x80235718: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8023571C: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80235720: lw          $v0, 0x30($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X30);
    // 0x80235724: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x80235728: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x8023572C: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x80235730: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80235734: addu        $t6, $t7, $s0
    ctx->r14 = ADD32(ctx->r15, ctx->r16);
    // 0x80235738: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8023573C: lw          $v1, 0x30($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X30);
    // 0x80235740: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80235744: addu        $t3, $t9, $s2
    ctx->r11 = ADD32(ctx->r25, ctx->r18);
    // 0x80235748: bne         $at, $zero, L_802357E0
    if (ctx->r1 != 0) {
        // 0x8023574C: sh          $t3, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r11;
            goto L_802357E0;
    }
    // 0x8023574C: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x80235750: slti        $at, $t1, 0xAA
    ctx->r1 = SIGNED(ctx->r9) < 0XAA ? 1 : 0;
    // 0x80235754: beq         $at, $zero, L_802357E0
    if (ctx->r1 == 0) {
        // 0x80235758: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_802357E0;
    }
    // 0x80235758: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8023575C: bnel        $s1, $at, L_80235778
    if (ctx->r17 != ctx->r1) {
        // 0x80235760: lw          $t6, 0x0($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X0);
            goto L_80235778;
    }
    goto skip_2;
    // 0x80235760: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    skip_2:
    // 0x80235764: multu       $s4, $s6
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80235768: mflo        $s4
    ctx->r20 = lo;
    // 0x8023576C: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x80235770: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80235774: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
L_80235778:
    // 0x80235778: lh          $t4, 0x62($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X62);
    // 0x8023577C: addu        $t8, $t6, $s0
    ctx->r24 = ADD32(ctx->r14, ctx->r16);
    // 0x80235780: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80235784: subu        $t5, $s4, $t4
    ctx->r13 = SUB32(ctx->r20, ctx->r12);
    // 0x80235788: addiu       $t7, $t5, 0xA0
    ctx->r15 = ADD32(ctx->r13, 0XA0);
    // 0x8023578C: lw          $t3, 0x30($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X30);
    // 0x80235790: sh          $t7, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r15;
    // 0x80235794: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x80235798: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8023579C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x802357A0: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x802357A4: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x802357A8: bgez        $t8, L_802357B8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x802357AC: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_802357B8;
    }
    // 0x802357AC: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x802357B0: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x802357B4: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_802357B8:
    // 0x802357B8: subu        $t7, $s4, $t9
    ctx->r15 = SUB32(ctx->r20, ctx->r25);
    // 0x802357BC: addiu       $t3, $t7, 0xA0
    ctx->r11 = ADD32(ctx->r15, 0XA0);
    // 0x802357C0: beq         $t0, $zero, L_802357E0
    if (ctx->r8 == 0) {
        // 0x802357C4: sh          $t3, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r11;
            goto L_802357E0;
    }
    // 0x802357C4: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x802357C8: multu       $s1, $s3
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802357CC: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x802357D0: subu        $t5, $t4, $s2
    ctx->r13 = SUB32(ctx->r12, ctx->r18);
    // 0x802357D4: mflo        $t6
    ctx->r14 = lo;
    // 0x802357D8: addu        $t8, $s7, $t6
    ctx->r24 = ADD32(ctx->r23, ctx->r14);
    // 0x802357DC: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
L_802357E0:
    // 0x802357E0: beql        $t0, $zero, L_80235858
    if (ctx->r8 == 0) {
        // 0x802357E4: lb          $t8, 0xA3($fp)
        ctx->r24 = MEM_B(ctx->r30, 0XA3);
            goto L_80235858;
    }
    goto skip_3;
    // 0x802357E4: lb          $t8, 0xA3($fp)
    ctx->r24 = MEM_B(ctx->r30, 0XA3);
    skip_3:
    // 0x802357E8: multu       $s1, $s3
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802357EC: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x802357F0: addiu       $t4, $zero, 0x82
    ctx->r12 = ADD32(0, 0X82);
    // 0x802357F4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x802357F8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x802357FC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80235800: addiu       $a3, $a3, 0x558
    ctx->r7 = ADD32(ctx->r7, 0X558);
    // 0x80235804: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x80235808: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x8023580C: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x80235810: mflo        $t9
    ctx->r25 = lo;
    // 0x80235814: addu        $v0, $s7, $t9
    ctx->r2 = ADD32(ctx->r23, ctx->r25);
    // 0x80235818: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8023581C: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x80235820: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80235824: addu        $t3, $t7, $s2
    ctx->r11 = ADD32(ctx->r15, ctx->r18);
    // 0x80235828: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x8023582C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80235830: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80235834: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x80235838: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8023583C: jal         0x8001B204
    // 0x80235840: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x80235840: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_6:
    // 0x80235844: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x80235848: addiu       $a0, $a0, 0x864
    ctx->r4 = ADD32(ctx->r4, 0X864);
    // 0x8023584C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80235850: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80235854: lb          $t8, 0xA3($fp)
    ctx->r24 = MEM_B(ctx->r30, 0XA3);
L_80235858:
    // 0x80235858: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8023585C: sll         $s1, $s1, 24
    ctx->r17 = S32(ctx->r17 << 24);
    // 0x80235860: sra         $s1, $s1, 24
    ctx->r17 = S32(SIGNED(ctx->r17) >> 24);
    // 0x80235864: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80235868: bnel        $at, $zero, L_80235710
    if (ctx->r1 != 0) {
        // 0x8023586C: lw          $t8, 0x0($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X0);
            goto L_80235710;
    }
    goto skip_4;
    // 0x8023586C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    skip_4:
L_80235870:
    // 0x80235870: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80235874:
    // 0x80235874: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80235878: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8023587C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80235880: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80235884: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80235888: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8023588C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80235890: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80235894: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80235898: jr          $ra
    // 0x8023589C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8023589C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802358a0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802358a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802358A0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x802358A4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x802358A8: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x802358AC: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x802358B0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x802358B4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x802358B8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x802358BC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x802358C0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x802358C4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x802358C8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x802358CC: lb          $t6, 0xA4($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XA4);
    // 0x802358D0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x802358D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x802358D8: blez        $t6, L_80235AA4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x802358DC: lui         $fp, 0x801C
        ctx->r30 = S32(0X801C << 16);
            goto L_80235AA4;
    }
    // 0x802358DC: lui         $fp, 0x801C
    ctx->r30 = S32(0X801C << 16);
    // 0x802358E0: lui         $s6, 0x8024
    ctx->r22 = S32(0X8024 << 16);
    // 0x802358E4: lui         $s5, 0x8024
    ctx->r21 = S32(0X8024 << 16);
    // 0x802358E8: lui         $s4, 0x8024
    ctx->r20 = S32(0X8024 << 16);
    // 0x802358EC: addiu       $s4, $s4, 0x86C
    ctx->r20 = ADD32(ctx->r20, 0X86C);
    // 0x802358F0: addiu       $s5, $s5, 0x870
    ctx->r21 = ADD32(ctx->r21, 0X870);
    // 0x802358F4: addiu       $s6, $s6, 0x7E8
    ctx->r22 = ADD32(ctx->r22, 0X7E8);
    // 0x802358F8: addiu       $fp, $fp, -0x4410
    ctx->r30 = ADD32(ctx->r30, -0X4410);
    // 0x802358FC: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
    // 0x80235900: lb          $t7, 0xA5($s3)
    ctx->r15 = MEM_B(ctx->r19, 0XA5);
L_80235904:
    // 0x80235904: bne         $s2, $t7, L_802359D8
    if (ctx->r18 != ctx->r15) {
        // 0x80235908: nop
    
            goto L_802359D8;
    }
    // 0x80235908: nop

    // 0x8023590C: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x80235910: sll         $s1, $s2, 2
    ctx->r17 = S32(ctx->r18 << 2);
    // 0x80235914: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80235918: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x8023591C: jal         0x801451C0
    // 0x80235920: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_0;
    // 0x80235920: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_0:
    // 0x80235924: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x80235928: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8023592C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80235930: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80235934: jal         0x80145310
    // 0x80235938: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_1;
    // 0x80235938: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_1:
    // 0x8023593C: jal         0x80234D2C
    // 0x80235940: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80234D2C)(rdram, ctx);
        goto after_2;
    // 0x80235940: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x80235944: beq         $v0, $zero, L_8023597C
    if (ctx->r2 == 0) {
        // 0x80235948: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8023597C;
    }
    // 0x80235948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8023594C: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80235950: addiu       $t4, $zero, 0x1B
    ctx->r12 = ADD32(0, 0X1B);
    // 0x80235954: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80235958: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x8023595C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80235960: addiu       $t6, $zero, 0x1B
    ctx->r14 = ADD32(0, 0X1B);
    // 0x80235964: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80235968: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8023596C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80235970: lbu         $a2, 0x1030($fp)
    ctx->r6 = MEM_BU(ctx->r30, 0X1030);
    // 0x80235974: jal         0x801453CC
    // 0x80235978: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_3;
    // 0x80235978: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
L_8023597C:
    // 0x8023597C: lb          $t7, 0xA1($s3)
    ctx->r15 = MEM_B(ctx->r19, 0XA1);
    // 0x80235980: blezl       $t7, L_80235A8C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80235984: lb          $t5, 0xA4($s3)
        ctx->r13 = MEM_B(ctx->r19, 0XA4);
            goto L_80235A8C;
    }
    goto skip_0;
    // 0x80235984: lb          $t5, 0xA4($s3)
    ctx->r13 = MEM_B(ctx->r19, 0XA4);
    skip_0:
    // 0x80235988: multu       $s2, $s7
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8023598C: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x80235990: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80235994: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80235998: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8023599C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x802359A0: addiu       $a3, $a3, 0x560
    ctx->r7 = ADD32(ctx->r7, 0X560);
    // 0x802359A4: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x802359A8: mflo        $t8
    ctx->r24 = lo;
    // 0x802359AC: addu        $s0, $s6, $t8
    ctx->r16 = ADD32(ctx->r22, ctx->r24);
    // 0x802359B0: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x802359B4: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x802359B8: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x802359BC: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x802359C0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x802359C4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x802359C8: jal         0x8001B204
    // 0x802359CC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x802359CC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_4:
    // 0x802359D0: b           L_80235A8C
    // 0x802359D4: lb          $t5, 0xA4($s3)
    ctx->r13 = MEM_B(ctx->r19, 0XA4);
        goto L_80235A8C;
    // 0x802359D4: lb          $t5, 0xA4($s3)
    ctx->r13 = MEM_B(ctx->r19, 0XA4);
L_802359D8:
    // 0x802359D8: multu       $s2, $s7
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x802359DC: sll         $t5, $s2, 2
    ctx->r13 = S32(ctx->r18 << 2);
    // 0x802359E0: mflo        $t2
    ctx->r10 = lo;
    // 0x802359E4: addu        $s0, $s6, $t2
    ctx->r16 = ADD32(ctx->r22, ctx->r10);
    // 0x802359E8: lbu         $t3, 0x8($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X8);
    // 0x802359EC: bnel        $t3, $zero, L_80235A18
    if (ctx->r11 != 0) {
        // 0x802359F0: lw          $t7, 0x0($s5)
        ctx->r15 = MEM_W(ctx->r21, 0X0);
            goto L_80235A18;
    }
    goto skip_1;
    // 0x802359F0: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    skip_1:
    // 0x802359F4: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x802359F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x802359FC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80235A00: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80235A04: jal         0x80145310
    // 0x80235A08: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_5;
    // 0x80235A08: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_5:
    // 0x80235A0C: b           L_80235A8C
    // 0x80235A10: lb          $t5, 0xA4($s3)
    ctx->r13 = MEM_B(ctx->r19, 0XA4);
        goto L_80235A8C;
    // 0x80235A10: lb          $t5, 0xA4($s3)
    ctx->r13 = MEM_B(ctx->r19, 0XA4);
    // 0x80235A14: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
L_80235A18:
    // 0x80235A18: sll         $s1, $s2, 2
    ctx->r17 = S32(ctx->r18 << 2);
    // 0x80235A1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80235A20: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80235A24: jal         0x801451C0
    // 0x80235A28: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_6;
    // 0x80235A28: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_6:
    // 0x80235A2C: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80235A30: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80235A34: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80235A38: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x80235A3C: jal         0x80145310
    // 0x80235A40: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_7;
    // 0x80235A40: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_7:
    // 0x80235A44: lb          $t1, 0xA1($s3)
    ctx->r9 = MEM_B(ctx->r19, 0XA1);
    // 0x80235A48: lui         $a3, 0x8024
    ctx->r7 = S32(0X8024 << 16);
    // 0x80235A4C: addiu       $a3, $a3, 0x568
    ctx->r7 = ADD32(ctx->r7, 0X568);
    // 0x80235A50: blez        $t1, L_80235A88
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80235A54: andi        $a0, $s2, 0xFF
        ctx->r4 = ctx->r18 & 0XFF;
            goto L_80235A88;
    }
    // 0x80235A54: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x80235A58: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80235A5C: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80235A60: addiu       $t2, $zero, 0x82
    ctx->r10 = ADD32(0, 0X82);
    // 0x80235A64: addiu       $a1, $a1, 0x3E8
    ctx->r5 = ADD32(ctx->r5, 0X3E8);
    // 0x80235A68: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80235A6C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80235A70: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80235A74: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80235A78: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80235A7C: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x80235A80: jal         0x8001B204
    // 0x80235A84: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_8;
    // 0x80235A84: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_8:
L_80235A88:
    // 0x80235A88: lb          $t5, 0xA4($s3)
    ctx->r13 = MEM_B(ctx->r19, 0XA4);
L_80235A8C:
    // 0x80235A8C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80235A90: sll         $s2, $s2, 24
    ctx->r18 = S32(ctx->r18 << 24);
    // 0x80235A94: sra         $s2, $s2, 24
    ctx->r18 = S32(SIGNED(ctx->r18) >> 24);
    // 0x80235A98: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80235A9C: bnel        $at, $zero, L_80235904
    if (ctx->r1 != 0) {
        // 0x80235AA0: lb          $t7, 0xA5($s3)
        ctx->r15 = MEM_B(ctx->r19, 0XA5);
            goto L_80235904;
    }
    goto skip_2;
    // 0x80235AA0: lb          $t7, 0xA5($s3)
    ctx->r15 = MEM_B(ctx->r19, 0XA5);
    skip_2:
L_80235AA4:
    // 0x80235AA4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80235AA8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80235AAC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80235AB0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80235AB4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80235AB8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80235ABC: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80235AC0: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80235AC4: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80235AC8: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80235ACC: jr          $ra
    // 0x80235AD0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80235AD0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80235ad4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80235ad4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80235AD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80235AD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80235ADC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80235AE0: jal         0x80145310
    // 0x80235AE4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x80235AE4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80235AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80235AEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80235AF0: jr          $ra
    // 0x80235AF4: nop

    return;
    // 0x80235AF4: nop

;}
RECOMP_FUNC void M10_FUN_80235af8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80235AF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80235AFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80235B00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80235B04: jal         0x80145310
    // 0x80235B08: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x80235B08: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80235B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80235B10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80235B14: jr          $ra
    // 0x80235B18: nop

    return;
    // 0x80235B18: nop

;}
RECOMP_FUNC void M10_FUN_80235b1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80235B1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80235B20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80235B24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80235B28: jal         0x80145310
    // 0x80235B2C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    LOOKUP_FUNC(0x80145310)(rdram, ctx);
        goto after_0;
    // 0x80235B2C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_0:
    // 0x80235B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80235B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80235B38: jr          $ra
    // 0x80235B3C: nop

    return;
    // 0x80235B3C: nop

;}
RECOMP_FUNC void M10_FUN_80235b40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80235B40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80235B44: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80235B48: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80235B4C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80235B50: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80235B54: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80235B58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80235B5C: lb          $t6, 0xA4($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XA4);
    // 0x80235B60: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80235B64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80235B68: blez        $t6, L_80235BFC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80235B6C: lui         $s3, 0x8024
        ctx->r19 = S32(0X8024 << 16);
            goto L_80235BFC;
    }
    // 0x80235B6C: lui         $s3, 0x8024
    ctx->r19 = S32(0X8024 << 16);
    // 0x80235B70: lui         $s2, 0x8024
    ctx->r18 = S32(0X8024 << 16);
    // 0x80235B74: addiu       $s2, $s2, 0x870
    ctx->r18 = ADD32(ctx->r18, 0X870);
    // 0x80235B78: addiu       $s3, $s3, 0x86C
    ctx->r19 = ADD32(ctx->r19, 0X86C);
    // 0x80235B7C: lb          $t7, 0xA5($s4)
    ctx->r15 = MEM_B(ctx->r20, 0XA5);
L_80235B80:
    // 0x80235B80: bnel        $s1, $t7, L_80235BBC
    if (ctx->r17 != ctx->r15) {
        // 0x80235B84: lw          $t2, 0x0($s2)
        ctx->r10 = MEM_W(ctx->r18, 0X0);
            goto L_80235BBC;
    }
    goto skip_0;
    // 0x80235B84: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    skip_0:
    // 0x80235B88: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80235B8C: sll         $s0, $s1, 2
    ctx->r16 = S32(ctx->r17 << 2);
    // 0x80235B90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80235B94: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80235B98: jal         0x801451C0
    // 0x80235B9C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_0;
    // 0x80235B9C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_0:
    // 0x80235BA0: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80235BA4: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80235BA8: jal         0x80235AD4
    // 0x80235BAC: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    LOOKUP_FUNC(0x80235AD4)(rdram, ctx);
        goto after_1;
    // 0x80235BAC: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_1:
    // 0x80235BB0: b           L_80235BE4
    // 0x80235BB4: lb          $t6, 0xA4($s4)
    ctx->r14 = MEM_B(ctx->r20, 0XA4);
        goto L_80235BE4;
    // 0x80235BB4: lb          $t6, 0xA4($s4)
    ctx->r14 = MEM_B(ctx->r20, 0XA4);
    // 0x80235BB8: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
L_80235BBC:
    // 0x80235BBC: sll         $s0, $s1, 2
    ctx->r16 = S32(ctx->r17 << 2);
    // 0x80235BC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80235BC4: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80235BC8: jal         0x801451C0
    // 0x80235BCC: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_2;
    // 0x80235BCC: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_2:
    // 0x80235BD0: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x80235BD4: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80235BD8: jal         0x80235AF8
    // 0x80235BDC: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    LOOKUP_FUNC(0x80235AF8)(rdram, ctx);
        goto after_3;
    // 0x80235BDC: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    after_3:
    // 0x80235BE0: lb          $t6, 0xA4($s4)
    ctx->r14 = MEM_B(ctx->r20, 0XA4);
L_80235BE4:
    // 0x80235BE4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80235BE8: sll         $s1, $s1, 24
    ctx->r17 = S32(ctx->r17 << 24);
    // 0x80235BEC: sra         $s1, $s1, 24
    ctx->r17 = S32(SIGNED(ctx->r17) >> 24);
    // 0x80235BF0: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80235BF4: bnel        $at, $zero, L_80235B80
    if (ctx->r1 != 0) {
        // 0x80235BF8: lb          $t7, 0xA5($s4)
        ctx->r15 = MEM_B(ctx->r20, 0XA5);
            goto L_80235B80;
    }
    goto skip_1;
    // 0x80235BF8: lb          $t7, 0xA5($s4)
    ctx->r15 = MEM_B(ctx->r20, 0XA5);
    skip_1:
L_80235BFC:
    // 0x80235BFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80235C00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80235C04: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80235C08: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80235C0C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80235C10: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80235C14: jr          $ra
    // 0x80235C18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80235C18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80235c1c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80235c1c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80235C1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80235C20: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80235C24: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80235C28: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80235C2C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80235C30: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80235C34: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80235C38: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80235C3C: lb          $t6, 0xA4($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XA4);
    // 0x80235C40: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80235C44: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80235C48: blez        $t6, L_80235D24
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80235C4C: lui         $s5, 0x8024
        ctx->r21 = S32(0X8024 << 16);
            goto L_80235D24;
    }
    // 0x80235C4C: lui         $s5, 0x8024
    ctx->r21 = S32(0X8024 << 16);
    // 0x80235C50: lui         $s3, 0x8024
    ctx->r19 = S32(0X8024 << 16);
    // 0x80235C54: lui         $s2, 0x8024
    ctx->r18 = S32(0X8024 << 16);
    // 0x80235C58: addiu       $s2, $s2, 0x870
    ctx->r18 = ADD32(ctx->r18, 0X870);
    // 0x80235C5C: addiu       $s3, $s3, 0x86C
    ctx->r19 = ADD32(ctx->r19, 0X86C);
    // 0x80235C60: addiu       $s5, $s5, 0x7E0
    ctx->r21 = ADD32(ctx->r21, 0X7E0);
    // 0x80235C64: lb          $t7, 0xA5($s4)
    ctx->r15 = MEM_B(ctx->r20, 0XA5);
L_80235C68:
    // 0x80235C68: addu        $t2, $s5, $s1
    ctx->r10 = ADD32(ctx->r21, ctx->r17);
    // 0x80235C6C: bnel        $s1, $t7, L_80235CA8
    if (ctx->r17 != ctx->r15) {
        // 0x80235C70: lbu         $t3, 0x0($t2)
        ctx->r11 = MEM_BU(ctx->r10, 0X0);
            goto L_80235CA8;
    }
    goto skip_0;
    // 0x80235C70: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    skip_0:
    // 0x80235C74: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80235C78: sll         $s0, $s1, 2
    ctx->r16 = S32(ctx->r17 << 2);
    // 0x80235C7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80235C80: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80235C84: jal         0x801451C0
    // 0x80235C88: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_0;
    // 0x80235C88: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_0:
    // 0x80235C8C: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80235C90: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80235C94: jal         0x80235AD4
    // 0x80235C98: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    LOOKUP_FUNC(0x80235AD4)(rdram, ctx);
        goto after_1;
    // 0x80235C98: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_1:
    // 0x80235C9C: b           L_80235D0C
    // 0x80235CA0: lb          $t2, 0xA4($s4)
    ctx->r10 = MEM_B(ctx->r20, 0XA4);
        goto L_80235D0C;
    // 0x80235CA0: lb          $t2, 0xA4($s4)
    ctx->r10 = MEM_B(ctx->r20, 0XA4);
    // 0x80235CA4: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
L_80235CA8:
    // 0x80235CA8: beql        $t3, $zero, L_80235CE4
    if (ctx->r11 == 0) {
        // 0x80235CAC: lw          $t8, 0x0($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X0);
            goto L_80235CE4;
    }
    goto skip_1;
    // 0x80235CAC: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    skip_1:
    // 0x80235CB0: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80235CB4: sll         $s0, $s1, 2
    ctx->r16 = S32(ctx->r17 << 2);
    // 0x80235CB8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80235CBC: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80235CC0: jal         0x801451C0
    // 0x80235CC4: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_2;
    // 0x80235CC4: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    after_2:
    // 0x80235CC8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80235CCC: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80235CD0: jal         0x80235B1C
    // 0x80235CD4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    LOOKUP_FUNC(0x80235B1C)(rdram, ctx);
        goto after_3;
    // 0x80235CD4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_3:
    // 0x80235CD8: b           L_80235D0C
    // 0x80235CDC: lb          $t2, 0xA4($s4)
    ctx->r10 = MEM_B(ctx->r20, 0XA4);
        goto L_80235D0C;
    // 0x80235CDC: lb          $t2, 0xA4($s4)
    ctx->r10 = MEM_B(ctx->r20, 0XA4);
    // 0x80235CE0: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_80235CE4:
    // 0x80235CE4: sll         $s0, $s1, 2
    ctx->r16 = S32(ctx->r17 << 2);
    // 0x80235CE8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80235CEC: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80235CF0: jal         0x801451C0
    // 0x80235CF4: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_4;
    // 0x80235CF4: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_4:
    // 0x80235CF8: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80235CFC: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80235D00: jal         0x80235AF8
    // 0x80235D04: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    LOOKUP_FUNC(0x80235AF8)(rdram, ctx);
        goto after_5;
    // 0x80235D04: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_5:
    // 0x80235D08: lb          $t2, 0xA4($s4)
    ctx->r10 = MEM_B(ctx->r20, 0XA4);
L_80235D0C:
    // 0x80235D0C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80235D10: sll         $s1, $s1, 24
    ctx->r17 = S32(ctx->r17 << 24);
    // 0x80235D14: sra         $s1, $s1, 24
    ctx->r17 = S32(SIGNED(ctx->r17) >> 24);
    // 0x80235D18: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80235D1C: bnel        $at, $zero, L_80235C68
    if (ctx->r1 != 0) {
        // 0x80235D20: lb          $t7, 0xA5($s4)
        ctx->r15 = MEM_B(ctx->r20, 0XA5);
            goto L_80235C68;
    }
    goto skip_2;
    // 0x80235D20: lb          $t7, 0xA5($s4)
    ctx->r15 = MEM_B(ctx->r20, 0XA5);
    skip_2:
L_80235D24:
    // 0x80235D24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80235D28: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80235D2C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80235D30: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80235D34: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80235D38: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80235D3C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80235D40: jr          $ra
    // 0x80235D44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80235D44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80235d48(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80235d48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80235D48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80235D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80235D50: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
    // 0x80235D54: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80235D58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80235D5C: lhu         $v1, 0xC($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XC);
    // 0x80235D60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80235D64: andi        $t6, $v1, 0x800
    ctx->r14 = ctx->r3 & 0X800;
    // 0x80235D68: beq         $t6, $zero, L_80235D88
    if (ctx->r14 == 0) {
        // 0x80235D6C: andi        $t8, $v1, 0x400
        ctx->r24 = ctx->r3 & 0X400;
            goto L_80235D88;
    }
    // 0x80235D6C: andi        $t8, $v1, 0x400
    ctx->r24 = ctx->r3 & 0X400;
    // 0x80235D70: lb          $t7, 0xA5($a0)
    ctx->r15 = MEM_B(ctx->r4, 0XA5);
    // 0x80235D74: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80235D78: blez        $t7, L_80235DB0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80235D7C: nop
    
            goto L_80235DB0;
    }
    // 0x80235D7C: nop

    // 0x80235D80: b           L_80235DB0
    // 0x80235D84: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_80235DB0;
    // 0x80235D84: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80235D88:
    // 0x80235D88: beq         $t8, $zero, L_80235DB0
    if (ctx->r24 == 0) {
        // 0x80235D8C: nop
    
            goto L_80235DB0;
    }
    // 0x80235D8C: nop

    // 0x80235D90: lb          $t0, 0xA4($a1)
    ctx->r8 = MEM_B(ctx->r5, 0XA4);
    // 0x80235D94: lb          $t9, 0xA5($a1)
    ctx->r25 = MEM_B(ctx->r5, 0XA5);
    // 0x80235D98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80235D9C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80235DA0: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80235DA4: beq         $at, $zero, L_80235DB0
    if (ctx->r1 == 0) {
        // 0x80235DA8: nop
    
            goto L_80235DB0;
    }
    // 0x80235DA8: nop

    // 0x80235DAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80235DB0:
    // 0x80235DB0: beq         $a2, $zero, L_80235DD4
    if (ctx->r6 == 0) {
        // 0x80235DB4: addiu       $a0, $zero, 0x300
        ctx->r4 = ADD32(0, 0X300);
            goto L_80235DD4;
    }
    // 0x80235DB4: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x80235DB8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80235DBC: sb          $a2, 0x1A($sp)
    MEM_B(0X1A, ctx->r29) = ctx->r6;
    // 0x80235DC0: jal         0x80020744
    // 0x80235DC4: sb          $a3, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80235DC4: sb          $a3, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r7;
    after_0:
    // 0x80235DC8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80235DCC: lb          $a2, 0x1A($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X1A);
    // 0x80235DD0: lb          $a3, 0x1B($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X1B);
L_80235DD4:
    // 0x80235DD4: lb          $t2, 0xA5($a1)
    ctx->r10 = MEM_B(ctx->r5, 0XA5);
    // 0x80235DD8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80235DDC: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x80235DE0: sb          $t3, 0xA5($a1)
    MEM_B(0XA5, ctx->r5) = ctx->r11;
    // 0x80235DE4: jal         0x802358A0
    // 0x80235DE8: sb          $a3, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x802358A0)(rdram, ctx);
        goto after_1;
    // 0x80235DE8: sb          $a3, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r7;
    after_1:
    // 0x80235DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80235DF0: lb          $v0, 0x1B($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X1B);
    // 0x80235DF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80235DF8: jr          $ra
    // 0x80235DFC: nop

    return;
    // 0x80235DFC: nop

;}
RECOMP_FUNC void M10_FUN_80235e00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80235E00: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80235E04: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80235E08: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x80235E0C: addiu       $v0, $v0, 0x7E8
    ctx->r2 = ADD32(ctx->r2, 0X7E8);
    // 0x80235E10: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80235E14: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
L_80235E18:
    // 0x80235E18: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80235E1C: mflo        $t6
    ctx->r14 = lo;
    // 0x80235E20: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80235E24: lbu         $t8, 0x8($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X8);
    // 0x80235E28: blez        $t8, L_80235E38
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80235E2C: nop
    
            goto L_80235E38;
    }
    // 0x80235E2C: nop

    // 0x80235E30: jr          $ra
    // 0x80235E34: sb          $a1, 0xA5($a0)
    MEM_B(0XA5, ctx->r4) = ctx->r5;
    return;
    // 0x80235E34: sb          $a1, 0xA5($a0)
    MEM_B(0XA5, ctx->r4) = ctx->r5;
L_80235E38:
    // 0x80235E38: blez        $a1, L_80235E4C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80235E3C: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_80235E4C;
    }
    // 0x80235E3C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80235E40: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80235E44: b           L_80235E18
    // 0x80235E48: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
        goto L_80235E18;
    // 0x80235E48: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
L_80235E4C:
    // 0x80235E4C: jr          $ra
    // 0x80235E50: nop

    return;
    // 0x80235E50: nop

;}
RECOMP_FUNC void M10_FUN_80235e54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80235E54: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80235E58: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80235E5C: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x80235E60: addiu       $v0, $v0, 0x7E8
    ctx->r2 = ADD32(ctx->r2, 0X7E8);
    // 0x80235E64: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80235E68: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
L_80235E6C:
    // 0x80235E6C: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80235E70: mflo        $t6
    ctx->r14 = lo;
    // 0x80235E74: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80235E78: lbu         $t8, 0x8($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X8);
    // 0x80235E7C: blezl       $t8, L_80235E90
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80235E80: lb          $t9, 0xA4($a0)
        ctx->r25 = MEM_B(ctx->r4, 0XA4);
            goto L_80235E90;
    }
    goto skip_0;
    // 0x80235E80: lb          $t9, 0xA4($a0)
    ctx->r25 = MEM_B(ctx->r4, 0XA4);
    skip_0:
    // 0x80235E84: jr          $ra
    // 0x80235E88: sb          $a1, 0xA5($a0)
    MEM_B(0XA5, ctx->r4) = ctx->r5;
    return;
    // 0x80235E88: sb          $a1, 0xA5($a0)
    MEM_B(0XA5, ctx->r4) = ctx->r5;
    // 0x80235E8C: lb          $t9, 0xA4($a0)
    ctx->r25 = MEM_B(ctx->r4, 0XA4);
L_80235E90:
    // 0x80235E90: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80235E94: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80235E98: beq         $at, $zero, L_80235EAC
    if (ctx->r1 == 0) {
        // 0x80235E9C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80235EAC;
    }
    // 0x80235E9C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80235EA0: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80235EA4: b           L_80235E6C
    // 0x80235EA8: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
        goto L_80235E6C;
    // 0x80235EA8: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
L_80235EAC:
    // 0x80235EAC: jr          $ra
    // 0x80235EB0: nop

    return;
    // 0x80235EB0: nop

;}
RECOMP_FUNC void M10_FUN_80235eb4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80235EB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80235EB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80235EBC: lw          $t0, 0x94($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X94);
    // 0x80235EC0: sb          $zero, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = 0;
    // 0x80235EC4: lb          $a3, 0xA5($a0)
    ctx->r7 = MEM_B(ctx->r4, 0XA5);
    // 0x80235EC8: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80235ECC: addiu       $a1, $a1, 0x7E8
    ctx->r5 = ADD32(ctx->r5, 0X7E8);
    // 0x80235ED0: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80235ED4: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x80235ED8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80235EDC: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80235EE0: lbu         $t8, 0x8($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X8);
    // 0x80235EE4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80235EE8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80235EEC: bnel        $t8, $zero, L_80235F48
    if (ctx->r24 != 0) {
        // 0x80235EF0: sb          $a3, 0x19($sp)
        MEM_B(0X19, ctx->r29) = ctx->r7;
            goto L_80235F48;
    }
    goto skip_0;
    // 0x80235EF0: sb          $a3, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r7;
    skip_0:
    // 0x80235EF4: lb          $v1, 0xA4($a0)
    ctx->r3 = MEM_B(ctx->r4, 0XA4);
    // 0x80235EF8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80235EFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80235F00: blezl       $v1, L_80235F48
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80235F04: sb          $a3, 0x19($sp)
        MEM_B(0X19, ctx->r29) = ctx->r7;
            goto L_80235F48;
    }
    goto skip_1;
    // 0x80235F04: sb          $a3, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r7;
    skip_1:
L_80235F08:
    // 0x80235F08: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80235F0C: mflo        $t9
    ctx->r25 = lo;
    // 0x80235F10: addu        $t1, $a1, $t9
    ctx->r9 = ADD32(ctx->r5, ctx->r25);
    // 0x80235F14: lbu         $t2, 0x8($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X8);
    // 0x80235F18: blezl       $t2, L_80235F30
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80235F1C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80235F30;
    }
    goto skip_2;
    // 0x80235F1C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x80235F20: sb          $v0, 0xA5($a2)
    MEM_B(0XA5, ctx->r6) = ctx->r2;
    // 0x80235F24: b           L_80235F44
    // 0x80235F28: lb          $a3, 0xA5($a2)
    ctx->r7 = MEM_B(ctx->r6, 0XA5);
        goto L_80235F44;
    // 0x80235F28: lb          $a3, 0xA5($a2)
    ctx->r7 = MEM_B(ctx->r6, 0XA5);
    // 0x80235F2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80235F30:
    // 0x80235F30: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80235F34: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80235F38: bne         $at, $zero, L_80235F08
    if (ctx->r1 != 0) {
        // 0x80235F3C: sb          $v1, 0xA5($a2)
        MEM_B(0XA5, ctx->r6) = ctx->r3;
            goto L_80235F08;
    }
    // 0x80235F3C: sb          $v1, 0xA5($a2)
    MEM_B(0XA5, ctx->r6) = ctx->r3;
    // 0x80235F40: lb          $a3, 0xA5($a2)
    ctx->r7 = MEM_B(ctx->r6, 0XA5);
L_80235F44:
    // 0x80235F44: sb          $a3, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r7;
L_80235F48:
    // 0x80235F48: lhu         $v0, 0xC($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0XC);
    // 0x80235F4C: andi        $t3, $v0, 0x800
    ctx->r11 = ctx->r2 & 0X800;
    // 0x80235F50: beq         $t3, $zero, L_80235F84
    if (ctx->r11 == 0) {
        // 0x80235F54: andi        $t5, $v0, 0x400
        ctx->r13 = ctx->r2 & 0X400;
            goto L_80235F84;
    }
    // 0x80235F54: andi        $t5, $v0, 0x400
    ctx->r13 = ctx->r2 & 0X400;
    // 0x80235F58: blez        $a3, L_80235FC0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80235F5C: sb          $t4, 0x1B($sp)
        MEM_B(0X1B, ctx->r29) = ctx->r12;
            goto L_80235FC0;
    }
    // 0x80235F5C: sb          $t4, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r12;
    // 0x80235F60: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
    // 0x80235F64: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80235F68: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80235F6C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80235F70: jal         0x80235E00
    // 0x80235F74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80235E00)(rdram, ctx);
        goto after_0;
    // 0x80235F74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80235F78: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80235F7C: b           L_80235FC0
    // 0x80235F80: lb          $a3, 0xA5($a2)
    ctx->r7 = MEM_B(ctx->r6, 0XA5);
        goto L_80235FC0;
    // 0x80235F80: lb          $a3, 0xA5($a2)
    ctx->r7 = MEM_B(ctx->r6, 0XA5);
L_80235F84:
    // 0x80235F84: beq         $t5, $zero, L_80235FC0
    if (ctx->r13 == 0) {
        // 0x80235F88: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80235FC0;
    }
    // 0x80235F88: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80235F8C: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    // 0x80235F90: lb          $t7, 0xA4($a2)
    ctx->r15 = MEM_B(ctx->r6, 0XA4);
    // 0x80235F94: addiu       $a1, $a3, 0x1
    ctx->r5 = ADD32(ctx->r7, 0X1);
    // 0x80235F98: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80235F9C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80235FA0: slt         $at, $a3, $t8
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80235FA4: beq         $at, $zero, L_80235FC0
    if (ctx->r1 == 0) {
        // 0x80235FA8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80235FC0;
    }
    // 0x80235FA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80235FAC: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80235FB0: jal         0x80235E54
    // 0x80235FB4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80235E54)(rdram, ctx);
        goto after_1;
    // 0x80235FB4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80235FB8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80235FBC: lb          $a3, 0xA5($a2)
    ctx->r7 = MEM_B(ctx->r6, 0XA5);
L_80235FC0:
    // 0x80235FC0: lb          $t9, 0x19($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X19);
    // 0x80235FC4: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x80235FC8: beq         $t9, $a3, L_80235FDC
    if (ctx->r25 == ctx->r7) {
        // 0x80235FCC: nop
    
            goto L_80235FDC;
    }
    // 0x80235FCC: nop

    // 0x80235FD0: jal         0x80020744
    // 0x80235FD4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x80235FD4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x80235FD8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80235FDC:
    // 0x80235FDC: jal         0x802358A0
    // 0x80235FE0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(0x802358A0)(rdram, ctx);
        goto after_3;
    // 0x80235FE0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80235FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80235FE8: lb          $v0, 0x1B($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X1B);
    // 0x80235FEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80235FF0: jr          $ra
    // 0x80235FF4: nop

    return;
    // 0x80235FF4: nop

;}
RECOMP_FUNC void M10_FUN_80235ff8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80235FF8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80235FFC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80236000: lui         $ra, 0x8024
    ctx->r31 = S32(0X8024 << 16);
    // 0x80236004: addiu       $ra, $ra, 0x874
    ctx->r31 = ADD32(ctx->r31, 0X874);
    // 0x80236008: lw          $t6, 0x0($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X0);
    // 0x8023600C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80236010: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80236014: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80236018: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8023601C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80236020: lw          $v0, 0x30($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X30);
    // 0x80236024: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80236028: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x8023602C: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x80236030: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x80236034: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x80236038: bgez        $t7, L_80236048
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8023603C: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_80236048;
    }
    // 0x8023603C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80236040: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x80236044: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80236048:
    // 0x80236048: addu        $s0, $v1, $t8
    ctx->r16 = ADD32(ctx->r3, ctx->r24);
    // 0x8023604C: addiu       $s0, $s0, -0xA0
    ctx->r16 = ADD32(ctx->r16, -0XA0);
    // 0x80236050: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80236054: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80236058: addiu       $t8, $zero, -0x50
    ctx->r24 = ADD32(0, -0X50);
    // 0x8023605C: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x80236060: bgez        $t6, L_80236070
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80236064: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_80236070;
    }
    // 0x80236064: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80236068: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8023606C: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80236070:
    // 0x80236070: subu        $t6, $t8, $s0
    ctx->r14 = SUB32(ctx->r24, ctx->r16);
    // 0x80236074: div         $zero, $t6, $t5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r13)));
    // 0x80236078: addu        $s1, $t9, $t7
    ctx->r17 = ADD32(ctx->r25, ctx->r15);
    // 0x8023607C: addiu       $s1, $s1, -0x82
    ctx->r17 = ADD32(ctx->r17, -0X82);
    // 0x80236080: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80236084: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80236088: addiu       $t9, $zero, -0x41
    ctx->r25 = ADD32(0, -0X41);
    // 0x8023608C: subu        $t7, $t9, $s1
    ctx->r15 = SUB32(ctx->r25, ctx->r17);
    // 0x80236090: mflo        $a3
    ctx->r7 = lo;
    // 0x80236094: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x80236098: addu        $t8, $v1, $t1
    ctx->r24 = ADD32(ctx->r3, ctx->r9);
    // 0x8023609C: div         $zero, $t7, $t5
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r13)));
    // 0x802360A0: bne         $t5, $zero, L_802360AC
    if (ctx->r13 != 0) {
        // 0x802360A4: nop
    
            goto L_802360AC;
    }
    // 0x802360A4: nop

    // 0x802360A8: break       7
    do_break(2149802152);
L_802360AC:
    // 0x802360AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x802360B0: bne         $t5, $at, L_802360C4
    if (ctx->r13 != ctx->r1) {
        // 0x802360B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_802360C4;
    }
    // 0x802360B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x802360B8: bne         $t6, $at, L_802360C4
    if (ctx->r14 != ctx->r1) {
        // 0x802360BC: nop
    
            goto L_802360C4;
    }
    // 0x802360BC: nop

    // 0x802360C0: break       6
    do_break(2149802176);
L_802360C4:
    // 0x802360C4: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x802360C8: lw          $t6, 0x0($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X0);
    // 0x802360CC: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x802360D0: lw          $t8, 0x878($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X878);
    // 0x802360D4: lw          $t9, 0x30($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X30);
    // 0x802360D8: mflo        $t2
    ctx->r10 = lo;
    // 0x802360DC: lw          $t6, 0x30($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X30);
    // 0x802360E0: addu        $s1, $s1, $t2
    ctx->r17 = ADD32(ctx->r17, ctx->r10);
    // 0x802360E4: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
    // 0x802360E8: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x802360EC: bne         $t5, $zero, L_802360F8
    if (ctx->r13 != 0) {
        // 0x802360F0: nop
    
            goto L_802360F8;
    }
    // 0x802360F0: nop

    // 0x802360F4: break       7
    do_break(2149802228);
L_802360F8:
    // 0x802360F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x802360FC: bne         $t5, $at, L_80236110
    if (ctx->r13 != ctx->r1) {
        // 0x80236100: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80236110;
    }
    // 0x80236100: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80236104: bne         $t7, $at, L_80236110
    if (ctx->r15 != ctx->r1) {
        // 0x80236108: nop
    
            goto L_80236110;
    }
    // 0x80236108: nop

    // 0x8023610C: break       6
    do_break(2149802252);
L_80236110:
    // 0x80236110: lh          $t7, 0x0($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X0);
    // 0x80236114: or          $t4, $t2, $zero
    ctx->r12 = ctx->r10 | 0;
    // 0x80236118: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8023611C: sh          $t7, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r15;
    // 0x80236120: lw          $t9, 0x0($ra)
    ctx->r25 = MEM_W(ctx->r31, 0X0);
    // 0x80236124: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80236128: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8023612C: lw          $v0, 0x30($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X30);
    // 0x80236130: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80236134: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80236138: addu        $t7, $t8, $t2
    ctx->r15 = ADD32(ctx->r24, ctx->r10);
    // 0x8023613C: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x80236140: lw          $t6, 0x0($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X0);
    // 0x80236144: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x80236148: lw          $t7, 0x878($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X878);
    // 0x8023614C: lw          $t9, 0x30($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X30);
    // 0x80236150: lw          $t6, 0x30($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X30);
    // 0x80236154: lh          $t8, 0x2($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X2);
    // 0x80236158: sh          $t8, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r24;
    // 0x8023615C: sh          $t4, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r12;
    // 0x80236160: sh          $t3, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r11;
    // 0x80236164: jal         0x80006088
    // 0x80236168: lw          $a0, 0x878($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X878);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_0;
    // 0x80236168: lw          $a0, 0x878($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X878);
    after_0:
    // 0x8023616C: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x80236170: jal         0x80006088
    // 0x80236174: lw          $a0, 0x874($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X874);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_1;
    // 0x80236174: lw          $a0, 0x874($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X874);
    after_1:
    // 0x80236178: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8023617C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80236180: lh          $t3, 0x32($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X32);
    // 0x80236184: lhu         $t7, 0xAC($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0XAC);
    // 0x80236188: lh          $t4, 0x30($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X30);
    // 0x8023618C: bgez        $t7, L_802361A0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80236190: andi        $t8, $t7, 0x1
        ctx->r24 = ctx->r15 & 0X1;
            goto L_802361A0;
    }
    // 0x80236190: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80236194: beq         $t8, $zero, L_802361A0
    if (ctx->r24 == 0) {
        // 0x80236198: nop
    
            goto L_802361A0;
    }
    // 0x80236198: nop

    // 0x8023619C: addiu       $t8, $t8, -0x2
    ctx->r24 = ADD32(ctx->r24, -0X2);
L_802361A0:
    // 0x802361A0: bne         $t8, $at, L_80236228
    if (ctx->r24 != ctx->r1) {
        // 0x802361A4: nop
    
            goto L_80236228;
    }
    // 0x802361A4: nop

    // 0x802361A8: bgez        $t3, L_802361B8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x802361AC: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_802361B8;
    }
    // 0x802361AC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x802361B0: b           L_802361B8
    // 0x802361B4: negu        $v0, $t3
    ctx->r2 = SUB32(0, ctx->r11);
        goto L_802361B8;
    // 0x802361B4: negu        $v0, $t3
    ctx->r2 = SUB32(0, ctx->r11);
L_802361B8:
    // 0x802361B8: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x802361BC: beq         $at, $zero, L_802361DC
    if (ctx->r1 == 0) {
        // 0x802361C0: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_802361DC;
    }
    // 0x802361C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x802361C4: bgez        $t4, L_802361D4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x802361C8: or          $v0, $t4, $zero
        ctx->r2 = ctx->r12 | 0;
            goto L_802361D4;
    }
    // 0x802361C8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x802361CC: b           L_802361D4
    // 0x802361D0: negu        $v0, $t4
    ctx->r2 = SUB32(0, ctx->r12);
        goto L_802361D4;
    // 0x802361D0: negu        $v0, $t4
    ctx->r2 = SUB32(0, ctx->r12);
L_802361D4:
    // 0x802361D4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x802361D8: bne         $at, $zero, L_80236228
    if (ctx->r1 != 0) {
        // 0x802361DC: sll         $a3, $s0, 16
        ctx->r7 = S32(ctx->r16 << 16);
            goto L_80236228;
    }
L_802361DC:
    // 0x802361DC: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
    // 0x802361E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x802361E4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x802361E8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x802361EC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x802361F0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x802361F4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x802361F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x802361FC: jal         0x8023448C
    // 0x80236200: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_2;
    // 0x80236200: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_2:
    // 0x80236204: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
    // 0x80236208: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8023620C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80236210: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80236214: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80236218: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8023621C: lbu         $a2, 0x4B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X4B);
    // 0x80236220: jal         0x802345B0
    // 0x80236224: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x802345B0)(rdram, ctx);
        goto after_3;
    // 0x80236224: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_3:
L_80236228:
    // 0x80236228: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x8023622C: lw          $t8, 0x87C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X87C);
    // 0x80236230: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    // 0x80236234: beql        $a0, $zero, L_80236248
    if (ctx->r4 == 0) {
        // 0x80236238: sll         $a3, $s0, 16
        ctx->r7 = S32(ctx->r16 << 16);
            goto L_80236248;
    }
    goto skip_0;
    // 0x80236238: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
    skip_0:
    // 0x8023623C: jal         0x80147174
    // 0x80236240: nop

    LOOKUP_FUNC(0x80147174)(rdram, ctx);
        goto after_4;
    // 0x80236240: nop

    after_4:
    // 0x80236244: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
L_80236248:
    // 0x80236248: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8023624C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80236250: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80236254: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80236258: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8023625C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80236260: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80236264: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80236268: jal         0x8023448C
    // 0x8023626C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x8023448C)(rdram, ctx);
        goto after_5;
    // 0x8023626C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_5:
    // 0x80236270: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80236274: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
    // 0x80236278: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8023627C: sw          $v0, 0x874($at)
    MEM_W(0X874, ctx->r1) = ctx->r2;
    // 0x80236280: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80236284: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80236288: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8023628C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80236290: lbu         $a2, 0x4B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X4B);
    // 0x80236294: jal         0x802345B0
    // 0x80236298: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    LOOKUP_FUNC(0x802345B0)(rdram, ctx);
        goto after_6;
    // 0x80236298: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_6:
    // 0x8023629C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x802362A0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x802362A4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x802362A8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x802362AC: sw          $v0, 0x878($at)
    MEM_W(0X878, ctx->r1) = ctx->r2;
    // 0x802362B0: jr          $ra
    // 0x802362B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x802362B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802362b8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802362b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802362B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x802362BC: lbu         $v0, 0xA7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA7);
    // 0x802362C0: addiu       $a2, $sp, 0xC
    ctx->r6 = ADD32(ctx->r29, 0XC);
    // 0x802362C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x802362C8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x802362CC: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
L_802362D0:
    // 0x802362D0: beq         $at, $zero, L_802362E8
    if (ctx->r1 == 0) {
        // 0x802362D4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_802362E8;
    }
    // 0x802362D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x802362D8: addu        $t6, $a2, $v1
    ctx->r14 = ADD32(ctx->r6, ctx->r3);
    // 0x802362DC: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x802362E0: b           L_802362F8
    // 0x802362E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_802362F8;
    // 0x802362E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_802362E8:
    // 0x802362E8: addiu       $v0, $a1, -0x5
    ctx->r2 = ADD32(ctx->r5, -0X5);
    // 0x802362EC: addu        $t7, $a2, $v1
    ctx->r15 = ADD32(ctx->r6, ctx->r3);
    // 0x802362F0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x802362F4: sb          $a3, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r7;
L_802362F8:
    // 0x802362F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x802362FC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80236300: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80236304: bnel        $at, $zero, L_802362D0
    if (ctx->r1 != 0) {
        // 0x80236308: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_802362D0;
    }
    goto skip_0;
    // 0x80236308: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    skip_0:
    // 0x8023630C: lb          $t8, 0xA1($a0)
    ctx->r24 = MEM_B(ctx->r4, 0XA1);
    // 0x80236310: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x80236314: lbu         $v0, 0x0($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X0);
    // 0x80236318: jr          $ra
    // 0x8023631C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8023631C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80236320(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80236320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236320: lw          $v0, 0x98($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X98);
    // 0x80236324: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x80236328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8023632C: slti        $at, $t6, 0xC8
    ctx->r1 = SIGNED(ctx->r14) < 0XC8 ? 1 : 0;
    // 0x80236330: bne         $at, $zero, L_80236340
    if (ctx->r1 != 0) {
            // 0x80236334: nop

    LOOKUP_FUNC(0x80236340)(rdram, ctx);
    return;
    }
    // 0x80236334: nop

    // 0x80236338: jr          $ra
    // 0x8023633C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8023633C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80236340(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80236340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236340: jr          $ra
    // 0x80236344: nop

    return;
    // 0x80236344: nop

;}
RECOMP_FUNC void M10_FUN_80236348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236348: lw          $v0, 0x98($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X98);
    // 0x8023634C: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x80236350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80236354: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80236358: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x8023635C: beq         $t8, $zero, L_8023636C
    if (ctx->r24 == 0) {
            // 0x80236360: nop

    LOOKUP_FUNC(0x8023636C)(rdram, ctx);
    return;
    }
    // 0x80236360: nop

    // 0x80236364: jr          $ra
    // 0x80236368: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80236368: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023636c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023636c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023636C: jr          $ra
    // 0x80236370: nop

    return;
    // 0x80236370: nop

;}
RECOMP_FUNC void M10_FUN_80236374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236374: lw          $v0, 0x98($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X98);
    // 0x80236378: lw          $t6, 0x38($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X38);
    // 0x8023637C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80236380: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80236384: beq         $t7, $zero, L_80236394
    if (ctx->r15 == 0) {
            // 0x80236388: nop

    LOOKUP_FUNC(0x80236394)(rdram, ctx);
    return;
    }
    // 0x80236388: nop

    // 0x8023638C: jr          $ra
    // 0x80236390: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80236390: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80236394(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80236394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236394: jr          $ra
    // 0x80236398: nop

    return;
    // 0x80236398: nop

;}
RECOMP_FUNC void M10_FUN_8023639c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023639C: lw          $v0, 0x9C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X9C);
    // 0x802363A0: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x802363A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x802363A8: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x802363AC: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x802363B0: beq         $t8, $zero, L_802363C0
    if (ctx->r24 == 0) {
            // 0x802363B4: nop

    LOOKUP_FUNC(0x802363C0)(rdram, ctx);
    return;
    }
    // 0x802363B4: nop

    // 0x802363B8: jr          $ra
    // 0x802363BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x802363BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_802363c0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_802363c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802363C0: jr          $ra
    // 0x802363C4: nop

    return;
    // 0x802363C4: nop

;}
RECOMP_FUNC void M10_FUN_802363c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802363C8: jr          $ra
    // 0x802363CC: nop

    return;
    // 0x802363CC: nop

;}
RECOMP_FUNC void M10_FUN_802363d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802363D0: jr          $ra
    // 0x802363D4: nop

    return;
    // 0x802363D4: nop

;}
RECOMP_FUNC void M10_FUN_802363d8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802363D8: lui         $v1, 0x8024
    ctx->r3 = S32(0X8024 << 16);
    // 0x802363DC: addiu       $v1, $v1, -0x1C60
    ctx->r3 = ADD32(ctx->r3, -0X1C60);
    // 0x802363E0: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x802363E4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x802363E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x802363EC: beql        $t6, $zero, L_80236400
    if (ctx->r14 == 0) {
        // 0x802363F0: sb          $t7, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r15;
            goto L_80236400;
    }
    goto skip_0;
    // 0x802363F0: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    skip_0:
    // 0x802363F4: jr          $ra
    // 0x802363F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x802363F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x802363FC: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_80236400:
    // 0x80236400: jr          $ra
    // 0x80236404: nop

    return;
    // 0x80236404: nop

;}
RECOMP_FUNC void M10_FUN_80236408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236408: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8023640C: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80236410: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80236414: addiu       $t6, $t6, -0x1B18
    ctx->r14 = ADD32(ctx->r14, -0X1B18);
    // 0x80236418: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x8023641C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80236420: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80236424: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x80236428: sb          $t9, 0xA3($a0)
    MEM_B(0XA3, ctx->r4) = ctx->r25;
    // 0x8023642C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80236430: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80236434: jal         0x80234ED4
    // 0x80236438: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80234ED4)(rdram, ctx);
        goto after_0;
    // 0x80236438: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8023643C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80236440: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80236444: jr          $ra
    // 0x80236448: nop

    return;
    // 0x80236448: nop

;}
RECOMP_FUNC void M10_FUN_8023644c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023644C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80236450: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80236454: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80236458: addiu       $t6, $t6, -0x1B14
    ctx->r14 = ADD32(ctx->r14, -0X1B14);
    // 0x8023645C: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x80236460: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80236464: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80236468: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x8023646C: sb          $t9, 0xA3($a0)
    MEM_B(0XA3, ctx->r4) = ctx->r25;
    // 0x80236470: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80236474: jal         0x80234ED4
    // 0x80236478: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80234ED4)(rdram, ctx);
        goto after_0;
    // 0x80236478: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8023647C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80236480: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80236484: jr          $ra
    // 0x80236488: nop

    return;
    // 0x80236488: nop

;}
RECOMP_FUNC void M10_FUN_8023648c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023648C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80236490: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80236494: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80236498: addiu       $t6, $t6, -0x1B10
    ctx->r14 = ADD32(ctx->r14, -0X1B10);
    // 0x8023649C: lwr         $t8, 0x2($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X2);
    // 0x802364A0: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x802364A4: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x802364A8: swr         $t8, 0x2($a2)
    do_swr(rdram, 0X2, ctx->r6, ctx->r24);
    // 0x802364AC: lbu         $t9, -0x1C54($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1C54);
    // 0x802364B0: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x802364B4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x802364B8: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x802364BC: bne         $at, $zero, L_802364CC
    if (ctx->r1 != 0) {
        // 0x802364C0: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_802364CC;
    }
    // 0x802364C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x802364C4: b           L_802364D0
    // 0x802364C8: sb          $t0, 0xA3($a0)
    MEM_B(0XA3, ctx->r4) = ctx->r8;
        goto L_802364D0;
    // 0x802364C8: sb          $t0, 0xA3($a0)
    MEM_B(0XA3, ctx->r4) = ctx->r8;
L_802364CC:
    // 0x802364CC: sb          $t1, 0xA3($a0)
    MEM_B(0XA3, ctx->r4) = ctx->r9;
L_802364D0:
    // 0x802364D0: jal         0x80234ED4
    // 0x802364D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    LOOKUP_FUNC(0x80234ED4)(rdram, ctx);
        goto after_0;
    // 0x802364D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x802364D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802364DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x802364E0: jr          $ra
    // 0x802364E4: nop

    return;
    // 0x802364E4: nop

;}
RECOMP_FUNC void M10_FUN_802364e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802364E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x802364EC: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x802364F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x802364F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x802364F8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x802364FC: addiu       $t7, $t7, -0x1B0C
    ctx->r15 = ADD32(ctx->r15, -0X1B0C);
    // 0x80236500: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80236504: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x80236508: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8023650C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80236510: lbu         $t9, 0x4($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X4);
    // 0x80236514: jal         0x80236374
    // 0x80236518: sb          $t9, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r25;
    LOOKUP_FUNC(0x80236374)(rdram, ctx);
        goto after_0;
    // 0x80236518: sb          $t9, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r25;
    after_0:
    // 0x8023651C: beq         $v0, $zero, L_80236548
    if (ctx->r2 == 0) {
        // 0x80236520: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_80236548;
    }
    // 0x80236520: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80236524: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80236528: sb          $t0, 0xA3($s0)
    MEM_B(0XA3, ctx->r16) = ctx->r8;
    // 0x8023652C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80236530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80236534: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80236538: jal         0x80234ED4
    // 0x8023653C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80234ED4)(rdram, ctx);
        goto after_1;
    // 0x8023653C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80236540: b           L_802365D0
    // 0x80236544: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802365D0;
    // 0x80236544: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80236548:
    // 0x80236548: jal         0x8023639C
    // 0x8023654C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8023639C)(rdram, ctx);
        goto after_2;
    // 0x8023654C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80236550: beq         $v0, $zero, L_8023657C
    if (ctx->r2 == 0) {
        // 0x80236554: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_8023657C;
    }
    // 0x80236554: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80236558: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8023655C: sb          $t1, 0xA3($s0)
    MEM_B(0XA3, ctx->r16) = ctx->r9;
    // 0x80236560: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80236564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80236568: addiu       $a2, $sp, 0x2B
    ctx->r6 = ADD32(ctx->r29, 0X2B);
    // 0x8023656C: jal         0x80234ED4
    // 0x80236570: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80234ED4)(rdram, ctx);
        goto after_3;
    // 0x80236570: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80236574: b           L_802365D0
    // 0x80236578: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802365D0;
    // 0x80236578: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8023657C:
    // 0x8023657C: jal         0x80236320
    // 0x80236580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80236320)(rdram, ctx);
        goto after_4;
    // 0x80236580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80236584: beq         $v0, $zero, L_802365B0
    if (ctx->r2 == 0) {
        // 0x80236588: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_802365B0;
    }
    // 0x80236588: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8023658C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80236590: sb          $t2, 0xA3($s0)
    MEM_B(0XA3, ctx->r16) = ctx->r10;
    // 0x80236594: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80236598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8023659C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x802365A0: jal         0x80234ED4
    // 0x802365A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80234ED4)(rdram, ctx);
        goto after_5;
    // 0x802365A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x802365A8: b           L_802365D0
    // 0x802365AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_802365D0;
    // 0x802365AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_802365B0:
    // 0x802365B0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x802365B4: sb          $t3, 0xA3($s0)
    MEM_B(0XA3, ctx->r16) = ctx->r11;
    // 0x802365B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x802365BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x802365C0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x802365C4: jal         0x80234ED4
    // 0x802365C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80234ED4)(rdram, ctx);
        goto after_6;
    // 0x802365C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x802365CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_802365D0:
    // 0x802365D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x802365D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x802365D8: jr          $ra
    // 0x802365DC: nop

    return;
    // 0x802365DC: nop

;}
RECOMP_FUNC void M10_FUN_802365e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802365E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802365E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802365E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x802365EC: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x802365F0: addiu       $v0, $v0, -0x3290
    ctx->r2 = ADD32(ctx->r2, -0X3290);
    // 0x802365F4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x802365F8: sb          $t6, 0xAA($a0)
    MEM_B(0XAA, ctx->r4) = ctx->r14;
    // 0x802365FC: sw          $v0, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r2;
    // 0x80236600: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80236604: sb          $t7, 0xA7($a0)
    MEM_B(0XA7, ctx->r4) = ctx->r15;
    // 0x80236608: jal         0x802362B8
    // 0x8023660C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x802362B8)(rdram, ctx);
        goto after_0;
    // 0x8023660C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80236610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80236614: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80236618: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8023661C: sb          $v0, 0xA3($a0)
    MEM_B(0XA3, ctx->r4) = ctx->r2;
    // 0x80236620: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80236624: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80236628: jal         0x80234ED4
    // 0x8023662C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80234ED4)(rdram, ctx);
        goto after_1;
    // 0x8023662C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80236630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80236634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80236638: jr          $ra
    // 0x8023663C: nop

    return;
    // 0x8023663C: nop

;}
RECOMP_FUNC void M10_FUN_80236640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236640: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80236644: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80236648: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8023664C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80236650: addiu       $v0, $v0, -0x31E8
    ctx->r2 = ADD32(ctx->r2, -0X31E8);
    // 0x80236654: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80236658: sb          $t6, 0xAA($a0)
    MEM_B(0XAA, ctx->r4) = ctx->r14;
    // 0x8023665C: sw          $v0, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r2;
    // 0x80236660: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80236664: sb          $t7, 0xA7($a0)
    MEM_B(0XA7, ctx->r4) = ctx->r15;
    // 0x80236668: jal         0x802362B8
    // 0x8023666C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x802362B8)(rdram, ctx);
        goto after_0;
    // 0x8023666C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80236670: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80236674: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80236678: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8023667C: sb          $v0, 0xA3($a0)
    MEM_B(0XA3, ctx->r4) = ctx->r2;
    // 0x80236680: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80236684: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80236688: jal         0x80234ED4
    // 0x8023668C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80234ED4)(rdram, ctx);
        goto after_1;
    // 0x8023668C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80236690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80236694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80236698: jr          $ra
    // 0x8023669C: nop

    return;
    // 0x8023669C: nop

;}
RECOMP_FUNC void M10_FUN_802366a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x802366A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x802366A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x802366A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x802366AC: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x802366B0: addiu       $v0, $v0, -0x3140
    ctx->r2 = ADD32(ctx->r2, -0X3140);
    // 0x802366B4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x802366B8: sb          $t6, 0xAA($a0)
    MEM_B(0XAA, ctx->r4) = ctx->r14;
    // 0x802366BC: sw          $v0, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r2;
    // 0x802366C0: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x802366C4: sb          $t7, 0xA7($a0)
    MEM_B(0XA7, ctx->r4) = ctx->r15;
    // 0x802366C8: jal         0x802362B8
    // 0x802366CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x802362B8)(rdram, ctx);
        goto after_0;
    // 0x802366CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x802366D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x802366D4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x802366D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x802366DC: sb          $v0, 0xA3($a0)
    MEM_B(0XA3, ctx->r4) = ctx->r2;
    // 0x802366E0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x802366E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x802366E8: jal         0x80234ED4
    // 0x802366EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80234ED4)(rdram, ctx);
        goto after_1;
    // 0x802366EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x802366F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x802366F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x802366F8: jr          $ra
    // 0x802366FC: nop

    return;
    // 0x802366FC: nop

;}
RECOMP_FUNC void M10_FUN_80236700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236700: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80236704: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80236708: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8023670C: addiu       $t6, $t6, -0x1B04
    ctx->r14 = ADD32(ctx->r14, -0X1B04);
    // 0x80236710: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x80236714: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80236718: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8023671C: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x80236720: sb          $zero, 0xA1($a0)
    MEM_B(0XA1, ctx->r4) = 0;
    // 0x80236724: sb          $t9, 0xA3($a0)
    MEM_B(0XA3, ctx->r4) = ctx->r25;
    // 0x80236728: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8023672C: jal         0x80234ED4
    // 0x80236730: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80234ED4)(rdram, ctx);
        goto after_0;
    // 0x80236730: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80236734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80236738: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8023673C: jr          $ra
    // 0x80236740: nop

    return;
    // 0x80236740: nop

;}
RECOMP_FUNC void M10_FUN_80236744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236744: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80236748: lw          $t6, -0x1C44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1C44);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_8023674c(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_8023674c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8023674C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80236750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80236754: bne         $t6, $zero, L_80236778
    if (ctx->r14 != 0) {
        // 0x80236758: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80236778;
    }
    // 0x80236758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8023675C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x80236760: jal         0x80005670
    // 0x80236764: addiu       $a1, $a1, -0x1C28
    ctx->r5 = ADD32(ctx->r5, -0X1C28);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x80236764: addiu       $a1, $a1, -0x1C28
    ctx->r5 = ADD32(ctx->r5, -0X1C28);
    after_0:
    // 0x80236768: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8023676C: sw          $v0, -0x1C44($at)
    MEM_W(-0X1C44, ctx->r1) = ctx->r2;
    // 0x80236770: b           L_80236778
    // 0x80236774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80236778;
    // 0x80236774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80236778:
    // 0x80236778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8023677C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80236780: jr          $ra
    // 0x80236784: nop

    return;
    // 0x80236784: nop

;}
RECOMP_FUNC void M10_FUN_80236788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236788: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x8023678C: lw          $a0, -0x1C48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1C48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80236790(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80236790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236790: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80236794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80236798: beql        $a0, $zero, L_80236A2C
    if (ctx->r4 == 0) {
        // 0x8023679C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80236A2C;
    }
    goto skip_0;
    // 0x8023679C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x802367A0: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x802367A4: lui         $t6, 0x8023
    ctx->r14 = S32(0X8023 << 16);
    // 0x802367A8: addiu       $t6, $t6, 0x7250
    ctx->r14 = ADD32(ctx->r14, 0X7250);
    // 0x802367AC: bne         $t6, $v1, L_802367BC
    if (ctx->r14 != ctx->r3) {
        // 0x802367B0: lw          $a2, 0x98($a0)
        ctx->r6 = MEM_W(ctx->r4, 0X98);
            goto L_802367BC;
    }
    // 0x802367B0: lw          $a2, 0x98($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X98);
    // 0x802367B4: b           L_80236A2C
    // 0x802367B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80236A2C;
    // 0x802367B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_802367BC:
    // 0x802367BC: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x802367C0: lbu         $t7, -0x1C58($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1C58);
    // 0x802367C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x802367C8: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x802367CC: bne         $a1, $t7, L_802367DC
    if (ctx->r5 != ctx->r15) {
        // 0x802367D0: addiu       $t8, $t8, -0x71A0
        ctx->r24 = ADD32(ctx->r24, -0X71A0);
            goto L_802367DC;
    }
    // 0x802367D0: addiu       $t8, $t8, -0x71A0
    ctx->r24 = ADD32(ctx->r24, -0X71A0);
    // 0x802367D4: b           L_80236A2C
    // 0x802367D8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_80236A2C;
    // 0x802367D8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_802367DC:
    // 0x802367DC: beq         $t8, $v1, L_802367F0
    if (ctx->r24 == ctx->r3) {
        // 0x802367E0: lui         $t9, 0x8024
        ctx->r25 = S32(0X8024 << 16);
            goto L_802367F0;
    }
    // 0x802367E0: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x802367E4: addiu       $t9, $t9, -0x76D8
    ctx->r25 = ADD32(ctx->r25, -0X76D8);
    // 0x802367E8: bnel        $t9, $v1, L_802368C0
    if (ctx->r25 != ctx->r3) {
        // 0x802367EC: lw          $v1, 0x1C($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1C);
            goto L_802368C0;
    }
    goto skip_1;
    // 0x802367EC: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    skip_1:
L_802367F0:
    // 0x802367F0: lb          $t0, 0xA2($a0)
    ctx->r8 = MEM_B(ctx->r4, 0XA2);
    // 0x802367F4: bne         $t0, $zero, L_80236804
    if (ctx->r8 != 0) {
        // 0x802367F8: nop
    
            goto L_80236804;
    }
    // 0x802367F8: nop

    // 0x802367FC: b           L_80236A2C
    // 0x80236800: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_80236A2C;
    // 0x80236800: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80236804:
    // 0x80236804: jal         0x80236348
    // 0x80236808: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80236348)(rdram, ctx);
        goto after_0;
    // 0x80236808: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8023680C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80236810: beq         $v0, $zero, L_80236844
    if (ctx->r2 == 0) {
        // 0x80236814: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_80236844;
    }
    // 0x80236814: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80236818: lui         $t1, 0x8024
    ctx->r9 = S32(0X8024 << 16);
    // 0x8023681C: lw          $t1, -0x1C48($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X1C48);
    // 0x80236820: lb          $v0, 0xA5($t1)
    ctx->r2 = MEM_B(ctx->r9, 0XA5);
    // 0x80236824: bne         $v0, $zero, L_80236834
    if (ctx->r2 != 0) {
        // 0x80236828: nop
    
            goto L_80236834;
    }
    // 0x80236828: nop

    // 0x8023682C: b           L_80236A2C
    // 0x80236830: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_80236A2C;
    // 0x80236830: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_80236834:
    // 0x80236834: bnel        $a1, $v0, L_80236848
    if (ctx->r5 != ctx->r2) {
        // 0x80236838: lw          $t2, 0x38($a2)
        ctx->r10 = MEM_W(ctx->r6, 0X38);
            goto L_80236848;
    }
    goto skip_2;
    // 0x80236838: lw          $t2, 0x38($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X38);
    skip_2:
    // 0x8023683C: b           L_80236A2C
    // 0x80236840: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_80236A2C;
    // 0x80236840: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_80236844:
    // 0x80236844: lw          $t2, 0x38($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X38);
L_80236848:
    // 0x80236848: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x8023684C: lw          $a0, -0x1C48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1C48);
    // 0x80236850: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x80236854: beq         $t3, $zero, L_8023688C
    if (ctx->r11 == 0) {
        // 0x80236858: lb          $v0, 0xA5($a0)
        ctx->r2 = MEM_B(ctx->r4, 0XA5);
            goto L_8023688C;
    }
    // 0x80236858: lb          $v0, 0xA5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XA5);
    // 0x8023685C: bne         $v0, $zero, L_8023686C
    if (ctx->r2 != 0) {
        // 0x80236860: nop
    
            goto L_8023686C;
    }
    // 0x80236860: nop

    // 0x80236864: b           L_80236A2C
    // 0x80236868: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_80236A2C;
    // 0x80236868: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_8023686C:
    // 0x8023686C: bne         $a1, $v0, L_8023687C
    if (ctx->r5 != ctx->r2) {
        // 0x80236870: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8023687C;
    }
    // 0x80236870: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80236874: b           L_80236A2C
    // 0x80236878: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_80236A2C;
    // 0x80236878: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_8023687C:
    // 0x8023687C: bne         $v0, $at, L_8023688C
    if (ctx->r2 != ctx->r1) {
        // 0x80236880: nop
    
            goto L_8023688C;
    }
    // 0x80236880: nop

    // 0x80236884: b           L_80236A2C
    // 0x80236888: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_80236A2C;
    // 0x80236888: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_8023688C:
    // 0x8023688C: bne         $v0, $zero, L_8023689C
    if (ctx->r2 != 0) {
        // 0x80236890: nop
    
            goto L_8023689C;
    }
    // 0x80236890: nop

    // 0x80236894: b           L_80236A2C
    // 0x80236898: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_80236A2C;
    // 0x80236898: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_8023689C:
    // 0x8023689C: bne         $a1, $v0, L_802368AC
    if (ctx->r5 != ctx->r2) {
        // 0x802368A0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_802368AC;
    }
    // 0x802368A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x802368A4: b           L_80236A2C
    // 0x802368A8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_80236A2C;
    // 0x802368A8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_802368AC:
    // 0x802368AC: bnel        $v0, $at, L_802368C0
    if (ctx->r2 != ctx->r1) {
        // 0x802368B0: lw          $v1, 0x1C($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1C);
            goto L_802368C0;
    }
    goto skip_3;
    // 0x802368B0: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    skip_3:
    // 0x802368B4: b           L_80236A2C
    // 0x802368B8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_80236A2C;
    // 0x802368B8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x802368BC: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
L_802368C0:
    // 0x802368C0: lui         $t4, 0x8023
    ctx->r12 = S32(0X8023 << 16);
    // 0x802368C4: addiu       $t4, $t4, 0x748C
    ctx->r12 = ADD32(ctx->r12, 0X748C);
    // 0x802368C8: bne         $t4, $v1, L_802368F4
    if (ctx->r12 != ctx->r3) {
        // 0x802368CC: lui         $t5, 0x8023
        ctx->r13 = S32(0X8023 << 16);
            goto L_802368F4;
    }
    // 0x802368CC: lui         $t5, 0x8023
    ctx->r13 = S32(0X8023 << 16);
    // 0x802368D0: lb          $v0, 0xA5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XA5);
    // 0x802368D4: bne         $v0, $zero, L_802368E4
    if (ctx->r2 != 0) {
        // 0x802368D8: nop
    
            goto L_802368E4;
    }
    // 0x802368D8: nop

    // 0x802368DC: b           L_80236A2C
    // 0x802368E0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_80236A2C;
    // 0x802368E0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_802368E4:
    // 0x802368E4: bne         $a1, $v0, L_802368F4
    if (ctx->r5 != ctx->r2) {
        // 0x802368E8: nop
    
            goto L_802368F4;
    }
    // 0x802368E8: nop

    // 0x802368EC: b           L_80236A2C
    // 0x802368F0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80236A2C;
    // 0x802368F0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_802368F4:
    // 0x802368F4: addiu       $t5, $t5, 0x78DC
    ctx->r13 = ADD32(ctx->r13, 0X78DC);
    // 0x802368F8: bnel        $t5, $v1, L_80236994
    if (ctx->r13 != ctx->r3) {
        // 0x802368FC: lw          $v1, 0x1C($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1C);
            goto L_80236994;
    }
    goto skip_4;
    // 0x802368FC: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    skip_4:
    // 0x80236900: jal         0x80236374
    // 0x80236904: nop

    LOOKUP_FUNC(0x80236374)(rdram, ctx);
        goto after_1;
    // 0x80236904: nop

    after_1:
    // 0x80236908: beq         $v0, $zero, L_80236918
    if (ctx->r2 == 0) {
        // 0x8023690C: lui         $a0, 0x8024
        ctx->r4 = S32(0X8024 << 16);
            goto L_80236918;
    }
    // 0x8023690C: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x80236910: b           L_80236A2C
    // 0x80236914: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80236A2C;
    // 0x80236914: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80236918:
    // 0x80236918: jal         0x8023639C
    // 0x8023691C: lw          $a0, -0x1C48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1C48);
    LOOKUP_FUNC(0x8023639C)(rdram, ctx);
        goto after_2;
    // 0x8023691C: lw          $a0, -0x1C48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1C48);
    after_2:
    // 0x80236920: beq         $v0, $zero, L_80236954
    if (ctx->r2 == 0) {
        // 0x80236924: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80236954;
    }
    // 0x80236924: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80236928: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x8023692C: lw          $t6, -0x1C48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1C48);
    // 0x80236930: lb          $v0, 0xA5($t6)
    ctx->r2 = MEM_B(ctx->r14, 0XA5);
    // 0x80236934: bne         $v0, $zero, L_80236944
    if (ctx->r2 != 0) {
        // 0x80236938: nop
    
            goto L_80236944;
    }
    // 0x80236938: nop

    // 0x8023693C: b           L_80236A2C
    // 0x80236940: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80236A2C;
    // 0x80236940: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80236944:
    // 0x80236944: bne         $a1, $v0, L_80236954
    if (ctx->r5 != ctx->r2) {
        // 0x80236948: nop
    
            goto L_80236954;
    }
    // 0x80236948: nop

    // 0x8023694C: b           L_80236A2C
    // 0x80236950: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80236A2C;
    // 0x80236950: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80236954:
    // 0x80236954: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x80236958: lw          $a0, -0x1C48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1C48);
    // 0x8023695C: lb          $v0, 0xA5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XA5);
    // 0x80236960: bne         $v0, $zero, L_80236970
    if (ctx->r2 != 0) {
        // 0x80236964: nop
    
            goto L_80236970;
    }
    // 0x80236964: nop

    // 0x80236968: b           L_80236A2C
    // 0x8023696C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80236A2C;
    // 0x8023696C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80236970:
    // 0x80236970: bne         $a1, $v0, L_80236980
    if (ctx->r5 != ctx->r2) {
        // 0x80236974: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80236980;
    }
    // 0x80236974: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80236978: b           L_80236A2C
    // 0x8023697C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80236A2C;
    // 0x8023697C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80236980:
    // 0x80236980: bnel        $v0, $at, L_80236994
    if (ctx->r2 != ctx->r1) {
        // 0x80236984: lw          $v1, 0x1C($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1C);
            goto L_80236994;
    }
    goto skip_5;
    // 0x80236984: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    skip_5:
    // 0x80236988: b           L_80236A2C
    // 0x8023698C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80236A2C;
    // 0x8023698C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80236990: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
L_80236994:
    // 0x80236994: lui         $t7, 0x8023
    ctx->r15 = S32(0X8023 << 16);
    // 0x80236998: addiu       $t7, $t7, 0x7B7C
    ctx->r15 = ADD32(ctx->r15, 0X7B7C);
    // 0x8023699C: bne         $t7, $v1, L_802369AC
    if (ctx->r15 != ctx->r3) {
        // 0x802369A0: lui         $t8, 0x8023
        ctx->r24 = S32(0X8023 << 16);
            goto L_802369AC;
    }
    // 0x802369A0: lui         $t8, 0x8023
    ctx->r24 = S32(0X8023 << 16);
    // 0x802369A4: b           L_80236A2C
    // 0x802369A8: lbu         $v0, 0xAA($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XAA);
        goto L_80236A2C;
    // 0x802369A8: lbu         $v0, 0xAA($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XAA);
L_802369AC:
    // 0x802369AC: addiu       $t8, $t8, 0x7EC8
    ctx->r24 = ADD32(ctx->r24, 0X7EC8);
    // 0x802369B0: bne         $t8, $v1, L_802369DC
    if (ctx->r24 != ctx->r3) {
        // 0x802369B4: lui         $t9, 0x8024
        ctx->r25 = S32(0X8024 << 16);
            goto L_802369DC;
    }
    // 0x802369B4: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x802369B8: lb          $v0, 0xA5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XA5);
    // 0x802369BC: bne         $v0, $zero, L_802369CC
    if (ctx->r2 != 0) {
        // 0x802369C0: nop
    
            goto L_802369CC;
    }
    // 0x802369C0: nop

    // 0x802369C4: b           L_80236A2C
    // 0x802369C8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_80236A2C;
    // 0x802369C8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_802369CC:
    // 0x802369CC: bne         $a1, $v0, L_802369DC
    if (ctx->r5 != ctx->r2) {
        // 0x802369D0: nop
    
            goto L_802369DC;
    }
    // 0x802369D0: nop

    // 0x802369D4: b           L_80236A2C
    // 0x802369D8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_80236A2C;
    // 0x802369D8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_802369DC:
    // 0x802369DC: addiu       $t9, $t9, -0x7F14
    ctx->r25 = ADD32(ctx->r25, -0X7F14);
    // 0x802369E0: bne         $t9, $v1, L_802369F0
    if (ctx->r25 != ctx->r3) {
        // 0x802369E4: lui         $t0, 0x8024
        ctx->r8 = S32(0X8024 << 16);
            goto L_802369F0;
    }
    // 0x802369E4: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x802369E8: b           L_80236A2C
    // 0x802369EC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_80236A2C;
    // 0x802369EC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_802369F0:
    // 0x802369F0: addiu       $t0, $t0, -0x6858
    ctx->r8 = ADD32(ctx->r8, -0X6858);
    // 0x802369F4: beq         $t0, $v1, L_80236A20
    if (ctx->r8 == ctx->r3) {
        // 0x802369F8: lui         $t1, 0x8024
        ctx->r9 = S32(0X8024 << 16);
            goto L_80236A20;
    }
    // 0x802369F8: lui         $t1, 0x8024
    ctx->r9 = S32(0X8024 << 16);
    // 0x802369FC: addiu       $t1, $t1, -0x6704
    ctx->r9 = ADD32(ctx->r9, -0X6704);
    // 0x80236A00: beq         $t1, $v1, L_80236A20
    if (ctx->r9 == ctx->r3) {
        // 0x80236A04: lui         $t2, 0x8024
        ctx->r10 = S32(0X8024 << 16);
            goto L_80236A20;
    }
    // 0x80236A04: lui         $t2, 0x8024
    ctx->r10 = S32(0X8024 << 16);
    // 0x80236A08: addiu       $t2, $t2, -0x6FB8
    ctx->r10 = ADD32(ctx->r10, -0X6FB8);
    // 0x80236A0C: beq         $t2, $v1, L_80236A20
    if (ctx->r10 == ctx->r3) {
        // 0x80236A10: lui         $t3, 0x8024
        ctx->r11 = S32(0X8024 << 16);
            goto L_80236A20;
    }
    // 0x80236A10: lui         $t3, 0x8024
    ctx->r11 = S32(0X8024 << 16);
    // 0x80236A14: addiu       $t3, $t3, -0x6C08
    ctx->r11 = ADD32(ctx->r11, -0X6C08);
    // 0x80236A18: bnel        $t3, $v1, L_80236A2C
    if (ctx->r11 != ctx->r3) {
        // 0x80236A1C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80236A2C;
    }
    goto skip_6;
    // 0x80236A1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
L_80236A20:
    // 0x80236A20: b           L_80236A2C
    // 0x80236A24: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_80236A2C;
    // 0x80236A24: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80236A28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80236A2C:
    // 0x80236A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80236A30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80236A34: jr          $ra
    // 0x80236A38: nop

    return;
    // 0x80236A38: nop

;}
RECOMP_FUNC void M10_FUN_80236a3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236A3C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80236A40: jr          $ra
    // 0x80236A44: sb          $zero, -0x1C50($at)
    MEM_B(-0X1C50, ctx->r1) = 0;
    return;
    // 0x80236A44: sb          $zero, -0x1C50($at)
    MEM_B(-0X1C50, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80236a48(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80236a48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236A48: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80236A4C: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80236A50: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80236A54: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80236A58: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80236A5C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80236A60: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80236A64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80236A68: addiu       $t6, $t6, -0x1B00
    ctx->r14 = ADD32(ctx->r14, -0X1B00);
    // 0x80236A6C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80236A70: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x80236A74: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x80236A78: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80236A7C: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x80236A80: addiu       $t9, $t9, -0x1AF8
    ctx->r25 = ADD32(ctx->r25, -0X1AF8);
    // 0x80236A84: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x80236A88: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
    // 0x80236A8C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80236A90: lui         $t2, 0x8024
    ctx->r10 = S32(0X8024 << 16);
    // 0x80236A94: addiu       $t2, $t2, -0x1AF0
    ctx->r10 = ADD32(ctx->r10, -0X1AF0);
    // 0x80236A98: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80236A9C: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80236AA0: addiu       $v1, $sp, 0x48
    ctx->r3 = ADD32(ctx->r29, 0X48);
    // 0x80236AA4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80236AA8: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
    // 0x80236AAC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80236AB0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80236AB4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80236AB8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80236ABC: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80236AC0: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x80236AC4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80236AC8: lhu         $v0, -0x43E4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X43E4);
    // 0x80236ACC: beq         $v0, $at, L_80236ADC
    if (ctx->r2 == ctx->r1) {
        // 0x80236AD0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80236ADC;
    }
    // 0x80236AD0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80236AD4: bne         $v0, $at, L_80236AE4
    if (ctx->r2 != ctx->r1) {
        // 0x80236AD8: nop
    
            goto L_80236AE4;
    }
    // 0x80236AD8: nop

L_80236ADC:
    // 0x80236ADC: b           L_80236B04
    // 0x80236AE0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80236B04;
    // 0x80236AE0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80236AE4:
    // 0x80236AE4: jal         0x80236C9C
    // 0x80236AE8: nop

    LOOKUP_FUNC(0x80236C9C)(rdram, ctx);
        goto after_0;
    // 0x80236AE8: nop

    after_0:
    // 0x80236AEC: beq         $v0, $zero, L_80236AFC
    if (ctx->r2 == 0) {
        // 0x80236AF0: or          $s2, $s1, $zero
        ctx->r18 = ctx->r17 | 0;
            goto L_80236AFC;
    }
    // 0x80236AF0: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x80236AF4: b           L_80236B04
    // 0x80236AF8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80236B04;
    // 0x80236AF8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80236AFC:
    // 0x80236AFC: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x80236B00: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80236B04:
    // 0x80236B04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80236B08: blez        $v0, L_80236B5C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80236B0C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80236B5C;
    }
    // 0x80236B0C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80236B10: lui         $s1, 0x8024
    ctx->r17 = S32(0X8024 << 16);
    // 0x80236B14: addiu       $s1, $s1, -0x1C50
    ctx->r17 = ADD32(ctx->r17, -0X1C50);
    // 0x80236B18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80236B1C:
    // 0x80236B1C: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x80236B20: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80236B24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80236B28: bne         $v1, $v0, L_80236B48
    if (ctx->r3 != ctx->r2) {
        // 0x80236B2C: sll         $t5, $v1, 1
        ctx->r13 = S32(ctx->r3 << 1);
            goto L_80236B48;
    }
    // 0x80236B2C: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    // 0x80236B30: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x80236B34: jal         0x80126A0C
    // 0x80236B38: lhu         $a1, 0x0($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X0);
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_1;
    // 0x80236B38: lhu         $a1, 0x0($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X0);
    after_1:
    // 0x80236B3C: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
    // 0x80236B40: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80236B44: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
L_80236B48:
    // 0x80236B48: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80236B4C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80236B50: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80236B54: bne         $at, $zero, L_80236B1C
    if (ctx->r1 != 0) {
        // 0x80236B58: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80236B1C;
    }
    // 0x80236B58: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80236B5C:
    // 0x80236B5C: lui         $s1, 0x8024
    ctx->r17 = S32(0X8024 << 16);
    // 0x80236B60: addiu       $s1, $s1, -0x1C50
    ctx->r17 = ADD32(ctx->r17, -0X1C50);
    // 0x80236B64: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x80236B68: slt         $at, $t9, $s3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80236B6C: bne         $at, $zero, L_80236B80
    if (ctx->r1 != 0) {
        // 0x80236B70: addiu       $t0, $zero, 0xFF
        ctx->r8 = ADD32(0, 0XFF);
            goto L_80236B80;
    }
    // 0x80236B70: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80236B74: sb          $t0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r8;
    // 0x80236B78: b           L_80236B84
    // 0x80236B7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80236B84;
    // 0x80236B7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80236B80:
    // 0x80236B80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80236B84:
    // 0x80236B84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80236B88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80236B8C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80236B90: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80236B94: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80236B98: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80236B9C: jr          $ra
    // 0x80236BA0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80236BA0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80236ba4(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80236ba4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236BA4: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80236BA8: lbu         $t6, -0x1C4C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X1C4C);
    // 0x80236BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80236BB0: beq         $t6, $zero, L_80236BC0
    if (ctx->r14 == 0) {
            // 0x80236BB4: nop

    LOOKUP_FUNC(0x80236BC0)(rdram, ctx);
    return;
    }
    // 0x80236BB4: nop

    // 0x80236BB8: jr          $ra
    // 0x80236BBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80236BBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80236bc0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80236bc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236BC0: jr          $ra
    // 0x80236BC4: nop

    return;
    // 0x80236BC4: nop

;}
RECOMP_FUNC void M10_FUN_80236bc8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236BC8: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80236BCC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80236BD0: jr          $ra
    // 0x80236BD4: sb          $a0, -0x1C4C($at)
    MEM_B(-0X1C4C, ctx->r1) = ctx->r4;
    return;
    // 0x80236BD4: sb          $a0, -0x1C4C($at)
    MEM_B(-0X1C4C, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80236bd8(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80236bd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236BD8: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80236BDC: lw          $t6, -0x1C40($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1C40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80236be0(rdram, ctx);
;}
RECOMP_FUNC void M10_FUN_80236be0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236BE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80236BE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80236BE8: bne         $t6, $zero, L_80236C50
    if (ctx->r14 != 0) {
        // 0x80236BEC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80236C50;
    }
    // 0x80236BEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80236BF0: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x80236BF4: addiu       $t7, $t7, -0x1C14
    ctx->r15 = ADD32(ctx->r15, -0X1C14);
    // 0x80236BF8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80236BFC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80236C00: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80236C04: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80236C08: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80236C0C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80236C10: lw          $a0, -0x43D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43D4);
    // 0x80236C14: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x80236C18: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80236C1C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80236C20: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x80236C24: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80236C28: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80236C2C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80236C30: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80236C34: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80236C38: jal         0x8012C4D0
    // 0x80236C3C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    LOOKUP_FUNC(0x8012C4D0)(rdram, ctx);
        goto after_0;
    // 0x80236C3C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x80236C40: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80236C44: sw          $v0, -0x1C40($at)
    MEM_W(-0X1C40, ctx->r1) = ctx->r2;
    // 0x80236C48: b           L_80236C50
    // 0x80236C4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80236C50;
    // 0x80236C4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80236C50:
    // 0x80236C50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80236C54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80236C58: jr          $ra
    // 0x80236C5C: nop

    return;
    // 0x80236C5C: nop

;}
RECOMP_FUNC void M10_FUN_80236c60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80236C60: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x80236C64: lw          $a0, -0x1C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1C40);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M10_FUN_80236c68(rdram, ctx);
;}
