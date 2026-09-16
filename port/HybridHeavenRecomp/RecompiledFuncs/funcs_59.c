#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M25_FUN_801e1d38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1D38: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E1D3C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E1D40: jr          $ra
    // 0x801E1D44: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E1D44: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e1d48(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e1d48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1D48: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E1D4C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E1D50: jr          $ra
    // 0x801E1D54: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E1D54: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e1d58(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e1d58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1D58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E1D5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E1D60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E1D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E1D68: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E1D6C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E1D70: lw          $a0, -0x5448($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5448);
    // 0x801E1D74: jal         0x801CCF48
    // 0x801E1D78: lw          $a1, -0x5444($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5444);
    LOOKUP_FUNC(0x801CCF48)(rdram, ctx);
        goto after_0;
    // 0x801E1D78: lw          $a1, -0x5444($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5444);
    after_0:
    // 0x801E1D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E1D80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E1D84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801E1D88: jr          $ra
    // 0x801E1D8C: nop

    return;
    // 0x801E1D8C: nop

;}
RECOMP_FUNC void M25_FUN_801e1d90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1D90: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E1D94: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E1D98: jr          $ra
    // 0x801E1D9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801E1D9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e1da0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e1da0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1DA0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E1DA4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E1DA8: jr          $ra
    // 0x801E1DAC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E1DAC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e1db0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e1db0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1DB0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E1DB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E1DB8: jr          $ra
    // 0x801E1DBC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E1DBC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e1dc0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e1dc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1DC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E1DC4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E1DC8: jr          $ra
    // 0x801E1DCC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E1DCC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e1dd0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e1dd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1DD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E1DD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E1DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E1DDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E1DE0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E1DE4: addiu       $a1, $a1, -0x2270
    ctx->r5 = ADD32(ctx->r5, -0X2270);
    // 0x801E1DE8: jal         0x801C2420
    // 0x801E1DEC: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    LOOKUP_FUNC(0x801C2420)(rdram, ctx);
        goto after_0;
    // 0x801E1DEC: addiu       $a0, $zero, 0xA1
    ctx->r4 = ADD32(0, 0XA1);
    after_0:
    // 0x801E1DF0: jal         0x8038BA70
    // 0x801E1DF4: nop

    LOOKUP_FUNC(0x8038BA70)(rdram, ctx);
        goto after_1;
    // 0x801E1DF4: nop

    after_1:
    // 0x801E1DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E1DFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E1E00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801E1E04: jr          $ra
    // 0x801E1E08: nop

    return;
    // 0x801E1E08: nop

;}
RECOMP_FUNC void M25_FUN_801e1e0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1E0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E1E10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E1E14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E1E18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E1E1C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801E1E20: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801E1E24: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x801E1E28: jal         0x80005E44
    // 0x801E1E2C: addiu       $a1, $a1, -0x2774
    ctx->r5 = ADD32(ctx->r5, -0X2774);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801E1E2C: addiu       $a1, $a1, -0x2774
    ctx->r5 = ADD32(ctx->r5, -0X2774);
    after_0:
    // 0x801E1E30: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801E1E34: jal         0x80006214
    // 0x801E1E38: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801E1E38: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_1:
    // 0x801E1E3C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801E1E40: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x801E1E44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E1E48: addiu       $a2, $zero, 0xA1
    ctx->r6 = ADD32(0, 0XA1);
    // 0x801E1E4C: jal         0x8012C89C
    // 0x801E1E50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801E1E50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801E1E54: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801E1E58: addiu       $v1, $v1, -0x2730
    ctx->r3 = ADD32(ctx->r3, -0X2730);
    // 0x801E1E5C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E1E60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801E1E64: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801E1E68: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801E1E6C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801E1E70: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x801E1E74: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801E1E78: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801E1E7C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801E1E80: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
    // 0x801E1E84: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801E1E88: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801E1E8C: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801E1E90: swc1        $f0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f0.u32l;
    // 0x801E1E94: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801E1E98: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801E1E9C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801E1EA0: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    // 0x801E1EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E1EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E1EAC: jr          $ra
    // 0x801E1EB0: nop

    return;
    // 0x801E1EB0: nop

;}
RECOMP_FUNC void M25_FUN_801e1eb4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1EB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E1EB8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E1EBC: jr          $ra
    // 0x801E1EC0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801E1EC0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e1ec4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e1ec4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1EC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E1EC8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E1ECC: jr          $ra
    // 0x801E1ED0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E1ED0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e1ed4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e1ed4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1ED4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E1ED8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E1EDC: jr          $ra
    // 0x801E1EE0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E1EE0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e1ee4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e1ee4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1EE4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E1EE8: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e1eec(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e1eec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1EEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801E1EF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801E1EF4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801E1EF8: beq         $t6, $zero, L_801E1F08
    if (ctx->r14 == 0) {
        // 0x801E1EFC: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_801E1F08;
    }
    // 0x801E1EFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801E1F00: b           L_801E1F40
    // 0x801E1F04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801E1F40;
    // 0x801E1F04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801E1F08:
    // 0x801E1F08: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801E1F0C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E1F10: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x801E1F14: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801E1F18: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801E1F1C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801E1F20: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801E1F24: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801E1F28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E1F2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E1F30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801E1F34: jal         0x8038C97C
    // 0x801E1F38: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_0;
    // 0x801E1F38: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x801E1F3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E1F40:
    // 0x801E1F40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801E1F44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801E1F48: jr          $ra
    // 0x801E1F4C: nop

    return;
    // 0x801E1F4C: nop

;}
RECOMP_FUNC void M25_FUN_801e1f50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1F50: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E1F54: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801E1F58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E1F5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E1F60: beq         $t6, $zero, L_801E1F70
    if (ctx->r14 == 0) {
            // 0x801E1F64: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    LOOKUP_FUNC(0x801E1F70)(rdram, ctx);
    return;
    }
    // 0x801E1F64: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x801E1F68: jr          $ra
    // 0x801E1F6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801E1F6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e1f70(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e1f70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1F70: sh          $zero, -0x6CAC($at)
    MEM_H(-0X6CAC, ctx->r1) = 0;
    // 0x801E1F74: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801E1F78: jr          $ra
    // 0x801E1F7C: nop

    return;
    // 0x801E1F7C: nop

;}
RECOMP_FUNC void M25_FUN_801e1f80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1F80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801E1F84: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801E1F88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801E1F8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801E1F90: lui         $a1, 0x89
    ctx->r5 = S32(0X89 << 16);
    // 0x801E1F94: ori         $a1, $a1, 0x5440
    ctx->r5 = ctx->r5 | 0X5440;
    // 0x801E1F98: jal         0x801C0B8C
    // 0x801E1F9C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E1F9C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E1FA0: beq         $v0, $zero, L_801E1FD8
    if (ctx->r2 == 0) {
        // 0x801E1FA4: lui         $a0, 0x801E
        ctx->r4 = S32(0X801E << 16);
            goto L_801E1FD8;
    }
    // 0x801E1FA4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E1FA8: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x801E1FAC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801E1FB0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801E1FB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801E1FB8: lw          $a0, -0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X72A0);
    // 0x801E1FBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E1FC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E1FC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801E1FC8: jal         0x8038C97C
    // 0x801E1FCC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    LOOKUP_FUNC(0x8038C97C)(rdram, ctx);
        goto after_1;
    // 0x801E1FCC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x801E1FD0: b           L_801E1FDC
    // 0x801E1FD4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801E1FDC;
    // 0x801E1FD4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E1FD8:
    // 0x801E1FD8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E1FDC:
    // 0x801E1FDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801E1FE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801E1FE4: jr          $ra
    // 0x801E1FE8: nop

    return;
    // 0x801E1FE8: nop

;}
RECOMP_FUNC void M25_FUN_801e1fec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1FEC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801E1FF0: lbu         $t6, -0x42AC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X42AC);
    // 0x801E1FF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E1FF8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E1FFC: beq         $t6, $zero, L_801E200C
    if (ctx->r14 == 0) {
            // 0x801E2000: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x801E200C)(rdram, ctx);
    return;
    }
    // 0x801E2000: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801E2004: jr          $ra
    // 0x801E2008: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801E2008: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e200c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e200c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E200C: jr          $ra
    // 0x801E2010: nop

    return;
    // 0x801E2010: nop

;}
RECOMP_FUNC void M25_FUN_801e2014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2014: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E2018: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E201C: jr          $ra
    // 0x801E2020: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E2020: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e2024(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e2024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E2028: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E202C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E2030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E2034: lui         $a1, 0x2D
    ctx->r5 = S32(0X2D << 16);
    // 0x801E2038: ori         $a1, $a1, 0xC6C0
    ctx->r5 = ctx->r5 | 0XC6C0;
    // 0x801E203C: jal         0x801C0B8C
    // 0x801E2040: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E2040: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E2044: beq         $v0, $zero, L_801E2060
    if (ctx->r2 == 0) {
        // 0x801E2048: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801E2060;
    }
    // 0x801E2048: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E204C: sw          $zero, -0x2B84($at)
    MEM_W(-0X2B84, ctx->r1) = 0;
    // 0x801E2050: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2054: sw          $zero, -0x2B80($at)
    MEM_W(-0X2B80, ctx->r1) = 0;
    // 0x801E2058: b           L_801E2064
    // 0x801E205C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E2064;
    // 0x801E205C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E2060:
    // 0x801E2060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801E2064:
    // 0x801E2064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E2068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E206C: jr          $ra
    // 0x801E2070: nop

    return;
    // 0x801E2070: nop

;}
RECOMP_FUNC void M25_FUN_801e2074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2074: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801E2078: lw          $v1, -0x2B80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2B80);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e207c(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e207c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E207C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801E2080: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E2084: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x801E2088: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801E208C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801E2090: bne         $at, $zero, L_801E2210
    if (ctx->r1 != 0) {
        // 0x801E2094: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_801E2210;
    }
    // 0x801E2094: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801E2098: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801E209C: lw          $v0, -0x2B84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2B84);
    // 0x801E20A0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801E20A4: bgez        $v0, L_801E20B4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801E20A8: sra         $s0, $v0, 4
        ctx->r16 = S32(SIGNED(ctx->r2) >> 4);
            goto L_801E20B4;
    }
    // 0x801E20A8: sra         $s0, $v0, 4
    ctx->r16 = S32(SIGNED(ctx->r2) >> 4);
    // 0x801E20AC: addiu       $at, $v0, 0xF
    ctx->r1 = ADD32(ctx->r2, 0XF);
    // 0x801E20B0: sra         $s0, $at, 4
    ctx->r16 = S32(SIGNED(ctx->r1) >> 4);
