#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801c37f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C37F0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C37F4: jr          $ra
    // 0x801C37F8: sw          $zero, -0x5D50($at)
    MEM_W(-0X5D50, ctx->r1) = 0;
    return;
    // 0x801C37F8: sw          $zero, -0x5D50($at)
    MEM_W(-0X5D50, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c37fc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c37fc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C37FC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C3800: jr          $ra
    // 0x801C3804: lw          $v0, -0x5D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5D4C);
    return;
    // 0x801C3804: lw          $v0, -0x5D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5D4C);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c3808(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c3808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3808: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C380C: lw          $t6, -0x5D50($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5D50);
    // 0x801C3810: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801C3814: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801C3818: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C381C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801C3820: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x801C3824: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801C3828: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801C382C: bne         $t6, $zero, L_801C383C
    if (ctx->r14 != 0) {
            // 0x801C3830: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    LOOKUP_FUNC(0x801C383C)(rdram, ctx);
    return;
    }
    // 0x801C3830: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801C3834: jr          $ra
    // 0x801C3838: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801C3838: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c383c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c383c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C383C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C3840: sb          $a0, -0x870($at)
    MEM_B(-0X870, ctx->r1) = ctx->r4;
    // 0x801C3844: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C3848: sb          $a1, -0x86F($at)
    MEM_B(-0X86F, ctx->r1) = ctx->r5;
    // 0x801C384C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C3850: sb          $a2, -0x86E($at)
    MEM_B(-0X86E, ctx->r1) = ctx->r6;
    // 0x801C3854: lbu         $t7, 0x13($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X13);
    // 0x801C3858: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C385C: sb          $a3, -0x86D($at)
    MEM_B(-0X86D, ctx->r1) = ctx->r7;
    // 0x801C3860: lbu         $t8, 0x17($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X17);
    // 0x801C3864: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C3868: sb          $t7, -0x86C($at)
    MEM_B(-0X86C, ctx->r1) = ctx->r15;
    // 0x801C386C: lbu         $t9, 0x1B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1B);
    // 0x801C3870: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C3874: sb          $t8, -0x86B($at)
    MEM_B(-0X86B, ctx->r1) = ctx->r24;
    // 0x801C3878: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x801C387C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C3880: sb          $t9, -0x86A($at)
    MEM_B(-0X86A, ctx->r1) = ctx->r25;
    // 0x801C3884: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C3888: sb          $t0, -0x869($at)
    MEM_B(-0X869, ctx->r1) = ctx->r8;
    // 0x801C388C: lhu         $t1, 0x22($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X22);
    // 0x801C3890: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C3894: sh          $zero, -0x868($at)
    MEM_H(-0X868, ctx->r1) = 0;
    // 0x801C3898: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C389C: sh          $t1, -0x866($at)
    MEM_H(-0X866, ctx->r1) = ctx->r9;
    // 0x801C38A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C38A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C38A8: sw          $v0, -0x5D4C($at)
    MEM_W(-0X5D4C, ctx->r1) = ctx->r2;
    // 0x801C38AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C38B0: sw          $v0, -0x5D48($at)
    MEM_W(-0X5D48, ctx->r1) = ctx->r2;
    // 0x801C38B4: jr          $ra
    // 0x801C38B8: nop

    return;
    // 0x801C38B8: nop

;}
RECOMP_FUNC void M24_FUN_801c38bc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C38BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C38C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C38C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C38C8: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C38CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C38D0: jal         0x80005E44
    // 0x801C38D4: addiu       $a1, $a1, -0x5D30
    ctx->r5 = ADD32(ctx->r5, -0X5D30);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C38D4: addiu       $a1, $a1, -0x5D30
    ctx->r5 = ADD32(ctx->r5, -0X5D30);
    after_0:
    // 0x801C38D8: jal         0x80006214
    // 0x801C38DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C38DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801C38E0: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C38E4: addiu       $t0, $t0, -0x1070
    ctx->r8 = ADD32(ctx->r8, -0X1070);
    // 0x801C38E8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C38EC: addiu       $a3, $a3, -0x5D54
    ctx->r7 = ADD32(ctx->r7, -0X5D54);
    // 0x801C38F0: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x801C38F4: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x801C38F8: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x801C38FC: lui         $t7, 0xDF00
    ctx->r15 = S32(0XDF00 << 16);
    // 0x801C3900: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x801C3904: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x801C3908: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x801C390C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C3910: or          $t8, $t0, $at
    ctx->r24 = ctx->r8 | ctx->r1;
    // 0x801C3914: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801C3918: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C391C: addiu       $a1, $a1, 0x3940
    ctx->r5 = ADD32(ctx->r5, 0X3940);
    // 0x801C3920: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C3924: sw          $t8, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r24;
    // 0x801C3928: jal         0x800058DC
    // 0x801C392C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C392C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801C3930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C3934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C3938: jr          $ra
    // 0x801C393C: nop

    return;
    // 0x801C393C: nop

;}
RECOMP_FUNC void M24_FUN_801c3940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3940: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C3944: lbu         $t6, -0x870($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X870);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c3948(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c3948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C394C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C3950: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C3954: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C3958: sb          $t6, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r14;
    // 0x801C395C: lbu         $t7, -0x86F($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X86F);
    // 0x801C3960: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C3964: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801C3968: sb          $t7, 0x91($a0)
    MEM_B(0X91, ctx->r4) = ctx->r15;
    // 0x801C396C: lbu         $t8, -0x86E($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X86E);
    // 0x801C3970: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C3974: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801C3978: sb          $t8, 0x92($a0)
    MEM_B(0X92, ctx->r4) = ctx->r24;
    // 0x801C397C: lbu         $t9, -0x86D($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X86D);
    // 0x801C3980: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x801C3984: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801C3988: sb          $t9, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r25;
    // 0x801C398C: lbu         $t0, -0x86C($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X86C);
    // 0x801C3990: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801C3994: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801C3998: sb          $t0, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r8;
    // 0x801C399C: lbu         $t1, -0x86B($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X86B);
    // 0x801C39A0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C39A4: addiu       $a1, $a1, 0x39E0
    ctx->r5 = ADD32(ctx->r5, 0X39E0);
    // 0x801C39A8: sb          $t1, 0x95($a0)
    MEM_B(0X95, ctx->r4) = ctx->r9;
    // 0x801C39AC: lbu         $t2, -0x86A($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X86A);
    // 0x801C39B0: sb          $t2, 0x96($a0)
    MEM_B(0X96, ctx->r4) = ctx->r10;
    // 0x801C39B4: lbu         $t3, -0x869($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X869);
    // 0x801C39B8: sb          $t3, 0x97($a0)
    MEM_B(0X97, ctx->r4) = ctx->r11;
    // 0x801C39BC: lhu         $t4, -0x868($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X868);
    // 0x801C39C0: sh          $t4, 0x98($a0)
    MEM_H(0X98, ctx->r4) = ctx->r12;
    // 0x801C39C4: lhu         $t5, -0x866($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X866);
    // 0x801C39C8: jal         0x800058DC
    // 0x801C39CC: sh          $t5, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r13;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_0;
    // 0x801C39CC: sh          $t5, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r13;
    after_0:
    // 0x801C39D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C39D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C39D8: jr          $ra
    // 0x801C39DC: nop

    return;
    // 0x801C39DC: nop

;}
RECOMP_FUNC void M24_FUN_801c39e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C39E0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C39E4: addiu       $v0, $v0, -0x5D50
    ctx->r2 = ADD32(ctx->r2, -0X5D50);
    // 0x801C39E8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c39ec(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c39ec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C39EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801C39F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C39F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C39F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C39FC: bne         $t6, $zero, L_801C3A28
    if (ctx->r14 != 0) {
        // 0x801C3A00: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_801C3A28;
    }
    // 0x801C3A00: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801C3A04: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C3A08: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801C3A0C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C3A10: addiu       $v1, $v1, -0x5D48
    ctx->r3 = ADD32(ctx->r3, -0X5D48);
    // 0x801C3A14: sw          $zero, -0x5D4C($at)
    MEM_W(-0X5D4C, ctx->r1) = 0;
    // 0x801C3A18: jal         0x80005700
    // 0x801C3A1C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801C3A1C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    after_0:
    // 0x801C3A20: b           L_801C4018
    // 0x801C3A24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x801C4018)(rdram, ctx);
    return;
    // 0x801C3A24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C3A28:
    // 0x801C3A28: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C3A2C: addiu       $v1, $v1, -0x5D48
    ctx->r3 = ADD32(ctx->r3, -0X5D48);
    // 0x801C3A30: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801C3A34: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C3A38: addiu       $a1, $a1, 0x3940
    ctx->r5 = ADD32(ctx->r5, 0X3940);
    // 0x801C3A3C: beq         $t7, $zero, L_801C3A54
    if (ctx->r15 == 0) {
        // 0x801C3A40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801C3A54;
    }
    // 0x801C3A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C3A44: jal         0x800058DC
    // 0x801C3A48: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C3A48: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    after_1:
    // 0x801C3A4C: b           L_801C4018
    // 0x801C3A50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    LOOKUP_FUNC(0x801C4018)(rdram, ctx);
    return;
    // 0x801C3A50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C3A54:
    // 0x801C3A54: lhu         $t1, 0x9C($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X9C);
    // 0x801C3A58: lhu         $t2, 0x98($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X98);
    // 0x801C3A5C: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C3A60: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C3A64: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x801C3A68: bne         $at, $zero, L_801C400C
    if (ctx->r1 != 0) {
        // 0x801C3A6C: addiu       $t8, $t8, -0x1070
        ctx->r24 = ADD32(ctx->r24, -0X1070);
        LOOKUP_FUNC(0x801C400C)(rdram, ctx);
        return;
    }
    // 0x801C3A6C: addiu       $t8, $t8, -0x1070
    ctx->r24 = ADD32(ctx->r24, -0X1070);
    // 0x801C3A70: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x801C3A74: addiu       $v1, $v1, -0x5D54
    ctx->r3 = ADD32(ctx->r3, -0X5D54);
    // 0x801C3A78: bgez        $t2, L_801C3A90
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801C3A7C: cvt.s.w     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C3A90;
    }
    // 0x801C3A7C: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C3A80: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C3A84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C3A88: nop

    // 0x801C3A8C: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_801C3A90:
    // 0x801C3A90: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801C3A94: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x801C3A98: bgez        $t1, L_801C3AB0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801C3A9C: cvt.s.w     $f12, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801C3AB0;
    }
    // 0x801C3A9C: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C3AA0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C3AA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C3AA8: nop

    // 0x801C3AAC: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
L_801C3AB0:
    // 0x801C3AB0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801C3AB4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801C3AB8: lui         $t3, 0xE300
    ctx->r11 = S32(0XE300 << 16);
    // 0x801C3ABC: ori         $t3, $t3, 0xC00
    ctx->r11 = ctx->r11 | 0XC00;
    // 0x801C3AC0: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x801C3AC4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x801C3AC8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801C3ACC: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x801C3AD0: ori         $t5, $t5, 0xF00
    ctx->r13 = ctx->r13 | 0XF00;
    // 0x801C3AD4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801C3AD8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x801C3ADC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801C3AE0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801C3AE4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801C3AE8: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x801C3AEC: ori         $t7, $t7, 0x1201
    ctx->r15 = ctx->r15 | 0X1201;
    // 0x801C3AF0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801C3AF4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801C3AF8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801C3AFC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801C3B00: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801C3B04: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x801C3B08: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x801C3B0C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801C3B10: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801C3B14: addiu       $t3, $zero, 0xC00
    ctx->r11 = ADD32(0, 0XC00);
    // 0x801C3B18: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801C3B1C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801C3B20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801C3B24: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x801C3B28: ori         $t5, $t5, 0x1001
    ctx->r13 = ctx->r13 | 0X1001;
    // 0x801C3B2C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801C3B30: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x801C3B34: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801C3B38: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801C3B3C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x801C3B40: jal         0x80001060
    // 0x801C3B44: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_2;
    // 0x801C3B44: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x801C3B48: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C3B4C: addiu       $v1, $v1, -0x5D54
    ctx->r3 = ADD32(ctx->r3, -0X5D54);
    // 0x801C3B50: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C3B54: beq         $v0, $zero, L_801C3BCC
    if (ctx->r2 == 0) {
        // 0x801C3B58: lwc1        $f12, 0x20($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
            goto L_801C3BCC;
    }
    // 0x801C3B58: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C3B5C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801C3B60: jal         0x801302CC
    // 0x801C3B64: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    LOOKUP_FUNC(0x801302CC)(rdram, ctx);
        goto after_3;
    // 0x801C3B64: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x801C3B68: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C3B6C: addiu       $v1, $v1, -0x5D54
    ctx->r3 = ADD32(ctx->r3, -0X5D54);
    // 0x801C3B70: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C3B74: beq         $v0, $zero, L_801C3BA4
    if (ctx->r2 == 0) {
        // 0x801C3B78: lwc1        $f12, 0x20($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
            goto L_801C3BA4;
    }
    // 0x801C3B78: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C3B7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801C3B80: lui         $t7, 0xED08
    ctx->r15 = S32(0XED08 << 16);
    // 0x801C3B84: lui         $t8, 0x98
    ctx->r24 = S32(0X98 << 16);
    // 0x801C3B88: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801C3B8C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801C3B90: ori         $t8, $t8, 0x618
    ctx->r24 = ctx->r24 | 0X618;
    // 0x801C3B94: ori         $t7, $t7, 0x168
    ctx->r15 = ctx->r15 | 0X168;
    // 0x801C3B98: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801C3B9C: b           L_801C3BF0
    // 0x801C3BA0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_801C3BF0;
    // 0x801C3BA0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_801C3BA4:
    // 0x801C3BA4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801C3BA8: lui         $t3, 0xED08
    ctx->r11 = S32(0XED08 << 16);
    // 0x801C3BAC: lui         $t4, 0x98
    ctx->r12 = S32(0X98 << 16);
    // 0x801C3BB0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801C3BB4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801C3BB8: ori         $t4, $t4, 0x740
    ctx->r12 = ctx->r12 | 0X740;
    // 0x801C3BBC: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x801C3BC0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801C3BC4: b           L_801C3BF0
    // 0x801C3BC8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_801C3BF0;
    // 0x801C3BC8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_801C3BCC:
    // 0x801C3BCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801C3BD0: lui         $t6, 0xED04
    ctx->r14 = S32(0XED04 << 16);
    // 0x801C3BD4: lui         $t7, 0x4C
    ctx->r15 = S32(0X4C << 16);
    // 0x801C3BD8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801C3BDC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801C3BE0: ori         $t7, $t7, 0x3A0
    ctx->r15 = ctx->r15 | 0X3A0;
    // 0x801C3BE4: ori         $t6, $t6, 0x20
    ctx->r14 = ctx->r14 | 0X20;
    // 0x801C3BE8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801C3BEC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_801C3BF0:
    // 0x801C3BF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801C3BF4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x801C3BF8: lui         $t4, 0xFCFF
    ctx->r12 = S32(0XFCFF << 16);
    // 0x801C3BFC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801C3C00: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801C3C04: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801C3C08: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801C3C0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801C3C10: lui         $t5, 0xFFFD
    ctx->r13 = S32(0XFFFD << 16);
    // 0x801C3C14: ori         $t5, $t5, 0xF6FB
    ctx->r13 = ctx->r13 | 0XF6FB;
    // 0x801C3C18: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801C3C1C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801C3C20: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x801C3C24: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801C3C28: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801C3C2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801C3C30: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x801C3C34: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x801C3C38: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801C3C3C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801C3C40: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x801C3C44: ori         $t8, $t8, 0x4240
    ctx->r24 = ctx->r24 | 0X4240;
    // 0x801C3C48: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801C3C4C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801C3C50: lbu         $t9, 0x94($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X94);
    // 0x801C3C54: lbu         $a3, 0x90($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X90);
    // 0x801C3C58: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C3C5C: subu        $t3, $t9, $a3
    ctx->r11 = SUB32(ctx->r25, ctx->r7);
    // 0x801C3C60: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801C3C64: nop

    // 0x801C3C68: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C3C6C: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x801C3C70: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x801C3C74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C3C78: bgez        $a3, L_801C3C8C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x801C3C7C: div.s       $f10, $f8, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
            goto L_801C3C8C;
    }
    // 0x801C3C7C: div.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x801C3C80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C3C84: nop

    // 0x801C3C88: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801C3C8C:
    // 0x801C3C8C: lbu         $t0, 0x91($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X91);
    // 0x801C3C90: lbu         $t4, 0x95($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X95);
    // 0x801C3C94: add.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801C3C98: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C3C9C: subu        $t5, $t4, $t0
    ctx->r13 = SUB32(ctx->r12, ctx->r8);
    // 0x801C3CA0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801C3CA4: nop

    // 0x801C3CA8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C3CAC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x801C3CB0: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801C3CB4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C3CB8: bgez        $t0, L_801C3CCC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801C3CBC: div.s       $f6, $f10, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
            goto L_801C3CCC;
    }
    // 0x801C3CBC: div.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x801C3CC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C3CC4: nop

    // 0x801C3CC8: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801C3CCC:
    // 0x801C3CCC: lbu         $t1, 0x92($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X92);
    // 0x801C3CD0: lbu         $t6, 0x96($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X96);
    // 0x801C3CD4: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801C3CD8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C3CDC: subu        $t7, $t6, $t1
    ctx->r15 = SUB32(ctx->r14, ctx->r9);
    // 0x801C3CE0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801C3CE4: nop

    // 0x801C3CE8: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C3CEC: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x801C3CF0: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x801C3CF4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C3CF8: bgez        $t1, L_801C3D0C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801C3CFC: div.s       $f8, $f6, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
            goto L_801C3D0C;
    }
    // 0x801C3CFC: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x801C3D00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C3D04: nop

    // 0x801C3D08: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_801C3D0C:
    // 0x801C3D0C: lbu         $a0, 0x93($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X93);
    // 0x801C3D10: lbu         $t8, 0x97($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X97);
    // 0x801C3D14: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801C3D18: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C3D1C: subu        $t9, $t8, $a0
    ctx->r25 = SUB32(ctx->r24, ctx->r4);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c3d20(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c3d20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3D20: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801C3D24: nop

    // 0x801C3D28: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C3D2C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x801C3D30: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x801C3D34: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C3D38: bgez        $a0, L_801C3D4C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801C3D3C: div.s       $f10, $f8, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
            goto L_801C3D4C;
    }
    // 0x801C3D3C: div.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x801C3D40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C3D44: nop

    // 0x801C3D48: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801C3D4C:
    // 0x801C3D4C: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801C3D50: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C3D54: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x801C3D58: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x801C3D5C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801C3D60: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C3D64: addiu       $t3, $a1, 0x8
    ctx->r11 = ADD32(ctx->r5, 0X8);
    // 0x801C3D68: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801C3D6C: cvt.w.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = CVT_W_S(ctx->f14.fl);
    // 0x801C3D70: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C3D74: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x801C3D78: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C3D7C: nop

    // 0x801C3D80: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801C3D84: beql        $t6, $zero, L_801C3DD4
    if (ctx->r14 == 0) {
        // 0x801C3D88: mfc1        $t6, $f4
        ctx->r14 = (int32_t)ctx->f4.u32l;
        LOOKUP_FUNC(0x801C3DD4)(rdram, ctx);
        return;
    }
    goto skip_0;
    // 0x801C3D88: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x801C3D8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c3d90(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c3d90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C3D90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C3D94: sub.s       $f4, $f14, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x801C3D98: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C3D9C: nop

    // 0x801C3DA0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801C3DA4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C3DA8: nop

    // 0x801C3DAC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801C3DB0: bne         $t6, $zero, L_801C3DC8
    if (ctx->r14 != 0) {
        // 0x801C3DB4: nop
    
            goto L_801C3DC8;
    }
    // 0x801C3DB4: nop

    // 0x801C3DB8: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x801C3DBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C3DC0: b           L_801C3DE0
    // 0x801C3DC4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801C3DE0;
    // 0x801C3DC4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801C3DC8:
    // 0x801C3DC8: b           L_801C3DE0
    // 0x801C3DCC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801C3DE0;
    // 0x801C3DCC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801C3DD0: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x801C3DD4: nop

    // 0x801C3DD8: bltz        $t6, L_801C3DC8
    if (SIGNED(ctx->r14) < 0) {
        // 0x801C3DDC: nop
    
            goto L_801C3DC8;
    }
    // 0x801C3DDC: nop

L_801C3DE0:
    // 0x801C3DE0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801C3DE4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C3DE8: sll         $t9, $t6, 24
    ctx->r25 = S32(ctx->r14 << 24);
    // 0x801C3DEC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C3DF0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C3DF4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C3DF8: nop

    // 0x801C3DFC: cvt.w.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801C3E00: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C3E04: nop

    // 0x801C3E08: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801C3E0C: beql        $t4, $zero, L_801C3E5C
    if (ctx->r12 == 0) {
        // 0x801C3E10: mfc1        $t4, $f8
        ctx->r12 = (int32_t)ctx->f8.u32l;
            goto L_801C3E5C;
    }
    goto skip_0;
    // 0x801C3E10: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x801C3E14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C3E18: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C3E1C: sub.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x801C3E20: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C3E24: nop

    // 0x801C3E28: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C3E2C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C3E30: nop

    // 0x801C3E34: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801C3E38: bne         $t4, $zero, L_801C3E50
    if (ctx->r12 != 0) {
        // 0x801C3E3C: nop
    
            goto L_801C3E50;
    }
    // 0x801C3E3C: nop

    // 0x801C3E40: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x801C3E44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C3E48: b           L_801C3E68
    // 0x801C3E4C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801C3E68;
    // 0x801C3E4C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801C3E50:
    // 0x801C3E50: b           L_801C3E68
    // 0x801C3E54: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801C3E68;
    // 0x801C3E54: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801C3E58: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
L_801C3E5C:
    // 0x801C3E5C: nop

    // 0x801C3E60: bltz        $t4, L_801C3E50
    if (SIGNED(ctx->r12) < 0) {
        // 0x801C3E64: nop
    
            goto L_801C3E50;
    }
    // 0x801C3E64: nop

L_801C3E68:
    // 0x801C3E68: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C3E6C: or          $t5, $t4, $zero
    ctx->r13 = ctx->r12 | 0;
    // 0x801C3E70: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C3E74: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x801C3E78: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C3E7C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C3E80: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x801C3E84: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x801C3E88: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801C3E8C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C3E90: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C3E94: nop

    // 0x801C3E98: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801C3E9C: beql        $t4, $zero, L_801C3EEC
    if (ctx->r12 == 0) {
        // 0x801C3EA0: mfc1        $t4, $f10
        ctx->r12 = (int32_t)ctx->f10.u32l;
            goto L_801C3EEC;
    }
    goto skip_1;
    // 0x801C3EA0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x801C3EA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C3EA8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C3EAC: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x801C3EB0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C3EB4: nop

    // 0x801C3EB8: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C3EBC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C3EC0: nop

    // 0x801C3EC4: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801C3EC8: bne         $t4, $zero, L_801C3EE0
    if (ctx->r12 != 0) {
        // 0x801C3ECC: nop
    
            goto L_801C3EE0;
    }
    // 0x801C3ECC: nop

    // 0x801C3ED0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x801C3ED4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C3ED8: b           L_801C3EF8
    // 0x801C3EDC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801C3EF8;
    // 0x801C3EDC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801C3EE0:
    // 0x801C3EE0: b           L_801C3EF8
    // 0x801C3EE4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801C3EF8;
    // 0x801C3EE4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801C3EE8: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
