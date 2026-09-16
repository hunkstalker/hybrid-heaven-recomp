#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M25_FUN_801ef844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF844: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EF848: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EF84C: jr          $ra
    // 0x801EF850: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x801EF850: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ef854(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ef854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF854: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EF858: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EF85C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EF860: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EF864: lui         $a1, 0x53
    ctx->r5 = S32(0X53 << 16);
    // 0x801EF868: ori         $a1, $a1, 0xEC60
    ctx->r5 = ctx->r5 | 0XEC60;
    // 0x801EF86C: jal         0x801C0B8C
    // 0x801EF870: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EF870: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EF874: beq         $v0, $zero, L_801EF890
    if (ctx->r2 == 0) {
        // 0x801EF878: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801EF890;
    }
    // 0x801EF878: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EF87C: sw          $zero, -0x2BA8($at)
    MEM_W(-0X2BA8, ctx->r1) = 0;
    // 0x801EF880: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EF884: sw          $zero, -0x2BA4($at)
    MEM_W(-0X2BA4, ctx->r1) = 0;
    // 0x801EF888: b           L_801EF894
    // 0x801EF88C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801EF894;
    // 0x801EF88C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801EF890:
    // 0x801EF890: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801EF894:
    // 0x801EF894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EF898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EF89C: jr          $ra
    // 0x801EF8A0: nop

    return;
    // 0x801EF8A0: nop

;}
RECOMP_FUNC void M25_FUN_801ef8a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF8A4: lui         $v1, 0x8020
    ctx->r3 = S32(0X8020 << 16);
    // 0x801EF8A8: lw          $v1, -0x2BA4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2BA4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801ef8ac(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801ef8ac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF8AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801EF8B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EF8B4: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x801EF8B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801EF8BC: bne         $at, $zero, L_801EF998
    if (ctx->r1 != 0) {
        // 0x801EF8C0: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_801EF998;
    }
    // 0x801EF8C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801EF8C4: lui         $t6, 0x8020
    ctx->r14 = S32(0X8020 << 16);
    // 0x801EF8C8: lw          $t6, -0x2BA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BA8);
    // 0x801EF8CC: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x801EF8D0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801EF8D4: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x801EF8D8: mfhi        $t7
    ctx->r15 = hi;
    // 0x801EF8DC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x801EF8E0: jal         0x801302CC
    // 0x801EF8E4: nop

    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_0;
    // 0x801EF8E4: nop

    after_0:
    // 0x801EF8E8: beq         $v0, $zero, L_801EF8F8
    if (ctx->r2 == 0) {
        // 0x801EF8EC: lui         $a0, 0x8020
        ctx->r4 = S32(0X8020 << 16);
            goto L_801EF8F8;
    }
    // 0x801EF8EC: lui         $a0, 0x8020
    ctx->r4 = S32(0X8020 << 16);
    // 0x801EF8F0: addiu       $t8, $zero, -0x14
    ctx->r24 = ADD32(0, -0X14);
    // 0x801EF8F4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_801EF8F8:
    // 0x801EF8F8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801EF8FC: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x801EF900: lw          $a1, -0x4920($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4920);
    // 0x801EF904: addiu       $a0, $a0, -0x2BA0
    ctx->r4 = ADD32(ctx->r4, -0X2BA0);
    // 0x801EF908: jal         0x8038CAF4
    // 0x801EF90C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    LOOKUP_FUNC(0x8038CAF4)(rdram, ctx);
        goto after_1;
    // 0x801EF90C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_1:
    // 0x801EF910: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x801EF914: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801EF918: lui         $a3, 0x8020
    ctx->r7 = S32(0X8020 << 16);
    // 0x801EF91C: addiu       $a3, $a3, -0x2BA0
    ctx->r7 = ADD32(ctx->r7, -0X2BA0);
    // 0x801EF920: addiu       $a2, $a2, 0xBA
    ctx->r6 = ADD32(ctx->r6, 0XBA);
    // 0x801EF924: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x801EF928: addu        $v1, $a3, $t9
    ctx->r3 = ADD32(ctx->r7, ctx->r25);
    // 0x801EF92C: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x801EF930: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x801EF934: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x801EF938: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EF93C: jal         0x8001B204
    // 0x801EF940: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_2;
    // 0x801EF940: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_2:
    // 0x801EF944: lui         $a0, 0x8020
    ctx->r4 = S32(0X8020 << 16);
    // 0x801EF948: addiu       $a0, $a0, -0x2BA8
    ctx->r4 = ADD32(ctx->r4, -0X2BA8);
    // 0x801EF94C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x801EF950: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801EF954: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801EF958: slti        $at, $t1, 0x18
    ctx->r1 = SIGNED(ctx->r9) < 0X18 ? 1 : 0;
    // 0x801EF95C: bne         $at, $zero, L_801EF96C
    if (ctx->r1 != 0) {
        // 0x801EF960: sw          $t1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r9;
            goto L_801EF96C;
    }
    // 0x801EF960: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x801EF964: b           L_801EF9A8
    // 0x801EF968: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801EF9A8;
    // 0x801EF968: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801EF96C:
    // 0x801EF96C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801EF970: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x801EF974: beq         $v0, $at, L_801EF98C
    if (ctx->r2 == ctx->r1) {
        // 0x801EF978: nop
    
            goto L_801EF98C;
    }
    // 0x801EF978: nop

    // 0x801EF97C: beq         $v0, $zero, L_801EF98C
    if (ctx->r2 == 0) {
        // 0x801EF980: nop
    
            goto L_801EF98C;
    }
    // 0x801EF980: nop

    // 0x801EF984: jal         0x8038D28C
    // 0x801EF988: addiu       $a0, $zero, 0x1C9
    ctx->r4 = ADD32(0, 0X1C9);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_3;
    // 0x801EF988: addiu       $a0, $zero, 0x1C9
    ctx->r4 = ADD32(0, 0X1C9);
    after_3:
L_801EF98C:
    // 0x801EF98C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EF990: sw          $zero, -0x2BA4($at)
    MEM_W(-0X2BA4, ctx->r1) = 0;
    // 0x801EF994: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801EF998:
    // 0x801EF998: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x801EF99C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EF9A0: sw          $t3, -0x2BA4($at)
    MEM_W(-0X2BA4, ctx->r1) = ctx->r11;
    // 0x801EF9A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801EF9A8:
    // 0x801EF9A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EF9AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801EF9B0: jr          $ra
    // 0x801EF9B4: nop

    return;
    // 0x801EF9B4: nop

;}
RECOMP_FUNC void M25_FUN_801ef9b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EF9B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EF9BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EF9C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EF9C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EF9C8: lui         $a3, 0x8020
    ctx->r7 = S32(0X8020 << 16);
    // 0x801EF9CC: addiu       $a3, $a3, -0x43C0
    ctx->r7 = ADD32(ctx->r7, -0X43C0);
    // 0x801EF9D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801EF9D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801EF9D8: jal         0x8001B204
    // 0x801EF9DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_0;
    // 0x801EF9DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801EF9E0: lui         $a3, 0x8020
    ctx->r7 = S32(0X8020 << 16);
    // 0x801EF9E4: addiu       $a3, $a3, -0x43BC
    ctx->r7 = ADD32(ctx->r7, -0X43BC);
    // 0x801EF9E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801EF9EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801EF9F0: jal         0x8001B204
    // 0x801EF9F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8001B204)(rdram, ctx);
        goto after_1;
    // 0x801EF9F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801EF9F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EF9FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EFA00: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801EFA04: jr          $ra
    // 0x801EFA08: nop

    return;
    // 0x801EFA08: nop