L_801E20B4:
    // 0x801E20B4: bgez        $v0, L_801E20C8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801E20B8: andi        $t6, $v0, 0xF
        ctx->r14 = ctx->r2 & 0XF;
            goto L_801E20C8;
    }
    // 0x801E20B8: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x801E20BC: beq         $t6, $zero, L_801E20C8
    if (ctx->r14 == 0) {
        // 0x801E20C0: nop
    
            goto L_801E20C8;
    }
    // 0x801E20C0: nop

    // 0x801E20C4: addiu       $t6, $t6, -0x10
    ctx->r14 = ADD32(ctx->r14, -0X10);
L_801E20C8:
    // 0x801E20C8: jal         0x801302CC
    // 0x801E20CC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_0;
    // 0x801E20CC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x801E20D0: beq         $v0, $zero, L_801E20DC
    if (ctx->r2 == 0) {
        // 0x801E20D4: addiu       $t7, $zero, -0x14
        ctx->r15 = ADD32(0, -0X14);
            goto L_801E20DC;
    }
    // 0x801E20D4: addiu       $t7, $zero, -0x14
    ctx->r15 = ADD32(0, -0X14);
    // 0x801E20D8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_801E20DC:
    // 0x801E20DC: bne         $s0, $zero, L_801E2138
    if (ctx->r16 != 0) {
        // 0x801E20E0: lui         $a1, 0x8020
        ctx->r5 = S32(0X8020 << 16);
            goto L_801E2138;
    }
    // 0x801E20E0: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801E20E4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801E20E8: lui         $s0, 0x8020
    ctx->r16 = S32(0X8020 << 16);
    // 0x801E20EC: addiu       $s0, $s0, -0x2B78
    ctx->r16 = ADD32(ctx->r16, -0X2B78);
    // 0x801E20F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801E20F4: lw          $a1, -0x5084($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5084);
    // 0x801E20F8: jal         0x8038CAF4
    // 0x801E20FC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    LOOKUP_FUNC(0x8038CAF4)(rdram, ctx);
        goto after_1;
    // 0x801E20FC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_1:
    // 0x801E2100: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801E2104: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x801E2108: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E210C: addiu       $a2, $a2, 0xAA
    ctx->r6 = ADD32(ctx->r6, 0XAA);
    // 0x801E2110: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801E2114: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x801E2118: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x801E211C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x801E2120: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801E2124: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801E2128: jal         0x8001B204
    // 0x801E212C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801E212C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x801E2130: b           L_801E21C0
    // 0x801E2134: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
        goto L_801E21C0;
    // 0x801E2134: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_801E2138:
    // 0x801E2138: lui         $s0, 0x8020
    ctx->r16 = S32(0X8020 << 16);
    // 0x801E213C: addiu       $s0, $s0, -0x2B78
    ctx->r16 = ADD32(ctx->r16, -0X2B78);
    // 0x801E2140: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801E2144: lw          $a1, -0x5084($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5084);
    // 0x801E2148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801E214C: jal         0x8038CAF4
    // 0x801E2150: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    LOOKUP_FUNC(0x8038CAF4)(rdram, ctx);
        goto after_3;
    // 0x801E2150: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_3:
    // 0x801E2154: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801E2158: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E215C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801E2160: addiu       $a2, $a2, 0xAA
    ctx->r6 = ADD32(ctx->r6, 0XAA);
    // 0x801E2164: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801E2168: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801E216C: jal         0x8001B204
    // 0x801E2170: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_4;
    // 0x801E2170: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x801E2174: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801E2178: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801E217C: lw          $a1, -0x5080($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5080);
    // 0x801E2180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801E2184: jal         0x8038CAF4
    // 0x801E2188: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    LOOKUP_FUNC(0x8038CAF4)(rdram, ctx);
        goto after_5;
    // 0x801E2188: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_5:
    // 0x801E218C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801E2190: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x801E2194: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801E2198: addiu       $a2, $a2, 0xBA
    ctx->r6 = ADD32(ctx->r6, 0XBA);
    // 0x801E219C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801E21A0: addu        $v1, $s0, $t9
    ctx->r3 = ADD32(ctx->r16, ctx->r25);
    // 0x801E21A4: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x801E21A8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x801E21AC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801E21B0: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801E21B4: jal         0x8001B204
    // 0x801E21B8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_6;
    // 0x801E21B8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x801E21BC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_801E21C0:
    // 0x801E21C0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801E21C4: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x801E21C8: beq         $v0, $at, L_801E21E0
    if (ctx->r2 == ctx->r1) {
        // 0x801E21CC: nop
    
            goto L_801E21E0;
    }
    // 0x801E21CC: nop

    // 0x801E21D0: beq         $v0, $zero, L_801E21E0
    if (ctx->r2 == 0) {
        // 0x801E21D4: nop
    
            goto L_801E21E0;
    }
    // 0x801E21D4: nop

    // 0x801E21D8: jal         0x8038D28C
    // 0x801E21DC: addiu       $a0, $zero, 0x1C9
    ctx->r4 = ADD32(0, 0X1C9);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_7;
    // 0x801E21DC: addiu       $a0, $zero, 0x1C9
    ctx->r4 = ADD32(0, 0X1C9);
    after_7:
L_801E21E0:
    // 0x801E21E0: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801E21E4: addiu       $v0, $v0, -0x2B84
    ctx->r2 = ADD32(ctx->r2, -0X2B84);
    // 0x801E21E8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801E21EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801E21F0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801E21F4: slti        $at, $t1, 0x20
    ctx->r1 = SIGNED(ctx->r9) < 0X20 ? 1 : 0;
    // 0x801E21F8: bne         $at, $zero, L_801E2208
    if (ctx->r1 != 0) {
        // 0x801E21FC: sw          $t1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r9;
            goto L_801E2208;
    }
    // 0x801E21FC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801E2200: b           L_801E2220
    // 0x801E2204: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801E2220;
    // 0x801E2204: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E2208:
    // 0x801E2208: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E220C: sw          $zero, -0x2B80($at)
    MEM_W(-0X2B80, ctx->r1) = 0;
L_801E2210:
    // 0x801E2210: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x801E2214: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2218: sw          $t3, -0x2B80($at)
    MEM_W(-0X2B80, ctx->r1) = ctx->r11;
    // 0x801E221C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E2220:
    // 0x801E2220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E2224: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801E2228: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801E222C: jr          $ra
    // 0x801E2230: nop

    return;
    // 0x801E2230: nop

;}
RECOMP_FUNC void M25_FUN_801e2234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2234: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E2238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E223C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E2240: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E2244: lui         $a3, 0x8020
    ctx->r7 = S32(0X8020 << 16);
    // 0x801E2248: addiu       $a3, $a3, -0x4430
    ctx->r7 = ADD32(ctx->r7, -0X4430);
    // 0x801E224C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E2250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E2254: jal         0x8001B204
    // 0x801E2258: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801E2258: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801E225C: lui         $a3, 0x8020
    ctx->r7 = S32(0X8020 << 16);
    // 0x801E2260: addiu       $a3, $a3, -0x442C
    ctx->r7 = ADD32(ctx->r7, -0X442C);
    // 0x801E2264: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801E2268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E226C: jal         0x8001B204
    // 0x801E2270: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801E2270: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801E2274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E2278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E227C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801E2280: jr          $ra
    // 0x801E2284: nop

    return;
    // 0x801E2284: nop

;}
RECOMP_FUNC void M25_FUN_801e2288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2288: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E228C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E2290: jr          $ra
    // 0x801E2294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801E2294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e2298(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e2298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2298: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E229C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E22A0: jr          $ra
    // 0x801E22A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801E22A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e22a8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e22a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E22A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E22AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E22B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E22B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E22B8: jal         0x8038D28C
    // 0x801E22BC: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_0;
    // 0x801E22BC: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    after_0:
    // 0x801E22C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E22C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E22C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801E22CC: jr          $ra
    // 0x801E22D0: nop

    return;
    // 0x801E22D0: nop

;}
RECOMP_FUNC void M25_FUN_801e22d4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E22D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E22D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E22DC: jr          $ra
    // 0x801E22E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E22E0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e22e4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e22e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E22E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E22E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E22EC: jr          $ra
    // 0x801E22F0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801E22F0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e22f4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e22f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E22F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E22F8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801E22FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E2300: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E2304: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E2308: jal         0x8038BEC8
    // 0x801E230C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x8038BEC8)(rdram, ctx);
        goto after_0;
    // 0x801E230C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801E2310: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x801E2314: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E2318: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801E231C: jal         0x8038BD50
    // 0x801E2320: lui         $a2, 0x4190
    ctx->r6 = S32(0X4190 << 16);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E2320: lui         $a2, 0x4190
    ctx->r6 = S32(0X4190 << 16);
    after_1:
    // 0x801E2324: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801E2328: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x801E232C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E2330: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801E2334: jal         0x8038BD88
    // 0x801E2338: nop

    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E2338: nop

    after_2:
    // 0x801E233C: lui         $a1, 0x35
    ctx->r5 = S32(0X35 << 16);
    // 0x801E2340: ori         $a1, $a1, 0x67E0
    ctx->r5 = ctx->r5 | 0X67E0;
    // 0x801E2344: jal         0x801C0B8C
    // 0x801E2348: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_3;
    // 0x801E2348: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_3:
    // 0x801E234C: beq         $v0, $zero, L_801E2364
    if (ctx->r2 == 0) {
        // 0x801E2350: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801E2364;
    }
    // 0x801E2350: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2354: jal         0x8038C158
    // 0x801E2358: sw          $zero, -0x5028($at)
    MEM_W(-0X5028, ctx->r1) = 0;
    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_4;
    // 0x801E2358: sw          $zero, -0x5028($at)
    MEM_W(-0X5028, ctx->r1) = 0;
    after_4:
    // 0x801E235C: b           L_801E2368
    // 0x801E2360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E2368;
    // 0x801E2360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E2364:
    // 0x801E2364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801E2368:
    // 0x801E2368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E236C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E2370: jr          $ra
    // 0x801E2374: nop

    return;
    // 0x801E2374: nop

