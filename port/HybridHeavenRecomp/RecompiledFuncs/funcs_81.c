#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M8_FUN_801d6d70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D6D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D6D78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D6D7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D6D80: lbu         $t6, 0x91($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X91);
    // 0x801D6D84: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801D6D88: addiu       $a0, $zero, 0x11C
    ctx->r4 = ADD32(0, 0X11C);
    // 0x801D6D8C: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x801D6D90: beql        $t7, $zero, L_801D6DB8
    if (ctx->r15 == 0) {
        // 0x801D6D94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D6DB8;
    }
    goto skip_0;
    // 0x801D6D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D6D98: jal         0x80133A24
    // 0x801D6D9C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801D6D9C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D6DA0: beq         $v0, $zero, L_801D6DB4
    if (ctx->r2 == 0) {
        // 0x801D6DA4: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_801D6DB4;
    }
    // 0x801D6DA4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801D6DA8: lbu         $t8, 0x91($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X91);
    // 0x801D6DAC: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x801D6DB0: sb          $t9, 0x91($a1)
    MEM_B(0X91, ctx->r5) = ctx->r25;
L_801D6DB4:
    // 0x801D6DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D6DB8:
    // 0x801D6DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D6DBC: jr          $ra
    // 0x801D6DC0: nop

    return;
    // 0x801D6DC0: nop

;}
RECOMP_FUNC void M8_FUN_801d6dc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6DC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D6DC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D6DCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D6DD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D6DD4: lbu         $t6, 0x91($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X91);
    // 0x801D6DD8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801D6DDC: addiu       $a0, $zero, 0x11D
    ctx->r4 = ADD32(0, 0X11D);
    // 0x801D6DE0: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x801D6DE4: beql        $t7, $zero, L_801D6E0C
    if (ctx->r15 == 0) {
        // 0x801D6DE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D6E0C;
    }
    goto skip_0;
    // 0x801D6DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D6DEC: jal         0x80133A24
    // 0x801D6DF0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801D6DF0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D6DF4: beq         $v0, $zero, L_801D6E08
    if (ctx->r2 == 0) {
        // 0x801D6DF8: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_801D6E08;
    }
    // 0x801D6DF8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801D6DFC: lbu         $t8, 0x91($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X91);
    // 0x801D6E00: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x801D6E04: sb          $t9, 0x91($a1)
    MEM_B(0X91, ctx->r5) = ctx->r25;
L_801D6E08:
    // 0x801D6E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D6E0C:
    // 0x801D6E0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D6E10: jr          $ra
    // 0x801D6E14: nop

    return;
    // 0x801D6E14: nop

;}
RECOMP_FUNC void M8_FUN_801d6e18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D6E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D6E20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D6E24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D6E28: lbu         $t6, 0x91($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X91);
    // 0x801D6E2C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801D6E30: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    // 0x801D6E34: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x801D6E38: beql        $t7, $zero, L_801D6E60
    if (ctx->r15 == 0) {
        // 0x801D6E3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D6E60;
    }
    goto skip_0;
    // 0x801D6E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D6E40: jal         0x80133A24
    // 0x801D6E44: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801D6E44: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D6E48: beq         $v0, $zero, L_801D6E5C
    if (ctx->r2 == 0) {
        // 0x801D6E4C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_801D6E5C;
    }
    // 0x801D6E4C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801D6E50: lbu         $t8, 0x91($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X91);
    // 0x801D6E54: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x801D6E58: sb          $t9, 0x91($a1)
    MEM_B(0X91, ctx->r5) = ctx->r25;
L_801D6E5C:
    // 0x801D6E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D6E60:
    // 0x801D6E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D6E64: jr          $ra
    // 0x801D6E68: nop

    return;
    // 0x801D6E68: nop

;}
RECOMP_FUNC void M8_FUN_801d6e6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6E6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D6E70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D6E74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D6E78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D6E7C: lbu         $t6, 0x91($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X91);
    // 0x801D6E80: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801D6E84: addiu       $a0, $zero, 0x123
    ctx->r4 = ADD32(0, 0X123);
    // 0x801D6E88: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x801D6E8C: beql        $t7, $zero, L_801D6EB4
    if (ctx->r15 == 0) {
        // 0x801D6E90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D6EB4;
    }
    goto skip_0;
    // 0x801D6E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D6E94: jal         0x80133A24
    // 0x801D6E98: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80133A24)(rdram, ctx);
        goto after_0;
    // 0x801D6E98: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D6E9C: beq         $v0, $zero, L_801D6EB0
    if (ctx->r2 == 0) {
        // 0x801D6EA0: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_801D6EB0;
    }
    // 0x801D6EA0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801D6EA4: lbu         $t8, 0x91($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X91);
    // 0x801D6EA8: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x801D6EAC: sb          $t9, 0x91($a1)
    MEM_B(0X91, ctx->r5) = ctx->r25;
L_801D6EB0:
    // 0x801D6EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D6EB4:
    // 0x801D6EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D6EB8: jr          $ra
    // 0x801D6EBC: nop

    return;
    // 0x801D6EBC: nop

