#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M55_FUN_8037f0c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F0C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037F0CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037F0D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8037F0D4: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037F0D8: lb          $t7, 0x96($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X96);
    // 0x8037F0DC: addiu       $v0, $v0, -0x5640
    ctx->r2 = ADD32(ctx->r2, -0X5640);
    // 0x8037F0E0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8037F0E4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8037F0E8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8037F0EC: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x8037F0F0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8037F0F4: addiu       $t9, $t8, 0x4A
    ctx->r25 = ADD32(ctx->r24, 0X4A);
    // 0x8037F0F8: sh          $t9, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r25;
    // 0x8037F0FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8037F100: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8037F104: addiu       $t4, $zero, 0x1A
    ctx->r12 = ADD32(0, 0X1A);
    // 0x8037F108: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8037F10C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8037F110: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8037F114: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8037F118: addiu       $a1, $zero, 0x180
    ctx->r5 = ADD32(0, 0X180);
    // 0x8037F11C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037F120: jal         0x801453CC
    // 0x8037F124: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_0;
    // 0x8037F124: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    after_0:
    // 0x8037F128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037F12C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037F130: jr          $ra
    // 0x8037F134: nop

    return;
    // 0x8037F134: nop

;}
RECOMP_FUNC void M55_FUN_8037f138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F138: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8037F13C: lbu         $t6, -0x43F9($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X43F9);
    // 0x8037F140: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8037F144: bne         $t6, $zero, L_8037F154
    if (ctx->r14 != 0) {
            // 0x8037F148: nop

    LOOKUP_FUNC(0x8037F154)(rdram, ctx);
    return;
    }
    // 0x8037F148: nop

    // 0x8037F14C: jr          $ra
    // 0x8037F150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8037F150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f154(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F154: jr          $ra
    // 0x8037F158: nop

    return;
    // 0x8037F158: nop

;}
RECOMP_FUNC void M55_FUN_8037f15c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F15C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8037F160: lb          $t6, -0x43F8($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X43F8);
    // 0x8037F164: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037F168: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8037F16C: bne         $t6, $at, L_8037F17C
    if (ctx->r14 != ctx->r1) {
            // 0x8037F170: nop

    LOOKUP_FUNC(0x8037F17C)(rdram, ctx);
    return;
    }
    // 0x8037F170: nop

    // 0x8037F174: jr          $ra
    // 0x8037F178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8037F178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f17c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f17c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F17C: jr          $ra
    // 0x8037F180: nop

    return;
    // 0x8037F180: nop

;}
RECOMP_FUNC void M55_FUN_8037f184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F184: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8037F188: lb          $t6, -0x43F7($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X43F7);
    // 0x8037F18C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037F190: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8037F194: bne         $t6, $at, L_8037F1A4
    if (ctx->r14 != ctx->r1) {
            // 0x8037F198: nop

    LOOKUP_FUNC(0x8037F1A4)(rdram, ctx);
    return;
    }
    // 0x8037F198: nop

    // 0x8037F19C: jr          $ra
    // 0x8037F1A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8037F1A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f1a4(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f1a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F1A4: jr          $ra
    // 0x8037F1A8: nop

    return;
    // 0x8037F1A8: nop

;}
RECOMP_FUNC void M55_FUN_8037f1ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F1AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8037F1B0: lbu         $t6, -0x2334($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2334);
    // 0x8037F1B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8037F1B8: bne         $t6, $zero, L_8037F1C8
    if (ctx->r14 != 0) {
            // 0x8037F1BC: nop

    LOOKUP_FUNC(0x8037F1C8)(rdram, ctx);
    return;
    }
    // 0x8037F1BC: nop

    // 0x8037F1C0: jr          $ra
    // 0x8037F1C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8037F1C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f1c8(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f1c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F1C8: jr          $ra
    // 0x8037F1CC: nop

    return;
    // 0x8037F1CC: nop

;}
RECOMP_FUNC void M55_FUN_8037f1d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F1D0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8037F1D4: lbu         $t6, -0x43F5($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X43F5);
    // 0x8037F1D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037F1DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8037F1E0: bne         $t6, $at, L_8037F1F0
    if (ctx->r14 != ctx->r1) {
            // 0x8037F1E4: nop

    LOOKUP_FUNC(0x8037F1F0)(rdram, ctx);
    return;
    }
    // 0x8037F1E4: nop

    // 0x8037F1E8: jr          $ra
    // 0x8037F1EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8037F1EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f1f0(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f1f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F1F0: jr          $ra
    // 0x8037F1F4: nop

    return;
    // 0x8037F1F4: nop

;}
RECOMP_FUNC void M55_FUN_8037f1f8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F1F8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8037F1FC: lbu         $t6, -0x43F4($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X43F4);
    // 0x8037F200: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037F204: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8037F208: bne         $t6, $at, L_8037F218
    if (ctx->r14 != ctx->r1) {
            // 0x8037F20C: nop

    LOOKUP_FUNC(0x8037F218)(rdram, ctx);
    return;
    }
    // 0x8037F20C: nop

    // 0x8037F210: jr          $ra
    // 0x8037F214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8037F214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f218(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F218: jr          $ra
    // 0x8037F21C: nop

    return;
    // 0x8037F21C: nop

