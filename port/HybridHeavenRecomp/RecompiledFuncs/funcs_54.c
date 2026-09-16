#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void M24_FUN_801d3620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3620: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D3624: lw          $v0, -0x4C88($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C88);
    // 0x801D3628: jr          $ra
    // 0x801D362C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D362C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d3630(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d3630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3630: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D3634: lw          $t6, -0x4C88($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C88);
    // 0x801D3638: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D363C: beq         $t6, $zero, L_801D364C
    if (ctx->r14 == 0) {
            // 0x801D3640: nop

    LOOKUP_FUNC(0x801D364C)(rdram, ctx);
    return;
    }
    // 0x801D3640: nop

    // 0x801D3644: jr          $ra
    // 0x801D3648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D3648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d364c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d364c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D364C: lw          $t7, -0x4C8C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C8C);
    // 0x801D3650: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D3654: beq         $t7, $zero, L_801D3664
    if (ctx->r15 == 0) {
            // 0x801D3658: nop

    LOOKUP_FUNC(0x801D3664)(rdram, ctx);
    return;
    }
    // 0x801D3658: nop

    // 0x801D365C: jr          $ra
    // 0x801D3660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D3660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d3664(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d3664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3664: lw          $v0, -0x4C84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C84);
    // 0x801D3668: jr          $ra
    // 0x801D366C: nop

    return;
    // 0x801D366C: nop

;}
RECOMP_FUNC void M24_FUN_801d3670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3670: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D3674: jr          $ra
    // 0x801D3678: addiu       $v0, $v0, 0x14A8
    ctx->r2 = ADD32(ctx->r2, 0X14A8);
    return;
    // 0x801D3678: addiu       $v0, $v0, 0x14A8
    ctx->r2 = ADD32(ctx->r2, 0X14A8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d367c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d367c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D367C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3680: jr          $ra
    // 0x801D3684: sw          $a0, -0x4C80($at)
    MEM_W(-0X4C80, ctx->r1) = ctx->r4;
    return;
    // 0x801D3684: sw          $a0, -0x4C80($at)
    MEM_W(-0X4C80, ctx->r1) = ctx->r4;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d3688(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d3688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3688: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D368C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D3690: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801D3694: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801D3698: beq         $a0, $zero, L_801D36F0
    if (ctx->r4 == 0) {
        // 0x801D369C: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_801D36F0;
    }
    // 0x801D369C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801D36A0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D36A4: jal         0x80006214
    // 0x801D36A8: lw          $a0, 0x14A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14A0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D36A8: lw          $a0, 0x14A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14A0);
    after_0:
    // 0x801D36AC: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x801D36B0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801D36B4: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x801D36B8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D36BC: lw          $a0, 0x14A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14A0);
    // 0x801D36C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801D36C4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801D36C8: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x801D36CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801D36D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801D36D4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801D36D8: jal         0x801C3370
    // 0x801D36DC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x801C3370)(rdram, ctx);
        goto after_1;
    // 0x801D36DC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_1:
    // 0x801D36E0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801D36E4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D36E8: b           L_801D36F8
    // 0x801D36EC: sw          $t9, -0x4C7C($at)
    MEM_W(-0X4C7C, ctx->r1) = ctx->r25;
        goto L_801D36F8;
    // 0x801D36EC: sw          $t9, -0x4C7C($at)
    MEM_W(-0X4C7C, ctx->r1) = ctx->r25;
L_801D36F0:
    // 0x801D36F0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D36F4: sw          $zero, -0x4C7C($at)
    MEM_W(-0X4C7C, ctx->r1) = 0;
L_801D36F8:
    // 0x801D36F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801D36FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D3700: jr          $ra
    // 0x801D3704: nop

    return;
    // 0x801D3704: nop

;}
RECOMP_FUNC void M24_FUN_801d3708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3708: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D370C: lw          $v0, -0x4C7C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C7C);
    // 0x801D3710: jr          $ra
    // 0x801D3714: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x801D3714: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d3718(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d3718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3718: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D371C: addiu       $v1, $v1, 0x14B8
    ctx->r3 = ADD32(ctx->r3, 0X14B8);
    // 0x801D3720: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D3724: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801D3728: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x801D372C: beql        $a0, $t6, L_801D3740
    if (ctx->r4 == ctx->r14) {
        // 0x801D3730: lhu         $t7, 0x4($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X4);
            goto L_801D3740;
    }
    goto skip_0;
    // 0x801D3730: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x801D3734: jr          $ra
    // 0x801D3738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D3738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D373C: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
L_801D3740:
    // 0x801D3740: xor         $v0, $a1, $t7
    ctx->r2 = ctx->r5 ^ ctx->r15;
    // 0x801D3744: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D3748: jr          $ra
    // 0x801D374C: nop

    return;
    // 0x801D374C: nop

;}
RECOMP_FUNC void M24_FUN_801d3750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D3754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D3758: beq         $a0, $zero, L_801D3774
    if (ctx->r4 == 0) {
        // 0x801D375C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_801D3774;
    }
    // 0x801D375C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801D3760: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D3764: lw          $a0, 0x14A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14A0);
    // 0x801D3768: jal         0x801D4008
    // 0x801D376C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801D4008)(rdram, ctx);
        goto after_0;
    // 0x801D376C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D3770: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_801D3774:
    // 0x801D3774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D3778: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D377C: sw          $a1, -0x4C74($at)
    MEM_W(-0X4C74, ctx->r1) = ctx->r5;
    // 0x801D3780: jr          $ra
    // 0x801D3784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801D3784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d3788(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d3788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D378C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801D3790: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D3794: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801D3798: addiu       $v0, $v0, 0x14C8
    ctx->r2 = ADD32(ctx->r2, 0X14C8);
    // 0x801D379C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D37A0: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x801D37A4: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x801D37A8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D37AC: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801D37B0: jal         0x80006214
    // 0x801D37B4: lw          $a0, 0x14A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14A0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D37B4: lw          $a0, 0x14A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14A0);
    after_0:
    // 0x801D37B8: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D37BC: lw          $t6, 0x14A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X14A0);
    // 0x801D37C0: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x801D37C4: addiu       $t5, $t5, -0x6C48
    ctx->r13 = ADD32(ctx->r13, -0X6C48);
    // 0x801D37C8: lw          $t0, 0x5C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X5C);
    // 0x801D37CC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801D37D0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801D37D4: lhu         $a1, 0xC($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0XC);
    // 0x801D37D8: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x801D37DC: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801D37E0: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x801D37E4: bne         $at, $zero, L_801D38A0
    if (ctx->r1 != 0) {
        // 0x801D37E8: addiu       $a2, $v0, 0x4
        ctx->r6 = ADD32(ctx->r2, 0X4);
            goto L_801D38A0;
    }
    // 0x801D37E8: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x801D37EC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x801D37F0: addiu       $t1, $t1, -0x2578
    ctx->r9 = ADD32(ctx->r9, -0X2578);
    // 0x801D37F4: addiu       $t3, $t3, -0x6CA0
    ctx->r11 = ADD32(ctx->r11, -0X6CA0);
    // 0x801D37F8: addiu       $t2, $zero, 0x15
    ctx->r10 = ADD32(0, 0X15);
    // 0x801D37FC: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
L_801D3800:
    // 0x801D3800: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x801D3804: addu        $v0, $t1, $a0
    ctx->r2 = ADD32(ctx->r9, ctx->r4);
    // 0x801D3808: bgezl       $t7, L_801D381C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801D380C: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_801D381C;
    }
    goto skip_0;
    // 0x801D380C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x801D3810: b           L_801D3890
    // 0x801D3814: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
        goto L_801D3890;
    // 0x801D3814: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x801D3818: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_801D381C:
    // 0x801D381C: lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X2C);
    // 0x801D3820: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x801D3824: ori         $t6, $t9, 0x100
    ctx->r14 = ctx->r25 | 0X100;
    // 0x801D3828: sw          $t6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r14;
    // 0x801D382C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D3830: or          $t6, $t3, $a3
    ctx->r14 = ctx->r11 | ctx->r7;
    // 0x801D3834: lw          $v1, 0x2C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X2C);
    // 0x801D3838: or          $t7, $t5, $a3
    ctx->r15 = ctx->r13 | ctx->r7;
    // 0x801D383C: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x801D3840: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801D3844: bnel        $t2, $t9, L_801D3858
    if (ctx->r10 != ctx->r25) {
        // 0x801D3848: sw          $t7, 0x30($v1)
        MEM_W(0X30, ctx->r3) = ctx->r15;
            goto L_801D3858;
    }
    goto skip_1;
    // 0x801D3848: sw          $t7, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r15;
    skip_1:
    // 0x801D384C: b           L_801D3858
    // 0x801D3850: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
        goto L_801D3858;
    // 0x801D3850: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    // 0x801D3854: sw          $t7, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r15;
L_801D3858:
    // 0x801D3858: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801D385C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D3860: sb          $zero, 0x48($t9)
    MEM_B(0X48, ctx->r25) = 0;
    // 0x801D3864: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D3868: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801D386C: sb          $zero, 0x49($t7)
    MEM_B(0X49, ctx->r15) = 0;
    // 0x801D3870: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801D3874: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D3878: sb          $zero, 0x4A($t9)
    MEM_B(0X4A, ctx->r25) = 0;
    // 0x801D387C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D3880: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801D3884: sb          $t4, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = ctx->r12;
    // 0x801D3888: lhu         $a1, 0xC($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0XC);
    // 0x801D388C: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
L_801D3890:
    // 0x801D3890: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801D3894: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801D3898: bne         $at, $zero, L_801D3800
    if (ctx->r1 != 0) {
        // 0x801D389C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_801D3800;
    }
    // 0x801D389C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_801D38A0:
    // 0x801D38A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D38A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D38A8: sw          $zero, -0x4C70($at)
    MEM_W(-0X4C70, ctx->r1) = 0;
    // 0x801D38AC: jr          $ra
    // 0x801D38B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801D38B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d38b4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d38b4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D38B4: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x801D38B8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D38BC: addiu       $v1, $v1, -0x4C70
    ctx->r3 = ADD32(ctx->r3, -0X4C70);
    // 0x801D38C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801D38C4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801D38C8: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x801D38CC: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x801D38D0: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x801D38D4: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x801D38D8: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x801D38DC: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x801D38E0: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x801D38E4: beq         $at, $zero, L_801D3FAC
    if (ctx->r1 == 0) {
        // 0x801D38E8: sdc1        $f20, 0x28($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
            goto L_801D3FAC;
    }
    // 0x801D38E8: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801D38EC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801D38F0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D38F4: addu        $at, $at, $t6
    gpr jr_addend_801D38FC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801D38F8: lw          $t6, -0x2AE8($at)
    ctx->r14 = ADD32(ctx->r1, -0X2AE8);
    // 0x801D38FC: jr          $t6
    // 0x801D3900: nop

    switch (jr_addend_801D38FC >> 2) {
        case 0: goto L_801D3904; break;
        case 1: goto L_801D3918; break;
        case 2: goto L_801D3AF0; break;
        case 3: goto L_801D3CF8; break;
        case 4: goto L_801D3E3C; break;
        case 5: goto L_801D3FA4; break;
        default: switch_error(__func__, 0x801D38FC, 0x801DD518);
    }
    // 0x801D3900: nop