L_801C3EEC:
    // 0x801C3EEC: nop

    // 0x801C3EF0: bltz        $t4, L_801C3EE0
    if (SIGNED(ctx->r12) < 0) {
        // 0x801C3EF4: nop
    
            goto L_801C3EE0;
    }
    // 0x801C3EF4: nop

L_801C3EF8:
    // 0x801C3EF8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C3EFC: or          $t5, $t4, $zero
    ctx->r13 = ctx->r12 | 0;
    // 0x801C3F00: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C3F04: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x801C3F08: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C3F0C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C3F10: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x801C3F14: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x801C3F18: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x801C3F1C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C3F20: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C3F24: nop

    // 0x801C3F28: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801C3F2C: beql        $t4, $zero, L_801C3F7C
    if (ctx->r12 == 0) {
        // 0x801C3F30: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801C3F7C;
    }
    goto skip_2;
    // 0x801C3F30: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x801C3F34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C3F38: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C3F3C: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x801C3F40: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C3F44: nop

    // 0x801C3F48: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801C3F4C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C3F50: nop

    // 0x801C3F54: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801C3F58: bne         $t4, $zero, L_801C3F70
    if (ctx->r12 != 0) {
        // 0x801C3F5C: nop
    
            goto L_801C3F70;
    }
    // 0x801C3F5C: nop

    // 0x801C3F60: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801C3F64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C3F68: b           L_801C3F88
    // 0x801C3F6C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801C3F88;
    // 0x801C3F6C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801C3F70:
    // 0x801C3F70: b           L_801C3F88
    // 0x801C3F74: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801C3F88;
    // 0x801C3F74: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801C3F78: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801C3F7C:
    // 0x801C3F7C: nop

    // 0x801C3F80: bltz        $t4, L_801C3F70
    if (SIGNED(ctx->r12) < 0) {
        // 0x801C3F84: nop
    
            goto L_801C3F70;
    }
    // 0x801C3F84: nop

L_801C3F88:
    // 0x801C3F88: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x801C3F8C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x801C3F90: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C3F94: jal         0x80001060
    // 0x801C3F98: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x801C3F98: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    after_0:
    // 0x801C3F9C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C3FA0: beq         $v0, $zero, L_801C3FC8
    if (ctx->r2 == 0) {
        // 0x801C3FA4: addiu       $v1, $v1, -0x5D54
        ctx->r3 = ADD32(ctx->r3, -0X5D54);
            goto L_801C3FC8;
    }
    // 0x801C3FA4: addiu       $v1, $v1, -0x5D54
    ctx->r3 = ADD32(ctx->r3, -0X5D54);
    // 0x801C3FA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801C3FAC: lui         $t3, 0xF6A0
    ctx->r11 = S32(0XF6A0 << 16);
    // 0x801C3FB0: ori         $t3, $t3, 0x780
    ctx->r11 = ctx->r11 | 0X780;
    // 0x801C3FB4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801C3FB8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801C3FBC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801C3FC0: b           L_801C3FE4
    // 0x801C3FC4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_801C3FE4;
    // 0x801C3FC4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_801C3FC8:
    // 0x801C3FC8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801C3FCC: lui         $t5, 0xF650
    ctx->r13 = S32(0XF650 << 16);
    // 0x801C3FD0: ori         $t5, $t5, 0x3C0
    ctx->r13 = ctx->r13 | 0X3C0;
    // 0x801C3FD4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801C3FD8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x801C3FDC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801C3FE0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_801C3FE4:
    // 0x801C3FE4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801C3FE8: lui         $t6, 0xDF00
    ctx->r14 = S32(0XDF00 << 16);
    // 0x801C3FEC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801C3FF0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801C3FF4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801C3FF8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801C3FFC: lhu         $t8, 0x98($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X98);
    // 0x801C4000: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801C4004: b           L_801C4014
    // 0x801C4008: sh          $t9, 0x98($s0)
    MEM_H(0X98, ctx->r16) = ctx->r25;
        goto L_801C4014;
    // 0x801C4008: sh          $t9, 0x98($s0)
    MEM_H(0X98, ctx->r16) = ctx->r25;
    // 0x801C400C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C4010: sw          $zero, -0x5D4C($at)
    MEM_W(-0X5D4C, ctx->r1) = 0;
L_801C4014:
    // 0x801C4014: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C4018: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C401C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801C4020: jr          $ra
    // 0x801C4024: nop

    return;
    // 0x801C4024: nop

;}
RECOMP_FUNC void M24_FUN_801c4028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C402C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C4030: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C4034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C4038: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C403C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C4040: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C4044: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C4048: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x801C404C: jal         0x80005670
    // 0x801C4050: addiu       $a1, $a1, -0x5D20
    ctx->r5 = ADD32(ctx->r5, -0X5D20);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C4050: addiu       $a1, $a1, -0x5D20
    ctx->r5 = ADD32(ctx->r5, -0X5D20);
    after_0:
    // 0x801C4054: bne         $v0, $zero, L_801C4064
    if (ctx->r2 != 0) {
        // 0x801C4058: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C4064;
    }
    // 0x801C4058: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C405C: b           L_801C4210
    // 0x801C4060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C4210;
    // 0x801C4060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C4064:
    // 0x801C4064: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C4068: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801C406C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C4070: swc1        $f4, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f4.u32l;
    // 0x801C4074: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C4078: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C407C: swc1        $f6, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f6.u32l;
    // 0x801C4080: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C4084: swc1        $f8, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f8.u32l;
    // 0x801C4088: lhu         $t6, 0x32($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X32);
    // 0x801C408C: sh          $t6, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r14;
    // 0x801C4090: lhu         $t7, 0x2A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X2A);
    // 0x801C4094: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C4098: sh          $t7, 0x9E($v0)
    MEM_H(0X9E, ctx->r2) = ctx->r15;
    // 0x801C409C: lhu         $t8, 0x2E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2E);
    // 0x801C40A0: sh          $t8, 0xAC($v0)
    MEM_H(0XAC, ctx->r2) = ctx->r24;
    // 0x801C40A4: lbu         $t9, 0x3F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3F);
    // 0x801C40A8: sb          $t9, 0xA0($v0)
    MEM_B(0XA0, ctx->r2) = ctx->r25;
    // 0x801C40AC: lbu         $t0, 0x43($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X43);
    // 0x801C40B0: sb          $t0, 0xA1($v0)
    MEM_B(0XA1, ctx->r2) = ctx->r8;
    // 0x801C40B4: lbu         $t1, 0x47($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X47);
    // 0x801C40B8: sb          $t1, 0xA2($v0)
    MEM_B(0XA2, ctx->r2) = ctx->r9;
    // 0x801C40BC: lbu         $t2, 0x4B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4B);
    // 0x801C40C0: sb          $t2, 0xA4($v0)
    MEM_B(0XA4, ctx->r2) = ctx->r10;
    // 0x801C40C4: lbu         $t3, 0x4F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4F);
    // 0x801C40C8: sb          $t3, 0xA5($v1)
    MEM_B(0XA5, ctx->r3) = ctx->r11;
    // 0x801C40CC: lbu         $t4, 0x53($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X53);
    // 0x801C40D0: sb          $t4, 0xA6($v1)
    MEM_B(0XA6, ctx->r3) = ctx->r12;
    // 0x801C40D4: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801C40D8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C40DC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801C40E0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C40E4: nop

    // 0x801C40E8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801C40EC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C40F0: nop

    // 0x801C40F4: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801C40F8: beql        $t6, $zero, L_801C4148
    if (ctx->r14 == 0) {
        // 0x801C40FC: mfc1        $t6, $f18
        ctx->r14 = (int32_t)ctx->f18.u32l;
            goto L_801C4148;
    }
    goto skip_0;
    // 0x801C40FC: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x801C4100: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C4104: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C4108: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801C410C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C4110: nop

    // 0x801C4114: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801C4118: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C411C: nop

    // 0x801C4120: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801C4124: bne         $t6, $zero, L_801C413C
    if (ctx->r14 != 0) {
        // 0x801C4128: nop
    
            goto L_801C413C;
    }
    // 0x801C4128: nop

    // 0x801C412C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x801C4130: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C4134: b           L_801C4154
    // 0x801C4138: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801C4154;
    // 0x801C4138: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801C413C:
    // 0x801C413C: b           L_801C4154
    // 0x801C4140: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801C4154;
    // 0x801C4140: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801C4144: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
L_801C4148:
    // 0x801C4148: nop

    // 0x801C414C: bltz        $t6, L_801C413C
    if (SIGNED(ctx->r14) < 0) {
        // 0x801C4150: nop
    
            goto L_801C413C;
    }
    // 0x801C4150: nop

L_801C4154:
    // 0x801C4154: sb          $t6, 0xA3($v1)
    MEM_B(0XA3, ctx->r3) = ctx->r14;
    // 0x801C4158: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801C415C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801C4160: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C4164: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C4168: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801C416C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801C4170: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C4174: nop

    // 0x801C4178: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801C417C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C4180: nop

    // 0x801C4184: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801C4188: beql        $t8, $zero, L_801C41D8
    if (ctx->r24 == 0) {
        // 0x801C418C: mfc1        $t8, $f8
        ctx->r24 = (int32_t)ctx->f8.u32l;
            goto L_801C41D8;
    }
    goto skip_1;
    // 0x801C418C: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x801C4190: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C4194: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C4198: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801C419C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C41A0: nop

    // 0x801C41A4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C41A8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C41AC: nop

    // 0x801C41B0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801C41B4: bne         $t8, $zero, L_801C41CC
    if (ctx->r24 != 0) {
        // 0x801C41B8: nop
    
            goto L_801C41CC;
    }
    // 0x801C41B8: nop

    // 0x801C41BC: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x801C41C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C41C4: b           L_801C41E4
    // 0x801C41C8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_801C41E4;
    // 0x801C41C8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_801C41CC:
    // 0x801C41CC: b           L_801C41E4
    // 0x801C41D0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_801C41E4;
    // 0x801C41D0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801C41D4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
L_801C41D8:
    // 0x801C41D8: nop

    // 0x801C41DC: bltz        $t8, L_801C41CC
    if (SIGNED(ctx->r24) < 0) {
        // 0x801C41E0: nop
    
            goto L_801C41CC;
    }
    // 0x801C41E0: nop

L_801C41E4:
    // 0x801C41E4: sb          $t8, 0xA7($v1)
    MEM_B(0XA7, ctx->r3) = ctx->r24;
    // 0x801C41E8: sh          $zero, 0xB0($v1)
    MEM_H(0XB0, ctx->r3) = 0;
    // 0x801C41EC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x801C41F0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801C41F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801C41F8: sh          $t9, 0xB2($v1)
    MEM_H(0XB2, ctx->r3) = ctx->r25;
    // 0x801C41FC: lhu         $t0, 0x56($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X56);
    // 0x801C4200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C4204: jal         0x8038C4D8
    // 0x801C4208: sh          $t0, 0xA8($v1)
    MEM_H(0XA8, ctx->r3) = ctx->r8;
    LOOKUP_FUNC(0x8038C4D8)(rdram, ctx);
        goto after_1;
    // 0x801C4208: sh          $t0, 0xA8($v1)
    MEM_H(0XA8, ctx->r3) = ctx->r8;
    after_1:
    // 0x801C420C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C4210:
    // 0x801C4210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C4214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C4218: jr          $ra
    // 0x801C421C: nop

    return;
    // 0x801C421C: nop

;}
RECOMP_FUNC void M24_FUN_801c4220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4220: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C4224: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C4228: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C422C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C4230: lhu         $v0, 0xB2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XB2);
    // 0x801C4234: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C4238: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801C423C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801C4240: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801C4244: lw          $t7, -0x5DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5DCC);
    // 0x801C4248: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C424C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C4250: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C4254: addiu       $a1, $a1, -0x5D0C
    ctx->r5 = ADD32(ctx->r5, -0X5D0C);
    // 0x801C4258: jal         0x80005E44
    // 0x801C425C: sw          $t7, -0x5D08($at)
    MEM_W(-0X5D08, ctx->r1) = ctx->r15;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C425C: sw          $t7, -0x5D08($at)
    MEM_W(-0X5D08, ctx->r1) = ctx->r15;
    after_0:
    // 0x801C4260: jal         0x80006214
    // 0x801C4264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C4264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801C4268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C426C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C4270: addiu       $a2, $zero, 0xA7
    ctx->r6 = ADD32(0, 0XA7);
    // 0x801C4274: jal         0x8012C89C
    // 0x801C4278: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801C4278: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801C427C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801C4280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C4284: addiu       $a2, $zero, 0x2DD
    ctx->r6 = ADD32(0, 0X2DD);
    // 0x801C4288: lw          $a1, 0x30($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X30);
    // 0x801C428C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C4290: jal         0x8012CF8C
    // 0x801C4294: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x801C4294: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x801C4298: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801C429C: lwc1        $f4, 0x90($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801C42A0: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x801C42A4: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C42A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C42AC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801C42B0: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801C42B4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801C42B8: lwc1        $f6, 0x94($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801C42BC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C42C0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C42C4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801C42C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C42CC: swc1        $f6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f6.u32l;
    // 0x801C42D0: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801C42D4: lwc1        $f8, 0x98($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801C42D8: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C42DC: swc1        $f8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f8.u32l;
    // 0x801C42E0: lhu         $t5, 0x9E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X9E);
    // 0x801C42E4: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x801C42E8: bgez        $t5, L_801C42FC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801C42EC: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C42FC;
    }
    // 0x801C42EC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C42F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C42F4: nop

    // 0x801C42F8: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801C42FC:
    // 0x801C42FC: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801C4300: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801C4304: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4308: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C430C: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C4310: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C4314: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x801C4318: nop

    // 0x801C431C: sh          $t7, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r15;
    // 0x801C4320: lhu         $t0, 0xAC($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XAC);
    // 0x801C4324: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801C4328: bgez        $t0, L_801C433C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801C432C: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C433C;
    }
    // 0x801C432C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C4330: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C4334: nop

    // 0x801C4338: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_801C433C:
    // 0x801C433C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C4340: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801C4344: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4348: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C434C: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C4350: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C4354: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x801C4358: nop

    // 0x801C435C: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    // 0x801C4360: lhu         $t5, 0x9C($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X9C);
    // 0x801C4364: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x801C4368: bgez        $t5, L_801C437C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801C436C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C437C;
    }
    // 0x801C436C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C4370: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C4374: nop

    // 0x801C4378: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801C437C:
    // 0x801C437C: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801C4380: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C4384: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x801C4388: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C438C: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C4390: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C4394: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C4398: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C439C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C43A0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C43A4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x801C43A8: nop

    // 0x801C43AC: sh          $t8, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r24;
    // 0x801C43B0: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801C43B4: lbu         $t0, 0xA0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XA0);
    // 0x801C43B8: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801C43BC: sb          $t0, 0x48($t3)
    MEM_B(0X48, ctx->r11) = ctx->r8;
    // 0x801C43C0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801C43C4: lbu         $t2, 0xA1($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XA1);
    // 0x801C43C8: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C43CC: sb          $t2, 0x49($t5)
    MEM_B(0X49, ctx->r13) = ctx->r10;
    // 0x801C43D0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C43D4: lbu         $t6, 0xA2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA2);
    // 0x801C43D8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C43DC: sb          $t6, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = ctx->r14;
    // 0x801C43E0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801C43E4: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C43E8: sb          $v1, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r3;
    // 0x801C43EC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801C43F0: lbu         $t0, 0xA4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XA4);
    // 0x801C43F4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C43F8: sb          $t0, 0x4C($t4)
    MEM_B(0X4C, ctx->r12) = ctx->r8;
    // 0x801C43FC: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801C4400: lbu         $t2, 0xA5($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XA5);
    // 0x801C4404: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x801C4408: sb          $t2, 0x4D($t7)
    MEM_B(0X4D, ctx->r15) = ctx->r10;
    // 0x801C440C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801C4410: lbu         $t6, 0xA6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA6);
    // 0x801C4414: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C4418: sb          $t6, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = ctx->r14;
    // 0x801C441C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801C4420: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801C4424: sb          $v1, 0x4F($t3)
    MEM_B(0X4F, ctx->r11) = ctx->r3;
    // 0x801C4428: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x801C442C: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x801C4430: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x801C4434: ori         $t5, $t4, 0x300
    ctx->r13 = ctx->r12 | 0X300;
    // 0x801C4438: sw          $t5, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r13;
    // 0x801C443C: lbu         $t2, 0xA3($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XA3);
    // 0x801C4440: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x801C4444: bgez        $t2, L_801C4458
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801C4448: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C4458;
    }
    // 0x801C4448: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C444C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C4450: nop

    // 0x801C4454: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_801C4458:
    // 0x801C4458: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C445C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C4460: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4464: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C4468: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C446C: swc1        $f6, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f6.u32l;
    // 0x801C4470: lbu         $t6, 0xA7($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA7);
    // 0x801C4474: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x801C4478: bgez        $t6, L_801C448C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C447C: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801C448C;
    }
    // 0x801C447C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C4480: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C4484: nop

    // 0x801C4488: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_801C448C:
    // 0x801C448C: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C4490: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801C4494: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C4498: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C449C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C44A0: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801C44A4: addiu       $t4, $t4, -0x7060
    ctx->r12 = ADD32(ctx->r12, -0X7060);
    // 0x801C44A8: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x801C44AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C44B0: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x801C44B4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C44B8: addiu       $a1, $a1, 0x44F4
    ctx->r5 = ADD32(ctx->r5, 0X44F4);
    // 0x801C44BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C44C0: swc1        $f4, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f4.u32l;
    // 0x801C44C4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801C44C8: lw          $t0, 0x30($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X30);
    // 0x801C44CC: swc1        $f6, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f6.u32l;
    // 0x801C44D0: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801C44D4: lw          $t7, 0x30($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X30);
    // 0x801C44D8: jal         0x800058DC
    // 0x801C44DC: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C44DC: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    after_4:
    // 0x801C44E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C44E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C44E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C44EC: jr          $ra
    // 0x801C44F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C44F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c44f4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c44f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C44F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C44F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C44FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C4500: lhu         $t6, 0xB0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XB0);
    // 0x801C4504: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x801C4508: addiu       $a2, $zero, 0x2DD
    ctx->r6 = ADD32(0, 0X2DD);
    // 0x801C450C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C4510: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C4514: bgez        $t6, L_801C452C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C4518: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C452C;
    }
    // 0x801C4518: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C451C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4520: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C4524: nop

    // 0x801C4528: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801C452C:
    // 0x801C452C: lhu         $t7, 0xA8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XA8);
    // 0x801C4530: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4534: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801C4538: bgez        $t7, L_801C454C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C453C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C454C;
    }
    // 0x801C453C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C4540: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C4544: nop

    // 0x801C4548: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801C454C:
    // 0x801C454C: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801C4550: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801C4554: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C4558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C455C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C4560: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801C4564: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C4568: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801C456C: nop

    // 0x801C4570: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C4574: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801C4578: nop

    // 0x801C457C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801C4580: beql        $v0, $zero, L_801C45D0
    if (ctx->r2 == 0) {
        // 0x801C4584: mfc1        $v0, $f18
        ctx->r2 = (int32_t)ctx->f18.u32l;
            goto L_801C45D0;
    }
    goto skip_0;
    // 0x801C4584: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x801C4588: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C458C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C4590: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801C4594: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x801C4598: nop

    // 0x801C459C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801C45A0: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x801C45A4: nop

    // 0x801C45A8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x801C45AC: bne         $v0, $zero, L_801C45C4
    if (ctx->r2 != 0) {
        // 0x801C45B0: nop
    
            goto L_801C45C4;
    }
    // 0x801C45B0: nop

    // 0x801C45B4: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x801C45B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C45BC: b           L_801C45DC
    // 0x801C45C0: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_801C45DC;
    // 0x801C45C0: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_801C45C4:
    // 0x801C45C4: b           L_801C45DC
    // 0x801C45C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_801C45DC;
    // 0x801C45C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801C45CC: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
L_801C45D0:
    // 0x801C45D0: nop

    // 0x801C45D4: bltz        $v0, L_801C45C4
    if (SIGNED(ctx->r2) < 0) {
        // 0x801C45D8: nop
    
            goto L_801C45C4;
    }
    // 0x801C45D8: nop

L_801C45DC:
    // 0x801C45DC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x801C45E0: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x801C45E4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801C45E8: mfhi        $v0
    ctx->r2 = hi;
    // 0x801C45EC: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x801C45F0: lw          $a1, 0x30($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X30);
    // 0x801C45F4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C45F8: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // 0x801C45FC: lw          $a3, -0x5CFC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5CFC);
    // 0x801C4600: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C4604: jal         0x8012CF8C
    // 0x801C4608: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801C4608: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x801C460C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C4610: lhu         $t2, 0xB0($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0XB0);
    // 0x801C4614: lhu         $t5, 0xA8($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0XA8);
    // 0x801C4618: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801C461C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x801C4620: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801C4624: bne         $at, $zero, L_801C4634
    if (ctx->r1 != 0) {
        // 0x801C4628: sh          $t3, 0xB0($a0)
        MEM_H(0XB0, ctx->r4) = ctx->r11;
            goto L_801C4634;
    }
    // 0x801C4628: sh          $t3, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r11;
    // 0x801C462C: jal         0x80005700
    // 0x801C4630: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_1;
    // 0x801C4630: nop

    after_1:
L_801C4634:
    // 0x801C4634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C4638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C463C: jr          $ra
    // 0x801C4640: nop

    return;
    // 0x801C4640: nop