;}
RECOMP_FUNC void M55_FUN_8037f220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F220: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8037F224: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037F228: bne         $v0, $at, L_8037F23C
    if (ctx->r2 != ctx->r1) {
            // 0x8037F22C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8037F23C)(rdram, ctx);
    return;
    }
    // 0x8037F22C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037F230: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8037F234: jr          $ra
    // 0x8037F238: sb          $zero, -0x43F9($at)
    MEM_B(-0X43F9, ctx->r1) = 0;
    return;
    // 0x8037F238: sb          $zero, -0x43F9($at)
    MEM_B(-0X43F9, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f23c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f23c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F23C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037F240: bne         $v0, $at, L_8037F250
    if (ctx->r2 != ctx->r1) {
        // 0x8037F244: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8037F250;
    }
    // 0x8037F244: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8037F248: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8037F24C: sb          $t6, -0x43F9($at)
    MEM_B(-0X43F9, ctx->r1) = ctx->r14;
L_8037F250:
    // 0x8037F250: jr          $ra
    // 0x8037F254: nop

    return;
    // 0x8037F254: nop

;}
RECOMP_FUNC void M55_FUN_8037f258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F258: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8037F25C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8037F260: bne         $v1, $v0, L_8037F274
    if (ctx->r3 != ctx->r2) {
            // 0x8037F264: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8037F274)(rdram, ctx);
    return;
    }
    // 0x8037F264: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037F268: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8037F26C: jr          $ra
    // 0x8037F270: sb          $v1, -0x43F8($at)
    MEM_B(-0X43F8, ctx->r1) = ctx->r3;
    return;
    // 0x8037F270: sb          $v1, -0x43F8($at)
    MEM_B(-0X43F8, ctx->r1) = ctx->r3;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f274(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F274: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037F278: bne         $v0, $at, L_8037F288
    if (ctx->r2 != ctx->r1) {
        // 0x8037F27C: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_8037F288;
    }
    // 0x8037F27C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8037F280: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8037F284: sb          $t6, -0x43F8($at)
    MEM_B(-0X43F8, ctx->r1) = ctx->r14;
L_8037F288:
    // 0x8037F288: jr          $ra
    // 0x8037F28C: nop

    return;
    // 0x8037F28C: nop

;}
RECOMP_FUNC void M55_FUN_8037f290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F290: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8037F294: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8037F298: bne         $v1, $v0, L_8037F2AC
    if (ctx->r3 != ctx->r2) {
            // 0x8037F29C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8037F2AC)(rdram, ctx);
    return;
    }
    // 0x8037F29C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037F2A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8037F2A4: jr          $ra
    // 0x8037F2A8: sb          $v1, -0x43F7($at)
    MEM_B(-0X43F7, ctx->r1) = ctx->r3;
    return;
    // 0x8037F2A8: sb          $v1, -0x43F7($at)
    MEM_B(-0X43F7, ctx->r1) = ctx->r3;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f2ac(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f2ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F2AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037F2B0: bne         $v0, $at, L_8037F2C0
    if (ctx->r2 != ctx->r1) {
        // 0x8037F2B4: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_8037F2C0;
    }
    // 0x8037F2B4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8037F2B8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8037F2BC: sb          $t6, -0x43F7($at)
    MEM_B(-0X43F7, ctx->r1) = ctx->r14;
L_8037F2C0:
    // 0x8037F2C0: jr          $ra
    // 0x8037F2C4: nop

    return;
    // 0x8037F2C4: nop

;}
RECOMP_FUNC void M55_FUN_8037f2c8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F2C8: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8037F2CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037F2D0: bne         $v0, $at, L_8037F2E4
    if (ctx->r2 != ctx->r1) {
            // 0x8037F2D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8037F2E4)(rdram, ctx);
    return;
    }
    // 0x8037F2D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037F2D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8037F2DC: jr          $ra
    // 0x8037F2E0: sb          $zero, -0x2334($at)
    MEM_B(-0X2334, ctx->r1) = 0;
    return;
    // 0x8037F2E0: sb          $zero, -0x2334($at)
    MEM_B(-0X2334, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f2e4(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f2e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F2E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037F2E8: bne         $v0, $at, L_8037F2F8
    if (ctx->r2 != ctx->r1) {
        // 0x8037F2EC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8037F2F8;
    }
    // 0x8037F2EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8037F2F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8037F2F4: sb          $t6, -0x2334($at)
    MEM_B(-0X2334, ctx->r1) = ctx->r14;
L_8037F2F8:
    // 0x8037F2F8: jr          $ra
    // 0x8037F2FC: nop

    return;
    // 0x8037F2FC: nop

;}
RECOMP_FUNC void M55_FUN_8037f300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F300: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8037F304: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037F308: bne         $v0, $at, L_8037F320
    if (ctx->r2 != ctx->r1) {
            // 0x8037F30C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8037F320)(rdram, ctx);
    return;
    }
    // 0x8037F30C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037F310: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8037F314: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8037F318: jr          $ra
    // 0x8037F31C: sb          $t6, -0x43F5($at)
    MEM_B(-0X43F5, ctx->r1) = ctx->r14;
    return;
    // 0x8037F31C: sb          $t6, -0x43F5($at)
    MEM_B(-0X43F5, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f320(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F320: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037F324: bne         $v0, $at, L_8037F330
    if (ctx->r2 != ctx->r1) {
        // 0x8037F328: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8037F330;
    }
    // 0x8037F328: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8037F32C: sb          $zero, -0x43F5($at)
    MEM_B(-0X43F5, ctx->r1) = 0;
L_8037F330:
    // 0x8037F330: jr          $ra
    // 0x8037F334: nop

    return;
    // 0x8037F334: nop

;}
RECOMP_FUNC void M55_FUN_8037f338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F338: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8037F33C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037F340: bne         $v0, $at, L_8037F358
    if (ctx->r2 != ctx->r1) {
            // 0x8037F344: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8037F358)(rdram, ctx);
    return;
    }
    // 0x8037F344: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037F348: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8037F34C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8037F350: jr          $ra
    // 0x8037F354: sb          $t6, -0x43F4($at)
    MEM_B(-0X43F4, ctx->r1) = ctx->r14;
    return;
    // 0x8037F354: sb          $t6, -0x43F4($at)
    MEM_B(-0X43F4, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f358(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F358: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037F35C: bne         $v0, $at, L_8037F368
    if (ctx->r2 != ctx->r1) {
        // 0x8037F360: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8037F368;
    }
    // 0x8037F360: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8037F364: sb          $zero, -0x43F4($at)
    MEM_B(-0X43F4, ctx->r1) = 0;
L_8037F368:
    // 0x8037F368: jr          $ra
    // 0x8037F36C: nop

    return;
    // 0x8037F36C: nop

;}
RECOMP_FUNC void M55_FUN_8037f370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037F374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037F378: lb          $v0, 0x96($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X96);
    // 0x8037F37C: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037F380: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037F384: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8037F388: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8037F38C: lw          $v1, -0x7418($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7418);
    // 0x8037F390: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8037F394: beql        $v1, $zero, L_8037F3A8
    if (ctx->r3 == 0) {
        // 0x8037F398: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037F3A8;
    }
    goto skip_0;
    // 0x8037F398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8037F39C: jalr        $v1
    // 0x8037F3A0: lbu         $a0, -0x56B0($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X56B0);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8037F3A0: lbu         $a0, -0x56B0($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X56B0);
    after_0:
    // 0x8037F3A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037F3A8:
    // 0x8037F3A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037F3AC: jr          $ra
    // 0x8037F3B0: nop

    return;
    // 0x8037F3B0: nop

;}
RECOMP_FUNC void M55_FUN_8037f3b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F3B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037F3B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8037F3BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8037F3C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037F3C4: lui         $s1, 0x8039
    ctx->r17 = S32(0X8039 << 16);
    // 0x8037F3C8: lui         $s2, 0x8039
    ctx->r18 = S32(0X8039 << 16);
    // 0x8037F3CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037F3D0: addiu       $s2, $s2, -0x56B0
    ctx->r18 = ADD32(ctx->r18, -0X56B0);
    // 0x8037F3D4: addiu       $s1, $s1, -0x7430
    ctx->r17 = ADD32(ctx->r17, -0X7430);
    // 0x8037F3D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037F3DC: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
L_8037F3E0:
    // 0x8037F3E0: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8037F3E4: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8037F3E8: beql        $v0, $zero, L_8037F404
    if (ctx->r2 == 0) {
        // 0x8037F3EC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8037F404;
    }
    goto skip_0;
    // 0x8037F3EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8037F3F0: jalr        $v0
    // 0x8037F3F4: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8037F3F4: nop

    after_0:
    // 0x8037F3F8: addu        $t8, $s2, $s0
    ctx->r24 = ADD32(ctx->r18, ctx->r16);
    // 0x8037F3FC: sb          $v0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r2;
    // 0x8037F400: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8037F404:
    // 0x8037F404: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8037F408: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x8037F40C: bnel        $at, $zero, L_8037F3E0
    if (ctx->r1 != 0) {
        // 0x8037F410: sll         $t6, $s0, 2
        ctx->r14 = S32(ctx->r16 << 2);
            goto L_8037F3E0;
    }
    goto skip_1;
    // 0x8037F410: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    skip_1:
    // 0x8037F414: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037F418: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037F41C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8037F420: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8037F424: jr          $ra
    // 0x8037F428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8037F428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f42c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f42c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F42C: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8037F430: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037F434: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x8037F438: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8037F43C: addiu       $t7, $t7, -0x7320
    ctx->r15 = ADD32(ctx->r15, -0X7320);
    // 0x8037F440: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8037F444: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8037F448: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8037F44C: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x8037F450: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8037F454: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8037F458: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8037F45C: addiu       $t0, $t7, 0x48
    ctx->r8 = ADD32(ctx->r15, 0X48);
    // 0x8037F460: addiu       $t6, $sp, 0x98
    ctx->r14 = ADD32(ctx->r29, 0X98);
L_8037F464:
    // 0x8037F464: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8037F468: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8037F46C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8037F470: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x8037F474: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8037F478: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x8037F47C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8037F480: bne         $t7, $t0, L_8037F464
    if (ctx->r15 != ctx->r8) {
        // 0x8037F484: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_8037F464;
    }
    // 0x8037F484: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x8037F488: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x8037F48C: addiu       $t2, $t2, -0x72D8
    ctx->r10 = ADD32(ctx->r10, -0X72D8);
    // 0x8037F490: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8037F494: addiu       $t1, $sp, 0x90
    ctx->r9 = ADD32(ctx->r29, 0X90);
    // 0x8037F498: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8037F49C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x8037F4A0: lhu         $t4, 0x4($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X4);
    // 0x8037F4A4: addiu       $t0, $t0, -0x72D0
    ctx->r8 = ADD32(ctx->r8, -0X72D0);
    // 0x8037F4A8: addiu       $t5, $sp, 0x88
    ctx->r13 = ADD32(ctx->r29, 0X88);
    // 0x8037F4AC: sh          $t4, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r12;
    // 0x8037F4B0: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8037F4B4: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8037F4B8: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037F4BC: addiu       $t9, $t9, -0x72C8
    ctx->r25 = ADD32(ctx->r25, -0X72C8);
    // 0x8037F4C0: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8037F4C4: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8037F4C8: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8037F4CC: addiu       $t8, $sp, 0x7C
    ctx->r24 = ADD32(ctx->r29, 0X7C);
    // 0x8037F4D0: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8037F4D4: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8037F4D8: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x8037F4DC: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8037F4E0: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x8037F4E4: sw          $t2, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r10;
    // 0x8037F4E8: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8037F4EC: lw          $t3, -0x72BC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X72BC);
    // 0x8037F4F0: lw          $t4, -0x72B8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X72B8);
    // 0x8037F4F4: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8037F4F8: addiu       $t0, $t0, -0x72B4
    ctx->r8 = ADD32(ctx->r8, -0X72B4);
    // 0x8037F4FC: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x8037F500: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    // 0x8037F504: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8037F508: addiu       $t5, $sp, 0x6C
    ctx->r13 = ADD32(ctx->r29, 0X6C);
    // 0x8037F50C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037F510: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8037F514: lhu         $t6, 0x4($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X4);
    // 0x8037F518: addiu       $t9, $t9, -0x72AC
    ctx->r25 = ADD32(ctx->r25, -0X72AC);
    // 0x8037F51C: addiu       $t8, $sp, 0x64
    ctx->r24 = ADD32(ctx->r29, 0X64);
    // 0x8037F520: sh          $t6, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r14;
    // 0x8037F524: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8037F528: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8037F52C: addiu       $t4, $t4, -0x72A4
    ctx->r12 = ADD32(ctx->r12, -0X72A4);
    // 0x8037F530: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8037F534: lhu         $t2, 0x4($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X4);
    // 0x8037F538: addiu       $t3, $sp, 0x5C
    ctx->r11 = ADD32(ctx->r29, 0X5C);
    // 0x8037F53C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037F540: sh          $t2, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r10;
    // 0x8037F544: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8037F548: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x8037F54C: addiu       $a1, $zero, 0x122
    ctx->r5 = ADD32(0, 0X122);
    // 0x8037F550: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037F554: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8037F558: jal         0x80126A0C
    // 0x8037F55C: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x8037F55C: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    after_0:
    // 0x8037F560: beq         $v0, $zero, L_8037FCD4
    if (ctx->r2 == 0) {
            // 0x8037F564: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    LOOKUP_FUNC(0x8037FCD4)(rdram, ctx);
    return;
    }
    // 0x8037F564: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8037F568: addiu       $s4, $sp, 0xE6
    ctx->r20 = ADD32(ctx->r29, 0XE6);
    // 0x8037F56C: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f570(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F570: multu       $s1, $s2
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037F574: addiu       $t6, $sp, 0x98
    ctx->r14 = ADD32(ctx->r29, 0X98);
    // 0x8037F578: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x8037F57C: addiu       $t2, $zero, 0x1A
    ctx->r10 = ADD32(0, 0X1A);
    // 0x8037F580: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8037F584: addiu       $t4, $zero, 0x21D
    ctx->r12 = ADD32(0, 0X21D);
    // 0x8037F588: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037f58c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037f58c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_8037F570:
    // 0x8037F58C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037F590: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8037F594: mflo        $t7
    ctx->r15 = lo;
    // 0x8037F598: addu        $s0, $t7, $t6
    ctx->r16 = ADD32(ctx->r15, ctx->r14);
    // 0x8037F59C: lh          $t8, 0xA($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XA);
    // 0x8037F5A0: lh          $a3, 0x8($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X8);
    // 0x8037F5A4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8037F5A8: addiu       $t9, $t8, 0x14
    ctx->r25 = ADD32(ctx->r24, 0X14);
    // 0x8037F5AC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8037F5B0: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8037F5B4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8037F5B8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037F5BC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037F5C0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8037F5C4: jal         0x80146208
    // 0x8037F5C8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_0;
    // 0x8037F5C8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_0:
    // 0x8037F5CC: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x8037F5D0: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x8037F5D4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8037F5D8: addiu       $t0, $t5, 0x14
    ctx->r8 = ADD32(ctx->r13, 0X14);
    // 0x8037F5DC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8037F5E0: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8037F5E4: addiu       $t9, $zero, 0x21D
    ctx->r25 = ADD32(0, 0X21D);
    // 0x8037F5E8: addu        $t1, $sp, $s1
    ctx->r9 = ADD32(ctx->r29, ctx->r17);
    // 0x8037F5EC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8037F5F0: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x8037F5F4: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8037F5F8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8037F5FC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037F600: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037F604: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8037F608: lbu         $t1, 0x6C($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X6C);
    // 0x8037F60C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037F610: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037F614: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037F618: jal         0x80146208
    // 0x8037F61C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x8037F61C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_1:
    // 0x8037F620: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037F624: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    // 0x8037F628: jal         0x80145348
    // 0x8037F62C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_2;
    // 0x8037F62C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8037F630: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8037F634: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8037F638: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x8037F63C: bne         $at, $zero, L_8037F570
    if (ctx->r1 != 0) {
            // 0x8037F640: nop

    LOOKUP_FUNC(0x8037F570)(rdram, ctx);
    return;
    }
    // 0x8037F640: nop

    // 0x8037F644: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8037F648: lbu         $t2, -0x431C($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X431C);
    // 0x8037F64C: beq         $t2, $zero, L_8037F6F0
    if (ctx->r10 == 0) {
        // 0x8037F650: addiu       $t3, $zero, 0x5D
        ctx->r11 = ADD32(0, 0X5D);
            goto L_8037F6F0;
    }
    // 0x8037F650: addiu       $t3, $zero, 0x5D
    ctx->r11 = ADD32(0, 0X5D);
    // 0x8037F654: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x8037F658: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x8037F65C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8037F660: addiu       $t7, $zero, 0x21D
    ctx->r15 = ADD32(0, 0X21D);
    // 0x8037F664: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8037F668: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8037F66C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8037F670: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8037F674: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8037F678: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8037F67C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8037F680: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037F684: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037F688: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8037F68C: addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    // 0x8037F690: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037F694: jal         0x80146208
    // 0x8037F698: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x8037F698: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_3:
    // 0x8037F69C: addiu       $t8, $zero, 0x9D
    ctx->r24 = ADD32(0, 0X9D);
    // 0x8037F6A0: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8037F6A4: addiu       $t1, $zero, 0x18
    ctx->r9 = ADD32(0, 0X18);
    // 0x8037F6A8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8037F6AC: addiu       $t3, $zero, 0x21D
    ctx->r11 = ADD32(0, 0X21D);
    // 0x8037F6B0: addiu       $t4, $zero, 0x1F
    ctx->r12 = ADD32(0, 0X1F);
    // 0x8037F6B4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8037F6B8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8037F6BC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8037F6C0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8037F6C4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8037F6C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8037F6CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037F6D0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037F6D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8037F6D8: addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    // 0x8037F6DC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037F6E0: jal         0x80146208
    // 0x8037F6E4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_4;
    // 0x8037F6E4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_4:
    // 0x8037F6E8: b           L_8037F78C
    // 0x8037F6EC: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
        goto L_8037F78C;
    // 0x8037F6EC: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
L_8037F6F0:
    // 0x8037F6F0: addiu       $t5, $zero, 0x5D
    ctx->r13 = ADD32(0, 0X5D);
    // 0x8037F6F4: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x8037F6F8: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x8037F6FC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8037F700: addiu       $t8, $zero, 0x21D
    ctx->r24 = ADD32(0, 0X21D);
    // 0x8037F704: addiu       $t9, $zero, 0x1C
    ctx->r25 = ADD32(0, 0X1C);
    // 0x8037F708: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8037F70C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8037F710: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8037F714: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8037F718: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8037F71C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8037F720: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037F724: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037F728: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8037F72C: addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    // 0x8037F730: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037F734: jal         0x80146208
    // 0x8037F738: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_5;
    // 0x8037F738: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_5:
    // 0x8037F73C: addiu       $t1, $zero, 0x9D
    ctx->r9 = ADD32(0, 0X9D);
    // 0x8037F740: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x8037F744: addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    // 0x8037F748: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8037F74C: addiu       $t5, $zero, 0x21D
    ctx->r13 = ADD32(0, 0X21D);
    // 0x8037F750: addiu       $t0, $zero, 0x1D
    ctx->r8 = ADD32(0, 0X1D);
    // 0x8037F754: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8037F758: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8037F75C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8037F760: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8037F764: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8037F768: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8037F76C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037F770: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037F774: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8037F778: addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    // 0x8037F77C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037F780: jal         0x80146208
    // 0x8037F784: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_6;
    // 0x8037F784: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_6:
    // 0x8037F788: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
L_8037F78C:
    // 0x8037F78C: addiu       $t6, $zero, 0x60
    ctx->r14 = ADD32(0, 0X60);
    // 0x8037F790: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8037F794: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8037F798: addiu       $t1, $zero, 0x20E
    ctx->r9 = ADD32(0, 0X20E);
    // 0x8037F79C: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8037F7A0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8037F7A4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8037F7A8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8037F7AC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8037F7B0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8037F7B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8037F7B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037F7BC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037F7C0: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8037F7C4: addiu       $a3, $zero, 0x29
    ctx->r7 = ADD32(0, 0X29);
    // 0x8037F7C8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037F7CC: jal         0x80146208
    // 0x8037F7D0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_7;
    // 0x8037F7D0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_7:
    // 0x8037F7D4: addiu       $t3, $zero, 0x21
    ctx->r11 = ADD32(0, 0X21);
    // 0x8037F7D8: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x8037F7DC: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x8037F7E0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8037F7E4: addiu       $t7, $zero, 0x21D
    ctx->r15 = ADD32(0, 0X21D);
    // 0x8037F7E8: addiu       $t6, $zero, 0x16
    ctx->r14 = ADD32(0, 0X16);
    // 0x8037F7EC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8037F7F0: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8037F7F4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8037F7F8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8037F7FC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8037F800: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8037F804: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037F808: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037F80C: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8037F810: addiu       $a3, $zero, 0x39
    ctx->r7 = ADD32(0, 0X39);
    // 0x8037F814: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037F818: jal         0x80146208
    // 0x8037F81C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_8;
    // 0x8037F81C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_8:
    // 0x8037F820: addiu       $t8, $zero, 0x3B
    ctx->r24 = ADD32(0, 0X3B);
    // 0x8037F824: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8037F828: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x8037F82C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8037F830: addiu       $t3, $zero, 0x21D
    ctx->r11 = ADD32(0, 0X21D);
    // 0x8037F834: addiu       $t4, $zero, 0x19
    ctx->r12 = ADD32(0, 0X19);
    // 0x8037F838: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8037F83C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8037F840: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8037F844: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8037F848: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8037F84C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8037F850: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037F854: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037F858: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8037F85C: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    // 0x8037F860: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037F864: jal         0x80146208
    // 0x8037F868: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_9;
    // 0x8037F868: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_9:
    // 0x8037F86C: addiu       $t5, $zero, 0x3B
    ctx->r13 = ADD32(0, 0X3B);
    // 0x8037F870: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x8037F874: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x8037F878: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8037F87C: addiu       $t8, $zero, 0x21D
    ctx->r24 = ADD32(0, 0X21D);
    // 0x8037F880: addiu       $t9, $zero, 0x1A
    ctx->r25 = ADD32(0, 0X1A);
    // 0x8037F884: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8037F888: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8037F88C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8037F890: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8037F894: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8037F898: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8037F89C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037F8A0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037F8A4: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    // 0x8037F8A8: addiu       $a3, $zero, 0x3B
    ctx->r7 = ADD32(0, 0X3B);
    // 0x8037F8AC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037F8B0: jal         0x80146208
    // 0x8037F8B4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_10;
    // 0x8037F8B4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_10:
    // 0x8037F8B8: addiu       $t1, $zero, 0x3B
    ctx->r9 = ADD32(0, 0X3B);
    // 0x8037F8BC: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x8037F8C0: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x8037F8C4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8037F8C8: addiu       $t5, $zero, 0x21D
    ctx->r13 = ADD32(0, 0X21D);
    // 0x8037F8CC: addiu       $t0, $zero, 0x1B
    ctx->r8 = ADD32(0, 0X1B);
    // 0x8037F8D0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8037F8D4: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8037F8D8: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8037F8DC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8037F8E0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8037F8E4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8037F8E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037F8EC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037F8F0: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8037F8F4: addiu       $a3, $zero, 0x7B
    ctx->r7 = ADD32(0, 0X7B);
    // 0x8037F8F8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037F8FC: jal         0x80146208
    // 0x8037F900: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_11;
    // 0x8037F900: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_11:
    // 0x8037F904: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8037F908: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8037F90C:
    // 0x8037F90C: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x8037F910: addiu       $t6, $t7, 0x45
    ctx->r14 = ADD32(ctx->r15, 0X45);
    // 0x8037F914: sll         $s2, $s1, 1
    ctx->r18 = S32(ctx->r17 << 1);
    // 0x8037F918: addu        $t8, $sp, $s2
    ctx->r24 = ADD32(ctx->r29, ctx->r18);
    // 0x8037F91C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8037F920: lh          $t8, 0x90($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X90);
    // 0x8037F924: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8037F928: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8037F92C: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8037F930: addiu       $t3, $sp, 0x7C
    ctx->r11 = ADD32(ctx->r29, 0X7C);
    // 0x8037F934: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x8037F938: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8037F93C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8037F940: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037F944: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037F948: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8037F94C: lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X0);
    // 0x8037F950: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037F954: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037F958: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8037F95C: lhu         $t5, 0x2($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X2);
    // 0x8037F960: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037F964: addiu       $a3, $zero, 0x1F
    ctx->r7 = ADD32(0, 0X1F);
    // 0x8037F968: jal         0x80146208
    // 0x8037F96C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_12;
    // 0x8037F96C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    after_12:
    // 0x8037F970: addiu       $t0, $sp, 0x64
    ctx->r8 = ADD32(ctx->r29, 0X64);
    // 0x8037F974: addu        $v1, $s2, $t0
    ctx->r3 = ADD32(ctx->r18, ctx->r8);
    // 0x8037F978: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x8037F97C: lbu         $a2, 0x1($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1);
    // 0x8037F980: jal         0x80145348
    // 0x8037F984: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_13;
    // 0x8037F984: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x8037F988: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8037F98C: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8037F990: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x8037F994: bne         $at, $zero, L_8037F90C
    if (ctx->r1 != 0) {
        // 0x8037F998: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8037F90C;
    }
    // 0x8037F998: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8037F99C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8037F9A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8037F9A4:
    // 0x8037F9A4: sll         $s2, $s0, 4
    ctx->r18 = S32(ctx->r16 << 4);
    // 0x8037F9A8: addiu       $t7, $s2, 0x82
    ctx->r15 = ADD32(ctx->r18, 0X82);
    // 0x8037F9AC: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x8037F9B0: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x8037F9B4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8037F9B8: addiu       $t1, $zero, 0x21D
    ctx->r9 = ADD32(0, 0X21D);
    // 0x8037F9BC: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x8037F9C0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8037F9C4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8037F9C8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8037F9CC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8037F9D0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8037F9D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8037F9D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037F9DC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037F9E0: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8037F9E4: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x8037F9E8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037F9EC: jal         0x80146208
    // 0x8037F9F0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_14;
    // 0x8037F9F0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_14:
    // 0x8037F9F4: addiu       $t3, $s2, 0x85
    ctx->r11 = ADD32(ctx->r18, 0X85);
    // 0x8037F9F8: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x8037F9FC: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x8037FA00: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8037FA04: lh          $t5, 0x88($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X88);
    // 0x8037FA08: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8037FA0C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8037FA10: addiu       $t6, $zero, 0x21D
    ctx->r14 = ADD32(0, 0X21D);
    // 0x8037FA14: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8037FA18: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8037FA1C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8037FA20: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037FA24: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037FA28: addu        $t8, $sp, $s1
    ctx->r24 = ADD32(ctx->r29, ctx->r17);
    // 0x8037FA2C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8037FA30: lbu         $t8, 0x78($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X78);
    // 0x8037FA34: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037FA38: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037FA3C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037FA40: addiu       $a3, $zero, 0x23
    ctx->r7 = ADD32(0, 0X23);
    // 0x8037FA44: jal         0x80146208
    // 0x8037FA48: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_15;
    // 0x8037FA48: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_15:
    // 0x8037FA4C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037FA50: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8037FA54: jal         0x80145348
    // 0x8037FA58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_16;
    // 0x8037FA58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x8037FA5C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8037FA60: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8037FA64: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8037FA68: bne         $at, $zero, L_8037F9A4
    if (ctx->r1 != 0) {
        // 0x8037FA6C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8037F9A4;
    }
    // 0x8037FA6C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8037FA70: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8037FA74: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8037FA78: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8037FA7C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8037FA80: addiu       $t4, $zero, 0x209
    ctx->r12 = ADD32(0, 0X209);
    // 0x8037FA84: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8037FA88: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8037FA8C: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8037FA90: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8037FA94: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8037FA98: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8037FA9C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8037FAA0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037FAA4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037FAA8: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8037FAAC: addiu       $a3, $zero, 0xDC
    ctx->r7 = ADD32(0, 0XDC);
    // 0x8037FAB0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037FAB4: jal         0x80146208
    // 0x8037FAB8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_17;
    // 0x8037FAB8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_17:
    // 0x8037FABC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037FAC0: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8037FAC4: jal         0x80145348
    // 0x8037FAC8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_18;
    // 0x8037FAC8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_18:
    // 0x8037FACC: addiu       $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
    // 0x8037FAD0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8037FAD4: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8037FAD8: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8037FADC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8037FAE0: addiu       $t1, $zero, 0x209
    ctx->r9 = ADD32(0, 0X209);
    // 0x8037FAE4: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8037FAE8: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8037FAEC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8037FAF0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8037FAF4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8037FAF8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8037FAFC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8037FB00: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8037FB04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037FB08: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037FB0C: addiu       $a2, $zero, 0xE6
    ctx->r6 = ADD32(0, 0XE6);
    // 0x8037FB10: addiu       $a3, $zero, 0xDC
    ctx->r7 = ADD32(0, 0XDC);
    // 0x8037FB14: jal         0x80146208
    // 0x8037FB18: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_19;
    // 0x8037FB18: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_19:
    // 0x8037FB1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037FB20: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8037FB24: jal         0x80145348
    // 0x8037FB28: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_20;
    // 0x8037FB28: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_20:
    // 0x8037FB2C: jal         0x80006214
    // 0x8037FB30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_21;
    // 0x8037FB30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_21:
    // 0x8037FB34: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8037FB38: addiu       $t4, $zero, 0x48
    ctx->r12 = ADD32(0, 0X48);
    // 0x8037FB3C: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x8037FB40: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8037FB44: addiu       $t7, $zero, 0x21D
    ctx->r15 = ADD32(0, 0X21D);
    // 0x8037FB48: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8037FB4C: sb          $v0, 0xE4($sp)
    MEM_B(0XE4, ctx->r29) = ctx->r2;
    // 0x8037FB50: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8037FB54: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8037FB58: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8037FB5C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8037FB60: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8037FB64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8037FB68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037FB6C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037FB70: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8037FB74: addiu       $a3, $zero, 0xBC
    ctx->r7 = ADD32(0, 0XBC);
    // 0x8037FB78: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037FB7C: jal         0x80146208
    // 0x8037FB80: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_22;
    // 0x8037FB80: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_22:
    // 0x8037FB84: lbu         $t8, 0xE4($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XE4);
    // 0x8037FB88: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037FB8C: addiu       $v1, $v1, -0x5658
    ctx->r3 = ADD32(ctx->r3, -0X5658);
    // 0x8037FB90: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8037FB94: addu        $t1, $s5, $t9
    ctx->r9 = ADD32(ctx->r21, ctx->r25);
    // 0x8037FB98: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8037FB9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037FBA0: jal         0x801451C0
    // 0x8037FBA4: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    LOOKUP_FUNC(0x801451C0)(rdram, ctx);
        goto after_23;
    // 0x8037FBA4: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    after_23:
    // 0x8037FBA8: jal         0x80006214
    // 0x8037FBAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_24;
    // 0x8037FBAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_24:
    // 0x8037FBB0: sb          $v0, 0xE4($sp)
    MEM_B(0XE4, ctx->r29) = ctx->r2;
    // 0x8037FBB4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8037FBB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037FBBC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8037FBC0:
    // 0x8037FBC0: addiu       $t3, $zero, 0x22
    ctx->r11 = ADD32(0, 0X22);
    // 0x8037FBC4: addiu       $t4, $zero, 0x48
    ctx->r12 = ADD32(0, 0X48);
    // 0x8037FBC8: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8037FBCC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8037FBD0: addiu       $t7, $zero, 0x21D
    ctx->r15 = ADD32(0, 0X21D);
    // 0x8037FBD4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8037FBD8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8037FBDC: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8037FBE0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8037FBE4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8037FBE8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8037FBEC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037FBF0: addu        $t6, $sp, $s1
    ctx->r14 = ADD32(ctx->r29, ctx->r17);
    // 0x8037FBF4: lbu         $t6, 0x74($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X74);
    // 0x8037FBF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037FBFC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8037FC00: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8037FC04: addiu       $a3, $zero, 0xBC
    ctx->r7 = ADD32(0, 0XBC);
    // 0x8037FC08: jal         0x80146208
    // 0x8037FC0C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_25;
    // 0x8037FC0C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_25:
    // 0x8037FC10: sll         $t8, $s1, 1
    ctx->r24 = S32(ctx->r17 << 1);
    // 0x8037FC14: addu        $a1, $sp, $t8
    ctx->r5 = ADD32(ctx->r29, ctx->r24);
    // 0x8037FC18: lbu         $a1, 0x5C($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X5C);
    // 0x8037FC1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037FC20: jal         0x80145348
    // 0x8037FC24: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_26;
    // 0x8037FC24: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    after_26:
    // 0x8037FC28: jal         0x80006214
    // 0x8037FC2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_27;
    // 0x8037FC2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_27:
    // 0x8037FC30: lb          $t9, 0x91($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X91);
    // 0x8037FC34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8037FC38: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8037FC3C: bne         $s0, $t9, L_8037FC60
    if (ctx->r16 != ctx->r25) {
        // 0x8037FC40: slti        $at, $s1, 0x4
        ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
            goto L_8037FC60;
    }
    // 0x8037FC40: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8037FC44: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8037FC48: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x8037FC4C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8037FC50: addu        $t4, $s5, $t3
    ctx->r12 = ADD32(ctx->r21, ctx->r11);
    // 0x8037FC54: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8037FC58: b           L_8037FC78
    // 0x8037FC5C: sb          $s2, 0x22($t5)
    MEM_B(0X22, ctx->r13) = ctx->r18;
        goto L_8037FC78;
    // 0x8037FC5C: sb          $s2, 0x22($t5)
    MEM_B(0X22, ctx->r13) = ctx->r18;
L_8037FC60:
    // 0x8037FC60: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8037FC64: andi        $t7, $t0, 0xFF
    ctx->r15 = ctx->r8 & 0XFF;
    // 0x8037FC68: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8037FC6C: addu        $t8, $s5, $t6
    ctx->r24 = ADD32(ctx->r21, ctx->r14);
    // 0x8037FC70: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8037FC74: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
L_8037FC78:
    // 0x8037FC78: bne         $at, $zero, L_8037FBC0
    if (ctx->r1 != 0) {
        // 0x8037FC7C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8037FBC0;
    }
    // 0x8037FC7C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8037FC80: lbu         $t1, 0xE4($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XE4);
    // 0x8037FC84: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037FC88: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037FC8C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8037FC90: addu        $t3, $s5, $t2
    ctx->r11 = ADD32(ctx->r21, ctx->r10);
    // 0x8037FC94: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8037FC98: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8037FC9C: jal         0x8037D82C
    // 0x8037FCA0: sw          $t4, -0x5660($at)
    MEM_W(-0X5660, ctx->r1) = ctx->r12;
    LOOKUP_FUNC(0x8037D82C)(rdram, ctx);
        goto after_28;
    // 0x8037FCA0: sw          $t4, -0x5660($at)
    MEM_W(-0X5660, ctx->r1) = ctx->r12;
    after_28:
    // 0x8037FCA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037FCA8: jal         0x8037D9BC
    // 0x8037FCAC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    LOOKUP_FUNC(0x8037D9BC)(rdram, ctx);
        goto after_29;
    // 0x8037FCAC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_29:
    // 0x8037FCB0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037FCB4: jal         0x8037DA84
    // 0x8037FCB8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    LOOKUP_FUNC(0x8037DA84)(rdram, ctx);
        goto after_30;
    // 0x8037FCB8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_30:
    // 0x8037FCBC: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037FCC0: sb          $zero, 0x91($s3)
    MEM_B(0X91, ctx->r19) = 0;
    // 0x8037FCC4: sb          $zero, 0x94($s3)
    MEM_B(0X94, ctx->r19) = 0;
    // 0x8037FCC8: addiu       $a1, $a1, -0x308
    ctx->r5 = ADD32(ctx->r5, -0X308);
    // 0x8037FCCC: jal         0x800058DC
    // 0x8037FCD0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_31;
    // 0x8037FCD0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_31:
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037fcd4(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037fcd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037FCD4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8037FCD8: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8037FCDC: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8037FCE0: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8037FCE4: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8037FCE8: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8037FCEC: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x8037FCF0: jr          $ra
    // 0x8037FCF4: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x8037FCF4: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037fcf8(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037fcf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037FCF8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037FCFC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8037FD00: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8037FD04: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8037FD08: lw          $t6, 0xA4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA4);
    // 0x8037FD0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037FD10: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8037FD14: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8037FD18: lb          $v0, 0x91($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X91);
    // 0x8037FD1C: lhu         $a2, 0xC($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0XC);
    // 0x8037FD20: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8037FD24: sll         $a3, $v0, 24
    ctx->r7 = S32(ctx->r2 << 24);
    // 0x8037FD28: andi        $t8, $a2, 0x800
    ctx->r24 = ctx->r6 & 0X800;
    // 0x8037FD2C: beq         $t8, $zero, L_8037FD48
    if (ctx->r24 == 0) {
        // 0x8037FD30: sra         $a3, $a3, 24
        ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
            goto L_8037FD48;
    }
    // 0x8037FD30: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x8037FD34: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8037FD38: sb          $t9, 0x91($a0)
    MEM_B(0X91, ctx->r4) = ctx->r25;
    // 0x8037FD3C: lb          $v0, 0x91($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X91);
    // 0x8037FD40: b           L_8037FD64
    // 0x8037FD44: sb          $t0, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r8;
        goto L_8037FD64;
    // 0x8037FD44: sb          $t0, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r8;
L_8037FD48:
    // 0x8037FD48: andi        $t1, $a2, 0x400
    ctx->r9 = ctx->r6 & 0X400;
    // 0x8037FD4C: beq         $t1, $zero, L_8037FD64
    if (ctx->r9 == 0) {
        // 0x8037FD50: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_8037FD64;
    }
    // 0x8037FD50: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8037FD54: sb          $t2, 0x91($s0)
    MEM_B(0X91, ctx->r16) = ctx->r10;
    // 0x8037FD58: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8037FD5C: sb          $t3, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r11;
    // 0x8037FD60: lb          $v0, 0x91($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X91);
L_8037FD64:
    // 0x8037FD64: bgez        $v0, L_8037FD74
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8037FD68: nop
    
            goto L_8037FD74;
    }
    // 0x8037FD68: nop

    // 0x8037FD6C: sb          $t4, 0x91($s0)
    MEM_B(0X91, ctx->r16) = ctx->r12;
    // 0x8037FD70: lb          $v0, 0x91($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X91);
L_8037FD74:
    // 0x8037FD74: bgez        $v0, L_8037FD88
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8037FD78: andi        $t5, $v0, 0x3
        ctx->r13 = ctx->r2 & 0X3;
            goto L_8037FD88;
    }
    // 0x8037FD78: andi        $t5, $v0, 0x3
    ctx->r13 = ctx->r2 & 0X3;
    // 0x8037FD7C: beq         $t5, $zero, L_8037FD88
    if (ctx->r13 == 0) {
        // 0x8037FD80: nop
    
            goto L_8037FD88;
    }
    // 0x8037FD80: nop

    // 0x8037FD84: addiu       $t5, $t5, -0x4
    ctx->r13 = ADD32(ctx->r13, -0X4);
L_8037FD88:
    // 0x8037FD88: sb          $t5, 0x91($s0)
    MEM_B(0X91, ctx->r16) = ctx->r13;
    // 0x8037FD8C: lb          $t6, 0x91($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X91);
    // 0x8037FD90: beq         $a3, $t6, L_8037FDA0
    if (ctx->r7 == ctx->r14) {
        // 0x8037FD94: nop
    
            goto L_8037FDA0;
    }
    // 0x8037FD94: nop

    // 0x8037FD98: jal         0x80020744
    // 0x8037FD9C: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x8037FD9C: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_0:
L_8037FDA0:
    // 0x8037FDA0: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8037FDA4: lw          $a1, -0x5660($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5660);
    // 0x8037FDA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037FDAC: jal         0x80148C60
    // 0x8037FDB0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x80148C60)(rdram, ctx);
        goto after_1;
    // 0x8037FDB0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8037FDB4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037FDB8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8037FDBC: addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
    // 0x8037FDC0: addiu       $t9, $zero, 0x22
    ctx->r25 = ADD32(0, 0X22);
    // 0x8037FDC4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8037FDC8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8037FDCC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8037FDD0: lw          $a0, -0x5658($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5658);
    // 0x8037FDD4: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8037FDD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037FDDC: jal         0x801453CC
    // 0x8037FDE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_2;
    // 0x8037FDE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8037FDE4: lb          $t0, 0x94($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X94);
    // 0x8037FDE8: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037FDEC: beql        $t0, $zero, L_8037FE10
    if (ctx->r8 == 0) {
        // 0x8037FDF0: lw          $t1, 0x34($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X34);
            goto L_8037FE10;
    }
    goto skip_0;
    // 0x8037FDF0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8037FDF4: jal         0x801471DC
    // 0x8037FDF8: lw          $a0, -0x565C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X565C);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_3;
    // 0x8037FDF8: lw          $a0, -0x565C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X565C);
    after_3:
    // 0x8037FDFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037FE00: jal         0x8037DA84
    // 0x8037FE04: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    LOOKUP_FUNC(0x8037DA84)(rdram, ctx);
        goto after_4;
    // 0x8037FE04: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x8037FE08: sb          $zero, 0x94($s0)
    MEM_B(0X94, ctx->r16) = 0;
    // 0x8037FE0C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
L_8037FE10:
    // 0x8037FE10: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8037FE14: lhu         $v0, 0x4($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X4);
    // 0x8037FE18: andi        $t2, $v0, 0x4000
    ctx->r10 = ctx->r2 & 0X4000;
    // 0x8037FE1C: beq         $t2, $zero, L_8037FE4C
    if (ctx->r10 == 0) {
        // 0x8037FE20: andi        $t4, $v0, 0x1000
        ctx->r12 = ctx->r2 & 0X1000;
            goto L_8037FE4C;
    }
    // 0x8037FE20: andi        $t4, $v0, 0x1000
    ctx->r12 = ctx->r2 & 0X1000;
    // 0x8037FE24: jal         0x801471DC
    // 0x8037FE28: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_5;
    // 0x8037FE28: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    after_5:
    // 0x8037FE2C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8037FE30: addiu       $a1, $a1, -0x6734
    ctx->r5 = ADD32(ctx->r5, -0X6734);
    // 0x8037FE34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037FE38: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8037FE3C: jal         0x80148FC4
    // 0x8037FE40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_6;
    // 0x8037FE40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x8037FE44: b           L_8037FE78
    // 0x8037FE48: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8037FE78;
    // 0x8037FE48: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8037FE4C:
    // 0x8037FE4C: beql        $t4, $zero, L_8037FE78
    if (ctx->r12 == 0) {
        // 0x8037FE50: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8037FE78;
    }
    goto skip_1;
    // 0x8037FE50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8037FE54: jal         0x80148E44
    // 0x8037FE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148E44)(rdram, ctx);
        goto after_7;
    // 0x8037FE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8037FE5C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8037FE60: addiu       $a1, $a1, -0x54B8
    ctx->r5 = ADD32(ctx->r5, -0X54B8);
    // 0x8037FE64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037FE68: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8037FE6C: jal         0x80148FC4
    // 0x8037FE70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_8;
    // 0x8037FE70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x8037FE74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8037FE78:
    // 0x8037FE78: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8037FE7C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8037FE80: jr          $ra
    // 0x8037FE84: nop

    return;
    // 0x8037FE84: nop

;}
RECOMP_FUNC void M55_FUN_8037fe88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037FE88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037FE8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037FE90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8037FE94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8037FE98: addiu       $a1, $zero, 0x123
    ctx->r5 = ADD32(0, 0X123);
    // 0x8037FE9C: jal         0x80126A0C
    // 0x8037FEA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x8037FEA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8037FEA4: beq         $v0, $zero, L_8037FEC4
    if (ctx->r2 == 0) {
        // 0x8037FEA8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8037FEC4;
    }
    // 0x8037FEA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8037FEAC: jal         0x8037E118
    // 0x8037FEB0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x8037E118)(rdram, ctx);
        goto after_1;
    // 0x8037FEB0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8037FEB4: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037FEB8: addiu       $a1, $a1, -0x12C
    ctx->r5 = ADD32(ctx->r5, -0X12C);
    // 0x8037FEBC: jal         0x800058DC
    // 0x8037FEC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x8037FEC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8037FEC4:
    // 0x8037FEC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037FEC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037FECC: jr          $ra
    // 0x8037FED0: nop

    return;
    // 0x8037FED0: nop