;}
RECOMP_FUNC void M25_FUN_801e2378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2378: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801E237C: lw          $v0, -0x5028($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5028);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e2380(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e2380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2380: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801E2384: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801E2388: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801E238C: beq         $v0, $zero, L_801E23A8
    if (ctx->r2 == 0) {
        // 0x801E2390: sw          $a1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r5;
            goto L_801E23A8;
    }
    // 0x801E2390: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801E2394: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801E2398: beq         $v0, $at, L_801E2468
    if (ctx->r2 == ctx->r1) {
        // 0x801E239C: lui         $a2, 0xC192
        ctx->r6 = S32(0XC192 << 16);
            goto L_801E2468;
    }
    // 0x801E239C: lui         $a2, 0xC192
    ctx->r6 = S32(0XC192 << 16);
    // 0x801E23A0: b           L_801E2550
    // 0x801E23A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E2550;
    // 0x801E23A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E23A8:
    // 0x801E23A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E23AC: lwc1        $f0, -0x432C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X432C);
    // 0x801E23B0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E23B4: lwc1        $f2, -0x4328($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4328);
    // 0x801E23B8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E23BC: lwc1        $f14, -0x4324($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4324);
    // 0x801E23C0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E23C4: lwc1        $f4, -0x4320($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4320);
    // 0x801E23C8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E23CC: lwc1        $f6, -0x431C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X431C);
    // 0x801E23D0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E23D4: lwc1        $f8, -0x4318($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4318);
    // 0x801E23D8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E23DC: lwc1        $f10, -0x4314($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4314);
    // 0x801E23E0: lui         $at, 0x4148
    ctx->r1 = S32(0X4148 << 16);
    // 0x801E23E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801E23E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E23EC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E23F0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801E23F4: lwc1        $f6, -0x4310($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4310);
    // 0x801E23F8: lui         $at, 0xC19C
    ctx->r1 = S32(0XC19C << 16);
    // 0x801E23FC: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801E2400: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E2404: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2408: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x801E240C: lwc1        $f10, -0x430C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X430C);
    // 0x801E2410: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2414: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x801E2418: lwc1        $f4, -0x4308($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4308);
    // 0x801E241C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801E2420: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801E2424: lui         $a2, 0xC170
    ctx->r6 = S32(0XC170 << 16);
    // 0x801E2428: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801E242C: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x801E2430: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x801E2434: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x801E2438: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x801E243C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x801E2440: jal         0x8038C17C
    // 0x801E2444: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_0;
    // 0x801E2444: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801E2448: beql        $v0, $zero, L_801E2550
    if (ctx->r2 == 0) {
        // 0x801E244C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801E2550;
    }
    goto skip_0;
    // 0x801E244C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801E2450: jal         0x8038C158
    // 0x801E2454: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_1;
    // 0x801E2454: nop

    after_1:
    // 0x801E2458: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801E245C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2460: b           L_801E254C
    // 0x801E2464: sw          $t6, -0x5028($at)
    MEM_W(-0X5028, ctx->r1) = ctx->r14;
        goto L_801E254C;
    // 0x801E2464: sw          $t6, -0x5028($at)
    MEM_W(-0X5028, ctx->r1) = ctx->r14;
L_801E2468:
    // 0x801E2468: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E246C: lwc1        $f0, -0x4304($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4304);
    // 0x801E2470: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x801E2474: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801E2478: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x801E247C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801E2480: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801E2484: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801E2488: lui         $at, 0x40E8
    ctx->r1 = S32(0X40E8 << 16);
    // 0x801E248C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E2490: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2494: lwc1        $f6, -0x4300($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4300);
    // 0x801E2498: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E249C: lwc1        $f8, -0x42FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X42FC);
    // 0x801E24A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E24A4: lwc1        $f10, -0x42F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X42F8);
    // 0x801E24A8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E24AC: lwc1        $f4, -0x42F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X42F4);
    // 0x801E24B0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801E24B4: lui         $a3, 0x41A3
    ctx->r7 = S32(0X41A3 << 16);
    // 0x801E24B8: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x801E24BC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801E24C0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801E24C4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801E24C8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801E24CC: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x801E24D0: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x801E24D4: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x801E24D8: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x801E24DC: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x801E24E0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801E24E4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801E24E8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801E24EC: jal         0x8038C17C
    // 0x801E24F0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_2;
    // 0x801E24F0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x801E24F4: beq         $v0, $zero, L_801E254C
    if (ctx->r2 == 0) {
        // 0x801E24F8: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801E254C;
    }
    // 0x801E24F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E24FC: jal         0x8038BE98
    // 0x801E2500: lwc1        $f12, -0x42F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X42F0);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_3;
    // 0x801E2500: lwc1        $f12, -0x42F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X42F0);
    after_3:
    // 0x801E2504: jal         0x8038D28C
    // 0x801E2508: addiu       $a0, $zero, 0x695
    ctx->r4 = ADD32(0, 0X695);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_4;
    // 0x801E2508: addiu       $a0, $zero, 0x695
    ctx->r4 = ADD32(0, 0X695);
    after_4:
    // 0x801E250C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2510: lwc1        $f12, -0x42EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X42EC);
    // 0x801E2514: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2518: lui         $a2, 0x42C1
    ctx->r6 = S32(0X42C1 << 16);
    // 0x801E251C: ori         $a2, $a2, 0x3C6A
    ctx->r6 = ctx->r6 | 0X3C6A;
    // 0x801E2520: jal         0x8038BD50
    // 0x801E2524: lwc1        $f14, -0x42E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X42E8);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_5;
    // 0x801E2524: lwc1        $f14, -0x42E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X42E8);
    after_5:
    // 0x801E2528: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E252C: lwc1        $f12, -0x42E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X42E4);
    // 0x801E2530: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2534: lui         $a2, 0x429B
    ctx->r6 = S32(0X429B << 16);
    // 0x801E2538: ori         $a2, $a2, 0xCCD
    ctx->r6 = ctx->r6 | 0XCCD;
    // 0x801E253C: jal         0x8038BD88
    // 0x801E2540: lwc1        $f14, -0x42E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X42E0);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_6;
    // 0x801E2540: lwc1        $f14, -0x42E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X42E0);
    after_6:
    // 0x801E2544: b           L_801E2550
    // 0x801E2548: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801E2550;
    // 0x801E2548: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E254C:
    // 0x801E254C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E2550:
    // 0x801E2550: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801E2554: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801E2558: jr          $ra
    // 0x801E255C: nop

    return;
    // 0x801E255C: nop

;}
RECOMP_FUNC void M25_FUN_801e2560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E2564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E2568: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E256C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E2570: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801E2574: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801E2578: jal         0x801CCE50
    // 0x801E257C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_0;
    // 0x801E257C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_0:
    // 0x801E2580: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E2584: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801E2588: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801E258C: jal         0x801CCE88
    // 0x801E2590: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_1;
    // 0x801E2590: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_1:
    // 0x801E2594: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E2598: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E259C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E25A0: jal         0x801CCEC8
    // 0x801E25A4: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_2;
    // 0x801E25A4: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    after_2:
    // 0x801E25A8: lui         $a1, 0x176
    ctx->r5 = S32(0X176 << 16);
    // 0x801E25AC: ori         $a1, $a1, 0x9A70
    ctx->r5 = ctx->r5 | 0X9A70;
    // 0x801E25B0: jal         0x801C0B8C
    // 0x801E25B4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_3;
    // 0x801E25B4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_3:
    // 0x801E25B8: beq         $v0, $zero, L_801E268C
    if (ctx->r2 == 0) {
        // 0x801E25BC: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_801E268C;
    }
    // 0x801E25BC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801E25C0: addiu       $v1, $v1, -0x4410
    ctx->r3 = ADD32(ctx->r3, -0X4410);
    // 0x801E25C4: lw          $t6, 0xE8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XE8);
    // 0x801E25C8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E25CC: lwc1        $f6, -0x42DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X42DC);
    // 0x801E25D0: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801E25D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E25D8: lui         $a1, 0x1D9
    ctx->r5 = S32(0X1D9 << 16);
    // 0x801E25DC: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801E25E0: ori         $a1, $a1, 0xC910
    ctx->r5 = ctx->r5 | 0XC910;
    // 0x801E25E4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E25E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E25EC: swc1        $f8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f8.u32l;
    // 0x801E25F0: lw          $t7, 0xE8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XE8);
    // 0x801E25F4: lwc1        $f16, -0x42D8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X42D8);
    // 0x801E25F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E25FC: lw          $v0, 0x2C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X2C);
    // 0x801E2600: lwc1        $f10, 0x34($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801E2604: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E2608: swc1        $f18, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f18.u32l;
    // 0x801E260C: lw          $t8, 0xE8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XE8);
    // 0x801E2610: lwc1        $f6, -0x42D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X42D4);
    // 0x801E2614: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2618: lw          $v0, 0x2C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X2C);
    // 0x801E261C: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801E2620: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E2624: swc1        $f8, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f8.u32l;
    // 0x801E2628: lw          $t9, 0xE8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XE8);
    // 0x801E262C: lwc1        $f16, -0x42D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X42D0);
    // 0x801E2630: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2634: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x801E2638: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801E263C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E2640: swc1        $f18, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f18.u32l;
    // 0x801E2644: lw          $t0, 0xE8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XE8);
    // 0x801E2648: lwc1        $f6, -0x42CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X42CC);
    // 0x801E264C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2650: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    // 0x801E2654: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801E2658: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801E265C: swc1        $f8, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f8.u32l;
    // 0x801E2660: lw          $t1, 0xE8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XE8);
    // 0x801E2664: lwc1        $f16, -0x42C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X42C8);
    // 0x801E2668: lw          $v0, 0x2C($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X2C);
    // 0x801E266C: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801E2670: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801E2674: jal         0x801C0B8C
    // 0x801E2678: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_4;
    // 0x801E2678: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    after_4:
    // 0x801E267C: beql        $v0, $zero, L_801E2690
    if (ctx->r2 == 0) {
        // 0x801E2680: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_801E2690;
    }
    goto skip_0;
    // 0x801E2680: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x801E2684: b           L_801E2690
    // 0x801E2688: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_801E2690;
    // 0x801E2688: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E268C:
    // 0x801E268C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E2690:
    // 0x801E2690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E2694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E2698: jr          $ra
    // 0x801E269C: nop

    return;
    // 0x801E269C: nop