;}
RECOMP_FUNC void M24_FUN_801c4644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4644: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C4648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C464C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C4650: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C4654: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C4658: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x801C465C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C4660: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C4664: addiu       $a1, $a1, -0x5CAC
    ctx->r5 = ADD32(ctx->r5, -0X5CAC);
    // 0x801C4668: jal         0x80005670
    // 0x801C466C: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C466C: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C4670: bne         $v0, $zero, L_801C4680
    if (ctx->r2 != 0) {
        // 0x801C4674: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C4680;
    }
    // 0x801C4674: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C4678: b           L_801C46C0
    // 0x801C467C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C46C0;
    // 0x801C467C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C4680:
    // 0x801C4680: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C4684: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C4688: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801C468C: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C4690: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x801C4694: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C4698: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
    // 0x801C469C: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C46A0: swc1        $f10, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f10.u32l;
    // 0x801C46A4: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C46A8: swc1        $f16, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f16.u32l;
    // 0x801C46AC: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C46B0: sh          $zero, 0xA8($v1)
    MEM_H(0XA8, ctx->r3) = 0;
    // 0x801C46B4: swc1        $f18, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f18.u32l;
    // 0x801C46B8: lhu         $t6, 0x32($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X32);
    // 0x801C46BC: sh          $t6, 0xAC($v1)
    MEM_H(0XAC, ctx->r3) = ctx->r14;
L_801C46C0:
    // 0x801C46C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C46C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C46C8: jr          $ra
    // 0x801C46CC: nop

    return;
    // 0x801C46CC: nop

;}
RECOMP_FUNC void M24_FUN_801c46d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C46D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C46D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C46D8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801C46DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C46E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C46E4: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801C46E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C46EC: jal         0x80005E44
    // 0x801C46F0: addiu       $a1, $a1, -0x2774
    ctx->r5 = ADD32(ctx->r5, -0X2774);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C46F0: addiu       $a1, $a1, -0x2774
    ctx->r5 = ADD32(ctx->r5, -0X2774);
    after_0:
    // 0x801C46F4: jal         0x80006214
    // 0x801C46F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C46F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801C46FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C4700: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C4704: addiu       $a2, $zero, 0x2D9
    ctx->r6 = ADD32(0, 0X2D9);
    // 0x801C4708: jal         0x8012C89C
    // 0x801C470C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801C470C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_2:
    // 0x801C4710: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801C4714: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x801C4718: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C471C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801C4720: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C4724: lwc1        $f4, 0x90($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801C4728: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C472C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C4730: lwc1        $f12, -0x2DD0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2DD0);
    // 0x801C4734: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801C4738: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801C473C: lwc1        $f6, 0x94($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801C4740: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4744: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C4748: addiu       $a1, $a1, 0x480C
    ctx->r5 = ADD32(ctx->r5, 0X480C);
    // 0x801C474C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C4750: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x801C4754: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x801C4758: lwc1        $f8, 0x98($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801C475C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C4760: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x801C4764: lwc1        $f10, 0x9C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x801C4768: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801C476C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C4770: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C4774: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801C4778: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801C477C: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x801C4780: nop

    // 0x801C4784: sh          $t3, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r11;
    // 0x801C4788: lwc1        $f6, 0xA0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x801C478C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801C4790: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801C4794: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C4798: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801C479C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801C47A0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x801C47A4: nop

    // 0x801C47A8: sh          $t7, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r15;
    // 0x801C47AC: lwc1        $f18, 0xA4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x801C47B0: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801C47B4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C47B8: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x801C47BC: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C47C0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C47C4: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x801C47C8: nop

    // 0x801C47CC: sh          $t1, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r9;
    // 0x801C47D0: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801C47D4: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801C47D8: swc1        $f12, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f12.u32l;
    // 0x801C47DC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801C47E0: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801C47E4: swc1        $f12, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f12.u32l;
    // 0x801C47E8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C47EC: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C47F0: jal         0x800058DC
    // 0x801C47F4: swc1        $f12, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f12.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C47F4: swc1        $f12, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f12.u32l;
    after_3:
    // 0x801C47F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C47FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C4800: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C4804: jr          $ra
    // 0x801C4808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C4808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c480c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c480c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C480C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C4810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C4814: lhu         $t6, 0xA8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA8);
    // 0x801C4818: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C481C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C4820: bgez        $t6, L_801C4834
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C4824: cvt.s.w     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C4834;
    }
    // 0x801C4824: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C4828: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C482C: nop

    // 0x801C4830: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_801C4834:
    // 0x801C4834: lhu         $t7, 0xAC($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XAC);
    // 0x801C4838: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C483C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801C4840: bgez        $t7, L_801C4854
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C4844: cvt.s.w     $f12, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801C4854;
    }
    // 0x801C4844: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801C4848: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C484C: nop

    // 0x801C4850: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
L_801C4854:
    // 0x801C4854: lwc1        $f0, 0x94($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801C4858: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x801C485C: mul.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x801C4860: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C4864: div.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x801C4868: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x801C486C: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    // 0x801C4870: lhu         $t0, 0xA8($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0XA8);
    // 0x801C4874: lhu         $t2, 0xAC($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0XAC);
    // 0x801C4878: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801C487C: andi        $t3, $t1, 0xFFFF
    ctx->r11 = ctx->r9 & 0XFFFF;
    // 0x801C4880: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801C4884: beq         $at, $zero, L_801C4894
    if (ctx->r1 == 0) {
        // 0x801C4888: sh          $t1, 0xA8($a0)
        MEM_H(0XA8, ctx->r4) = ctx->r9;
            goto L_801C4894;
    }
    // 0x801C4888: sh          $t1, 0xA8($a0)
    MEM_H(0XA8, ctx->r4) = ctx->r9;
    // 0x801C488C: jal         0x80005700
    // 0x801C4890: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801C4890: nop

    after_0:
L_801C4894:
    // 0x801C4894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C4898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C489C: jr          $ra
    // 0x801C48A0: nop

    return;
    // 0x801C48A0: nop

;}
RECOMP_FUNC void M24_FUN_801c48a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C48A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C48A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C48AC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C48B0: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C48B4: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C48B8: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x801C48BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C48C0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C48C4: addiu       $a1, $a1, -0x5C98
    ctx->r5 = ADD32(ctx->r5, -0X5C98);
    // 0x801C48C8: jal         0x80005670
    // 0x801C48CC: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C48CC: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C48D0: bne         $v0, $zero, L_801C48E0
    if (ctx->r2 != 0) {
        // 0x801C48D4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C48E0;
    }
    // 0x801C48D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C48D8: b           L_801C4A88
    // 0x801C48DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    LOOKUP_FUNC(0x801C4A88)(rdram, ctx);
    return;
    // 0x801C48DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C48E0:
    // 0x801C48E0: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C48E4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801C48E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C48EC: swc1        $f4, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f4.u32l;
    // 0x801C48F0: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C48F4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801C48F8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C48FC: swc1        $f6, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f6.u32l;
    // 0x801C4900: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C4904: swc1        $f8, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f8.u32l;
    // 0x801C4908: lhu         $t6, 0x2E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2E);
    // 0x801C490C: sh          $t6, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r14;
    // 0x801C4910: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x801C4914: sh          $t7, 0x9E($v0)
    MEM_H(0X9E, ctx->r2) = ctx->r15;
    // 0x801C4918: lbu         $t8, 0x3B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3B);
    // 0x801C491C: sb          $t8, 0xA0($v0)
    MEM_B(0XA0, ctx->r2) = ctx->r24;
    // 0x801C4920: lbu         $t9, 0x3F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3F);
    // 0x801C4924: sb          $t9, 0xA1($v0)
    MEM_B(0XA1, ctx->r2) = ctx->r25;
    // 0x801C4928: lbu         $t0, 0x43($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X43);
    // 0x801C492C: sb          $t0, 0xA2($v0)
    MEM_B(0XA2, ctx->r2) = ctx->r8;
    // 0x801C4930: lbu         $t1, 0x47($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X47);
    // 0x801C4934: sb          $t1, 0xA4($v0)
    MEM_B(0XA4, ctx->r2) = ctx->r9;
    // 0x801C4938: lbu         $t2, 0x4B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4B);
    // 0x801C493C: sb          $t2, 0xA5($v0)
    MEM_B(0XA5, ctx->r2) = ctx->r10;
    // 0x801C4940: lbu         $t3, 0x4F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4F);
    // 0x801C4944: sb          $t3, 0xA6($v1)
    MEM_B(0XA6, ctx->r3) = ctx->r11;
    // 0x801C4948: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801C494C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C4950: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C4954: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801C4958: nop

    // 0x801C495C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801C4960: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801C4964: nop

    // 0x801C4968: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801C496C: beql        $t5, $zero, L_801C49BC
    if (ctx->r13 == 0) {
        // 0x801C4970: mfc1        $t5, $f18
        ctx->r13 = (int32_t)ctx->f18.u32l;
            goto L_801C49BC;
    }
    goto skip_0;
    // 0x801C4970: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x801C4974: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C4978: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801C497C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801C4980: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801C4984: nop

    // 0x801C4988: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801C498C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801C4990: nop

    // 0x801C4994: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801C4998: bne         $t5, $zero, L_801C49B0
    if (ctx->r13 != 0) {
        // 0x801C499C: nop
    
            goto L_801C49B0;
    }
    // 0x801C499C: nop

    // 0x801C49A0: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x801C49A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C49A8: b           L_801C49C8
    // 0x801C49AC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_801C49C8;
    // 0x801C49AC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_801C49B0:
    // 0x801C49B0: b           L_801C49C8
    // 0x801C49B4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_801C49C8;
    // 0x801C49B4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801C49B8: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
L_801C49BC:
    // 0x801C49BC: nop

    // 0x801C49C0: bltz        $t5, L_801C49B0
    if (SIGNED(ctx->r13) < 0) {
        // 0x801C49C4: nop
    
            goto L_801C49B0;
    }
    // 0x801C49C4: nop

L_801C49C8:
    // 0x801C49C8: sb          $t5, 0xA3($v1)
    MEM_B(0XA3, ctx->r3) = ctx->r13;
    // 0x801C49CC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C49D0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801C49D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C49D8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C49DC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801C49E0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C49E4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801C49E8: nop

    // 0x801C49EC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801C49F0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801C49F4: nop

    // 0x801C49F8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801C49FC: beql        $t7, $zero, L_801C4A4C
    if (ctx->r15 == 0) {
        // 0x801C4A00: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_801C4A4C;
    }
    goto skip_1;
    // 0x801C4A00: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x801C4A04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C4A08: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C4A0C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801C4A10: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801C4A14: nop

    // 0x801C4A18: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C4A1C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801C4A20: nop

    // 0x801C4A24: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801C4A28: bne         $t7, $zero, L_801C4A40
    if (ctx->r15 != 0) {
        // 0x801C4A2C: nop
    
            goto L_801C4A40;
    }
    // 0x801C4A2C: nop

    // 0x801C4A30: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x801C4A34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C4A38: b           L_801C4A58
    // 0x801C4A3C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801C4A58;
    // 0x801C4A3C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801C4A40:
    // 0x801C4A40: b           L_801C4A58
    // 0x801C4A44: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801C4A58;
    // 0x801C4A44: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801C4A48: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_801C4A4C:
    // 0x801C4A4C: nop

    // 0x801C4A50: bltz        $t7, L_801C4A40
    if (SIGNED(ctx->r15) < 0) {
        // 0x801C4A54: nop
    
            goto L_801C4A40;
    }
    // 0x801C4A54: nop

L_801C4A58:
    // 0x801C4A58: sb          $t7, 0xA7($v1)
    MEM_B(0XA7, ctx->r3) = ctx->r15;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c4a5c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c4a5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4A5C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x801C4A60: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C4A64: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801C4A68: sw          $t8, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r24;
    // 0x801C4A6C: lhu         $t9, 0x2A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X2A);
    // 0x801C4A70: sh          $zero, 0xB0($v1)
    MEM_H(0XB0, ctx->r3) = 0;
    // 0x801C4A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C4A78: sh          $t9, 0xAC($v1)
    MEM_H(0XAC, ctx->r3) = ctx->r25;
    // 0x801C4A7C: lhu         $t0, 0x56($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X56);
    // 0x801C4A80: sh          $t1, 0xAE($v1)
    MEM_H(0XAE, ctx->r3) = ctx->r9;
    // 0x801C4A84: sh          $t0, 0xB2($v1)
    MEM_H(0XB2, ctx->r3) = ctx->r8;
    // 0x801C4A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C4A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C4A90: jr          $ra
    // 0x801C4A94: nop

    return;
    // 0x801C4A94: nop

;}
RECOMP_FUNC void M24_FUN_801c4a98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4A98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C4A9C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C4AA0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801C4AA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C4AA8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C4AAC: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801C4AB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C4AB4: jal         0x80005E44
    // 0x801C4AB8: addiu       $a1, $a1, -0x2764
    ctx->r5 = ADD32(ctx->r5, -0X2764);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C4AB8: addiu       $a1, $a1, -0x2764
    ctx->r5 = ADD32(ctx->r5, -0X2764);
    after_0:
    // 0x801C4ABC: jal         0x80006214
    // 0x801C4AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C4AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801C4AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C4AC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C4ACC: addiu       $a2, $zero, 0xA7
    ctx->r6 = ADD32(0, 0XA7);
    // 0x801C4AD0: jal         0x8012C89C
    // 0x801C4AD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801C4AD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801C4AD8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801C4ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C4AE0: addiu       $a2, $zero, 0x2DD
    ctx->r6 = ADD32(0, 0X2DD);
    // 0x801C4AE4: lw          $a1, 0x30($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X30);
    // 0x801C4AE8: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x801C4AEC: jal         0x8012CF8C
    // 0x801C4AF0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x801C4AF0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x801C4AF4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C4AF8: lwc1        $f4, 0x90($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801C4AFC: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x801C4B00: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C4B04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C4B08: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801C4B0C: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x801C4B10: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801C4B14: lwc1        $f6, 0x94($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801C4B18: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C4B1C: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C4B20: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801C4B24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4B28: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x801C4B2C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801C4B30: lwc1        $f8, 0x98($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801C4B34: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C4B38: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x801C4B3C: lhu         $t3, 0x9E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X9E);
    // 0x801C4B40: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x801C4B44: bgez        $t3, L_801C4B58
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801C4B48: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C4B58;
    }
    // 0x801C4B48: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C4B4C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C4B50: nop

    // 0x801C4B54: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801C4B58:
    // 0x801C4B58: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801C4B5C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801C4B60: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4B64: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C4B68: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C4B6C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C4B70: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x801C4B74: nop

    // 0x801C4B78: sh          $t5, 0x10($t7)
    MEM_H(0X10, ctx->r15) = ctx->r13;
    // 0x801C4B7C: lhu         $t8, 0xAC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XAC);
    // 0x801C4B80: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x801C4B84: bgez        $t8, L_801C4B98
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801C4B88: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C4B98;
    }
    // 0x801C4B88: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C4B8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C4B90: nop

    // 0x801C4B94: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_801C4B98:
    // 0x801C4B98: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C4B9C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801C4BA0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4BA4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C4BA8: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C4BAC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C4BB0: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x801C4BB4: nop

    // 0x801C4BB8: sh          $t0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r8;
    // 0x801C4BBC: lhu         $t3, 0x9C($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X9C);
    // 0x801C4BC0: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x801C4BC4: bgez        $t3, L_801C4BD8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801C4BC8: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C4BD8;
    }
    // 0x801C4BC8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C4BCC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C4BD0: nop

    // 0x801C4BD4: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801C4BD8:
    // 0x801C4BD8: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801C4BDC: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801C4BE0: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x801C4BE4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C4BE8: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x801C4BEC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4BF0: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C4BF4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C4BF8: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x801C4BFC: nop

    // 0x801C4C00: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x801C4C04: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801C4C08: lbu         $t8, 0xA0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XA0);
    // 0x801C4C0C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C4C10: sb          $t8, 0x48($t1)
    MEM_B(0X48, ctx->r9) = ctx->r24;
    // 0x801C4C14: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801C4C18: lbu         $t0, 0xA1($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XA1);
    // 0x801C4C1C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C4C20: sb          $t0, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r8;
    // 0x801C4C24: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801C4C28: lbu         $t4, 0xA2($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XA2);
    // 0x801C4C2C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C4C30: sb          $t4, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r12;
    // 0x801C4C34: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C4C38: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C4C3C: sb          $v1, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r3;
    // 0x801C4C40: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801C4C44: lbu         $t8, 0xA4($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XA4);
    // 0x801C4C48: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C4C4C: sb          $t8, 0x4C($t2)
    MEM_B(0X4C, ctx->r10) = ctx->r24;
    // 0x801C4C50: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801C4C54: lbu         $t0, 0xA5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XA5);
    // 0x801C4C58: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801C4C5C: sb          $t0, 0x4D($t5)
    MEM_B(0X4D, ctx->r13) = ctx->r8;
    // 0x801C4C60: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801C4C64: lbu         $t4, 0xA6($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XA6);
    // 0x801C4C68: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C4C6C: sb          $t4, 0x4E($t7)
    MEM_B(0X4E, ctx->r15) = ctx->r12;
    // 0x801C4C70: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801C4C74: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C4C78: sb          $v1, 0x4F($t1)
    MEM_B(0X4F, ctx->r9) = ctx->r3;
    // 0x801C4C7C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801C4C80: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x801C4C84: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x801C4C88: ori         $t3, $t2, 0x300
    ctx->r11 = ctx->r10 | 0X300;
    // 0x801C4C8C: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x801C4C90: lbu         $t0, 0xA3($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XA3);
    // 0x801C4C94: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801C4C98: bgez        $t0, L_801C4CAC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801C4C9C: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C4CAC;
    }
    // 0x801C4C9C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C4CA0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C4CA4: nop

    // 0x801C4CA8: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_801C4CAC:
    // 0x801C4CAC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C4CB0: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801C4CB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C4CB8: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C4CBC: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
    // 0x801C4CC0: lbu         $t4, 0xA7($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XA7);
    // 0x801C4CC4: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x801C4CC8: bgez        $t4, L_801C4CDC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x801C4CCC: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801C4CDC;
    }
    // 0x801C4CCC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C4CD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C4CD4: nop

    // 0x801C4CD8: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801C4CDC:
    // 0x801C4CDC: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801C4CE0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C4CE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C4CE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C4CEC: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C4CF0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C4CF4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C4CF8: swc1        $f16, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f16.u32l;
    // 0x801C4CFC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801C4D00: addiu       $a1, $a1, 0x4D3C
    ctx->r5 = ADD32(ctx->r5, 0X4D3C);
    // 0x801C4D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C4D08: lw          $t8, 0x30($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X30);
    // 0x801C4D0C: swc1        $f18, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f18.u32l;
    // 0x801C4D10: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x801C4D14: lw          $t2, 0xA8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XA8);
    // 0x801C4D18: lw          $t5, 0x30($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X30);
    // 0x801C4D1C: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x801C4D20: jal         0x800058DC
    // 0x801C4D24: sw          $t3, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r11;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_4;
    // 0x801C4D24: sw          $t3, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r11;
    after_4:
    // 0x801C4D28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C4D2C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C4D30: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C4D34: jr          $ra
    // 0x801C4D38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C4D38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c4d3c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c4d3c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4D3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C4D40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C4D44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C4D48: lhu         $v0, 0xB0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XB0);
    // 0x801C4D4C: lhu         $t6, 0xB2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XB2);
    // 0x801C4D50: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C4D54: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x801C4D58: div         $zero, $v0, $t6
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r14)));
    // 0x801C4D5C: sh          $t7, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r15;
    // 0x801C4D60: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x801C4D64: mflo        $v1
    ctx->r3 = lo;
    // 0x801C4D68: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x801C4D6C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801C4D70: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x801C4D74: addu        $a3, $a3, $t0
    ctx->r7 = ADD32(ctx->r7, ctx->r8);
    // 0x801C4D78: lw          $a1, 0x30($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X30);
    // 0x801C4D7C: bne         $t6, $zero, L_801C4D88
    if (ctx->r14 != 0) {
        // 0x801C4D80: nop
    
            goto L_801C4D88;
    }
    // 0x801C4D80: nop

    // 0x801C4D84: break       7
    do_break(2149338500);
L_801C4D88:
    // 0x801C4D88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801C4D8C: bne         $t6, $at, L_801C4DA0
    if (ctx->r14 != ctx->r1) {
        // 0x801C4D90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801C4DA0;
    }
    // 0x801C4D90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C4D94: bne         $v0, $at, L_801C4DA0
    if (ctx->r2 != ctx->r1) {
        // 0x801C4D98: nop
    
            goto L_801C4DA0;
    }
    // 0x801C4D98: nop

    // 0x801C4D9C: break       6
    do_break(2149338524);
L_801C4DA0:
    // 0x801C4DA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C4DA4: lw          $a3, -0x5C84($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5C84);
    // 0x801C4DA8: addiu       $a2, $zero, 0x2DD
    ctx->r6 = ADD32(0, 0X2DD);
    // 0x801C4DAC: jal         0x8012CF8C
    // 0x801C4DB0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801C4DB0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x801C4DB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C4DB8: lhu         $t1, 0xB0($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0XB0);
    // 0x801C4DBC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801C4DC0: sh          $t2, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r10;
    // 0x801C4DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C4DC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C4DCC: jr          $ra
    // 0x801C4DD0: nop

    return;
    // 0x801C4DD0: nop

;}
RECOMP_FUNC void M24_FUN_801c4dd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4DD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C4DD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C4DDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C4DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C4DE4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C4DE8: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C4DEC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C4DF0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C4DF4: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x801C4DF8: jal         0x80005670
    // 0x801C4DFC: addiu       $a1, $a1, -0x5B40
    ctx->r5 = ADD32(ctx->r5, -0X5B40);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C4DFC: addiu       $a1, $a1, -0x5B40
    ctx->r5 = ADD32(ctx->r5, -0X5B40);
    after_0:
    // 0x801C4E00: bne         $v0, $zero, L_801C4E10
    if (ctx->r2 != 0) {
        // 0x801C4E04: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C4E10;
    }
    // 0x801C4E04: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C4E08: b           L_801C4E5C
    // 0x801C4E0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C4E5C;
    // 0x801C4E0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C4E10:
    // 0x801C4E10: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C4E14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C4E18: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801C4E1C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801C4E20: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x801C4E24: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801C4E28: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
    // 0x801C4E2C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801C4E30: swc1        $f10, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f10.u32l;
    // 0x801C4E34: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801C4E38: sh          $t6, 0xA0($v1)
    MEM_H(0XA0, ctx->r3) = ctx->r14;
    // 0x801C4E3C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801C4E40: sw          $t7, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->r15;
    // 0x801C4E44: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x801C4E48: sw          $t8, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r24;
    // 0x801C4E4C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801C4E50: sw          $t9, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = ctx->r25;
    // 0x801C4E54: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x801C4E58: sw          $t0, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r8;
L_801C4E5C:
    // 0x801C4E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C4E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C4E64: jr          $ra
    // 0x801C4E68: nop

    return;
    // 0x801C4E68: nop