;}
RECOMP_FUNC void M8_FUN_801d6ec0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6EC0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801D6EC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D6EC8: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801D6ECC: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x801D6ED0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D6ED4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801D6ED8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801D6EDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801D6EE0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801D6EE4: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801D6EE8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801D6EEC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801D6EF0: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801D6EF4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D6EF8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801D6EFC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801D6F00: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801D6F04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D6F08: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801D6F0C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801D6F10: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801D6F14: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801D6F18: addiu       $a0, $a0, 0x37B0
    ctx->r4 = ADD32(ctx->r4, 0X37B0);
    // 0x801D6F1C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801D6F20: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801D6F24: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x801D6F28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801D6F2C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801D6F30: lwc1        $f16, 0x40($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801D6F34: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x801D6F38: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801D6F3C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x801D6F40: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801D6F44: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801D6F48: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801D6F4C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x801D6F50: jal         0x8011AAF4
    // 0x801D6F54: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x801D6F54: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x801D6F58: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x801D6F5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D6F60: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D6F64: sb          $t0, 0x93($a2)
    MEM_B(0X93, ctx->r6) = ctx->r8;
    // 0x801D6F68: swc1        $f0, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f0.u32l;
    // 0x801D6F6C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801D6F70: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801D6F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D6F78: jr          $ra
    // 0x801D6F7C: nop

    return;
    // 0x801D6F7C: nop

;}
RECOMP_FUNC void M8_FUN_801d6f80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D6F80: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801D6F84: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D6F88: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801D6F8C: lw          $t7, -0x4328($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4328);
    // 0x801D6F90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D6F94: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801D6F98: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801D6F9C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801D6FA0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801D6FA4: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801D6FA8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801D6FAC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801D6FB0: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801D6FB4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D6FB8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801D6FBC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801D6FC0: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801D6FC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D6FC8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801D6FCC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801D6FD0: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801D6FD4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801D6FD8: addiu       $a0, $a0, 0x37F0
    ctx->r4 = ADD32(ctx->r4, 0X37F0);
    // 0x801D6FDC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801D6FE0: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801D6FE4: addiu       $a1, $zero, 0xD1
    ctx->r5 = ADD32(0, 0XD1);
    // 0x801D6FE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801D6FEC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801D6FF0: lwc1        $f16, 0x40($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801D6FF4: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x801D6FF8: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801D6FFC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x801D7000: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801D7004: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801D7008: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801D700C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x801D7010: jal         0x8011AAF4
    // 0x801D7014: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8011AAF4)(rdram, ctx);
        goto after_0;
    // 0x801D7014: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x801D7018: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x801D701C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D7020: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D7024: sb          $t0, 0x93($a2)
    MEM_B(0X93, ctx->r6) = ctx->r8;
    // 0x801D7028: swc1        $f0, 0x94($a2)
    MEM_W(0X94, ctx->r6) = ctx->f0.u32l;
    // 0x801D702C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801D7030: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801D7034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D7038: jr          $ra
    // 0x801D703C: nop

    return;
    // 0x801D703C: nop

;}
RECOMP_FUNC void M8_FUN_801d7040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7048: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D704C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7050: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7054: addiu       $a0, $zero, 0x69C
    ctx->r4 = ADD32(0, 0X69C);
    // 0x801D7058: bne         $t6, $at, L_801D7068
    if (ctx->r14 != ctx->r1) {
        // 0x801D705C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_801D7068;
    }
    // 0x801D705C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801D7060: jal         0x801FC720
    // 0x801D7064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x801FC720)(rdram, ctx);
        goto after_0;
    // 0x801D7064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_801D7068:
    // 0x801D7068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D706C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7070: jr          $ra
    // 0x801D7074: nop

    return;
    // 0x801D7074: nop

;}
RECOMP_FUNC void M8_FUN_801d7078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D707C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7080: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7084: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7088: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D708C: bnel        $t6, $at, L_801D70B0
    if (ctx->r14 != ctx->r1) {
        // 0x801D7090: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D70B0;
    }
    goto skip_0;
    // 0x801D7090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D7094: jal         0x80020718
    // 0x801D7098: addiu       $a0, $zero, 0x1F7
    ctx->r4 = ADD32(0, 0X1F7);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801D7098: addiu       $a0, $zero, 0x1F7
    ctx->r4 = ADD32(0, 0X1F7);
    after_0:
    // 0x801D709C: addiu       $a0, $zero, 0x69D
    ctx->r4 = ADD32(0, 0X69D);
    // 0x801D70A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801D70A4: jal         0x801FC720
    // 0x801D70A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801FC720)(rdram, ctx);
        goto after_1;
    // 0x801D70A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801D70AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D70B0:
    // 0x801D70B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D70B4: jr          $ra
    // 0x801D70B8: nop

    return;
    // 0x801D70B8: nop

;}
RECOMP_FUNC void M8_FUN_801d70bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D70BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D70C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D70C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D70C8: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D70CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D70D0: bne         $t6, $at, L_801D70F0
    if (ctx->r14 != ctx->r1) {
        // 0x801D70D4: nop
    
            goto L_801D70F0;
    }
    // 0x801D70D4: nop

    // 0x801D70D8: jal         0x800208C4
    // 0x801D70DC: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D70DC: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_0:
    // 0x801D70E0: jal         0x80020718
    // 0x801D70E4: addiu       $a0, $zero, 0x69C
    ctx->r4 = ADD32(0, 0X69C);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_1;
    // 0x801D70E4: addiu       $a0, $zero, 0x69C
    ctx->r4 = ADD32(0, 0X69C);
    after_1:
    // 0x801D70E8: b           L_801D70FC
    // 0x801D70EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D70FC;
    // 0x801D70EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D70F0:
    // 0x801D70F0: jal         0x800208C4
    // 0x801D70F4: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_2;
    // 0x801D70F4: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_2:
    // 0x801D70F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D70FC:
    // 0x801D70FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7100: jr          $ra
    // 0x801D7104: nop

    return;
    // 0x801D7104: nop