L_801D3904:
    // 0x801D3904: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x801D3908: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801D390C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3910: b           L_801D3FAC
    // 0x801D3914: sw          $zero, 0x14D4($at)
    MEM_W(0X14D4, ctx->r1) = 0;
        goto L_801D3FAC;
    // 0x801D3914: sw          $zero, 0x14D4($at)
    MEM_W(0X14D4, ctx->r1) = 0;
L_801D3918:
    // 0x801D3918: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801D391C: addiu       $s0, $s0, 0x14A0
    ctx->r16 = ADD32(ctx->r16, 0X14A0);
    // 0x801D3920: jal         0x80006214
    // 0x801D3924: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D3924: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x801D3928: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801D392C: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x801D3930: lui         $ra, 0x801E
    ctx->r31 = S32(0X801E << 16);
    // 0x801D3934: lw          $t2, 0x5C($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X5C);
    // 0x801D3938: addiu       $ra, $ra, -0x6C48
    ctx->r31 = ADD32(ctx->r31, -0X6C48);
    // 0x801D393C: addiu       $s1, $s1, -0x2578
    ctx->r17 = ADD32(ctx->r17, -0X2578);
    // 0x801D3940: lhu         $a2, 0xC($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0XC);
    // 0x801D3944: lw          $v0, 0x4($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X4);
    // 0x801D3948: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x801D394C: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x801D3950: bne         $at, $zero, L_801D3AB8
    if (ctx->r1 != 0) {
        // 0x801D3954: addiu       $a3, $v0, 0x4
        ctx->r7 = ADD32(ctx->r2, 0X4);
            goto L_801D3AB8;
    }
    // 0x801D3954: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    // 0x801D3958: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x801D395C: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D3960: lw          $t1, 0x14D4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X14D4);
    // 0x801D3964: addiu       $t4, $t4, -0x6CA0
    ctx->r12 = ADD32(ctx->r12, -0X6CA0);
    // 0x801D3968: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x801D396C: addiu       $t3, $zero, 0x15
    ctx->r11 = ADD32(0, 0X15);
    // 0x801D3970: lui         $t0, 0x4000
    ctx->r8 = S32(0X4000 << 16);
L_801D3974:
    // 0x801D3974: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x801D3978: bgezl       $t9, L_801D398C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801D397C: mtc1        $t1, $f4
        ctx->f4.u32l = ctx->r9;
            goto L_801D398C;
    }
    goto skip_0;
    // 0x801D397C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    skip_0:
    // 0x801D3980: b           L_801D3AA8
    // 0x801D3984: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
        goto L_801D3AA8;
    // 0x801D3984: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x801D3988: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
L_801D398C:
    // 0x801D398C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801D3990: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D3994: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D3998: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801D399C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801D39A0: addu        $v0, $s1, $a1
    ctx->r2 = ADD32(ctx->r17, ctx->r5);
    // 0x801D39A4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D39A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801D39AC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801D39B0: lw          $v1, 0x2C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X2C);
    // 0x801D39B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D39B8: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x801D39BC: ori         $t8, $t7, 0x100
    ctx->r24 = ctx->r15 | 0X100;
    // 0x801D39C0: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x801D39C4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801D39C8: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x801D39CC: or          $t9, $t4, $t0
    ctx->r25 = ctx->r12 | ctx->r8;
    // 0x801D39D0: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x801D39D4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801D39D8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801D39DC: nop

    // 0x801D39E0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801D39E4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801D39E8: nop

    // 0x801D39EC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801D39F0: beql        $a0, $zero, L_801D3A40
    if (ctx->r4 == 0) {
        // 0x801D39F4: mfc1        $a0, $f4
        ctx->r4 = (int32_t)ctx->f4.u32l;
            goto L_801D3A40;
    }
    goto skip_1;
    // 0x801D39F4: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x801D39F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D39FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801D3A00: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801D3A04: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x801D3A08: nop

    // 0x801D3A0C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D3A10: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x801D3A14: nop

    // 0x801D3A18: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x801D3A1C: bne         $a0, $zero, L_801D3A34
    if (ctx->r4 != 0) {
        // 0x801D3A20: nop
    
            goto L_801D3A34;
    }
    // 0x801D3A20: nop

    // 0x801D3A24: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x801D3A28: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D3A2C: b           L_801D3A4C
    // 0x801D3A30: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_801D3A4C;
    // 0x801D3A30: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_801D3A34:
    // 0x801D3A34: b           L_801D3A4C
    // 0x801D3A38: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_801D3A4C;
    // 0x801D3A38: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801D3A3C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
L_801D3A40:
    // 0x801D3A40: nop

    // 0x801D3A44: bltz        $a0, L_801D3A34
    if (SIGNED(ctx->r4) < 0) {
        // 0x801D3A48: nop
    
            goto L_801D3A34;
    }
    // 0x801D3A48: nop

L_801D3A4C:
    // 0x801D3A4C: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x801D3A50: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801D3A54: or          $t6, $ra, $t0
    ctx->r14 = ctx->r31 | ctx->r8;
    // 0x801D3A58: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801D3A5C: bnel        $t3, $t8, L_801D3A70
    if (ctx->r11 != ctx->r24) {
        // 0x801D3A60: sw          $t6, 0x30($v1)
        MEM_W(0X30, ctx->r3) = ctx->r14;
            goto L_801D3A70;
    }
    goto skip_2;
    // 0x801D3A60: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    skip_2:
    // 0x801D3A64: b           L_801D3A70
    // 0x801D3A68: sw          $t9, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r25;
        goto L_801D3A70;
    // 0x801D3A68: sw          $t9, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r25;
    // 0x801D3A6C: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
L_801D3A70:
    // 0x801D3A70: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D3A74: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D3A78: sb          $a0, 0x48($t8)
    MEM_B(0X48, ctx->r24) = ctx->r4;
    // 0x801D3A7C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801D3A80: lw          $t6, 0x2C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X2C);
    // 0x801D3A84: sb          $a0, 0x49($t6)
    MEM_B(0X49, ctx->r14) = ctx->r4;
    // 0x801D3A88: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801D3A8C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D3A90: sb          $a0, 0x4A($t8)
    MEM_B(0X4A, ctx->r24) = ctx->r4;
    // 0x801D3A94: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801D3A98: lw          $t6, 0x2C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X2C);
    // 0x801D3A9C: sb          $t5, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = ctx->r13;
    // 0x801D3AA0: lhu         $a2, 0xC($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0XC);
    // 0x801D3AA4: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
L_801D3AA8:
    // 0x801D3AA8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x801D3AAC: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801D3AB0: bne         $at, $zero, L_801D3974
    if (ctx->r1 != 0) {
        // 0x801D3AB4: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_801D3974;
    }
    // 0x801D3AB4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_801D3AB8:
    // 0x801D3AB8: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D3ABC: lw          $t1, 0x14D4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X14D4);
    // 0x801D3AC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3AC4: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D3AC8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x801D3ACC: sw          $t1, 0x14D4($at)
    MEM_W(0X14D4, ctx->r1) = ctx->r9;
    // 0x801D3AD0: slti        $at, $t1, 0x79
    ctx->r1 = SIGNED(ctx->r9) < 0X79 ? 1 : 0;
    // 0x801D3AD4: bnel        $at, $zero, L_801D3FB0
    if (ctx->r1 != 0) {
        // 0x801D3AD8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801D3FB0;
    }
    goto skip_3;
    // 0x801D3AD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x801D3ADC: lw          $t7, -0x4C70($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C70);
    // 0x801D3AE0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3AE4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801D3AE8: b           L_801D3FAC
    // 0x801D3AEC: sw          $t8, -0x4C70($at)
    MEM_W(-0X4C70, ctx->r1) = ctx->r24;
        goto L_801D3FAC;
    // 0x801D3AEC: sw          $t8, -0x4C70($at)
    MEM_W(-0X4C70, ctx->r1) = ctx->r24;
L_801D3AF0:
    // 0x801D3AF0: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801D3AF4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801D3AF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3AFC: addiu       $s0, $s0, 0x14A0
    ctx->r16 = ADD32(ctx->r16, 0X14A0);
    // 0x801D3B00: sw          $t9, -0x4C78($at)
    MEM_W(-0X4C78, ctx->r1) = ctx->r25;
    // 0x801D3B04: jal         0x80006214
    // 0x801D3B08: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_1;
    // 0x801D3B08: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x801D3B0C: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801D3B10: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3B14: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x801D3B18: addiu       $s1, $s1, -0x2578
    ctx->r17 = ADD32(ctx->r17, -0X2578);
    // 0x801D3B1C: lwc1        $f20, -0x2AD0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2AD0);
    // 0x801D3B20: addiu       $s0, $s0, -0x4C6C
    ctx->r16 = ADD32(ctx->r16, -0X4C6C);
    // 0x801D3B24: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801D3B28: addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
    // 0x801D3B2C: addiu       $s4, $sp, 0xA0
    ctx->r20 = ADD32(ctx->r29, 0XA0);