;}
RECOMP_FUNC void M24_FUN_801c4e6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C4E6C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801C4E70: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C4E74: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C4E78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C4E7C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C4E80: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C4E84: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C4E88: jal         0x80005E44
    // 0x801C4E8C: addiu       $a1, $a1, -0x5B2C
    ctx->r5 = ADD32(ctx->r5, -0X5B2C);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C4E8C: addiu       $a1, $a1, -0x5B2C
    ctx->r5 = ADD32(ctx->r5, -0X5B2C);
    after_0:
    // 0x801C4E90: jal         0x80006214
    // 0x801C4E94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C4E94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C4E98: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C4E9C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C4EA0: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x801C4EA4: lw          $a1, 0x30($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X30);
    // 0x801C4EA8: addiu       $a2, $zero, 0x462
    ctx->r6 = ADD32(0, 0X462);
    // 0x801C4EAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C4EB0: jal         0x8012CF8C
    // 0x801C4EB4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_2;
    // 0x801C4EB4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_2:
    // 0x801C4EB8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C4EBC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C4EC0: lwc1        $f0, -0x2DCC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2DCC);
    // 0x801C4EC4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C4EC8: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x801C4ECC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C4ED0: sw          $zero, 0x30($t8)
    MEM_W(0X30, ctx->r24) = 0;
    // 0x801C4ED4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C4ED8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801C4EDC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C4EE0: lw          $t6, 0x30($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X30);
    // 0x801C4EE4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C4EE8: addiu       $a1, $a1, -0x5C00
    ctx->r5 = ADD32(ctx->r5, -0X5C00);
    // 0x801C4EEC: sw          $zero, 0x28($t6)
    MEM_W(0X28, ctx->r14) = 0;
    // 0x801C4EF0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C4EF4: addiu       $v0, $v0, -0x5C60
    ctx->r2 = ADD32(ctx->r2, -0X5C60);
    // 0x801C4EF8: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C4EFC: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
    // 0x801C4F00: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C4F04: lw          $t6, 0x30($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X30);
    // 0x801C4F08: sh          $zero, 0x2C($t6)
    MEM_H(0X2C, ctx->r14) = 0;
    // 0x801C4F0C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C4F10: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801C4F14: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C4F18: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x801C4F1C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C4F20: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801C4F24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C4F28: lw          $t6, 0x30($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X30);
    // 0x801C4F2C: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x801C4F30: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C4F34: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801C4F38: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C4F3C: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    // 0x801C4F40: lwc1        $f10, 0x9C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x801C4F44: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C4F48: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801C4F4C: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C4F50: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801C4F54: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C4F58: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x801C4F5C: nop

    // 0x801C4F60: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    // 0x801C4F64: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C4F68: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x801C4F6C: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    // 0x801C4F70: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C4F74: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801C4F78: swc1        $f0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f0.u32l;
    // 0x801C4F7C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C4F80: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C4F84: addiu       $t8, $t8, -0x860
    ctx->r24 = ADD32(ctx->r24, -0X860);
    // 0x801C4F88: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x801C4F8C: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x801C4F90: lhu         $a3, 0xA0($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0XA0);
    // 0x801C4F94: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x801C4F98: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x801C4F9C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801C4FA0: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x801C4FA4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801C4FA8: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x801C4FAC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801C4FB0: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x801C4FB4: addiu       $v1, $t0, 0x8
    ctx->r3 = ADD32(ctx->r8, 0X8);
    // 0x801C4FB8: addiu       $a0, $t0, 0x68
    ctx->r4 = ADD32(ctx->r8, 0X68);
L_801C4FBC:
    // 0x801C4FBC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C4FC0: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x801C4FC4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C4FC8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801C4FCC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801C4FD0: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x801C4FD4: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x801C4FD8: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x801C4FDC: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x801C4FE0: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x801C4FE4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801C4FE8: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x801C4FEC: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x801C4FF0: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x801C4FF4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801C4FF8: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x801C4FFC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801C5000: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x801C5004: sw          $t6, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r14;
    // 0x801C5008: bne         $at, $zero, L_801C4FBC
    if (ctx->r1 != 0) {
        // 0x801C500C: sw          $t8, -0x8($a0)
        MEM_W(-0X8, ctx->r4) = ctx->r24;
            goto L_801C4FBC;
    }
    // 0x801C500C: sw          $t8, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->r24;
    // 0x801C5010: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
    // 0x801C5014: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801C5018: addiu       $t1, $ra, 0x210
    ctx->r9 = ADD32(ctx->r31, 0X210);
    // 0x801C501C: addiu       $t2, $ra, 0xD8
    ctx->r10 = ADD32(ctx->r31, 0XD8);
    // 0x801C5020: addiu       $t3, $ra, 0x218
    ctx->r11 = ADD32(ctx->r31, 0X218);
    // 0x801C5024: addiu       $t4, $ra, 0xE0
    ctx->r12 = ADD32(ctx->r31, 0XE0);
    // 0x801C5028: addiu       $t5, $ra, 0x220
    ctx->r13 = ADD32(ctx->r31, 0X220);
    // 0x801C502C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801C5030: lui         $ra, 0x801E
    ctx->r31 = S32(0X801E << 16);
    // 0x801C5034: addiu       $a3, $t0, 0x208
    ctx->r7 = ADD32(ctx->r8, 0X208);
    // 0x801C5038: addiu       $a2, $t0, 0xC8
    ctx->r6 = ADD32(ctx->r8, 0XC8);
    // 0x801C503C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801C5040: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C5044: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C5048: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C504C: addiu       $v0, $v0, -0x5BE8
    ctx->r2 = ADD32(ctx->r2, -0X5BE8);
    // 0x801C5050: addiu       $a1, $a1, -0x5BF0
    ctx->r5 = ADD32(ctx->r5, -0X5BF0);
    // 0x801C5054: addiu       $a0, $a0, -0x5BF8
    ctx->r4 = ADD32(ctx->r4, -0X5BF8);
    // 0x801C5058: addiu       $v1, $v1, -0x5C00
    ctx->r3 = ADD32(ctx->r3, -0X5C00);
    // 0x801C505C: addiu       $t0, $t0, 0xD0
    ctx->r8 = ADD32(ctx->r8, 0XD0);
    // 0x801C5060: addiu       $ra, $ra, -0x5AA8
    ctx->r31 = ADD32(ctx->r31, -0X5AA8);
    // 0x801C5064: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_801C5068:
    // 0x801C5068: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801C506C: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x801C5070: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801C5074: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x801C5078: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801C507C: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x801C5080: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x801C5084: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x801C5088: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x801C508C: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x801C5090: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x801C5094: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x801C5098: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801C509C: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x801C50A0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801C50A4: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x801C50A8: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x801C50AC: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x801C50B0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x801C50B4: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x801C50B8: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x801C50BC: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x801C50C0: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x801C50C4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801C50C8: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x801C50CC: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x801C50D0: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x801C50D4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C50D8: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x801C50DC: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x801C50E0: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x801C50E4: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x801C50E8: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x801C50EC: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x801C50F0: addiu       $t0, $t0, 0x20
    ctx->r8 = ADD32(ctx->r8, 0X20);
    // 0x801C50F4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x801C50F8: addiu       $t1, $t1, 0x20
    ctx->r9 = ADD32(ctx->r9, 0X20);
    // 0x801C50FC: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x801C5100: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x801C5104: addiu       $t3, $t3, 0x20
    ctx->r11 = ADD32(ctx->r11, 0X20);
    // 0x801C5108: addiu       $t4, $t4, 0x20
    ctx->r12 = ADD32(ctx->r12, 0X20);
    // 0x801C510C: addiu       $t5, $t5, 0x20
    ctx->r13 = ADD32(ctx->r13, 0X20);
    // 0x801C5110: sw          $t6, -0x1C($t5)
    MEM_W(-0X1C, ctx->r13) = ctx->r14;
    // 0x801C5114: bne         $v0, $ra, L_801C5068
    if (ctx->r2 != ctx->r31) {
        // 0x801C5118: sw          $t8, -0x20($t5)
        MEM_W(-0X20, ctx->r13) = ctx->r24;
            goto L_801C5068;
    }
    // 0x801C5118: sw          $t8, -0x20($t5)
    MEM_W(-0X20, ctx->r13) = ctx->r24;
    // 0x801C511C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x801C5120: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801C5124: addiu       $t6, $t6, -0x860
    ctx->r14 = ADD32(ctx->r14, -0X860);
    // 0x801C5128: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x801C512C: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x801C5130: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801C5134: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x801C5138: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801C513C: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x801C5140: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801C5144: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x801C5148: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x801C514C: ori         $v1, $v1, 0x600C
    ctx->r3 = ctx->r3 | 0X600C;
    // 0x801C5150: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801C5154: addiu       $t9, $v0, 0x68
    ctx->r25 = ADD32(ctx->r2, 0X68);
    // 0x801C5158: sw          $t8, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->r24;
    // 0x801C515C: sw          $v1, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->r3;
    // 0x801C5160: sw          $t9, 0x214($v0)
    MEM_W(0X214, ctx->r2) = ctx->r25;
    // 0x801C5164: sw          $v1, 0x210($v0)
    MEM_W(0X210, ctx->r2) = ctx->r3;
    // 0x801C5168: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801C516C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C5170: addiu       $t7, $v0, 0xC8
    ctx->r15 = ADD32(ctx->r2, 0XC8);
    // 0x801C5174: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C5178: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x801C517C: addiu       $a1, $a1, 0x51A0
    ctx->r5 = ADD32(ctx->r5, 0X51A0);
    // 0x801C5180: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C5184: jal         0x800058DC
    // 0x801C5188: sw          $t7, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r15;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_3;
    // 0x801C5188: sw          $t7, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r15;
    after_3:
    // 0x801C518C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C5190: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C5194: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C5198: jr          $ra
    // 0x801C519C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801C519C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c51a0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c51a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C51A0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801C51A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C51A8: lhu         $v1, 0xA0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XA0);
    // 0x801C51AC: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801C51B0: addiu       $t7, $t7, -0x860
    ctx->r15 = ADD32(ctx->r15, -0X860);
    // 0x801C51B4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x801C51B8: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801C51BC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801C51C0: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x801C51C4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801C51C8: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x801C51CC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801C51D0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801C51D4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801C51D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C51DC: bnel        $t8, $zero, L_801C5204
    if (ctx->r24 != 0) {
        // 0x801C51E0: sw          $zero, 0x0($v0)
        MEM_W(0X0, ctx->r2) = 0;
            goto L_801C5204;
    }
    goto skip_0;
    // 0x801C51E0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    skip_0:
    // 0x801C51E4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801C51E8: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x801C51EC: addiu       $t0, $v0, 0x208
    ctx->r8 = ADD32(ctx->r2, 0X208);
    // 0x801C51F0: addiu       $v1, $v0, 0x68
    ctx->r3 = ADD32(ctx->r2, 0X68);
    // 0x801C51F4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C51F8: b           L_801C5218
    // 0x801C51FC: sw          $t0, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->r8;
        goto L_801C5218;
    // 0x801C51FC: sw          $t0, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->r8;
    // 0x801C5200: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_801C5204:
    // 0x801C5204: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x801C5208: addiu       $t3, $v0, 0xC8
    ctx->r11 = ADD32(ctx->r2, 0XC8);
    // 0x801C520C: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x801C5210: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C5214: sw          $t3, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r11;
L_801C5218:
    // 0x801C5218: lw          $t6, 0xAC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XAC);
    // 0x801C521C: lw          $v0, 0xA4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA4);
    // 0x801C5220: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x801C5224: lw          $t7, 0xB0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB0);
    // 0x801C5228: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801C522C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801C5230: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x801C5234: jalr        $v0
    // 0x801C5238: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x801C5238: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    after_0:
    // 0x801C523C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x801C5240: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x801C5244: jalr        $t9
    // 0x801C5248: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x801C5248: nop

    after_1:
    // 0x801C524C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801C5250: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x801C5254: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x801C5258: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801C525C: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x801C5260: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x801C5264: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    // 0x801C5268: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x801C526C: jalr        $t9
    // 0x801C5270: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x801C5270: nop

    after_2:
    // 0x801C5274: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801C5278: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x801C527C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x801C5280: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x801C5284: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801C5288: addiu       $t2, $sp, 0x1C
    ctx->r10 = ADD32(ctx->r29, 0X1C);
    // 0x801C528C: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x801C5290: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x801C5294: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801C5298: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C529C: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x801C52A0: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x801C52A4: sw          $t3, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r11;
    // 0x801C52A8: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x801C52AC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C52B0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C52B4: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x801C52B8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C52BC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801C52C0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801C52C4: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x801C52C8: nop

    // 0x801C52CC: sh          $t8, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r24;
    // 0x801C52D0: lwc1        $f18, 0x94($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801C52D4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801C52D8: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x801C52DC: nop

    // 0x801C52E0: sh          $t0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r8;
    // 0x801C52E4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801C52E8: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801C52EC: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x801C52F0: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x801C52F4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801C52F8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C52FC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801C5300: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x801C5304: nop

    // 0x801C5308: sh          $t3, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r11;
    // 0x801C530C: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x801C5310: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C5314: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C5318: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x801C531C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C5320: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801C5324: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801C5328: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x801C532C: nop

    // 0x801C5330: sh          $t8, 0x50($v1)
    MEM_H(0X50, ctx->r3) = ctx->r24;
    // 0x801C5334: lwc1        $f18, 0x94($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801C5338: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801C533C: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x801C5340: nop

    // 0x801C5344: sh          $t0, 0x52($v1)
    MEM_H(0X52, ctx->r3) = ctx->r8;
    // 0x801C5348: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801C534C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C5350: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x801C5354: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x801C5358: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801C535C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C5360: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801C5364: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x801C5368: nop

    // 0x801C536C: sh          $t3, 0x54($v1)
    MEM_H(0X54, ctx->r3) = ctx->r11;
    // 0x801C5370: lw          $t5, 0x24($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X24);
    // 0x801C5374: lwc1        $f4, 0x90($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X90);
    // 0x801C5378: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801C537C: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801C5380: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C5384: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x801C5388: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801C538C: swc1        $f8, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f8.u32l;
    // 0x801C5390: lw          $t1, 0x24($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X24);
    // 0x801C5394: lwc1        $f10, 0x94($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X94);
    // 0x801C5398: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801C539C: lw          $t0, 0x2C($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X2C);
    // 0x801C53A0: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x801C53A4: lwc1        $f16, 0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801C53A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801C53AC: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
    // 0x801C53B0: lw          $t4, 0x24($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X24);
    // 0x801C53B4: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
    // 0x801C53B8: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x801C53BC: lw          $t3, 0x2C($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X2C);
    // 0x801C53C0: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C53C4: lwc1        $f6, 0xC($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XC);
    // 0x801C53C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801C53CC: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x801C53D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C53D4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801C53D8: jr          $ra
    // 0x801C53DC: nop

    return;
    // 0x801C53DC: nop