;}
RECOMP_FUNC void M8_FUN_801d7108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D710C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7110: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7114: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7118: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D711C: bne         $t6, $at, L_801D7134
    if (ctx->r14 != ctx->r1) {
        // 0x801D7120: nop
    
            goto L_801D7134;
    }
    // 0x801D7120: nop

    // 0x801D7124: jal         0x800208C4
    // 0x801D7128: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D7128: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_0:
    // 0x801D712C: b           L_801D7140
    // 0x801D7130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7140;
    // 0x801D7130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7134:
    // 0x801D7134: jal         0x800208C4
    // 0x801D7138: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7138: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_1:
    // 0x801D713C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7140:
    // 0x801D7140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7144: jr          $ra
    // 0x801D7148: nop

    return;
    // 0x801D7148: nop

;}
RECOMP_FUNC void M8_FUN_801d714c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D714C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D7158: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D715C: jal         0x80133980
    // 0x801D7160: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x801D7160: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x801D7164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D7168: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D716C: jr          $ra
    // 0x801D7170: nop

    return;
    // 0x801D7170: nop

;}
RECOMP_FUNC void M8_FUN_801d7174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D717C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D7180: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7184: jal         0x801505AC
    // 0x801D7188: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801505AC)(rdram, ctx);
        goto after_0;
    // 0x801D7188: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801D718C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801D7190: jal         0x80150314
    // 0x801D7194: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    LOOKUP_FUNC(0x80150314)(rdram, ctx);
        goto after_1;
    // 0x801D7194: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_1:
    // 0x801D7198: jal         0x801505AC
    // 0x801D719C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801505AC)(rdram, ctx);
        goto after_2;
    // 0x801D719C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x801D71A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801D71A4: jal         0x80150314
    // 0x801D71A8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    LOOKUP_FUNC(0x80150314)(rdram, ctx);
        goto after_3;
    // 0x801D71A8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_3:
    // 0x801D71AC: jal         0x801505AC
    // 0x801D71B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x801505AC)(rdram, ctx);
        goto after_4;
    // 0x801D71B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x801D71B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801D71B8: jal         0x80150314
    // 0x801D71BC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    LOOKUP_FUNC(0x80150314)(rdram, ctx);
        goto after_5;
    // 0x801D71BC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_5:
    // 0x801D71C0: jal         0x801505AC
    // 0x801D71C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x801505AC)(rdram, ctx);
        goto after_6;
    // 0x801D71C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x801D71C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801D71CC: jal         0x80150314
    // 0x801D71D0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    LOOKUP_FUNC(0x80150314)(rdram, ctx);
        goto after_7;
    // 0x801D71D0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_7:
    // 0x801D71D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D71D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D71DC: jr          $ra
    // 0x801D71E0: nop

    return;
    // 0x801D71E0: nop

;}
RECOMP_FUNC void M8_FUN_801d71e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D71E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D71E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D71EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D71F0: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D71F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D71F8: bnel        $t6, $at, L_801D720C
    if (ctx->r14 != ctx->r1) {
        // 0x801D71FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D720C;
    }
    goto skip_0;
    // 0x801D71FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D7200: jal         0x80020718
    // 0x801D7204: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801D7204: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x801D7208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D720C:
    // 0x801D720C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7210: jr          $ra
    // 0x801D7214: nop

    return;
    // 0x801D7214: nop

;}
RECOMP_FUNC void M8_FUN_801d7218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D721C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7220: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7224: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7228: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D722C: bne         $t6, $at, L_801D7244
    if (ctx->r14 != ctx->r1) {
        // 0x801D7230: nop
    
            goto L_801D7244;
    }
    // 0x801D7230: nop

    // 0x801D7234: jal         0x800208C4
    // 0x801D7238: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D7238: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_0:
    // 0x801D723C: b           L_801D7250
    // 0x801D7240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7250;
    // 0x801D7240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7244:
    // 0x801D7244: jal         0x800208C4
    // 0x801D7248: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7248: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    after_1:
    // 0x801D724C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7250:
    // 0x801D7250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7254: jr          $ra
    // 0x801D7258: nop

    return;
    // 0x801D7258: nop

;}
RECOMP_FUNC void M8_FUN_801d725c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D725C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7264: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7268: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D726C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D7270: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    // 0x801D7274: bne         $t6, $at, L_801D7284
    if (ctx->r14 != ctx->r1) {
        // 0x801D7278: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_801D7284;
    }
    // 0x801D7278: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801D727C: jal         0x801FC720
    // 0x801D7280: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x801FC720)(rdram, ctx);
        goto after_0;
    // 0x801D7280: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_801D7284:
    // 0x801D7284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D7288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D728C: jr          $ra
    // 0x801D7290: nop

    return;
    // 0x801D7290: nop

;}
RECOMP_FUNC void M8_FUN_801d7294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7298: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D729C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D72A0: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D72A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D72A8: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    // 0x801D72AC: bne         $t6, $at, L_801D72C4
    if (ctx->r14 != ctx->r1) {
        // 0x801D72B0: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_801D72C4;
    }
    // 0x801D72B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801D72B4: jal         0x801FC720
    // 0x801D72B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x801FC720)(rdram, ctx);
        goto after_0;
    // 0x801D72B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801D72BC: jal         0x800208C4
    // 0x801D72C0: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D72C0: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_1:
L_801D72C4:
    // 0x801D72C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D72C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D72CC: jr          $ra
    // 0x801D72D0: nop

    return;
    // 0x801D72D0: nop