;}
RECOMP_FUNC void M55_FUN_8037fed4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037FED4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037FED8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8037FEDC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8037FEE0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8037FEE4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8037FEE8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8037FEEC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8037FEF0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8037FEF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037FEF8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8037FEFC: lw          $v1, 0xA4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XA4);
    // 0x8037FF00: lui         $s4, 0x8039
    ctx->r20 = S32(0X8039 << 16);
    // 0x8037FF04: lui         $s5, 0x8039
    ctx->r21 = S32(0X8039 << 16);
    // 0x8037FF08: lhu         $a1, 0xC($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0XC);
    // 0x8037FF0C: addiu       $s5, $s5, -0x564C
    ctx->r21 = ADD32(ctx->r21, -0X564C);
    // 0x8037FF10: addiu       $s4, $s4, -0x5650
    ctx->r20 = ADD32(ctx->r20, -0X5650);
    // 0x8037FF14: andi        $t6, $a1, 0x800
    ctx->r14 = ctx->r5 & 0X800;
    // 0x8037FF18: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8037FF1C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037FF20: lw          $s1, 0x0($s4)
    ctx->r17 = MEM_W(ctx->r20, 0X0);
    // 0x8037FF24: beq         $t6, $zero, L_8037FF40
    if (ctx->r14 == 0) {
        // 0x8037FF28: lw          $s2, 0x0($s5)
        ctx->r18 = MEM_W(ctx->r21, 0X0);
            goto L_8037FF40;
    }
    // 0x8037FF28: lw          $s2, 0x0($s5)
    ctx->r18 = MEM_W(ctx->r21, 0X0);
    // 0x8037FF2C: lb          $t7, 0x97($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X97);
    // 0x8037FF30: blez        $t7, L_80380078
    if (SIGNED(ctx->r15) <= 0) {
            // 0x8037FF34: nop

    LOOKUP_FUNC(0x80380078)(rdram, ctx);
    return;
    }
    // 0x8037FF34: nop

    // 0x8037FF38: b           L_80380078
    // 0x8037FF3C: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    LOOKUP_FUNC(0x80380078)(rdram, ctx);
    return;
    // 0x8037FF3C: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_8037FF40:
    // 0x8037FF40: andi        $t8, $a1, 0x400
    ctx->r24 = ctx->r5 & 0X400;
    // 0x8037FF44: beql        $t8, $zero, L_8037FF68
    if (ctx->r24 == 0) {
        // 0x8037FF48: lhu         $v0, 0x4($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X4);
            goto L_8037FF68;
    }
    goto skip_0;
    // 0x8037FF48: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x8037FF4C: lb          $t9, 0x97($s6)
    ctx->r25 = MEM_B(ctx->r22, 0X97);
    // 0x8037FF50: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x8037FF54: beq         $at, $zero, L_80380078
    if (ctx->r1 == 0) {
            // 0x8037FF58: nop

    LOOKUP_FUNC(0x80380078)(rdram, ctx);
    return;
    }
    // 0x8037FF58: nop

    // 0x8037FF5C: b           L_80380078
    // 0x8037FF60: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80380078)(rdram, ctx);
    return;
    // 0x8037FF60: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8037FF64: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