L_801D3B30:
    // 0x801D3B30: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801D3B34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D3B38: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x801D3B3C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x801D3B40: beql        $v0, $zero, L_801D3CD0
    if (ctx->r2 == 0) {
        // 0x801D3B44: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_801D3CD0;
    }
    goto skip_4;
    // 0x801D3B44: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_4:
    // 0x801D3B48: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    // 0x801D3B4C: sll         $t9, $s3, 2
    ctx->r25 = S32(ctx->r19 << 2);
    // 0x801D3B50: subu        $t9, $t9, $s3
    ctx->r25 = SUB32(ctx->r25, ctx->r19);
    // 0x801D3B54: beq         $a1, $zero, L_801D3CCC
    if (ctx->r5 == 0) {
        // 0x801D3B58: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_801D3CCC;
    }
    // 0x801D3B58: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801D3B5C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D3B60: addiu       $t6, $t6, 0x14D8
    ctx->r14 = ADD32(ctx->r14, 0X14D8);
    // 0x801D3B64: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801D3B68: jal         0x80029EE8
    // 0x801D3B6C: addu        $s2, $t9, $t6
    ctx->r18 = ADD32(ctx->r25, ctx->r14);
    LOOKUP_FUNC(0x80029EE8)(rdram, ctx);
        goto after_2;
    // 0x801D3B6C: addu        $s2, $t9, $t6
    ctx->r18 = ADD32(ctx->r25, ctx->r14);
    after_2:
    // 0x801D3B70: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801D3B74: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x801D3B78: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x801D3B7C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801D3B80: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x801D3B84: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x801D3B88: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    // 0x801D3B8C: addiu       $a3, $sp, 0x86
    ctx->r7 = ADD32(ctx->r29, 0X86);
    // 0x801D3B90: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x801D3B94: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x801D3B98: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x801D3B9C: sw          $t8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r24;
    // 0x801D3BA0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801D3BA4: lwc1        $f0, 0xD0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x801D3BA8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x801D3BAC: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x801D3BB0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D3BB4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D3BB8: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
    // 0x801D3BBC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801D3BC0: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
    // 0x801D3BC4: lwc1        $f0, 0xD4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x801D3BC8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D3BCC: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x801D3BD0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D3BD4: lw          $t6, 0x2C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X2C);
    // 0x801D3BD8: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x801D3BDC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801D3BE0: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
    // 0x801D3BE4: lwc1        $f0, 0xD8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x801D3BE8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801D3BEC: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x801D3BF0: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x801D3BF4: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x801D3BF8: swc1        $f0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f0.u32l;
    // 0x801D3BFC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801D3C00: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    // 0x801D3C04: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801D3C08: addu        $t6, $s1, $t9
    ctx->r14 = ADD32(ctx->r17, ctx->r25);
    // 0x801D3C0C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801D3C10: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D3C14: swc1        $f20, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f20.u32l;
    // 0x801D3C18: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801D3C1C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x801D3C20: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x801D3C24: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D3C28: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D3C2C: swc1        $f20, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f20.u32l;
    // 0x801D3C30: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801D3C34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D3C38: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x801D3C3C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D3C40: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
    // 0x801D3C44: addiu       $t8, $sp, 0x82
    ctx->r24 = ADD32(ctx->r29, 0X82);
    // 0x801D3C48: lw          $t6, 0x2C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X2C);
    // 0x801D3C4C: addiu       $t9, $sp, 0x90
    ctx->r25 = ADD32(ctx->r29, 0X90);
    // 0x801D3C50: swc1        $f20, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f20.u32l;
    // 0x801D3C54: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D3C58: addiu       $t7, $sp, 0x88
    ctx->r15 = ADD32(ctx->r29, 0X88);
    // 0x801D3C5C: addiu       $t6, $sp, 0x8C
    ctx->r14 = ADD32(ctx->r29, 0X8C);
    // 0x801D3C60: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x801D3C64: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x801D3C68: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x801D3C6C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801D3C70: jal         0x801D4148
    // 0x801D3C74: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(0x801D4148)(rdram, ctx);
        goto after_3;
    // 0x801D3C74: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_3:
    // 0x801D3C78: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801D3C7C: lhu         $t8, 0x86($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X86);
    // 0x801D3C80: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x801D3C84: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x801D3C88: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D3C8C: lw          $t6, 0x2C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X2C);
    // 0x801D3C90: sh          $t8, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r24;
    // 0x801D3C94: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801D3C98: lhu         $t7, 0x84($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X84);
    // 0x801D3C9C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x801D3CA0: addu        $t6, $s1, $t8
    ctx->r14 = ADD32(ctx->r17, ctx->r24);
    // 0x801D3CA4: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x801D3CA8: lw          $t8, 0x2C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X2C);
    // 0x801D3CAC: sh          $t7, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r15;
    // 0x801D3CB0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801D3CB4: lhu         $t6, 0x82($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X82);
    // 0x801D3CB8: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x801D3CBC: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x801D3CC0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D3CC4: lw          $t7, 0x2C($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X2C);
    // 0x801D3CC8: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
L_801D3CCC:
    // 0x801D3CCC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_801D3CD0:
    // 0x801D3CD0: bne         $s3, $s5, L_801D3B30
    if (ctx->r19 != ctx->r21) {
        // 0x801D3CD4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_801D3B30;
    }
    // 0x801D3CD4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801D3CD8: lui         $t8, 0x801E
    ctx->r24 = S32(0X801E << 16);
    // 0x801D3CDC: lw          $t8, -0x4C70($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4C70);
    // 0x801D3CE0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3CE4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801D3CE8: sw          $t9, -0x4C70($at)
    MEM_W(-0X4C70, ctx->r1) = ctx->r25;
    // 0x801D3CEC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3CF0: b           L_801D3FAC
    // 0x801D3CF4: sw          $zero, 0x14D4($at)
    MEM_W(0X14D4, ctx->r1) = 0;
        goto L_801D3FAC;
    // 0x801D3CF4: sw          $zero, 0x14D4($at)
    MEM_W(0X14D4, ctx->r1) = 0;
L_801D3CF8:
    // 0x801D3CF8: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D3CFC: lw          $t1, 0x14D4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X14D4);
    // 0x801D3D00: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801D3D04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801D3D08: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x801D3D0C: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801D3D10: addiu       $s0, $s0, 0x14A0
    ctx->r16 = ADD32(ctx->r16, 0X14A0);
    // 0x801D3D14: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801D3D18: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801D3D1C: jal         0x80006214
    // 0x801D3D20: div.s       $f20, $f8, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_4;
    // 0x801D3D20: div.s       $f20, $f8, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    after_4:
    // 0x801D3D24: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D3D28: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x801D3D2C: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D3D30: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801D3D34: addiu       $a2, $a2, 0x14C8
    ctx->r6 = ADD32(ctx->r6, 0X14C8);
    // 0x801D3D38: addiu       $a3, $a3, 0x14D8
    ctx->r7 = ADD32(ctx->r7, 0X14D8);
    // 0x801D3D3C: addiu       $s1, $s1, -0x2578
    ctx->r17 = ADD32(ctx->r17, -0X2578);
    // 0x801D3D40: addiu       $v1, $v1, -0x4C6C
    ctx->r3 = ADD32(ctx->r3, -0X4C6C);
    // 0x801D3D44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801D3D48: addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
    // 0x801D3D4C: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
L_801D3D50:
    // 0x801D3D50: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801D3D54: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D3D58: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x801D3D5C: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x801D3D60: beql        $a1, $zero, L_801D3DF8
    if (ctx->r5 == 0) {
        // 0x801D3D64: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_801D3DF8;
    }
    goto skip_5;
    // 0x801D3D64: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_5:
    // 0x801D3D68: lw          $t9, 0x1C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X1C);
    // 0x801D3D6C: beql        $t9, $zero, L_801D3DF8
    if (ctx->r25 == 0) {
        // 0x801D3D70: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_801D3DF8;
    }
    goto skip_6;
    // 0x801D3D70: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_6:
    // 0x801D3D74: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801D3D78: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801D3D7C: lw          $t7, 0x2C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X2C);
    // 0x801D3D80: mflo        $t6
    ctx->r14 = lo;
    // 0x801D3D84: addu        $v0, $a3, $t6
    ctx->r2 = ADD32(ctx->r7, ctx->r14);
    // 0x801D3D88: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801D3D8C: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x801D3D90: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x801D3D94: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x801D3D98: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x801D3D9C: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801D3DA0: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801D3DA4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801D3DA8: sub.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x801D3DAC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801D3DB0: addu        $t6, $s1, $t9
    ctx->r14 = ADD32(ctx->r17, ctx->r25);
    // 0x801D3DB4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801D3DB8: mul.s       $f10, $f16, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x801D3DBC: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D3DC0: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x801D3DC4: swc1        $f18, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f18.u32l;
    // 0x801D3DC8: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x801D3DCC: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D3DD0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801D3DD4: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x801D3DD8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x801D3DDC: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x801D3DE0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D3DE4: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x801D3DE8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D3DEC: add.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x801D3DF0: swc1        $f16, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f16.u32l;
    // 0x801D3DF4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_801D3DF8:
    // 0x801D3DF8: bne         $a0, $s5, L_801D3D50
    if (ctx->r4 != ctx->r21) {
        // 0x801D3DFC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_801D3D50;
    }
    // 0x801D3DFC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801D3E00: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D3E04: lw          $t1, 0x14D4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X14D4);
    // 0x801D3E08: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3E0C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D3E10: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x801D3E14: sw          $t1, 0x14D4($at)
    MEM_W(0X14D4, ctx->r1) = ctx->r9;
    // 0x801D3E18: slti        $at, $t1, 0x100
    ctx->r1 = SIGNED(ctx->r9) < 0X100 ? 1 : 0;
    // 0x801D3E1C: bne         $at, $zero, L_801D3FAC
    if (ctx->r1 != 0) {
        // 0x801D3E20: addiu       $v0, $v0, -0x4C70
        ctx->r2 = ADD32(ctx->r2, -0X4C70);
            goto L_801D3FAC;
    }
    // 0x801D3E20: addiu       $v0, $v0, -0x4C70
    ctx->r2 = ADD32(ctx->r2, -0X4C70);
    // 0x801D3E24: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D3E28: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3E2C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801D3E30: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801D3E34: b           L_801D3FAC
    // 0x801D3E38: sw          $zero, 0x14D4($at)
    MEM_W(0X14D4, ctx->r1) = 0;
        goto L_801D3FAC;
    // 0x801D3E38: sw          $zero, 0x14D4($at)
    MEM_W(0X14D4, ctx->r1) = 0;
L_801D3E3C:
    // 0x801D3E3C: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x801D3E40: addiu       $s0, $s0, 0x14A0
    ctx->r16 = ADD32(ctx->r16, 0X14A0);
    // 0x801D3E44: jal         0x80006214
    // 0x801D3E48: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_5;
    // 0x801D3E48: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x801D3E4C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3E50: lwc1        $f20, -0x2ACC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2ACC);
    // 0x801D3E54: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801D3E58: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801D3E5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3E60: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D3E64: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x801D3E68: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D3E6C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D3E70: addiu       $a0, $a0, -0x4C0C
    ctx->r4 = ADD32(ctx->r4, -0X4C0C);
    // 0x801D3E74: lw          $t1, 0x14D4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X14D4);
    // 0x801D3E78: addiu       $s1, $s1, -0x2578
    ctx->r17 = ADD32(ctx->r17, -0X2578);
    // 0x801D3E7C: addiu       $v0, $v0, -0x4C6C
    ctx->r2 = ADD32(ctx->r2, -0X4C6C);
    // 0x801D3E80: lwc1        $f2, -0x2AC8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2AC8);
    // 0x801D3E84: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_801D3E88:
    // 0x801D3E88: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801D3E8C: addu        $t6, $s1, $t9
    ctx->r14 = ADD32(ctx->r17, ctx->r25);
    // 0x801D3E90: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x801D3E94: beql        $v1, $zero, L_801D3EF8
    if (ctx->r3 == 0) {
        // 0x801D3E98: lw          $t7, 0x4($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X4);
            goto L_801D3EF8;
    }
    goto skip_7;
    // 0x801D3E98: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    skip_7:
    // 0x801D3E9C: lw          $t7, 0x1C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1C);
    // 0x801D3EA0: beql        $t7, $zero, L_801D3EF8
    if (ctx->r15 == 0) {
        // 0x801D3EA4: lw          $t7, 0x4($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X4);
            goto L_801D3EF8;
    }
    goto skip_8;
    // 0x801D3EA4: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    skip_8:
    // 0x801D3EA8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x801D3EAC: lw          $t8, 0x2C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2C);
    // 0x801D3EB0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D3EB4: div.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x801D3EB8: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x801D3EBC: add.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x801D3EC0: swc1        $f0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f0.u32l;
    // 0x801D3EC4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801D3EC8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x801D3ECC: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x801D3ED0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D3ED4: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D3ED8: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x801D3EDC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D3EE0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D3EE4: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x801D3EE8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801D3EEC: lw          $t6, 0x2C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X2C);
    // 0x801D3EF0: swc1        $f0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f0.u32l;
    // 0x801D3EF4: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