;}
RECOMP_FUNC void M8_FUN_801d72d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D72D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D72D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D72DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D72E0: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D72E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D72E8: bnel        $t6, $at, L_801D72FC
    if (ctx->r14 != ctx->r1) {
        // 0x801D72EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D72FC;
    }
    goto skip_0;
    // 0x801D72EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D72F0: jal         0x800208C4
    // 0x801D72F4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D72F4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x801D72F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D72FC:
    // 0x801D72FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7300: jr          $ra
    // 0x801D7304: nop

    return;
    // 0x801D7304: nop

;}
RECOMP_FUNC void M8_FUN_801d7308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D730C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7310: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D7314: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7318: jal         0x80020718
    // 0x801D731C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801D731C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x801D7320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D7324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7328: jr          $ra
    // 0x801D732C: nop

    return;
    // 0x801D732C: nop

;}
RECOMP_FUNC void M8_FUN_801d7330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7338: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D733C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7340: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D7344: bnel        $t6, $at, L_801D7358
    if (ctx->r14 != ctx->r1) {
        // 0x801D7348: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D7358;
    }
    goto skip_0;
    // 0x801D7348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D734C: jal         0x80020718
    // 0x801D7350: addiu       $a0, $zero, 0x6BA
    ctx->r4 = ADD32(0, 0X6BA);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801D7350: addiu       $a0, $zero, 0x6BA
    ctx->r4 = ADD32(0, 0X6BA);
    after_0:
    // 0x801D7354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7358:
    // 0x801D7358: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D735C: jr          $ra
    // 0x801D7360: nop

    return;
    // 0x801D7360: nop

;}
RECOMP_FUNC void M8_FUN_801d7364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D736C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7370: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7374: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7378: bnel        $t6, $at, L_801D738C
    if (ctx->r14 != ctx->r1) {
        // 0x801D737C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D738C;
    }
    goto skip_0;
    // 0x801D737C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D7380: jal         0x80020718
    // 0x801D7384: addiu       $a0, $zero, 0x6BA
    ctx->r4 = ADD32(0, 0X6BA);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801D7384: addiu       $a0, $zero, 0x6BA
    ctx->r4 = ADD32(0, 0X6BA);
    after_0:
    // 0x801D7388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D738C:
    // 0x801D738C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7390: jr          $ra
    // 0x801D7394: nop

    return;
    // 0x801D7394: nop

;}
RECOMP_FUNC void M8_FUN_801d7398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D739C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D73A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D73A4: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D73A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D73AC: bnel        $t6, $at, L_801D73D0
    if (ctx->r14 != ctx->r1) {
        // 0x801D73B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D73D0;
    }
    goto skip_0;
    // 0x801D73B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D73B4: jal         0x80020718
    // 0x801D73B8: addiu       $a0, $zero, 0x6BA
    ctx->r4 = ADD32(0, 0X6BA);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801D73B8: addiu       $a0, $zero, 0x6BA
    ctx->r4 = ADD32(0, 0X6BA);
    after_0:
    // 0x801D73BC: addiu       $a0, $zero, 0x6AA
    ctx->r4 = ADD32(0, 0X6AA);
    // 0x801D73C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801D73C4: jal         0x801FC720
    // 0x801D73C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801FC720)(rdram, ctx);
        goto after_1;
    // 0x801D73C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801D73CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D73D0:
    // 0x801D73D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D73D4: jr          $ra
    // 0x801D73D8: nop

    return;
    // 0x801D73D8: nop

;}
RECOMP_FUNC void M8_FUN_801d73dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D73DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D73E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D73E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D73E8: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D73EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D73F0: bne         $t6, $at, L_801D7408
    if (ctx->r14 != ctx->r1) {
        // 0x801D73F4: nop
    
            goto L_801D7408;
    }
    // 0x801D73F4: nop

    // 0x801D73F8: jal         0x800208C4
    // 0x801D73FC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D73FC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_0:
    // 0x801D7400: b           L_801D7414
    // 0x801D7404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7414;
    // 0x801D7404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7408:
    // 0x801D7408: jal         0x800208C4
    // 0x801D740C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D740C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_1:
    // 0x801D7410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7414:
    // 0x801D7414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7418: jr          $ra
    // 0x801D741C: nop

    return;
    // 0x801D741C: nop

;}
RECOMP_FUNC void M8_FUN_801d7420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7428: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D742C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7430: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7434: bne         $t6, $at, L_801D744C
    if (ctx->r14 != ctx->r1) {
        // 0x801D7438: nop
    
            goto L_801D744C;
    }
    // 0x801D7438: nop

    // 0x801D743C: jal         0x800208C4
    // 0x801D7440: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D7440: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_0:
    // 0x801D7444: b           L_801D7458
    // 0x801D7448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7458;
    // 0x801D7448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D744C:
    // 0x801D744C: jal         0x800208C4
    // 0x801D7450: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7450: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    after_1:
    // 0x801D7454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7458:
    // 0x801D7458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D745C: jr          $ra
    // 0x801D7460: nop

    return;
    // 0x801D7460: nop