L_8037FF68:
    // 0x8037FF68: andi        $t0, $v0, 0x8000
    ctx->r8 = ctx->r2 & 0X8000;
    // 0x8037FF6C: beq         $t0, $zero, L_80380010
    if (ctx->r8 == 0) {
            // 0x8037FF70: andi        $t4, $v0, 0x4000
    ctx->r12 = ctx->r2 & 0X4000;
    LOOKUP_FUNC(0x80380010)(rdram, ctx);
    return;
    }
    // 0x8037FF70: andi        $t4, $v0, 0x4000
    ctx->r12 = ctx->r2 & 0X4000;
    // 0x8037FF74: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x8037FF78: addiu       $s0, $s0, -0x5664
    ctx->r16 = ADD32(ctx->r16, -0X5664);
    // 0x8037FF7C: jal         0x80006088
    // 0x8037FF80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_0;
    // 0x8037FF80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x8037FF84: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8037FF88: jal         0x80006088
    // 0x8037FF8C: lw          $a0, 0x10($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X10);
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_1;
    // 0x8037FF8C: lw          $a0, 0x10($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X10);
    after_1:
    // 0x8037FF90: lui         $s3, 0x8039
    ctx->r19 = S32(0X8039 << 16);
    // 0x8037FF94: addiu       $s3, $s3, -0x563C
    ctx->r19 = ADD32(ctx->r19, -0X563C);
    // 0x8037FF98: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8037FF9C:
    // 0x8037FF9C: lb          $t2, 0x97($s6)
    ctx->r10 = MEM_B(ctx->r22, 0X97);
    // 0x8037FFA0: beql        $s0, $t2, L_8037FFC4
    if (ctx->r16 == ctx->r10) {
        // 0x8037FFA4: lw          $t3, 0x14($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X14);
            goto L_8037FFC4;
    }
    goto skip_1;
    // 0x8037FFA4: lw          $t3, 0x14($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X14);
    skip_1:
    // 0x8037FFA8: jal         0x80006088
    // 0x8037FFAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_2;
    // 0x8037FFAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8037FFB0: jal         0x80006088
    // 0x8037FFB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80006088)(rdram, ctx);
        goto after_3;
    // 0x8037FFB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x8037FFB8: b           L_8037FFD4
    // 0x8037FFBC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8037FFD4;
    // 0x8037FFBC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037FFC0: lw          $t3, 0x14($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X14);