;}
RECOMP_FUNC void M25_FUN_801e26a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E26A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E26A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E26A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E26AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E26B0: lui         $a1, 0x294
    ctx->r5 = S32(0X294 << 16);
    // 0x801E26B4: ori         $a1, $a1, 0xB4A0
    ctx->r5 = ctx->r5 | 0XB4A0;
    // 0x801E26B8: jal         0x801C0B8C
    // 0x801E26BC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E26BC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E26C0: beq         $v0, $zero, L_801E2724
    if (ctx->r2 == 0) {
        // 0x801E26C4: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801E2724;
    }
    // 0x801E26C4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E26C8: lwc1        $f12, -0x42C4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X42C4);
    // 0x801E26CC: lui         $at, 0x41AC
    ctx->r1 = S32(0X41AC << 16);
    // 0x801E26D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E26D4: jal         0x8038BD50
    // 0x801E26D8: lui         $a2, 0x41D8
    ctx->r6 = S32(0X41D8 << 16);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E26D8: lui         $a2, 0x41D8
    ctx->r6 = S32(0X41D8 << 16);
    after_1:
    // 0x801E26DC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E26E0: lwc1        $f12, -0x42C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X42C0);
    // 0x801E26E4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E26E8: lui         $a2, 0x3E23
    ctx->r6 = S32(0X3E23 << 16);
    // 0x801E26EC: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x801E26F0: jal         0x8038BD88
    // 0x801E26F4: lwc1        $f14, -0x42BC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X42BC);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E26F4: lwc1        $f14, -0x42BC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X42BC);
    after_2:
    // 0x801E26F8: jal         0x8038D28C
    // 0x801E26FC: addiu       $a0, $zero, 0x694
    ctx->r4 = ADD32(0, 0X694);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_3;
    // 0x801E26FC: addiu       $a0, $zero, 0x694
    ctx->r4 = ADD32(0, 0X694);
    after_3:
    // 0x801E2700: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801E2704: jal         0x80006214
    // 0x801E2708: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_4;
    // 0x801E2708: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_4:
    // 0x801E270C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x801E2710: lw          $t6, -0x2560($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2560);
    // 0x801E2714: jal         0x8038C158
    // 0x801E2718: sb          $zero, 0x22($t6)
    MEM_B(0X22, ctx->r14) = 0;
    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_5;
    // 0x801E2718: sb          $zero, 0x22($t6)
    MEM_B(0X22, ctx->r14) = 0;
    after_5:
    // 0x801E271C: b           L_801E2728
    // 0x801E2720: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801E2728;
    // 0x801E2720: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801E2724:
    // 0x801E2724: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801E2728:
    // 0x801E2728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E272C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E2730: jr          $ra
    // 0x801E2734: nop

    return;
    // 0x801E2734: nop

;}
RECOMP_FUNC void M25_FUN_801e2738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2738: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801E273C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801E2740: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801E2744: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801E2748: lui         $a1, 0x2C2
    ctx->r5 = S32(0X2C2 << 16);
    // 0x801E274C: ori         $a1, $a1, 0x7B60
    ctx->r5 = ctx->r5 | 0X7B60;
    // 0x801E2750: jal         0x801C0B8C
    // 0x801E2754: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E2754: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E2758: beq         $v0, $zero, L_801E2780
    if (ctx->r2 == 0) {
        // 0x801E275C: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_801E2780;
    }
    // 0x801E275C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801E2760: lui         $a1, 0x2CA
    ctx->r5 = S32(0X2CA << 16);
    // 0x801E2764: ori         $a1, $a1, 0x1C80
    ctx->r5 = ctx->r5 | 0X1C80;
    // 0x801E2768: jal         0x801C0B8C
    // 0x801E276C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801E276C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_1:
    // 0x801E2770: beql        $v0, $zero, L_801E282C
    if (ctx->r2 == 0) {
        // 0x801E2774: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_801E282C;
    }
    goto skip_0;
    // 0x801E2774: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    skip_0:
    // 0x801E2778: b           L_801E282C
    // 0x801E277C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801E282C;
    // 0x801E277C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801E2780:
    // 0x801E2780: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E2784: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2788: lwc1        $f4, -0x42B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X42B8);
    // 0x801E278C: lui         $at, 0xC198
    ctx->r1 = S32(0XC198 << 16);
    // 0x801E2790: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E2794: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2798: lwc1        $f8, -0x42B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X42B4);
    // 0x801E279C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E27A0: lwc1        $f10, -0x42B0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X42B0);
    // 0x801E27A4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E27A8: lwc1        $f16, -0x42AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X42AC);
    // 0x801E27AC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E27B0: lwc1        $f18, -0x42A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X42A8);
    // 0x801E27B4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E27B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801E27BC: lwc1        $f4, -0x42A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X42A4);
    // 0x801E27C0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E27C4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801E27C8: lwc1        $f6, -0x42A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X42A0);
    // 0x801E27CC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E27D0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801E27D4: lwc1        $f8, -0x429C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X429C);
    // 0x801E27D8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E27DC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801E27E0: lwc1        $f10, -0x4298($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4298);
    // 0x801E27E4: lui         $at, 0x41CC
    ctx->r1 = S32(0X41CC << 16);
    // 0x801E27E8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801E27EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801E27F0: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x801E27F4: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x801E27F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801E27FC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801E2800: lui         $a2, 0xC190
    ctx->r6 = S32(0XC190 << 16);
    // 0x801E2804: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801E2808: lui         $a3, 0x41A4
    ctx->r7 = S32(0X41A4 << 16);
    // 0x801E280C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801E2810: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801E2814: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x801E2818: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x801E281C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x801E2820: jal         0x8038C17C
    // 0x801E2824: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_2;
    // 0x801E2824: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x801E2828: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801E282C:
    // 0x801E282C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801E2830: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801E2834: jr          $ra
    // 0x801E2838: nop

    return;
    // 0x801E2838: nop

;}
RECOMP_FUNC void M25_FUN_801e283c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E283C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E2840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E2844: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E284C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E2850: jal         0x8038BE98
    // 0x801E2854: lwc1        $f12, -0x4294($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4294);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_0;
    // 0x801E2854: lwc1        $f12, -0x4294($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4294);
    after_0:
    // 0x801E2858: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E285C: lwc1        $f12, -0x4290($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4290);
    // 0x801E2860: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2864: lui         $a2, 0x41D8
    ctx->r6 = S32(0X41D8 << 16);
    // 0x801E2868: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801E286C: jal         0x8038BD50
    // 0x801E2870: lwc1        $f14, -0x428C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X428C);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_1;
    // 0x801E2870: lwc1        $f14, -0x428C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X428C);
    after_1:
    // 0x801E2874: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2878: lwc1        $f12, -0x4288($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4288);
    // 0x801E287C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2880: lui         $a2, 0xC066
    ctx->r6 = S32(0XC066 << 16);
    // 0x801E2884: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801E2888: jal         0x8038BD88
    // 0x801E288C: lwc1        $f14, -0x4284($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4284);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_2;
    // 0x801E288C: lwc1        $f14, -0x4284($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4284);
    after_2:
    // 0x801E2890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E2894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E2898: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x801E289C: jr          $ra
    // 0x801E28A0: nop

    return;
    // 0x801E28A0: nop

;}
RECOMP_FUNC void M25_FUN_801e28a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E28A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E28A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E28AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E28B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E28B4: lui         $a1, 0x36A
    ctx->r5 = S32(0X36A << 16);
    // 0x801E28B8: ori         $a1, $a1, 0x5420
    ctx->r5 = ctx->r5 | 0X5420;
    // 0x801E28BC: jal         0x801C0B8C
    // 0x801E28C0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E28C0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E28C4: beq         $v0, $zero, L_801E2924
    if (ctx->r2 == 0) {
        // 0x801E28C8: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801E2924;
    }
    // 0x801E28C8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E28CC: lui         $a1, 0x3F3
    ctx->r5 = S32(0X3F3 << 16);
    // 0x801E28D0: jal         0x801C0B8C
    // 0x801E28D4: ori         $a1, $a1, 0xA860
    ctx->r5 = ctx->r5 | 0XA860;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801E28D4: ori         $a1, $a1, 0xA860
    ctx->r5 = ctx->r5 | 0XA860;
    after_1:
    // 0x801E28D8: beq         $v0, $zero, L_801E28E8
    if (ctx->r2 == 0) {
        // 0x801E28DC: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801E28E8;
    }
    // 0x801E28DC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E28E0: b           L_801E2970
    // 0x801E28E4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_801E2970;
    // 0x801E28E4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801E28E8:
    // 0x801E28E8: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E28EC: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E28F0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E28F4: lwc1        $f0, -0x4280($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4280);
    // 0x801E28F8: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801E28FC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x801E2900: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801E2904: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x801E2908: swc1        $f6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f6.u32l;
    // 0x801E290C: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x801E2910: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801E2914: lwc1        $f8, 0x40($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801E2918: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801E291C: b           L_801E2970
    // 0x801E2920: swc1        $f10, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f10.u32l;
        goto L_801E2970;
    // 0x801E2920: swc1        $f10, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f10.u32l;