;}
RECOMP_FUNC void M8_FUN_801d7464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7464: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801D7468: lbu         $t6, -0x431A($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X431A);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d746c(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d746c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D746C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7470: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801D7474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7478: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D747C: bne         $t6, $at, L_801D74A0
    if (ctx->r14 != ctx->r1) {
        // 0x801D7480: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801D74A0;
    }
    // 0x801D7480: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7484: lbu         $t7, 0x91($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X91);
    // 0x801D7488: addiu       $t9, $zero, 0x76
    ctx->r25 = ADD32(0, 0X76);
    // 0x801D748C: sh          $t9, 0x9E($a0)
    MEM_H(0X9E, ctx->r4) = ctx->r25;
    // 0x801D7490: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x801D7494: sb          $t8, 0x91($a0)
    MEM_B(0X91, ctx->r4) = ctx->r24;
    // 0x801D7498: jal         0x80020718
    // 0x801D749C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801D749C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
L_801D74A0:
    // 0x801D74A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D74A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D74A8: jr          $ra
    // 0x801D74AC: nop

    return;
    // 0x801D74AC: nop

;}
RECOMP_FUNC void M8_FUN_801d74b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D74B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D74B4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x801D74B8: jr          $ra
    // 0x801D74BC: sb          $t6, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r14;
    return;
    // 0x801D74BC: sb          $t6, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d74c0(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d74c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D74C0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801D74C4: lbu         $t6, -0x431A($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X431A);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d74c8(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d74c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D74C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D74CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801D74D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D74D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D74D8: bne         $t6, $at, L_801D74FC
    if (ctx->r14 != ctx->r1) {
        // 0x801D74DC: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801D74FC;
    }
    // 0x801D74DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D74E0: lbu         $t7, 0x91($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X91);
    // 0x801D74E4: addiu       $t9, $zero, 0x76
    ctx->r25 = ADD32(0, 0X76);
    // 0x801D74E8: sh          $t9, 0x9E($a0)
    MEM_H(0X9E, ctx->r4) = ctx->r25;
    // 0x801D74EC: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x801D74F0: sb          $t8, 0x91($a0)
    MEM_B(0X91, ctx->r4) = ctx->r24;
    // 0x801D74F4: jal         0x80020718
    // 0x801D74F8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801D74F8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
L_801D74FC:
    // 0x801D74FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D7500: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7504: jr          $ra
    // 0x801D7508: nop

    return;
    // 0x801D7508: nop

;}
RECOMP_FUNC void M8_FUN_801d750c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D750C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801D7510: lbu         $t6, -0x431A($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X431A);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M8_FUN_801d7514(rdram, ctx);
;}
RECOMP_FUNC void M8_FUN_801d7514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7518: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801D751C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7520: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D7524: bne         $t6, $at, L_801D7548
    if (ctx->r14 != ctx->r1) {
        // 0x801D7528: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801D7548;
    }
    // 0x801D7528: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D752C: lbu         $t7, 0x91($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X91);
    // 0x801D7530: addiu       $t9, $zero, 0x76
    ctx->r25 = ADD32(0, 0X76);
    // 0x801D7534: sh          $t9, 0x9E($a0)
    MEM_H(0X9E, ctx->r4) = ctx->r25;
    // 0x801D7538: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x801D753C: sb          $t8, 0x91($a0)
    MEM_B(0X91, ctx->r4) = ctx->r24;
    // 0x801D7540: jal         0x80020718
    // 0x801D7544: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801D7544: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
L_801D7548:
    // 0x801D7548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D754C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7550: jr          $ra
    // 0x801D7554: nop

    return;
    // 0x801D7554: nop

;}
RECOMP_FUNC void M8_FUN_801d7558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7558: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D755C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7560: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7564: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7568: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D756C: bnel        $t6, $at, L_801D7580
    if (ctx->r14 != ctx->r1) {
        // 0x801D7570: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D7580;
    }
    goto skip_0;
    // 0x801D7570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D7574: jal         0x80020718
    // 0x801D7578: addiu       $a0, $zero, 0x6BA
    ctx->r4 = ADD32(0, 0X6BA);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801D7578: addiu       $a0, $zero, 0x6BA
    ctx->r4 = ADD32(0, 0X6BA);
    after_0:
    // 0x801D757C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7580:
    // 0x801D7580: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7584: jr          $ra
    // 0x801D7588: nop

    return;
    // 0x801D7588: nop

;}
RECOMP_FUNC void M8_FUN_801d758c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D758C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7590: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7594: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7598: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D759C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D75A0: bne         $t6, $at, L_801D75B8
    if (ctx->r14 != ctx->r1) {
        // 0x801D75A4: nop
    
            goto L_801D75B8;
    }
    // 0x801D75A4: nop

    // 0x801D75A8: jal         0x800208C4
    // 0x801D75AC: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D75AC: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_0:
    // 0x801D75B0: b           L_801D75C4
    // 0x801D75B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D75C4;
    // 0x801D75B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D75B8:
    // 0x801D75B8: jal         0x800208C4
    // 0x801D75BC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D75BC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_1:
    // 0x801D75C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D75C4:
    // 0x801D75C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D75C8: jr          $ra
    // 0x801D75CC: nop

    return;
    // 0x801D75CC: nop

;}
RECOMP_FUNC void M8_FUN_801d75d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D75D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D75D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D75D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D75DC: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D75E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D75E4: bne         $t6, $at, L_801D75FC
    if (ctx->r14 != ctx->r1) {
        // 0x801D75E8: nop
    
            goto L_801D75FC;
    }
    // 0x801D75E8: nop

    // 0x801D75EC: jal         0x800208C4
    // 0x801D75F0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D75F0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_0:
    // 0x801D75F4: b           L_801D7608
    // 0x801D75F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7608;
    // 0x801D75F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D75FC:
    // 0x801D75FC: jal         0x800208C4
    // 0x801D7600: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7600: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_1:
    // 0x801D7604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7608:
    // 0x801D7608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D760C: jr          $ra
    // 0x801D7610: nop

    return;
    // 0x801D7610: nop