;}
RECOMP_FUNC void M24_FUN_801c53e0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C53E0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C53E4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801C53E8: swc1        $f12, -0x5B08($at)
    MEM_W(-0X5B08, ctx->r1) = ctx->f12.u32l;
    // 0x801C53EC: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x801C53F0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C53F4: swc1        $f14, -0x5B04($at)
    MEM_W(-0X5B04, ctx->r1) = ctx->f14.u32l;
    // 0x801C53F8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C53FC: lui         $t6, 0x7754
    ctx->r14 = S32(0X7754 << 16);
    // 0x801C5400: swc1        $f4, -0x5B00($at)
    MEM_W(-0X5B00, ctx->r1) = ctx->f4.u32l;
    // 0x801C5404: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C5408: ori         $t6, $t6, 0x3897
    ctx->r14 = ctx->r14 | 0X3897;
    // 0x801C540C: jr          $ra
    // 0x801C5410: sw          $t6, -0x5AFC($at)
    MEM_W(-0X5AFC, ctx->r1) = ctx->r14;
    return;
    // 0x801C5410: sw          $t6, -0x5AFC($at)
    MEM_W(-0X5AFC, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c5414(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c5414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C5418: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C541C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C5420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C5424: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C5428: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C542C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C5430: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C5434: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    // 0x801C5438: jal         0x80005670
    // 0x801C543C: addiu       $a1, $a1, -0x5B1C
    ctx->r5 = ADD32(ctx->r5, -0X5B1C);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C543C: addiu       $a1, $a1, -0x5B1C
    ctx->r5 = ADD32(ctx->r5, -0X5B1C);
    after_0:
    // 0x801C5440: bne         $v0, $zero, L_801C5450
    if (ctx->r2 != 0) {
        // 0x801C5444: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C5450;
    }
    // 0x801C5444: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C5448: b           L_801C5634
    // 0x801C544C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C5634;
    // 0x801C544C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C5450:
    // 0x801C5450: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C5454: lwc1        $f0, -0x5B08($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5B08);
    // 0x801C5458: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C545C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C5460: addiu       $a0, $a0, -0x5B00
    ctx->r4 = ADD32(ctx->r4, -0X5B00);
    // 0x801C5464: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x801C5468: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801C546C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C5470: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801C5474: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x801C5478: swc1        $f16, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f16.u32l;
    // 0x801C547C: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C5480: swc1        $f18, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f18.u32l;
    // 0x801C5484: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C5488: lwc1        $f2, -0x5B04($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5B04);
    // 0x801C548C: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801C5490: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801C5494: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x801C5498: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C549C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C54A0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801C54A4: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x801C54A8: swc1        $f16, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f16.u32l;
    // 0x801C54AC: lhu         $t6, 0x32($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X32);
    // 0x801C54B0: sh          $t6, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = ctx->r14;
    // 0x801C54B4: lhu         $t7, 0x2A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X2A);
    // 0x801C54B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C54BC: sh          $t7, 0x9E($v0)
    MEM_H(0X9E, ctx->r2) = ctx->r15;
    // 0x801C54C0: lhu         $t8, 0x2E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2E);
    // 0x801C54C4: sh          $t8, 0xAC($v0)
    MEM_H(0XAC, ctx->r2) = ctx->r24;
    // 0x801C54C8: lbu         $t9, 0x3F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3F);
    // 0x801C54CC: sb          $t9, 0xA0($v0)
    MEM_B(0XA0, ctx->r2) = ctx->r25;
    // 0x801C54D0: lbu         $t0, 0x43($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X43);
    // 0x801C54D4: sb          $t0, 0xA1($v0)
    MEM_B(0XA1, ctx->r2) = ctx->r8;
    // 0x801C54D8: lbu         $t1, 0x47($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X47);
    // 0x801C54DC: sb          $t1, 0xA2($v0)
    MEM_B(0XA2, ctx->r2) = ctx->r9;
    // 0x801C54E0: lbu         $t2, 0x4B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4B);
    // 0x801C54E4: sb          $t2, 0xA4($v0)
    MEM_B(0XA4, ctx->r2) = ctx->r10;
    // 0x801C54E8: lbu         $t3, 0x4F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4F);
    // 0x801C54EC: sb          $t3, 0xA5($v1)
    MEM_B(0XA5, ctx->r3) = ctx->r11;
    // 0x801C54F0: lbu         $t4, 0x53($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X53);
    // 0x801C54F4: sb          $t4, 0xA6($v1)
    MEM_B(0XA6, ctx->r3) = ctx->r12;
    // 0x801C54F8: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801C54FC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C5500: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801C5504: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C5508: nop

    // 0x801C550C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801C5510: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C5514: nop

    // 0x801C5518: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801C551C: beql        $t6, $zero, L_801C556C
    if (ctx->r14 == 0) {
        // 0x801C5520: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_801C556C;
    }
    goto skip_0;
    // 0x801C5520: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801C5524: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C5528: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C552C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C5530: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C5534: nop

    // 0x801C5538: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801C553C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C5540: nop

    // 0x801C5544: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801C5548: bne         $t6, $zero, L_801C5560
    if (ctx->r14 != 0) {
        // 0x801C554C: nop
    
            goto L_801C5560;
    }
    // 0x801C554C: nop

    // 0x801C5550: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x801C5554: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C5558: b           L_801C5578
    // 0x801C555C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801C5578;
    // 0x801C555C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801C5560:
    // 0x801C5560: b           L_801C5578
    // 0x801C5564: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801C5578;
    // 0x801C5564: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801C5568: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_801C556C:
    // 0x801C556C: nop

    // 0x801C5570: bltz        $t6, L_801C5560
    if (SIGNED(ctx->r14) < 0) {
        // 0x801C5574: nop
    
            goto L_801C5560;
    }
    // 0x801C5574: nop

L_801C5578:
    // 0x801C5578: sb          $t6, 0xA3($v1)
    MEM_B(0XA3, ctx->r3) = ctx->r14;
    // 0x801C557C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801C5580: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801C5584: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C5588: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C558C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801C5590: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801C5594: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C5598: nop

    // 0x801C559C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C55A0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C55A4: nop

    // 0x801C55A8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801C55AC: beql        $t8, $zero, L_801C55FC
    if (ctx->r24 == 0) {
        // 0x801C55B0: mfc1        $t8, $f16
        ctx->r24 = (int32_t)ctx->f16.u32l;
            goto L_801C55FC;
    }
    goto skip_1;
    // 0x801C55B0: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x801C55B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C55B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C55BC: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801C55C0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C55C4: nop

    // 0x801C55C8: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801C55CC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C55D0: nop

    // 0x801C55D4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801C55D8: bne         $t8, $zero, L_801C55F0
    if (ctx->r24 != 0) {
        // 0x801C55DC: nop
    
            goto L_801C55F0;
    }
    // 0x801C55DC: nop

    // 0x801C55E0: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x801C55E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C55E8: b           L_801C5608
    // 0x801C55EC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_801C5608;
    // 0x801C55EC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_801C55F0:
    // 0x801C55F0: b           L_801C5608
    // 0x801C55F4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_801C5608;
    // 0x801C55F4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801C55F8: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
L_801C55FC:
    // 0x801C55FC: nop

    // 0x801C5600: bltz        $t8, L_801C55F0
    if (SIGNED(ctx->r24) < 0) {
        // 0x801C5604: nop
    
            goto L_801C55F0;
    }
    // 0x801C5604: nop

L_801C5608:
    // 0x801C5608: sb          $t8, 0xA7($v1)
    MEM_B(0XA7, ctx->r3) = ctx->r24;
    // 0x801C560C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x801C5610: sb          $zero, 0xA9($v1)
    MEM_B(0XA9, ctx->r3) = 0;
    // 0x801C5614: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801C5618: sb          $t9, 0xA8($v1)
    MEM_B(0XA8, ctx->r3) = ctx->r25;
    // 0x801C561C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x801C5620: sh          $zero, 0xB0($v1)
    MEM_H(0XB0, ctx->r3) = 0;
    // 0x801C5624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C5628: sb          $t0, 0xAA($v1)
    MEM_B(0XAA, ctx->r3) = ctx->r8;
    // 0x801C562C: lhu         $t1, 0x56($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X56);
    // 0x801C5630: sh          $t1, 0xB2($v1)
    MEM_H(0XB2, ctx->r3) = ctx->r9;
L_801C5634:
    // 0x801C5634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C5638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C563C: jr          $ra
    // 0x801C5640: nop

    return;
    // 0x801C5640: nop

;}
RECOMP_FUNC void M24_FUN_801c5644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5644: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C5648: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C564C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801C5650: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C5654: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C5658: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x801C565C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C5660: jal         0x80005E44
    // 0x801C5664: addiu       $a1, $a1, -0x2764
    ctx->r5 = ADD32(ctx->r5, -0X2764);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C5664: addiu       $a1, $a1, -0x2764
    ctx->r5 = ADD32(ctx->r5, -0X2764);
    after_0:
    // 0x801C5668: jal         0x80006214
    // 0x801C566C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C566C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801C5670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C5674: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801C5678: addiu       $a2, $zero, 0xA7
    ctx->r6 = ADD32(0, 0XA7);
    // 0x801C567C: jal         0x8012C89C
    // 0x801C5680: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(0x8012C89C)(rdram, ctx);
        goto after_2;
    // 0x801C5680: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801C5684: lbu         $v0, 0xA8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA8);
    // 0x801C5688: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C568C: beql        $v0, $zero, L_801C56B0
    if (ctx->r2 == 0) {
        // 0x801C5690: lw          $t6, 0x0($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X0);
            goto L_801C56B0;
    }
    goto skip_0;
    // 0x801C5690: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x801C5694: beq         $v0, $at, L_801C56D0
    if (ctx->r2 == ctx->r1) {
        // 0x801C5698: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801C56D0;
    }
    // 0x801C5698: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C569C: beql        $v0, $at, L_801C56F8
    if (ctx->r2 == ctx->r1) {
        // 0x801C56A0: lw          $t8, 0x0($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X0);
            goto L_801C56F8;
    }
    goto skip_1;
    // 0x801C56A0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x801C56A4: b           L_801C5714
    // 0x801C56A8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
        goto L_801C5714;
    // 0x801C56A8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801C56AC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
L_801C56B0:
    // 0x801C56B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C56B4: addiu       $a2, $zero, 0x43C
    ctx->r6 = ADD32(0, 0X43C);
    // 0x801C56B8: lw          $a1, 0x30($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X30);
    // 0x801C56BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C56C0: jal         0x8012CF8C
    // 0x801C56C4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x801C56C4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x801C56C8: b           L_801C5714
    // 0x801C56CC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
        goto L_801C5714;
    // 0x801C56CC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
L_801C56D0:
    // 0x801C56D0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C56D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C56D8: addiu       $a2, $zero, 0x43C
    ctx->r6 = ADD32(0, 0X43C);
    // 0x801C56DC: lw          $a1, 0x30($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X30);
    // 0x801C56E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x801C56E4: jal         0x8012CF8C
    // 0x801C56E8: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_4;
    // 0x801C56E8: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_4:
    // 0x801C56EC: b           L_801C5714
    // 0x801C56F0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
        goto L_801C5714;
    // 0x801C56F0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801C56F4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
L_801C56F8:
    // 0x801C56F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C56FC: addiu       $a2, $zero, 0x43D
    ctx->r6 = ADD32(0, 0X43D);
    // 0x801C5700: lw          $a1, 0x30($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X30);
    // 0x801C5704: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C5708: jal         0x8012CF8C
    // 0x801C570C: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_5;
    // 0x801C570C: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_5:
    // 0x801C5710: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
L_801C5714:
    // 0x801C5714: lwc1        $f4, 0x90($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X90);
    // 0x801C5718: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x801C571C: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C5720: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C5724: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801C5728: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x801C572C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801C5730: lwc1        $f6, 0x94($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X94);
    // 0x801C5734: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801C5738: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C573C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801C5740: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5744: swc1        $f6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f6.u32l;
    // 0x801C5748: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801C574C: lwc1        $f8, 0x98($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X98);
    // 0x801C5750: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C5754: swc1        $f8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f8.u32l;
    // 0x801C5758: lhu         $t5, 0x9E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X9E);
    // 0x801C575C: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x801C5760: bgez        $t5, L_801C5774
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801C5764: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C5774;
    }
    // 0x801C5764: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C5768: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C576C: nop

    // 0x801C5770: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801C5774:
    // 0x801C5774: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801C5778: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801C577C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C5780: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C5784: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C5788: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C578C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x801C5790: nop

    // 0x801C5794: sh          $t7, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r15;
    // 0x801C5798: lhu         $t0, 0xAC($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XAC);
    // 0x801C579C: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801C57A0: bgez        $t0, L_801C57B4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801C57A4: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C57B4;
    }
    // 0x801C57A4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C57A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C57AC: nop

    // 0x801C57B0: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_801C57B4:
    // 0x801C57B4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C57B8: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801C57BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C57C0: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C57C4: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C57C8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C57CC: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x801C57D0: nop

    // 0x801C57D4: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    // 0x801C57D8: lhu         $t5, 0x9C($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X9C);
    // 0x801C57DC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x801C57E0: bgez        $t5, L_801C57F4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801C57E4: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C57F4;
    }
    // 0x801C57E4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C57E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C57EC: nop

    // 0x801C57F0: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801C57F4:
    // 0x801C57F4: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801C57F8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C57FC: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x801C5800: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C5804: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C5808: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C580C: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801C5810: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801C5814: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x801C5818: nop

    // 0x801C581C: sh          $t8, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r24;
    // 0x801C5820: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801C5824: lbu         $t0, 0xA0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XA0);
    // 0x801C5828: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801C582C: sb          $t0, 0x48($t3)
    MEM_B(0X48, ctx->r11) = ctx->r8;
    // 0x801C5830: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801C5834: lbu         $t2, 0xA1($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XA1);
    // 0x801C5838: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C583C: sb          $t2, 0x49($t5)
    MEM_B(0X49, ctx->r13) = ctx->r10;
    // 0x801C5840: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C5844: lbu         $t6, 0xA2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA2);
    // 0x801C5848: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C584C: sb          $t6, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = ctx->r14;
    // 0x801C5850: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801C5854: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C5858: sb          $v1, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r3;
    // 0x801C585C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801C5860: lbu         $t0, 0xA4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XA4);
    // 0x801C5864: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C5868: sb          $t0, 0x4C($t4)
    MEM_B(0X4C, ctx->r12) = ctx->r8;
    // 0x801C586C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801C5870: lbu         $t2, 0xA5($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XA5);
    // 0x801C5874: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x801C5878: sb          $t2, 0x4D($t7)
    MEM_B(0X4D, ctx->r15) = ctx->r10;
    // 0x801C587C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801C5880: lbu         $t6, 0xA6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA6);
    // 0x801C5884: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C5888: sb          $t6, 0x4E($t9)
    MEM_B(0X4E, ctx->r25) = ctx->r14;
    // 0x801C588C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801C5890: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x801C5894: sb          $v1, 0x4F($t3)
    MEM_B(0X4F, ctx->r11) = ctx->r3;
    // 0x801C5898: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x801C589C: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x801C58A0: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x801C58A4: ori         $t5, $t4, 0x300
    ctx->r13 = ctx->r12 | 0X300;
    // 0x801C58A8: sw          $t5, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r13;
    // 0x801C58AC: lbu         $t2, 0xA3($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XA3);
    // 0x801C58B0: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x801C58B4: bgez        $t2, L_801C58C8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801C58B8: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C58C8;
    }
    // 0x801C58B8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C58BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C58C0: nop

    // 0x801C58C4: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_801C58C8:
    // 0x801C58C8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C58CC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801C58D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C58D4: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x801C58D8: swc1        $f4, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f4.u32l;
    // 0x801C58DC: lbu         $t6, 0xA7($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA7);
    // 0x801C58E0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x801C58E4: bgez        $t6, L_801C58F8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C58E8: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801C58F8;
    }
    // 0x801C58E8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801C58EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C58F0: nop

    // 0x801C58F4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801C58F8:
    // 0x801C58F8: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801C58FC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801C5900: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801C5904: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C5908: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C590C: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801C5910: addiu       $t4, $t4, -0x7060
    ctx->r12 = ADD32(ctx->r12, -0X7060);
    // 0x801C5914: swc1        $f16, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f16.u32l;
    // 0x801C5918: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801C591C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801C5920: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x801C5924: lw          $t0, 0x30($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X30);
    // 0x801C5928: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C592C: addiu       $a1, $a1, 0x595C
    ctx->r5 = ADD32(ctx->r5, 0X595C);
    // 0x801C5930: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x801C5934: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801C5938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C593C: lw          $t7, 0x30($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X30);
    // 0x801C5940: jal         0x800058DC
    // 0x801C5944: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_6;
    // 0x801C5944: sw          $t5, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r13;
    after_6:
    // 0x801C5948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C594C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C5950: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C5954: jr          $ra
    // 0x801C5958: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801C5958: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c595c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c595c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C595C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C5960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C5964: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C5968: lbu         $v0, 0xA8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA8);
    // 0x801C596C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C5970: beql        $v0, $zero, L_801C599C
    if (ctx->r2 == 0) {
        // 0x801C5974: lhu         $v0, 0xB0($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0XB0);
            goto L_801C599C;
    }
    goto skip_0;
    // 0x801C5974: lhu         $v0, 0xB0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XB0);
    skip_0:
    // 0x801C5978: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801C597C: beq         $v0, $at, L_801C5A1C
    if (ctx->r2 == ctx->r1) {
            // 0x801C5980: addiu       $a2, $zero, 0x43C
    ctx->r6 = ADD32(0, 0X43C);
    LOOKUP_FUNC(0x801C5A1C)(rdram, ctx);
    return;
    }
    // 0x801C5980: addiu       $a2, $zero, 0x43C
    ctx->r6 = ADD32(0, 0X43C);
    // 0x801C5984: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801C5988: beq         $v0, $at, L_801C5AA0
    if (ctx->r2 == ctx->r1) {
        // 0x801C598C: addiu       $a2, $zero, 0x43D
        ctx->r6 = ADD32(0, 0X43D);
        LOOKUP_FUNC(0x801C5AA0)(rdram, ctx);
        return;
    }
    // 0x801C598C: addiu       $a2, $zero, 0x43D
    ctx->r6 = ADD32(0, 0X43D);
    // 0x801C5990: b           L_801C5B20
    // 0x801C5994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    LOOKUP_FUNC(0x801C5B20)(rdram, ctx);
    return;
    // 0x801C5994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C5998: lhu         $v0, 0xB0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XB0);
L_801C599C:
    // 0x801C599C: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C59A0: addiu       $a2, $zero, 0x43C
    ctx->r6 = ADD32(0, 0X43C);
    // 0x801C59A4: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x801C59A8: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801C59AC: sh          $t6, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r14;
    // 0x801C59B0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801C59B4: mfhi        $v1
    ctx->r3 = hi;
    // 0x801C59B8: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x801C59BC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801C59C0: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x801C59C4: lw          $a3, -0x2E94($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2E94);
    // 0x801C59C8: lw          $a1, 0x30($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X30);
    // 0x801C59CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C59D0: jal         0x8012CF8C
    // 0x801C59D4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801C59D4: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x801C59D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C59DC: lhu         $t0, 0xB0($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0XB0);
    // 0x801C59E0: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x801C59E4: bnel        $at, $zero, L_801C5B20
    if (ctx->r1 != 0) {
        // 0x801C59E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
        LOOKUP_FUNC(0x801C5B20)(rdram, ctx);
        return;
    }
    goto skip_1;
    // 0x801C59E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801C59EC: lbu         $t1, 0xA9($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XA9);
    // 0x801C59F0: lbu         $t4, 0xAA($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0XAA);
    // 0x801C59F4: sh          $zero, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = 0;
    // 0x801C59F8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801C59FC: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c5a00(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c5a00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5A00: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x801C5A04: bne         $at, $zero, L_801C5B1C
    if (ctx->r1 != 0) {
        // 0x801C5A08: sb          $t2, 0xA9($a0)
        MEM_B(0XA9, ctx->r4) = ctx->r10;
            goto L_801C5B1C;
    }
    // 0x801C5A08: sb          $t2, 0xA9($a0)
    MEM_B(0XA9, ctx->r4) = ctx->r10;
    // 0x801C5A0C: jal         0x80005700
    // 0x801C5A10: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801C5A10: nop

    after_0:
    // 0x801C5A14: b           L_801C5B20
    // 0x801C5A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C5B20;
    // 0x801C5A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C5A1C: lhu         $v0, 0xB0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XB0);
    // 0x801C5A20: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C5A24: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C5A28: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x801C5A2C: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x801C5A30: sh          $t5, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r13;
    // 0x801C5A34: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x801C5A38: mfhi        $v1
    ctx->r3 = hi;
    // 0x801C5A3C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x801C5A40: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801C5A44: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x801C5A48: lw          $a3, -0x2E88($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2E88);
    // 0x801C5A4C: lw          $a1, 0x30($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X30);
    // 0x801C5A50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C5A54: jal         0x8012CF8C
    // 0x801C5A58: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_1;
    // 0x801C5A58: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_1:
    // 0x801C5A5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C5A60: lhu         $t9, 0xB0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0XB0);
    // 0x801C5A64: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x801C5A68: bnel        $at, $zero, L_801C5B20
    if (ctx->r1 != 0) {
        // 0x801C5A6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C5B20;
    }
    goto skip_0;
    // 0x801C5A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801C5A70: lbu         $t0, 0xA9($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XA9);
    // 0x801C5A74: lbu         $t3, 0xAA($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XAA);
    // 0x801C5A78: sh          $zero, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = 0;
    // 0x801C5A7C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801C5A80: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801C5A84: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801C5A88: bne         $at, $zero, L_801C5B1C
    if (ctx->r1 != 0) {
        // 0x801C5A8C: sb          $t1, 0xA9($a0)
        MEM_B(0XA9, ctx->r4) = ctx->r9;
            goto L_801C5B1C;
    }
    // 0x801C5A8C: sb          $t1, 0xA9($a0)
    MEM_B(0XA9, ctx->r4) = ctx->r9;
    // 0x801C5A90: jal         0x80005700
    // 0x801C5A94: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_2;
    // 0x801C5A94: nop

    after_2:
    // 0x801C5A98: b           L_801C5B20
    // 0x801C5A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801C5B20;
    // 0x801C5A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C5AA0: lhu         $v0, 0xB0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XB0);
    // 0x801C5AA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801C5AA8: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C5AAC: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x801C5AB0: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x801C5AB4: sh          $t4, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r12;
    // 0x801C5AB8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x801C5ABC: mfhi        $v1
    ctx->r3 = hi;
    // 0x801C5AC0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x801C5AC4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801C5AC8: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x801C5ACC: lw          $a3, -0x2E7C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2E7C);
    // 0x801C5AD0: lw          $a1, 0x30($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X30);
    // 0x801C5AD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C5AD8: jal         0x8012CF8C
    // 0x801C5ADC: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_3;
    // 0x801C5ADC: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_3:
    // 0x801C5AE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C5AE4: lhu         $t8, 0xB0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XB0);
    // 0x801C5AE8: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x801C5AEC: bnel        $at, $zero, L_801C5B20
    if (ctx->r1 != 0) {
        // 0x801C5AF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C5B20;
    }
    goto skip_1;
    // 0x801C5AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801C5AF4: lbu         $t9, 0xA9($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XA9);
    // 0x801C5AF8: lbu         $t2, 0xAA($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XAA);
    // 0x801C5AFC: sh          $zero, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = 0;
    // 0x801C5B00: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x801C5B04: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x801C5B08: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x801C5B0C: bne         $at, $zero, L_801C5B1C
    if (ctx->r1 != 0) {
        // 0x801C5B10: sb          $t0, 0xA9($a0)
        MEM_B(0XA9, ctx->r4) = ctx->r8;
            goto L_801C5B1C;
    }
    // 0x801C5B10: sb          $t0, 0xA9($a0)
    MEM_B(0XA9, ctx->r4) = ctx->r8;
    // 0x801C5B14: jal         0x80005700
    // 0x801C5B18: nop

    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x801C5B18: nop

    after_4:
L_801C5B1C:
    // 0x801C5B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C5B20:
    // 0x801C5B20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C5B24: jr          $ra
    // 0x801C5B28: nop

    return;
    // 0x801C5B28: nop

;}
RECOMP_FUNC void M24_FUN_801c5b2c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5B2C: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x801C5B30: lw          $t6, -0x32B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X32B8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c5b34(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c5b34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5B34: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C5B38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C5B3C: bne         $t6, $zero, L_801C5BC4
    if (ctx->r14 != 0) {
        // 0x801C5B40: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801C5BC4;
    }
    // 0x801C5B40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801C5B44: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x801C5B48: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x801C5B4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C5B50: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801C5B54: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801C5B58: sh          $t7, 0xA6($v0)
    MEM_H(0XA6, ctx->r2) = ctx->r15;
    // 0x801C5B5C: sh          $t8, 0xA4($v0)
    MEM_H(0XA4, ctx->r2) = ctx->r24;
    // 0x801C5B60: addiu       $t9, $t9, -0x5AE8
    ctx->r25 = ADD32(ctx->r25, -0X5AE8);
    // 0x801C5B64: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801C5B68: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x801C5B6C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C5B70: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x801C5B74: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801C5B78: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x801C5B7C: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801C5B80: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x801C5B84: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x801C5B88: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
    // 0x801C5B8C: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x801C5B90: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x801C5B94: jal         0x80005670
    // 0x801C5B98: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C5B98: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C5B9C: bne         $v0, $zero, L_801C5BAC
    if (ctx->r2 != 0) {
        // 0x801C5BA0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C5BAC;
    }
    // 0x801C5BA0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C5BA4: b           L_801C5BC4
    // 0x801C5BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C5BC4;
    // 0x801C5BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C5BAC:
    // 0x801C5BAC: sh          $zero, 0x90($v1)
    MEM_H(0X90, ctx->r3) = 0;
    // 0x801C5BB0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801C5BB4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C5BB8: sw          $t2, -0x5AEC($at)
    MEM_W(-0X5AEC, ctx->r1) = ctx->r10;
    // 0x801C5BBC: b           L_801C5BC4
    // 0x801C5BC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801C5BC4;
    // 0x801C5BC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801C5BC4:
    // 0x801C5BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C5BC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801C5BCC: jr          $ra
    // 0x801C5BD0: nop

    return;
    // 0x801C5BD0: nop

;}
RECOMP_FUNC void M24_FUN_801c5bd4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5BD4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C5BD8: lw          $v0, -0x5AEC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5AEC);
    // 0x801C5BDC: jr          $ra
    // 0x801C5BE0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x801C5BE0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c5be4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c5be4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C5BE4: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x801C5BE8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801C5BEC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x801C5BF0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x801C5BF4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801C5BF8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801C5BFC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801C5C00: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801C5C04: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801C5C08: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801C5C0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C5C10: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    // 0x801C5C14: jal         0x80001060
    // 0x801C5C18: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_0;
    // 0x801C5C18: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    after_0:
    // 0x801C5C1C: beq         $v0, $zero, L_801C5C48
    if (ctx->r2 == 0) {
        // 0x801C5C20: nop
    
            goto L_801C5C48;
    }
    // 0x801C5C20: nop

    // 0x801C5C24: jal         0x8001F290
    // 0x801C5C28: addiu       $a0, $zero, 0x3360
    ctx->r4 = ADD32(0, 0X3360);
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_1;
    // 0x801C5C28: addiu       $a0, $zero, 0x3360
    ctx->r4 = ADD32(0, 0X3360);
    after_1:
    // 0x801C5C2C: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801C5C30: addiu       $a2, $a2, -0x5AF0
    ctx->r6 = ADD32(ctx->r6, -0X5AF0);
    // 0x801C5C34: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x801C5C38: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C5C3C: sw          $v0, -0x5AF4($at)
    MEM_W(-0X5AF4, ctx->r1) = ctx->r2;
    // 0x801C5C40: b           L_801C5C68
    // 0x801C5C44: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_801C5C68;
    // 0x801C5C44: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801C5C48:
    // 0x801C5C48: jal         0x8001F290
    // 0x801C5C4C: addiu       $a0, $zero, 0xCD8
    ctx->r4 = ADD32(0, 0XCD8);
    LOOKUP_FUNC(0x8001F290)(rdram, ctx);
        goto after_2;
    // 0x801C5C4C: addiu       $a0, $zero, 0xCD8
    ctx->r4 = ADD32(0, 0XCD8);
    after_2:
    // 0x801C5C50: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801C5C54: addiu       $a2, $a2, -0x5AF0
    ctx->r6 = ADD32(ctx->r6, -0X5AF0);
    // 0x801C5C58: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x801C5C5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C5C60: sw          $v0, -0x5AF4($at)
    MEM_W(-0X5AF4, ctx->r1) = ctx->r2;
    // 0x801C5C64: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801C5C68:
    // 0x801C5C68: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801C5C6C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801C5C70: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801C5C74: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801C5C78: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C5C7C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5C80: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x801C5C84: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x801C5C88: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801C5C8C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801C5C90: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C5C94: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801C5C98: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5C9C: lui         $s0, 0xE300
    ctx->r16 = S32(0XE300 << 16);
    // 0x801C5CA0: ori         $s0, $s0, 0xC00
    ctx->r16 = ctx->r16 | 0XC00;
    // 0x801C5CA4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801C5CA8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801C5CAC: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x801C5CB0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801C5CB4: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x801C5CB8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5CBC: lui         $t9, 0xD9D0
    ctx->r25 = S32(0XD9D0 << 16);
    // 0x801C5CC0: ori         $t9, $t9, 0xF9FA
    ctx->r25 = ctx->r25 | 0XF9FA;
    // 0x801C5CC4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801C5CC8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801C5CCC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C5CD0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801C5CD4: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5CD8: lui         $t8, 0x22
    ctx->r24 = S32(0X22 << 16);
    // 0x801C5CDC: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x801C5CE0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801C5CE4: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801C5CE8: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x801C5CEC: ori         $t8, $t8, 0x4
    ctx->r24 = ctx->r24 | 0X4;
    // 0x801C5CF0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801C5CF4: jal         0x80001060
    // 0x801C5CF8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_3;
    // 0x801C5CF8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    after_3:
    // 0x801C5CFC: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801C5D00: beq         $v0, $zero, L_801C5D2C
    if (ctx->r2 == 0) {
        // 0x801C5D04: addiu       $a2, $a2, -0x5AF0
        ctx->r6 = ADD32(ctx->r6, -0X5AF0);
            goto L_801C5D2C;
    }
    // 0x801C5D04: addiu       $a2, $a2, -0x5AF0
    ctx->r6 = ADD32(ctx->r6, -0X5AF0);
    // 0x801C5D08: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5D0C: lui         $t7, 0x9F
    ctx->r15 = S32(0X9F << 16);
    // 0x801C5D10: ori         $t7, $t7, 0xC77C
    ctx->r15 = ctx->r15 | 0XC77C;
    // 0x801C5D14: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801C5D18: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x801C5D1C: lui         $t6, 0xED00
    ctx->r14 = S32(0XED00 << 16);
    // 0x801C5D20: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801C5D24: b           L_801C5D4C
    // 0x801C5D28: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
        goto L_801C5D4C;
    // 0x801C5D28: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_801C5D2C:
    // 0x801C5D2C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5D30: lui         $t6, 0x4F
    ctx->r14 = S32(0X4F << 16);
    // 0x801C5D34: ori         $t6, $t6, 0xC3BC
    ctx->r14 = ctx->r14 | 0XC3BC;
    // 0x801C5D38: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801C5D3C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801C5D40: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x801C5D44: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801C5D48: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_801C5D4C:
    // 0x801C5D4C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5D50: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x801C5D54: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x801C5D58: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801C5D5C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801C5D60: ori         $t9, $t9, 0x4340
    ctx->r25 = ctx->r25 | 0X4340;
    // 0x801C5D64: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x801C5D68: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801C5D6C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801C5D70: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5D74: lui         $t8, 0xFFFC
    ctx->r24 = S32(0XFFFC << 16);
    // 0x801C5D78: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x801C5D7C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801C5D80: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801C5D84: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x801C5D88: ori         $t8, $t8, 0xF67B
    ctx->r24 = ctx->r24 | 0XF67B;
    // 0x801C5D8C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801C5D90: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801C5D94: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5D98: lui         $t6, 0xD700
    ctx->r14 = S32(0XD700 << 16);
    // 0x801C5D9C: ori         $t6, $t6, 0x2
    ctx->r14 = ctx->r14 | 0X2;
    // 0x801C5DA0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801C5DA4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x801C5DA8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801C5DAC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801C5DB0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801C5DB4: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5DB8: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x801C5DBC: ori         $t9, $t9, 0xF00
    ctx->r25 = ctx->r25 | 0XF00;
    // 0x801C5DC0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801C5DC4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801C5DC8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C5DCC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801C5DD0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5DD4: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x801C5DD8: ori         $t7, $t7, 0x1E01
    ctx->r15 = ctx->r15 | 0X1E01;
    // 0x801C5DDC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801C5DE0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801C5DE4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C5DE8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801C5DEC: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5DF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C5DF4: lui         $t9, 0xF900
    ctx->r25 = S32(0XF900 << 16);
    // 0x801C5DF8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801C5DFC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801C5E00: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801C5E04: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801C5E08: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5E0C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x801C5E10: ori         $t8, $t8, 0x1201
    ctx->r24 = ctx->r24 | 0X1201;
    // 0x801C5E14: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801C5E18: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801C5E1C: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x801C5E20: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801C5E24: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801C5E28: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5E2C: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x801C5E30: ori         $t7, $t7, 0x1001
    ctx->r15 = ctx->r15 | 0X1001;
    // 0x801C5E34: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801C5E38: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801C5E3C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C5E40: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801C5E44: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5E48: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801C5E4C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801C5E50: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C5E54: jal         0x80001060
    // 0x801C5E58: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    LOOKUP_FUNC(0x80001060)(rdram, ctx);
        goto after_4;
    // 0x801C5E58: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    after_4:
    // 0x801C5E5C: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801C5E60: beq         $v0, $zero, L_801C5FDC
    if (ctx->r2 == 0) {
        // 0x801C5E64: addiu       $a2, $a2, -0x5AF0
        ctx->r6 = ADD32(ctx->r6, -0X5AF0);
            goto L_801C5FDC;
    }
    // 0x801C5E64: addiu       $a2, $a2, -0x5AF0
    ctx->r6 = ADD32(ctx->r6, -0X5AF0);
    // 0x801C5E68: lui         $t9, 0x8040
    ctx->r25 = S32(0X8040 << 16);
    // 0x801C5E6C: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x801C5E70: lui         $fp, 0x400
    ctx->r30 = S32(0X400 << 16);
    // 0x801C5E74: ori         $fp, $fp, 0x400
    ctx->r30 = ctx->r30 | 0X400;
    // 0x801C5E78: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x801C5E7C: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x801C5E80: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x801C5E84: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801C5E88: lui         $s7, 0xF100
    ctx->r23 = S32(0XF100 << 16);
    // 0x801C5E8C: lui         $s6, 0xE100
    ctx->r22 = S32(0XE100 << 16);
    // 0x801C5E90: lui         $s5, 0xF200
    ctx->r21 = S32(0XF200 << 16);
    // 0x801C5E94: lui         $s4, 0xF300
    ctx->r20 = S32(0XF300 << 16);
    // 0x801C5E98: lui         $s3, 0xE600
    ctx->r19 = S32(0XE600 << 16);
    // 0x801C5E9C: lui         $s2, 0xF510
    ctx->r18 = S32(0XF510 << 16);
    // 0x801C5EA0: lui         $s1, 0xFD10
    ctx->r17 = S32(0XFD10 << 16);