;}
RECOMP_FUNC void M25_FUN_801efa0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFA0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EFA10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EFA14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EFA18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EFA1C: lui         $a1, 0x205
    ctx->r5 = S32(0X205 << 16);
    // 0x801EFA20: ori         $a1, $a1, 0x45E0
    ctx->r5 = ctx->r5 | 0X45E0;
    // 0x801EFA24: jal         0x801C0B8C
    // 0x801EFA28: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EFA28: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EFA2C: beql        $v0, $zero, L_801EFA50
    if (ctx->r2 == 0) {
        // 0x801EFA30: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_801EFA50;
    }
    goto skip_0;
    // 0x801EFA30: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
    // 0x801EFA34: jal         0x8038D28C
    // 0x801EFA38: addiu       $a0, $zero, 0x628
    ctx->r4 = ADD32(0, 0X628);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801EFA38: addiu       $a0, $zero, 0x628
    ctx->r4 = ADD32(0, 0X628);
    after_1:
    // 0x801EFA3C: jal         0x801D0498
    // 0x801EFA40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D0498)(rdram, ctx);
        goto after_2;
    // 0x801EFA40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x801EFA44: b           L_801EFA50
    // 0x801EFA48: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801EFA50;
    // 0x801EFA48: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801EFA4C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801EFA50:
    // 0x801EFA50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EFA54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EFA58: jr          $ra
    // 0x801EFA5C: nop

    return;
    // 0x801EFA5C: nop

;}
RECOMP_FUNC void M25_FUN_801efa60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFA60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EFA64: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EFA68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EFA6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EFA70: lui         $a1, 0x223
    ctx->r5 = S32(0X223 << 16);
    // 0x801EFA74: ori         $a1, $a1, 0xCA60
    ctx->r5 = ctx->r5 | 0XCA60;
    // 0x801EFA78: jal         0x801C0B8C
    // 0x801EFA7C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EFA7C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EFA80: beql        $v0, $zero, L_801EFA9C
    if (ctx->r2 == 0) {
        // 0x801EFA84: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_801EFA9C;
    }
    goto skip_0;
    // 0x801EFA84: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    skip_0:
    // 0x801EFA88: jal         0x801D0498
    // 0x801EFA8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D0498)(rdram, ctx);
        goto after_1;
    // 0x801EFA8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x801EFA90: b           L_801EFA9C
    // 0x801EFA94: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801EFA9C;
    // 0x801EFA94: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x801EFA98: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801EFA9C:
    // 0x801EFA9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EFAA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EFAA4: jr          $ra
    // 0x801EFAA8: nop

    return;
    // 0x801EFAA8: nop

;}
RECOMP_FUNC void M25_FUN_801efaac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFAAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EFAB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EFAB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EFAB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EFABC: lui         $a1, 0x2F1
    ctx->r5 = S32(0X2F1 << 16);
    // 0x801EFAC0: ori         $a1, $a1, 0xC8C0
    ctx->r5 = ctx->r5 | 0XC8C0;
    // 0x801EFAC4: jal         0x801C0B8C
    // 0x801EFAC8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EFAC8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EFACC: beq         $v0, $zero, L_801EFADC
    if (ctx->r2 == 0) {
        // 0x801EFAD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801EFADC;
    }
    // 0x801EFAD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EFAD4: b           L_801EFAE0
    // 0x801EFAD8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801EFAE0;
    // 0x801EFAD8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801EFADC:
    // 0x801EFADC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801EFAE0:
    // 0x801EFAE0: jr          $ra
    // 0x801EFAE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801EFAE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efae8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efae8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFAE8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EFAEC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EFAF0: jr          $ra
    // 0x801EFAF4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x801EFAF4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efaf8(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efaf8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFAF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EFAFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EFB00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EFB04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EFB08: lui         $a1, 0x3D0
    ctx->r5 = S32(0X3D0 << 16);
    // 0x801EFB0C: ori         $a1, $a1, 0x9000
    ctx->r5 = ctx->r5 | 0X9000;
    // 0x801EFB10: jal         0x801C0B8C
    // 0x801EFB14: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EFB14: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EFB18: beq         $v0, $zero, L_801EFB28
    if (ctx->r2 == 0) {
        // 0x801EFB1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801EFB28;
    }
    // 0x801EFB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EFB20: b           L_801EFB2C
    // 0x801EFB24: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_801EFB2C;
    // 0x801EFB24: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801EFB28:
    // 0x801EFB28: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801EFB2C:
    // 0x801EFB2C: jr          $ra
    // 0x801EFB30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801EFB30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efb34(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efb34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFB34: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EFB38: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EFB3C: jr          $ra
    // 0x801EFB40: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x801EFB40: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efb44(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efb44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFB44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EFB48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EFB4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EFB50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EFB54: lui         $a1, 0x575
    ctx->r5 = S32(0X575 << 16);
    // 0x801EFB58: ori         $a1, $a1, 0xF59A
    ctx->r5 = ctx->r5 | 0XF59A;
    // 0x801EFB5C: jal         0x801C0B8C
    // 0x801EFB60: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EFB60: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EFB64: beq         $v0, $zero, L_801EFB90
    if (ctx->r2 == 0) {
        // 0x801EFB68: lui         $at, 0x8020
        ctx->r1 = S32(0X8020 << 16);
            goto L_801EFB90;
    }
    // 0x801EFB68: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EFB6C: sw          $zero, -0x491C($at)
    MEM_W(-0X491C, ctx->r1) = 0;
    // 0x801EFB70: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EFB74: sw          $zero, -0x4918($at)
    MEM_W(-0X4918, ctx->r1) = 0;
    // 0x801EFB78: jal         0x801D0498
    // 0x801EFB7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D0498)(rdram, ctx);
        goto after_1;
    // 0x801EFB7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801EFB80: jal         0x801D0B04
    // 0x801EFB84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D0B04)(rdram, ctx);
        goto after_2;
    // 0x801EFB84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801EFB88: b           L_801EFB94
    // 0x801EFB8C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801EFB94;
    // 0x801EFB8C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801EFB90:
    // 0x801EFB90: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801EFB94:
    // 0x801EFB94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EFB98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EFB9C: jr          $ra
    // 0x801EFBA0: nop

    return;
    // 0x801EFBA0: nop

;}
RECOMP_FUNC void M25_FUN_801efba4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFBA4: lui         $v0, 0x8020
    ctx->r2 = S32(0X8020 << 16);
    // 0x801EFBA8: lw          $v0, -0x4918($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4918);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efbac(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efbac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFBAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EFBB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EFBB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EFBB8: beq         $v0, $zero, L_801EFBEC
    if (ctx->r2 == 0) {
        // 0x801EFBBC: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801EFBEC;
    }
    // 0x801EFBBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EFBC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801EFBC4: beq         $v0, $at, L_801EFC24
    if (ctx->r2 == ctx->r1) {
        // 0x801EFBC8: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801EFC24;
    }
    // 0x801EFBC8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801EFBCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801EFBD0: beq         $v0, $at, L_801EFC58
    if (ctx->r2 == ctx->r1) {
        // 0x801EFBD4: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801EFC58;
    }
    // 0x801EFBD4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801EFBD8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801EFBDC: beq         $v0, $at, L_801EFC88
    if (ctx->r2 == ctx->r1) {
        // 0x801EFBE0: nop
    
            goto L_801EFC88;
    }
    // 0x801EFBE0: nop

    // 0x801EFBE4: b           L_801EFC88
    // 0x801EFBE8: nop

        goto L_801EFC88;
    // 0x801EFBE8: nop