;}
RECOMP_FUNC void M8_FUN_801d7614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7614: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D761C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7620: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7624: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7628: bne         $t6, $at, L_801D7640
    if (ctx->r14 != ctx->r1) {
        // 0x801D762C: nop
    
            goto L_801D7640;
    }
    // 0x801D762C: nop

    // 0x801D7630: jal         0x800208C4
    // 0x801D7634: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D7634: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_0:
    // 0x801D7638: b           L_801D764C
    // 0x801D763C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D764C;
    // 0x801D763C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7640:
    // 0x801D7640: jal         0x800208C4
    // 0x801D7644: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7644: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    after_1:
    // 0x801D7648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D764C:
    // 0x801D764C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7650: jr          $ra
    // 0x801D7654: nop

    return;
    // 0x801D7654: nop

;}
RECOMP_FUNC void M8_FUN_801d7658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D765C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7660: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7664: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7668: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D766C: bne         $t6, $at, L_801D7684
    if (ctx->r14 != ctx->r1) {
        // 0x801D7670: nop
    
            goto L_801D7684;
    }
    // 0x801D7670: nop

    // 0x801D7674: jal         0x800208C4
    // 0x801D7678: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D7678: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x801D767C: b           L_801D7690
    // 0x801D7680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7690;
    // 0x801D7680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7684:
    // 0x801D7684: jal         0x800208C4
    // 0x801D7688: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7688: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_1:
    // 0x801D768C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7690:
    // 0x801D7690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7694: jr          $ra
    // 0x801D7698: nop

    return;
    // 0x801D7698: nop

;}
RECOMP_FUNC void M8_FUN_801d769c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D769C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D76A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D76A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D76A8: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D76AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D76B0: bne         $t6, $at, L_801D76D0
    if (ctx->r14 != ctx->r1) {
        // 0x801D76B4: nop
    
            goto L_801D76D0;
    }
    // 0x801D76B4: nop

    // 0x801D76B8: jal         0x800208C4
    // 0x801D76BC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D76BC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_0:
    // 0x801D76C0: jal         0x800208C4
    // 0x801D76C4: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D76C4: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_1:
    // 0x801D76C8: b           L_801D7700
    // 0x801D76CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7700;
    // 0x801D76CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D76D0:
    // 0x801D76D0: jal         0x8012FF58
    // 0x801D76D4: nop

    LOOKUP_FUNC(0x8012FF58)(rdram, ctx);
        goto after_2;
    // 0x801D76D4: nop

    after_2:
    // 0x801D76D8: slti        $at, $v0, 0x46
    ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
    // 0x801D76DC: beq         $at, $zero, L_801D76F4
    if (ctx->r1 == 0) {
        // 0x801D76E0: nop
    
            goto L_801D76F4;
    }
    // 0x801D76E0: nop

    // 0x801D76E4: jal         0x800208C4
    // 0x801D76E8: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_3;
    // 0x801D76E8: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_3:
    // 0x801D76EC: b           L_801D7700
    // 0x801D76F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7700;
    // 0x801D76F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D76F4:
    // 0x801D76F4: jal         0x800208C4
    // 0x801D76F8: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_4;
    // 0x801D76F8: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_4:
    // 0x801D76FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7700:
    // 0x801D7700: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7704: jr          $ra
    // 0x801D7708: nop

    return;
    // 0x801D7708: nop

;}
RECOMP_FUNC void M8_FUN_801d770c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D770C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7714: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7718: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D771C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7720: beql        $t6, $at, L_801D7734
    if (ctx->r14 == ctx->r1) {
        // 0x801D7724: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D7734;
    }
    goto skip_0;
    // 0x801D7724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D7728: jal         0x800208C4
    // 0x801D772C: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D772C: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_0:
    // 0x801D7730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7734:
    // 0x801D7734: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7738: jr          $ra
    // 0x801D773C: nop

    return;
    // 0x801D773C: nop

;}
RECOMP_FUNC void M8_FUN_801d7740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7744: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7748: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D774C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7750: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7754: bne         $t6, $at, L_801D776C
    if (ctx->r14 != ctx->r1) {
        // 0x801D7758: nop
    
            goto L_801D776C;
    }
    // 0x801D7758: nop

    // 0x801D775C: jal         0x800208C4
    // 0x801D7760: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D7760: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_0:
    // 0x801D7764: b           L_801D7780
    // 0x801D7768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7780;
    // 0x801D7768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D776C:
    // 0x801D776C: jal         0x800208C4
    // 0x801D7770: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7770: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_1:
    // 0x801D7774: jal         0x800208C4
    // 0x801D7778: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_2;
    // 0x801D7778: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_2:
    // 0x801D777C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7780:
    // 0x801D7780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7784: jr          $ra
    // 0x801D7788: nop

    return;
    // 0x801D7788: nop

;}
RECOMP_FUNC void M8_FUN_801d778c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D778C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7794: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7798: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D779C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D77A0: bne         $t6, $at, L_801D77B8
    if (ctx->r14 != ctx->r1) {
        // 0x801D77A4: nop
    
            goto L_801D77B8;
    }
    // 0x801D77A4: nop

    // 0x801D77A8: jal         0x800208C4
    // 0x801D77AC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D77AC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_0:
    // 0x801D77B0: b           L_801D77C4
    // 0x801D77B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D77C4;
    // 0x801D77B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D77B8:
    // 0x801D77B8: jal         0x800208C4
    // 0x801D77BC: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D77BC: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_1:
    // 0x801D77C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D77C4:
    // 0x801D77C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D77C8: jr          $ra
    // 0x801D77CC: nop

    return;
    // 0x801D77CC: nop