L_801D3EF8:
    // 0x801D3EF8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801D3EFC: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x801D3F00: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x801D3F04: beql        $v1, $zero, L_801D3F68
    if (ctx->r3 == 0) {
        // 0x801D3F08: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_801D3F68;
    }
    goto skip_9;
    // 0x801D3F08: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    skip_9:
    // 0x801D3F0C: lw          $t6, 0x1C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1C);
    // 0x801D3F10: beql        $t6, $zero, L_801D3F68
    if (ctx->r14 == 0) {
        // 0x801D3F14: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_801D3F68;
    }
    goto skip_10;
    // 0x801D3F14: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    skip_10:
    // 0x801D3F18: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801D3F1C: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x801D3F20: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D3F24: div.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x801D3F28: mul.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x801D3F2C: add.s       $f0, $f18, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x801D3F30: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    // 0x801D3F34: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x801D3F38: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801D3F3C: addu        $t6, $s1, $t9
    ctx->r14 = ADD32(ctx->r17, ctx->r25);
    // 0x801D3F40: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801D3F44: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D3F48: swc1        $f0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f0.u32l;
    // 0x801D3F4C: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x801D3F50: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x801D3F54: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x801D3F58: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801D3F5C: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D3F60: swc1        $f0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f0.u32l;
    // 0x801D3F64: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_801D3F68:
    // 0x801D3F68: bnel        $v0, $a0, L_801D3E88
    if (ctx->r2 != ctx->r4) {
        // 0x801D3F6C: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_801D3E88;
    }
    goto skip_11;
    // 0x801D3F6C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_11:
    // 0x801D3F70: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x801D3F74: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3F78: sw          $t1, 0x14D4($at)
    MEM_W(0X14D4, ctx->r1) = ctx->r9;
    // 0x801D3F7C: slti        $at, $t1, 0x1F
    ctx->r1 = SIGNED(ctx->r9) < 0X1F ? 1 : 0;
    // 0x801D3F80: bne         $at, $zero, L_801D3FAC
    if (ctx->r1 != 0) {
        // 0x801D3F84: lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
            goto L_801D3FAC;
    }
    // 0x801D3F84: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D3F88: addiu       $v0, $v0, -0x4C70
    ctx->r2 = ADD32(ctx->r2, -0X4C70);
    // 0x801D3F8C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801D3F90: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3F94: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801D3F98: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801D3F9C: b           L_801D3FAC
    // 0x801D3FA0: sw          $zero, 0x14D4($at)
    MEM_W(0X14D4, ctx->r1) = 0;
        goto L_801D3FAC;
    // 0x801D3FA0: sw          $zero, 0x14D4($at)
    MEM_W(0X14D4, ctx->r1) = 0;
L_801D3FA4:
    // 0x801D3FA4: b           L_801D3FB0
    // 0x801D3FA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801D3FB0;
    // 0x801D3FA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801D3FAC:
    // 0x801D3FAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801D3FB0:
    // 0x801D3FB0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801D3FB4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801D3FB8: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x801D3FBC: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x801D3FC0: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x801D3FC4: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x801D3FC8: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x801D3FCC: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x801D3FD0: jr          $ra
    // 0x801D3FD4: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x801D3FD4: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d3fd8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d3fd8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3FD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D3FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D3FE0: jal         0x80006214
    // 0x801D3FE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D3FE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D3FE8: jal         0x801C354C
    // 0x801D3FEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801C354C)(rdram, ctx);
        goto after_1;
    // 0x801D3FEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801D3FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D3FF4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D3FF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D3FFC: sw          $t6, -0x4C7C($at)
    MEM_W(-0X4C7C, ctx->r1) = ctx->r14;
    // 0x801D4000: jr          $ra
    // 0x801D4004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801D4004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d4008(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d4008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D400C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D4010: jal         0x80006214
    // 0x801D4014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D4014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D4018: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801D401C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D4020: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4024: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801D4028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D402C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D4030: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801D4034: swc1        $f4, -0x4C0C($at)
    MEM_W(-0X4C0C, ctx->r1) = ctx->f4.u32l;
    // 0x801D4038: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D403C: swc1        $f6, -0x4C08($at)
    MEM_W(-0X4C08, ctx->r1) = ctx->f6.u32l;
    // 0x801D4040: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4044: lwc1        $f8, -0x2AC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2AC4);
    // 0x801D4048: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D404C: swc1        $f8, -0x4C04($at)
    MEM_W(-0X4C04, ctx->r1) = ctx->f8.u32l;
    // 0x801D4050: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4054: lwc1        $f10, -0x2AC0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2AC0);
    // 0x801D4058: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D405C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D4060: jr          $ra
    // 0x801D4064: swc1        $f10, -0x4C00($at)
    MEM_W(-0X4C00, ctx->r1) = ctx->f10.u32l;
    return;
    // 0x801D4064: swc1        $f10, -0x4C00($at)
    MEM_W(-0X4C00, ctx->r1) = ctx->f10.u32l;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d4068(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d4068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4068: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D406C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D4070: addiu       $v1, $v1, -0x4C08
    ctx->r3 = ADD32(ctx->r3, -0X4C08);
    // 0x801D4074: addiu       $v0, $v0, -0x4C04
    ctx->r2 = ADD32(ctx->r2, -0X4C04);
    // 0x801D4078: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D407C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801D4080: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x801D4084: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x801D4088: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x801D408C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801D4090: addiu       $a1, $a1, -0x4C00
    ctx->r5 = ADD32(ctx->r5, -0X4C00);
    // 0x801D4094: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801D4098: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x801D409C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D40A0: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d40a4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d40a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D40A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D40A8: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x801D40AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D40B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801D40B4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x801D40B8: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x801D40BC: nop

    // 0x801D40C0: bc1f        L_801D4108
    if (!c1cs) {
        // 0x801D40C4: nop
    
            goto L_801D4108;
    }
    // 0x801D40C4: nop

    // 0x801D40C8: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x801D40CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D40D0: bc1f        L_801D40F4
    if (!c1cs) {
        // 0x801D40D4: nop
    
            goto L_801D40F4;
    }
    // 0x801D40D4: nop

    // 0x801D40D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D40DC: lwc1        $f16, -0x2ABC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2ABC);
    // 0x801D40E0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D40E4: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x801D40E8: lwc1        $f18, -0x2AB8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2AB8);
    // 0x801D40EC: b           L_801D4108
    // 0x801D40F0: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
        goto L_801D4108;
    // 0x801D40F0: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_801D40F4:
    // 0x801D40F4: lwc1        $f4, -0x2AB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2AB4);
    // 0x801D40F8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D40FC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x801D4100: lwc1        $f6, -0x2AB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2AB0);
    // 0x801D4104: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
L_801D4108:
    // 0x801D4108: jal         0x80006214
    // 0x801D410C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D410C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x801D4110: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801D4114: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D4118: addiu       $v1, $v1, -0x4C08
    ctx->r3 = ADD32(ctx->r3, -0X4C08);
    // 0x801D411C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4120: lwc1        $f10, -0x4C0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4C0C);
    // 0x801D4124: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D4128: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801D412C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801D4130: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D4134: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x801D4138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D413C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D4140: jr          $ra
    // 0x801D4144: nop

    return;
    // 0x801D4144: nop

;}
RECOMP_FUNC void M24_FUN_801d4148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4148: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801D414C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D4150: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D4154: lhu         $t6, 0x0($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X0);
    // 0x801D4158: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x801D415C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x801D4160: sh          $t6, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r14;
    // 0x801D4164: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x801D4168: lw          $s0, 0x8C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8C);
    // 0x801D416C: addiu       $t1, $zero, 0x200
    ctx->r9 = ADD32(0, 0X200);
    // 0x801D4170: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
    // 0x801D4174: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x801D4178: sh          $t0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r8;
    // 0x801D417C: sh          $t1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r9;
    // 0x801D4180: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x801D4184: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x801D4188: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x801D418C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x801D4190: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x801D4194: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x801D4198: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801D419C: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D41A0: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D41A4: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801D41A8: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x801D41AC: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801D41B0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801D41B4: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801D41B8: jal         0x8002FC20
    // 0x801D41BC: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x801D41BC: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_0:
    // 0x801D41C0: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x801D41C4: swc1        $f0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f0.u32l;
    // 0x801D41C8: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801D41CC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801D41D0: lwc1        $f2, 0x18($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801D41D4: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801D41D8: nop

    // 0x801D41DC: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801D41E0: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801D41E4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801D41E8: jal         0x8002FC20
    // 0x801D41EC: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_1;
    // 0x801D41EC: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_1:
    // 0x801D41F0: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x801D41F4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801D41F8: lwc1        $f14, 0x20($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801D41FC: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x801D4200: lwc1        $f2, 0x28($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X28);
    // 0x801D4204: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801D4208: nop

    // 0x801D420C: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801D4210: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801D4214: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801D4218: jal         0x8002FC20
    // 0x801D421C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_2;
    // 0x801D421C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_2:
    // 0x801D4220: lw          $v1, 0x88($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X88);
    // 0x801D4224: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801D4228: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x801D422C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801D4230: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801D4234: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801D4238: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x801D423C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x801D4240: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x801D4244: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x801D4248: bc1tl       L_801D4280
    if (c1cs) {
        // 0x801D424C: lwc1        $f0, 0x0($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
            goto L_801D4280;
    }
    goto skip_0;
    // 0x801D424C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x801D4250: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801D4254: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801D4258: div.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x801D425C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D4260: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x801D4264: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801D4268: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801D426C: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x801D4270: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801D4274: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801D4278: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x801D427C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_801D4280:
    // 0x801D4280: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x801D4284: nop

    // 0x801D4288: bc1tl       L_801D42C0
    if (c1cs) {
        // 0x801D428C: lwc1        $f0, 0x0($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
            goto L_801D42C0;
    }
    goto skip_1;
    // 0x801D428C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x801D4290: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801D4294: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801D4298: div.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801D429C: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801D42A0: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x801D42A4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801D42A8: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801D42AC: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x801D42B0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801D42B4: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801D42B8: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x801D42BC: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
L_801D42C0:
    // 0x801D42C0: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x801D42C4: nop

    // 0x801D42C8: bc1t        L_801D42FC
    if (c1cs) {
        // 0x801D42CC: nop
    
            goto L_801D42FC;
    }
    // 0x801D42CC: nop

    // 0x801D42D0: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801D42D4: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x801D42D8: div.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801D42DC: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x801D42E0: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x801D42E4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D42E8: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801D42EC: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x801D42F0: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D42F4: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801D42F8: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
L_801D42FC:
    // 0x801D42FC: jal         0x801D4390
    // 0x801D4300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801D4390)(rdram, ctx);
        goto after_3;
    // 0x801D4300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801D4304: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x801D4308: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801D430C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801D4310: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801D4314: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801D4318: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801D431C: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x801D4320: div.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x801D4324: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801D4328: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x801D432C: nop

    // 0x801D4330: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x801D4334: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801D4338: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x801D433C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801D4340: div.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x801D4344: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801D4348: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x801D434C: nop

    // 0x801D4350: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x801D4354: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801D4358: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x801D435C: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801D4360: div.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x801D4364: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801D4368: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x801D436C: nop

    // 0x801D4370: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x801D4374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D4378: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D437C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x801D4380: jr          $ra
    // 0x801D4384: nop

    return;
    // 0x801D4384: nop