L_8037FFC4:
    // 0x8037FFC4: sw          $s1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r17;
    // 0x8037FFC8: sw          $s2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r18;
    // 0x8037FFCC: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x8037FFD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8037FFD4:
    // 0x8037FFD4: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    // 0x8037FFD8: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x8037FFDC: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8037FFE0: lw          $s1, 0x10($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X10);
    // 0x8037FFE4: bne         $at, $zero, L_8037FF9C
    if (ctx->r1 != 0) {
        // 0x8037FFE8: lw          $s2, 0x10($s2)
        ctx->r18 = MEM_W(ctx->r18, 0X10);
            goto L_8037FF9C;
    }
    // 0x8037FFE8: lw          $s2, 0x10($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X10);
    // 0x8037FFEC: sh          $zero, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_8037fff0(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_8037fff0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037FFF0: jal         0x80020744
    // 0x8037FFF4: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x8037FFF4: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_0:
    // 0x8037FFF8: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037FFFC: addiu       $a1, $a1, 0xC4
    ctx->r5 = ADD32(ctx->r5, 0XC4);
    // 0x80380000: jal         0x800058DC
    // 0x80380004: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80380004: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x80380008: b           L_803800A0
    // 0x8038000C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x803800A0)(rdram, ctx);
    return;
    // 0x8038000C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80380010(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80380010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380010: beq         $t4, $zero, L_80380048
    if (ctx->r12 == 0) {
        // 0x80380014: andi        $t5, $v0, 0x1000
        ctx->r13 = ctx->r2 & 0X1000;
            goto L_80380048;
    }
    // 0x80380014: andi        $t5, $v0, 0x1000
    ctx->r13 = ctx->r2 & 0X1000;
    // 0x80380018: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x8038001C: addiu       $s0, $s0, -0x5664
    ctx->r16 = ADD32(ctx->r16, -0X5664);
    // 0x80380020: jal         0x801471DC
    // 0x80380024: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_0;
    // 0x80380024: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x80380028: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8038002C: addiu       $a1, $a1, -0x6734
    ctx->r5 = ADD32(ctx->r5, -0X6734);
    // 0x80380030: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80380034: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80380038: jal         0x80148FC4
    // 0x8038003C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_1;
    // 0x8038003C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80380040: b           L_803800A0
    // 0x80380044: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x803800A0)(rdram, ctx);
    return;
    // 0x80380044: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80380048:
    // 0x80380048: beq         $t5, $zero, L_80380078
    if (ctx->r13 == 0) {
            // 0x8038004C: nop

    LOOKUP_FUNC(0x80380078)(rdram, ctx);
    return;
    }
    // 0x8038004C: nop

    // 0x80380050: jal         0x80148E44
    // 0x80380054: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    LOOKUP_FUNC(0x80148E44)(rdram, ctx);
        goto after_2;
    // 0x80380054: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x80380058: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8038005C: addiu       $a1, $a1, -0x54B8
    ctx->r5 = ADD32(ctx->r5, -0X54B8);
    // 0x80380060: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80380064: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80380068: jal         0x80148FC4
    // 0x8038006C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_3;
    // 0x8038006C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80380070: b           L_803800A0
    // 0x80380074: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    LOOKUP_FUNC(0x803800A0)(rdram, ctx);
    return;
    // 0x80380074: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80380078(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80380078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380078: beql        $s0, $zero, L_8038008C
    if (ctx->r16 == 0) {
        // 0x8038007C: lb          $t6, 0x97($s6)
        ctx->r14 = MEM_B(ctx->r22, 0X97);
            goto L_8038008C;
    }
    goto skip_0;
    // 0x8038007C: lb          $t6, 0x97($s6)
    ctx->r14 = MEM_B(ctx->r22, 0X97);
    skip_0:
    // 0x80380080: jal         0x80020744
    // 0x80380084: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80380084: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_0:
    // 0x80380088: lb          $t6, 0x97($s6)
    ctx->r14 = MEM_B(ctx->r22, 0X97);
L_8038008C:
    // 0x8038008C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80380090: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80380094: jal         0x8037DF24
    // 0x80380098: sb          $t7, 0x97($s6)
    MEM_B(0X97, ctx->r22) = ctx->r15;
    LOOKUP_FUNC(0x8037DF24)(rdram, ctx);
        goto after_1;
    // 0x80380098: sb          $t7, 0x97($s6)
    MEM_B(0X97, ctx->r22) = ctx->r15;
    after_1:
    // 0x8038009C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803800a0(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803800a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803800A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803800A4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x803800A8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x803800AC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x803800B0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x803800B4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x803800B8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x803800BC: jr          $ra
    // 0x803800C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x803800C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_803800c4(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_803800c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803800C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803800C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803800CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803800D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803800D4: lhu         $t6, 0x3C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X3C);
    // 0x803800D8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x803800DC: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x803800E0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x803800E4: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x803800E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803800EC: lw          $a2, -0x564C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X564C);
    // 0x803800F0: lw          $a1, -0x5650($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5650);
    // 0x803800F4: jal         0x8037DD6C
    // 0x803800F8: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8037DD6C)(rdram, ctx);
        goto after_0;
    // 0x803800F8: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    after_0:
    // 0x803800FC: bnel        $v0, $zero, L_80380158
    if (ctx->r2 != 0) {
        // 0x80380100: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80380158;
    }
    goto skip_0;
    // 0x80380100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80380104: lb          $t8, 0x97($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X97);
    // 0x80380108: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8038010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380110: bne         $t8, $at, L_8038014C
    if (ctx->r24 != ctx->r1) {
        // 0x80380114: lui         $a1, 0x8038
        ctx->r5 = S32(0X8038 << 16);
            goto L_8038014C;
    }
    // 0x80380114: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80380118: sb          $zero, 0x97($s0)
    MEM_B(0X97, ctx->r16) = 0;
    // 0x8038011C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80380120: jal         0x801471DC
    // 0x80380124: lw          $a0, -0x5650($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5650);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_1;
    // 0x80380124: lw          $a0, -0x5650($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5650);
    after_1:
    // 0x80380128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8038012C: jal         0x8037E38C
    // 0x80380130: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x8037E38C)(rdram, ctx);
        goto after_2;
    // 0x80380130: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80380134: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80380138: addiu       $a1, $a1, 0x584
    ctx->r5 = ADD32(ctx->r5, 0X584);
    // 0x8038013C: jal         0x800058DC
    // 0x80380140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x80380140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80380144: b           L_80380158
    // 0x80380148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80380158;
    // 0x80380148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8038014C:
    // 0x8038014C: jal         0x800058DC
    // 0x80380150: addiu       $a1, $a1, 0x168
    ctx->r5 = ADD32(ctx->r5, 0X168);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x80380150: addiu       $a1, $a1, 0x168
    ctx->r5 = ADD32(ctx->r5, 0X168);
    after_4:
    // 0x80380154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80380158:
    // 0x80380158: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8038015C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80380160: jr          $ra
    // 0x80380164: nop

    return;
    // 0x80380164: nop

;}
RECOMP_FUNC void M55_FUN_80380168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380168: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8038016C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80380170: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80380174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80380178: jal         0x80006214
    // 0x8038017C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x8038017C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80380180: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x80380184: addiu       $t7, $zero, 0x100
    ctx->r15 = ADD32(0, 0X100);
    // 0x80380188: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8038018C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80380190: addiu       $t0, $zero, 0x21E
    ctx->r8 = ADD32(0, 0X21E);
    // 0x80380194: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80380198: sb          $v0, 0x45($sp)
    MEM_B(0X45, ctx->r29) = ctx->r2;
    // 0x8038019C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x803801A0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x803801A4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x803801A8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x803801AC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x803801B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x803801B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803801B8: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x803801BC: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x803801C0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x803801C4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x803801C8: jal         0x80146208
    // 0x803801CC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_1;
    // 0x803801CC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_1:
    // 0x803801D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803801D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x803801D8: jal         0x80145348
    // 0x803801DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_2;
    // 0x803801DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x803801E0: addiu       $t2, $zero, 0x44
    ctx->r10 = ADD32(0, 0X44);
    // 0x803801E4: addiu       $t3, $zero, 0x100
    ctx->r11 = ADD32(0, 0X100);
    // 0x803801E8: addiu       $t4, $zero, 0x88
    ctx->r12 = ADD32(0, 0X88);
    // 0x803801EC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x803801F0: addiu       $t6, $zero, 0x21E
    ctx->r14 = ADD32(0, 0X21E);
    // 0x803801F4: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x803801F8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x803801FC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80380200: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80380204: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80380208: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8038020C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80380210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380214: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x80380218: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    // 0x8038021C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80380220: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80380224: jal         0x80146208
    // 0x80380228: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x80380228: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_3:
    // 0x8038022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380230: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80380234: jal         0x80145348
    // 0x80380238: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_4;
    // 0x80380238: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8038023C: addiu       $t8, $zero, 0xCC
    ctx->r24 = ADD32(0, 0XCC);
    // 0x80380240: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x80380244: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80380248: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8038024C: addiu       $t2, $zero, 0x21E
    ctx->r10 = ADD32(0, 0X21E);
    // 0x80380250: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80380254: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80380258: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8038025C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80380260: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80380264: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80380268: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8038026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380270: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x80380274: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80380278: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8038027C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80380280: jal         0x80146208
    // 0x80380284: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_5;
    // 0x80380284: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_5:
    // 0x80380288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8038028C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80380290: jal         0x80145348
    // 0x80380294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_6;
    // 0x80380294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80380298: lbu         $t5, 0x45($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X45);
    // 0x8038029C: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x803802A0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803802A4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x803802A8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x803802AC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x803802B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803802B4: jal         0x80006214
    // 0x803802B8: sw          $t8, -0x5654($at)
    MEM_W(-0X5654, ctx->r1) = ctx->r24;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_7;
    // 0x803802B8: sw          $t8, -0x5654($at)
    MEM_W(-0X5654, ctx->r1) = ctx->r24;
    after_7:
    // 0x803802BC: addiu       $t9, $zero, 0x4A
    ctx->r25 = ADD32(0, 0X4A);
    // 0x803802C0: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x803802C4: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x803802C8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x803802CC: addiu       $t3, $zero, 0x209
    ctx->r11 = ADD32(0, 0X209);
    // 0x803802D0: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x803802D4: sb          $v0, 0x45($sp)
    MEM_B(0X45, ctx->r29) = ctx->r2;
    // 0x803802D8: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x803802DC: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x803802E0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x803802E4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x803802E8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x803802EC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x803802F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803802F4: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x803802F8: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x803802FC: addiu       $a3, $zero, 0x29
    ctx->r7 = ADD32(0, 0X29);
    // 0x80380300: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80380304: jal         0x80146208
    // 0x80380308: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_8;
    // 0x80380308: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_8:
    // 0x8038030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380310: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80380314: jal         0x80145348
    // 0x80380318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_9;
    // 0x80380318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x8038031C: addiu       $t4, $zero, 0xBE
    ctx->r12 = ADD32(0, 0XBE);
    // 0x80380320: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80380324: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80380328: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8038032C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80380330: addiu       $t0, $zero, 0x209
    ctx->r8 = ADD32(0, 0X209);
    // 0x80380334: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80380338: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8038033C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80380340: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80380344: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80380348: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8038034C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80380350: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80380354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380358: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x8038035C: addiu       $a2, $zero, 0xE6
    ctx->r6 = ADD32(0, 0XE6);
    // 0x80380360: addiu       $a3, $zero, 0x29
    ctx->r7 = ADD32(0, 0X29);
    // 0x80380364: jal         0x80146208
    // 0x80380368: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_10;
    // 0x80380368: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_10:
    // 0x8038036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80380374: jal         0x80145348
    // 0x80380378: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_11;
    // 0x80380378: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x8038037C: lbu         $t3, 0x45($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X45);
    // 0x80380380: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80380384: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80380388: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8038038C: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x80380390: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80380394: addiu       $v1, $v1, -0x5640
    ctx->r3 = ADD32(ctx->r3, -0X5640);
    // 0x80380398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8038039C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x803803A0: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x803803A4: sb          $zero, 0x22($t8)
    MEM_B(0X22, ctx->r24) = 0;
    // 0x803803A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x803803AC: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x803803B0: lbu         $t0, 0x22($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X22);
    // 0x803803B4: jal         0x8037ED08
    // 0x803803B8: sb          $t0, 0x22($v0)
    MEM_B(0X22, ctx->r2) = ctx->r8;
    LOOKUP_FUNC(0x8037ED08)(rdram, ctx);
        goto after_12;
    // 0x803803B8: sb          $t0, 0x22($v0)
    MEM_B(0X22, ctx->r2) = ctx->r8;
    after_12:
    // 0x803803BC: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x803803C0: sb          $v0, 0x95($s0)
    MEM_B(0X95, ctx->r16) = ctx->r2;
    // 0x803803C4: addiu       $a1, $a1, 0x3E4
    ctx->r5 = ADD32(ctx->r5, 0X3E4);
    // 0x803803C8: jal         0x800058DC
    // 0x803803CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_13;
    // 0x803803CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x803803D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x803803D4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x803803D8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x803803DC: jr          $ra
    // 0x803803E0: nop

    return;
    // 0x803803E0: nop