L_801C5EA4:
    // 0x801C5EA4: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5EA8: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x801C5EAC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801C5EB0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801C5EB4: sw          $s1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r17;
    // 0x801C5EB8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x801C5EBC: addu        $t8, $t7, $ra
    ctx->r24 = ADD32(ctx->r15, ctx->r31);
    // 0x801C5EC0: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x801C5EC4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801C5EC8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5ECC: lui         $t7, 0x709
    ctx->r15 = S32(0X709 << 16);
    // 0x801C5ED0: ori         $t7, $t7, 0x82A0
    ctx->r15 = ctx->r15 | 0X82A0;
    // 0x801C5ED4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801C5ED8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801C5EDC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801C5EE0: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x801C5EE4: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5EE8: lui         $t6, 0x777
    ctx->r14 = S32(0X777 << 16);
    // 0x801C5EEC: ori         $t6, $t6, 0xF00D
    ctx->r14 = ctx->r14 | 0XF00D;
    // 0x801C5EF0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801C5EF4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801C5EF8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C5EFC: sw          $s3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r19;
    // 0x801C5F00: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5F04: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801C5F08: lui         $at, 0xE4A0
    ctx->r1 = S32(0XE4A0 << 16);
    // 0x801C5F0C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801C5F10: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x801C5F14: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801C5F18: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x801C5F1C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5F20: lui         $t6, 0xF511
    ctx->r14 = S32(0XF511 << 16);
    // 0x801C5F24: ori         $t6, $t6, 0x4000
    ctx->r14 = ctx->r14 | 0X4000;
    // 0x801C5F28: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801C5F2C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801C5F30: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C5F34: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801C5F38: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5F3C: lui         $t7, 0x9
    ctx->r15 = S32(0X9 << 16);
    // 0x801C5F40: ori         $t7, $t7, 0x82A0
    ctx->r15 = ctx->r15 | 0X82A0;
    // 0x801C5F44: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801C5F48: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x801C5F4C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801C5F50: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801C5F54: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5F58: lui         $t9, 0x9F
    ctx->r25 = S32(0X9F << 16);
    // 0x801C5F5C: ori         $t9, $t9, 0xC008
    ctx->r25 = ctx->r25 | 0XC008;
    // 0x801C5F60: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801C5F64: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801C5F68: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801C5F6C: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x801C5F70: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5F74: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x801C5F78: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x801C5F7C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801C5F80: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801C5F84: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801C5F88: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x801C5F8C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x801C5F90: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801C5F94: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801C5F98: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5F9C: addiu       $at, $zero, 0x1CE
    ctx->r1 = ADD32(0, 0X1CE);
    // 0x801C5FA0: addiu       $t4, $t4, 0x3
    ctx->r12 = ADD32(ctx->r12, 0X3);
    // 0x801C5FA4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801C5FA8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801C5FAC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C5FB0: sw          $s6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r22;
    // 0x801C5FB4: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C5FB8: addiu       $t5, $t5, 0x3
    ctx->r13 = ADD32(ctx->r13, 0X3);
    // 0x801C5FBC: addiu       $ra, $ra, 0xF00
    ctx->r31 = ADD32(ctx->r31, 0XF00);
    // 0x801C5FC0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801C5FC4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x801C5FC8: sw          $fp, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r30;
    // 0x801C5FCC: bne         $t4, $at, L_801C5EA4
    if (ctx->r12 != ctx->r1) {
        // 0x801C5FD0: sw          $s7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r23;
            goto L_801C5EA4;
    }
    // 0x801C5FD0: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x801C5FD4: b           L_801C6150
    // 0x801C5FD8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
        goto L_801C6150;
    // 0x801C5FD8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_801C5FDC:
    // 0x801C5FDC: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x801C5FE0: addiu       $t6, $t6, -0x800
    ctx->r14 = ADD32(ctx->r14, -0X800);
    // 0x801C5FE4: lui         $fp, 0x400
    ctx->r30 = S32(0X400 << 16);
    // 0x801C5FE8: ori         $fp, $fp, 0x400
    ctx->r30 = ctx->r30 | 0X400;
    // 0x801C5FEC: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x801C5FF0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x801C5FF4: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x801C5FF8: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x801C5FFC: lui         $s7, 0xF100
    ctx->r23 = S32(0XF100 << 16);
    // 0x801C6000: lui         $s6, 0xE100
    ctx->r22 = S32(0XE100 << 16);
    // 0x801C6004: lui         $s5, 0xF200
    ctx->r21 = S32(0XF200 << 16);
    // 0x801C6008: lui         $s4, 0xF300
    ctx->r20 = S32(0XF300 << 16);
    // 0x801C600C: lui         $s3, 0xE600
    ctx->r19 = S32(0XE600 << 16);
    // 0x801C6010: lui         $s2, 0xF510
    ctx->r18 = S32(0XF510 << 16);
    // 0x801C6014: lui         $s1, 0xFD10
    ctx->r17 = S32(0XFD10 << 16);
L_801C6018:
    // 0x801C6018: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C601C: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x801C6020: ori         $at, $at, 0xB000
    ctx->r1 = ctx->r1 | 0XB000;
    // 0x801C6024: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801C6028: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801C602C: sw          $s1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r17;
    // 0x801C6030: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x801C6034: addu        $t9, $t8, $ra
    ctx->r25 = ADD32(ctx->r24, ctx->r31);
    // 0x801C6038: addu        $t6, $t9, $at
    ctx->r14 = ADD32(ctx->r25, ctx->r1);
    // 0x801C603C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801C6040: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C6044: lui         $t8, 0x709
    ctx->r24 = S32(0X709 << 16);
    // 0x801C6048: ori         $t8, $t8, 0x8290
    ctx->r24 = ctx->r24 | 0X8290;
    // 0x801C604C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801C6050: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801C6054: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801C6058: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x801C605C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C6060: lui         $t7, 0x777
    ctx->r15 = S32(0X777 << 16);
    // 0x801C6064: ori         $t7, $t7, 0xF01A
    ctx->r15 = ctx->r15 | 0XF01A;
    // 0x801C6068: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801C606C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x801C6070: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C6074: sw          $s3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r19;
    // 0x801C6078: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C607C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x801C6080: lui         $at, 0xE450
    ctx->r1 = S32(0XE450 << 16);
    // 0x801C6084: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801C6088: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801C608C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801C6090: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x801C6094: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C6098: lui         $t7, 0xF510
    ctx->r15 = S32(0XF510 << 16);
    // 0x801C609C: ori         $t7, $t7, 0xA000
    ctx->r15 = ctx->r15 | 0XA000;
    // 0x801C60A0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801C60A4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801C60A8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C60AC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801C60B0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C60B4: lui         $t8, 0x9
    ctx->r24 = S32(0X9 << 16);
    // 0x801C60B8: ori         $t8, $t8, 0x8290
    ctx->r24 = ctx->r24 | 0X8290;
    // 0x801C60BC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801C60C0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801C60C4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801C60C8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801C60CC: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C60D0: lui         $t6, 0x4F
    ctx->r14 = S32(0X4F << 16);
    // 0x801C60D4: ori         $t6, $t6, 0xC014
    ctx->r14 = ctx->r14 | 0XC014;
    // 0x801C60D8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801C60DC: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x801C60E0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801C60E4: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x801C60E8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C60EC: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x801C60F0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x801C60F4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801C60F8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801C60FC: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x801C6100: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x801C6104: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x801C6108: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801C610C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801C6110: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C6114: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x801C6118: addiu       $t4, $t4, 0x6
    ctx->r12 = ADD32(ctx->r12, 0X6);
    // 0x801C611C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801C6120: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x801C6124: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C6128: sw          $s6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r22;
    // 0x801C612C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C6130: addiu       $t5, $t5, 0x6
    ctx->r13 = ADD32(ctx->r13, 0X6);
    // 0x801C6134: addiu       $ra, $ra, 0xF00
    ctx->r31 = ADD32(ctx->r31, 0XF00);
    // 0x801C6138: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801C613C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801C6140: sw          $fp, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r30;
    // 0x801C6144: bne         $t4, $at, L_801C6018
    if (ctx->r12 != ctx->r1) {
        // 0x801C6148: sw          $s7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r23;
            goto L_801C6018;
    }
    // 0x801C6148: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x801C614C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_801C6150:
    // 0x801C6150: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x801C6154: ori         $t9, $t9, 0x8000
    ctx->r25 = ctx->r25 | 0X8000;
    // 0x801C6158: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801C615C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801C6160: lui         $t8, 0xD700
    ctx->r24 = S32(0XD700 << 16);
    // 0x801C6164: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801C6168: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801C616C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801C6170: lui         $t7, 0xDF00
    ctx->r15 = S32(0XDF00 << 16);
    // 0x801C6174: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C6178: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801C617C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801C6180: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801C6184: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801C6188: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x801C618C: jal         0x800058DC
    // 0x801C6190: addiu       $a1, $a1, 0x61C4
    ctx->r5 = ADD32(ctx->r5, 0X61C4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_5;
    // 0x801C6190: addiu       $a1, $a1, 0x61C4
    ctx->r5 = ADD32(ctx->r5, 0X61C4);
    after_5:
    // 0x801C6194: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801C6198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C619C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801C61A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801C61A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801C61A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801C61AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801C61B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801C61B4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x801C61B8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x801C61BC: jr          $ra
    // 0x801C61C0: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x801C61C0: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c61c4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c61c4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C61C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C61C8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801C61CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C61D0: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C61D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801C61D8: addiu       $a1, $a1, -0x5AD4
    ctx->r5 = ADD32(ctx->r5, -0X5AD4);
    // 0x801C61DC: jal         0x80005E44
    // 0x801C61E0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C61E0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801C61E4: beq         $v0, $zero, L_801C6284
    if (ctx->r2 == 0) {
        // 0x801C61E8: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_801C6284;
    }
    // 0x801C61E8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x801C61EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C61F0: jal         0x80006214
    // 0x801C61F4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C61F4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x801C61F8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x801C61FC: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801C6200: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801C6204: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x801C6208: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x801C620C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C6210: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C6214: addiu       $v1, $v1, -0x6D50
    ctx->r3 = ADD32(ctx->r3, -0X6D50);
    // 0x801C6218: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C621C: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    // 0x801C6220: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x801C6224: addiu       $t7, $zero, 0x100
    ctx->r15 = ADD32(0, 0X100);
    // 0x801C6228: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C622C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C6230: addiu       $a1, $a1, 0x6294
    ctx->r5 = ADD32(ctx->r5, 0X6294);
    // 0x801C6234: sw          $zero, 0x28($t9)
    MEM_W(0X28, ctx->r25) = 0;
    // 0x801C6238: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x801C623C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C6240: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C6244: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x801C6248: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x801C624C: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C6250: sh          $zero, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = 0;
    // 0x801C6254: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x801C6258: lw          $t4, -0x5AF4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5AF4);
    // 0x801C625C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C6260: sw          $t4, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r12;
    // 0x801C6264: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x801C6268: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C626C: sw          $t7, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r15;
    // 0x801C6270: sh          $zero, 0xA4($v1)
    MEM_H(0XA4, ctx->r3) = 0;
    // 0x801C6274: sh          $t0, 0xA6($v1)
    MEM_H(0XA6, ctx->r3) = ctx->r8;
    // 0x801C6278: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C627C: jal         0x800058DC
    // 0x801C6280: swc1        $f4, -0x5AF8($at)
    MEM_W(-0X5AF8, ctx->r1) = ctx->f4.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801C6280: swc1        $f4, -0x5AF8($at)
    MEM_W(-0X5AF8, ctx->r1) = ctx->f4.u32l;
    after_2:
L_801C6284:
    // 0x801C6284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C6288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C628C: jr          $ra
    // 0x801C6290: nop

    return;
    // 0x801C6290: nop

;}
RECOMP_FUNC void M24_FUN_801c6294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C6294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C6298: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C629C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C62A0: jal         0x80006214
    // 0x801C62A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801C62A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801C62A8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801C62AC: addiu       $v0, $v0, -0x5AF8
    ctx->r2 = ADD32(ctx->r2, -0X5AF8);
    // 0x801C62B0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801C62B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C62B8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C62BC: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x801C62C0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801C62C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C62C8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C62CC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801C62D0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801C62D4: addiu       $a1, $a1, 0x63B4
    ctx->r5 = ADD32(ctx->r5, 0X63B4);
    // 0x801C62D8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801C62DC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801C62E0: nop

    // 0x801C62E4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801C62E8: beql        $t7, $zero, L_801C6338
    if (ctx->r15 == 0) {
        // 0x801C62EC: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_801C6338;
    }
    goto skip_0;
    // 0x801C62EC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801C62F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C62F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801C62F8: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801C62FC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801C6300: nop

    // 0x801C6304: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801C6308: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801C630C: nop

    // 0x801C6310: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801C6314: bne         $t7, $zero, L_801C632C
    if (ctx->r15 != 0) {
        // 0x801C6318: nop
    
            goto L_801C632C;
    }
    // 0x801C6318: nop

    // 0x801C631C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x801C6320: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C6324: b           L_801C6344
    // 0x801C6328: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801C6344;
    // 0x801C6328: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801C632C:
    // 0x801C632C: b           L_801C6344
    // 0x801C6330: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801C6344;
    // 0x801C6330: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801C6334: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_801C6338:
    // 0x801C6338: nop

    // 0x801C633C: bltz        $t7, L_801C632C
    if (SIGNED(ctx->r15) < 0) {
        // 0x801C6340: nop
    
            goto L_801C632C;
    }
    // 0x801C6340: nop

L_801C6344:
    // 0x801C6344: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801C6348: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C634C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801C6350: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801C6354: sb          $t7, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r15;
    // 0x801C6358: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801C635C: lwc1        $f10, -0x2DC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2DC8);
    // 0x801C6360: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801C6364: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C6368: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801C636C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x801C6370: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801C6374: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x801C6378: nop

    // 0x801C637C: bc1fl       L_801C63A8
    if (!c1cs) {
        // 0x801C6380: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801C63A8;
    }
    goto skip_1;
    // 0x801C6380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801C6384: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801C6388: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x801C638C: addiu       $v0, $v0, -0x6D50
    ctx->r2 = ADD32(ctx->r2, -0X6D50);
    // 0x801C6390: sb          $zero, 0x22($t0)
    MEM_B(0X22, ctx->r8) = 0;
    // 0x801C6394: sh          $zero, 0xA6($v0)
    MEM_H(0XA6, ctx->r2) = 0;
    // 0x801C6398: sh          $zero, 0xA4($v0)
    MEM_H(0XA4, ctx->r2) = 0;
    // 0x801C639C: jal         0x800058DC
    // 0x801C63A0: sh          $zero, 0x90($a0)
    MEM_H(0X90, ctx->r4) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C63A0: sh          $zero, 0x90($a0)
    MEM_H(0X90, ctx->r4) = 0;
    after_1:
    // 0x801C63A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801C63A8:
    // 0x801C63A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C63AC: jr          $ra
    // 0x801C63B0: nop

    return;
    // 0x801C63B0: nop

;}
RECOMP_FUNC void M24_FUN_801c63b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C63B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C63B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C63BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C63C0: lhu         $v0, 0x90($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X90);
    // 0x801C63C4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801C63C8: slti        $v1, $v0, 0x7
    ctx->r3 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x801C63CC: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x801C63D0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801C63D4: beq         $v1, $zero, L_801C63FC
    if (ctx->r3 == 0) {
        // 0x801C63D8: sh          $t6, 0x90($a0)
        MEM_H(0X90, ctx->r4) = ctx->r14;
            goto L_801C63FC;
    }
    // 0x801C63D8: sh          $t6, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r14;
    // 0x801C63DC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801C63E0: lw          $a0, -0x5AF4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5AF4);
    // 0x801C63E4: jal         0x8001F540
    // 0x801C63E8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(0x8001F540)(rdram, ctx);
        goto after_0;
    // 0x801C63E8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801C63EC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C63F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801C63F4: jal         0x800058DC
    // 0x801C63F8: addiu       $a1, $a1, 0x640C
    ctx->r5 = ADD32(ctx->r5, 0X640C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801C63F8: addiu       $a1, $a1, 0x640C
    ctx->r5 = ADD32(ctx->r5, 0X640C);
    after_1:
L_801C63FC:
    // 0x801C63FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C6400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C6404: jr          $ra
    // 0x801C6408: nop

    return;
    // 0x801C6408: nop

;}
RECOMP_FUNC void M24_FUN_801c640c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C640C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C6410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C6414: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C6418: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801C641C: jal         0x80005700
    // 0x801C6420: sw          $zero, -0x5AEC($at)
    MEM_W(-0X5AEC, ctx->r1) = 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_0;
    // 0x801C6420: sw          $zero, -0x5AEC($at)
    MEM_W(-0X5AEC, ctx->r1) = 0;
    after_0:
    // 0x801C6424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C6428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C642C: jr          $ra
    // 0x801C6430: nop

    return;
    // 0x801C6430: nop

;}
RECOMP_FUNC void M24_FUN_801c6434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C6434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C6438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C643C: jal         0x801C78C0
    // 0x801C6440: nop

    LOOKUP_FUNC(0x801C78C0)(rdram, ctx);
        goto after_0;
    // 0x801C6440: nop

    after_0:
    // 0x801C6444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C6448: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C644C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C6450: sw          $t6, -0x5DD0($at)
    MEM_W(-0X5DD0, ctx->r1) = ctx->r14;
    // 0x801C6454: jr          $ra
    // 0x801C6458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801C6458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c645c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c645c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C645C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801C6460: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801C6464: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801C6468: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801C646C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801C6470: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801C6474: beq         $a0, $zero, L_801C64CC
    if (ctx->r4 == 0) {
        // 0x801C6478: sw          $s0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r16;
            goto L_801C64CC;
    }
    // 0x801C6478: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801C647C: beq         $a0, $zero, L_801C64CC
    if (ctx->r4 == 0) {
        // 0x801C6480: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_801C64CC;
    }
    // 0x801C6480: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801C6484: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C6488: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