L_801EFBEC:
    // 0x801EFBEC: lui         $a1, 0x585
    ctx->r5 = S32(0X585 << 16);
    // 0x801EFBF0: ori         $a1, $a1, 0x37DA
    ctx->r5 = ctx->r5 | 0X37DA;
    // 0x801EFBF4: jal         0x801C0B8C
    // 0x801EFBF8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EFBF8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EFBFC: beq         $v0, $zero, L_801EFC88
    if (ctx->r2 == 0) {
        // 0x801EFC00: nop
    
            goto L_801EFC88;
    }
    // 0x801EFC00: nop

    // 0x801EFC04: jal         0x801D0498
    // 0x801EFC08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D0498)(rdram, ctx);
        goto after_1;
    // 0x801EFC08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x801EFC0C: jal         0x801D0B04
    // 0x801EFC10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D0B04)(rdram, ctx);
        goto after_2;
    // 0x801EFC10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x801EFC14: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801EFC18: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EFC1C: b           L_801EFC88
    // 0x801EFC20: sw          $t6, -0x4918($at)
    MEM_W(-0X4918, ctx->r1) = ctx->r14;
        goto L_801EFC88;
    // 0x801EFC20: sw          $t6, -0x4918($at)
    MEM_W(-0X4918, ctx->r1) = ctx->r14;
L_801EFC24:
    // 0x801EFC24: lui         $a1, 0x5BA
    ctx->r5 = S32(0X5BA << 16);
    // 0x801EFC28: jal         0x801C0B8C
    // 0x801EFC2C: ori         $a1, $a1, 0x9FBA
    ctx->r5 = ctx->r5 | 0X9FBA;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_3;
    // 0x801EFC2C: ori         $a1, $a1, 0x9FBA
    ctx->r5 = ctx->r5 | 0X9FBA;
    after_3:
    // 0x801EFC30: beq         $v0, $zero, L_801EFC88
    if (ctx->r2 == 0) {
        // 0x801EFC34: nop
    
            goto L_801EFC88;
    }
    // 0x801EFC34: nop

    // 0x801EFC38: jal         0x801D0498
    // 0x801EFC3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D0498)(rdram, ctx);
        goto after_4;
    // 0x801EFC3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x801EFC40: jal         0x801D0B04
    // 0x801EFC44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D0B04)(rdram, ctx);
        goto after_5;
    // 0x801EFC44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x801EFC48: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801EFC4C: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EFC50: b           L_801EFC88
    // 0x801EFC54: sw          $t7, -0x4918($at)
    MEM_W(-0X4918, ctx->r1) = ctx->r15;
        goto L_801EFC88;
    // 0x801EFC54: sw          $t7, -0x4918($at)
    MEM_W(-0X4918, ctx->r1) = ctx->r15;
L_801EFC58:
    // 0x801EFC58: lui         $a1, 0x5C9
    ctx->r5 = S32(0X5C9 << 16);
    // 0x801EFC5C: jal         0x801C0B8C
    // 0x801EFC60: ori         $a1, $a1, 0xE1FA
    ctx->r5 = ctx->r5 | 0XE1FA;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_6;
    // 0x801EFC60: ori         $a1, $a1, 0xE1FA
    ctx->r5 = ctx->r5 | 0XE1FA;
    after_6:
    // 0x801EFC64: beq         $v0, $zero, L_801EFC88
    if (ctx->r2 == 0) {
        // 0x801EFC68: nop
    
            goto L_801EFC88;
    }
    // 0x801EFC68: nop

    // 0x801EFC6C: jal         0x801D0498
    // 0x801EFC70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D0498)(rdram, ctx);
        goto after_7;
    // 0x801EFC70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x801EFC74: jal         0x801D0B04
    // 0x801EFC78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D0B04)(rdram, ctx);
        goto after_8;
    // 0x801EFC78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x801EFC7C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x801EFC80: lui         $at, 0x8020
    ctx->r1 = S32(0X8020 << 16);
    // 0x801EFC84: sw          $t8, -0x4918($at)
    MEM_W(-0X4918, ctx->r1) = ctx->r24;
L_801EFC88:
    // 0x801EFC88: lui         $a0, 0x8020
    ctx->r4 = S32(0X8020 << 16);
    // 0x801EFC8C: addiu       $a0, $a0, -0x491C
    ctx->r4 = ADD32(ctx->r4, -0X491C);
    // 0x801EFC90: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801EFC94: sltiu       $v0, $v1, 0xCD
    ctx->r2 = ctx->r3 < 0XCD ? 1 : 0;
    // 0x801EFC98: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x801EFC9C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x801EFCA0: beq         $v0, $zero, L_801EFCC0
    if (ctx->r2 == 0) {
        // 0x801EFCA4: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_801EFCC0;
    }
    // 0x801EFCA4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801EFCA8: jal         0x801D0498
    // 0x801EFCAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D0498)(rdram, ctx);
        goto after_9;
    // 0x801EFCAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x801EFCB0: jal         0x801D0B04
    // 0x801EFCB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(0x801D0B04)(rdram, ctx);
        goto after_10;
    // 0x801EFCB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x801EFCB8: b           L_801EFCC4
    // 0x801EFCBC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_801EFCC4;
    // 0x801EFCBC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801EFCC0:
    // 0x801EFCC0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801EFCC4:
    // 0x801EFCC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EFCC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EFCCC: jr          $ra
    // 0x801EFCD0: nop

    return;
    // 0x801EFCD0: nop

;}
RECOMP_FUNC void M25_FUN_801efcd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFCD4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EFCD8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EFCDC: jr          $ra
    // 0x801EFCE0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x801EFCE0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efce4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efce4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFCE4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EFCE8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EFCEC: jr          $ra
    // 0x801EFCF0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x801EFCF0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efcf4(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efcf4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFCF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EFCF8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EFCFC: jr          $ra
    // 0x801EFD00: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    return;
    // 0x801EFD00: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efd04(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efd04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFD04: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EFD08: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EFD0C: jr          $ra
    // 0x801EFD10: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    return;
    // 0x801EFD10: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efd14(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efd14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFD14: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EFD18: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EFD1C: jr          $ra
    // 0x801EFD20: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    return;
    // 0x801EFD20: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efd24(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efd24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFD24: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EFD28: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EFD2C: jr          $ra
    // 0x801EFD30: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x801EFD30: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efd34(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efd34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFD34: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EFD38: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EFD3C: jr          $ra
    // 0x801EFD40: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    return;
    // 0x801EFD40: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efd44(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efd44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFD44: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EFD48: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EFD4C: jr          $ra
    // 0x801EFD50: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x801EFD50: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efd54(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efd54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFD54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EFD58: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EFD5C: jr          $ra
    // 0x801EFD60: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    return;
    // 0x801EFD60: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efd64(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efd64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFD64: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EFD68: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EFD6C: jr          $ra
    // 0x801EFD70: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x801EFD70: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efd74(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efd74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFD74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EFD78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EFD7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EFD80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EFD84: lui         $a1, 0x7
    ctx->r5 = S32(0X7 << 16);
    // 0x801EFD88: ori         $a1, $a1, 0xA120
    ctx->r5 = ctx->r5 | 0XA120;
    // 0x801EFD8C: jal         0x801C0B8C
    // 0x801EFD90: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EFD90: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EFD94: beql        $v0, $zero, L_801EFDB0
    if (ctx->r2 == 0) {
        // 0x801EFD98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801EFDB0;
    }
    goto skip_0;
    // 0x801EFD98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801EFD9C: jal         0x8038D28C
    // 0x801EFDA0: addiu       $a0, $zero, 0x1D3
    ctx->r4 = ADD32(0, 0X1D3);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801EFDA0: addiu       $a0, $zero, 0x1D3
    ctx->r4 = ADD32(0, 0X1D3);
    after_1:
    // 0x801EFDA4: b           L_801EFDB0
    // 0x801EFDA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801EFDB0;
    // 0x801EFDA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801EFDAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801EFDB0:
    // 0x801EFDB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EFDB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EFDB8: jr          $ra
    // 0x801EFDBC: nop

    return;
    // 0x801EFDBC: nop