L_801E2924:
    // 0x801E2924: lui         $a1, 0x30A
    ctx->r5 = S32(0X30A << 16);
    // 0x801E2928: ori         $a1, $a1, 0x32C0
    ctx->r5 = ctx->r5 | 0X32C0;
    // 0x801E292C: jal         0x801C0B8C
    // 0x801E2930: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_2;
    // 0x801E2930: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_2:
    // 0x801E2934: beq         $v0, $zero, L_801E296C
    if (ctx->r2 == 0) {
        // 0x801E2938: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801E296C;
    }
    // 0x801E2938: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E293C: lwc1        $f12, -0x427C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X427C);
    // 0x801E2940: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2944: lwc1        $f14, -0x4278($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4278);
    // 0x801E2948: jal         0x8038BD50
    // 0x801E294C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_3;
    // 0x801E294C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_3:
    // 0x801E2950: lui         $at, 0x428F
    ctx->r1 = S32(0X428F << 16);
    // 0x801E2954: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E2958: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E295C: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    // 0x801E2960: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801E2964: jal         0x8038BD88
    // 0x801E2968: lwc1        $f14, -0x4274($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4274);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_4;
    // 0x801E2968: lwc1        $f14, -0x4274($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4274);
    after_4:
L_801E296C:
    // 0x801E296C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801E2970:
    // 0x801E2970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E2974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E2978: jr          $ra
    // 0x801E297C: nop

    return;
    // 0x801E297C: nop

;}
RECOMP_FUNC void M25_FUN_801e2980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E2984: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E2988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E298C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E2990: lui         $a1, 0x45E
    ctx->r5 = S32(0X45E << 16);
    // 0x801E2994: ori         $a1, $a1, 0x7820
    ctx->r5 = ctx->r5 | 0X7820;
    // 0x801E2998: jal         0x801C0B8C
    // 0x801E299C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E299C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E29A0: beq         $v0, $zero, L_801E29C0
    if (ctx->r2 == 0) {
        // 0x801E29A4: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801E29C0;
    }
    // 0x801E29A4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E29A8: jal         0x8038C158
    // 0x801E29AC: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_1;
    // 0x801E29AC: nop

    after_1:
    // 0x801E29B0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E29B4: sw          $zero, -0x5028($at)
    MEM_W(-0X5028, ctx->r1) = 0;
    // 0x801E29B8: b           L_801E29F8
    // 0x801E29BC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_801E29F8;
    // 0x801E29BC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801E29C0:
    // 0x801E29C0: lwc1        $f12, -0x4270($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4270);
    // 0x801E29C4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E29C8: lui         $a2, 0xC02C
    ctx->r6 = S32(0XC02C << 16);
    // 0x801E29CC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801E29D0: jal         0x8038BD50
    // 0x801E29D4: lwc1        $f14, -0x426C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X426C);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_2;
    // 0x801E29D4: lwc1        $f14, -0x426C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X426C);
    after_2:
    // 0x801E29D8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E29DC: lwc1        $f12, -0x4268($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4268);
    // 0x801E29E0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E29E4: lui         $a2, 0x40C9
    ctx->r6 = S32(0X40C9 << 16);
    // 0x801E29E8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801E29EC: jal         0x8038BD88
    // 0x801E29F0: lwc1        $f14, -0x4264($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4264);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_3;
    // 0x801E29F0: lwc1        $f14, -0x4264($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4264);
    after_3:
    // 0x801E29F4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801E29F8:
    // 0x801E29F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E29FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E2A00: jr          $ra
    // 0x801E2A04: nop

    return;
    // 0x801E2A04: nop

;}
RECOMP_FUNC void M25_FUN_801e2a08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2A08: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801E2A0C: lw          $v0, -0x5028($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5028);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e2a10(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e2a10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2A10: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801E2A14: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801E2A18: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801E2A1C: beq         $v0, $zero, L_801E2A38
    if (ctx->r2 == 0) {
        // 0x801E2A20: sw          $a1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r5;
            goto L_801E2A38;
    }
    // 0x801E2A20: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801E2A24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801E2A28: beq         $v0, $at, L_801E2AFC
    if (ctx->r2 == ctx->r1) {
        // 0x801E2A2C: lui         $a2, 0x4293
        ctx->r6 = S32(0X4293 << 16);
            goto L_801E2AFC;
    }
    // 0x801E2A2C: lui         $a2, 0x4293
    ctx->r6 = S32(0X4293 << 16);
    // 0x801E2A30: b           L_801E2BB4
    // 0x801E2A34: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_801E2BB4;
    // 0x801E2A34: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801E2A38:
    // 0x801E2A38: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2A3C: lwc1        $f2, -0x4260($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4260);
    // 0x801E2A40: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2A44: lwc1        $f16, -0x425C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X425C);
    // 0x801E2A48: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2A4C: lwc1        $f14, -0x4258($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4258);
    // 0x801E2A50: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2A54: lwc1        $f4, -0x4254($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4254);
    // 0x801E2A58: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2A5C: lwc1        $f6, -0x4250($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4250);
    // 0x801E2A60: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2A64: lwc1        $f8, -0x424C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X424C);
    // 0x801E2A68: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2A6C: lwc1        $f10, -0x4248($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4248);
    // 0x801E2A70: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2A74: lwc1        $f18, -0x4244($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4244);
    // 0x801E2A78: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2A7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801E2A80: lwc1        $f4, -0x4240($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4240);
    // 0x801E2A84: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2A88: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801E2A8C: lwc1        $f6, -0x423C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X423C);
    // 0x801E2A90: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2A94: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801E2A98: lwc1        $f8, -0x4238($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4238);
    // 0x801E2A9C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2AA0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801E2AA4: lwc1        $f10, -0x4234($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4234);
    // 0x801E2AA8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801E2AAC: lui         $a2, 0x429B
    ctx->r6 = S32(0X429B << 16);
    // 0x801E2AB0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801E2AB4: lui         $a3, 0x41D4
    ctx->r7 = S32(0X41D4 << 16);
    // 0x801E2AB8: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x801E2ABC: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x801E2AC0: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x801E2AC4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x801E2AC8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801E2ACC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801E2AD0: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x801E2AD4: jal         0x8038C17C
    // 0x801E2AD8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_0;
    // 0x801E2AD8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x801E2ADC: beql        $v0, $zero, L_801E2BB4
    if (ctx->r2 == 0) {
        // 0x801E2AE0: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_801E2BB4;
    }
    goto skip_0;
    // 0x801E2AE0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    skip_0:
    // 0x801E2AE4: jal         0x8038C158
    // 0x801E2AE8: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_1;
    // 0x801E2AE8: nop

    after_1:
    // 0x801E2AEC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801E2AF0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2AF4: b           L_801E2BB0
    // 0x801E2AF8: sw          $t6, -0x5028($at)
    MEM_W(-0X5028, ctx->r1) = ctx->r14;
        goto L_801E2BB0;
    // 0x801E2AF8: sw          $t6, -0x5028($at)
    MEM_W(-0X5028, ctx->r1) = ctx->r14;
L_801E2AFC:
    // 0x801E2AFC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2B00: lwc1        $f0, -0x4230($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4230);
    // 0x801E2B04: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2B08: lwc1        $f2, -0x422C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X422C);
    // 0x801E2B0C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2B10: lwc1        $f16, -0x4228($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4228);
    // 0x801E2B14: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2B18: lwc1        $f14, -0x4224($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4224);
    // 0x801E2B1C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2B20: lwc1        $f18, -0x4220($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4220);
    // 0x801E2B24: lui         $at, 0x4293
    ctx->r1 = S32(0X4293 << 16);
    // 0x801E2B28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E2B2C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2B30: lwc1        $f6, -0x421C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X421C);
    // 0x801E2B34: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x801E2B38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E2B3C: lui         $at, 0x4184
    ctx->r1 = S32(0X4184 << 16);
    // 0x801E2B40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E2B44: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2B48: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801E2B4C: lwc1        $f18, -0x4218($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4218);
    // 0x801E2B50: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2B54: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801E2B58: lwc1        $f4, -0x4214($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4214);
    // 0x801E2B5C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801E2B60: lui         $a3, 0x4182
    ctx->r7 = S32(0X4182 << 16);
    // 0x801E2B64: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x801E2B68: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801E2B6C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801E2B70: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801E2B74: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x801E2B78: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x801E2B7C: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x801E2B80: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801E2B84: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801E2B88: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x801E2B8C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x801E2B90: jal         0x8038C17C
    // 0x801E2B94: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_2;
    // 0x801E2B94: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x801E2B98: beql        $v0, $zero, L_801E2BB4
    if (ctx->r2 == 0) {
        // 0x801E2B9C: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_801E2BB4;
    }
    goto skip_1;
    // 0x801E2B9C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    skip_1:
    // 0x801E2BA0: jal         0x8038C158
    // 0x801E2BA4: nop

    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_3;
    // 0x801E2BA4: nop

    after_3:
    // 0x801E2BA8: b           L_801E2BB4
    // 0x801E2BAC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_801E2BB4;
    // 0x801E2BAC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801E2BB0:
    // 0x801E2BB0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801E2BB4:
    // 0x801E2BB4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801E2BB8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801E2BBC: jr          $ra
    // 0x801E2BC0: nop

    return;
    // 0x801E2BC0: nop

;}
RECOMP_FUNC void M25_FUN_801e2bc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2BC4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801E2BC8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801E2BCC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801E2BD0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801E2BD4: lui         $a1, 0x69D
    ctx->r5 = S32(0X69D << 16);
    // 0x801E2BD8: ori         $a1, $a1, 0x4490
    ctx->r5 = ctx->r5 | 0X4490;
    // 0x801E2BDC: jal         0x801C0B8C
    // 0x801E2BE0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E2BE0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E2BE4: beq         $v0, $zero, L_801E2BF4
    if (ctx->r2 == 0) {
        // 0x801E2BE8: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801E2BF4;
    }
    // 0x801E2BE8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2BEC: b           L_801E2C9C
    // 0x801E2BF0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801E2C9C;
    // 0x801E2BF0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801E2BF4:
    // 0x801E2BF4: lwc1        $f0, -0x4210($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4210);
    // 0x801E2BF8: lui         $at, 0x419C
    ctx->r1 = S32(0X419C << 16);
    // 0x801E2BFC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E2C00: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2C04: lwc1        $f4, -0x420C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X420C);
    // 0x801E2C08: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2C0C: lwc1        $f6, -0x4208($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4208);
    // 0x801E2C10: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2C14: lwc1        $f8, -0x4204($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4204);
    // 0x801E2C18: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2C1C: lwc1        $f10, -0x4200($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4200);
    // 0x801E2C20: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801E2C24: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801E2C28: lui         $at, 0x4178
    ctx->r1 = S32(0X4178 << 16);
    // 0x801E2C2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801E2C30: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2C34: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801E2C38: lwc1        $f4, -0x41FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X41FC);
    // 0x801E2C3C: lui         $at, 0x424A
    ctx->r1 = S32(0X424A << 16);
    // 0x801E2C40: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801E2C44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E2C48: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2C4C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801E2C50: lwc1        $f8, -0x41F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X41F8);
    // 0x801E2C54: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2C58: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801E2C5C: lwc1        $f10, -0x41F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X41F4);
    // 0x801E2C60: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801E2C64: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    // 0x801E2C68: lui         $a3, 0x4121
    ctx->r7 = S32(0X4121 << 16);
    // 0x801E2C6C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x801E2C70: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801E2C74: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x801E2C78: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801E2C7C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801E2C80: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x801E2C84: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801E2C88: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801E2C8C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x801E2C90: jal         0x8038C17C
    // 0x801E2C94: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_1;
    // 0x801E2C94: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801E2C98: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801E2C9C:
    // 0x801E2C9C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801E2CA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801E2CA4: jr          $ra
    // 0x801E2CA8: nop

    return;
    // 0x801E2CA8: nop