L_801C648C:
    // 0x801C648C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801C6490: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801C6494: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C6498: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x801C649C: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x801C64A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801C64A4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801C64A8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801C64AC: lw          $t6, 0x18($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X18);
    // 0x801C64B0: jal         0x801C64F4
    // 0x801C64B4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(0x801C64F4)(rdram, ctx);
        goto after_0;
    // 0x801C64B4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x801C64B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801C64BC: sltu        $at, $s1, $s3
    ctx->r1 = ctx->r17 < ctx->r19 ? 1 : 0;
    // 0x801C64C0: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x801C64C4: bne         $at, $zero, L_801C648C
    if (ctx->r1 != 0) {
        // 0x801C64C8: addiu       $s2, $s2, 0x1C
        ctx->r18 = ADD32(ctx->r18, 0X1C);
            goto L_801C648C;
    }
    // 0x801C64C8: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
L_801C64CC:
    // 0x801C64CC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801C64D0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801C64D4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801C64D8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801C64DC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801C64E0: jr          $ra
    // 0x801C64E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801C64E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c64e8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c64e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C64E8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C64EC: jr          $ra
    // 0x801C64F0: sw          $zero, -0x5DD0($at)
    MEM_W(-0X5DD0, ctx->r1) = 0;
    return;
    // 0x801C64F0: sw          $zero, -0x5DD0($at)
    MEM_W(-0X5DD0, ctx->r1) = 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c64f4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c64f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C64F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C64F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C64FC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C6500: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C6504: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C6508: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x801C650C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C6510: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C6514: addiu       $a1, $a1, -0x5AC4
    ctx->r5 = ADD32(ctx->r5, -0X5AC4);
    // 0x801C6518: jal         0x80005670
    // 0x801C651C: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C651C: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C6520: bne         $v0, $zero, L_801C6530
    if (ctx->r2 != 0) {
        // 0x801C6524: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C6530;
    }
    // 0x801C6524: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C6528: b           L_801C6570
    // 0x801C652C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C6570;
    // 0x801C652C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C6530:
    // 0x801C6530: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C6534: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C6538: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801C653C: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C6540: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x801C6544: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C6548: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
    // 0x801C654C: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C6550: swc1        $f10, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f10.u32l;
    // 0x801C6554: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C6558: swc1        $f16, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f16.u32l;
    // 0x801C655C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C6560: sh          $zero, 0xB0($v1)
    MEM_H(0XB0, ctx->r3) = 0;
    // 0x801C6564: swc1        $f18, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f18.u32l;
    // 0x801C6568: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x801C656C: sh          $t6, 0xB2($v1)
    MEM_H(0XB2, ctx->r3) = ctx->r14;
L_801C6570:
    // 0x801C6570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C6574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C6578: jr          $ra
    // 0x801C657C: nop

    return;
    // 0x801C657C: nop

;}
RECOMP_FUNC void M24_FUN_801c6580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C6580: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C6584: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C6588: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C658C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C6590: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C6594: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C6598: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C659C: jal         0x80005E44
    // 0x801C65A0: addiu       $a1, $a1, -0x5AB0
    ctx->r5 = ADD32(ctx->r5, -0X5AB0);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C65A0: addiu       $a1, $a1, -0x5AB0
    ctx->r5 = ADD32(ctx->r5, -0X5AB0);
    after_0:
    // 0x801C65A4: jal         0x80006214
    // 0x801C65A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C65A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C65AC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C65B0: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C65B4: addiu       $t8, $t8, -0x66F8
    ctx->r24 = ADD32(ctx->r24, -0X66F8);
    // 0x801C65B8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C65BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C65C0: addiu       $a2, $zero, 0x473
    ctx->r6 = ADD32(0, 0X473);
    // 0x801C65C4: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    // 0x801C65C8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C65CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C65D0: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C65D4: sw          $t8, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r24;
    // 0x801C65D8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C65DC: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C65E0: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x801C65E4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C65E8: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C65EC: sh          $zero, 0x2C($t4)
    MEM_H(0X2C, ctx->r12) = 0;
    // 0x801C65F0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C65F4: lw          $a1, 0x30($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X30);
    // 0x801C65F8: jal         0x8012CF8C
    // 0x801C65FC: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_2;
    // 0x801C65FC: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_2:
    // 0x801C6600: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C6604: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801C6608: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801C660C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C6610: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801C6614: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C6618: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801C661C: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801C6620: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801C6624: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C6628: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801C662C: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C6630: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x801C6634: lw          $t2, -0x4328($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4328);
    // 0x801C6638: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x801C663C: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C6640: lwc1        $f16, 0x30($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801C6644: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C6648: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801C664C: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801C6650: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801C6654: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C6658: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801C665C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801C6660: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801C6664: jal         0x8002FC20
    // 0x801C6668: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_3;
    // 0x801C6668: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_3:
    // 0x801C666C: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801C6670: lw          $t3, -0x4328($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4328);
    // 0x801C6674: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801C6678: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801C667C: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801C6680: lwc1        $f16, 0x34($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801C6684: jal         0x8001EF38
    // 0x801C6688: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_4;
    // 0x801C6688: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    after_4:
    // 0x801C668C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C6690: andi        $t4, $v0, 0x1FFF
    ctx->r12 = ctx->r2 & 0X1FFF;
    // 0x801C6694: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C6698: sh          $t4, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r12;
    // 0x801C669C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C66A0: jal         0x8001EF38
    // 0x801C66A4: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_5;
    // 0x801C66A4: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x801C66A8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C66AC: addiu       $t8, $v0, 0x1000
    ctx->r24 = ADD32(ctx->r2, 0X1000);
    // 0x801C66B0: andi        $t0, $t8, 0x1FFF
    ctx->r8 = ctx->r24 & 0X1FFF;
    // 0x801C66B4: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C66B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801C66BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801C66C0: sh          $t0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r8;
    // 0x801C66C4: lwc1        $f18, 0x9C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x801C66C8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C66CC: addiu       $t8, $zero, 0x300
    ctx->r24 = ADD32(0, 0X300);
    // 0x801C66D0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801C66D4: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801C66D8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801C66DC: swc1        $f4, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f4.u32l;
    // 0x801C66E0: lwc1        $f6, 0xA0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x801C66E4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C66E8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801C66EC: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801C66F0: swc1        $f8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f8.u32l;
    // 0x801C66F4: lwc1        $f10, 0xA4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x801C66F8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C66FC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801C6700: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C6704: swc1        $f16, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f16.u32l;
    // 0x801C6708: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C670C: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x801C6710: sw          $t8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r24;
    // 0x801C6714: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C6718: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C671C: sb          $v1, 0x48($t3)
    MEM_B(0X48, ctx->r11) = ctx->r3;
    // 0x801C6720: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C6724: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x801C6728: sb          $v1, 0x49($t4)
    MEM_B(0X49, ctx->r12) = ctx->r3;
    // 0x801C672C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C6730: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C6734: sb          $v1, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r3;
    // 0x801C6738: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C673C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C6740: sb          $v1, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r3;
    // 0x801C6744: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C6748: lw          $t0, 0x30($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X30);
    // 0x801C674C: sb          $v1, 0x4C($t0)
    MEM_B(0X4C, ctx->r8) = ctx->r3;
    // 0x801C6750: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C6754: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C6758: sb          $v1, 0x4D($t3)
    MEM_B(0X4D, ctx->r11) = ctx->r3;
    // 0x801C675C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C6760: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x801C6764: sb          $v1, 0x4E($t4)
    MEM_B(0X4E, ctx->r12) = ctx->r3;
    // 0x801C6768: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C676C: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C6770: sb          $v1, 0x4F($t7)
    MEM_B(0X4F, ctx->r15) = ctx->r3;
    // 0x801C6774: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C6778: jal         0x801C78F8
    // 0x801C677C: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_6;
    // 0x801C677C: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
    after_6:
    // 0x801C6780: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801C6784: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C6788: nop

    // 0x801C678C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801C6790: jal         0x801C78F8
    // 0x801C6794: swc1        $f4, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->f4.u32l;
    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_7;
    // 0x801C6794: swc1        $f4, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->f4.u32l;
    after_7:
    // 0x801C6798: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801C679C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C67A0: nop

    // 0x801C67A4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801C67A8: jal         0x801C78F8
    // 0x801C67AC: swc1        $f8, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->f8.u32l;
    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_8;
    // 0x801C67AC: swc1        $f8, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->f8.u32l;
    after_8:
    // 0x801C67B0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801C67B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C67B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C67BC: lwc1        $f18, 0x90($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801C67C0: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801C67C4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C67C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C67CC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801C67D0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C67D4: swc1        $f16, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f16.u32l;
    // 0x801C67D8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801C67DC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C67E0: nop

    // 0x801C67E4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801C67E8: beql        $t8, $zero, L_801C6838
    if (ctx->r24 == 0) {
        // 0x801C67EC: mfc1        $t8, $f4
        ctx->r24 = (int32_t)ctx->f4.u32l;
            goto L_801C6838;
    }
    goto skip_0;
    // 0x801C67EC: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x801C67F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C67F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801C67F8: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801C67FC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C6800: nop

    // 0x801C6804: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801C6808: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C680C: nop

    // 0x801C6810: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801C6814: bne         $t8, $zero, L_801C682C
    if (ctx->r24 != 0) {
        // 0x801C6818: nop
    
            goto L_801C682C;
    }
    // 0x801C6818: nop

    // 0x801C681C: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x801C6820: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C6824: b           L_801C6844
    // 0x801C6828: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_801C6844;
    // 0x801C6828: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_801C682C:
    // 0x801C682C: b           L_801C6844
    // 0x801C6830: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_801C6844;
    // 0x801C6830: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801C6834: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
L_801C6838:
    // 0x801C6838: nop

    // 0x801C683C: bltz        $t8, L_801C682C
    if (SIGNED(ctx->r24) < 0) {
        // 0x801C6840: nop
    
            goto L_801C682C;
    }
    // 0x801C6840: nop

L_801C6844:
    // 0x801C6844: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C6848: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801C684C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801C6850: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x801C6854: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C6858: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801C685C: sb          $t8, 0x4C($t2)
    MEM_B(0X4C, ctx->r10) = ctx->r24;
    // 0x801C6860: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801C6864: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801C6868: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801C686C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801C6870: nop

    // 0x801C6874: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801C6878: beql        $t5, $zero, L_801C68C8
    if (ctx->r13 == 0) {
        // 0x801C687C: mfc1        $t5, $f8
        ctx->r13 = (int32_t)ctx->f8.u32l;
            goto L_801C68C8;
    }
    goto skip_1;
    // 0x801C687C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x801C6880: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C6884: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801C6888: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801C688C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801C6890: nop

    // 0x801C6894: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C6898: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801C689C: nop

    // 0x801C68A0: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801C68A4: bne         $t5, $zero, L_801C68BC
    if (ctx->r13 != 0) {
        // 0x801C68A8: nop
    
            goto L_801C68BC;
    }
    // 0x801C68A8: nop

    // 0x801C68AC: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x801C68B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C68B4: b           L_801C68D4
    // 0x801C68B8: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_801C68D4;
    // 0x801C68B8: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_801C68BC:
    // 0x801C68BC: b           L_801C68D4
    // 0x801C68C0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_801C68D4;
    // 0x801C68C0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801C68C4: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
L_801C68C8:
    // 0x801C68C8: nop

    // 0x801C68CC: bltz        $t5, L_801C68BC
    if (SIGNED(ctx->r13) < 0) {
        // 0x801C68D0: nop
    
            goto L_801C68BC;
    }
    // 0x801C68D0: nop

L_801C68D4:
    // 0x801C68D4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C68D8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801C68DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C68E0: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801C68E4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C68E8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801C68EC: sb          $t5, 0x4D($t6)
    MEM_B(0X4D, ctx->r14) = ctx->r13;
    // 0x801C68F0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801C68F4: lwc1        $f10, 0x98($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801C68F8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C68FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801C6900: nop

    // 0x801C6904: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801C6908: beql        $t9, $zero, L_801C6958
    if (ctx->r25 == 0) {
        // 0x801C690C: mfc1        $t9, $f16
        ctx->r25 = (int32_t)ctx->f16.u32l;
            goto L_801C6958;
    }
    goto skip_2;
    // 0x801C690C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x801C6910: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C6914: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801C6918: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801C691C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801C6920: nop

    // 0x801C6924: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801C6928: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801C692C: nop

    // 0x801C6930: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801C6934: bne         $t9, $zero, L_801C694C
    if (ctx->r25 != 0) {
        // 0x801C6938: nop
    
            goto L_801C694C;
    }
    // 0x801C6938: nop

    // 0x801C693C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x801C6940: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C6944: b           L_801C6964
    // 0x801C6948: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801C6964;
    // 0x801C6948: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801C694C:
    // 0x801C694C: b           L_801C6964
    // 0x801C6950: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801C6964;
    // 0x801C6950: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801C6954: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
L_801C6958:
    // 0x801C6958: nop

    // 0x801C695C: bltz        $t9, L_801C694C
    if (SIGNED(ctx->r25) < 0) {
        // 0x801C6960: nop
    
            goto L_801C694C;
    }
    // 0x801C6960: nop

L_801C6964:
    // 0x801C6964: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C6968: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801C696C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801C6970: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x801C6974: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C6978: addiu       $a1, $a1, 0x699C
    ctx->r5 = ADD32(ctx->r5, 0X699C);
    // 0x801C697C: sb          $t9, 0x4E($t0)
    MEM_B(0X4E, ctx->r8) = ctx->r25;
    // 0x801C6980: jal         0x800058DC
    // 0x801C6984: swc1        $f18, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f18.u32l;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_9;
    // 0x801C6984: swc1        $f18, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f18.u32l;
    after_9:
    // 0x801C6988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C698C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C6990: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C6994: jr          $ra
    // 0x801C6998: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C6998: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c699c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c699c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C699C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C69A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C69A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C69A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C69AC: lhu         $t6, 0xB0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XB0);
    // 0x801C69B0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C69B4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C69B8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C69BC: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C69C0: bgez        $t6, L_801C69D8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C69C4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C69D8;
    }
    // 0x801C69C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C69C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C69CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C69D0: nop

    // 0x801C69D4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801C69D8:
    // 0x801C69D8: lhu         $t7, 0xB2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0XB2);
    // 0x801C69DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C69E0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801C69E4: bgez        $t7, L_801C69F8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C69E8: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C69F8;
    }
    // 0x801C69E8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C69EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C69F0: nop

    // 0x801C69F4: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801C69F8:
    // 0x801C69F8: div.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801C69FC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801C6A00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C6A04: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C6A08: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C6A0C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C6A10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C6A14: lw          $a1, 0x30($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X30);
    // 0x801C6A18: addiu       $a2, $zero, 0x473
    ctx->r6 = ADD32(0, 0X473);
    // 0x801C6A1C: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x801C6A20: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801C6A24: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801C6A28: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801C6A2C: nop

    // 0x801C6A30: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C6A34: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801C6A38: nop

    // 0x801C6A3C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801C6A40: beql        $t0, $zero, L_801C6A90
    if (ctx->r8 == 0) {
        // 0x801C6A44: mfc1        $t0, $f10
        ctx->r8 = (int32_t)ctx->f10.u32l;
            goto L_801C6A90;
    }
    goto skip_0;
    // 0x801C6A44: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x801C6A48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C6A4C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C6A50: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801C6A54: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801C6A58: nop

    // 0x801C6A5C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C6A60: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801C6A64: nop

    // 0x801C6A68: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801C6A6C: bne         $t0, $zero, L_801C6A84
    if (ctx->r8 != 0) {
        // 0x801C6A70: nop
    
            goto L_801C6A84;
    }
    // 0x801C6A70: nop

    // 0x801C6A74: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x801C6A78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C6A7C: b           L_801C6A9C
    // 0x801C6A80: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_801C6A9C;
    // 0x801C6A80: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_801C6A84:
    // 0x801C6A84: b           L_801C6A9C
    // 0x801C6A88: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_801C6A9C;
    // 0x801C6A88: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801C6A8C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
L_801C6A90:
    // 0x801C6A90: nop

    // 0x801C6A94: bltz        $t0, L_801C6A84
    if (SIGNED(ctx->r8) < 0) {
        // 0x801C6A98: nop
    
            goto L_801C6A84;
    }
    // 0x801C6A98: nop

L_801C6A9C:
    // 0x801C6A9C: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x801C6AA0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801C6AA4: addu        $a3, $a3, $t2
    ctx->r7 = ADD32(ctx->r7, ctx->r10);
    // 0x801C6AA8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801C6AAC: jal         0x8012CF8C
    // 0x801C6AB0: lw          $a3, -0x5AA0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5AA0);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801C6AB0: lw          $a3, -0x5AA0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5AA0);
    after_0:
    // 0x801C6AB4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C6AB8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801C6ABC: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801C6AC0: sb          $t3, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r11;
    // 0x801C6AC4: lw          $t5, -0x4328($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4328);
    // 0x801C6AC8: lw          $v0, 0x2C($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X2C);
    // 0x801C6ACC: lwc1        $f18, 0x3C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C6AD0: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801C6AD4: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C6AD8: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801C6ADC: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x801C6AE0: sub.s       $f14, $f16, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x801C6AE4: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x801C6AE8: jal         0x8001EF38
    // 0x801C6AEC: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x801C6AEC: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x801C6AF0: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C6AF4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C6AF8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C6AFC: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C6B00: addiu       $t8, $v0, 0x1000
    ctx->r24 = ADD32(ctx->r2, 0X1000);
    // 0x801C6B04: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C6B08: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C6B0C: andi        $t9, $t8, 0x1FFF
    ctx->r25 = ctx->r24 & 0X1FFF;
    // 0x801C6B10: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    // 0x801C6B14: jal         0x8002FC20
    // 0x801C6B18: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x801C6B18: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x801C6B1C: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801C6B20: lw          $t2, -0x4328($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4328);
    // 0x801C6B24: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801C6B28: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x801C6B2C: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801C6B30: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801C6B34: jal         0x8001EF38
    // 0x801C6B38: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x801C6B38: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    after_3:
    // 0x801C6B3C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C6B40: andi        $t3, $v0, 0x1FFF
    ctx->r11 = ctx->r2 & 0X1FFF;
    // 0x801C6B44: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801C6B48: sh          $t3, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r11;
    // 0x801C6B4C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C6B50: lw          $v1, 0x30($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X30);
    // 0x801C6B54: lbu         $t7, 0x4C($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4C);
    // 0x801C6B58: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801C6B5C: sb          $t8, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r24;
    // 0x801C6B60: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C6B64: lw          $v1, 0x30($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X30);
    // 0x801C6B68: lbu         $t9, 0x4D($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4D);
    // 0x801C6B6C: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x801C6B70: sb          $t1, 0x4D($v1)
    MEM_B(0X4D, ctx->r3) = ctx->r9;
    // 0x801C6B74: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C6B78: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    // 0x801C6B7C: lbu         $t4, 0x4E($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4E);
    // 0x801C6B80: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x801C6B84: sb          $t3, 0x4E($v1)
    MEM_B(0X4E, ctx->r3) = ctx->r11;
    // 0x801C6B88: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C6B8C: lw          $v1, 0x30($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X30);
    // 0x801C6B90: lbu         $t7, 0x4C($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4C);
    // 0x801C6B94: sb          $t7, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r15;
    // 0x801C6B98: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C6B9C: lw          $v1, 0x30($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X30);
    // 0x801C6BA0: lbu         $t0, 0x4D($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X4D);
    // 0x801C6BA4: or          $t9, $t0, $zero
    ctx->r25 = ctx->r8 | 0;
    // 0x801C6BA8: sb          $t9, 0x4D($v1)
    MEM_B(0X4D, ctx->r3) = ctx->r25;
    // 0x801C6BAC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C6BB0: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801C6BB4: lw          $v1, 0x30($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X30);
    // 0x801C6BB8: lbu         $t2, 0x4E($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X4E);
    // 0x801C6BBC: or          $t4, $t2, $zero
    ctx->r12 = ctx->r10 | 0;
    // 0x801C6BC0: sb          $t4, 0x4E($v1)
    MEM_B(0X4E, ctx->r3) = ctx->r12;
    // 0x801C6BC4: lhu         $t3, 0xB0($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0XB0);
    // 0x801C6BC8: lhu         $t7, 0xB2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0XB2);
    // 0x801C6BCC: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x801C6BD0: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x801C6BD4: div         $zero, $t6, $t7
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r15)));
    // 0x801C6BD8: sh          $t5, 0xB0($s1)
    MEM_H(0XB0, ctx->r17) = ctx->r13;
    // 0x801C6BDC: mfhi        $t8
    ctx->r24 = hi;
    // 0x801C6BE0: sh          $t8, 0xB0($s1)
    MEM_H(0XB0, ctx->r17) = ctx->r24;
    // 0x801C6BE4: lw          $t0, -0x5DD0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5DD0);
    // 0x801C6BE8: bne         $t7, $zero, L_801C6BF4
    if (ctx->r15 != 0) {
        // 0x801C6BEC: nop
    
            goto L_801C6BF4;
    }
    // 0x801C6BEC: nop

    // 0x801C6BF0: break       7
    do_break(2149346288);
L_801C6BF4:
    // 0x801C6BF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801C6BF8: bne         $t7, $at, L_801C6C0C
    if (ctx->r15 != ctx->r1) {
        // 0x801C6BFC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801C6C0C;
    }
    // 0x801C6BFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C6C00: bne         $t6, $at, L_801C6C0C
    if (ctx->r14 != ctx->r1) {
        // 0x801C6C04: nop
    
            goto L_801C6C0C;
    }
    // 0x801C6C04: nop

    // 0x801C6C08: break       6
    do_break(2149346312);
L_801C6C0C:
    // 0x801C6C0C: bnel        $t0, $zero, L_801C6C20
    if (ctx->r8 != 0) {
        // 0x801C6C10: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801C6C20;
    }
    goto skip_1;
    // 0x801C6C10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801C6C14: jal         0x80005700
    // 0x801C6C18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x801C6C18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801C6C1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801C6C20:
    // 0x801C6C20: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C6C24: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C6C28: jr          $ra
    // 0x801C6C2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C6C2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c6c30(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c6c30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C6C30: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801C6C34: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801C6C38: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801C6C3C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801C6C40: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801C6C44: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801C6C48: beq         $a0, $zero, L_801C6CA8
    if (ctx->r4 == 0) {
        // 0x801C6C4C: sw          $s0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r16;
            goto L_801C6CA8;
    }
    // 0x801C6C4C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801C6C50: beq         $a0, $zero, L_801C6CA8
    if (ctx->r4 == 0) {
        // 0x801C6C54: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_801C6CA8;
    }
    // 0x801C6C54: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C6C58: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C6C5C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_801C6C60:
    // 0x801C6C60: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801C6C64: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801C6C68: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C6C6C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x801C6C70: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x801C6C74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801C6C78: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801C6C7C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801C6C80: lw          $t6, 0x18($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X18);
    // 0x801C6C84: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801C6C88: lw          $t7, 0x1C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1C);
    // 0x801C6C8C: jal         0x801C6CC4
    // 0x801C6C90: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x801C6CC4)(rdram, ctx);
        goto after_0;
    // 0x801C6C90: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x801C6C94: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801C6C98: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x801C6C9C: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x801C6CA0: bne         $at, $zero, L_801C6C60
    if (ctx->r1 != 0) {
        // 0x801C6CA4: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_801C6C60;
    }
    // 0x801C6CA4: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