;}
RECOMP_FUNC void M55_FUN_803803e4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803803E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803803E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803803EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803803F0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803803F4: lw          $t6, 0xA4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA4);
    // 0x803803F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803803FC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80380400: lhu         $a1, 0xC($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0XC);
    // 0x80380404: lb          $v0, 0x96($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X96);
    // 0x80380408: andi        $t8, $a1, 0x800
    ctx->r24 = ctx->r5 & 0X800;
    // 0x8038040C: beq         $t8, $zero, L_80380424
    if (ctx->r24 == 0) {
        // 0x80380410: andi        $a2, $v0, 0xFFFF
        ctx->r6 = ctx->r2 & 0XFFFF;
            goto L_80380424;
    }
    // 0x80380410: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x80380414: blez        $v0, L_80380424
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80380418: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80380424;
    }
    // 0x80380418: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8038041C: sb          $t9, 0x96($a0)
    MEM_B(0X96, ctx->r4) = ctx->r25;
    // 0x80380420: lb          $v0, 0x96($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X96);
L_80380424:
    // 0x80380424: andi        $t0, $a1, 0x400
    ctx->r8 = ctx->r5 & 0X400;
    // 0x80380428: beq         $t0, $zero, L_80380450
    if (ctx->r8 == 0) {
        // 0x8038042C: nop
    
            goto L_80380450;
    }
    // 0x8038042C: nop

    // 0x80380430: lbu         $t1, 0x95($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X95);
    // 0x80380434: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80380438: addiu       $t2, $t1, -0xA
    ctx->r10 = ADD32(ctx->r9, -0XA);
    // 0x8038043C: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80380440: beq         $at, $zero, L_80380450
    if (ctx->r1 == 0) {
        // 0x80380444: nop
    
            goto L_80380450;
    }
    // 0x80380444: nop

    // 0x80380448: sb          $t3, 0x96($s0)
    MEM_B(0X96, ctx->r16) = ctx->r11;
    // 0x8038044C: lb          $v0, 0x96($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X96);
L_80380450:
    // 0x80380450: beq         $a2, $v0, L_80380468
    if (ctx->r6 == ctx->r2) {
        // 0x80380454: nop
    
            goto L_80380468;
    }
    // 0x80380454: nop

    // 0x80380458: jal         0x80020744
    // 0x8038045C: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x8038045C: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_0:
    // 0x80380460: jal         0x8037EBB0
    // 0x80380464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8037EBB0)(rdram, ctx);
        goto after_1;
    // 0x80380464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80380468:
    // 0x80380468: jal         0x8037EABC
    // 0x8038046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8037EABC)(rdram, ctx);
        goto after_2;
    // 0x8038046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80380470: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80380474: lhu         $v0, 0x4($t4)
    ctx->r2 = MEM_HU(ctx->r12, 0X4);
    // 0x80380478: andi        $t5, $v0, 0x4000
    ctx->r13 = ctx->r2 & 0X4000;
    // 0x8038047C: beq         $t5, $zero, L_803804B4
    if (ctx->r13 == 0) {
        // 0x80380480: andi        $t6, $v0, 0x1000
        ctx->r14 = ctx->r2 & 0X1000;
            goto L_803804B4;
    }
    // 0x80380480: andi        $t6, $v0, 0x1000
    ctx->r14 = ctx->r2 & 0X1000;
    // 0x80380484: jal         0x80147DCC
    // 0x80380488: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80147DCC)(rdram, ctx);
        goto after_3;
    // 0x80380488: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x8038048C: sh          $zero, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = 0;
    // 0x80380490: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80380494: jal         0x801471DC
    // 0x80380498: lw          $a0, -0x5654($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5654);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_4;
    // 0x80380498: lw          $a0, -0x5654($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5654);
    after_4:
    // 0x8038049C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x803804A0: addiu       $a1, $a1, 0x4F0
    ctx->r5 = ADD32(ctx->r5, 0X4F0);
    // 0x803804A4: jal         0x800058DC
    // 0x803804A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x803804A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x803804AC: b           L_803804E0
    // 0x803804B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_803804E0;
    // 0x803804B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803804B4:
    // 0x803804B4: beql        $t6, $zero, L_803804E0
    if (ctx->r14 == 0) {
        // 0x803804B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_803804E0;
    }
    goto skip_0;
    // 0x803804B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x803804BC: jal         0x80148E44
    // 0x803804C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148E44)(rdram, ctx);
        goto after_6;
    // 0x803804C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x803804C4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x803804C8: addiu       $a1, $a1, -0x54B8
    ctx->r5 = ADD32(ctx->r5, -0X54B8);
    // 0x803804CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803804D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x803804D4: jal         0x80148FC4
    // 0x803804D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_7;
    // 0x803804D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x803804DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803804E0:
    // 0x803804E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803804E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803804E8: jr          $ra
    // 0x803804EC: nop

    return;
    // 0x803804EC: nop

;}
RECOMP_FUNC void M55_FUN_803804f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803804F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803804F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803804F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803804FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80380500: lhu         $t6, 0x3C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X3C);
    // 0x80380504: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80380508: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038050C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80380510: sh          $t7, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r15;
    // 0x80380514: lb          $a3, 0x97($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X97);
    // 0x80380518: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8038051C: lw          $a2, -0x564C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X564C);
    // 0x80380520: addu        $at, $a3, $zero
    ctx->r1 = ADD32(ctx->r7, 0);
    // 0x80380524: sll         $a3, $a3, 4
    ctx->r7 = S32(ctx->r7 << 4);
    // 0x80380528: subu        $a3, $a3, $at
    ctx->r7 = SUB32(ctx->r7, ctx->r1);
    // 0x8038052C: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x80380530: addiu       $a3, $a3, 0x4B
    ctx->r7 = ADD32(ctx->r7, 0X4B);
    // 0x80380534: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80380538: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8038053C: jal         0x8037DD6C
    // 0x80380540: lw          $a1, -0x5650($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5650);
    LOOKUP_FUNC(0x8037DD6C)(rdram, ctx);
        goto after_0;
    // 0x80380540: lw          $a1, -0x5650($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5650);
    after_0:
    // 0x80380544: bne         $v0, $zero, L_80380570
    if (ctx->r2 != 0) {
        // 0x80380548: lui         $a0, 0x8039
        ctx->r4 = S32(0X8039 << 16);
            goto L_80380570;
    }
    // 0x80380548: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8038054C: jal         0x801471DC
    // 0x80380550: lw          $a0, -0x5650($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5650);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_1;
    // 0x80380550: lw          $a0, -0x5650($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5650);
    after_1:
    // 0x80380554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380558: jal         0x8037E118
    // 0x8038055C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x8037E118)(rdram, ctx);
        goto after_2;
    // 0x8038055C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80380560: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80380564: addiu       $a1, $a1, -0x12C
    ctx->r5 = ADD32(ctx->r5, -0X12C);
    // 0x80380568: jal         0x800058DC
    // 0x8038056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8038056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80380570:
    // 0x80380570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80380574: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80380578: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8038057C: jr          $ra
    // 0x80380580: nop

    return;
    // 0x80380580: nop

;}
RECOMP_FUNC void M55_FUN_80380584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380584: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80380588: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8038058C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80380590: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80380594: lw          $v1, 0xA4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XA4);
    // 0x80380598: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8038059C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x803805A0: lhu         $a2, 0xC($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0XC);
    // 0x803805A4: andi        $t6, $a2, 0x800
    ctx->r14 = ctx->r6 & 0X800;
    // 0x803805A8: beq         $t6, $zero, L_803805C4
    if (ctx->r14 == 0) {
        // 0x803805AC: andi        $t8, $a2, 0x400
        ctx->r24 = ctx->r6 & 0X400;
            goto L_803805C4;
    }
    // 0x803805AC: andi        $t8, $a2, 0x400
    ctx->r24 = ctx->r6 & 0X400;
    // 0x803805B0: lb          $t7, 0x97($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X97);
    // 0x803805B4: blez        $t7, L_8038073C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x803805B8: nop
    
            goto L_8038073C;
    }
    // 0x803805B8: nop

    // 0x803805BC: b           L_8038073C
    // 0x803805C0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_8038073C;
    // 0x803805C0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_803805C4:
    // 0x803805C4: beql        $t8, $zero, L_803805E8
    if (ctx->r24 == 0) {
        // 0x803805C8: lhu         $v0, 0x4($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X4);
            goto L_803805E8;
    }
    goto skip_0;
    // 0x803805C8: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x803805CC: lb          $t9, 0x97($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X97);
    // 0x803805D0: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x803805D4: beq         $at, $zero, L_8038073C
    if (ctx->r1 == 0) {
        // 0x803805D8: nop
    
            goto L_8038073C;
    }
    // 0x803805D8: nop

    // 0x803805DC: b           L_8038073C
    // 0x803805E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8038073C;
    // 0x803805E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x803805E4: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
L_803805E8:
    // 0x803805E8: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x803805EC: andi        $t0, $v0, 0x8000
    ctx->r8 = ctx->r2 & 0X8000;
    // 0x803805F0: beq         $t0, $zero, L_803806CC
    if (ctx->r8 == 0) {
        // 0x803805F4: andi        $t7, $v0, 0x4000
        ctx->r15 = ctx->r2 & 0X4000;
            goto L_803806CC;
    }
    // 0x803805F4: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
    // 0x803805F8: jal         0x801471DC
    // 0x803805FC: lw          $a0, -0x5650($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5650);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_0;
    // 0x803805FC: lw          $a0, -0x5650($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5650);
    after_0:
    // 0x80380600: jal         0x80147DCC
    // 0x80380604: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80147DCC)(rdram, ctx);
        goto after_1;
    // 0x80380604: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80380608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8038060C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80380610: jal         0x8037DC30
    // 0x80380614: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x8037DC30)(rdram, ctx);
        goto after_2;
    // 0x80380614: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_2:
    // 0x80380618: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038061C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80380620: sw          $v0, -0x5648($at)
    MEM_W(-0X5648, ctx->r1) = ctx->r2;
    // 0x80380624: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80380628: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8038062C: lb          $t2, 0x97($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X97);
    // 0x80380630: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x80380634: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80380638: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8038063C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80380640: lw          $t4, -0x73FC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73FC);
    // 0x80380644: addiu       $a3, $a3, -0x65DC
    ctx->r7 = ADD32(ctx->r7, -0X65DC);
    // 0x80380648: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8038064C: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80380650: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x80380654: jal         0x8001B204
    // 0x80380658: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_3;
    // 0x80380658: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_3:
    // 0x8038065C: lb          $t5, 0x97($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X97);
    // 0x80380660: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80380664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380668: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x8038066C: beq         $at, $zero, L_803806A4
    if (ctx->r1 == 0) {
        // 0x80380670: nop
    
            goto L_803806A4;
    }
    // 0x80380670: nop

    // 0x80380674: sb          $t6, 0x91($s0)
    MEM_B(0X91, ctx->r16) = ctx->r14;
    // 0x80380678: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8038067C: jal         0x8037E630
    // 0x80380680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8037E630)(rdram, ctx);
        goto after_4;
    // 0x80380680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80380684: jal         0x80020744
    // 0x80380688: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_5;
    // 0x80380688: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_5:
    // 0x8038068C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80380690: addiu       $a1, $a1, 0x778
    ctx->r5 = ADD32(ctx->r5, 0X778);
    // 0x80380694: jal         0x800058DC
    // 0x80380698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x80380698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8038069C: b           L_80380768
    // 0x803806A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80380768;
    // 0x803806A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_803806A4:
    // 0x803806A4: jal         0x8037E920
    // 0x803806A8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    LOOKUP_FUNC(0x8037E920)(rdram, ctx);
        goto after_7;
    // 0x803806A8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_7:
    // 0x803806AC: jal         0x80020744
    // 0x803806B0: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_8;
    // 0x803806B0: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    after_8:
    // 0x803806B4: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x803806B8: addiu       $a1, $a1, 0x908
    ctx->r5 = ADD32(ctx->r5, 0X908);
    // 0x803806BC: jal         0x800058DC
    // 0x803806C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x803806C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x803806C4: b           L_80380768
    // 0x803806C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80380768;
    // 0x803806C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_803806CC:
    // 0x803806CC: beq         $t7, $zero, L_8038070C
    if (ctx->r15 == 0) {
        // 0x803806D0: andi        $t9, $v0, 0x1000
        ctx->r25 = ctx->r2 & 0X1000;
            goto L_8038070C;
    }
    // 0x803806D0: andi        $t9, $v0, 0x1000
    ctx->r25 = ctx->r2 & 0X1000;
    // 0x803806D4: jal         0x80147DCC
    // 0x803806D8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80147DCC)(rdram, ctx);
        goto after_10;
    // 0x803806D8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x803806DC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x803806E0: sh          $zero, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = 0;
    // 0x803806E4: sb          $t8, 0x97($s0)
    MEM_B(0X97, ctx->r16) = ctx->r24;
    // 0x803806E8: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x803806EC: jal         0x801471DC
    // 0x803806F0: lw          $a0, -0x5648($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5648);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_11;
    // 0x803806F0: lw          $a0, -0x5648($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5648);
    after_11:
    // 0x803806F4: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x803806F8: addiu       $a1, $a1, 0x4F0
    ctx->r5 = ADD32(ctx->r5, 0X4F0);
    // 0x803806FC: jal         0x800058DC
    // 0x80380700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_12;
    // 0x80380700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80380704: b           L_80380768
    // 0x80380708: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80380768;
    // 0x80380708: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8038070C:
    // 0x8038070C: beq         $t9, $zero, L_8038073C
    if (ctx->r25 == 0) {
        // 0x80380710: nop
    
            goto L_8038073C;
    }
    // 0x80380710: nop

    // 0x80380714: jal         0x80148E44
    // 0x80380718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148E44)(rdram, ctx);
        goto after_13;
    // 0x80380718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8038071C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80380720: addiu       $a1, $a1, -0x54B8
    ctx->r5 = ADD32(ctx->r5, -0X54B8);
    // 0x80380724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380728: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8038072C: jal         0x80148FC4
    // 0x80380730: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_14;
    // 0x80380730: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x80380734: b           L_80380768
    // 0x80380738: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80380768;
    // 0x80380738: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8038073C:
    // 0x8038073C: beq         $a3, $zero, L_80380750
    if (ctx->r7 == 0) {
        // 0x80380740: addiu       $a0, $zero, 0x300
        ctx->r4 = ADD32(0, 0X300);
            goto L_80380750;
    }
    // 0x80380740: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x80380744: jal         0x80020744
    // 0x80380748: sb          $a3, 0x31($sp)
    MEM_B(0X31, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_15;
    // 0x80380748: sb          $a3, 0x31($sp)
    MEM_B(0X31, ctx->r29) = ctx->r7;
    after_15:
    // 0x8038074C: lb          $a3, 0x31($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X31);
L_80380750:
    // 0x80380750: lb          $t0, 0x97($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X97);
    // 0x80380754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380758: addu        $t1, $t0, $a3
    ctx->r9 = ADD32(ctx->r8, ctx->r7);
    // 0x8038075C: jal         0x8037DFDC
    // 0x80380760: sb          $t1, 0x97($s0)
    MEM_B(0X97, ctx->r16) = ctx->r9;
    LOOKUP_FUNC(0x8037DFDC)(rdram, ctx);
        goto after_16;
    // 0x80380760: sb          $t1, 0x97($s0)
    MEM_B(0X97, ctx->r16) = ctx->r9;
    after_16:
    // 0x80380764: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80380768:
    // 0x80380768: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8038076C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80380770: jr          $ra
    // 0x80380774: nop

    return;
    // 0x80380774: nop

;}
RECOMP_FUNC void M55_FUN_80380778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380778: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8038077C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80380780: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80380784: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80380788: lw          $t6, 0xA4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA4);
    // 0x8038078C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80380790: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80380794: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80380798: lhu         $v1, 0xC($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0XC);
    // 0x8038079C: andi        $t8, $v1, 0x200
    ctx->r24 = ctx->r3 & 0X200;
    // 0x803807A0: beq         $t8, $zero, L_803807C0
    if (ctx->r24 == 0) {
        // 0x803807A4: andi        $t0, $v1, 0x100
        ctx->r8 = ctx->r3 & 0X100;
            goto L_803807C0;
    }
    // 0x803807A4: andi        $t0, $v1, 0x100
    ctx->r8 = ctx->r3 & 0X100;
    // 0x803807A8: lb          $t9, 0x91($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X91);
    // 0x803807AC: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x803807B0: bne         $at, $zero, L_803807DC
    if (ctx->r1 != 0) {
        // 0x803807B4: nop
    
            goto L_803807DC;
    }
    // 0x803807B4: nop

    // 0x803807B8: b           L_803807DC
    // 0x803807BC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_803807DC;
    // 0x803807BC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_803807C0:
    // 0x803807C0: beq         $t0, $zero, L_803807DC
    if (ctx->r8 == 0) {
        // 0x803807C4: nop
    
            goto L_803807DC;
    }
    // 0x803807C4: nop

    // 0x803807C8: lb          $t1, 0x91($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X91);
    // 0x803807CC: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x803807D0: beq         $at, $zero, L_803807DC
    if (ctx->r1 == 0) {
        // 0x803807D4: nop
    
            goto L_803807DC;
    }
    // 0x803807D4: nop

    // 0x803807D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_803807DC:
    // 0x803807DC: beq         $a2, $zero, L_8038081C
    if (ctx->r6 == 0) {
        // 0x803807E0: addiu       $a0, $zero, 0x300
        ctx->r4 = ADD32(0, 0X300);
            goto L_8038081C;
    }
    // 0x803807E0: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    // 0x803807E4: jal         0x80020744
    // 0x803807E8: sb          $a2, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x803807E8: sb          $a2, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r6;
    after_0:
    // 0x803807EC: lb          $a2, 0x39($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X39);
    // 0x803807F0: lb          $t2, 0x91($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X91);
    // 0x803807F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x803807F8: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x803807FC: jal         0x80147DCC
    // 0x80380800: sb          $t3, 0x91($s0)
    MEM_B(0X91, ctx->r16) = ctx->r11;
    LOOKUP_FUNC(0x80147DCC)(rdram, ctx);
        goto after_1;
    // 0x80380800: sb          $t3, 0x91($s0)
    MEM_B(0X91, ctx->r16) = ctx->r11;
    after_1:
    // 0x80380804: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80380808: jal         0x801471DC
    // 0x8038080C: lw          $a0, -0x5640($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5640);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_2;
    // 0x8038080C: lw          $a0, -0x5640($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5640);
    after_2:
    // 0x80380810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380814: jal         0x8037E630
    // 0x80380818: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8037E630)(rdram, ctx);
        goto after_3;
    // 0x80380818: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_3:
L_8038081C:
    // 0x8038081C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80380820: lw          $a0, -0x5640($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5640);
    // 0x80380824: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80380828: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8038082C: addiu       $t6, $zero, 0x1A
    ctx->r14 = ADD32(0, 0X1A);
    // 0x80380830: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80380834: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80380838: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8038083C: addiu       $a1, $zero, 0x180
    ctx->r5 = ADD32(0, 0X180);
    // 0x80380840: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80380844: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    // 0x80380848: jal         0x801453CC
    // 0x8038084C: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_4;
    // 0x8038084C: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_4:
    // 0x80380850: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80380854: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80380858: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8038085C: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    // 0x80380860: addiu       $t9, $zero, 0x1A
    ctx->r25 = ADD32(0, 0X1A);
    // 0x80380864: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80380868: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8038086C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80380870: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80380874: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80380878: jal         0x801453CC
    // 0x8038087C: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    LOOKUP_FUNC(0x801453CC)(rdram, ctx);
        goto after_5;
    // 0x8038087C: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    after_5:
    // 0x80380880: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80380884: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80380888: lhu         $v0, 0x4($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X4);
    // 0x8038088C: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x80380890: beq         $t1, $zero, L_803808CC
    if (ctx->r9 == 0) {
        // 0x80380894: andi        $t2, $v0, 0x1000
        ctx->r10 = ctx->r2 & 0X1000;
            goto L_803808CC;
    }
    // 0x80380894: andi        $t2, $v0, 0x1000
    ctx->r10 = ctx->r2 & 0X1000;
    // 0x80380898: jal         0x801471DC
    // 0x8038089C: lw          $a0, -0x5648($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5648);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_6;
    // 0x8038089C: lw          $a0, -0x5648($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5648);
    after_6:
    // 0x803808A0: jal         0x80147DCC
    // 0x803808A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80147DCC)(rdram, ctx);
        goto after_7;
    // 0x803808A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x803808A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803808AC: jal         0x8037E38C
    // 0x803808B0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    LOOKUP_FUNC(0x8037E38C)(rdram, ctx);
        goto after_8;
    // 0x803808B0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_8:
    // 0x803808B4: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x803808B8: addiu       $a1, $a1, 0x584
    ctx->r5 = ADD32(ctx->r5, 0X584);
    // 0x803808BC: jal         0x800058DC
    // 0x803808C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x803808C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x803808C4: b           L_803808F8
    // 0x803808C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_803808F8;
    // 0x803808C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_803808CC:
    // 0x803808CC: beql        $t2, $zero, L_803808F8
    if (ctx->r10 == 0) {
        // 0x803808D0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_803808F8;
    }
    goto skip_0;
    // 0x803808D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x803808D4: jal         0x80148E44
    // 0x803808D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148E44)(rdram, ctx);
        goto after_10;
    // 0x803808D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x803808DC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x803808E0: addiu       $a1, $a1, -0x54B8
    ctx->r5 = ADD32(ctx->r5, -0X54B8);
    // 0x803808E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803808E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x803808EC: jal         0x80148FC4
    // 0x803808F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_11;
    // 0x803808F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // 0x803808F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_803808F8:
    // 0x803808F8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x803808FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80380900: jr          $ra
    // 0x80380904: nop

    return;
    // 0x80380904: nop

;}
RECOMP_FUNC void M55_FUN_80380908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380908: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8038090C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80380910: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80380914: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80380918: lw          $v0, 0xA4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA4);
    // 0x8038091C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80380920: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80380924: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x80380928: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    // 0x8038092C: beq         $t6, $zero, L_80380968
    if (ctx->r14 == 0) {
        // 0x80380930: andi        $t7, $v1, 0x1000
        ctx->r15 = ctx->r3 & 0X1000;
            goto L_80380968;
    }
    // 0x80380930: andi        $t7, $v1, 0x1000
    ctx->r15 = ctx->r3 & 0X1000;
    // 0x80380934: jal         0x801471DC
    // 0x80380938: lw          $a0, -0x5648($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5648);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_0;
    // 0x80380938: lw          $a0, -0x5648($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5648);
    after_0:
    // 0x8038093C: jal         0x80147DCC
    // 0x80380940: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80147DCC)(rdram, ctx);
        goto after_1;
    // 0x80380940: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80380944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380948: jal         0x8037E38C
    // 0x8038094C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(0x8037E38C)(rdram, ctx);
        goto after_2;
    // 0x8038094C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80380950: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80380954: addiu       $a1, $a1, 0x584
    ctx->r5 = ADD32(ctx->r5, 0X584);
    // 0x80380958: jal         0x800058DC
    // 0x8038095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x8038095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80380960: b           L_80380994
    // 0x80380964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80380994;
    // 0x80380964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80380968:
    // 0x80380968: beql        $t7, $zero, L_80380994
    if (ctx->r15 == 0) {
        // 0x8038096C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80380994;
    }
    goto skip_0;
    // 0x8038096C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80380970: jal         0x80148E44
    // 0x80380974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148E44)(rdram, ctx);
        goto after_4;
    // 0x80380974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80380978: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8038097C: addiu       $a1, $a1, -0x54B8
    ctx->r5 = ADD32(ctx->r5, -0X54B8);
    // 0x80380980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380984: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80380988: jal         0x80148FC4
    // 0x8038098C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_5;
    // 0x8038098C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80380990: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80380994:
    // 0x80380994: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80380998: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8038099C: jr          $ra
    // 0x803809A0: nop

    return;
    // 0x803809A0: nop

;}
RECOMP_FUNC void M55_FUN_803809a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803809A4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x803809A8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x803809AC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x803809B0: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x803809B4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x803809B8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x803809BC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x803809C0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x803809C4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x803809C8: addiu       $a1, $zero, 0x124
    ctx->r5 = ADD32(0, 0X124);
    // 0x803809CC: jal         0x80126A0C
    // 0x803809D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80126A0C)(rdram, ctx);
        goto after_0;
    // 0x803809D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x803809D4: beql        $v0, $zero, L_80380C40
    if (ctx->r2 == 0) {
        // 0x803809D8: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80380C40;
    }
    goto skip_0;
    // 0x803809D8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x803809DC: jal         0x80006214
    // 0x803809E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x803809E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x803809E4: addiu       $s3, $sp, 0x5E
    ctx->r19 = ADD32(ctx->r29, 0X5E);
    // 0x803809E8: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x803809EC: addiu       $t7, $zero, 0x60
    ctx->r15 = ADD32(0, 0X60);
    // 0x803809F0: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x803809F4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x803809F8: addiu       $t0, $zero, 0x20E
    ctx->r8 = ADD32(0, 0X20E);
    // 0x803809FC: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80380A00: sb          $v0, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = ctx->r2;
    // 0x80380A04: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80380A08: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80380A0C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80380A10: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80380A14: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80380A18: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80380A1C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80380A20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80380A24: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80380A28: addiu       $a3, $zero, 0x70
    ctx->r7 = ADD32(0, 0X70);
    // 0x80380A2C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80380A30: jal         0x80146208
    // 0x80380A34: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_2;
    // 0x80380A34: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_2:
    // 0x80380A38: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x80380A3C: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x80380A40: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80380A44: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80380A48: addiu       $t6, $zero, 0x21F
    ctx->r14 = ADD32(0, 0X21F);
    // 0x80380A4C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80380A50: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80380A54: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80380A58: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80380A5C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80380A60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80380A64: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80380A68: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80380A6C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x80380A70: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80380A74: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80380A78: jal         0x80146208
    // 0x80380A7C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_3;
    // 0x80380A7C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_3:
    // 0x80380A80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80380A84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80380A88: jal         0x80145348
    // 0x80380A8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_4;
    // 0x80380A8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80380A90: lbu         $t8, 0x5D($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X5D);
    // 0x80380A94: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80380A98: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80380A9C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80380AA0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80380AA4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80380AA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80380AAC: jal         0x80006214
    // 0x80380AB0: sw          $t1, -0x5664($at)
    MEM_W(-0X5664, ctx->r1) = ctx->r9;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_5;
    // 0x80380AB0: sw          $t1, -0x5664($at)
    MEM_W(-0X5664, ctx->r1) = ctx->r9;
    after_5:
    // 0x80380AB4: sb          $v0, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = ctx->r2;
    // 0x80380AB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80380ABC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80380AC0: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