;}
RECOMP_FUNC void M25_FUN_801e2cac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2CAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E2CB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E2CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E2CB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E2CBC: lui         $a1, 0x6E8
    ctx->r5 = S32(0X6E8 << 16);
    // 0x801E2CC0: ori         $a1, $a1, 0x930
    ctx->r5 = ctx->r5 | 0X930;
    // 0x801E2CC4: jal         0x801C0B8C
    // 0x801E2CC8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E2CC8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E2CCC: beq         $v0, $zero, L_801E2D80
    if (ctx->r2 == 0) {
        // 0x801E2CD0: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801E2D80;
    }
    // 0x801E2CD0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2CD4: jal         0x8038BE98
    // 0x801E2CD8: lwc1        $f12, -0x41F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X41F0);
    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_1;
    // 0x801E2CD8: lwc1        $f12, -0x41F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X41F0);
    after_1:
    // 0x801E2CDC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2CE0: lwc1        $f12, -0x41EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X41EC);
    // 0x801E2CE4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2CE8: lui         $a2, 0x41B6
    ctx->r6 = S32(0X41B6 << 16);
    // 0x801E2CEC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801E2CF0: jal         0x8038BD50
    // 0x801E2CF4: lwc1        $f14, -0x41E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X41E8);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_2;
    // 0x801E2CF4: lwc1        $f14, -0x41E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X41E8);
    after_2:
    // 0x801E2CF8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2CFC: lwc1        $f12, -0x41E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X41E4);
    // 0x801E2D00: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2D04: lwc1        $f14, -0x41E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X41E0);
    // 0x801E2D08: jal         0x8038BD88
    // 0x801E2D0C: lui         $a2, 0xC060
    ctx->r6 = S32(0XC060 << 16);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_3;
    // 0x801E2D0C: lui         $a2, 0xC060
    ctx->r6 = S32(0XC060 << 16);
    after_3:
    // 0x801E2D10: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801E2D14: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801E2D18: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E2D1C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801E2D20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E2D24: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801E2D28: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801E2D2C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x801E2D30: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801E2D34: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E2D38: addiu       $t8, $zero, 0x1800
    ctx->r24 = ADD32(0, 0X1800);
    // 0x801E2D3C: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x801E2D40: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801E2D44: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801E2D48: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801E2D4C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E2D50: swc1        $f0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f0.u32l;
    // 0x801E2D54: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801E2D58: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801E2D5C: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801E2D60: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E2D64: swc1        $f0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f0.u32l;
    // 0x801E2D68: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801E2D6C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801E2D70: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x801E2D74: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x801E2D78: b           L_801E2D84
    // 0x801E2D7C: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
        goto L_801E2D84;
    // 0x801E2D7C: sh          $t8, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r24;
L_801E2D80:
    // 0x801E2D80: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801E2D84:
    // 0x801E2D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E2D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E2D8C: jr          $ra
    // 0x801E2D90: nop

    return;
    // 0x801E2D90: nop

;}
RECOMP_FUNC void M25_FUN_801e2d94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2D94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E2D98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801E2D9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E2DA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E2DA4: lui         $a1, 0x8DA
    ctx->r5 = S32(0X8DA << 16);
    // 0x801E2DA8: ori         $a1, $a1, 0xFF90
    ctx->r5 = ctx->r5 | 0XFF90;
    // 0x801E2DAC: jal         0x801C0B8C
    // 0x801E2DB0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E2DB0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E2DB4: beq         $v0, $zero, L_801E2DC4
    if (ctx->r2 == 0) {
        // 0x801E2DB8: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801E2DC4;
    }
    // 0x801E2DB8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E2DBC: b           L_801E3298
    // 0x801E2DC0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801E3298;
    // 0x801E2DC0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801E2DC4:
    // 0x801E2DC4: lui         $a1, 0x869
    ctx->r5 = S32(0X869 << 16);
    // 0x801E2DC8: jal         0x801C0B8C
    // 0x801E2DCC: ori         $a1, $a1, 0x5200
    ctx->r5 = ctx->r5 | 0X5200;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801E2DCC: ori         $a1, $a1, 0x5200
    ctx->r5 = ctx->r5 | 0X5200;
    after_1:
    // 0x801E2DD0: beql        $v0, $zero, L_801E2F18
    if (ctx->r2 == 0) {
        // 0x801E2DD4: lui         $a1, 0x79D
        ctx->r5 = S32(0X79D << 16);
            goto L_801E2F18;
    }
    goto skip_0;
    // 0x801E2DD4: lui         $a1, 0x79D
    ctx->r5 = S32(0X79D << 16);
    skip_0:
    // 0x801E2DD8: jal         0x801C0B2C
    // 0x801E2DDC: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_2;
    // 0x801E2DDC: nop

    after_2:
    // 0x801E2DE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E2DE4: jal         0x80034C24
    // 0x801E2DE8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_3;
    // 0x801E2DE8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_3:
    // 0x801E2DEC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2DF0: ldc1        $f4, -0x41D8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X41D8);
    // 0x801E2DF4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2DF8: ldc1        $f8, -0x41D0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X41D0);
    // 0x801E2DFC: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E2E00: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2E04: ldc1        $f4, -0x41C8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X41C8);
    // 0x801E2E08: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2E0C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E2E10: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E2E14: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E2E18: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x801E2E1C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E2E20: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E2E24: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E2E28: ldc1        $f10, -0x41C0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X41C0);
    // 0x801E2E2C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2E30: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E2E34: ldc1        $f16, -0x41B8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X41B8);
    // 0x801E2E38: div.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E2E3C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2E40: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E2E44: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x801E2E48: mul.d       $f12, $f2, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801E2E4C: add.d       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f12.d + ctx->f16.d;
    // 0x801E2E50: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E2E54: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
    // 0x801E2E58: ldc1        $f6, -0x41B0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X41B0);
    // 0x801E2E5C: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E2E60: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2E64: add.d       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f12.d + ctx->f6.d;
    // 0x801E2E68: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E2E6C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E2E70: swc1        $f10, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f10.u32l;
    // 0x801E2E74: ldc1        $f16, -0x41A8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X41A8);
    // 0x801E2E78: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2E7C: ldc1        $f4, -0x41A0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X41A0);
    // 0x801E2E80: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801E2E84: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E2E88: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2E8C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E2E90: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801E2E94: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E2E98: swc1        $f8, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f8.u32l;
    // 0x801E2E9C: ldc1        $f10, -0x4198($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X4198);
    // 0x801E2EA0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2EA4: ldc1        $f18, -0x4190($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X4190);
    // 0x801E2EA8: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801E2EAC: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E2EB0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2EB4: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E2EB8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801E2EBC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E2EC0: swc1        $f6, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f6.u32l;
    // 0x801E2EC4: ldc1        $f8, -0x4188($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X4188);
    // 0x801E2EC8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2ECC: ldc1        $f16, -0x4180($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X4180);
    // 0x801E2ED0: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801E2ED4: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E2ED8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2EDC: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E2EE0: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801E2EE4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E2EE8: swc1        $f4, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f4.u32l;
    // 0x801E2EEC: ldc1        $f6, -0x4178($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X4178);
    // 0x801E2EF0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2EF4: ldc1        $f10, -0x4170($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X4170);
    // 0x801E2EF8: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801E2EFC: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E2F00: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E2F04: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801E2F08: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E2F0C: b           L_801E3298
    // 0x801E2F10: swc1        $f18, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f18.u32l;
        goto L_801E3298;
    // 0x801E2F10: swc1        $f18, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f18.u32l;
    // 0x801E2F14: lui         $a1, 0x79D
    ctx->r5 = S32(0X79D << 16);