;}
RECOMP_FUNC void M25_FUN_801efdc0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFDC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EFDC4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EFDC8: jr          $ra
    // 0x801EFDCC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801EFDCC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efdd0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efdd0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFDD0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801EFDD4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801EFDD8: jr          $ra
    // 0x801EFDDC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801EFDDC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801efde0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801efde0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFDE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EFDE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EFDE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EFDEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EFDF0: lui         $a1, 0x53
    ctx->r5 = S32(0X53 << 16);
    // 0x801EFDF4: ori         $a1, $a1, 0xEC60
    ctx->r5 = ctx->r5 | 0XEC60;
    // 0x801EFDF8: jal         0x801C0B8C
    // 0x801EFDFC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EFDFC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EFE00: beql        $v0, $zero, L_801EFE1C
    if (ctx->r2 == 0) {
        // 0x801EFE04: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_801EFE1C;
    }
    goto skip_0;
    // 0x801EFE04: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
    // 0x801EFE08: jal         0x8038D28C
    // 0x801EFE0C: addiu       $a0, $zero, 0x1D5
    ctx->r4 = ADD32(0, 0X1D5);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801EFE0C: addiu       $a0, $zero, 0x1D5
    ctx->r4 = ADD32(0, 0X1D5);
    after_1:
    // 0x801EFE10: b           L_801EFE1C
    // 0x801EFE14: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801EFE1C;
    // 0x801EFE14: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801EFE18: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801EFE1C:
    // 0x801EFE1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EFE20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EFE24: jr          $ra
    // 0x801EFE28: nop

    return;
    // 0x801EFE28: nop

;}
RECOMP_FUNC void M25_FUN_801efe2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFE2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EFE30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EFE34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EFE38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EFE3C: lui         $a1, 0xAF
    ctx->r5 = S32(0XAF << 16);
    // 0x801EFE40: ori         $a1, $a1, 0x79E0
    ctx->r5 = ctx->r5 | 0X79E0;
    // 0x801EFE44: jal         0x801C0B8C
    // 0x801EFE48: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EFE48: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EFE4C: beql        $v0, $zero, L_801EFE68
    if (ctx->r2 == 0) {
        // 0x801EFE50: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_801EFE68;
    }
    goto skip_0;
    // 0x801EFE50: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    skip_0:
    // 0x801EFE54: jal         0x8038D28C
    // 0x801EFE58: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801EFE58: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    after_1:
    // 0x801EFE5C: b           L_801EFE68
    // 0x801EFE60: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801EFE68;
    // 0x801EFE60: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x801EFE64: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801EFE68:
    // 0x801EFE68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EFE6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EFE70: jr          $ra
    // 0x801EFE74: nop

    return;
    // 0x801EFE74: nop

;}
RECOMP_FUNC void M25_FUN_801efe78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFE78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EFE7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EFE80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EFE84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EFE88: lui         $a1, 0x140
    ctx->r5 = S32(0X140 << 16);
    // 0x801EFE8C: ori         $a1, $a1, 0x6F40
    ctx->r5 = ctx->r5 | 0X6F40;
    // 0x801EFE90: jal         0x801C0B8C
    // 0x801EFE94: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EFE94: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EFE98: beql        $v0, $zero, L_801EFEBC
    if (ctx->r2 == 0) {
        // 0x801EFE9C: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_801EFEBC;
    }
    goto skip_0;
    // 0x801EFE9C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    skip_0:
    // 0x801EFEA0: jal         0x8038D28C
    // 0x801EFEA4: addiu       $a0, $zero, 0x693
    ctx->r4 = ADD32(0, 0X693);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801EFEA4: addiu       $a0, $zero, 0x693
    ctx->r4 = ADD32(0, 0X693);
    after_1:
    // 0x801EFEA8: jal         0x8038D28C
    // 0x801EFEAC: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_2;
    // 0x801EFEAC: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_2:
    // 0x801EFEB0: b           L_801EFEBC
    // 0x801EFEB4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801EFEBC;
    // 0x801EFEB4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x801EFEB8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801EFEBC:
    // 0x801EFEBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801EFEC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801EFEC4: jr          $ra
    // 0x801EFEC8: nop

    return;
    // 0x801EFEC8: nop

;}
RECOMP_FUNC void M25_FUN_801efecc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801EFECC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801EFED0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801EFED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801EFED8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801EFEDC: lui         $a1, 0x2A5
    ctx->r5 = S32(0X2A5 << 16);
    // 0x801EFEE0: ori         $a1, $a1, 0x7D80
    ctx->r5 = ctx->r5 | 0X7D80;
    // 0x801EFEE4: jal         0x801C0B8C
    // 0x801EFEE8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801EFEE8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801EFEEC: beq         $v0, $zero, L_801EFEFC
    if (ctx->r2 == 0) {
        // 0x801EFEF0: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801EFEFC;
    }
    // 0x801EFEF0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801EFEF4: b           L_801F007C
    // 0x801EFEF8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_801F007C;
    // 0x801EFEF8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801EFEFC:
    // 0x801EFEFC: lui         $a1, 0x28E
    ctx->r5 = S32(0X28E << 16);
    // 0x801EFF00: jal         0x801C0B8C
    // 0x801EFF04: ori         $a1, $a1, 0x9A20
    ctx->r5 = ctx->r5 | 0X9A20;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_1;
    // 0x801EFF04: ori         $a1, $a1, 0x9A20
    ctx->r5 = ctx->r5 | 0X9A20;
    after_1:
    // 0x801EFF08: beq         $v0, $zero, L_801EFF4C
    if (ctx->r2 == 0) {
        // 0x801EFF0C: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801EFF4C;
    }
    // 0x801EFF0C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801EFF10: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801EFF14: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801EFF18: jal         0x801D1AC0
    // 0x801EFF1C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_2;
    // 0x801EFF1C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
    // 0x801EFF20: bne         $v0, $zero, L_801EFF3C
    if (ctx->r2 != 0) {
        // 0x801EFF24: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801EFF3C;
    }
    // 0x801EFF24: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801EFF28: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801EFF2C: jal         0x801D1AC0
    // 0x801EFF30: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_3;
    // 0x801EFF30: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_3:
    // 0x801EFF34: beq         $v0, $zero, L_801EFF44
    if (ctx->r2 == 0) {
        // 0x801EFF38: nop
    
            goto L_801EFF44;
    }
    // 0x801EFF38: nop

L_801EFF3C:
    // 0x801EFF3C: jal         0x8038D28C
    // 0x801EFF40: addiu       $a0, $zero, 0x6A4
    ctx->r4 = ADD32(0, 0X6A4);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_4;
    // 0x801EFF40: addiu       $a0, $zero, 0x6A4
    ctx->r4 = ADD32(0, 0X6A4);
    after_4:
L_801EFF44:
    // 0x801EFF44: b           L_801F007C
    // 0x801EFF48: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801F007C;
    // 0x801EFF48: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801EFF4C:
    // 0x801EFF4C: lui         $a1, 0x242
    ctx->r5 = S32(0X242 << 16);
    // 0x801EFF50: jal         0x801C0B8C
    // 0x801EFF54: ori         $a1, $a1, 0x4EE0
    ctx->r5 = ctx->r5 | 0X4EE0;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_5;
    // 0x801EFF54: ori         $a1, $a1, 0x4EE0
    ctx->r5 = ctx->r5 | 0X4EE0;
    after_5:
    // 0x801EFF58: beq         $v0, $zero, L_801EFF9C
    if (ctx->r2 == 0) {
        // 0x801EFF5C: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801EFF9C;
    }
    // 0x801EFF5C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801EFF60: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801EFF64: ori         $a0, $a0, 0x1C
    ctx->r4 = ctx->r4 | 0X1C;
    // 0x801EFF68: jal         0x801D1AC0
    // 0x801EFF6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_6;
    // 0x801EFF6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x801EFF70: bne         $v0, $zero, L_801EFF8C
    if (ctx->r2 != 0) {
        // 0x801EFF74: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801EFF8C;
    }
    // 0x801EFF74: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801EFF78: ori         $a0, $a0, 0x1C
    ctx->r4 = ctx->r4 | 0X1C;
    // 0x801EFF7C: jal         0x801D1AC0
    // 0x801EFF80: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_7;
    // 0x801EFF80: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_7:
    // 0x801EFF84: beq         $v0, $zero, L_801EFF94
    if (ctx->r2 == 0) {
        // 0x801EFF88: nop
    
            goto L_801EFF94;
    }
    // 0x801EFF88: nop

L_801EFF8C:
    // 0x801EFF8C: jal         0x8038D28C
    // 0x801EFF90: addiu       $a0, $zero, 0x6A2
    ctx->r4 = ADD32(0, 0X6A2);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_8;
    // 0x801EFF90: addiu       $a0, $zero, 0x6A2
    ctx->r4 = ADD32(0, 0X6A2);
    after_8:
L_801EFF94:
    // 0x801EFF94: b           L_801F007C
    // 0x801EFF98: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801F007C;
    // 0x801EFF98: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801EFF9C:
    // 0x801EFF9C: lui         $a1, 0x1C8
    ctx->r5 = S32(0X1C8 << 16);
    // 0x801EFFA0: jal         0x801C0B8C
    // 0x801EFFA4: ori         $a1, $a1, 0x3CE0
    ctx->r5 = ctx->r5 | 0X3CE0;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_9;
    // 0x801EFFA4: ori         $a1, $a1, 0x3CE0
    ctx->r5 = ctx->r5 | 0X3CE0;
    after_9:
    // 0x801EFFA8: beq         $v0, $zero, L_801EFFEC
    if (ctx->r2 == 0) {
        // 0x801EFFAC: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_801EFFEC;
    }
    // 0x801EFFAC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801EFFB0: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801EFFB4: ori         $a0, $a0, 0x1C
    ctx->r4 = ctx->r4 | 0X1C;
    // 0x801EFFB8: jal         0x801D1AC0
    // 0x801EFFBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_10;
    // 0x801EFFBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x801EFFC0: bne         $v0, $zero, L_801EFFDC
    if (ctx->r2 != 0) {
        // 0x801EFFC4: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801EFFDC;
    }
    // 0x801EFFC4: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801EFFC8: ori         $a0, $a0, 0x1C
    ctx->r4 = ctx->r4 | 0X1C;
    // 0x801EFFCC: jal         0x801D1AC0
    // 0x801EFFD0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_11;
    // 0x801EFFD0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_11:
    // 0x801EFFD4: beq         $v0, $zero, L_801EFFE4
    if (ctx->r2 == 0) {
        // 0x801EFFD8: nop
    
            goto L_801EFFE4;
    }
    // 0x801EFFD8: nop

L_801EFFDC:
    // 0x801EFFDC: jal         0x8038D28C
    // 0x801EFFE0: addiu       $a0, $zero, 0x6A3
    ctx->r4 = ADD32(0, 0X6A3);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_12;
    // 0x801EFFE0: addiu       $a0, $zero, 0x6A3
    ctx->r4 = ADD32(0, 0X6A3);
    after_12:
L_801EFFE4:
    // 0x801EFFE4: b           L_801F007C
    // 0x801EFFE8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_801F007C;
    // 0x801EFFE8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801EFFEC:
    // 0x801EFFEC: lui         $a1, 0x1A9
    ctx->r5 = S32(0X1A9 << 16);
    // 0x801EFFF0: jal         0x801C0B8C
    // 0x801EFFF4: ori         $a1, $a1, 0xB860
    ctx->r5 = ctx->r5 | 0XB860;
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_13;
    // 0x801EFFF4: ori         $a1, $a1, 0xB860
    ctx->r5 = ctx->r5 | 0XB860;
    after_13:
    // 0x801EFFF8: beq         $v0, $zero, L_801F0030
    if (ctx->r2 == 0) {
        // 0x801EFFFC: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801F0030;
    }
    // 0x801EFFFC: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801F0000: ori         $a0, $a0, 0x1C
    ctx->r4 = ctx->r4 | 0X1C;
    // 0x801F0004: jal         0x801D1AC0
    // 0x801F0008: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_14;
    // 0x801F0008: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x801F000C: bne         $v0, $zero, L_801F0028
    if (ctx->r2 != 0) {
        // 0x801F0010: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801F0028;
    }
    // 0x801F0010: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801F0014: ori         $a0, $a0, 0x1C
    ctx->r4 = ctx->r4 | 0X1C;
    // 0x801F0018: jal         0x801D1AC0
    // 0x801F001C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_15;
    // 0x801F001C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_15:
    // 0x801F0020: beql        $v0, $zero, L_801F0034
    if (ctx->r2 == 0) {
        // 0x801F0024: lui         $a1, 0x169
        ctx->r5 = S32(0X169 << 16);
            goto L_801F0034;
    }
    goto skip_0;
    // 0x801F0024: lui         $a1, 0x169
    ctx->r5 = S32(0X169 << 16);
    skip_0:
L_801F0028:
    // 0x801F0028: jal         0x8038D28C
    // 0x801F002C: addiu       $a0, $zero, 0x6A2
    ctx->r4 = ADD32(0, 0X6A2);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_16;
    // 0x801F002C: addiu       $a0, $zero, 0x6A2
    ctx->r4 = ADD32(0, 0X6A2);
    after_16:
L_801F0030:
    // 0x801F0030: lui         $a1, 0x169
    ctx->r5 = S32(0X169 << 16);
L_801F0034:
    // 0x801F0034: ori         $a1, $a1, 0xA220
    ctx->r5 = ctx->r5 | 0XA220;
    // 0x801F0038: jal         0x801C0B8C
    // 0x801F003C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_17;
    // 0x801F003C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_17:
    // 0x801F0040: beq         $v0, $zero, L_801F0078
    if (ctx->r2 == 0) {
        // 0x801F0044: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801F0078;
    }
    // 0x801F0044: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801F0048: ori         $a0, $a0, 0x1C
    ctx->r4 = ctx->r4 | 0X1C;
    // 0x801F004C: jal         0x801D1AC0
    // 0x801F0050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_18;
    // 0x801F0050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x801F0054: bne         $v0, $zero, L_801F0070
    if (ctx->r2 != 0) {
        // 0x801F0058: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801F0070;
    }
    // 0x801F0058: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801F005C: ori         $a0, $a0, 0x1C
    ctx->r4 = ctx->r4 | 0X1C;
    // 0x801F0060: jal         0x801D1AC0
    // 0x801F0064: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_19;
    // 0x801F0064: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_19:
    // 0x801F0068: beql        $v0, $zero, L_801F007C
    if (ctx->r2 == 0) {
        // 0x801F006C: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_801F007C;
    }
    goto skip_1;
    // 0x801F006C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    skip_1:
L_801F0070:
    // 0x801F0070: jal         0x8038D28C
    // 0x801F0074: addiu       $a0, $zero, 0x6A3
    ctx->r4 = ADD32(0, 0X6A3);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_20;
    // 0x801F0074: addiu       $a0, $zero, 0x6A3
    ctx->r4 = ADD32(0, 0X6A3);
    after_20:
L_801F0078:
    // 0x801F0078: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_801F007C:
    // 0x801F007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F0080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F0084: jr          $ra
    // 0x801F0088: nop

    return;
    // 0x801F0088: nop

;}
RECOMP_FUNC void M25_FUN_801f008c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F008C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F0090: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F0094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F0098: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F009C: lui         $a1, 0x2C4
    ctx->r5 = S32(0X2C4 << 16);
    // 0x801F00A0: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x801F00A4: jal         0x801C0B8C
    // 0x801F00A8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F00A8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F00AC: beq         $v0, $zero, L_801F00C4
    if (ctx->r2 == 0) {
        // 0x801F00B0: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801F00C4;
    }
    // 0x801F00B0: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801F00B4: jal         0x8038D28C
    // 0x801F00B8: addiu       $a0, $zero, 0x69A
    ctx->r4 = ADD32(0, 0X69A);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F00B8: addiu       $a0, $zero, 0x69A
    ctx->r4 = ADD32(0, 0X69A);
    after_1:
    // 0x801F00BC: b           L_801F00F8
    // 0x801F00C0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_801F00F8;
    // 0x801F00C0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801F00C4:
    // 0x801F00C4: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801F00C8: jal         0x801D1AC0
    // 0x801F00CC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_2;
    // 0x801F00CC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
    // 0x801F00D0: bne         $v0, $zero, L_801F00EC
    if (ctx->r2 != 0) {
        // 0x801F00D4: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801F00EC;
    }
    // 0x801F00D4: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801F00D8: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801F00DC: jal         0x801D1AC0
    // 0x801F00E0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_3;
    // 0x801F00E0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_3:
    // 0x801F00E4: beql        $v0, $zero, L_801F00F8
    if (ctx->r2 == 0) {
        // 0x801F00E8: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_801F00F8;
    }
    goto skip_0;
    // 0x801F00E8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    skip_0:
L_801F00EC:
    // 0x801F00EC: jal         0x8038D28C
    // 0x801F00F0: addiu       $a0, $zero, 0x6A3
    ctx->r4 = ADD32(0, 0X6A3);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_4;
    // 0x801F00F0: addiu       $a0, $zero, 0x6A3
    ctx->r4 = ADD32(0, 0X6A3);
    after_4:
    // 0x801F00F4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_801F00F8:
    // 0x801F00F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F00FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F0100: jr          $ra
    // 0x801F0104: nop

    return;
    // 0x801F0104: nop

;}
RECOMP_FUNC void M25_FUN_801f0108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F010C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F0110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F0114: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F0118: lui         $a1, 0x2D3
    ctx->r5 = S32(0X2D3 << 16);
    // 0x801F011C: ori         $a1, $a1, 0x4440
    ctx->r5 = ctx->r5 | 0X4440;
    // 0x801F0120: jal         0x801C0B8C
    // 0x801F0124: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F0124: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F0128: beql        $v0, $zero, L_801F0144
    if (ctx->r2 == 0) {
        // 0x801F012C: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_801F0144;
    }
    goto skip_0;
    // 0x801F012C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    skip_0:
    // 0x801F0130: jal         0x8038D28C
    // 0x801F0134: addiu       $a0, $zero, 0x69B
    ctx->r4 = ADD32(0, 0X69B);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F0134: addiu       $a0, $zero, 0x69B
    ctx->r4 = ADD32(0, 0X69B);
    after_1:
    // 0x801F0138: b           L_801F0144
    // 0x801F013C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_801F0144;
    // 0x801F013C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x801F0140: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_801F0144:
    // 0x801F0144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F0148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F014C: jr          $ra
    // 0x801F0150: nop

    return;
    // 0x801F0150: nop

;}
RECOMP_FUNC void M25_FUN_801f0154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0154: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F0158: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F015C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F0160: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F0164: lui         $a1, 0x2F1
    ctx->r5 = S32(0X2F1 << 16);
    // 0x801F0168: ori         $a1, $a1, 0xC8C0
    ctx->r5 = ctx->r5 | 0XC8C0;
    // 0x801F016C: jal         0x801C0B8C
    // 0x801F0170: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F0170: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F0174: beq         $v0, $zero, L_801F019C
    if (ctx->r2 == 0) {
        // 0x801F0178: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801F019C;
    }
    // 0x801F0178: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801F017C: jal         0x8038D2B0
    // 0x801F0180: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_1;
    // 0x801F0180: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x801F0184: jal         0x8038D2B0
    // 0x801F0188: addiu       $a0, $zero, 0x62A
    ctx->r4 = ADD32(0, 0X62A);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_2;
    // 0x801F0188: addiu       $a0, $zero, 0x62A
    ctx->r4 = ADD32(0, 0X62A);
    after_2:
    // 0x801F018C: jal         0x8038D2B0
    // 0x801F0190: addiu       $a0, $zero, 0x62B
    ctx->r4 = ADD32(0, 0X62B);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_3;
    // 0x801F0190: addiu       $a0, $zero, 0x62B
    ctx->r4 = ADD32(0, 0X62B);
    after_3:
    // 0x801F0194: b           L_801F01D0
    // 0x801F0198: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_801F01D0;
    // 0x801F0198: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F019C:
    // 0x801F019C: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801F01A0: jal         0x801D1AC0
    // 0x801F01A4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_4;
    // 0x801F01A4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_4:
    // 0x801F01A8: bne         $v0, $zero, L_801F01C4
    if (ctx->r2 != 0) {
        // 0x801F01AC: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801F01C4;
    }
    // 0x801F01AC: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801F01B0: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801F01B4: jal         0x801D1AC0
    // 0x801F01B8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_5;
    // 0x801F01B8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_5:
    // 0x801F01BC: beql        $v0, $zero, L_801F01D0
    if (ctx->r2 == 0) {
        // 0x801F01C0: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_801F01D0;
    }
    goto skip_0;
    // 0x801F01C0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    skip_0:
L_801F01C4:
    // 0x801F01C4: jal         0x8038D28C
    // 0x801F01C8: addiu       $a0, $zero, 0x6A2
    ctx->r4 = ADD32(0, 0X6A2);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_6;
    // 0x801F01C8: addiu       $a0, $zero, 0x6A2
    ctx->r4 = ADD32(0, 0X6A2);
    after_6:
    // 0x801F01CC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_801F01D0:
    // 0x801F01D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F01D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F01D8: jr          $ra
    // 0x801F01DC: nop

    return;
    // 0x801F01DC: nop

;}
RECOMP_FUNC void M25_FUN_801f01e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F01E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F01E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F01E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F01EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F01F0: lui         $a1, 0x393
    ctx->r5 = S32(0X393 << 16);
    // 0x801F01F4: ori         $a1, $a1, 0x8700
    ctx->r5 = ctx->r5 | 0X8700;
    // 0x801F01F8: jal         0x801C0B8C
    // 0x801F01FC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F01FC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F0200: beq         $v0, $zero, L_801F0210
    if (ctx->r2 == 0) {
        // 0x801F0204: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801F0210;
    }
    // 0x801F0204: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801F0208: b           L_801F0278
    // 0x801F020C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_801F0278;
    // 0x801F020C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801F0210:
    // 0x801F0210: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801F0214: jal         0x801D1AC0
    // 0x801F0218: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_1;
    // 0x801F0218: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_1:
    // 0x801F021C: bne         $v0, $zero, L_801F0238
    if (ctx->r2 != 0) {
        // 0x801F0220: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801F0238;
    }
    // 0x801F0220: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801F0224: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801F0228: jal         0x801D1AC0
    // 0x801F022C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_2;
    // 0x801F022C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_2:
    // 0x801F0230: beql        $v0, $zero, L_801F0244
    if (ctx->r2 == 0) {
        // 0x801F0234: lui         $a0, 0x1B8
        ctx->r4 = S32(0X1B8 << 16);
            goto L_801F0244;
    }
    goto skip_0;
    // 0x801F0234: lui         $a0, 0x1B8
    ctx->r4 = S32(0X1B8 << 16);
    skip_0:
L_801F0238:
    // 0x801F0238: jal         0x8038D28C
    // 0x801F023C: addiu       $a0, $zero, 0x6A2
    ctx->r4 = ADD32(0, 0X6A2);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_3;
    // 0x801F023C: addiu       $a0, $zero, 0x6A2
    ctx->r4 = ADD32(0, 0X6A2);
    after_3:
    // 0x801F0240: lui         $a0, 0x1B8
    ctx->r4 = S32(0X1B8 << 16);
L_801F0244:
    // 0x801F0244: ori         $a0, $a0, 0xE
    ctx->r4 = ctx->r4 | 0XE;
    // 0x801F0248: jal         0x801D1220
    // 0x801F024C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    LOOKUP_FUNC(0x801D1220)(rdram, ctx);
        goto after_4;
    // 0x801F024C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_4:
    // 0x801F0250: bne         $v0, $zero, L_801F026C
    if (ctx->r2 != 0) {
        // 0x801F0254: lui         $a0, 0x1B8
        ctx->r4 = S32(0X1B8 << 16);
            goto L_801F026C;
    }
    // 0x801F0254: lui         $a0, 0x1B8
    ctx->r4 = S32(0X1B8 << 16);
    // 0x801F0258: ori         $a0, $a0, 0xE
    ctx->r4 = ctx->r4 | 0XE;
    // 0x801F025C: jal         0x801D1220
    // 0x801F0260: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    LOOKUP_FUNC(0x801D1220)(rdram, ctx);
        goto after_5;
    // 0x801F0260: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_5:
    // 0x801F0264: beql        $v0, $zero, L_801F0278
    if (ctx->r2 == 0) {
        // 0x801F0268: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_801F0278;
    }
    goto skip_1;
    // 0x801F0268: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_1:
L_801F026C:
    // 0x801F026C: jal         0x8038D28C
    // 0x801F0270: addiu       $a0, $zero, 0x6A0
    ctx->r4 = ADD32(0, 0X6A0);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_6;
    // 0x801F0270: addiu       $a0, $zero, 0x6A0
    ctx->r4 = ADD32(0, 0X6A0);
    after_6:
    // 0x801F0274: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_801F0278:
    // 0x801F0278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F027C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F0280: jr          $ra
    // 0x801F0284: nop

    return;
    // 0x801F0284: nop

;}
RECOMP_FUNC void M25_FUN_801f0288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F028C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F0290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F0294: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F0298: lui         $a1, 0x3D0
    ctx->r5 = S32(0X3D0 << 16);
    // 0x801F029C: ori         $a1, $a1, 0x9000
    ctx->r5 = ctx->r5 | 0X9000;
    // 0x801F02A0: jal         0x801C0B8C
    // 0x801F02A4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F02A4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F02A8: beq         $v0, $zero, L_801F02C8
    if (ctx->r2 == 0) {
        // 0x801F02AC: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801F02C8;
    }
    // 0x801F02AC: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801F02B0: jal         0x8038D2B0
    // 0x801F02B4: addiu       $a0, $zero, 0x62C
    ctx->r4 = ADD32(0, 0X62C);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_1;
    // 0x801F02B4: addiu       $a0, $zero, 0x62C
    ctx->r4 = ADD32(0, 0X62C);
    after_1:
    // 0x801F02B8: jal         0x8038D2B0
    // 0x801F02BC: addiu       $a0, $zero, 0x62D
    ctx->r4 = ADD32(0, 0X62D);
    LOOKUP_FUNC(0x8038D2B0)(rdram, ctx);
        goto after_2;
    // 0x801F02BC: addiu       $a0, $zero, 0x62D
    ctx->r4 = ADD32(0, 0X62D);
    after_2:
    // 0x801F02C0: b           L_801F0330
    // 0x801F02C4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_801F0330;
    // 0x801F02C4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_801F02C8:
    // 0x801F02C8: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801F02CC: jal         0x801D1AC0
    // 0x801F02D0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_3;
    // 0x801F02D0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x801F02D4: bne         $v0, $zero, L_801F02F0
    if (ctx->r2 != 0) {
        // 0x801F02D8: lui         $a0, 0x168
        ctx->r4 = S32(0X168 << 16);
            goto L_801F02F0;
    }
    // 0x801F02D8: lui         $a0, 0x168
    ctx->r4 = S32(0X168 << 16);
    // 0x801F02DC: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801F02E0: jal         0x801D1AC0
    // 0x801F02E4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    LOOKUP_FUNC(0x801D1AC0)(rdram, ctx);
        goto after_4;
    // 0x801F02E4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_4:
    // 0x801F02E8: beql        $v0, $zero, L_801F02FC
    if (ctx->r2 == 0) {
        // 0x801F02EC: lui         $a0, 0x1B8
        ctx->r4 = S32(0X1B8 << 16);
            goto L_801F02FC;
    }
    goto skip_0;
    // 0x801F02EC: lui         $a0, 0x1B8
    ctx->r4 = S32(0X1B8 << 16);
    skip_0:
L_801F02F0:
    // 0x801F02F0: jal         0x8038D28C
    // 0x801F02F4: addiu       $a0, $zero, 0x6A3
    ctx->r4 = ADD32(0, 0X6A3);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_5;
    // 0x801F02F4: addiu       $a0, $zero, 0x6A3
    ctx->r4 = ADD32(0, 0X6A3);
    after_5:
    // 0x801F02F8: lui         $a0, 0x1B8
    ctx->r4 = S32(0X1B8 << 16);
L_801F02FC:
    // 0x801F02FC: ori         $a0, $a0, 0xE
    ctx->r4 = ctx->r4 | 0XE;
    // 0x801F0300: jal         0x801D1220
    // 0x801F0304: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    LOOKUP_FUNC(0x801D1220)(rdram, ctx);
        goto after_6;
    // 0x801F0304: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_6:
    // 0x801F0308: bne         $v0, $zero, L_801F0324
    if (ctx->r2 != 0) {
        // 0x801F030C: lui         $a0, 0x1B8
        ctx->r4 = S32(0X1B8 << 16);
            goto L_801F0324;
    }
    // 0x801F030C: lui         $a0, 0x1B8
    ctx->r4 = S32(0X1B8 << 16);
    // 0x801F0310: ori         $a0, $a0, 0xE
    ctx->r4 = ctx->r4 | 0XE;
    // 0x801F0314: jal         0x801D1220
    // 0x801F0318: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    LOOKUP_FUNC(0x801D1220)(rdram, ctx);
        goto after_7;
    // 0x801F0318: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_7:
    // 0x801F031C: beql        $v0, $zero, L_801F0330
    if (ctx->r2 == 0) {
        // 0x801F0320: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_801F0330;
    }
    goto skip_1;
    // 0x801F0320: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    skip_1:
L_801F0324:
    // 0x801F0324: jal         0x8038D28C
    // 0x801F0328: addiu       $a0, $zero, 0x6A1
    ctx->r4 = ADD32(0, 0X6A1);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_8;
    // 0x801F0328: addiu       $a0, $zero, 0x6A1
    ctx->r4 = ADD32(0, 0X6A1);
    after_8:
    // 0x801F032C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_801F0330:
    // 0x801F0330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F0334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F0338: jr          $ra
    // 0x801F033C: nop

    return;
    // 0x801F033C: nop

;}
RECOMP_FUNC void M25_FUN_801f0340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0340: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F0344: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F0348: jr          $ra
    // 0x801F034C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    return;
    // 0x801F034C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f0350(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f0350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0350: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F0354: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F0358: jr          $ra
    // 0x801F035C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    return;
    // 0x801F035C: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f0360(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f0360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0360: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F0364: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F0368: jr          $ra
    // 0x801F036C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    return;
    // 0x801F036C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f0370(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f0370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F0374: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F0378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F037C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F0380: lui         $a1, 0x44A
    ctx->r5 = S32(0X44A << 16);
    // 0x801F0384: ori         $a1, $a1, 0xA200
    ctx->r5 = ctx->r5 | 0XA200;
    // 0x801F0388: jal         0x801C0B8C
    // 0x801F038C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F038C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F0390: beql        $v0, $zero, L_801F03AC
    if (ctx->r2 == 0) {
        // 0x801F0394: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_801F03AC;
    }
    goto skip_0;
    // 0x801F0394: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    skip_0:
    // 0x801F0398: jal         0x8038D28C
    // 0x801F039C: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F039C: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    after_1:
    // 0x801F03A0: b           L_801F03AC
    // 0x801F03A4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_801F03AC;
    // 0x801F03A4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x801F03A8: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_801F03AC:
    // 0x801F03AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F03B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F03B4: jr          $ra
    // 0x801F03B8: nop

    return;
    // 0x801F03B8: nop

;}
RECOMP_FUNC void M25_FUN_801f03bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F03BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F03C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F03C4: jr          $ra
    // 0x801F03C8: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    return;
    // 0x801F03C8: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f03cc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f03cc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F03CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F03D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F03D4: jr          $ra
    // 0x801F03D8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x801F03D8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f03dc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f03dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F03DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F03E0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F03E4: jr          $ra
    // 0x801F03E8: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    return;
    // 0x801F03E8: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f03ec(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f03ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F03EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F03F0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F03F4: jr          $ra
    // 0x801F03F8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x801F03F8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f03fc(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f03fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F03FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F0400: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F0404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F0408: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F040C: lui         $a1, 0x503
    ctx->r5 = S32(0X503 << 16);
    // 0x801F0410: ori         $a1, $a1, 0x84BA
    ctx->r5 = ctx->r5 | 0X84BA;
    // 0x801F0414: jal         0x801C0B8C
    // 0x801F0418: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F0418: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F041C: beq         $v0, $zero, L_801F042C
    if (ctx->r2 == 0) {
        // 0x801F0420: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801F042C;
    }
    // 0x801F0420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F0424: b           L_801F0430
    // 0x801F0428: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_801F0430;
    // 0x801F0428: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_801F042C:
    // 0x801F042C: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_801F0430:
    // 0x801F0430: jr          $ra
    // 0x801F0434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801F0434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f0438(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f0438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F043C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F0440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F0444: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F0448: lui         $a1, 0x549
    ctx->r5 = S32(0X549 << 16);
    // 0x801F044C: ori         $a1, $a1, 0xB57A
    ctx->r5 = ctx->r5 | 0XB57A;
    // 0x801F0450: jal         0x801C0B8C
    // 0x801F0454: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F0454: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F0458: beql        $v0, $zero, L_801F0474
    if (ctx->r2 == 0) {
        // 0x801F045C: addiu       $v0, $zero, 0x15
        ctx->r2 = ADD32(0, 0X15);
            goto L_801F0474;
    }
    goto skip_0;
    // 0x801F045C: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    skip_0:
    // 0x801F0460: jal         0x8038D28C
    // 0x801F0464: addiu       $a0, $zero, 0x1D7
    ctx->r4 = ADD32(0, 0X1D7);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F0464: addiu       $a0, $zero, 0x1D7
    ctx->r4 = ADD32(0, 0X1D7);
    after_1:
    // 0x801F0468: b           L_801F0474
    // 0x801F046C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
        goto L_801F0474;
    // 0x801F046C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x801F0470: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_801F0474:
    // 0x801F0474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F0478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F047C: jr          $ra
    // 0x801F0480: nop

    return;
    // 0x801F0480: nop

;}
RECOMP_FUNC void M25_FUN_801f0484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F0484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F0488: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F048C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F0490: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F0494: lui         $a1, 0x54C
    ctx->r5 = S32(0X54C << 16);
    // 0x801F0498: ori         $a1, $a1, 0xC2BA
    ctx->r5 = ctx->r5 | 0XC2BA;
    // 0x801F049C: jal         0x801C0B8C
    // 0x801F04A0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F04A0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F04A4: beql        $v0, $zero, L_801F04C0
    if (ctx->r2 == 0) {
        // 0x801F04A8: addiu       $v0, $zero, 0x16
        ctx->r2 = ADD32(0, 0X16);
            goto L_801F04C0;
    }
    goto skip_0;
    // 0x801F04A8: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    skip_0:
    // 0x801F04AC: jal         0x8038D28C
    // 0x801F04B0: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F04B0: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_1:
    // 0x801F04B4: b           L_801F04C0
    // 0x801F04B8: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_801F04C0;
    // 0x801F04B8: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
    // 0x801F04BC: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_801F04C0:
    // 0x801F04C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F04C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F04C8: jr          $ra
    // 0x801F04CC: nop

    return;
    // 0x801F04CC: nop

;}
RECOMP_FUNC void M25_FUN_801f04d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F04D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F04D4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F04D8: jr          $ra
    // 0x801F04DC: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    return;
    // 0x801F04DC: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f04e0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f04e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F04E0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801F04E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801F04E8: jr          $ra
    // 0x801F04EC: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    return;
    // 0x801F04EC: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M25_FUN_801f04f0(rdram, ctx);
;}
RECOMP_FUNC void M25_FUN_801f04f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801F04F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801F04F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801F04F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801F04FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801F0500: lui         $a1, 0x5B7
    ctx->r5 = S32(0X5B7 << 16);
    // 0x801F0504: ori         $a1, $a1, 0x927A
    ctx->r5 = ctx->r5 | 0X927A;
    // 0x801F0508: jal         0x801C0B8C
    // 0x801F050C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    LOOKUP_FUNC(0x801C0B8C)(rdram, ctx);
        goto after_0;
    // 0x801F050C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_0:
    // 0x801F0510: beql        $v0, $zero, L_801F052C
    if (ctx->r2 == 0) {
        // 0x801F0514: addiu       $v0, $zero, 0x19
        ctx->r2 = ADD32(0, 0X19);
            goto L_801F052C;
    }
    goto skip_0;
    // 0x801F0514: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    skip_0:
    // 0x801F0518: jal         0x8038D28C
    // 0x801F051C: addiu       $a0, $zero, 0x5C6
    ctx->r4 = ADD32(0, 0X5C6);
    LOOKUP_FUNC(0x8038D28C)(rdram, ctx);
        goto after_1;
    // 0x801F051C: addiu       $a0, $zero, 0x5C6
    ctx->r4 = ADD32(0, 0X5C6);
    after_1:
    // 0x801F0520: b           L_801F052C
    // 0x801F0524: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
        goto L_801F052C;
    // 0x801F0524: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    // 0x801F0528: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_801F052C:
    // 0x801F052C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801F0530: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801F0534: jr          $ra
    // 0x801F0538: nop

    return;
    // 0x801F0538: nop

;}