L_80380AC4:
    // 0x80380AC4: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80380AC8: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x80380ACC: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80380AD0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80380AD4: addiu       $t5, $zero, 0x21F
    ctx->r13 = ADD32(0, 0X21F);
    // 0x80380AD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80380ADC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80380AE0: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80380AE4: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80380AE8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80380AEC: mflo        $s1
    ctx->r17 = lo;
    // 0x80380AF0: addiu       $s1, $s1, 0x46
    ctx->r17 = ADD32(ctx->r17, 0X46);
    // 0x80380AF4: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80380AF8: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80380AFC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80380B00: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80380B04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80380B08: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80380B0C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80380B10: addiu       $a3, $zero, 0x94
    ctx->r7 = ADD32(0, 0X94);
    // 0x80380B14: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80380B18: jal         0x80146208
    // 0x80380B1C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_6;
    // 0x80380B1C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_6:
    // 0x80380B20: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x80380B24: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80380B28: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80380B2C: addiu       $t0, $zero, 0x21F
    ctx->r8 = ADD32(0, 0X21F);
    // 0x80380B30: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80380B34: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80380B38: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80380B3C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80380B40: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80380B44: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80380B48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80380B4C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80380B50: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80380B54: addiu       $a3, $zero, 0xDA
    ctx->r7 = ADD32(0, 0XDA);
    // 0x80380B58: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80380B5C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80380B60: jal         0x80146208
    // 0x80380B64: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_7;
    // 0x80380B64: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_7:
    // 0x80380B68: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80380B6C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80380B70: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80380B74: bne         $at, $zero, L_80380AC4
    if (ctx->r1 != 0) {
        // 0x80380B78: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80380AC4;
    }
    // 0x80380B78: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80380B7C: lbu         $t3, 0x5D($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X5D);
    // 0x80380B80: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80380B84: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80380B88: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80380B8C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80380B90: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80380B94: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80380B98: addiu       $t8, $zero, 0x4A
    ctx->r24 = ADD32(0, 0X4A);
    // 0x80380B9C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80380BA0: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80380BA4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80380BA8: addiu       $t1, $zero, 0x209
    ctx->r9 = ADD32(0, 0X209);
    // 0x80380BAC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80380BB0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80380BB4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80380BB8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80380BBC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80380BC0: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80380BC4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80380BC8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80380BCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80380BD0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80380BD4: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x80380BD8: addiu       $a3, $zero, 0x2A
    ctx->r7 = ADD32(0, 0X2A);
    // 0x80380BDC: jal         0x80146208
    // 0x80380BE0: sw          $t6, -0x5638($at)
    MEM_W(-0X5638, ctx->r1) = ctx->r14;
    LOOKUP_FUNC(0x80146208)(rdram, ctx);
        goto after_8;
    // 0x80380BE0: sw          $t6, -0x5638($at)
    MEM_W(-0X5638, ctx->r1) = ctx->r14;
    after_8:
    // 0x80380BE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80380BE8: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80380BEC: jal         0x80145348
    // 0x80380BF0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    LOOKUP_FUNC(0x80145348)(rdram, ctx);
        goto after_9;
    // 0x80380BF0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_9:
    // 0x80380BF4: jal         0x80006214
    // 0x80380BF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_10;
    // 0x80380BF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x80380BFC: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80380C00: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80380C04: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80380C08: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80380C0C: lw          $t6, -0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X4);
    // 0x80380C10: sw          $t6, -0x5640($at)
    MEM_W(-0X5640, ctx->r1) = ctx->r14;
    // 0x80380C14: jal         0x8037F3B4
    // 0x80380C18: sb          $zero, 0x96($s2)
    MEM_B(0X96, ctx->r18) = 0;
    LOOKUP_FUNC(0x8037F3B4)(rdram, ctx);
        goto after_11;
    // 0x80380C18: sb          $zero, 0x96($s2)
    MEM_B(0X96, ctx->r18) = 0;
    after_11:
    // 0x80380C1C: jal         0x8037EDF4
    // 0x80380C20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x8037EDF4)(rdram, ctx);
        goto after_12;
    // 0x80380C20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x80380C24: jal         0x8037EF2C
    // 0x80380C28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x8037EF2C)(rdram, ctx);
        goto after_13;
    // 0x80380C28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x80380C2C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80380C30: addiu       $a1, $a1, 0xC5C
    ctx->r5 = ADD32(ctx->r5, 0XC5C);
    // 0x80380C34: jal         0x800058DC
    // 0x80380C38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_14;
    // 0x80380C38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x80380C3C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80380C40:
    // 0x80380C40: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80380C44: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80380C48: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80380C4C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80380C50: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80380C54: jr          $ra
    // 0x80380C58: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80380C58: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M55_FUN_80380c5c(rdram, ctx);
;}
RECOMP_FUNC void M55_FUN_80380c5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380C5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80380C60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80380C64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80380C68: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80380C6C: lw          $t6, 0xA4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA4);
    // 0x80380C70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80380C74: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80380C78: lhu         $a1, 0xC($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0XC);
    // 0x80380C7C: lb          $v0, 0x96($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X96);
    // 0x80380C80: andi        $t8, $a1, 0x800
    ctx->r24 = ctx->r5 & 0X800;
    // 0x80380C84: beq         $t8, $zero, L_80380CA0
    if (ctx->r24 == 0) {
        // 0x80380C88: sb          $v0, 0x21($sp)
        MEM_B(0X21, ctx->r29) = ctx->r2;
            goto L_80380CA0;
    }
    // 0x80380C88: sb          $v0, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r2;
    // 0x80380C8C: blez        $v0, L_80380CA0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80380C90: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80380CA0;
    }
    // 0x80380C90: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80380C94: sb          $t9, 0x96($a0)
    MEM_B(0X96, ctx->r4) = ctx->r25;
    // 0x80380C98: b           L_80380D54
    // 0x80380C9C: lb          $v0, 0x96($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X96);
        goto L_80380D54;
    // 0x80380C9C: lb          $v0, 0x96($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X96);
L_80380CA0:
    // 0x80380CA0: andi        $t0, $a1, 0x400
    ctx->r8 = ctx->r5 & 0X400;
    // 0x80380CA4: beq         $t0, $zero, L_80380CC0
    if (ctx->r8 == 0) {
        // 0x80380CA8: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_80380CC0;
    }
    // 0x80380CA8: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80380CAC: beq         $at, $zero, L_80380CC0
    if (ctx->r1 == 0) {
        // 0x80380CB0: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_80380CC0;
    }
    // 0x80380CB0: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80380CB4: sb          $t1, 0x96($s0)
    MEM_B(0X96, ctx->r16) = ctx->r9;
    // 0x80380CB8: b           L_80380D54
    // 0x80380CBC: lb          $v0, 0x96($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X96);
        goto L_80380D54;
    // 0x80380CBC: lb          $v0, 0x96($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X96);
L_80380CC0:
    // 0x80380CC0: andi        $t2, $a1, 0x100
    ctx->r10 = ctx->r5 & 0X100;
    // 0x80380CC4: beq         $t2, $zero, L_80380D0C
    if (ctx->r10 == 0) {
        // 0x80380CC8: lui         $t3, 0x8039
        ctx->r11 = S32(0X8039 << 16);
            goto L_80380D0C;
    }
    // 0x80380CC8: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80380CCC: addiu       $t3, $t3, -0x56B0
    ctx->r11 = ADD32(ctx->r11, -0X56B0);
    // 0x80380CD0: addu        $v1, $v0, $t3
    ctx->r3 = ADD32(ctx->r2, ctx->r11);
    // 0x80380CD4: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
    // 0x80380CD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80380CDC: bnel        $t4, $at, L_80380D00
    if (ctx->r12 != ctx->r1) {
        // 0x80380CE0: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80380D00;
    }
    goto skip_0;
    // 0x80380CE0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    skip_0:
    // 0x80380CE4: jal         0x80020744
    // 0x80380CE8: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_0;
    // 0x80380CE8: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_0:
    // 0x80380CEC: lb          $t5, 0x96($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X96);
    // 0x80380CF0: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80380CF4: addiu       $t6, $t6, -0x56B0
    ctx->r14 = ADD32(ctx->r14, -0X56B0);
    // 0x80380CF8: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x80380CFC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_80380D00:
    // 0x80380D00: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x80380D04: b           L_80380D54
    // 0x80380D08: lb          $v0, 0x96($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X96);
        goto L_80380D54;
    // 0x80380D08: lb          $v0, 0x96($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X96);
L_80380D0C:
    // 0x80380D0C: andi        $t8, $a1, 0x200
    ctx->r24 = ctx->r5 & 0X200;
    // 0x80380D10: beq         $t8, $zero, L_80380D54
    if (ctx->r24 == 0) {
        // 0x80380D14: lui         $t9, 0x8039
        ctx->r25 = S32(0X8039 << 16);
            goto L_80380D54;
    }
    // 0x80380D14: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80380D18: addiu       $t9, $t9, -0x56B0
    ctx->r25 = ADD32(ctx->r25, -0X56B0);
    // 0x80380D1C: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x80380D20: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x80380D24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80380D28: bnel        $t0, $at, L_80380D4C
    if (ctx->r8 != ctx->r1) {
        // 0x80380D2C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80380D4C;
    }
    goto skip_1;
    // 0x80380D2C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    skip_1:
    // 0x80380D30: jal         0x80020744
    // 0x80380D34: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_1;
    // 0x80380D34: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_1:
    // 0x80380D38: lb          $t1, 0x96($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X96);
    // 0x80380D3C: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80380D40: addiu       $t2, $t2, -0x56B0
    ctx->r10 = ADD32(ctx->r10, -0X56B0);
    // 0x80380D44: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80380D48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80380D4C:
    // 0x80380D4C: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x80380D50: lb          $v0, 0x96($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X96);
L_80380D54:
    // 0x80380D54: lb          $t4, 0x21($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X21);
    // 0x80380D58: beq         $t4, $v0, L_80380D68
    if (ctx->r12 == ctx->r2) {
        // 0x80380D5C: nop
    
            goto L_80380D68;
    }
    // 0x80380D5C: nop

    // 0x80380D60: jal         0x80020744
    // 0x80380D64: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    LOOKUP_FUNC(0x80020744)(rdram, ctx);
        goto after_2;
    // 0x80380D64: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_2:
L_80380D68:
    // 0x80380D68: jal         0x8037EDF4
    // 0x80380D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8037EDF4)(rdram, ctx);
        goto after_3;
    // 0x80380D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80380D70: jal         0x8037EF2C
    // 0x80380D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8037EF2C)(rdram, ctx);
        goto after_4;
    // 0x80380D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80380D78: jal         0x8037F0C8
    // 0x80380D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8037F0C8)(rdram, ctx);
        goto after_5;
    // 0x80380D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80380D80: jal         0x8037F370
    // 0x80380D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8037F370)(rdram, ctx);
        goto after_6;
    // 0x80380D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80380D88: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80380D8C: lhu         $v0, 0x4($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0X4);
    // 0x80380D90: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x80380D94: beql        $t6, $zero, L_80380DD4
    if (ctx->r14 == 0) {
        // 0x80380D98: andi        $t7, $v0, 0x1000
        ctx->r15 = ctx->r2 & 0X1000;
            goto L_80380DD4;
    }
    goto skip_2;
    // 0x80380D98: andi        $t7, $v0, 0x1000
    ctx->r15 = ctx->r2 & 0X1000;
    skip_2:
    // 0x80380D9C: jal         0x80147DCC
    // 0x80380DA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x80147DCC)(rdram, ctx);
        goto after_7;
    // 0x80380DA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x80380DA4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80380DA8: jal         0x801471DC
    // 0x80380DAC: lw          $a0, -0x5664($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5664);
    LOOKUP_FUNC(0x801471DC)(rdram, ctx);
        goto after_8;
    // 0x80380DAC: lw          $a0, -0x5664($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5664);
    after_8:
    // 0x80380DB0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80380DB4: addiu       $a1, $a1, -0x6734
    ctx->r5 = ADD32(ctx->r5, -0X6734);
    // 0x80380DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380DBC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80380DC0: jal         0x80148FC4
    // 0x80380DC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_9;
    // 0x80380DC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80380DC8: b           L_80380E00
    // 0x80380DCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80380E00;
    // 0x80380DCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80380DD0: andi        $t7, $v0, 0x1000
    ctx->r15 = ctx->r2 & 0X1000;
L_80380DD4:
    // 0x80380DD4: beql        $t7, $zero, L_80380E00
    if (ctx->r15 == 0) {
        // 0x80380DD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80380E00;
    }
    goto skip_3;
    // 0x80380DD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80380DDC: jal         0x80148E44
    // 0x80380DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80148E44)(rdram, ctx);
        goto after_10;
    // 0x80380DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80380DE4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80380DE8: addiu       $a1, $a1, -0x54B8
    ctx->r5 = ADD32(ctx->r5, -0X54B8);
    // 0x80380DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380DF0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80380DF4: jal         0x80148FC4
    // 0x80380DF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x80148FC4)(rdram, ctx);
        goto after_11;
    // 0x80380DF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // 0x80380DFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80380E00:
    // 0x80380E00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80380E04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80380E08: jr          $ra
    // 0x80380E0C: nop

    return;
    // 0x80380E0C: nop

;}
RECOMP_FUNC void M55_FUN_80380e10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380E10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80380E14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80380E18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80380E1C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80380E20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80380E24: jal         0x80005670
    // 0x80380E28: addiu       $a1, $a1, 0x1D64
    ctx->r5 = ADD32(ctx->r5, 0X1D64);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x80380E28: addiu       $a1, $a1, 0x1D64
    ctx->r5 = ADD32(ctx->r5, 0X1D64);
    after_0:
    // 0x80380E2C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80380E30: addiu       $a1, $a1, 0xE4C
    ctx->r5 = ADD32(ctx->r5, 0XE4C);
    // 0x80380E34: jal         0x800058DC
    // 0x80380E38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x80380E38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80380E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80380E40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80380E44: jr          $ra
    // 0x80380E48: nop

    return;
    // 0x80380E48: nop

;}
RECOMP_FUNC void M55_FUN_80380e4c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380E4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80380E50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80380E54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80380E58: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80380E5C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80380E60: bnel        $t6, $zero, L_80380E74
    if (ctx->r14 != 0) {
        // 0x80380E64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80380E74;
    }
    goto skip_0;
    // 0x80380E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80380E68: jal         0x80005700
    // 0x80380E6C: sw          $zero, -0x73A0($at)
    MEM_W(-0X73A0, ctx->r1) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x80380E6C: sw          $zero, -0x73A0($at)
    MEM_W(-0X73A0, ctx->r1) = 0;
    after_0:
    // 0x80380E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80380E74:
    // 0x80380E74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80380E78: jr          $ra
    // 0x80380E7C: nop

    return;
    // 0x80380E7C: nop

;}
RECOMP_FUNC void M55_FUN_80380e80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380E80: jr          $ra
    // 0x80380E84: nop

    return;
    // 0x80380E84: nop

;}