;}
RECOMP_FUNC void M24_FUN_801d4388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4388: jr          $ra
    // 0x801D438C: nop

    return;
    // 0x801D438C: nop

;}
RECOMP_FUNC void M24_FUN_801d4390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4390: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D4394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D4398: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D439C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801D43A0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801D43A4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801D43A8: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801D43AC: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801D43B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D43B4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801D43B8: nop

    // 0x801D43BC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801D43C0: jal         0x8002FC20
    // 0x801D43C4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(0x8002FC20)(rdram, ctx);
        goto after_0;
    // 0x801D43C4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x801D43C8: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801D43CC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801D43D0: jal         0x801D44A4
    // 0x801D43D4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    LOOKUP_FUNC(0x801D44A4)(rdram, ctx);
        goto after_1;
    // 0x801D43D4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x801D43D8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801D43DC: lwc1        $f14, 0x28($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X28);
    // 0x801D43E0: jal         0x801D44A4
    // 0x801D43E4: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    LOOKUP_FUNC(0x801D44A4)(rdram, ctx);
        goto after_2;
    // 0x801D43E4: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    after_2:
    // 0x801D43E8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801D43EC: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801D43F0: jal         0x801D44A4
    // 0x801D43F4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    LOOKUP_FUNC(0x801D44A4)(rdram, ctx);
        goto after_3;
    // 0x801D43F4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    after_3:
    // 0x801D43F8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801D43FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801D4400: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801D4404: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4408: lwc1        $f12, -0x2AAC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2AAC);
    // 0x801D440C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801D4410: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x801D4414: div.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x801D4418: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x801D441C: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801D4420: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x801D4424: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x801D4428: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801D442C: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x801D4430: div.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x801D4434: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x801D4438: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x801D443C: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
    // 0x801D4440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D4444: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D4448: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D444C: jr          $ra
    // 0x801D4450: nop

    return;
    // 0x801D4450: nop

;}
RECOMP_FUNC void M24_FUN_801d4454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4454: jr          $ra
    // 0x801D4458: nop

    return;
    // 0x801D4458: nop

;}
RECOMP_FUNC void M24_FUN_801d445c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D445C: jr          $ra
    // 0x801D4460: nop

    return;
    // 0x801D4460: nop

;}
RECOMP_FUNC void M24_FUN_801d4464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4464: jr          $ra
    // 0x801D4468: nop

    return;
    // 0x801D4468: nop

;}
RECOMP_FUNC void M24_FUN_801d446c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D446C: jr          $ra
    // 0x801D4470: nop

    return;
    // 0x801D4470: nop

;}
RECOMP_FUNC void M24_FUN_801d4474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4474: jr          $ra
    // 0x801D4478: nop

    return;
    // 0x801D4478: nop

;}
RECOMP_FUNC void M24_FUN_801d447c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D447C: jr          $ra
    // 0x801D4480: nop

    return;
    // 0x801D4480: nop

;}
RECOMP_FUNC void M24_FUN_801d4484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4484: jr          $ra
    // 0x801D4488: nop

    return;
    // 0x801D4488: nop

;}
RECOMP_FUNC void M24_FUN_801d448c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D448C: jr          $ra
    // 0x801D4490: nop

    return;
    // 0x801D4490: nop

;}
RECOMP_FUNC void M24_FUN_801d4494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4494: jr          $ra
    // 0x801D4498: nop

    return;
    // 0x801D4498: nop

;}
RECOMP_FUNC void M24_FUN_801d449c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D449C: jr          $ra
    // 0x801D44A0: nop

    return;
    // 0x801D44A0: nop

;}
RECOMP_FUNC void M24_FUN_801d44a4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D44A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801D44A8: nop

    // 0x801D44AC: c.eq.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl == ctx->f18.fl;
    // 0x801D44B0: nop

    // 0x801D44B4: bc1fl       L_801D44F0
    if (!c1cs) {
        // 0x801D44B8: c.eq.s      $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl == ctx->f18.fl;
            goto L_801D44F0;
    }
    goto skip_0;
    // 0x801D44B8: c.eq.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl == ctx->f18.fl;
    skip_0:
    // 0x801D44BC: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x801D44C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D44C4: bc1fl       L_801D44D8
    if (!c1cs) {
        // 0x801D44C8: c.lt.s      $f18, $f12
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
            goto L_801D44D8;
    }
    goto skip_1;
    // 0x801D44C8: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    skip_1:
    // 0x801D44CC: jr          $ra
    // 0x801D44D0: lwc1        $f0, -0x2AA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2AA8);
    return;
    // 0x801D44D0: lwc1        $f0, -0x2AA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2AA8);
    // 0x801D44D4: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
L_801D44D8:
    // 0x801D44D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D44DC: bc1fl       L_801D44F0
    if (!c1cs) {
        // 0x801D44E0: c.eq.s      $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl == ctx->f18.fl;
            goto L_801D44F0;
    }
    goto skip_2;
    // 0x801D44E0: c.eq.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl == ctx->f18.fl;
    skip_2:
    // 0x801D44E4: jr          $ra
    // 0x801D44E8: lwc1        $f0, -0x2AA4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2AA4);
    return;
    // 0x801D44E8: lwc1        $f0, -0x2AA4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2AA4);
    // 0x801D44EC: c.eq.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl == ctx->f18.fl;
L_801D44F0:
    // 0x801D44F0: nop

    // 0x801D44F4: bc1fl       L_801D4530
    if (!c1cs) {
        // 0x801D44F8: c.eq.s      $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl == ctx->f18.fl;
            goto L_801D4530;
    }
    goto skip_3;
    // 0x801D44F8: c.eq.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl == ctx->f18.fl;
    skip_3:
    // 0x801D44FC: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    // 0x801D4500: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4504: bc1fl       L_801D4518
    if (!c1cs) {
        // 0x801D4508: c.lt.s      $f18, $f14
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
            goto L_801D4518;
    }
    goto skip_4;
    // 0x801D4508: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    skip_4:
    // 0x801D450C: jr          $ra
    // 0x801D4510: lwc1        $f0, -0x2AA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2AA0);
    return;
    // 0x801D4510: lwc1        $f0, -0x2AA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2AA0);
    // 0x801D4514: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
L_801D4518:
    // 0x801D4518: nop

    // 0x801D451C: bc1fl       L_801D4530
    if (!c1cs) {
        // 0x801D4520: c.eq.s      $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl == ctx->f18.fl;
            goto L_801D4530;
    }
    goto skip_5;
    // 0x801D4520: c.eq.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl == ctx->f18.fl;
    skip_5:
    // 0x801D4524: jr          $ra
    // 0x801D4528: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    return;
    // 0x801D4528: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    // 0x801D452C: c.eq.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl == ctx->f18.fl;
L_801D4530:
    // 0x801D4530: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D4534: addiu       $v1, $v1, -0x4BD8
    ctx->r3 = ADD32(ctx->r3, -0X4BD8);
    // 0x801D4538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801D453C: bc1fl       L_801D4550
    if (!c1cs) {
        // 0x801D4540: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_801D4550;
    }
    goto skip_6;
    // 0x801D4540: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_6:
    // 0x801D4544: jr          $ra
    // 0x801D4548: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    return;
    // 0x801D4548: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    // 0x801D454C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_801D4550:
    // 0x801D4550: nop

    // 0x801D4554: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x801D4558: nop

    // 0x801D455C: bc1fl       L_801D4570
    if (!c1cs) {
        // 0x801D4560: mov.s       $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
            goto L_801D4570;
    }
    goto skip_7;
    // 0x801D4560: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    skip_7:
    // 0x801D4564: b           L_801D4570
    // 0x801D4568: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
        goto L_801D4570;
    // 0x801D4568: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
    // 0x801D456C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_801D4570:
    // 0x801D4570: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x801D4574: nop

    // 0x801D4578: bc1fl       L_801D458C
    if (!c1cs) {
        // 0x801D457C: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_801D458C;
    }
    goto skip_8;
    // 0x801D457C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    skip_8:
    // 0x801D4580: b           L_801D458C
    // 0x801D4584: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
        goto L_801D458C;
    // 0x801D4584: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    // 0x801D4588: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_801D458C:
    // 0x801D458C: div.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
L_801D4590:
    // 0x801D4590: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D4594: c.le.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl <= ctx->f4.fl;
    // 0x801D4598: nop

    // 0x801D459C: bc1tl       L_801D45B8
    if (c1cs) {
        // 0x801D45A0: addiu       $at, $zero, 0x5A
        ctx->r1 = ADD32(0, 0X5A);
            goto L_801D45B8;
    }
    goto skip_9;
    // 0x801D45A0: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    skip_9:
    // 0x801D45A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801D45A8: slti        $at, $v0, 0x5A
    ctx->r1 = SIGNED(ctx->r2) < 0X5A ? 1 : 0;
    // 0x801D45AC: bne         $at, $zero, L_801D4590
    if (ctx->r1 != 0) {
        // 0x801D45B0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_801D4590;
    }
    // 0x801D45B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801D45B4: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
L_801D45B8:
    // 0x801D45B8: bnel        $v0, $at, L_801D45C8
    if (ctx->r2 != ctx->r1) {
        // 0x801D45BC: c.lt.s      $f18, $f14
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
            goto L_801D45C8;
    }
    goto skip_10;
    // 0x801D45BC: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    skip_10:
    // 0x801D45C0: addiu       $v0, $zero, 0x59
    ctx->r2 = ADD32(0, 0X59);
    // 0x801D45C4: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
L_801D45C8:
    // 0x801D45C8: nop

    // 0x801D45CC: bc1fl       L_801D460C
    if (!c1cs) {
        // 0x801D45D0: c.lt.s      $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
            goto L_801D460C;
    }
    goto skip_11;
    // 0x801D45D0: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    skip_11:
    // 0x801D45D4: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x801D45D8: nop

    // 0x801D45DC: bc1fl       L_801D460C
    if (!c1cs) {
        // 0x801D45E0: c.lt.s      $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
            goto L_801D460C;
    }
    goto skip_12;
    // 0x801D45E0: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    skip_12:
    // 0x801D45E4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x801D45E8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D45EC: lwc1        $f10, -0x2A9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2A9C);
    // 0x801D45F0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801D45F4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801D45F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D45FC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801D4600: jr          $ra
    // 0x801D4604: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    return;
    // 0x801D4604: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801D4608: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
L_801D460C:
    // 0x801D460C: nop

    // 0x801D4610: bc1fl       L_801D4654
    if (!c1cs) {
        // 0x801D4614: c.lt.s      $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
            goto L_801D4654;
    }
    goto skip_13;
    // 0x801D4614: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    skip_13:
    // 0x801D4618: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x801D461C: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x801D4620: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x801D4624: bc1fl       L_801D4654
    if (!c1cs) {
        // 0x801D4628: c.lt.s      $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
            goto L_801D4654;
    }
    goto skip_14;
    // 0x801D4628: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    skip_14:
    // 0x801D462C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801D4630: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4634: lwc1        $f4, -0x2A98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2A98);
    // 0x801D4638: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801D463C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801D4640: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D4644: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801D4648: jr          $ra
    // 0x801D464C: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    return;
    // 0x801D464C: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801D4650: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