;}
RECOMP_FUNC void M8_FUN_801d77d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D77D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D77D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D77D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D77DC: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D77E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D77E4: bne         $t6, $at, L_801D780C
    if (ctx->r14 != ctx->r1) {
        // 0x801D77E8: nop
    
            goto L_801D780C;
    }
    // 0x801D77E8: nop

    // 0x801D77EC: jal         0x800208C4
    // 0x801D77F0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D77F0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_0:
    // 0x801D77F4: jal         0x800208C4
    // 0x801D77F8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D77F8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_1:
    // 0x801D77FC: jal         0x800208C4
    // 0x801D7800: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_2;
    // 0x801D7800: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_2:
    // 0x801D7804: b           L_801D7818
    // 0x801D7808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7818;
    // 0x801D7808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D780C:
    // 0x801D780C: jal         0x800208C4
    // 0x801D7810: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_3;
    // 0x801D7810: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    after_3:
    // 0x801D7814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7818:
    // 0x801D7818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D781C: jr          $ra
    // 0x801D7820: nop

    return;
    // 0x801D7820: nop

;}
RECOMP_FUNC void M8_FUN_801d7824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7824: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D782C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D7830: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7834: jal         0x80133980
    // 0x801D7838: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x801D7838: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    after_0:
    // 0x801D783C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D7840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7844: jr          $ra
    // 0x801D7848: nop

    return;
    // 0x801D7848: nop

;}
RECOMP_FUNC void M8_FUN_801d784c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D784C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7854: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7858: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D785C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7860: bne         $t6, $at, L_801D7888
    if (ctx->r14 != ctx->r1) {
        // 0x801D7864: nop
    
            goto L_801D7888;
    }
    // 0x801D7864: nop

    // 0x801D7868: jal         0x800208C4
    // 0x801D786C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_0;
    // 0x801D786C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_0:
    // 0x801D7870: jal         0x800208C4
    // 0x801D7874: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D7874: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_1:
    // 0x801D7878: jal         0x800208C4
    // 0x801D787C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_2;
    // 0x801D787C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_2:
    // 0x801D7880: b           L_801D7894
    // 0x801D7884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7894;
    // 0x801D7884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7888:
    // 0x801D7888: jal         0x800208C4
    // 0x801D788C: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_3;
    // 0x801D788C: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_3:
    // 0x801D7890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7894:
    // 0x801D7894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7898: jr          $ra
    // 0x801D789C: nop

    return;
    // 0x801D789C: nop

;}
RECOMP_FUNC void M8_FUN_801d78a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D78A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D78A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D78A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D78AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D78B0: jal         0x80133980
    // 0x801D78B4: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x801D78B4: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    after_0:
    // 0x801D78B8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801D78BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D78C0: lbu         $t7, 0x92($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X92);
    // 0x801D78C4: bne         $t7, $at, L_801D78DC
    if (ctx->r15 != ctx->r1) {
        // 0x801D78C8: nop
    
            goto L_801D78DC;
    }
    // 0x801D78C8: nop

    // 0x801D78CC: jal         0x800208C4
    // 0x801D78D0: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_1;
    // 0x801D78D0: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_1:
    // 0x801D78D4: b           L_801D78E8
    // 0x801D78D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D78E8;
    // 0x801D78D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D78DC:
    // 0x801D78DC: jal         0x800208C4
    // 0x801D78E0: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    LOOKUP_FUNC(0x800208C4)(rdram, ctx);
        goto after_2;
    // 0x801D78E0: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_2:
    // 0x801D78E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D78E8:
    // 0x801D78E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D78EC: jr          $ra
    // 0x801D78F0: nop

    return;
    // 0x801D78F0: nop

;}
RECOMP_FUNC void M8_FUN_801d78f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D78F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D78F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D78FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D7900: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7904: jal         0x80133980
    // 0x801D7908: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    LOOKUP_FUNC(0x80133980)(rdram, ctx);
        goto after_0;
    // 0x801D7908: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    after_0:
    // 0x801D790C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D7910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7914: jr          $ra
    // 0x801D7918: nop

    return;
    // 0x801D7918: nop

;}
RECOMP_FUNC void M8_FUN_801d791c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D791C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7924: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7928: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D792C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7930: bne         $t6, $at, L_801D7948
    if (ctx->r14 != ctx->r1) {
        // 0x801D7934: nop
    
            goto L_801D7948;
    }
    // 0x801D7934: nop

    // 0x801D7938: jal         0x801FCBA8
    // 0x801D793C: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_0;
    // 0x801D793C: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_0:
    // 0x801D7940: b           L_801D7954
    // 0x801D7944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7954;
    // 0x801D7944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7948:
    // 0x801D7948: jal         0x801FCBA8
    // 0x801D794C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_1;
    // 0x801D794C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_1:
    // 0x801D7950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7954:
    // 0x801D7954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7958: jr          $ra
    // 0x801D795C: nop

    return;
    // 0x801D795C: nop

;}
RECOMP_FUNC void M8_FUN_801d7960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7968: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D796C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7970: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7974: bnel        $t6, $at, L_801D79A8
    if (ctx->r14 != ctx->r1) {
        // 0x801D7978: lbu         $v0, 0x9C($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X9C);
            goto L_801D79A8;
    }
    goto skip_0;
    // 0x801D7978: lbu         $v0, 0x9C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9C);
    skip_0:
    // 0x801D797C: lbu         $v0, 0x9C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9C);
    // 0x801D7980: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801D7984: beq         $v0, $zero, L_801D7994
    if (ctx->r2 == 0) {
        // 0x801D7988: nop
    
            goto L_801D7994;
    }
    // 0x801D7988: nop

    // 0x801D798C: bnel        $v0, $at, L_801D79D0
    if (ctx->r2 != ctx->r1) {
        // 0x801D7990: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D79D0;
    }
    goto skip_1;
    // 0x801D7990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_801D7994:
    // 0x801D7994: jal         0x801FCBA8
    // 0x801D7998: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_0;
    // 0x801D7998: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_0:
    // 0x801D799C: b           L_801D79D0
    // 0x801D79A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D79D0;
    // 0x801D79A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D79A4: lbu         $v0, 0x9C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9C);