L_801E2F18:
    // 0x801E2F18: ori         $a1, $a1, 0x9D90
    ctx->r5 = ctx->r5 | 0X9D90;
    // 0x801E2F1C: jal         0x801C0B8C
    // 0x801E2F20: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_4;
    // 0x801E2F20: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_4:
    // 0x801E2F24: beql        $v0, $zero, L_801E3070
    if (ctx->r2 == 0) {
        // 0x801E2F28: lui         $a1, 0x72B
        ctx->r5 = S32(0X72B << 16);
            goto L_801E3070;
    }
    goto skip_1;
    // 0x801E2F28: lui         $a1, 0x72B
    ctx->r5 = S32(0X72B << 16);
    skip_1:
    // 0x801E2F2C: jal         0x801C0B2C
    // 0x801E2F30: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801E2F30: nop

    after_5:
    // 0x801E2F34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E2F38: jal         0x80034C24
    // 0x801E2F3C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_6;
    // 0x801E2F3C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_6:
    // 0x801E2F40: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2F44: ldc1        $f4, -0x4168($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X4168);
    // 0x801E2F48: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2F4C: ldc1        $f8, -0x4160($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X4160);
    // 0x801E2F50: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E2F54: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2F58: ldc1        $f4, -0x4158($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X4158);
    // 0x801E2F5C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2F60: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E2F64: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E2F68: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E2F6C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x801E2F70: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E2F74: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E2F78: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E2F7C: ldc1        $f10, -0x4150($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X4150);
    // 0x801E2F80: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2F84: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E2F88: div.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E2F8C: ldc1        $f18, -0x4148($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X4148);
    // 0x801E2F90: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2F94: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E2F98: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x801E2F9C: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801E2FA0: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801E2FA4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E2FA8: swc1        $f6, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f6.u32l;
    // 0x801E2FAC: ldc1        $f8, -0x4140($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X4140);
    // 0x801E2FB0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2FB4: ldc1        $f16, -0x4138($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X4138);
    // 0x801E2FB8: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801E2FBC: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E2FC0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2FC4: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E2FC8: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x801E2FCC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E2FD0: swc1        $f4, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f4.u32l;
    // 0x801E2FD4: ldc1        $f6, -0x4130($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X4130);
    // 0x801E2FD8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2FDC: ldc1        $f10, -0x4128($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X4128);
    // 0x801E2FE0: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x801E2FE4: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E2FE8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E2FEC: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E2FF0: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x801E2FF4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801E2FF8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E2FFC: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x801E3000: swc1        $f18, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f18.u32l;
    // 0x801E3004: ldc1        $f4, -0x4120($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X4120);
    // 0x801E3008: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x801E300C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x801E3010: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x801E3014: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801E3018: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E301C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3020: mul.d       $f12, $f2, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x801E3024: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E3028: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801E302C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E3030: swc1        $f16, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f16.u32l;
    // 0x801E3034: ldc1        $f4, -0x4118($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X4118);
    // 0x801E3038: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E303C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3040: add.d       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f12.d + ctx->f4.d;
    // 0x801E3044: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E3048: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E304C: swc1        $f8, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f8.u32l;
    // 0x801E3050: ldc1        $f10, -0x4110($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X4110);
    // 0x801E3054: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E3058: add.d       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f12.d + ctx->f10.d;
    // 0x801E305C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E3060: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E3064: b           L_801E3298
    // 0x801E3068: swc1        $f18, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f18.u32l;
        goto L_801E3298;
    // 0x801E3068: swc1        $f18, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f18.u32l;
    // 0x801E306C: lui         $a1, 0x72B
    ctx->r5 = S32(0X72B << 16);
L_801E3070:
    // 0x801E3070: ori         $a1, $a1, 0x2CB0
    ctx->r5 = ctx->r5 | 0X2CB0;
    // 0x801E3074: jal         0x801C0B8C
    // 0x801E3078: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_7;
    // 0x801E3078: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_7:
    // 0x801E307C: beql        $v0, $zero, L_801E31BC
    if (ctx->r2 == 0) {
        // 0x801E3080: lui         $a1, 0x71B
        ctx->r5 = S32(0X71B << 16);
            goto L_801E31BC;
    }
    goto skip_2;
    // 0x801E3080: lui         $a1, 0x71B
    ctx->r5 = S32(0X71B << 16);
    skip_2:
    // 0x801E3084: jal         0x801C0B2C
    // 0x801E3088: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_8;
    // 0x801E3088: nop

    after_8:
    // 0x801E308C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801E3090: jal         0x80034C24
    // 0x801E3094: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_9;
    // 0x801E3094: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_9:
    // 0x801E3098: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E309C: ldc1        $f4, -0x4108($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X4108);
    // 0x801E30A0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E30A4: ldc1        $f8, -0x4100($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X4100);
    // 0x801E30A8: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801E30AC: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x801E30B0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801E30B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E30B8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E30BC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E30C0: addiu       $a0, $a0, -0x4410
    ctx->r4 = ADD32(ctx->r4, -0X4410);
    // 0x801E30C4: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E30C8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x801E30CC: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E30D0: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x801E30D4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801E30D8: ldc1        $f10, -0x40F8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X40F8);
    // 0x801E30DC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E30E0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801E30E4: ldc1        $f16, -0x40F0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X40F0);
    // 0x801E30E8: div.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x801E30EC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E30F0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E30F4: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x801E30F8: mul.d       $f12, $f2, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801E30FC: add.d       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f12.d + ctx->f16.d;
    // 0x801E3100: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x801E3104: swc1        $f4, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f4.u32l;
    // 0x801E3108: ldc1        $f6, -0x40E8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X40E8);
    // 0x801E310C: lw          $t2, 0xE8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XE8);
    // 0x801E3110: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3114: add.d       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f12.d + ctx->f6.d;
    // 0x801E3118: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E311C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x801E3120: swc1        $f10, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->f10.u32l;
    // 0x801E3124: ldc1        $f16, -0x40E0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X40E0);
    // 0x801E3128: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E312C: ldc1        $f4, -0x40D8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X40D8);
    // 0x801E3130: mul.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f2.d, ctx->f16.d);
    // 0x801E3134: lw          $t4, 0xE8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XE8);
    // 0x801E3138: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E313C: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E3140: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x801E3144: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E3148: swc1        $f8, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->f8.u32l;
    // 0x801E314C: ldc1        $f10, -0x40D0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X40D0);
    // 0x801E3150: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3154: ldc1        $f18, -0x40C8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X40C8);
    // 0x801E3158: mul.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x801E315C: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x801E3160: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3164: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E3168: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x801E316C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x801E3170: swc1        $f6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f6.u32l;
    // 0x801E3174: ldc1        $f8, -0x40C0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X40C0);
    // 0x801E3178: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E317C: ldc1        $f10, -0x40B8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X40B8);
    // 0x801E3180: mul.d       $f14, $f2, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x801E3184: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x801E3188: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E318C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E3190: add.d       $f16, $f14, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f14.d + ctx->f10.d;
    // 0x801E3194: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x801E3198: swc1        $f18, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f18.u32l;
    // 0x801E319C: ldc1        $f4, -0x40B0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X40B0);
    // 0x801E31A0: lw          $t0, 0xE8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE8);
    // 0x801E31A4: add.d       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f14.d + ctx->f4.d;
    // 0x801E31A8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E31AC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x801E31B0: b           L_801E3298
    // 0x801E31B4: swc1        $f8, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f8.u32l;
        goto L_801E3298;
    // 0x801E31B4: swc1        $f8, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f8.u32l;
    // 0x801E31B8: lui         $a1, 0x71B
    ctx->r5 = S32(0X71B << 16);
L_801E31BC:
    // 0x801E31BC: ori         $a1, $a1, 0xEA70
    ctx->r5 = ctx->r5 | 0XEA70;
    // 0x801E31C0: jal         0x801C0B8C
    // 0x801E31C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_10;
    // 0x801E31C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_10:
    // 0x801E31C8: beq         $v0, $zero, L_801E3294
    if (ctx->r2 == 0) {
        // 0x801E31CC: lui         $at, 0x41C4
        ctx->r1 = S32(0X41C4 << 16);
            goto L_801E3294;
    }
    // 0x801E31CC: lui         $at, 0x41C4
    ctx->r1 = S32(0X41C4 << 16);
    // 0x801E31D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E31D4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E31D8: lui         $a2, 0x40D6
    ctx->r6 = S32(0X40D6 << 16);
    // 0x801E31DC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801E31E0: jal         0x8038BD50
    // 0x801E31E4: lwc1        $f14, -0x40A8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X40A8);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_11;
    // 0x801E31E4: lwc1        $f14, -0x40A8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X40A8);
    after_11:
    // 0x801E31E8: lui         $at, 0x4184
    ctx->r1 = S32(0X4184 << 16);
    // 0x801E31EC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E31F0: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E31F4: lui         $a2, 0x413B
    ctx->r6 = S32(0X413B << 16);
    // 0x801E31F8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801E31FC: jal         0x8038BD88
    // 0x801E3200: lwc1        $f14, -0x40A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X40A4);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_12;
    // 0x801E3200: lwc1        $f14, -0x40A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X40A4);
    after_12:
    // 0x801E3204: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801E3208: addiu       $v0, $v0, -0x54EC
    ctx->r2 = ADD32(ctx->r2, -0X54EC);
    // 0x801E320C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801E3210: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3214: lwc1        $f10, -0x40A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X40A0);
    // 0x801E3218: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801E321C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801E3220: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x801E3224: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x801E3228: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801E322C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E3230: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801E3234: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E3238: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E323C: swc1        $f10, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f10.u32l;
    // 0x801E3240: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801E3244: ori         $a1, $a1, 0x15
    ctx->r5 = ctx->r5 | 0X15;
    // 0x801E3248: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E324C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801E3250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E3254: addiu       $a3, $zero, 0x1001
    ctx->r7 = ADD32(0, 0X1001);
    // 0x801E3258: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801E325C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E3260: swc1        $f16, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f16.u32l;
    // 0x801E3264: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801E3268: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801E326C: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801E3270: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E3274: swc1        $f18, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f18.u32l;
    // 0x801E3278: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801E327C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801E3280: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801E3284: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E3288: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    // 0x801E328C: jal         0x801CC470
    // 0x801E3290: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_13;
    // 0x801E3290: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_13:
L_801E3294:
    // 0x801E3294: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801E3298:
    // 0x801E3298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E329C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E32A0: jr          $ra
    // 0x801E32A4: nop

    return;
    // 0x801E32A4: nop