L_801D4654:
    // 0x801D4654: nop

    // 0x801D4658: bc1fl       L_801D4698
    if (!c1cs) {
        // 0x801D465C: c.lt.s      $f18, $f14
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
            goto L_801D4698;
    }
    goto skip_15;
    // 0x801D465C: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    skip_15:
    // 0x801D4660: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x801D4664: addiu       $t8, $v0, 0xB4
    ctx->r24 = ADD32(ctx->r2, 0XB4);
    // 0x801D4668: bc1fl       L_801D4698
    if (!c1cs) {
        // 0x801D466C: c.lt.s      $f18, $f14
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
            goto L_801D4698;
    }
    goto skip_16;
    // 0x801D466C: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    skip_16:
    // 0x801D4670: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x801D4674: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4678: lwc1        $f6, -0x2A94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2A94);
    // 0x801D467C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801D4680: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801D4684: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801D4688: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801D468C: jr          $ra
    // 0x801D4690: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    return;
    // 0x801D4690: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801D4694: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
L_801D4698:
    // 0x801D4698: nop

    // 0x801D469C: bc1fl       L_801D46E0
    if (!c1cs) {
        // 0x801D46A0: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_801D46E0;
    }
    goto skip_17;
    // 0x801D46A0: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_17:
    // 0x801D46A4: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x801D46A8: addiu       $t9, $zero, 0x168
    ctx->r25 = ADD32(0, 0X168);
    // 0x801D46AC: subu        $t0, $t9, $v0
    ctx->r8 = SUB32(ctx->r25, ctx->r2);
    // 0x801D46B0: bc1fl       L_801D46E0
    if (!c1cs) {
        // 0x801D46B4: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_801D46E0;
    }
    goto skip_18;
    // 0x801D46B4: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_18:
    // 0x801D46B8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x801D46BC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D46C0: lwc1        $f8, -0x2A90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2A90);
    // 0x801D46C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801D46C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801D46CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D46D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801D46D4: jr          $ra
    // 0x801D46D8: div.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    return;
    // 0x801D46D8: div.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801D46DC: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
L_801D46E0:
    // 0x801D46E0: jr          $ra
    // 0x801D46E4: nop

    return;
    // 0x801D46E4: nop

;}
RECOMP_FUNC void M24_FUN_801d46e8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D46E8: nop

    // 0x801D46EC: nop

;}
RECOMP_FUNC void M24_FUN_801d46f0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D46F0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D46F4: sw          $a0, 0x1600($at)
    MEM_W(0X1600, ctx->r1) = ctx->r4;
    // 0x801D46F8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D46FC: sw          $zero, -0x4A58($at)
    MEM_W(-0X4A58, ctx->r1) = 0;
    // 0x801D4700: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4704: sw          $zero, -0x4A54($at)
    MEM_W(-0X4A54, ctx->r1) = 0;
    // 0x801D4708: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D470C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D4710: sw          $t6, -0x4A4C($at)
    MEM_W(-0X4A4C, ctx->r1) = ctx->r14;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d4714(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d4714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4714: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D4718: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D471C: sw          $zero, -0x4A70($at)
    MEM_W(-0X4A70, ctx->r1) = 0;
    // 0x801D4720: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801D4724: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D4728: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801D472C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4730: addiu       $t7, $t7, 0x475C
    ctx->r15 = ADD32(ctx->r15, 0X475C);
    // 0x801D4734: sw          $zero, -0x4A48($at)
    MEM_W(-0X4A48, ctx->r1) = 0;
    // 0x801D4738: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D473C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801D4740: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D4744: jal         0x8013B570
    // 0x801D4748: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_0;
    // 0x801D4748: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801D474C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D4750: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D4754: jr          $ra
    // 0x801D4758: nop

    return;
    // 0x801D4758: nop

;}
RECOMP_FUNC void M24_FUN_801d475c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D475C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D4760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D4764: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D4768: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D476C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D4770: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D4774: beq         $t6, $zero, L_801D47A0
    if (ctx->r14 == 0) {
        // 0x801D4778: nop
    
            goto L_801D47A0;
    }
    // 0x801D4778: nop

    // 0x801D477C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801D4780: jal         0x8012D844
    // 0x801D4784: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D4784: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D4788: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D478C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D4790: jal         0x800058DC
    // 0x801D4794: addiu       $a1, $a1, 0x47B8
    ctx->r5 = ADD32(ctx->r5, 0X47B8);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D4794: addiu       $a1, $a1, 0x47B8
    ctx->r5 = ADD32(ctx->r5, 0X47B8);
    after_1:
    // 0x801D4798: b           L_801D47AC
    // 0x801D479C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D47AC;
    // 0x801D479C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D47A0:
    // 0x801D47A0: jal         0x800058DC
    // 0x801D47A4: addiu       $a1, $a1, 0x475C
    ctx->r5 = ADD32(ctx->r5, 0X475C);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D47A4: addiu       $a1, $a1, 0x475C
    ctx->r5 = ADD32(ctx->r5, 0X475C);
    after_2:
    // 0x801D47A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D47AC:
    // 0x801D47AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D47B0: jr          $ra
    // 0x801D47B4: nop

    return;
    // 0x801D47B4: nop

;}
RECOMP_FUNC void M24_FUN_801d47b8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D47B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D47BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D47C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801D47C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801D47C8: jal         0x801CC540
    // 0x801D47CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(0x801CC540)(rdram, ctx);
        goto after_0;
    // 0x801D47CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801D47D0: beq         $v0, $zero, L_801D47F0
    if (ctx->r2 == 0) {
        // 0x801D47D4: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D47F0;
    }
    // 0x801D47D4: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D47D8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D47DC: addiu       $a1, $a1, 0x47B8
    ctx->r5 = ADD32(ctx->r5, 0X47B8);
    // 0x801D47E0: jal         0x800058DC
    // 0x801D47E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D47E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801D47E8: b           L_801D49A0
    // 0x801D47EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801D49A0;
    // 0x801D47EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D47F0:
    // 0x801D47F0: lw          $t6, -0x4A58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4A58);
    // 0x801D47F4: beq         $t6, $zero, L_801D4848
    if (ctx->r14 == 0) {
        // 0x801D47F8: nop
    
            goto L_801D4848;
    }
    // 0x801D47F8: nop

    // 0x801D47FC: jal         0x80006214
    // 0x801D4800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_2;
    // 0x801D4800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801D4804: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D4808: lw          $t7, -0x4A58($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4A58);
    // 0x801D480C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801D4810: addiu       $a0, $a0, -0x2578
    ctx->r4 = ADD32(ctx->r4, -0X2578);
    // 0x801D4814: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D4818: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x801D481C: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x801D4820: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801D4824: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801D4828: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x801D482C: jal         0x8013A28C
    // 0x801D4830: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x8013A28C)(rdram, ctx);
        goto after_3;
    // 0x801D4830: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_3:
    // 0x801D4834: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x801D4838: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801D483C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4840: sb          $t0, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r8;
    // 0x801D4844: sw          $zero, -0x4A58($at)
    MEM_W(-0X4A58, ctx->r1) = 0;
L_801D4848:
    // 0x801D4848: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D484C: lw          $v0, -0x4A54($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4A54);
    // 0x801D4850: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D4854: beq         $v0, $zero, L_801D4920
    if (ctx->r2 == 0) {
        // 0x801D4858: nop
    
            goto L_801D4920;
    }
    // 0x801D4858: nop

    // 0x801D485C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801D4860: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x801D4864: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801D4868: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x801D486C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801D4870: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D4874: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D4878: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x801D487C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801D4880: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801D4884: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801D4888: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D488C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801D4890: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801D4894: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D4898: nop

    // 0x801D489C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D48A0: beql        $t4, $zero, L_801D48F0
    if (ctx->r12 == 0) {
        // 0x801D48A4: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801D48F0;
    }
    goto skip_0;
    // 0x801D48A4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801D48A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D48AC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801D48B0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D48B4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801D48B8: nop

    // 0x801D48BC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801D48C0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801D48C4: nop

    // 0x801D48C8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801D48CC: bne         $t4, $zero, L_801D48E4
    if (ctx->r12 != 0) {
        // 0x801D48D0: nop
    
            goto L_801D48E4;
    }
    // 0x801D48D0: nop

    // 0x801D48D4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801D48D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801D48DC: b           L_801D48FC
    // 0x801D48E0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801D48FC;
    // 0x801D48E0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801D48E4:
    // 0x801D48E4: b           L_801D48FC
    // 0x801D48E8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801D48FC;
    // 0x801D48E8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801D48EC: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801D48F0:
    // 0x801D48F0: nop

    // 0x801D48F4: bltz        $t4, L_801D48E4
    if (SIGNED(ctx->r12) < 0) {
        // 0x801D48F8: nop
    
            goto L_801D48E4;
    }
    // 0x801D48F8: nop

L_801D48FC:
    // 0x801D48FC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801D4900: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801D4904: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801D4908: jal         0x80011140
    // 0x801D490C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    LOOKUP_FUNC(0x80011140)(rdram, ctx);
        goto after_4;
    // 0x801D490C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    after_4:
    // 0x801D4910: beq         $v0, $zero, L_801D496C
    if (ctx->r2 == 0) {
        // 0x801D4914: lui         $at, 0x801E
        ctx->r1 = S32(0X801E << 16);
            goto L_801D496C;
    }
    // 0x801D4914: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4918: b           L_801D496C
    // 0x801D491C: sw          $zero, -0x4A54($at)
    MEM_W(-0X4A54, ctx->r1) = 0;
        goto L_801D496C;
    // 0x801D491C: sw          $zero, -0x4A54($at)
    MEM_W(-0X4A54, ctx->r1) = 0;
L_801D4920:
    // 0x801D4920: jal         0x80010550
    // 0x801D4924: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    LOOKUP_FUNC(0x80010550)(rdram, ctx);
        goto after_5;
    // 0x801D4924: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    after_5:
    // 0x801D4928: beq         $v0, $zero, L_801D4940
    if (ctx->r2 == 0) {
        // 0x801D492C: lui         $t6, 0x801E
        ctx->r14 = S32(0X801E << 16);
            goto L_801D4940;
    }
    // 0x801D492C: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D4930: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801D4934: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4938: b           L_801D4948
    // 0x801D493C: sw          $t5, -0x4A4C($at)
    MEM_W(-0X4A4C, ctx->r1) = ctx->r13;
        goto L_801D4948;
    // 0x801D493C: sw          $t5, -0x4A4C($at)
    MEM_W(-0X4A4C, ctx->r1) = ctx->r13;
L_801D4940:
    // 0x801D4940: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4944: sw          $zero, -0x4A4C($at)
    MEM_W(-0X4A4C, ctx->r1) = 0;