L_801D79A8:
    // 0x801D79A8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801D79AC: beq         $v0, $zero, L_801D79BC
    if (ctx->r2 == 0) {
        // 0x801D79B0: nop
    
            goto L_801D79BC;
    }
    // 0x801D79B0: nop

    // 0x801D79B4: bne         $v0, $at, L_801D79C4
    if (ctx->r2 != ctx->r1) {
        // 0x801D79B8: nop
    
            goto L_801D79C4;
    }
    // 0x801D79B8: nop

L_801D79BC:
    // 0x801D79BC: jal         0x801FCBA8
    // 0x801D79C0: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_1;
    // 0x801D79C0: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_1:
L_801D79C4:
    // 0x801D79C4: jal         0x80020718
    // 0x801D79C8: addiu       $a0, $zero, 0x17B
    ctx->r4 = ADD32(0, 0X17B);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_2;
    // 0x801D79C8: addiu       $a0, $zero, 0x17B
    ctx->r4 = ADD32(0, 0X17B);
    after_2:
    // 0x801D79CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D79D0:
    // 0x801D79D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D79D4: jr          $ra
    // 0x801D79D8: nop

    return;
    // 0x801D79D8: nop

;}
RECOMP_FUNC void M8_FUN_801d79dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D79DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D79E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D79E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D79E8: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D79EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D79F0: bne         $t6, $at, L_801D7A08
    if (ctx->r14 != ctx->r1) {
        // 0x801D79F4: nop
    
            goto L_801D7A08;
    }
    // 0x801D79F4: nop

    // 0x801D79F8: jal         0x801FCBA8
    // 0x801D79FC: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_0;
    // 0x801D79FC: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_0:
    // 0x801D7A00: b           L_801D7A14
    // 0x801D7A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7A14;
    // 0x801D7A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7A08:
    // 0x801D7A08: jal         0x801FCBA8
    // 0x801D7A0C: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_1;
    // 0x801D7A0C: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_1:
    // 0x801D7A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7A14:
    // 0x801D7A14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7A18: jr          $ra
    // 0x801D7A1C: nop

    return;
    // 0x801D7A1C: nop

;}
RECOMP_FUNC void M8_FUN_801d7a20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7A20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7A24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7A28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7A2C: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7A30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7A34: bne         $t6, $at, L_801D7A4C
    if (ctx->r14 != ctx->r1) {
        // 0x801D7A38: nop
    
            goto L_801D7A4C;
    }
    // 0x801D7A38: nop

    // 0x801D7A3C: jal         0x801FCBA8
    // 0x801D7A40: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_0;
    // 0x801D7A40: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_0:
    // 0x801D7A44: b           L_801D7A58
    // 0x801D7A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7A58;
    // 0x801D7A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7A4C:
    // 0x801D7A4C: jal         0x801FCBA8
    // 0x801D7A50: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_1;
    // 0x801D7A50: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_1:
    // 0x801D7A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7A58:
    // 0x801D7A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7A5C: jr          $ra
    // 0x801D7A60: nop

    return;
    // 0x801D7A60: nop

;}
RECOMP_FUNC void M8_FUN_801d7a64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7A64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7A6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7A70: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7A74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7A78: bnel        $t6, $at, L_801D7A8C
    if (ctx->r14 != ctx->r1) {
        // 0x801D7A7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D7A8C;
    }
    goto skip_0;
    // 0x801D7A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D7A80: jal         0x80020718
    // 0x801D7A84: addiu       $a0, $zero, 0x17C
    ctx->r4 = ADD32(0, 0X17C);
    LOOKUP_FUNC(0x80020718)(rdram, ctx);
        goto after_0;
    // 0x801D7A84: addiu       $a0, $zero, 0x17C
    ctx->r4 = ADD32(0, 0X17C);
    after_0:
    // 0x801D7A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7A8C:
    // 0x801D7A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7A90: jr          $ra
    // 0x801D7A94: nop

    return;
    // 0x801D7A94: nop

;}
RECOMP_FUNC void M8_FUN_801d7a98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D7A98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D7A9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D7AA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D7AA4: lbu         $t6, 0x92($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X92);
    // 0x801D7AA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D7AAC: bne         $t6, $at, L_801D7AC4
    if (ctx->r14 != ctx->r1) {
        // 0x801D7AB0: nop
    
            goto L_801D7AC4;
    }
    // 0x801D7AB0: nop

    // 0x801D7AB4: jal         0x801FCBA8
    // 0x801D7AB8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_0;
    // 0x801D7AB8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_0:
    // 0x801D7ABC: b           L_801D7AD0
    // 0x801D7AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D7AD0;
    // 0x801D7AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7AC4:
    // 0x801D7AC4: jal         0x801FCBA8
    // 0x801D7AC8: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    LOOKUP_FUNC(0x801FCBA8)(rdram, ctx);
        goto after_1;
    // 0x801D7AC8: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_1:
    // 0x801D7ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D7AD0:
    // 0x801D7AD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D7AD4: jr          $ra
    // 0x801D7AD8: nop

    return;
    // 0x801D7AD8: nop

;}