;}
RECOMP_FUNC void M25_FUN_801e32a8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E32A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E32AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801E32B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E32B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E32B8: lui         $a1, 0x90E
    ctx->r5 = S32(0X90E << 16);
    // 0x801E32BC: ori         $a1, $a1, 0x1D7F
    ctx->r5 = ctx->r5 | 0X1D7F;
    // 0x801E32C0: jal         0x801C0B8C
    // 0x801E32C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801E32C4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801E32C8: beq         $v0, $zero, L_801E33B0
    if (ctx->r2 == 0) {
        // 0x801E32CC: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_801E33B0;
    }
    // 0x801E32CC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801E32D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801E32D4: jal         0x8038BE98
    // 0x801E32D8: nop

    LOOKUP_FUNC(0x8038BE98)(rdram, ctx);
        goto after_1;
    // 0x801E32D8: nop

    after_1:
    // 0x801E32DC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E32E0: lwc1        $f12, -0x409C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X409C);
    // 0x801E32E4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E32E8: lui         $a2, 0x419F
    ctx->r6 = S32(0X419F << 16);
    // 0x801E32EC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801E32F0: jal         0x8038BD50
    // 0x801E32F4: lwc1        $f14, -0x4098($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4098);
    LOOKUP_FUNC(0x8038BD50)(rdram, ctx);
        goto after_2;
    // 0x801E32F4: lwc1        $f14, -0x4098($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4098);
    after_2:
    // 0x801E32F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E32FC: lwc1        $f12, -0x4094($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4094);
    // 0x801E3300: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3304: lui         $a2, 0xBFCC
    ctx->r6 = S32(0XBFCC << 16);
    // 0x801E3308: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801E330C: jal         0x8038BD88
    // 0x801E3310: lwc1        $f14, -0x4090($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4090);
    LOOKUP_FUNC(0x8038BD88)(rdram, ctx);
        goto after_3;
    // 0x801E3310: lwc1        $f14, -0x4090($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4090);
    after_3:
    // 0x801E3314: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E3318: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E331C: lui         $a1, 0x1B8
    ctx->r5 = S32(0X1B8 << 16);
    // 0x801E3320: ori         $a1, $a1, 0x14
    ctx->r5 = ctx->r5 | 0X14;
    // 0x801E3324: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E3328: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E332C: addiu       $a3, $zero, 0x1100
    ctx->r7 = ADD32(0, 0X1100);
    // 0x801E3330: jal         0x801CC470
    // 0x801E3334: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801CC470)(rdram, ctx);
        goto after_4;
    // 0x801E3334: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x801E3338: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801E333C: addiu       $v1, $v1, -0x54EC
    ctx->r3 = ADD32(ctx->r3, -0X54EC);
    // 0x801E3340: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801E3344: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3348: lwc1        $f6, -0x408C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X408C);
    // 0x801E334C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801E3350: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801E3354: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801E3358: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x801E335C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E3360: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801E3364: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x801E3368: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801E336C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x801E3370: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x801E3374: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801E3378: swc1        $f8, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f8.u32l;
    // 0x801E337C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801E3380: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x801E3384: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x801E3388: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801E338C: swc1        $f10, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f10.u32l;
    // 0x801E3390: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801E3394: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801E3398: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x801E339C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801E33A0: jal         0x8038C158
    // 0x801E33A4: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    LOOKUP_FUNC(0x8038C158)(rdram, ctx);
        goto after_5;
    // 0x801E33A4: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    after_5:
    // 0x801E33A8: b           L_801E33B4
    // 0x801E33AC: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_801E33B4;
    // 0x801E33AC: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801E33B0:
    // 0x801E33B0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801E33B4:
    // 0x801E33B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E33B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E33BC: jr          $ra
    // 0x801E33C0: nop

    return;
    // 0x801E33C0: nop

;}
RECOMP_FUNC void M25_FUN_801e33c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E33C4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E33C8: lwc1        $f0, -0x4088($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4088);
    // 0x801E33CC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E33D0: lwc1        $f2, -0x4084($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4084);
    // 0x801E33D4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801E33D8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801E33DC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E33E0: lwc1        $f4, -0x4080($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4080);
    // 0x801E33E4: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E33E8: lwc1        $f6, -0x407C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X407C);
    // 0x801E33EC: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E33F0: lwc1        $f8, -0x4078($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4078);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e33f4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e33f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E33F4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801E33F8: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E33FC: lwc1        $f10, -0x4074($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4074);
    // 0x801E3400: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3404: lwc1        $f16, -0x4070($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4070);
    // 0x801E3408: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E340C: lwc1        $f18, -0x406C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X406C);
    // 0x801E3410: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E3414: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801E3418: lwc1        $f4, -0x4068($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4068);
    // 0x801E341C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801E3420: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801E3424: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E3428: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801E342C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801E3430: lwc1        $f8, -0x4064($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4064);
    // 0x801E3434: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801E3438: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801E343C: lui         $a3, 0x418E
    ctx->r7 = S32(0X418E << 16);
    // 0x801E3440: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801E3444: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801E3448: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801E344C: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x801E3450: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x801E3454: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x801E3458: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x801E345C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801E3460: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801E3464: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x801E3468: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801E346C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x801E3470: jal         0x8038C17C
    // 0x801E3474: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    LOOKUP_FUNC(0x8038C17C)(rdram, ctx);
        goto after_0;
    // 0x801E3474: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801E3478: beq         $v0, $zero, L_801E3488
    if (ctx->r2 == 0) {
        // 0x801E347C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_801E3488;
    }
    // 0x801E347C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801E3480: b           L_801E348C
    // 0x801E3484: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_801E348C;
    // 0x801E3484: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_801E3488:
    // 0x801E3488: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_801E348C:
    // 0x801E348C: jr          $ra
    // 0x801E3490: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801E3490: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e3494(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e3494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E3494: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E3498: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E349C: jr          $ra
    // 0x801E34A0: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    return;
    // 0x801E34A0: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e34a4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e34a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E34A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801E34A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801E34AC: jr          $ra
    // 0x801E34B0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    return;
    // 0x801E34B0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801e34b4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801e34b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E34B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E34B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E34BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E34C0: jal         0x801CD044
    // 0x801E34C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CD044)(rdram, ctx);
        goto after_0;
    // 0x801E34C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801E34C8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E34CC: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801E34D0: lw          $a1, -0x5444($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5444);
    // 0x801E34D4: jal         0x801CCF48
    // 0x801E34D8: lw          $a0, -0x5448($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5448);
    LOOKUP_FUNC(0x801CCF48)(rdram, ctx);
        goto after_1;
    // 0x801E34D8: lw          $a0, -0x5448($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5448);
    after_1:
    // 0x801E34DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E34E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E34E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801E34E8: jr          $ra
    // 0x801E34EC: nop

    return;
    // 0x801E34EC: nop

;}
RECOMP_FUNC void M25_FUN_801e34f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E34F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E34F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E34F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801E34FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801E3500: jal         0x801CCE0C
    // 0x801E3504: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801CCE0C)(rdram, ctx);
        goto after_0;
    // 0x801E3504: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x801E3508: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801E350C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801E3510: jal         0x801CCE50
    // 0x801E3514: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCE50)(rdram, ctx);
        goto after_1;
    // 0x801E3514: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_1:
    // 0x801E3518: jal         0x801BF6B0
    // 0x801E351C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801BF6B0)(rdram, ctx);
        goto after_2;
    // 0x801E351C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801E3520: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x801E3524: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E3528: lui         $a1, 0xB2
    ctx->r5 = S32(0XB2 << 16);
    // 0x801E352C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801E3530: bne         $at, $zero, L_801E3540
    if (ctx->r1 != 0) {
        // 0x801E3534: nop
    
            goto L_801E3540;
    }
    // 0x801E3534: nop

    // 0x801E3538: b           L_801E3600
    // 0x801E353C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801E3600;
    // 0x801E353C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801E3540:
    // 0x801E3540: jal         0x801C0B8C
    // 0x801E3544: ori         $a1, $a1, 0x871F
    ctx->r5 = ctx->r5 | 0X871F;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_3;
    // 0x801E3544: ori         $a1, $a1, 0x871F
    ctx->r5 = ctx->r5 | 0X871F;
    after_3:
    // 0x801E3548: beq         $v0, $zero, L_801E3580
    if (ctx->r2 == 0) {
        // 0x801E354C: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801E3580;
    }
    // 0x801E354C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E3550: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E3554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E3558: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E355C: jal         0x801CCE88
    // 0x801E3560: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_4;
    // 0x801E3560: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    after_4:
    // 0x801E3564: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E3568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E356C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E3570: jal         0x801CCEC8
    // 0x801E3574: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_5;
    // 0x801E3574: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_5:
    // 0x801E3578: b           L_801E3600
    // 0x801E357C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E3600;
    // 0x801E357C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E3580:
    // 0x801E3580: lui         $a1, 0x75
    ctx->r5 = S32(0X75 << 16);
    // 0x801E3584: jal         0x801C0B8C
    // 0x801E3588: ori         $a1, $a1, 0x7E1F
    ctx->r5 = ctx->r5 | 0X7E1F;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_6;
    // 0x801E3588: ori         $a1, $a1, 0x7E1F
    ctx->r5 = ctx->r5 | 0X7E1F;
    after_6:
    // 0x801E358C: beq         $v0, $zero, L_801E35C4
    if (ctx->r2 == 0) {
        // 0x801E3590: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801E35C4;
    }
    // 0x801E3590: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801E3594: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E3598: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E359C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x801E35A0: jal         0x801CCE88
    // 0x801E35A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_7;
    // 0x801E35A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x801E35A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E35AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E35B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E35B4: jal         0x801CCEC8
    // 0x801E35B8: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_8;
    // 0x801E35B8: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_8:
    // 0x801E35BC: b           L_801E3600
    // 0x801E35C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801E3600;
    // 0x801E35C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E35C4:
    // 0x801E35C4: lui         $a1, 0x35
    ctx->r5 = S32(0X35 << 16);
    // 0x801E35C8: jal         0x801C0B8C
    // 0x801E35CC: ori         $a1, $a1, 0x67E0
    ctx->r5 = ctx->r5 | 0X67E0;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_9;
    // 0x801E35CC: ori         $a1, $a1, 0x67E0
    ctx->r5 = ctx->r5 | 0X67E0;
    after_9:
    // 0x801E35D0: beq         $v0, $zero, L_801E35FC
    if (ctx->r2 == 0) {
        // 0x801E35D4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801E35FC;
    }
    // 0x801E35D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E35D8: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801E35DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E35E0: jal         0x801CCE88
    // 0x801E35E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801CCE88)(rdram, ctx);
        goto after_10;
    // 0x801E35E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x801E35E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801E35EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E35F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E35F4: jal         0x801CCEC8
    // 0x801E35F8: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    LOOKUP_FUNC(0x801CCEC8)(rdram, ctx);
        goto after_11;
    // 0x801E35F8: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_11:
L_801E35FC:
    // 0x801E35FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801E3600:
    // 0x801E3600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E3604: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E3608: jr          $ra
    // 0x801E360C: nop

    return;
    // 0x801E360C: nop

;}