L_801D4948:
    // 0x801D4948: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801D494C: addiu       $t7, $t7, -0x3FD8
    ctx->r15 = ADD32(ctx->r15, -0X3FD8);
    // 0x801D4950: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801D4954: addiu       $t6, $t6, 0x1608
    ctx->r14 = ADD32(ctx->r14, 0X1608);
    // 0x801D4958: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801D495C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801D4960: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801D4964: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801D4968: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
L_801D496C:
    // 0x801D496C: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x801D4970: lw          $t0, -0x4A70($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4A70);
    // 0x801D4974: beq         $t0, $zero, L_801D4984
    if (ctx->r8 == 0) {
        // 0x801D4978: nop
    
            goto L_801D4984;
    }
    // 0x801D4978: nop

    // 0x801D497C: jal         0x801D4AF8
    // 0x801D4980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801D4AF8)(rdram, ctx);
        goto after_6;
    // 0x801D4980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_801D4984:
    // 0x801D4984: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D4988: lw          $t1, -0x4A48($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4A48);
    // 0x801D498C: beql        $t1, $zero, L_801D49A0
    if (ctx->r9 == 0) {
        // 0x801D4990: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801D49A0;
    }
    goto skip_1;
    // 0x801D4990: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801D4994: jal         0x801D4C58
    // 0x801D4998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x801D4C58)(rdram, ctx);
        goto after_7;
    // 0x801D4998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801D499C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801D49A0:
    // 0x801D49A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801D49A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D49A8: jr          $ra
    // 0x801D49AC: nop

    return;
    // 0x801D49AC: nop

;}
RECOMP_FUNC void M24_FUN_801d49b0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D49B0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D49B4: lw          $v0, -0x4A54($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4A54);
    // 0x801D49B8: jr          $ra
    // 0x801D49BC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x801D49BC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d49c0(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d49c0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D49C0: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D49C4: lw          $t6, -0x4A54($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4A54);
    // 0x801D49C8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D49CC: beq         $t6, $zero, L_801D49DC
    if (ctx->r14 == 0) {
            // 0x801D49D0: nop

    LOOKUP_FUNC(0x801D49DC)(rdram, ctx);
    return;
    }
    // 0x801D49D0: nop

    // 0x801D49D4: jr          $ra
    // 0x801D49D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D49D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d49dc(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d49dc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D49DC: lw          $t7, -0x4A58($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4A58);
    // 0x801D49E0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D49E4: beq         $t7, $zero, L_801D49F4
    if (ctx->r15 == 0) {
            // 0x801D49E8: nop

    LOOKUP_FUNC(0x801D49F4)(rdram, ctx);
    return;
    }
    // 0x801D49E8: nop

    // 0x801D49EC: jr          $ra
    // 0x801D49F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801D49F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d49f4(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d49f4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D49F4: lw          $v0, -0x4A4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4A4C);
    // 0x801D49F8: jr          $ra
    // 0x801D49FC: nop

    return;
    // 0x801D49FC: nop

;}
RECOMP_FUNC void M24_FUN_801d4a00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4A00: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D4A04: jr          $ra
    // 0x801D4A08: addiu       $v0, $v0, 0x1608
    ctx->r2 = ADD32(ctx->r2, 0X1608);
    return;
    // 0x801D4A08: addiu       $v0, $v0, 0x1608
    ctx->r2 = ADD32(ctx->r2, 0X1608);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d4a0c(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d4a0c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4A0C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D4A10: addiu       $v0, $v0, -0x4A70
    ctx->r2 = ADD32(ctx->r2, -0X4A70);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d4a14(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d4a14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4A14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D4A18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D4A1C: beq         $a0, $zero, L_801D4A48
    if (ctx->r4 == 0) {
        // 0x801D4A20: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801D4A48;
    }
    // 0x801D4A20: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801D4A24: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4A28: jal         0x801C0B2C
    // 0x801D4A2C: sw          $zero, -0x4A50($at)
    MEM_W(-0X4A50, ctx->r1) = 0;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D4A2C: sw          $zero, -0x4A50($at)
    MEM_W(-0X4A50, ctx->r1) = 0;
    after_0:
    // 0x801D4A30: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4A34: sw          $v0, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->r2;
    // 0x801D4A38: sw          $v1, 0x161C($at)
    MEM_W(0X161C, ctx->r1) = ctx->r3;
    // 0x801D4A3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4A40: b           L_801D4A5C
    // 0x801D4A44: sw          $zero, 0x1620($at)
    MEM_W(0X1620, ctx->r1) = 0;
        goto L_801D4A5C;
    // 0x801D4A44: sw          $zero, 0x1620($at)
    MEM_W(0X1620, ctx->r1) = 0;
L_801D4A48:
    // 0x801D4A48: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D4A4C: lw          $a0, 0x1600($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1600);
    // 0x801D4A50: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801D4A54: jal         0x8012D844
    // 0x801D4A58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_1;
    // 0x801D4A58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_801D4A5C:
    // 0x801D4A5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D4A60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D4A64: jr          $ra
    // 0x801D4A68: nop

    return;
    // 0x801D4A68: nop

;}
RECOMP_FUNC void M24_FUN_801d4a6c(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4A6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D4A70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801D4A74: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801D4A78: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801D4A7C: beq         $a0, $zero, L_801D4AD0
    if (ctx->r4 == 0) {
        // 0x801D4A80: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_801D4AD0;
    }
    // 0x801D4A80: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801D4A84: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D4A88: jal         0x80006214
    // 0x801D4A8C: lw          $a0, 0x1600($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1600);
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D4A8C: lw          $a0, 0x1600($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1600);
    after_0:
    // 0x801D4A90: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x801D4A94: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801D4A98: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D4A9C: lw          $a0, 0x1600($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1600);
    // 0x801D4AA0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801D4AA4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801D4AA8: lbu         $a3, 0x37($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X37);
    // 0x801D4AAC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801D4AB0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801D4AB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801D4AB8: jal         0x801C3370
    // 0x801D4ABC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    LOOKUP_FUNC(0x801C3370)(rdram, ctx);
        goto after_1;
    // 0x801D4ABC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_1:
    // 0x801D4AC0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801D4AC4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4AC8: b           L_801D4AD8
    // 0x801D4ACC: sw          $t8, -0x4A48($at)
    MEM_W(-0X4A48, ctx->r1) = ctx->r24;
        goto L_801D4AD8;
    // 0x801D4ACC: sw          $t8, -0x4A48($at)
    MEM_W(-0X4A48, ctx->r1) = ctx->r24;
L_801D4AD0:
    // 0x801D4AD0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4AD4: sw          $zero, -0x4A48($at)
    MEM_W(-0X4A48, ctx->r1) = 0;
L_801D4AD8:
    // 0x801D4AD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801D4ADC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D4AE0: jr          $ra
    // 0x801D4AE4: nop

    return;
    // 0x801D4AE4: nop

;}
RECOMP_FUNC void M24_FUN_801d4ae8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4AE8: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x801D4AEC: lw          $v0, -0x4A48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4A48);
    // 0x801D4AF0: jr          $ra
    // 0x801D4AF4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x801D4AF4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d4af8(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d4af8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4AF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D4AFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D4B00: jal         0x801C0B2C
    // 0x801D4B04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_0;
    // 0x801D4B04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D4B08: lui         $t6, 0x801E
    ctx->r14 = S32(0X801E << 16);
    // 0x801D4B0C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D4B10: lw          $t7, 0x161C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X161C);
    // 0x801D4B14: lw          $t6, 0x1618($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1618);
    // 0x801D4B18: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801D4B1C: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x801D4B20: subu        $a0, $t8, $at
    ctx->r4 = SUB32(ctx->r24, ctx->r1);
    // 0x801D4B24: subu        $a1, $v1, $t7
    ctx->r5 = SUB32(ctx->r3, ctx->r15);
    // 0x801D4B28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D4B2C: jal         0x80034C24
    // 0x801D4B30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80034C24)(rdram, ctx);
        goto after_1;
    // 0x801D4B30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x801D4B34: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4B38: ldc1        $f4, -0x2A80($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2A80);
    // 0x801D4B3C: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D4B40: addiu       $a3, $a3, 0x1620
    ctx->r7 = ADD32(ctx->r7, 0X1620);
    // 0x801D4B44: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x801D4B48: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x801D4B4C: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D4B50: addiu       $t1, $t1, -0x4A44
    ctx->r9 = ADD32(ctx->r9, -0X4A44);
    // 0x801D4B54: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x801D4B58: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x801D4B5C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801D4B60: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x801D4B64: c.le.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d <= ctx->f6.d;
    // 0x801D4B68: nop

    // 0x801D4B6C: bc1fl       L_801D4C4C
    if (!c1cs) {
        // 0x801D4B70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801D4C4C;
    }
    goto skip_0;
    // 0x801D4B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801D4B74: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801D4B78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D4B7C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801D4B80: beq         $v0, $zero, L_801D4BA4
    if (ctx->r2 == 0) {
        // 0x801D4B84: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801D4BA4;
    }
    // 0x801D4B84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D4B88: beq         $v0, $at, L_801D4BC0
    if (ctx->r2 == ctx->r1) {
        // 0x801D4B8C: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_801D4BC0;
    }
    // 0x801D4B8C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801D4B90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D4B94: beq         $v0, $at, L_801D4BE0
    if (ctx->r2 == ctx->r1) {
        // 0x801D4B98: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_801D4BE0;
    }
    // 0x801D4B98: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x801D4B9C: b           L_801D4C00
    // 0x801D4BA0: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
        goto L_801D4C00;
    // 0x801D4BA0: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D4BA4:
    // 0x801D4BA4: jal         0x8012D844
    // 0x801D4BA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_2;
    // 0x801D4BA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801D4BAC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D4BB0: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D4BB4: addiu       $a3, $a3, 0x1620
    ctx->r7 = ADD32(ctx->r7, 0X1620);
    // 0x801D4BB8: b           L_801D4BFC
    // 0x801D4BBC: lw          $a0, 0x1620($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1620);
        goto L_801D4BFC;
    // 0x801D4BBC: lw          $a0, 0x1620($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1620);
L_801D4BC0:
    // 0x801D4BC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D4BC4: jal         0x8012D844
    // 0x801D4BC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_3;
    // 0x801D4BC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801D4BCC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D4BD0: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D4BD4: addiu       $a3, $a3, 0x1620
    ctx->r7 = ADD32(ctx->r7, 0X1620);
    // 0x801D4BD8: b           L_801D4BFC
    // 0x801D4BDC: lw          $a0, 0x1620($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1620);
        goto L_801D4BFC;
    // 0x801D4BDC: lw          $a0, 0x1620($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1620);
L_801D4BE0:
    // 0x801D4BE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801D4BE4: jal         0x8012D844
    // 0x801D4BE8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_4;
    // 0x801D4BE8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x801D4BEC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D4BF0: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D4BF4: addiu       $a3, $a3, 0x1620
    ctx->r7 = ADD32(ctx->r7, 0X1620);
    // 0x801D4BF8: lw          $a0, 0x1620($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1620);
L_801D4BFC:
    // 0x801D4BFC: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