L_801C6CA8:
    // 0x801C6CA8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801C6CAC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801C6CB0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801C6CB4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801C6CB8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801C6CBC: jr          $ra
    // 0x801C6CC0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801C6CC0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c6cc4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c6cc4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C6CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C6CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C6CCC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C6CD0: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C6CD4: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x801C6CD8: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x801C6CDC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801C6CE0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801C6CE4: addiu       $a1, $a1, -0x5A80
    ctx->r5 = ADD32(ctx->r5, -0X5A80);
    // 0x801C6CE8: jal         0x80005670
    // 0x801C6CEC: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C6CEC: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C6CF0: bne         $v0, $zero, L_801C6D00
    if (ctx->r2 != 0) {
        // 0x801C6CF4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C6D00;
    }
    // 0x801C6CF4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C6CF8: b           L_801C6D4C
    // 0x801C6CFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C6D4C;
    // 0x801C6CFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C6D00:
    // 0x801C6D00: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801C6D04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C6D08: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801C6D0C: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801C6D10: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x801C6D14: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C6D18: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
    // 0x801C6D1C: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C6D20: swc1        $f10, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f10.u32l;
    // 0x801C6D24: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C6D28: swc1        $f16, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f16.u32l;
    // 0x801C6D2C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C6D30: sh          $zero, 0xA8($v1)
    MEM_H(0XA8, ctx->r3) = 0;
    // 0x801C6D34: swc1        $f18, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f18.u32l;
    // 0x801C6D38: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x801C6D3C: sh          $zero, 0xB0($v1)
    MEM_H(0XB0, ctx->r3) = 0;
    // 0x801C6D40: sh          $t6, 0xAA($v1)
    MEM_H(0XAA, ctx->r3) = ctx->r14;
    // 0x801C6D44: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x801C6D48: sh          $t7, 0xB2($v1)
    MEM_H(0XB2, ctx->r3) = ctx->r15;
L_801C6D4C:
    // 0x801C6D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C6D50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C6D54: jr          $ra
    // 0x801C6D58: nop

    return;
    // 0x801C6D58: nop

;}
RECOMP_FUNC void M24_FUN_801c6d5c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C6D5C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C6D60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801C6D64: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C6D68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C6D6C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801C6D70: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C6D74: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801C6D78: jal         0x80005E44
    // 0x801C6D7C: addiu       $a1, $a1, -0x5A6C
    ctx->r5 = ADD32(ctx->r5, -0X5A6C);
    LOOKUP_FUNC(0x80005E44)(rdram, ctx);
        goto after_0;
    // 0x801C6D7C: addiu       $a1, $a1, -0x5A6C
    ctx->r5 = ADD32(ctx->r5, -0X5A6C);
    after_0:
    // 0x801C6D80: jal         0x80006214
    // 0x801C6D84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801C6D84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801C6D88: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C6D8C: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801C6D90: addiu       $t8, $t8, -0x66F8
    ctx->r24 = ADD32(ctx->r24, -0X66F8);
    // 0x801C6D94: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C6D98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C6D9C: addiu       $a2, $zero, 0x474
    ctx->r6 = ADD32(0, 0X474);
    // 0x801C6DA0: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    // 0x801C6DA4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C6DA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801C6DAC: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x801C6DB0: sw          $t8, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r24;
    // 0x801C6DB4: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C6DB8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C6DBC: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x801C6DC0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C6DC4: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x801C6DC8: sh          $zero, 0x2C($t4)
    MEM_H(0X2C, ctx->r12) = 0;
    // 0x801C6DCC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C6DD0: lw          $a1, 0x30($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X30);
    // 0x801C6DD4: jal         0x8012CF8C
    // 0x801C6DD8: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_2;
    // 0x801C6DD8: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_2:
    // 0x801C6DDC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C6DE0: lwc1        $f4, 0x90($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X90);
    // 0x801C6DE4: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801C6DE8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C6DEC: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x801C6DF0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C6DF4: lwc1        $f6, 0x94($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X94);
    // 0x801C6DF8: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x801C6DFC: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x801C6E00: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C6E04: lwc1        $f8, 0x98($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X98);
    // 0x801C6E08: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C6E0C: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x801C6E10: lw          $t2, -0x4328($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4328);
    // 0x801C6E14: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x801C6E18: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C6E1C: lwc1        $f16, 0x30($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801C6E20: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C6E24: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801C6E28: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801C6E2C: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801C6E30: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C6E34: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801C6E38: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801C6E3C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801C6E40: jal         0x8002FC20
    // 0x801C6E44: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_3;
    // 0x801C6E44: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_3:
    // 0x801C6E48: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801C6E4C: lw          $t3, -0x4328($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4328);
    // 0x801C6E50: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801C6E54: lw          $v0, 0x2C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X2C);
    // 0x801C6E58: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801C6E5C: lwc1        $f16, 0x34($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801C6E60: jal         0x8001EF38
    // 0x801C6E64: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_4;
    // 0x801C6E64: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    after_4:
    // 0x801C6E68: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C6E6C: andi        $t4, $v0, 0x1FFF
    ctx->r12 = ctx->r2 & 0X1FFF;
    // 0x801C6E70: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x801C6E74: sh          $t4, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r12;
    // 0x801C6E78: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C6E7C: jal         0x8001EF38
    // 0x801C6E80: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_5;
    // 0x801C6E80: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x801C6E84: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C6E88: addiu       $t8, $v0, 0x1000
    ctx->r24 = ADD32(ctx->r2, 0X1000);
    // 0x801C6E8C: andi        $t0, $t8, 0x1FFF
    ctx->r8 = ctx->r24 & 0X1FFF;
    // 0x801C6E90: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801C6E94: addiu       $t8, $zero, 0x300
    ctx->r24 = ADD32(0, 0X300);
    // 0x801C6E98: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801C6E9C: sh          $t0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r8;
    // 0x801C6EA0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801C6EA4: lwc1        $f18, 0x9C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x801C6EA8: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x801C6EAC: swc1        $f18, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f18.u32l;
    // 0x801C6EB0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801C6EB4: lwc1        $f4, 0xA0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x801C6EB8: lw          $t6, 0x30($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X30);
    // 0x801C6EBC: swc1        $f4, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f4.u32l;
    // 0x801C6EC0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801C6EC4: lwc1        $f6, 0xA4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x801C6EC8: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x801C6ECC: swc1        $f6, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f6.u32l;
    // 0x801C6ED0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801C6ED4: lw          $t0, 0x30($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X30);
    // 0x801C6ED8: sw          $t8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r24;
    // 0x801C6EDC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C6EE0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C6EE4: sb          $v1, 0x48($t3)
    MEM_B(0X48, ctx->r11) = ctx->r3;
    // 0x801C6EE8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801C6EEC: lw          $t4, 0x30($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X30);
    // 0x801C6EF0: sb          $v1, 0x49($t4)
    MEM_B(0X49, ctx->r12) = ctx->r3;
    // 0x801C6EF4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C6EF8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C6EFC: sb          $v1, 0x4A($t7)
    MEM_B(0X4A, ctx->r15) = ctx->r3;
    // 0x801C6F00: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C6F04: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C6F08: jal         0x801C78F8
    // 0x801C6F0C: sb          $v1, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r3;
    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_6;
    // 0x801C6F0C: sb          $v1, 0x4B($t1)
    MEM_B(0X4B, ctx->r9) = ctx->r3;
    after_6:
    // 0x801C6F10: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x801C6F14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C6F18: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x801C6F1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801C6F20: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801C6F24: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C6F28: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C6F2C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801C6F30: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C6F34: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801C6F38: nop

    // 0x801C6F3C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801C6F40: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801C6F44: nop

    // 0x801C6F48: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801C6F4C: beql        $t0, $zero, L_801C6F9C
    if (ctx->r8 == 0) {
        // 0x801C6F50: mfc1        $t0, $f4
        ctx->r8 = (int32_t)ctx->f4.u32l;
            goto L_801C6F9C;
    }
    goto skip_0;
    // 0x801C6F50: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x801C6F54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C6F58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801C6F5C: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801C6F60: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801C6F64: nop

    // 0x801C6F68: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801C6F6C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801C6F70: nop

    // 0x801C6F74: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801C6F78: bne         $t0, $zero, L_801C6F90
    if (ctx->r8 != 0) {
        // 0x801C6F7C: nop
    
            goto L_801C6F90;
    }
    // 0x801C6F7C: nop

    // 0x801C6F80: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x801C6F84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C6F88: b           L_801C6FA8
    // 0x801C6F8C: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_801C6FA8;
    // 0x801C6F8C: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_801C6F90:
    // 0x801C6F90: b           L_801C6FA8
    // 0x801C6F94: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_801C6FA8;
    // 0x801C6F94: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801C6F98: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
L_801C6F9C:
    // 0x801C6F9C: nop

    // 0x801C6FA0: bltz        $t0, L_801C6F90
    if (SIGNED(ctx->r8) < 0) {
        // 0x801C6FA4: nop
    
            goto L_801C6F90;
    }
    // 0x801C6FA4: nop

L_801C6FA8:
    // 0x801C6FA8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801C6FAC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C6FB0: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x801C6FB4: jal         0x801C78F8
    // 0x801C6FB8: sb          $t0, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = ctx->r8;
    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_7;
    // 0x801C6FB8: sb          $t0, 0x4C($t3)
    MEM_B(0X4C, ctx->r11) = ctx->r8;
    after_7:
    // 0x801C6FBC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x801C6FC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801C6FC4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C6FC8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C6FCC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801C6FD0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801C6FD4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801C6FD8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C6FDC: nop

    // 0x801C6FE0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C6FE4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C6FE8: nop

    // 0x801C6FEC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801C6FF0: beql        $t4, $zero, L_801C7040
    if (ctx->r12 == 0) {
        // 0x801C6FF4: mfc1        $t4, $f10
        ctx->r12 = (int32_t)ctx->f10.u32l;
            goto L_801C7040;
    }
    goto skip_1;
    // 0x801C6FF4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x801C6FF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C6FFC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801C7000: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801C7004: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801C7008: nop

    // 0x801C700C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C7010: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801C7014: nop

    // 0x801C7018: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801C701C: bne         $t4, $zero, L_801C7034
    if (ctx->r12 != 0) {
        // 0x801C7020: nop
    
            goto L_801C7034;
    }
    // 0x801C7020: nop

    // 0x801C7024: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x801C7028: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C702C: b           L_801C704C
    // 0x801C7030: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801C704C;
    // 0x801C7030: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801C7034:
    // 0x801C7034: b           L_801C704C
    // 0x801C7038: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801C704C;
    // 0x801C7038: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801C703C: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
L_801C7040:
    // 0x801C7040: nop

    // 0x801C7044: bltz        $t4, L_801C7034
    if (SIGNED(ctx->r12) < 0) {
        // 0x801C7048: nop
    
            goto L_801C7034;
    }
    // 0x801C7048: nop

L_801C704C:
    // 0x801C704C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801C7050: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801C7054: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801C7058: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x801C705C: addiu       $a1, $a1, 0x70A0
    ctx->r5 = ADD32(ctx->r5, 0X70A0);
    // 0x801C7060: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801C7064: sb          $t4, 0x4D($t7)
    MEM_B(0X4D, ctx->r15) = ctx->r12;
    // 0x801C7068: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801C706C: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x801C7070: sb          $zero, 0x4E($t1)
    MEM_B(0X4E, ctx->r9) = 0;
    // 0x801C7074: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801C7078: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x801C707C: sb          $v1, 0x4F($t2)
    MEM_B(0X4F, ctx->r10) = ctx->r3;
    // 0x801C7080: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801C7084: jal         0x800058DC
    // 0x801C7088: sb          $zero, 0x22($t0)
    MEM_B(0X22, ctx->r8) = 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_8;
    // 0x801C7088: sb          $zero, 0x22($t0)
    MEM_B(0X22, ctx->r8) = 0;
    after_8:
    // 0x801C708C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C7090: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801C7094: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801C7098: jr          $ra
    // 0x801C709C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801C709C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c70a0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c70a0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C70A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801C70A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801C70A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801C70AC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801C70B0: lhu         $t6, 0xB0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XB0);
    // 0x801C70B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801C70B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C70BC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801C70C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801C70C4: bgez        $t6, L_801C70D8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801C70C8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801C70D8;
    }
    // 0x801C70C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801C70CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801C70D0: nop

    // 0x801C70D4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801C70D8:
    // 0x801C70D8: lhu         $t7, 0xB2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XB2);
    // 0x801C70DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801C70E0: addiu       $a2, $zero, 0x474
    ctx->r6 = ADD32(0, 0X474);
    // 0x801C70E4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801C70E8: bgez        $t7, L_801C70FC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801C70EC: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801C70FC;
    }
    // 0x801C70EC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801C70F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801C70F4: nop

    // 0x801C70F8: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801C70FC:
    // 0x801C70FC: div.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801C7100: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801C7104: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801C7108: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801C710C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801C7110: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801C7114: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801C7118: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x801C711C: nop

    // 0x801C7120: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801C7124: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x801C7128: nop

    // 0x801C712C: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x801C7130: beql        $v1, $zero, L_801C7180
    if (ctx->r3 == 0) {
        // 0x801C7134: mfc1        $v1, $f10
        ctx->r3 = (int32_t)ctx->f10.u32l;
            goto L_801C7180;
    }
    goto skip_0;
    // 0x801C7134: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x801C7138: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801C713C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801C7140: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801C7144: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x801C7148: nop

    // 0x801C714C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801C7150: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x801C7154: nop

    // 0x801C7158: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x801C715C: bne         $v1, $zero, L_801C7174
    if (ctx->r3 != 0) {
        // 0x801C7160: nop
    
            goto L_801C7174;
    }
    // 0x801C7160: nop

    // 0x801C7164: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x801C7168: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801C716C: b           L_801C718C
    // 0x801C7170: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_801C718C;
    // 0x801C7170: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_801C7174:
    // 0x801C7174: b           L_801C718C
    // 0x801C7178: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_801C718C;
    // 0x801C7178: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x801C717C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
L_801C7180:
    // 0x801C7180: nop

    // 0x801C7184: bltz        $v1, L_801C7174
    if (SIGNED(ctx->r3) < 0) {
        // 0x801C7188: nop
    
            goto L_801C7174;
    }
    // 0x801C7188: nop

L_801C718C:
    // 0x801C718C: lhu         $t9, 0xA8($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XA8);
    // 0x801C7190: lhu         $t1, 0xAA($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XAA);
    // 0x801C7194: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801C7198: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x801C719C: andi        $t2, $t0, 0xFFFF
    ctx->r10 = ctx->r8 & 0XFFFF;
    // 0x801C71A0: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x801C71A4: beq         $at, $zero, L_801C729C
    if (ctx->r1 == 0) {
        // 0x801C71A8: sh          $t0, 0xA8($s0)
        MEM_H(0XA8, ctx->r16) = ctx->r8;
            goto L_801C729C;
    }
    // 0x801C71A8: sh          $t0, 0xA8($s0)
    MEM_H(0XA8, ctx->r16) = ctx->r8;
    // 0x801C71AC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x801C71B0: andi        $v0, $v1, 0x7
    ctx->r2 = ctx->r3 & 0X7;
    // 0x801C71B4: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x801C71B8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801C71BC: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801C71C0: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x801C71C4: lw          $a1, 0x30($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X30);
    // 0x801C71C8: lw          $a3, -0x5A5C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5A5C);
    // 0x801C71CC: jal         0x8012CF8C
    // 0x801C71D0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    LOOKUP_FUNC(0x8012CF8C)(rdram, ctx);
        goto after_0;
    // 0x801C71D0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x801C71D4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x801C71D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801C71DC: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801C71E0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801C71E4: sb          $t6, 0x22($t8)
    MEM_B(0X22, ctx->r24) = ctx->r14;
    // 0x801C71E8: lw          $t9, -0x4328($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4328);
    // 0x801C71EC: lw          $v0, 0x2C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X2C);
    // 0x801C71F0: lwc1        $f18, 0x3C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801C71F4: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801C71F8: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801C71FC: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801C7200: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x801C7204: sub.s       $f14, $f16, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x801C7208: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x801C720C: jal         0x8001EF38
    // 0x801C7210: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_1;
    // 0x801C7210: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x801C7214: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C7218: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C721C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x801C7220: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801C7224: addiu       $t2, $v0, 0x1000
    ctx->r10 = ADD32(ctx->r2, 0X1000);
    // 0x801C7228: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801C722C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801C7230: andi        $t3, $t2, 0x1FFF
    ctx->r11 = ctx->r10 & 0X1FFF;
    // 0x801C7234: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x801C7238: sh          $t3, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r11;
    // 0x801C723C: jal         0x8002FC20
    // 0x801C7240: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x801C7240: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x801C7244: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801C7248: lw          $t6, -0x4328($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4328);
    // 0x801C724C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801C7250: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801C7254: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801C7258: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801C725C: jal         0x8001EF38
    // 0x801C7260: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    LOOKUP_FUNC(0x8001EF38)(rdram, ctx);
        goto after_3;
    // 0x801C7260: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    after_3:
    // 0x801C7264: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801C7268: andi        $t8, $v0, 0x1FFF
    ctx->r24 = ctx->r2 & 0X1FFF;
    // 0x801C726C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801C7270: lw          $t1, 0x30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X30);
    // 0x801C7274: sh          $t8, 0x10($t1)
    MEM_H(0X10, ctx->r9) = ctx->r24;
    // 0x801C7278: lhu         $t2, 0xB0($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XB0);
    // 0x801C727C: lhu         $t5, 0xB2($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XB2);
    // 0x801C7280: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x801C7284: andi        $t3, $t4, 0xFFFF
    ctx->r11 = ctx->r12 & 0XFFFF;
    // 0x801C7288: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801C728C: beq         $at, $zero, L_801C729C
    if (ctx->r1 == 0) {
        // 0x801C7290: sh          $t4, 0xB0($s0)
        MEM_H(0XB0, ctx->r16) = ctx->r12;
            goto L_801C729C;
    }
    // 0x801C7290: sh          $t4, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r12;
    // 0x801C7294: jal         0x80005700
    // 0x801C7298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80005700)(rdram, ctx);
        goto after_4;
    // 0x801C7298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_801C729C:
    // 0x801C729C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801C72A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801C72A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801C72A8: jr          $ra
    // 0x801C72AC: nop

    return;
    // 0x801C72AC: nop

;}
RECOMP_FUNC void M24_FUN_801c72b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C72B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801C72B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C72B8: jal         0x801C78C0
    // 0x801C72BC: nop

    LOOKUP_FUNC(0x801C78C0)(rdram, ctx);
        goto after_0;
    // 0x801C72BC: nop

    after_0:
    // 0x801C72C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C72C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801C72C8: jr          $ra
    // 0x801C72CC: nop

    return;
    // 0x801C72CC: nop

;}
RECOMP_FUNC void M24_FUN_801c72d0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C72D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801C72D4: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801C72D8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801C72DC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801C72E0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801C72E4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801C72E8: beq         $a0, $zero, L_801C7348
    if (ctx->r4 == 0) {
        // 0x801C72EC: sw          $s0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r16;
            goto L_801C7348;
    }
    // 0x801C72EC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801C72F0: beq         $a0, $zero, L_801C7348
    if (ctx->r4 == 0) {
        // 0x801C72F4: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_801C7348;
    }
    // 0x801C72F4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801C72F8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801C72FC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_801C7300:
    // 0x801C7300: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801C7304: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801C7308: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801C730C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x801C7310: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x801C7314: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801C7318: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801C731C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801C7320: lw          $t6, 0x18($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X18);
    // 0x801C7324: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801C7328: lw          $t7, 0x1C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1C);
    // 0x801C732C: jal         0x801C7364
    // 0x801C7330: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x801C7364)(rdram, ctx);
        goto after_0;
    // 0x801C7330: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x801C7334: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801C7338: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x801C733C: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x801C7340: bne         $at, $zero, L_801C7300
    if (ctx->r1 != 0) {
        // 0x801C7344: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_801C7300;
    }
    // 0x801C7344: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
L_801C7348:
    // 0x801C7348: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801C734C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801C7350: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801C7354: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801C7358: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801C735C: jr          $ra
    // 0x801C7360: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801C7360: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801c7364(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801c7364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801C7364: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801C7368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801C736C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x801C7370: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801C7374: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x801C7378: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801C737C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801C7380: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801C7384: addiu       $a1, $a1, -0x5A3C
    ctx->r5 = ADD32(ctx->r5, -0X5A3C);
    // 0x801C7388: jal         0x80005670
    // 0x801C738C: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    LOOKUP_FUNC(0x80005670)(rdram, ctx);
        goto after_0;
    // 0x801C738C: lw          $a0, -0x2734($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2734);
    after_0:
    // 0x801C7390: bne         $v0, $zero, L_801C73A0
    if (ctx->r2 != 0) {
        // 0x801C7394: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801C73A0;
    }
    // 0x801C7394: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801C7398: b           L_801C7414
    // 0x801C739C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801C7414;
    // 0x801C739C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801C73A0:
    // 0x801C73A0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801C73A4: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801C73A8: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801C73AC: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x801C73B0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801C73B4: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
    // 0x801C73B8: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801C73BC: swc1        $f10, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f10.u32l;
    // 0x801C73C0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801C73C4: swc1        $f16, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f16.u32l;
    // 0x801C73C8: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801C73CC: sh          $zero, 0xA8($v1)
    MEM_H(0XA8, ctx->r3) = 0;
    // 0x801C73D0: swc1        $f18, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f18.u32l;
    // 0x801C73D4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x801C73D8: sh          $t6, 0xAA($v1)
    MEM_H(0XAA, ctx->r3) = ctx->r14;
    // 0x801C73DC: jal         0x801C78F8
    // 0x801C73E0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(0x801C78F8)(rdram, ctx);
        goto after_1;
    // 0x801C73E0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x801C73E4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C73E8: lwc1        $f4, -0x2DC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2DC4);
    // 0x801C73EC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801C73F0: lwc1        $f8, -0x2DC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2DC0);
    // 0x801C73F4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801C73F8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801C73FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801C7400: sh          $zero, 0xB0($v1)
    MEM_H(0XB0, ctx->r3) = 0;
    // 0x801C7404: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801C7408: swc1        $f10, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = ctx->f10.u32l;
    // 0x801C740C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801C7410: sh          $t7, 0xB2($v1)
    MEM_H(0XB2, ctx->r3) = ctx->r15;
L_801C7414:
    // 0x801C7414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801C7418: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801C741C: jr          $ra
    // 0x801C7420: nop

    return;
    // 0x801C7420: nop

;}