L_801D4C00:
    // 0x801D4C00: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    // 0x801D4C04: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x801D4C08: bne         $at, $zero, L_801D4C34
    if (ctx->r1 != 0) {
        // 0x801D4C0C: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_801D4C34;
    }
    // 0x801D4C0C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801D4C10: jal         0x801C0B2C
    // 0x801D4C14: nop

    LOOKUP_FUNC(0x801C0B2C)(rdram, ctx);
        goto after_5;
    // 0x801D4C14: nop

    after_5:
    // 0x801D4C18: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4C1C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D4C20: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x801D4C24: addiu       $a3, $a3, 0x1620
    ctx->r7 = ADD32(ctx->r7, 0X1620);
    // 0x801D4C28: lw          $a0, 0x1620($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1620);
    // 0x801D4C2C: sw          $v0, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->r2;
    // 0x801D4C30: sw          $v1, 0x161C($at)
    MEM_W(0X161C, ctx->r1) = ctx->r3;
L_801D4C34:
    // 0x801D4C34: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801D4C38: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x801D4C3C: mfhi        $t3
    ctx->r11 = hi;
    // 0x801D4C40: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801D4C44: nop

    // 0x801D4C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D4C4C:
    // 0x801D4C4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D4C50: jr          $ra
    // 0x801D4C54: nop

    return;
    // 0x801D4C54: nop

;}
RECOMP_FUNC void M24_FUN_801d4c58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D4C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D4C60: jal         0x80006214
    // 0x801D4C64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x80006214)(rdram, ctx);
        goto after_0;
    // 0x801D4C64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D4C68: jal         0x801C354C
    // 0x801D4C6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(0x801C354C)(rdram, ctx);
        goto after_1;
    // 0x801D4C6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801D4C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D4C74: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801D4C78: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4C7C: sw          $t6, -0x4A48($at)
    MEM_W(-0X4A48, ctx->r1) = ctx->r14;
    // 0x801D4C80: jr          $ra
    // 0x801D4C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801D4C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // @fallthrough-fix: split fallthrough -> chain to continuation
    M24_FUN_801d4c88(rdram, ctx);
;}
RECOMP_FUNC void M24_FUN_801d4c88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4C88: nop

    // 0x801D4C8C: nop

;}
RECOMP_FUNC void M24_FUN_801d4c90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4C90: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801D4C94: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4C98: sw          $a0, -0x49C0($at)
    MEM_W(-0X49C0, ctx->r1) = ctx->r4;
    // 0x801D4C9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4CA0: sw          $zero, -0x49A0($at)
    MEM_W(-0X49A0, ctx->r1) = 0;
    // 0x801D4CA4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4CA8: sw          $zero, -0x499C($at)
    MEM_W(-0X499C, ctx->r1) = 0;
    // 0x801D4CAC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4CB0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801D4CB4: sw          $t6, -0x497C($at)
    MEM_W(-0X497C, ctx->r1) = ctx->r14;
    // 0x801D4CB8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801D4CBC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801D4CC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4CC4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x801D4CC8: addiu       $t8, $zero, 0x118
    ctx->r24 = ADD32(0, 0X118);
    // 0x801D4CCC: addiu       $t9, $zero, 0x118
    ctx->r25 = ADD32(0, 0X118);
    // 0x801D4CD0: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x801D4CD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801D4CD8: sw          $zero, -0x49B8($at)
    MEM_W(-0X49B8, ctx->r1) = 0;
    // 0x801D4CDC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801D4CE0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801D4CE4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801D4CE8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801D4CEC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801D4CF0: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // 0x801D4CF4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801D4CF8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x801D4CFC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801D4D00: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801D4D04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D4D08: jal         0x801CC654
    // 0x801D4D0C: addiu       $a3, $zero, 0x118
    ctx->r7 = ADD32(0, 0X118);
    LOOKUP_FUNC(0x801CC654)(rdram, ctx);
        goto after_0;
    // 0x801D4D0C: addiu       $a3, $zero, 0x118
    ctx->r7 = ADD32(0, 0X118);
    after_0:
    // 0x801D4D10: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801D4D14: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4D18: addiu       $t2, $t2, 0x4D48
    ctx->r10 = ADD32(ctx->r10, 0X4D48);
    // 0x801D4D1C: sw          $v0, -0x4978($at)
    MEM_W(-0X4978, ctx->r1) = ctx->r2;
    // 0x801D4D20: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801D4D24: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801D4D28: addiu       $a1, $zero, 0x11B
    ctx->r5 = ADD32(0, 0X11B);
    // 0x801D4D2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D4D30: jal         0x8013B570
    // 0x801D4D34: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    LOOKUP_FUNC(0x8013B570)(rdram, ctx);
        goto after_1;
    // 0x801D4D34: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x801D4D38: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801D4D3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801D4D40: jr          $ra
    // 0x801D4D44: nop

    return;
    // 0x801D4D44: nop

;}
RECOMP_FUNC void M24_FUN_801d4d48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4D48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D4D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D4D50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D4D54: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D4D58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D4D5C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D4D60: beq         $t6, $zero, L_801D4D8C
    if (ctx->r14 == 0) {
        // 0x801D4D64: nop
    
            goto L_801D4D8C;
    }
    // 0x801D4D64: nop

    // 0x801D4D68: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // 0x801D4D6C: jal         0x8012D844
    // 0x801D4D70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(0x8012D844)(rdram, ctx);
        goto after_0;
    // 0x801D4D70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801D4D74: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D4D78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801D4D7C: jal         0x800058DC
    // 0x801D4D80: addiu       $a1, $a1, 0x4DA4
    ctx->r5 = ADD32(ctx->r5, 0X4DA4);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D4D80: addiu       $a1, $a1, 0x4DA4
    ctx->r5 = ADD32(ctx->r5, 0X4DA4);
    after_1:
    // 0x801D4D84: b           L_801D4D98
    // 0x801D4D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D4D98;
    // 0x801D4D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D4D8C:
    // 0x801D4D8C: jal         0x800058DC
    // 0x801D4D90: addiu       $a1, $a1, 0x4D48
    ctx->r5 = ADD32(ctx->r5, 0X4D48);
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D4D90: addiu       $a1, $a1, 0x4D48
    ctx->r5 = ADD32(ctx->r5, 0X4D48);
    after_2:
    // 0x801D4D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D4D98:
    // 0x801D4D98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D4D9C: jr          $ra
    // 0x801D4DA0: nop

    return;
    // 0x801D4DA0: nop

;}
RECOMP_FUNC void M24_FUN_801d4da4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D4DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D4DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D4DAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801D4DB0: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x801D4DB4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801D4DB8: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x801D4DBC: beq         $t6, $zero, L_801D4EFC
    if (ctx->r14 == 0) {
        // 0x801D4DC0: nop
    
            goto L_801D4EFC;
    }
    // 0x801D4DC0: nop

    // 0x801D4DC4: lw          $t7, -0x4984($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4984);
    // 0x801D4DC8: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x801D4DCC: addiu       $a2, $a2, -0x4998
    ctx->r6 = ADD32(ctx->r6, -0X4998);
    // 0x801D4DD0: beq         $t7, $zero, L_801D4ED0
    if (ctx->r15 == 0) {
        // 0x801D4DD4: nop
    
            goto L_801D4ED0;
    }
    // 0x801D4DD4: nop

    // 0x801D4DD8: lw          $a1, 0x30($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X30);
    // 0x801D4DDC: jal         0x80005FAC
    // 0x801D4DE0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(0x80005FAC)(rdram, ctx);
        goto after_0;
    // 0x801D4DE0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801D4DE4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801D4DE8: addiu       $a1, $a1, 0x1CF0
    ctx->r5 = ADD32(ctx->r5, 0X1CF0);
    // 0x801D4DEC: lw          $t9, 0x980($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X980);
    // 0x801D4DF0: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D4DF4: addiu       $v1, $v1, -0x4988
    ctx->r3 = ADD32(ctx->r3, -0X4988);
    // 0x801D4DF8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801D4DFC: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801D4E00: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x801D4E04: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801D4E08: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801D4E0C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801D4E10: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801D4E14: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    // 0x801D4E18: lw          $t4, 0x980($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X980);
    // 0x801D4E1C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D4E20: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801D4E24: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801D4E28: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801D4E2C: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x801D4E30: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x801D4E34: ori         $at, $at, 0x15
    ctx->r1 = ctx->r1 | 0X15;
    // 0x801D4E38: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x801D4E3C: lw          $t9, 0x980($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X980);
    // 0x801D4E40: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801D4E44: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801D4E48: lw          $t3, 0x2C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X2C);
    // 0x801D4E4C: lhu         $t2, 0x2($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X2);
    // 0x801D4E50: sh          $t2, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r10;
    // 0x801D4E54: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801D4E58: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801D4E5C: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x801D4E60: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D4E64: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D4E68: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x801D4E6C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801D4E70: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801D4E74: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x801D4E78: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801D4E7C: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x801D4E80: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x801D4E84: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801D4E88: lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // 0x801D4E8C: lw          $t3, 0x2C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2C);
    // 0x801D4E90: swc1        $f2, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f2.u32l;
    // 0x801D4E94: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801D4E98: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x801D4E9C: swc1        $f2, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f2.u32l;
    // 0x801D4EA0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801D4EA4: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801D4EA8: swc1        $f2, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f2.u32l;
    // 0x801D4EAC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801D4EB0: lw          $a0, 0x2C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X2C);
    // 0x801D4EB4: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x801D4EB8: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x801D4EBC: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
    // 0x801D4EC0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801D4EC4: lw          $t1, -0x4980($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4980);
    // 0x801D4EC8: b           L_801D4EE4
    // 0x801D4ECC: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
        goto L_801D4EE4;
    // 0x801D4ECC: sb          $t1, 0x22($t2)
    MEM_B(0X22, ctx->r10) = ctx->r9;
L_801D4ED0:
    // 0x801D4ED0: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x801D4ED4: addiu       $v1, $v1, -0x4988
    ctx->r3 = ADD32(ctx->r3, -0X4988);
    // 0x801D4ED8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801D4EDC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801D4EE0: sw          $zero, -0x4980($at)
    MEM_W(-0X4980, ctx->r1) = 0;
L_801D4EE4:
    // 0x801D4EE4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D4EE8: addiu       $a1, $a1, 0x4F1C
    ctx->r5 = ADD32(ctx->r5, 0X4F1C);
    // 0x801D4EEC: jal         0x800058DC
    // 0x801D4EF0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_1;
    // 0x801D4EF0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x801D4EF4: b           L_801D4F10
    // 0x801D4EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801D4F10;
    // 0x801D4EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D4EFC:
    // 0x801D4EFC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801D4F00: addiu       $a1, $a1, 0x4DA4
    ctx->r5 = ADD32(ctx->r5, 0X4DA4);
    // 0x801D4F04: jal         0x800058DC
    // 0x801D4F08: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    LOOKUP_FUNC(0x800058DC)(rdram, ctx);
        goto after_2;
    // 0x801D4F08: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x801D4F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801D4F10:
    // 0x801D4F10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D4F14: jr          $ra
    // 0x801D4F18: nop

    return;
    // 0x801D4F18: nop

;}
